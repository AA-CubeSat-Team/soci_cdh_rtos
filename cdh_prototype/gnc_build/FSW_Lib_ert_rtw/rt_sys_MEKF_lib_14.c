/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_14.c
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

#include "rt_sys_MEKF_lib_14.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S83>/Negative Trace'
 *    '<S272>/Negative Trace'
 */
void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4])
{
  real_T rtb_sqrt_k;
  real_T rtb_Switch_bh_idx_0;
  real_T rtb_Switch_bh_idx_1;

  /* If: '<S84>/Find Maximum Diagonal Value' */
  if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
    /* Outputs for IfAction SubSystem: '<S84>/Maximum Value at DCM(2,2)' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* Sqrt: '<S89>/sqrt' incorporates:
     *  Constant: '<S101>/Constant'
     *  Sum: '<S101>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S100>/Switch' */

    /* Product: '<S100>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S89>/Gain1' incorporates:
     *  Product: '<S89>/Product'
     *  Sum: '<S99>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S89>/Gain3' incorporates:
     *  Product: '<S89>/Product'
     *  Sum: '<S98>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S89>/Gain4' incorporates:
     *  Product: '<S89>/Product'
     *  Sum: '<S97>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S89>/Gain' */
    rty_qwqxqyqz[2] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S84>/Maximum Value at DCM(2,2)' */
  } else if (rtu_DCM[8] > rtu_DCM[0]) {
    /* Outputs for IfAction SubSystem: '<S84>/Maximum Value at DCM(3,3)' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* Sqrt: '<S90>/sqrt' incorporates:
     *  Constant: '<S106>/Constant'
     *  Sum: '<S106>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) + 1.0);

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S105>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S105>/Switch' */

    /* Product: '<S105>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S90>/Gain1' incorporates:
     *  Product: '<S90>/Product'
     *  Sum: '<S102>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S90>/Gain2' incorporates:
     *  Product: '<S90>/Product'
     *  Sum: '<S103>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S90>/Gain3' incorporates:
     *  Product: '<S90>/Product'
     *  Sum: '<S104>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S90>/Gain' */
    rty_qwqxqyqz[3] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S84>/Maximum Value at DCM(3,3)' */
  } else {
    /* Outputs for IfAction SubSystem: '<S84>/Maximum Value at DCM(1,1)' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* Sqrt: '<S88>/sqrt' incorporates:
     *  Constant: '<S96>/Constant'
     *  Sum: '<S96>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S95>/Switch' incorporates:
     *  Constant: '<S95>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S95>/Switch' */

    /* Product: '<S95>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S88>/Gain1' incorporates:
     *  Product: '<S88>/Product'
     *  Sum: '<S94>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S88>/Gain2' incorporates:
     *  Product: '<S88>/Product'
     *  Sum: '<S92>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S88>/Gain3' incorporates:
     *  Product: '<S88>/Product'
     *  Sum: '<S93>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S88>/Gain' */
    rty_qwqxqyqz[1] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S84>/Maximum Value at DCM(1,1)' */
  }

  /* End of If: '<S84>/Find Maximum Diagonal Value' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
