#include "definitions.h"
#include "app_usbd_cdc.h"
#include "app_qspi.h"
#include "app.h"

//#define USB_DOWNLOAD_ONLY 1
//#define ENABLE_CONSOLE_LOGS

#ifdef ENABLE_CONSOLE_LOGS
#define APP_LOG_PRINTF(...) printf(__VA_ARGS__)
#else
#define APP_LOG_PRINTF(...)
#endif

typedef enum
{
    /* APP initialization states */
    APP_IMGFLASH_STATE_INIT,
    APP_IMGFLASH_STATE_USB_INIT,
    APP_IMGFLASH_STATE_QSPI_RESET,
    APP_IMGFLASH_STATE_QSPI_ENABLE_QUADIO,
    APP_IMGFLASH_STATE_QSPI_UNLOCK,
    APP_IMGFLASH_STATE_QSPI_READ_JEDECID,

    APP_IMGFLASH_STATE_IDLE,
            
    /* APP USB Download */
    APP_IMGFLASH_STATE_USB_START_DOWNLOAD,
    APP_IMGFLASH_STATE_USB_PREP_DOWNLOAD,
    APP_IMGFLASH_STATE_USB_DOWNLOAD,
    APP_IMGFLASH_STATE_USB_DOWNLOAD_WAIT,

    /* APP QSPI Program */
    APP_IMGFLASH_STATE_QSPI_ERASE,
    APP_IMGFLASH_STATE_QSPI_ERASE_WAIT,
    APP_IMGFLASH_STATE_QSPI_WRITE,
    APP_IMGFLASH_STATE_QSPI_WRITE_WAIT,
    APP_IMGFLASH_STATE_QSPI_READ,
    APP_IMGFLASH_STATE_QSPI_VERIFY,
            
    APP_IMGFLASH_STATE_QSPI_FINAL_WRITE,
            
    APP_IMGFLASH_STATE_ERROR,
} APP_IMGFLASH_STATE;

typedef enum 
{
    APP_IMGFLASH_EVENT_NONE,
    APP_IMGFLASH_EVENT_START_FLASH,
    APP_IMGFLASH_EVENT_EXIT,
} APP_IMGFLASH_EVENT;

typedef struct
{
    APP_IMGFLASH_STATE prevstate;
    APP_IMGFLASH_STATE state;
    APP_IMGFLASH_EVENT event;
    APP_USBCDC_DATA usbcdc;
    APP_QSPI_DATA qspi;
    uint32_t totalBytesCopied; //total # of bytes copied to qspi
}  APP_IMGFLASH_DATA;

static APP_IMGFLASH_DATA app_imgflash_data;
static char charBuff[32] = {0};

bool APP_IMGFLASH_GetReadyStatus(void)
{
    return (app_imgflash_data.state == APP_IMGFLASH_STATE_IDLE);
}

void APP_IMGFLASH_StartDownload (void)
{
    app_imgflash_data.event = APP_IMGFLASH_EVENT_START_FLASH;
}

void APP_IMGFLASH_StopDownload (void)
{
    app_imgflash_data.event = APP_IMGFLASH_EVENT_EXIT;
}

void APP_IMGFLASH_Initialize( void )
{
    app_imgflash_data.event = APP_IMGFLASH_EVENT_NONE;
    app_imgflash_data.state = APP_IMGFLASH_STATE_INIT;
    APP_QSPI_Initialize(&app_imgflash_data.qspi);
    APP_USBD_CDC_Initialize(&app_imgflash_data.usbcdc);
}

void APP_IMGFLASH_NextState(APP_IMGFLASH_STATE next)
{
    app_imgflash_data.prevstate = app_imgflash_data.state;
    app_imgflash_data.state = next;
}

