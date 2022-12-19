#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Menu_PanelWidget0;
leLabelWidget* Menu_LabelWidget0;
leLineWidget* Menu_LineWidget0;
leLineWidget* Menu_LineWidget1;
leWidget* Menu_PanelWidget1;
leImageWidget* Menu_ImageWidget0;
leImageWidget* Menu_ImageWidget1;
leLabelWidget* Menu_FPSLabel;
leLabelWidget* Menu_LabelWidget1;
leButtonWidget* Menu_MenuButton0;
leButtonWidget* Menu_MenuButton1;
leButtonWidget* Menu_MenuButton2;
leButtonWidget* Menu_MenuButton3;
leButtonWidget* Menu_MenuButton4;
leButtonWidget* Menu_MenuButton5;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Menu(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Menu(void)
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

    Menu_PanelWidget0 = leWidget_New();
    Menu_PanelWidget0->fn->setPosition(Menu_PanelWidget0, 0, 0);
    Menu_PanelWidget0->fn->setSize(Menu_PanelWidget0, 480, 320);
    Menu_PanelWidget0->fn->setScheme(Menu_PanelWidget0, &MainMenuScheme);
    root0->fn->addChild(root0, (leWidget*)Menu_PanelWidget0);

    Menu_LabelWidget0 = leLabelWidget_New();
    Menu_LabelWidget0->fn->setPosition(Menu_LabelWidget0, 36, 64);
    Menu_LabelWidget0->fn->setSize(Menu_LabelWidget0, 412, 46);
    Menu_LabelWidget0->fn->setScheme(Menu_LabelWidget0, &MainMenuScheme);
    Menu_LabelWidget0->fn->setHAlignment(Menu_LabelWidget0, LE_HALIGN_CENTER);
    Menu_LabelWidget0->fn->setString(Menu_LabelWidget0, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)Menu_LabelWidget0);

    Menu_LineWidget0 = leLineWidget_New();
    Menu_LineWidget0->fn->setPosition(Menu_LineWidget0, 20, 119);
    Menu_LineWidget0->fn->setSize(Menu_LineWidget0, 440, 3);
    Menu_LineWidget0->fn->setScheme(Menu_LineWidget0, &MainMenuScheme);
    Menu_LineWidget0->fn->setBackgroundType(Menu_LineWidget0, LE_WIDGET_BACKGROUND_NONE);
    Menu_LineWidget0->fn->setStartPoint(Menu_LineWidget0, 0, 1);
    Menu_LineWidget0->fn->setEndPoint(Menu_LineWidget0, 440, 1);
    root0->fn->addChild(root0, (leWidget*)Menu_LineWidget0);

    Menu_LineWidget1 = leLineWidget_New();
    Menu_LineWidget1->fn->setPosition(Menu_LineWidget1, 20, 259);
    Menu_LineWidget1->fn->setSize(Menu_LineWidget1, 440, 3);
    Menu_LineWidget1->fn->setScheme(Menu_LineWidget1, &MainMenuScheme);
    Menu_LineWidget1->fn->setBackgroundType(Menu_LineWidget1, LE_WIDGET_BACKGROUND_NONE);
    Menu_LineWidget1->fn->setStartPoint(Menu_LineWidget1, 0, 1);
    Menu_LineWidget1->fn->setEndPoint(Menu_LineWidget1, 440, 1);
    root0->fn->addChild(root0, (leWidget*)Menu_LineWidget1);

    Menu_PanelWidget1 = leWidget_New();
    Menu_PanelWidget1->fn->setPosition(Menu_PanelWidget1, -120, 115);
    Menu_PanelWidget1->fn->setSize(Menu_PanelWidget1, 720, 150);
    Menu_PanelWidget1->fn->setBackgroundType(Menu_PanelWidget1, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Menu_PanelWidget1);

    Menu_MenuButton0 = leButtonWidget_New();
    Menu_MenuButton0->fn->setPosition(Menu_MenuButton0, 0, 0);
    Menu_MenuButton0->fn->setSize(Menu_MenuButton0, 120, 150);
    Menu_MenuButton0->fn->setBackgroundType(Menu_MenuButton0, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton0->fn->setBorderType(Menu_MenuButton0, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton0->fn->setPressedImage(Menu_MenuButton0, (leImage*)&MenuPlayer565);
    Menu_MenuButton0->fn->setReleasedImage(Menu_MenuButton0, (leImage*)&MenuPlayer565);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton0);

    Menu_MenuButton1 = leButtonWidget_New();
    Menu_MenuButton1->fn->setPosition(Menu_MenuButton1, 120, 0);
    Menu_MenuButton1->fn->setSize(Menu_MenuButton1, 120, 150);
    Menu_MenuButton1->fn->setBackgroundType(Menu_MenuButton1, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton1->fn->setBorderType(Menu_MenuButton1, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton1->fn->setPressedImage(Menu_MenuButton1, (leImage*)&MenuCooker565);
    Menu_MenuButton1->fn->setReleasedImage(Menu_MenuButton1, (leImage*)&MenuCooker565);
    Menu_MenuButton1->fn->setPressedOffset(Menu_MenuButton1, 0);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton1);

    Menu_MenuButton2 = leButtonWidget_New();
    Menu_MenuButton2->fn->setPosition(Menu_MenuButton2, 240, 0);
    Menu_MenuButton2->fn->setSize(Menu_MenuButton2, 120, 150);
    Menu_MenuButton2->fn->setBackgroundType(Menu_MenuButton2, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton2->fn->setBorderType(Menu_MenuButton2, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton2->fn->setPressedImage(Menu_MenuButton2, (leImage*)&MenuCar565);
    Menu_MenuButton2->fn->setReleasedImage(Menu_MenuButton2, (leImage*)&MenuCar565);
    Menu_MenuButton2->fn->setPressedOffset(Menu_MenuButton2, 0);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton2);

    Menu_MenuButton3 = leButtonWidget_New();
    Menu_MenuButton3->fn->setPosition(Menu_MenuButton3, 360, 0);
    Menu_MenuButton3->fn->setSize(Menu_MenuButton3, 120, 150);
    Menu_MenuButton3->fn->setBackgroundType(Menu_MenuButton3, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton3->fn->setBorderType(Menu_MenuButton3, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton3->fn->setPressedImage(Menu_MenuButton3, (leImage*)&MenuGesture565);
    Menu_MenuButton3->fn->setReleasedImage(Menu_MenuButton3, (leImage*)&MenuGesture565);
    Menu_MenuButton3->fn->setPressedOffset(Menu_MenuButton3, 0);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton3);

    Menu_MenuButton4 = leButtonWidget_New();
    Menu_MenuButton4->fn->setPosition(Menu_MenuButton4, 480, 0);
    Menu_MenuButton4->fn->setSize(Menu_MenuButton4, 120, 150);
    Menu_MenuButton4->fn->setBackgroundType(Menu_MenuButton4, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton4->fn->setBorderType(Menu_MenuButton4, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton4->fn->setPressedImage(Menu_MenuButton4, (leImage*)&MenuCooker2565);
    Menu_MenuButton4->fn->setReleasedImage(Menu_MenuButton4, (leImage*)&MenuCooker2565);
    Menu_MenuButton4->fn->setPressedOffset(Menu_MenuButton4, 0);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton4);

    Menu_MenuButton5 = leButtonWidget_New();
    Menu_MenuButton5->fn->setPosition(Menu_MenuButton5, 600, 0);
    Menu_MenuButton5->fn->setSize(Menu_MenuButton5, 120, 150);
    Menu_MenuButton5->fn->setBackgroundType(Menu_MenuButton5, LE_WIDGET_BACKGROUND_NONE);
    Menu_MenuButton5->fn->setBorderType(Menu_MenuButton5, LE_WIDGET_BORDER_NONE);
    Menu_MenuButton5->fn->setPressedImage(Menu_MenuButton5, (leImage*)&info565);
    Menu_MenuButton5->fn->setReleasedImage(Menu_MenuButton5, (leImage*)&info565);
    Menu_MenuButton5->fn->setPressedOffset(Menu_MenuButton5, 0);
    Menu_PanelWidget1->fn->addChild(Menu_PanelWidget1, (leWidget*)Menu_MenuButton5);

    Menu_ImageWidget0 = leImageWidget_New();
    Menu_ImageWidget0->fn->setPosition(Menu_ImageWidget0, 318, 13);
    Menu_ImageWidget0->fn->setSize(Menu_ImageWidget0, 154, 33);
    Menu_ImageWidget0->fn->setBackgroundType(Menu_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Menu_ImageWidget0->fn->setBorderType(Menu_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Menu_ImageWidget0->fn->setImage(Menu_ImageWidget0, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)Menu_ImageWidget0);

    Menu_ImageWidget1 = leImageWidget_New();
    Menu_ImageWidget1->fn->setPosition(Menu_ImageWidget1, 5, 6);
    Menu_ImageWidget1->fn->setSize(Menu_ImageWidget1, 52, 44);
    Menu_ImageWidget1->fn->setBackgroundType(Menu_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Menu_ImageWidget1->fn->setBorderType(Menu_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Menu_ImageWidget1->fn->setImage(Menu_ImageWidget1, (leImage*)&mhgs565);
    root0->fn->addChild(root0, (leWidget*)Menu_ImageWidget1);

    Menu_FPSLabel = leLabelWidget_New();
    Menu_FPSLabel->fn->setPosition(Menu_FPSLabel, 355, 290);
    Menu_FPSLabel->fn->setSize(Menu_FPSLabel, 120, 25);
    Menu_FPSLabel->fn->setScheme(Menu_FPSLabel, &WhiteTextScheme);
    Menu_FPSLabel->fn->setBackgroundType(Menu_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    Menu_FPSLabel->fn->setHAlignment(Menu_FPSLabel, LE_HALIGN_CENTER);
    Menu_FPSLabel->fn->setString(Menu_FPSLabel, (leString*)&string_MetricsInfo);
    root0->fn->addChild(root0, (leWidget*)Menu_FPSLabel);

    Menu_LabelWidget1 = leLabelWidget_New();
    Menu_LabelWidget1->fn->setPosition(Menu_LabelWidget1, 139, 270);
    Menu_LabelWidget1->fn->setSize(Menu_LabelWidget1, 221, 34);
    Menu_LabelWidget1->fn->setVisible(Menu_LabelWidget1, LE_FALSE);
    Menu_LabelWidget1->fn->setScheme(Menu_LabelWidget1, &PlayerBarScheme);
    Menu_LabelWidget1->fn->setBackgroundType(Menu_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    Menu_LabelWidget1->fn->setHAlignment(Menu_LabelWidget1, LE_HALIGN_CENTER);
    Menu_LabelWidget1->fn->setString(Menu_LabelWidget1, (leString*)&string_DemoVersion);
    root0->fn->addChild(root0, (leWidget*)Menu_LabelWidget1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Menu_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Menu(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Menu_OnUpdate(); // raise event
}

void screenHide_Menu(void)
{
    Menu_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Menu_PanelWidget0 = NULL;
    Menu_LabelWidget0 = NULL;
    Menu_LineWidget0 = NULL;
    Menu_LineWidget1 = NULL;
    Menu_PanelWidget1 = NULL;
    Menu_ImageWidget0 = NULL;
    Menu_ImageWidget1 = NULL;
    Menu_FPSLabel = NULL;
    Menu_LabelWidget1 = NULL;
    Menu_MenuButton0 = NULL;
    Menu_MenuButton1 = NULL;
    Menu_MenuButton2 = NULL;
    Menu_MenuButton3 = NULL;
    Menu_MenuButton4 = NULL;
    Menu_MenuButton5 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Menu(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Menu(uint32_t lyrIdx)
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

