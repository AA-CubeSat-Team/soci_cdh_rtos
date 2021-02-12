#include <stdint.h>
#include <imag_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"

/*to send commands to IMG*/
void sendCommand(unit8_t command, unit8_t param){

	unit8_t toSend[] = { command, param };

	PRINTF("Sending command to IMG System: ")

	int status = LPUART_RTOS_Send(/*handle*/, &toSend, sizeOf(toSend));

	if (status != kStatus_Success){
		PRINTF("Sending command failed!.\r\n");
	}
	else{
		PRINTF("Sending command succeeded!.\r\n");
	}

}

void testCheckStatus(char parameter) {

	PRINTF("--Begin Testing All Status--");







	PRINTF("\n-- Testing All Status Completed --");

}
