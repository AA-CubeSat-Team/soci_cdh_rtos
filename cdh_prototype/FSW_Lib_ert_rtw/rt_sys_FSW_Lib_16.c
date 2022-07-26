/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_FSW_Lib_16.c
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

#include "rt_sys_FSW_Lib_16.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S47>/Negative Trace'
 *    '<S162>/Negative Trace'
 */
void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4])
{
  real_T rtb_Product_en;
  real_T rtb_Switch_a_idx_0;

  /* If: '<S48>/Find Maximum Diagonal Value' */
  if ((rtu_DCM[4] > rtu_DCM[0]) && (rtu_DCM[4] > rtu_DCM[8])) {
    /* Outputs for IfAction SubSystem: '<S48>/Maximum Value at DCM(2,2)' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* Sqrt: '<S53>/sqrt' incorporates:
     *  Constant: '<S65>/Constant'
     *  Sum: '<S65>/Add'
     */
    rtb_Product_en = sqrt(((rtu_DCM[4] - rtu_DCM[0]) - rtu_DCM[8]) + 1.0);

    /* Gain: '<S53>/Gain' */
    rty_qwqxqyqz[2] = 0.5 * rtb_Product_en;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    if (rtb_Product_en != 0.0) {
      rtb_Switch_a_idx_0 = 0.5;
    } else {
      rtb_Switch_a_idx_0 = 0.0;
      rtb_Product_en = 1.0;
    }

    /* End of Switch: '<S64>/Switch' */

    /* Product: '<S64>/Product' */
    rtb_Product_en = rtb_Switch_a_idx_0 / rtb_Product_en;

    /* Gain: '<S53>/Gain1' incorporates:
     *  Product: '<S53>/Product'
     *  Sum: '<S63>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_en;

    /* Gain: '<S53>/Gain3' incorporates:
     *  Product: '<S53>/Product'
     *  Sum: '<S62>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_en;

    /* Gain: '<S53>/Gain4' incorporates:
     *  Product: '<S53>/Product'
     *  Sum: '<S61>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[2] - rtu_DCM[6]) * rtb_Product_en;

    /* End of Outputs for SubSystem: '<S48>/Maximum Value at DCM(2,2)' */
  } else if (rtu_DCM[8] > rtu_DCM[0]) {
    /* Outputs for IfAction SubSystem: '<S48>/Maximum Value at DCM(3,3)' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* Sqrt: '<S54>/sqrt' incorporates:
     *  Constant: '<S70>/Constant'
     *  Sum: '<S70>/Add'
     */
    rtb_Product_en = sqrt(((rtu_DCM[8] - rtu_DCM[0]) - rtu_DCM[4]) + 1.0);

    /* Gain: '<S54>/Gain' */
    rty_qwqxqyqz[3] = 0.5 * rtb_Product_en;

    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S69>/Constant1'
     */
    if (rtb_Product_en != 0.0) {
      rtb_Switch_a_idx_0 = 0.5;
    } else {
      rtb_Switch_a_idx_0 = 0.0;
      rtb_Product_en = 1.0;
    }

    /* End of Switch: '<S69>/Switch' */

    /* Product: '<S69>/Product' */
    rtb_Product_en = rtb_Switch_a_idx_0 / rtb_Product_en;

    /* Gain: '<S54>/Gain1' incorporates:
     *  Product: '<S54>/Product'
     *  Sum: '<S66>/Add'
     */
    rty_qwqxqyqz[1] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_en;

    /* Gain: '<S54>/Gain2' incorporates:
     *  Product: '<S54>/Product'
     *  Sum: '<S67>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[5] + rtu_DCM[7]) * rtb_Product_en;

    /* Gain: '<S54>/Gain3' incorporates:
     *  Product: '<S54>/Product'
     *  Sum: '<S68>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[3] - rtu_DCM[1]) * rtb_Product_en;

    /* End of Outputs for SubSystem: '<S48>/Maximum Value at DCM(3,3)' */
  } else {
    /* Outputs for IfAction SubSystem: '<S48>/Maximum Value at DCM(1,1)' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* Sqrt: '<S52>/sqrt' incorporates:
     *  Constant: '<S60>/Constant'
     *  Sum: '<S60>/Add'
     */
    rtb_Product_en = sqrt(((rtu_DCM[0] - rtu_DCM[4]) - rtu_DCM[8]) + 1.0);

    /* Gain: '<S52>/Gain' */
    rty_qwqxqyqz[1] = 0.5 * rtb_Product_en;

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    if (rtb_Product_en != 0.0) {
      rtb_Switch_a_idx_0 = 0.5;
    } else {
      rtb_Switch_a_idx_0 = 0.0;
      rtb_Product_en = 1.0;
    }

    /* End of Switch: '<S59>/Switch' */

    /* Product: '<S59>/Product' */
    rtb_Product_en = rtb_Switch_a_idx_0 / rtb_Product_en;

    /* Gain: '<S52>/Gain1' incorporates:
     *  Product: '<S52>/Product'
     *  Sum: '<S58>/Add'
     */
    rty_qwqxqyqz[2] = (rtu_DCM[1] + rtu_DCM[3]) * rtb_Product_en;

    /* Gain: '<S52>/Gain2' incorporates:
     *  Product: '<S52>/Product'
     *  Sum: '<S56>/Add'
     */
    rty_qwqxqyqz[3] = (rtu_DCM[2] + rtu_DCM[6]) * rtb_Product_en;

    /* Gain: '<S52>/Gain3' incorporates:
     *  Product: '<S52>/Product'
     *  Sum: '<S57>/Add'
     */
    rty_qwqxqyqz[0] = (rtu_DCM[7] - rtu_DCM[5]) * rtb_Product_en;

    /* End of Outputs for SubSystem: '<S48>/Maximum Value at DCM(1,1)' */
  }

  /* End of If: '<S48>/Find Maximum Diagonal Value' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
