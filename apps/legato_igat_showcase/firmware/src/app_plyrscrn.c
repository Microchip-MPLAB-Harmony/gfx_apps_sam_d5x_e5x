#include "definitions.h"
#include "app.h"
#include <stdio.h>
#include <string.h>

typedef enum
{
    PLYR_SCRN_STATE_INIT,
    PLYR_SCRN_STATE_WAIT_FOR_READY,
    PLYR_SCRN_STATE_WAIT_FOR_BACKLIGHT_ON,            
    PLYR_SCRN_STATE_IDLE,
    PLYR_SCRN_STATE_SLIDE_LEFT,
    PLYR_SCRN_STATE_SLIDE_RIGHT,
    PLYR_SCRN_STATE_SLIDING_LEFT,
    PLYR_SCRN_STATE_SLIDING_RIGHT,
    PLYR_SCRN_STATE_WAIT_FOR_EXIT,             
} PLYR_SCRN_STATE;

static PLYR_SCRN_STATE state = PLYR_SCRN_STATE_INIT;
static leFixedString hrStr, minStr;
static leChar hrStrBuff[16] = {0};
static leChar minStrBuff[16] = {0};
static int nextScreen = 0;

void PlyrScrn_UpdateClock(void)
{
    char charBuff[16] = {0};
        
    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", (clock_hr % 12) ? (clock_hr % 12) : 12); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    PlyrScrn_HrLabel->fn->setString(PlyrScrn_HrLabel, (leString*)&hrStr);

    if (clock_hr >= 12)
        sprintf(charBuff, "%02u PM", clock_min); 
    else
        sprintf(charBuff, "%02u AM", clock_min); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    PlyrScrn_MinLabel->fn->setString(PlyrScrn_MinLabel, (leString*)&minStr);
}

static leBool VolumeButton_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{    
    leBool retval = LE_FALSE;

    int32_t x;
    
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            x = ((leWidgetEvent_TouchDown *) evt)->x;
            
            if (x >= PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel) + (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2) &&
                x <= PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel) + PlyrScrn_VolPanel->fn->getWidth(PlyrScrn_VolPanel))
            {
                unsigned int pct;
                
                PlyrScrn_VolumeButton->fn->setX(PlyrScrn_VolumeButton, x - (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2));
                PlyrScrn_VolPanelMax->fn->setX(PlyrScrn_VolPanelMax, PlyrScrn_VolumeButton->fn->getX(PlyrScrn_VolumeButton) + (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2));
                
                pct = ((x - PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel)) * 100) / PlyrScrn_VolPanel->fn->getWidth(PlyrScrn_VolPanel);
                if (pct > 10 && pct <= 100)
                {
                    APP_SetTargetBacklight(pct);
                }                
            }
            
            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            retval = LE_TRUE;
            
            break;
        }   
        case LE_EVENT_TOUCH_MOVE:            
        {
            x = ((leWidgetEvent_TouchMove *) evt)->x;
            
            if (x >= PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel) + (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2) &&
                x <= PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel) + PlyrScrn_VolPanel->fn->getWidth(PlyrScrn_VolPanel))
            {
                unsigned int pct;
                
                PlyrScrn_VolumeButton->fn->setX(PlyrScrn_VolumeButton, x - (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2));
                PlyrScrn_VolPanelMax->fn->setX(PlyrScrn_VolPanelMax, PlyrScrn_VolumeButton->fn->getX(PlyrScrn_VolumeButton) + (PlyrScrn_VolumeButton->fn->getWidth(PlyrScrn_VolumeButton)/2));
                
                pct = ((x - PlyrScrn_VolPanel->fn->getX(PlyrScrn_VolPanel)) * 100) / PlyrScrn_VolPanel->fn->getWidth(PlyrScrn_VolPanel);
                if (pct > 10 && pct <= 100)
                {
                    APP_SetTargetBacklight(pct);
                }
            }
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;
           
            break;
        }
        default:
            break;
    }
    
   return retval;
}

static leWidgetEventFilter VolumeButton_eventFilter =
{
    VolumeButton_filterEvent,
    NULL
};

void event_PlyrScrn_HomeButton_OnPressed(leButtonWidget* btn)
{
    nextScreen = screenID_Menu;
    state = PLYR_SCRN_STATE_WAIT_FOR_EXIT;
}

void event_PlyrScrn_UsbButton_OnPressed(leButtonWidget* btn)
{
    PlyrScrn_WifiButton->fn->setPressed(PlyrScrn_WifiButton, LE_FALSE);
    PlyrScrn_BtButton->fn->setPressed(PlyrScrn_BtButton, LE_FALSE);
    PlyrScrn_AuxButton->fn->setPressed(PlyrScrn_AuxButton, LE_FALSE);
}

void event_PlyrScrn_WifiButton_OnPressed(leButtonWidget* btn)
{
    PlyrScrn_UsbButton->fn->setPressed(PlyrScrn_UsbButton, LE_FALSE);
    PlyrScrn_BtButton->fn->setPressed(PlyrScrn_BtButton, LE_FALSE);
    PlyrScrn_AuxButton->fn->setPressed(PlyrScrn_AuxButton, LE_FALSE);
}

