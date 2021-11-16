#include <stdbool.h>
#include <time.h>

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "com_wrap.h"
#include "com_task.h"
#include "clock_config.h"

#define CLOCKS_PER_SECOND 1000000

#include "timers.h"
#include "peripherals.h"

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;
bool com_wrap_debug = false; // Turn this true if you want to test individual functions

TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;
extern bool i2c_com_antennaDeployed;

char *send_message     = "12345678";
char *ring_overrun     = "\r\nRing buffer overrun!\r\n";
char *hardware_overrun = "\r\nHardware buffer overrun!\r\n";
uint8_t recv_buffer[8];

void com_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time

#if UART_TESTING
	int error;
	size_t n = 0;

	PRINTF("Send UART\n");

	/* Send introduction message. */
	if (kStatus_Success != LPUART_RTOS_Send(&uart4_handle, (uint8_t *)send_message, strlen(send_message)))
	{
		PRINTF("NOT SENT SUCCESFULLY\n");
		vTaskSuspend(NULL);
	}
	else{
		PRINTF("SENT SUCCESFULLY\n");
	}

	/* Receive user input and send it back to terminal. */
	do
	{
		PRINTF("TRYING TO RECEIVE ...\n");
		error = LPUART_RTOS_Receive(&uart4_handle, recv_buffer, sizeof(recv_buffer), &n);
		PRINTF("MADE IT PAST RECEIVE ...\n");
//		for(int i = 0; i < sizeof(recv_buffer); i++){
//			PRINTF("recv_buffer[i]: %d", recv_buffer[i]);
//		}
		if (error == kStatus_LPUART_RxHardwareOverrun)
		{
			PRINTF("HARDWARE BUFFER OVERRUN\n");
			/* Notify about hardware buffer overrun */
			if (kStatus_Success !=
				LPUART_RTOS_Send(&uart4_handle, (uint8_t *)hardware_overrun, strlen(hardware_overrun)))
			{
				vTaskSuspend(NULL);
			}
		}
		if (error == kStatus_LPUART_RxRingBufferOverrun)
		{
			PRINTF("RXRINGBUFFEROVERRUN\n");
			/* Notify about ring buffer overrun */
			if (kStatus_Success != LPUART_RTOS_Send(&uart4_handle, (uint8_t *)ring_overrun, strlen(ring_overrun)))
			{
				vTaskSuspend(NULL);
			}
		}
		if (n > 0)
		{
			PRINTF("RECEIVE SUCCESSFUL");
			for(int i = 0; i < n; i++){
				PRINTF("recv_buffer[i]: %d", recv_buffer[i]);
			}
			/* send back the received data */
			if (kStatus_Success != LPUART_RTOS_Send(&uart4_handle, recv_buffer, n))
			{
				vTaskSuspend(NULL);
			}
		}
	} while (kStatus_Success == error);

#endif

#if COM_WRAP_DEBUG
	// Delay to test "soft-break" into command mode via com_init function
	// delay(1);

	PRINTF("Testing enterCommandMode function:\n");
	com_enterCommandMode();
	PRINTF("\n");

	//Testing if sending a command to the radio (non delay dependent) works
	PRINTF("Testing exitCommandMode function:\n");
	com_exitCommandMode();
	PRINTF("\n");

	PRINTF("Testing test_data_mode function:\n");
	com_test_data_mode();
	PRINTF("\n");

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
	//PRINTF("\n");   // Moved uart initialization up so both if/else statements can use
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
		xLastWakeTime = xTaskGetTickCount();

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
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
