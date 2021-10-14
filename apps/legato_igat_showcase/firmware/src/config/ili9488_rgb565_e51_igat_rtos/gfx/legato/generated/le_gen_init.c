#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_Intro();
    screenInit_CkrScrn1();
    screenInit_CkrScrn2();
    screenInit_Menu();
    screenInit_PlyrScrn();
    screenInit_CCtrlScrn1();
    screenInit_MGScrn();
    screenInit_Settings();
    screenInit_Info();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_Intro);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Intro:
        {
            screenHide_Intro();
            currentScreen = 0;
            break;
        }
        case screenID_CkrScrn1:
        {
            screenHide_CkrScrn1();
            currentScreen = 0;
            break;
        }
        case screenID_CkrScrn2:
        {
            screenHide_CkrScrn2();
            currentScreen = 0;
            break;
        }
        case screenID_Menu:
        {
            screenHide_Menu();
            currentScreen = 0;
            break;
        }
        case screenID_PlyrScrn:
        {
            screenHide_PlyrScrn();
            currentScreen = 0;
            break;
        }
        case screenID_CCtrlScrn1:
        {
            screenHide_CCtrlScrn1();
            currentScreen = 0;
            break;
        }
        case screenID_MGScrn:
        {
            screenHide_MGScrn();
            currentScreen = 0;
            break;
        }
        case screenID_Settings:
        {
            screenHide_Settings();
            currentScreen = 0;
            break;
        }
        case screenID_Info:
        {
            screenHide_Info();
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
            case screenID_Intro:
            {
                screenShow_Intro();
                break;
            }
            case screenID_CkrScrn1:
            {
                screenShow_CkrScrn1();
                break;
            }
            case screenID_CkrScrn2:
            {
                screenShow_CkrScrn2();
                break;
            }
            case screenID_Menu:
            {
                screenShow_Menu();
                break;
            }
            case screenID_PlyrScrn:
            {
                screenShow_PlyrScrn();
                break;
            }
            case screenID_CCtrlScrn1:
            {
                screenShow_CCtrlScrn1();
                break;
            }
            case screenID_MGScrn:
            {
                screenShow_MGScrn();
                break;
            }
            case screenID_Settings:
            {
                screenShow_Settings();
                break;
            }
            case screenID_Info:
            {
                screenShow_Info();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_Intro:
        {
            screenUpdate_Intro();
            break;
        }
        case screenID_CkrScrn1:
        {
            screenUpdate_CkrScrn1();
            break;
        }
        case screenID_CkrScrn2:
        {
            screenUpdate_CkrScrn2();
            break;
        }
        case screenID_Menu:
        {
            screenUpdate_Menu();
            break;
        }
        case screenID_PlyrScrn:
        {
            screenUpdate_PlyrScrn();
            break;
        }
        case screenID_CCtrlScrn1:
        {
            screenUpdate_CCtrlScrn1();
            break;
        }
        case screenID_MGScrn:
        {
            screenUpdate_MGScrn();
            break;
        }
        case screenID_Settings:
        {
            screenUpdate_Settings();
            break;
        }
        case screenID_Info:
        {
            screenUpdate_Info();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

