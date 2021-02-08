/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: nothing_lib.c
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

#include <gnc_build/Subsystem_ert_rtw/nothing_lib.h>
#include <gnc_build/Subsystem_ert_rtw/Subsystem.h>
#include <gnc_build/Subsystem_ert_rtw/Subsystem_private.h>

/* Output and update for atomic system: '<Root>/nothing_lib' */
real_T nothing_lib(real_T rtu_In1, real_T rtu_In2)
{
  /* Sum: '<S1>/Sum' */
  return rtu_In1 + rtu_In2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
