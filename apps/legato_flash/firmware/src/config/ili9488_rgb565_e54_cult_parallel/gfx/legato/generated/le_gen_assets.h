/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// DOM-IGNORE-END

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   mchpLogo
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_332
 ***********************************/
extern leImage mchpLogo;

/*********************************
 * Legato Image Asset
 * Name:   sdcard_sm
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage sdcard_sm;

/*********************************
 * Legato Image Asset
 * Name:   usb_icon_sm
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage usb_icon_sm;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small
 * Size:   141x132 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage MHGS_logo_small;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       21
 * Baseline:     15
 * Style:        Antialias
 * Glyph Count:  28
 * Range Count:  13
 * Glyph Ranges: 0x20
                 0x41-0x44
                 0x46
                 0x4C-0x4D
                 0x4F
                 0x53
                 0x55
                 0x61
                 0x63-0x65
                 0x67-0x69
                 0x6B-0x70
                 0x72-0x74
                 0x79
***********************************/
extern leRasterFont NotoSans_Bold;

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       21
 * Baseline:     12
 * Style:        Antialias
 * Glyph Count:  48
 * Range Count:  14
 * Glyph Ranges: 0x20-0x21
                 0x27
                 0x2E
                 0x30-0x39
                 0x41-0x44
                 0x46
                 0x49
                 0x4E
                 0x50-0x51
                 0x53-0x55
                 0x61
                 0x63-0x69
                 0x6B-0x70
                 0x72-0x79
***********************************/
extern leRasterFont NotoSans_Regular;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   19
 *****************************************************************************/

// language IDs
#define language_default    0

// string IDs
#define stringID_FileNotFound2    0
#define stringID_FlashingComplete    1
#define stringID_Title    2
#define stringID_RecordCount    3
#define stringID_UnknownError    4
#define stringID_Numbers    5
#define stringID_Done    6
#define stringID_NoMedium    7
#define stringID_FileNotFound1    8
#define stringID_NoValidMedium    9
#define stringID_stringNumberFiller    10
#define stringID_Ok    11
#define stringID_SDCard    12
#define stringID_SelectSource    13
#define stringID_Of    14
#define stringID_Flashing    15
#define stringID_NoValidMedium2    16
#define stringID_InvalidFile    17
#define stringID_USB    18

extern const leStringTable stringTable;


// string list
extern leTableString string_FileNotFound2;
extern leTableString string_FlashingComplete;
extern leTableString string_Title;
extern leTableString string_RecordCount;
extern leTableString string_UnknownError;
extern leTableString string_Numbers;
extern leTableString string_Done;
extern leTableString string_NoMedium;
extern leTableString string_FileNotFound1;
extern leTableString string_NoValidMedium;
extern leTableString string_stringNumberFiller;
extern leTableString string_Ok;
extern leTableString string_SDCard;
extern leTableString string_SelectSource;
extern leTableString string_Of;
extern leTableString string_Flashing;
extern leTableString string_NoValidMedium2;
extern leTableString string_InvalidFile;
extern leTableString string_USB;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
