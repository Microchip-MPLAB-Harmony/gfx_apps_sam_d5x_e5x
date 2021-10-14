#include "definitions.h"
#include "app.h"

//#define USE_TICK_ANIMATION 1 

#define SLIDE_DELTA_X 3
#define SLIDE_COEFF_X 5
#define TOUCH_MOVE_DELTA_MIN 1
#define TOUCH_MOVE_DELTA_MAX 20
#define MAX_E54INFO_POS (-220)
#define BAR_ANIM_DELTA_PIX 10
#define PANEL_WIDTH_SW_INFO 305

#define NUM_MENU_BUTTONS (sizeof(Info_MenuButtons)/sizeof(leButtonWidget **))
#define NUM_MENU_LABELS (sizeof(Info_MenuLabels)/sizeof(leLabelWidget **))

typedef enum 
{
    SCRN_INFO_STATE_INIT,
    SCRN_INFO_STATE_WAIT_FOR_READY,
    SCRN_INFO_STATE_SHOWING,
    SCRN_INFO_STATE_IDLE,
    SCRN_INFO_MCU,
    SCRN_INFO_HW,
    SCRN_INFO_SW,
    SCRN_INFO_REFS,
    SCRN_INFO_EXIT,
} SCRN_INFO_STATE;

typedef enum
{
    SCRN_INFO_SUBMENU_INIT,
    SCRN_INFO_SUBMENU_EXIT,
    SCRN_INFO_SUBMENU_POST_INIT,
    SCRN_INFO_SUBMENU_PROCESSING,
    SCRN_INFO_SUBMENU_PRE_EXIT,
            
    //HW substate
    SCRN_INFO_SHOWING_BACK,
    SCRN_INFO_SHOWING_FRONT,            
} SCRN_INFO_SUBSTATE;

typedef enum 
{
    SCRN_INFO_EVENT_NONE,
    SCRN_INFO_EVENT_EXIT,
    SCRN_INFO_EVENT_SHOW_MCU,
    SCRN_INFO_EVENT_SHOW_HW,
    SCRN_INFO_EVENT_SHOW_SW,          
    SCRN_INFO_EVENT_SHOW_REFS,
            
    SCRN_INFO_EVENT_SHOW_INIT,
    SCRN_INFO_EVENT_SHOW_INIT1,            
    SCRN_INFO_EVENT_SHOW_INIT2,
    SCRN_INFO_EVENT_SHOW_INIT3,
    SCRN_INFO_EVENT_SHOW_INIT4,
    SCRN_INFO_EVENT_SHOW_FRONT,
    SCRN_INFO_EVENT_SHOW_BACK,

    SCRN_INFO_EVENT_SHOW_SW_INFO_BASE,
    SCRN_INFO_EVENT_SHOW_MH3 = SCRN_INFO_EVENT_SHOW_SW_INFO_BASE,
    SCRN_INFO_EVENT_SHOW_MHGS,
    SCRN_INFO_EVENT_SHOW_TOUCH,
            
    SCRN_INFO_EVENT_TOUCH_MOVEX,
    SCRN_INFO_EVENT_TOUCH_MOVEY,
    SCRN_INFO_EVENT_TOUCH_TAP,
    SCRN_INFO_EVENT_TOUCH_DOWN,
    SCRN_INFO_EVENT_TOUCH_UP,
    SCRN_INFO_EVENT_TOUCH_ARROW_UP,
    SCRN_INFO_EVENT_TOUCH_ARROW_DOWN,
} SCRN_INFO_EVENT;

typedef enum
{
    SCRN_INFO_STAT_DONE,
    SCRN_INFO_STAT_BUSY,
} SCRN_INFO_STATUS;

static SCRN_INFO_STATE info_state;
static SCRN_INFO_SUBSTATE info_substate;
static SCRN_INFO_EVENT info_event;
static unsigned int count = 0;
static int touch_evt_argx, touch_evt_argy;
static int nextScreen = 0;

leButtonWidget ** Info_MenuButtons[] = 
{
    &Info_MCUButton,
    &Info_HardwareButton,
    &Info_SoftwareButton,
    &Info_ReferencesButton
};

leLabelWidget ** Info_MenuLabels[] = 
{
    &Info_MCULabel,
    &Info_HWLabel,
    &Info_SWLabel,
    &Info_ReferencesLabel,    
};

