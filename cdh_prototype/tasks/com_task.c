
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include <stdbool.h>
#include <time.h>

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "com_wrap.h"
#include "com_task.h"
#include "clock_config.h"

/* PIT */
#include "fsl_pit.h"

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;
bool com_wrap_debug = false; // Turn this true if you want to test individual functions

TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;

#define COM_TASK_DEBUG 1

#if COM_TASK_DEBUG
bool g_comActive = false;
bool g_imgActive = false;

#else
extern bool g_comActive;
extern bool g_imgActive;
#endif

/* Macros and Global Variable for PIT Timer */
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_OscClk) // TO DO: check if the OSC won't turn of during low power mode
#define DAY_COUNT 5 // (24 * 60)
uint16_t minute_count;

////////////////////////////////////////// Testing interrupt handling
/*UART 1
  Ring buffer for data input and output, input data are saved
  to ring buffer in IRQ handler. The main function polls the ring buffer status,
  if there is new data, then send them out.
  Ring buffer full: (((rxIndex + 1) % DEMO_RING_BUFFER_SIZE) == txIndex)
  Ring buffer empty: (rxIndex == txIndex)
*/
uint8_t UART1RingBuffer[UART1_RING_BUFFER_SIZE];
volatile uint16_t txIndex_1; /* Index of the data to send out. */
volatile uint16_t rxIndex_1; /* Index of the memory to save new arrived data. */
uint8_t UART_1[] =
    "UART 1 initialised \r\n";

/////////////////////////////////////////////////////////////////////
///// Example message queues code (functions not used yet) START ////
////////////////////////////////////////////////////////////////////
/* Define a variable of type struct AMMessage.  The examples below demonstrate
how to pass the whole variable through the queue, and as the structure is
moderately large, also how to pass a reference to the variable through a queue. */
struct AMessage
{
   char ucMessageID;
   char ucData[ 20 ];
} xMessage;

/* Queue used to send and receive complete struct AMessage structures. */
QueueHandle_t xStructQueue = NULL;

/* Queue used to send and receive pointers to struct AMessage structures. */
QueueHandle_t xPointerQueue = NULL;


// command and telemetry data struct, used to share between subsystem, need to move to global struct after prototype
typedef struct {
	uint8_t megID;
	uint8_t meg[8];
} TIL_Prototype;

typedef struct {
	bool new_cmd;
	uint8_t cmdID;
	uint8_t cmd[8];
} CMD_Prototype;

void vCreateQueues( void )
{
   xMessage.ucMessageID = 0xab;
   memset( &( xMessage.ucData ), 0x12, 20 );

   /* Create the queue used to send complete struct AMessage structures.  This can
   also be created after the schedule starts, but care must be task to ensure
   nothing uses the queue until after it has been created. */
   xStructQueue = xQueueCreate(
                         /* The number of items the queue can hold. */
                         10,
                         /* Size of each item is big enough to hold the
                         whole structure. */
                         sizeof( xMessage ));

   /* Create the queue used to send pointers to struct AMessage structures. */
   xPointerQueue = xQueueCreate(
                         /* The number of items the queue can hold. */
                         10,
                         /* Size of each item is big enough to hold only a
                         pointer. */
                         sizeof( &xMessage ));

   if( ( xStructQueue == NULL ) || ( xPointerQueue == NULL ) )
   {
      /* One or more queues were not created successfully as there was not enough
      heap memory available.  Handle the error here.  Queues can also be created
      statically. */
	   PRINTF("Error creating one of the queues!");
   }
}

/* Task that writes to the queues. */
void vATask( void *pvParameters )
{
struct AMessage *pxPointerToxMessage;

   /* Send the entire structure to the queue created to hold 10 structures. */
   xQueueSend( /* The handle of the queue. */
               xStructQueue,
               /* The address of the xMessage variable.  sizeof( struct AMessage )
               bytes are copied from here into the queue. */
               ( void * ) &xMessage,
               /* Block time of 0 says don't block if the queue is already full.
               Check the value returned by xQueueSend() to know if the message
               was sent to the queue successfully. */
               ( TickType_t ) 0 );

   /* Store the address of the xMessage variable in a pointer variable. */
   pxPointerToxMessage = &xMessage;

   /* Send the address of xMessage to the queue created to hold 10    pointers. */
   xQueueSend( /* The handle of the queue. */
               xPointerQueue,
               /* The address of the variable that holds the address of xMessage.
               sizeof( &xMessage ) bytes are copied from here into the queue. As the
               variable holds the address of xMessage it is the address of xMessage
               that is copied into the queue. */
               ( void * ) &pxPointerToxMessage,
               ( TickType_t ) 0 );

   /* ... Rest of task code goes here. */
}

