#include "gfx/legato/generated/screen/le_gen_screen_CkrScrn2.h"

// screen member widget declarations
static leWidget* root0;

leWidget* CkrScrn2_PanelWidget2;
leWidget* CkrScrn2_PanelWidget5;
leWidget* CkrScrn2_PanelWidget4;
leWidget* CkrScrn2_QuickSelectionsPanel;
leWidget* CkrScrn2_Screen2MainClockPanel;
leWidget* CkrScrn2_Screen2LabelPanel;
leButtonWidget* CkrScrn2_SliderButton2;
leImageWidget* CkrScrn2_ImageWidget0;
leButtonWidget* CkrScrn2_HomeButton;
leLabelWidget* CkrScrn2_FPSLabel;
leRectangleWidget* CkrScrn2_ProgressRect;
leButtonWidget* CkrScrn2_ButtonWidget5;
leButtonWidget* CkrScrn2_CookButtonWidget;
leButtonWidget* CkrScrn2_ReheatButtonWidget;
leWidget* CkrScrn2_MenuItem4;
leWidget* CkrScrn2_MenuItem3;
leWidget* CkrScrn2_MenuItem2;
leLabelWidget* CkrScrn2_LabelWidget2;
leWidget* CkrScrn2_MenuItem1;
leRectangleWidget* CkrScrn2_Button4Rect;
leRectangleWidget* CkrScrn2_Button4RectBack;
leLabelWidget* CkrScrn2_MenuItem4Label;
leImageWidget* CkrScrn2_Button4Image;
leButtonWidget* CkrScrn2_ButtonWidget4;
leRectangleWidget* CkrScrn2_Button3Rect;
leRectangleWidget* CkrScrn2_Button3RectBack;
leLabelWidget* CkrScrn2_MenuItem3Label;
leImageWidget* CkrScrn2_ButtonImage3;
leButtonWidget* CkrScrn2_ButtonWidget3;
leRectangleWidget* CkrScrn2_Button2Rect;
leRectangleWidget* CkrScrn2_Button2RectBack;
leImageWidget* CkrScrn2_ButtonImage2;
leLabelWidget* CkrScrn2_MenuItem2Label;
leButtonWidget* CkrScrn2_ButtonWidget2;
leRectangleWidget* CkrScrn2_Button1Rect;
leRectangleWidget* CkrScrn2_ButtonRect1Back;
leLabelWidget* CkrScrn2_MenuItem1Label;
leImageWidget* CkrScrn2_ButtonImage1;
leButtonWidget* CkrScrn2_ButtonWidget1;
leLabelWidget* CkrScrn2_Screen2MinuteLabel;
leLabelWidget* CkrScrn2_Screen2ColonLabel;
leLabelWidget* CkrScrn2_Screen2HourLabel;
leButtonWidget* CkrScrn2_ButtonWidget6;
leLabelWidget* CkrScrn2_Screen2SmartCookerLabel;
leLabelWidget* CkrScrn2_Screen2BytesLabel;
leLabelWidget* CkrScrn2_Screen2GoodLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_CkrScrn2(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_CkrScrn2(void)
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

    CkrScrn2_PanelWidget2 = leWidget_New();
    CkrScrn2_PanelWidget2->fn->setPosition(CkrScrn2_PanelWidget2, 0, 0);
    CkrScrn2_PanelWidget2->fn->setSize(CkrScrn2_PanelWidget2, 480, 320);
    CkrScrn2_PanelWidget2->fn->setScheme(CkrScrn2_PanelWidget2, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_PanelWidget2);

    CkrScrn2_PanelWidget5 = leWidget_New();
    CkrScrn2_PanelWidget5->fn->setPosition(CkrScrn2_PanelWidget5, 212, 22);
    CkrScrn2_PanelWidget5->fn->setSize(CkrScrn2_PanelWidget5, 153, 290);
    CkrScrn2_PanelWidget5->fn->setScheme(CkrScrn2_PanelWidget5, &VeryDarkGrayScheme);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_PanelWidget5);

    CkrScrn2_ProgressRect = leRectangleWidget_New();
    CkrScrn2_ProgressRect->fn->setPosition(CkrScrn2_ProgressRect, 0, 30);
    CkrScrn2_ProgressRect->fn->setSize(CkrScrn2_ProgressRect, 153, 260);
    CkrScrn2_ProgressRect->fn->setScheme(CkrScrn2_ProgressRect, &Button1Scheme);
    CkrScrn2_ProgressRect->fn->setBorderType(CkrScrn2_ProgressRect, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ProgressRect->fn->setThickness(CkrScrn2_ProgressRect, 0);
    CkrScrn2_PanelWidget5->fn->addChild(CkrScrn2_PanelWidget5, (leWidget*)CkrScrn2_ProgressRect);

    CkrScrn2_PanelWidget4 = leWidget_New();
    CkrScrn2_PanelWidget4->fn->setPosition(CkrScrn2_PanelWidget4, 365, 0);
    CkrScrn2_PanelWidget4->fn->setSize(CkrScrn2_PanelWidget4, 115, 320);
    CkrScrn2_PanelWidget4->fn->setScheme(CkrScrn2_PanelWidget4, &RightPanelScheme);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_PanelWidget4);

    CkrScrn2_ButtonWidget5 = leButtonWidget_New();
    CkrScrn2_ButtonWidget5->fn->setPosition(CkrScrn2_ButtonWidget5, 0, 251);
    CkrScrn2_ButtonWidget5->fn->setSize(CkrScrn2_ButtonWidget5, 115, 40);
    CkrScrn2_ButtonWidget5->fn->setBackgroundType(CkrScrn2_ButtonWidget5, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget5->fn->setBorderType(CkrScrn2_ButtonWidget5, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget5->fn->setPressedImage(CkrScrn2_ButtonWidget5, (leImage*)&gscalesmall);
    CkrScrn2_ButtonWidget5->fn->setReleasedImage(CkrScrn2_ButtonWidget5, (leImage*)&gscalesmall);
    CkrScrn2_ButtonWidget5->fn->setPressedOffset(CkrScrn2_ButtonWidget5, 0);
    CkrScrn2_ButtonWidget5->fn->setReleasedEventCallback(CkrScrn2_ButtonWidget5, event_CkrScrn2_ButtonWidget5_OnReleased);
    CkrScrn2_PanelWidget4->fn->addChild(CkrScrn2_PanelWidget4, (leWidget*)CkrScrn2_ButtonWidget5);

    CkrScrn2_CookButtonWidget = leButtonWidget_New();
    CkrScrn2_CookButtonWidget->fn->setPosition(CkrScrn2_CookButtonWidget, 0, 85);
    CkrScrn2_CookButtonWidget->fn->setSize(CkrScrn2_CookButtonWidget, 115, 78);
    CkrScrn2_CookButtonWidget->fn->setScheme(CkrScrn2_CookButtonWidget, &BlackBackground);
    CkrScrn2_CookButtonWidget->fn->setBackgroundType(CkrScrn2_CookButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_CookButtonWidget->fn->setBorderType(CkrScrn2_CookButtonWidget, LE_WIDGET_BORDER_NONE);
    CkrScrn2_CookButtonWidget->fn->setPressedImage(CkrScrn2_CookButtonWidget, (leImage*)&cook2);
    CkrScrn2_CookButtonWidget->fn->setReleasedImage(CkrScrn2_CookButtonWidget, (leImage*)&cook2);
    CkrScrn2_CookButtonWidget->fn->setPressedOffset(CkrScrn2_CookButtonWidget, 0);
    CkrScrn2_CookButtonWidget->fn->setReleasedEventCallback(CkrScrn2_CookButtonWidget, event_CkrScrn2_CookButtonWidget_OnReleased);
    CkrScrn2_PanelWidget4->fn->addChild(CkrScrn2_PanelWidget4, (leWidget*)CkrScrn2_CookButtonWidget);

    CkrScrn2_ReheatButtonWidget = leButtonWidget_New();
    CkrScrn2_ReheatButtonWidget->fn->setPosition(CkrScrn2_ReheatButtonWidget, 0, 166);
    CkrScrn2_ReheatButtonWidget->fn->setSize(CkrScrn2_ReheatButtonWidget, 116, 75);
    CkrScrn2_ReheatButtonWidget->fn->setScheme(CkrScrn2_ReheatButtonWidget, &BlackBackground);
    CkrScrn2_ReheatButtonWidget->fn->setBackgroundType(CkrScrn2_ReheatButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ReheatButtonWidget->fn->setBorderType(CkrScrn2_ReheatButtonWidget, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ReheatButtonWidget->fn->setPressedImage(CkrScrn2_ReheatButtonWidget, (leImage*)&reheat2);
    CkrScrn2_ReheatButtonWidget->fn->setReleasedImage(CkrScrn2_ReheatButtonWidget, (leImage*)&reheat2);
    CkrScrn2_ReheatButtonWidget->fn->setPressedOffset(CkrScrn2_ReheatButtonWidget, 0);
    CkrScrn2_ReheatButtonWidget->fn->setReleasedEventCallback(CkrScrn2_ReheatButtonWidget, event_CkrScrn2_ReheatButtonWidget_OnReleased);
    CkrScrn2_PanelWidget4->fn->addChild(CkrScrn2_PanelWidget4, (leWidget*)CkrScrn2_ReheatButtonWidget);

    CkrScrn2_QuickSelectionsPanel = leWidget_New();
    CkrScrn2_QuickSelectionsPanel->fn->setPosition(CkrScrn2_QuickSelectionsPanel, 0, 0);
    CkrScrn2_QuickSelectionsPanel->fn->setSize(CkrScrn2_QuickSelectionsPanel, 212, 320);
    CkrScrn2_QuickSelectionsPanel->fn->setBackgroundType(CkrScrn2_QuickSelectionsPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_QuickSelectionsPanel);

    CkrScrn2_MenuItem4 = leWidget_New();
    CkrScrn2_MenuItem4->fn->setPosition(CkrScrn2_MenuItem4, 0, 246);
    CkrScrn2_MenuItem4->fn->setSize(CkrScrn2_MenuItem4, 212, 70);
    CkrScrn2_MenuItem4->fn->setBackgroundType(CkrScrn2_MenuItem4, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_QuickSelectionsPanel->fn->addChild(CkrScrn2_QuickSelectionsPanel, (leWidget*)CkrScrn2_MenuItem4);

    CkrScrn2_Button4Rect = leRectangleWidget_New();
    CkrScrn2_Button4Rect->fn->setPosition(CkrScrn2_Button4Rect, 0, 7);
    CkrScrn2_Button4Rect->fn->setSize(CkrScrn2_Button4Rect, 212, 50);
    CkrScrn2_Button4Rect->fn->setScheme(CkrScrn2_Button4Rect, &Button4Scheme);
    CkrScrn2_Button4Rect->fn->setBorderType(CkrScrn2_Button4Rect, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button4Rect->fn->setThickness(CkrScrn2_Button4Rect, 0);
    CkrScrn2_MenuItem4->fn->addChild(CkrScrn2_MenuItem4, (leWidget*)CkrScrn2_Button4Rect);

    CkrScrn2_Button4RectBack = leRectangleWidget_New();
    CkrScrn2_Button4RectBack->fn->setPosition(CkrScrn2_Button4RectBack, 6, 57);
    CkrScrn2_Button4RectBack->fn->setSize(CkrScrn2_Button4RectBack, 206, 8);
    CkrScrn2_Button4RectBack->fn->setScheme(CkrScrn2_Button4RectBack, &VeryDarkGrayScheme);
    CkrScrn2_Button4RectBack->fn->setBorderType(CkrScrn2_Button4RectBack, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button4RectBack->fn->setThickness(CkrScrn2_Button4RectBack, 0);
    CkrScrn2_MenuItem4->fn->addChild(CkrScrn2_MenuItem4, (leWidget*)CkrScrn2_Button4RectBack);

    CkrScrn2_MenuItem4Label = leLabelWidget_New();
    CkrScrn2_MenuItem4Label->fn->setPosition(CkrScrn2_MenuItem4Label, 108, 21);
    CkrScrn2_MenuItem4Label->fn->setScheme(CkrScrn2_MenuItem4Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem4Label->fn->setBackgroundType(CkrScrn2_MenuItem4Label, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_MenuItem4Label->fn->setString(CkrScrn2_MenuItem4Label, (leString*)&string_Pasta);
    CkrScrn2_MenuItem4->fn->addChild(CkrScrn2_MenuItem4, (leWidget*)CkrScrn2_MenuItem4Label);

    CkrScrn2_Button4Image = leImageWidget_New();
    CkrScrn2_Button4Image->fn->setPosition(CkrScrn2_Button4Image, 23, 0);
    CkrScrn2_Button4Image->fn->setSize(CkrScrn2_Button4Image, 70, 70);
    CkrScrn2_Button4Image->fn->setBackgroundType(CkrScrn2_Button4Image, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Button4Image->fn->setBorderType(CkrScrn2_Button4Image, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button4Image->fn->setImage(CkrScrn2_Button4Image, (leImage*)&pasta_photo_70);
    CkrScrn2_MenuItem4->fn->addChild(CkrScrn2_MenuItem4, (leWidget*)CkrScrn2_Button4Image);

    CkrScrn2_ButtonWidget4 = leButtonWidget_New();
    CkrScrn2_ButtonWidget4->fn->setPosition(CkrScrn2_ButtonWidget4, 0, 0);
    CkrScrn2_ButtonWidget4->fn->setSize(CkrScrn2_ButtonWidget4, 212, 70);
    CkrScrn2_ButtonWidget4->fn->setBackgroundType(CkrScrn2_ButtonWidget4, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget4->fn->setBorderType(CkrScrn2_ButtonWidget4, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget4->fn->setPressedEventCallback(CkrScrn2_ButtonWidget4, event_CkrScrn2_ButtonWidget4_OnPressed);
    CkrScrn2_MenuItem4->fn->addChild(CkrScrn2_MenuItem4, (leWidget*)CkrScrn2_ButtonWidget4);

    CkrScrn2_MenuItem3 = leWidget_New();
    CkrScrn2_MenuItem3->fn->setPosition(CkrScrn2_MenuItem3, 0, 175);
    CkrScrn2_MenuItem3->fn->setSize(CkrScrn2_MenuItem3, 212, 70);
    CkrScrn2_MenuItem3->fn->setBackgroundType(CkrScrn2_MenuItem3, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_QuickSelectionsPanel->fn->addChild(CkrScrn2_QuickSelectionsPanel, (leWidget*)CkrScrn2_MenuItem3);

    CkrScrn2_Button3Rect = leRectangleWidget_New();
    CkrScrn2_Button3Rect->fn->setPosition(CkrScrn2_Button3Rect, 0, 7);
    CkrScrn2_Button3Rect->fn->setSize(CkrScrn2_Button3Rect, 212, 50);
    CkrScrn2_Button3Rect->fn->setScheme(CkrScrn2_Button3Rect, &Button3Scheme);
    CkrScrn2_Button3Rect->fn->setBorderType(CkrScrn2_Button3Rect, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button3Rect->fn->setThickness(CkrScrn2_Button3Rect, 0);
    CkrScrn2_MenuItem3->fn->addChild(CkrScrn2_MenuItem3, (leWidget*)CkrScrn2_Button3Rect);

    CkrScrn2_Button3RectBack = leRectangleWidget_New();
    CkrScrn2_Button3RectBack->fn->setPosition(CkrScrn2_Button3RectBack, 6, 56);
    CkrScrn2_Button3RectBack->fn->setSize(CkrScrn2_Button3RectBack, 206, 9);
    CkrScrn2_Button3RectBack->fn->setScheme(CkrScrn2_Button3RectBack, &VeryDarkGrayScheme);
    CkrScrn2_Button3RectBack->fn->setBorderType(CkrScrn2_Button3RectBack, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button3RectBack->fn->setThickness(CkrScrn2_Button3RectBack, 0);
    CkrScrn2_MenuItem3->fn->addChild(CkrScrn2_MenuItem3, (leWidget*)CkrScrn2_Button3RectBack);

    CkrScrn2_MenuItem3Label = leLabelWidget_New();
    CkrScrn2_MenuItem3Label->fn->setPosition(CkrScrn2_MenuItem3Label, 99, 21);
    CkrScrn2_MenuItem3Label->fn->setScheme(CkrScrn2_MenuItem3Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem3Label->fn->setBackgroundType(CkrScrn2_MenuItem3Label, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_MenuItem3Label->fn->setString(CkrScrn2_MenuItem3Label, (leString*)&string_PizzaMenuItem);
    CkrScrn2_MenuItem3->fn->addChild(CkrScrn2_MenuItem3, (leWidget*)CkrScrn2_MenuItem3Label);

    CkrScrn2_ButtonImage3 = leImageWidget_New();
    CkrScrn2_ButtonImage3->fn->setPosition(CkrScrn2_ButtonImage3, 13, 0);
    CkrScrn2_ButtonImage3->fn->setSize(CkrScrn2_ButtonImage3, 70, 70);
    CkrScrn2_ButtonImage3->fn->setBackgroundType(CkrScrn2_ButtonImage3, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonImage3->fn->setBorderType(CkrScrn2_ButtonImage3, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonImage3->fn->setImage(CkrScrn2_ButtonImage3, (leImage*)&pizza_photo70);
    CkrScrn2_MenuItem3->fn->addChild(CkrScrn2_MenuItem3, (leWidget*)CkrScrn2_ButtonImage3);

    CkrScrn2_ButtonWidget3 = leButtonWidget_New();
    CkrScrn2_ButtonWidget3->fn->setPosition(CkrScrn2_ButtonWidget3, 0, 0);
    CkrScrn2_ButtonWidget3->fn->setSize(CkrScrn2_ButtonWidget3, 212, 70);
    CkrScrn2_ButtonWidget3->fn->setBackgroundType(CkrScrn2_ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget3->fn->setBorderType(CkrScrn2_ButtonWidget3, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget3->fn->setPressedEventCallback(CkrScrn2_ButtonWidget3, event_CkrScrn2_ButtonWidget3_OnPressed);
    CkrScrn2_MenuItem3->fn->addChild(CkrScrn2_MenuItem3, (leWidget*)CkrScrn2_ButtonWidget3);

    CkrScrn2_MenuItem2 = leWidget_New();
    CkrScrn2_MenuItem2->fn->setPosition(CkrScrn2_MenuItem2, 0, 102);
    CkrScrn2_MenuItem2->fn->setSize(CkrScrn2_MenuItem2, 212, 70);
    CkrScrn2_MenuItem2->fn->setBackgroundType(CkrScrn2_MenuItem2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_QuickSelectionsPanel->fn->addChild(CkrScrn2_QuickSelectionsPanel, (leWidget*)CkrScrn2_MenuItem2);

    CkrScrn2_Button2Rect = leRectangleWidget_New();
    CkrScrn2_Button2Rect->fn->setPosition(CkrScrn2_Button2Rect, 0, 7);
    CkrScrn2_Button2Rect->fn->setSize(CkrScrn2_Button2Rect, 212, 50);
    CkrScrn2_Button2Rect->fn->setScheme(CkrScrn2_Button2Rect, &Button2Scheme);
    CkrScrn2_Button2Rect->fn->setBorderType(CkrScrn2_Button2Rect, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button2Rect->fn->setThickness(CkrScrn2_Button2Rect, 0);
    CkrScrn2_MenuItem2->fn->addChild(CkrScrn2_MenuItem2, (leWidget*)CkrScrn2_Button2Rect);

    CkrScrn2_Button2RectBack = leRectangleWidget_New();
    CkrScrn2_Button2RectBack->fn->setPosition(CkrScrn2_Button2RectBack, 6, 57);
    CkrScrn2_Button2RectBack->fn->setSize(CkrScrn2_Button2RectBack, 206, 8);
    CkrScrn2_Button2RectBack->fn->setScheme(CkrScrn2_Button2RectBack, &VeryDarkGrayScheme);
    CkrScrn2_Button2RectBack->fn->setBorderType(CkrScrn2_Button2RectBack, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button2RectBack->fn->setThickness(CkrScrn2_Button2RectBack, 0);
    CkrScrn2_MenuItem2->fn->addChild(CkrScrn2_MenuItem2, (leWidget*)CkrScrn2_Button2RectBack);

    CkrScrn2_ButtonImage2 = leImageWidget_New();
    CkrScrn2_ButtonImage2->fn->setPosition(CkrScrn2_ButtonImage2, 23, 0);
    CkrScrn2_ButtonImage2->fn->setSize(CkrScrn2_ButtonImage2, 70, 70);
    CkrScrn2_ButtonImage2->fn->setBackgroundType(CkrScrn2_ButtonImage2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonImage2->fn->setBorderType(CkrScrn2_ButtonImage2, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonImage2->fn->setImage(CkrScrn2_ButtonImage2, (leImage*)&salmon_photo_70);
    CkrScrn2_MenuItem2->fn->addChild(CkrScrn2_MenuItem2, (leWidget*)CkrScrn2_ButtonImage2);

    CkrScrn2_MenuItem2Label = leLabelWidget_New();
    CkrScrn2_MenuItem2Label->fn->setPosition(CkrScrn2_MenuItem2Label, 109, 19);
    CkrScrn2_MenuItem2Label->fn->setScheme(CkrScrn2_MenuItem2Label, &UnselectedItemTextScheme);
    CkrScrn2_MenuItem2Label->fn->setBackgroundType(CkrScrn2_MenuItem2Label, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_MenuItem2Label->fn->setString(CkrScrn2_MenuItem2Label, (leString*)&string_SalmonMenuItem);
    CkrScrn2_MenuItem2->fn->addChild(CkrScrn2_MenuItem2, (leWidget*)CkrScrn2_MenuItem2Label);

    CkrScrn2_ButtonWidget2 = leButtonWidget_New();
    CkrScrn2_ButtonWidget2->fn->setPosition(CkrScrn2_ButtonWidget2, 0, 0);
    CkrScrn2_ButtonWidget2->fn->setSize(CkrScrn2_ButtonWidget2, 212, 70);
    CkrScrn2_ButtonWidget2->fn->setBackgroundType(CkrScrn2_ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget2->fn->setBorderType(CkrScrn2_ButtonWidget2, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget2->fn->setPressedEventCallback(CkrScrn2_ButtonWidget2, event_CkrScrn2_ButtonWidget2_OnPressed);
    CkrScrn2_MenuItem2->fn->addChild(CkrScrn2_MenuItem2, (leWidget*)CkrScrn2_ButtonWidget2);

    CkrScrn2_LabelWidget2 = leLabelWidget_New();
    CkrScrn2_LabelWidget2->fn->setPosition(CkrScrn2_LabelWidget2, 0, -1);
    CkrScrn2_LabelWidget2->fn->setSize(CkrScrn2_LabelWidget2, 212, 31);
    CkrScrn2_LabelWidget2->fn->setBackgroundType(CkrScrn2_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_LabelWidget2->fn->setHAlignment(CkrScrn2_LabelWidget2, LE_HALIGN_CENTER);
    CkrScrn2_LabelWidget2->fn->setString(CkrScrn2_LabelWidget2, (leString*)&string_QuickItems);
    CkrScrn2_QuickSelectionsPanel->fn->addChild(CkrScrn2_QuickSelectionsPanel, (leWidget*)CkrScrn2_LabelWidget2);

    CkrScrn2_MenuItem1 = leWidget_New();
    CkrScrn2_MenuItem1->fn->setPosition(CkrScrn2_MenuItem1, 0, 31);
    CkrScrn2_MenuItem1->fn->setSize(CkrScrn2_MenuItem1, 212, 70);
    CkrScrn2_MenuItem1->fn->setBackgroundType(CkrScrn2_MenuItem1, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_QuickSelectionsPanel->fn->addChild(CkrScrn2_QuickSelectionsPanel, (leWidget*)CkrScrn2_MenuItem1);

    CkrScrn2_Button1Rect = leRectangleWidget_New();
    CkrScrn2_Button1Rect->fn->setPosition(CkrScrn2_Button1Rect, 0, 7);
    CkrScrn2_Button1Rect->fn->setSize(CkrScrn2_Button1Rect, 212, 50);
    CkrScrn2_Button1Rect->fn->setScheme(CkrScrn2_Button1Rect, &Button1Scheme);
    CkrScrn2_Button1Rect->fn->setBorderType(CkrScrn2_Button1Rect, LE_WIDGET_BORDER_NONE);
    CkrScrn2_Button1Rect->fn->setThickness(CkrScrn2_Button1Rect, 0);
    CkrScrn2_MenuItem1->fn->addChild(CkrScrn2_MenuItem1, (leWidget*)CkrScrn2_Button1Rect);

    CkrScrn2_ButtonRect1Back = leRectangleWidget_New();
    CkrScrn2_ButtonRect1Back->fn->setPosition(CkrScrn2_ButtonRect1Back, 6, 57);
    CkrScrn2_ButtonRect1Back->fn->setSize(CkrScrn2_ButtonRect1Back, 206, 8);
    CkrScrn2_ButtonRect1Back->fn->setScheme(CkrScrn2_ButtonRect1Back, &VeryDarkGrayScheme);
    CkrScrn2_ButtonRect1Back->fn->setBorderType(CkrScrn2_ButtonRect1Back, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonRect1Back->fn->setThickness(CkrScrn2_ButtonRect1Back, 0);
    CkrScrn2_MenuItem1->fn->addChild(CkrScrn2_MenuItem1, (leWidget*)CkrScrn2_ButtonRect1Back);

    CkrScrn2_MenuItem1Label = leLabelWidget_New();
    CkrScrn2_MenuItem1Label->fn->setPosition(CkrScrn2_MenuItem1Label, 99, 20);
    CkrScrn2_MenuItem1Label->fn->setScheme(CkrScrn2_MenuItem1Label, &WhiteTextScheme);
    CkrScrn2_MenuItem1Label->fn->setBackgroundType(CkrScrn2_MenuItem1Label, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_MenuItem1Label->fn->setString(CkrScrn2_MenuItem1Label, (leString*)&string_SteakMenuItem);
    CkrScrn2_MenuItem1->fn->addChild(CkrScrn2_MenuItem1, (leWidget*)CkrScrn2_MenuItem1Label);

    CkrScrn2_ButtonImage1 = leImageWidget_New();
    CkrScrn2_ButtonImage1->fn->setPosition(CkrScrn2_ButtonImage1, 13, 0);
    CkrScrn2_ButtonImage1->fn->setSize(CkrScrn2_ButtonImage1, 70, 70);
    CkrScrn2_ButtonImage1->fn->setBackgroundType(CkrScrn2_ButtonImage1, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonImage1->fn->setBorderType(CkrScrn2_ButtonImage1, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonImage1->fn->setImage(CkrScrn2_ButtonImage1, (leImage*)&steak_photo_70);
    CkrScrn2_MenuItem1->fn->addChild(CkrScrn2_MenuItem1, (leWidget*)CkrScrn2_ButtonImage1);

    CkrScrn2_ButtonWidget1 = leButtonWidget_New();
    CkrScrn2_ButtonWidget1->fn->setPosition(CkrScrn2_ButtonWidget1, 0, 0);
    CkrScrn2_ButtonWidget1->fn->setSize(CkrScrn2_ButtonWidget1, 212, 70);
    CkrScrn2_ButtonWidget1->fn->setBackgroundType(CkrScrn2_ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget1->fn->setBorderType(CkrScrn2_ButtonWidget1, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget1->fn->setPressedOffset(CkrScrn2_ButtonWidget1, 0);
    CkrScrn2_ButtonWidget1->fn->setPressedEventCallback(CkrScrn2_ButtonWidget1, event_CkrScrn2_ButtonWidget1_OnPressed);
    CkrScrn2_MenuItem1->fn->addChild(CkrScrn2_MenuItem1, (leWidget*)CkrScrn2_ButtonWidget1);

    CkrScrn2_Screen2MainClockPanel = leWidget_New();
    CkrScrn2_Screen2MainClockPanel->fn->setPosition(CkrScrn2_Screen2MainClockPanel, 212, 22);
    CkrScrn2_Screen2MainClockPanel->fn->setSize(CkrScrn2_Screen2MainClockPanel, 153, 290);
    CkrScrn2_Screen2MainClockPanel->fn->setBackgroundType(CkrScrn2_Screen2MainClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_Screen2MainClockPanel);

    CkrScrn2_Screen2MinuteLabel = leLabelWidget_New();
    CkrScrn2_Screen2MinuteLabel->fn->setPosition(CkrScrn2_Screen2MinuteLabel, 51, 138);
    CkrScrn2_Screen2MinuteLabel->fn->setSize(CkrScrn2_Screen2MinuteLabel, 101, 80);
    CkrScrn2_Screen2MinuteLabel->fn->setScheme(CkrScrn2_Screen2MinuteLabel, &WhiteTextScheme);
    CkrScrn2_Screen2MinuteLabel->fn->setBackgroundType(CkrScrn2_Screen2MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Screen2MinuteLabel->fn->setString(CkrScrn2_Screen2MinuteLabel, (leString*)&string_DefaultMinute2);
    CkrScrn2_Screen2MainClockPanel->fn->addChild(CkrScrn2_Screen2MainClockPanel, (leWidget*)CkrScrn2_Screen2MinuteLabel);

    CkrScrn2_Screen2ColonLabel = leLabelWidget_New();
    CkrScrn2_Screen2ColonLabel->fn->setPosition(CkrScrn2_Screen2ColonLabel, 26, 146);
    CkrScrn2_Screen2ColonLabel->fn->setSize(CkrScrn2_Screen2ColonLabel, 26, 52);
    CkrScrn2_Screen2ColonLabel->fn->setScheme(CkrScrn2_Screen2ColonLabel, &WhiteTextScheme);
    CkrScrn2_Screen2ColonLabel->fn->setBackgroundType(CkrScrn2_Screen2ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Screen2ColonLabel->fn->setString(CkrScrn2_Screen2ColonLabel, (leString*)&string_Colon);
    CkrScrn2_Screen2MainClockPanel->fn->addChild(CkrScrn2_Screen2MainClockPanel, (leWidget*)CkrScrn2_Screen2ColonLabel);

    CkrScrn2_Screen2HourLabel = leLabelWidget_New();
    CkrScrn2_Screen2HourLabel->fn->setPosition(CkrScrn2_Screen2HourLabel, 0, 64);
    CkrScrn2_Screen2HourLabel->fn->setSize(CkrScrn2_Screen2HourLabel, 153, 75);
    CkrScrn2_Screen2HourLabel->fn->setScheme(CkrScrn2_Screen2HourLabel, &WhiteTextScheme);
    CkrScrn2_Screen2HourLabel->fn->setBackgroundType(CkrScrn2_Screen2HourLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Screen2HourLabel->fn->setHAlignment(CkrScrn2_Screen2HourLabel, LE_HALIGN_CENTER);
    CkrScrn2_Screen2HourLabel->fn->setString(CkrScrn2_Screen2HourLabel, (leString*)&string_DefaultHour2);
    CkrScrn2_Screen2MainClockPanel->fn->addChild(CkrScrn2_Screen2MainClockPanel, (leWidget*)CkrScrn2_Screen2HourLabel);

    CkrScrn2_Screen2LabelPanel = leWidget_New();
    CkrScrn2_Screen2LabelPanel->fn->setPosition(CkrScrn2_Screen2LabelPanel, 205, 0);
    CkrScrn2_Screen2LabelPanel->fn->setSize(CkrScrn2_Screen2LabelPanel, 275, 76);
    CkrScrn2_Screen2LabelPanel->fn->setBackgroundType(CkrScrn2_Screen2LabelPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_Screen2LabelPanel);

    CkrScrn2_ButtonWidget6 = leButtonWidget_New();
    CkrScrn2_ButtonWidget6->fn->setPosition(CkrScrn2_ButtonWidget6, 0, 22);
    CkrScrn2_ButtonWidget6->fn->setSize(CkrScrn2_ButtonWidget6, 160, 30);
    CkrScrn2_ButtonWidget6->fn->setBackgroundType(CkrScrn2_ButtonWidget6, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_ButtonWidget6->fn->setBorderType(CkrScrn2_ButtonWidget6, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ButtonWidget6->fn->setToggleable(CkrScrn2_ButtonWidget6, LE_TRUE);
    CkrScrn2_ButtonWidget6->fn->setPressedImage(CkrScrn2_ButtonWidget6, (leImage*)&DemoOff);
    CkrScrn2_ButtonWidget6->fn->setReleasedImage(CkrScrn2_ButtonWidget6, (leImage*)&DemoOn);
    CkrScrn2_ButtonWidget6->fn->setPressedEventCallback(CkrScrn2_ButtonWidget6, event_CkrScrn2_ButtonWidget6_OnPressed);
    CkrScrn2_ButtonWidget6->fn->setReleasedEventCallback(CkrScrn2_ButtonWidget6, event_CkrScrn2_ButtonWidget6_OnReleased);
    CkrScrn2_Screen2LabelPanel->fn->addChild(CkrScrn2_Screen2LabelPanel, (leWidget*)CkrScrn2_ButtonWidget6);

    CkrScrn2_Screen2SmartCookerLabel = leLabelWidget_New();
    CkrScrn2_Screen2SmartCookerLabel->fn->setPosition(CkrScrn2_Screen2SmartCookerLabel, 160, 58);
    CkrScrn2_Screen2SmartCookerLabel->fn->setSize(CkrScrn2_Screen2SmartCookerLabel, 115, 26);
    CkrScrn2_Screen2SmartCookerLabel->fn->setScheme(CkrScrn2_Screen2SmartCookerLabel, &WhiteTextScheme);
    CkrScrn2_Screen2SmartCookerLabel->fn->setBackgroundType(CkrScrn2_Screen2SmartCookerLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Screen2SmartCookerLabel->fn->setHAlignment(CkrScrn2_Screen2SmartCookerLabel, LE_HALIGN_CENTER);
    CkrScrn2_Screen2SmartCookerLabel->fn->setString(CkrScrn2_Screen2SmartCookerLabel, (leString*)&string_SmartCooker);
    CkrScrn2_Screen2LabelPanel->fn->addChild(CkrScrn2_Screen2LabelPanel, (leWidget*)CkrScrn2_Screen2SmartCookerLabel);

    CkrScrn2_Screen2BytesLabel = leLabelWidget_New();
    CkrScrn2_Screen2BytesLabel->fn->setPosition(CkrScrn2_Screen2BytesLabel, 0, 22);
    CkrScrn2_Screen2BytesLabel->fn->setSize(CkrScrn2_Screen2BytesLabel, 214, 30);
    CkrScrn2_Screen2BytesLabel->fn->setScheme(CkrScrn2_Screen2BytesLabel, &LabelBannerScheme);
    CkrScrn2_Screen2BytesLabel->fn->setHAlignment(CkrScrn2_Screen2BytesLabel, LE_HALIGN_RIGHT);
    CkrScrn2_Screen2BytesLabel->fn->setString(CkrScrn2_Screen2BytesLabel, (leString*)&string_Bytes);
    CkrScrn2_Screen2LabelPanel->fn->addChild(CkrScrn2_Screen2LabelPanel, (leWidget*)CkrScrn2_Screen2BytesLabel);

    CkrScrn2_Screen2GoodLabel = leLabelWidget_New();
    CkrScrn2_Screen2GoodLabel->fn->setPosition(CkrScrn2_Screen2GoodLabel, 80, 19);
    CkrScrn2_Screen2GoodLabel->fn->setSize(CkrScrn2_Screen2GoodLabel, 71, 29);
    CkrScrn2_Screen2GoodLabel->fn->setScheme(CkrScrn2_Screen2GoodLabel, &WhiteTextScheme);
    CkrScrn2_Screen2GoodLabel->fn->setBackgroundType(CkrScrn2_Screen2GoodLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_Screen2GoodLabel->fn->setHAlignment(CkrScrn2_Screen2GoodLabel, LE_HALIGN_CENTER);
    CkrScrn2_Screen2GoodLabel->fn->setString(CkrScrn2_Screen2GoodLabel, (leString*)&string_GoodBytes);
    CkrScrn2_Screen2LabelPanel->fn->addChild(CkrScrn2_Screen2LabelPanel, (leWidget*)CkrScrn2_Screen2GoodLabel);

    CkrScrn2_SliderButton2 = leButtonWidget_New();
    CkrScrn2_SliderButton2->fn->setPosition(CkrScrn2_SliderButton2, 212, 52);
    CkrScrn2_SliderButton2->fn->setSize(CkrScrn2_SliderButton2, 153, 260);
    CkrScrn2_SliderButton2->fn->setBackgroundType(CkrScrn2_SliderButton2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_SliderButton2->fn->setBorderType(CkrScrn2_SliderButton2, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_SliderButton2);

    CkrScrn2_ImageWidget0 = leImageWidget_New();
    CkrScrn2_ImageWidget0->fn->setPosition(CkrScrn2_ImageWidget0, 420, 0);
    CkrScrn2_ImageWidget0->fn->setSize(CkrScrn2_ImageWidget0, 60, 60);
    CkrScrn2_ImageWidget0->fn->setScheme(CkrScrn2_ImageWidget0, &PlayerVolScheme);
    CkrScrn2_ImageWidget0->fn->setBorderType(CkrScrn2_ImageWidget0, LE_WIDGET_BORDER_NONE);
    CkrScrn2_ImageWidget0->fn->setImage(CkrScrn2_ImageWidget0, (leImage*)&Home565Gray);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_ImageWidget0);

    CkrScrn2_HomeButton = leButtonWidget_New();
    CkrScrn2_HomeButton->fn->setPosition(CkrScrn2_HomeButton, 400, 0);
    CkrScrn2_HomeButton->fn->setSize(CkrScrn2_HomeButton, 80, 60);
    CkrScrn2_HomeButton->fn->setScheme(CkrScrn2_HomeButton, &PlayerVolScheme);
    CkrScrn2_HomeButton->fn->setBackgroundType(CkrScrn2_HomeButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn2_HomeButton->fn->setBorderType(CkrScrn2_HomeButton, LE_WIDGET_BORDER_NONE);
    CkrScrn2_HomeButton->fn->setPressedEventCallback(CkrScrn2_HomeButton, event_CkrScrn2_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_HomeButton);

    CkrScrn2_FPSLabel = leLabelWidget_New();
    CkrScrn2_FPSLabel->fn->setPosition(CkrScrn2_FPSLabel, 365, 292);
    CkrScrn2_FPSLabel->fn->setSize(CkrScrn2_FPSLabel, 115, 26);
    CkrScrn2_FPSLabel->fn->setScheme(CkrScrn2_FPSLabel, &WhiteTextScheme);
    CkrScrn2_FPSLabel->fn->setBackgroundType(CkrScrn2_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn2_FPSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    CkrScrn2_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_CkrScrn2(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    CkrScrn2_OnUpdate(); // raise event
}

void screenHide_CkrScrn2(void)
{
    CkrScrn2_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    CkrScrn2_PanelWidget2 = NULL;
    CkrScrn2_PanelWidget5 = NULL;
    CkrScrn2_PanelWidget4 = NULL;
    CkrScrn2_QuickSelectionsPanel = NULL;
    CkrScrn2_Screen2MainClockPanel = NULL;
    CkrScrn2_Screen2LabelPanel = NULL;
    CkrScrn2_SliderButton2 = NULL;
    CkrScrn2_ImageWidget0 = NULL;
    CkrScrn2_HomeButton = NULL;
    CkrScrn2_FPSLabel = NULL;
    CkrScrn2_ProgressRect = NULL;
    CkrScrn2_ButtonWidget5 = NULL;
    CkrScrn2_CookButtonWidget = NULL;
    CkrScrn2_ReheatButtonWidget = NULL;
    CkrScrn2_MenuItem4 = NULL;
    CkrScrn2_MenuItem3 = NULL;
    CkrScrn2_MenuItem2 = NULL;
    CkrScrn2_LabelWidget2 = NULL;
    CkrScrn2_MenuItem1 = NULL;
    CkrScrn2_Button4Rect = NULL;
    CkrScrn2_Button4RectBack = NULL;
    CkrScrn2_MenuItem4Label = NULL;
    CkrScrn2_Button4Image = NULL;
    CkrScrn2_ButtonWidget4 = NULL;
    CkrScrn2_Button3Rect = NULL;
    CkrScrn2_Button3RectBack = NULL;
    CkrScrn2_MenuItem3Label = NULL;
    CkrScrn2_ButtonImage3 = NULL;
    CkrScrn2_ButtonWidget3 = NULL;
    CkrScrn2_Button2Rect = NULL;
    CkrScrn2_Button2RectBack = NULL;
    CkrScrn2_ButtonImage2 = NULL;
    CkrScrn2_MenuItem2Label = NULL;
    CkrScrn2_ButtonWidget2 = NULL;
    CkrScrn2_Button1Rect = NULL;
    CkrScrn2_ButtonRect1Back = NULL;
    CkrScrn2_MenuItem1Label = NULL;
    CkrScrn2_ButtonImage1 = NULL;
    CkrScrn2_ButtonWidget1 = NULL;
    CkrScrn2_Screen2MinuteLabel = NULL;
    CkrScrn2_Screen2ColonLabel = NULL;
    CkrScrn2_Screen2HourLabel = NULL;
    CkrScrn2_ButtonWidget6 = NULL;
    CkrScrn2_Screen2SmartCookerLabel = NULL;
    CkrScrn2_Screen2BytesLabel = NULL;
    CkrScrn2_Screen2GoodLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_CkrScrn2(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_CkrScrn2(uint32_t lyrIdx)
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

