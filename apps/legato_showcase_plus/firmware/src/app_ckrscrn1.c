#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"
#include "app.h"

#include <stdio.h>
#include <string.h>

#define PROGRESS_BAR_BLOCK_EXTEND 10
#define DELTA_RECT_PIX 30
#define COOK_TIME_SECS 60

typedef enum
{
    MAIN_MENU_INIT,
    MAIN_MENU_INIT2,
    MAIN_MENU_PROCESS,
    MAIN_MENU_PREPARE_PROGRESS_SCENE1,
    MAIN_MENU_PREPARE_PROGRESS_SCENE2,
    MAIN_MENU_PREPARE_PROGRESS_SCENE3,
    MAIN_MENU_PREPARE_PROGRESS_SCENE4,
    MAIN_MENU_PREPARE_PROGRESS_SCENE5,
    MAIN_MENU_PREPARE_PROGRESS_SCENE6,            
    MAIN_MENU_PREPARE_PROGRESS_SCENE7,
    MAIN_MENU_PREPARE_PROGRESS_SCENE8,
    MAIN_MENU_SHOW_PROGRESS_SCENE,
    MAIN_MENU_PROCESS_PROGRESS_SCENE,
    MAIN_MENU_DONE_PROGRESS_SCENE,
    MAIN_MENU_IDLE_PROGRESS_SCENE,
    SCREEN_EXIT_PROGRESS_SCENE1,
    SCREEN_EXIT_PROGRESS_SCENE2,        
    SCREEN_EXIT_PROGRESS_SCENE3,
    SCREEN_EXIT_PROGRESS_SCENE4,
    SCREEN_EXIT_PROGRESS_SCENE5,
    SCREEN_EXIT_PROGRESS_SCENE6,
    SCREEN_EXIT_PROGRESS_SCENE7,
    MAIN_MENU_SHOW_MAIN,
    MAIN_MENU_CHANGE_SCREEN,
    MAIN_MENU_IDLE,
    SCREEN_EXIT,
} MAIN_MENU_SCENE_STATE;

typedef enum
{
    BAKE_MODE,
    COOK_MODE,
    REHEAT_MODE,
    BROIL_MODE,
} OPERATION_MODE;

static MAIN_MENU_SCENE_STATE CkrScrn1_menu_state = MAIN_MENU_INIT;
static OPERATION_MODE mode;
static leFixedString hrStr, minStr, progressStr;
static leChar hrStrBuff[16] = {0};
static leChar minStrBuff[16] = {0};
static leChar progressStrBuff[16] = {0};
char charBuff[16] = {0};    
static unsigned int width, x;
static int cookSec = COOK_TIME_SECS;

static int nextScreen = 0;

//This should match the listwheel items
leImage * smart_favorites_images[] =
{
    &hotdog70,
    &kabobs70,
    &meat70,
    &bacon70,
    &veggies70,    
};

leImage * mode_images[] = 
{
    &bake100,
    &cook100,
    &reheat100,
    &broil100,
    
};

static void startMode(OPERATION_MODE new_mode)
{
    mode = new_mode;
    app_event = EVENT_START_COOKING;
}

static bool show_CkrScrn1_menu(bool show)
{
    leBool lshow = (show == true) ? LE_TRUE : LE_FALSE;
    const leScheme* scheme = (show == true) ? &WhiteTextScheme : &OffWhiteTextScheme;
    
    CkrScrn1_MainPanel->fn->setVisible(CkrScrn1_MainPanel, lshow);
    CkrScrn1_PanelWidget3->fn->setVisible(CkrScrn1_PanelWidget3, lshow);
    CkrScrn1_ImageWidget1->fn->setVisible(CkrScrn1_ImageWidget1, lshow);
    CkrScrn1_ImageWidget2->fn->setVisible(CkrScrn1_ImageWidget2, lshow);
    CkrScrn1_ImageWidget3->fn->setVisible(CkrScrn1_ImageWidget3, lshow);
    CkrScrn1_ImageWidget4->fn->setVisible(CkrScrn1_ImageWidget4, lshow);
    CkrScrn1_ImageWidget8->fn->setVisible(CkrScrn1_ImageWidget8, lshow);
    
    CkrScrn1_HourLabel->fn->setScheme(CkrScrn1_HourLabel, scheme);
    CkrScrn1_ColonLabel->fn->setScheme(CkrScrn1_ColonLabel, scheme);
    CkrScrn1_MinuteLabel->fn->setScheme(CkrScrn1_MinuteLabel, scheme);
    
    return true;
}


