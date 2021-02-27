/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_10.c
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

#include "rt_sys_MEKF_lib_10.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S83>/Positive Trace'
 *    '<S272>/Positive Trace'
 */
void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
                   *rty_qwqxqyqz, real_T rty_qwqxqyqz_e[3])
{
  real_T rtb_Gain1;

  /* Sqrt: '<S85>/sqrt' incorporates:
   *  Constant: '<S85>/Constant'
   *  Sum: '<S85>/Sum'
   */
  rtb_Gain1 = sqrt(rtu_traceDCM + 1.0);

  /* Gain: '<S85>/Gain' */
  *rty_qwqxqyqz = 0.5 * rtb_Gain1;

  /* Gain: '<S85>/Gain1' */
  rtb_Gain1 *= 2.0;

  /* Product: '<S85>/Product' incorporates:
   *  Sum: '<S107>/Add'
   *  Sum: '<S108>/Add'
   *  Sum: '<S109>/Add'
   */
  rty_qwqxqyqz_e[0] = (rtu_DCM[7] - rtu_DCM[5]) / rtb_Gain1;
  rty_qwqxqyqz_e[1] = (rtu_DCM[2] - rtu_DCM[6]) / rtb_Gain1;
  rty_qwqxqyqz_e[2] = (rtu_DCM[3] - rtu_DCM[1]) / rtb_Gain1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
