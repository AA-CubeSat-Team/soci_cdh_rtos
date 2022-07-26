/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PD_Controller_Lib.c
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

#include "PD_Controller_Lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S94>/PD_Controller_Lib'
 *    '<S96>/PD_Controller_Lib'
 */
void PD_Controller_Lib(const real_T rtu_quat_err[4], const real_T
  rtu_w_err_radps[3], real_T rty_cmd_Nm[3])
{
  /* Sum: '<S106>/Sum' incorporates:
   *  Gain: '<S106>/Kp'
   *  Gain: '<S106>/kd'
   */
  rty_cmd_Nm[0] = 0.0022784130629625535 * rtu_quat_err[1] - 0.010379269447506475
    * rtu_w_err_radps[0];
  rty_cmd_Nm[1] = 0.0022428910187985854 * rtu_quat_err[2] - 0.010217449418602387
    * rtu_w_err_radps[1];
  rty_cmd_Nm[2] = 0.001163157994406938 * rtu_quat_err[3] - 0.00529874517936314 *
    rtu_w_err_radps[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
