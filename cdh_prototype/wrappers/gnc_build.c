/* Jay Lee
 * 11/3/21
 * A helper function that initializes the GNC build and sets up the periodic interrupt timer
 * with rt_onestep()
 */
#include "gnc_build.h"
#include "fsl_pit.h"

//from ert_main.c
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "FSW_Lib0.h"                  /* Model's header file */
#include "rtwtypes.h"
#include "fsl_debug_console.h"

void PIT_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    /* Attach rt_OneStep to a timer or interrupt service routine with
	 * period 0.0125 seconds (the model's base sample time) here.  The
	 * call syntax for rt_OneStep is
	 */
    PRINTF("entered Interrupt\n");
    rt_OneStep();
    PRINTF("finished Interrupt\n");
    __DSB();
}

void gnc_build_init(void)
{
	/* Initialize model */
	FSW_Lib0_initialize();
	timer_init();
}

void timer_init(void)
{
    /* Structure of initialize PIT */
    pit_config_t pitConfig;

    /* Enable clock gate for GPIO1 */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    /* Set PERCLK_CLK source to OSC_CLK*/
    CLOCK_SetMux(kCLOCK_PerclkMux, 1U);
    /* Set PERCLK_CLK divider to 1 */
    CLOCK_SetDiv(kCLOCK_PerclkDiv, 0U);

    /*
     * pitConfig.enableRunInDebug = false;
     */
    PIT_GetDefaultConfig(&pitConfig);

    /* Init pit module */
    PIT_Init(PIT, &pitConfig);

    /* Set timer period for channel 0 */
    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(12500U, CLOCK_GetFreq(kCLOCK_OscClk)));

    /* Enable timer interrupts for channel 0 */
    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

    /* Enable at the NVIC */
    EnableIRQ(PIT_IRQn);

    /* Start channel 0 */
    PRINTF("\r\nStarting channel No.0 ...");
    PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void rt_OneStep(void)
{
  static boolean_T OverrunFlags[2] = { 0, 0 };

  static boolean_T eventFlags[2] = { 0, 0 };/* Model has 2 rates */

  static int_T taskCounter[2] = { 0, 0 };

  /* Disable interrupts here */
  PIT_DisableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

  /* Check base rate for overrun */
  if (OverrunFlags[0]) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlags[0] = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
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
  // not sure about this

  /* Step the model for base rate */
  FSW_Lib0_step0();

  /* Get model outputs here */
  // not sure about this

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
    // not sure about this

    /* Step the model for subrate 1 */
    FSW_Lib0_step1();

    /* Get model outputs here */
    // not sure about this

    /* Indicate task complete for subrate */
    OverrunFlags[1] = false;
    eventFlags[1] = false;
  }

  /* Disable interrupts here */
  PIT_DisableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
  PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
}
