#include "definitions.h"
#include "app.h"
#include <stdio.h>
#include <string.h>

#define APP_MGSCRN_PRINTF(...) printf(__VA_ARGS__)

#define GEST_IMG_SHOW_POS_X 116
#define GEST_IMG_HIDE_POS_X 480

#define SHOW_TOUCH_2 1
#define TOUCH_POINT_SIZE 2

typedef enum
{
    MG_DEMO_M2D,
    MG_DEMO_MODE_GESTURES,
#ifdef ENABLE_MG_DEMO            
    MG_DEMO_MODE_ML,
#endif            
    MG_DEMO_MODE_MAX
} MG_TOUCH_DEMO_MODE;

typedef enum
{
    MG_SCRN_STATE_INIT,
    MG_SCRN_STATE_WAIT_FOR_READY,
    MG_SCRN_STATE_READY,
    MG_SCRN_STATE_IDLE,
    MG_SCRN_STATE_ACTIVE,
    MG_SCRN_STATE_DONE,
    MG_SCRN_STATE_EXIT,
} MG_SCRN_STATE;

typedef enum
{
    MG_SCRN_TOUCH_NONE,
    MG_SCRN_TOUCH_DOWN,
    MG_SCRN_TOUCH_MOVE,
    MG_SCRN_TOUCH_UP,
} MG_SCRN_TOUCH_CMD;

typedef enum
{
    MG_SCRN_DRAW_NONE,
    MG_SCRN_DRAW_CLEAR,
    MG_SCRN_DRAW_POINT,
} MG_SCRN_DRAW_CMD;

static MG_SCRN_STATE mgState = MG_SCRN_STATE_INIT;
static MG_SCRN_TOUCH_CMD touchCmd = MG_SCRN_TOUCH_NONE;
static MG_SCRN_DRAW_CMD drawCmd = MG_SCRN_DRAW_NONE;
#ifdef ENABLE_MG_DEMO   
static MG_TOUCH_DEMO_MODE mode = MG_DEMO_MODE_ML;
#else
static MG_TOUCH_DEMO_MODE mode = MG_DEMO_MODE_GESTURES;
#endif

static bool touchActive[2];
static int32_t prevX[2], prevY[2];
static int32_t lastX[2], lastY[2];
static int inputIdx = -1;

static leBool DrawSurface_filterEvent(leWidget* target, leWidgetEvent* evt, void* data);
static int nextScreen = 0;

extern bool mg_enabled;
static bool mg_enabled_saved;

static leWidgetEventFilter DrawSurface_eventFilter =
{
    DrawSurface_filterEvent,
    NULL
};

//The images in the array should match the enum APP_GESTURE_CMD
static leImage * gestureImages[APP_MAX_GESTURE] = 
{
    &GestUpSwipe,
    &GestDownSwipe,
    &GestLeftSwipe,
    &GestRightSwipe,
    &GestTapSingle,
    &GestTapDouble,
    &GestTwoFingerTapSingle,
    &GestWheelClockwise,
    &GestWheelCounterClockwise,
    &GestPinch,
    &GestZoom,
    //Dual Swipe Gestures
    NULL,
    NULL,
    //Edge Gestures
    NULL,
    NULL,
    NULL,
    NULL,    
    //Hold Gesture Images
    &GestUpSwipeHold,
    &GestDownSwipeHold,
    &GestLeftSwipeHold,            
    &GestRightSwipeHold,
    &GestTapHold,
    &GestTwoFingerTapHold,
#ifdef ENABLE_MG_DEMO      
    //Motion Gesture Images
    &GestMG_M,
    &GestMG_S,
    &GestMG_2,
    &GestMG_Check,
    &GestMG_Alpha,
    &GestMG_Star,
#endif            
};

