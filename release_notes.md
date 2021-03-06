﻿---
title: Release notes
nav_order: 99
---

# ![MPLAB® Harmony Graphics Suite](./docs/html/mhgs.png) Microchip MPLAB® Harmony 3 Graphics application examples for SAM D5x/E5x Family

## Harmony 3 Graphics application examples for SAM D5x/E5x family v3.9.1

### Development kit and demo application support

Following table provides number of peripheral library examples available for different development kits.

| Development Kits  | MPLABx applications |
|:-----------------:|:-------------------:|
| [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)     | 13 |

## Release v3.9.1

### New Features

New features added in this release are as follows:

- Added Legato Quickstart for the IGAT Development Board
- Added Legato IGAT Showcase for the IGAT Development Board


## Release v3.9.0

### New Features

New features added in this release are as follows:

- Applications migrated from gfx and gfx_apps repository to this new application repository for SAM D5x/E5x development support
- Added legato_qs_e54_cult_cpro_parallel.IAR and legato_qs_e54_cu_tm4301b_ssd1963.IAR configurations

### Known Issues

The current known issues are as follows:

- For all IAR configurations, make sure LE_DYNAMIC_VTABLES is define to 1 to ensure build success

### Development Tools

- [MPLAB® X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® X IDE plug-ins:
  - MPLAB® Harmony Configurator (MHC) v3.6.5
- [MPLAB® XC32 C/C++ Compiler v2.50](https://www.microchip.com/mplab/compilers)

### Dependent Components

* [Harmony 3 GFX v3.9.3](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.9.3)
* [Harmony 3 TOUCH v3.9.2](https://github.com/Microchip-MPLAB-Harmony/touch/releases/tag/v3.9.2)
