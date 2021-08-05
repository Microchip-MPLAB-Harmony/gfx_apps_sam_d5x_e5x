#ifndef LEGATO_INIT_H
#define LEGATO_INIT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

#include "gfx/legato/generated/screen/le_gen_screen_Intro.h"
#include "gfx/legato/generated/screen/le_gen_screen_CkrScrn1.h"
#include "gfx/legato/generated/screen/le_gen_screen_CkrScrn2.h"
#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"
#include "gfx/legato/generated/screen/le_gen_screen_PlyrScrn.h"
#include "gfx/legato/generated/screen/le_gen_screen_CCtrlScrn1.h"
#include "gfx/legato/generated/screen/le_gen_screen_MGScrn.h"
#include "gfx/legato/generated/screen/le_gen_screen_Settings.h"
#include "gfx/legato/generated/screen/le_gen_screen_Info.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen IDs
#define screenID_Intro    0
#define screenID_CkrScrn1    1
#define screenID_CkrScrn2    2
#define screenID_Menu    3
#define screenID_PlyrScrn    4
#define screenID_CCtrlScrn1    5
#define screenID_MGScrn    6
#define screenID_Settings    7
#define screenID_Info    8

void legato_initializeScreenState(void);

// global screen control functions
uint32_t legato_getCurrentScreen(void);
void legato_showScreen(uint32_t id);
void legato_updateScreenState(void);

// do not do anything in the application if this returns true
leBool legato_isChangingScreens(void);


//DOM-IGNORE-BEGIN

#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_H