static void Info_ShowMenuLabel(int i, bool show)
{
    (*Info_MenuLabels[i])->fn->setVisible(*Info_MenuLabels[i], 
                (show == true) ? LE_TRUE : LE_FALSE);
}

static SCRN_INFO_STATUS Info_ShowMenuButtons(bool show)
{
    int i = 0;

    //hiding
    if (show == false)
    {
        for (i = 0; i < NUM_MENU_BUTTONS; i ++)
        {
            int x = (*Info_MenuButtons[i])->fn->getX((*Info_MenuButtons[i]));
            int width = (*Info_MenuButtons[i])->fn->getWidth(*Info_MenuButtons[i]);
            if (x > -width)
            {
                Info_ShowMenuLabel(i, false);
                (*Info_MenuButtons[i])->fn->translate((*Info_MenuButtons[i]), 
                                 -SLIDE_DELTA_X, 0);
                break;
            }
            else
            {
                (*Info_MenuButtons[i])->fn->setX(*Info_MenuButtons[i], -width);
            }
        }
    }
    else
    {
        for (i = 0; i < NUM_MENU_BUTTONS; i ++)
        {
            int x = (*Info_MenuButtons[i])->fn->getX(*Info_MenuButtons[i]);
            if (x < 0)
            {
                (*Info_MenuButtons[i])->fn->translate(*Info_MenuButtons[i],
                    SLIDE_DELTA_X, 0);
                
                break;
            }
            else
            {
                Info_ShowMenuLabel(i, true);
                (*Info_MenuButtons[i])->fn->setX(*Info_MenuButtons[i], 0);
            }
        }        
    }
    
    return (i < NUM_MENU_BUTTONS) ? SCRN_INFO_STAT_BUSY : SCRN_INFO_STAT_DONE;
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
                nextScreen = screenID_MGScrn;
                info_state = SCRN_INFO_EXIT;
                break;
            }
            case APP_GEST_LEFT_SWIPE_DUAL:
            {
                nextScreen = screenID_CkrScrn2;
                info_state = SCRN_INFO_EXIT;
                break;
            }
            case APP_START_MG_M:
            {
                nextScreen = screenID_Menu;
                info_state = SCRN_INFO_EXIT;
                break;
            }
            case APP_START_MG_S:
            {
                nextScreen = screenID_Intro;
                info_state = SCRN_INFO_EXIT;
                break;
            }            
            default:
                break;
        }

        APP_ClearGesture();
    } 
}

void event_Info_BoardViewBackButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_BACK;
}

void event_Info_BoardViewFrontButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_FRONT;
}

void event_Info_HomeButton_OnPressed(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_EXIT;
}

void event_Info_MCUButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_MCU;
}

void event_Info_HardwareButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_HW;
}

void event_Info_SoftwareButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_SW;
}

void event_Info_ReferencesButton_OnReleased(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_SHOW_REFS;
}

void event_Info_ListWheelWidget0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx)
{
    info_event = SCRN_INFO_EVENT_SHOW_SW_INFO_BASE + idx;
}

void event_Info_SWUpButton_OnPressed(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_TOUCH_ARROW_UP;
}

void event_Info_SWDownButton_OnPressed(leButtonWidget* btn)
{
    info_event = SCRN_INFO_EVENT_TOUCH_ARROW_DOWN;
}

