#include "app.h"
#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"

#include <stdio.h>
#include <string.h>

#define MENU_BAR_BLOCK_EXTEND_PIX 3
#define NUM_MENU_ITEMS 4
#define COLOR_BAR_WIDTH 212
#define CLOCK_BACK_PANEL_HEIGHT 289
#define DIVIDER 5
#define CLOCK_BACK_PANEL_MOVE_INC_PIX 5
#define CLOCK_BACK_PANEL_YPOS 22
#define MODES_BACK_PANEL_XPOS 365
#define MOVE_DIVIDER 5
#define COOK_TIME_SECS 60

typedef enum 
{
    COLOR_SCENE_INIT,
    COLOR_SCENE_PREPARE_MENU0,
    COLOR_SCENE_PREPARE_MENU1,
    COLOR_SCENE_PREPARE_MENU2,
    COLOR_SCENE_PREPARE_MENU3,            
    COLOR_SCENE_PREPARE_MENU4,
    COLOR_SCENE_PREPARE_MENU5,
    COLOR_SCENE_PREPARE_MENU6,
    COLOR_SCENE_PREPARE_MENU7,
    COLOR_SCENE_PREPARE_MENU8,
    COLOR_SCENE_PREPARE_MENU9,
    COLOR_SCENE_PREPARE_MENU10,                    
    COLOR_SCENE_PROCESS,
    COLOR_SCENE_PREPARE,
    COLOR_SCENE_COOKING,
    COLOR_SCENE_DONE,
    COLOR_SCENE_RETURNING,
    COLOR_SCENE_EXIT,
    MAIN_MENU_EXIT,
} COLOR_SCENE_STATES;

static COLOR_SCENE_STATES CkrScrn2_scene_state = COLOR_SCENE_INIT;
static int last_sec, last_min = 0;
static int x, y;
static int cookSec = COOK_TIME_SECS;
static int startCookSec = COOK_TIME_SECS;

static leFixedString hrStr, minStr;
static leChar hrStrBuff[16] = {0};
static leChar minStrBuff[16] = {0};
static int nextScreen = 0;

static void updateClock(unsigned int hr, unsigned int min)
{
    char charBuff[16] = {0};

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", hr); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    CkrScrn2_Screen2HourLabel->fn->setString(CkrScrn2_Screen2HourLabel, (leString*)&hrStr);   

    sprintf(charBuff, "%02u", min); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    CkrScrn2_Screen2MinuteLabel->fn->setString(CkrScrn2_Screen2MinuteLabel, (leString*)&minStr);   
}

static void Rect_PreAnimate(leRectangleWidget * widget)
{
    widget->fn->setVisible(widget, LE_TRUE);
    widget->fn->setWidth(widget, 0);    
}

static bool Rect_Animate(leRectangleWidget * widget, int32_t x, uint32_t width)
{
    uint32_t cur_width = widget->fn->getWidth(widget);
    bool done = false;
    
    if (width - cur_width > DIVIDER)
    {
        widget->fn->setWidth(widget, 
                             cur_width + (width - cur_width)/DIVIDER);
    }
    else
    {
        widget->fn->setWidth(widget, width);
        done = true;
    }    
    
    return done;
    
}

