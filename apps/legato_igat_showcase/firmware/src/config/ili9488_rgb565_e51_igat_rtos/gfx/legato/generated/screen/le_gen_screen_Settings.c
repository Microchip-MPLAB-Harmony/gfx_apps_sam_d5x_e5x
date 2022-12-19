#include "gfx/legato/generated/screen/le_gen_screen_Settings.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Settings_PanelWidget0;
leLabelWidget* Settings_LabelWidget0;
leButtonWidget* Settings_UpdateSQIButton;
leLabelWidget* Settings_SQIUpdateStatusString;
leButtonWidget* Settings_HomeButton;
leButtonWidget* Settings_ToggleDemoModeButton;
leButtonWidget* Settings_RebootButtonWidget0;
leButtonWidget* Settings_StatsEnableButton;
leLabelWidget* Settings_TimeStampString;
leButtonWidget* Settings_AdvancedGesturesEnable;
leWidget* Settings_ScratchBufferControl;
leLabelWidget* Settings_SQIUpdateWarningLabel;
leLabelWidget* Settings_SLALabel;
leLabelWidget* Settings_DemoModeStatusString;
leLabelWidget* Settings_StatsEnableLabel;
leLabelWidget* Settings_MGInfoLabel;
leButtonWidget* Settings_ScratchBuffButton;
leSliderWidget* Settings_ScatchBuffSlider;
leLabelWidget* Settings_ScatchBufferSizeLabel;
leButtonWidget* Settings_EraseYesButton;
leButtonWidget* Settings_EraseNoButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Settings(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Settings(void)
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

    Settings_PanelWidget0 = leWidget_New();
    Settings_PanelWidget0->fn->setPosition(Settings_PanelWidget0, 0, 0);
    Settings_PanelWidget0->fn->setSize(Settings_PanelWidget0, 480, 320);
    Settings_PanelWidget0->fn->setScheme(Settings_PanelWidget0, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Settings_PanelWidget0);

    Settings_LabelWidget0 = leLabelWidget_New();
    Settings_LabelWidget0->fn->setPosition(Settings_LabelWidget0, 9, 4);
    Settings_LabelWidget0->fn->setSize(Settings_LabelWidget0, 153, 45);
    Settings_LabelWidget0->fn->setScheme(Settings_LabelWidget0, &WhiteBackgroundScheme);
    Settings_LabelWidget0->fn->setBackgroundType(Settings_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Settings_LabelWidget0->fn->setString(Settings_LabelWidget0, (leString*)&string_DemoConfig);
    root0->fn->addChild(root0, (leWidget*)Settings_LabelWidget0);

    Settings_UpdateSQIButton = leButtonWidget_New();
    Settings_UpdateSQIButton->fn->setPosition(Settings_UpdateSQIButton, 8, 103);
    Settings_UpdateSQIButton->fn->setSize(Settings_UpdateSQIButton, 140, 50);
    Settings_UpdateSQIButton->fn->setScheme(Settings_UpdateSQIButton, &SettingsScheme);
    Settings_UpdateSQIButton->fn->setBorderType(Settings_UpdateSQIButton, LE_WIDGET_BORDER_LINE);
    Settings_UpdateSQIButton->fn->setMargins(Settings_UpdateSQIButton, 4, 5, 4, 3);
    Settings_UpdateSQIButton->fn->setToggleable(Settings_UpdateSQIButton, LE_TRUE);
    Settings_UpdateSQIButton->fn->setString(Settings_UpdateSQIButton, (leString*)&string_SettingsDownload);
    Settings_UpdateSQIButton->fn->setPressedEventCallback(Settings_UpdateSQIButton, event_Settings_UpdateSQIButton_OnPressed);
    Settings_UpdateSQIButton->fn->setReleasedEventCallback(Settings_UpdateSQIButton, event_Settings_UpdateSQIButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Settings_UpdateSQIButton);

    Settings_SQIUpdateStatusString = leLabelWidget_New();
    Settings_SQIUpdateStatusString->fn->setPosition(Settings_SQIUpdateStatusString, 148, 103);
    Settings_SQIUpdateStatusString->fn->setSize(Settings_SQIUpdateStatusString, 325, 50);
    Settings_SQIUpdateStatusString->fn->setBackgroundType(Settings_SQIUpdateStatusString, LE_WIDGET_BACKGROUND_NONE);
    Settings_SQIUpdateStatusString->fn->setBorderType(Settings_SQIUpdateStatusString, LE_WIDGET_BORDER_LINE);
    Settings_SQIUpdateStatusString->fn->setHAlignment(Settings_SQIUpdateStatusString, LE_HALIGN_CENTER);
    root0->fn->addChild(root0, (leWidget*)Settings_SQIUpdateStatusString);

    Settings_HomeButton = leButtonWidget_New();
    Settings_HomeButton->fn->setPosition(Settings_HomeButton, 400, 0);
    Settings_HomeButton->fn->setSize(Settings_HomeButton, 80, 50);
    Settings_HomeButton->fn->setScheme(Settings_HomeButton, &PlayerVolScheme);
    Settings_HomeButton->fn->setBorderType(Settings_HomeButton, LE_WIDGET_BORDER_NONE);
    Settings_HomeButton->fn->setPressedImage(Settings_HomeButton, (leImage*)&Home565Gray);
    Settings_HomeButton->fn->setReleasedImage(Settings_HomeButton, (leImage*)&Home565Gray);
    Settings_HomeButton->fn->setPressedEventCallback(Settings_HomeButton, event_Settings_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Settings_HomeButton);

    Settings_ToggleDemoModeButton = leButtonWidget_New();
    Settings_ToggleDemoModeButton->fn->setPosition(Settings_ToggleDemoModeButton, 8, 235);
    Settings_ToggleDemoModeButton->fn->setSize(Settings_ToggleDemoModeButton, 142, 80);
    Settings_ToggleDemoModeButton->fn->setVisible(Settings_ToggleDemoModeButton, LE_FALSE);
    Settings_ToggleDemoModeButton->fn->setScheme(Settings_ToggleDemoModeButton, &SettingsScheme);
    Settings_ToggleDemoModeButton->fn->setBorderType(Settings_ToggleDemoModeButton, LE_WIDGET_BORDER_LINE);
    Settings_ToggleDemoModeButton->fn->setVAlignment(Settings_ToggleDemoModeButton, LE_VALIGN_TOP);
    Settings_ToggleDemoModeButton->fn->setMargins(Settings_ToggleDemoModeButton, 4, 15, 4, 4);
    Settings_ToggleDemoModeButton->fn->setToggleable(Settings_ToggleDemoModeButton, LE_TRUE);
    Settings_ToggleDemoModeButton->fn->setString(Settings_ToggleDemoModeButton, (leString*)&string_ToggleDemoMode);
    Settings_ToggleDemoModeButton->fn->setPressedEventCallback(Settings_ToggleDemoModeButton, event_Settings_ToggleDemoModeButton_OnPressed);
    Settings_ToggleDemoModeButton->fn->setReleasedEventCallback(Settings_ToggleDemoModeButton, event_Settings_ToggleDemoModeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Settings_ToggleDemoModeButton);

    Settings_DemoModeStatusString = leLabelWidget_New();
    Settings_DemoModeStatusString->fn->setPosition(Settings_DemoModeStatusString, 0, 50);
    Settings_DemoModeStatusString->fn->setSize(Settings_DemoModeStatusString, 142, 30);
    Settings_DemoModeStatusString->fn->setEnabled(Settings_DemoModeStatusString, LE_FALSE);
    Settings_DemoModeStatusString->fn->setBorderType(Settings_DemoModeStatusString, LE_WIDGET_BORDER_LINE);
    Settings_DemoModeStatusString->fn->setHAlignment(Settings_DemoModeStatusString, LE_HALIGN_CENTER);
    Settings_DemoModeStatusString->fn->setString(Settings_DemoModeStatusString, (leString*)&string_DisabledString);
    Settings_ToggleDemoModeButton->fn->addChild(Settings_ToggleDemoModeButton, (leWidget*)Settings_DemoModeStatusString);

    Settings_RebootButtonWidget0 = leButtonWidget_New();
    Settings_RebootButtonWidget0->fn->setPosition(Settings_RebootButtonWidget0, 8, 52);
    Settings_RebootButtonWidget0->fn->setSize(Settings_RebootButtonWidget0, 465, 50);
    Settings_RebootButtonWidget0->fn->setScheme(Settings_RebootButtonWidget0, &SettingsScheme);
    Settings_RebootButtonWidget0->fn->setBorderType(Settings_RebootButtonWidget0, LE_WIDGET_BORDER_LINE);
    Settings_RebootButtonWidget0->fn->setString(Settings_RebootButtonWidget0, (leString*)&string_Reboot);
    Settings_RebootButtonWidget0->fn->setPressedEventCallback(Settings_RebootButtonWidget0, event_Settings_RebootButtonWidget0_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Settings_RebootButtonWidget0);

    Settings_StatsEnableButton = leButtonWidget_New();
    Settings_StatsEnableButton->fn->setPosition(Settings_StatsEnableButton, 8, 154);
    Settings_StatsEnableButton->fn->setSize(Settings_StatsEnableButton, 140, 80);
    Settings_StatsEnableButton->fn->setScheme(Settings_StatsEnableButton, &SettingsScheme);
    Settings_StatsEnableButton->fn->setBorderType(Settings_StatsEnableButton, LE_WIDGET_BORDER_LINE);
    Settings_StatsEnableButton->fn->setVAlignment(Settings_StatsEnableButton, LE_VALIGN_TOP);
    Settings_StatsEnableButton->fn->setMargins(Settings_StatsEnableButton, 4, 15, 4, 4);
    Settings_StatsEnableButton->fn->setToggleable(Settings_StatsEnableButton, LE_TRUE);
    Settings_StatsEnableButton->fn->setString(Settings_StatsEnableButton, (leString*)&string_ToggleStats);
    Settings_StatsEnableButton->fn->setPressedEventCallback(Settings_StatsEnableButton, event_Settings_StatsEnableButton_OnPressed);
    Settings_StatsEnableButton->fn->setReleasedEventCallback(Settings_StatsEnableButton, event_Settings_StatsEnableButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Settings_StatsEnableButton);

    Settings_StatsEnableLabel = leLabelWidget_New();
    Settings_StatsEnableLabel->fn->setPosition(Settings_StatsEnableLabel, 0, 50);
    Settings_StatsEnableLabel->fn->setSize(Settings_StatsEnableLabel, 140, 30);
    Settings_StatsEnableLabel->fn->setEnabled(Settings_StatsEnableLabel, LE_FALSE);
    Settings_StatsEnableLabel->fn->setBorderType(Settings_StatsEnableLabel, LE_WIDGET_BORDER_LINE);
    Settings_StatsEnableLabel->fn->setHAlignment(Settings_StatsEnableLabel, LE_HALIGN_CENTER);
    Settings_StatsEnableLabel->fn->setString(Settings_StatsEnableLabel, (leString*)&string_DisabledString);
    Settings_StatsEnableButton->fn->addChild(Settings_StatsEnableButton, (leWidget*)Settings_StatsEnableLabel);

    Settings_TimeStampString = leLabelWidget_New();
    Settings_TimeStampString->fn->setPosition(Settings_TimeStampString, 163, 14);
    Settings_TimeStampString->fn->setSize(Settings_TimeStampString, 234, 25);
    Settings_TimeStampString->fn->setScheme(Settings_TimeStampString, &WhiteBackgroundScheme);
    Settings_TimeStampString->fn->setBackgroundType(Settings_TimeStampString, LE_WIDGET_BACKGROUND_NONE);
    Settings_TimeStampString->fn->setHAlignment(Settings_TimeStampString, LE_HALIGN_RIGHT);
    root0->fn->addChild(root0, (leWidget*)Settings_TimeStampString);

    Settings_AdvancedGesturesEnable = leButtonWidget_New();
    Settings_AdvancedGesturesEnable->fn->setPosition(Settings_AdvancedGesturesEnable, 149, 154);
    Settings_AdvancedGesturesEnable->fn->setSize(Settings_AdvancedGesturesEnable, 324, 80);
    Settings_AdvancedGesturesEnable->fn->setScheme(Settings_AdvancedGesturesEnable, &SettingsScheme);
    Settings_AdvancedGesturesEnable->fn->setBorderType(Settings_AdvancedGesturesEnable, LE_WIDGET_BORDER_NONE);
    Settings_AdvancedGesturesEnable->fn->setVAlignment(Settings_AdvancedGesturesEnable, LE_VALIGN_TOP);
    Settings_AdvancedGesturesEnable->fn->setMargins(Settings_AdvancedGesturesEnable, 4, 15, 4, 4);
    Settings_AdvancedGesturesEnable->fn->setToggleable(Settings_AdvancedGesturesEnable, LE_TRUE);
    Settings_AdvancedGesturesEnable->fn->setString(Settings_AdvancedGesturesEnable, (leString*)&string_MotionGesturesEnable);
    Settings_AdvancedGesturesEnable->fn->setPressedEventCallback(Settings_AdvancedGesturesEnable, event_Settings_AdvancedGesturesEnable_OnPressed);
    Settings_AdvancedGesturesEnable->fn->setReleasedEventCallback(Settings_AdvancedGesturesEnable, event_Settings_AdvancedGesturesEnable_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Settings_AdvancedGesturesEnable);

    Settings_MGInfoLabel = leLabelWidget_New();
    Settings_MGInfoLabel->fn->setPosition(Settings_MGInfoLabel, 0, 50);
    Settings_MGInfoLabel->fn->setSize(Settings_MGInfoLabel, 324, 30);
    Settings_MGInfoLabel->fn->setEnabled(Settings_MGInfoLabel, LE_FALSE);
    Settings_MGInfoLabel->fn->setBorderType(Settings_MGInfoLabel, LE_WIDGET_BORDER_LINE);
    Settings_MGInfoLabel->fn->setHAlignment(Settings_MGInfoLabel, LE_HALIGN_CENTER);
    Settings_MGInfoLabel->fn->setString(Settings_MGInfoLabel, (leString*)&string_DisabledString);
    Settings_AdvancedGesturesEnable->fn->addChild(Settings_AdvancedGesturesEnable, (leWidget*)Settings_MGInfoLabel);

    Settings_ScratchBufferControl = leWidget_New();
    Settings_ScratchBufferControl->fn->setPosition(Settings_ScratchBufferControl, 8, 235);
    Settings_ScratchBufferControl->fn->setSize(Settings_ScratchBufferControl, 465, 54);
    Settings_ScratchBufferControl->fn->setBackgroundType(Settings_ScratchBufferControl, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Settings_ScratchBufferControl);

    Settings_ScratchBuffButton = leButtonWidget_New();
    Settings_ScratchBuffButton->fn->setPosition(Settings_ScratchBuffButton, 0, 0);
    Settings_ScratchBuffButton->fn->setSize(Settings_ScratchBuffButton, 140, 50);
    Settings_ScratchBuffButton->fn->setScheme(Settings_ScratchBuffButton, &SettingsScheme);
    Settings_ScratchBuffButton->fn->setBorderType(Settings_ScratchBuffButton, LE_WIDGET_BORDER_LINE);
    Settings_ScratchBuffButton->fn->setString(Settings_ScratchBuffButton, (leString*)&string_ScratchBuffSize);
    Settings_ScratchBufferControl->fn->addChild(Settings_ScratchBufferControl, (leWidget*)Settings_ScratchBuffButton);

    Settings_ScatchBuffSlider = leSliderWidget_New();
    Settings_ScatchBuffSlider->fn->setPosition(Settings_ScatchBuffSlider, 146, 0);
    Settings_ScatchBuffSlider->fn->setSize(Settings_ScatchBuffSlider, 256, 50);
    Settings_ScatchBuffSlider->fn->setBackgroundType(Settings_ScatchBuffSlider, LE_WIDGET_BACKGROUND_NONE);
    Settings_ScatchBuffSlider->fn->setOrientation(Settings_ScatchBuffSlider, LE_ORIENTATION_HORIZONTAL, LE_FALSE);
    Settings_ScatchBuffSlider->fn->setValue(Settings_ScatchBuffSlider, 100);
    Settings_ScatchBuffSlider->fn->setGripSize(Settings_ScatchBuffSlider, 30);
    Settings_ScatchBuffSlider->fn->setValueChangedEventCallback(Settings_ScatchBuffSlider, event_Settings_ScatchBuffSlider_OnValueChanged);
    Settings_ScratchBufferControl->fn->addChild(Settings_ScratchBufferControl, (leWidget*)Settings_ScatchBuffSlider);

    Settings_ScatchBufferSizeLabel = leLabelWidget_New();
    Settings_ScatchBufferSizeLabel->fn->setPosition(Settings_ScatchBufferSizeLabel, 406, 1);
    Settings_ScatchBufferSizeLabel->fn->setSize(Settings_ScatchBufferSizeLabel, 60, 50);
    Settings_ScatchBufferSizeLabel->fn->setBackgroundType(Settings_ScatchBufferSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    Settings_ScatchBufferSizeLabel->fn->setString(Settings_ScatchBufferSizeLabel, (leString*)&string_ScratchBufferSize);
    Settings_ScratchBufferControl->fn->addChild(Settings_ScratchBufferControl, (leWidget*)Settings_ScatchBufferSizeLabel);

    Settings_SQIUpdateWarningLabel = leLabelWidget_New();
    Settings_SQIUpdateWarningLabel->fn->setPosition(Settings_SQIUpdateWarningLabel, 41, 62);
    Settings_SQIUpdateWarningLabel->fn->setSize(Settings_SQIUpdateWarningLabel, 409, 215);
    Settings_SQIUpdateWarningLabel->fn->setScheme(Settings_SQIUpdateWarningLabel, &WhiteBackgroundScheme);
    Settings_SQIUpdateWarningLabel->fn->setBorderType(Settings_SQIUpdateWarningLabel, LE_WIDGET_BORDER_LINE);
    Settings_SQIUpdateWarningLabel->fn->setHAlignment(Settings_SQIUpdateWarningLabel, LE_HALIGN_CENTER);
    Settings_SQIUpdateWarningLabel->fn->setVAlignment(Settings_SQIUpdateWarningLabel, LE_VALIGN_TOP);
    Settings_SQIUpdateWarningLabel->fn->setMargins(Settings_SQIUpdateWarningLabel, 4, 50, 4, 4);
    Settings_SQIUpdateWarningLabel->fn->setString(Settings_SQIUpdateWarningLabel, (leString*)&string_SQIUpdateWarning);
    root0->fn->addChild(root0, (leWidget*)Settings_SQIUpdateWarningLabel);

    Settings_EraseYesButton = leButtonWidget_New();
    Settings_EraseYesButton->fn->setPosition(Settings_EraseYesButton, 18, 107);
    Settings_EraseYesButton->fn->setSize(Settings_EraseYesButton, 184, 60);
    Settings_EraseYesButton->fn->setScheme(Settings_EraseYesButton, &InfoPageScheme);
    Settings_EraseYesButton->fn->setBorderType(Settings_EraseYesButton, LE_WIDGET_BORDER_NONE);
    Settings_EraseYesButton->fn->setString(Settings_EraseYesButton, (leString*)&string_Yes);
    Settings_EraseYesButton->fn->setReleasedEventCallback(Settings_EraseYesButton, event_Settings_EraseYesButton_OnReleased);
    Settings_SQIUpdateWarningLabel->fn->addChild(Settings_SQIUpdateWarningLabel, (leWidget*)Settings_EraseYesButton);

    Settings_EraseNoButton = leButtonWidget_New();
    Settings_EraseNoButton->fn->setPosition(Settings_EraseNoButton, 204, 107);
    Settings_EraseNoButton->fn->setSize(Settings_EraseNoButton, 191, 60);
    Settings_EraseNoButton->fn->setBackgroundType(Settings_EraseNoButton, LE_WIDGET_BACKGROUND_NONE);
    Settings_EraseNoButton->fn->setBorderType(Settings_EraseNoButton, LE_WIDGET_BORDER_LINE);
    Settings_EraseNoButton->fn->setString(Settings_EraseNoButton, (leString*)&string_No);
    Settings_EraseNoButton->fn->setReleasedEventCallback(Settings_EraseNoButton, event_Settings_EraseNoButton_OnReleased);
    Settings_SQIUpdateWarningLabel->fn->addChild(Settings_SQIUpdateWarningLabel, (leWidget*)Settings_EraseNoButton);

    Settings_SLALabel = leLabelWidget_New();
    Settings_SLALabel->fn->setPosition(Settings_SLALabel, 2, 289);
    Settings_SLALabel->fn->setSize(Settings_SLALabel, 393, 30);
    Settings_SLALabel->fn->setEnabled(Settings_SLALabel, LE_FALSE);
    Settings_SLALabel->fn->setBackgroundType(Settings_SLALabel, LE_WIDGET_BACKGROUND_NONE);
    Settings_SLALabel->fn->setString(Settings_SLALabel, (leString*)&string_MotionGesturesInfo);
    root0->fn->addChild(root0, (leWidget*)Settings_SLALabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Settings_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Settings(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Settings_OnUpdate(); // raise event
}

void screenHide_Settings(void)
{
    Settings_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Settings_PanelWidget0 = NULL;
    Settings_LabelWidget0 = NULL;
    Settings_UpdateSQIButton = NULL;
    Settings_SQIUpdateStatusString = NULL;
    Settings_HomeButton = NULL;
    Settings_ToggleDemoModeButton = NULL;
    Settings_RebootButtonWidget0 = NULL;
    Settings_StatsEnableButton = NULL;
    Settings_TimeStampString = NULL;
    Settings_AdvancedGesturesEnable = NULL;
    Settings_ScratchBufferControl = NULL;
    Settings_SQIUpdateWarningLabel = NULL;
    Settings_SLALabel = NULL;
    Settings_DemoModeStatusString = NULL;
    Settings_StatsEnableLabel = NULL;
    Settings_MGInfoLabel = NULL;
    Settings_ScratchBuffButton = NULL;
    Settings_ScatchBuffSlider = NULL;
    Settings_ScatchBufferSizeLabel = NULL;
    Settings_EraseYesButton = NULL;
    Settings_EraseNoButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Settings(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Settings(uint32_t lyrIdx)
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