void event_PlyrScrn_BtButton_OnPressed(leButtonWidget* btn)
{
    PlyrScrn_WifiButton->fn->setPressed(PlyrScrn_WifiButton, LE_FALSE);
    PlyrScrn_UsbButton->fn->setPressed(PlyrScrn_UsbButton, LE_FALSE);
    PlyrScrn_AuxButton->fn->setPressed(PlyrScrn_AuxButton, LE_FALSE);
}

void event_PlyrScrn_AuxButton_OnPressed(leButtonWidget* btn)
{
    PlyrScrn_WifiButton->fn->setPressed(PlyrScrn_WifiButton, LE_FALSE);
    PlyrScrn_BtButton->fn->setPressed(PlyrScrn_BtButton, LE_FALSE);
    PlyrScrn_UsbButton->fn->setPressed(PlyrScrn_UsbButton, LE_FALSE);
}

void PlyrScrn_OnShow(void)
{
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultHour3,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute3,
                                                              0));
    
    PlyrScrn_VolPanelButton->fn->installEventFilter(PlyrScrn_VolPanelButton, VolumeButton_eventFilter);    
    
    PlyrScrn_UpdateClock();
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    PlyrScrn_FPSLabel->fn->setVisible(PlyrScrn_FPSLabel, stats_enabled == true);
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT);    
                
    state = PLYR_SCRN_STATE_INIT;
}

void PlyrScrn_OnHide(void)
{
    hrStr.fn->destructor(&hrStr);
    minStr.fn->destructor(&minStr);
    
    fpsStr.fn->destructor(&fpsStr);
    
    PlyrScrn_VolPanelButton->fn->removeEventFilter(PlyrScrn_VolPanelButton, VolumeButton_eventFilter);    
}

extern bool isDisplayReady(void);

void PlyrScrn_OnUpdate(void)
{
    switch (state)
    {
        case PLYR_SCRN_STATE_INIT:
        {
            //Flush out any gestures
            nextScreen = 0;
            APP_ClearGesture();
            state = PLYR_SCRN_STATE_WAIT_FOR_READY;
            break;
        }
        case PLYR_SCRN_STATE_WAIT_FOR_READY:
        {
            if(leRenderer_IsIdle() == LE_FALSE ||
               isDisplayReady() != true)
                break;
            
            state = PLYR_SCRN_STATE_WAIT_FOR_BACKLIGHT_ON;
            
            break;
        }
        case PLYR_SCRN_STATE_WAIT_FOR_BACKLIGHT_ON:
        {
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;            
            
            state = PLYR_SCRN_STATE_IDLE;
            
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            
            break;
        }
        case PLYR_SCRN_STATE_IDLE:
        {
            APP_GESTURE_CMD gesture = APP_GetGesture();
            //check for gestures
            if (gesture != APP_GEST_NONE)
            {
                switch(gesture)
                {
                    case APP_GEST_RIGHT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_CkrScrn2;
                        state = PLYR_SCRN_STATE_WAIT_FOR_EXIT;
                        break;
                    }
                    case APP_GEST_LEFT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_CkrScrn1;
                        state = PLYR_SCRN_STATE_WAIT_FOR_EXIT;
                        break;
                    }
                    case APP_START_MG_M:
                    {
                        nextScreen = screenID_Menu;
                        state = PLYR_SCRN_STATE_WAIT_FOR_EXIT;
                        break;
                    }
                    case APP_START_MG_S:
                    {
                        nextScreen = screenID_Intro;
                        state = PLYR_SCRN_STATE_WAIT_FOR_EXIT;
                        break;
                    }                     
                    case APP_GEST_WHEEL_CW:
                    {
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
                        
                        PlyrScrn_UpdateClock();
                        
                        break;
                    }
                    case APP_GEST_WHEEL_CCW:
                    {
                        clock_min--;
                        if (clock_min <= 0)
                        {
                            clock_min = 59;
                            clock_hr--;
                            if (clock_hr <= 0)
                            {
                                clock_hr = 24;
                            }
                        }
                        
                        PlyrScrn_UpdateClock();
                        
                        break;
                    }
                    default:
                        break;
                }
                
                APP_ClearGesture();
            }
            
            break;
        }
        case PLYR_SCRN_STATE_WAIT_FOR_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                break;
            
            legato_showScreen(nextScreen);
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            
            break;
        }
        default:
        {
            break;
        }
    }
    
    //Update Clock
    if (last_sec_count != sec_count)
    {
        static bool clock_dot_visible = true;    
        if (clock_dot_visible == true)
        {
            clock_dot_visible = false;
            PlyrScrn_ColonLabel->fn->setVisible(PlyrScrn_ColonLabel, LE_FALSE);
        }
        else
        {
            clock_dot_visible = true;
            PlyrScrn_ColonLabel->fn->setVisible(PlyrScrn_ColonLabel, LE_TRUE);
        }    

        PlyrScrn_UpdateClock();

        if (stats_enabled == true)
        {
            //update fps
#ifdef RTOS_ENABLED
        sprintf(fpsStrBuff, "%u fps, cpu %u%%", fps, 100 - cpu_free); 
#else
        sprintf(fpsStrBuff, "%u fps", fps);
#endif
            fpsStr.fn->setFromCStr(&fpsStr, fpsStrBuff);    
            PlyrScrn_FPSLabel->fn->setString(PlyrScrn_FPSLabel, (leString*)&fpsStr);          
        }

        last_sec_count = sec_count;
    }    
}