/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "sunSeek_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Output and update for atomic system: '<S237>/sunSeek_lib' */
void sunSeek_lib(uint8_T rtu_ss_valid, const real_T rtu_sc2sun_pd_body_unit[3],
                 const real_T rtu_sc2sun_ss_body_unit[3], const real_T
                 rtu_w_err_radps[3], real_T rty_torque_cmd_body_Nm[3])
{
  int32_T i;
  real_T rtb_Kp_idx_1;
  real_T rtb_Kp_idx_2;
  real_T rtb_Kp_idx_0;
  real_T rtb_MathFunction_m_idx_0;
  real_T rtb_Add3_idx_0;
  real_T rtb_MathFunction_m_idx_1;
  real_T rtb_Add3_idx_1;
  real_T rtb_Switch_ac_idx_2;

  /* Switch: '<S256>/Switch' */
  if (rtu_ss_valid != 0) {
    rtb_Kp_idx_0 = rtu_sc2sun_ss_body_unit[0];
    rtb_Kp_idx_1 = rtu_sc2sun_ss_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_ss_body_unit[2];
  } else {
    rtb_Kp_idx_0 = rtu_sc2sun_pd_body_unit[0];
    rtb_Kp_idx_1 = rtu_sc2sun_pd_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_pd_body_unit[2];
  }

  /* End of Switch: '<S256>/Switch' */

  /* Sum: '<S258>/Add3' incorporates:
   *  Product: '<S258>/Element product'
   */
  rtb_Switch_ac_idx_2 = rtb_Kp_idx_1 * 0.0 - rtb_Kp_idx_2;

  /* Math: '<S259>/Math Function' */
  rtb_MathFunction_m_idx_0 = rtb_Switch_ac_idx_2 * rtb_Switch_ac_idx_2;

  /* Sum: '<S258>/Add3' incorporates:
   *  Product: '<S258>/Element product'
   */
  rtb_Add3_idx_0 = rtb_Switch_ac_idx_2;
  rtb_Switch_ac_idx_2 = rtb_Kp_idx_2 * 0.0 - rtb_Kp_idx_0 * 0.0;

  /* Math: '<S259>/Math Function' */
  rtb_MathFunction_m_idx_1 = rtb_Switch_ac_idx_2 * rtb_Switch_ac_idx_2;

  /* Sum: '<S258>/Add3' incorporates:
   *  Product: '<S258>/Element product'
   */
  rtb_Add3_idx_1 = rtb_Switch_ac_idx_2;
  rtb_Switch_ac_idx_2 = rtb_Kp_idx_0 - rtb_Kp_idx_1 * 0.0;

  /* Sum: '<S259>/Sum of Elements' incorporates:
   *  Math: '<S259>/Math Function'
   */
  rtb_MathFunction_m_idx_1 = (rtb_MathFunction_m_idx_0 +
    rtb_MathFunction_m_idx_1) + rtb_Switch_ac_idx_2 * rtb_Switch_ac_idx_2;

  /* Math: '<S259>/Math Function1'
   *
   * About '<S259>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction_m_idx_1 < 0.0) {
    rtb_MathFunction_m_idx_1 = -sqrt(fabs(rtb_MathFunction_m_idx_1));
  } else {
    rtb_MathFunction_m_idx_1 = sqrt(rtb_MathFunction_m_idx_1);
  }

  /* End of Math: '<S259>/Math Function1' */

  /* Switch: '<S259>/Switch' incorporates:
   *  Constant: '<S259>/Constant'
   *  Product: '<S259>/Product'
   */
  if (rtb_MathFunction_m_idx_1 > 0.0) {
    rtb_MathFunction_m_idx_0 = rtb_MathFunction_m_idx_1;
  } else {
    rtb_Add3_idx_0 *= 0.0;
    rtb_Add3_idx_1 *= 0.0;
    rtb_Switch_ac_idx_2 *= 0.0;
    rtb_MathFunction_m_idx_0 = 1.0;
  }

  /* End of Switch: '<S259>/Switch' */

  /* DotProduct: '<S257>/Dot Product' */
  rtb_Kp_idx_0 = (0.0 * rtb_Kp_idx_0 + rtb_Kp_idx_1) + 0.0 * rtb_Kp_idx_2;

  /* Saturate: '<S257>/sat_pm1' incorporates:
   *  DotProduct: '<S257>/Dot Product'
   */
  if (rtb_Kp_idx_0 > 1.0) {
    rtb_Kp_idx_0 = 1.0;
  } else {
    if (rtb_Kp_idx_0 < -1.0) {
      rtb_Kp_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S257>/sat_pm1' */

  /* Trigonometry: '<S257>/Sin' incorporates:
   *  Gain: '<S257>/Gain'
   *  Trigonometry: '<S257>/Acos'
   */
  rtb_MathFunction_m_idx_1 = sin(0.5 * acos(rtb_Kp_idx_0));

  /* Product: '<S257>/Product' incorporates:
   *  Product: '<S259>/Divide'
   */
  rtb_Add3_idx_0 = rtb_Add3_idx_0 / rtb_MathFunction_m_idx_0 *
    rtb_MathFunction_m_idx_1;
  rtb_Add3_idx_1 = rtb_Add3_idx_1 / rtb_MathFunction_m_idx_0 *
    rtb_MathFunction_m_idx_1;
  rtb_Switch_ac_idx_2 = rtb_Switch_ac_idx_2 / rtb_MathFunction_m_idx_0 *
    rtb_MathFunction_m_idx_1;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S256>/Sum' incorporates:
     *  Gain: '<S256>/Kd'
     *  Gain: '<S256>/Kp'
     */
    rty_torque_cmd_body_Nm[i] = (rtCP_Kp_Gain[i + 6] * rtb_Switch_ac_idx_2 +
      (rtCP_Kp_Gain[i + 3] * rtb_Add3_idx_1 + rtCP_Kp_Gain[i] * rtb_Add3_idx_0))
      - (rtCP_Kd_Gain[i + 6] * rtu_w_err_radps[2] + (rtCP_Kd_Gain[i + 3] *
          rtu_w_err_radps[1] + rtCP_Kd_Gain[i] * rtu_w_err_radps[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
