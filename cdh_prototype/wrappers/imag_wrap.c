#include <stdint.h>
#include <imag_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

// Each command has a specific command byte that it sends to IMG
uint8_t commandByte0 = 0; // checkStatus
uint8_t commandByte1 = 1; // takePicture
uint8_t commandByte2 = 2; // getThumbnailSize
uint8_t commandByte3 = 3; // getPictureSize
uint8_t commandByte4 = 4; // getThumbnail
uint8_t commandByte5 = 5; // getPicture
uint8_t commandByte6 = 6; // setContrast
uint8_t commandByte7 = 7; // setBrightness
uint8_t commandByte8 = 8; // setExposure
uint8_t commandByte9 = 9; // setSleepTime

static uint8_t recv_buffer[5]; // Receive 5 bytes

// To send commands to IMG
// Param command  The main command to send
// Param param    Specifies a sub command 
status_t sendCommand(uint8_t command, uint8_t param){

	status_t status; 
	uint8_t toSend[] = { command, param };

	PRINTF("Sending command to IMG System... \n");

	// Send command to IMG (Max. 3 attempts)
	for (int attempt = 1; attempt <= 3; attempt++){
		
		status = LPUART_RTOS_Send(&uart4_handle, toSend, sizeOf(toSend));

		if(status == kStatus_Success){
			PRINTF("Sending command succeeded!\r\n");
			return status; 
		} else if (status == kStatus_InvalidArgument){
			PRINTF("Invalid argument. Command cannot be sent.\r\n");
			return status;
		} else if (status == kStatus_Fail) {
			PRINTF("Attempt %d failed to send. Retrying...\r\n", attempt);
		}
	}	
	return status;
}

// To fetch response from IMG
size_t getResponse(){

	//Response format: <Response> <Command> <Command specifier> <Error> <Padding> *Padding is sometimes significant
	status_t status;
	size_t responseSize = 0; // Default value, will update to number of bytes received ("5" expected)

	PRINTF("Fetching response from the IMG system... \n");

	// Reset buffer memory before receiving
	memset(recv_buffer, 0, sizeOf(recv_buffer));

	// fetch response from IMG, store in recv_buffer (Max. 3 attempts)
	for (int attempt = 1; attempt <= 3; attempt++){
		
		status = LPUART_RTOS_Receive(&uart4_handle, recv_buffer, sizeOf(recv_buffer), &responseSize);

		if(status == kStatus_Success){
			PRINTF("Fetching response succeeded!\r\n");
			return responseSize; 
		} else if (status == kStatus_InvalidArgument){
			PRINTF("Invalid argument. Response could not be fetched.\r\n");
			return 7; // Arbitrary value for error checking
		} else if (status == kStatus_Fail) {
			PRINTF("Attempt %d failed to fetch response. Retrying...\r\n", attempt);
		}
	}	
	return 8; // Arbitrary value for error checking
}


// Checks the health of the components of the IMG system
// device - Designates which device's status to check 
// (0) All Systems (1) uCamIII (2) SD Breakout Board
void checkStatus(uint8_t device) {

	if (device == 1) { 
		PRINTF("-- Begin checking the health of the uCamIII --");
	} else if (device == 2) {
		PRINTF("-- Begin checking the health of the SD Breakout Board --");
	} else {
		//Default status check operation
		PRINTF("-- Begin checking the health of All Components --");
	}
	sendCommand(commandByte0, device); 
	getResponse();

	//Error checking

	PRINTF("\n-- Acknowledged. You sent 0x00 0x0%u. Requested test passed. -- \n", device);
}


// Sends command to take a picture
// Param slot  Indicates where in the microSD card to store the thumbnail
void takePicture(uint8_t slot){

	sendCommand(commandByte1, slot);
	getResponse();
}



// Param slot  Indicates where in the microSD card to find the thumbnail
void getThumbnailSize(uint8_t slot){

	sendCommand(commandByte2, slot);
	getResponse;


}

// Param slot  Indicates where in the microSD card to find the picture
void getPictureSize(uint8_t slot){

	sendCommand(commandByte3, slot);
	getResponse;


}

// Param slot  Indicates where in the microSD card to find the thumbnail
void getThumbnail(uint8_t slot){

	sendCommand(commandByte4, slot);
	getResponse();

}

// Param slot  Indicates where in the microSD card to find the picture
void getPicture(uint8_t slot){

	sendCommand(commandByte5, slot);
	getResponse();


}

// Param contrastLevel  Corresponds to a level of contrast
void setContrast(uint8_t contrastLevel){

	sendCommand(commandByte6, contrastLevel);
	getResponse();

}

// Param brightnessLevel  Corresponds to a level of brightness
void setBrightness(uint8_t brightnessLevel){

	sendCommand(commandByte7, brightnessLevel);
	getResponse();

}

// Param exposureLevel  Corresponds to a level of exposure
void setExposure(uint8_t exposureLevel){

	sendCommand(commandByte8, exposureLevel);
	getResponse();

}

// Param setSleepTime Corresponds to a length of time
void setSleepTime(uint8_t seconds){

	sendCommand(commandByte9, seconds);
	getResponse();
}




