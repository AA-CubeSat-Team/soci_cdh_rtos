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
#include "FSW_Lib0.h"                  /* Model's header file */
#include "rtwtypes.h"
#include "zero_crossing_types.h"

extern bool g_senActive, g_rwaActive, g_mtqActive;

// TO DO: Double check if we need to disable interrupts and save FPU context
void rt_OneStep(void)
{
  static boolean_T OverrunFlags[2] = { 0, 0 };

  static boolean_T eventFlags[2] = { 0, 0 };/* Model has 2 rates */

  static int_T taskCounter[2] = { 0, 0 };

  /* Disable interrupts here */

  /* Check base rate for overrun */
  if (OverrunFlags[0]) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlags[0] = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  if (taskCounter[1] == 0) {
    if (eventFlags[1]) {
      OverrunFlags[0] = false;
      OverrunFlags[1] = true;

      /* Sampling too fast */
      rtmSetErrorStatus(rtM, "Overrun");
      return;
    }

    eventFlags[1] = true;
  }

  taskCounter[1]++;
  if (taskCounter[1] == 20) {
    taskCounter[1]= 0;
  }

  /* Set model inputs associated with base rate here */

  /* Step the model for base rate */
  FSW_Lib0_step0();

  /* Get model outputs here */

  /* Indicate task for base rate complete */
  OverrunFlags[0] = false;

  /* If task 1 is running, don't run any lower priority task */
  if (OverrunFlags[1]) {
    return;
  }

  /* Step the model for subrate */
  if (eventFlags[1]) {
    OverrunFlags[1] = true;

    /* Set model inputs associated with subrates here */

    /* Step the model for subrate 1 */
    FSW_Lib0_step1();

    /* Get model outputs here */

    /* Indicate task complete for subrate */
    OverrunFlags[1] = false;
    eventFlags[1] = false;
  }

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
#if GNC_ENABLE
	/* gnc, sens, act initialization */
//	sens_init();
//  act_init();
	/* Initialize model */
	FSW_Lib0_initialize();
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
