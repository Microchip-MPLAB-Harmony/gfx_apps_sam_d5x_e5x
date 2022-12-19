    #include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"

#include <stdio.h>
#include <string.h>

typedef enum
{
    INTRO_STATE_0,
    INTRO_STATE_1,
    INTRO_STATE_ANIM_IN,
    INTRO_STATE_ANIM_PAUSE,   
    INTRO_STATE_ANIM_OUT,
    INTRO_STATE_DIM,        
    INTRO_STATE_GOTO_SETTINGS,
} INTO_STATES;

static INTO_STATES intro_state;
static int count = 0;

void event_Intro_ButtonWidget0_OnPressed(leButtonWidget* btn)
{
    intro_state = INTRO_STATE_GOTO_SETTINGS;
}
        
void Intro_OnShow(void)
{
    intro_state = INTRO_STATE_0;
    count = 0;
    
    Intro_ImageWidget0->fn->setVisible(Intro_ImageWidget0, LE_FALSE);
    Intro_SplashAnimWidget->fn->setVisible(Intro_SplashAnimWidget, LE_FALSE);
    
    Intro_SplashAnimWidget->fn->setImageCount(Intro_SplashAnimWidget, 23);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 0, &mh36);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 1, &mh37);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 2, &mh38);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 3, &mh39);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 4, &mh310);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 5, &mh311);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 6, &mh312);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 7, &mh313);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 8, &mh314);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 9, &mh315);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 10, &mh316);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 11, &mh317);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 12, &mh318);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 13, &mh319);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 14, &mh320);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 15, &mh321);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 16, &mh322);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 17, &mh323);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 18, &mh324);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 19, &mh325);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 20, &mh326);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 21, &mh327);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 22, &mh328);
    
    Intro_ButtonWidget0->fn->setVisible(Intro_ButtonWidget0, LE_FALSE);
    
    leFixedString_Constructor(&fpsStr, fpsStrCharBuff, FPS_STR_SIZE);
    fpsStr.fn->setFont(&fpsStr, (leFont*)&FPS_Font);
    Intro_FPSLabel->fn->setVisible(Intro_FPSLabel, stats_enabled == true);
    
}
    
void Intro_OnHide(void)
{
    fpsStr.fn->destructor(&fpsStr);
}

void Intro_OnUpdate(void)
{
    switch(intro_state)
    {
        case INTRO_STATE_GOTO_SETTINGS:
        {
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            legato_showScreen(screenID_Settings);

            break;
        }        
        case INTRO_STATE_0:
        {
            if(leRenderer_IsIdle() == LE_FALSE ||
               isDisplayReady() != true)
                break;
                        
            if (APP_IMGFLASH_GetReadyStatus() == true)
            {
                intro_state = INTRO_STATE_1;
                
                APP_SetTargetBacklight(BACKLIGHT_MAX_PCT);
            }
            
            break;
        }
        case INTRO_STATE_1:
        {
            if (APP_GetBacklightBrightness() != BACKLIGHT_MAX_PCT)
                break;

            Intro_ImageWidget0->fn->setVisible(Intro_ImageWidget0, LE_TRUE);
            Intro_SplashAnimWidget->fn->setVisible(Intro_SplashAnimWidget, LE_TRUE);              

            intro_state = INTRO_STATE_ANIM_IN;

            break;
        }
        case INTRO_STATE_ANIM_IN:
        {
            if (count < Intro_SplashAnimWidget->fn->getImageCount(Intro_SplashAnimWidget))
            {
                if (tick_count !=  tick_count_last)
                {                       
                    Intro_SplashAnimWidget->fn->showImage(Intro_SplashAnimWidget, count);
                    count++;

                    tick_count_last = tick_count;
                }
            }
            else if (Intro_SplashAnimWidget->fn->getX(Intro_SplashAnimWidget) > 70)
            {
                Intro_SplashAnimWidget->fn->translate(Intro_SplashAnimWidget, -5, 0);
            }            
            else if (Intro_GraphicsImage->fn->getX(Intro_GraphicsImage) > 250)
            {
                Intro_GraphicsImage->fn->translate(Intro_GraphicsImage, -5, 0);
            }
            else if (Intro_TouchImage->fn->getX(Intro_TouchImage) > 340)
            {
                Intro_TouchImage->fn->translate(Intro_TouchImage, -5, 0);                
            }
            else
            {
                Intro_ButtonWidget0->fn->setVisible(Intro_ButtonWidget0, LE_TRUE);                
                intro_state = INTRO_STATE_ANIM_PAUSE;
            }
            
            break;
        }
        case INTRO_STATE_ANIM_PAUSE:
        {
            if (tick_count >= tick_count_last)
            {
                if (tick_count - tick_count_last > NUM_COUNT_SEC_TICK * 2)
                {
                    intro_state = INTRO_STATE_ANIM_OUT;
                }
            }
            else
            {
                tick_count_last = tick_count;
            }

            break;
        }
        case INTRO_STATE_ANIM_OUT:
        {
            if (Intro_TouchImage->fn->getX(Intro_TouchImage) < 480)
            {
                Intro_TouchImage->fn->translate(Intro_TouchImage, 5, 0);                
            }
            else if (Intro_GraphicsImage->fn->getX(Intro_GraphicsImage) < 480)
            {
                Intro_GraphicsImage->fn->translate(Intro_GraphicsImage, 5, 0);
            }
            else if (Intro_SplashAnimWidget->fn->getX(Intro_SplashAnimWidget) < 155)
            {
                Intro_SplashAnimWidget->fn->translate(Intro_SplashAnimWidget, 5, 0);
            }            
            else if (count > 0)
            {
                if (tick_count !=  tick_count_last)
                {
                    count--;
                    Intro_SplashAnimWidget->fn->showImage(Intro_SplashAnimWidget, count);
                    
                    tick_count_last = tick_count;
                }
            }
            else
            {
                intro_state = INTRO_STATE_DIM;
                APP_SetTargetBacklight(BACKLIGHT_MIN_PCT);
            }

            break;            
        }
        case INTRO_STATE_DIM:
        {
            if (APP_GetBacklightBrightness() != BACKLIGHT_MIN_PCT)
                break;
            
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            legato_showScreen(screenID_Menu);
            
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
        Intro_FPSLabel->fn->setString(Intro_FPSLabel, (leString*)&fpsStr);          
        
        last_sec_count = sec_count;
    }    
}
