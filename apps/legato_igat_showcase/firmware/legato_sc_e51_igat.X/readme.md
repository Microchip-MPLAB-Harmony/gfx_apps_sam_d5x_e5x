
![](../../../../docs/images/mhgs.png) 

SAME51 IGaT Legato Showcase
-------------------------

Defining the Architecture
-------------------------

<img src="../../../../docs/html/legato_sc_e51_igat_block_diagram.png" width="800" height="480" />

This application showcases the capabilities of the SAME51 Integrated Graphics and Touch Development Kit.
The SAM E51 Integrated Graphics and Touch Development Kit is a low-cost reference design for HMI applications
using the SAME5x/D5x MCU for running both the graphics and touch functions in a single MCU. It features a 
480x320 HVGA Smart Display module with a Capacitive Touch Sensor Overlay.


The graphics function uses the Legato Harmony Graphics library and display driver to deliver the UI frames to
a smart display module thru an 8-bit parallel 8080 interface. This interface is driven from the MCU using a 
combination of the DMA, EVSYS, CCL and GPIO peripherals. 

The touch function uses the on-chip Peripheral Touch Controller (PTC) peripheral to acquire touch sensor information
from the Capacitive Touch Sensor. The Touch Sensor is connected to the PTC thru a 7x5 channel interface.

This demonstration also uses RAW images stored in the external SQI flash for the images on UI screens.


### Demonstration Features 

* Legato Graphics Library 
* Peripheral Touch Controller, 2D Touch Library with Basic Gestures
* Advanced Gestures Detection using the [Motion Gestures](https://motiongestures.com/) library
* Input system service and Integrated Touch Driver
* Time system service, timer-counter peripheral library and driver 
* ILI9488 display 8-bit parallel mode driver (DMA-CCL boosted) 
* 16-bit RGB565 color depth (8-bit palettized double buffering) 
* Port/GPIO peripheral 
* SST26 QSPI driver 
* External Image assets stored in external SQI Flash

Creating the Project Graph
--------------------------

<img src="../../../../docs/html/legato_sc_e51_igat_mhc.png" width="800" height="600" />

The MHC configuration for this project is unique to the SAM E51 IGaT Development Kit Hardware. To create a
duplicate project configuration, use the MHC import function to import the IGaT MHC configuration in
"legato_igat_showcase\firmware\src\config\ili9488_rgb565_e51_igat\ili9488_rgb565_e51_igat.mhc".


Building the Application
------------------------

The parent directory for this application is apps/legato_igat_showcase. To build this application, use MPLAB X IDE to open the apps\legato_igat_showcase\firmware\legato_sc_e51_igat.X project file.

The following table lists configuration properties:

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_sc_e51_igat.X | None | None| SAM E51 Integrated Graphics and Touch Development Kit |

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
--------------------------

This section describes how to configure the supported hardware. 

Configure the hardware as follows: 

* Connect a USB cable from the host computer to the DEBUG USB port on the SAM E51 Integrated Graphics and Touch Development Kit. This USB connection is used for code download and debugging. 

The final hardware setup should be: 

![](../../../../docs/html/legato_sc_e51_igat_board.png)


Updating the Graphics Assets in SQI Flash 
-----------------------------------------

The SAME51 Integrated Graphics and Touch board comes pre-programmed with the Showcase demo. The SQI flash is also pre-programmed with the image assets needed to run the demo.

![](../../../../docs/html/legato_igat_sc_asset_storage_diagram.png)

The SQI flash may need to be re-programmed if the external image assets get corrupted or if a new version of the Showcase demo requires new image assets. 

This section provides the steps on how to update firmware and the SQI Flash image on the SAME51 IGaT Curiosity board for the IGaT Showcase demo application.

This process requires a PC with a serial terminal application like [TeraTerm](https://ttssh2.osdn.jp/index.html.en) and 2 micro-USB cables to connect the board’s debug and target USB ports to the PC.

**Connect the board to the PC**

1. Debug USB connection to Host PC for Firmware Updates
1. Target USB connection for SQI Flash image update

![](../../../../docs/html/igat_usb_connections.png)

**Getting to the Application Setup**

SQI Flash Update process can be started from the Application Setup Screen. There are two ways to get to the Application Setup Screen:

1. Reboot, and tap the bottom part of the Intro Splash Screen during boot **, or
1. Tap the Setup button on the Menu Screen

** use this method if the buttons on the Menu Screen do not show up properly due to incorrect SQI Flash image

![](../../../../docs/html/igat_sqi_update_start.png)

**Starting the SQI Flash Update**

1. On the Application Setup screen, touch the “Erase & Update” button
1. Touch “Yes” to Erase the SQI Flash and wait for the Host PC to send the binary file

![](../../../../docs/html/igat_start_sqi_update.png)

**Downloading the SQI Flash Image**

On the Host PC, download and install the TeraTerm application.

1. Launch TeraTerm and start a New Connection  
2. Select Serial -> COMx: USB Serial Port**  
3. Go to File -> Send File to select the file to send  
4. Select the SQI Flash binary file QSPI_IMG.bin**  
	a. Make sure “Binary” Option is checked (***very important***)  	
	b. Click Open to continue

_** QSPI_IMG.bin can be copied from apps\legato_igat_showcase\firmware\src\config\ili9488_rgb565_e51_igat\.legato_generate_cache.zip_


![](../../../../docs/html/igat_download_image.png)

**Completing the SQI Flash Update**

Download progress is shown in TeraTerm, and in the application  

![](../../../../docs/html/igat_download_progress.png)

1. TeraTerm dialog box will close when download is complete.
1. Tap “Restart Application” to restart the application with the new SQI Flash binary

![](../../../../docs/html/igat_restart.png)


Running the Demonstration
--------------------------

When power-on is successful, the application will show a splash screen and then the menu screen.

![](../../../../docs/html/igat_splash_main_menu.png)

Tapping on any of the menu icons will open the various demonstration screens. Each screen is interactive, and basic gestures like two-finger swipe can be used to move between screens.

![](../../../../docs/html/igat_splash_music_color.png)
![](../../../../docs/html/igat_touch_infopage.png)
![](../../../../docs/html/igat_car_basic_app.png)

The Application Setup page provides controls for enabling metrics, updating the the SQI flash and other global application settings like advanced gesture recognition.

![](../../../../docs/html/igat_settings.png)

Active gesture recognition demonstrates basic gesture detection using the H3 Touch Library or Advanced Gestures using the [Motion Gestures](https://motiongestures.com/).

![](../../../../docs/html/igat_active_gestures.png)

**Low Power Mode and Proximity Sensing**

The application will automatically enter low power mode after 30 seconds of inactivity. Low power mode can also be initiated by double-tapping the upper left corner of the display.

During low power mode, proximity detection is enabled and the application will exit low power mode when proximity or touch input is detected.



* * * * *
