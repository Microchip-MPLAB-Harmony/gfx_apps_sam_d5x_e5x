#ifndef LE_GEN_SCREEN_PLYRSCRN_H
#define LE_GEN_SCREEN_PLYRSCRN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* PlyrScrn_PanelWidget0;
extern leWidget* PlyrScrn_PanelWidget2;
extern leWidget* PlyrScrn_SourcePanel;
extern leWidget* PlyrScrn_ControlPanel;
extern leButtonWidget* PlyrScrn_HomeButton;
extern leImageWidget* PlyrScrn_ImageWidget0;
extern leWidget* PlyrScrn_ClockPanel;
extern leWidget* PlyrScrn_VolPanel;
extern leButtonWidget* PlyrScrn_VolumeButton;
extern leWidget* PlyrScrn_VolPanelButton;
extern leLabelWidget* PlyrScrn_FPSLabel;
extern leWidget* PlyrScrn_PanelWidget1;
extern leButtonWidget* PlyrScrn_UsbButton;
extern leButtonWidget* PlyrScrn_WifiButton;
extern leButtonWidget* PlyrScrn_BtButton;
extern leButtonWidget* PlyrScrn_AuxButton;
extern leButtonWidget* PlyrScrn_ButtonWidget5;
extern leButtonWidget* PlyrScrn_ButtonWidget6;
extern leLabelWidget* PlyrScrn_TrackArtist;
extern leLabelWidget* PlyrScrn_TrackTitle;
extern leLabelWidget* PlyrScrn_HrLabel;
extern leLabelWidget* PlyrScrn_ColonLabel;
extern leLabelWidget* PlyrScrn_MinLabel;
extern leWidget* PlyrScrn_VolPanelActive;
extern leWidget* PlyrScrn_VolPanelMax;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_PlyrScrn_HomeButton_OnPressed(leButtonWidget* btn);
void event_PlyrScrn_UsbButton_OnPressed(leButtonWidget* btn);
void event_PlyrScrn_WifiButton_OnPressed(leButtonWidget* btn);
void event_PlyrScrn_BtButton_OnPressed(leButtonWidget* btn);
void event_PlyrScrn_AuxButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_PlyrScrn(void); // called when Legato is initialized
leResult screenShow_PlyrScrn(void); // called when screen is shown
void screenHide_PlyrScrn(void); // called when screen is hidden
void screenDestroy_PlyrScrn(void); // called when Legato is destroyed
void screenUpdate_PlyrScrn(void); // called when Legato is updating

leWidget* screenGetRoot_PlyrScrn(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void PlyrScrn_OnShow(void); // called when this screen is shown
void PlyrScrn_OnHide(void); // called when this screen is hidden
void PlyrScrn_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_PLYRSCRN_H
