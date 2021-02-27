/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: asmController_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "asmController_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S128>/asmController_lib' */
void asmController_lib(void)
{
  int32_T i;

  /* Product: '<S133>/Matrix Multiply' incorporates:
   *  Constant: '<S133>/Constant'
   */
  for (i = 0; i < 3; i++) {
    rtDW.Merge[i] = 0.0;
    rtDW.Merge[i] += rtCP_Constant_Value_c[i] * rtDW.w_err_radps[0];
    rtDW.Merge[i] += rtCP_Constant_Value_c[i + 3] * rtDW.w_err_radps[1];
    rtDW.Merge[i] += rtCP_Constant_Value_c[i + 6] * rtDW.w_err_radps[2];
  }

  /* End of Product: '<S133>/Matrix Multiply' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
