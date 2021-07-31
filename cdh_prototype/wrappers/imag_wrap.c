#include <stdint.h>
#include <imag_wrap.h>
#include <imag_task.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"
#include "semc_sdram.h"

extern uint8_t recv_buffer[5]; // Receive 5 bytes
static uint8_t package_buffer[32]; // Packages sent from IMG are 32 bytes or less
const uint8_t EXTERNAL_PACKAGE_SIZE = 32; // External packages should be 32 bytes (receiving image files)
uint8_t imageBytesReceived;


// To send commands to IMG
// Param command  The main command to send
// Param param    Specifies a sub command 
// Returns 		  UART Send status
status_t sendCommand(uint8_t command, uint8_t param){

	status_t status; 
	uint8_t toSend[] = { command, param };

	PRINTF("Sending command to IMG System... \n");

	// Send command to IMG (Max. 3 attempts)
	for (int attempt = 1; attempt <= 3; attempt++){
		
		status = LPUART_Writeblocking(LPUART_4, toSend, sizeof(toSend)/sizeof(toSend[0]));

		if(status == kStatus_Success){
			PRINTF("Sending command succeeded!\r\n");
			return status; 
		} else if (status == kStatus_InvalidArgument){
			PRINTF("Invalid argument. Command cannot be sent.\r\n");
			return status;
		} else if (status == kStatus_LPUART_Timeout) {
			PRINTF("Attempt %d failed to send. Retrying...\r\n", attempt);
			if(attempt == 3){
				PRINTF("All attempts failed. Command not sent.");
			}
		}
	}	
	return status;
}

// To fetch response from IMG
// Returns the number of bytes received
size_t getResponse(){

	//Response format: <Response> <Command> <Command specifier> <Error> <Padding> *Padding is sometimes significant
	status_t status;
	size_t responseSize = 0; // Default value, will update to number of bytes received ("5" expected)
	

	PRINTF("Fetching response from IMG system... \n");

	// Reset buffer memory before receiving
	memset(recv_buffer, 0, sizeof(recv_buffer));

	// fetch response from IMG, store in recv_buffer (Max. 3 attempts)
	for (int attempt = 1; attempt <= 3; attempt++){
		
		status = LPUART_RTOS_Receive(&uart4_handle, recv_buffer, sizeof(recv_buffer), &responseSize); // TODO: Needs to be updated

		if(status == kStatus_Success){
			PRINTF("Fetching response succeeded!\r\n");
			return responseSize; 
		} else if (status == kStatus_InvalidArgument){
			PRINTF("Invalid argument. Response could not be fetched.\r\n");
			return responseSize;
		} else if (status == kStatus_LPUART_Timeout) {
			PRINTF("Attempt %d timed out. Retrying...\r\n", attempt);
			if(attempt == 3){
				PRINTF("Failed to fetch response.\n");
			}
		}
	}	

	return responseSize; 
}

