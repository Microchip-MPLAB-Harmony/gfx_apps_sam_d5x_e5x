#ifndef LE_GEN_SCREEN_CKRSCRN1_H
#define LE_GEN_SCREEN_CKRSCRN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* CkrScrn1_PanelWidget1;
extern leImageWidget* CkrScrn1_ImageWidget1;
extern leWidget* CkrScrn1_PanelWidget3;
extern leWidget* CkrScrn1_MainPanel;
extern leImageWidget* CkrScrn1_ImageWidget2;
extern leImageWidget* CkrScrn1_ImageWidget3;
extern leImageWidget* CkrScrn1_ImageWidget4;
extern leWidget* CkrScrn1_Badge;
extern leWidget* CkrScrn1_ClockPanel;
extern leImageWidget* CkrScrn1_ImageWidget8;
extern leWidget* CkrScrn1_PanelWidget0;
extern leButtonWidget* CkrScrn1_ButtonWidget0;
extern leButtonWidget* CkrScrn1_DemoModeOnButton;
extern leImageWidget* CkrScrn1_ImageWidget7;
extern leButtonWidget* CkrScrn1_HomeButton;
extern leImageWidget* CkrScrn1_ImageWidget5;
extern leLabelWidget* CkrScrn1_FPSLabel;
extern leListWheelWidget* CkrScrn1_ListWheelWidget2;
extern leButtonWidget* CkrScrn1_ReheatButton;
extern leButtonWidget* CkrScrn1_BroilButton;
extern leButtonWidget* CkrScrn1_CookButton;
extern leButtonWidget* CkrScrn1_BakeButton;
extern leLabelWidget* CkrScrn1_LabelWidget1;
extern leLabelWidget* CkrScrn1_LabelWidget3;
extern leLabelWidget* CkrScrn1_LabelWidget0;
extern leLabelWidget* CkrScrn1_HourLabel;
extern leImageWidget* CkrScrn1_ImageWidget6;
extern leLabelWidget* CkrScrn1_ColonLabel;
extern leLabelWidget* CkrScrn1_MinuteLabel;
extern leImageWidget* CkrScrn1_ImageWidget0;
extern leProgressBarWidget* CkrScrn1_ProgressBarWidget0;
extern leImageWidget* CkrScrn1_ModeImageWidget;
extern leRectangleWidget* CkrScrn1_RectangleWidget3;
extern leRectangleWidget* CkrScrn1_RectangleWidget2;
extern leRectangleWidget* CkrScrn1_RectangleWidget1;
extern leRectangleWidget* CkrScrn1_RectangleWidget0;
extern leLabelWidget* CkrScrn1_CookTimeLabel;
extern leButtonWidget* CkrScrn1_RestartButton;
extern leButtonWidget* CkrScrn1_SliderButton0;
extern leButtonWidget* CkrScrn1_CancelButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_CkrScrn1_ButtonWidget0_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_HomeButton_OnPressed(leButtonWidget* btn);
void event_CkrScrn1_ListWheelWidget2_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);
void event_CkrScrn1_ReheatButton_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_BroilButton_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_CookButton_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_BakeButton_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_RestartButton_OnReleased(leButtonWidget* btn);
void event_CkrScrn1_CancelButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_CkrScrn1(void); // called when Legato is initialized
leResult screenShow_CkrScrn1(void); // called when screen is shown
void screenHide_CkrScrn1(void); // called when screen is hidden
void screenDestroy_CkrScrn1(void); // called when Legato is destroyed
void screenUpdate_CkrScrn1(void); // called when Legato is updating

leWidget* screenGetRoot_CkrScrn1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void CkrScrn1_OnShow(void); // called when this screen is shown
void CkrScrn1_OnHide(void); // called when this screen is hidden
void CkrScrn1_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_CKRSCRN1_H
