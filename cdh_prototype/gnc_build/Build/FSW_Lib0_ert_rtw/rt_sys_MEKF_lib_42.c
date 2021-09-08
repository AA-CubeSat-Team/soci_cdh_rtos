/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_42.c
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

#include "rt_sys_MEKF_lib_42.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S173>/Negative Trace'
 *    '<S364>/Negative Trace'
 */
void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4])
{
  real_T rtb_sqrt_k;
  real_T rtb_Switch_bh_idx_0;
  real_T rtb_Switch_bh_idx_1;

  /* If: '<S174>/Find Maximum Diagonal Value' */
  if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
    /* Outputs for IfAction SubSystem: '<S174>/Maximum Value at DCM(2,2)' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* Sqrt: '<S179>/sqrt' incorporates:
     *  Constant: '<S191>/Constant'
     *  Sum: '<S191>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S190>/Switch' incorporates:
     *  Constant: '<S190>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S190>/Switch' */

    /* Product: '<S190>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S179>/Gain1' incorporates:
     *  Product: '<S179>/Product'
     *  Sum: '<S189>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S179>/Gain3' incorporates:
     *  Product: '<S179>/Product'
     *  Sum: '<S188>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S179>/Gain4' incorporates:
     *  Product: '<S179>/Product'
     *  Sum: '<S187>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S179>/Gain' */
    rty_qwqxqyqz[2] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S174>/Maximum Value at DCM(2,2)' */
  } else if (rtu_DCM[8] > rtu_DCM[0]) {
    /* Outputs for IfAction SubSystem: '<S174>/Maximum Value at DCM(3,3)' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Sqrt: '<S180>/sqrt' incorporates:
     *  Constant: '<S196>/Constant'
     *  Sum: '<S196>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) + 1.0);

    /* Switch: '<S195>/Switch' incorporates:
     *  Constant: '<S195>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S195>/Switch' */

    /* Product: '<S195>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S180>/Gain1' incorporates:
     *  Product: '<S180>/Product'
     *  Sum: '<S192>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S180>/Gain2' incorporates:
     *  Product: '<S180>/Product'
     *  Sum: '<S193>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S180>/Gain3' incorporates:
     *  Product: '<S180>/Product'
     *  Sum: '<S194>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S180>/Gain' */
    rty_qwqxqyqz[3] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S174>/Maximum Value at DCM(3,3)' */
  } else {
    /* Outputs for IfAction SubSystem: '<S174>/Maximum Value at DCM(1,1)' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Sqrt: '<S178>/sqrt' incorporates:
     *  Constant: '<S186>/Constant'
     *  Sum: '<S186>/Add'
     */
    rtb_sqrt_k = sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) + 1.0);

    /* Switch: '<S185>/Switch' incorporates:
     *  Constant: '<S185>/Constant1'
     */
    if (rtb_sqrt_k != 0.0) {
      rtb_Switch_bh_idx_0 = 0.5;
      rtb_Switch_bh_idx_1 = rtb_sqrt_k;
    } else {
      rtb_Switch_bh_idx_0 = 0.0;
      rtb_Switch_bh_idx_1 = 1.0;
    }

    /* End of Switch: '<S185>/Switch' */

    /* Product: '<S185>/Product' */
    rtb_Switch_bh_idx_0 /= rtb_Switch_bh_idx_1;

    /* Gain: '<S178>/Gain1' incorporates:
     *  Product: '<S178>/Product'
     *  Sum: '<S184>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S178>/Gain2' incorporates:
     *  Product: '<S178>/Product'
     *  Sum: '<S182>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S178>/Gain3' incorporates:
     *  Product: '<S178>/Product'
     *  Sum: '<S183>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Switch_bh_idx_0;

    /* Gain: '<S178>/Gain' */
    rty_qwqxqyqz[1] = 0.5 * rtb_sqrt_k;

    /* End of Outputs for SubSystem: '<S174>/Maximum Value at DCM(1,1)' */
  }

  /* End of If: '<S174>/Find Maximum Diagonal Value' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
