/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.c
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

#include "sunSeek_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S97>/sunSeek_lib' */
void sunSeek_lib(uint8_T rtu_ss_valid, const real_T rtu_sc2sun_pd_body_unit[3],
                 const real_T rtu_sc2sun_ss_body_unit[3], const real_T
                 rtu_w_err_radps[3], real_T rty_torque_cmd_body_Nm[3])
{
  real_T rtb_Add3_f_idx_0;
  real_T rtb_Add3_f_idx_1;
  real_T rtb_Kp_idx_0;
  real_T rtb_Kp_idx_1;
  real_T rtb_Kp_idx_2;
  real_T rtb_MathFunction_j_idx_0;
  real_T rtb_MathFunction_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  int32_T i;

  /* Switch: '<S116>/Switch' */
  if (rtu_ss_valid != 0) {
    rtb_Kp_idx_0 = rtu_sc2sun_ss_body_unit[0];
    rtb_Kp_idx_1 = rtu_sc2sun_ss_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_ss_body_unit[2];
  } else {
    rtb_Kp_idx_0 = rtu_sc2sun_pd_body_unit[0];
    rtb_Kp_idx_1 = rtu_sc2sun_pd_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_pd_body_unit[2];
  }

  /* End of Switch: '<S116>/Switch' */

  /* Sum: '<S118>/Add3' incorporates:
   *  Product: '<S118>/Element product'
   */
  rtb_Switch_j_idx_2 = rtb_Kp_idx_1 * 0.0 - rtb_Kp_idx_2;

  /* Math: '<S119>/Math Function' */
  rtb_MathFunction_j_idx_0 = rtb_Switch_j_idx_2 * rtb_Switch_j_idx_2;

  /* Sum: '<S118>/Add3' incorporates:
   *  Product: '<S118>/Element product'
   */
  rtb_Add3_f_idx_0 = rtb_Switch_j_idx_2;
  rtb_Switch_j_idx_2 = rtb_Kp_idx_2 * 0.0 - rtb_Kp_idx_0 * 0.0;

  /* Math: '<S119>/Math Function' */
  rtb_MathFunction_j_idx_1 = rtb_Switch_j_idx_2 * rtb_Switch_j_idx_2;

  /* Sum: '<S118>/Add3' incorporates:
   *  Product: '<S118>/Element product'
   */
  rtb_Add3_f_idx_1 = rtb_Switch_j_idx_2;
  rtb_Switch_j_idx_2 = rtb_Kp_idx_0 - rtb_Kp_idx_1 * 0.0;

  /* Sum: '<S119>/Sum of Elements' incorporates:
   *  Math: '<S119>/Math Function'
   */
  rtb_MathFunction_j_idx_1 = (rtb_MathFunction_j_idx_0 +
    rtb_MathFunction_j_idx_1) + rtb_Switch_j_idx_2 * rtb_Switch_j_idx_2;

  /* Math: '<S119>/Math Function1'
   *
   * About '<S119>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction_j_idx_1 < 0.0) {
    rtb_MathFunction_j_idx_1 = -sqrt(fabs(rtb_MathFunction_j_idx_1));
  } else {
    rtb_MathFunction_j_idx_1 = sqrt(rtb_MathFunction_j_idx_1);
  }

  /* End of Math: '<S119>/Math Function1' */

  /* Switch: '<S119>/Switch' incorporates:
   *  Constant: '<S119>/Constant'
   *  Product: '<S119>/Product'
   */
  if (rtb_MathFunction_j_idx_1 > 0.0) {
    rtb_MathFunction_j_idx_0 = rtb_MathFunction_j_idx_1;
  } else {
    rtb_Add3_f_idx_0 *= 0.0;
    rtb_Add3_f_idx_1 *= 0.0;
    rtb_Switch_j_idx_2 *= 0.0;
    rtb_MathFunction_j_idx_0 = 1.0;
  }

  /* End of Switch: '<S119>/Switch' */

  /* DotProduct: '<S117>/Dot Product' */
  rtb_Kp_idx_0 = (0.0 * rtb_Kp_idx_0 + rtb_Kp_idx_1) + 0.0 * rtb_Kp_idx_2;

  /* Saturate: '<S117>/sat_pm1' incorporates:
   *  DotProduct: '<S117>/Dot Product'
   */
  if (rtb_Kp_idx_0 > 1.0) {
    rtb_Kp_idx_0 = 1.0;
  } else {
    if (rtb_Kp_idx_0 < -1.0) {
      rtb_Kp_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S117>/sat_pm1' */

  /* Trigonometry: '<S117>/Sin' incorporates:
   *  Gain: '<S117>/Gain'
   *  Trigonometry: '<S117>/Acos'
   */
  rtb_MathFunction_j_idx_1 = sin(0.5 * acos(rtb_Kp_idx_0));

  /* Product: '<S117>/Product' incorporates:
   *  Product: '<S119>/Divide'
   */
  rtb_Add3_f_idx_0 = rtb_Add3_f_idx_0 / rtb_MathFunction_j_idx_0 *
    rtb_MathFunction_j_idx_1;
  rtb_Add3_f_idx_1 = rtb_Add3_f_idx_1 / rtb_MathFunction_j_idx_0 *
    rtb_MathFunction_j_idx_1;
  rtb_Switch_j_idx_2 = rtb_Switch_j_idx_2 / rtb_MathFunction_j_idx_0 *
    rtb_MathFunction_j_idx_1;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S116>/Kd'
     *  Gain: '<S116>/Kp'
     */
    rty_torque_cmd_body_Nm[i] = (rtConstP.Kp_Gain[i + 6] * rtb_Switch_j_idx_2 +
      (rtConstP.Kp_Gain[i + 3] * rtb_Add3_f_idx_1 + rtConstP.Kp_Gain[i] *
       rtb_Add3_f_idx_0)) - (rtConstP.Kd_Gain[i + 6] * rtu_w_err_radps[2] +
      (rtConstP.Kd_Gain[i + 3] * rtu_w_err_radps[1] + rtConstP.Kd_Gain[i] *
       rtu_w_err_radps[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
