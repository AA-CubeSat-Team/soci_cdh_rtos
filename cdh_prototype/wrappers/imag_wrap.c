#include <stdint.h>
#include <imag_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

extern uint8_t recv_buffer[5]; // Receive 5 bytes
static uint8_t package_buffer[32]; // Packages sent from IMG are 32 bytes or less
static uint8_t image_storage[256]; // FIX THIS -- How large and what type of buffer for receiving images? 
const uint8_t EXTERNAL_PACKAGE_SIZE = 32; // External packages should be 32 bytes (receiving image files)
const uint8_t ACK = 1;
const uint8_t NAK = 0;

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
// Returns the number of bytes received
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

// Gets individual packages and stores them in image_storage
// Returns NAK if package could not be retrieved, packageSize if successful
uint8_t getPackage(){
	// Receive package in package_buffer (Send NAK to retry up to 3 times)
	int attempt = 1;
	uint8_t packageSize;
	PRINTF("-- Requesting Package from IMG --");
	status_t receiveStatus = LPUART_RTOS_Receive(&uart4_handle, package_buffer, sizeOf(package_buffer), &packageSize);
	while (receiveStatus != kStatus_Success && attempt <= 3){
			
		if (status == kStatus_InvalidArgument){
			PRINTF("Invalid argument. Package could not be fetched.\r\n", i);
			return NAK;
		} else if (status == kStatus_Fail) {
			PRINTF("Attempt %d failed to fetch package. Retrying...\r\n", attempt);
		}
		if(attempt == 3){
			PRINTF("Failed to fetch package after 3 attemps.\n", i);
			return NAK; 
		}
		attempt++;
		receiveStatus = LPUART_RTOS_Receive(&uart4_handle, package_buffer, sizeOf(package_buffer), &packageSize); // Retry Receiving
	}

	PRINTF("Fetching package succeeded!\r\n");
	
	int imageStorageSlot; // Position in image_storage to store new bytes
	//Copy package_buffer to image_storage
	for(int j = 0; j < EXTERNAL_PACKAGE_SIZE; j++){
		imageStorageSlot = (i * EXTERNAL_PACKAGE_SIZE + j);
		image_storage[imageStorageSlot] = package_buffer[j];
	}	
	return packageSize;
}