static leBool DrawSurface_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{    
    leBool retval = LE_FALSE;
    int32_t touchID;

    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            //Clear the widget
            touchID = ((leWidgetEvent_TouchDown *) evt)->touchID;
            if (touchID < 2)
            {
                lastX[touchID] = ((leWidgetEvent_TouchDown *) evt)->x;
                lastY[touchID] = ((leWidgetEvent_TouchDown *) evt)->y;
                prevX[touchID] = lastX[touchID];
                prevY[touchID] = lastY[touchID];
                touchActive[touchID] = true;
            
                if (touchID == 0)
                {
                    touchCmd = MG_SCRN_TOUCH_DOWN;
                }
            }
            
            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            retval = LE_TRUE;
            
            break;
        }   
        case LE_EVENT_TOUCH_MOVE:            
        {
            touchID = ((leWidgetEvent_TouchMove *) evt)->touchID;
            if (touchID < 2)
            {            
                prevX[touchID] = lastX[touchID];
                prevY[touchID] = lastY[touchID];

                lastX[touchID] = ((leWidgetEvent_TouchMove *) evt)->x;
                lastY[touchID] = ((leWidgetEvent_TouchMove *) evt)->y;

                touchCmd = MG_SCRN_TOUCH_MOVE;
            }
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;
           
            break;
        }
        case LE_EVENT_TOUCH_UP:
        {
            touchID = ((leWidgetEvent_TouchUp *) evt)->touchID;
            touchActive[touchID] = false;
            
            touchCmd = MG_SCRN_TOUCH_UP;
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    
   return retval;
}

static void CheckNavGesture(void)
{
    APP_GESTURE_CMD gesture = APP_GetGesture();
    
    //Filter invalid gestures
    if (gesture == APP_GEST_RIGHT_SWIPE_DUAL)
    {
        nextScreen = screenID_CCtrlScrn1;
        mgState = MG_SCRN_STATE_EXIT;
        APP_ClearGesture(); 
    }
    else if (gesture == APP_GEST_LEFT_SWIPE_DUAL)
    {
        nextScreen = screenID_Info;
        mgState = MG_SCRN_STATE_EXIT;
        APP_ClearGesture(); 
    }
}

static void CheckGesture(void)
{
    APP_GESTURE_CMD gesture = APP_GetGesture();
    
    //Filter invalid gestures
    if ((mode == MG_DEMO_M2D) ||
        (mode == MG_DEMO_MODE_GESTURES && 
         gesture >=  APP_GEST_BASIC_END))
        return;
    
    if (gesture >= APP_MAX_GESTURE)
        return;
    
    APP_MGSCRN_PRINTF("xxxxx Done -> show gest %d \n\r", gesture);
    MGScrn_GestureImageWidget->fn->setImage
                            (MGScrn_GestureImageWidget, gestureImages[gesture]);
    MGScrn_GestureImageWidget->fn->setX
                            (MGScrn_GestureImageWidget, GEST_IMG_SHOW_POS_X);

    drawCmd = MG_SCRN_DRAW_CLEAR;
    
    APP_ClearGesture();        
}

void event_MGScrn_TouchModeButton_OnReleased(leButtonWidget* btn)
{
    mode = (mode < MG_DEMO_MODE_MAX - 1) ? mode + 1 : MG_DEMO_M2D;
    
#ifdef ENABLE_MG_DEMO  
    MGScrn_MGLogoImageWidget->fn->setVisible(MGScrn_MGLogoImageWidget, mode == MG_DEMO_MODE_ML);
    MGScrn_MG_Gestures->fn->setVisible(MGScrn_MG_Gestures, (mode == MG_DEMO_MODE_ML));
    MGScrn_MGLicenseLabel->fn->setVisible(MGScrn_MGLicenseLabel, (mode == MG_DEMO_MODE_ML));
#endif
    
    MGScrn_ImageSequenceWidget0->fn->showImage(MGScrn_ImageSequenceWidget0, mode);
    
    MGScrn_GestureImageWidget->fn->setX(MGScrn_GestureImageWidget, GEST_IMG_HIDE_POS_X);
    
    APP_ClearGesture();
}