static leBool Info_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{    
    leBool retval = LE_FALSE;

    static int32_t lastY;
    static int32_t lastX;    
    
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            tick_count_last = tick_count;
            
            lastY = ((leWidgetEvent_TouchDown *) evt)->y;
            lastX = ((leWidgetEvent_TouchDown *) evt)->x;
            
            info_event = SCRN_INFO_EVENT_TOUCH_DOWN;
            
            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            retval = LE_TRUE;
            
            break;
        }
        case LE_EVENT_TOUCH_UP:
        {
            //basic tap detection
            if (tick_count >= tick_count_last && 
                tick_count - tick_count_last < NUM_COUNT_TAP_TICK)
                info_event = SCRN_INFO_EVENT_TOUCH_TAP;
            else
                info_event = SCRN_INFO_EVENT_TOUCH_UP;
            
            break;
        }
        case LE_EVENT_TOUCH_MOVE:            
        {
            int32_t x, y;
            
            y = ((leWidgetEvent_TouchMove *) evt)->y;
            x = ((leWidgetEvent_TouchMove *) evt)->x;
            
            touch_evt_argx = x - lastX;
            touch_evt_argy = y - lastY;
            
            //vertical move
            if (abs(touch_evt_argy) > TOUCH_MOVE_DELTA_MIN &&
                abs(touch_evt_argx) < TOUCH_MOVE_DELTA_MAX)
            {
                info_event = SCRN_INFO_EVENT_TOUCH_MOVEY;
            }
            else if (abs(touch_evt_argx) > TOUCH_MOVE_DELTA_MIN &&
                    abs(touch_evt_argy) < TOUCH_MOVE_DELTA_MAX)
            {
                info_event = SCRN_INFO_EVENT_TOUCH_MOVEX;
            }
            
            lastY = y;
            lastX = x;
               
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;
           
            break;
        }
        default:
            break;
    }
    
   return retval;
}

static leWidgetEventFilter Info_eventFilter =
{
    Info_filterEvent,
    NULL
};

void Info_OnShow(void)
{
    int i = 0;
    
    info_event = SCRN_INFO_EVENT_NONE;
    info_state = SCRN_INFO_STATE_INIT;
    info_substate = SCRN_INFO_SUBMENU_PROCESSING;
    
    //hide all the menu items
    for (i = 0; i < NUM_MENU_BUTTONS; i ++)
    {
        int width = (*Info_MenuButtons[i])->fn->getWidth(*Info_MenuButtons[i]);
            (*Info_MenuButtons[i])->fn->setX(*Info_MenuButtons[i], -width);
    }
    
    for (i = 0; i < NUM_MENU_LABELS; i ++)
    {
        Info_ShowMenuLabel(i, false);
    }
    
    Info_IgatImageSequence->fn->setVisible(Info_IgatImageSequence, LE_FALSE);
    
    //initialize the board animation
    Info_BoardViewImageSequence->fn->setImageCount(Info_BoardViewImageSequence, 28);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 0, &igat71);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 1, &igat71);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 2, &igat72);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 3, &igat73);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 4, &igat74);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 5, &igat75);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 6, &igat76);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 7, &igat77);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 8, &igat78);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 9, &igat79);
    
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 10, &igat80);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 11, &igat81);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 12, &igat82);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 13, &igat83);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 14, &igat84);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 15, &igat85);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 16, &igat86);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 17, &igat87);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 18, &igat88);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 19, &igat89);
    
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 20, &igat90);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 21, &igat91);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 22, &igat92);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 23, &igat93);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 24, &igat94);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 25, &igat95);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 26, &igat96);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 27, &igat97);
    
    count = Info_BoardViewImageSequence->fn->getImageCount(Info_BoardViewImageSequence);
    Info_BoardViewImageSequence->fn->showImage(Info_BoardViewImageSequence, count - 1);
    
    Info_HWF_DisplayInfoFront->fn->setVisible(Info_HWF_DisplayInfoFront, LE_FALSE);
    
    Info_SAME5xScrollPanel->fn->installEventFilter(Info_SAME5xScrollPanel, Info_eventFilter);
    
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    Info_FPSLabel->fn->setVisible(Info_FPSLabel, stats_enabled == true);
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT);    
}

void Info_OnHide(void)
{
    Info_SAME5xScrollPanel->fn->removeEventFilter(Info_SAME5xScrollPanel, Info_eventFilter);
    
    fpsStr.fn->destructor(&fpsStr);
}

