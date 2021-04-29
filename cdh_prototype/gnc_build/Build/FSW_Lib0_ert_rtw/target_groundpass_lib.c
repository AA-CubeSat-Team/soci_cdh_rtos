/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
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

#include "target_groundpass_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "rt_atan2d_snf.h"

/* Output and update for atomic system: '<S261>/target_groundpass_lib' */
void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad,
  real_T rty_sc2target_ecef_unit[3], const ConstB_target_groundpass_lib *localC)
{
  real_T rtb_Sum_k5[3];
  real_T rtb_MathFunction_p[3];
  real_T rtb_Sqrt;
  int32_T i;
  real_T rtb_Switch_e_idx_3;
  real_T rtb_Switch_fd_idx_3;
  real_T rtb_Switch_e_idx_0;
  real_T rtb_Switch_e_idx_1;
  real_T rtb_Switch_e_idx_2;
  real_T rtb_Switch_fd_idx_0;
  real_T rtb_Switch_fd_idx_1;
  real_T rtb_Switch_fd_idx_2;

  /* Sum: '<S267>/Sum' */
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[0] - rtu_targ_ecef_m[0];

  /* Math: '<S310>/Math Function' */
  rtb_MathFunction_p[0] = rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Sum: '<S267>/Sum' */
  rtb_Sum_k5[0] = rtb_Switch_fd_idx_0;
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[1] - rtu_targ_ecef_m[1];

  /* Math: '<S310>/Math Function' */
  rtb_MathFunction_p[1] = rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Sum: '<S267>/Sum' */
  rtb_Sum_k5[1] = rtb_Switch_fd_idx_0;
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[2] - rtu_targ_ecef_m[2];

  /* Sum: '<S310>/Sum of Elements' incorporates:
   *  Math: '<S310>/Math Function'
   */
  rtb_Sqrt = rtb_MathFunction_p[0];
  rtb_Sqrt += rtb_MathFunction_p[1];
  rtb_Sqrt += rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Math: '<S310>/Math Function1'
   *
   * About '<S310>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt < 0.0) {
    rtb_Sqrt = -sqrt(fabs(rtb_Sqrt));
  } else {
    rtb_Sqrt = sqrt(rtb_Sqrt);
  }

  /* End of Math: '<S310>/Math Function1' */

  /* Switch: '<S310>/Switch' incorporates:
   *  Constant: '<S310>/Constant'
   *  Product: '<S310>/Product'
   */
  if (rtb_Sqrt > 0.0) {
    rtb_Switch_e_idx_0 = rtb_Sum_k5[0];
    rtb_Switch_e_idx_1 = rtb_Sum_k5[1];
    rtb_Switch_e_idx_2 = rtb_Switch_fd_idx_0;
    rtb_Switch_e_idx_3 = rtb_Sqrt;
  } else {
    rtb_Switch_e_idx_0 = rtb_Sum_k5[0] * 0.0;
    rtb_Switch_e_idx_1 = rtb_Sum_k5[1] * 0.0;
    rtb_Switch_e_idx_2 = rtb_Switch_fd_idx_0 * 0.0;
    rtb_Switch_e_idx_3 = 1.0;
  }

  /* End of Switch: '<S310>/Switch' */

  /* Product: '<S267>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_p[i] = localC->VectorConcatenate[i + 6] *
      rtb_Switch_fd_idx_0 + (localC->VectorConcatenate[i + 3] * rtb_Sum_k5[1] +
      localC->VectorConcatenate[i] * rtb_Sum_k5[0]);
  }

  /* End of Product: '<S267>/Product' */

  /* Sum: '<S311>/Sum of Elements' incorporates:
   *  Math: '<S311>/Math Function'
   */
  rtb_Sqrt = rtb_MathFunction_p[0] * rtb_MathFunction_p[0];
  rtb_Sqrt += rtb_MathFunction_p[1] * rtb_MathFunction_p[1];
  rtb_Sqrt += rtb_MathFunction_p[2] * rtb_MathFunction_p[2];

  /* Math: '<S311>/Math Function1'
   *
   * About '<S311>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt < 0.0) {
    rtb_Sqrt = -sqrt(fabs(rtb_Sqrt));
  } else {
    rtb_Sqrt = sqrt(rtb_Sqrt);
  }

  /* End of Math: '<S311>/Math Function1' */

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S311>/Constant'
   *  Product: '<S311>/Product'
   */
  if (rtb_Sqrt > 0.0) {
    rtb_Switch_fd_idx_0 = rtb_MathFunction_p[0];
    rtb_Switch_fd_idx_1 = rtb_MathFunction_p[1];
    rtb_Switch_fd_idx_2 = rtb_MathFunction_p[2];
    rtb_Switch_fd_idx_3 = rtb_Sqrt;
  } else {
    rtb_Switch_fd_idx_0 = rtb_MathFunction_p[0] * 0.0;
    rtb_Switch_fd_idx_1 = rtb_MathFunction_p[1] * 0.0;
    rtb_Switch_fd_idx_2 = rtb_MathFunction_p[2] * 0.0;
    rtb_Switch_fd_idx_3 = 1.0;
  }

  /* End of Switch: '<S311>/Switch' */

  /* Product: '<S311>/Divide' */
  rtb_Sum_k5[0] = rtb_Switch_fd_idx_0 / rtb_Switch_fd_idx_3;

  /* Product: '<S310>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_e_idx_0 / rtb_Switch_e_idx_3;

  /* Product: '<S311>/Divide' */
  rtb_Sum_k5[1] = rtb_Switch_fd_idx_1 / rtb_Switch_fd_idx_3;

  /* Product: '<S310>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_e_idx_1 / rtb_Switch_e_idx_3;

  /* Product: '<S311>/Divide' */
  rtb_Sum_k5[2] = rtb_Switch_fd_idx_2 / rtb_Switch_fd_idx_3;

  /* Product: '<S310>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_e_idx_2 / rtb_Switch_e_idx_3;

  /* Outputs for Atomic SubSystem: '<S267>/twonorm' */
  rtb_Sqrt = twonorm_h(&rtb_Sum_k5[0]);

  /* End of Outputs for SubSystem: '<S267>/twonorm' */

  /* Trigonometry: '<S267>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_k5[2], rtb_Sqrt);

  /* RelationalOperator: '<S309>/Compare' incorporates:
   *  Constant: '<S309>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/* Output and update for atomic system: '<S261>/target_groundpass_lib1' */
