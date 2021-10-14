/* 
 * File:   app_pwrmgr.h
 * Author: C18797
 *
 * Created on August 24, 2021, 8:34 AM
 */

#ifndef APP_PWRMGR_H
#define	APP_PWRMGR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define IDLE_TIMEOUT_SECS 30
    
typedef enum
{
    PM_INITIALIZING,        //initialization
    PM_RUNNING,             //running, waiting for power save events
    PM_PREPARING,           //preparing for low power mode
    PM_COMP_EVENT_ABORTING,            //aborting low power mode transition
    PM_POWERING_DOWN,       //powering down components
    PM_POWERING_DOWN_WAIT,  //waiting for components to power down
    PM_SLEEPING,            //powered down, sleeping, waiting for wake up
    PM_POWERING_UP,          //powering up components
    PM_POWERING_UP_WAIT,    //waiting for components to power up
} PM_STATES;

typedef enum
{
    PM_MIN_COMP = 0,
    PM_APP_COMP = PM_MIN_COMP,
    PM_MIDDLEWARE_COMP,
    PM_DRIVER_COMP,
    PM_PLIB_COMP,
    PM_SYSTEM_COMP,
    PM_MAX_COMP,
} PM_COMP;

typedef enum
{
    PM_COMP_FREE = 0,
    PM_COMP_ACTIVE,
    PM_COMP_READY,
    PM_COMP_POWERED_DOWN,
} PM_COMP_STATE;

typedef enum
{
    PM_COMP_EVENT_PREPARE,     //check if components can power down
    PM_COMP_EVENT_ABORT,       //abort power down
    PM_COMP_EVENT_POWER_DOWN,  //start power down process
    PM_COMP_EVENT_POWER_UP,    //start power up process
} PM_COMP_EVENT;

typedef enum
{
    PM_EVENT_NONE,
    PM_EVENT_INPUT,
    PM_EVENT_POWER_DOWN,
    PM_EVENT_POWER_UP,
    PM_EVENT_MAX,
} PM_EVENTS;

typedef enum
{
    PM_OK,
    PM_FAILED = -1,
    PM_NOT_READY = -2,
} PM_RESULT;

typedef PM_RESULT (*PM_CALLBACK_FN) (PM_COMP_EVENT event, void * parm);

PM_RESULT pmRegisterComponent(PM_COMP comp, PM_CALLBACK_FN callback, void * parm);
PM_RESULT pmRemoveComponent(int id);
PM_RESULT pmComponentSetState(int id, PM_COMP_STATE state);
PM_RESULT pmSendEvent(PM_EVENTS event);

void APP_PWRMGR_Tasks(void);
void APP_PWRMGR_Initialize(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APP_PWRMGR_H */