leBool event_MGScrn_DrawSurfaceWidget0_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds)
{
    leBool retval = LE_TRUE;
    
    switch(drawCmd)
    {
        case MG_SCRN_DRAW_CLEAR:
        {
            APP_MGSCRN_PRINTF("++++ clear %d \n\r", touchCmd);
            leRenderer_FillArea_Safe(sfc->widget.rect.x,
                                    sfc->widget.rect.y,
                                    sfc->widget.rect.width,
                                    sfc->widget.rect.height,
                                    leScheme_GetRenderColor(sfc->widget.scheme, LE_SCHM_BASE),
                                    255);
            
            break;
        }
        case MG_SCRN_DRAW_POINT:
        {
            APP_MGSCRN_PRINTF("++++ drawPoint \n\r");
            if (touchActive[0] == true)
            {
                leRenderer_FillArea_Safe(lastX[0] - TOUCH_POINT_SIZE,
                                    lastY[0] - TOUCH_POINT_SIZE,
                                    TOUCH_POINT_SIZE * 2,
                                    TOUCH_POINT_SIZE * 2,
                                    leScheme_GetRenderColor(sfc->widget.scheme, LE_SCHM_FOREGROUND),
                                    255);
                
                leRenderer_DrawLine(lastX[0],
                                    lastY[0],
                                    prevX[0],
                                    prevY[0],
                                    leScheme_GetRenderColor(sfc->widget.scheme, LE_SCHM_FOREGROUND),
                                    255);
            }
#if SHOW_TOUCH_2            
            if (touchActive[1] == true)
            {
                leRenderer_FillArea_Safe(lastX[1] - TOUCH_POINT_SIZE,
                                    lastY[1] - TOUCH_POINT_SIZE,
                                    TOUCH_POINT_SIZE * 2,
                                    TOUCH_POINT_SIZE * 2,
                                    leScheme_GetRenderColor(sfc->widget.scheme, LE_SCHM_FOREGROUND),
                                    255);
                
                leRenderer_DrawLine(lastX[1],
                                    lastY[1],
                                    prevX[1],
                                    prevY[1],
                                    leScheme_GetRenderColor(sfc->widget.scheme, LE_SCHM_TEXT_HIGHLIGHT),
                                    255);
            }
#endif            

            break;
        }
        default:
        {
            break;
        }
    }
    
    return retval;
}



void event_MGScrn_HomeButton_OnPressed (leButtonWidget* btn)
{
    nextScreen = screenID_Menu;
    mgState = MG_SCRN_STATE_EXIT;
}

void MGScrn_OnShow(void)
{
    MGScrn_DrawSurfaceWidget0->fn->installEventFilter(MGScrn_DrawSurfaceWidget0, DrawSurface_eventFilter);    
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    MGScrn_FPSLabel->fn->setVisible(MGScrn_FPSLabel, stats_enabled == true); 
    
    MGScrn_GestureImageWidget->fn->setX(MGScrn_GestureImageWidget, GEST_IMG_HIDE_POS_X);
    
    
#ifdef ENABLE_MG_DEMO  
    MGScrn_ImageSequenceWidget0->fn->showImage(MGScrn_ImageSequenceWidget0, MG_DEMO_MODE_ML);
    mode = MG_DEMO_MODE_ML;
    mg_enabled_saved = mg_enabled;
    mg_enabled = true;
#else
    MGScrn_ImageSequenceWidget0->fn->showImage(MGScrn_ImageSequenceWidget0, MG_DEMO_MODE_GESTURES);
    MGScrn_MG_Gestures->fn->setVisible(MGScrn_MG_Gestures, LE_FALSE);
#endif    
    
    APP_SetBacklightBrightness(BACKLIGHT_MIN_PCT);

    mgState = MG_SCRN_STATE_INIT;
}

void MGScrn_OnHide(void)
{
    MGScrn_DrawSurfaceWidget0->fn->removeEventFilter(MGScrn_DrawSurfaceWidget0, DrawSurface_eventFilter); 
    
    SYS_INP_RemoveListener(inputIdx);
    
    mg_enabled = mg_enabled_saved;
    
    fpsStr.fn->destructor(&fpsStr);
}

