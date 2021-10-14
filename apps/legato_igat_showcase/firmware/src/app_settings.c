#include "definitions.h"
#include "app.h"
#include "app_qspi.h"
#include "app_usbd_cdc.h"
#include "gfx/legato/generated/le_gen_assets.h"

#include <stdio.h>
#include <string.h>
#define SQI_LOG_STR_SIZE 64

#ifdef RTOS_ENABLED
#define MIN_SCRATCH_BUFF_VALUE_KB 16
#define SCRATCH_BUFF_STR_SIZE 16
#endif

typedef enum
{
    SCRN_STATE_INIT,
    SCRN_STATE_IDLE,
    SCRN_STATE_EXIT,
} SETTINGS_SCRN_STATE;

typedef enum
{
    SCRN_EVENT_NONE,
    SCRN_EVENT_START_UPDATE,
    SCRN_EVENT_CONTINUE_UPDATE,
    SCRN_EVENT_CANCEL_UPDATE,
    SCRN_EVENT_ABORT_UPDATE,
    SCRN_EVENT_EXIT,
    SCRN_EVENT_SHOW_LOG,
    SCRN_EVENT_RESTART,
} SETTINGS_SCRN_EVENT;

static leFixedString sqiUpdateStr;
static char charBuff[SQI_LOG_STR_SIZE];
static leChar sqiUpdateStrBuff[SQI_LOG_STR_SIZE] = {0};
static SETTINGS_SCRN_STATE app_scrn_state;
static SETTINGS_SCRN_EVENT app_scrn_event;

static char timeStampStrBuff[TIMESTAMP_STR_SIZE];
static leChar timeStampStrCharBuff[TIMESTAMP_STR_SIZE] = {0};
static leFixedString timeStampStr;

#ifdef RTOS_ENABLED
static char scratchBuffStrBuff[SCRATCH_BUFF_STR_SIZE];
static leChar scratchBuffStrCharBuff[SCRATCH_BUFF_STR_SIZE] = {0};
static leFixedString scratchBuffStr;
#endif

extern bool mg_enabled;

void APP_ShowSQIUpdateLog(char * str)
{
    memcpy(charBuff, str, SQI_LOG_STR_SIZE - 1);
    charBuff[SQI_LOG_STR_SIZE - 1] = '\0';
    app_scrn_event = SCRN_EVENT_SHOW_LOG;
}

void event_Settings_UpdateSQIButton_OnPressed(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_START_UPDATE;
}

void event_Settings_UpdateSQIButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_ABORT_UPDATE;
}

void event_Settings_HomeButton_OnPressed(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_EXIT;

}

void event_Settings_EraseYesButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_CONTINUE_UPDATE;
}

void event_Settings_EraseNoButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_CANCEL_UPDATE;
}

void event_Settings_ToggleDemoModeButton_OnPressed(leButtonWidget* btn)
{
    demo_mode_enabled = true;
    Settings_DemoModeStatusString->fn->setString(Settings_DemoModeStatusString, (leString*)&string_EnabledString);
}

void event_Settings_ToggleDemoModeButton_OnReleased(leButtonWidget* btn)
{
    demo_mode_enabled = false;
    Settings_DemoModeStatusString->fn->setString(Settings_DemoModeStatusString, (leString*)&string_DisabledString);
}

void event_Settings_StatsEnableButton_OnPressed(leButtonWidget* btn)
{
    stats_enabled = true;
    Settings_StatsEnableLabel->fn->setString(Settings_StatsEnableLabel, (leString*)&string_EnabledString);
}

void event_Settings_StatsEnableButton_OnReleased(leButtonWidget* btn)
{
    stats_enabled = false;
    Settings_StatsEnableLabel->fn->setString(Settings_StatsEnableLabel, (leString*)&string_DisabledString);
}

void event_Settings_RebootButtonWidget0_OnPressed(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_RESTART;
}

void event_Settings_AdvancedGesturesEnable_OnPressed(leButtonWidget* btn)
{
    mg_enabled = true;
    Settings_MGInfoLabel->fn->setString(Settings_MGInfoLabel, (leString*)&string_EnabledString);
}

void event_Settings_AdvancedGesturesEnable_OnReleased(leButtonWidget* btn)
{
    mg_enabled = false;
    Settings_MGInfoLabel->fn->setString(Settings_MGInfoLabel, (leString*)&string_DisabledString);
}

#ifdef RTOS_ENABLED
void event_Settings_ScatchBuffSlider_OnValueChanged(leSliderWidget* scr)
{
    uint32_t value;
    
    value = (((LE_SCRATCH_BUFFER_SIZE_KB - MIN_SCRATCH_BUFF_VALUE_KB) * scr->value) / 100) +
            MIN_SCRATCH_BUFF_VALUE_KB;
        
    leSetScratchBufferSizeKB((value > LE_SCRATCH_BUFFER_SIZE_KB) ? 
                              LE_SCRATCH_BUFFER_SIZE_KB : value);
    
    sprintf(scratchBuffStrBuff, "%u kB", 
            (unsigned int)((value > LE_SCRATCH_BUFFER_SIZE_KB) ? 
                            LE_SCRATCH_BUFFER_SIZE_KB : value));
    scratchBuffStr.fn->setFromCStr(&scratchBuffStr, scratchBuffStrBuff);   
    Settings_ScatchBufferSizeLabel->fn->setString(Settings_ScatchBufferSizeLabel,
                                            (leString*)&scratchBuffStr);     
}
#endif

