/*
 * MCU Pinouts:

IMG:

80	GPIO_AD_B1_10	UART4_TX	CIA Board
79	GPIO_AD_B1_11	UART4_RX	CIA Board
 */
#include <img_wrap.h>
#include <imag_task.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

uint8_t recv_buffer[RESPONSE_LENGTH]; // Receive 5 bytes
uint8_t package_buffer[EXTERNAL_PACKAGE_SIZE]; // Packages sent from IMG are 32 bytes or less
unsigned int returnedSize[IMAGES_COUNT]; //size of image at each slot

volatile uint8_t receivePackageFlag = 0;
volatile uint8_t receiveLastPackageFlag = 0;
unsigned int fullPackages, remainingBytes;

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

		status = LPUART_RTOS_Send(&LPUART4_rtos_handle, toSend, sizeof(toSend)/sizeof(toSend[0]));

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

// Receive response from IMG system, response should be 5 bytes long fixed
status_t getResponse(){
	status_t status;
    size_t n = 0;

	if (receivePackageFlag) {
		status = LPUART_RTOS_Receive(&LPUART4_rtos_handle, package_buffer, EXTERNAL_PACKAGE_SIZE, &n);
		receivePackageFlag = 0;
	} else if (receiveLastPackageFlag) {
		status = LPUART_RTOS_Receive(&LPUART4_rtos_handle, package_buffer, remainingBytes, &n);
		receiveLastPackageFlag = 0;
	} else {
		status =  LPUART_RTOS_Receive(&LPUART4_rtos_handle, recv_buffer, RESPONSE_LENGTH, &n);
	}
	/*PRINTF("%d", recv_buffer[0]);
	PRINTF("%d", recv_buffer[1]);
	PRINTF("%d\n", recv_buffer[2]);*/

	if(status == kStatus_Success){
		PRINTF("Response received!\r\n");
		return status;
	} else if (status == kStatus_InvalidArgument){
		PRINTF("Invalid argument. Response not received.\r\n");
		return status;
	} else if (status == kStatus_LPUART_Timeout) {
		PRINTF("Timeout. Reponse not received.\r\n");
		return status;
	}
	return status;
}

// check status
IMG_system_response checkStatus(uint8_t IMG_param) {
	PRINTF("Checking status of: ");
	if (IMG_param == COMPONENT_ALL) {
		PRINTF("ALL COMPONENTS.\n");
		if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
		else if (recv_buffer[1] != CHECK_STATUS) return CMDFAILURE;
		else if (recv_buffer[2] != COMPONENT_ALL) return PARAMFAILURE;
	} else if (IMG_param == COMPONENT_UCAMIII) {
		PRINTF("UCAMIII.\n");
		if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
		else if (recv_buffer[1] != CHECK_STATUS) return CMDFAILURE;
		else if (recv_buffer[2] != COMPONENT_UCAMIII) return PARAMFAILURE;
	} else if (IMG_param == COMPONENT_SD) {
		PRINTF("SDCARD.\n");
		if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
		else if (recv_buffer[1] != CHECK_STATUS) return CMDFAILURE;
		else if (recv_buffer[2] != COMPONENT_SD) return PARAMFAILURE;
	}
	return SUCCESS;
}

// take picture
IMG_system_response takePicture(uint8_t IMG_param) {
	PRINTF("Taking picture at slot: %d.\n", IMG_param);
	if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
	else if (recv_buffer[1] != TAKE_PICTURE) return CMDFAILURE;
	else if (recv_buffer[2] != IMG_param) return PARAMFAILURE;
	return SUCCESS;
}

// get picture size
IMG_system_response getPictureSize(uint8_t IMG_param) {
	PRINTF("Getting picture size at slot: %d.\n", IMG_param);
	if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
	else if (recv_buffer[1] != GET_PICTURE_SIZE) return CMDFAILURE;
	else if (recv_buffer[2] != IMG_param) return PARAMFAILURE;

	returnedSize[IMG_param] = recv_buffer[3] << 8 | recv_buffer[4];
	PRINTF("size = %d.\n", returnedSize[IMG_param]);

	return SUCCESS;
}

