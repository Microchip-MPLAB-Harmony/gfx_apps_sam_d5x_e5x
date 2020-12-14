#ifndef LEGATO_INIT_H
#define LEGATO_INIT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"
#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"
#include "gfx/legato/generated/screen/le_gen_screen_Screen2.h"
#include "gfx/legato/generated/screen/le_gen_screen_Screen3.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen IDs
#define screenID_Screen0    0
#define screenID_Screen1    1
#define screenID_Screen2    2
#define screenID_Screen3    3

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
