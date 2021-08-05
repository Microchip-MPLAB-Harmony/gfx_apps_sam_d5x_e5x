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
#include "gfx/driver/gfx_driver.h"
#include "app_qspi.h"

void APP_SW_VGPUInit(void)
{
    
}

static gfxResult APP_SW_BlitBuffer(const gfxPixelBuffer* src,
                                   const gfxRect * srcRect,
                                   const gfxPixelBuffer* dest,
                                   const gfxRect * destRect)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize;

    rowSize = srcRect->width * gfxColorInfoTable[src->mode].size;

    for(row = 0; row < srcRect->height; row++)
    {
        srcPtr = gfxPixelBufferOffsetGet(src, srcRect->x, srcRect->y + row);
        destPtr = gfxPixelBufferOffsetGet(dest, destRect->x, destRect->y + row);

        memcpy(destPtr, srcPtr, rowSize);
    }

    return GFX_SUCCESS;
}

static gfxResult APP_SQI_XIP_BlitBuffer(const gfxPixelBuffer* src,
                                        const gfxRect * srcRect,
                                        const gfxPixelBuffer* dest,
                                        const gfxRect * destRect)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize;

    rowSize = srcRect->width * gfxColorInfoTable[src->mode].size;

    for(row = 0; row < srcRect->height; row++)
    {
        srcPtr = gfxPixelBufferOffsetGet(src, srcRect->x, srcRect->y + row);
        destPtr = gfxPixelBufferOffsetGet(dest, destRect->x, destRect->y + row);

        APP_MemoryRead(destPtr, rowSize, (uint32_t) srcPtr);
    }

    return GFX_SUCCESS;
}

gfxResult APP_VGPU_BlitBuffer(const gfxPixelBuffer* sourceBuf,
                              const gfxRect * gfxSourceRect,
                              const gfxPixelBuffer* destBuf,
                              const gfxRect * gfxDestRect)
{
    gfxResult res;
    
    if ((((uint32_t) sourceBuf->pixels) & QSPI_ADDR) == QSPI_ADDR)
    {
        res = APP_SQI_XIP_BlitBuffer(sourceBuf,
                   gfxSourceRect,
                   destBuf,
                   gfxDestRect);

    }
    else
    {
        res = APP_SW_BlitBuffer(sourceBuf,
                           gfxSourceRect,
                           destBuf,
                           gfxDestRect);
    }
    
    return res;
}

gfxResult APP_VGPU_SetGlobalAlpha(const gfxAlpha srcGlobalAlpha,
                            const gfxAlpha dstGlobalAlpha,
                            uint32_t srcGlobalAlphaValue,
                            uint32_t dstGlobalAlphaValue)
{
    //Nothing to do
    
    return GFX_SUCCESS;
}

gfxResult APP_VGPU_SetBlend (const gfxBlend blend)
{
    //Nothing to do
    
    return GFX_SUCCESS;
}