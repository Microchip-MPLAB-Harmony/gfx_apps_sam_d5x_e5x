#include "gfx/legato/generated/screen/le_gen_screen_CCtrlScrn1.h"

// screen member widget declarations
static leWidget* root0;

leWidget* CCtrlScrn1_PanelWidget0;
leImageWidget* CCtrlScrn1_ImageWidget2;
leImageWidget* CCtrlScrn1_ImageWidget1;
leListWheelWidget* CCtrlScrn1_ListWheelWidget0;
leListWheelWidget* CCtrlScrn1_ListWheelWidget1;
leButtonWidget* CCtrlScrn1_ButtonWidget0;
leButtonWidget* CCtrlScrn1_ButtonWidget1;
leButtonWidget* CCtrlScrn1_ButtonWidget2;
leButtonWidget* CCtrlScrn1_ButtonWidget3;
leButtonWidget* CCtrlScrn1_ButtonWidget4;
leListWheelWidget* CCtrlScrn1_ListWheelWidget2;
leButtonWidget* CCtrlScrn1_HomeButton;
leImageSequenceWidget* CCtrlScrn1_RightFanImageSequence;
leImageSequenceWidget* CCtrlScrn1_LeftFanImageSequence;
leButtonWidget* CCtrlScrn1_RightFanDownButton;
leButtonWidget* CCtrlScrn1_RightFanUpButton;
leButtonWidget* CCtrlScrn1_LeftFanDownButton;
leButtonWidget* CCtrlScrn1_LeftFanUpButton;
leLineWidget* CCtrlScrn1_LineWidget0;
leLineWidget* CCtrlScrn1_LineWidget1;
leLabelWidget* CCtrlScrn1_FPSLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_CCtrlScrn1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_CCtrlScrn1(void)
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

    CCtrlScrn1_PanelWidget0 = leWidget_New();
    CCtrlScrn1_PanelWidget0->fn->setPosition(CCtrlScrn1_PanelWidget0, 0, 0);
    CCtrlScrn1_PanelWidget0->fn->setSize(CCtrlScrn1_PanelWidget0, 480, 320);
    CCtrlScrn1_PanelWidget0->fn->setScheme(CCtrlScrn1_PanelWidget0, &BlackBackground);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_PanelWidget0);

    CCtrlScrn1_ImageWidget2 = leImageWidget_New();
    CCtrlScrn1_ImageWidget2->fn->setPosition(CCtrlScrn1_ImageWidget2, 74, 0);
    CCtrlScrn1_ImageWidget2->fn->setSize(CCtrlScrn1_ImageWidget2, 326, 60);
    CCtrlScrn1_ImageWidget2->fn->setBackgroundType(CCtrlScrn1_ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ImageWidget2->fn->setBorderType(CCtrlScrn1_ImageWidget2, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ImageWidget2->fn->setImage(CCtrlScrn1_ImageWidget2, (leImage*)&Cctrl_Background);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ImageWidget2);

    CCtrlScrn1_ImageWidget1 = leImageWidget_New();
    CCtrlScrn1_ImageWidget1->fn->setPosition(CCtrlScrn1_ImageWidget1, 0, 1);
    CCtrlScrn1_ImageWidget1->fn->setSize(CCtrlScrn1_ImageWidget1, 134, 40);
    CCtrlScrn1_ImageWidget1->fn->setBackgroundType(CCtrlScrn1_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ImageWidget1->fn->setBorderType(CCtrlScrn1_ImageWidget1, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ImageWidget1->fn->setImage(CCtrlScrn1_ImageWidget1, (leImage*)&mchp_black);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ImageWidget1);

    CCtrlScrn1_ListWheelWidget0 = leListWheelWidget_New();
    CCtrlScrn1_ListWheelWidget0->fn->setPosition(CCtrlScrn1_ListWheelWidget0, 94, 50);
    CCtrlScrn1_ListWheelWidget0->fn->setSize(CCtrlScrn1_ListWheelWidget0, 90, 180);
    CCtrlScrn1_ListWheelWidget0->fn->setBackgroundType(CCtrlScrn1_ListWheelWidget0, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ListWheelWidget0->fn->setBorderType(CCtrlScrn1_ListWheelWidget0, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ListWheelWidget0->fn->setVisibleItemCount(CCtrlScrn1_ListWheelWidget0, 3);
    CCtrlScrn1_ListWheelWidget0->fn->setShowIndicators(CCtrlScrn1_ListWheelWidget0, LE_FALSE);
    CCtrlScrn1_ListWheelWidget0->fn->setIndicatorFill(CCtrlScrn1_ListWheelWidget0, LE_LISTWHEEL_INDICATOR_FILL_NONE);
    CCtrlScrn1_ListWheelWidget0->fn->setShaded(CCtrlScrn1_ListWheelWidget0, LE_FALSE);
    CCtrlScrn1_ListWheelWidget0->fn->setAutoHideWheel(CCtrlScrn1_ListWheelWidget0, LE_TRUE);
    CCtrlScrn1_ListWheelWidget0->fn->appendItem(CCtrlScrn1_ListWheelWidget0);
    CCtrlScrn1_ListWheelWidget0->fn->setItemIcon(CCtrlScrn1_ListWheelWidget0, 0, &Cctrl_Vent1);
    CCtrlScrn1_ListWheelWidget0->fn->appendItem(CCtrlScrn1_ListWheelWidget0);
    CCtrlScrn1_ListWheelWidget0->fn->setItemIcon(CCtrlScrn1_ListWheelWidget0, 1, &Cctrl_Vent2);
    CCtrlScrn1_ListWheelWidget0->fn->appendItem(CCtrlScrn1_ListWheelWidget0);
    CCtrlScrn1_ListWheelWidget0->fn->setItemIcon(CCtrlScrn1_ListWheelWidget0, 2, &Cctrl_Vent3);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ListWheelWidget0);

    CCtrlScrn1_ListWheelWidget1 = leListWheelWidget_New();
    CCtrlScrn1_ListWheelWidget1->fn->setPosition(CCtrlScrn1_ListWheelWidget1, 307, 50);
    CCtrlScrn1_ListWheelWidget1->fn->setSize(CCtrlScrn1_ListWheelWidget1, 90, 180);
    CCtrlScrn1_ListWheelWidget1->fn->setBackgroundType(CCtrlScrn1_ListWheelWidget1, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ListWheelWidget1->fn->setBorderType(CCtrlScrn1_ListWheelWidget1, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ListWheelWidget1->fn->setVisibleItemCount(CCtrlScrn1_ListWheelWidget1, 3);
    CCtrlScrn1_ListWheelWidget1->fn->setShowIndicators(CCtrlScrn1_ListWheelWidget1, LE_FALSE);
    CCtrlScrn1_ListWheelWidget1->fn->setIndicatorFill(CCtrlScrn1_ListWheelWidget1, LE_LISTWHEEL_INDICATOR_FILL_NONE);
    CCtrlScrn1_ListWheelWidget1->fn->setShaded(CCtrlScrn1_ListWheelWidget1, LE_FALSE);
    CCtrlScrn1_ListWheelWidget1->fn->setAutoHideWheel(CCtrlScrn1_ListWheelWidget1, LE_TRUE);
    CCtrlScrn1_ListWheelWidget1->fn->appendItem(CCtrlScrn1_ListWheelWidget1);
    CCtrlScrn1_ListWheelWidget1->fn->setItemIcon(CCtrlScrn1_ListWheelWidget1, 0, &Cctrl_Vent1_R);
    CCtrlScrn1_ListWheelWidget1->fn->appendItem(CCtrlScrn1_ListWheelWidget1);
    CCtrlScrn1_ListWheelWidget1->fn->setItemIcon(CCtrlScrn1_ListWheelWidget1, 1, &Cctrl_Vent2_R);
    CCtrlScrn1_ListWheelWidget1->fn->appendItem(CCtrlScrn1_ListWheelWidget1);
    CCtrlScrn1_ListWheelWidget1->fn->setItemIcon(CCtrlScrn1_ListWheelWidget1, 2, &Cctrl_Vent3_R);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ListWheelWidget1);

    CCtrlScrn1_ButtonWidget0 = leButtonWidget_New();
    CCtrlScrn1_ButtonWidget0->fn->setPosition(CCtrlScrn1_ButtonWidget0, 199, 39);
    CCtrlScrn1_ButtonWidget0->fn->setSize(CCtrlScrn1_ButtonWidget0, 100, 40);
    CCtrlScrn1_ButtonWidget0->fn->setBackgroundType(CCtrlScrn1_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ButtonWidget0->fn->setBorderType(CCtrlScrn1_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ButtonWidget0);

    CCtrlScrn1_ButtonWidget1 = leButtonWidget_New();
    CCtrlScrn1_ButtonWidget1->fn->setPosition(CCtrlScrn1_ButtonWidget1, 200, 204);
    CCtrlScrn1_ButtonWidget1->fn->setSize(CCtrlScrn1_ButtonWidget1, 100, 48);
    CCtrlScrn1_ButtonWidget1->fn->setBackgroundType(CCtrlScrn1_ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ButtonWidget1->fn->setBorderType(CCtrlScrn1_ButtonWidget1, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ButtonWidget1);

    CCtrlScrn1_ButtonWidget2 = leButtonWidget_New();
    CCtrlScrn1_ButtonWidget2->fn->setPosition(CCtrlScrn1_ButtonWidget2, 92, 230);
    CCtrlScrn1_ButtonWidget2->fn->setSize(CCtrlScrn1_ButtonWidget2, 100, 80);
    CCtrlScrn1_ButtonWidget2->fn->setBackgroundType(CCtrlScrn1_ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ButtonWidget2->fn->setBorderType(CCtrlScrn1_ButtonWidget2, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ButtonWidget2->fn->setToggleable(CCtrlScrn1_ButtonWidget2, LE_TRUE);
    CCtrlScrn1_ButtonWidget2->fn->setPressedImage(CCtrlScrn1_ButtonWidget2, (leImage*)&Cctrl_VentOpen);
    CCtrlScrn1_ButtonWidget2->fn->setReleasedImage(CCtrlScrn1_ButtonWidget2, (leImage*)&Cctrl_VentClose);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ButtonWidget2);

    CCtrlScrn1_ButtonWidget3 = leButtonWidget_New();
    CCtrlScrn1_ButtonWidget3->fn->setPosition(CCtrlScrn1_ButtonWidget3, 196, 250);
    CCtrlScrn1_ButtonWidget3->fn->setSize(CCtrlScrn1_ButtonWidget3, 100, 70);
    CCtrlScrn1_ButtonWidget3->fn->setBackgroundType(CCtrlScrn1_ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ButtonWidget3->fn->setBorderType(CCtrlScrn1_ButtonWidget3, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ButtonWidget3->fn->setToggleable(CCtrlScrn1_ButtonWidget3, LE_TRUE);
    CCtrlScrn1_ButtonWidget3->fn->setPressedImage(CCtrlScrn1_ButtonWidget3, (leImage*)&Cctrl_ClimateControlOn);
    CCtrlScrn1_ButtonWidget3->fn->setReleasedImage(CCtrlScrn1_ButtonWidget3, (leImage*)&Cctrl_ClimateControlOff);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ButtonWidget3);

    CCtrlScrn1_ButtonWidget4 = leButtonWidget_New();
    CCtrlScrn1_ButtonWidget4->fn->setPosition(CCtrlScrn1_ButtonWidget4, 295, 230);
    CCtrlScrn1_ButtonWidget4->fn->setSize(CCtrlScrn1_ButtonWidget4, 100, 78);
    CCtrlScrn1_ButtonWidget4->fn->setBackgroundType(CCtrlScrn1_ButtonWidget4, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ButtonWidget4->fn->setBorderType(CCtrlScrn1_ButtonWidget4, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ButtonWidget4->fn->setToggleable(CCtrlScrn1_ButtonWidget4, LE_TRUE);
    CCtrlScrn1_ButtonWidget4->fn->setPressedImage(CCtrlScrn1_ButtonWidget4, (leImage*)&Cctrl_HeatedSeatsOn);
    CCtrlScrn1_ButtonWidget4->fn->setReleasedImage(CCtrlScrn1_ButtonWidget4, (leImage*)&Cctrl_HeatedSeatsOff);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ButtonWidget4);

    CCtrlScrn1_ListWheelWidget2 = leListWheelWidget_New();
    CCtrlScrn1_ListWheelWidget2->fn->setPosition(CCtrlScrn1_ListWheelWidget2, 187, 59);
    CCtrlScrn1_ListWheelWidget2->fn->setSize(CCtrlScrn1_ListWheelWidget2, 119, 191);
    CCtrlScrn1_ListWheelWidget2->fn->setScheme(CCtrlScrn1_ListWheelWidget2, &CCtrlScheme);
    CCtrlScrn1_ListWheelWidget2->fn->setBackgroundType(CCtrlScrn1_ListWheelWidget2, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_ListWheelWidget2->fn->setBorderType(CCtrlScrn1_ListWheelWidget2, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_ListWheelWidget2->fn->setVisibleItemCount(CCtrlScrn1_ListWheelWidget2, 3);
    CCtrlScrn1_ListWheelWidget2->fn->setShowIndicators(CCtrlScrn1_ListWheelWidget2, LE_FALSE);
    CCtrlScrn1_ListWheelWidget2->fn->setIndicatorFill(CCtrlScrn1_ListWheelWidget2, LE_LISTWHEEL_INDICATOR_FILL_NONE);
    CCtrlScrn1_ListWheelWidget2->fn->setShaded(CCtrlScrn1_ListWheelWidget2, LE_FALSE);
    CCtrlScrn1_ListWheelWidget2->fn->setAutoHideWheel(CCtrlScrn1_ListWheelWidget2, LE_TRUE);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 0, (leString*)&string_Temp79);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 1, (leString*)&string_Temp78);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 2, (leString*)&string_Temp77);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 3, (leString*)&string_Temp76);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 4, (leString*)&string_Temp75);
    CCtrlScrn1_ListWheelWidget2->fn->appendItem(CCtrlScrn1_ListWheelWidget2);
    CCtrlScrn1_ListWheelWidget2->fn->setItemString(CCtrlScrn1_ListWheelWidget2, 5, (leString*)&string_Temp74);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_ListWheelWidget2);

    CCtrlScrn1_HomeButton = leButtonWidget_New();
    CCtrlScrn1_HomeButton->fn->setPosition(CCtrlScrn1_HomeButton, 400, 0);
    CCtrlScrn1_HomeButton->fn->setSize(CCtrlScrn1_HomeButton, 80, 50);
    CCtrlScrn1_HomeButton->fn->setScheme(CCtrlScrn1_HomeButton, &PlayerVolScheme);
    CCtrlScrn1_HomeButton->fn->setBorderType(CCtrlScrn1_HomeButton, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_HomeButton->fn->setPressedImage(CCtrlScrn1_HomeButton, (leImage*)&Home565Gray);
    CCtrlScrn1_HomeButton->fn->setReleasedImage(CCtrlScrn1_HomeButton, (leImage*)&Home565Gray);
    CCtrlScrn1_HomeButton->fn->setPressedOffset(CCtrlScrn1_HomeButton, 0);
    CCtrlScrn1_HomeButton->fn->setPressedEventCallback(CCtrlScrn1_HomeButton, event_CCtrlScrn1_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_HomeButton);

    CCtrlScrn1_RightFanImageSequence = leImageSequenceWidget_New();
    CCtrlScrn1_RightFanImageSequence->fn->setPosition(CCtrlScrn1_RightFanImageSequence, 426, 60);
    CCtrlScrn1_RightFanImageSequence->fn->setSize(CCtrlScrn1_RightFanImageSequence, 40, 233);
    CCtrlScrn1_RightFanImageSequence->fn->setBackgroundType(CCtrlScrn1_RightFanImageSequence, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_RightFanImageSequence->fn->setImageCount(CCtrlScrn1_RightFanImageSequence, 5);
    CCtrlScrn1_RightFanImageSequence->fn->setImage(CCtrlScrn1_RightFanImageSequence, 0, &CctrlFan1);
    CCtrlScrn1_RightFanImageSequence->fn->setImageDelay(CCtrlScrn1_RightFanImageSequence, 0, 1000);
    CCtrlScrn1_RightFanImageSequence->fn->setImage(CCtrlScrn1_RightFanImageSequence, 1, &CctrlFan2);
    CCtrlScrn1_RightFanImageSequence->fn->setImageDelay(CCtrlScrn1_RightFanImageSequence, 1, 1000);
    CCtrlScrn1_RightFanImageSequence->fn->setImage(CCtrlScrn1_RightFanImageSequence, 2, &CctrlFan3);
    CCtrlScrn1_RightFanImageSequence->fn->setImageDelay(CCtrlScrn1_RightFanImageSequence, 2, 1000);
    CCtrlScrn1_RightFanImageSequence->fn->setImage(CCtrlScrn1_RightFanImageSequence, 3, &CctrlFan4);
    CCtrlScrn1_RightFanImageSequence->fn->setImageDelay(CCtrlScrn1_RightFanImageSequence, 3, 1000);
    CCtrlScrn1_RightFanImageSequence->fn->setImage(CCtrlScrn1_RightFanImageSequence, 4, &CctrlFan5);
    CCtrlScrn1_RightFanImageSequence->fn->setImageDelay(CCtrlScrn1_RightFanImageSequence, 4, 1000);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_RightFanImageSequence);

    CCtrlScrn1_LeftFanImageSequence = leImageSequenceWidget_New();
    CCtrlScrn1_LeftFanImageSequence->fn->setPosition(CCtrlScrn1_LeftFanImageSequence, 20, 60);
    CCtrlScrn1_LeftFanImageSequence->fn->setSize(CCtrlScrn1_LeftFanImageSequence, 40, 233);
    CCtrlScrn1_LeftFanImageSequence->fn->setBackgroundType(CCtrlScrn1_LeftFanImageSequence, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageCount(CCtrlScrn1_LeftFanImageSequence, 5);
    CCtrlScrn1_LeftFanImageSequence->fn->setImage(CCtrlScrn1_LeftFanImageSequence, 0, &CctrlFan1);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageDelay(CCtrlScrn1_LeftFanImageSequence, 0, 1000);
    CCtrlScrn1_LeftFanImageSequence->fn->setImage(CCtrlScrn1_LeftFanImageSequence, 1, &CctrlFan2);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageDelay(CCtrlScrn1_LeftFanImageSequence, 1, 1000);
    CCtrlScrn1_LeftFanImageSequence->fn->setImage(CCtrlScrn1_LeftFanImageSequence, 2, &CctrlFan3);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageDelay(CCtrlScrn1_LeftFanImageSequence, 2, 1000);
    CCtrlScrn1_LeftFanImageSequence->fn->setImage(CCtrlScrn1_LeftFanImageSequence, 3, &CctrlFan4);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageDelay(CCtrlScrn1_LeftFanImageSequence, 3, 1000);
    CCtrlScrn1_LeftFanImageSequence->fn->setImage(CCtrlScrn1_LeftFanImageSequence, 4, &CctrlFan5);
    CCtrlScrn1_LeftFanImageSequence->fn->setImageDelay(CCtrlScrn1_LeftFanImageSequence, 4, 1000);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_LeftFanImageSequence);

    CCtrlScrn1_RightFanDownButton = leButtonWidget_New();
    CCtrlScrn1_RightFanDownButton->fn->setPosition(CCtrlScrn1_RightFanDownButton, 400, 170);
    CCtrlScrn1_RightFanDownButton->fn->setSize(CCtrlScrn1_RightFanDownButton, 80, 150);
    CCtrlScrn1_RightFanDownButton->fn->setBackgroundType(CCtrlScrn1_RightFanDownButton, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_RightFanDownButton->fn->setBorderType(CCtrlScrn1_RightFanDownButton, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_RightFanDownButton->fn->setPressedEventCallback(CCtrlScrn1_RightFanDownButton, event_CCtrlScrn1_RightFanDownButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_RightFanDownButton);

    CCtrlScrn1_RightFanUpButton = leButtonWidget_New();
    CCtrlScrn1_RightFanUpButton->fn->setPosition(CCtrlScrn1_RightFanUpButton, 401, 50);
    CCtrlScrn1_RightFanUpButton->fn->setSize(CCtrlScrn1_RightFanUpButton, 79, 121);
    CCtrlScrn1_RightFanUpButton->fn->setBackgroundType(CCtrlScrn1_RightFanUpButton, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_RightFanUpButton->fn->setBorderType(CCtrlScrn1_RightFanUpButton, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_RightFanUpButton->fn->setPressedOffset(CCtrlScrn1_RightFanUpButton, 0);
    CCtrlScrn1_RightFanUpButton->fn->setPressedEventCallback(CCtrlScrn1_RightFanUpButton, event_CCtrlScrn1_RightFanUpButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_RightFanUpButton);

    CCtrlScrn1_LeftFanDownButton = leButtonWidget_New();
    CCtrlScrn1_LeftFanDownButton->fn->setPosition(CCtrlScrn1_LeftFanDownButton, 0, 172);
    CCtrlScrn1_LeftFanDownButton->fn->setSize(CCtrlScrn1_LeftFanDownButton, 80, 148);
    CCtrlScrn1_LeftFanDownButton->fn->setBackgroundType(CCtrlScrn1_LeftFanDownButton, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_LeftFanDownButton->fn->setBorderType(CCtrlScrn1_LeftFanDownButton, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_LeftFanDownButton->fn->setPressedEventCallback(CCtrlScrn1_LeftFanDownButton, event_CCtrlScrn1_LeftFanDownButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_LeftFanDownButton);

    CCtrlScrn1_LeftFanUpButton = leButtonWidget_New();
    CCtrlScrn1_LeftFanUpButton->fn->setPosition(CCtrlScrn1_LeftFanUpButton, 0, 50);
    CCtrlScrn1_LeftFanUpButton->fn->setSize(CCtrlScrn1_LeftFanUpButton, 80, 124);
    CCtrlScrn1_LeftFanUpButton->fn->setBackgroundType(CCtrlScrn1_LeftFanUpButton, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_LeftFanUpButton->fn->setBorderType(CCtrlScrn1_LeftFanUpButton, LE_WIDGET_BORDER_NONE);
    CCtrlScrn1_LeftFanUpButton->fn->setPressedEventCallback(CCtrlScrn1_LeftFanUpButton, event_CCtrlScrn1_LeftFanUpButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_LeftFanUpButton);

    CCtrlScrn1_LineWidget0 = leLineWidget_New();
    CCtrlScrn1_LineWidget0->fn->setPosition(CCtrlScrn1_LineWidget0, 399, 82);
    CCtrlScrn1_LineWidget0->fn->setSize(CCtrlScrn1_LineWidget0, 3, 200);
    CCtrlScrn1_LineWidget0->fn->setScheme(CCtrlScrn1_LineWidget0, &WhiteTextScheme);
    CCtrlScrn1_LineWidget0->fn->setBackgroundType(CCtrlScrn1_LineWidget0, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_LineWidget0->fn->setStartPoint(CCtrlScrn1_LineWidget0, 1, 0);
    CCtrlScrn1_LineWidget0->fn->setEndPoint(CCtrlScrn1_LineWidget0, 1, 200);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_LineWidget0);

    CCtrlScrn1_LineWidget1 = leLineWidget_New();
    CCtrlScrn1_LineWidget1->fn->setPosition(CCtrlScrn1_LineWidget1, 81, 82);
    CCtrlScrn1_LineWidget1->fn->setSize(CCtrlScrn1_LineWidget1, 3, 200);
    CCtrlScrn1_LineWidget1->fn->setScheme(CCtrlScrn1_LineWidget1, &WhiteTextScheme);
    CCtrlScrn1_LineWidget1->fn->setBackgroundType(CCtrlScrn1_LineWidget1, LE_WIDGET_BACKGROUND_NONE);
    CCtrlScrn1_LineWidget1->fn->setStartPoint(CCtrlScrn1_LineWidget1, 1, 0);
    CCtrlScrn1_LineWidget1->fn->setEndPoint(CCtrlScrn1_LineWidget1, 1, 200);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_LineWidget1);

    CCtrlScrn1_FPSLabel = leLabelWidget_New();
    CCtrlScrn1_FPSLabel->fn->setPosition(CCtrlScrn1_FPSLabel, 402, 295);
    CCtrlScrn1_FPSLabel->fn->setSize(CCtrlScrn1_FPSLabel, 78, 25);
    CCtrlScrn1_FPSLabel->fn->setScheme(CCtrlScrn1_FPSLabel, &WhiteTextScheme);
    CCtrlScrn1_FPSLabel->fn->setBackgroundType(CCtrlScrn1_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CCtrlScrn1_FPSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    CCtrlScrn1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_CCtrlScrn1(void)
{
    CCtrlScrn1_OnUpdate(); // raise event
}

void screenHide_CCtrlScrn1(void)
{
    CCtrlScrn1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    CCtrlScrn1_PanelWidget0 = NULL;
    CCtrlScrn1_ImageWidget2 = NULL;
    CCtrlScrn1_ImageWidget1 = NULL;
    CCtrlScrn1_ListWheelWidget0 = NULL;
    CCtrlScrn1_ListWheelWidget1 = NULL;
    CCtrlScrn1_ButtonWidget0 = NULL;
    CCtrlScrn1_ButtonWidget1 = NULL;
    CCtrlScrn1_ButtonWidget2 = NULL;
    CCtrlScrn1_ButtonWidget3 = NULL;
    CCtrlScrn1_ButtonWidget4 = NULL;
    CCtrlScrn1_ListWheelWidget2 = NULL;
    CCtrlScrn1_HomeButton = NULL;
    CCtrlScrn1_RightFanImageSequence = NULL;
    CCtrlScrn1_LeftFanImageSequence = NULL;
    CCtrlScrn1_RightFanDownButton = NULL;
    CCtrlScrn1_RightFanUpButton = NULL;
    CCtrlScrn1_LeftFanDownButton = NULL;
    CCtrlScrn1_LeftFanUpButton = NULL;
    CCtrlScrn1_LineWidget0 = NULL;
    CCtrlScrn1_LineWidget1 = NULL;
    CCtrlScrn1_FPSLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_CCtrlScrn1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_CCtrlScrn1(uint32_t lyrIdx)
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

