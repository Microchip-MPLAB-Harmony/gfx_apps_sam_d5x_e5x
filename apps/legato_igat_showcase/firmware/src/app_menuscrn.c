#include "definitions.h"
#include "app.h"
#include "gfx/legato/common/legato_utils.h"

#define SCROLL_YMAX_PIX 10
#define SCROLL_XMIN_PIX 1 //3
#define SWIPE_XMIN_PIX 5
#define SLIDE_X_DELTA_PIX 10
#define MAX_LEFT_OFFSET (-120)
#define MAX_LEFT_SLIDE (-240)
#define MAX_RIGHT_SLIDE (0)
#define DEFAULT_X_POS (-120)
#define START_X_POS (-720)
#define NUM_MENU_ITEMS 7
#define NUM_MENU_BUTTONS 6
#define SLIDE_X_COEFF 8

//#define MAX_TRANSLATE_X 20
//#define USE_GESTURE_TAP_SWIPE 1

#define INVALID_SCREEN_ID -1

typedef enum
{
    MENU_STATE_INIT,
    MENU_STATE_WAIT_FOR_READY,
    MENU_STATE_WAIT_FOR_BACKLIGHT,
    MENU_STATE_SLIDE_IN,
    MENU_STATE_IDLE,
    MENU_STATE_SWITCH_SCREEN,            
    MENU_STATE_SLIDING_LEFT,
    MENU_STATE_SLIDING_RIGHT,
} MENU_STATE;

typedef enum
{
    MENU_EVENT_NONE,
    MENU_EVENT_LOCK_LEFT,
    MENU_EVENT_LOCK_RIGHT,
    MENU_EVENT_SLIDE_RIGHT,
    MENU_EVENT_SLIDE_LEFT,
    MENU_EVENT_TOUCH_UP,
    MENU_EVENT_TOUCH_DOWN,
    MENU_EVENT_TOUCH_TAP,
} MENU_EVENT;

typedef enum
{
    MENU_MOVE_NONE,
    MENU_MOVE_LEFT,
    MENU_MOVE_RIGHT,
} MOVE_FLAG;

typedef struct
{
    leImage * image;
    int screenID;
    
} MENU_BUTTON_SCREEN_MAP;

MENU_BUTTON_SCREEN_MAP menuMap[NUM_MENU_ITEMS] = 
{
    {&MenuCooker2565, screenID_CkrScrn2},    
    {&MenuPlayer565, screenID_PlyrScrn},
    {&MenuCooker565, screenID_CkrScrn1},
    {&MenuCar565, screenID_CCtrlScrn1},
    {&MenuGesture565, screenID_MGScrn},
    {&info565, screenID_Info},
    {&Settings565, screenID_Settings},
};

leButtonWidget ** menuButtons[NUM_MENU_BUTTONS] =
{
    &Menu_MenuButton0,
    &Menu_MenuButton1,
    &Menu_MenuButton2,
    &Menu_MenuButton3,
    &Menu_MenuButton4,
    &Menu_MenuButton5,
};

static MENU_STATE state = MENU_STATE_INIT;
static MENU_EVENT event = MENU_EVENT_NONE;
static MOVE_FLAG moveFlag = MENU_MOVE_NONE;
static int32_t deltaY;
static int32_t deltaX;
static int32_t lastX, lastY;
static uint32_t menuStartIndex = 0;
static int nextScreen;

static void AppMenu_AssignButtons(unsigned int start)
{
    int btnId, imgId;
    
    for (btnId = 0, imgId = menuStartIndex; 
         btnId < NUM_MENU_BUTTONS;
         btnId++, imgId++)
    {
        leButtonWidget * button = *(menuButtons[btnId]);
        
        if (imgId >= NUM_MENU_ITEMS)
            imgId = 0;
        
        button->fn->setPressedImage(button, menuMap[imgId].image);
        button->fn->setReleasedImage(button, menuMap[imgId].image);
    }
}

