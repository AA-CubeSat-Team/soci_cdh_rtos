/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_41.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rt_sys_MEKF_lib_41.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S188>/Negative Trace'
 *    '<S338>/Negative Trace'
 */
void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4])
{
  real_T rtb_Product_om;
  real_T rtb_Switch_f_idx_0;

  /* If: '<S189>/Find Maximum Diagonal Value' */
  if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
    /* Outputs for IfAction SubSystem: '<S189>/Maximum Value at DCM(2,2)' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    /* Sqrt: '<S194>/sqrt' incorporates:
     *  Constant: '<S206>/Constant'
     *  Sum: '<S206>/Add'
     */
    rtb_Product_om = sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) + 1.0);

    /* Gain: '<S194>/Gain' */
    rty_qwqxqyqz[2] = 0.5 * rtb_Product_om;

    /* Switch: '<S205>/Switch' incorporates:
     *  Constant: '<S205>/Constant1'
     */
    if (rtb_Product_om != 0.0) {
      rtb_Switch_f_idx_0 = 0.5;
    } else {
      rtb_Switch_f_idx_0 = 0.0;
      rtb_Product_om = 1.0;
    }

    /* End of Switch: '<S205>/Switch' */

    /* Product: '<S205>/Product' */
    rtb_Product_om = rtb_Switch_f_idx_0 / rtb_Product_om;

    /* Gain: '<S194>/Gain1' incorporates:
     *  Product: '<S194>/Product'
     *  Sum: '<S204>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_om;

    /* Gain: '<S194>/Gain3' incorporates:
     *  Product: '<S194>/Product'
     *  Sum: '<S203>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_om;

    /* Gain: '<S194>/Gain4' incorporates:
     *  Product: '<S194>/Product'
     *  Sum: '<S202>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Product_om;

    /* End of Outputs for SubSystem: '<S189>/Maximum Value at DCM(2,2)' */
  } else if (rtu_DCM[8] > rtu_DCM[0]) {
    /* Outputs for IfAction SubSystem: '<S189>/Maximum Value at DCM(3,3)' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    /* Sqrt: '<S195>/sqrt' incorporates:
     *  Constant: '<S211>/Constant'
     *  Sum: '<S211>/Add'
     */
    rtb_Product_om = sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) + 1.0);

    /* Gain: '<S195>/Gain' */
    rty_qwqxqyqz[3] = 0.5 * rtb_Product_om;

    /* Switch: '<S210>/Switch' incorporates:
     *  Constant: '<S210>/Constant1'
     */
    if (rtb_Product_om != 0.0) {
      rtb_Switch_f_idx_0 = 0.5;
    } else {
      rtb_Switch_f_idx_0 = 0.0;
      rtb_Product_om = 1.0;
    }

    /* End of Switch: '<S210>/Switch' */

    /* Product: '<S210>/Product' */
    rtb_Product_om = rtb_Switch_f_idx_0 / rtb_Product_om;

    /* Gain: '<S195>/Gain1' incorporates:
     *  Product: '<S195>/Product'
     *  Sum: '<S207>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_om;

    /* Gain: '<S195>/Gain2' incorporates:
     *  Product: '<S195>/Product'
     *  Sum: '<S208>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_om;

    /* Gain: '<S195>/Gain3' incorporates:
     *  Product: '<S195>/Product'
     *  Sum: '<S209>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Product_om;

    /* End of Outputs for SubSystem: '<S189>/Maximum Value at DCM(3,3)' */
  } else {
    /* Outputs for IfAction SubSystem: '<S189>/Maximum Value at DCM(1,1)' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    /* Sqrt: '<S193>/sqrt' incorporates:
     *  Constant: '<S201>/Constant'
     *  Sum: '<S201>/Add'
     */
    rtb_Product_om = sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) + 1.0);

    /* Gain: '<S193>/Gain' */
    rty_qwqxqyqz[1] = 0.5 * rtb_Product_om;

    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S200>/Constant1'
     */
    if (rtb_Product_om != 0.0) {
      rtb_Switch_f_idx_0 = 0.5;
    } else {
      rtb_Switch_f_idx_0 = 0.0;
      rtb_Product_om = 1.0;
    }

    /* End of Switch: '<S200>/Switch' */

    /* Product: '<S200>/Product' */
    rtb_Product_om = rtb_Switch_f_idx_0 / rtb_Product_om;

    /* Gain: '<S193>/Gain1' incorporates:
     *  Product: '<S193>/Product'
     *  Sum: '<S199>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_om;

    /* Gain: '<S193>/Gain2' incorporates:
     *  Product: '<S193>/Product'
     *  Sum: '<S197>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_om;

    /* Gain: '<S193>/Gain3' incorporates:
     *  Product: '<S193>/Product'
     *  Sum: '<S198>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Product_om;

    /* End of Outputs for SubSystem: '<S189>/Maximum Value at DCM(1,1)' */
  }

  /* End of If: '<S189>/Find Maximum Diagonal Value' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
