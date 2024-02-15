
![](../../../../images/mhgs.png) legato_qs_e54_cult_cpro_parallel.X

Defining the Architecture
-------------------------

![](../../../../images/legato_qs_e54_cult_cpro_parallel_arch.png)

This application demonstrates single-layer HVGA graphics.

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.

### Demonstration Features 

* Legato Graphics Library 
* ILI9488 display 8-bit parallel mode driver, optimized DMA-CCL mode 
* Time system service, timer-counter peripheral library and driver 
* 16-bit RGB565 color depth support (65535 unique colors) 
* CCL, DMA, PORT, EVSYS peripheral 
* RAW, RAW RLE images 

Creating the Project Graph
--------------------------

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg.png)


The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the **SAM E54 Curiosity Ultra BSP** and **Legato Graphics w/ MXT Curiosity Pro Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller.  

For the DMA-CCL boosted setup, components TC4, CCL needs to be added. 

Additional components to support File System, MSD Client Driver, USB Full Speed Driver, USB Host Layer, SDMMC, SDHC1, QSPI and SST26 needs to be added and connected manually. 

Some of these components are fine with default settings, while other require some changes. The following is a list of all the components that required custom settings. 

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg1.png)

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg2.png)

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg5.png)

To setup the CCL to clock the pixel data, make sure PB09 is set to CCL_OUT2 

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg3.png)

Instead of write strobe, make sure PB17 is setup as RSDC instead

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg4.png)


Building the Application
------------------------

The parent directory for this application is apps/legato_quickstart. To build this application, use MPLAB X IDE to open the apps/legato_quickstart/firmware/legato_qs_e54_cult_cpro_parallel.X project file. 

The following table lists configuration properties:

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_qs_e54_cult_cpro_parallel.X | SAM E54 Curiosity Ultra BSP | Legato Graphics w/ maXTouch Curiosity Pro Display | SAM E54 Curiosity Ultra w/ maXTouch Curiosity Pro display via 8-bit parallel interface |

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

This section describes how to configure the supported hardware. 

Configure the hardware as follows: 

* Attach the 24-bit pass through card to the GFX Connector on the SAM E54 Curiosity Ultra board. 
* Connect the ribbon cable from the maXTouch Curiosity Pro Display to the ribbon connector on the 24-bit pass through card. Make sure that the S1 switch on the 24-bit pass through card is set to 2. 
* On the backside of the maXTouch Curiosity Pro display, set the IM[2:0] switches to **011** for 8-bit MCU mode. 

![](../../../../images/cpro_8_bit_parallel_conf.png)

* Connect 5.5V power supply to the SAM E54 Curiosity Ultra board is optional 

The final hardware setup should be: 

![](../../../../images/legato_qs_e54_cult_cpro_parallel_conf1.png)


Running the Demonstration
-------------------------

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure (different configurations may have slight variation in the screen aspect ratio. 

![](../../../../images/legato_qs_e54_cu_cpro_spi_run1.png)

* * * * *
