
![](../../../../images/mhgs.png) legato_bm_e54_cu_cpro_parallel.X

Defining the Architecture
-------------------------

<img src="../../../../images/legato_qs_e54_cult_cpro_parallel_arch.png" width="480" height="272" />

The application continuously uses the graphics library to render text, fill areas, and draw images to the screen. Once a layer is completely rendered to, the graphics library increments a layer swap counter. The application periodically (at 1 second intervals) samples the layer swap counter and calculates the difference from the previous sample. This difference is shown as the Frame Update Rate (Hz). 

The block diagrams below show the various software and hardware blocks used in this application. 

This configuration runs on the SAM E54 Curiosity Ultra board with a 24-bit passthrough GFX interface card and a maXTouch Curiosity Pro display. The maXTouch Curiosity Pro display has an ILI9488 display controller that is connected to the SAM E54 thru the port/GPIO peripheral using an 8-bit 8080/Parallel interface. The Legato graphics library draws the updated sections of the frame to an internal scratch buffer which is used by the ILI9488 display driver to update the ILI9488 display controller. 

The ILI9488 display driver uses the DMA to drive command and data values out to the parallel PORT IO. Every time the DMA is done sending a word/byte, it uses the Event System (EVSYS) to send an event to the CCL peripheral. When the CCL receives the event, it generates an active low pulse that drives the write enable pin to the ILI9488 display controller. This combination of DMA-EVSYS-CCL works like an external bus interface for writing parallel data out thru the PORT pins. The other control signals DC# and CS# are controlled by the CPU in GPIO mode. 

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

Some of these components use default settings, while other require some changes. The following is a list of all the components that required custom settings. 

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg1.png)

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg2.png)

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg5.png)

To setup the CCL to clock the pixel data, make sure PB09 is set to CCL_OUT2 

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg3.png)

Instead of write strobe, make sure PB17 is setup as RSDC instead

![](../../../../images/legato_qs_e54_cult_cpro_parallel_pg4.png)


Building the Application
------------------------

The parent directory for this application is apps/legato_benchmark. To build this application, use MPLAB X IDE to open the apps/legato_benchmark/firmware/legato_bm_e54_cult_cpro_parallel.X project file.

The following table lists configuration properties:

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_bm_e54_cult_cpro_parallel.X | SAM E54 Curiosity Ultra BSP | Legato Graphics w/ maXTouch Curiosity Pro Display | SAM E54 Curiosity Ultra w/ maXTouch Curiosity Pro display via 8-bit parallel interface |

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
--------------------------

This section describes how to configure the supported hardware. 

Configure the hardware as follows: 

* Attach the 24-bit pass through card to the GFX Connector on the SAM E54 Curiosity Ultra board. 
* Connect the ribbon cable from the maXTouch Curiosity Pro Display to the ribbon connector on the 24-bit pass through card. Make sure that the S1 switch on the 24-bit pass through card is set to 2. 
* On the backside of the maXTouch Curiosity Pro display, set the IM[2:0] switches to 011 for 8-bit MCU mode.

![](../../../../images/cpro_8_bit_parallel_conf.png)

* Connect a USB cable from the host computer to the DEBUG USB port on the SAM E54 Curiosity Ultra board. This USB connection is used for code download and debugging. 
* Connect 5.5V power supply to the SAM E54 Curiosity Ultra board is optional 

The final hardware setup should be: 

<img src="../../../../images/legato_qs_e54_cult_cpro_parallel_conf1.png"/>

Power up the board by connecting the power adapter to power connector or a powered USB cable to the DEBUG USB port on the board.

Running the Demonstration
--------------------------

On start-up, the application will display a splash screen.

After the splash-screen completes, the String Update benchmark screen is shown. In this screen, a counter is incremented at every application cycle. The screen demonstrates the rate at which the graphics library renders a string on the screen. This involves a fill operation that clears the background, lookup of the glyphs from the string library, and the drawing of the glyphs on the frame buffer.

<img src="../../../../images/legato_bm_e70_xu_tm4301b_run1.png"/>

The **Frame Update (Hz)** field shows the current or instantaneous rate at which the graphics library updates the label widget that shows the counter value. Touching the Frame Update value switches between the current value (curr) and the average (avg) value across 10 samples.

Touching the **+** and **-** buttons increases and decreases the size of the string, respectively.

Touching the **Next** button switches to the Motion and Fill benchmark screen. In this screen, squares are showing moving across the screen. The Frame Update value is the rate at which the graphics library is able to render all the squares on the screen at their new positions. This involves a fill operation of the background color at the old location of the squares and a fill of the squares colors at the new position

<img src="../../../../images/legato_bm_e70_xu_tm4301b_run2.png"/>

The number and size of the squares can be increased and decreased using the **+** and **-** buttons. If the maximum or minimum size is reached, touching **+** or **-**, respectively, will switch to a full screen fill of alternating colors.

Touching the **Next** button transitions to the Image Decode and Rendering screen. In this screen, two images of the same size are alternately rendered between application cycles. This involves a fill of the background color, decode and conversion of the image to the frame buffer format, and the drawing of the image to the frame buffer. The Frame Update value is the rate at which the graphics library is able to render an image on the screen.

<img src="../../../../images/legato_bm_e70_xu_tm4301b_run3.png"/>

The size of the images can be increased and decreased using the **+** and **-** buttons.

Touching the **<** and **>** buttons switches between the various image formats. The formats that are supported are PNG, RAW RLE 16-bit, RAW 16-bit and JPG 24-bit.

* * * * *
