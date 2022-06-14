/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
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

#include "target_groundpass_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "rt_atan2d_snf.h"

/* Output and update for atomic system: '<S288>/target_groundpass_lib' */
void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad,
  real_T rty_sc2target_ecef_unit[3], const ConstB_target_groundpass_lib *localC)
{
  real_T rtb_MathFunction_j3[3];
  real_T rtb_Product_hz[3];
  real_T rtb_MathFunction1;
  real_T rtb_Sum_mr_idx_0;
  real_T rtb_Sum_mr_idx_1;
  real_T rtb_Sum_mr_idx_2;
  real_T rtb_Switch_c_idx_0;
  real_T rtb_Switch_c_idx_1;
  real_T rtb_Switch_c_idx_2;
  real_T rtb_Switch_c_idx_3;
  int32_T i;

  /* Sum: '<S293>/Sum' */
  rtb_Sum_mr_idx_0 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];
  rtb_Sum_mr_idx_1 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];
  rtb_Sum_mr_idx_2 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S293>/Product' incorporates:
     *  Concatenate: '<S300>/Vector Concatenate'
     *  Gain: '<S293>/Gain'
     */
    rtb_Switch_c_idx_0 = localC->VectorConcatenate[i + 6] * -rtb_Sum_mr_idx_2 +
      (localC->VectorConcatenate[i + 3] * -rtb_Sum_mr_idx_1 +
       localC->VectorConcatenate[i] * -rtb_Sum_mr_idx_0);

    /* Math: '<S297>/Math Function' */
    rtb_MathFunction_j3[i] = rtb_Switch_c_idx_0 * rtb_Switch_c_idx_0;

    /* Product: '<S293>/Product' */
    rtb_Product_hz[i] = rtb_Switch_c_idx_0;
  }

  /* Sum: '<S297>/Sum of Elements' */
  rtb_MathFunction1 = rtb_MathFunction_j3[0];
  rtb_MathFunction1 += rtb_MathFunction_j3[1];
  rtb_MathFunction1 += rtb_MathFunction_j3[2];
  *rty_elev_sez_rad = rtb_MathFunction1;

  /* Math: '<S297>/Math Function1'
   *
   * About '<S297>/Math Function1':
   *  Operator: sqrt
   */
  if (*rty_elev_sez_rad < 0.0) {
    *rty_elev_sez_rad = -sqrt(fabs(*rty_elev_sez_rad));
  } else {
    *rty_elev_sez_rad = sqrt(*rty_elev_sez_rad);
  }

  /* End of Math: '<S297>/Math Function1' */

  /* Switch: '<S297>/Switch' incorporates:
   *  Constant: '<S297>/Constant'
   *  Product: '<S297>/Product'
   */
  if (*rty_elev_sez_rad > 0.0) {
    rtb_Switch_c_idx_0 = rtb_Product_hz[0];
    rtb_Switch_c_idx_1 = rtb_Product_hz[1];
    rtb_Switch_c_idx_2 = rtb_Product_hz[2];
    rtb_Switch_c_idx_3 = *rty_elev_sez_rad;
  } else {
    rtb_Switch_c_idx_0 = rtb_Product_hz[0] * 0.0;
    rtb_Switch_c_idx_1 = rtb_Product_hz[1] * 0.0;
    rtb_Switch_c_idx_2 = rtb_Product_hz[2] * 0.0;
    rtb_Switch_c_idx_3 = 1.0;
  }

  /* End of Switch: '<S297>/Switch' */

  /* Product: '<S297>/Divide' */
  rtb_Product_hz[0] = rtb_Switch_c_idx_0 / rtb_Switch_c_idx_3;
  rtb_Product_hz[1] = rtb_Switch_c_idx_1 / rtb_Switch_c_idx_3;
  rtb_Product_hz[2] = rtb_Switch_c_idx_2 / rtb_Switch_c_idx_3;

  /* Outputs for Atomic SubSystem: '<S293>/twonorm' */
  rtb_MathFunction1 = twonorm_f(&rtb_Product_hz[0]);

  /* End of Outputs for SubSystem: '<S293>/twonorm' */

  /* Trigonometry: '<S293>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Product_hz[2], rtb_MathFunction1);

  /* RelationalOperator: '<S295>/Compare' incorporates:
   *  Constant: '<S295>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);

  /* Sum: '<S296>/Sum of Elements' incorporates:
   *  Math: '<S296>/Math Function'
   */
  rtb_MathFunction1 = rtb_Sum_mr_idx_0 * rtb_Sum_mr_idx_0;
  rtb_MathFunction1 += rtb_Sum_mr_idx_1 * rtb_Sum_mr_idx_1;
  rtb_MathFunction1 += rtb_Sum_mr_idx_2 * rtb_Sum_mr_idx_2;

  /* Math: '<S296>/Math Function1'
   *
   * About '<S296>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1 < 0.0) {
    rtb_MathFunction1 = -sqrt(fabs(rtb_MathFunction1));
  } else {
    rtb_MathFunction1 = sqrt(rtb_MathFunction1);
  }

  /* End of Math: '<S296>/Math Function1' */

  /* Switch: '<S296>/Switch' incorporates:
   *  Constant: '<S296>/Constant'
   *  Product: '<S296>/Product'
   */
  if (rtb_MathFunction1 > 0.0) {
    rtb_Switch_c_idx_0 = rtb_Sum_mr_idx_0;
    rtb_Switch_c_idx_1 = rtb_Sum_mr_idx_1;
    rtb_Switch_c_idx_2 = rtb_Sum_mr_idx_2;
    rtb_Switch_c_idx_3 = rtb_MathFunction1;
  } else {
    rtb_Switch_c_idx_0 = rtb_Sum_mr_idx_0 * 0.0;
    rtb_Switch_c_idx_1 = rtb_Sum_mr_idx_1 * 0.0;
    rtb_Switch_c_idx_2 = rtb_Sum_mr_idx_2 * 0.0;
    rtb_Switch_c_idx_3 = 1.0;
  }

  /* End of Switch: '<S296>/Switch' */

  /* Product: '<S296>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_c_idx_0 / rtb_Switch_c_idx_3;
  rty_sc2target_ecef_unit[1] = rtb_Switch_c_idx_1 / rtb_Switch_c_idx_3;
  rty_sc2target_ecef_unit[2] = rtb_Switch_c_idx_2 / rtb_Switch_c_idx_3;
}

/* Output and update for atomic system: '<S288>/target_groundpass_lib1' */
void target_groundpass_lib1(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3])
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_MathFunction_mp[3];
  real_T rtb_Product_jn[3];
  real_T rtb_MathFunction1;
  real_T rtb_SinCos_o1;
  real_T rtb_Sum_mg_idx_1;
  real_T rtb_Sum_mg_idx_2;
  real_T rtb_Switch_lp_idx_0;
  real_T rtb_Switch_lp_idx_1;
  real_T rtb_Switch_lp_idx_2;
  int32_T i;

  /* Gain: '<S294>/deg2rad1' */
  rtb_SinCos_o1 = 0.017453292519943295 * rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S304>/SinCos' */
  rtb_Sum_mg_idx_1 = cos(rtb_SinCos_o1);
  rtb_SinCos_o1 = sin(rtb_SinCos_o1);

  /* Gain: '<S294>/deg2rad2' */
  rtb_MathFunction1 = 0.017453292519943295 * rtu_targ_lon_deg;

  /* Trigonometry: '<S304>/SinCos1' */
  *rty_elev_sez_rad = cos(rtb_MathFunction1);
  rtb_MathFunction1 = sin(rtb_MathFunction1);

  /* Product: '<S304>/Product' */
  rtb_VectorConcatenate[0] = rtb_SinCos_o1 * *rty_elev_sez_rad;

  /* Gain: '<S304>/Gain1' */
  rtb_VectorConcatenate[1] = -rtb_MathFunction1;

  /* Product: '<S304>/Product2' incorporates:
   *  Trigonometry: '<S304>/SinCos'
   */
  rtb_VectorConcatenate[2] = rtb_Sum_mg_idx_1 * *rty_elev_sez_rad;

  /* Product: '<S304>/Product1' */
  rtb_VectorConcatenate[3] = rtb_SinCos_o1 * rtb_MathFunction1;

  /* SignalConversion generated from: '<S306>/Vector Concatenate' */
  rtb_VectorConcatenate[4] = *rty_elev_sez_rad;

  /* Product: '<S304>/Product3' incorporates:
   *  Trigonometry: '<S304>/SinCos'
   */
  rtb_VectorConcatenate[5] = rtb_Sum_mg_idx_1 * rtb_MathFunction1;

  /* Gain: '<S304>/Gain' incorporates:
   *  Trigonometry: '<S304>/SinCos'
   */
  rtb_VectorConcatenate[6] = -rtb_Sum_mg_idx_1;

  /* SignalConversion generated from: '<S306>/Vector Concatenate' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* SignalConversion generated from: '<S306>/Vector Concatenate' */
  rtb_VectorConcatenate[8] = rtb_SinCos_o1;

  /* Sum: '<S294>/Sum' */
  rtb_SinCos_o1 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];
  rtb_Sum_mg_idx_1 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];
  rtb_Sum_mg_idx_2 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S294>/Product' incorporates:
     *  Concatenate: '<S306>/Vector Concatenate'
     *  Gain: '<S294>/Gain'
     */
    rtb_MathFunction1 = rtb_VectorConcatenate[i + 6] * -rtb_Sum_mg_idx_2 +
      (rtb_VectorConcatenate[i + 3] * -rtb_Sum_mg_idx_1 +
       rtb_VectorConcatenate[i] * -rtb_SinCos_o1);

    /* Math: '<S303>/Math Function' */
    rtb_MathFunction_mp[i] = rtb_MathFunction1 * rtb_MathFunction1;

    /* Product: '<S294>/Product' */
    rtb_Product_jn[i] = rtb_MathFunction1;
  }

  /* Sum: '<S303>/Sum of Elements' */
  *rty_elev_sez_rad = (rtb_MathFunction_mp[0] + rtb_MathFunction_mp[1]) +
    rtb_MathFunction_mp[2];

  /* Math: '<S303>/Math Function1'
   *
   * About '<S303>/Math Function1':
   *  Operator: sqrt
   */
  if (*rty_elev_sez_rad < 0.0) {
    *rty_elev_sez_rad = -sqrt(fabs(*rty_elev_sez_rad));
  } else {
    *rty_elev_sez_rad = sqrt(*rty_elev_sez_rad);
  }

  /* End of Math: '<S303>/Math Function1' */

  /* Switch: '<S303>/Switch' incorporates:
   *  Constant: '<S303>/Constant'
   *  Product: '<S303>/Product'
   */
  if (*rty_elev_sez_rad > 0.0) {
    rtb_Switch_lp_idx_0 = rtb_Product_jn[0];
    rtb_Switch_lp_idx_1 = rtb_Product_jn[1];
    rtb_Switch_lp_idx_2 = rtb_Product_jn[2];
    rtb_MathFunction1 = *rty_elev_sez_rad;
  } else {
    rtb_Switch_lp_idx_0 = rtb_Product_jn[0] * 0.0;
    rtb_Switch_lp_idx_1 = rtb_Product_jn[1] * 0.0;
    rtb_Switch_lp_idx_2 = rtb_Product_jn[2] * 0.0;
    rtb_MathFunction1 = 1.0;
  }

  /* End of Switch: '<S303>/Switch' */

  /* Product: '<S303>/Divide' */
  rtb_Product_jn[0] = rtb_Switch_lp_idx_0 / rtb_MathFunction1;
  rtb_Product_jn[1] = rtb_Switch_lp_idx_1 / rtb_MathFunction1;
  rtb_Product_jn[2] = rtb_Switch_lp_idx_2 / rtb_MathFunction1;

  /* Outputs for Atomic SubSystem: '<S294>/twonorm' */
  *rty_elev_sez_rad = twonorm_f(&rtb_Product_jn[0]);

  /* End of Outputs for SubSystem: '<S294>/twonorm' */

  /* Trigonometry: '<S294>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Product_jn[2], *rty_elev_sez_rad);

  /* RelationalOperator: '<S301>/Compare' incorporates:
   *  Constant: '<S301>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);

  /* Sum: '<S302>/Sum of Elements' incorporates:
   *  Math: '<S302>/Math Function'
   */
  rtb_MathFunction1 = (rtb_SinCos_o1 * rtb_SinCos_o1 + rtb_Sum_mg_idx_1 *
                       rtb_Sum_mg_idx_1) + rtb_Sum_mg_idx_2 * rtb_Sum_mg_idx_2;

  /* Math: '<S302>/Math Function1'
   *
   * About '<S302>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1 < 0.0) {
    rtb_MathFunction1 = -sqrt(fabs(rtb_MathFunction1));
  } else {
    rtb_MathFunction1 = sqrt(rtb_MathFunction1);
  }

  /* End of Math: '<S302>/Math Function1' */

  /* Switch: '<S302>/Switch' incorporates:
   *  Constant: '<S302>/Constant'
   *  Product: '<S302>/Product'
   */
  if (rtb_MathFunction1 > 0.0) {
    rtb_Switch_lp_idx_0 = rtb_SinCos_o1;
    rtb_Switch_lp_idx_1 = rtb_Sum_mg_idx_1;
    rtb_Switch_lp_idx_2 = rtb_Sum_mg_idx_2;
  } else {
    rtb_Switch_lp_idx_0 = rtb_SinCos_o1 * 0.0;
    rtb_Switch_lp_idx_1 = rtb_Sum_mg_idx_1 * 0.0;
    rtb_Switch_lp_idx_2 = rtb_Sum_mg_idx_2 * 0.0;
    rtb_MathFunction1 = 1.0;
  }

  /* End of Switch: '<S302>/Switch' */

  /* Product: '<S302>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_lp_idx_0 / rtb_MathFunction1;
  rty_sc2target_ecef_unit[1] = rtb_Switch_lp_idx_1 / rtb_MathFunction1;
  rty_sc2target_ecef_unit[2] = rtb_Switch_lp_idx_2 / rtb_MathFunction1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
