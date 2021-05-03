/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _APP_USBD_CDC_H 
#define _APP_USBD_CDC_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define APP_CDC_BUFFER_SIZE 256

typedef struct
{
    USB_DEVICE_HANDLE deviceHandle;
    USB_CDC_LINE_CODING setLineCodingData;
    USB_CDC_LINE_CODING getLineCodingData;
    USB_CDC_CONTROL_LINE_STATE controlLineStateData;
    USB_DEVICE_CDC_TRANSFER_HANDLE readTransferHandle;
    USB_DEVICE_CDC_TRANSFER_HANDLE writeTransferHandle;
    bool sofEventHasOccurred;
    bool isConfigured;
    bool isReadComplete;
    bool isWriteComplete;
    uint16_t breakData;
    uint32_t bytesToRead;    //# of bytes to read per trans
    uint32_t numBytesRead;   //# of bytes read from last trans
    uint32_t totalBytesRead; //total # of bytes read
    uint8_t * cdcReadBuffer;
} APP_USBCDC_DATA;

void APP_USBD_CDC_Initialize ( APP_USBCDC_DATA * appUSBDCDData );
void APP_USBD_CDC_Tasks ( void );
void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context);
 
#ifdef __cplusplus
}
#endif

#endif /* _APP_USBD_CDC_H */

/* *****************************************************************************
 End of File
 */
