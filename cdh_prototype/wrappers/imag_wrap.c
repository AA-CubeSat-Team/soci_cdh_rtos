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

extern uint8_t recv_buffer[5]; // Receive 5 bytes
extern uint8_t package_buffer[32]; // Packages sent from IMG are 32 bytes
extern uint8_t imageBuffer[200] // FIX THIS -- How large and what type of buffer for receiving images? 
const uint8_t SUCCESS = 1;
const uint8_t FAILURE = 0;

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
			if(attempt == 3){
				PRINTF("All attempts failed. Command not sent.");
			}
		}
	}	
	return status;
}

// To fetch response from IMG
size_t getResponse(){

	//Response format: <Response> <Command> <Command specifier> <Error> <Padding> *Padding is sometimes significant
	status_t status;
	size_t responseSize = 0; // Default value, will update to number of bytes received ("5" expected)

	PRINTF("Fetching response from IMG system... \n");

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
			return responseSize;
		} else if (status == kStatus_Fail) {
			PRINTF("Attempt %d failed to fetch response. Retrying...\r\n", attempt);
			if(attempt == 3){
				PRINTF("Failed to fetch response.\n");
			}
		}
	}	

	return responseSize; 
}









// To fetch image files from IMG ()
uint8_t getImage(param low byte size, param big byte size)){

	status_t status;
	size_t responseSize = 0; // Default value, will update to number of bytes received ("5" expected)

	PRINTF("Fetching response from IMG system... \n");

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
			return responseSize;
		} else if (status == kStatus_Fail) {
			PRINTF("Attempt %d failed to fetch response. Retrying...\r\n", attempt);
			if(attempt == 3){
				PRINTF("Failed to fetch response.\n");
			}
		}
	}	

	return responseSize; 
}






















// Checks for errors returned in the recv_buffer.
// Returns the value of the error byte 
uint8_t checkError(){

	//Check the first byte for <Response> 
	if(recv_buffer[0] == 1){
		PRINTF("Acknowledged."); // Previous command was successful
	} else if(recv_buffer[0] == 0){
		PRINTF("Not Acknowledged."); // Previous command failed
		// Since the previous command failed, check the error specifier in byte 4
		if(recv_buffer[3] == 0){
			PRINTF("uCam-III is not responding.\r\n");
		} else if(recv_buffer[3] == 1){
			PRINTF("SD Breakout Board is not responding.\r\n");
		} else if(recv_buffer[3] == 2){ 
			PRINTF("Command sent was not complete.\r\n");
		} else if(recv_buffer[3] == 3){
			PRINTF("Command sent was not recognized.\r\n");
		} else if(recv_buffer[3] == 4){
			PRINTF("Slot sent was not in range.\r\n");
		} else if(recv_buffer[3] == 5){
			PRINTF("Integer setting was not in range.\r\n");
		} else if(recv_buffer[3] == 6){
			PRINTF("Attempted to use a non-existent file.\r\n");
		} else {
			PRINTF("Unrecognized error. Error byte is greater than 6.\r\n");
		}
	}
	return recv_buffer[3]; // This will be padded with 0xAA (=170) if there's no error
}

// Prints the recv_buffer without the padding bytes
void printResponse(){
	int loop; // Determines how many slots of the recv_buffer to print

	if(recv_buffer[3] == 0xAA){
		loop = 3; // Print 3 slots
	} else if(recv_buffer[4] == 0xAA){
		loop = 4; // Print 4 slots
	} else {
		loop = 5; // Print 5 slots
	}

	//Print the recv_buffer 
	PRINTF("Received : ");
	for(int i = 0; i < loop; i++){
		PRINTF("0x%X ", recv_buffer[i]);
	}
	PRINTF(" \n");
}

// Checks the health of the components of the IMG system
// device - Designates which device's status to check 
// (0) All Systems (1) uCamIII (2) SD Breakout Board
uint8_t checkStatus(uint8_t device) {

	if (device == 1) { 
		PRINTF("-- Begin checking the health of the uCamIII --\n");
	} else if (device == 2) {
		PRINTF("-- Begin checking the health of the SD Breakout Board --\n");
	} else {
		//Default status check operation
		PRINTF("-- Begin checking the health of All Components --\n");
	}

	status_t sendStatus = sendCommand(commandByte0, device); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte0 ||
			recv_buffer[2] != device) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte0, device, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Requested test passed. --\n", commandByte0, device);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- checkStatus complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send checkStatus command to IMG --\n");
		return FAILURE;
	}
}


// Sends command to take a picture
// Param slot  Indicates where in the microSD card to store the thumbnail
uint8_t takePicture(uint8_t slot){

	PRINTF("-- Sending command to take a picture (with thumbnail stored at slot 0x%X) --\r\n", slot);
	status_t sendStatus = sendCommand(commandByte1, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte1 ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte1, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Image has been successfully stored at slot 0x%X. --\n", commandByte1, slot, slot);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- takePicture complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send takePicture command to IMG --\n");
		return FAILURE;
	}
}

// Param slot  Indicates where in the microSD card to find the thumbnail
uint8_t getThumbnailSize(uint8_t slot){

	PRINTF("-- Fetching the size of thumbnail at slot 0x%X --\r\n", slot);
	status_t sendStatus = sendCommand(commandByte2, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte2 ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte2, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Thumbnail size is 0x%X 0x%X. --\n", commandByte2, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getThumbnailSize complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send getThumbnailSize command to IMG --\n");
		return FAILURE;
	}
}

