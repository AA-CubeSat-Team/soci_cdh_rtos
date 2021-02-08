/* This is a source file for testing IMG functions
 * UART 4
 *
 * GPIO_AD_B1_10	UART4_TX
 * GPIO_AD_B1_11	UART4_RX
 *
 */

#include "cia.h"
#include <stdio.h>

int main(void){

	// define IMG variables

}


void testCheckStatus(char parameter) {

	printf("--Begin testCheckStatus--");

	// To check all components
	if(parameter == '0'){

		/* sendCommand(CHECK_STATUS, COMPONENT_ALL); */

		/* Loop to get all values for responseBytes */

		/* Check contents of responseBytes [0],[1],[2] are proper values,
		 * otherwise print all contents of responseBytes and report Error
		 */

	}

	// To check uCamIII
	else if(parameter == '1'){

		/* sendCommand(CHECK_STATUS, COMPONENT_UCAMIII); */

		/* Loop to get all values for responseBytes */

		/* Check contents of responseBytes [0],[1],[2] are proper values,
		 * otherwise print all contents of responseBytes and report Error
		 */

	}

	// To check SD Shield
	else if(parameter == '2'){

		/* sendCommand(CHECK_STATUS, COMPONENT_SD); */

		/* Loop to get all values for responseBytes */

		/* Check contents of responseBytes [0],[1],[2] are proper values,
		 * otherwise print all contents of responseBytes and report Error
		 */

	}

	printf("\n-- testCheckStatus() completed --");

}

void testTakePicture(){

	printf("--Begin testTakePicture--");




}