static SCRN_INFO_STATUS Info_ProcessMCUSubMenu(SCRN_INFO_SUBSTATE * substate,
                                               SCRN_INFO_EVENT * event)
{
    SCRN_INFO_STATUS retval = SCRN_INFO_STAT_BUSY;
    
    switch (*event)
    {
        case SCRN_INFO_EVENT_SHOW_INIT:
        {
            Info_MCUPanel->fn->setX(Info_MCUPanel, 0);
            Info_SAME5xDetailedImage->fn->setY(Info_SAME5xDetailedImage, 0);
            
            Info_ImageWidget1->fn->setVisible(Info_ImageWidget1, LE_FALSE);
            Info_ImageWidget2->fn->setVisible(Info_ImageWidget2, LE_FALSE);            
            
            *event = SCRN_INFO_EVENT_NONE;            
            break;
        }
        case SCRN_INFO_EVENT_EXIT:
        {
            Info_MCUPanel->fn->setX(Info_MCUPanel, -480);
            
            *substate = SCRN_INFO_SUBMENU_EXIT;
            *event = SCRN_INFO_EVENT_NONE;
            retval = SCRN_INFO_STAT_DONE;

            break;
        }
        case SCRN_INFO_EVENT_TOUCH_MOVEY:
        {
            int ypos;
            
            Info_SAME5xDetailedImage->fn->translate(Info_SAME5xDetailedImage, 0, touch_evt_argy);

            ypos = Info_SAME5xDetailedImage->fn->getY(Info_SAME5xDetailedImage);
            if (ypos > 0)
                Info_SAME5xDetailedImage->fn->setY(Info_SAME5xDetailedImage, 0);
            else if (ypos < MAX_E54INFO_POS)
                    Info_SAME5xDetailedImage->fn->setY(Info_SAME5xDetailedImage, MAX_E54INFO_POS);
            
            *event = SCRN_INFO_EVENT_NONE;

        }
        case SCRN_INFO_EVENT_TOUCH_DOWN:
        {
            Info_ImageWidget1->fn->setVisible(Info_ImageWidget1, LE_TRUE);
            Info_ImageWidget2->fn->setVisible(Info_ImageWidget2, LE_TRUE);
            break;
        }
        case SCRN_INFO_EVENT_TOUCH_UP:
        case SCRN_INFO_EVENT_TOUCH_TAP:
        {
            Info_ImageWidget1->fn->setVisible(Info_ImageWidget1, LE_FALSE);
            Info_ImageWidget2->fn->setVisible(Info_ImageWidget2, LE_FALSE);
        }
        default:
            break;                        
    }
    
    return retval;
}