// Gets packages and stores them in image_storage -- When to send NAK?
// Returns imageBytesReceived  The number of image bytes received 
uint8_t getPackages(){
	status_t sendStatus; 
	bool retryPackage = false; // Default (True if the received package has an incorrect veri. byte and must be retried)
	uint8_t packageSize;
	uint8_t imageSize = recv_buffer[3] << 8 | recv_buffer[4]; 
	uint8_t fullPackages = imageSize / EXTERNAL_PACKAGE_SIZE; 
	uint8_t remainingBytes = imageSize % EXTERNAL_PACKAGE_SIZE;
	imageBytesReceived = 0;

	// Calculate next available slot in SDRAM
	uint8_t SDRAM_Image_Index = 0; // TODO: Zero is placeholder

	for(int i = 0; i <= fullPackages; i++){
		PRINTF("-- Requesting Package from IMG. --\r\n");
		if(retryPackage == false){
			status_t sendStatus = sendCommand(ACK, PADDING); // Will this get confused with sending takePicture command?
		} else if(retryPackage == true){
			// If the last package's verification byte was wrong, request the same package
			status_t sendStatus = sendCommand(NAK, PADDING); // Will this get confused with sending checkStatus command?
		}

		if(sendStatus == kStatus_Success){
			PRINTF("-- Package %d requested from IMG. --\r\n", i);
		} else {
			PRINTF("-- Package %d request failed. Image cannot be retrieved. --\r\n");
			return imageBytesReceived;
		}

		// Reset package_buffer before receiving each new package
		memset(package_buffer, 0, sizeof(package_buffer));

		PRINTF("-- Receiving package from IMG. --\r\n");

		status_t receiveStatus = LPUART_RTOS_Receive(&uart4_handle, package_buffer, sizeof(package_buffer), &packageSize); //TODO: Needs to be updated
		//Try receiving 3 times 
		int attempt = 1;
		while (receiveStatus != kStatus_Success && attempt <= 3){
			if (receiveStatus == kStatus_InvalidArgument){
				PRINTF("-- Invalid argument. Package could not be fetched. --\r\n");
				return imageBytesReceived;
			} else if (receiveStatus == kStatus_LPUART_Timeout) {
				PRINTF("-- Attempt %d failed to fetch package. Retrying... --\r\n", attempt);
			}
			if(attempt == 3){
				PRINTF("-- Failed to fetch package after 3 attempts. --\n");
				return imageBytesReceived; 
			}
			attempt++;
			receiveStatus = LPUART_RTOS_Receive(&uart4_handle, package_buffer, sizeof(package_buffer), &packageSize); // Retry Receiving TODO: Needs to be updated
		}
		// Check verification byte
		if(package_buffer[31] == 0xFF){
			// Package received correctly

			// Copy package_buffer to sdram 
			uint8_t SDRAMStorageSlot = SDRAM_Image_Index + i * EXTERNAL_PACKAGE_SIZE; // Position in SDRAM to store new bytes
			for(int j = 0; j < EXTERNAL_PACKAGE_SIZE; j++){
			sdram_writeBuffer[j] = package_buffer[j];
			}

			SEMC_SDRAM_Write(SDRAMStorageSlot, EXTERNAL_PACKAGE_SIZE, 1); 

			imageBytesReceived += packageSize;
			retryPackage = false;
		} else {
			// Package not received correctly (Retry current package)
			PRINTF("-- Package verification byte is incorrect (not 0xFF), retrying... --\r\n");
			retryPackage = true;
			i--; // To ensure the loop is ran one more time for the same package
		}
	}
	// Send image storage info to queue
	PRINTF("Sending image info to queue\r\n");
	uint8_t imageInfo[] = {SDRAM_Image_Index, imageBytesReceived};
	xQueueSend(QueueHandler_imag1, &imageInfo, 100);

	sendStatus = sendCommand(ACK, PADDING); // Confirmation of all packages received
	if(sendStatus == kStatus_Success){
		PRINTF("-- IMG notified of all packages being received --\r\n");
	} else {
		PRINTF("-- Failed to notify IMG of all packages being received --\r\n");
		return imageBytesReceived;
	}
	PRINTF("-- Fetched all packages successfully! --\r\n");
	PRINTF("-- Reading image from SDRAM --\r\n");

	// Read SDRAM (to sdram_readBuffer) and task will send the buffer to MCC through a FreeRTOS queue
	// SEMC_SDRAM_Read(0, imageBytesReceived, 1); COM will retrieve image?

	return imageBytesReceived;
}	

// Checks for errors returned in the recv_buffer.
// Returns the value of the error byte 
uint8_t checkError(){

	//Check the first byte for <Response> 
	if(recv_buffer[0] == ACK){
		PRINTF("Acknowledged."); // Previous command was successful
	} else if(recv_buffer[0] == NAK){
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

	status_t sendStatus = sendCommand(CHECK_STATUS, device); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != CHECK_STATUS ||
			recv_buffer[2] != device) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  CHECK_STATUS, device, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Requested test passed. --\n", CHECK_STATUS, device);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- checkStatus complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send checkStatus command to IMG --\n");
		return NAK;
	}
}


