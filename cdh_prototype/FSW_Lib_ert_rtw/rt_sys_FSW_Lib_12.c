/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_FSW_Lib_12.c
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

#include "rt_sys_FSW_Lib_12.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S47>/Positive Trace'
 *    '<S162>/Positive Trace'
 */
void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
                   *rty_qwqxqyqz, real_T rty_qwqxqyqz_e[3])
{
  real_T rtb_Gain1_b;

  /* Sqrt: '<S49>/sqrt' incorporates:
   *  Constant: '<S49>/Constant'
   *  Sum: '<S49>/Sum'
   */
  rtb_Gain1_b = sqrt(rtu_traceDCM + 1.0);

  /* Gain: '<S49>/Gain' */
  *rty_qwqxqyqz = 0.5 * rtb_Gain1_b;

  /* Gain: '<S49>/Gain1' */
  rtb_Gain1_b *= 2.0;

  /* Product: '<S49>/Product' incorporates:
   *  Sum: '<S71>/Add'
   *  Sum: '<S72>/Add'
   *  Sum: '<S73>/Add'
   */
  rty_qwqxqyqz_e[0] = (rtu_DCM[7] - rtu_DCM[5]) / rtb_Gain1_b;
  rty_qwqxqyqz_e[1] = (rtu_DCM[2] - rtu_DCM[6]) / rtb_Gain1_b;
  rty_qwqxqyqz_e[2] = (rtu_DCM[3] - rtu_DCM[1]) / rtb_Gain1_b;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