static SCRN_INFO_STATUS Info_ProcessHWSubMenu(SCRN_INFO_SUBSTATE * substate,
                                              SCRN_INFO_EVENT * event)
{
    SCRN_INFO_STATUS retval = SCRN_INFO_STAT_BUSY;
    
    switch (*event)
    {
        case SCRN_INFO_EVENT_SHOW_INIT:
        {
            Info_BoardViewPanel->fn->setX(Info_BoardViewPanel, 0);
            Info_HWF_DisplayInfoFront->fn->setVisible(Info_HWF_DisplayInfoFront, LE_FALSE);
            Info_BoardViewImageSequence->fn->showImage(Info_BoardViewImageSequence, 0);
            
            *event = SCRN_INFO_EVENT_SHOW_INIT2;            
            break;
        }
        case SCRN_INFO_EVENT_SHOW_INIT2:
        {
            Info_HWF_DisplayInfoFront->fn->setVisible(Info_HWF_DisplayInfoFront, LE_TRUE); 
            
            *event = SCRN_INFO_EVENT_SHOW_FRONT;                 
            break;
        }
        case SCRN_INFO_EVENT_EXIT:
        {
            Info_BoardViewPanel->fn->setX(Info_BoardViewPanel, 480);
            
            *substate = SCRN_INFO_SUBMENU_EXIT;
            *event = SCRN_INFO_EVENT_NONE;

            break;
        }
        case SCRN_INFO_EVENT_SHOW_BACK:
        {
            if (Info_BoardViewImageSequence->activeIdx > 0)
            {
                Info_BoardViewImageSequence->fn->showPreviousImage(Info_BoardViewImageSequence);
                if (Info_BoardViewImageSequence->activeIdx == 0)
                {
                    Info_HWF_DisplayInfoFront->fn->setString(Info_HWF_DisplayInfoFront, (leString*) &string_HWF_Back);               
                }
            }
            else
            {
                *event = SCRN_INFO_EVENT_NONE;
            }
            
            break;
        }
        case SCRN_INFO_EVENT_SHOW_FRONT:
        {
            unsigned int count = Info_BoardViewImageSequence->fn->getImageCount(Info_BoardViewImageSequence);
            
            if (Info_BoardViewImageSequence->activeIdx < count - 1)
            {
                Info_BoardViewImageSequence->fn->showNextImage(Info_BoardViewImageSequence);
                if (Info_BoardViewImageSequence->activeIdx == count - 1)
                {
                    Info_HWF_DisplayInfoFront->fn->setString(Info_HWF_DisplayInfoFront, (leString*) &string_HWF_Front);          
                }
            }
            else
            {
                *event = SCRN_INFO_EVENT_NONE;
            }
            
            break;
        }
        case SCRN_INFO_EVENT_TOUCH_UP:
        {
            if (touch_evt_argx > 0)
            {
                *event = SCRN_INFO_EVENT_SHOW_FRONT;
            }
            else
            {
                *event = SCRN_INFO_EVENT_SHOW_BACK;
            }
            break;
        }
        case SCRN_INFO_EVENT_TOUCH_MOVEX:
        {
            unsigned int count = Info_BoardViewImageSequence->fn->getImageCount(Info_BoardViewImageSequence);
            
            if (touch_evt_argx > 0)
            {
                Info_BoardViewImageSequence->fn->showNextImage(Info_BoardViewImageSequence);
            }
            else
            {
                Info_BoardViewImageSequence->fn->showPreviousImage(Info_BoardViewImageSequence);
            }
            
            //Front
            if (Info_BoardViewImageSequence->activeIdx == count - 1)
            {
                //Show front
                Info_HWF_DisplayInfoFront->fn->setString(Info_HWF_DisplayInfoFront, (leString*) &string_HWF_Front);
            }
            else if (Info_BoardViewImageSequence->activeIdx == 0)
            {
                //Show back
                Info_HWF_DisplayInfoFront->fn->setString(Info_HWF_DisplayInfoFront, (leString*) &string_HWF_Back);
            }
            
            *event = SCRN_INFO_EVENT_NONE;
            
            break;
        }
        case SCRN_INFO_EVENT_TOUCH_TAP:
        {
            unsigned int count = Info_BoardViewImageSequence->fn->getImageCount(Info_BoardViewImageSequence);
            
            //Back showing
            if (Info_BoardViewImageSequence->activeIdx < count/2)
            {
                *event = SCRN_INFO_EVENT_SHOW_FRONT;
            }
            //Front showing
            else
            {
                *event = SCRN_INFO_EVENT_SHOW_BACK;
            }
            
            break;
        }
        default:
            break;                        
    }
    
    return retval;
}

