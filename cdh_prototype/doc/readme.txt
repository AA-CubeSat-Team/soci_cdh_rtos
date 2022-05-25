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
   
COSMOS GUIDE
============
/tasks/telemetry.h		| contains the definition of the packet structures
/source/cdh_prototype.h | contains the preprocessor to turn on different modes of the software.
/tasks/com_task.*		| contains the COM task flow
/wrappers.com_wrapper.*	| contains the wrapper functions for com task

COSMO TEST Project overview
-----------------------------
The CDH prototype with COSMOS_TEST set as 1 is a simple software that receive all the payload
then send what ever payload is stored by the prep_payload(). The payloads are stored in the file
described below.

setting up to test COSMOS with the Dev Board
--------------------------------------------
1) on cdh_prototype.h, make sure the preprocessor is defined as:
#define OBC 0			
#define COM_ENABLE	0 	// Change it 1 if testing with the COM Radio (not ready)
#define COSMOS_TEST 1 	// ENABLES COSMOS Test
2) modify the data structures on telemetry.h
3) com_wrap.c, prep_payload() | to store the necessary data
4) com_wrap.c, send_payload() | send all the payload

Running the Program
-------------------
Go to the quickstart panel -> on the bottom left press quick settings>> -> hover over SDK Debug Console -> select UART console
Press debug

NOTES:
*Applies to only when the debug console is UART not semihost*
GETCHAR() | serves as a receive function
PRINTF()  | serves as a send function
 

Hardware requirements
=====================
- Mini/micro USB cable (only works with the NXP cable in the box)
- EVK-MIMXRT1020 board
- Personal Computer