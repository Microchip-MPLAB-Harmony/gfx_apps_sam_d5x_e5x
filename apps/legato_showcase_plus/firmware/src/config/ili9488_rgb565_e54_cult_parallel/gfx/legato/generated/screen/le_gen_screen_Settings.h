#ifndef LE_GEN_SCREEN_SETTINGS_H
#define LE_GEN_SCREEN_SETTINGS_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Settings_PanelWidget0;
extern leLabelWidget* Settings_LabelWidget0;
extern leButtonWidget* Settings_UpdateSQIButton;
extern leLabelWidget* Settings_SQIUpdateStatusString;
extern leButtonWidget* Settings_HomeButton;
extern leButtonWidget* Settings_ToggleDemoModeButton;
extern leButtonWidget* Settings_RebootButtonWidget0;
extern leButtonWidget* Settings_StatsEnableButton;
extern leLabelWidget* Settings_TimeStampString;
extern leButtonWidget* Settings_AdvancedGesturesEnable;
extern leLabelWidget* Settings_SQIUpdateWarningLabel;
extern leLabelWidget* Settings_SLALabel;
extern leLabelWidget* Settings_DemoModeStatusString;
extern leLabelWidget* Settings_StatsEnableLabel;
extern leLabelWidget* Settings_MGInfoLabel;
extern leButtonWidget* Settings_EraseYesButton;
extern leButtonWidget* Settings_EraseNoButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Settings_UpdateSQIButton_OnPressed(leButtonWidget* btn);
void event_Settings_UpdateSQIButton_OnReleased(leButtonWidget* btn);
void event_Settings_HomeButton_OnPressed(leButtonWidget* btn);
void event_Settings_ToggleDemoModeButton_OnPressed(leButtonWidget* btn);
void event_Settings_ToggleDemoModeButton_OnReleased(leButtonWidget* btn);
void event_Settings_RebootButtonWidget0_OnPressed(leButtonWidget* btn);
void event_Settings_StatsEnableButton_OnPressed(leButtonWidget* btn);
void event_Settings_StatsEnableButton_OnReleased(leButtonWidget* btn);
void event_Settings_AdvancedGesturesEnable_OnPressed(leButtonWidget* btn);
void event_Settings_AdvancedGesturesEnable_OnReleased(leButtonWidget* btn);
void event_Settings_EraseYesButton_OnReleased(leButtonWidget* btn);
void event_Settings_EraseNoButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Settings(void); // called when Legato is initialized
leResult screenShow_Settings(void); // called when screen is shown
void screenHide_Settings(void); // called when screen is hidden
void screenDestroy_Settings(void); // called when Legato is destroyed
void screenUpdate_Settings(void); // called when Legato is updating

leWidget* screenGetRoot_Settings(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Settings_OnShow(void); // called when this screen is shown
void Settings_OnHide(void); // called when this screen is hidden
void Settings_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SETTINGS_H