static SCRN_INFO_STATUS Info_ProcessSWSubMenu(SCRN_INFO_SUBSTATE * substate,
                                              SCRN_INFO_EVENT * event)
{
    SCRN_INFO_STATUS retval = SCRN_INFO_STAT_BUSY;

    switch (*event)
    {
        case SCRN_INFO_EVENT_SHOW_INIT:
        {
            Info_SoftwarePanel->fn->setX(Info_SoftwarePanel, 0);
            
            Info_RedBarPanel->fn->setWidth(Info_RedBarPanel, 5);
            Info_SWModuleTitle->fn->setWidth(Info_SWModuleTitle, 5);
            Info_SWModuleDesc->fn->setWidth(Info_SWModuleDesc, 5);
            
            Info_SWModuleTitle->fn->setString(Info_SWModuleTitle, NULL);
            Info_SWModuleDesc->fn->setString(Info_SWModuleDesc, NULL);            

            Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_FALSE);
            Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_FALSE);
            Info_TouchIconsImage->fn->setVisible(Info_TouchIconsImage, LE_FALSE);
            
            Info_ButtonWidget0->fn->setPressed(Info_ButtonWidget0, LE_FALSE);
            Info_ButtonWidget1->fn->setPressed(Info_ButtonWidget1, LE_FALSE);
            Info_ButtonWidget2->fn->setPressed(Info_ButtonWidget2, LE_FALSE);
            Info_ButtonWidget3->fn->setPressed(Info_ButtonWidget3, LE_FALSE);
            Info_ButtonWidget4->fn->setPressed(Info_ButtonWidget4, LE_FALSE);
            
            *event = SCRN_INFO_EVENT_SHOW_INIT1;
            
            break;
        }
        case SCRN_INFO_EVENT_SHOW_INIT1:
        {
            if (Info_SWModuleTitle->fn->getWidth(Info_SWModuleTitle) < PANEL_WIDTH_SW_INFO - BAR_ANIM_DELTA_PIX)
            {
                Info_SWModuleTitle->fn->setWidth(Info_SWModuleTitle, 
                        Info_SWModuleTitle->fn->getWidth(Info_SWModuleTitle) + 
                        BAR_ANIM_DELTA_PIX);
            }
            else if (Info_RedBarPanel->fn->getWidth(Info_RedBarPanel) < PANEL_WIDTH_SW_INFO - BAR_ANIM_DELTA_PIX)
            {
                Info_RedBarPanel->fn->setWidth(Info_RedBarPanel, 
                        Info_RedBarPanel->fn->getWidth(Info_RedBarPanel) + 
                        BAR_ANIM_DELTA_PIX);
            }
            else if (Info_SWModuleDesc->fn->getWidth(Info_SWModuleDesc) < PANEL_WIDTH_SW_INFO - BAR_ANIM_DELTA_PIX)
            {
                Info_SWModuleDesc->fn->setWidth(Info_SWModuleDesc, 
                        Info_SWModuleTitle->fn->getWidth(Info_SWModuleDesc) + 
                        BAR_ANIM_DELTA_PIX);
            }
            else if (Info_SWModuleTitle->fn->getString(Info_SWModuleTitle) == NULL)
            {
                Info_SWModuleTitle->fn->setWidth(Info_SWModuleTitle,PANEL_WIDTH_SW_INFO);
                Info_RedBarPanel->fn->setWidth(Info_RedBarPanel,PANEL_WIDTH_SW_INFO);
                Info_SWModuleDesc->fn->setWidth(Info_SWModuleDesc,PANEL_WIDTH_SW_INFO);
                        
                Info_SWModuleTitle->fn->setString(Info_SWModuleTitle,
                                                 (leString *)&string_MH3_Title);
            }
            else if (Info_SWModuleDesc->fn->getString(Info_SWModuleDesc) == NULL)
            {
                Info_SWModuleDesc->fn->setString(Info_SWModuleDesc,
                                                 (leString *)&string_MH3_Desc);
            }
            else 
            {
                Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_TRUE);
                
                *event = SCRN_INFO_EVENT_NONE;                  
            }

            break;
        }
        case SCRN_INFO_EVENT_SHOW_MH3:
        {
            Info_SWModuleTitle->fn->setString(Info_SWModuleTitle,
                                                 (leString *)&string_MH3_Title);
            Info_SWModuleDesc->fn->setString(Info_SWModuleDesc,
                                                 (leString *)&string_MH3_Desc);

            Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_FALSE);
            Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_TRUE);
            Info_TouchIconsImage->fn->setVisible(Info_TouchIconsImage, LE_FALSE);
            
            *event = SCRN_INFO_EVENT_NONE;
            break;
        }
        case SCRN_INFO_EVENT_SHOW_MHGS:
        {
            Info_SWModuleTitle->fn->setString(Info_SWModuleTitle,
                                                 (leString *)&string_MHGS_Title);
            Info_SWModuleDesc->fn->setString(Info_SWModuleDesc,
                                                 (leString *)&string_MHGS_Desc);

            Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_TRUE);
            Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_FALSE);
            Info_TouchIconsImage->fn->setVisible(Info_TouchIconsImage, LE_FALSE);
            
            *event = SCRN_INFO_EVENT_NONE;
            break;
        }
        case SCRN_INFO_EVENT_SHOW_TOUCH:
        {
            Info_SWModuleTitle->fn->setString(Info_SWModuleTitle,
                                                 (leString *)&string_MH3_Touch);
            Info_SWModuleDesc->fn->setString(Info_SWModuleDesc,
                                                 (leString *)&string_MH3_Touch_Desc);

            Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_FALSE);
            Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_FALSE);
            Info_TouchIconsImage->fn->setVisible(Info_TouchIconsImage, LE_TRUE);
            
            *event = SCRN_INFO_EVENT_NONE;
            break;
        }
        case SCRN_INFO_EVENT_EXIT:
        {
            Info_SoftwarePanel->fn->setX(Info_SoftwarePanel, 480);
            
            Info_SWModuleTitle->fn->setString(Info_SWModuleTitle, NULL);
            Info_SWModuleDesc->fn->setString(Info_SWModuleDesc, NULL);

            Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_FALSE);
            Info_MH3IconsImage->fn->setVisible(Info_MH3IconsImage, LE_FALSE);  
            Info_TouchIconsImage->fn->setVisible(Info_TouchIconsImage, LE_FALSE);
            
            *substate = SCRN_INFO_SUBMENU_EXIT;
            *event = SCRN_INFO_EVENT_NONE;

            break;
        }
        case SCRN_INFO_EVENT_TOUCH_ARROW_UP:
        {
            *event = SCRN_INFO_EVENT_NONE;
            
            Info_ListWheelWidget0->fn->selectPreviousItem(Info_ListWheelWidget0);
            
            break;
        }
        case SCRN_INFO_EVENT_TOUCH_ARROW_DOWN:
        {
            *event = SCRN_INFO_EVENT_NONE;
            
            Info_ListWheelWidget0->fn->selectNextItem(Info_ListWheelWidget0);

            break;
        }
        default:
            break;                        
    }
    
    return retval;
}