static int AppMenu_GetNextScreen(leButtonWidget * button)
{
    int i;
    for (i = 0; i < NUM_MENU_ITEMS; i++)
    {
        if (button->fn->getPressedImage(button) == (leImage*) menuMap[i].image)
        {
            return menuMap[i].screenID;
        }
    }
    
    return INVALID_SCREEN_ID;
}

static leBool Menu2_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{    
    leBool retval = LE_FALSE;

    int32_t x, y;
    
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            tick_count_last = tick_count;
            
            lastX = ((leWidgetEvent_TouchDown *) evt)->x;
            lastY = ((leWidgetEvent_TouchDown *) evt)->y;                    
            
            moveFlag = MENU_MOVE_NONE;
            
            event = MENU_EVENT_TOUCH_DOWN;

            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            retval = LE_TRUE;
            
            break;
        }   
        case LE_EVENT_TOUCH_UP:            
        {
            y = ((leWidgetEvent_TouchUp *) evt)->y;
            x = ((leWidgetEvent_TouchUp *) evt)->x;
            
#ifdef USE_GESTURE_TAP_SWIPE
            lastX = x;
            lastY = y;
#else            
            deltaX = x - lastX;

            //basic tap detection
            if (abs(deltaX) <= SWIPE_XMIN_PIX &&
                tick_count >= tick_count_last && 
                tick_count - tick_count_last < NUM_COUNT_TAP_TICK)
            {
                moveFlag = MENU_MOVE_NONE;
            }
            
            //Tap detected, toggle if button was tapped
            switch (moveFlag)
            {
                case MENU_MOVE_NONE:
                {
                    lastX = x;
                    lastY = y;
                    
                    event = MENU_EVENT_TOUCH_UP;
                    
                    break;
                }
                case MENU_MOVE_LEFT:
                {
                    event = MENU_EVENT_LOCK_LEFT;                    
                    break;
                }
                case MENU_MOVE_RIGHT:
                {
                    event = MENU_EVENT_LOCK_RIGHT;
                    break;
                }
                default:
                    break;
            }
#endif            
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;

            break;        
        }
        case LE_EVENT_TOUCH_MOVE:            
        {
            if (state != MENU_STATE_IDLE)
                break;
            
            y = ((leWidgetEvent_TouchMove *) evt)->y;
            x = ((leWidgetEvent_TouchMove *) evt)->x;
            
            deltaY = y - lastY;
            deltaX = x - lastX;
            
            if (abs(deltaX) > SCROLL_XMIN_PIX &&
                abs(deltaY) < SCROLL_YMAX_PIX)
            {
                if (x > lastX)
                {
                    event = MENU_EVENT_SLIDE_RIGHT;
                    moveFlag = MENU_MOVE_RIGHT;
                }
                else if (x < lastX)
                {
                    event = MENU_EVENT_SLIDE_LEFT;
                    moveFlag = MENU_MOVE_LEFT;
                }
            }
            
            lastX = x;
            lastY = y;
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;
           
            break;
        }
        default:
            break;
    }
    
   return retval;
}

static leWidgetEventFilter Menu_eventFilter =
{
    Menu2_filterEvent,
    NULL
};

void Menu_OnShow(void)
{
    state = MENU_STATE_INIT;
    event = MENU_EVENT_NONE;
    menuStartIndex = 0;
    
    Menu_MenuButton0->fn->installEventFilter(Menu_MenuButton0, Menu_eventFilter);
    Menu_MenuButton1->fn->installEventFilter(Menu_MenuButton1, Menu_eventFilter);
    Menu_MenuButton2->fn->installEventFilter(Menu_MenuButton2, Menu_eventFilter);
    Menu_MenuButton3->fn->installEventFilter(Menu_MenuButton3, Menu_eventFilter);
    Menu_MenuButton4->fn->installEventFilter(Menu_MenuButton4, Menu_eventFilter);
    Menu_MenuButton5->fn->installEventFilter(Menu_MenuButton5, Menu_eventFilter);
    
    Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, START_X_POS);
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    Menu_FPSLabel->fn->setVisible(Menu_FPSLabel, stats_enabled == true);
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT);
    
    AppMenu_AssignButtons(0);
}