static void Set_SelectedMenuItem(int index)
{
    if (CkrScrn2_scene_state != COLOR_SCENE_PROCESS)
        return;
    
    CkrScrn2_MenuItem1Label->fn->setScheme(CkrScrn2_MenuItem1Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem2Label->fn->setScheme(CkrScrn2_MenuItem2Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem3Label->fn->setScheme(CkrScrn2_MenuItem3Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem4Label->fn->setScheme(CkrScrn2_MenuItem4Label, &UnselectedItemTextScheme);
    
    CkrScrn2_ButtonImage1->fn->setSize(CkrScrn2_ButtonImage1, 64, 64);
    CkrScrn2_ButtonImage2->fn->setSize(CkrScrn2_ButtonImage2, 64, 64);
    CkrScrn2_ButtonImage3->fn->setSize(CkrScrn2_ButtonImage3, 64, 64);
    CkrScrn2_Button4Image->fn->setSize(CkrScrn2_Button4Image, 64, 64);
    
    CkrScrn2_ButtonImage1->fn->setPosition(CkrScrn2_ButtonImage1, 15, 2);
    CkrScrn2_ButtonImage2->fn->setPosition(CkrScrn2_ButtonImage2, 25, 2);
    CkrScrn2_ButtonImage3->fn->setPosition(CkrScrn2_ButtonImage3, 15, 2);
    CkrScrn2_Button4Image->fn->setPosition(CkrScrn2_Button4Image, 25, 2);
    

    switch(index)
    {
        case 0:
        {
            CkrScrn2_MenuItem1Label->fn->setScheme(CkrScrn2_MenuItem1Label, &WhiteTextScheme);
            CkrScrn2_ButtonImage1->fn->setSize(CkrScrn2_ButtonImage1, 70, 70);
            CkrScrn2_ButtonImage1->fn->setPosition(CkrScrn2_ButtonImage1, 13, 0);
            
            CkrScrn2_ProgressRect->fn->setScheme(CkrScrn2_ProgressRect, &Button1Scheme);
            
            startCookSec = 200;
                    
            break;
        }
        case 1:
        {
            CkrScrn2_MenuItem2Label->fn->setScheme(CkrScrn2_MenuItem2Label, &WhiteTextScheme);
            CkrScrn2_ButtonImage2->fn->setSize(CkrScrn2_ButtonImage2, 70, 70);
            CkrScrn2_ButtonImage2->fn->setPosition(CkrScrn2_ButtonImage2, 23, 0);
            
            CkrScrn2_ProgressRect->fn->setScheme(CkrScrn2_ProgressRect, &Button2Scheme);
            
            startCookSec = 110;
                    
            break;
        }
        case 2:
        {
            CkrScrn2_MenuItem3Label->fn->setScheme(CkrScrn2_MenuItem3Label, &WhiteTextScheme);
            CkrScrn2_ButtonImage3->fn->setSize(CkrScrn2_ButtonImage3, 70, 70);
            CkrScrn2_ButtonImage3->fn->setPosition(CkrScrn2_ButtonImage3, 13, 0);                    
                 
            CkrScrn2_ProgressRect->fn->setScheme(CkrScrn2_ProgressRect, &Button3Scheme);
            
            startCookSec = 60;
            
            break;
        }
        case 3:
        {
            CkrScrn2_MenuItem4Label->fn->setScheme(CkrScrn2_MenuItem4Label, &WhiteTextScheme);
            CkrScrn2_Button4Image->fn->setSize(CkrScrn2_Button4Image, 70, 70);
            CkrScrn2_Button4Image->fn->setPosition(CkrScrn2_Button4Image, 23, 0);                    
                    
            CkrScrn2_ProgressRect->fn->setScheme(CkrScrn2_ProgressRect, &Button4Scheme);
            
            startCookSec = 50;
            
            break;
        }
        default:
        {
            break;
        }
    }
}

static leBool CkrScrn2_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
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
            
            app_event = SET_COOK_TIME;
            
            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    return LE_FALSE;
}

static leWidgetEventFilter CkrScrn2_eventFilter =
{
    CkrScrn2_filterEvent,
    NULL
};

void CkrScrn2_OnShow(void)
{
    //Hide the other menu items
    CkrScrn2_MenuItem2->fn->setVisible(CkrScrn2_MenuItem2, LE_FALSE);
    CkrScrn2_MenuItem3->fn->setVisible(CkrScrn2_MenuItem3, LE_FALSE);
    CkrScrn2_MenuItem4->fn->setVisible(CkrScrn2_MenuItem4, LE_FALSE);

    //Hide all the menu item images
    CkrScrn2_ButtonImage1->fn->setVisible(CkrScrn2_ButtonImage1, LE_FALSE);
    CkrScrn2_ButtonImage2->fn->setVisible(CkrScrn2_ButtonImage2, LE_FALSE);
    CkrScrn2_ButtonImage3->fn->setVisible(CkrScrn2_ButtonImage3, LE_FALSE);
    CkrScrn2_Button4Image->fn->setVisible(CkrScrn2_Button4Image, LE_FALSE);

    //Hide all the background gray rects
    CkrScrn2_ButtonRect1Back->fn->setVisible(CkrScrn2_ButtonRect1Back, LE_FALSE);
    CkrScrn2_Button2RectBack->fn->setVisible(CkrScrn2_Button2RectBack, LE_FALSE);
    CkrScrn2_Button3RectBack->fn->setVisible(CkrScrn2_Button3RectBack, LE_FALSE);
    CkrScrn2_Button4RectBack->fn->setVisible(CkrScrn2_Button4RectBack, LE_FALSE);

    //Hide all the menu labels
    CkrScrn2_MenuItem1Label->fn->setVisible(CkrScrn2_MenuItem1Label, LE_FALSE);
    CkrScrn2_MenuItem2Label->fn->setVisible(CkrScrn2_MenuItem2Label, LE_FALSE);
    CkrScrn2_MenuItem3Label->fn->setVisible(CkrScrn2_MenuItem3Label, LE_FALSE);
    CkrScrn2_MenuItem4Label->fn->setVisible(CkrScrn2_MenuItem4Label, LE_FALSE);

    // Hide the clock panel
    CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_FALSE);

    //Hide the Banner
    CkrScrn2_Screen2LabelPanel->fn->setY(CkrScrn2_Screen2LabelPanel, -76);

    //Hide the mode buttons
    CkrScrn2_CookButtonWidget->fn->setVisible(CkrScrn2_CookButtonWidget, LE_FALSE);
    CkrScrn2_ReheatButtonWidget->fn->setVisible(CkrScrn2_ReheatButtonWidget, LE_FALSE);

    //Hide the progress rectangle
    CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, -153);
    CkrScrn2_ProgressRect->fn->setY(CkrScrn2_ProgressRect, 30);

    //Hide the back panels
    CkrScrn2_PanelWidget5->fn->setY(CkrScrn2_PanelWidget5, 320);
    CkrScrn2_PanelWidget4->fn->setX(CkrScrn2_PanelWidget4, 480);
    
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultHour2,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));
    
    CkrScrn2_ButtonWidget6->fn->setPressed(CkrScrn2_ButtonWidget6, (leBool) (demo_mode_on == false));
    
    CkrScrn2_SliderButton2->fn->installEventFilter(CkrScrn2_SliderButton2, CkrScrn2_eventFilter);
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    CkrScrn2_FPSLabel->fn->setVisible(CkrScrn2_FPSLabel, stats_enabled == true);    
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT);     
    
    CkrScrn2_scene_state = COLOR_SCENE_INIT;
    app_event = EVENT_NONE;
}

