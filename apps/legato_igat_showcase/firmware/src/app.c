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

#include "definitions.h"
#include "app.h"
#include "app_qspi.h"
#include "app_usbd_cdc.h"
#include "app_pwrmgr.h"
#ifdef RTOS_ENABLED
#include "task.h"
#endif

#define APP_PRINTF(...) //printf(__VA_ARGS__)

static SYS_INP_InputListener app_inputListener;
unsigned int idle_secs = 0;
unsigned int demo_mode_count_secs = 0;
unsigned int demo_mode_event_idx = 0;
bool demo_mode_on = true;
bool demo_mode_enabled = false;
volatile unsigned int tick_count = 0;
unsigned int tick_count_last = 0;
volatile unsigned int sec_count = 0;
int last_sec_count = 0;
int clock_sec = 0;
int clock_min = 0;
int clock_hr = 12;
unsigned int last_frame_count = 0;
unsigned int fps;
unsigned int cpu_free;
bool stats_enabled = 0;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
APP_EVENTS app_event = EVENT_NONE;
uint32_t event_parm = 0;
char fpsStrBuff[FPS_STR_SIZE];
leChar fpsStrCharBuff[FPS_STR_SIZE] = {0};

leFixedString fpsStr;
static int brightness = 0, target_brightness = 100;

static APP_GESTURE_CMD gesture = APP_GEST_NONE;

#ifdef RTOS_ENABLED
extern unsigned int Task_Usage(void);
#endif
#ifdef PM_ENABLED
static int APP_PMID = 0;
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

void APP_SetBacklightBrightness(unsigned int pct)
{
    pct = (pct <= 100) ? pct : 100;
    TC3_Compare16bitMatch1Set((BACKLIGHT_PWM_MAX_VALUE * pct) / 100);
    target_brightness = pct;    
    brightness = pct;
}

unsigned int APP_GetBacklightBrightness(void)
{
    return brightness;
}

void APP_SetTargetBacklight(unsigned int pct)
{
    target_brightness = (pct <= 100) ? pct : 100;
}

bool isDisplayReady(void)
{
    gfxIOCTLArg_Value val;
    
    gfxDriverInterface.ioctl(GFX_IOCTL_GET_STATUS, &val);
    
    return  (val.value.v_uint == 0);
}

extern void touch_enable_lowpower_measurement(void);
extern void touch_disable_nonlp_sensors(void);
extern uint16_t measurement_period_store;

static void Timer_Callback ( uintptr_t context)
{
    tick_count++;
    
    if (tick_count % NUM_COUNT_SEC_TICK == 0)
    {
        
        if (leGetRenderState()->drawCount > last_frame_count)
        {
            fps = leGetRenderState()->drawCount - last_frame_count;
            last_frame_count = leGetRenderState()->drawCount;
        }
        else
        {
            fps = 0;
        }
                
        sec_count++;
        idle_secs++;
        
        clock_sec++;
        if (clock_sec == 60)
        {
            clock_sec = 0;
            clock_min++;
            if (clock_min == 60)
            {
                clock_min = 0;
                clock_hr++;
                if (clock_hr == 24)
                {
                    clock_hr = 0;
                }
            }
        }        
    }
    
    if (brightness != target_brightness)
    {
        if (brightness > target_brightness)
        {
            brightness -= BL_STEP_DELTA_PCT;
            if (brightness < target_brightness)
                brightness = target_brightness;
        }
        else if (brightness < target_brightness)
        {
            brightness += BL_STEP_DELTA_PCT;
            if (brightness > target_brightness)
                brightness = target_brightness;
        }
        
        TC3_Compare16bitMatch1Set((BACKLIGHT_PWM_MAX_VALUE * brightness) / 100);
    }
}

#ifdef RTOS_ENABLED
void RTOS_AppConfigureTimerForRuntimeStats()
{
    //do nothing
    tick_count = 0;
}

uint32_t RTOS_AppGetRuntimeCounterValue(void)
{
    return tick_count;
}
#endif

