/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "lv_conf.h"
#include "third_party/lvgl/src/lv_api_map.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

#define BUFF_DIM (480 * 200)
#define LVGL_TICK_TIMER_MS 10

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[BUFF_DIM];

static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;
static lv_indev_t * my_indev;
static SYS_INP_InputListener inputListener;
static uint32_t touchX = 0, touchY = 0;
static bool touchDown = false;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

gfxResult DRV_ILI9488_BlitBuffer(int32_t x, int32_t y, gfxPixelBuffer* buf);
void lv_init(void);
LV_ATTRIBUTE_TICK_INC void lv_tick_inc(uint32_t tick_period);
void lv_demo_music(void);


gfxPixelBuffer pixelBuff;

void flush_cb(struct _lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    gfxPixelBufferCreate(area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, GFX_COLOR_MODE_RGB_565, buf1, &pixelBuff);
    
    DRV_ILI9488_BlitBuffer(area->x1, area->y1, &pixelBuff);
}

void gfxBlitCallBackFunc (void)
{
    lv_disp_flush_ready(&disp_drv);
}

void input_read(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
    data->point.x = touchX;
    data->point.y = touchY;
    data->state = (touchDown == true) ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}

static void touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    touchX = evt->x;
    touchY = evt->y;
    touchDown = true;
}

static void touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    touchX = evt->x;
    touchY = evt->y;
    touchDown = false;
}

static void touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    touchX = evt->x;
    touchY = evt->y;
    touchDown = true;
}

static void Timer_Callback ( uintptr_t context)
{
    lv_tick_inc(LVGL_TICK_TIMER_MS);
}

int main ( void )
{
    gfxIOCTLArg_Value val; 
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* Initialize tick timer */
    timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, LVGL_TICK_TIMER_MS, SYS_TIME_PERIODIC);

    /* Initialize blit callback */
    val.value.v_pointer = (void*) gfxBlitCallBackFunc;
    DRV_ILI9488_IOCTL(GFX_IOCTL_SET_BLIT_CALLBACK, &val);    
    
    /* Initialize lvgl library */
    lv_init();

    /* Initialize lvgl > display interface*/
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, BUFF_DIM);
    
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 320;
    disp_drv.flush_cb = flush_cb;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
    
    /* Initialize lvgl > touch interface*/
    inputListener.handleTouchDown = &touchDownHandler;
    inputListener.handleTouchUp = &touchUpHandler;
    inputListener.handleTouchMove = &touchMoveHandler;
    SYS_INP_AddListener(&inputListener);    
    
    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = input_read;
    
    /*Register the driver in LVGL and save the created input device object*/
    my_indev = lv_indev_drv_register(&indev_drv);
    
    lv_disp_flush_ready(&disp_drv);
  
    lv_demo_music();
    
    SYS_TIME_TimerStart(timer);
    
    while ( true )
    {
        
        DRV_ILI9488_IOCTL(GFX_IOCTL_GET_STATUS, &val);
        if (val.value.v_uint == 0)
        {
            lv_task_handler();
        }
        
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