/* Task that reads from the queues. */
void vADifferentTask( void *pvParameters )
{
struct AMessage xRxedStructure, *pxRxedPointer;

   if( xStructQueue != NULL )
   {
      /* Receive a message from the created queue to hold complex struct AMessage
      structure.  Block for 10 ticks if a message is not immediately available.
      The value is read into a struct AMessage variable, so after calling
      xQueueReceive() xRxedStructure will hold a copy of xMessage. */
      if( xQueueReceive( xStructQueue,
                         &( xRxedStructure ),
                         ( TickType_t ) 10 ) == pdPASS )
      {
         /* xRxedStructure now contains a copy of xMessage. */
      }
   }

   if( xPointerQueue != NULL )
   {
      /* Receive a message from the created queue to hold pointers.  Block for 10
      ticks if a message is not immediately available.  The value is read into a
      pointer variable, and as the value received is the address of the xMessage
      variable, after this call pxRxedPointer will point to xMessage. */
      if( xQueueReceive( xPointerQueue,
                         &( pxRxedPointer ),
                         ( TickType_t ) 10 ) == pdPASS )
      {
         /* *pxRxedPointer now points to xMessage. */
      }
   }

   /* ... Rest of task code goes here. */
}

///////////////////////////////////////////////////////////////////
///// Example message queues code (functions not used yet) END ////
//////////////////////////////////////////////////////////////////

void UART1_IRQHandler(void)
{
    uint8_t data;
    uint16_t tmprxIndex = rxIndex_1;
    uint16_t tmptxIndex = txIndex_1;

    /* If new data arrived. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART_1))
    {
        data = LPUART_ReadByte(LPUART_1);

        /* If ring buffer is not full, add data to ring buffer. */
        if (((tmprxIndex + 1) % UART1_RING_BUFFER_SIZE) != tmptxIndex)
        {
        	UART1RingBuffer[rxIndex_1] = data;
            rxIndex_1++;
            rxIndex_1 %= UART1_RING_BUFFER_SIZE;
        }
    }
    SDK_ISR_EXIT_BARRIER;
}
/////////////////////////////////////////



/*
 * States for COM_task
 * INIT: initialization of the GPIO and radio, stay in this state until satellite is in orbit
 * NORMAL: send health beacon every 60s, health check
 * PASSING: while passing, start uplinking and downlinking.
 *
 */
//enum com_state{INIT, NORMAL, PASSING};
typedef enum {
	INIT, NORMAL, PASSING
} com_state;
com_state comCurrentState = INIT;

bool GNC_DetumbleFlag = false; //TODO: verify with GNC
bool GNC_PassingFlag = false; //TODO: verify with GNC

// Sends Beacon Message every minute and Healthcheck message everyday
//TODO: integrate wrapper function to beacon message once COM wrapper is finished
void PIT_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    PRINTF("Beacon Message\r\n"); // TODO: not send if critically low power
    //com_sendBeacons();
    minute_count++;
    if(minute_count == DAY_COUNT) {
    	minute_count = 0;
#if !COM_TASK_DEBUG
    	if(!com_healthcheck()) {
			PRINTF("Health check failed, resetting radio\n");
			//com_radio_init();
			//TODO: double check resetting radio won't cause antenna to disconnect/un-deploy
    	}
#endif
    	PRINTF("healthcheck!\r\n");
    }
    __DSB();
}

