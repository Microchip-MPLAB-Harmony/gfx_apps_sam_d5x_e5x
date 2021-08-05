#ifndef LE_GEN_SCREEN_INFO_H
#define LE_GEN_SCREEN_INFO_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Info_PanelWidget0;
extern leButtonWidget* Info_HomeButton;
extern leLabelWidget* Info_InfoPageTitleLabel;
extern leWidget* Info_MenuPanelWidget;
extern leImageSequenceWidget* Info_IgatImageSequence;
extern leWidget* Info_BoardViewPanel;
extern leWidget* Info_MCUPanel;
extern leWidget* Info_SAME5xScrollPanel;
extern leWidget* Info_ResourcesPanel;
extern leWidget* Info_SoftwarePanel;
extern leLabelWidget* Info_FPSLabel;
extern leImageWidget* Info_ImageWidget0;
extern leButtonWidget* Info_ReferencesButton;
extern leButtonWidget* Info_SoftwareButton;
extern leButtonWidget* Info_HardwareButton;
extern leButtonWidget* Info_MCUButton;
extern leLabelWidget* Info_ReferencesLabel;
extern leLabelWidget* Info_SWLabel;
extern leLabelWidget* Info_HWLabel;
extern leLabelWidget* Info_MCULabel;
extern leImageSequenceWidget* Info_BoardViewImageSequence;
extern leLabelWidget* Info_HWF_DisplayInfoFront;
extern leImageWidget* Info_SAME51;
extern leWidget* Info_SAME5xInfoPanel;
extern leLabelWidget* Info_LabelWidget0;
extern leImageWidget* Info_ImageWidget1;
extern leImageWidget* Info_ImageWidget2;
extern leImageWidget* Info_SAME5xDetailedImage;
extern leButtonWidget* Info_ButtonWidget0;
extern leButtonWidget* Info_ButtonWidget1;
extern leButtonWidget* Info_ButtonWidget2;
extern leButtonWidget* Info_ButtonWidget3;
extern leButtonWidget* Info_ButtonWidget4;
extern leLabelWidget* Info_LabelWidget1;
extern leListWheelWidget* Info_ListWheelWidget0;
extern leLineWidget* Info_LineWidget0;
extern leLabelWidget* Info_SWModuleTitle;
extern leLabelWidget* Info_SWModuleDesc;
extern leWidget* Info_RedBarPanel;
extern leImageWidget* Info_MHGSDiagramImage;
extern leImageWidget* Info_MH3IconsImage;
extern leImageWidget* Info_TouchIconsImage;
extern leButtonWidget* Info_SWUpButton;
extern leButtonWidget* Info_SWDownButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Info_HomeButton_OnPressed(leButtonWidget* btn);
void event_Info_ReferencesButton_OnReleased(leButtonWidget* btn);
void event_Info_SoftwareButton_OnReleased(leButtonWidget* btn);
void event_Info_HardwareButton_OnReleased(leButtonWidget* btn);
void event_Info_MCUButton_OnReleased(leButtonWidget* btn);
void event_Info_ListWheelWidget0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);
void event_Info_SWUpButton_OnPressed(leButtonWidget* btn);
void event_Info_SWDownButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Info(void); // called when Legato is initialized
leResult screenShow_Info(void); // called when screen is shown
void screenHide_Info(void); // called when screen is hidden
void screenDestroy_Info(void); // called when Legato is destroyed
void screenUpdate_Info(void); // called when Legato is updating

leWidget* screenGetRoot_Info(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Info_OnShow(void); // called when this screen is shown
void Info_OnHide(void); // called when this screen is hidden
void Info_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INFO_H
