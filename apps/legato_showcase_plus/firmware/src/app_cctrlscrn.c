#include "definitions.h"
#include "app.h"
#include <stdio.h>
#include <string.h>

typedef enum
{
    CCTRL_SCRN_STATE_INIT,
    CCTRL_SCRN_STATE_WAIT_FOR_READY,
    CCTRL_SCRN_STATE_IDLE,
    CCTRL_SCRN_STATE_EXIT,
} CCTRL_SCRN_STATE;

static CCTRL_SCRN_STATE cctrl_state = CCTRL_SCRN_STATE_INIT;
static int nextScreen = 0;

void event_CCtrlScrn1_HomeButton_OnPressed (leButtonWidget* btn)
{
    nextScreen = screenID_Menu;
    cctrl_state = CCTRL_SCRN_STATE_EXIT;
}

void event_CCtrlScrn1_RightFanDownButton_OnPressed(leButtonWidget* btn)
{
    CCtrlScrn1_RightFanImageSequence->fn->showPreviousImage(CCtrlScrn1_RightFanImageSequence);
}

void event_CCtrlScrn1_RightFanUpButton_OnPressed(leButtonWidget* btn)
{
    CCtrlScrn1_RightFanImageSequence->fn->showNextImage(CCtrlScrn1_RightFanImageSequence);
}

void event_CCtrlScrn1_LeftFanUpButton_OnPressed(leButtonWidget* btn)
{
    CCtrlScrn1_LeftFanImageSequence->fn->showNextImage(CCtrlScrn1_LeftFanImageSequence);
}

void event_CCtrlScrn1_LeftFanDownButton_OnPressed(leButtonWidget* btn)
{
    CCtrlScrn1_LeftFanImageSequence->fn->showPreviousImage(CCtrlScrn1_LeftFanImageSequence);
}

void CCtrlScrn1_OnShow(void)
{
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    CCtrlScrn1_FPSLabel->fn->setVisible(CCtrlScrn1_FPSLabel, stats_enabled == true);  
    
    cctrl_state = CCTRL_SCRN_STATE_INIT;
}

void CCtrlScrn1_OnHide(void)
{
    fpsStr.fn->destructor(&fpsStr);
}

void CCtrlScrn1_OnUpdate(void)
{
    switch (cctrl_state)
    {
        case CCTRL_SCRN_STATE_INIT:
        {
            nextScreen = 0;
            APP_ClearGesture();
            cctrl_state = CCTRL_SCRN_STATE_WAIT_FOR_READY;
            break;
        }
        case CCTRL_SCRN_STATE_WAIT_FOR_READY:
        {
            if(leGetRenderState()->frameState != LE_FRAME_READY || 
               leEvent_GetCount() != 0 ||
               isDisplayReady() != true)
                break;
            
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;               

            GFX_DISP_INTF_PIN_BACKLIGHT_Set();               
            
            cctrl_state = CCTRL_SCRN_STATE_IDLE;
            
            break;
        }
        case CCTRL_SCRN_STATE_IDLE:
        {
            APP_GESTURE_CMD gesture = APP_GetGesture();
            
            //check for gestures
            if (gesture != APP_GEST_NONE)
            {
                switch(gesture)
                {
                    case APP_GEST_RIGHT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_CkrScrn1;
                        cctrl_state = CCTRL_SCRN_STATE_EXIT;
                        break;
                    }
                    case APP_GEST_LEFT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_MGScrn;
                        cctrl_state = CCTRL_SCRN_STATE_EXIT;
                        break;
                    }                    
                    case APP_START_MG_M:
                    {
                        nextScreen = screenID_Menu;
                        cctrl_state = CCTRL_SCRN_STATE_EXIT;
                        break;
                    }
                    case APP_START_MG_S:
                    {
                        nextScreen = screenID_Intro;
                        cctrl_state = CCTRL_SCRN_STATE_EXIT;
                        break;
                    }                    
                    default:
                        break;
                }
                
                APP_ClearGesture();
            }               
            break;
        }
        case CCTRL_SCRN_STATE_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
            
            legato_showScreen(nextScreen);
            
            break;
        }
        default:
            break;
    }
    
    if (stats_enabled == true &&
        last_sec_count != sec_count)
    {
        //update fps
        sprintf(fpsStrBuff, "%u fps", fps);
        fpsStr.fn->setFromCStr(&fpsStr, fpsStrBuff);    
        CCtrlScrn1_FPSLabel->fn->setString(CCtrlScrn1_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    }      
}