void APP_IMGFLASH_Tasks( void )
{
    switch (app_imgflash_data.state)
    {
        case APP_IMGFLASH_STATE_INIT:
        {
            app_imgflash_data.event = APP_IMGFLASH_EVENT_NONE;
            
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_INIT);
            
            break;
        }
        case APP_IMGFLASH_STATE_USB_INIT:
        {
            app_imgflash_data.usbcdc.deviceHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE );
            
            if(app_imgflash_data.usbcdc.deviceHandle != USB_DEVICE_HANDLE_INVALID)
            {
                USB_DEVICE_EventHandlerSet(app_imgflash_data.usbcdc.deviceHandle,
                                           APP_USBDeviceEventHandler,
                                           (uintptr_t) &app_imgflash_data.usbcdc);

                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_RESET);
            }
            else
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }            

            break;
        }
        case APP_IMGFLASH_STATE_QSPI_RESET:
        {
            if (APP_ResetFlash() != APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }
            else
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_ENABLE_QUADIO);
            }            
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_ENABLE_QUADIO:
        {
            if (APP_EnableQuadIO() != APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }
            else
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_UNLOCK);
            }

            break;
        }
        case APP_IMGFLASH_STATE_QSPI_UNLOCK:
        {
            if (APP_UnlockFlash() != APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }
            else
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_READ_JEDECID);
            }            
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_READ_JEDECID:
        {
            if (APP_ReadJedecId(&app_imgflash_data.qspi.jedec_id) != APP_TRANSFER_COMPLETED ||
                app_imgflash_data.qspi.jedec_id != SST26VF064B_JEDEC_ID)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
                break;
            }

            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_IDLE);
            
            
            break;
        }
        case APP_IMGFLASH_STATE_IDLE:
        {
            switch (app_imgflash_data.event)
            {
                case APP_IMGFLASH_EVENT_START_FLASH:
                {
                    app_imgflash_data.event = APP_IMGFLASH_EVENT_NONE;
                    
                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_START_DOWNLOAD);
                    break;
                }
                default:
                    break;
            }
            
            break;
        }
        case APP_IMGFLASH_STATE_USB_START_DOWNLOAD:
        {
            if (app_imgflash_data.usbcdc.isConfigured)
            {
                app_imgflash_data.usbcdc.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                app_imgflash_data.usbcdc.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                app_imgflash_data.usbcdc.isReadComplete = true;
                app_imgflash_data.usbcdc.isWriteComplete = true;
                app_imgflash_data.usbcdc.totalBytesRead = 0;
                app_imgflash_data.usbcdc.bytesToRead = APP_CDC_BUFFER_SIZE;
                app_imgflash_data.usbcdc.numBytesRead = 0;
                
                app_imgflash_data.totalBytesCopied = 0;
                
                app_imgflash_data.qspi.writeOffset = 0;
                app_imgflash_data.qspi.writeBuffer = app_imgflash_data.usbcdc.cdcReadBuffer;
                
#ifdef USB_DOWNLOAD_ONLY
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD);
#else
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_ERASE);                
#endif
                APP_LOG_PRINTF("waiting for data\n\r");
                APP_ShowSQIUpdateLog("Ready.\nPlease send BIN file via USB.");
            }
            else
            {
                APP_LOG_PRINTF("usb not ready\n\r");
                APP_ShowSQIUpdateLog("USB not ready. Please connect to PC.");
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_IDLE);
            }
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_ERASE:
        {
            APP_ChipErase();
            APP_LOG_PRINTF("erasing\n\r");
            
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_ERASE_WAIT);
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_ERASE_WAIT:
        {
            if (APP_TransferStatusCheck() == APP_TRANSFER_COMPLETED)
            {
                APP_LOG_PRINTF("erase done\n\r");
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD);
            }
            
            break;
        }
        case APP_IMGFLASH_STATE_USB_PREP_DOWNLOAD:
        {
            if (app_imgflash_data.usbcdc.totalBytesRead > 0)
            {
                APP_LOG_PRINTF("recover excess %u \n\r", (unsigned int) app_imgflash_data.usbcdc.totalBytesRead);
                memcpy(&app_imgflash_data.usbcdc.cdcReadBuffer[0], 
                       &app_imgflash_data.usbcdc.cdcReadBuffer[APP_CDC_BUFFER_SIZE],
                       app_imgflash_data.usbcdc.totalBytesRead);
            }
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD);
            break;
        }
        case APP_IMGFLASH_STATE_USB_DOWNLOAD:
        {
            if(app_imgflash_data.usbcdc.isReadComplete == true)
            {
                app_imgflash_data.usbcdc.isReadComplete = false;
                app_imgflash_data.usbcdc.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

                USB_DEVICE_CDC_Read (USB_DEVICE_CDC_INDEX_0,
                        &app_imgflash_data.usbcdc.readTransferHandle,
                        &app_imgflash_data.usbcdc.cdcReadBuffer[app_imgflash_data.usbcdc.totalBytesRead],
                        APP_CDC_BUFFER_SIZE);
                
                if(app_imgflash_data.usbcdc.readTransferHandle == USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID)
                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
                else                
                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD_WAIT);
            }
            
            break;
        }
        case APP_IMGFLASH_STATE_USB_DOWNLOAD_WAIT:
        {
            if(app_imgflash_data.usbcdc.isReadComplete)
            {
                if (app_imgflash_data.usbcdc.numBytesRead > 0)
                {
                    app_imgflash_data.usbcdc.totalBytesRead += app_imgflash_data.usbcdc.numBytesRead;
                    app_imgflash_data.totalBytesCopied += app_imgflash_data.usbcdc.numBytesRead;;
                    
                    APP_LOG_PRINTF("usb read %u bytes\n\r", (unsigned int) app_imgflash_data.usbcdc.numBytesRead);
                    APP_LOG_PRINTF("total read %u bytes\n\r", (unsigned int) app_imgflash_data.usbcdc.totalBytesRead);
                    
                    if (app_imgflash_data.usbcdc.totalBytesRead < APP_CDC_BUFFER_SIZE)
                    {
                        APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD);
                    }
                    else
                    {
                        app_imgflash_data.usbcdc.totalBytesRead %= APP_CDC_BUFFER_SIZE;
                        
#ifdef USB_DOWNLOAD_ONLY
                        APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_DOWNLOAD);
#else
                        APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_WRITE);
#endif
                    }
                }
            }
            
            //Process events
            switch (app_imgflash_data.event)
            {
                case APP_IMGFLASH_EVENT_EXIT:
                {
                    app_imgflash_data.event = APP_IMGFLASH_EVENT_NONE;

                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_FINAL_WRITE);
                    
                    break;
                }
                default:
                    break;
            }
            
            if (tick_count >= tick_count_last)
            {
                if (tick_count - tick_count_last > NUM_COUNT_SEC_TICK)
                {
                    APP_LOG_PRINTF("copied %u bytes\n\r", (unsigned int) app_imgflash_data.totalBytesCopied);
                    APP_LOG_PRINTF("written %u bytes\n\r", (unsigned int) app_imgflash_data.qspi.writeOffset);

                    sprintf(charBuff, "Downloading %7u kb", (unsigned int) (app_imgflash_data.totalBytesCopied/1024));
                    APP_ShowSQIUpdateLog(charBuff);
                    
                    tick_count_last = tick_count;
                }
            }
            else
            {
                tick_count_last = tick_count;
            }            
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_WRITE:
        {
            if (APP_MemoryWrite((uint32_t *) app_imgflash_data.qspi.writeBuffer, 
                                APP_CDC_BUFFER_SIZE,
                                app_imgflash_data.qspi.writeOffset) != APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
                break;
            }
            
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_WRITE_WAIT);

            break;
        }
        case APP_IMGFLASH_STATE_QSPI_WRITE_WAIT:
        {
            if (APP_TransferStatusCheck() == APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_READ);
            }

            break;
        }
        case APP_IMGFLASH_STATE_QSPI_READ:
        {
            if (APP_MemoryRead((uint32_t *)app_imgflash_data.qspi.readBuffer,
                               APP_CDC_BUFFER_SIZE,
                               app_imgflash_data.qspi.writeOffset) != APP_TRANSFER_COMPLETED)
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }
            else
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_QSPI_VERIFY);

            break;
        }
        case APP_IMGFLASH_STATE_QSPI_VERIFY:
        {
            if (!memcmp(app_imgflash_data.qspi.writeBuffer,
                        app_imgflash_data.qspi.readBuffer,
                        APP_CDC_BUFFER_SIZE))
            {
                    app_imgflash_data.qspi.writeOffset += APP_CDC_BUFFER_SIZE;
                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_USB_PREP_DOWNLOAD);
            }
            else
            {
                APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
            }
            
            break;
        }
        case APP_IMGFLASH_STATE_QSPI_FINAL_WRITE:
        {
            if (app_imgflash_data.usbcdc.totalBytesRead > 0)
            {
                if (APP_MemoryWrite((uint32_t *) app_imgflash_data.qspi.writeBuffer, 
                                    APP_CDC_BUFFER_SIZE,
                                    app_imgflash_data.qspi.writeOffset) != APP_TRANSFER_COMPLETED)
                {
                    APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_ERROR);
                    break;
                }                
            }
            
            APP_LOG_PRINTF("Done\n\r");
            APP_ShowSQIUpdateLog("Update Complete.");
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_IDLE);
            
            break;
        }        
        case APP_IMGFLASH_STATE_ERROR:
        {
            sprintf(charBuff, "error %d", app_imgflash_data.prevstate);
            APP_ShowSQIUpdateLog(charBuff);
            APP_LOG_PRINTF(charBuff);
            
            APP_IMGFLASH_NextState(APP_IMGFLASH_STATE_IDLE);

            break;
        }
        default:
            break;
    }
}