void CkrScrn2_OnHide(void)
{
    hrStr.fn->destructor(&hrStr);
    minStr.fn->destructor(&minStr);
    
    fpsStr.fn->destructor(&fpsStr);
}

static void CheckGestures(void)
{
    APP_GESTURE_CMD gesture = APP_GetGesture();
            
    //check for gestures
    if (gesture != APP_GEST_NONE)
    {
        switch(gesture)
        {
            case APP_GEST_RIGHT_SWIPE_DUAL:
            {
                nextScreen = screenID_Info;
                CkrScrn2_scene_state = MAIN_MENU_EXIT;
                break;
            }
            case APP_GEST_LEFT_SWIPE_DUAL:
            {
                nextScreen = screenID_PlyrScrn;
                CkrScrn2_scene_state = MAIN_MENU_EXIT;
                break;
            }
            case APP_START_MG_M:
            {
                nextScreen = screenID_Menu;
                CkrScrn2_scene_state = MAIN_MENU_EXIT;
                break;
            }
            case APP_START_MG_S:
            {
                nextScreen = screenID_Intro;
                CkrScrn2_scene_state = MAIN_MENU_EXIT;
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

                updateClock(clock_hr, clock_min);

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

                updateClock(clock_hr, clock_min);

                break;
            }            
            default:
                break;
        }

        APP_ClearGesture();
    } 
}

