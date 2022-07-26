/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
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

#include "target_groundpass_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Output and update for atomic system: '<S4>/target_groundpass_lib1' */
void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3])
{
  real_T rtb_VectorConcatenate_g[9];
  real_T rtb_MathFunction_lu[3];
  real_T rtb_Product_dw[3];
  real_T rtb_MathFunction1_h;
  real_T rtb_SinCos1_o1;
  real_T rtb_SinCos_o1;
  real_T rtb_Sum_p_idx_0;
  real_T rtb_Switch_p_idx_0;
  real_T rtb_Switch_p_idx_1;
  real_T rtb_Switch_p_idx_2;
  real_T rtb_Switch_p_idx_3;
  int32_T i;

  /* Gain: '<S17>/deg2rad1' */
  rtb_SinCos_o1 = 0.017453292519943295 * rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S40>/SinCos' */
  rtb_Sum_p_idx_0 = cos(rtb_SinCos_o1);
  rtb_SinCos_o1 = sin(rtb_SinCos_o1);

  /* Gain: '<S17>/deg2rad2' */
  rtb_SinCos1_o1 = 0.017453292519943295 * rtu_targ_lon_deg;

  /* Trigonometry: '<S40>/SinCos1' */
  rtb_MathFunction1_h = cos(rtb_SinCos1_o1);
  rtb_SinCos1_o1 = sin(rtb_SinCos1_o1);

  /* Product: '<S40>/Product' incorporates:
   *  Trigonometry: '<S40>/SinCos1'
   */
  rtb_VectorConcatenate_g[0] = rtb_SinCos_o1 * rtb_MathFunction1_h;

  /* Gain: '<S40>/Gain1' */
  rtb_VectorConcatenate_g[1] = -rtb_SinCos1_o1;

  /* Product: '<S40>/Product2' incorporates:
   *  Trigonometry: '<S40>/SinCos'
   *  Trigonometry: '<S40>/SinCos1'
   */
  rtb_VectorConcatenate_g[2] = rtb_Sum_p_idx_0 * rtb_MathFunction1_h;

  /* Product: '<S40>/Product1' */
  rtb_VectorConcatenate_g[3] = rtb_SinCos_o1 * rtb_SinCos1_o1;

  /* SignalConversion generated from: '<S42>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S40>/SinCos1'
   */
  rtb_VectorConcatenate_g[4] = rtb_MathFunction1_h;

  /* Product: '<S40>/Product3' incorporates:
   *  Trigonometry: '<S40>/SinCos'
   */
  rtb_VectorConcatenate_g[5] = rtb_Sum_p_idx_0 * rtb_SinCos1_o1;

  /* Gain: '<S40>/Gain' incorporates:
   *  Trigonometry: '<S40>/SinCos'
   */
  rtb_VectorConcatenate_g[6] = -rtb_Sum_p_idx_0;

  /* SignalConversion generated from: '<S42>/Vector Concatenate' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_VectorConcatenate_g[7] = 0.0;

  /* SignalConversion generated from: '<S42>/Vector Concatenate' */
  rtb_VectorConcatenate_g[8] = rtb_SinCos_o1;

  /* Sum: '<S17>/Sum' */
  rtb_SinCos_o1 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];

  /* Gain: '<S17>/Gain' */
  rty_sc2target_ecef_unit[0] = -rtb_SinCos_o1;

  /* Sum: '<S17>/Sum' */
  rtb_Sum_p_idx_0 = rtb_SinCos_o1;
  rtb_SinCos_o1 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];

  /* Gain: '<S17>/Gain' */
  rty_sc2target_ecef_unit[1] = -rtb_SinCos_o1;

  /* Sum: '<S17>/Sum' */
  rtb_SinCos1_o1 = rtb_SinCos_o1;
  rtb_SinCos_o1 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];

  /* Gain: '<S17>/Gain' */
  rty_sc2target_ecef_unit[2] = -rtb_SinCos_o1;
  for (i = 0; i < 3; i++) {
    /* Product: '<S17>/Product' incorporates:
     *  Concatenate: '<S42>/Vector Concatenate'
     */
    rtb_Switch_p_idx_0 = rtb_VectorConcatenate_g[i + 6] *
      rty_sc2target_ecef_unit[2] + (rtb_VectorConcatenate_g[i + 3] *
      rty_sc2target_ecef_unit[1] + rtb_VectorConcatenate_g[i] *
      rty_sc2target_ecef_unit[0]);

    /* Math: '<S39>/Math Function' */
    rtb_MathFunction_lu[i] = rtb_Switch_p_idx_0 * rtb_Switch_p_idx_0;

    /* Product: '<S17>/Product' */
    rtb_Product_dw[i] = rtb_Switch_p_idx_0;
  }

  /* Sum: '<S39>/Sum of Elements' */
  rtb_MathFunction1_h = rtb_MathFunction_lu[0];
  rtb_MathFunction1_h += rtb_MathFunction_lu[1];
  rtb_MathFunction1_h += rtb_MathFunction_lu[2];

  /* Math: '<S39>/Math Function1'
   *
   * About '<S39>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1_h < 0.0) {
    rtb_MathFunction1_h = -sqrt(fabs(rtb_MathFunction1_h));
  } else {
    rtb_MathFunction1_h = sqrt(rtb_MathFunction1_h);
  }

  /* End of Math: '<S39>/Math Function1' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant'
   *  Product: '<S39>/Product'
   */
  if (rtb_MathFunction1_h > 0.0) {
    rtb_Switch_p_idx_0 = rtb_Product_dw[0];
    rtb_Switch_p_idx_1 = rtb_Product_dw[1];
    rtb_Switch_p_idx_2 = rtb_Product_dw[2];
    rtb_Switch_p_idx_3 = rtb_MathFunction1_h;
  } else {
    rtb_Switch_p_idx_0 = rtb_Product_dw[0] * 0.0;
    rtb_Switch_p_idx_1 = rtb_Product_dw[1] * 0.0;
    rtb_Switch_p_idx_2 = rtb_Product_dw[2] * 0.0;
    rtb_Switch_p_idx_3 = 1.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Product: '<S39>/Divide' */
  rtb_Product_dw[0] = rtb_Switch_p_idx_0 / rtb_Switch_p_idx_3;
  rtb_Product_dw[1] = rtb_Switch_p_idx_1 / rtb_Switch_p_idx_3;
  rtb_Product_dw[2] = rtb_Switch_p_idx_2 / rtb_Switch_p_idx_3;

  /* Outputs for Atomic SubSystem: '<S17>/twonorm' */
  rtb_MathFunction1_h = twonorm(&rtb_Product_dw[0]);

  /* End of Outputs for SubSystem: '<S17>/twonorm' */

  /* Trigonometry: '<S17>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Product_dw[2], rtb_MathFunction1_h);

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);

  /* Sum: '<S38>/Sum of Elements' incorporates:
   *  Math: '<S38>/Math Function'
   */
  rtb_MathFunction1_h = rtb_Sum_p_idx_0 * rtb_Sum_p_idx_0;
  rtb_MathFunction1_h += rtb_SinCos1_o1 * rtb_SinCos1_o1;
  rtb_MathFunction1_h += rtb_SinCos_o1 * rtb_SinCos_o1;

  /* Math: '<S38>/Math Function1'
   *
   * About '<S38>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1_h < 0.0) {
    rtb_MathFunction1_h = -sqrt(fabs(rtb_MathFunction1_h));
  } else {
    rtb_MathFunction1_h = sqrt(rtb_MathFunction1_h);
  }

  /* End of Math: '<S38>/Math Function1' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Product: '<S38>/Product'
   */
  if (rtb_MathFunction1_h > 0.0) {
    rtb_Switch_p_idx_0 = rtb_Sum_p_idx_0;
    rtb_Switch_p_idx_1 = rtb_SinCos1_o1;
    rtb_Switch_p_idx_2 = rtb_SinCos_o1;
    rtb_Switch_p_idx_3 = rtb_MathFunction1_h;
  } else {
    rtb_Switch_p_idx_0 = rtb_Sum_p_idx_0 * 0.0;
    rtb_Switch_p_idx_1 = rtb_SinCos1_o1 * 0.0;
    rtb_Switch_p_idx_2 = rtb_SinCos_o1 * 0.0;
    rtb_Switch_p_idx_3 = 1.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Product: '<S38>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_p_idx_0 / rtb_Switch_p_idx_3;
  rty_sc2target_ecef_unit[1] = rtb_Switch_p_idx_1 / rtb_Switch_p_idx_3;
  rty_sc2target_ecef_unit[2] = rtb_Switch_p_idx_2 / rtb_Switch_p_idx_3;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
