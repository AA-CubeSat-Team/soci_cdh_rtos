#include "peripherals.h"
#include "gyro_wrap.h"
#include "gnc_task.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "idle_task.h"
#include "sun_wrap.h"
#include "fsl_debug_console.h"
#include "com_protocol_helper.h"

// includes for GNC Build
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "FSW_Lib0.h"                  /* Model's header file */
#include "rtwtypes.h"

extern bool g_senActive, g_rwaActive, g_mtqActive;

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  FSW_Lib0_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  FSW_Lib0_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    __enable_irq();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      FSW_Lib0_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    __disable_irq();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested = false;

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();
	SPI_GPIO_init();

	/* Initialize model */
	FSW_Lib0_initialize();
#if GNC_ENABLE
	printf("\ninitialize gnc.\r\n");
	/* gnc, sens, act initialization */
//	sens_init();
//  act_init();
//	FSW_Lib_initialize(); //GNC initialization
#endif
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		rt_OneStep();
#if GNC_ENABLE
		xLastWakeTime = xTaskGetTickCount();
		printf("\nGNC TASK START.\r\n");

		getSunAngles(&Sun1);

		int a1 = (int) (Sun1.angles[0]*1000);
		int a2 = (int) (Sun1.angles[1]*1000);
		printf("\n");
		printf("a1: %d\n", a1);
		printf("a2: %d\n", a2);

		/* read sensors and actuator measurements to sensor_bus */
		if (g_senActive) {
//			sens_readSun();
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
//		 rt_OneStep(); // TODO: enable rt_OneStep() after include
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