void CkrScrn2_OnUpdate(void)
{
    //Wait for the library to be done drawing before processing events/animation
    if(!leRenderer_IsIdle() || leEvent_GetCount() != 0)
        return;
    
    switch(CkrScrn2_scene_state)
    {
        case COLOR_SCENE_INIT:
        {
            if(!leRenderer_IsIdle() || 
               leEvent_GetCount() != 0 ||
               isDisplayReady() != true)
                break;            
            
            app_event = EVENT_NONE;
            idle_secs = 0;
            demo_mode_count_secs = 0;
            demo_mode_event_idx = 0;
            
            nextScreen = 0;            
            APP_ClearGesture();
            
            CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU0;
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU0:
        {
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;  
            
            //Move the panel in to the scene
            CkrScrn2_QuickSelectionsPanel->fn->setX(CkrScrn2_QuickSelectionsPanel, 0);
            
            CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU1;
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU1:
        {   
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            
            Rect_PreAnimate(CkrScrn2_Button1Rect);
            
            CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU2;
            break;
        }
        case COLOR_SCENE_PREPARE_MENU2:
        {
            if (Rect_Animate(CkrScrn2_Button1Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                CkrScrn2_MenuItem1Label->fn->setVisible(CkrScrn2_MenuItem1Label, LE_TRUE);
                CkrScrn2_ButtonImage1->fn->setVisible(CkrScrn2_ButtonImage1, LE_TRUE);
                CkrScrn2_MenuItem2->fn->setVisible(CkrScrn2_MenuItem2, LE_TRUE);
                CkrScrn2_ButtonImage2->fn->setVisible(CkrScrn2_ButtonImage2, LE_FALSE);

                Rect_PreAnimate(CkrScrn2_Button2Rect);

                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU3;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU3:
        {    
            if (Rect_Animate(CkrScrn2_Button2Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                CkrScrn2_MenuItem2Label->fn->setVisible(CkrScrn2_MenuItem2Label, LE_TRUE);
                CkrScrn2_ButtonImage2->fn->setVisible(CkrScrn2_ButtonImage2, LE_TRUE);                
                CkrScrn2_MenuItem3->fn->setVisible(CkrScrn2_MenuItem3, LE_TRUE);
                CkrScrn2_ButtonImage3->fn->setVisible(CkrScrn2_ButtonImage3, LE_FALSE);

                Rect_PreAnimate(CkrScrn2_Button3Rect);

                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU4;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU4:
        {    
            if (Rect_Animate(CkrScrn2_Button3Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                CkrScrn2_MenuItem3Label->fn->setVisible(CkrScrn2_MenuItem3Label, LE_TRUE);
                CkrScrn2_ButtonImage3->fn->setVisible(CkrScrn2_ButtonImage3, LE_TRUE);
                CkrScrn2_MenuItem4->fn->setVisible(CkrScrn2_MenuItem4, LE_TRUE);
                
                CkrScrn2_Button4Image->fn->setVisible(CkrScrn2_Button4Image, LE_FALSE);

                Rect_PreAnimate(CkrScrn2_Button4Rect);

                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU5;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU5:
        {    
            if (Rect_Animate(CkrScrn2_Button4Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                CkrScrn2_MenuItem4Label->fn->setVisible(CkrScrn2_MenuItem4Label, LE_TRUE);                
                CkrScrn2_Button4Image->fn->setVisible(CkrScrn2_Button4Image, LE_TRUE);
                    
                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU6;
            }            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU6:
        {
            CkrScrn2_ButtonRect1Back->fn->setVisible(CkrScrn2_ButtonRect1Back, LE_TRUE);
            CkrScrn2_Button2RectBack->fn->setVisible(CkrScrn2_Button2RectBack, LE_TRUE);
            CkrScrn2_Button3RectBack->fn->setVisible(CkrScrn2_Button3RectBack, LE_TRUE);
            CkrScrn2_Button4RectBack->fn->setVisible(CkrScrn2_Button4RectBack, LE_TRUE);
            
            Set_SelectedMenuItem(0);
            
            CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU7;
            break;
        }
        case COLOR_SCENE_PREPARE_MENU7:
        {
            //animate the clock back panel            
            y = CkrScrn2_PanelWidget5->fn->getY(CkrScrn2_PanelWidget5);

            if ( y - CLOCK_BACK_PANEL_YPOS > MOVE_DIVIDER)
            {
                CkrScrn2_PanelWidget5->fn->setY(CkrScrn2_PanelWidget5, y - (y - CLOCK_BACK_PANEL_YPOS)/MOVE_DIVIDER);
            }
            else
            {
                CkrScrn2_PanelWidget5->fn->setY(CkrScrn2_PanelWidget5, CLOCK_BACK_PANEL_YPOS);
                CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_TRUE);   
                updateClock(clock_hr, clock_min);
                
                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU8;
            }

            break;
        }
        case COLOR_SCENE_PREPARE_MENU8:
        {
            //animate the modes panel
            x = CkrScrn2_PanelWidget4->fn->getX(CkrScrn2_PanelWidget4);

            if ( x - MODES_BACK_PANEL_XPOS > MOVE_DIVIDER)
            {
                CkrScrn2_PanelWidget4->fn->setX(CkrScrn2_PanelWidget4, x - (x - MODES_BACK_PANEL_XPOS)/MOVE_DIVIDER);
            }
            else
            {
                CkrScrn2_PanelWidget4->fn->setX(CkrScrn2_PanelWidget4, MODES_BACK_PANEL_XPOS);
                CkrScrn2_CookButtonWidget->fn->setVisible(CkrScrn2_CookButtonWidget, LE_TRUE);
                CkrScrn2_ReheatButtonWidget->fn->setVisible(CkrScrn2_ReheatButtonWidget, LE_TRUE);             
                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU9;
            }
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU9:
        {
            //Animate the label panel
            y = CkrScrn2_Screen2LabelPanel->fn->getY(CkrScrn2_Screen2LabelPanel);

            if ( y < 0)
            {
                CkrScrn2_Screen2LabelPanel->fn->setY(CkrScrn2_Screen2LabelPanel, y + 1);
            }
            else
            {
                CkrScrn2_Screen2LabelPanel->fn->setY(CkrScrn2_Screen2LabelPanel, 0);
                CkrScrn2_scene_state = COLOR_SCENE_PREPARE_MENU10;
            }            

            break;
        }
        case COLOR_SCENE_PREPARE_MENU10:
        {
            CkrScrn2_scene_state = COLOR_SCENE_PROCESS;
            break;
        }
        case COLOR_SCENE_PROCESS:
        {
            if (last_sec != clock_sec)
            {
                if (CkrScrn2_Screen2ColonLabel->fn->getVisible(CkrScrn2_Screen2ColonLabel) == LE_TRUE)
                    CkrScrn2_Screen2ColonLabel->fn->setVisible(CkrScrn2_Screen2ColonLabel, LE_FALSE);
                else
                    CkrScrn2_Screen2ColonLabel->fn->setVisible(CkrScrn2_Screen2ColonLabel, LE_TRUE);
                
                last_sec = clock_sec;
            }
            
            if (last_min != clock_min)
            {
                updateClock(clock_hr, clock_min);           
                
                last_min = clock_min;
            }
            
            switch(app_event)
            {
                case START_COOKING:
                    CkrScrn2_scene_state = COLOR_SCENE_PREPARE;
                    break;
                case SELECT_ITEM_0:
                {
                    Set_SelectedMenuItem(0);
                    break;
                }
                case SELECT_ITEM_1:
                {
                    Set_SelectedMenuItem(1);
                    break;
                }
                case SELECT_ITEM_2:
                {
                    Set_SelectedMenuItem(2);
                    break;
                }
                case SELECT_ITEM_3:
                {
                    Set_SelectedMenuItem(3);                    
                    break;
                }
                case CHANGE_SCENE:
                {
                    CkrScrn2_scene_state = COLOR_SCENE_EXIT;
                    break;
                }
                case EXIT_TO_MENU:
                {
                    CkrScrn2_scene_state = MAIN_MENU_EXIT;
                    nextScreen = screenID_Menu;
                    break;
                }                  
                default:
                    break;
            }
            
            CheckGestures();
            
            app_event = EVENT_NONE;
            
            break;
        }
        case COLOR_SCENE_PREPARE:
        {
            CkrScrn2_CookButtonWidget->fn->setPressedImage(CkrScrn2_CookButtonWidget, &cancel2);
            CkrScrn2_CookButtonWidget->fn->setReleasedImage(CkrScrn2_CookButtonWidget, &cancel2);
            CkrScrn2_ReheatButtonWidget->fn->setVisible(CkrScrn2_ReheatButtonWidget, LE_FALSE);
            CkrScrn2_Screen2ColonLabel->fn->setVisible(CkrScrn2_Screen2ColonLabel, LE_TRUE);
            
            updateClock(cookSec/60, cookSec%60);
            
            CkrScrn2_scene_state = COLOR_SCENE_COOKING;
            
            cookSec = startCookSec;
            
            break;
        }
        case COLOR_SCENE_COOKING:
        {
            switch(app_event)
            {
                case STOP_COOKING:
                {
                    CkrScrn2_scene_state = COLOR_SCENE_RETURNING;
                    app_event = EVENT_NONE;
                    break;
                }
                case SET_COOK_TIME:
                {
                    cookSec = startCookSec - (event_parm * startCookSec) / 100;
            
                    updateClock(cookSec/60, cookSec%60);
                    
                    CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, 
                                               (-153 * cookSec) / startCookSec);                    
                    
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EXIT_TO_MENU:
                {
                    CkrScrn2_scene_state = MAIN_MENU_EXIT;
                    nextScreen = screenID_Menu;
                    app_event = EVENT_NONE;
                    break;
                }                  
                default:
                {
                    //start progress bar
                    if (tick_count > tick_count_last + 4)
                    {
                        if (cookSec > 0)
                        {
                            updateClock(cookSec/60, cookSec%60);

                            CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, 
                                                       (-153 * cookSec) / startCookSec);

                            cookSec--;
                        }
                        else
                        {
                            cookSec = startCookSec;

                            CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, 0);

                            CkrScrn2_CookButtonWidget->fn->setPressedImage(CkrScrn2_CookButtonWidget, &ok2);
                            CkrScrn2_CookButtonWidget->fn->setReleasedImage(CkrScrn2_CookButtonWidget, &ok2);

                            updateClock(0, 0);

                            CkrScrn2_scene_state = COLOR_SCENE_DONE; 
                        }
                        
                        tick_count_last = tick_count;
                    }
                    else if (tick_count < tick_count_last)
                    {
                        tick_count_last = tick_count;
                    }
                        
            
                    break;
                }
            }
            
            break;
        }
        case COLOR_SCENE_DONE:
        {
            if (last_sec != clock_sec)
            {
                if (CkrScrn2_Screen2MainClockPanel->fn->getVisible(CkrScrn2_Screen2MainClockPanel) == LE_TRUE)
                {
                    CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_FALSE);
                }
                else
                {
                    CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_TRUE);
                }
                
                last_sec = clock_sec;
            }
            
            switch(app_event)
            {
                case STOP_COOKING:
                {
                    CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_TRUE);
                    CkrScrn2_scene_state = COLOR_SCENE_RETURNING;
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case SET_COOK_TIME:
                {
                    cookSec = startCookSec - (event_parm * startCookSec) / 100;
            
                    updateClock(cookSec/60, cookSec%60);
                    
                    CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, 
                                               (-153 * cookSec) / startCookSec);  
                    
                    CkrScrn2_Screen2MainClockPanel->fn->setVisible(CkrScrn2_Screen2MainClockPanel, LE_TRUE);
                    CkrScrn2_CookButtonWidget->fn->setPressedImage(CkrScrn2_CookButtonWidget, &cancel2);
                    CkrScrn2_CookButtonWidget->fn->setReleasedImage(CkrScrn2_CookButtonWidget, &cancel2);                    
                    
                    CkrScrn2_scene_state = COLOR_SCENE_COOKING;
                    
                    app_event = EVENT_NONE;
                    
                    break;
                }
                case EXIT_TO_MENU:
                {
                    CkrScrn2_scene_state = MAIN_MENU_EXIT;
                    nextScreen = screenID_Menu;
                    app_event = EVENT_NONE;
                    break;
                }                   
                default:
                    break;
            }
            
            break;
        }
        case COLOR_SCENE_RETURNING:
        {
            cookSec = startCookSec;
            
            x = CkrScrn2_ProgressRect->fn->getX(CkrScrn2_ProgressRect);
            
            if (x > -153)
            {
                CkrScrn2_ProgressRect->fn->setX(CkrScrn2_ProgressRect, x - 10);
            }
            else
            {
                updateClock(clock_hr, clock_min);
                
                CkrScrn2_ReheatButtonWidget->fn->setPressedImage(CkrScrn2_ReheatButtonWidget, &reheat2);
                CkrScrn2_ReheatButtonWidget->fn->setReleasedImage(CkrScrn2_ReheatButtonWidget, &reheat2);
                CkrScrn2_ReheatButtonWidget->fn->setVisible(CkrScrn2_ReheatButtonWidget, LE_TRUE);                

                CkrScrn2_CookButtonWidget->fn->setPressedImage(CkrScrn2_CookButtonWidget, &cook2);
                CkrScrn2_CookButtonWidget->fn->setReleasedImage(CkrScrn2_CookButtonWidget, &cook2);
                CkrScrn2_CookButtonWidget->fn->setVisible(CkrScrn2_CookButtonWidget, LE_TRUE);                
                
                CkrScrn2_scene_state = COLOR_SCENE_PROCESS;
            }
                
            break;
        }  
        case COLOR_SCENE_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
                            
            CkrScrn2_SliderButton2->fn->removeEventFilter(CkrScrn2_SliderButton2, CkrScrn2_eventFilter);
    
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            
            legato_showScreen(screenID_CkrScrn1);
            
            break;
        }
        case MAIN_MENU_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
                
            CkrScrn2_SliderButton2->fn->removeEventFilter(CkrScrn2_SliderButton2, CkrScrn2_eventFilter);
    
            legato_showScreen(nextScreen);

            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();     
            
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
        CkrScrn2_FPSLabel->fn->setString(CkrScrn2_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    }
}

void event_CkrScrn2_ButtonWidget1_OnPressed(leButtonWidget* btn)
{
    app_send_event(SELECT_ITEM_0);
}

void event_CkrScrn2_ButtonWidget4_OnPressed(leButtonWidget* btn)
{
    app_send_event(SELECT_ITEM_3);
}

void event_CkrScrn2_ButtonWidget3_OnPressed(leButtonWidget* btn)
{
    app_send_event(SELECT_ITEM_2);
}

void event_CkrScrn2_ButtonWidget2_OnPressed(leButtonWidget* btn)
{
    app_send_event(SELECT_ITEM_1);
}

void event_CkrScrn2_ReheatButtonWidget_OnReleased(leButtonWidget* btn)
{
    app_send_event(START_COOKING);
}

void event_CkrScrn2_CookButtonWidget_OnReleased(leButtonWidget* btn)
{
    if (CkrScrn2_scene_state == COLOR_SCENE_PROCESS)
    {
        app_send_event(START_COOKING);
    }
    else if (CkrScrn2_scene_state == COLOR_SCENE_COOKING ||
             CkrScrn2_scene_state == COLOR_SCENE_DONE)
    {
        app_send_event(STOP_COOKING);
    }
}

void event_CkrScrn2_ButtonWidget5_OnReleased(leButtonWidget* btn)
{
    app_send_event(CHANGE_SCENE);
}

void event_CkrScrn2_ButtonWidget6_OnPressed(leButtonWidget* btn)
{

}


void event_CkrScrn2_ButtonWidget6_OnReleased(leButtonWidget* btn)
{

}

void event_CkrScrn2_HomeButton_OnPressed(leButtonWidget* btn)
{
    app_send_event(EXIT_TO_MENU);
}