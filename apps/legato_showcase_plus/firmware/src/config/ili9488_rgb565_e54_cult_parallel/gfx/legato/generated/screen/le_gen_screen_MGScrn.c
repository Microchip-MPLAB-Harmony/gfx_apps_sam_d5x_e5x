#include "gfx/legato/generated/screen/le_gen_screen_MGScrn.h"

// screen member widget declarations
static leWidget* root0;

leWidget* MGScrn_PanelWidget3;
leWidget* MGScrn_PanelWidget2;
leWidget* MGScrn_PanelWidget1;
leWidget* MGScrn_PanelWidget0;
leButtonWidget* MGScrn_HomeButton;
leDrawSurfaceWidget* MGScrn_DrawSurfaceWidget0;
leImageWidget* MGScrn_GestureImageWidget;
leLabelWidget* MGScrn_FPSLabel;
leImageWidget* MGScrn_ImageWidget0;
leLabelWidget* MGScrn_LabelWidget0;
leButtonWidget* MGScrn_TouchModeButton;
leImageWidget* MGScrn_MGLogoImageWidget;
leLabelWidget* MGScrn_DrawInstructionLabel;
leImageWidget* MGScrn_MG_Gestures;
leLabelWidget* MGScrn_MGLicenseLabel;
leImageSequenceWidget* MGScrn_ImageSequenceWidget0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MGScrn(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MGScrn(void)
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

    MGScrn_PanelWidget3 = leWidget_New();
    MGScrn_PanelWidget3->fn->setPosition(MGScrn_PanelWidget3, 472, 47);
    MGScrn_PanelWidget3->fn->setSize(MGScrn_PanelWidget3, 8, 273);
    MGScrn_PanelWidget3->fn->setScheme(MGScrn_PanelWidget3, &MGScheme);
    root0->fn->addChild(root0, (leWidget*)MGScrn_PanelWidget3);

    MGScrn_PanelWidget2 = leWidget_New();
    MGScrn_PanelWidget2->fn->setPosition(MGScrn_PanelWidget2, 59, 280);
    MGScrn_PanelWidget2->fn->setSize(MGScrn_PanelWidget2, 413, 40);
    MGScrn_PanelWidget2->fn->setScheme(MGScrn_PanelWidget2, &MGScheme);
    root0->fn->addChild(root0, (leWidget*)MGScrn_PanelWidget2);

    MGScrn_PanelWidget1 = leWidget_New();
    MGScrn_PanelWidget1->fn->setPosition(MGScrn_PanelWidget1, 60, -1);
    MGScrn_PanelWidget1->fn->setSize(MGScrn_PanelWidget1, 412, 61);
    MGScrn_PanelWidget1->fn->setScheme(MGScrn_PanelWidget1, &MGScheme);
    root0->fn->addChild(root0, (leWidget*)MGScrn_PanelWidget1);

    MGScrn_PanelWidget0 = leWidget_New();
    MGScrn_PanelWidget0->fn->setPosition(MGScrn_PanelWidget0, 0, 0);
    MGScrn_PanelWidget0->fn->setSize(MGScrn_PanelWidget0, 115, 320);
    MGScrn_PanelWidget0->fn->setScheme(MGScrn_PanelWidget0, &MGScheme);
    root0->fn->addChild(root0, (leWidget*)MGScrn_PanelWidget0);

    MGScrn_HomeButton = leButtonWidget_New();
    MGScrn_HomeButton->fn->setPosition(MGScrn_HomeButton, 400, 0);
    MGScrn_HomeButton->fn->setSize(MGScrn_HomeButton, 80, 50);
    MGScrn_HomeButton->fn->setScheme(MGScrn_HomeButton, &PlayerVolScheme);
    MGScrn_HomeButton->fn->setBorderType(MGScrn_HomeButton, LE_WIDGET_BORDER_NONE);
    MGScrn_HomeButton->fn->setPressedImage(MGScrn_HomeButton, (leImage*)&Home565Gray);
    MGScrn_HomeButton->fn->setReleasedImage(MGScrn_HomeButton, (leImage*)&Home565Gray);
    MGScrn_HomeButton->fn->setPressedOffset(MGScrn_HomeButton, 0);
    MGScrn_HomeButton->fn->setPressedEventCallback(MGScrn_HomeButton, event_MGScrn_HomeButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)MGScrn_HomeButton);

    MGScrn_DrawSurfaceWidget0 = leDrawSurfaceWidget_New();
    MGScrn_DrawSurfaceWidget0->fn->setPosition(MGScrn_DrawSurfaceWidget0, 115, 60);
    MGScrn_DrawSurfaceWidget0->fn->setSize(MGScrn_DrawSurfaceWidget0, 360, 220);
    MGScrn_DrawSurfaceWidget0->fn->setScheme(MGScrn_DrawSurfaceWidget0, &WhiteBackgroundScheme);
    MGScrn_DrawSurfaceWidget0->fn->setBackgroundType(MGScrn_DrawSurfaceWidget0, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_DrawSurfaceWidget0->fn->setBorderType(MGScrn_DrawSurfaceWidget0, LE_WIDGET_BORDER_LINE);
    MGScrn_DrawSurfaceWidget0->fn->setDrawCallback(MGScrn_DrawSurfaceWidget0, event_MGScrn_DrawSurfaceWidget0_OnDraw);
    root0->fn->addChild(root0, (leWidget*)MGScrn_DrawSurfaceWidget0);

    MGScrn_GestureImageWidget = leImageWidget_New();
    MGScrn_GestureImageWidget->fn->setPosition(MGScrn_GestureImageWidget, 116, 61);
    MGScrn_GestureImageWidget->fn->setSize(MGScrn_GestureImageWidget, 358, 218);
    MGScrn_GestureImageWidget->fn->setEnabled(MGScrn_GestureImageWidget, LE_FALSE);
    MGScrn_GestureImageWidget->fn->setScheme(MGScrn_GestureImageWidget, &WhiteBackgroundScheme);
    MGScrn_GestureImageWidget->fn->setBorderType(MGScrn_GestureImageWidget, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)MGScrn_GestureImageWidget);

    MGScrn_FPSLabel = leLabelWidget_New();
    MGScrn_FPSLabel->fn->setPosition(MGScrn_FPSLabel, 17, 285);
    MGScrn_FPSLabel->fn->setSize(MGScrn_FPSLabel, 63, 25);
    MGScrn_FPSLabel->fn->setBackgroundType(MGScrn_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)MGScrn_FPSLabel);

    MGScrn_ImageWidget0 = leImageWidget_New();
    MGScrn_ImageWidget0->fn->setPosition(MGScrn_ImageWidget0, 0, 0);
    MGScrn_ImageWidget0->fn->setSize(MGScrn_ImageWidget0, 154, 32);
    MGScrn_ImageWidget0->fn->setBackgroundType(MGScrn_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_ImageWidget0->fn->setBorderType(MGScrn_ImageWidget0, LE_WIDGET_BORDER_NONE);
    MGScrn_ImageWidget0->fn->setImage(MGScrn_ImageWidget0, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)MGScrn_ImageWidget0);

    MGScrn_LabelWidget0 = leLabelWidget_New();
    MGScrn_LabelWidget0->fn->setPosition(MGScrn_LabelWidget0, 8, 32);
    MGScrn_LabelWidget0->fn->setSize(MGScrn_LabelWidget0, 170, 25);
    MGScrn_LabelWidget0->fn->setBackgroundType(MGScrn_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_LabelWidget0->fn->setString(MGScrn_LabelWidget0, (leString*)&string_TouchTitle);
    root0->fn->addChild(root0, (leWidget*)MGScrn_LabelWidget0);

    MGScrn_TouchModeButton = leButtonWidget_New();
    MGScrn_TouchModeButton->fn->setPosition(MGScrn_TouchModeButton, 3, 59);
    MGScrn_TouchModeButton->fn->setSize(MGScrn_TouchModeButton, 110, 110);
    MGScrn_TouchModeButton->fn->setBackgroundType(MGScrn_TouchModeButton, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_TouchModeButton->fn->setBorderType(MGScrn_TouchModeButton, LE_WIDGET_BORDER_NONE);
    MGScrn_TouchModeButton->fn->setReleasedEventCallback(MGScrn_TouchModeButton, event_MGScrn_TouchModeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MGScrn_TouchModeButton);

    MGScrn_ImageSequenceWidget0 = leImageSequenceWidget_New();
    MGScrn_ImageSequenceWidget0->fn->setPosition(MGScrn_ImageSequenceWidget0, 5, 0);
    MGScrn_ImageSequenceWidget0->fn->setSize(MGScrn_ImageSequenceWidget0, 100, 104);
    MGScrn_ImageSequenceWidget0->fn->setEnabled(MGScrn_ImageSequenceWidget0, LE_FALSE);
    MGScrn_ImageSequenceWidget0->fn->setBackgroundType(MGScrn_ImageSequenceWidget0, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_ImageSequenceWidget0->fn->setImageCount(MGScrn_ImageSequenceWidget0, 3);
    MGScrn_ImageSequenceWidget0->fn->setImage(MGScrn_ImageSequenceWidget0, 0, &Touch2D);
    MGScrn_ImageSequenceWidget0->fn->setImageDelay(MGScrn_ImageSequenceWidget0, 0, 1000);
    MGScrn_ImageSequenceWidget0->fn->setImage(MGScrn_ImageSequenceWidget0, 1, &TouchGesture);
    MGScrn_ImageSequenceWidget0->fn->setImageDelay(MGScrn_ImageSequenceWidget0, 1, 1000);
    MGScrn_ImageSequenceWidget0->fn->setImage(MGScrn_ImageSequenceWidget0, 2, &TouchML);
    MGScrn_ImageSequenceWidget0->fn->setImageDelay(MGScrn_ImageSequenceWidget0, 2, 1000);
    MGScrn_TouchModeButton->fn->addChild(MGScrn_TouchModeButton, (leWidget*)MGScrn_ImageSequenceWidget0);

    MGScrn_MGLogoImageWidget = leImageWidget_New();
    MGScrn_MGLogoImageWidget->fn->setPosition(MGScrn_MGLogoImageWidget, 198, 1);
    MGScrn_MGLogoImageWidget->fn->setSize(MGScrn_MGLogoImageWidget, 180, 51);
    MGScrn_MGLogoImageWidget->fn->setEnabled(MGScrn_MGLogoImageWidget, LE_FALSE);
    MGScrn_MGLogoImageWidget->fn->setVisible(MGScrn_MGLogoImageWidget, LE_FALSE);
    MGScrn_MGLogoImageWidget->fn->setBackgroundType(MGScrn_MGLogoImageWidget, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_MGLogoImageWidget->fn->setBorderType(MGScrn_MGLogoImageWidget, LE_WIDGET_BORDER_NONE);
    MGScrn_MGLogoImageWidget->fn->setImage(MGScrn_MGLogoImageWidget, (leImage*)&MG_Horiz);
    root0->fn->addChild(root0, (leWidget*)MGScrn_MGLogoImageWidget);

    MGScrn_DrawInstructionLabel = leLabelWidget_New();
    MGScrn_DrawInstructionLabel->fn->setPosition(MGScrn_DrawInstructionLabel, 116, 61);
    MGScrn_DrawInstructionLabel->fn->setSize(MGScrn_DrawInstructionLabel, 358, 218);
    MGScrn_DrawInstructionLabel->fn->setEnabled(MGScrn_DrawInstructionLabel, LE_FALSE);
    MGScrn_DrawInstructionLabel->fn->setScheme(MGScrn_DrawInstructionLabel, &MGScheme);
    MGScrn_DrawInstructionLabel->fn->setHAlignment(MGScrn_DrawInstructionLabel, LE_HALIGN_CENTER);
    MGScrn_DrawInstructionLabel->fn->setVAlignment(MGScrn_DrawInstructionLabel, LE_VALIGN_TOP);
    MGScrn_DrawInstructionLabel->fn->setString(MGScrn_DrawInstructionLabel, (leString*)&string_MotionInstruction);
    root0->fn->addChild(root0, (leWidget*)MGScrn_DrawInstructionLabel);

    MGScrn_MG_Gestures = leImageWidget_New();
    MGScrn_MG_Gestures->fn->setPosition(MGScrn_MG_Gestures, 118, 98);
    MGScrn_MG_Gestures->fn->setSize(MGScrn_MG_Gestures, 354, 170);
    MGScrn_MG_Gestures->fn->setEnabled(MGScrn_MG_Gestures, LE_FALSE);
    MGScrn_MG_Gestures->fn->setVisible(MGScrn_MG_Gestures, LE_FALSE);
    MGScrn_MG_Gestures->fn->setBackgroundType(MGScrn_MG_Gestures, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_MG_Gestures->fn->setBorderType(MGScrn_MG_Gestures, LE_WIDGET_BORDER_NONE);
    MGScrn_MG_Gestures->fn->setImage(MGScrn_MG_Gestures, (leImage*)&gestures);
    root0->fn->addChild(root0, (leWidget*)MGScrn_MG_Gestures);

    MGScrn_MGLicenseLabel = leLabelWidget_New();
    MGScrn_MGLicenseLabel->fn->setPosition(MGScrn_MGLicenseLabel, 63, 284);
    MGScrn_MGLicenseLabel->fn->setSize(MGScrn_MGLicenseLabel, 401, 31);
    MGScrn_MGLicenseLabel->fn->setEnabled(MGScrn_MGLicenseLabel, LE_FALSE);
    MGScrn_MGLicenseLabel->fn->setVisible(MGScrn_MGLicenseLabel, LE_FALSE);
    MGScrn_MGLicenseLabel->fn->setBackgroundType(MGScrn_MGLicenseLabel, LE_WIDGET_BACKGROUND_NONE);
    MGScrn_MGLicenseLabel->fn->setString(MGScrn_MGLicenseLabel, (leString*)&string_MotionGesturesInfo);
    root0->fn->addChild(root0, (leWidget*)MGScrn_MGLicenseLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MGScrn_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MGScrn(void)
{
    root0->fn->setSize(root0, root0->parent->rect.width, root0->parent->rect.height);

    MGScrn_OnUpdate(); // raise event
}

void screenHide_MGScrn(void)
{
    MGScrn_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MGScrn_PanelWidget3 = NULL;
    MGScrn_PanelWidget2 = NULL;
    MGScrn_PanelWidget1 = NULL;
    MGScrn_PanelWidget0 = NULL;
    MGScrn_HomeButton = NULL;
    MGScrn_DrawSurfaceWidget0 = NULL;
    MGScrn_GestureImageWidget = NULL;
    MGScrn_FPSLabel = NULL;
    MGScrn_ImageWidget0 = NULL;
    MGScrn_LabelWidget0 = NULL;
    MGScrn_TouchModeButton = NULL;
    MGScrn_MGLogoImageWidget = NULL;
    MGScrn_DrawInstructionLabel = NULL;
    MGScrn_MG_Gestures = NULL;
    MGScrn_MGLicenseLabel = NULL;
    MGScrn_ImageSequenceWidget0 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MGScrn(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_MGScrn(uint32_t lyrIdx)
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

