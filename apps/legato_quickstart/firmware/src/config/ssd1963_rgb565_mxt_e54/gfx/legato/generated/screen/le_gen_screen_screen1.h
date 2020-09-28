#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* screen1_PanelWidget0;
extern leImageWidget* screen1_LogoWidget;
extern leLabelWidget* screen1_TitleLabel;
extern leButtonWidget* screen1_SloganButton;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_screen1(); // called when Legato is initialized
leResult screenShow_screen1(); // called when screen is shown
void screenHide_screen1(); // called when screen is hidden
void screenDestroy_screen1(); // called when Legato is destroyed
void screenUpdate_screen1(); // called when Legato is updating

leWidget* screenGetRoot_screen1(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
