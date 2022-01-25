// Name: Jay Lee
// Notes: simple GNC build integrated
// TO-DO list: Make sure GNC task runs every 250 ms

#include "peripherals.h"
#include "gyro_wrap.h"
#include "gnc_task.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "idle_task.h"
#include "sun_wrap.h"
#include "fsl_debug_console.h"
#include "com_protocol_helper.h"

//GNC BUILD include
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "FSW_0123.h"                  /* Model's header file */
#include "rtwtypes.h"

extern bool g_senActive, g_rwaActive, g_mtqActive;

void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  FSW_0123_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 250 ); //delay 250 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();
	PRINTF("initialize gnc.\r\n");
	SPI_GPIO_init();
	FSW_0123_initialize();
#if GNC_ENABLE
	/* gnc, sens, act initialization */
//	sens_init();
//  act_init();
	/* Initialize model */
	FSW_0123_initialize();
#endif
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		PRINTF("GNC task loop\r\n");
		rt_OneStep();
#if GNC_ENABLE
		xLastWakeTime = xTaskGetTickCount();
		printf("\nGNC TASK START.\r\n");

		/* read sensors and actuator measurements to sensor_bus */
		if (g_senActive) {
//			sens_readSun(); //getSunAngles(&Sun1);
//			sens_readMag();
//			sens_readPhd();
//			sens_readGyr();
		}
		if (g_rwaActive) {
//			readRWA();
		}
		if (g_mtqActive) {
//			readMTQ();
		}

		/* call GNC rt_OneStep() */
		 rt_OneStep();
		/* write to actuators */
		if (g_rwaActive) {
//			writeRWA();
		}
		if (g_mtqActive) {
//			writeMTQ();
		}
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
