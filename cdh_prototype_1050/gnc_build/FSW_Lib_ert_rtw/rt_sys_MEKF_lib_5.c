/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_5.c
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
#include <gnc_build/FSW_Lib_ert_rtw/rt_sys_MEKF_lib_5.h>

/*
 * Output and update for action system:
 *    '<S66>/Negative Trace'
 *    '<S330>/Negative Trace'
 */
void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4])
{
  real_T rtb_sqrt_k;
  real_T rtb_Switch_b_idx_0;
  real_T rtb_Switch_b_idx_1;

  /* If: '<S67>/Find Maximum Diagonal Value' */
  if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
    /* Outputs for IfAction SubSystem: '<S67>/Maximum Value at DCM(2,2)' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    /* Sqrt: '<S72>/sqrt' incorporates:
     *  Constant: '<S84>/Constant'
     *  Sum: '<S84>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_b_idx_0 = 0.5;
      rtb_Switch_b_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_b_idx_0 = 0.0;
      rtb_Switch_b_idx_1 = 1.0;
    }

    /* End of Switch: '<S83>/Switch' */

    /* Product: '<S83>/Product' */
    rtb_Switch_b_idx_0 /= rtb_Switch_b_idx_1;

    /* Gain: '<S72>/Gain1' incorporates:
     *  Product: '<S72>/Product'
     *  Sum: '<S82>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_b_idx_0;

    /* Gain: '<S72>/Gain3' incorporates:
     *  Product: '<S72>/Product'
     *  Sum: '<S81>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_b_idx_0;

    /* Gain: '<S72>/Gain4' incorporates:
     *  Product: '<S72>/Product'
     *  Sum: '<S80>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Switch_b_idx_0;

    /* Gain: '<S72>/Gain' */
    rty_qwqxqyqz[2] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S67>/Maximum Value at DCM(2,2)' */
  } else if (rtu_DCM[8] > rtu_DCM[0]) {
    /* Outputs for IfAction SubSystem: '<S67>/Maximum Value at DCM(3,3)' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Sqrt: '<S73>/sqrt' incorporates:
     *  Constant: '<S89>/Constant'
     *  Sum: '<S89>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) + 1.0);

    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S88>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_b_idx_0 = 0.5;
      rtb_Switch_b_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_b_idx_0 = 0.0;
      rtb_Switch_b_idx_1 = 1.0;
    }

    /* End of Switch: '<S88>/Switch' */

    /* Product: '<S88>/Product' */
    rtb_Switch_b_idx_0 /= rtb_Switch_b_idx_1;

    /* Gain: '<S73>/Gain1' incorporates:
     *  Product: '<S73>/Product'
     *  Sum: '<S85>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_b_idx_0;

    /* Gain: '<S73>/Gain2' incorporates:
     *  Product: '<S73>/Product'
     *  Sum: '<S86>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_b_idx_0;

    /* Gain: '<S73>/Gain3' incorporates:
     *  Product: '<S73>/Product'
     *  Sum: '<S87>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Switch_b_idx_0;

    /* Gain: '<S73>/Gain' */
    rty_qwqxqyqz[3] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S67>/Maximum Value at DCM(3,3)' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/Maximum Value at DCM(1,1)' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    /* Sqrt: '<S71>/sqrt' incorporates:
     *  Constant: '<S79>/Constant'
     *  Sum: '<S79>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_b_idx_0 = 0.5;
      rtb_Switch_b_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_b_idx_0 = 0.0;
      rtb_Switch_b_idx_1 = 1.0;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Product: '<S78>/Product' */
    rtb_Switch_b_idx_0 /= rtb_Switch_b_idx_1;

    /* Gain: '<S71>/Gain1' incorporates:
     *  Product: '<S71>/Product'
     *  Sum: '<S77>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_b_idx_0;

    /* Gain: '<S71>/Gain2' incorporates:
     *  Product: '<S71>/Product'
     *  Sum: '<S75>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_b_idx_0;

    /* Gain: '<S71>/Gain3' incorporates:
     *  Product: '<S71>/Product'
     *  Sum: '<S76>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Switch_b_idx_0;

    /* Gain: '<S71>/Gain' */
    rty_qwqxqyqz[1] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S67>/Maximum Value at DCM(1,1)' */
  }

  /* End of If: '<S67>/Find Maximum Diagonal Value' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
