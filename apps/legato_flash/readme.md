---
parent: Example Applications
title: Legato Flash
nav_order: 1
---

# Legato Flash

![](./../../docs/html/legato_flash.png)

The legato_flash demonstration application serves as an external memory programmer to flash the off-chip non-volatile memory with the resources held on an Memory Storage Device (MSD), such as a USB MSD or an SD EMMC, which can then be accessed by other applications saving on-chip memory for other programs and resources.

The application [legato_quickstart_external_resources](../legato_quickstart_ext_res/readme.md) in MPLAB Harmony needs to use preloaded images/fonts from QSPI flash external non-volatile memory. This would require legato_flash to flash the required image and font resources onto the QSPI flash. Refer to [legato_quickstart_external_resources](../legato_quickstart_ext_res/readme.md) for usage model information.

![](./../../docs/html/external_resources_flash_reader_diagram.png)

|MPLABX Configuration|Board Configuration|
|:-------------------|:------------------|
| [legato_fl_e54_cult_cpro_parallel.X](firmware/legato_fl_e54_cult_cpro_parallel.X/readme.md)| [SAM E54 Curiosity Ultra Development Board](https://www.microchip.com/Developmenttools/ProductDetails/DM320210) using external ILI9488 controller to drive the [maXTouch® Curiosity Pro Board](https://www.microchip.com/Developmenttools/ProductDetails/AC320007) |