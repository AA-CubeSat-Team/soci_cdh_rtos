/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Oct 28 23:55:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FSW_Lib0.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function for TID0 */
void FSW_Lib0_step0(void)              /* Sample time: [0.0125s, 0.0s] */
{
  int32_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0125s, 0.0s] to Sample time: [0.25s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 19) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition6' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    for (i = 0; i < 5; i++) {
      rtDW.RateTransition6[i] = 0.01;
    }

    /* RateTransition: '<S1>/Rate Transition7' */
    rtDW.RateTransition7[0] = 1000.0;
    rtDW.RateTransition7[1] = -1000.0;
    rtDW.RateTransition7[2] = 1000.0;
    rtDW.RateTransition7[3] = -1000.0;
  }

  /* End of RateTransition: '<S1>/Rate Transition6' */
}

/* Model step function for TID1 */
void FSW_Lib0_step1(void)              /* Sample time: [0.25s, 0.0s] */
{
  int32_T i;

  /* Outport: '<Root>/fsw_out' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_fsw_out_at_inport_0'
   */
  rtY.fsw_out_j.rwa_cmd_rpm[0] = rtDW.RateTransition7[0];
  rtY.fsw_out_j.rwa_cmd_rpm[1] = rtDW.RateTransition7[1];
  rtY.fsw_out_j.rwa_cmd_rpm[2] = rtDW.RateTransition7[2];
  rtY.fsw_out_j.rwa_cmd_rpm[3] = rtDW.RateTransition7[3];
  for (i = 0; i < 5; i++) {
    rtY.fsw_out_j.mtq_cmd_Am2[i] = rtDW.RateTransition6[i];
  }

  /* End of Outport: '<Root>/fsw_out' */
}

/* Model initialize function */
void FSW_Lib0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