static leBool CkrScrn1_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        case LE_EVENT_TOUCH_MOVE:            
        {
            int x;
            uint32_t width = target->fn->getWidth(target);
            int startx = target->fn->getX(target);
            
            if (evt->id == LE_EVENT_TOUCH_DOWN)
            {
                leWidgetEvent_TouchDown * down = (leWidgetEvent_TouchDown *) evt;
                x = down->x;
            }
            else
            {
                leWidgetEvent_TouchMove * move = (leWidgetEvent_TouchMove *) evt;
                x = move->x;
            }

            if (x < startx)
                event_parm = 0;
            else if (x > startx + width)
                event_parm = 100;
            else
                event_parm = ((x - startx) * 100)/width;
            
            app_event = EVENT_SET_COOK_TIME;
            
            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    
    return LE_FALSE;
}

static leWidgetEventFilter CkrScrn1_eventFilter =
{
    CkrScrn1_filterEvent,
    NULL
};


// event handlers
void CkrScrn1_OnShow(void)
{
    CkrScrn1_menu_state = MAIN_MENU_INIT;
    app_event = EVENT_NONE;   
    
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));
    
    leFixedString_Constructor(&progressStr, progressStrBuff, 16);
    progressStr.fn->setFont(&progressStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultCookTime,
                                                              0));
    
    CkrScrn1_SliderButton0->fn->installEventFilter(CkrScrn1_SliderButton0, CkrScrn1_eventFilter);
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    CkrScrn1_FPSLabel->fn->setVisible(CkrScrn1_FPSLabel, stats_enabled == true);  
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT); 
    
}

void CkrScrn1_OnHide(void)
{
    hrStr.fn->destructor(&hrStr);
    minStr.fn->destructor(&minStr);
    progressStr.fn->destructor(&progressStr);
    
    fpsStr.fn->destructor(&fpsStr);
}

static void CkrScrn1_UpdateClock(void)
{
    static bool clock_dot_visible = true;    
    char charBuff[16] = {0};

    if (clock_dot_visible == true)
    {
        clock_dot_visible = false;
        CkrScrn1_ColonLabel->fn->setVisible(CkrScrn1_ColonLabel, LE_FALSE);
    }
    else
    {
        clock_dot_visible = true;
        CkrScrn1_ColonLabel->fn->setVisible(CkrScrn1_ColonLabel, LE_TRUE);
    }    

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", clock_hr); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    CkrScrn1_HourLabel->fn->setString(CkrScrn1_HourLabel, (leString*)&hrStr);   

    sprintf(charBuff, "%02u", clock_min); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    CkrScrn1_MinuteLabel->fn->setString(CkrScrn1_MinuteLabel, (leString*)&minStr);

    if (demo_mode_on)
    {
        CkrScrn1_DemoModeOnButton->fn->setVisible(CkrScrn1_DemoModeOnButton, sec_count%2);        
    }

    if (stats_enabled == true)
    {
        //update fps
        sprintf(fpsStrBuff, "%u fps", fps);
        fpsStr.fn->setFromCStr(&fpsStr, fpsStrBuff);    
        CkrScrn1_FPSLabel->fn->setString(CkrScrn1_FPSLabel, (leString*)&fpsStr);
    }
}

