/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: asmController_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "asmController_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S93>/asmController_lib' */
void asmController_lib(const real_T rtu_w_err_radps[3], real_T
  rty_torque_cmd_Nm[3])
{
  int32_T i;

  /* Product: '<S98>/Matrix Multiply' incorporates:
   *  Constant: '<S98>/Constant'
   */
  for (i = 0; i < 3; i++) {
    rty_torque_cmd_Nm[i] = 0.0;
    rty_torque_cmd_Nm[i] += rtConstP.Constant_Value_a[i] * rtu_w_err_radps[0];
    rty_torque_cmd_Nm[i] += rtConstP.Constant_Value_a[i + 3] * rtu_w_err_radps[1];
    rty_torque_cmd_Nm[i] += rtConstP.Constant_Value_a[i + 6] * rtu_w_err_radps[2];
  }

  /* End of Product: '<S98>/Matrix Multiply' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
