---
title: Release notes
nav_order: 99
---

# ![MPLAB® Harmony Graphics Suite](./images/mhgs.png) Microchip MPLAB® Harmony 3 Graphics application examples for SAM D5x/E5x Family

## Harmony 3 Graphics application examples for SAM D5x/E5x family v3.11.0

### Development kit and demo application support

Following table provides number of peripheral library examples available for different development kits.

| Development Kits  | MPLABx applications |
|:-----------------:|:-------------------:|
| [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210)     | 9 |
| [SAM E51 Integrated Graphics and Touch Development Board](https://www.microchip.com/developmenttools/ProductDetails/EV14C17A)     | 4 |

## Release v3.11.0

### New Features

New features added in this release are as follows:

- Added **LVGL Showcase** for IGaT Development Board


### Development Tools

- [MPLAB® X IDE v6.20](https://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® X IDE plug-ins:
    - [MPLAB® Code Configurator (MCC) Plugin v5.4.1](https://github.com/Microchip-MPLAB-Harmony/mplabx-plugin).
    - [MPLAB® Code Configurator (MCC) Core v5.6.1](https://github.com/Microchip-MPLAB-Harmony/mplabx-plugin).
- [MPLAB® XC32 C/C++ Compiler v4.35](https://www.microchip.com/mplab/compilers)


### Dependent Components

* [Harmony 3 GFX v3.14.0](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.14.0)
* [Harmony 3 TOUCH v3.14.0](https://github.com/Microchip-MPLAB-Harmony/touch/releases/tag/v3.14.0)


## Release v3.10.0

### New Features

New features added in this release are as follows:

- Added MCC Configurations


## Release v3.9.3

### New Features

New features added in this release are as follows:

- Added Low Power mode and Proximity Sensing support to **Legato IGaT Showcase**
- Added RTOS version of **Legato IGaT Showcase** with CPU usage metrics


## Release v3.9.2

### New Features

New features added in this release are as follows:

- Added **Legato Showcase Plus** for the SAM E54 Curiosity Ultra Development Board
- **Legato Cooker**, **Legato Adventure** and **Legato Monitor** are removed as their features are replicated in **Legato Showcase Plus**
- USB MSD reader support added to **Legato Flash**


## Release v3.9.1

### New Features

New features added in this release are as follows:

- Added Legato Quickstart for the IGaT Development Board
- Added Legato IGaT Showcase for the IGaT Development Board


## Release v3.9.0

### New Features

New features added in this release are as follows:

- Applications migrated from gfx and gfx_apps repository to this new application repository for SAM D5x/E5x development support
- Added legato_qs_e54_cult_cpro_parallel.IAR and legato_qs_e54_cu_tm4301b_ssd1963.IAR configurations

### Known Issues

The current known issues are as follows:

- For all IAR configurations, make sure LE_DYNAMIC_VTABLES is define to 1 to ensure build success


### Development Tools

- [MPLAB® X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® X IDE plug-ins:
    - [MPLAB® Harmony Configurator (MHC) v3.8.5](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator).
    - [MPLAB® Code Configurator (MCC) v5.2.2](https://github.com/Microchip-MPLAB-Harmony/mplabx-plugin).
- [MPLAB® XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers)


### Dependent Components

* [Harmony 3 GFX v3.12.0](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.12.0)
* [Harmony 3 TOUCH v3.13.0](https://github.com/Microchip-MPLAB-Harmony/touch/releases/tag/v3.13.0)
