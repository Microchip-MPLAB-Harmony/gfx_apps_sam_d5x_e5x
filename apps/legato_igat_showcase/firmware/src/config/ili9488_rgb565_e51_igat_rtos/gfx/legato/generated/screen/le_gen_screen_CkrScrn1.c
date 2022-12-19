#include "gfx/legato/generated/screen/le_gen_screen_CkrScrn1.h"

// screen member widget declarations
static leWidget* root0;

leWidget* CkrScrn1_PanelWidget1;
leImageWidget* CkrScrn1_ImageWidget1;
leWidget* CkrScrn1_PanelWidget3;
leWidget* CkrScrn1_MainPanel;
leImageWidget* CkrScrn1_ImageWidget2;
leImageWidget* CkrScrn1_ImageWidget3;
leImageWidget* CkrScrn1_ImageWidget4;
leWidget* CkrScrn1_Badge;
leWidget* CkrScrn1_ClockPanel;
leImageWidget* CkrScrn1_ImageWidget8;
leWidget* CkrScrn1_PanelWidget0;
leButtonWidget* CkrScrn1_ButtonWidget0;
leButtonWidget* CkrScrn1_DemoModeOnButton;
leImageWidget* CkrScrn1_ImageWidget7;
leButtonWidget* CkrScrn1_HomeButton;
leImageWidget* CkrScrn1_ImageWidget5;
leLabelWidget* CkrScrn1_FPSLabel;
leListWheelWidget* CkrScrn1_ListWheelWidget2;
leButtonWidget* CkrScrn1_ReheatButton;
leButtonWidget* CkrScrn1_BroilButton;
leButtonWidget* CkrScrn1_CookButton;
leButtonWidget* CkrScrn1_BakeButton;
leLabelWidget* CkrScrn1_LabelWidget1;
leLabelWidget* CkrScrn1_LabelWidget3;
leLabelWidget* CkrScrn1_LabelWidget0;
leLabelWidget* CkrScrn1_HourLabel;
leImageWidget* CkrScrn1_ImageWidget6;
leLabelWidget* CkrScrn1_ColonLabel;
leLabelWidget* CkrScrn1_MinuteLabel;
leImageWidget* CkrScrn1_ImageWidget0;
leProgressBarWidget* CkrScrn1_ProgressBarWidget0;
leImageWidget* CkrScrn1_ModeImageWidget;
leRectangleWidget* CkrScrn1_RectangleWidget3;
leRectangleWidget* CkrScrn1_RectangleWidget2;
leRectangleWidget* CkrScrn1_RectangleWidget1;
leRectangleWidget* CkrScrn1_RectangleWidget0;
leLabelWidget* CkrScrn1_CookTimeLabel;
leButtonWidget* CkrScrn1_RestartButton;
leButtonWidget* CkrScrn1_SliderButton0;
leButtonWidget* CkrScrn1_CancelButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_CkrScrn1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_CkrScrn1(void)
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

    CkrScrn1_PanelWidget1 = leWidget_New();
    CkrScrn1_PanelWidget1->fn->setPosition(CkrScrn1_PanelWidget1, 0, 0);
    CkrScrn1_PanelWidget1->fn->setSize(CkrScrn1_PanelWidget1, 480, 320);
    CkrScrn1_PanelWidget1->fn->setScheme(CkrScrn1_PanelWidget1, &BlackBackground);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_PanelWidget1);

    CkrScrn1_ImageWidget1 = leImageWidget_New();
    CkrScrn1_ImageWidget1->fn->setPosition(CkrScrn1_ImageWidget1, 6, 111);
    CkrScrn1_ImageWidget1->fn->setSize(CkrScrn1_ImageWidget1, 105, 200);
    CkrScrn1_ImageWidget1->fn->setBackgroundType(CkrScrn1_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget1->fn->setBorderType(CkrScrn1_ImageWidget1, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget1->fn->setHAlignment(CkrScrn1_ImageWidget1, LE_HALIGN_LEFT);
    CkrScrn1_ImageWidget1->fn->setImage(CkrScrn1_ImageWidget1, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget1);

    CkrScrn1_PanelWidget3 = leWidget_New();
    CkrScrn1_PanelWidget3->fn->setPosition(CkrScrn1_PanelWidget3, 110, 124);
    CkrScrn1_PanelWidget3->fn->setSize(CkrScrn1_PanelWidget3, 116, 172);
    CkrScrn1_PanelWidget3->fn->setBackgroundType(CkrScrn1_PanelWidget3, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_PanelWidget3);

    CkrScrn1_ListWheelWidget2 = leListWheelWidget_New();
    CkrScrn1_ListWheelWidget2->fn->setPosition(CkrScrn1_ListWheelWidget2, 0, 1);
    CkrScrn1_ListWheelWidget2->fn->setSize(CkrScrn1_ListWheelWidget2, 115, 170);
    CkrScrn1_ListWheelWidget2->fn->setScheme(CkrScrn1_ListWheelWidget2, &ListWheelScheme);
    CkrScrn1_ListWheelWidget2->fn->setBackgroundType(CkrScrn1_ListWheelWidget2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ListWheelWidget2->fn->setBorderType(CkrScrn1_ListWheelWidget2, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ListWheelWidget2->fn->setIconMargin(CkrScrn1_ListWheelWidget2, 5);
    CkrScrn1_ListWheelWidget2->fn->setShowIndicators(CkrScrn1_ListWheelWidget2, LE_FALSE);
    CkrScrn1_ListWheelWidget2->fn->setShaded(CkrScrn1_ListWheelWidget2, LE_FALSE);
    CkrScrn1_ListWheelWidget2->fn->appendItem(CkrScrn1_ListWheelWidget2);
    CkrScrn1_ListWheelWidget2->fn->setItemString(CkrScrn1_ListWheelWidget2, 0, (leString*)&string_Hotdog);
    CkrScrn1_ListWheelWidget2->fn->appendItem(CkrScrn1_ListWheelWidget2);
    CkrScrn1_ListWheelWidget2->fn->setItemString(CkrScrn1_ListWheelWidget2, 1, (leString*)&string_Kabobs);
    CkrScrn1_ListWheelWidget2->fn->appendItem(CkrScrn1_ListWheelWidget2);
    CkrScrn1_ListWheelWidget2->fn->setItemString(CkrScrn1_ListWheelWidget2, 2, (leString*)&string_Steak);
    CkrScrn1_ListWheelWidget2->fn->appendItem(CkrScrn1_ListWheelWidget2);
    CkrScrn1_ListWheelWidget2->fn->setItemString(CkrScrn1_ListWheelWidget2, 3, (leString*)&string_Bacon);
    CkrScrn1_ListWheelWidget2->fn->appendItem(CkrScrn1_ListWheelWidget2);
    CkrScrn1_ListWheelWidget2->fn->setItemString(CkrScrn1_ListWheelWidget2, 4, (leString*)&string_Vegetables);
    CkrScrn1_ListWheelWidget2->fn->setSelectedItemChangedEventCallback(CkrScrn1_ListWheelWidget2, event_CkrScrn1_ListWheelWidget2_OnSelectionChanged);
    CkrScrn1_PanelWidget3->fn->addChild(CkrScrn1_PanelWidget3, (leWidget*)CkrScrn1_ListWheelWidget2);

    CkrScrn1_MainPanel = leWidget_New();
    CkrScrn1_MainPanel->fn->setPosition(CkrScrn1_MainPanel, 264, 102);
    CkrScrn1_MainPanel->fn->setSize(CkrScrn1_MainPanel, 207, 210);
    CkrScrn1_MainPanel->fn->setBackgroundType(CkrScrn1_MainPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_MainPanel);

    CkrScrn1_ReheatButton = leButtonWidget_New();
    CkrScrn1_ReheatButton->fn->setPosition(CkrScrn1_ReheatButton, 108, 5);
    CkrScrn1_ReheatButton->fn->setSize(CkrScrn1_ReheatButton, 100, 100);
    CkrScrn1_ReheatButton->fn->setBackgroundType(CkrScrn1_ReheatButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ReheatButton->fn->setBorderType(CkrScrn1_ReheatButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ReheatButton->fn->setPressedImage(CkrScrn1_ReheatButton, (leImage*)&reheat100);
    CkrScrn1_ReheatButton->fn->setReleasedImage(CkrScrn1_ReheatButton, (leImage*)&reheat100);
    CkrScrn1_ReheatButton->fn->setReleasedEventCallback(CkrScrn1_ReheatButton, event_CkrScrn1_ReheatButton_OnReleased);
    CkrScrn1_MainPanel->fn->addChild(CkrScrn1_MainPanel, (leWidget*)CkrScrn1_ReheatButton);

    CkrScrn1_BroilButton = leButtonWidget_New();
    CkrScrn1_BroilButton->fn->setPosition(CkrScrn1_BroilButton, 108, 106);
    CkrScrn1_BroilButton->fn->setSize(CkrScrn1_BroilButton, 100, 100);
    CkrScrn1_BroilButton->fn->setBackgroundType(CkrScrn1_BroilButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_BroilButton->fn->setBorderType(CkrScrn1_BroilButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_BroilButton->fn->setPressedImage(CkrScrn1_BroilButton, (leImage*)&broil100);
    CkrScrn1_BroilButton->fn->setReleasedImage(CkrScrn1_BroilButton, (leImage*)&broil100);
    CkrScrn1_BroilButton->fn->setReleasedEventCallback(CkrScrn1_BroilButton, event_CkrScrn1_BroilButton_OnReleased);
    CkrScrn1_MainPanel->fn->addChild(CkrScrn1_MainPanel, (leWidget*)CkrScrn1_BroilButton);

    CkrScrn1_CookButton = leButtonWidget_New();
    CkrScrn1_CookButton->fn->setPosition(CkrScrn1_CookButton, 9, 5);
    CkrScrn1_CookButton->fn->setSize(CkrScrn1_CookButton, 100, 100);
    CkrScrn1_CookButton->fn->setBackgroundType(CkrScrn1_CookButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_CookButton->fn->setBorderType(CkrScrn1_CookButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_CookButton->fn->setPressedImage(CkrScrn1_CookButton, (leImage*)&cook100);
    CkrScrn1_CookButton->fn->setReleasedImage(CkrScrn1_CookButton, (leImage*)&cook100);
    CkrScrn1_CookButton->fn->setReleasedEventCallback(CkrScrn1_CookButton, event_CkrScrn1_CookButton_OnReleased);
    CkrScrn1_MainPanel->fn->addChild(CkrScrn1_MainPanel, (leWidget*)CkrScrn1_CookButton);

    CkrScrn1_BakeButton = leButtonWidget_New();
    CkrScrn1_BakeButton->fn->setPosition(CkrScrn1_BakeButton, 9, 106);
    CkrScrn1_BakeButton->fn->setSize(CkrScrn1_BakeButton, 100, 100);
    CkrScrn1_BakeButton->fn->setScheme(CkrScrn1_BakeButton, &SquareButtonScheme);
    CkrScrn1_BakeButton->fn->setBackgroundType(CkrScrn1_BakeButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_BakeButton->fn->setBorderType(CkrScrn1_BakeButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_BakeButton->fn->setPressedImage(CkrScrn1_BakeButton, (leImage*)&bake100);
    CkrScrn1_BakeButton->fn->setReleasedImage(CkrScrn1_BakeButton, (leImage*)&bake100);
    CkrScrn1_BakeButton->fn->setImagePosition(CkrScrn1_BakeButton, LE_RELATIVE_POSITION_ABOVE);
    CkrScrn1_BakeButton->fn->setReleasedEventCallback(CkrScrn1_BakeButton, event_CkrScrn1_BakeButton_OnReleased);
    CkrScrn1_MainPanel->fn->addChild(CkrScrn1_MainPanel, (leWidget*)CkrScrn1_BakeButton);

    CkrScrn1_ImageWidget2 = leImageWidget_New();
    CkrScrn1_ImageWidget2->fn->setPosition(CkrScrn1_ImageWidget2, 228, 110);
    CkrScrn1_ImageWidget2->fn->setSize(CkrScrn1_ImageWidget2, 22, 200);
    CkrScrn1_ImageWidget2->fn->setBackgroundType(CkrScrn1_ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget2->fn->setBorderType(CkrScrn1_ImageWidget2, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget2->fn->setHAlignment(CkrScrn1_ImageWidget2, LE_HALIGN_RIGHT);
    CkrScrn1_ImageWidget2->fn->setImage(CkrScrn1_ImageWidget2, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget2);

    CkrScrn1_ImageWidget3 = leImageWidget_New();
    CkrScrn1_ImageWidget3->fn->setPosition(CkrScrn1_ImageWidget3, 110, 111);
    CkrScrn1_ImageWidget3->fn->setSize(CkrScrn1_ImageWidget3, 141, 12);
    CkrScrn1_ImageWidget3->fn->setBackgroundType(CkrScrn1_ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget3->fn->setBorderType(CkrScrn1_ImageWidget3, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget3->fn->setHAlignment(CkrScrn1_ImageWidget3, LE_HALIGN_RIGHT);
    CkrScrn1_ImageWidget3->fn->setVAlignment(CkrScrn1_ImageWidget3, LE_VALIGN_TOP);
    CkrScrn1_ImageWidget3->fn->setMargins(CkrScrn1_ImageWidget3, 4, 0, 4, 0);
    CkrScrn1_ImageWidget3->fn->setImage(CkrScrn1_ImageWidget3, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget3);

    CkrScrn1_ImageWidget4 = leImageWidget_New();
    CkrScrn1_ImageWidget4->fn->setPosition(CkrScrn1_ImageWidget4, 109, 299);
    CkrScrn1_ImageWidget4->fn->setSize(CkrScrn1_ImageWidget4, 139, 12);
    CkrScrn1_ImageWidget4->fn->setBackgroundType(CkrScrn1_ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget4->fn->setBorderType(CkrScrn1_ImageWidget4, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget4->fn->setHAlignment(CkrScrn1_ImageWidget4, LE_HALIGN_RIGHT);
    CkrScrn1_ImageWidget4->fn->setVAlignment(CkrScrn1_ImageWidget4, LE_VALIGN_BOTTOM);
    CkrScrn1_ImageWidget4->fn->setMargins(CkrScrn1_ImageWidget4, 4, 0, 4, 0);
    CkrScrn1_ImageWidget4->fn->setImage(CkrScrn1_ImageWidget4, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget4);

    CkrScrn1_Badge = leWidget_New();
    CkrScrn1_Badge->fn->setPosition(CkrScrn1_Badge, 18, 38);
    CkrScrn1_Badge->fn->setSize(CkrScrn1_Badge, 225, 54);
    CkrScrn1_Badge->fn->setBackgroundType(CkrScrn1_Badge, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_Badge);

    CkrScrn1_LabelWidget1 = leLabelWidget_New();
    CkrScrn1_LabelWidget1->fn->setPosition(CkrScrn1_LabelWidget1, 87, 31);
    CkrScrn1_LabelWidget1->fn->setSize(CkrScrn1_LabelWidget1, 125, 23);
    CkrScrn1_LabelWidget1->fn->setScheme(CkrScrn1_LabelWidget1, &WhiteTextScheme);
    CkrScrn1_LabelWidget1->fn->setBackgroundType(CkrScrn1_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_LabelWidget1->fn->setHAlignment(CkrScrn1_LabelWidget1, LE_HALIGN_RIGHT);
    CkrScrn1_LabelWidget1->fn->setString(CkrScrn1_LabelWidget1, (leString*)&string_SmartCooker);
    CkrScrn1_Badge->fn->addChild(CkrScrn1_Badge, (leWidget*)CkrScrn1_LabelWidget1);

    CkrScrn1_LabelWidget3 = leLabelWidget_New();
    CkrScrn1_LabelWidget3->fn->setPosition(CkrScrn1_LabelWidget3, 75, 1);
    CkrScrn1_LabelWidget3->fn->setSize(CkrScrn1_LabelWidget3, 72, 30);
    CkrScrn1_LabelWidget3->fn->setScheme(CkrScrn1_LabelWidget3, &BlackTextScheme);
    CkrScrn1_LabelWidget3->fn->setMargins(CkrScrn1_LabelWidget3, 4, 0, 4, 0);
    CkrScrn1_LabelWidget3->fn->setString(CkrScrn1_LabelWidget3, (leString*)&string_Bytes);
    CkrScrn1_Badge->fn->addChild(CkrScrn1_Badge, (leWidget*)CkrScrn1_LabelWidget3);

    CkrScrn1_LabelWidget0 = leLabelWidget_New();
    CkrScrn1_LabelWidget0->fn->setPosition(CkrScrn1_LabelWidget0, 3, -1);
    CkrScrn1_LabelWidget0->fn->setSize(CkrScrn1_LabelWidget0, 75, 30);
    CkrScrn1_LabelWidget0->fn->setScheme(CkrScrn1_LabelWidget0, &WhiteTextScheme);
    CkrScrn1_LabelWidget0->fn->setBackgroundType(CkrScrn1_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_LabelWidget0->fn->setString(CkrScrn1_LabelWidget0, (leString*)&string_GoodBytes);
    CkrScrn1_Badge->fn->addChild(CkrScrn1_Badge, (leWidget*)CkrScrn1_LabelWidget0);

    CkrScrn1_ClockPanel = leWidget_New();
    CkrScrn1_ClockPanel->fn->setPosition(CkrScrn1_ClockPanel, 271, 43);
    CkrScrn1_ClockPanel->fn->setSize(CkrScrn1_ClockPanel, 189, 60);
    CkrScrn1_ClockPanel->fn->setBackgroundType(CkrScrn1_ClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ClockPanel);

    CkrScrn1_HourLabel = leLabelWidget_New();
    CkrScrn1_HourLabel->fn->setPosition(CkrScrn1_HourLabel, -12, 3);
    CkrScrn1_HourLabel->fn->setSize(CkrScrn1_HourLabel, 90, 55);
    CkrScrn1_HourLabel->fn->setScheme(CkrScrn1_HourLabel, &WhiteTextScheme);
    CkrScrn1_HourLabel->fn->setBackgroundType(CkrScrn1_HourLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_HourLabel->fn->setHAlignment(CkrScrn1_HourLabel, LE_HALIGN_CENTER);
    CkrScrn1_HourLabel->fn->setString(CkrScrn1_HourLabel, (leString*)&string_DefaultHour);
    CkrScrn1_ClockPanel->fn->addChild(CkrScrn1_ClockPanel, (leWidget*)CkrScrn1_HourLabel);

    CkrScrn1_ImageWidget6 = leImageWidget_New();
    CkrScrn1_ImageWidget6->fn->setPosition(CkrScrn1_ImageWidget6, 156, 31);
    CkrScrn1_ImageWidget6->fn->setSize(CkrScrn1_ImageWidget6, 28, 24);
    CkrScrn1_ImageWidget6->fn->setBackgroundType(CkrScrn1_ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget6->fn->setBorderType(CkrScrn1_ImageWidget6, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget6->fn->setImage(CkrScrn1_ImageWidget6, (leImage*)&time30);
    CkrScrn1_ClockPanel->fn->addChild(CkrScrn1_ClockPanel, (leWidget*)CkrScrn1_ImageWidget6);

    CkrScrn1_ColonLabel = leLabelWidget_New();
    CkrScrn1_ColonLabel->fn->setPosition(CkrScrn1_ColonLabel, 68, 0);
    CkrScrn1_ColonLabel->fn->setSize(CkrScrn1_ColonLabel, 23, 57);
    CkrScrn1_ColonLabel->fn->setScheme(CkrScrn1_ColonLabel, &WhiteTextScheme);
    CkrScrn1_ColonLabel->fn->setBackgroundType(CkrScrn1_ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ColonLabel->fn->setString(CkrScrn1_ColonLabel, (leString*)&string_Colon);
    CkrScrn1_ClockPanel->fn->addChild(CkrScrn1_ClockPanel, (leWidget*)CkrScrn1_ColonLabel);

    CkrScrn1_MinuteLabel = leLabelWidget_New();
    CkrScrn1_MinuteLabel->fn->setPosition(CkrScrn1_MinuteLabel, 85, 5);
    CkrScrn1_MinuteLabel->fn->setSize(CkrScrn1_MinuteLabel, 80, 55);
    CkrScrn1_MinuteLabel->fn->setScheme(CkrScrn1_MinuteLabel, &WhiteTextScheme);
    CkrScrn1_MinuteLabel->fn->setBackgroundType(CkrScrn1_MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_MinuteLabel->fn->setString(CkrScrn1_MinuteLabel, (leString*)&string_DefaultMinute);
    CkrScrn1_ClockPanel->fn->addChild(CkrScrn1_ClockPanel, (leWidget*)CkrScrn1_MinuteLabel);

    CkrScrn1_ImageWidget8 = leImageWidget_New();
    CkrScrn1_ImageWidget8->fn->setPosition(CkrScrn1_ImageWidget8, 20, 193);
    CkrScrn1_ImageWidget8->fn->setSize(CkrScrn1_ImageWidget8, 80, 80);
    CkrScrn1_ImageWidget8->fn->setScheme(CkrScrn1_ImageWidget8, &BlackBackground);
    CkrScrn1_ImageWidget8->fn->setBorderType(CkrScrn1_ImageWidget8, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget8->fn->setImage(CkrScrn1_ImageWidget8, (leImage*)&hotdog70);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget8);

    CkrScrn1_PanelWidget0 = leWidget_New();
    CkrScrn1_PanelWidget0->fn->setPosition(CkrScrn1_PanelWidget0, 480, 102);
    CkrScrn1_PanelWidget0->fn->setSize(CkrScrn1_PanelWidget0, 480, 218);
    CkrScrn1_PanelWidget0->fn->setScheme(CkrScrn1_PanelWidget0, &BlackBackground);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_PanelWidget0);

    CkrScrn1_ImageWidget0 = leImageWidget_New();
    CkrScrn1_ImageWidget0->fn->setPosition(CkrScrn1_ImageWidget0, 30, 0);
    CkrScrn1_ImageWidget0->fn->setSize(CkrScrn1_ImageWidget0, 415, 218);
    CkrScrn1_ImageWidget0->fn->setScheme(CkrScrn1_ImageWidget0, &BlackBackground);
    CkrScrn1_ImageWidget0->fn->setBackgroundType(CkrScrn1_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget0->fn->setBorderType(CkrScrn1_ImageWidget0, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget0->fn->setImage(CkrScrn1_ImageWidget0, (leImage*)&main_rect);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_ImageWidget0);

    CkrScrn1_ProgressBarWidget0 = leProgressBarWidget_New();
    CkrScrn1_ProgressBarWidget0->fn->setPosition(CkrScrn1_ProgressBarWidget0, 106, 117);
    CkrScrn1_ProgressBarWidget0->fn->setSize(CkrScrn1_ProgressBarWidget0, 276, 15);
    CkrScrn1_ProgressBarWidget0->fn->setScheme(CkrScrn1_ProgressBarWidget0, &ProgressBarScheme);
    CkrScrn1_ProgressBarWidget0->fn->setBorderType(CkrScrn1_ProgressBarWidget0, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ProgressBarWidget0->fn->setValue(CkrScrn1_ProgressBarWidget0, 50);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_ProgressBarWidget0);

    CkrScrn1_ModeImageWidget = leImageWidget_New();
    CkrScrn1_ModeImageWidget->fn->setPosition(CkrScrn1_ModeImageWidget, 0, 62);
    CkrScrn1_ModeImageWidget->fn->setScheme(CkrScrn1_ModeImageWidget, &BlackBackground);
    CkrScrn1_ModeImageWidget->fn->setBorderType(CkrScrn1_ModeImageWidget, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ModeImageWidget->fn->setImage(CkrScrn1_ModeImageWidget, (leImage*)&reheat100);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_ModeImageWidget);

    CkrScrn1_RectangleWidget3 = leRectangleWidget_New();
    CkrScrn1_RectangleWidget3->fn->setPosition(CkrScrn1_RectangleWidget3, 36, 8);
    CkrScrn1_RectangleWidget3->fn->setSize(CkrScrn1_RectangleWidget3, 30, 200);
    CkrScrn1_RectangleWidget3->fn->setVisible(CkrScrn1_RectangleWidget3, LE_FALSE);
    CkrScrn1_RectangleWidget3->fn->setScheme(CkrScrn1_RectangleWidget3, &BlackBackground);
    CkrScrn1_RectangleWidget3->fn->setBorderType(CkrScrn1_RectangleWidget3, LE_WIDGET_BORDER_NONE);
    CkrScrn1_RectangleWidget3->fn->setThickness(CkrScrn1_RectangleWidget3, 0);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_RectangleWidget3);

    CkrScrn1_RectangleWidget2 = leRectangleWidget_New();
    CkrScrn1_RectangleWidget2->fn->setPosition(CkrScrn1_RectangleWidget2, 406, 8);
    CkrScrn1_RectangleWidget2->fn->setSize(CkrScrn1_RectangleWidget2, 33, 200);
    CkrScrn1_RectangleWidget2->fn->setVisible(CkrScrn1_RectangleWidget2, LE_FALSE);
    CkrScrn1_RectangleWidget2->fn->setScheme(CkrScrn1_RectangleWidget2, &BlackBackground);
    CkrScrn1_RectangleWidget2->fn->setBorderType(CkrScrn1_RectangleWidget2, LE_WIDGET_BORDER_NONE);
    CkrScrn1_RectangleWidget2->fn->setThickness(CkrScrn1_RectangleWidget2, 0);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_RectangleWidget2);

    CkrScrn1_RectangleWidget1 = leRectangleWidget_New();
    CkrScrn1_RectangleWidget1->fn->setPosition(CkrScrn1_RectangleWidget1, 66, 199);
    CkrScrn1_RectangleWidget1->fn->setSize(CkrScrn1_RectangleWidget1, 340, 9);
    CkrScrn1_RectangleWidget1->fn->setVisible(CkrScrn1_RectangleWidget1, LE_FALSE);
    CkrScrn1_RectangleWidget1->fn->setScheme(CkrScrn1_RectangleWidget1, &BlackBackground);
    CkrScrn1_RectangleWidget1->fn->setBorderType(CkrScrn1_RectangleWidget1, LE_WIDGET_BORDER_NONE);
    CkrScrn1_RectangleWidget1->fn->setThickness(CkrScrn1_RectangleWidget1, 0);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_RectangleWidget1);

    CkrScrn1_RectangleWidget0 = leRectangleWidget_New();
    CkrScrn1_RectangleWidget0->fn->setPosition(CkrScrn1_RectangleWidget0, 66, 8);
    CkrScrn1_RectangleWidget0->fn->setSize(CkrScrn1_RectangleWidget0, 340, 9);
    CkrScrn1_RectangleWidget0->fn->setVisible(CkrScrn1_RectangleWidget0, LE_FALSE);
    CkrScrn1_RectangleWidget0->fn->setScheme(CkrScrn1_RectangleWidget0, &BlackBackground);
    CkrScrn1_RectangleWidget0->fn->setBorderType(CkrScrn1_RectangleWidget0, LE_WIDGET_BORDER_NONE);
    CkrScrn1_RectangleWidget0->fn->setThickness(CkrScrn1_RectangleWidget0, 0);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_RectangleWidget0);

    CkrScrn1_CookTimeLabel = leLabelWidget_New();
    CkrScrn1_CookTimeLabel->fn->setPosition(CkrScrn1_CookTimeLabel, 149, 29);
    CkrScrn1_CookTimeLabel->fn->setSize(CkrScrn1_CookTimeLabel, 189, 64);
    CkrScrn1_CookTimeLabel->fn->setScheme(CkrScrn1_CookTimeLabel, &WhiteTextScheme);
    CkrScrn1_CookTimeLabel->fn->setBackgroundType(CkrScrn1_CookTimeLabel, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_CookTimeLabel->fn->setHAlignment(CkrScrn1_CookTimeLabel, LE_HALIGN_CENTER);
    CkrScrn1_CookTimeLabel->fn->setString(CkrScrn1_CookTimeLabel, (leString*)&string_DefaultCookTime);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_CookTimeLabel);

    CkrScrn1_RestartButton = leButtonWidget_New();
    CkrScrn1_RestartButton->fn->setPosition(CkrScrn1_RestartButton, 0, 62);
    CkrScrn1_RestartButton->fn->setSize(CkrScrn1_RestartButton, 100, 100);
    CkrScrn1_RestartButton->fn->setBackgroundType(CkrScrn1_RestartButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_RestartButton->fn->setBorderType(CkrScrn1_RestartButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_RestartButton->fn->setToggleable(CkrScrn1_RestartButton, LE_TRUE);
    CkrScrn1_RestartButton->fn->setPressedOffset(CkrScrn1_RestartButton, 0);
    CkrScrn1_RestartButton->fn->setReleasedEventCallback(CkrScrn1_RestartButton, event_CkrScrn1_RestartButton_OnReleased);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_RestartButton);

    CkrScrn1_SliderButton0 = leButtonWidget_New();
    CkrScrn1_SliderButton0->fn->setPosition(CkrScrn1_SliderButton0, 106, 88);
    CkrScrn1_SliderButton0->fn->setSize(CkrScrn1_SliderButton0, 276, 70);
    CkrScrn1_SliderButton0->fn->setBackgroundType(CkrScrn1_SliderButton0, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_SliderButton0->fn->setBorderType(CkrScrn1_SliderButton0, LE_WIDGET_BORDER_NONE);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_SliderButton0);

    CkrScrn1_CancelButton = leButtonWidget_New();
    CkrScrn1_CancelButton->fn->setPosition(CkrScrn1_CancelButton, 377, 69);
    CkrScrn1_CancelButton->fn->setSize(CkrScrn1_CancelButton, 100, 100);
    CkrScrn1_CancelButton->fn->setBackgroundType(CkrScrn1_CancelButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_CancelButton->fn->setBorderType(CkrScrn1_CancelButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_CancelButton->fn->setPressedImage(CkrScrn1_CancelButton, (leImage*)&cancel_80);
    CkrScrn1_CancelButton->fn->setReleasedImage(CkrScrn1_CancelButton, (leImage*)&cancel_80);
    CkrScrn1_CancelButton->fn->setReleasedEventCallback(CkrScrn1_CancelButton, event_CkrScrn1_CancelButton_OnReleased);
    CkrScrn1_PanelWidget0->fn->addChild(CkrScrn1_PanelWidget0, (leWidget*)CkrScrn1_CancelButton);

    CkrScrn1_ButtonWidget0 = leButtonWidget_New();
    CkrScrn1_ButtonWidget0->fn->setPosition(CkrScrn1_ButtonWidget0, 295, 0);
    CkrScrn1_ButtonWidget0->fn->setSize(CkrScrn1_ButtonWidget0, 106, 30);
    CkrScrn1_ButtonWidget0->fn->setBackgroundType(CkrScrn1_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ButtonWidget0->fn->setBorderType(CkrScrn1_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ButtonWidget0->fn->setPressedImage(CkrScrn1_ButtonWidget0, (leImage*)&rgbsmall);
    CkrScrn1_ButtonWidget0->fn->setReleasedImage(CkrScrn1_ButtonWidget0, (leImage*)&rgbsmall);
    CkrScrn1_ButtonWidget0->fn->setReleasedEventCallback(CkrScrn1_ButtonWidget0, event_CkrScrn1_ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ButtonWidget0);

    CkrScrn1_DemoModeOnButton = leButtonWidget_New();
    CkrScrn1_DemoModeOnButton->fn->setPosition(CkrScrn1_DemoModeOnButton, 151, 0);
    CkrScrn1_DemoModeOnButton->fn->setSize(CkrScrn1_DemoModeOnButton, 142, 35);
    CkrScrn1_DemoModeOnButton->fn->setVisible(CkrScrn1_DemoModeOnButton, LE_FALSE);
    CkrScrn1_DemoModeOnButton->fn->setBackgroundType(CkrScrn1_DemoModeOnButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_DemoModeOnButton->fn->setBorderType(CkrScrn1_DemoModeOnButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_DemoModeOnButton->fn->setPressedImage(CkrScrn1_DemoModeOnButton, (leImage*)&DemoOff);
    CkrScrn1_DemoModeOnButton->fn->setReleasedImage(CkrScrn1_DemoModeOnButton, (leImage*)&DemoOn);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_DemoModeOnButton);

    CkrScrn1_ImageWidget7 = leImageWidget_New();
    CkrScrn1_ImageWidget7->fn->setPosition(CkrScrn1_ImageWidget7, 400, 0);
    CkrScrn1_ImageWidget7->fn->setSize(CkrScrn1_ImageWidget7, 80, 40);
    CkrScrn1_ImageWidget7->fn->setScheme(CkrScrn1_ImageWidget7, &PlayerVolScheme);
    CkrScrn1_ImageWidget7->fn->setBorderType(CkrScrn1_ImageWidget7, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget7->fn->setImage(CkrScrn1_ImageWidget7, (leImage*)&Home565Gray);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget7);

    CkrScrn1_HomeButton = leButtonWidget_New();
    CkrScrn1_HomeButton->fn->setPosition(CkrScrn1_HomeButton, 400, 0);
    CkrScrn1_HomeButton->fn->setSize(CkrScrn1_HomeButton, 80, 50);
    CkrScrn1_HomeButton->fn->setScheme(CkrScrn1_HomeButton, &PlayerVolScheme);
    CkrScrn1_HomeButton->fn->setBackgroundType(CkrScrn1_HomeButton, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_HomeButton->fn->setBorderType(CkrScrn1_HomeButton, LE_WIDGET_BORDER_NONE);
    CkrScrn1_HomeButton->fn->setPressedEventCallback(CkrScrn1_HomeButton, event_CkrScrn1_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_HomeButton);

    CkrScrn1_ImageWidget5 = leImageWidget_New();
    CkrScrn1_ImageWidget5->fn->setPosition(CkrScrn1_ImageWidget5, 1, 2);
    CkrScrn1_ImageWidget5->fn->setSize(CkrScrn1_ImageWidget5, 127, 32);
    CkrScrn1_ImageWidget5->fn->setBackgroundType(CkrScrn1_ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    CkrScrn1_ImageWidget5->fn->setBorderType(CkrScrn1_ImageWidget5, LE_WIDGET_BORDER_NONE);
    CkrScrn1_ImageWidget5->fn->setImage(CkrScrn1_ImageWidget5, (leImage*)&mchp_black);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_ImageWidget5);

    CkrScrn1_FPSLabel = leLabelWidget_New();
    CkrScrn1_FPSLabel->fn->setPosition(CkrScrn1_FPSLabel, 188, 2);
    CkrScrn1_FPSLabel->fn->setSize(CkrScrn1_FPSLabel, 120, 25);
    CkrScrn1_FPSLabel->fn->setScheme(CkrScrn1_FPSLabel, &WhiteTextScheme);
    root0->fn->addChild(root0, (leWidget*)CkrScrn1_FPSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    CkrScrn1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_CkrScrn1(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    CkrScrn1_OnUpdate(); // raise event
}

void screenHide_CkrScrn1(void)
{
    CkrScrn1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    CkrScrn1_PanelWidget1 = NULL;
    CkrScrn1_ImageWidget1 = NULL;
    CkrScrn1_PanelWidget3 = NULL;
    CkrScrn1_MainPanel = NULL;
    CkrScrn1_ImageWidget2 = NULL;
    CkrScrn1_ImageWidget3 = NULL;
    CkrScrn1_ImageWidget4 = NULL;
    CkrScrn1_Badge = NULL;
    CkrScrn1_ClockPanel = NULL;
    CkrScrn1_ImageWidget8 = NULL;
    CkrScrn1_PanelWidget0 = NULL;
    CkrScrn1_ButtonWidget0 = NULL;
    CkrScrn1_DemoModeOnButton = NULL;
    CkrScrn1_ImageWidget7 = NULL;
    CkrScrn1_HomeButton = NULL;
    CkrScrn1_ImageWidget5 = NULL;
    CkrScrn1_FPSLabel = NULL;
    CkrScrn1_ListWheelWidget2 = NULL;
    CkrScrn1_ReheatButton = NULL;
    CkrScrn1_BroilButton = NULL;
    CkrScrn1_CookButton = NULL;
    CkrScrn1_BakeButton = NULL;
    CkrScrn1_LabelWidget1 = NULL;
    CkrScrn1_LabelWidget3 = NULL;
    CkrScrn1_LabelWidget0 = NULL;
    CkrScrn1_HourLabel = NULL;
    CkrScrn1_ImageWidget6 = NULL;
    CkrScrn1_ColonLabel = NULL;
    CkrScrn1_MinuteLabel = NULL;
    CkrScrn1_ImageWidget0 = NULL;
    CkrScrn1_ProgressBarWidget0 = NULL;
    CkrScrn1_ModeImageWidget = NULL;
    CkrScrn1_RectangleWidget3 = NULL;
    CkrScrn1_RectangleWidget2 = NULL;
    CkrScrn1_RectangleWidget1 = NULL;
    CkrScrn1_RectangleWidget0 = NULL;
    CkrScrn1_CookTimeLabel = NULL;
    CkrScrn1_RestartButton = NULL;
    CkrScrn1_SliderButton0 = NULL;
    CkrScrn1_CancelButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_CkrScrn1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_CkrScrn1(uint32_t lyrIdx)
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

