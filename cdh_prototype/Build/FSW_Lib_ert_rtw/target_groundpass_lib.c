/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
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
  real_T rtb_Sum_mj[3];
  real_T rtb_MathFunction_b[3];
  real_T rtb_Sqrt_kp;
  int32_T i;
  real_T rtb_Switch_c_idx_3;
  real_T rtb_Switch_c5_idx_3;
  real_T rtb_Switch_c_idx_0;
  real_T rtb_Switch_c_idx_1;
  real_T rtb_Switch_c_idx_2;
  real_T rtb_Switch_c5_idx_0;
  real_T rtb_Switch_c5_idx_1;
  real_T rtb_Switch_c5_idx_2;

  /* Sum: '<S294>/Sum' */
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];

  /* Math: '<S337>/Math Function' */
  rtb_MathFunction_b[0] = rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Sum: '<S294>/Sum' */
  rtb_Sum_mj[0] = rtb_Switch_c5_idx_0;
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];

  /* Math: '<S337>/Math Function' */
  rtb_MathFunction_b[1] = rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Sum: '<S294>/Sum' */
  rtb_Sum_mj[1] = rtb_Switch_c5_idx_0;
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];

  /* Sum: '<S337>/Sum of Elements' incorporates:
   *  Math: '<S337>/Math Function'
   */
  rtb_Sqrt_kp = rtb_MathFunction_b[0];
  rtb_Sqrt_kp += rtb_MathFunction_b[1];
  rtb_Sqrt_kp += rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Math: '<S337>/Math Function1'
   *
   * About '<S337>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_kp < 0.0) {
    rtb_Sqrt_kp = -sqrt(fabs(rtb_Sqrt_kp));
  } else {
    rtb_Sqrt_kp = sqrt(rtb_Sqrt_kp);
  }

  /* End of Math: '<S337>/Math Function1' */

  /* Switch: '<S337>/Switch' incorporates:
   *  Constant: '<S337>/Constant'
   *  Product: '<S337>/Product'
   */
  if (rtb_Sqrt_kp > 0.0) {
    rtb_Switch_c_idx_0 = rtb_Sum_mj[0];
    rtb_Switch_c_idx_1 = rtb_Sum_mj[1];
    rtb_Switch_c_idx_2 = rtb_Switch_c5_idx_0;
    rtb_Switch_c_idx_3 = rtb_Sqrt_kp;
  } else {
    rtb_Switch_c_idx_0 = rtb_Sum_mj[0] * 0.0;
    rtb_Switch_c_idx_1 = rtb_Sum_mj[1] * 0.0;
    rtb_Switch_c_idx_2 = rtb_Switch_c5_idx_0 * 0.0;
    rtb_Switch_c_idx_3 = 1.0;
  }

  /* End of Switch: '<S337>/Switch' */

  /* Product: '<S294>/Product' incorporates:
   *  Gain: '<S294>/Gain'
   */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_b[i] = localC->VectorConcatenate[i + 6] *
      -rtb_Switch_c5_idx_0 + (localC->VectorConcatenate[i + 3] * -rtb_Sum_mj[1]
      + localC->VectorConcatenate[i] * -rtb_Sum_mj[0]);
  }

  /* End of Product: '<S294>/Product' */

  /* Sum: '<S338>/Sum of Elements' incorporates:
   *  Math: '<S338>/Math Function'
   */
  rtb_Sqrt_kp = rtb_MathFunction_b[0] * rtb_MathFunction_b[0];
  rtb_Sqrt_kp += rtb_MathFunction_b[1] * rtb_MathFunction_b[1];
  rtb_Sqrt_kp += rtb_MathFunction_b[2] * rtb_MathFunction_b[2];

  /* Math: '<S338>/Math Function1'
   *
   * About '<S338>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_kp < 0.0) {
    rtb_Sqrt_kp = -sqrt(fabs(rtb_Sqrt_kp));
  } else {
    rtb_Sqrt_kp = sqrt(rtb_Sqrt_kp);
  }

  /* End of Math: '<S338>/Math Function1' */

  /* Switch: '<S338>/Switch' incorporates:
   *  Constant: '<S338>/Constant'
   *  Product: '<S338>/Product'
   */
  if (rtb_Sqrt_kp > 0.0) {
    rtb_Switch_c5_idx_0 = rtb_MathFunction_b[0];
    rtb_Switch_c5_idx_1 = rtb_MathFunction_b[1];
    rtb_Switch_c5_idx_2 = rtb_MathFunction_b[2];
    rtb_Switch_c5_idx_3 = rtb_Sqrt_kp;
  } else {
    rtb_Switch_c5_idx_0 = rtb_MathFunction_b[0] * 0.0;
    rtb_Switch_c5_idx_1 = rtb_MathFunction_b[1] * 0.0;
    rtb_Switch_c5_idx_2 = rtb_MathFunction_b[2] * 0.0;
    rtb_Switch_c5_idx_3 = 1.0;
  }

  /* End of Switch: '<S338>/Switch' */

  /* Product: '<S338>/Divide' */
  rtb_Sum_mj[0] = rtb_Switch_c5_idx_0 / rtb_Switch_c5_idx_3;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_c_idx_0 / rtb_Switch_c_idx_3;

  /* Product: '<S338>/Divide' */
  rtb_Sum_mj[1] = rtb_Switch_c5_idx_1 / rtb_Switch_c5_idx_3;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_c_idx_1 / rtb_Switch_c_idx_3;

  /* Product: '<S338>/Divide' */
  rtb_Sum_mj[2] = rtb_Switch_c5_idx_2 / rtb_Switch_c5_idx_3;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_c_idx_2 / rtb_Switch_c_idx_3;

  /* Outputs for Atomic SubSystem: '<S294>/twonorm' */
  rtb_Sqrt_kp = twonorm_f(&rtb_Sum_mj[0]);

  /* End of Outputs for SubSystem: '<S294>/twonorm' */

  /* Trigonometry: '<S294>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_mj[2], rtb_Sqrt_kp);

  /* RelationalOperator: '<S336>/Compare' incorporates:
   *  Constant: '<S336>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/* Output and update for atomic system: '<S288>/target_groundpass_lib1' */
