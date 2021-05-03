#include "gfx/legato/generated/screen/le_gen_screen_Info.h"

// screen member widget declarations
leWidget* root0;

leWidget* Info_PanelWidget0;
leButtonWidget* Info_HomeButton;
leLabelWidget* Info_InfoPageTitleLabel;
leWidget* Info_MenuPanelWidget;
leImageSequenceWidget* Info_IgatImageSequence;
leWidget* Info_BoardViewPanel;
leWidget* Info_MCUPanel;
leWidget* Info_SAME5xScrollPanel;
leWidget* Info_ResourcesPanel;
leWidget* Info_SoftwarePanel;
leLabelWidget* Info_FPSLabel;
leImageWidget* Info_ImageWidget0;
leButtonWidget* Info_ReferencesButton;
leButtonWidget* Info_SoftwareButton;
leButtonWidget* Info_HardwareButton;
leButtonWidget* Info_MCUButton;
leLabelWidget* Info_ReferencesLabel;
leLabelWidget* Info_SWLabel;
leLabelWidget* Info_HWLabel;
leLabelWidget* Info_MCULabel;
leImageSequenceWidget* Info_BoardViewImageSequence;
leLabelWidget* Info_HWF_DisplayInfoFront;
leImageWidget* Info_SAME51;
leWidget* Info_SAME5xInfoPanel;
leLabelWidget* Info_LabelWidget0;
leImageWidget* Info_ImageWidget1;
leImageWidget* Info_ImageWidget2;
leImageWidget* Info_SAME5xDetailedImage;
leButtonWidget* Info_ButtonWidget0;
leButtonWidget* Info_ButtonWidget1;
leButtonWidget* Info_ButtonWidget2;
leButtonWidget* Info_ButtonWidget3;
leButtonWidget* Info_ButtonWidget4;
leLabelWidget* Info_LabelWidget1;
leListWheelWidget* Info_ListWheelWidget0;
leLineWidget* Info_LineWidget0;
leLabelWidget* Info_SWModuleTitle;
leLabelWidget* Info_SWModuleDesc;
leWidget* Info_RedBarPanel;
leImageWidget* Info_MHGSDiagramImage;
leImageWidget* Info_MH3IconsImage;
leImageWidget* Info_TouchIconsImage;
leButtonWidget* Info_SWUpButton;
leButtonWidget* Info_SWDownButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Info(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Info(void)
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

    Info_PanelWidget0 = leWidget_New();
    Info_PanelWidget0->fn->setPosition(Info_PanelWidget0, 0, 0);
    Info_PanelWidget0->fn->setSize(Info_PanelWidget0, 480, 320);
    Info_PanelWidget0->fn->setScheme(Info_PanelWidget0, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Info_PanelWidget0);

    Info_HomeButton = leButtonWidget_New();
    Info_HomeButton->fn->setPosition(Info_HomeButton, 372, 0);
    Info_HomeButton->fn->setSize(Info_HomeButton, 108, 54);
    Info_HomeButton->fn->setScheme(Info_HomeButton, &PlayerVolScheme);
    Info_HomeButton->fn->setBackgroundType(Info_HomeButton, LE_WIDGET_BACKGROUND_NONE);
    Info_HomeButton->fn->setBorderType(Info_HomeButton, LE_WIDGET_BORDER_NONE);
    Info_HomeButton->fn->setPressedImage(Info_HomeButton, (leImage*)&Button100x80);
    Info_HomeButton->fn->setReleasedImage(Info_HomeButton, (leImage*)&Button100x80);
    Info_HomeButton->fn->setPressedEventCallback(Info_HomeButton, event_Info_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Info_HomeButton);

    Info_ImageWidget0 = leImageWidget_New();
    Info_ImageWidget0->fn->setPosition(Info_ImageWidget0, 31, 7);
    Info_ImageWidget0->fn->setSize(Info_ImageWidget0, 45, 40);
    Info_ImageWidget0->fn->setEnabled(Info_ImageWidget0, LE_FALSE);
    Info_ImageWidget0->fn->setBackgroundType(Info_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Info_ImageWidget0->fn->setBorderType(Info_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Info_ImageWidget0->fn->setImage(Info_ImageWidget0, (leImage*)&Home565Gray);
    Info_HomeButton->fn->addChild(Info_HomeButton, (leWidget*)Info_ImageWidget0);

    Info_InfoPageTitleLabel = leLabelWidget_New();
    Info_InfoPageTitleLabel->fn->setPosition(Info_InfoPageTitleLabel, 14, 7);
    Info_InfoPageTitleLabel->fn->setSize(Info_InfoPageTitleLabel, 327, 39);
    Info_InfoPageTitleLabel->fn->setScheme(Info_InfoPageTitleLabel, &BlackTextScheme);
    Info_InfoPageTitleLabel->fn->setBackgroundType(Info_InfoPageTitleLabel, LE_WIDGET_BACKGROUND_NONE);
    Info_InfoPageTitleLabel->fn->setString(Info_InfoPageTitleLabel, (leString*)&string_IgatTitle);
    root0->fn->addChild(root0, (leWidget*)Info_InfoPageTitleLabel);

    Info_MenuPanelWidget = leWidget_New();
    Info_MenuPanelWidget->fn->setPosition(Info_MenuPanelWidget, 6, 69);
    Info_MenuPanelWidget->fn->setSize(Info_MenuPanelWidget, 180, 235);
    Info_MenuPanelWidget->fn->setBackgroundType(Info_MenuPanelWidget, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_MenuPanelWidget);

    Info_ReferencesButton = leButtonWidget_New();
    Info_ReferencesButton->fn->setPosition(Info_ReferencesButton, 0, 181);
    Info_ReferencesButton->fn->setSize(Info_ReferencesButton, 180, 50);
    Info_ReferencesButton->fn->setBackgroundType(Info_ReferencesButton, LE_WIDGET_BACKGROUND_NONE);
    Info_ReferencesButton->fn->setBorderType(Info_ReferencesButton, LE_WIDGET_BORDER_NONE);
    Info_ReferencesButton->fn->setPressedImage(Info_ReferencesButton, (leImage*)&Button150x80_pressed);
    Info_ReferencesButton->fn->setReleasedImage(Info_ReferencesButton, (leImage*)&Button150x80);
    Info_ReferencesButton->fn->setReleasedEventCallback(Info_ReferencesButton, event_Info_ReferencesButton_OnReleased);
    Info_MenuPanelWidget->fn->addChild(Info_MenuPanelWidget, (leWidget*)Info_ReferencesButton);

    Info_ReferencesLabel = leLabelWidget_New();
    Info_ReferencesLabel->fn->setPosition(Info_ReferencesLabel, 18, 12);
    Info_ReferencesLabel->fn->setSize(Info_ReferencesLabel, 148, 31);
    Info_ReferencesLabel->fn->setEnabled(Info_ReferencesLabel, LE_FALSE);
    Info_ReferencesLabel->fn->setScheme(Info_ReferencesLabel, &InfoPageScheme);
    Info_ReferencesLabel->fn->setBackgroundType(Info_ReferencesLabel, LE_WIDGET_BACKGROUND_NONE);
    Info_ReferencesLabel->fn->setHAlignment(Info_ReferencesLabel, LE_HALIGN_CENTER);
    Info_ReferencesLabel->fn->setString(Info_ReferencesLabel, (leString*)&string_References);
    Info_ReferencesButton->fn->addChild(Info_ReferencesButton, (leWidget*)Info_ReferencesLabel);

    Info_SoftwareButton = leButtonWidget_New();
    Info_SoftwareButton->fn->setPosition(Info_SoftwareButton, 0, 123);
    Info_SoftwareButton->fn->setSize(Info_SoftwareButton, 180, 50);
    Info_SoftwareButton->fn->setScheme(Info_SoftwareButton, &InfoPageScheme);
    Info_SoftwareButton->fn->setBackgroundType(Info_SoftwareButton, LE_WIDGET_BACKGROUND_NONE);
    Info_SoftwareButton->fn->setBorderType(Info_SoftwareButton, LE_WIDGET_BORDER_NONE);
    Info_SoftwareButton->fn->setPressedImage(Info_SoftwareButton, (leImage*)&Button150x80_pressed);
    Info_SoftwareButton->fn->setReleasedImage(Info_SoftwareButton, (leImage*)&Button150x80);
    Info_SoftwareButton->fn->setReleasedEventCallback(Info_SoftwareButton, event_Info_SoftwareButton_OnReleased);
    Info_MenuPanelWidget->fn->addChild(Info_MenuPanelWidget, (leWidget*)Info_SoftwareButton);

    Info_SWLabel = leLabelWidget_New();
    Info_SWLabel->fn->setPosition(Info_SWLabel, 52, 12);
    Info_SWLabel->fn->setSize(Info_SWLabel, 81, 25);
    Info_SWLabel->fn->setEnabled(Info_SWLabel, LE_FALSE);
    Info_SWLabel->fn->setScheme(Info_SWLabel, &InfoPageScheme);
    Info_SWLabel->fn->setBackgroundType(Info_SWLabel, LE_WIDGET_BACKGROUND_NONE);
    Info_SWLabel->fn->setString(Info_SWLabel, (leString*)&string_Software);
    Info_SoftwareButton->fn->addChild(Info_SoftwareButton, (leWidget*)Info_SWLabel);

    Info_HardwareButton = leButtonWidget_New();
    Info_HardwareButton->fn->setPosition(Info_HardwareButton, 0, 64);
    Info_HardwareButton->fn->setSize(Info_HardwareButton, 180, 50);
    Info_HardwareButton->fn->setScheme(Info_HardwareButton, &InfoPageScheme);
    Info_HardwareButton->fn->setBackgroundType(Info_HardwareButton, LE_WIDGET_BACKGROUND_NONE);
    Info_HardwareButton->fn->setBorderType(Info_HardwareButton, LE_WIDGET_BORDER_NONE);
    Info_HardwareButton->fn->setPressedImage(Info_HardwareButton, (leImage*)&Button150x80_pressed);
    Info_HardwareButton->fn->setReleasedImage(Info_HardwareButton, (leImage*)&Button150x80);
    Info_HardwareButton->fn->setReleasedEventCallback(Info_HardwareButton, event_Info_HardwareButton_OnReleased);
    Info_MenuPanelWidget->fn->addChild(Info_MenuPanelWidget, (leWidget*)Info_HardwareButton);

    Info_HWLabel = leLabelWidget_New();
    Info_HWLabel->fn->setPosition(Info_HWLabel, 39, 13);
    Info_HWLabel->fn->setEnabled(Info_HWLabel, LE_FALSE);
    Info_HWLabel->fn->setScheme(Info_HWLabel, &InfoPageScheme);
    Info_HWLabel->fn->setBackgroundType(Info_HWLabel, LE_WIDGET_BACKGROUND_NONE);
    Info_HWLabel->fn->setHAlignment(Info_HWLabel, LE_HALIGN_CENTER);
    Info_HWLabel->fn->setString(Info_HWLabel, (leString*)&string_BoardFeatures);
    Info_HardwareButton->fn->addChild(Info_HardwareButton, (leWidget*)Info_HWLabel);

    Info_MCUButton = leButtonWidget_New();
    Info_MCUButton->fn->setPosition(Info_MCUButton, 0, 5);
    Info_MCUButton->fn->setSize(Info_MCUButton, 180, 50);
    Info_MCUButton->fn->setScheme(Info_MCUButton, &InfoPageScheme);
    Info_MCUButton->fn->setBackgroundType(Info_MCUButton, LE_WIDGET_BACKGROUND_NONE);
    Info_MCUButton->fn->setBorderType(Info_MCUButton, LE_WIDGET_BORDER_NONE);
    Info_MCUButton->fn->setPressedImage(Info_MCUButton, (leImage*)&Button150x80_pressed);
    Info_MCUButton->fn->setReleasedImage(Info_MCUButton, (leImage*)&Button150x80);
    Info_MCUButton->fn->setReleasedEventCallback(Info_MCUButton, event_Info_MCUButton_OnReleased);
    Info_MenuPanelWidget->fn->addChild(Info_MenuPanelWidget, (leWidget*)Info_MCUButton);

    Info_MCULabel = leLabelWidget_New();
    Info_MCULabel->fn->setPosition(Info_MCULabel, 23, 11);
    Info_MCULabel->fn->setSize(Info_MCULabel, 140, 30);
    Info_MCULabel->fn->setEnabled(Info_MCULabel, LE_FALSE);
    Info_MCULabel->fn->setScheme(Info_MCULabel, &InfoPageScheme);
    Info_MCULabel->fn->setBackgroundType(Info_MCULabel, LE_WIDGET_BACKGROUND_NONE);
    Info_MCULabel->fn->setString(Info_MCULabel, (leString*)&string_SAME51);
    Info_MCUButton->fn->addChild(Info_MCUButton, (leWidget*)Info_MCULabel);

    Info_IgatImageSequence = leImageSequenceWidget_New();
    Info_IgatImageSequence->fn->setPosition(Info_IgatImageSequence, 200, 82);
    Info_IgatImageSequence->fn->setSize(Info_IgatImageSequence, 274, 206);
    Info_IgatImageSequence->fn->setBackgroundType(Info_IgatImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Info_IgatImageSequence->fn->setRepeat(Info_IgatImageSequence, LE_TRUE);
    Info_IgatImageSequence->fn->setImageCount(Info_IgatImageSequence, 4);
    Info_IgatImageSequence->fn->setImage(Info_IgatImageSequence, 0, &IgatFront250);
    Info_IgatImageSequence->fn->setImageDelay(Info_IgatImageSequence, 0, 1000);
    Info_IgatImageSequence->fn->setImage(Info_IgatImageSequence, 1, &MHGC_120x120);
    Info_IgatImageSequence->fn->setImageDelay(Info_IgatImageSequence, 1, 1000);
    Info_IgatImageSequence->fn->setImage(Info_IgatImageSequence, 2, &SAME51);
    Info_IgatImageSequence->fn->setImageDelay(Info_IgatImageSequence, 2, 1000);
    Info_IgatImageSequence->fn->setImage(Info_IgatImageSequence, 3, &mh328);
    Info_IgatImageSequence->fn->setImageDelay(Info_IgatImageSequence, 3, 1000);
    root0->fn->addChild(root0, (leWidget*)Info_IgatImageSequence);

    Info_BoardViewPanel = leWidget_New();
    Info_BoardViewPanel->fn->setPosition(Info_BoardViewPanel, 480, 50);
    Info_BoardViewPanel->fn->setSize(Info_BoardViewPanel, 480, 270);
    Info_BoardViewPanel->fn->setScheme(Info_BoardViewPanel, &WhiteBackgroundScheme);
    Info_BoardViewPanel->fn->setBackgroundType(Info_BoardViewPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_BoardViewPanel);

    Info_BoardViewImageSequence = leImageSequenceWidget_New();
    Info_BoardViewImageSequence->fn->setPosition(Info_BoardViewImageSequence, 168, 29);
    Info_BoardViewImageSequence->fn->setSize(Info_BoardViewImageSequence, 300, 214);
    Info_BoardViewImageSequence->fn->setScheme(Info_BoardViewImageSequence, &BlackBackground);
    Info_BoardViewImageSequence->fn->setBackgroundType(Info_BoardViewImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Info_BoardViewImageSequence->fn->setImageCount(Info_BoardViewImageSequence, 1);
    Info_BoardViewImageSequence->fn->setImage(Info_BoardViewImageSequence, 0, &igat96);
    Info_BoardViewImageSequence->fn->setImageDelay(Info_BoardViewImageSequence, 0, 1000);
    Info_BoardViewPanel->fn->addChild(Info_BoardViewPanel, (leWidget*)Info_BoardViewImageSequence);

    Info_HWF_DisplayInfoFront = leLabelWidget_New();
    Info_HWF_DisplayInfoFront->fn->setPosition(Info_HWF_DisplayInfoFront, 21, 29);
    Info_HWF_DisplayInfoFront->fn->setSize(Info_HWF_DisplayInfoFront, 145, 214);
    Info_HWF_DisplayInfoFront->fn->setScheme(Info_HWF_DisplayInfoFront, &InfoPageScheme);
    Info_HWF_DisplayInfoFront->fn->setVAlignment(Info_HWF_DisplayInfoFront, LE_VALIGN_TOP);
    Info_BoardViewPanel->fn->addChild(Info_BoardViewPanel, (leWidget*)Info_HWF_DisplayInfoFront);

    Info_MCUPanel = leWidget_New();
    Info_MCUPanel->fn->setPosition(Info_MCUPanel, -480, 0);
    Info_MCUPanel->fn->setSize(Info_MCUPanel, 480, 320);
    Info_MCUPanel->fn->setEnabled(Info_MCUPanel, LE_FALSE);
    Info_MCUPanel->fn->setScheme(Info_MCUPanel, &WhiteBackgroundScheme);
    Info_MCUPanel->fn->setBackgroundType(Info_MCUPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_MCUPanel);

    Info_SAME51 = leImageWidget_New();
    Info_SAME51->fn->setPosition(Info_SAME51, 21, 100);
    Info_SAME51->fn->setSize(Info_SAME51, 155, 131);
    Info_SAME51->fn->setBackgroundType(Info_SAME51, LE_WIDGET_BACKGROUND_NONE);
    Info_SAME51->fn->setBorderType(Info_SAME51, LE_WIDGET_BORDER_NONE);
    Info_SAME51->fn->setImage(Info_SAME51, (leImage*)&SAME51);
    Info_MCUPanel->fn->addChild(Info_MCUPanel, (leWidget*)Info_SAME51);

    Info_SAME5xInfoPanel = leWidget_New();
    Info_SAME5xInfoPanel->fn->setPosition(Info_SAME5xInfoPanel, 180, 68);
    Info_SAME5xInfoPanel->fn->setSize(Info_SAME5xInfoPanel, 300, 215);
    Info_SAME5xInfoPanel->fn->setBackgroundType(Info_SAME5xInfoPanel, LE_WIDGET_BACKGROUND_NONE);
    Info_MCUPanel->fn->addChild(Info_MCUPanel, (leWidget*)Info_SAME5xInfoPanel);

    Info_SAME5xDetailedImage = leImageWidget_New();
    Info_SAME5xDetailedImage->fn->setPosition(Info_SAME5xDetailedImage, 0, 0);
    Info_SAME5xDetailedImage->fn->setSize(Info_SAME5xDetailedImage, 296, 426);
    Info_SAME5xDetailedImage->fn->setBackgroundType(Info_SAME5xDetailedImage, LE_WIDGET_BACKGROUND_NONE);
    Info_SAME5xDetailedImage->fn->setBorderType(Info_SAME5xDetailedImage, LE_WIDGET_BORDER_NONE);
    Info_SAME5xDetailedImage->fn->setHAlignment(Info_SAME5xDetailedImage, LE_HALIGN_LEFT);
    Info_SAME5xDetailedImage->fn->setVAlignment(Info_SAME5xDetailedImage, LE_VALIGN_TOP);
    Info_SAME5xDetailedImage->fn->setMargins(Info_SAME5xDetailedImage, 0, 0, 4, 4);
    Info_SAME5xDetailedImage->fn->setImage(Info_SAME5xDetailedImage, (leImage*)&SAME5xMCU);
    Info_SAME5xInfoPanel->fn->addChild(Info_SAME5xInfoPanel, (leWidget*)Info_SAME5xDetailedImage);

    Info_LabelWidget0 = leLabelWidget_New();
    Info_LabelWidget0->fn->setPosition(Info_LabelWidget0, 30, 63);
    Info_LabelWidget0->fn->setSize(Info_LabelWidget0, 137, 35);
    Info_LabelWidget0->fn->setScheme(Info_LabelWidget0, &BlackTextScheme);
    Info_LabelWidget0->fn->setBackgroundType(Info_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Info_LabelWidget0->fn->setHAlignment(Info_LabelWidget0, LE_HALIGN_CENTER);
    Info_LabelWidget0->fn->setString(Info_LabelWidget0, (leString*)&string_SAME51);
    Info_MCUPanel->fn->addChild(Info_MCUPanel, (leWidget*)Info_LabelWidget0);

    Info_ImageWidget1 = leImageWidget_New();
    Info_ImageWidget1->fn->setPosition(Info_ImageWidget1, 298, 47);
    Info_ImageWidget1->fn->setSize(Info_ImageWidget1, 48, 23);
    Info_ImageWidget1->fn->setBackgroundType(Info_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Info_ImageWidget1->fn->setBorderType(Info_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Info_ImageWidget1->fn->setImage(Info_ImageWidget1, (leImage*)&ArrowUp);
    Info_MCUPanel->fn->addChild(Info_MCUPanel, (leWidget*)Info_ImageWidget1);

    Info_ImageWidget2 = leImageWidget_New();
    Info_ImageWidget2->fn->setPosition(Info_ImageWidget2, 298, 293);
    Info_ImageWidget2->fn->setSize(Info_ImageWidget2, 48, 22);
    Info_ImageWidget2->fn->setBackgroundType(Info_ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    Info_ImageWidget2->fn->setBorderType(Info_ImageWidget2, LE_WIDGET_BORDER_NONE);
    Info_ImageWidget2->fn->setImage(Info_ImageWidget2, (leImage*)&ArrowDown);
    Info_MCUPanel->fn->addChild(Info_MCUPanel, (leWidget*)Info_ImageWidget2);

    Info_SAME5xScrollPanel = leWidget_New();
    Info_SAME5xScrollPanel->fn->setPosition(Info_SAME5xScrollPanel, 179, 68);
    Info_SAME5xScrollPanel->fn->setSize(Info_SAME5xScrollPanel, 300, 226);
    Info_SAME5xScrollPanel->fn->setBackgroundType(Info_SAME5xScrollPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_SAME5xScrollPanel);

    Info_ResourcesPanel = leWidget_New();
    Info_ResourcesPanel->fn->setPosition(Info_ResourcesPanel, 480, 50);
    Info_ResourcesPanel->fn->setSize(Info_ResourcesPanel, 480, 270);
    Info_ResourcesPanel->fn->setScheme(Info_ResourcesPanel, &WhiteBackgroundScheme);
    Info_ResourcesPanel->fn->setBackgroundType(Info_ResourcesPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_ResourcesPanel);

    Info_ButtonWidget0 = leButtonWidget_New();
    Info_ButtonWidget0->fn->setPosition(Info_ButtonWidget0, 18, 35);
    Info_ButtonWidget0->fn->setSize(Info_ButtonWidget0, 145, 120);
    Info_ButtonWidget0->fn->setBackgroundType(Info_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    Info_ButtonWidget0->fn->setBorderType(Info_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    Info_ButtonWidget0->fn->setToggleable(Info_ButtonWidget0, LE_TRUE);
    Info_ButtonWidget0->fn->setPressedImage(Info_ButtonWidget0, (leImage*)&qr_mh3);
    Info_ButtonWidget0->fn->setReleasedImage(Info_ButtonWidget0, (leImage*)&logo_mh3_100);
    Info_ButtonWidget0->fn->setImagePosition(Info_ButtonWidget0, LE_RELATIVE_POSITION_ABOVE);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_ButtonWidget0);

    Info_ButtonWidget1 = leButtonWidget_New();
    Info_ButtonWidget1->fn->setPosition(Info_ButtonWidget1, 191, 38);
    Info_ButtonWidget1->fn->setSize(Info_ButtonWidget1, 111, 113);
    Info_ButtonWidget1->fn->setBackgroundType(Info_ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    Info_ButtonWidget1->fn->setBorderType(Info_ButtonWidget1, LE_WIDGET_BORDER_NONE);
    Info_ButtonWidget1->fn->setToggleable(Info_ButtonWidget1, LE_TRUE);
    Info_ButtonWidget1->fn->setPressedImage(Info_ButtonWidget1, (leImage*)&qr_mhgs);
    Info_ButtonWidget1->fn->setReleasedImage(Info_ButtonWidget1, (leImage*)&logo_mhgs_100);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_ButtonWidget1);

    Info_ButtonWidget2 = leButtonWidget_New();
    Info_ButtonWidget2->fn->setPosition(Info_ButtonWidget2, 116, 156);
    Info_ButtonWidget2->fn->setSize(Info_ButtonWidget2, 114, 108);
    Info_ButtonWidget2->fn->setBackgroundType(Info_ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    Info_ButtonWidget2->fn->setBorderType(Info_ButtonWidget2, LE_WIDGET_BORDER_NONE);
    Info_ButtonWidget2->fn->setToggleable(Info_ButtonWidget2, LE_TRUE);
    Info_ButtonWidget2->fn->setPressedImage(Info_ButtonWidget2, (leImage*)&qr_touch);
    Info_ButtonWidget2->fn->setReleasedImage(Info_ButtonWidget2, (leImage*)&logo_touch_100);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_ButtonWidget2);

    Info_ButtonWidget3 = leButtonWidget_New();
    Info_ButtonWidget3->fn->setPosition(Info_ButtonWidget3, 322, 23);
    Info_ButtonWidget3->fn->setSize(Info_ButtonWidget3, 150, 130);
    Info_ButtonWidget3->fn->setBackgroundType(Info_ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    Info_ButtonWidget3->fn->setBorderType(Info_ButtonWidget3, LE_WIDGET_BORDER_NONE);
    Info_ButtonWidget3->fn->setToggleable(Info_ButtonWidget3, LE_TRUE);
    Info_ButtonWidget3->fn->setPressedImage(Info_ButtonWidget3, (leImage*)&qr_sam5x);
    Info_ButtonWidget3->fn->setReleasedImage(Info_ButtonWidget3, (leImage*)&SAME51);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_ButtonWidget3);

    Info_ButtonWidget4 = leButtonWidget_New();
    Info_ButtonWidget4->fn->setPosition(Info_ButtonWidget4, 267, 154);
    Info_ButtonWidget4->fn->setSize(Info_ButtonWidget4, 135, 110);
    Info_ButtonWidget4->fn->setBackgroundType(Info_ButtonWidget4, LE_WIDGET_BACKGROUND_NONE);
    Info_ButtonWidget4->fn->setBorderType(Info_ButtonWidget4, LE_WIDGET_BORDER_NONE);
    Info_ButtonWidget4->fn->setToggleable(Info_ButtonWidget4, LE_TRUE);
    Info_ButtonWidget4->fn->setPressedImage(Info_ButtonWidget4, (leImage*)&qr_igatprod);
    Info_ButtonWidget4->fn->setReleasedImage(Info_ButtonWidget4, (leImage*)&IgatFront120);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_ButtonWidget4);

    Info_LabelWidget1 = leLabelWidget_New();
    Info_LabelWidget1->fn->setPosition(Info_LabelWidget1, 5, 5);
    Info_LabelWidget1->fn->setSize(Info_LabelWidget1, 175, 30);
    Info_LabelWidget1->fn->setScheme(Info_LabelWidget1, &InfoPageScheme);
    Info_LabelWidget1->fn->setHAlignment(Info_LabelWidget1, LE_HALIGN_CENTER);
    Info_LabelWidget1->fn->setString(Info_LabelWidget1, (leString*)&string_References);
    Info_ResourcesPanel->fn->addChild(Info_ResourcesPanel, (leWidget*)Info_LabelWidget1);

    Info_SoftwarePanel = leWidget_New();
    Info_SoftwarePanel->fn->setPosition(Info_SoftwarePanel, 480, 50);
    Info_SoftwarePanel->fn->setSize(Info_SoftwarePanel, 480, 270);
    Info_SoftwarePanel->fn->setScheme(Info_SoftwarePanel, &WhiteBackgroundScheme);
    Info_SoftwarePanel->fn->setBackgroundType(Info_SoftwarePanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_SoftwarePanel);

    Info_ListWheelWidget0 = leListWheelWidget_New();
    Info_ListWheelWidget0->fn->setPosition(Info_ListWheelWidget0, 3, 47);
    Info_ListWheelWidget0->fn->setSize(Info_ListWheelWidget0, 152, 195);
    Info_ListWheelWidget0->fn->setBackgroundType(Info_ListWheelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Info_ListWheelWidget0->fn->setBorderType(Info_ListWheelWidget0, LE_WIDGET_BORDER_NONE);
    Info_ListWheelWidget0->fn->setVisibleItemCount(Info_ListWheelWidget0, 3);
    Info_ListWheelWidget0->fn->setShowIndicators(Info_ListWheelWidget0, LE_FALSE);
    Info_ListWheelWidget0->fn->setIndicatorFill(Info_ListWheelWidget0, LE_LISTWHEEL_INDICATOR_FILL_NONE);
    Info_ListWheelWidget0->fn->setAutoHideWheel(Info_ListWheelWidget0, LE_TRUE);
    Info_ListWheelWidget0->fn->appendItem(Info_ListWheelWidget0);
    Info_ListWheelWidget0->fn->setItemIcon(Info_ListWheelWidget0, 0, &logo_mh3_100);
    Info_ListWheelWidget0->fn->appendItem(Info_ListWheelWidget0);
    Info_ListWheelWidget0->fn->setItemIcon(Info_ListWheelWidget0, 1, &logo_mhgs_100);
    Info_ListWheelWidget0->fn->appendItem(Info_ListWheelWidget0);
    Info_ListWheelWidget0->fn->setItemIcon(Info_ListWheelWidget0, 2, &logo_touch_100);
    Info_ListWheelWidget0->fn->setSelectedItemChangedEventCallback(Info_ListWheelWidget0, event_Info_ListWheelWidget0_OnSelectionChanged);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_ListWheelWidget0);

    Info_LineWidget0 = leLineWidget_New();
    Info_LineWidget0->fn->setPosition(Info_LineWidget0, 158, 10);
    Info_LineWidget0->fn->setSize(Info_LineWidget0, 3, 250);
    Info_LineWidget0->fn->setBackgroundType(Info_LineWidget0, LE_WIDGET_BACKGROUND_NONE);
    Info_LineWidget0->fn->setStartPoint(Info_LineWidget0, 1, 0);
    Info_LineWidget0->fn->setEndPoint(Info_LineWidget0, 1, 250);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_LineWidget0);

    Info_SWModuleTitle = leLabelWidget_New();
    Info_SWModuleTitle->fn->setPosition(Info_SWModuleTitle, 165, 8);
    Info_SWModuleTitle->fn->setSize(Info_SWModuleTitle, 305, 35);
    Info_SWModuleTitle->fn->setScheme(Info_SWModuleTitle, &InfoPageScheme);
    Info_SWModuleTitle->fn->setHAlignment(Info_SWModuleTitle, LE_HALIGN_CENTER);
    Info_SWModuleTitle->fn->setString(Info_SWModuleTitle, (leString*)&string_MH3_Touch);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_SWModuleTitle);

    Info_SWModuleDesc = leLabelWidget_New();
    Info_SWModuleDesc->fn->setPosition(Info_SWModuleDesc, 165, 55);
    Info_SWModuleDesc->fn->setSize(Info_SWModuleDesc, 305, 200);
    Info_SWModuleDesc->fn->setVAlignment(Info_SWModuleDesc, LE_VALIGN_TOP);
    Info_SWModuleDesc->fn->setMargins(Info_SWModuleDesc, 8, 8, 4, 4);
    Info_SWModuleDesc->fn->setString(Info_SWModuleDesc, (leString*)&string_MH3_Touch_Desc);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_SWModuleDesc);

    Info_RedBarPanel = leWidget_New();
    Info_RedBarPanel->fn->setPosition(Info_RedBarPanel, 165, 46);
    Info_RedBarPanel->fn->setSize(Info_RedBarPanel, 305, 5);
    Info_RedBarPanel->fn->setScheme(Info_RedBarPanel, &Button3Scheme);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_RedBarPanel);

    Info_MHGSDiagramImage = leImageWidget_New();
    Info_MHGSDiagramImage->fn->setPosition(Info_MHGSDiagramImage, 168, 111);
    Info_MHGSDiagramImage->fn->setSize(Info_MHGSDiagramImage, 300, 131);
    Info_MHGSDiagramImage->fn->setVisible(Info_MHGSDiagramImage, LE_FALSE);
    Info_MHGSDiagramImage->fn->setBackgroundType(Info_MHGSDiagramImage, LE_WIDGET_BACKGROUND_NONE);
    Info_MHGSDiagramImage->fn->setBorderType(Info_MHGSDiagramImage, LE_WIDGET_BORDER_NONE);
    Info_MHGSDiagramImage->fn->setImage(Info_MHGSDiagramImage, (leImage*)&MHGS_Diagram);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_MHGSDiagramImage);

    Info_MH3IconsImage = leImageWidget_New();
    Info_MH3IconsImage->fn->setPosition(Info_MH3IconsImage, 181, 103);
    Info_MH3IconsImage->fn->setSize(Info_MH3IconsImage, 278, 140);
    Info_MH3IconsImage->fn->setBackgroundType(Info_MH3IconsImage, LE_WIDGET_BACKGROUND_NONE);
    Info_MH3IconsImage->fn->setBorderType(Info_MH3IconsImage, LE_WIDGET_BORDER_NONE);
    Info_MH3IconsImage->fn->setImage(Info_MH3IconsImage, (leImage*)&MH3_icons);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_MH3IconsImage);

    Info_TouchIconsImage = leImageWidget_New();
    Info_TouchIconsImage->fn->setPosition(Info_TouchIconsImage, 168, 164);
    Info_TouchIconsImage->fn->setSize(Info_TouchIconsImage, 300, 92);
    Info_TouchIconsImage->fn->setBackgroundType(Info_TouchIconsImage, LE_WIDGET_BACKGROUND_NONE);
    Info_TouchIconsImage->fn->setBorderType(Info_TouchIconsImage, LE_WIDGET_BORDER_NONE);
    Info_TouchIconsImage->fn->setImage(Info_TouchIconsImage, (leImage*)&TouchIcons);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_TouchIconsImage);

    Info_SWUpButton = leButtonWidget_New();
    Info_SWUpButton->fn->setPosition(Info_SWUpButton, 5, 19);
    Info_SWUpButton->fn->setSize(Info_SWUpButton, 150, 40);
    Info_SWUpButton->fn->setBackgroundType(Info_SWUpButton, LE_WIDGET_BACKGROUND_NONE);
    Info_SWUpButton->fn->setBorderType(Info_SWUpButton, LE_WIDGET_BORDER_NONE);
    Info_SWUpButton->fn->setVAlignment(Info_SWUpButton, LE_VALIGN_TOP);
    Info_SWUpButton->fn->setPressedImage(Info_SWUpButton, (leImage*)&ArrowUp);
    Info_SWUpButton->fn->setReleasedImage(Info_SWUpButton, (leImage*)&ArrowUp);
    Info_SWUpButton->fn->setPressedEventCallback(Info_SWUpButton, event_Info_SWUpButton_OnPressed);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_SWUpButton);

    Info_SWDownButton = leButtonWidget_New();
    Info_SWDownButton->fn->setPosition(Info_SWDownButton, 5, 226);
    Info_SWDownButton->fn->setSize(Info_SWDownButton, 150, 40);
    Info_SWDownButton->fn->setBackgroundType(Info_SWDownButton, LE_WIDGET_BACKGROUND_NONE);
    Info_SWDownButton->fn->setBorderType(Info_SWDownButton, LE_WIDGET_BORDER_NONE);
    Info_SWDownButton->fn->setVAlignment(Info_SWDownButton, LE_VALIGN_BOTTOM);
    Info_SWDownButton->fn->setPressedImage(Info_SWDownButton, (leImage*)&ArrowDown);
    Info_SWDownButton->fn->setReleasedImage(Info_SWDownButton, (leImage*)&ArrowDown);
    Info_SWDownButton->fn->setPressedEventCallback(Info_SWDownButton, event_Info_SWDownButton_OnPressed);
    Info_SoftwarePanel->fn->addChild(Info_SoftwarePanel, (leWidget*)Info_SWDownButton);

    Info_FPSLabel = leLabelWidget_New();
    Info_FPSLabel->fn->setPosition(Info_FPSLabel, 406, 305);
    Info_FPSLabel->fn->setSize(Info_FPSLabel, 75, 16);
    Info_FPSLabel->fn->setScheme(Info_FPSLabel, &BlackTextScheme);
    Info_FPSLabel->fn->setBackgroundType(Info_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Info_FPSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Info_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Info(void)
{
    Info_OnUpdate(); // raise event
}

void screenHide_Info(void)
{
    Info_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Info_PanelWidget0 = NULL;
    Info_HomeButton = NULL;
    Info_InfoPageTitleLabel = NULL;
    Info_MenuPanelWidget = NULL;
    Info_IgatImageSequence = NULL;
    Info_BoardViewPanel = NULL;
    Info_MCUPanel = NULL;
    Info_SAME5xScrollPanel = NULL;
    Info_ResourcesPanel = NULL;
    Info_SoftwarePanel = NULL;
    Info_FPSLabel = NULL;
    Info_ImageWidget0 = NULL;
    Info_ReferencesButton = NULL;
    Info_SoftwareButton = NULL;
    Info_HardwareButton = NULL;
    Info_MCUButton = NULL;
    Info_ReferencesLabel = NULL;
    Info_SWLabel = NULL;
    Info_HWLabel = NULL;
    Info_MCULabel = NULL;
    Info_BoardViewImageSequence = NULL;
    Info_HWF_DisplayInfoFront = NULL;
    Info_SAME51 = NULL;
    Info_SAME5xInfoPanel = NULL;
    Info_LabelWidget0 = NULL;
    Info_ImageWidget1 = NULL;
    Info_ImageWidget2 = NULL;
    Info_SAME5xDetailedImage = NULL;
    Info_ButtonWidget0 = NULL;
    Info_ButtonWidget1 = NULL;
    Info_ButtonWidget2 = NULL;
    Info_ButtonWidget3 = NULL;
    Info_ButtonWidget4 = NULL;
    Info_LabelWidget1 = NULL;
    Info_ListWheelWidget0 = NULL;
    Info_LineWidget0 = NULL;
    Info_SWModuleTitle = NULL;
    Info_SWModuleDesc = NULL;
    Info_RedBarPanel = NULL;
    Info_MHGSDiagramImage = NULL;
    Info_MH3IconsImage = NULL;
    Info_TouchIconsImage = NULL;
    Info_SWUpButton = NULL;
    Info_SWDownButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Info(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Info(uint32_t lyrIdx)
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

