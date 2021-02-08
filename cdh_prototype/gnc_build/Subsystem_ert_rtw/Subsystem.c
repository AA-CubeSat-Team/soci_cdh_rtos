/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May 10 16:24:08 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <gnc_build/Subsystem_ert_rtw/Subsystem.h>
#include <gnc_build/Subsystem_ert_rtw/Subsystem_private.h>

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Subsystem_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/nothing_lib' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  rtY.Out1 = nothing_lib(0.25 * rtU.In1, rtU.In2);

  /* End of Outputs for SubSystem: '<Root>/nothing_lib' */
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
