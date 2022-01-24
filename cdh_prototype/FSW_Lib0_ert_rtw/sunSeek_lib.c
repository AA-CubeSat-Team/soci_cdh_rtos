/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "sunSeek_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Output and update for atomic system: '<S238>/sunSeek_lib' */
void sunSeek_lib(uint8_T rtu_ss_valid, const real_T rtu_sc2sun_pd_body_unit[3],
                 const real_T rtu_sc2sun_ss_body_unit[3], const real_T
                 rtu_w_err_radps[3], real_T rty_torque_cmd_body_Nm[3],
                 DW_sunSeek_lib *localDW, P_sunSeek_lib *localP)
{
  int32_T i;
  real_T rtb_Kp_idx_2;
  real_T rtb_Kp_idx_0;
  real_T rtb_MathFunction_d_idx_0;
  real_T rtb_Add3_idx_0;
  real_T rtb_MathFunction_d_idx_1;
  real_T rtb_Add3_idx_1;
  real_T rtb_Switch_g0_idx_2;

  /* Switch: '<S257>/Switch' */
  if (rtu_ss_valid != 0) {
    rtb_Kp_idx_0 = rtu_sc2sun_ss_body_unit[0];
    localDW->rtb_Kp_idx_1 = rtu_sc2sun_ss_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_ss_body_unit[2];
  } else {
    rtb_Kp_idx_0 = rtu_sc2sun_pd_body_unit[0];
    localDW->rtb_Kp_idx_1 = rtu_sc2sun_pd_body_unit[1];
    rtb_Kp_idx_2 = rtu_sc2sun_pd_body_unit[2];
  }

  /* End of Switch: '<S257>/Switch' */

  /* Sum: '<S259>/Add3' incorporates:
   *  Constant: '<S258>/sunsensor_boresight_unit'
   *  Product: '<S259>/Element product'
   */
  rtb_Switch_g0_idx_2 = localDW->rtb_Kp_idx_1 * rtP.fswParams.scParams.yB_dir[2]
    - rtb_Kp_idx_2 * rtP.fswParams.scParams.yB_dir[1];

  /* Math: '<S260>/Math Function' */
  rtb_MathFunction_d_idx_0 = rtb_Switch_g0_idx_2 * rtb_Switch_g0_idx_2;

  /* Sum: '<S259>/Add3' incorporates:
   *  Constant: '<S258>/sunsensor_boresight_unit'
   *  Product: '<S259>/Element product'
   */
  rtb_Add3_idx_0 = rtb_Switch_g0_idx_2;
  rtb_Switch_g0_idx_2 = rtb_Kp_idx_2 * rtP.fswParams.scParams.yB_dir[0] -
    rtb_Kp_idx_0 * rtP.fswParams.scParams.yB_dir[2];

  /* Math: '<S260>/Math Function' */
  rtb_MathFunction_d_idx_1 = rtb_Switch_g0_idx_2 * rtb_Switch_g0_idx_2;

  /* Sum: '<S259>/Add3' incorporates:
   *  Constant: '<S258>/sunsensor_boresight_unit'
   *  Product: '<S259>/Element product'
   */
  rtb_Add3_idx_1 = rtb_Switch_g0_idx_2;
  rtb_Switch_g0_idx_2 = rtb_Kp_idx_0 * rtP.fswParams.scParams.yB_dir[1] -
    localDW->rtb_Kp_idx_1 * rtP.fswParams.scParams.yB_dir[0];

  /* Sum: '<S260>/Sum of Elements' incorporates:
   *  Math: '<S260>/Math Function'
   */
  rtb_MathFunction_d_idx_1 = (rtb_MathFunction_d_idx_0 +
    rtb_MathFunction_d_idx_1) + rtb_Switch_g0_idx_2 * rtb_Switch_g0_idx_2;

  /* Math: '<S260>/Math Function1'
   *
   * About '<S260>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction_d_idx_1 < 0.0) {
    rtb_MathFunction_d_idx_1 = -sqrt(fabs(rtb_MathFunction_d_idx_1));
  } else {
    rtb_MathFunction_d_idx_1 = sqrt(rtb_MathFunction_d_idx_1);
  }

  /* End of Math: '<S260>/Math Function1' */

  /* Switch: '<S260>/Switch' incorporates:
   *  Constant: '<S260>/Constant'
   *  Product: '<S260>/Product'
   */
  if (rtb_MathFunction_d_idx_1 > localP->NormalizeVector_maxzero) {
    rtb_MathFunction_d_idx_0 = rtb_MathFunction_d_idx_1;
  } else {
    rtb_Add3_idx_0 *= 0.0;
    rtb_Add3_idx_1 *= 0.0;
    rtb_Switch_g0_idx_2 *= 0.0;
    rtb_MathFunction_d_idx_0 = localP->Constant_Value;
  }

  /* End of Switch: '<S260>/Switch' */

  /* DotProduct: '<S258>/Dot Product' incorporates:
   *  Constant: '<S258>/sunsensor_boresight_unit'
   */
  rtb_Kp_idx_0 = (rtP.fswParams.scParams.yB_dir[0] * rtb_Kp_idx_0 +
                  rtP.fswParams.scParams.yB_dir[1] * localDW->rtb_Kp_idx_1) +
    rtP.fswParams.scParams.yB_dir[2] * rtb_Kp_idx_2;

  /* Saturate: '<S258>/sat_pm1' incorporates:
   *  DotProduct: '<S258>/Dot Product'
   */
  if (rtb_Kp_idx_0 > localP->sat_pm1_UpperSat) {
    rtb_Kp_idx_0 = localP->sat_pm1_UpperSat;
  } else {
    if (rtb_Kp_idx_0 < localP->sat_pm1_LowerSat) {
      rtb_Kp_idx_0 = localP->sat_pm1_LowerSat;
    }
  }

  /* End of Saturate: '<S258>/sat_pm1' */

  /* Trigonometry: '<S258>/Acos' */
  if (rtb_Kp_idx_0 > 1.0) {
    rtb_Kp_idx_0 = 1.0;
  } else {
    if (rtb_Kp_idx_0 < -1.0) {
      rtb_Kp_idx_0 = -1.0;
    }
  }

  /* Trigonometry: '<S258>/Sin' incorporates:
   *  Gain: '<S258>/Gain'
   *  Trigonometry: '<S258>/Acos'
   */
  rtb_MathFunction_d_idx_1 = sin(localP->Gain_Gain * acos(rtb_Kp_idx_0));

  /* Product: '<S258>/Product' incorporates:
   *  Product: '<S260>/Divide'
   */
  rtb_Add3_idx_0 = rtb_Add3_idx_0 / rtb_MathFunction_d_idx_0 *
    rtb_MathFunction_d_idx_1;
  rtb_Add3_idx_1 = rtb_Add3_idx_1 / rtb_MathFunction_d_idx_0 *
    rtb_MathFunction_d_idx_1;
  rtb_Switch_g0_idx_2 = rtb_Switch_g0_idx_2 / rtb_MathFunction_d_idx_0 *
    rtb_MathFunction_d_idx_1;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S257>/Sum' incorporates:
     *  Gain: '<S257>/Kd'
     *  Gain: '<S257>/Kp'
     */
    rty_torque_cmd_body_Nm[i] = (rtP.fswParams.controllers.sunseek.Kp[i + 6] *
      rtb_Switch_g0_idx_2 + (rtP.fswParams.controllers.sunseek.Kp[i + 3] *
      rtb_Add3_idx_1 + rtP.fswParams.controllers.sunseek.Kp[i] * rtb_Add3_idx_0))
      - (rtP.fswParams.controllers.sunseek.Kd[i + 6] * rtu_w_err_radps[2] +
         (rtP.fswParams.controllers.sunseek.Kd[i + 3] * rtu_w_err_radps[1] +
          rtP.fswParams.controllers.sunseek.Kd[i] * rtu_w_err_radps[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