void MGScrn_OnUpdate(void)
{
    switch (mgState)
    {
        case MG_SCRN_STATE_INIT:
        {
            leRenderer_FillArea_Safe(MGScrn_DrawSurfaceWidget0->widget.rect.x,
                                    MGScrn_DrawSurfaceWidget0->widget.rect.y,
                                    MGScrn_DrawSurfaceWidget0->widget.rect.width,
                                    MGScrn_DrawSurfaceWidget0->widget.rect.height,
                                    leScheme_GetRenderColor(MGScrn_DrawSurfaceWidget0->widget.scheme, LE_SCHM_BASE),
                                    255);
            
            nextScreen = 0;
            APP_ClearGesture();
            touchCmd = MG_SCRN_TOUCH_NONE;            
            
            mgState = MG_SCRN_STATE_WAIT_FOR_READY;
            break;
        }
        case MG_SCRN_STATE_WAIT_FOR_READY:
        {
            if(leGetRenderState()->frameState != LE_FRAME_READY || 
               leEvent_GetCount() != 0 ||
               isDisplayReady() != true)
                break;
            
            APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;               

            GFX_DISP_INTF_PIN_BACKLIGHT_Set();            
            mgState = MG_SCRN_STATE_READY;
            
            break;
        }
        case MG_SCRN_STATE_READY:
        {
            if (touchCmd == MG_SCRN_TOUCH_DOWN)
                mgState = MG_SCRN_STATE_IDLE;
            
            CheckNavGesture();
            
            break;
        }
        case MG_SCRN_STATE_IDLE:
        {
            switch(touchCmd)
            {
                case MG_SCRN_TOUCH_DOWN:
                {
                    APP_MGSCRN_PRINTF("**** idle -> down -> start \n\r");
                    MGScrn_DrawInstructionLabel->fn->setX(MGScrn_DrawInstructionLabel,
                            GEST_IMG_HIDE_POS_X);
                    MGScrn_GestureImageWidget->fn->setX(MGScrn_GestureImageWidget,
                            GEST_IMG_HIDE_POS_X);
                    MGScrn_DrawSurfaceWidget0->fn->invalidate(MGScrn_DrawSurfaceWidget0);
                    MGScrn_MG_Gestures->fn->setVisible(MGScrn_MG_Gestures, LE_FALSE);
                    
                    drawCmd = MG_SCRN_DRAW_CLEAR;
                    mgState = MG_SCRN_STATE_ACTIVE;
                    
                    break;
                }
                default:
                {
                    CheckNavGesture();
                    CheckGesture();
                    break;
                }
            }
            
            touchCmd = MG_SCRN_TOUCH_NONE;

            break;
        }
        case MG_SCRN_STATE_ACTIVE:
        {
            switch(touchCmd)
            {
                case MG_SCRN_TOUCH_MOVE:
                {
                    APP_MGSCRN_PRINTF("===== active -> move \n\r");
                    MGScrn_DrawSurfaceWidget0->fn->invalidate(MGScrn_DrawSurfaceWidget0);
                    drawCmd = MG_SCRN_DRAW_POINT;
                    
                    break;
                }
                case MG_SCRN_TOUCH_UP:
                {
                    APP_MGSCRN_PRINTF("===== active -> up -> Done \n\r");
                    mgState = MG_SCRN_STATE_DONE;
                    break;
                }
                default:
                {
                    break;
                }
            }
            
            //Check for hold gestures
            if (APP_GetGesture() >= APP_START_GESTURE_HOLD)
            {
                CheckGesture();
            }
            
            touchCmd = MG_SCRN_TOUCH_NONE;

            break;
        }
        case MG_SCRN_STATE_DONE:
        {
            CheckGesture();
            
            mgState = MG_SCRN_STATE_IDLE;
            break;
        }
        case MG_SCRN_STATE_EXIT:
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
        sprintf(fpsStrBuff, "%u fps", fps);
        fpsStr.fn->setFromCStr(&fpsStr, fpsStrBuff);    
        MGScrn_FPSLabel->fn->setString(MGScrn_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    } 
}