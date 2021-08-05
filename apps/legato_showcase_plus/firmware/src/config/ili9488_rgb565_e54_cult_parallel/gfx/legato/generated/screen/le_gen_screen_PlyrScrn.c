#include "gfx/legato/generated/screen/le_gen_screen_PlyrScrn.h"

// screen member widget declarations
static leWidget* root0;

leWidget* PlyrScrn_PanelWidget0;
leWidget* PlyrScrn_PanelWidget2;
leWidget* PlyrScrn_SourcePanel;
leWidget* PlyrScrn_ControlPanel;
leButtonWidget* PlyrScrn_HomeButton;
leImageWidget* PlyrScrn_ImageWidget0;
leWidget* PlyrScrn_ClockPanel;
leWidget* PlyrScrn_VolPanel;
leButtonWidget* PlyrScrn_VolumeButton;
leWidget* PlyrScrn_VolPanelButton;
leLabelWidget* PlyrScrn_FPSLabel;
leWidget* PlyrScrn_PanelWidget1;
leButtonWidget* PlyrScrn_UsbButton;
leButtonWidget* PlyrScrn_WifiButton;
leButtonWidget* PlyrScrn_BtButton;
leButtonWidget* PlyrScrn_AuxButton;
leButtonWidget* PlyrScrn_ButtonWidget5;
leButtonWidget* PlyrScrn_ButtonWidget6;
leLabelWidget* PlyrScrn_TrackArtist;
leLabelWidget* PlyrScrn_TrackTitle;
leLabelWidget* PlyrScrn_HrLabel;
leLabelWidget* PlyrScrn_ColonLabel;
leLabelWidget* PlyrScrn_MinLabel;
leWidget* PlyrScrn_VolPanelActive;
leWidget* PlyrScrn_VolPanelMax;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_PlyrScrn(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_PlyrScrn(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    PlyrScrn_PanelWidget0 = leWidget_New();
    PlyrScrn_PanelWidget0->fn->setPosition(PlyrScrn_PanelWidget0, 0, 0);
    PlyrScrn_PanelWidget0->fn->setSize(PlyrScrn_PanelWidget0, 480, 320);
    PlyrScrn_PanelWidget0->fn->setScheme(PlyrScrn_PanelWidget0, &PlayerBaseScheme);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_PanelWidget0);

    PlyrScrn_PanelWidget2 = leWidget_New();
    PlyrScrn_PanelWidget2->fn->setPosition(PlyrScrn_PanelWidget2, 0, 141);
    PlyrScrn_PanelWidget2->fn->setSize(PlyrScrn_PanelWidget2, 480, 80);
    PlyrScrn_PanelWidget2->fn->setScheme(PlyrScrn_PanelWidget2, &PlayerBarScheme);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_PanelWidget2);

    PlyrScrn_SourcePanel = leWidget_New();
    PlyrScrn_SourcePanel->fn->setPosition(PlyrScrn_SourcePanel, 160, 55);
    PlyrScrn_SourcePanel->fn->setSize(PlyrScrn_SourcePanel, 320, 70);
    PlyrScrn_SourcePanel->fn->setBackgroundType(PlyrScrn_SourcePanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_SourcePanel);

    PlyrScrn_PanelWidget1 = leWidget_New();
    PlyrScrn_PanelWidget1->fn->setPosition(PlyrScrn_PanelWidget1, 33, 16);
    PlyrScrn_PanelWidget1->fn->setSize(PlyrScrn_PanelWidget1, 287, 32);
    PlyrScrn_PanelWidget1->fn->setScheme(PlyrScrn_PanelWidget1, &PlayerBarScheme);
    PlyrScrn_SourcePanel->fn->addChild(PlyrScrn_SourcePanel, (leWidget*)PlyrScrn_PanelWidget1);

    PlyrScrn_UsbButton = leButtonWidget_New();
    PlyrScrn_UsbButton->fn->setPosition(PlyrScrn_UsbButton, 240, 1);
    PlyrScrn_UsbButton->fn->setSize(PlyrScrn_UsbButton, 80, 65);
    PlyrScrn_UsbButton->fn->setBackgroundType(PlyrScrn_UsbButton, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_UsbButton->fn->setBorderType(PlyrScrn_UsbButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_UsbButton->fn->setToggleable(PlyrScrn_UsbButton, LE_TRUE);
    PlyrScrn_UsbButton->fn->setPressedImage(PlyrScrn_UsbButton, (leImage*)&Plyr_USB60);
    PlyrScrn_UsbButton->fn->setReleasedImage(PlyrScrn_UsbButton, (leImage*)&Plyr_USB30);
    PlyrScrn_UsbButton->fn->setPressedEventCallback(PlyrScrn_UsbButton, event_PlyrScrn_UsbButton_OnPressed);
    PlyrScrn_SourcePanel->fn->addChild(PlyrScrn_SourcePanel, (leWidget*)PlyrScrn_UsbButton);

    PlyrScrn_WifiButton = leButtonWidget_New();
    PlyrScrn_WifiButton->fn->setPosition(PlyrScrn_WifiButton, 160, 1);
    PlyrScrn_WifiButton->fn->setSize(PlyrScrn_WifiButton, 80, 65);
    PlyrScrn_WifiButton->fn->setBackgroundType(PlyrScrn_WifiButton, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_WifiButton->fn->setBorderType(PlyrScrn_WifiButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_WifiButton->fn->setToggleable(PlyrScrn_WifiButton, LE_TRUE);
    PlyrScrn_WifiButton->fn->setPressedImage(PlyrScrn_WifiButton, (leImage*)&Plyr_WIFI60);
    PlyrScrn_WifiButton->fn->setReleasedImage(PlyrScrn_WifiButton, (leImage*)&Plyr_WIFI30);
    PlyrScrn_WifiButton->fn->setPressedEventCallback(PlyrScrn_WifiButton, event_PlyrScrn_WifiButton_OnPressed);
    PlyrScrn_SourcePanel->fn->addChild(PlyrScrn_SourcePanel, (leWidget*)PlyrScrn_WifiButton);

    PlyrScrn_BtButton = leButtonWidget_New();
    PlyrScrn_BtButton->fn->setPosition(PlyrScrn_BtButton, 80, 0);
    PlyrScrn_BtButton->fn->setSize(PlyrScrn_BtButton, 80, 65);
    PlyrScrn_BtButton->fn->setBackgroundType(PlyrScrn_BtButton, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_BtButton->fn->setBorderType(PlyrScrn_BtButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_BtButton->fn->setToggleable(PlyrScrn_BtButton, LE_TRUE);
    PlyrScrn_BtButton->fn->setPressedImage(PlyrScrn_BtButton, (leImage*)&Plyr_BT60);
    PlyrScrn_BtButton->fn->setReleasedImage(PlyrScrn_BtButton, (leImage*)&Plyr_BT30);
    PlyrScrn_BtButton->fn->setPressedEventCallback(PlyrScrn_BtButton, event_PlyrScrn_BtButton_OnPressed);
    PlyrScrn_SourcePanel->fn->addChild(PlyrScrn_SourcePanel, (leWidget*)PlyrScrn_BtButton);

    PlyrScrn_AuxButton = leButtonWidget_New();
    PlyrScrn_AuxButton->fn->setPosition(PlyrScrn_AuxButton, 0, 0);
    PlyrScrn_AuxButton->fn->setSize(PlyrScrn_AuxButton, 80, 65);
    PlyrScrn_AuxButton->fn->setBackgroundType(PlyrScrn_AuxButton, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_AuxButton->fn->setBorderType(PlyrScrn_AuxButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_AuxButton->fn->setToggleable(PlyrScrn_AuxButton, LE_TRUE);
    PlyrScrn_AuxButton->fn->setPressedImage(PlyrScrn_AuxButton, (leImage*)&Plyr_AUX60);
    PlyrScrn_AuxButton->fn->setReleasedImage(PlyrScrn_AuxButton, (leImage*)&Plyr_AUX30);
    PlyrScrn_AuxButton->fn->setPressedEventCallback(PlyrScrn_AuxButton, event_PlyrScrn_AuxButton_OnPressed);
    PlyrScrn_SourcePanel->fn->addChild(PlyrScrn_SourcePanel, (leWidget*)PlyrScrn_AuxButton);

    PlyrScrn_ControlPanel = leWidget_New();
    PlyrScrn_ControlPanel->fn->setPosition(PlyrScrn_ControlPanel, 0, 128);
    PlyrScrn_ControlPanel->fn->setSize(PlyrScrn_ControlPanel, 480, 110);
    PlyrScrn_ControlPanel->fn->setBackgroundType(PlyrScrn_ControlPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_ControlPanel);

    PlyrScrn_ButtonWidget5 = leButtonWidget_New();
    PlyrScrn_ButtonWidget5->fn->setPosition(PlyrScrn_ButtonWidget5, 339, 2);
    PlyrScrn_ButtonWidget5->fn->setSize(PlyrScrn_ButtonWidget5, 100, 102);
    PlyrScrn_ButtonWidget5->fn->setBackgroundType(PlyrScrn_ButtonWidget5, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_ButtonWidget5->fn->setBorderType(PlyrScrn_ButtonWidget5, LE_WIDGET_BORDER_NONE);
    PlyrScrn_ButtonWidget5->fn->setToggleable(PlyrScrn_ButtonWidget5, LE_TRUE);
    PlyrScrn_ButtonWidget5->fn->setPressedImage(PlyrScrn_ButtonWidget5, (leImage*)&Plyr_Pause100);
    PlyrScrn_ButtonWidget5->fn->setReleasedImage(PlyrScrn_ButtonWidget5, (leImage*)&Plyr_Play100);
    PlyrScrn_ButtonWidget5->fn->setPressedOffset(PlyrScrn_ButtonWidget5, 0);
    PlyrScrn_ControlPanel->fn->addChild(PlyrScrn_ControlPanel, (leWidget*)PlyrScrn_ButtonWidget5);

    PlyrScrn_ButtonWidget6 = leButtonWidget_New();
    PlyrScrn_ButtonWidget6->fn->setPosition(PlyrScrn_ButtonWidget6, 0, 12);
    PlyrScrn_ButtonWidget6->fn->setSize(PlyrScrn_ButtonWidget6, 66, 80);
    PlyrScrn_ButtonWidget6->fn->setBackgroundType(PlyrScrn_ButtonWidget6, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_ButtonWidget6->fn->setBorderType(PlyrScrn_ButtonWidget6, LE_WIDGET_BORDER_NONE);
    PlyrScrn_ButtonWidget6->fn->setPressedImage(PlyrScrn_ButtonWidget6, (leImage*)&Plyr_Bars);
    PlyrScrn_ButtonWidget6->fn->setReleasedImage(PlyrScrn_ButtonWidget6, (leImage*)&Plyr_Bars);
    PlyrScrn_ButtonWidget6->fn->setPressedOffset(PlyrScrn_ButtonWidget6, 0);
    PlyrScrn_ControlPanel->fn->addChild(PlyrScrn_ControlPanel, (leWidget*)PlyrScrn_ButtonWidget6);

    PlyrScrn_TrackArtist = leLabelWidget_New();
    PlyrScrn_TrackArtist->fn->setPosition(PlyrScrn_TrackArtist, 225, 59);
    PlyrScrn_TrackArtist->fn->setSize(PlyrScrn_TrackArtist, 81, 24);
    PlyrScrn_TrackArtist->fn->setScheme(PlyrScrn_TrackArtist, &PlayerBarScheme);
    PlyrScrn_TrackArtist->fn->setBackgroundType(PlyrScrn_TrackArtist, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_TrackArtist->fn->setString(PlyrScrn_TrackArtist, (leString*)&string_Artist);
    PlyrScrn_ControlPanel->fn->addChild(PlyrScrn_ControlPanel, (leWidget*)PlyrScrn_TrackArtist);

    PlyrScrn_TrackTitle = leLabelWidget_New();
    PlyrScrn_TrackTitle->fn->setPosition(PlyrScrn_TrackTitle, 118, 20);
    PlyrScrn_TrackTitle->fn->setSize(PlyrScrn_TrackTitle, 191, 40);
    PlyrScrn_TrackTitle->fn->setScheme(PlyrScrn_TrackTitle, &PlayerBaseScheme);
    PlyrScrn_TrackTitle->fn->setBackgroundType(PlyrScrn_TrackTitle, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_TrackTitle->fn->setString(PlyrScrn_TrackTitle, (leString*)&string_TrackTitle);
    PlyrScrn_ControlPanel->fn->addChild(PlyrScrn_ControlPanel, (leWidget*)PlyrScrn_TrackTitle);

    PlyrScrn_HomeButton = leButtonWidget_New();
    PlyrScrn_HomeButton->fn->setPosition(PlyrScrn_HomeButton, 400, 0);
    PlyrScrn_HomeButton->fn->setSize(PlyrScrn_HomeButton, 80, 50);
    PlyrScrn_HomeButton->fn->setScheme(PlyrScrn_HomeButton, &PlayerVolScheme);
    PlyrScrn_HomeButton->fn->setBorderType(PlyrScrn_HomeButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_HomeButton->fn->setPressedImage(PlyrScrn_HomeButton, (leImage*)&Home565Gray);
    PlyrScrn_HomeButton->fn->setReleasedImage(PlyrScrn_HomeButton, (leImage*)&Home565Gray);
    PlyrScrn_HomeButton->fn->setPressedEventCallback(PlyrScrn_HomeButton, event_PlyrScrn_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_HomeButton);

    PlyrScrn_ImageWidget0 = leImageWidget_New();
    PlyrScrn_ImageWidget0->fn->setPosition(PlyrScrn_ImageWidget0, 2, 3);
    PlyrScrn_ImageWidget0->fn->setSize(PlyrScrn_ImageWidget0, 153, 31);
    PlyrScrn_ImageWidget0->fn->setBackgroundType(PlyrScrn_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_ImageWidget0->fn->setBorderType(PlyrScrn_ImageWidget0, LE_WIDGET_BORDER_NONE);
    PlyrScrn_ImageWidget0->fn->setImage(PlyrScrn_ImageWidget0, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_ImageWidget0);

    PlyrScrn_ClockPanel = leWidget_New();
    PlyrScrn_ClockPanel->fn->setPosition(PlyrScrn_ClockPanel, 182, 0);
    PlyrScrn_ClockPanel->fn->setSize(PlyrScrn_ClockPanel, 133, 42);
    PlyrScrn_ClockPanel->fn->setBackgroundType(PlyrScrn_ClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_ClockPanel);

    PlyrScrn_HrLabel = leLabelWidget_New();
    PlyrScrn_HrLabel->fn->setPosition(PlyrScrn_HrLabel, -5, -5);
    PlyrScrn_HrLabel->fn->setSize(PlyrScrn_HrLabel, 51, 60);
    PlyrScrn_HrLabel->fn->setScheme(PlyrScrn_HrLabel, &WhiteTextScheme);
    PlyrScrn_HrLabel->fn->setBackgroundType(PlyrScrn_HrLabel, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_HrLabel->fn->setHAlignment(PlyrScrn_HrLabel, LE_HALIGN_RIGHT);
    PlyrScrn_HrLabel->fn->setString(PlyrScrn_HrLabel, (leString*)&string_DefaultHour3);
    PlyrScrn_ClockPanel->fn->addChild(PlyrScrn_ClockPanel, (leWidget*)PlyrScrn_HrLabel);

    PlyrScrn_ColonLabel = leLabelWidget_New();
    PlyrScrn_ColonLabel->fn->setPosition(PlyrScrn_ColonLabel, 46, 11);
    PlyrScrn_ColonLabel->fn->setSize(PlyrScrn_ColonLabel, 20, 30);
    PlyrScrn_ColonLabel->fn->setScheme(PlyrScrn_ColonLabel, &WhiteTextScheme);
    PlyrScrn_ColonLabel->fn->setBackgroundType(PlyrScrn_ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_ColonLabel->fn->setString(PlyrScrn_ColonLabel, (leString*)&string_Colon3);
    PlyrScrn_ClockPanel->fn->addChild(PlyrScrn_ClockPanel, (leWidget*)PlyrScrn_ColonLabel);

    PlyrScrn_MinLabel = leLabelWidget_New();
    PlyrScrn_MinLabel->fn->setPosition(PlyrScrn_MinLabel, 57, 12);
    PlyrScrn_MinLabel->fn->setSize(PlyrScrn_MinLabel, 80, 30);
    PlyrScrn_MinLabel->fn->setScheme(PlyrScrn_MinLabel, &WhiteTextScheme);
    PlyrScrn_MinLabel->fn->setBackgroundType(PlyrScrn_MinLabel, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_MinLabel->fn->setString(PlyrScrn_MinLabel, (leString*)&string_DefaultMinute3);
    PlyrScrn_ClockPanel->fn->addChild(PlyrScrn_ClockPanel, (leWidget*)PlyrScrn_MinLabel);

    PlyrScrn_VolPanel = leWidget_New();
    PlyrScrn_VolPanel->fn->setPosition(PlyrScrn_VolPanel, 0, 241);
    PlyrScrn_VolPanel->fn->setSize(PlyrScrn_VolPanel, 270, 60);
    PlyrScrn_VolPanel->fn->setBackgroundType(PlyrScrn_VolPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_VolPanel);

    PlyrScrn_VolPanelActive = leWidget_New();
    PlyrScrn_VolPanelActive->fn->setPosition(PlyrScrn_VolPanelActive, 0, 20);
    PlyrScrn_VolPanelActive->fn->setSize(PlyrScrn_VolPanelActive, 270, 20);
    PlyrScrn_VolPanelActive->fn->setEnabled(PlyrScrn_VolPanelActive, LE_FALSE);
    PlyrScrn_VolPanelActive->fn->setScheme(PlyrScrn_VolPanelActive, &PlayerBarScheme);
    PlyrScrn_VolPanel->fn->addChild(PlyrScrn_VolPanel, (leWidget*)PlyrScrn_VolPanelActive);

    PlyrScrn_VolPanelMax = leWidget_New();
    PlyrScrn_VolPanelMax->fn->setPosition(PlyrScrn_VolPanelMax, 27, 20);
    PlyrScrn_VolPanelMax->fn->setSize(PlyrScrn_VolPanelMax, 269, 20);
    PlyrScrn_VolPanelMax->fn->setEnabled(PlyrScrn_VolPanelMax, LE_FALSE);
    PlyrScrn_VolPanelMax->fn->setScheme(PlyrScrn_VolPanelMax, &PlayerVolScheme);
    PlyrScrn_VolPanel->fn->addChild(PlyrScrn_VolPanel, (leWidget*)PlyrScrn_VolPanelMax);

    PlyrScrn_VolumeButton = leButtonWidget_New();
    PlyrScrn_VolumeButton->fn->setPosition(PlyrScrn_VolumeButton, 10, 253);
    PlyrScrn_VolumeButton->fn->setSize(PlyrScrn_VolumeButton, 36, 35);
    PlyrScrn_VolumeButton->fn->setBackgroundType(PlyrScrn_VolumeButton, LE_WIDGET_BACKGROUND_NONE);
    PlyrScrn_VolumeButton->fn->setBorderType(PlyrScrn_VolumeButton, LE_WIDGET_BORDER_NONE);
    PlyrScrn_VolumeButton->fn->setPressedImage(PlyrScrn_VolumeButton, (leImage*)&Plyr_Vol30_solid);
    PlyrScrn_VolumeButton->fn->setReleasedImage(PlyrScrn_VolumeButton, (leImage*)&Plyr_Vol30_solid);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_VolumeButton);

    PlyrScrn_VolPanelButton = leWidget_New();
    PlyrScrn_VolPanelButton->fn->setPosition(PlyrScrn_VolPanelButton, 0, 224);
    PlyrScrn_VolPanelButton->fn->setSize(PlyrScrn_VolPanelButton, 270, 94);
    PlyrScrn_VolPanelButton->fn->setBackgroundType(PlyrScrn_VolPanelButton, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_VolPanelButton);

    PlyrScrn_FPSLabel = leLabelWidget_New();
    PlyrScrn_FPSLabel->fn->setPosition(PlyrScrn_FPSLabel, 406, 289);
    PlyrScrn_FPSLabel->fn->setSize(PlyrScrn_FPSLabel, 70, 27);
    PlyrScrn_FPSLabel->fn->setScheme(PlyrScrn_FPSLabel, &WhiteTextScheme);
    PlyrScrn_FPSLabel->fn->setBackgroundType(PlyrScrn_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)PlyrScrn_FPSLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    PlyrScrn_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_PlyrScrn(void)
{
    PlyrScrn_OnUpdate(); // raise event
}

void screenHide_PlyrScrn(void)
{
    PlyrScrn_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    PlyrScrn_PanelWidget0 = NULL;
    PlyrScrn_PanelWidget2 = NULL;
    PlyrScrn_SourcePanel = NULL;
    PlyrScrn_ControlPanel = NULL;
    PlyrScrn_HomeButton = NULL;
    PlyrScrn_ImageWidget0 = NULL;
    PlyrScrn_ClockPanel = NULL;
    PlyrScrn_VolPanel = NULL;
    PlyrScrn_VolumeButton = NULL;
    PlyrScrn_VolPanelButton = NULL;
    PlyrScrn_FPSLabel = NULL;
    PlyrScrn_PanelWidget1 = NULL;
    PlyrScrn_UsbButton = NULL;
    PlyrScrn_WifiButton = NULL;
    PlyrScrn_BtButton = NULL;
    PlyrScrn_AuxButton = NULL;
    PlyrScrn_ButtonWidget5 = NULL;
    PlyrScrn_ButtonWidget6 = NULL;
    PlyrScrn_TrackArtist = NULL;
    PlyrScrn_TrackTitle = NULL;
    PlyrScrn_HrLabel = NULL;
    PlyrScrn_ColonLabel = NULL;
    PlyrScrn_MinLabel = NULL;
    PlyrScrn_VolPanelActive = NULL;
    PlyrScrn_VolPanelMax = NULL;


    showing = LE_FALSE;
}

void screenDestroy_PlyrScrn(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_PlyrScrn(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

