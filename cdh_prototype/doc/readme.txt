Overview
========
CDH prototype is the flight software for the A & A CubeSat team at University of Washington.
The software consists of four tasks: COM, GNC, IDLE, and IMG. The COM Task keep task of the
the radio communication with the ground station. The GNC Task keep task of the advanced
guidance navigation control. The idle task keep track of the the electric power system. The
imaging task keep track of the imaging board and commands when to take pictures.

Changing UART/I2C/SPI seetting
==============================
To change the peripheral/serial communication protocol driver setting go to the tab above and 
press ConfigTools. On the drop down menu for the ConfigTools press on peripherals to change 
the serial communication protocol driver. After changes are made, press update code to apply 
the changes.

Serial Communication Protocol Driver Issue
==========================================
1. Check that you are using the correct pins based on the header pins on the Google Drive.
2. Check that you are passing the correct parameters for serial communication protocol driver.
3. Check that .settings/langauge.settings and .cproject (on the cdh_prototype directory) is 
   the same as the one in dev branch. if not copy and past the the one from dev branch.
4. Use a logic analyzer to read the signals coming out from the drivers if issue still persist
   contact one of the members in CDH.

Hardware requirements
=====================
- Mini/micro USB cable (only works with the NXP cable in the box)
- EVK-MIMXRT1020 board
- Personal Computer