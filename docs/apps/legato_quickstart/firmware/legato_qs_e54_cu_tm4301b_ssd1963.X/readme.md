
![](../../../../images/mhgs.png) legato\_qs\_e54\_cu\_tm4301\_ssd1963.X

Defining the Architecture
-------------------------

![](../../../../images/legato_qs_e54_cu_tm4301b_ssd1963_arch.png)

This application demonstrates single-layer, WQVGA graphics using SRAM memory.

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.

### Demonstration Features 

* Legato Graphics Library
* Input system service and touch driver
* Time system service, timer-counter peripheral library and driver
* SSD1963 display controller driver
* PORT/GPIO peripheral library and driver
* I2C driver 
* 16-bit RGB565 color depth support (65535 unique colors)
* JPEG image stored in internal flash

Creating the Project Graph
--------------------------

![](../../../../images/legato_qs_e54_cu_tm4301b_ssd1963_pg.png)

The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the **SAM E54 Curiosity Ultra BSP** and **Legato Graphics w/ PDA TM4301B Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller.  

Building the Application
------------------------

The parent directory for this application is apps/legato_quickstart. To build this application, use MPLAB X IDE open the apps/legato_quickstart/firmware/legato_qs_e54_cu_tm4301b_ssd1963.X project file.

The following table lists configuration properties:

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_qs_e54_cu_tm4301b_ssd1963.X | SAM E54 Curiosity Ultra BSP | Legato graphics w/ PDA TM4301B Display | SAM E54 Curiosity Ultra w/ PDA TM4301B Display and SSD1963 display driver |

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

The final setup should be: 

![](../../../../images/legato_qs_e54_cu_tm4301b_ssd1963_conf1.png)

Running the Demonstration
-------------------------

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure different configurations may have slight variation in the screen aspect ratio.

![](../../../../images/legato_quickstart_wqvga_run.png)



* * * * *