void target_groundpass_lib1(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3])
{
  real_T rtb_Sum_mk[3];
  real_T rtb_MathFunction_br[3];
  real_T rtb_SinCos_o1;
  real_T rtb_SinCos1_o1;
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_gw;
  int32_T i;
  real_T rtb_Switch_lp_idx_3;
  real_T rtb_Switch_lp_idx_0;
  real_T rtb_Switch_lp_idx_1;
  real_T rtb_Switch_lp_idx_2;
  real_T rtb_Switch_n0_idx_0;
  real_T rtb_Switch_n0_idx_2;

  /* Sum: '<S295>/Sum' */
  rtb_Switch_n0_idx_0 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];

  /* Math: '<S343>/Math Function' */
  rtb_MathFunction_br[0] = rtb_Switch_n0_idx_0 * rtb_Switch_n0_idx_0;

  /* Sum: '<S295>/Sum' */
  rtb_Sum_mk[0] = rtb_Switch_n0_idx_0;
  rtb_Switch_n0_idx_0 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];

  /* Math: '<S343>/Math Function' */
  rtb_MathFunction_br[1] = rtb_Switch_n0_idx_0 * rtb_Switch_n0_idx_0;

  /* Sum: '<S295>/Sum' */
  rtb_Sum_mk[1] = rtb_Switch_n0_idx_0;
  rtb_Switch_n0_idx_0 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];

  /* Sum: '<S343>/Sum of Elements' incorporates:
   *  Math: '<S343>/Math Function'
   */
  rtb_SinCos_o1 = (rtb_MathFunction_br[0] + rtb_MathFunction_br[1]) +
    rtb_Switch_n0_idx_0 * rtb_Switch_n0_idx_0;

  /* Math: '<S343>/Math Function1'
   *
   * About '<S343>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_SinCos_o1 < 0.0) {
    rtb_SinCos_o1 = -sqrt(fabs(rtb_SinCos_o1));
  } else {
    rtb_SinCos_o1 = sqrt(rtb_SinCos_o1);
  }

  /* End of Math: '<S343>/Math Function1' */

  /* Switch: '<S343>/Switch' incorporates:
   *  Constant: '<S343>/Constant'
   *  Product: '<S343>/Product'
   */
  if (rtb_SinCos_o1 > 0.0) {
    rtb_Switch_lp_idx_0 = rtb_Sum_mk[0];
    rtb_Switch_lp_idx_1 = rtb_Sum_mk[1];
    rtb_Switch_lp_idx_2 = rtb_Switch_n0_idx_0;
    rtb_Switch_lp_idx_3 = rtb_SinCos_o1;
  } else {
    rtb_Switch_lp_idx_0 = rtb_Sum_mk[0] * 0.0;
    rtb_Switch_lp_idx_1 = rtb_Sum_mk[1] * 0.0;
    rtb_Switch_lp_idx_2 = rtb_Switch_n0_idx_0 * 0.0;
    rtb_Switch_lp_idx_3 = 1.0;
  }

  /* End of Switch: '<S343>/Switch' */

  /* Gain: '<S295>/deg2rad1' */
  rtb_SinCos_o1 = 0.017453292519943295 * rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S345>/SinCos' */
  rtb_Switch_n0_idx_2 = cos(rtb_SinCos_o1);
  rtb_SinCos_o1 = sin(rtb_SinCos_o1);

  /* Gain: '<S295>/deg2rad2' */
  rtb_SinCos1_o1 = 0.017453292519943295 * rtu_targ_lon_deg;

  /* Trigonometry: '<S345>/SinCos1' */
  rtb_Sqrt_gw = cos(rtb_SinCos1_o1);
  rtb_SinCos1_o1 = sin(rtb_SinCos1_o1);

  /* Product: '<S345>/Product' incorporates:
   *  Trigonometry: '<S345>/SinCos1'
   */
  rtb_VectorConcatenate[0] = rtb_SinCos_o1 * rtb_Sqrt_gw;

  /* Gain: '<S345>/Gain1' */
  rtb_VectorConcatenate[1] = -rtb_SinCos1_o1;

  /* Product: '<S345>/Product2' incorporates:
   *  Trigonometry: '<S345>/SinCos'
   *  Trigonometry: '<S345>/SinCos1'
   */
  rtb_VectorConcatenate[2] = rtb_Switch_n0_idx_2 * rtb_Sqrt_gw;

  /* Product: '<S345>/Product1' */
  rtb_VectorConcatenate[3] = rtb_SinCos_o1 * rtb_SinCos1_o1;

  /* SignalConversion: '<S347>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S345>/SinCos1'
   */
  rtb_VectorConcatenate[4] = rtb_Sqrt_gw;

  /* Product: '<S345>/Product3' incorporates:
   *  Trigonometry: '<S345>/SinCos'
   */
  rtb_VectorConcatenate[5] = rtb_Switch_n0_idx_2 * rtb_SinCos1_o1;

  /* Gain: '<S345>/Gain' incorporates:
   *  Trigonometry: '<S345>/SinCos'
   */
  rtb_VectorConcatenate[6] = -rtb_Switch_n0_idx_2;

  /* SignalConversion: '<S347>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S345>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* SignalConversion: '<S347>/ConcatBufferAtVector ConcatenateIn9' */
  rtb_VectorConcatenate[8] = rtb_SinCos_o1;

  /* Product: '<S295>/Product' incorporates:
   *  Gain: '<S295>/Gain'
   */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_br[i] = rtb_VectorConcatenate[i + 6] * -rtb_Switch_n0_idx_0
      + (rtb_VectorConcatenate[i + 3] * -rtb_Sum_mk[1] + rtb_VectorConcatenate[i]
         * -rtb_Sum_mk[0]);
  }

  /* End of Product: '<S295>/Product' */

  /* Sum: '<S344>/Sum of Elements' incorporates:
   *  Math: '<S344>/Math Function'
   */
  rtb_Sqrt_gw = rtb_MathFunction_br[0] * rtb_MathFunction_br[0];
  rtb_Sqrt_gw += rtb_MathFunction_br[1] * rtb_MathFunction_br[1];
  rtb_Sqrt_gw += rtb_MathFunction_br[2] * rtb_MathFunction_br[2];

  /* Math: '<S344>/Math Function1'
   *
   * About '<S344>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_gw < 0.0) {
    rtb_Sqrt_gw = -sqrt(fabs(rtb_Sqrt_gw));
  } else {
    rtb_Sqrt_gw = sqrt(rtb_Sqrt_gw);
  }

  /* End of Math: '<S344>/Math Function1' */

  /* Switch: '<S344>/Switch' incorporates:
   *  Constant: '<S344>/Constant'
   *  Product: '<S344>/Product'
   */
  if (rtb_Sqrt_gw > 0.0) {
    rtb_Switch_n0_idx_0 = rtb_MathFunction_br[0];
    rtb_SinCos_o1 = rtb_MathFunction_br[1];
    rtb_Switch_n0_idx_2 = rtb_MathFunction_br[2];
    rtb_SinCos1_o1 = rtb_Sqrt_gw;
  } else {
    rtb_Switch_n0_idx_0 = rtb_MathFunction_br[0] * 0.0;
    rtb_SinCos_o1 = rtb_MathFunction_br[1] * 0.0;
    rtb_Switch_n0_idx_2 = rtb_MathFunction_br[2] * 0.0;
    rtb_SinCos1_o1 = 1.0;
  }

  /* End of Switch: '<S344>/Switch' */

  /* Product: '<S344>/Divide' */
  rtb_Sum_mk[0] = rtb_Switch_n0_idx_0 / rtb_SinCos1_o1;

  /* Product: '<S343>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_lp_idx_0 / rtb_Switch_lp_idx_3;

  /* Product: '<S344>/Divide' */
  rtb_Sum_mk[1] = rtb_SinCos_o1 / rtb_SinCos1_o1;

  /* Product: '<S343>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_lp_idx_1 / rtb_Switch_lp_idx_3;

  /* Product: '<S344>/Divide' */
  rtb_Sum_mk[2] = rtb_Switch_n0_idx_2 / rtb_SinCos1_o1;

  /* Product: '<S343>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_lp_idx_2 / rtb_Switch_lp_idx_3;

  /* Outputs for Atomic SubSystem: '<S295>/twonorm' */
  rtb_Sqrt_gw = twonorm_f(&rtb_Sum_mk[0]);

  /* End of Outputs for SubSystem: '<S295>/twonorm' */

  /* Trigonometry: '<S295>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_mk[2], rtb_Sqrt_gw);

  /* RelationalOperator: '<S342>/Compare' incorporates:
   *  Constant: '<S342>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
