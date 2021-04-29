#include <stdint.h>
#include <imag_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

// To send commands to IMG
// Param command  The main command to send
// Param param    Specifies a sub command 
void sendCommand(uint8_t command, uint8_t param){

	uint8_t toSend[] = { command, param };

	PRINTF("Sending command to IMG System \n");

	int status; 

	do {
		status = LPUART_RTOS_Send(&uart4_handle, toSend, sizeOf(toSend));

		if (status == kStatus_Fail){
			printf("Sending command failed. Retrying...\r\n");
		} else if (status == kStatus_InvalidArgument){
			printf("Invalid Argument. Command cannot be sent.\r\n");
		} else if (status == kStatus_Success){
			PRINTF("Sending command succeeded!.\r\n");
		}
	}
	while (status == kStatus_Fail);
}

//getResponse()

void getResponse(/*&responseArray*/){

	//Always read 5 bytes
	//Response format: <Response> <Command> <depends on "Command"> <Error> <Padding> *Padding is sometimes significant

	
	//uart receive, retry if not == success
	int LPUART_RTOS_Receive(&uart4_handle, /* rec_v buffer, sizeOf(rec_v buffer), &n */);


	//declare uint8_t array with 5 slots
	uint8_t responseArray[] = {response, command, integer, error, padding};

	//print "Fetching Response"

	//return uint array with response bytes

}


// Checks the health of the components of the IMG system
// device - Designates which device's status to check 
// (0) All Systems (1) uCamIII (2) SD Breakout Board
void checkStatus(uint8_t device) {

	uint8_t commandByte = 0; // commandByte is 0 for checkStatus command

	if (device == 1) { 
		PRINTF("-- Begin checking the health of the uCamIII --");
	} else if (device == 2) {
		PRINTF("-- Begin checking the health of the SD Breakout Board --");
	} else {
		//Default status check operation
		PRINTF("-- Begin checking the health of All Components --");
	}
	sendCommand(commandByte, device); 
	getResponse();

	//Error checking

	PRINTF("\n-- Acknowledged. You sent 0x00 0x0%u. Requested test passed. -- \n", device);
}


// Sends command to take a picture
// Param slot  Indicates where in the microSD card to store the thumbnail
void takePicture(uint8_t slot){

	uint8_t commandByte = 1; // commandByte is 1 for takePicture command

	sendCommand(commandByte, slot);
	getResponse();
}



// Param slot  Indicates where in the microSD card to find the thumbnail
void getThumbnailSize(uint8_t slot){

	uint8_t commandByte = 2; // commandByte is 2 for getThumbnailSize command

	sendCommand(commandByte, slot);
	getResponse;


}

// Param slot  Indicates where in the microSD card to find the picture
void getPictureSize(uint8_t slot){

	uint8_t commandByte = 3; // commandByte is 3 for getPicture command

	sendCommand(commandByte, slot);
	getResponse;


}

// Param slot  Indicates where in the microSD card to find the thumbnail
void getThumbnail(uint8_t slot){

	uint8_t commandByte = 4; // commandByte is 4 for getThumbnail command

	sendCommand(commandByte, slot);
	getResponse();

}

// Param slot  Indicates where in the microSD card to find the picture
void getPicture(uint8_t slot){

	uint8_t commandByte = 5; // commandByte is 5 for getPicture command

	sendCommand(commandByte, slot);
	getResponse();


}

// Param contrastLevel  Corresponds to a level of contrast
void setContrast(uint8_t contrastLevel){

	uint8_t commandByte = 6; // commandByte is 6 for setContrast command

	sendCommand(commandByte, contrastLevel);
	getResponse();

}

// Param brightnessLevel  Corresponds to a level of brightness
void setBrightness(uint8_t commandByte, uint8_t brightnessLevel){

	//uint8_t commandByte = 7; // commandByte is 7 for setBrightness command

	sendCommand(commandByte, brightnessLevel);
	getResponse();

}

void setExposure(uint8_t commandByte, uint8_t exposureLevel){

	//uint8_t commandByte = 8; // commandByte is 8 for setExposure command

	sendCommand(commandByte, exposureLevel);
	getResponse();

}


void setSleepTime(uint8_t commandByte, uint8_t seconds){

	//uint8_t commandByte = 9; // commandByte is 9 for setSleepTime command

	sendCommand(commandByte, seconds);


}




