/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
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

/* Output and update for atomic system: '<S169>/target_groundpass_lib' */
void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad,
  real_T rty_sc2target_ecef_unit[3], const ConstB_target_groundpass_lib *localC)
{
  real_T rtb_Sum_k5[3];
  real_T rtb_MathFunction_p[3];
  real_T rtb_Sqrt_n4;
  int32_T i;
  real_T rtb_Switch_e_idx_3;
  real_T rtb_Switch_fd_idx_3;
  real_T rtb_Switch_e_idx_0;
  real_T rtb_Switch_e_idx_1;
  real_T rtb_Switch_e_idx_2;
  real_T rtb_Switch_fd_idx_0;
  real_T rtb_Switch_fd_idx_1;
  real_T rtb_Switch_fd_idx_2;

  /* Sum: '<S175>/Sum' */
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[0] - rtu_targ_ecef_m[0];

  /* Math: '<S218>/Math Function' */
  rtb_MathFunction_p[0] = rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Sum: '<S175>/Sum' */
  rtb_Sum_k5[0] = rtb_Switch_fd_idx_0;
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[1] - rtu_targ_ecef_m[1];

  /* Math: '<S218>/Math Function' */
  rtb_MathFunction_p[1] = rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Sum: '<S175>/Sum' */
  rtb_Sum_k5[1] = rtb_Switch_fd_idx_0;
  rtb_Switch_fd_idx_0 = rtu_r_ecef_m[2] - rtu_targ_ecef_m[2];

  /* Sum: '<S218>/Sum of Elements' incorporates:
   *  Math: '<S218>/Math Function'
   */
  rtb_Sqrt_n4 = rtb_MathFunction_p[0];
  rtb_Sqrt_n4 += rtb_MathFunction_p[1];
  rtb_Sqrt_n4 += rtb_Switch_fd_idx_0 * rtb_Switch_fd_idx_0;

  /* Math: '<S218>/Math Function1'
   *
   * About '<S218>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_n4 < 0.0) {
    rtb_Sqrt_n4 = -sqrt(fabs(rtb_Sqrt_n4));
  } else {
    rtb_Sqrt_n4 = sqrt(rtb_Sqrt_n4);
  }

  /* End of Math: '<S218>/Math Function1' */

  /* Switch: '<S218>/Switch' incorporates:
   *  Constant: '<S218>/Constant'
   *  Product: '<S218>/Product'
   */
  if (rtb_Sqrt_n4 > 0.0) {
    rtb_Switch_e_idx_0 = rtb_Sum_k5[0];
    rtb_Switch_e_idx_1 = rtb_Sum_k5[1];
    rtb_Switch_e_idx_2 = rtb_Switch_fd_idx_0;
    rtb_Switch_e_idx_3 = rtb_Sqrt_n4;
  } else {
    rtb_Switch_e_idx_0 = rtb_Sum_k5[0] * 0.0;
    rtb_Switch_e_idx_1 = rtb_Sum_k5[1] * 0.0;
    rtb_Switch_e_idx_2 = rtb_Switch_fd_idx_0 * 0.0;
    rtb_Switch_e_idx_3 = 1.0;
  }

  /* End of Switch: '<S218>/Switch' */

  /* Product: '<S175>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_p[i] = localC->VectorConcatenate[i + 6] *
      rtb_Switch_fd_idx_0 + (localC->VectorConcatenate[i + 3] * rtb_Sum_k5[1] +
      localC->VectorConcatenate[i] * rtb_Sum_k5[0]);
  }

  /* End of Product: '<S175>/Product' */

  /* Sum: '<S219>/Sum of Elements' incorporates:
   *  Math: '<S219>/Math Function'
   */
  rtb_Sqrt_n4 = rtb_MathFunction_p[0] * rtb_MathFunction_p[0];
  rtb_Sqrt_n4 += rtb_MathFunction_p[1] * rtb_MathFunction_p[1];
  rtb_Sqrt_n4 += rtb_MathFunction_p[2] * rtb_MathFunction_p[2];

  /* Math: '<S219>/Math Function1'
   *
   * About '<S219>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_n4 < 0.0) {
    rtb_Sqrt_n4 = -sqrt(fabs(rtb_Sqrt_n4));
  } else {
    rtb_Sqrt_n4 = sqrt(rtb_Sqrt_n4);
  }

  /* End of Math: '<S219>/Math Function1' */

  /* Switch: '<S219>/Switch' incorporates:
   *  Constant: '<S219>/Constant'
   *  Product: '<S219>/Product'
   */
  if (rtb_Sqrt_n4 > 0.0) {
    rtb_Switch_fd_idx_0 = rtb_MathFunction_p[0];
    rtb_Switch_fd_idx_1 = rtb_MathFunction_p[1];
    rtb_Switch_fd_idx_2 = rtb_MathFunction_p[2];
    rtb_Switch_fd_idx_3 = rtb_Sqrt_n4;
  } else {
    rtb_Switch_fd_idx_0 = rtb_MathFunction_p[0] * 0.0;
    rtb_Switch_fd_idx_1 = rtb_MathFunction_p[1] * 0.0;
    rtb_Switch_fd_idx_2 = rtb_MathFunction_p[2] * 0.0;
    rtb_Switch_fd_idx_3 = 1.0;
  }

  /* End of Switch: '<S219>/Switch' */

  /* Product: '<S219>/Divide' */
  rtb_Sum_k5[0] = rtb_Switch_fd_idx_0 / rtb_Switch_fd_idx_3;

  /* Product: '<S218>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_e_idx_0 / rtb_Switch_e_idx_3;

  /* Product: '<S219>/Divide' */
  rtb_Sum_k5[1] = rtb_Switch_fd_idx_1 / rtb_Switch_fd_idx_3;

  /* Product: '<S218>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_e_idx_1 / rtb_Switch_e_idx_3;

  /* Product: '<S219>/Divide' */
  rtb_Sum_k5[2] = rtb_Switch_fd_idx_2 / rtb_Switch_fd_idx_3;

  /* Product: '<S218>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_e_idx_2 / rtb_Switch_e_idx_3;

  /* Outputs for Atomic SubSystem: '<S175>/twonorm' */
  rtb_Sqrt_n4 = twonorm(&rtb_Sum_k5[0]);

  /* End of Outputs for SubSystem: '<S175>/twonorm' */

  /* Trigonometry: '<S175>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_k5[2], rtb_Sqrt_n4);

  /* RelationalOperator: '<S217>/Compare' incorporates:
   *  Constant: '<S217>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/* Output and update for atomic system: '<S169>/target_groundpass_lib1' */
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
  real_T rtb_Sqrt_d;
  int32_T i;
  real_T rtb_Switch_j_idx_3;
  real_T rtb_Switch_j_idx_0;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_k_idx_0;
  real_T rtb_Switch_k_idx_2;

  /* Sum: '<S176>/Sum' */
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[0] - rtu_targ_ecef_m[0];

  /* Math: '<S224>/Math Function' */
  rtb_MathFunction_a[0] = rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Sum: '<S176>/Sum' */
  rtb_Sum_l[0] = rtb_Switch_k_idx_0;
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[1] - rtu_targ_ecef_m[1];

  /* Math: '<S224>/Math Function' */
  rtb_MathFunction_a[1] = rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Sum: '<S176>/Sum' */
  rtb_Sum_l[1] = rtb_Switch_k_idx_0;
  rtb_Switch_k_idx_0 = rtu_r_ecef_m[2] - rtu_targ_ecef_m[2];

  /* Sum: '<S224>/Sum of Elements' incorporates:
   *  Math: '<S224>/Math Function'
   */
  rtb_SinCos_o1 = (rtb_MathFunction_a[0] + rtb_MathFunction_a[1]) +
    rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;

  /* Math: '<S224>/Math Function1'
   *
   * About '<S224>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_SinCos_o1 < 0.0) {
    rtb_SinCos_o1 = -sqrt(fabs(rtb_SinCos_o1));
  } else {
    rtb_SinCos_o1 = sqrt(rtb_SinCos_o1);
  }

  /* End of Math: '<S224>/Math Function1' */

  /* Switch: '<S224>/Switch' incorporates:
   *  Constant: '<S224>/Constant'
   *  Product: '<S224>/Product'
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

  /* End of Switch: '<S224>/Switch' */

  /* Gain: '<S176>/deg2rad1' */
  rtb_SinCos_o1 = 0.017453292519943295 * rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S226>/SinCos' */
  rtb_Switch_k_idx_2 = cos(rtb_SinCos_o1);
  rtb_SinCos_o1 = sin(rtb_SinCos_o1);

  /* Gain: '<S176>/deg2rad2' */
  rtb_SinCos1_o1 = 0.017453292519943295 * rtu_targ_lon_deg;

  /* Trigonometry: '<S226>/SinCos1' */
  rtb_Sqrt_d = cos(rtb_SinCos1_o1);
  rtb_SinCos1_o1 = sin(rtb_SinCos1_o1);

  /* Product: '<S226>/Product' incorporates:
   *  Trigonometry: '<S226>/SinCos1'
   */
  rtb_VectorConcatenate[0] = rtb_SinCos_o1 * rtb_Sqrt_d;

  /* Gain: '<S226>/Gain1' */
  rtb_VectorConcatenate[1] = -rtb_SinCos1_o1;

  /* Product: '<S226>/Product2' incorporates:
   *  Trigonometry: '<S226>/SinCos'
   *  Trigonometry: '<S226>/SinCos1'
   */
  rtb_VectorConcatenate[2] = rtb_Switch_k_idx_2 * rtb_Sqrt_d;

  /* Product: '<S226>/Product1' */
  rtb_VectorConcatenate[3] = rtb_SinCos_o1 * rtb_SinCos1_o1;

  /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S226>/SinCos1'
   */
  rtb_VectorConcatenate[4] = rtb_Sqrt_d;

  /* Product: '<S226>/Product3' incorporates:
   *  Trigonometry: '<S226>/SinCos'
   */
  rtb_VectorConcatenate[5] = rtb_Switch_k_idx_2 * rtb_SinCos1_o1;

  /* Gain: '<S226>/Gain' incorporates:
   *  Trigonometry: '<S226>/SinCos'
   */
  rtb_VectorConcatenate[6] = -rtb_Switch_k_idx_2;

  /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S226>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn9' */
  rtb_VectorConcatenate[8] = rtb_SinCos_o1;

  /* Product: '<S176>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_a[i] = rtb_VectorConcatenate[i + 6] * rtb_Switch_k_idx_0 +
      (rtb_VectorConcatenate[i + 3] * rtb_Sum_l[1] + rtb_VectorConcatenate[i] *
       rtb_Sum_l[0]);
  }

  /* End of Product: '<S176>/Product' */

  /* Sum: '<S225>/Sum of Elements' incorporates:
   *  Math: '<S225>/Math Function'
   */
  rtb_Sqrt_d = rtb_MathFunction_a[0] * rtb_MathFunction_a[0];
  rtb_Sqrt_d += rtb_MathFunction_a[1] * rtb_MathFunction_a[1];
  rtb_Sqrt_d += rtb_MathFunction_a[2] * rtb_MathFunction_a[2];

  /* Math: '<S225>/Math Function1'
   *
   * About '<S225>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sqrt_d < 0.0) {
    rtb_Sqrt_d = -sqrt(fabs(rtb_Sqrt_d));
  } else {
    rtb_Sqrt_d = sqrt(rtb_Sqrt_d);
  }

  /* End of Math: '<S225>/Math Function1' */

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Constant'
   *  Product: '<S225>/Product'
   */
  if (rtb_Sqrt_d > 0.0) {
    rtb_Switch_k_idx_0 = rtb_MathFunction_a[0];
    rtb_SinCos_o1 = rtb_MathFunction_a[1];
    rtb_Switch_k_idx_2 = rtb_MathFunction_a[2];
    rtb_SinCos1_o1 = rtb_Sqrt_d;
  } else {
    rtb_Switch_k_idx_0 = rtb_MathFunction_a[0] * 0.0;
    rtb_SinCos_o1 = rtb_MathFunction_a[1] * 0.0;
    rtb_Switch_k_idx_2 = rtb_MathFunction_a[2] * 0.0;
    rtb_SinCos1_o1 = 1.0;
  }

  /* End of Switch: '<S225>/Switch' */

  /* Product: '<S225>/Divide' */
  rtb_Sum_l[0] = rtb_Switch_k_idx_0 / rtb_SinCos1_o1;

  /* Product: '<S224>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_j_idx_0 / rtb_Switch_j_idx_3;

  /* Product: '<S225>/Divide' */
  rtb_Sum_l[1] = rtb_SinCos_o1 / rtb_SinCos1_o1;

  /* Product: '<S224>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_j_idx_1 / rtb_Switch_j_idx_3;

  /* Product: '<S225>/Divide' */
  rtb_Sum_l[2] = rtb_Switch_k_idx_2 / rtb_SinCos1_o1;

  /* Product: '<S224>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_j_idx_2 / rtb_Switch_j_idx_3;

  /* Outputs for Atomic SubSystem: '<S176>/twonorm' */
  rtb_Sqrt_d = twonorm(&rtb_Sum_l[0]);

  /* End of Outputs for SubSystem: '<S176>/twonorm' */

  /* Trigonometry: '<S176>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(rtb_Sum_l[2], rtb_Sqrt_d);

  /* RelationalOperator: '<S223>/Compare' incorporates:
   *  Constant: '<S223>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= 0.17453292519943295);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