// Param slot  Indicates where in the microSD card to find the picture
uint8_t getPictureSize(uint8_t slot){

	PRINTF("-- Fetching the size of picture at slot 0x%X --\r\n", slot);
	status_t sendStatus = sendCommand(commandByte3, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte3 ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte3, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Picture size is 0x%X 0x%X. --\n", commandByte3, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getPictureSize complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send getPictureSize command to IMG --\n");
		return FAILURE;
	}
}

// NEEDS WORK 
// Param slot  Indicates where in the microSD card to find the thumbnail
uint8_t getThumbnail(uint8_t slot){

	PRINTF("-- Fetching the thumbnail at slot 0x%X --\r\n", slot);

	status_t sendStatus = sendCommand(commandByte4, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte4 ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte4, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Thumbnail size is 0x%X 0x%X. --\n", commandByte4, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getThumbnail complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send getThumbnail command to IMG --\n");
		return FAILURE;
	}
}

//NEEDS WORK (Same idea as getThumbnail)
// Param slot  Indicates where in the microSD card to find the picture
void getPicture(uint8_t slot){

	sendCommand(commandByte5, slot);
	getResponse();


}


// Param contrastLevel  Corresponds to a level of contrast
uint8_t setContrast(uint8_t contrastLevel){

	if(contrastLevel == 0){
		PRINTF("-- Setting the contrast to 0x%X (Min). --\n", contrastLevel);
	} else if (contrastLevel == 1){
		PRINTF("-- Setting the contrast to 0x%X (Low). --\n", contrastLevel);
	} else if (contrastLevel == 2){
		PRINTF("-- Setting the contrast to 0x%X (High). --\n", contrastLevel);
	} else if (contrastLevel == 3){
		PRINTF("-- Setting the contrast to 0x%X (Max). --\n", contrastLevel);
	} else { //Default
		PRINTF("-- Setting the contrast to 0x%X (Normal). --\n", contrastLevel);
	}

	status_t sendStatus = sendCommand(commandByte6, contrastLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte6 ||
			recv_buffer[2] != contrastLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte6, contrastLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Contrast is now 0x%X. --\n", commandByte6, contrastLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setContrast complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send setContrast command to IMG --\n");
		return FAILURE;
	}
}

// Param brightnessLevel  Corresponds to a level of brightness
uint8_t setBrightness(uint8_t brightnessLevel){

	if(brightnessLevel == 0){
		PRINTF("-- Setting the brightness to 0x%X (Min). --\n", brightnessLevel);
	} else if (brightnessLevel == 1){
		PRINTF("-- Setting the brightness to 0x%X (Low). --\n", brightnessLevel);
	} else if (brightnessLevel == 2){
		PRINTF("-- Setting the brightness to 0x%X (High). --\n", brightnessLevel);
	} else if (brightnessLevel == 3){
		PRINTF("-- Setting the brightness to 0x%X (Max). --\n", brightnessLevel);
	} else { //Default
		PRINTF("-- Setting the brightness to 0x%X (Normal). --\n", brightnessLevel);
	}

	status_t sendStatus = sendCommand(commandByte7, brightnessLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte7 ||
			recv_buffer[2] != brightnessLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte7, brightnessLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Brightness is now 0x%X. --\n", commandByte7, brightnessLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setBrightness complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send setBrightness command to IMG --\n");
		return FAILURE;
	}
}

// Param exposureLevel  Corresponds to a level of exposure
uint8_t setExposure(uint8_t exposureLevel){

	if(exposureLevel == 0){
		PRINTF("-- Setting the exposure to 0x%X (-2). --\n", exposureLevel);
	} else if (exposureLevel == 1){
		PRINTF("-- Setting the exposure to 0x%X (-1). --\n", exposureLevel);
	} else if (exposureLevel == 2){
		PRINTF("-- Setting the exposure to 0x%X (1). --\n", exposureLevel);
	} else if (exposureLevel == 3){
		PRINTF("-- Setting the exposure to 0x%X (2). --\n", exposureLevel);
	} else { //Default
		PRINTF("-- Setting the exposure to 0x%X (0). --\n", exposureLevel);
	}

	status_t sendStatus = sendCommand(commandByte8, exposureLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte8 ||
			recv_buffer[2] != exposureLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte8, exposureLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Exposure is now 0x%X. --\n", commandByte8, exposureLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setExposure complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send setExposure command to IMG --\n");
		return FAILURE;
	}
}

// Param setSleepTime Corresponds to a length of time
void setSleepTime(uint8_t seconds){
	if(seconds == 0){
		PRINTF("-- Setting the sleep time to 0x%X seconds. (infinite, will not sleep) --\n", seconds);
	} else {
		PRINTF("-- Setting the sleep time to 0x%X or %u seconds. --\n", seconds, seconds);
	} 
	status_t sendStatus = sendCommand(commandByte9, seconds); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != commandByte9 ||
			recv_buffer[2] != seconds) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  commandByte9, seconds, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Sleep time is now 0x%X or %u seconds. --\n", commandByte9, seconds, seconds);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setSleepTime complete --\n");
			return SUCCESS;
		} else {
			PRINT("-- Failed to get response from IMG --\n");
			return FAILURE;
		}	
	} else {
		PRINTF("-- Failed to send setSleepTime command to IMG --\n");
		return FAILURE;
	}
}




