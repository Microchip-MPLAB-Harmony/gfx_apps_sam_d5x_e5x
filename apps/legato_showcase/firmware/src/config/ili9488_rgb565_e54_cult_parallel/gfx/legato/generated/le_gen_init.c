#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_SplashScreen();
    screenInit_MainMenu();
    screenInit_ListWheelDemoScreen();
    screenInit_TouchTestDemoScreen();
    screenInit_KeypadDemoScreen();
    screenInit_AlphaBlendingDemoScreen();
    screenInit_SlideShowDemoScreen();
    screenInit_SettingsScreen();
    screenInit_MainMenuHelp();
    screenInit_ListWheelHelpScreen();
    screenInit_TouchTestHelpScreen();
    screenInit_KeypadHelpScreen();
    screenInit_AlphaBlendingHelpScreen();
    screenInit_SlideshowHelpScreen();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_SplashScreen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenHide_SplashScreen();
            currentScreen = 0;
            break;
        }
        case screenID_MainMenu:
        {
            screenHide_MainMenu();
            currentScreen = 0;
            break;
        }
        case screenID_ListWheelDemoScreen:
        {
            screenHide_ListWheelDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_TouchTestDemoScreen:
        {
            screenHide_TouchTestDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_KeypadDemoScreen:
        {
            screenHide_KeypadDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_AlphaBlendingDemoScreen:
        {
            screenHide_AlphaBlendingDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SlideShowDemoScreen:
        {
            screenHide_SlideShowDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SettingsScreen:
        {
            screenHide_SettingsScreen();
            currentScreen = 0;
            break;
        }
        case screenID_MainMenuHelp:
        {
            screenHide_MainMenuHelp();
            currentScreen = 0;
            break;
        }
        case screenID_ListWheelHelpScreen:
        {
            screenHide_ListWheelHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_TouchTestHelpScreen:
        {
            screenHide_TouchTestHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_KeypadHelpScreen:
        {
            screenHide_KeypadHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_AlphaBlendingHelpScreen:
        {
            screenHide_AlphaBlendingHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SlideshowHelpScreen:
        {
            screenHide_SlideshowHelpScreen();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    if(changingToScreen >= 0)
        return;

    changingToScreen = id;
}

void legato_updateScreenState(void)
{
    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_SplashScreen:
            {
                screenShow_SplashScreen();
                break;
            }
            case screenID_MainMenu:
            {
                screenShow_MainMenu();
                break;
            }
            case screenID_ListWheelDemoScreen:
            {
                screenShow_ListWheelDemoScreen();
                break;
            }
            case screenID_TouchTestDemoScreen:
            {
                screenShow_TouchTestDemoScreen();
                break;
            }
            case screenID_KeypadDemoScreen:
            {
                screenShow_KeypadDemoScreen();
                break;
            }
            case screenID_AlphaBlendingDemoScreen:
            {
                screenShow_AlphaBlendingDemoScreen();
                break;
            }
            case screenID_SlideShowDemoScreen:
            {
                screenShow_SlideShowDemoScreen();
                break;
            }
            case screenID_SettingsScreen:
            {
                screenShow_SettingsScreen();
                break;
            }
            case screenID_MainMenuHelp:
            {
                screenShow_MainMenuHelp();
                break;
            }
            case screenID_ListWheelHelpScreen:
            {
                screenShow_ListWheelHelpScreen();
                break;
            }
            case screenID_TouchTestHelpScreen:
            {
                screenShow_TouchTestHelpScreen();
                break;
            }
            case screenID_KeypadHelpScreen:
            {
                screenShow_KeypadHelpScreen();
                break;
            }
            case screenID_AlphaBlendingHelpScreen:
            {
                screenShow_AlphaBlendingHelpScreen();
                break;
            }
            case screenID_SlideshowHelpScreen:
            {
                screenShow_SlideshowHelpScreen();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenUpdate_SplashScreen();
            break;
        }
        case screenID_MainMenu:
        {
            screenUpdate_MainMenu();
            break;
        }
        case screenID_ListWheelDemoScreen:
        {
            screenUpdate_ListWheelDemoScreen();
            break;
        }
        case screenID_TouchTestDemoScreen:
        {
            screenUpdate_TouchTestDemoScreen();
            break;
        }
        case screenID_KeypadDemoScreen:
        {
            screenUpdate_KeypadDemoScreen();
            break;
        }
        case screenID_AlphaBlendingDemoScreen:
        {
            screenUpdate_AlphaBlendingDemoScreen();
            break;
        }
        case screenID_SlideShowDemoScreen:
        {
            screenUpdate_SlideShowDemoScreen();
            break;
        }
        case screenID_SettingsScreen:
        {
            screenUpdate_SettingsScreen();
            break;
        }
        case screenID_MainMenuHelp:
        {
            screenUpdate_MainMenuHelp();
            break;
        }
        case screenID_ListWheelHelpScreen:
        {
            screenUpdate_ListWheelHelpScreen();
            break;
        }
        case screenID_TouchTestHelpScreen:
        {
            screenUpdate_TouchTestHelpScreen();
            break;
        }
        case screenID_KeypadHelpScreen:
        {
            screenUpdate_KeypadHelpScreen();
            break;
        }
        case screenID_AlphaBlendingHelpScreen:
        {
            screenUpdate_AlphaBlendingHelpScreen();
            break;
        }
        case screenID_SlideshowHelpScreen:
        {
            screenUpdate_SlideshowHelpScreen();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