// get picture
IMG_system_response getPicture(uint8_t IMG_param) {
	// get image size in prior to know number of packages
	IMG_system_response getPictureSizeResponse = getPictureSize(IMG_param);
	if (getPictureSizeResponse == SUCCESS) {
		unsigned int pictureSize = returnedSize[IMG_param];
		fullPackages = pictureSize / (EXTERNAL_PACKAGE_SIZE - 1); // last byte is verification byte
		remainingBytes = pictureSize - fullPackages * (EXTERNAL_PACKAGE_SIZE - 1);
		PRINTF("pictureSize = %d,\n", pictureSize);
		PRINTF("fullPackages = %d, \n", fullPackages);
		PRINTF("remainingBytes = %d.\n", remainingBytes);

		/* Checking response of valid command */
		sendCommand(GET_PICTURE, IMG_param);
		// TODO: some code to wait for interrupt
		/*extern volatile bool responseReceivedFlag;
		while (responseReceivedFlag == false) {
			delay(1);
		}
		responseReceivedFlag = true;*/
		delay(1);
		// at this point we know new response is received
		if (recv_buffer[0] != ACK) return HANDSHAKEFAILURE;
		else if (recv_buffer[1] != GET_PICTURE) return CMDFAILURE;
		else if (recv_buffer[2] != IMG_param) return PARAMFAILURE;
		else PRINTF("ExternalACK received, ready to receive data.\n");

		/* Begin reading data */
		for (int i = 0; i < fullPackages; i++) {
			memset(package_buffer, 0, sizeof(package_buffer)); // clear buffer before receiving package
			receivePackageFlag = 1; // reset flag before sending ACK
			 if (kStatus_Success == LPUART_RTOS_Send(&LPUART4_rtos_handle, &ACK, 1)) {
				 	while(1) {// retry until package received is correct
				 		// wait for package
				 		while(receivePackageFlag == 1){delay(1);}
				 		if (package_buffer[EXTERNAL_PACKAGE_SIZE - 1] != 0xFF) {
				 			PRINTF("verification byte is not 0xFF, need to resend package.\n");
				 			LPUART_RTOS_Send(&LPUART4_rtos_handle, &NAK, 1); //NAK, request resend package
				 		} else {
				 			LPUART_RTOS_Send(&LPUART4_rtos_handle, &ACK, 1);
				 			// print out package_buffer, excluding verification byte
				 			char tmp[3] = {0};
				 			for (int j = 0; j < EXTERNAL_PACKAGE_SIZE - 1; j++) {
				 				sprintf(tmp, "%02X", (int)package_buffer[j]);
				 				PRINTF("%s", tmp);
				 			}
				 			PRINTF("\n");
				 			if (i == fullPackages - 1) LPUART_RTOS_Send(&LPUART4_rtos_handle, &ACK, 1); // ACK for last package
				 			break;
				 		}
				 	}
			 }
		}

		// receive last (incomplete) package
		memset(package_buffer, 0, sizeof(package_buffer)); // clear buffer before receiving package
		while(1) {// retry until package received is correct
			receiveLastPackageFlag = 1;
			if (kStatus_Success == LPUART_RTOS_Send(&LPUART4_rtos_handle, &ACK, 1)) {
				while(1) {// retry until package received is correct
					// wait for package
					while(receiveLastPackageFlag == 1);
					if (package_buffer[EXTERNAL_PACKAGE_SIZE - 1] != 0xFF) {
						PRINTF("verification byte is not 0xFF, need to resend package.\n");
						LPUART_RTOS_Send(&LPUART4_rtos_handle, &NAK, 1); //NAK, request resend package
					} else {
						LPUART_RTOS_Send(&LPUART4_rtos_handle, &ACK, 1);
						// print out package_buffer, excluding verification byte
						char tmp[3] = {0};
						for (int j = 0; j < EXTERNAL_PACKAGE_SIZE - 1; j++) {
							sprintf(tmp, "%02X", (int)package_buffer[j]);
							PRINTF("%s", tmp);
						}
						PRINTF("\n");
						break;
					}
				}
			}
		}
	} else {
		return getPictureSizeResponse;
	}
}

// set contrast
IMG_system_response setContrast(uint8_t IMG_param) {
	return SUCCESS;
}

// set brightness
IMG_system_response setBrightness(uint8_t IMG_param) {
	return SUCCESS;
}

// set exposure
IMG_system_response setExposure(uint8_t IMG_param) {
	return SUCCESS;
}

// set sleep time
IMG_system_response setSleepTime(uint8_t IMG_param) {
	return SUCCESS;
}
