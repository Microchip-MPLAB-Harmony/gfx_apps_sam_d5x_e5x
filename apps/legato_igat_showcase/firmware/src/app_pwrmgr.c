/* 
 * File:   app_pwrmgr.c
 * Author: C18797
 *
 * Created on August 24, 2021, 8:32 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "app_pwrmgr.h"

#define MAX_NODES 4
#define PM_GET_ID(comp, node) ((comp * MAX_NODES) + node)
#define PM_GET_COMP(id) (id / MAX_NODES)
#define PM_GET_NODE(id) (id % MAX_NODES)
#define PM_MAX_COMP_NODES (PM_MAX_COMP * MAX_NODES)

typedef struct
{
    PM_CALLBACK_FN callback;
    void * parm;
    PM_COMP_STATE state;
} PM_COMP_NODE;

static PM_STATES pm_state;
static PM_EVENTS pm_event;
static PM_COMP_NODE pm_comp[PM_MAX_COMP][MAX_NODES];
static unsigned int pm_last_sec_count;

void APP_PWRMGR_Initialize(void)
{
    pm_state = PM_INITIALIZING;
    pm_event = PM_EVENT_NONE;
    pm_last_sec_count = 0;
    memset(pm_comp, 0, sizeof(PM_COMP_NODE) * PM_MAX_COMP * MAX_NODES);
}

void APP_PWRMGR_Tasks(void)
{
    static unsigned int comp;
    static unsigned int node;
    
    switch(pm_state)
    {
        case PM_INITIALIZING:
        {
            pm_state = PM_RUNNING;
            
            break;
        }
        case PM_RUNNING:
        {
            //Check for events and idle
            if (pm_last_sec_count != sec_count)
            {
                idle_secs++;
                LED0_Toggle();
                
                if (idle_secs > IDLE_TIMEOUT_SECS)
                {
                    pmSendEvent(PM_EVENT_POWER_DOWN);
                    idle_secs = 0;
                }
                
                pm_last_sec_count = sec_count;
            }
            
            switch(pm_event)
            {
                case PM_EVENT_POWER_DOWN:
                {
                    pm_state = PM_PREPARING;
                    break;
                }
                //Any event will reset the idle timer
                case PM_EVENT_INPUT:
                {
                    idle_secs = 0;
                    break;
                }
                default:
                {
                    break;
                }
            }
            
            pm_event = PM_EVENT_NONE;
            
            break;
        }
        case PM_PREPARING:
        {
            for (comp = 0; comp < PM_MAX_COMP; comp++)
            {
                for (node = 0; node < MAX_NODES; node++)
                {
                    PM_RESULT result;
                    if (pm_comp[comp][node].state != PM_COMP_FREE)
                    {
                        result = pm_comp[comp][node].callback(PM_COMP_EVENT_PREPARE, pm_comp[comp][node].parm);

                        //cannot power down, abort back to running state
                        if (result != PM_OK)
                        {
                            pm_state = PM_COMP_EVENT_ABORTING;
                            return;
                        }
                    }
                }
            }
            
            comp = 0;
            node = 0;
            pm_state = PM_POWERING_DOWN;
            
            break;
        }
        case PM_COMP_EVENT_ABORTING:
        {
            for (comp = 0; comp < PM_MAX_COMP; comp++)
            {
                for (node = 0; node < MAX_NODES; node++)
                {
                    if (pm_comp[comp][node].state != PM_COMP_FREE)
                    {
                        pm_comp[comp][node].callback(PM_COMP_EVENT_ABORT, pm_comp[comp][node].parm);
                    }
                }
            }
            
            pm_state = PM_RUNNING;
                        
            break;
        }
        case PM_POWERING_DOWN:
        {
            for (node = 0; node < MAX_NODES; node++)
            {
                if (pm_comp[comp][node].state != PM_COMP_FREE)
                {                
                    pm_comp[comp][node].callback(PM_COMP_EVENT_POWER_DOWN, pm_comp[comp][node].parm);
                }
            }
            
            pm_state = PM_POWERING_DOWN_WAIT;
            
            node = 0;
                    
            break;
        }
        case PM_POWERING_DOWN_WAIT:
        {
            while (node < MAX_NODES)
            {
                if (pm_comp[comp][node].state != PM_COMP_FREE && 
                    pm_comp[comp][node].state != PM_COMP_POWERED_DOWN)
                    return;
                
                node++;
            }
            
            if (comp == PM_MAX_COMP - 1)
            {
                LED0_InputEnable();
                pm_state = PM_SLEEPING;
                node = 0;
            }
            else
            {
                comp += 1;
                pm_state = PM_POWERING_DOWN;
            }
            
            break;
        }
        case PM_SLEEPING:
        {
            PM_IdleModeEnter();
            switch(pm_event)
            {
                case PM_EVENT_INPUT:
                    //no break, fall through
                case PM_EVENT_POWER_UP:
                {
                    idle_secs = 0;
                    pm_state = PM_POWERING_UP;
                    break;
                }
                default:
                {
                    break;
                }
            }            
            
            break;
        }
        case PM_POWERING_UP:
        {
            for (node = 0; node < MAX_NODES; node++)
            {
                if (pm_comp[comp][node].state != PM_COMP_FREE)
                {                
                    pm_comp[comp][node].callback(PM_COMP_EVENT_POWER_UP, pm_comp[comp][node].parm);
                }
            }
            
            pm_state = PM_POWERING_UP_WAIT;
            
            node = 0;
           
            break;
        }
        case PM_POWERING_UP_WAIT:
        {
            while (node < MAX_NODES)
            {
                if (pm_comp[comp][node].state != PM_COMP_FREE && 
                    pm_comp[comp][node].state != PM_COMP_ACTIVE)
                    return;
                
                node++;
            }
            
            if (comp == PM_MIN_COMP)
            {
                LED0_OutputEnable();
                pm_state = PM_RUNNING;
                comp = PM_MIN_COMP;
                idle_secs = 0;
                node = 0;
            }
            else
            {
                comp -= 1;
                pm_state = PM_POWERING_UP;
            }
            
            break;
        }
        default:
            break;
    }
}

PM_RESULT pmRegisterComponent(PM_COMP comp, PM_CALLBACK_FN callback, void * parm)
{
    unsigned int node;
    
    if (comp >= PM_MAX_COMP ||
        callback == NULL)
        return PM_FAILED;
    
    for (node = 0; node < MAX_NODES; node++)
    {
        if (pm_comp[comp][node].state == PM_COMP_FREE)
        {
            pm_comp[comp][node].callback = callback;
            pm_comp[comp][node].parm = parm;
            pm_comp[comp][node].state = PM_COMP_ACTIVE;
            
            return PM_GET_ID(comp, node);
        }
    }
  
    return PM_FAILED;
}

PM_RESULT pmRemoveComponent(int id)
{
    unsigned int node;
    unsigned int comp;
    
    if (id >= PM_MAX_COMP_NODES)
        return PM_FAILED;
    
    comp = PM_GET_COMP(id);
    node = PM_GET_NODE(id);
    
    if (pm_comp[comp][node].state != PM_COMP_FREE)
    {
        pm_comp[comp][node].callback = NULL;
        pm_comp[comp][node].parm = NULL;
        pm_comp[comp][node].state = PM_COMP_FREE;
        
        return PM_OK;
    }
    
    return PM_FAILED;
}

PM_RESULT pmComponentSetState(int id, PM_COMP_STATE state)
{
    unsigned int node;
    unsigned int comp;
    
    if (id >= PM_MAX_COMP_NODES)
        return PM_FAILED;
    
    comp = PM_GET_COMP(id);
    node = PM_GET_NODE(id);
    
    if (pm_comp[comp][node].state != PM_COMP_FREE)
    {
        pm_comp[comp][node].state = state;

        return PM_OK;
    }
    
    return PM_FAILED;

}

PM_RESULT pmSendEvent(PM_EVENTS event)
{
    if (event >= PM_EVENT_MAX)
        return PM_FAILED;
    
    pm_event = event;

    return PM_OK;
}