static void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
#ifdef PM_ENABLED    
    pmSendEvent(PM_EVENT_INPUT);
#endif
}

static void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
#ifdef PM_ENABLED    
    pmSendEvent(PM_EVENT_INPUT);
#endif
}

static void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
#ifdef PM_ENABLED    
    pmSendEvent(PM_EVENT_INPUT);
#endif
}

void app_send_event(APP_EVENTS evt)
{
    app_event = evt;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    APP_IMGFLASH_Initialize();
}

static void FlickGestureHandler(const SYS_INP_FlickGestureEvent* const evt)
{
    APP_PRINTF(">>>> flick \n\r");
    switch (evt->dir)
    {
        case 0:
            gesture = APP_GEST_RIGHT_SWIPE;
            break;
        case 90:
            gesture = APP_GEST_UP_SWIPE;
            break;
        case 180:
            gesture = APP_GEST_LEFT_SWIPE;
            break;
        case 270:
            gesture = APP_GEST_DOWN_SWIPE;
            break;
        default:
            break;
    }
}

static void PinchGestureHandler(const SYS_INP_PinchGestureEvent* const evt)
{
    gesture = APP_GEST_PINCH;
    APP_PRINTF(">>>> pinch \n\r");
}

static void StretchGestureHandler(const SYS_INP_StretchGestureEvent* const evt)
{
    gesture = APP_GEST_ZOOM;
    APP_PRINTF(">>>> stretch \n\r");
}

static void RotateGestureHandler(const SYS_INP_RotateGestureEvent* const evt)
{
    APP_PRINTF(">>>> rotate \n\r");
}

static void GenericGestureHandler(const SYS_INP_GenericGestureEvent* const evt)
{
    APP_PRINTF(">>>> gest 0x%2x \n\r", evt->gest);
    switch (evt->gest)
    {
        case TAP_SINGLE:
        {
            gesture = APP_GEST_TAP;
            break;
        }  
        case DOUBLE_TAP_SINGLE:
        {
#ifdef PM_ENABLED
            if (evt->x < 50 && evt->y < 50)
            {
                pmSendEvent(PM_EVENT_POWER_DOWN);
            }
            else
#endif                
            {
                gesture = APP_GEST_TAP_DOUBLE;
            }
            break;
        }            
        case SINGLE_TAP_DUAL:
        {
            gesture = APP_GEST_DUAL_TAP;
            break;
        }
        case CW_WHEEL:
        {
            gesture = APP_GEST_WHEEL_CW;
            break;
        }     
        case CCW_WHEEL:
        {
            gesture = APP_GEST_WHEEL_CCW;
            break;
        }
        case LEFT_SWIPE_DUAL:
        {
            gesture = APP_GEST_LEFT_SWIPE_DUAL;
            break;
        }
        case RIGHT_SWIPE_DUAL:
        {
            gesture = APP_GEST_RIGHT_SWIPE_DUAL;
            break;
        }
        case RIGHT_EDGE_SWIPE:
        {
            gesture = APP_GEST_RIGHT_EDGE_SWIPE;
            break;
        }
        case LEFT_EDGE_SWIPE:
        {
            gesture = APP_GEST_LEFT_EDGE_SWIPE;
            break;
        }        
        case RIGHT_SWIPE_HOLD:
        {
            gesture = APP_GEST_RIGHT_SWIPE_HOLD;
            break;
        }  
        case LEFT_SWIPE_HOLD:
        {
            gesture = APP_GEST_LEFT_SWIPE_HOLD;
            break;
        }            
        case UP_SWIPE_HOLD:
        {
            gesture = APP_GEST_UP_SWIPE_HOLD;
            break;
        }
        case DOWN_SWIPE_HOLD:
        {
            gesture = APP_GEST_DOWN_SWIPE_HOLD;
            break;
        }
        case HOLD_TAP:
        {
            gesture = APP_GEST_TAP_HOLD;
            break;
        }
        case HOLD_TAP_DUAL:
        {
            gesture = APP_GEST_DUAL_TAP_HOLD;
            break;
        }
        case MG_M:
        {   
            gesture = APP_START_MG_M;
            break;
        }
        case MG_S:
        {   
            gesture = APP_START_MG_S;
            break;
        }
        case MG_2:
        {   
            gesture = APP_START_MG_2;
            break;
        }
        case MG_CHECK:
        {   
            gesture = APP_START_MG_CHECK;
            break;
        }
        case MG_ALPHA:
        {   
            gesture = APP_START_MG_ALPHA;
            break;
        }
        case MG_STAR:
        {   
            gesture = APP_START_MG_STAR;
            break;
        }
        default:
        {
            break;
        }
    }
}

