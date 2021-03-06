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
 * Name:         NotoSans_Regular_Menu
 * Height:       19
 * Baseline:     15
 * Style:        Antialias
 * Glyph Count:  24
 * Range Count:  13
 * Glyph Ranges: 0x20
                 0x41
                 0x45
                 0x49
                 0x4B-0x51
                 0x53-0x54
                 0x5A
                 0x63
                 0x65
                 0x69
                 0x6B-0x6C
                 0x6E-0x6F
                 0x73-0x75
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
const uint8_t NotoSans_Regular_Menu_glyphs[484] =
{
    0x18,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x0D,0x00,0x0E,0x00,0x0D,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x00,0x00,0x45,0x00,0x09,0x00,
    0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x09,0x00,0xB6,0x00,0x00,0x00,
    0x49,0x00,0x06,0x00,0x0E,0x00,0x07,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x06,0x00,
    0x34,0x01,0x00,0x00,0x4B,0x00,0x0C,0x00,0x0E,0x00,0x0C,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0C,0x00,0x88,0x01,0x00,0x00,0x4C,0x00,0x09,0x00,0x0E,0x00,0x0A,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x09,0x00,0x30,0x02,0x00,0x00,0x4D,0x00,0x10,0x00,
    0x0E,0x00,0x12,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x10,0x00,0xAE,0x02,0x00,0x00,
    0x4E,0x00,0x0D,0x00,0x0E,0x00,0x0F,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0D,0x00,
    0x8E,0x03,0x00,0x00,0x4F,0x00,0x0E,0x00,0x0E,0x00,0x10,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0E,0x00,0x44,0x04,0x00,0x00,0x50,0x00,0x0B,0x00,0x0E,0x00,0x0C,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0x08,0x05,0x00,0x00,0x51,0x00,0x0E,0x00,
    0x11,0x00,0x10,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0E,0x00,0xA2,0x05,0x00,0x00,
    0x53,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0A,0x00,
    0x90,0x06,0x00,0x00,0x54,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x0B,0x00,0x1C,0x07,0x00,0x00,0x5A,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0xB6,0x07,0x00,0x00,0x63,0x00,0x08,0x00,
    0x0B,0x00,0x0A,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x08,0x00,0x50,0x08,0x00,0x00,
    0x65,0x00,0x0A,0x00,0x0B,0x00,0x0B,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0xA8,0x08,0x00,0x00,0x69,0x00,0x03,0x00,0x0F,0x00,0x05,0x00,0x01,0x00,0x0F,0x00,
    0x00,0x00,0x03,0x00,0x16,0x09,0x00,0x00,0x6B,0x00,0x0A,0x00,0x0F,0x00,0x0B,0x00,
    0x01,0x00,0x0F,0x00,0x00,0x00,0x0A,0x00,0x43,0x09,0x00,0x00,0x6C,0x00,0x03,0x00,
    0x0F,0x00,0x05,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x03,0x00,0xD9,0x09,0x00,0x00,
    0x6E,0x00,0x0A,0x00,0x0B,0x00,0x0C,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0x06,0x0A,0x00,0x00,0x6F,0x00,0x0B,0x00,0x0B,0x00,0x0C,0x00,0x01,0x00,0x0B,0x00,
    0x00,0x00,0x0B,0x00,0x74,0x0A,0x00,0x00,0x73,0x00,0x08,0x00,0x0B,0x00,0x0A,0x00,
    0x01,0x00,0x0B,0x00,0x00,0x00,0x08,0x00,0xED,0x0A,0x00,0x00,0x74,0x00,0x07,0x00,
    0x0E,0x00,0x07,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x07,0x00,0x45,0x0B,0x00,0x00,
    0x75,0x00,0x0A,0x00,0x0B,0x00,0x0C,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0xA7,0x0B,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_Menu_data[3093] =
{
    0x00,0x00,0x00,0x00,0x00,0x9F,0xFF,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xF5,0xFC,0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6B,0xFF,
    0x95,0xFF,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD0,0xDA,0x18,0xFC,0x97,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x37,0xFF,0x7C,0x00,0xB5,0xF1,0x0B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x9D,0xFC,0x1B,0x00,0x53,0xFF,0x63,0x00,0x00,0x00,0x00,0x00,
    0x0E,0xF4,0xB5,0x00,0x00,0x05,0xEA,0xC9,0x00,0x00,0x00,0x00,0x00,0x69,0xFF,0x51,
    0x00,0x00,0x00,0x8D,0xFF,0x2E,0x00,0x00,0x00,0x00,0xCE,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x94,0x00,0x00,0x00,0x35,0xFF,0xC5,0x98,0x98,0x98,0x98,0x98,0xE4,0xEF,
    0x09,0x00,0x00,0x9B,0xFF,0x29,0x00,0x00,0x00,0x00,0x00,0x76,0xFF,0x5F,0x00,0x0D,
    0xF3,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0xFA,0xC5,0x00,0x67,0xFF,0x63,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xAE,0xFF,0x2B,0xCD,0xF4,0x0C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x4A,0xFF,0x91,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEC,0x10,
    0xFF,0xDA,0x74,0x74,0x74,0x74,0x74,0x6A,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,
    0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,
    0x00,0x00,0x00,0x10,0xFF,0xC5,0x24,0x24,0x24,0x24,0x24,0x14,0x10,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x90,0x10,0xFF,0xD1,0x50,0x50,0x50,0x50,0x50,0x2D,0x10,0xFF,
    0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,
    0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,
    0x00,0x00,0x10,0xFF,0xDA,0x74,0x74,0x74,0x74,0x74,0x6A,0x10,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xEC,0x34,0xFF,0xFF,0xFF,0xFF,0xF4,0x06,0x42,0xB9,0xFF,0x92,0x32,
    0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,
    0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,
    0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,
    0x00,0x00,0x84,0xFF,0x48,0x00,0x00,0x00,0x84,0xFF,0x48,0x00,0x01,0x2A,0xAB,0xFF,
    0x7E,0x1C,0x34,0xFF,0xFF,0xFF,0xFF,0xF4,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,
    0x64,0xFF,0xAE,0x03,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x4F,0xFC,0xBE,0x07,0x00,
    0x10,0xFF,0xBC,0x00,0x00,0x00,0x3C,0xF7,0xCC,0x0D,0x00,0x00,0x10,0xFF,0xBC,0x00,
    0x00,0x2B,0xEE,0xD8,0x15,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x1F,0xE4,0xE3,0x1E,
    0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x16,0xDA,0xEC,0x29,0x00,0x00,0x00,0x00,0x00,
    0x10,0xFF,0xC9,0xCD,0xFF,0xC5,0x03,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xFF,0xDE,
    0xBB,0xFF,0x83,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xDC,0x14,0x10,0xDD,0xFD,0x45,
    0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x32,0xF8,0xE9,0x19,0x00,0x00,0x00,
    0x10,0xFF,0xBC,0x00,0x00,0x00,0x67,0xFF,0xBE,0x02,0x00,0x00,0x10,0xFF,0xBC,0x00,
    0x00,0x00,0x00,0xA4,0xFF,0x81,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x0B,
    0xD6,0xFD,0x42,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x2A,0xF4,0xE8,0x18,
    0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,
    0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,
    0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,
    0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,
    0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,
    0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,
    0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xE4,0x98,
    0x98,0x98,0x98,0x98,0x95,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x10,0xFF,
    0xFF,0xC9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA2,0xFF,0xFF,0x34,0x10,0xFF,
    0xF9,0xFF,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF6,0xFA,0xFF,0x34,0x10,0xFF,
    0xAF,0xFF,0x8D,0x00,0x00,0x00,0x00,0x00,0x00,0x6A,0xFF,0xB2,0xFF,0x34,0x10,0xFF,
    0x8B,0xCD,0xE9,0x05,0x00,0x00,0x00,0x00,0x00,0xCE,0xD2,0x88,0xFF,0x34,0x10,0xFF,
    0x91,0x6B,0xFF,0x51,0x00,0x00,0x00,0x00,0x32,0xFF,0x6E,0x8F,0xFF,0x34,0x10,0xFF,
    0x96,0x10,0xF7,0xB4,0x00,0x00,0x00,0x00,0x96,0xF8,0x12,0x93,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0xA6,0xFC,0x19,0x00,0x00,0x09,0xF0,0xA6,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x44,0xFF,0x78,0x00,0x00,0x5E,0xFF,0x42,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x01,0xDF,0xD9,0x00,0x00,0xC2,0xDC,0x01,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x00,0x7F,0xFF,0x3C,0x26,0xFF,0x7A,0x00,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x00,0x1F,0xFD,0x9F,0x8A,0xFC,0x1A,0x00,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x00,0x00,0xBA,0xF4,0xEA,0xB2,0x00,0x00,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x00,0x00,0x58,0xFF,0xFF,0x4E,0x00,0x00,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0x98,0x00,0x00,0x00,0x07,0xED,0xE6,0x03,0x00,0x00,0x00,0x94,0xFF,0x34,0x10,0xFF,
    0xFF,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0x44,0x10,0xFF,0xFF,0xE9,0x12,
    0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0x44,0x10,0xFF,0xDC,0xFF,0xA0,0x00,0x00,0x00,
    0x00,0x00,0x6C,0xFF,0x44,0x10,0xFF,0x82,0xC6,0xFF,0x45,0x00,0x00,0x00,0x00,0x6C,
    0xFF,0x44,0x10,0xFF,0x8A,0x27,0xF7,0xDF,0x0B,0x00,0x00,0x00,0x6C,0xFF,0x44,0x10,
    0xFF,0x92,0x00,0x76,0xFF,0x8F,0x00,0x00,0x00,0x6C,0xFF,0x44,0x10,0xFF,0x97,0x00,
    0x03,0xCA,0xFD,0x37,0x00,0x00,0x6C,0xFF,0x44,0x10,0xFF,0x98,0x00,0x00,0x2B,0xF9,
    0xD3,0x05,0x00,0x6C,0xFF,0x44,0x10,0xFF,0x98,0x00,0x00,0x00,0x7B,0xFF,0x7E,0x00,
    0x69,0xFF,0x44,0x10,0xFF,0x98,0x00,0x00,0x00,0x04,0xCD,0xF9,0x2A,0x63,0xFF,0x44,
    0x10,0xFF,0x98,0x00,0x00,0x00,0x00,0x2E,0xFA,0xC6,0x5A,0xFF,0x44,0x10,0xFF,0x98,
    0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xBB,0xFF,0x44,0x10,0xFF,0x98,0x00,0x00,0x00,
    0x00,0x00,0x05,0xD1,0xFF,0xFF,0x44,0x10,0xFF,0x98,0x00,0x00,0x00,0x00,0x00,0x00,
    0x31,0xFB,0xFF,0x44,0x00,0x00,0x00,0x44,0xA8,0xDB,0xF5,0xED,0xCF,0x80,0x1A,0x00,
    0x00,0x00,0x00,0x05,0x9C,0xFF,0xE9,0x9D,0x7B,0x82,0xB2,0xFB,0xEE,0x46,0x00,0x00,
    0x00,0x87,0xFF,0xAD,0x0C,0x00,0x00,0x00,0x00,0x2D,0xE6,0xF6,0x26,0x00,0x1D,0xFB,
    0xE0,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0xFF,0xB3,0x00,0x70,0xFF,0x7B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDA,0xFA,0x11,0xA5,0xFF,0x3F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0x43,0xBD,0xFF,0x26,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x87,0xFF,0x5C,0xBC,0xFF,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x88,0xFF,0x5B,0xA4,0xFF,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA2,
    0xFF,0x43,0x6E,0xFF,0x7D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDD,0xFA,0x10,
    0x1D,0xFB,0xE2,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x4D,0xFF,0xB3,0x00,0x00,0x87,
    0xFF,0xAE,0x0C,0x00,0x00,0x00,0x00,0x31,0xE9,0xF6,0x25,0x00,0x00,0x06,0x9D,0xFF,
    0xE9,0x9B,0x7A,0x81,0xB4,0xFC,0xED,0x44,0x00,0x00,0x00,0x00,0x00,0x45,0xA9,0xDC,
    0xF6,0xED,0xCE,0x7F,0x19,0x00,0x00,0x00,0x10,0xFF,0xFF,0xFF,0xFF,0xF5,0xD9,0x9B,
    0x28,0x00,0x00,0x10,0xFF,0xDA,0x74,0x76,0x8D,0xC2,0xFF,0xF7,0x3D,0x00,0x10,0xFF,
    0xBC,0x00,0x00,0x00,0x00,0x5C,0xFF,0xCD,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,
    0x00,0xE5,0xFF,0x08,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0xDD,0xFD,0x06,0x10,
    0xFF,0xBC,0x00,0x00,0x00,0x00,0x31,0xFE,0xC8,0x00,0x10,0xFF,0xC5,0x24,0x27,0x3B,
    0x75,0xE9,0xFB,0x3F,0x00,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xC6,0x3A,0x00,0x00,
    0x10,0xFF,0xD1,0x50,0x4C,0x39,0x17,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x44,0xA8,0xDB,0xF5,0xED,0xCF,0x80,0x1A,0x00,0x00,0x00,
    0x00,0x05,0x9C,0xFF,0xE9,0x9D,0x7B,0x82,0xB2,0xFB,0xEE,0x46,0x00,0x00,0x00,0x87,
    0xFF,0xAD,0x0C,0x00,0x00,0x00,0x00,0x2D,0xE6,0xF6,0x26,0x00,0x1D,0xFB,0xE0,0x09,
    0x00,0x00,0x00,0x00,0x00,0x00,0x47,0xFF,0xB3,0x00,0x70,0xFF,0x7B,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xDA,0xFA,0x11,0xA5,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xA0,0xFF,0x43,0xBD,0xFF,0x26,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x87,0xFF,0x5B,0xBC,0xFF,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,
    0xFF,0x60,0xA4,0xFF,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA2,0xFF,0x48,
    0x6E,0xFF,0x7D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDD,0xFD,0x15,0x1D,0xFB,
    0xE2,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x4D,0xFF,0xB7,0x00,0x00,0x87,0xFF,0xAE,
    0x0C,0x00,0x00,0x00,0x00,0x31,0xE9,0xF9,0x30,0x00,0x00,0x06,0x9D,0xFF,0xE9,0x9B,
    0x7A,0x81,0xB4,0xFC,0xF5,0x54,0x00,0x00,0x00,0x00,0x00,0x45,0xA9,0xDC,0xF7,0xFF,
    0xFF,0xAF,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0xF8,0xE9,
    0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0xFC,0xEC,0x32,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xFB,0xEB,0x35,0x00,
    0x00,0x1D,0x97,0xDE,0xF8,0xED,0xD4,0x9D,0x3E,0x00,0x24,0xEB,0xFA,0xA6,0x7D,0x8C,
    0xB1,0xF4,0x68,0x00,0x9D,0xFF,0x54,0x00,0x00,0x00,0x00,0x09,0x08,0x00,0xC2,0xFF,
    0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA1,0xFF,0x50,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x32,0xFC,0xF6,0x7D,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x45,0xE5,0xFF,
    0xF8,0xA7,0x3B,0x00,0x00,0x00,0x00,0x00,0x06,0x5E,0xC7,0xFF,0xFF,0xAA,0x0B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x35,0xC7,0xFF,0x9E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0A,0xEC,0xF6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD2,0xFD,0x04,0x18,0x00,
    0x00,0x00,0x00,0x00,0x3A,0xFC,0xC8,0x00,0xF9,0xC9,0x9F,0x82,0x80,0xAB,0xFA,0xF0,
    0x34,0x00,0x88,0xCA,0xE7,0xF8,0xF8,0xD9,0x93,0x1E,0x00,0x00,0xCC,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE8,0x5C,0x74,0x74,0x74,0xA4,0xFF,0xB3,0x74,0x74,
    0x74,0x69,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,
    0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x58,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,
    0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0x74,0x00,0x74,0x74,0x74,0x74,0x74,0x74,0x75,0xF0,0xFF,0x44,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x6B,0xFF,0x9E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xF3,0xE4,
    0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xBD,0xFF,0x4A,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x69,0xFF,0xA0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF3,0xE5,0x10,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xBC,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x67,0xFF,0xA1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0xF2,0xE5,0x10,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xBA,0xFF,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x65,0xFF,0xA2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF1,0xFF,0x85,0x74,0x74,
    0x74,0x74,0x74,0x74,0x4C,0x3C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA8,
    0x00,0x00,0x59,0xC1,0xEE,0xF4,0xD7,0x8A,0x00,0x94,0xFF,0xD3,0x84,0x85,0xBA,0x95,
    0x44,0xFF,0xB8,0x04,0x00,0x00,0x00,0x00,0xA3,0xFF,0x35,0x00,0x00,0x00,0x00,0x00,
    0xCF,0xFA,0x03,0x00,0x00,0x00,0x00,0x00,0xE2,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
    0xD2,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0xAA,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,
    0x4F,0xFF,0xB9,0x02,0x00,0x00,0x00,0x01,0x00,0xA5,0xFF,0xCE,0x80,0x82,0xA6,0xB4,
    0x00,0x01,0x6A,0xCB,0xF3,0xFA,0xDA,0x72,0x00,0x00,0x5E,0xCA,0xF3,0xED,0xB7,0x3D,
    0x00,0x00,0x00,0x8C,0xFF,0xBD,0x80,0x8D,0xE5,0xFC,0x50,0x00,0x3A,0xFF,0x86,0x00,
    0x00,0x00,0x14,0xEB,0xE2,0x02,0x9B,0xFF,0x35,0x24,0x24,0x24,0x24,0xB3,0xFF,0x2B,
    0xCF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x42,0xE2,0xF9,0x50,0x50,0x50,0x50,
    0x50,0x50,0x50,0x15,0xD1,0xFF,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA1,0xFF,
    0x5A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xFF,0xDB,0x13,0x00,0x00,0x00,0x00,
    0x1D,0x00,0x00,0x84,0xFF,0xE8,0x90,0x7B,0x97,0xCF,0xC8,0x00,0x00,0x00,0x4F,0xBA,
    0xEB,0xFC,0xED,0xBB,0x5A,0x00,0x3F,0xF2,0x67,0x51,0xFF,0x7F,0x00,0x12,0x00,0x00,
    0x00,0x00,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,
    0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,
    0x4C,0xFF,0x74,0x4C,0xFF,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4C,0xFF,0x70,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4C,0xFF,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x4C,0xFF,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4C,0xFF,0x70,0x00,0x00,
    0x00,0x53,0xFD,0xB8,0x05,0x4C,0xFF,0x70,0x00,0x00,0x43,0xF8,0xC8,0x0B,0x00,0x4C,
    0xFF,0x70,0x00,0x33,0xF2,0xD5,0x12,0x00,0x00,0x4C,0xFF,0x6F,0x25,0xEA,0xE1,0x1C,
    0x00,0x00,0x00,0x4C,0xFF,0x74,0xD6,0xF9,0x28,0x00,0x00,0x00,0x00,0x4C,0xFF,0xEC,
    0xFD,0xFF,0x6C,0x00,0x00,0x00,0x00,0x4C,0xFF,0xD9,0x2D,0xDA,0xF8,0x31,0x00,0x00,
    0x00,0x4C,0xFF,0x70,0x00,0x32,0xF9,0xDA,0x0D,0x00,0x00,0x4C,0xFF,0x70,0x00,0x00,
    0x72,0xFF,0xA5,0x00,0x00,0x4C,0xFF,0x70,0x00,0x00,0x01,0xB6,0xFF,0x63,0x00,0x4C,
    0xFF,0x70,0x00,0x00,0x00,0x16,0xE7,0xF5,0x2B,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,
    0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,
    0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x74,
    0x4C,0xFF,0x74,0x4C,0xFF,0x74,0x4C,0xFF,0x33,0x4F,0xC4,0xF5,0xE8,0xB8,0x33,0x00,
    0x4C,0xFF,0xB4,0xF2,0x99,0x7B,0xA0,0xFB,0xF8,0x2A,0x4C,0xFF,0xFD,0x2E,0x00,0x00,
    0x00,0x64,0xFF,0x8E,0x4C,0xFF,0xB7,0x00,0x00,0x00,0x00,0x14,0xFF,0xB4,0x4C,0xFF,
    0x8A,0x00,0x00,0x00,0x00,0x00,0xFF,0xBC,0x4C,0xFF,0x75,0x00,0x00,0x00,0x00,0x00,
    0xFF,0xBC,0x4C,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0xFF,0xBC,0x4C,0xFF,0x74,0x00,
    0x00,0x00,0x00,0x00,0xFF,0xBC,0x4C,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0xFF,0xBC,
    0x4C,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0xFF,0xBC,0x4C,0xFF,0x74,0x00,0x00,0x00,
    0x00,0x00,0xFF,0xBC,0x00,0x00,0x5F,0xC7,0xF3,0xF3,0xC9,0x63,0x00,0x00,0x00,0x00,
    0x98,0xFF,0xD0,0x83,0x7F,0xC7,0xFF,0xA3,0x00,0x00,0x48,0xFF,0xB9,0x03,0x00,0x00,
    0x00,0xA4,0xFF,0x58,0x00,0xA7,0xFF,0x3D,0x00,0x00,0x00,0x00,0x22,0xFE,0xBB,0x00,
    0xD6,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0xE9,0xEB,0x00,0xE2,0xF3,0x00,0x00,0x00,
    0x00,0x00,0x00,0xD3,0xFD,0x00,0xCE,0xFF,0x09,0x00,0x00,0x00,0x00,0x00,0xEA,0xF0,
    0x00,0x9B,0xFF,0x43,0x00,0x00,0x00,0x00,0x26,0xFF,0xBE,0x00,0x38,0xFE,0xBE,0x04,
    0x00,0x00,0x00,0xA6,0xFF,0x5C,0x00,0x00,0x81,0xFF,0xD2,0x82,0x7E,0xC6,0xFF,0xA8,
    0x00,0x00,0x00,0x00,0x52,0xC1,0xF1,0xF6,0xCC,0x69,0x02,0x00,0x00,0x04,0x6C,0xCC,
    0xEF,0xF2,0xD5,0x95,0x23,0x99,0xFF,0xBB,0x7E,0x88,0xB2,0xF5,0x23,0xF1,0xCC,0x00,
    0x00,0x00,0x00,0x08,0x00,0xDE,0xEF,0x25,0x00,0x00,0x00,0x00,0x00,0x52,0xF7,0xF9,
    0xA0,0x3A,0x00,0x00,0x00,0x00,0x23,0x98,0xF3,0xFF,0xD1,0x47,0x00,0x00,0x00,0x00,
    0x0D,0x6E,0xEB,0xFD,0x45,0x00,0x00,0x00,0x00,0x00,0x31,0xFF,0xA2,0x17,0x00,0x00,
    0x00,0x00,0x2F,0xFF,0x9B,0xF0,0xBF,0x94,0x7A,0x93,0xEA,0xFA,0x37,0x76,0xCF,0xF4,
    0xFA,0xE1,0xA7,0x32,0x00,0x00,0x00,0x41,0x4C,0x00,0x00,0x00,0x00,0x00,0xBD,0x98,
    0x00,0x00,0x00,0x00,0x14,0xFA,0x98,0x00,0x00,0x00,0x69,0xEF,0xFF,0xFF,0xFF,0xFF,
    0xB4,0x4F,0x89,0xFF,0xC7,0x74,0x74,0x51,0x00,0x28,0xFF,0x98,0x00,0x00,0x00,0x00,
    0x28,0xFF,0x98,0x00,0x00,0x00,0x00,0x28,0xFF,0x98,0x00,0x00,0x00,0x00,0x28,0xFF,
    0x98,0x00,0x00,0x00,0x00,0x28,0xFF,0x98,0x00,0x00,0x00,0x00,0x26,0xFF,0x9A,0x00,
    0x00,0x00,0x00,0x13,0xFF,0xC5,0x00,0x00,0x00,0x00,0x00,0xC7,0xFF,0xAD,0x7A,0x74,
    0x00,0x00,0x1F,0xB5,0xF4,0xF5,0xA0,0x6C,0xFF,0x5C,0x00,0x00,0x00,0x00,0x18,0xFF,
    0xA8,0x6C,0xFF,0x5C,0x00,0x00,0x00,0x00,0x18,0xFF,0xA8,0x6C,0xFF,0x5C,0x00,0x00,
    0x00,0x00,0x18,0xFF,0xA8,0x6C,0xFF,0x5C,0x00,0x00,0x00,0x00,0x18,0xFF,0xA8,0x6C,
    0xFF,0x5C,0x00,0x00,0x00,0x00,0x18,0xFF,0xA8,0x6C,0xFF,0x5C,0x00,0x00,0x00,0x00,
    0x1A,0xFF,0xA8,0x6C,0xFF,0x5C,0x00,0x00,0x00,0x00,0x30,0xFF,0xA8,0x65,0xFF,0x6D,
    0x00,0x00,0x00,0x00,0x5E,0xFF,0xA8,0x40,0xFF,0xBB,0x00,0x00,0x00,0x06,0xCD,0xFF,
    0xA8,0x03,0xD4,0xFF,0xC2,0x7E,0x87,0xD7,0xC5,0xFD,0xA8,0x00,0x15,0x97,0xDD,0xF8,
    0xDF,0x8B,0x0D,0xDD,0xA8,
};

leRasterFont NotoSans_Regular_Menu =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Regular_Menu_data, // data address pointer
            3093, // data size
        },
        LE_RASTER_FONT,
    },
    19,
    15,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Regular_Menu_glyphs, // glyph table
};
