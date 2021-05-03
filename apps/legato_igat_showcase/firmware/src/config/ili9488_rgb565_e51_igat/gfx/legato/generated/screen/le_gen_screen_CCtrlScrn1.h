#ifndef LE_GEN_SCREEN_CCTRLSCRN1_H
#define LE_GEN_SCREEN_CCTRLSCRN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* CCtrlScrn1_PanelWidget0;
extern leImageWidget* CCtrlScrn1_ImageWidget2;
extern leImageWidget* CCtrlScrn1_ImageWidget1;
extern leListWheelWidget* CCtrlScrn1_ListWheelWidget0;
extern leListWheelWidget* CCtrlScrn1_ListWheelWidget1;
extern leButtonWidget* CCtrlScrn1_ButtonWidget0;
extern leButtonWidget* CCtrlScrn1_ButtonWidget1;
extern leButtonWidget* CCtrlScrn1_ButtonWidget2;
extern leButtonWidget* CCtrlScrn1_ButtonWidget3;
extern leButtonWidget* CCtrlScrn1_ButtonWidget4;
extern leListWheelWidget* CCtrlScrn1_ListWheelWidget2;
extern leButtonWidget* CCtrlScrn1_HomeButton;
extern leImageSequenceWidget* CCtrlScrn1_RightFanImageSequence;
extern leImageSequenceWidget* CCtrlScrn1_LeftFanImageSequence;
extern leButtonWidget* CCtrlScrn1_RightFanDownButton;
extern leButtonWidget* CCtrlScrn1_RightFanUpButton;
extern leButtonWidget* CCtrlScrn1_LeftFanDownButton;
extern leButtonWidget* CCtrlScrn1_LeftFanUpButton;
extern leLineWidget* CCtrlScrn1_LineWidget0;
extern leLineWidget* CCtrlScrn1_LineWidget1;
extern leLabelWidget* CCtrlScrn1_FPSLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_CCtrlScrn1_HomeButton_OnPressed(leButtonWidget* btn);
void event_CCtrlScrn1_RightFanDownButton_OnPressed(leButtonWidget* btn);
void event_CCtrlScrn1_RightFanUpButton_OnPressed(leButtonWidget* btn);
void event_CCtrlScrn1_LeftFanDownButton_OnPressed(leButtonWidget* btn);
void event_CCtrlScrn1_LeftFanUpButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_CCtrlScrn1(void); // called when Legato is initialized
leResult screenShow_CCtrlScrn1(void); // called when screen is shown
void screenHide_CCtrlScrn1(void); // called when screen is hidden
void screenDestroy_CCtrlScrn1(void); // called when Legato is destroyed
void screenUpdate_CCtrlScrn1(void); // called when Legato is updating

leWidget* screenGetRoot_CCtrlScrn1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void CCtrlScrn1_OnShow(void); // called when this screen is shown
void CCtrlScrn1_OnHide(void); // called when this screen is hidden
void CCtrlScrn1_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_CCTRLSCRN1_H