APP_GESTURE_CMD APP_GetGesture(void)
{
    return gesture;
}

void APP_ClearGesture(void)
{
    gesture = APP_GEST_NONE;
}

PM_RESULT APP_PMCallbackFunc(PM_COMP_EVENT event, void * parm)
{
    switch(event)
    {
        case PM_COMP_EVENT_PREPARE:
        {
            if (appData.state == APP_STATE_SERVICE_TASKS &&
                APP_IMGFLASH_GetReadyStatus() == true)
            {
                return PM_OK;
            }
            
            return PM_FAILED;
        }
        case PM_COMP_EVENT_ABORT:
        {
            appData.state = APP_STATE_SERVICE_TASKS;
            
            break;
        }
        case PM_COMP_EVENT_POWER_DOWN:
        {
            APP_SetTargetBacklight(BACKLIGHT_SLEEP_PCT);
            
            appData.state = APP_STATE_POWERING_DOWN;
            
            break;
        }
        case PM_COMP_EVENT_POWER_UP:
        {
            SYS_TIME_TimerStart(timer);
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            appData.state = APP_STATE_POWERING_UP;
            
            break;
        }
        default:
            break;
    }
    
    return PM_OK;
}
/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            
            TC3_CompareStart();
            
            timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, CLOCK_TICK_TIMER_PERIOD_MS, SYS_TIME_PERIODIC);   
#ifdef PM_ENABLED            
            APP_PMID = pmRegisterComponent(PM_APP_COMP, APP_PMCallbackFunc, NULL);
#endif
            if (appInitialized)
            {
                app_inputListener.handleTouchDown = &app_touchDownHandler;
                app_inputListener.handleTouchUp = &app_touchUpHandler;
                app_inputListener.handleTouchMove = &app_touchMoveHandler;
                
                app_inputListener.handleFlickGesture = &FlickGestureHandler;
                app_inputListener.handlePinchGesture = &PinchGestureHandler;
                app_inputListener.handleStretchGesture = &StretchGestureHandler;
                app_inputListener.handleRotateGesture = &RotateGestureHandler;
                app_inputListener.handleGenericGesture = &GenericGestureHandler;

                SYS_INP_AddListener(&app_inputListener);

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
#ifdef RTOS_ENABLED
            static unsigned int sec_count_last;              

            if (stats_enabled == true && 
                sec_count != sec_count_last)
            {
                cpu_free = Task_Usage();
                sec_count_last = sec_count;
            }            
#else
            APP_IMGFLASH_Tasks();
#endif
            break;
        }
#ifdef PM_ENABLED        
        case APP_STATE_POWERING_DOWN:
        {
            if (APP_GetBacklightBrightness() <= BACKLIGHT_SLEEP_PCT)
            {
                SYS_TIME_TimerStop(timer);
                pmComponentSetState(APP_PMID, PM_COMP_POWERED_DOWN);
                appData.state = APP_STATE_SLEEP;
            }
            
            break;
        }        
        case APP_STATE_SLEEP:
        {
            break;
        }
        case APP_STATE_POWERING_UP:
        {
            if (APP_GetBacklightBrightness() >= BACKLIGHT_MAX_PCT)
            {
                pmComponentSetState(APP_PMID, PM_COMP_ACTIVE);
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            
            break;
        }
#endif        

        /* TODO: implement your application state machine.*/

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
