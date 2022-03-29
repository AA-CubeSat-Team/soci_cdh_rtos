#include <stdbool.h>
#include "peripherals.h"
#include "com_wrap.h"
#include "com_task.h"
#include "com_protocol_helper.h"

#define CLOCKS_PER_SECOND 1000000

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;
//bool com_wrap_debug = true; // Turn this true if you want to test individual functions

TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;
extern bool i2c_com_antennaDeployed;

void com_task(void *pvParameters)
{
#if COM_WRAP_DEBUG
	// Delay to test "soft-break" into command mode via com_init function
	// delay(1);

//	PRINTF("TESTING CONTINOUS SENDING\n");
//	testSending();

	PRINTF("Testing enterCommandMode function:\n");
	//com_enterCommandMode();
	PRINTF("\n");

	//Testing if sending a command to the radio (non delay dependent) works
	PRINTF("Testing exitCommandMode function:\n");;
	//com_exitCommandMode();
	PRINTF("\n");

	//Test sending data to radio in data mode
	PRINTF("Testing data mode: \n");
	testSending();
	PRINTF("\n");

//	PRINTF("CONFIGURING THE RADIO\n");
//	com_radio_init();

	//PRINTF("Testing com_init() function:\n");
	//com_init();
	//PRINTF("\n");

	//PRINTF("Testing com_healthcheck() function:\n");
	//com_healthcheck(); // exits command mode afterwards
	//PRINTF("\n");

	//PRINTF("Testing com_set_burn_wire1()\n");
	//com_set_burn_wire1();
	//PRINTF("\n");

	//PRINTF("Testing com_set_burn_wire2()\n");
	//com_set_burn_wire2();
	//PRINTF("\n");

	//PRINTF("Testing checkDeploy()\n");
	//com_i2c_checkDeploy();
	//PRINTF("\n");

#else
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time

    // Moved uart initialization up so both if/else statements can use
#endif

#if COM_ENABLE
		PRINTF("\ninitialize comm.\r\n");
		com_init();

		/***deploy antenna****/
		//TODO: should we make this whole sequence of deployment into a function?
		com_deployAntenna_algorithmOne(); //TODO: uncomment this line when incorporating the newer com wrapper
		//TODO: should we wait for 15 min and check if we need to try, if we do vTaskDelay, then we were able to switch to other tasks in the meantime
	//	i2c_com_antennaDeployed = com_i2c_checkDeploy(); //it might be easier to just update the global flag in the checkDeploy //TODO: uncomment this line when incorporating the newer com wrapper
		if (!i2c_com_antennaDeployed) {
			com_deployAntenna_algorithmTwo(); //TODO: uncomment this line when incorporating the newer com wrapper
		}
		//TODO: should we wait for 15 min and check if we need to try
		i2c_com_antennaDeployed = com_i2c_checkDeploy(); //TODO: uncomment this line when incorporating the newer com wrapper
		if (!i2c_com_antennaDeployed) {
			com_set_burn_wire1();
		}
		//TODO: should we wait for 15 min and check if we need to try, by vTaskDelay? or by delay() in com wrapper
	//	i2c_com_antennaDeployed = com_i2c_checkDeploy(); //TODO: uncomment this line when incorporating the newer com wrapper
		if (!i2c_com_antennaDeployed) {
			com_set_burn_wire2();
		}
		/****end of deployment of antenna****/
#endif

	for (;;) {
		//xLastWakeTime = xTaskGetTickCount();

#if COM_ENABLE
			com_getCommands(); //TODO: getCommands should raise the flag command_request if n>0 and decode what commands we have (raise those check flags for each type of data).
			if (command_request){
				//sending data based on priority
				if (payload_check) {
					com_sendPayloads();
				} else if (image_check) {
					PRINTF("resuming img task\r\n");
					vTaskResume(TaskHandler_img);
					com_sendImages();
				}
			}
			//always send beacons when COM is active
			//TODO: but it looks like xLastWakeTime is updated every for loop. That means the above process should take longer than 60 sec, if not, then we will never send beacons.
			if(xTaskGetTickCount() - xLastWakeTime >= 60*1000){ //check if 60 secs have passed
				com_sendBeacons();
			}
			vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
		//vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