void initialization_PIT()
{
    pit_config_t pitConfig; // Structure of initialize PIT
	minute_count = 0;
	/*
	 * pitConfig.enableRunInDebug = false;
	 */
	PIT_GetDefaultConfig(&pitConfig);

	/* Init pit module */
	PIT_Init(PIT, &pitConfig);

	/* Set timer period for channel 0 */
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000U, PIT_SOURCE_CLOCK));

	/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

	/* Enable at the NVIC */
	EnableIRQ(PIT_IRQn);

	/* Start channel 0 */
	PRINTF("\r\nStarting channel No.0 ...");
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void com_task(void *pvParameters)
{
	// Creating TIL and CMD message struct and test using one megId and one message
	// struct should be global and can be accessed by other subsystem
	volatile TIL_Prototype til_struct;
	volatile CMD_Prototype cmd_struct;

	// TODO: will ignore this warning for now, may need to implement loop to initilize the array.
	// https://stackoverflow.com/questions/17144570/how-to-set-volatile-array-to-zero-using-memset
	til_struct.megID = 0x00;
	memset( &( til_struct.meg ), 0x00, 8);

	cmd_struct.new_cmd = false;
	cmd_struct.cmdID = 0x01;
	memset( &( cmd_struct.cmd ), 0x01, 8);

	if(com_wrap_debug){
		// Delay to test "soft-break" into command mode via com_init function
//		delay(1);
//
		//PRINTF("Testing enterCommandMode function:\n");
		//com_enterCommandMode();
		//PRINTF("\n");

		// Testing if sending a command to the radio (non delay dependent) works
		//PRINTF("Testing exitCommandMode function:\n");;
		//com_exitCommandMode();
		//PRINTF("\n");

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

		PRINTF("Testing com_set_burn_wire2()\n");
		com_i2c_checkDeploy();
		PRINTF("\n");

	} else {
		initialization_PIT();
		comCurrentState = INIT;

		while(1) {
			TickType_t xLastWakeTime = xTaskGetTickCount();
			const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms

//			int count = 0;
//			if (true == GNC_DetumbleFlag) {
//				comCurrentState = NORMAL;
//			}
//			if (true == GNC_PassingFlag) {
//				comCurrentState = PASSING;
//			}

			switch (comCurrentState){
				case INIT:
					PRINTF("\ninitialize comm.\r\n");
					//com_init();
					//com_set_burn_wire1();
					//com_set_burn_wire2();


					PRINTF("Waiting to detumble\n");
#if COM_TASK_DEBUG
					vTaskDelay(pdMS_TO_TICKS( 1000 )); // TODO wait for detumble, 15min
#else
					vTaskDelay(pdMS_TO_TICKS( 15*60*1000 )); // TODO wait for detumble, 15min
#endif
					PRINTF("Detumble time limit hit\n");


					// Deploy Antenna
					//com_deployAntenna(); //TODO: remove
					//com_i2c_checkDeploy();
					bool AntennaCheck = true;
					if (AntennaCheck) {
						PRINTF("Sucessfully deployed antenna\n");
					}
					comCurrentState = NORMAL;
					break;

				case NORMAL:

					PRINTF("Waiting for commands\r\n");
					// Note: user uart recieve right here to test, consider modifying the wrapper later
					//cmd_struct.new_cmd = com_getCommands(cmd_struct.cmd); //TODO: getCommands should raise the flag command_request if n>0 and decode what commands we have (raise those check flags for each type of data).
					// TO DO: figure out different types of command

//					// taken from the com_getCommands()
//					int n = 0;
//					uint8_t buffer[8] = {0}; // TODO: copy from buffer to struct?
//					status_t error = LPUART_RTOS_Receive(&uart1_handle, cmd_struct.cmd, sizeof(cmd_struct.cmd), &n);
//					if (error == kStatus_LPUART_RxHardwareOverrun)
//					{
//						PRINTF("hardware overrun!!!\r\n\r\n");
//						return;
//					}
//					if (error == kStatus_LPUART_RxRingBufferOverrun)
//					{
//						PRINTF("ring buffer overrun!!!\r\n\r\n");
//						return;
//					}
//					if (n > 0)
//					{
//						/* send back the received data */
//						if (kStatus_Success != LPUART_RTOS_Send(&uart1_handle, cmd_struct.cmd, n))
//						{
//							vTaskSuspend(NULL);
//						}
//					}

					if (cmd_struct.new_cmd) {
						comCurrentState = PASSING;
						cmd_struct.new_cmd = false;
					} else {
						vTaskDelayUntil(&xLastWakeTime, xDelayms);
					}
					break;

				case PASSING:
					// TODO: send beacon
					// TODO: listen for response


					//sending data based on priority
					if (payload_check) {
						//com_sendPayloads(); // TO DO: how to send payload with Global Structs
					} else if (image_check) {
						PRINTF("resuming img task\r\n");
						//vTaskResume(TaskHandler_img);
						//com_sendImages();
					}


					comCurrentState = NORMAL;
					break;
			} // TO DO: add default state

		}
	}
}
