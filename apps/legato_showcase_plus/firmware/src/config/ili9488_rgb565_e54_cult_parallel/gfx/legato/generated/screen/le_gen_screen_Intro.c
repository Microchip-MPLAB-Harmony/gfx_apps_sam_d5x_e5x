#include "gfx/legato/generated/screen/le_gen_screen_Intro.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Intro_PanelWidget6;
leImageSequenceWidget* Intro_SplashAnimWidget;
leImageWidget* Intro_ImageWidget0;
leImageWidget* Intro_GraphicsImage;
leImageWidget* Intro_TouchImage;
leLabelWidget* Intro_FPSLabel;
leButtonWidget* Intro_ButtonWidget0;
leLabelWidget* Intro_LabelWidget0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Intro(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Intro(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Intro_PanelWidget6 = leWidget_New();
    Intro_PanelWidget6->fn->setPosition(Intro_PanelWidget6, 0, 0);
    Intro_PanelWidget6->fn->setSize(Intro_PanelWidget6, 480, 320);
    Intro_PanelWidget6->fn->setScheme(Intro_PanelWidget6, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Intro_PanelWidget6);

    Intro_SplashAnimWidget = leImageSequenceWidget_New();
    Intro_SplashAnimWidget->fn->setPosition(Intro_SplashAnimWidget, 155, 112);
    Intro_SplashAnimWidget->fn->setSize(Intro_SplashAnimWidget, 180, 112);
    Intro_SplashAnimWidget->fn->setBackgroundType(Intro_SplashAnimWidget, LE_WIDGET_BACKGROUND_NONE);
    Intro_SplashAnimWidget->fn->setImageCount(Intro_SplashAnimWidget, 1);
    Intro_SplashAnimWidget->fn->setImage(Intro_SplashAnimWidget, 0, &mh328);
    Intro_SplashAnimWidget->fn->setImageDelay(Intro_SplashAnimWidget, 0, 1000);
    root0->fn->addChild(root0, (leWidget*)Intro_SplashAnimWidget);

    Intro_ImageWidget0 = leImageWidget_New();
    Intro_ImageWidget0->fn->setPosition(Intro_ImageWidget0, 4, 5);
    Intro_ImageWidget0->fn->setSize(Intro_ImageWidget0, 165, 30);
    Intro_ImageWidget0->fn->setScheme(Intro_ImageWidget0, &WhiteBackgroundScheme);
    Intro_ImageWidget0->fn->setBorderType(Intro_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Intro_ImageWidget0->fn->setImage(Intro_ImageWidget0, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)Intro_ImageWidget0);

    Intro_GraphicsImage = leImageWidget_New();
    Intro_GraphicsImage->fn->setPosition(Intro_GraphicsImage, 480, 120);
    Intro_GraphicsImage->fn->setSize(Intro_GraphicsImage, 80, 100);
    Intro_GraphicsImage->fn->setBackgroundType(Intro_GraphicsImage, LE_WIDGET_BACKGROUND_NONE);
    Intro_GraphicsImage->fn->setBorderType(Intro_GraphicsImage, LE_WIDGET_BORDER_NONE);
    Intro_GraphicsImage->fn->setImage(Intro_GraphicsImage, (leImage*)&graphics_icon);
    root0->fn->addChild(root0, (leWidget*)Intro_GraphicsImage);

    Intro_TouchImage = leImageWidget_New();
    Intro_TouchImage->fn->setPosition(Intro_TouchImage, 480, 117);
    Intro_TouchImage->fn->setSize(Intro_TouchImage, 80, 101);
    Intro_TouchImage->fn->setBackgroundType(Intro_TouchImage, LE_WIDGET_BACKGROUND_NONE);
    Intro_TouchImage->fn->setBorderType(Intro_TouchImage, LE_WIDGET_BORDER_NONE);
    Intro_TouchImage->fn->setImage(Intro_TouchImage, (leImage*)&touch_icon);
    root0->fn->addChild(root0, (leWidget*)Intro_TouchImage);

    Intro_FPSLabel = leLabelWidget_New();
    Intro_FPSLabel->fn->setPosition(Intro_FPSLabel, 405, 1);
    Intro_FPSLabel->fn->setSize(Intro_FPSLabel, 75, 25);
    Intro_FPSLabel->fn->setScheme(Intro_FPSLabel, &BlackTextScheme);
    Intro_FPSLabel->fn->setBackgroundType(Intro_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Intro_FPSLabel);

    Intro_ButtonWidget0 = leButtonWidget_New();
    Intro_ButtonWidget0->fn->setPosition(Intro_ButtonWidget0, 0, 35);
    Intro_ButtonWidget0->fn->setSize(Intro_ButtonWidget0, 480, 285);
    Intro_ButtonWidget0->fn->setBackgroundType(Intro_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    Intro_ButtonWidget0->fn->setBorderType(Intro_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    Intro_ButtonWidget0->fn->setPressedEventCallback(Intro_ButtonWidget0, event_Intro_ButtonWidget0_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Intro_ButtonWidget0);

    Intro_LabelWidget0 = leLabelWidget_New();
    Intro_LabelWidget0->fn->setPosition(Intro_LabelWidget0, 173, 253);
    Intro_LabelWidget0->fn->setSize(Intro_LabelWidget0, 139, 25);
    Intro_LabelWidget0->fn->setBackgroundType(Intro_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Intro_LabelWidget0->fn->setHAlignment(Intro_LabelWidget0, LE_HALIGN_CENTER);
    Intro_LabelWidget0->fn->setString(Intro_LabelWidget0, (leString*)&string_TapToGotoSettings);
    Intro_ButtonWidget0->fn->addChild(Intro_ButtonWidget0, (leWidget*)Intro_LabelWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Intro_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Intro(void)
{
    Intro_OnUpdate(); // raise event
}

void screenHide_Intro(void)
{
    Intro_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Intro_PanelWidget6 = NULL;
    Intro_SplashAnimWidget = NULL;
    Intro_ImageWidget0 = NULL;
    Intro_GraphicsImage = NULL;
    Intro_TouchImage = NULL;
    Intro_FPSLabel = NULL;
    Intro_ButtonWidget0 = NULL;
    Intro_LabelWidget0 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Intro(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Intro(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

