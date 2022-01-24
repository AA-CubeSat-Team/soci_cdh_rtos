/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.c
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

#include "target_groundpass_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "rt_atan2d_snf.h"

/*
 * Output and update for atomic system:
 *    '<S288>/target_groundpass_lib'
 *    '<S288>/target_groundpass_lib1'
 */
void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3], DW_target_groundpass_lib *localDW,
  P_target_groundpass_lib *localP, real_T rtp_id)
{
  real_T rtb_SinCos1_o1;
  int32_T i;
  real_T rtb_Switch_c_idx_3;
  real_T rtb_Switch_c_idx_0;
  real_T rtb_Switch_c_idx_1;
  real_T rtb_Switch_c_idx_2;
  real_T rtb_Switch_c5_idx_0;

  /* Sum: '<S294>/Sum' */
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[0] - rtu_r_ecef_m[0];

  /* Math: '<S337>/Math Function' */
  localDW->MathFunction_oh[0] = rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Sum: '<S294>/Sum' */
  localDW->Sum_mr[0] = rtb_Switch_c5_idx_0;
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[1] - rtu_r_ecef_m[1];

  /* Math: '<S337>/Math Function' */
  localDW->MathFunction_oh[1] = rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Sum: '<S294>/Sum' */
  localDW->Sum_mr[1] = rtb_Switch_c5_idx_0;
  rtb_Switch_c5_idx_0 = rtu_targ_ecef_m[2] - rtu_r_ecef_m[2];

  /* Sum: '<S337>/Sum of Elements' incorporates:
   *  Math: '<S337>/Math Function'
   */
  localDW->SinCos_o1 = (localDW->MathFunction_oh[0] + localDW->MathFunction_oh[1])
    + rtb_Switch_c5_idx_0 * rtb_Switch_c5_idx_0;

  /* Math: '<S337>/Math Function1'
   *
   * About '<S337>/Math Function1':
   *  Operator: sqrt
   */
  if (localDW->SinCos_o1 < 0.0) {
    localDW->SinCos_o1 = -sqrt(fabs(localDW->SinCos_o1));
  } else {
    localDW->SinCos_o1 = sqrt(localDW->SinCos_o1);
  }

  /* End of Math: '<S337>/Math Function1' */

  /* Switch: '<S337>/Switch' incorporates:
   *  Constant: '<S337>/Constant'
   *  Product: '<S337>/Product'
   */
  if (localDW->SinCos_o1 > localP->NormalizeVector_maxzero) {
    rtb_Switch_c_idx_0 = localDW->Sum_mr[0];
    rtb_Switch_c_idx_1 = localDW->Sum_mr[1];
    rtb_Switch_c_idx_2 = rtb_Switch_c5_idx_0;
    rtb_Switch_c_idx_3 = localDW->SinCos_o1;
  } else {
    rtb_Switch_c_idx_0 = localDW->Sum_mr[0] * 0.0;
    rtb_Switch_c_idx_1 = localDW->Sum_mr[1] * 0.0;
    rtb_Switch_c_idx_2 = rtb_Switch_c5_idx_0 * 0.0;
    rtb_Switch_c_idx_3 = localP->Constant_Value;
  }

  /* End of Switch: '<S337>/Switch' */

  /* Gain: '<S294>/deg2rad1' */
  localDW->deg2rad1 = rtP.fswParams.constants.convert.DEG2RAD *
    rtu_targ_gd_lat_deg;

  /* Trigonometry: '<S339>/SinCos' */
  localDW->SinCos_o1 = sin(localDW->deg2rad1);
  localDW->deg2rad1 = cos(localDW->deg2rad1);

  /* Gain: '<S294>/deg2rad2' */
  localDW->deg2rad2 = rtP.fswParams.constants.convert.DEG2RAD * rtu_targ_lon_deg;

  /* Trigonometry: '<S339>/SinCos1' */
  rtb_SinCos1_o1 = sin(localDW->deg2rad2);
  localDW->deg2rad2 = cos(localDW->deg2rad2);

  /* Product: '<S339>/Product' */
  localDW->VectorConcatenate_b[0] = localDW->SinCos_o1 * localDW->deg2rad2;

  /* Gain: '<S339>/Gain1' */
  localDW->VectorConcatenate_b[1] = localP->Gain1_Gain * rtb_SinCos1_o1;

  /* Product: '<S339>/Product2' */
  localDW->VectorConcatenate_b[2] = localDW->deg2rad1 * localDW->deg2rad2;

  /* Product: '<S339>/Product1' */
  localDW->VectorConcatenate_b[3] = localDW->SinCos_o1 * rtb_SinCos1_o1;

  /* SignalConversion: '<S341>/ConcatBufferAtVector ConcatenateIn5' */
  localDW->VectorConcatenate_b[4] = localDW->deg2rad2;

  /* Product: '<S339>/Product3' */
  localDW->VectorConcatenate_b[5] = localDW->deg2rad1 * rtb_SinCos1_o1;

  /* Gain: '<S339>/Gain' */
  localDW->VectorConcatenate_b[6] = localP->Gain_Gain * localDW->deg2rad1;

  /* Constant: '<S339>/Constant' */
  localDW->VectorConcatenate_b[7] = localP->Constant_Value_h4;

  /* SignalConversion: '<S341>/ConcatBufferAtVector ConcatenateIn9' */
  localDW->VectorConcatenate_b[8] = localDW->SinCos_o1;

  /* Product: '<S294>/Product' incorporates:
   *  Gain: '<S294>/Gain'
   */
  for (i = 0; i < 3; i++) {
    localDW->MathFunction_oh[i] = localDW->VectorConcatenate_b[i + 6] *
      (localP->Gain_Gain_l * rtb_Switch_c5_idx_0) +
      (localDW->VectorConcatenate_b[i + 3] * (localP->Gain_Gain_l *
        localDW->Sum_mr[1]) + localP->Gain_Gain_l * localDW->Sum_mr[0] *
       localDW->VectorConcatenate_b[i]);
  }

  /* End of Product: '<S294>/Product' */

  /* Sum: '<S338>/Sum of Elements' incorporates:
   *  Math: '<S338>/Math Function'
   */
  localDW->deg2rad2 = localDW->MathFunction_oh[0] * localDW->MathFunction_oh[0];
  localDW->deg2rad2 += localDW->MathFunction_oh[1] * localDW->MathFunction_oh[1];
  localDW->deg2rad2 += localDW->MathFunction_oh[2] * localDW->MathFunction_oh[2];

  /* Math: '<S338>/Math Function1'
   *
   * About '<S338>/Math Function1':
   *  Operator: sqrt
   */
  if (localDW->deg2rad2 < 0.0) {
    localDW->deg2rad2 = -sqrt(fabs(localDW->deg2rad2));
  } else {
    localDW->deg2rad2 = sqrt(localDW->deg2rad2);
  }

  /* End of Math: '<S338>/Math Function1' */

  /* Switch: '<S338>/Switch' incorporates:
   *  Constant: '<S338>/Constant'
   *  Product: '<S338>/Product'
   */
  if (localDW->deg2rad2 > localP->NormalizeVector1_maxzero) {
    rtb_Switch_c5_idx_0 = localDW->MathFunction_oh[0];
    localDW->SinCos_o1 = localDW->MathFunction_oh[1];
    localDW->deg2rad1 = localDW->MathFunction_oh[2];
    rtb_SinCos1_o1 = localDW->deg2rad2;
  } else {
    rtb_Switch_c5_idx_0 = localDW->MathFunction_oh[0] * 0.0;
    localDW->SinCos_o1 = localDW->MathFunction_oh[1] * 0.0;
    localDW->deg2rad1 = localDW->MathFunction_oh[2] * 0.0;
    rtb_SinCos1_o1 = localP->Constant_Value_h;
  }

  /* End of Switch: '<S338>/Switch' */

  /* Product: '<S338>/Divide' */
  localDW->Sum_mr[0] = rtb_Switch_c5_idx_0 / rtb_SinCos1_o1;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[0] = rtb_Switch_c_idx_0 / rtb_Switch_c_idx_3;

  /* Product: '<S338>/Divide' */
  localDW->Sum_mr[1] = localDW->SinCos_o1 / rtb_SinCos1_o1;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[1] = rtb_Switch_c_idx_1 / rtb_Switch_c_idx_3;

  /* Product: '<S338>/Divide' */
  localDW->Sum_mr[2] = localDW->deg2rad1 / rtb_SinCos1_o1;

  /* Product: '<S337>/Divide' */
  rty_sc2target_ecef_unit[2] = rtb_Switch_c_idx_2 / rtb_Switch_c_idx_3;

  /* Outputs for Atomic SubSystem: '<S294>/twonorm' */
  localDW->deg2rad2 = twonorm_f(&localDW->Sum_mr[0]);

  /* End of Outputs for SubSystem: '<S294>/twonorm' */

  /* Trigonometry: '<S294>/Atan2' */
  *rty_elev_sez_rad = rt_atan2d_snf(localDW->Sum_mr[2], localDW->deg2rad2);

  /* RelationalOperator: '<S336>/Compare' incorporates:
   *  Constant: '<S336>/Constant'
   */
  *rty_sc_above_target = (*rty_elev_sez_rad >= rtP.fswParams.ground_targs
    [(int32_T)rtp_id - 1].min_elev_rad);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
