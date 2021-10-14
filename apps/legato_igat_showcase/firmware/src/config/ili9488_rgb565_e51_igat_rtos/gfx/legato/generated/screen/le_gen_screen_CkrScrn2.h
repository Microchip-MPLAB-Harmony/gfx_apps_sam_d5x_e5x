#ifndef LE_GEN_SCREEN_CKRSCRN2_H
#define LE_GEN_SCREEN_CKRSCRN2_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* CkrScrn2_PanelWidget2;
extern leWidget* CkrScrn2_PanelWidget5;
extern leWidget* CkrScrn2_PanelWidget4;
extern leWidget* CkrScrn2_QuickSelectionsPanel;
extern leWidget* CkrScrn2_Screen2MainClockPanel;
extern leWidget* CkrScrn2_Screen2LabelPanel;
extern leButtonWidget* CkrScrn2_SliderButton2;
extern leImageWidget* CkrScrn2_ImageWidget0;
extern leButtonWidget* CkrScrn2_HomeButton;
extern leLabelWidget* CkrScrn2_FPSLabel;
extern leRectangleWidget* CkrScrn2_ProgressRect;
extern leButtonWidget* CkrScrn2_ButtonWidget5;
extern leButtonWidget* CkrScrn2_CookButtonWidget;
extern leButtonWidget* CkrScrn2_ReheatButtonWidget;
extern leWidget* CkrScrn2_MenuItem4;
extern leWidget* CkrScrn2_MenuItem3;
extern leWidget* CkrScrn2_MenuItem2;
extern leLabelWidget* CkrScrn2_LabelWidget2;
extern leWidget* CkrScrn2_MenuItem1;
extern leRectangleWidget* CkrScrn2_Button4Rect;
extern leRectangleWidget* CkrScrn2_Button4RectBack;
extern leLabelWidget* CkrScrn2_MenuItem4Label;
extern leImageWidget* CkrScrn2_Button4Image;
extern leButtonWidget* CkrScrn2_ButtonWidget4;
extern leRectangleWidget* CkrScrn2_Button3Rect;
extern leRectangleWidget* CkrScrn2_Button3RectBack;
extern leLabelWidget* CkrScrn2_MenuItem3Label;
extern leImageWidget* CkrScrn2_ButtonImage3;
extern leButtonWidget* CkrScrn2_ButtonWidget3;
extern leRectangleWidget* CkrScrn2_Button2Rect;
extern leRectangleWidget* CkrScrn2_Button2RectBack;
extern leImageWidget* CkrScrn2_ButtonImage2;
extern leLabelWidget* CkrScrn2_MenuItem2Label;
extern leButtonWidget* CkrScrn2_ButtonWidget2;
extern leRectangleWidget* CkrScrn2_Button1Rect;
extern leRectangleWidget* CkrScrn2_ButtonRect1Back;
extern leLabelWidget* CkrScrn2_MenuItem1Label;
extern leImageWidget* CkrScrn2_ButtonImage1;
extern leButtonWidget* CkrScrn2_ButtonWidget1;
extern leLabelWidget* CkrScrn2_Screen2MinuteLabel;
extern leLabelWidget* CkrScrn2_Screen2ColonLabel;
extern leLabelWidget* CkrScrn2_Screen2HourLabel;
extern leButtonWidget* CkrScrn2_ButtonWidget6;
extern leLabelWidget* CkrScrn2_Screen2SmartCookerLabel;
extern leLabelWidget* CkrScrn2_Screen2BytesLabel;
extern leLabelWidget* CkrScrn2_Screen2GoodLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_CkrScrn2_HomeButton_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget5_OnReleased(leButtonWidget* btn);
void event_CkrScrn2_CookButtonWidget_OnReleased(leButtonWidget* btn);
void event_CkrScrn2_ReheatButtonWidget_OnReleased(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget4_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget3_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget2_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget1_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget6_OnPressed(leButtonWidget* btn);
void event_CkrScrn2_ButtonWidget6_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_CkrScrn2(void); // called when Legato is initialized
leResult screenShow_CkrScrn2(void); // called when screen is shown
void screenHide_CkrScrn2(void); // called when screen is hidden
void screenDestroy_CkrScrn2(void); // called when Legato is destroyed
void screenUpdate_CkrScrn2(void); // called when Legato is updating

leWidget* screenGetRoot_CkrScrn2(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void CkrScrn2_OnShow(void); // called when this screen is shown
void CkrScrn2_OnHide(void); // called when this screen is hidden
void CkrScrn2_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_CKRSCRN2_H