// To fetch image files from IMG ()
// Param sizeHighByte  The high size byte of the image file (recv_buffer[3] if get<image>Size is called)
// Param sizeLowByte   The low size byte of the image file (recv_buffer[4] if get<image>Size is called
// Returns 			   Total image bytes received
size_t getImage(uint8_t sizeHighByte, uint8_t sizeLowByte){ // Long function --> Split up?

	status_t sendStatus;
	size_t image_bytes_received = 0; // To track total image bytes received
	size_t packageSize; // To check whether a full package (32 bytes) was received 
	uint8_t padding = 0xAA;
	uint8_t imageSize = sizeHighByte << 8 | sizeLowByte; 
	uint8_t fullPackages = imageSize / EXTERNAL_PACKAGE_SIZE; // Max value of 8 currently (Due to image_storage have size 256)?
	uint8_t remainingBytes = imageSize % EXTERNAL_PACKAGE_SIZE;

	PRINTF("Fetching image from IMG system... \n");

	// Reset storage memory before storing the new image file
	memset(image_storage, 0, sizeOf(image_storage));

	//Receive all packages followed by the remaining bytes 
	//May need to change this to a while loop
	for(int i = 0; i <= fullPackages; i++){

		PRINTF("Requesting package %d from IMG...\r\n", i);

		// Reset package_buffer before receiving each new package
		memset(package_buffer, 0, sizeOf(package_buffer));

		// Request package by sending ACK (= 0x01)
		sendStatus = sendCommand(ACK, padding); // Will this get confused with sending takePicture command?
		if(sendStatus == kStatus_Success){
			PRINTF("Package %d requested from IMG\r\n", i);
			packageSize = getPackage();
			if(packageSize == NAK){
				PRINT("Failed to receive package %d. Retrying...\r\n", i);
				sendCommand(NAK, padding); // Will this get confused with sending checkStatus command?
				packageSize = getPackage(); // Retry receiving the package - Might need to swap for while loop
			}
		} else if {
			PRINTF("Package %d request failed. Image cannot be retrieved.\r\n");
			return image_bytes_received;
		}
		image_bytes_received += packageSize;
	}
	// Confirm that the last byte was received 
	sendStatus = sendCommand(ACK, padding); // Will this get confused with sending takePicture command?
	if(sendStatus == kStatus_Success){
			PRINTF("Fetching image succeeded!"); // Image bytes successfully stored in image_storage
		} else if {
			PRINTF("Error: Could not notify IMG of last byte being received.\r\n"); 
		}
	return image_bytes_received; 
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

// Param slot  Indicates where in the microSD card to find the thumbnail
uint8_t getThumbnailSize(uint8_t slot){

	PRINTF("-- Fetching the size of thumbnail at slot 0x%X --\r\n", slot);
	status_t sendStatus = sendCommand(GET_THUMBNAIL_SIZE, slot); 
	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != GET_THUMBNAIL_SIZE ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  GET_THUMBNAIL_SIZE, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Thumbnail size is 0x%X 0x%X. --\n", GET_THUMBNAIL_SIZE, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getThumbnailSize complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send getThumbnailSize command to IMG --\n");
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

// NEEDS WORK ?
// Param slot  Indicates where in the microSD card to find the thumbnail
uint8_t getThumbnail(uint8_t slot){

	PRINTF("-- Fetching the thumbnail at slot 0x%X --\r\n", slot);
	PRINTF("-- Fetching the thumbnail size --");
	uint8_t sizeStatus = getThumbnailSize(slot);

	if(sizeStatus == ACK){
		PRINTF("-- Thumbnail size fetched successfully --");
	} else {
		PRINTF("-- Failed to fetch thumbnail size. --");
		return NAK;
	}

	status_t sendStatus = sendCommand(GET_THUMBNAIL, slot); // What does this do? Initialize the data stream? 
	size_t imageBytesReceived = getImage(recv_buffer[3], recv_buffer[4]);

	if(sendStatus == kStatus_Success){ 	// Only check response if sending the command was successful
		size_t bytesReceived = getResponse();
		if(bytesReceived == 5){ // Only check errors if receiving the response was successful 
			
			uint8_t errorCheck = checkError();
			// Check that the output is as expected
			if(recv_buffer[0] != 1 ||
			recv_buffer[1] != GET_THUMBNAIL ||
			recv_buffer[2] != slot) {
				PRINTF("-- Not Acknowledged. You sent 0x%X 0x%X. Error 0x%X occurred. --\n",  GET_THUMBNAIL, slot, errorCheck);
			} else {
				PRINTF("-- Acknowledged. You sent 0x%X 0x%X. Thumbnail  0x%X 0x%X. --\n", GET_THUMBNAIL, slot, recv_buffer[3], recv_buffer[4]);
			}
			printResponse(); // Prints the recv_buffer without the padding bytes
			PRINTF("-- getThumbnail complete --\n");
			return ACK;
		} else {
			PRINTF("-- Failed to get response from IMG --\n");
			return NAK;
		}	
	} else {
		PRINTF("-- Failed to send getThumbnail command to IMG --\n");
		return NAK;
	}
}

//NEEDS WORK (Same idea as getThumbnail)
// Param slot  Indicates where in the microSD card to find the picture
size_t getPicture(uint8_t slot){
	size_t imageBytesReceived = 0;
	PRINTF("-- Running getPicture command. --");
	PRINTF("-- Fetching picture size at slot 0x%X --\r\n", slot);
	uint8_t sendStatus = getPictureSize(slot);
	if(sendStatus == ACK){
		PRINTF("-- Picture size fetched successfully --");
	} else {
		PRINTF("-- Failed to fetch thumbnail size. --");
		return NAK;
	}
	PRINTF("-- Fetching picture at slot 0x%X --\r\n", slot);
	sendStatus = sendCommand(GET_PICTURE, slot); //Initialize data stream
	if(sendStatus == kStatus_Success){ 	// Only try receiving image if sending the command was successful
			imageBytesReceived = getImage(recv_buffer[3], recv_buffer[4]); 
	} else {
		PRINTF("-- Failed to fetch picture size from IMG --");
		return imageBytesReceived;
	}


	//Add error checking


	return imageBytesReceived;
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