void CkrScrn1_OnUpdate(void)
{
    //Wait for the library to be done drawing before processing events/animation
    if(leGetRenderState()->frameState != LE_FRAME_READY || leEvent_GetCount() != 0)
        return;
    
    switch(CkrScrn1_menu_state)
    {
        case MAIN_MENU_INIT:
        {
            idle_secs = 0;
            demo_mode_count_secs = 0;
            demo_mode_event_idx = 0;
            
            CkrScrn1_menu_state = MAIN_MENU_INIT2;
            
            nextScreen = 0;
            APP_ClearGesture();
            
            break;
        }
        case MAIN_MENU_INIT2:
        {
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;            
            
            CkrScrn1_menu_state = MAIN_MENU_PROCESS;
            
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            
            break;
        }
        case MAIN_MENU_PROCESS:
        {
            APP_GESTURE_CMD gesture;
                    
            switch(app_event)
            {
                case EVENT_START_COOKING:
                {
                    CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE1;
                    app_event = EVENT_NONE;
                    break;
                }
                case EVENT_CHANGE_SCENE:
                {
                    CkrScrn1_menu_state = MAIN_MENU_CHANGE_SCREEN;
                    app_event = EVENT_NONE;
                    break;
                }
                case EVENT_EXIT_SCREEN:
                {
                    CkrScrn1_menu_state = SCREEN_EXIT;
                    nextScreen = screenID_Menu;
                    app_event = EVENT_NONE;
                    break;
                }                
                default:
                    break;
            }
            
            gesture = APP_GetGesture();
            
            //check for gestures
            if (gesture != APP_GEST_NONE)
            {
                switch(gesture)
                {
                    case APP_GEST_RIGHT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_PlyrScrn;
                        CkrScrn1_menu_state = SCREEN_EXIT;
                        break;
                    }
                    case APP_GEST_LEFT_SWIPE_DUAL:
                    {
                        nextScreen = screenID_CCtrlScrn1;
                        CkrScrn1_menu_state = SCREEN_EXIT;
                        break;
                    }
                    case APP_START_MG_M:
                    {
                        nextScreen = screenID_Menu;
                        CkrScrn1_menu_state = SCREEN_EXIT;
                        break;
                    }
                    case APP_START_MG_S:
                    {
                        nextScreen = screenID_Intro;
                        CkrScrn1_menu_state = SCREEN_EXIT;
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
                        
                        CkrScrn1_UpdateClock();
                        
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
                        
                        CkrScrn1_UpdateClock();
                        
                        break;
                    }                    
                    default:
                        break;
                }
                
                APP_ClearGesture();
            }            
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE1:
        {
            show_CkrScrn1_menu(false);
            CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE2;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE2:
        {
            //Prepare to show progress panel
            CkrScrn1_PanelWidget0->fn->setX(CkrScrn1_PanelWidget0, 0);   
            
            //Restore and show black rects to hide border
            CkrScrn1_RectangleWidget0->fn->setVisible(CkrScrn1_RectangleWidget0, LE_TRUE);
            CkrScrn1_RectangleWidget1->fn->setVisible(CkrScrn1_RectangleWidget1, LE_TRUE);
            CkrScrn1_RectangleWidget2->fn->setVisible(CkrScrn1_RectangleWidget2, LE_TRUE);
            CkrScrn1_RectangleWidget3->fn->setVisible(CkrScrn1_RectangleWidget3, LE_TRUE); 
            CkrScrn1_RectangleWidget0->fn->setWidth(CkrScrn1_RectangleWidget0, 340);
            CkrScrn1_RectangleWidget0->fn->setX(CkrScrn1_RectangleWidget0, 66);
            CkrScrn1_RectangleWidget1->fn->setWidth(CkrScrn1_RectangleWidget1, 340);
            CkrScrn1_RectangleWidget1->fn->setX(CkrScrn1_RectangleWidget1, 66);
            
            //Reset and hide the progress indicators
            CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, 0);
            CkrScrn1_ProgressBarWidget0->fn->setVisible(CkrScrn1_ProgressBarWidget0, LE_FALSE);
            CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_FALSE);
            CkrScrn1_CancelButton->fn->setPressedImage(CkrScrn1_CancelButton, &cancel_80);
            CkrScrn1_CancelButton->fn->setReleasedImage(CkrScrn1_CancelButton, &cancel_80);            
            CkrScrn1_CancelButton->fn->setVisible(CkrScrn1_CancelButton, LE_FALSE);
            
            //Prepare and Hide the Mode Image
            CkrScrn1_ModeImageWidget->fn->setVisible(CkrScrn1_ModeImageWidget, LE_FALSE);
            CkrScrn1_ModeImageWidget->fn->setImage(CkrScrn1_ModeImageWidget, mode_images[mode]);
            
            CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE3;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE3:
        {
            CkrScrn1_RectangleWidget3->fn->setVisible(CkrScrn1_RectangleWidget3, LE_FALSE); 
            CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE4;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE4:            
        {
            uint32_t length = CkrScrn1_RectangleWidget0->fn->getWidth(CkrScrn1_RectangleWidget0);
            uint32_t xpos = CkrScrn1_RectangleWidget0->fn->getX(CkrScrn1_RectangleWidget0);

            if (length > DELTA_RECT_PIX)
            {
                CkrScrn1_RectangleWidget0->fn->setWidth(CkrScrn1_RectangleWidget0, length - DELTA_RECT_PIX);
                CkrScrn1_RectangleWidget0->fn->setX(CkrScrn1_RectangleWidget0, xpos + DELTA_RECT_PIX);
                CkrScrn1_RectangleWidget1->fn->setWidth(CkrScrn1_RectangleWidget1, length - DELTA_RECT_PIX);
                CkrScrn1_RectangleWidget1->fn->setX(CkrScrn1_RectangleWidget1, xpos + DELTA_RECT_PIX);
            }
            else
            {
                CkrScrn1_RectangleWidget0->fn->setVisible(CkrScrn1_RectangleWidget0, LE_FALSE);
                CkrScrn1_RectangleWidget1->fn->setVisible(CkrScrn1_RectangleWidget1, LE_FALSE);
                CkrScrn1_RectangleWidget1->fn->setVisible(CkrScrn1_RectangleWidget2, LE_FALSE);
                
                CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE5;
            }
                
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE5:
        {
            width = CkrScrn1_ProgressBarWidget0->fn->getWidth(CkrScrn1_ProgressBarWidget0);
            x = CkrScrn1_ProgressBarWidget0->fn->getX(CkrScrn1_ProgressBarWidget0);
                        
            CkrScrn1_ProgressBarWidget0->fn->setVisible(CkrScrn1_ProgressBarWidget0, LE_TRUE);
            CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, 0);       
            
            CkrScrn1_ProgressBarWidget0->fn->setX(CkrScrn1_ProgressBarWidget0, x + (width*3)/8);
            CkrScrn1_ProgressBarWidget0->fn->setWidth(CkrScrn1_ProgressBarWidget0, width/4);
            
            CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE6;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE6:
        {
            width = CkrScrn1_ProgressBarWidget0->fn->getWidth(CkrScrn1_ProgressBarWidget0);
            x = CkrScrn1_ProgressBarWidget0->fn->getX(CkrScrn1_ProgressBarWidget0);
            
            if (width < 280 - PROGRESS_BAR_BLOCK_EXTEND)
            {
                CkrScrn1_ProgressBarWidget0->fn->setWidth(CkrScrn1_ProgressBarWidget0, 
                                            width + PROGRESS_BAR_BLOCK_EXTEND);
                CkrScrn1_ProgressBarWidget0->fn->setX(CkrScrn1_ProgressBarWidget0, x - PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                CkrScrn1_ProgressBarWidget0->fn->setWidth(CkrScrn1_ProgressBarWidget0, 280);
                CkrScrn1_ProgressBarWidget0->fn->setX(CkrScrn1_ProgressBarWidget0, 104);
                CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE7;
            }
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE7:
        {
            CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_TRUE);
            
            CkrScrn1_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE8;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE8:
        {
            CkrScrn1_ModeImageWidget->fn->setVisible(CkrScrn1_ModeImageWidget, LE_TRUE);  
            CkrScrn1_CancelButton->fn->setVisible(CkrScrn1_CancelButton, LE_TRUE);            
            cookSec = COOK_TIME_SECS;
                        
            CkrScrn1_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
            
            break;
        }        
        case MAIN_MENU_PROCESS_PROGRESS_SCENE:
        {
            switch(app_event)
            {
                case EVENT_STOP_COOKING:
                {
                    CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE1;
            
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_PAUSE_COOKING:
                {
                    CkrScrn1_menu_state = MAIN_MENU_IDLE_PROGRESS_SCENE;
                    
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_SET_COOK_TIME:
                {
                    cookSec = COOK_TIME_SECS - (event_parm * COOK_TIME_SECS) / 100;
            
                    sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&progressStr);    
                    CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, event_parm);
                    
                    CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_TRUE);
                    
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_EXIT_SCREEN:
                {
                    CkrScrn1_menu_state = SCREEN_EXIT;
                    nextScreen = screenID_Menu;
                    app_event = EVENT_NONE;
                    break;
                }                 
                default:
                {
                    if (tick_count_last != tick_count)
                    {
                        tick_count_last = tick_count;

                        if (cookSec > 0)
                        {
                                    sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                            CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&progressStr);                       

                            CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, 
                                                100 - (100 * cookSec) / COOK_TIME_SECS);

                            cookSec--;

                        }
                        else
                        {
                            cookSec = COOK_TIME_SECS;

                            CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, 100);
                                    sprintf(charBuff, "Done"); 
                                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                            CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&progressStr);   
                            CkrScrn1_CancelButton->fn->setPressedImage(CkrScrn1_CancelButton, &ok_80);
                            CkrScrn1_CancelButton->fn->setReleasedImage(CkrScrn1_CancelButton, &ok_80);
                            CkrScrn1_menu_state = MAIN_MENU_DONE_PROGRESS_SCENE; 
                        }
                    }
                    break;
                }
            }
            
            break;
        }
        case MAIN_MENU_IDLE_PROGRESS_SCENE:
        case MAIN_MENU_DONE_PROGRESS_SCENE:
        {
            if (last_sec_count != sec_count)
            {
                if (CkrScrn1_CookTimeLabel->fn->getVisible(CkrScrn1_CookTimeLabel) == LE_TRUE)
                    CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_FALSE);
                else
                    CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_TRUE);
            }
            
            switch(app_event)
            {
                case EVENT_CONTINUE_COOKING:
                {
                    if (CkrScrn1_menu_state == MAIN_MENU_IDLE_PROGRESS_SCENE)
                    {
                        CkrScrn1_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
                        CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_TRUE);                        
                    }
                    
                    app_event = EVENT_NONE;
                    break;
                }
                case EVENT_STOP_COOKING:
                {
                    CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE1;
                    
                    app_event = EVENT_NONE;
                    break;
                }
                case EVENT_SET_COOK_TIME:
                {
                    cookSec = COOK_TIME_SECS - (event_parm * COOK_TIME_SECS) / 100;
            
                    sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&progressStr);    
                    CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, event_parm);
                    
                    CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_TRUE);
                    
                    //cook time has been adjusted, switch back to idle/paused state
                    if (CkrScrn1_menu_state == MAIN_MENU_DONE_PROGRESS_SCENE)
                    {
                        CkrScrn1_CancelButton->fn->setPressedImage(CkrScrn1_CancelButton, &cancel_80);
                        CkrScrn1_CancelButton->fn->setReleasedImage(CkrScrn1_CancelButton, &cancel_80);  
                        CkrScrn1_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
                    }
                    
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_EXIT_SCREEN:
                {
                    CkrScrn1_menu_state = SCREEN_EXIT;
                    nextScreen = screenID_Menu;
                    app_event = EVENT_NONE;
                    break;
                }                 
                default:
                    break;
            }
            
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE1:
        {
            CkrScrn1_ModeImageWidget->fn->setVisible(CkrScrn1_ModeImageWidget, LE_FALSE);  
            CkrScrn1_CancelButton->fn->setVisible(CkrScrn1_CancelButton, LE_FALSE);   
            CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE2;
            
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE2:
        {
            width = CkrScrn1_ProgressBarWidget0->fn->getWidth(CkrScrn1_ProgressBarWidget0);
            x = CkrScrn1_ProgressBarWidget0->fn->getX(CkrScrn1_ProgressBarWidget0);
            
            if (width > PROGRESS_BAR_BLOCK_EXTEND)
            {
                CkrScrn1_ProgressBarWidget0->fn->setWidth(CkrScrn1_ProgressBarWidget0, 
                                            width - PROGRESS_BAR_BLOCK_EXTEND);
                CkrScrn1_ProgressBarWidget0->fn->setX(CkrScrn1_ProgressBarWidget0, x + PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                char charBuff[16] = {0}; 
                
                CkrScrn1_ProgressBarWidget0->fn->setVisible(CkrScrn1_ProgressBarWidget0, LE_FALSE);
                
                sprintf(charBuff, "2:00"); 
                progressStr.fn->setFromCStr(&progressStr, charBuff);    
                CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&progressStr);                       
                                    
                CkrScrn1_CookTimeLabel->fn->setVisible(CkrScrn1_CookTimeLabel, LE_FALSE);   
                CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE3;
            }
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE3:
        {
            CkrScrn1_PanelWidget0->fn->setX(CkrScrn1_PanelWidget0, 480); 
            
            CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE4;
            
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE4:
        {
            CkrScrn1_ImageWidget1->fn->setVisible(CkrScrn1_ImageWidget1, LE_TRUE);
            CkrScrn1_ImageWidget8->fn->setVisible(CkrScrn1_ImageWidget8, LE_TRUE);  
            
            CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE5;
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE5:
        {
            CkrScrn1_ImageWidget3->fn->setVisible(CkrScrn1_ImageWidget3, LE_TRUE);
            CkrScrn1_ImageWidget4->fn->setVisible(CkrScrn1_ImageWidget4, LE_TRUE);
            CkrScrn1_PanelWidget3->fn->setVisible(CkrScrn1_PanelWidget3, LE_TRUE);
                
            CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE6;
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE6:
        {
            CkrScrn1_ImageWidget2->fn->setVisible(CkrScrn1_ImageWidget2, LE_TRUE);
            
            CkrScrn1_menu_state = SCREEN_EXIT_PROGRESS_SCENE7;
            
            break;
        }
        case SCREEN_EXIT_PROGRESS_SCENE7:
        {
            CkrScrn1_MainPanel->fn->setVisible(CkrScrn1_MainPanel, LE_TRUE); 
            
            CkrScrn1_menu_state = MAIN_MENU_SHOW_MAIN;
            
            break;
        }        
        case MAIN_MENU_SHOW_MAIN:
        {
            CkrScrn1_ColonLabel->fn->setScheme(CkrScrn1_ColonLabel, &WhiteTextScheme);
            CkrScrn1_HourLabel->fn->setScheme(CkrScrn1_HourLabel, &WhiteTextScheme);
            CkrScrn1_MinuteLabel->fn->setScheme(CkrScrn1_MinuteLabel, &WhiteTextScheme);            
            
            CkrScrn1_menu_state = MAIN_MENU_PROCESS;
            
            break;
        }
        case MAIN_MENU_CHANGE_SCREEN:
        {
    
            CkrScrn1_SliderButton0->fn->removeEventFilter(CkrScrn1_SliderButton0, CkrScrn1_eventFilter);

            legato_showScreen(screenID_CkrScrn2);

            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();            
            
            CkrScrn1_menu_state = MAIN_MENU_IDLE;
            
            break;
        }
        case MAIN_MENU_IDLE:
        {
            break;
        }
        case SCREEN_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
                
            CkrScrn1_SliderButton0->fn->removeEventFilter(CkrScrn1_SliderButton0, CkrScrn1_eventFilter);

            legato_showScreen(nextScreen);

            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();            
            
            break;
        }
        default:
            break;
    }
    
    //Update Clock
    if (last_sec_count != sec_count)
    {
        
        CkrScrn1_UpdateClock();
        
        last_sec_count = sec_count;
    }
}

void event_CkrScrn1_ListWheelWidget2_OnSelectionChanged(leListWheelWidget* lst, int32_t idx)
{
    CkrScrn1_ImageWidget8->fn->setImage(CkrScrn1_ImageWidget8, smart_favorites_images[idx]);
}

void event_CkrScrn1_BakeButton_OnReleased(leButtonWidget* btn)
{
    startMode(BAKE_MODE);
}

void event_CkrScrn1_CookButton_OnReleased(leButtonWidget* btn)
{
    startMode(COOK_MODE);
}

void event_CkrScrn1_BroilButton_OnReleased(leButtonWidget* btn)
{
    startMode(BROIL_MODE);
}

void event_CkrScrn1_ReheatButton_OnReleased(leButtonWidget* btn)
{
    startMode(REHEAT_MODE);
}

void event_CkrScrn1_CancelButton_OnReleased(leButtonWidget* btn)
{
    app_send_event(EVENT_STOP_COOKING);
}

void event_CkrScrn1_RestartButton_OnPressed(leButtonWidget* btn)
{
    app_send_event(EVENT_PAUSE_COOKING);
}

void event_CkrScrn1_RestartButton_OnReleased(leButtonWidget* btn)
{
    app_send_event(EVENT_CONTINUE_COOKING);
}

void event_CkrScrn1_ButtonWidget0_OnReleased(leButtonWidget* btn)
{
    app_send_event(EVENT_CHANGE_SCENE);
}

void event_CkrScrn1_HomeButton_OnPressed(leButtonWidget* btn)
{
    app_send_event(EVENT_EXIT_SCREEN);
}
