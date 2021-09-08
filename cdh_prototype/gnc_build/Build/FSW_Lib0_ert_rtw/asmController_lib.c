/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: asmController_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
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
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Output and update for atomic system: '<S218>/asmController_lib' */
void asmController_lib(const real_T rtu_w_err_radps[3], real_T
  rty_torque_cmd_Nm[3])
{
  int32_T i;

  /* Product: '<S223>/Matrix Multiply' incorporates:
   *  Constant: '<S223>/Constant'
   */
  for (i = 0; i < 3; i++) {
    rty_torque_cmd_Nm[i] = 0.0;
    rty_torque_cmd_Nm[i] += rtCP_Constant_Value_c[i] * rtu_w_err_radps[0];
    rty_torque_cmd_Nm[i] += rtCP_Constant_Value_c[i + 3] * rtu_w_err_radps[1];
    rty_torque_cmd_Nm[i] += rtCP_Constant_Value_c[i + 6] * rtu_w_err_radps[2];
  }

  /* End of Product: '<S223>/Matrix Multiply' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
