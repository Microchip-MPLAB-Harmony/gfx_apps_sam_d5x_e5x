#include "gfx/legato/generated/screen/le_gen_screen_screen1.h"

// screen member widget declarations
leWidget* root0;

leWidget* screen1_PanelWidget0;
leImageWidget* screen1_LogoWidget;
leLabelWidget* screen1_TitleLabel;
leButtonWidget* screen1_SloganButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_screen1()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_screen1()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    screen1_PanelWidget0 = leWidget_New();
    screen1_PanelWidget0->fn->setPosition(screen1_PanelWidget0, 0, 0);
    screen1_PanelWidget0->fn->setSize(screen1_PanelWidget0, 480, 272);
    screen1_PanelWidget0->fn->setScheme(screen1_PanelWidget0, &DefaultScheme);
    root0->fn->addChild(root0, (leWidget*)screen1_PanelWidget0);

    screen1_LogoWidget = leImageWidget_New();
    screen1_LogoWidget->fn->setPosition(screen1_LogoWidget, 161, 51);
    screen1_LogoWidget->fn->setSize(screen1_LogoWidget, 150, 150);
    screen1_LogoWidget->fn->setBackgroundType(screen1_LogoWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_LogoWidget->fn->setBorderType(screen1_LogoWidget, LE_WIDGET_BORDER_NONE);
    screen1_LogoWidget->fn->setImage(screen1_LogoWidget, (leImage*)&MHGC_150x150);
    root0->fn->addChild(root0, (leWidget*)screen1_LogoWidget);

    screen1_TitleLabel = leLabelWidget_New();
    screen1_TitleLabel->fn->setPosition(screen1_TitleLabel, 71, 18);
    screen1_TitleLabel->fn->setSize(screen1_TitleLabel, 343, 25);
    screen1_TitleLabel->fn->setBackgroundType(screen1_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    screen1_TitleLabel->fn->setHAlignment(screen1_TitleLabel, LE_HALIGN_CENTER);
    screen1_TitleLabel->fn->setString(screen1_TitleLabel, (leString*)&string_TitleString);
    root0->fn->addChild(root0, (leWidget*)screen1_TitleLabel);

    screen1_SloganButton = leButtonWidget_New();
    screen1_SloganButton->fn->setPosition(screen1_SloganButton, 119, 211);
    screen1_SloganButton->fn->setSize(screen1_SloganButton, 238, 37);
    screen1_SloganButton->fn->setString(screen1_SloganButton, (leString*)&string_Slogan);
    root0->fn->addChild(root0, (leWidget*)screen1_SloganButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_screen1()
{
}

void screenHide_screen1()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    screen1_PanelWidget0 = NULL;
    screen1_LogoWidget = NULL;
    screen1_TitleLabel = NULL;
    screen1_SloganButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_screen1()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_screen1(uint32_t lyrIdx)
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