void Settings_OnShow(void)
{
#ifdef RTOS_ENABLED     
    uint32_t scratchBuffVal;
#endif
    
    Settings_DemoModeStatusString->fn->setVisible(Settings_DemoModeStatusString, false);
    Settings_ToggleDemoModeButton->fn->setVisible(Settings_ToggleDemoModeButton, false);

    Settings_StatsEnableButton->fn->setPressed(Settings_StatsEnableButton, (stats_enabled == true));
    Settings_AdvancedGesturesEnable->fn->setPressed(Settings_AdvancedGesturesEnable, (mg_enabled == true));
    
    Settings_SQIUpdateWarningLabel->fn->setVisible(Settings_SQIUpdateWarningLabel, LE_FALSE);
    
    leFixedString_Constructor(&sqiUpdateStr, sqiUpdateStrBuff, SQI_LOG_STR_SIZE);
    sqiUpdateStr.fn->setFont(&sqiUpdateStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DisabledString,
                                                              0));
    
    leFixedString_Constructor(&timeStampStr, timeStampStrCharBuff, TIMESTAMP_STR_SIZE);
    timeStampStr.fn->setFont(&timeStampStr, (leFont*)&FPS_Font);
    sprintf(timeStampStrBuff, "Build: %s", __TIMESTAMP__);
    timeStampStr.fn->setFromCStr(&timeStampStr, timeStampStrBuff);   
    Settings_TimeStampString->fn->setString(Settings_TimeStampString,
                                            (leString*)&timeStampStr);

#ifdef RTOS_ENABLED     
    //Update scratch buffer slider value and label
    scratchBuffVal = leGetScratchBufferSizeKB();
    
    leFixedString_Constructor(&scratchBuffStr, scratchBuffStrCharBuff, SCRATCH_BUFF_STR_SIZE);
    timeStampStr.fn->setFont(&scratchBuffStr, (leFont*)&FPS_Font);    

    sprintf(scratchBuffStrBuff, "%u kB", (unsigned int)scratchBuffVal);
    scratchBuffStr.fn->setFromCStr(&scratchBuffStr, scratchBuffStrBuff);   
    Settings_ScatchBufferSizeLabel->fn->setString(Settings_ScatchBufferSizeLabel,
                                            (leString*)&scratchBuffStr);      
    Settings_ScatchBuffSlider->fn->setValue(Settings_ScatchBuffSlider, 
                      ((scratchBuffVal - MIN_SCRATCH_BUFF_VALUE_KB) * 100) /
                      (LE_SCRATCH_BUFFER_SIZE_KB - MIN_SCRATCH_BUFF_VALUE_KB));
#endif
    
    app_scrn_state = SCRN_STATE_INIT;
    app_scrn_event = SCRN_EVENT_NONE;
}

void Settings_OnHide(void)
{
    sqiUpdateStr.fn->destructor(&sqiUpdateStr);
    timeStampStr.fn->destructor(&timeStampStr);
#ifdef RTOS_ENABLED     
    scratchBuffStr.fn->destructor(&scratchBuffStr);
#endif
}

void Settings_OnUpdate(void)
{
    switch(app_scrn_state)
    {
        case SCRN_STATE_INIT:
        {
            if(leGetRenderState()->frameState != LE_FRAME_READY || leEvent_GetCount() != 0)
                break;
    
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;               

            GFX_DISP_INTF_PIN_BACKLIGHT_Set(); 
            
            app_scrn_state = SCRN_STATE_IDLE;
            
            break;
        }
        case SCRN_STATE_IDLE:
        {
            switch (app_scrn_event)
            {
                case SCRN_EVENT_START_UPDATE:
                {
                    Settings_SQIUpdateWarningLabel->fn->setVisible(Settings_SQIUpdateWarningLabel, LE_TRUE);
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_CONTINUE_UPDATE:
                {
                    Settings_SQIUpdateWarningLabel->fn->setVisible(Settings_SQIUpdateWarningLabel, LE_FALSE);
                    APP_IMGFLASH_StartDownload ();
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_CANCEL_UPDATE:
                {
                    Settings_UpdateSQIButton->fn->setPressed(Settings_UpdateSQIButton, LE_FALSE);
                    Settings_SQIUpdateWarningLabel->fn->setVisible(Settings_SQIUpdateWarningLabel, LE_FALSE);
                    Settings_SQIUpdateStatusString->fn->setString(Settings_SQIUpdateStatusString, NULL);
                    
                    app_scrn_event = SCRN_EVENT_NONE;
                    
                    break;
                }
                case SCRN_EVENT_ABORT_UPDATE:
                {
                    APP_IMGFLASH_StopDownload();
                    app_scrn_event = SCRN_EVENT_NONE;
                    Settings_SQIUpdateStatusString->fn->setString(Settings_SQIUpdateStatusString, NULL);
                    
                    break;
                }
                case SCRN_EVENT_SHOW_LOG:
                {
                    if (strlen(charBuff) < SQI_LOG_STR_SIZE)
                    {
                        sqiUpdateStr.fn->setFromCStr(&sqiUpdateStr, charBuff);    
                        Settings_SQIUpdateStatusString->fn->setString(Settings_SQIUpdateStatusString,
                                                                     (leString*)&sqiUpdateStr);  
                    }
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_RESTART:
                {
                    APP_IMGFLASH_StopDownload();
                    GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
                    legato_showScreen(screenID_Intro);
                    
                    app_scrn_event = SCRN_EVENT_NONE;
                    
                    break;
                }
                case SCRN_EVENT_EXIT:
                {
                    APP_IMGFLASH_StopDownload();
                    app_scrn_state = SCRN_STATE_EXIT;
                }
                default:
                    break;
            }
            break;
        }
        case SCRN_STATE_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
            
            legato_showScreen(screenID_Menu);
            
            break;
        }
        default:
            break;
    }
}