void target_groundpass_lib1(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3])
{
  real_T rtb_Sum_l[3];
  real_T rtb_MathFunction_a[3];
  real_T rtb_SinCos_o1;
  real_T rtb_SinCos1_o1;
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt;
  int32_T i;
  real_T rtb_Switch_j_idx_3;
  real_T rtb_Switch_j_idx_0;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_k_idx_0;
  real_T rtb_Switch_k_idx_2;

  /* Sum: '<S268>/Sum' */
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[0] - rtu_targ_ecef_m[0];

  /* Math: '<S316>/Math Function' */
  rtb_MathFunction_a[0] = rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Sum: '<S268>/Sum' */
  rtb_Sum_l[0] = rtb_Switch_k_idx_0;
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[1] - rtu_targ_ecef_m[1];

  /* Math: '<S316>/Math Function' */
  rtb_MathFunction_a[1] = rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Sum: '<S268>/Sum' */
  rtb_Sum_l[1] = rtb_Switch_k_idx_0;
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[2] - rtu_targ_ecef_m[2];

  /* Sum: '<S316>/Sum of Elements' incorporates:
   *  Math: '<S316>/Math Function'
   */
  rtb_SinCos_o1 = (rtb_MathFunction_a[0] + rtb_MathFunction_a[1]) +
    rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Math: '<S316>/Math Function1'
   *
   * About '<S316>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_SinCos_o1 < 0.0) {
    rtb_SinCos_o1 = -sqrt(fabs(rtb_SinCos_o1));
  } else {
    rtb_SinCos_o1 = sqrt(rtb_SinCos_o1);
  }

  /* End of Math: '<S316>/Math Function1' */

  /* Switch: '<S316>/Switch' incorporates:
   *  Constant: '<S316>/Constant'
   *  Product: '<S316>/Product'
   */
  if (rtb_SinCos_o1 > 0.0) {
    rtb_Switch_j_idx_0 = rtb_Sum_l[0];
    rtb_Switch_j_idx_1 = rtb_Sum_l[1];
    rtb_Switch_j_idx_2 = rtb_Switch_k_idx_0;
    rtb_Switch_j_idx_3 = rtb_SinCos_o1;
  } else {
    rtb_Switch_j_idx_0 = rtb_Sum_l[0] * 0.0;
    rtb_Switch_j_idx_1 = rtb_Sum_l[1] * 0.0;
    rtb_Switch_j_idx_2 = rtb_Switch_k_idx_0 * 0.0;
    rtb_Switch_j_idx_3 = 1.0;
  }

  /* End of Switch: '<S316>/Switch' */

  /* Gain: '<S268>/deg2rad1' */
  rtb_SinCos_o1 = 0.017453292519943295 * rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S318>/SinCos' */
  rtb_Switch_k_idx_2 = cos(rtb_SinCos_o1);
  rtb_SinCos_o1 = sin(rtb_SinCos_o1);

  /* Gain: '<S268>/deg2rad2' */
  rtb_SinCos1_o1 = 0.017453292519943295 * rtu_targ_lon_deg;

  /* Trigonometry: '<S318>/SinCos1' */
  rtb_Sqrt = cos(rtb_SinCos1_o1);
  rtb_SinCos1_o1 = sin(rtb_SinCos1_o1);

  /* Product: '<S318>/Product' incorporates:
   *  Trigonometry: '<S318>/SinCos1'
   */
  rtb_VectorConcatenate[0] = rtb_SinCos_o1 * rtb_Sqrt;

  /* Gain: '<S318>/Gain1' */
  rtb_VectorConcatenate[1] = -rtb_SinCos1_o1;

  /* Product: '<S318>/Product2' incorporates:
   *  Trigonometry: '<S318>/SinCos'
   *  Trigonometry: '<S318>/SinCos1'
   */
  rtb_VectorConcatenate[2] = rtb_Switch_k_idx_2 * rtb_Sqrt;

  /* Product: '<S318>/Product1' */
  rtb_VectorConcatenate[3] = rtb_SinCos_o1 * rtb_SinCos1_o1;

  /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S318>/SinCos1'
   */
  rtb_VectorConcatenate[4] = rtb_Sqrt;

  /* Product: '<S318>/Product3' incorporates:
   *  Trigonometry: '<S318>/SinCos'
   */
  rtb_VectorConcatenate[5] = rtb_Switch_k_idx_2 * rtb_SinCos1_o1;

  /* Gain: '<S318>/Gain' incorporates:
   *  Trigonometry: '<S318>/SinCos'
   */
  rtb_VectorConcatenate[6] = -rtb_Switch_k_idx_2;

  /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S318>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn9' */
  rtb_VectorConcatenate[8] = rtb_SinCos_o1;

  /* Product: '<S268>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_a[i] = rtb_VectorConcatenate[i + 6] * rtb_Switch_k_idx_0 +
      (rtb_VectorConcatenate[i + 3] * rtb_Sum_l[1] + rtb_VectorConcatenate[i] *
       rtb_Sum_l[0]);
  }

  /* End of Product: '<S268>/Product' */

  /* Sum: '<S317>/Sum of Elements' incorporates:
   *  Math: '<S317>/Math Function'
   */
  rtb_Sqrt = rtb_MathFunction_a[0] * rtb_MathFunction_a[0];
  rtb_Sqrt += rtb_MathFunction_a[1] * rtb_MathFunction_a[1];
  rtb_Sqrt += rtb_MathFunction_a[2] * rtb_MathFunction_a[2];

  /* Math: '<S317>/Math Function1'
   *
   * About '<S317>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt < 0.0) {
    rtb_Sqrt = -sqrt(fabs(rtb_Sqrt));
  } else {
    rtb_Sqrt = sqrt(rtb_Sqrt);
  }

  /* End of Math: '<S317>/Math Function1' */

  /* Switch: '<S317>/Switch' incorporates:
   *  Constant: '<S317>/Constant'
   *  Product: '<S317>/Product'
   */
  if (rtb_Sqrt > 0.0) {
    rtb_Switch_k_idx_0 = rtb_MathFunction_a[0];
    rtb_SinCos_o1 = rtb_MathFunction_a[1];
    rtb_Switch_k_idx_2 = rtb_MathFunction_a[2];
    rtb_SinCos1_o1 = rtb_Sqrt;
  } else {
    rtb_Switch_k_idx_0 = rtb_MathFunction_a[0] * 0.0;
    rtb_SinCos_o1 = rtb_MathFunction_a[1] * 0.0;
    rtb_Switch_k_idx_2 = rtb_MathFunction_a[2] * 0.0;
    rtb_SinCos1_o1 = 1.0;
  }

  /* End of Switch: '<S317>/Switch' */

  /* Product: '<S317>/Divide' */
  rtb_Sum_l[0] = rtb_Switch_k_idx_0 / rtb_SinCos1_o1;

  /* Product: '<S316>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_j_idx_0 / rtb_Switch_j_idx_3;

  /* Product: '<S317>/Divide' */
  rtb_Sum_l[1] = rtb_SinCos_o1 / rtb_SinCos1_o1;

  /* Product: '<S316>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_j_idx_1 / rtb_Switch_j_idx_3;

  /* Product: '<S317>/Divide' */
  rtb_Sum_l[2] = rtb_Switch_k_idx_2 / rtb_SinCos1_o1;

  /* Product: '<S316>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_j_idx_2 / rtb_Switch_j_idx_3;

  /* Outputs for Atomic SubSystem: '<S268>/twonorm' */
  rtb_Sqrt = twonorm_h(&rtb_Sum_l[0]);

  /* End of Outputs for SubSystem: '<S268>/twonorm' */

  /* Trigonometry: '<S268>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_l[2], rtb_Sqrt);

  /* RelationalOperator: '<S315>/Compare' incorporates:
   *  Constant: '<S315>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
