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
 * Name:         NotoSans_Regular_20
 * Height:       25
 * Baseline:     18
 * Style:        Antialias
 * Glyph Count:  5
 * Range Count:  4
 * Glyph Ranges: 0x42
                 0x65
                 0x73-0x74
                 0x79
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
const uint8_t NotoSans_Regular_20_glyphs[104] =
{
    0x05,0x00,0x00,0x00,0x42,0x00,0x0D,0x00,0x12,0x00,0x10,0x00,0x02,0x00,0x12,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,0x00,0x00,0x65,0x00,0x0C,0x00,0x0E,0x00,0x0E,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x0C,0x00,0xEA,0x00,0x00,0x00,0x73,0x00,0x0A,0x00,
    0x0E,0x00,0x0C,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0A,0x00,0x92,0x01,0x00,0x00,
    0x74,0x00,0x09,0x00,0x11,0x00,0x09,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x09,0x00,
    0x1E,0x02,0x00,0x00,0x79,0x00,0x0D,0x00,0x14,0x00,0x0D,0x00,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x0D,0x00,0xB7,0x02,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_20_data[955] =
{
    0x94,0xFF,0xFF,0xFF,0xFF,0xFE,0xF5,0xE1,0xBB,0x79,0x18,0x00,0x00,0x94,0xFF,0xF4,
    0xDC,0xDC,0xDC,0xE5,0xFB,0xFF,0xFF,0xF2,0x48,0x00,0x94,0xFF,0xAC,0x00,0x00,0x00,
    0x00,0x06,0x46,0xD9,0xFF,0xEC,0x06,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,
    0x37,0xFF,0xFF,0x39,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0xFF,0xFF,
    0x3D,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0x46,0xFF,0xF8,0x12,0x94,0xFF,
    0xAC,0x00,0x00,0x00,0x00,0x02,0x3D,0xDE,0xFF,0x78,0x00,0x94,0xFF,0xF4,0xDC,0xDC,
    0xDC,0xE1,0xF7,0xFD,0xBC,0x53,0x00,0x00,0x94,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFE,0xC7,0x6A,0x04,0x00,0x94,0xFF,0xAC,0x00,0x00,0x00,0x05,0x1D,0x5C,0xDF,0xFF,
    0xC2,0x07,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0xF6,0xFF,0x78,0x94,
    0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAA,0xFF,0xC8,0x94,0xFF,0xAC,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x8A,0xFF,0xE1,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xA9,0xFF,0xD3,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,
    0xF3,0xFF,0x9A,0x94,0xFF,0xAC,0x00,0x00,0x00,0x00,0x01,0x36,0xCA,0xFF,0xFA,0x29,
    0x94,0xFF,0xF4,0xDC,0xDC,0xDC,0xDF,0xF3,0xFF,0xFF,0xF4,0x52,0x00,0x94,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xF4,0xD1,0x8C,0x1F,0x00,0x00,0x00,0x00,0x00,0x45,0xB3,0xE5,
    0xF7,0xDC,0x93,0x22,0x00,0x00,0x00,0x00,0x89,0xFF,0xFF,0xF8,0xE8,0xFF,0xFF,0xF1,
    0x43,0x00,0x00,0x61,0xFF,0xE7,0x4E,0x02,0x00,0x13,0xA6,0xFF,0xE9,0x13,0x04,0xEA,
    0xFF,0x41,0x00,0x00,0x00,0x00,0x05,0xDB,0xFF,0x6F,0x45,0xFF,0xDE,0x00,0x00,0x00,
    0x00,0x00,0x00,0x93,0xFF,0xB2,0x7B,0xFF,0xF5,0xDC,0xDC,0xDC,0xDC,0xDC,0xDC,0xED,
    0xFF,0xCC,0x92,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD4,0x95,0xFF,
    0xB1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7D,0xFF,0xD1,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x4E,0xFF,0xFC,0x19,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x06,0xEE,0xFF,0x99,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x62,
    0xFF,0xFF,0x96,0x17,0x00,0x00,0x04,0x3A,0x9A,0x2E,0x00,0x00,0x7F,0xFD,0xFF,0xFE,
    0xE5,0xE3,0xF8,0xFF,0xFF,0x38,0x00,0x00,0x00,0x35,0x9C,0xDB,0xF6,0xFA,0xE5,0xB3,
    0x63,0x0A,0x00,0x0C,0x6E,0xC7,0xE8,0xFA,0xEA,0xBC,0x6D,0x17,0x14,0xDA,0xFF,0xFF,
    0xEB,0xE2,0xFA,0xFF,0xFF,0x57,0x88,0xFF,0xD0,0x24,0x00,0x00,0x08,0x47,0x95,0x05,
    0xB0,0xFF,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x91,0xFF,0xC6,0x0F,0x00,0x00,
    0x00,0x00,0x00,0x00,0x22,0xEC,0xFF,0xE9,0x7A,0x18,0x00,0x00,0x00,0x00,0x00,0x22,
    0xB4,0xFF,0xFF,0xFB,0xAC,0x37,0x00,0x00,0x00,0x00,0x00,0x2E,0x98,0xF3,0xFF,0xFF,
    0x9C,0x03,0x00,0x00,0x00,0x00,0x00,0x0F,0x84,0xFB,0xFF,0x78,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x7A,0xFF,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5D,0xFF,0xCB,
    0x8A,0x6F,0x22,0x00,0x00,0x00,0x33,0xDA,0xFF,0x8E,0xB4,0xFF,0xFF,0xF0,0xE0,0xF2,
    0xFF,0xFF,0xD6,0x13,0x30,0x93,0xD7,0xF4,0xFD,0xF0,0xC7,0x75,0x0A,0x00,0x00,0x00,
    0x04,0xEE,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0xFF,0x80,0x00,0x00,0x00,0x00,
    0x00,0x00,0x96,0xFF,0x80,0x00,0x00,0x00,0x00,0x3F,0xC7,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x60,0x82,0xDC,0xF5,0xFF,0xEE,0xDC,0xDC,0xDC,0x52,0x00,0x00,0xB4,0xFF,0x80,
    0x00,0x00,0x00,0x00,0x00,0x00,0xB4,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xB4,
    0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xB4,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,
    0x00,0xB4,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xB4,0xFF,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0xB4,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xB3,0xFF,0x81,0x00,
    0x00,0x00,0x00,0x00,0x00,0xA3,0xFF,0x9D,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0xFF,
    0xF3,0x32,0x00,0x00,0x0A,0x00,0x00,0x18,0xEA,0xFF,0xFE,0xE5,0xEF,0x78,0x00,0x00,
    0x00,0x29,0xB1,0xEE,0xF8,0xDE,0x53,0xC6,0xFF,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xCC,0xFF,0x90,0x63,0xFF,0xE8,0x04,0x00,0x00,0x00,0x00,0x00,0x25,0xFF,0xFF,
    0x32,0x0C,0xF3,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x7D,0xFF,0xD4,0x00,0x00,0x9D,
    0xFF,0xA9,0x00,0x00,0x00,0x00,0x00,0xD5,0xFF,0x76,0x00,0x00,0x3A,0xFF,0xF7,0x0F,
    0x00,0x00,0x00,0x2E,0xFF,0xFD,0x1A,0x00,0x00,0x00,0xD6,0xFF,0x65,0x00,0x00,0x00,
    0x86,0xFF,0xBA,0x00,0x00,0x00,0x00,0x73,0xFF,0xC3,0x00,0x00,0x00,0xDE,0xFF,0x5B,
    0x00,0x00,0x00,0x00,0x16,0xFA,0xFE,0x22,0x00,0x37,0xFF,0xF2,0x0A,0x00,0x00,0x00,
    0x00,0x00,0xAD,0xFF,0x7B,0x00,0x8C,0xFF,0x9F,0x00,0x00,0x00,0x00,0x00,0x00,0x49,
    0xFF,0xD0,0x00,0xDE,0xFF,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xE3,0xFF,0x47,
    0xFF,0xE1,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFF,0xD0,0xFF,0x85,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0xFE,0xFF,0xFF,0x26,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xBD,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xCF,0xFF,0x6A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0xFF,
    0xF8,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAF,0xFF,0x9B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x82,0xFF,0xF6,0x24,0x00,0x00,0x00,0x00,0x00,
    0x00,0xAE,0xE1,0xF7,0xFF,0xFF,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xF7,
    0xF8,0xCB,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

leRasterFont NotoSans_Regular_20 =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Regular_20_data, // data address pointer
            955, // data size
        },
        LE_RASTER_FONT,
    },
    25,
    18,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Regular_20_glyphs, // glyph table
};
