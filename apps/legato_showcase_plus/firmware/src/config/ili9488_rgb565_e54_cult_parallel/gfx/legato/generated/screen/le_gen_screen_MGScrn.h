#ifndef LE_GEN_SCREEN_MGSCRN_H
#define LE_GEN_SCREEN_MGSCRN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* MGScrn_PanelWidget3;
extern leWidget* MGScrn_PanelWidget2;
extern leWidget* MGScrn_PanelWidget1;
extern leWidget* MGScrn_PanelWidget0;
extern leButtonWidget* MGScrn_HomeButton;
extern leDrawSurfaceWidget* MGScrn_DrawSurfaceWidget0;
extern leImageWidget* MGScrn_GestureImageWidget;
extern leLabelWidget* MGScrn_FPSLabel;
extern leImageWidget* MGScrn_ImageWidget0;
extern leLabelWidget* MGScrn_LabelWidget0;
extern leButtonWidget* MGScrn_TouchModeButton;
extern leImageWidget* MGScrn_MGLogoImageWidget;
extern leLabelWidget* MGScrn_DrawInstructionLabel;
extern leImageWidget* MGScrn_MG_Gestures;
extern leLabelWidget* MGScrn_MGLicenseLabel;
extern leImageSequenceWidget* MGScrn_ImageSequenceWidget0;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_MGScrn_HomeButton_OnPressed(leButtonWidget* btn);
leBool event_MGScrn_DrawSurfaceWidget0_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds);
void event_MGScrn_TouchModeButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MGScrn(void); // called when Legato is initialized
leResult screenShow_MGScrn(void); // called when screen is shown
void screenHide_MGScrn(void); // called when screen is hidden
void screenDestroy_MGScrn(void); // called when Legato is destroyed
void screenUpdate_MGScrn(void); // called when Legato is updating

leWidget* screenGetRoot_MGScrn(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MGScrn_OnShow(void); // called when this screen is shown
void MGScrn_OnHide(void); // called when this screen is hidden
void MGScrn_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MGSCRN_H
