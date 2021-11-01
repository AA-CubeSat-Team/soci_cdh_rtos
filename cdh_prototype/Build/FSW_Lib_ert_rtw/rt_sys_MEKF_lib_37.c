/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_37.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
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
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S188>/Positive Trace'
 *    '<S390>/Positive Trace'
 */
void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
                   *rty_qwqxqyqz, real_T rty_qwqxqyqz_i[3])
{
  real_T rtb_Gain1;

  /* Sqrt: '<S190>/sqrt' incorporates:
   *  Constant: '<S190>/Constant'
   *  Sum: '<S190>/Sum'
   */
  rtb_Gain1 = sqrt(rtu_traceDCM + 1.0);

  /* Gain: '<S190>/Gain' */
  *rty_qwqxqyqz = 0.5 * rtb_Gain1;

  /* Gain: '<S190>/Gain1' */
  rtb_Gain1 *= 2.0;

  /* Product: '<S190>/Product' incorporates:
   *  Sum: '<S212>/Add'
   *  Sum: '<S213>/Add'
   *  Sum: '<S214>/Add'
   */
  rty_qwqxqyqz_i[0] = (rtu_DCM[7] - rtu_DCM[5]) / rtb_Gain1;
  rty_qwqxqyqz_i[1] = (rtu_DCM[2] - rtu_DCM[6]) / rtb_Gain1;
  rty_qwqxqyqz_i[2] = (rtu_DCM[3] - rtu_DCM[1]) / rtb_Gain1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
