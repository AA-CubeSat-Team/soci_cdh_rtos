/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_1.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>
#include <gnc_build/FSW_Lib_ert_rtw/rt_sys_MEKF_lib_1.h>

/*
 * Output and update for action system:
 *    '<S66>/Positive Trace'
 *    '<S330>/Positive Trace'
 */
void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
                   *rty_qwqxqyqz, real_T rty_qwqxqyqz_e[3])
{
  real_T rtb_Gain1;

  /* Sqrt: '<S68>/sqrt' incorporates:
   *  Constant: '<S68>/Constant'
   *  Sum: '<S68>/Sum'
   */
  rtb_Gain1 = sqrt(rtu_traceDCM + 1.0);

  /* Gain: '<S68>/Gain' */
  *rty_qwqxqyqz = 0.5 * rtb_Gain1;

  /* Gain: '<S68>/Gain1' */
  rtb_Gain1 *= 2.0;

  /* Product: '<S68>/Product' incorporates:
   *  Sum: '<S90>/Add'
   *  Sum: '<S91>/Add'
   *  Sum: '<S92>/Add'
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