static SCRN_INFO_STATUS Info_ProcessRefsSubMenu(SCRN_INFO_SUBSTATE * substate,
                                                SCRN_INFO_EVENT * event)
{
    SCRN_INFO_STATUS retval = SCRN_INFO_STAT_BUSY;

    switch (*event)
    {
        case SCRN_INFO_EVENT_SHOW_INIT:
        {
            Info_ResourcesPanel->fn->setX(Info_ResourcesPanel, 0);
            *event = SCRN_INFO_EVENT_NONE;
            
            break;
        }        
        case SCRN_INFO_EVENT_EXIT:
        {
            Info_ResourcesPanel->fn->setX(Info_ResourcesPanel, 480);
            
            *substate = SCRN_INFO_SUBMENU_EXIT;
            *event = SCRN_INFO_EVENT_NONE;

            break;
        }
        default:
            break;                        
    }
    
    return retval;
}

static SCRN_INFO_STATUS Info_ProcessSubMenu(SCRN_INFO_STATE * state,
                                            SCRN_INFO_SUBSTATE * substate,
                                            SCRN_INFO_EVENT * event)
{
    switch(*substate)
    {
        case SCRN_INFO_SUBMENU_INIT:
        {
#ifdef USE_TICK_ANIMATION            
            if (tick_count != tick_count_last)
#endif               
            {   
                if (Info_ShowMenuButtons(false) == SCRN_INFO_STAT_DONE)
                {
                    Info_IgatImageSequence->fn->setVisible(Info_IgatImageSequence, LE_FALSE);
                    *substate = SCRN_INFO_SUBMENU_PROCESSING;
                    *event = SCRN_INFO_EVENT_SHOW_INIT;
                }
#ifdef USE_TICK_ANIMATION
                tick_count_last = tick_count;
#endif
            }            
            break;
        }
        case SCRN_INFO_SUBMENU_EXIT:
        {
#ifdef USE_TICK_ANIMATION
            if (tick_count != tick_count_last)
#endif
            {            
                if (Info_ShowMenuButtons(true) == SCRN_INFO_STAT_DONE)
                {
                    Info_IgatImageSequence->fn->setVisible(Info_IgatImageSequence, LE_TRUE);
                    
                    return SCRN_INFO_STAT_DONE;
                }
#ifdef USE_TICK_ANIMATION
                tick_count_last = tick_count;
#endif                
            }            
            break;
        }
        case SCRN_INFO_SUBMENU_PROCESSING: //fall through
        default:
        {
            SCRN_INFO_STATUS retval = SCRN_INFO_STAT_BUSY; 
            
            switch (*state)
            {
                case SCRN_INFO_MCU:
                {
                    retval = Info_ProcessMCUSubMenu(substate, event);
                    break;
                }
                case SCRN_INFO_HW:
                {
                    retval = Info_ProcessHWSubMenu(substate, event);
                    break;
                }                    
                case SCRN_INFO_SW:
                {
                    retval = Info_ProcessSWSubMenu(substate, event);
                    break;
                }                    
                case SCRN_INFO_REFS:
                {
                    retval = Info_ProcessRefsSubMenu(substate, event);
                    break;
                }                   
                default:
                    break;
            }
            
            if (retval == SCRN_INFO_STAT_DONE )
            {
                *substate = SCRN_INFO_SUBMENU_EXIT;
            }

            break;
        }
    }
    
    return SCRN_INFO_STAT_BUSY;
}
void Info_OnUpdate(void)
{
    switch(info_state)
    {
        case SCRN_INFO_STATE_INIT:
        {
            nextScreen = 0;
            APP_ClearGesture();
            info_state = SCRN_INFO_STATE_WAIT_FOR_READY;
            
            break;
        }
        case SCRN_INFO_STATE_WAIT_FOR_READY:
        {
            if(leGetRenderState()->frameState != LE_FRAME_READY || 
               leEvent_GetCount() != 0 ||
               isDisplayReady() != true)
                break;
            
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;                 

            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            info_state = SCRN_INFO_STATE_SHOWING;

            break;
        }
        case SCRN_INFO_STATE_SHOWING:
        {
            if (Info_ShowMenuButtons(true) ==  SCRN_INFO_STAT_DONE)
            {
                tick_count_last = tick_count;
                info_state = SCRN_INFO_STATE_IDLE;
                Info_IgatImageSequence->fn->setVisible(Info_IgatImageSequence, LE_TRUE);
            }
                
            break;
        }
        case SCRN_INFO_STATE_IDLE:
        {
            switch(info_event)
            {
                case SCRN_INFO_EVENT_SHOW_HW:
                {
                    info_state = SCRN_INFO_HW;
                    info_substate = SCRN_INFO_SUBMENU_INIT;
                    info_event = SCRN_INFO_EVENT_NONE;
                    break;
                }
                case SCRN_INFO_EVENT_SHOW_MCU:
                {
                    info_state = SCRN_INFO_MCU;
                    info_substate = SCRN_INFO_SUBMENU_INIT;
                    info_event = SCRN_INFO_EVENT_NONE;
                    break;
                }
                case SCRN_INFO_EVENT_SHOW_SW:
                {
                    info_state = SCRN_INFO_SW;
                    info_substate = SCRN_INFO_SUBMENU_INIT;
                    info_event = SCRN_INFO_EVENT_NONE;
                    break;
                }                                
                case SCRN_INFO_EVENT_SHOW_REFS:
                {
                    info_state = SCRN_INFO_REFS;
                    info_substate = SCRN_INFO_SUBMENU_INIT;
                    info_event = SCRN_INFO_EVENT_NONE;
                    break;
                }
                
                case SCRN_INFO_EVENT_EXIT:
                {
                    if (Info_ShowMenuButtons(false) ==  SCRN_INFO_STAT_DONE)
                    {
                        nextScreen = screenID_Menu;
                        info_state = SCRN_INFO_EXIT; 
                        info_event = SCRN_INFO_EVENT_NONE;
                    }
                    break;
                }
                default:
                    break;
            }
            
            if (tick_count >= tick_count_last)
            {
                if (tick_count - tick_count_last > NUM_COUNT_SEC_TICK * 2)
                {
                    Info_IgatImageSequence->fn->showNextImage(Info_IgatImageSequence);
                    
                    tick_count_last = tick_count;
                }
            }
            else
            {
                tick_count_last = tick_count;
            }
            
            CheckGestures();
            
            break;
        }
        case SCRN_INFO_MCU:
        case SCRN_INFO_HW:
        case SCRN_INFO_SW:
        case SCRN_INFO_REFS:
        {
            if (Info_ProcessSubMenu(&info_state,
                                    &info_substate,
                                    &info_event) == SCRN_INFO_STAT_DONE)
            {
                info_state = SCRN_INFO_STATE_IDLE;
            }
            
            CheckGestures();
            
            
            break;
        }
        case SCRN_INFO_EXIT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                    break;
            
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
#ifdef RTOS_ENABLED
        sprintf(fpsStrBuff, "%u fps, cpu %u%%", fps, 100 - cpu_free); 
#else
        sprintf(fpsStrBuff, "%u fps", fps);
#endif
        fpsStr.fn->setFromCStr(&fpsStr, fpsStrBuff);    
        Info_FPSLabel->fn->setString(Info_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    }    
}