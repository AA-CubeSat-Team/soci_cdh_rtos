
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

#define CLOCKS_PER_SECOND 1000000


//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;
bool com_wrap_debug = false; // Turn this true if you want to test individual functions

extern TaskHandle_t TaskHandler_img;
extern bool g_comActive;
extern bool g_imgActive;

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

void com_task(void *pvParameters)
{
	/////////////////////////////////////////
	////// uart 1 initialization START //////
	/////////////////////////////////////////
	/*initiate UART 1*/
//    lpuart_config_t config;
//    uint16_t tmprxIndex = rxIndex_1;
//    uint16_t tmptxIndex = txIndex_1;
//
//    LPUART_GetDefaultConfig(&config);
//    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
//    config.enableTx     = true;
//    config.enableRx     = true;
//
//    LPUART_Init(LPUART_1, &config, LPUART1_CLK_FREQ);
//
//    /* Send g_tipString out. */
//    LPUART_WriteBlocking(LPUART_1, UART_1, sizeof(UART_1) / sizeof(UART_1[0]));
//
//    /* Enable RX interrupt. */
//    LPUART_EnableInterrupts(LPUART_1, kLPUART_RxDataRegFullInterruptEnable);
//    EnableIRQ(UART1_IRQn);

    /*UART 1 initialisation done */

	/////////////////////////////////////////
	////// uart 1 initialization END ////////
	/////////////////////////////////////////

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

	}
	else {
		const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
		PRINTF("\ninitialize comm.\r\n");
		com_init();
		com_set_burn_wire1();
		com_set_burn_wire2();
		int count = 0;
		for (;;) {
			TickType_t xLastWakeTime = xTaskGetTickCount();
			PRINTF("\ncomm work.\r\n");
			if(g_comActive == true){
	//			com_getCommands();
			}
			count++;
			PRINTF("count = %d\n", count);
			if (count >= 5){ //later: receive a command to take a pic
				vTaskResume(TaskHandler_img);
				count = 0;
				PRINTF("resuming img task\r\n");
			}

	//		if(g_comActive == true){
	//			//checking if getting a command request
	//			if (command_request){
	//				//sending data based on priority
	//				if (payload_check) {
	//					com_sendPayloads();
	//				} else if (image_check && g_imgActive) {
	//					com_sendImages();
	//				} else if(xTaskGetTickCount() - xLastWakeTime >= 60*1000){ //check if 60 secs have passed
	//					com_sendBeacons();
	//				}
	//			}
	//
	//		}
	//		else{
	//
	//		}

			vTaskDelayUntil(&xLastWakeTime, xDelayms);

		}
	}
}
