// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular_Time2
 * Height:       53
 * Baseline:     51
 * Style:        Antialias
 * Glyph Count:  2
 * Range Count:  1
 * Glyph Ranges: 0x32-0x33
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t NotoSans_Regular_Time2_glyphs[44] =
{
    0x02,0x00,0x00,0x00,0x32,0x00,0x22,0x00,0x33,0x00,0x28,0x00,0x03,0x00,0x33,0x00,
    0x00,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x22,0x00,0x34,0x00,0x28,0x00,
    0x03,0x00,0x33,0x00,0x00,0x00,0x22,0x00,0xC6,0x06,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_Time2_data[3502] =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x42,0x83,0xAF,0xD3,0xEA,0xF6,
    0xFA,0xE9,0xD7,0xC2,0x8D,0x51,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x9B,0xF2,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xA5,0x34,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2A,0xAE,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA6,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x16,0xA1,0xFD,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xDE,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x49,0xE9,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xF0,0x31,0x00,0x00,0x00,0x00,0x00,0x01,0x91,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFE,0xC4,0x80,0x52,0x2F,0x21,0x1E,0x30,0x53,0x92,0xEC,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0x12,0x00,0x00,0x00,0x00,0x00,0x91,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xF9,0x92,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0A,0x7C,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x9C,0x00,0x00,0x00,0x00,0x00,0x05,
    0xC5,0xFF,0xFF,0xFF,0xFF,0xB2,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x40,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x24,0x00,0x00,0x00,
    0x00,0x00,0x1A,0xE8,0xFF,0xEF,0x5B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x89,0x00,
    0x00,0x00,0x00,0x00,0x00,0x40,0xC9,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xD9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6A,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x29,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x09,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x53,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xF5,0xFF,0xFF,0xFF,0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFA,0xFF,0xFF,0xFF,0xFF,0xFF,0x54,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x0B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x44,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x21,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xF3,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA9,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xB4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF6,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xF5,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x11,0xED,0xFF,0xFF,0xFF,0xFF,0xFF,0x96,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x99,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x45,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x18,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0x0B,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x07,0xC7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x42,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xA7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x8B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x74,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xDD,0x16,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5E,0xFE,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xEB,0x25,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4F,0xFC,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xF6,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0xF8,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFB,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x39,0xF4,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFD,0x59,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0xF0,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,
    0xEC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x27,0xE8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x22,0xE4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1E,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x71,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x19,0xDB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x74,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x15,0xD6,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x76,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x11,0xD0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x79,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0xCA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0B,0xC4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7E,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xBE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xB7,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xB0,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x9D,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
    0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x09,0x89,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x68,0xA4,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x68,
    0xA4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x68,0xA4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x68,0xA4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x3B,
    0x73,0xA4,0xC4,0xE2,0xF0,0xFA,0xF8,0xE8,0xD9,0xC7,0x9A,0x64,0x2D,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0xA1,
    0xEE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD4,
    0x68,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x5E,0xD5,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xE7,0x45,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x49,0xD9,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x85,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xA8,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7A,0x00,0x00,0x00,0x00,0x00,
    0x46,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDD,0x9B,0x64,0x42,0x29,0x1F,
    0x1F,0x30,0x50,0x88,0xDE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x51,0x00,0x00,
    0x00,0x00,0x00,0x96,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xAE,0x3A,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x58,0xEA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,
    0x08,0x00,0x00,0x00,0x00,0x0A,0xD9,0xFF,0xFF,0xFF,0xAF,0x2F,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0xDA,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x73,0x00,0x00,0x00,0x00,0x00,0x36,0xFB,0xDD,0x47,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0xF6,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xCE,0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x09,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x86,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x2D,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x50,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0x67,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD9,0xFF,0xFF,0xFF,0xFF,0xFF,0x7D,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0xFF,0xFF,0xFF,0xFF,0x74,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6B,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
    0xD5,0xFF,0xFF,0xFF,0xFF,0xFF,0xB7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x75,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x54,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xB9,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x02,0x73,0xFA,0xFF,0xFF,0xFF,0xFF,0xFF,0xE6,0x16,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x05,0x52,0xC8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0x28,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x18,0x18,0x18,0x18,0x18,0x23,
    0x32,0x44,0x72,0xA5,0xE8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xBB,0x1B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD7,0x5D,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x98,0x47,0x01,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB9,0x82,0x55,
    0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x38,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFC,0xC0,0x62,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x38,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD9,0x4A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x14,0x1F,0x3B,0x5E,
    0x85,0xC5,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x7D,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x0D,0x67,0xD6,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7C,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x72,0xFA,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFD,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0xFC,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xD0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x4A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0E,0xF5,0xFF,0xFF,0xFF,0xFF,0xFF,0x94,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xAA,0xFF,0xFF,0xFF,0xFF,0xFF,0xD4,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x85,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x04,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFE,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8D,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xF2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,
    0xFD,0xFF,0xFF,0xFF,0xFF,0xFF,0x9E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x90,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x34,0xFA,0xFF,0xFF,0xFF,0xFF,0xFF,0xF3,0x0A,0x00,0x88,0x3C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x29,0xEB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x86,0x00,0x00,0xD8,0xFF,
    0xCF,0x69,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x02,0x6E,0xF4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE8,0x11,0x00,0x00,
    0xD8,0xFF,0xFF,0xFF,0xFF,0xD2,0x88,0x4F,0x23,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0x34,0x86,0xE2,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0x45,0x00,
    0x00,0x00,0xD8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF5,0xCF,0xBC,0xAD,0x9E,
    0x9E,0xAC,0xB9,0xD5,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0x65,
    0x00,0x00,0x00,0x00,0xD8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF2,
    0x57,0x00,0x00,0x00,0x00,0x00,0xCE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xBB,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x60,0xC7,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,
    0xB9,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0x67,0xA7,
    0xE3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xAE,
    0x6F,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x09,0x29,0x49,0x5E,0x69,0x73,0x7C,0x7A,0x71,0x68,0x54,0x35,0x16,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

leRasterFont NotoSans_Regular_Time2 =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Regular_Time2_data, // data address pointer
            3502, // data size
        },
        LE_RASTER_FONT,
    },
    53,
    51,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Regular_Time2_glyphs, // glyph table
};