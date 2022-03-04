/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_37.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rt_sys_MEKF_lib_37.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S187>/Positive Trace'
 *    '<S295>/Positive Trace'
 */
void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
                   *rty_qwqxqyqz, real_T rty_qwqxqyqz_d[3])
{
  real_T rtb_Gain1;

  /* Sqrt: '<S189>/sqrt' incorporates:
   *  Constant: '<S189>/Constant'
   *  Sum: '<S189>/Sum'
   */
  rtb_Gain1 = sqrt(rtu_traceDCM + 1.0);

  /* Gain: '<S189>/Gain' */
  *rty_qwqxqyqz = 0.5 * rtb_Gain1;

  /* Gain: '<S189>/Gain1' */
  rtb_Gain1 *= 2.0;

  /* Product: '<S189>/Product' incorporates:
   *  Sum: '<S211>/Add'
   *  Sum: '<S212>/Add'
   *  Sum: '<S213>/Add'
   */
  rty_qwqxqyqz_d[0] = (rtu_DCM[7] - rtu_DCM[5]) / rtb_Gain1;
  rty_qwqxqyqz_d[1] = (rtu_DCM[2] - rtu_DCM[6]) / rtb_Gain1;
  rty_qwqxqyqz_d[2] = (rtu_DCM[3] - rtu_DCM[1]) / rtb_Gain1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
