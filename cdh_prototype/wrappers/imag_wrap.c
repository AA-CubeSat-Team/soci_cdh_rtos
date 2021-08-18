/*
 * MCU Pinouts:

IMG:

80	GPIO_AD_B1_10	UART4_TX	CIA Board
79	GPIO_AD_B1_11	UART4_RX	CIA Board
 */
#include <imag_wrap.h>
#include <imag_task.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

extern uint8_t recv_buffer[5]; // Receive 5 bytes
static uint8_t package_buffer[32]; // Packages sent from IMG are 32 bytes or less
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

		status = LPUART_WriteBlocking(LPUART_4, toSend, sizeof(toSend)/sizeof(toSend[0]));

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
	status =  LPUART_ReadBlocking(LPUART_4, recv_buffer, RESPONSE_LENGTH);
	PRINTF("%d", recv_buffer[0]);
	PRINTF("%d", recv_buffer[1]);
	PRINTF("%d\n", recv_buffer[2]);\

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
	return SUCCESS;
}

// get picture size
IMG_system_response getPictureSize(uint8_t IMG_param) {
	return SUCCESS;
}

// get picture
IMG_system_response getPicture(uint8_t IMG_param) {
	return SUCCESS;
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