void Menu_OnHide(void)
{
    Menu_MenuButton0->fn->removeEventFilter(Menu_MenuButton0, Menu_eventFilter);
    Menu_MenuButton1->fn->removeEventFilter(Menu_MenuButton1, Menu_eventFilter);
    Menu_MenuButton2->fn->removeEventFilter(Menu_MenuButton2, Menu_eventFilter);
    Menu_MenuButton3->fn->removeEventFilter(Menu_MenuButton3, Menu_eventFilter);
    Menu_MenuButton4->fn->removeEventFilter(Menu_MenuButton4, Menu_eventFilter);
    Menu_MenuButton5->fn->removeEventFilter(Menu_MenuButton5, Menu_eventFilter);
    
    fpsStr.fn->destructor(&fpsStr);
}

void Menu_OnUpdate(void)
{
    switch (state)
    {
        case MENU_STATE_INIT:
        {
            state = MENU_STATE_WAIT_FOR_READY;
            break;
        }
        case MENU_STATE_WAIT_FOR_READY:
        {
            if(leGetRenderState()->frameState != LE_FRAME_READY || 
               leEvent_GetCount() != 0)
                break;
            
            if(isDisplayReady() != true)
                break;
            
            state = MENU_STATE_WAIT_FOR_BACKLIGHT;
            
            break;
        }
        case MENU_STATE_WAIT_FOR_BACKLIGHT:
        {
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;
            
            state = MENU_STATE_SLIDE_IN;
            
            break;
        }
        case MENU_STATE_SLIDE_IN:
        {
            int x = Menu_PanelWidget1->fn->getX(Menu_PanelWidget1);
            int deltaX = (x - DEFAULT_X_POS) / SLIDE_X_COEFF;
            
            if (deltaX < 0)
            {
                Menu_PanelWidget1->fn->translate(Menu_PanelWidget1, -deltaX, 0);
            }
            else
            {
                Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, DEFAULT_X_POS);
                state = MENU_STATE_IDLE;
    
                APP_ClearGesture();
            }

            break;
        }
        case MENU_STATE_IDLE:
        {
            APP_GESTURE_CMD gesture = APP_GetGesture();
            //check for gestures
            if (gesture != APP_GEST_NONE)
            {
                switch(gesture)
                {
#ifdef USE_GESTURE_TAP_SWIPE                      
                    case APP_GEST_TAP:
                    {
                        event = MENU_EVENT_TOUCH_TAP;
                        break;
                    }
                    case APP_GEST_LEFT_SWIPE:
                    {
                        event = MENU_EVENT_LOCK_LEFT;
                        break;
                    }
                    case APP_GEST_RIGHT_SWIPE:
                    {
                        event = MENU_EVENT_LOCK_RIGHT;
                        break;
                    }
#endif 
                    case APP_START_MG_S:
                    {
                        APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
                        nextScreen = screenID_Intro;
                        state = MENU_STATE_SWITCH_SCREEN;
                        break;
                    }
                    case APP_GEST_LEFT_SWIPE_DUAL:
                    {
                        APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
                        nextScreen = screenID_Info;
                        state = MENU_STATE_SWITCH_SCREEN;
                        break;
                    }
                    case APP_GEST_RIGHT_SWIPE_DUAL:
                    {
                        APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
                        nextScreen = screenID_CkrScrn1;
                        state = MENU_STATE_SWITCH_SCREEN;
                        break;
                    }                    
                    default:
                        break;
                }
                
                APP_ClearGesture();
            }
            
            switch(event)
            {
                case MENU_EVENT_LOCK_LEFT:
                {
                    state = MENU_STATE_SLIDING_LEFT;
                    
                    event = MENU_EVENT_NONE;
                    break;
                }
                case MENU_EVENT_LOCK_RIGHT:
                {
                    state = MENU_STATE_SLIDING_RIGHT;
                    
                    event = MENU_EVENT_NONE;
                    break;
                }
                case MENU_EVENT_SLIDE_LEFT:
                case MENU_EVENT_SLIDE_RIGHT:                    
                {
                    int x;
                    
                    int deltaXLocal = deltaX;

#ifdef MAX_TRANSLATE_X                    
                    if (abs(deltaXLocal) > MAX_TRANSLATE_X)
                    {
                        if (deltaXLocal > 0)
                        {
                            deltaX -= MAX_TRANSLATE_X;
                            deltaXLocal = MAX_TRANSLATE_X;
                        }
                        else
                        {
                            deltaX += MAX_TRANSLATE_X;
                            deltaXLocal = -MAX_TRANSLATE_X;
                        }
                    }
                    else
                    {
                        event = MENU_EVENT_NONE;
                    }
#else
                    event = MENU_EVENT_NONE;
#endif                    
                    
                    Menu_PanelWidget1->fn->translate(Menu_PanelWidget1, deltaXLocal, 0);
                    
                    x = Menu_PanelWidget1->fn->getX(Menu_PanelWidget1);
                    if (x < MAX_LEFT_SLIDE)
                    {
                        Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, DEFAULT_X_POS - (MAX_LEFT_SLIDE - x));
                        menuStartIndex = (menuStartIndex < NUM_MENU_ITEMS - 1) ? menuStartIndex + 1 : 0;
                        AppMenu_AssignButtons(menuStartIndex);
                    }
                    else if (x > MAX_RIGHT_SLIDE)
                    {
                        Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, DEFAULT_X_POS + x);
                        menuStartIndex = (menuStartIndex > 0) ? menuStartIndex - 1 : NUM_MENU_ITEMS - 1;
                        AppMenu_AssignButtons(menuStartIndex);
                    }
                    
                    
                                
                    break;
                }
                case MENU_EVENT_TOUCH_UP:
                case MENU_EVENT_TOUCH_TAP:
                {
                    leWidget * wgt = leUtils_PickFromWidget(
                                (leWidget *) &leGetState()->rootWidget[0], lastX, lastY);

                    if (wgt->type == LE_WIDGET_BUTTON)
                    {
                        
                        leButtonWidget* btn = (leButtonWidget*) wgt;
                        nextScreen = AppMenu_GetNextScreen(btn);
                        
                        if (nextScreen != INVALID_SCREEN_ID)
                        {
                            APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
                            state = MENU_STATE_SWITCH_SCREEN;
                        }
                    }
                    
                    event = MENU_EVENT_NONE;
                                
                    break;
                }
                case MENU_EVENT_TOUCH_DOWN: //do nothing
                {
                    event = MENU_EVENT_NONE;
                }                    
                default:
                    break;
            }

            break;
        }
        case MENU_STATE_SLIDING_LEFT:
        {
            int32_t x = Menu_PanelWidget1->fn->getX(Menu_PanelWidget1);

            if (event != MENU_EVENT_NONE)
            {
                state = MENU_STATE_IDLE;
                
                break;
            }

            if (x > MAX_LEFT_SLIDE + SLIDE_X_DELTA_PIX)
            {
                x -= SLIDE_X_DELTA_PIX;
            }
            else
            {
                x = MAX_LEFT_SLIDE;
                state = MENU_STATE_IDLE;
            }

            Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, x);

            break;
        }
        case MENU_STATE_SLIDING_RIGHT:
        {
            int32_t x = Menu_PanelWidget1->fn->getX(Menu_PanelWidget1);
            
            if (event != MENU_EVENT_NONE)
            {
                state = MENU_STATE_IDLE;
                
                break;
            }

            if (x < MAX_RIGHT_SLIDE - SLIDE_X_DELTA_PIX)
            {
                x += SLIDE_X_DELTA_PIX;
            }
            else
            {
                x = MAX_RIGHT_SLIDE;
                state = MENU_STATE_IDLE;
            }

            Menu_PanelWidget1->fn->setX(Menu_PanelWidget1, x);
            
            break;
        }
        case MENU_STATE_SWITCH_SCREEN:
        {
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
        Menu_FPSLabel->fn->setString(Menu_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    }
}