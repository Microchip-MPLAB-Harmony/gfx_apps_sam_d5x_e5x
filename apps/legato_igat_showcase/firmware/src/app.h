/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"
#include "app_pwrmgr.h"

//APP settings
//#define DEMO_MODE_OPTION_ENABLED 1
#ifdef RTOS_ENABLED
#define CLOCK_TICK_TIMER_PERIOD_MS 10
#else
#define CLOCK_TICK_TIMER_PERIOD_MS 30
#endif





#define NUM_COUNT_SEC_TICK (1000/CLOCK_TICK_TIMER_PERIOD_MS)
#define NUM_COUNT_TAP_TICK (200/CLOCK_TICK_TIMER_PERIOD_MS) 
#define DEMO_MODE_IDLE_TIMEOUT_SECS 5
#define FPS_STR_SIZE 32
#define TIMESTAMP_STR_SIZE 36
#define BL_STEP_DELTA_PCT 20
#define BACKLIGHT_PWM_MAX_VALUE 100
#define BACKLIGHT_MAX_PCT 100    
#define BACKLIGHT_MIN_PCT 0
#define BACKLIGHT_SLEEP_PCT 1
    
//#define ENABLE_APP_DEMO 1
//#define SHOW_UPDATE_MESSAGE    
#define ENABLE_MG_DEMO 1

#define GFX_DISP_INTF_PIN_BACKLIGHT_Set() APP_SetBacklightBrightness(BACKLIGHT_MAX_PCT)
#define GFX_DISP_INTF_PIN_BACKLIGHT_Clear() APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT)  
    
// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,
    APP_STATE_SERVICE_TASKS,
    APP_STATE_POWERING_DOWN,
    APP_STATE_SLEEP,
    APP_STATE_POWERING_UP,
    /* TODO: Define states used by the application state machine. */

} APP_STATES;

typedef enum
{
    EVENT_NONE,
    EVENT_START_COOKING,
    EVENT_STOP_COOKING,
    EVENT_PAUSE_COOKING,
    EVENT_CONTINUE_COOKING,
    EVENT_CHANGE_SCENE, 
    EVENT_SET_COOK_TIME,
    EVENT_EXIT_SCREEN,

    START_COOKING,
    STOP_COOKING,
    SELECT_ITEM_0,
    SELECT_ITEM_1,
    SELECT_ITEM_2,
    SELECT_ITEM_3,
    CHANGE_SCENE,
    SET_COOK_TIME,
    EXIT_TO_MENU, 
} APP_EVENTS;

typedef enum
{
    APP_GEST_START,
    APP_GEST_UP_SWIPE = APP_GEST_START,
    APP_GEST_DOWN_SWIPE,
    APP_GEST_LEFT_SWIPE,            
    APP_GEST_RIGHT_SWIPE,
    APP_GEST_TAP,
    APP_GEST_TAP_DOUBLE,
    APP_GEST_DUAL_TAP,
    APP_GEST_WHEEL_CW,            
    APP_GEST_WHEEL_CCW,
    APP_GEST_PINCH,
    APP_GEST_ZOOM,
    //Dual Swipes
    APP_GEST_LEFT_SWIPE_DUAL,
    APP_GEST_RIGHT_SWIPE_DUAL,     
    //Edge Gestures
    APP_GEST_UP_EDGE_SWIPE,
    APP_GEST_DOWN_EDGE_SWIPE,
    APP_GEST_LEFT_EDGE_SWIPE,
    APP_GEST_RIGHT_EDGE_SWIPE,
    //Hold Gestures
    APP_START_GESTURE_HOLD,
    APP_GEST_UP_SWIPE_HOLD = APP_START_GESTURE_HOLD,
    APP_GEST_DOWN_SWIPE_HOLD,
    APP_GEST_LEFT_SWIPE_HOLD,            
    APP_GEST_RIGHT_SWIPE_HOLD,
    APP_GEST_TAP_HOLD,
    APP_GEST_DUAL_TAP_HOLD,
    APP_GEST_BASIC_END = APP_GEST_DUAL_TAP_HOLD,
#ifdef ENABLE_MG_DEMO            
    //Motion Gestures
    APP_START_MG_GESTURES,
    APP_START_MG_M = APP_START_MG_GESTURES,
    APP_START_MG_S,
    APP_START_MG_2,
    APP_START_MG_CHECK,
    APP_START_MG_ALPHA,
    APP_START_MG_STAR,
#endif            
    APP_MAX_GESTURE,
    APP_GEST_NONE = APP_MAX_GESTURE,
} APP_GESTURE_CMD;

typedef struct
{
    unsigned int timeout;
    APP_EVENTS event;
} DEMO_MODE_OBJ;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

extern int clock_sec;
extern int clock_min;
extern int clock_hr;

extern unsigned int idle_secs;
extern unsigned int demo_mode_count_secs;
extern unsigned int demo_mode_event_idx;
extern bool demo_mode_on;
extern bool demo_mode_enabled;

extern volatile unsigned int tick_count;
extern unsigned int tick_count_last;
extern volatile unsigned int sec_count;
extern int last_sec_count;
extern unsigned int fps;
extern unsigned int cpu_free;
extern char fpsStrBuff[];
extern bool stats_enabled;
extern leChar fpsStrCharBuff[];
extern leFixedString fpsStr;

extern APP_EVENTS app_event;
extern uint32_t event_parm;

bool isDisplayReady(void);

void APP_Tasks( void );

void app_send_event(APP_EVENTS evt);

void APP_IMGFLASH_StartDownload (void);
void APP_IMGFLASH_StopDownload (void);
void APP_IMGFLASH_Tasks( void );
void APP_IMGFLASH_Initialize( void );
bool APP_IMGFLASH_GetReadyStatus(void);

void APP_ShowSQIUpdateLog(char * str);

void APP_SetBacklightBrightness(unsigned int pct);
unsigned int APP_GetBacklightBrightness(void);
void APP_SetTargetBacklight(unsigned int pct);

APP_GESTURE_CMD APP_GetGesture(void);
void APP_ClearGesture(void);

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