// Sends command to take a picture
// Param slot  Indicates where in the microSD card to store the thumbnail
uint8_t takePicture(uint8_t slot){

	PRINTF("-- Sending command to take a picture (with thumbnail stored at slot 0x%X) --\r\n", slot);
	status_t sendStatus = sendCommand(TAKE_PICTURE, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse(recv_buffer);
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != TAKE_PICTURE ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  TAKE_PICTURE, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Image has been successfully stored at slot 0x%X. --\n", TAKE_PICTURE, slot, slot);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- takePicture complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send takePicture command to IMG --\n");
		return NAK;
	}
}

// Param slot  Indicates where in the microSD card to find the picture
// Returns ACK (1) if successful or NAK (0) if unsuccessful
uint8_t getPictureSize(uint8_t slot){

	PRINTF("-- Fetching the size of picture at slot 0x%X --\r\n", slot);
	status_t sendStatus = sendCommand( GET_PICTURE_SIZE, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] !=  GET_PICTURE_SIZE ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",   GET_PICTURE_SIZE, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Picture size is 0x%X 0x%X. --\n",  GET_PICTURE_SIZE, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getPictureSize complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send getPictureSize command to IMG --\n");
		return NAK;
	}
}

// Param slot  Indicates where in the microSD card to find the picture
uint8_t getPicture(uint8_t slot){
	PRINTF("-- Fetching the picture at slot 0x%X --\r\n", slot);
	PRINTF("-- Fetching the picture size --\r\n");
	uint8_t sizeStatus = getPictureSize(slot);

	if(sizeStatus == ACK){
		PRINTF("-- Picture size fetched successfully --\r\n");
	} else {
		PRINTF("-- Failed to fetch picture size. --\r\n");
		return NAK;
	}
	int imageBytesExpected = recv_buffer[3] << 8 | recv_buffer[4];
	status_t sendStatus = sendCommand(GET_PICTURE, slot); // What does this do? Initialize the data stream? 

	if(sendStatus == kStatus_Success){ 	// Only try receiving packages if sending the command was successful
		int imageBytesReceived = getPackages();
		if(imageBytesReceived == imageBytesExpected){ // Receiving the packages was successful 
			// Is checking the error bytes in recv_buffer necessary?
			PRINTF("-- Picture received successfully and stored in image_storage. --\n");
			PRINTF("-- getPicture complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get picture from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send getPicture command to IMG --\n");
		return NAK;
	}
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

	status_t sendStatus = sendCommand(SET_CONTRAST, contrastLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != SET_CONTRAST ||
			recv_buffer[2] != contrastLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  SET_CONTRAST, contrastLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Contrast is now 0x%X. --\n", SET_CONTRAST, contrastLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setContrast complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send setContrast command to IMG --\n");
		return NAK;
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

	status_t sendStatus = sendCommand(SET_BRIGHTNESS, brightnessLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != SET_BRIGHTNESS ||
			recv_buffer[2] != brightnessLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  SET_BRIGHTNESS, brightnessLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Brightness is now 0x%X. --\n", SET_BRIGHTNESS, brightnessLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setBrightness complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send setBrightness command to IMG --\n");
		return NAK;
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

	status_t sendStatus = sendCommand(SET_EXPOSURE, exposureLevel); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != SET_EXPOSURE ||
			recv_buffer[2] != exposureLevel) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  SET_EXPOSURE, exposureLevel, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Exposure is now 0x%X. --\n", SET_EXPOSURE, exposureLevel);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setExposure complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send setExposure command to IMG --\n");
		return NAK;
	}
}

// Param setSleepTime Corresponds to a length of time
uint8_t setSleepTime(uint8_t seconds){
	if(seconds == 0){
		PRINTF("-- Setting the sleep time to 0x%X seconds. (infinite, will not sleep) --\n", seconds);
	} else {
		PRINTF("-- Setting the sleep time to 0x%X or %u seconds. --\n", seconds, seconds);
	} 
	status_t sendStatus = sendCommand(SET_SLEEP_TIME, seconds); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != SET_SLEEP_TIME ||
			recv_buffer[2] != seconds) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  SET_SLEEP_TIME, seconds, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Sleep time is now 0x%X or %u seconds. --\n", SET_SLEEP_TIME, seconds, seconds);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- setSleepTime complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send setSleepTime command to IMG --\n");
		return NAK;
	}
}




