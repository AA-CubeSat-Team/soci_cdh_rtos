#include <stdbool.h>
#include "com_wrap.h"
#include "com_task.h"
#include "clock_config.h"
#include "timers.h"

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;

TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;
extern bool i2c_com_antennaDeployed;

void com_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
#if COM_ENABLE
	PRINTF("\ninitialize comm.\r\n");
	com_init();

	/***deploy antenna****/
	//TODO: should we make this whole sequence of deployment into a function?
//	com_deployAntenna_algorithmOne(); //TODO: uncomment this line when incorporating the newer com wrapper
	//TODO: should we wait for 15 min and check if we need to try, if we do vTaskDelay, then we were able to switch to other tasks in the meantime
//	i2c_com_antennaDeployed = com_i2c_checkDeploy(); //it might be easier to just update the global flag in the checkDeploy //TODO: uncomment this line when incorporating the newer com wrapper
	if (!i2c_com_antennaDeployed) {
//		com_deployAntenna_algorithmTwo(); //TODO: uncomment this line when incorporating the newer com wrapper
	}
	//TODO: should we wait for 15 min and check if we need to try
//	i2c_com_antennaDeployed = com_i2c_checkDeploy(); //TODO: uncomment this line when incorporating the newer com wrapper
	if (!i2c_com_antennaDeployed) {
		com_set_burn_wire1();
	}
	//TODO: should we wait for 15 min and check if we need to try, by vTaskDelay? or by delay() in com wrapper
//	i2c_com_antennaDeployed = com_i2c_checkDeploy(); //TODO: uncomment this line when incorporating the newer com wrapper
	if (!i2c_com_antennaDeployed) {
		com_set_burn_wire2();
	}
	/****end of deployment of antenna****/

	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
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
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
#endif
}
