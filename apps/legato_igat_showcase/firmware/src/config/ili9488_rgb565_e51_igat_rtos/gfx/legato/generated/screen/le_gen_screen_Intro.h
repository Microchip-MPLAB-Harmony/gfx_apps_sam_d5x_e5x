#ifndef LE_GEN_SCREEN_INTRO_H
#define LE_GEN_SCREEN_INTRO_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Intro_PanelWidget6;
extern leImageSequenceWidget* Intro_SplashAnimWidget;
extern leImageWidget* Intro_ImageWidget0;
extern leImageWidget* Intro_GraphicsImage;
extern leImageWidget* Intro_TouchImage;
extern leLabelWidget* Intro_FPSLabel;
extern leButtonWidget* Intro_ButtonWidget0;
extern leLabelWidget* Intro_LabelWidget0;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Intro_ButtonWidget0_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Intro(void); // called when Legato is initialized
leResult screenShow_Intro(void); // called when screen is shown
void screenHide_Intro(void); // called when screen is hidden
void screenDestroy_Intro(void); // called when Legato is destroyed
void screenUpdate_Intro(void); // called when Legato is updating

leWidget* screenGetRoot_Intro(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Intro_OnShow(void); // called when this screen is shown
void Intro_OnHide(void); // called when this screen is hidden
void Intro_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INTRO_H
