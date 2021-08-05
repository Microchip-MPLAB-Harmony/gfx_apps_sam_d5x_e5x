/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "app.h"
#include "app_usbd_cdc.h"
#include "app_qspi.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
uint8_t CACHE_ALIGN cdcReadBuffer[APP_CDC_BUFFER_SIZE * 2];

USB_DEVICE_CDC_EVENT_RESPONSE APP_USBDeviceCDCEventHandler
(
    USB_DEVICE_CDC_INDEX index,
    USB_DEVICE_CDC_EVENT event,
    void * pData,
    uintptr_t userData
)
{
    APP_USBCDC_DATA * appDataObject;
    USB_CDC_CONTROL_LINE_STATE * controlLineStateData;
    USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE * eventDataRead;
    
    appDataObject = (APP_USBCDC_DATA *)userData;

    switch(event)
    {
        case USB_DEVICE_CDC_EVENT_GET_LINE_CODING:

            /* This means the host wants to know the current line
             * coding. This is a control transfer request. Use the
             * USB_DEVICE_ControlSend() function to send the data to
             * host.  */

            USB_DEVICE_ControlSend(appDataObject->deviceHandle,
                    &appDataObject->getLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_LINE_CODING:

            /* This means the host wants to set the line coding.
             * This is a control transfer request. Use the
             * USB_DEVICE_ControlReceive() function to receive the
             * data from the host */

            USB_DEVICE_ControlReceive(appDataObject->deviceHandle,
                    &appDataObject->setLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_CONTROL_LINE_STATE:

            /* This means the host is setting the control line state.
             * Read the control line state. We will accept this request
             * for now. */

            controlLineStateData = (USB_CDC_CONTROL_LINE_STATE *)pData;
            appDataObject->controlLineStateData.dtr = controlLineStateData->dtr;
            appDataObject->controlLineStateData.carrier = controlLineStateData->carrier;

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_SEND_BREAK:

            /* This means that the host is requesting that a break of the
             * specified duration be sent. Read the break duration */

            appDataObject->breakData = ((USB_DEVICE_CDC_EVENT_DATA_SEND_BREAK *)pData)->breakDuration;
            
            /* Complete the control transfer by sending a ZLP  */
            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
            
            break;

        case USB_DEVICE_CDC_EVENT_READ_COMPLETE:

            /* This means that the host has sent some data*/
            eventDataRead = (USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE *)pData;
            
            if(eventDataRead->status != USB_DEVICE_CDC_RESULT_ERROR)
            {
                appDataObject->isReadComplete = true;
                
                appDataObject->numBytesRead = eventDataRead->length; 
            }
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:

            /* The data stage of the last control transfer is
             * complete. For now we accept all the data */

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_SENT:

            /* This means the GET LINE CODING function data is valid. We don't
             * do much with this data in this demo. */
            break;

        case USB_DEVICE_CDC_EVENT_WRITE_COMPLETE:

            /* This means that the data write got completed. We can schedule
             * the next read. */

            appDataObject->isWriteComplete = true;
            break;

        default:
            break;
    }

    return USB_DEVICE_CDC_EVENT_RESPONSE_NONE;
}

/***********************************************
 * Application USB Device Layer Event Handler.
 ***********************************************/
void APP_USBDeviceEventHandler 
(
    USB_DEVICE_EVENT event, 
    void * eventData, 
    uintptr_t context 
)
{
    USB_DEVICE_EVENT_DATA_CONFIGURED *configuredEventData;
    APP_USBCDC_DATA * appUSBDCDData = (APP_USBCDC_DATA *) context;

    switch(event)
    {
        case USB_DEVICE_EVENT_SOF:
        {
            /* This event is used for switch debounce. This flag is reset
             * by the switch process routine. */
            appUSBDCDData->sofEventHasOccurred = true;
            
            break;
        }
        case USB_DEVICE_EVENT_RESET:
        {
            /* Update LED to show configured state */
            LED2_Off();
            
            appUSBDCDData->isConfigured = false;

            break;
        }
        case USB_DEVICE_EVENT_CONFIGURED:
        {
            /* Check the configuration. We only support configuration 1 */
            configuredEventData = (USB_DEVICE_EVENT_DATA_CONFIGURED*) eventData;
                        
            if ( configuredEventData->configurationValue == 1)
            {
                /* Update LED to show configured state */
                LED2_On();
                
                /* Register the CDC Device application event handler here.
                 * Note how the appUSBDCDData object pointer is passed as the
                 * user data */

                USB_DEVICE_CDC_EventHandlerSet(USB_DEVICE_CDC_INDEX_0, APP_USBDeviceCDCEventHandler, (uintptr_t)appUSBDCDData);

                /* Mark that the device is now configured */
                appUSBDCDData->isConfigured = true;
                
                APP_ShowSQIUpdateLog(" ");
            }
            
            break;
        }
        case USB_DEVICE_EVENT_POWER_DETECTED:
        {
            /* VBUS was detected. We can attach the device */
            USB_DEVICE_Attach(appUSBDCDData->deviceHandle);
            
            break;
        }
        case USB_DEVICE_EVENT_POWER_REMOVED:
        { 
            /* VBUS is not available. We can detach the device */
            USB_DEVICE_Detach(appUSBDCDData->deviceHandle);
            
            appUSBDCDData->isConfigured = false;
            
            /* Update LED to show configured state */
            LED2_Off();
            
            break;
        }
        case USB_DEVICE_EVENT_SUSPENDED:

            break;

        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            
            break;
    }
}

void APP_USBD_CDC_Initialize ( APP_USBCDC_DATA * appUSBDCDData )
{
    appUSBDCDData->deviceHandle = USB_DEVICE_HANDLE_INVALID ;
    appUSBDCDData->isConfigured = false;
    appUSBDCDData->totalBytesRead = 0;

    /* Initial get line coding state */
    appUSBDCDData->getLineCodingData.dwDTERate = 9600;
    appUSBDCDData->getLineCodingData.bParityType = 0;
    appUSBDCDData->getLineCodingData.bParityType = 0;
    appUSBDCDData->getLineCodingData.bDataBits = 8;

    /* Read Transfer Handle */
    appUSBDCDData->readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Write Transfer Handle */
    appUSBDCDData->writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Initialize the read complete flag */
    appUSBDCDData->isReadComplete = true;

    /*Initialize the write complete flag*/
    appUSBDCDData->isWriteComplete = true;

    /* Reset other flags */
    appUSBDCDData->sofEventHasOccurred = false;
    
    appUSBDCDData->cdcReadBuffer = &cdcReadBuffer[0];
}

/*******************************************************************************
 End of File
 */
