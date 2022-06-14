/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
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

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "mrdiv_01FAo0m2.h"
#include "qr_MDOP2S80.h"
#include "qr_v7LIxcTX.h"
#include "rt_powd_snf.h"

/* System initialize for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW)
{
  dsp_simulink_MovingAverage *obj;
  g_dsp_private_SlidingWindowAver *obj_0;
  int32_T i;

  /* Start for S-Function (sdspeye): '<S165>/Id_3' */
  memset(&localDW->Id_3[0], 0, 9U * sizeof(real_T));

  /* Fill in 1's on the diagonal. */
  localDW->Id_3[0] = 1.0;
  localDW->Id_3[4] = 1.0;
  localDW->Id_3[8] = 1.0;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0], &rtCP_UnitDelay_InitialConditi_e[0], 36U
         * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  TRIADActivation_lib_Init(&localDW->TRIADActivation_lib_f);

  /* End of SystemInitialize for SubSystem: '<S3>/TRIADActivation_lib' */

  /* SystemInitialize for Merge: '<S3>/q_p_merge' */
  rty_sc_quat[0] = 0.0;
  rty_sc_quat[1] = 0.0;
  rty_sc_quat[2] = 0.0;
  rty_sc_quat[3] = 0.0;

  /* Start for MATLABSystem: '<S121>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  obj->_pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &obj->_pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
  obj_0 = localDW->obj.pStatistic;
  if (obj_0->isInitialized == 1) {
    obj_0->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj_0->pCumSumRev[i] = 0.0;
    }

    obj_0->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
}

/* Output and update for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib(const real_T rtu_sc2sun_eci_unit[3], const real_T rtu_mag_eci_T[3],
              const real_T rtu_sun_meas_body_unit[3], const real_T
              rtu_mag_meas_body_T[3], const real_T rtu_gyro_meas_body_radps[3],
              uint8_T rtu_sunsensor_valid, boolean_T rtu_mag_meas_valid,
              boolean_T rtu_gryo_meas_valid, boolean_T rtu_triad_activate,
              real_T rty_sc_quat[4], real_T rty_body_rates_radps[3], real_T
              rty_threeSigma_rad[6], real_T rty_bias_radps[3], uint8_T
              *rty_mekf_telem, DW_MEKF_lib *localDW)
{
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  g_dsp_private_SlidingWindowAver *obj;
  real_T R[144];
  real_T tmp[144];
  real_T unusedU2[144];
  real_T K_0[72];
  real_T R2[72];
  real_T K[36];
  real_T rtb_P_chol_p_merge[36];
  real_T rtb_Phi[36];
  real_T rtb_Gain6_0[18];
  real_T rtb_MatrixConcatenate2_l[16];
  real_T rtb_Gain6[12];
  real_T rtb_MathFunction1[9];
  real_T rtb_MatrixConcatenate2[9];
  real_T rtb_MatrixConcatenate3[9];
  real_T rtb_Product3_j[6];
  real_T rtu_sun_meas_body_unit_0[6];
  real_T rtu_sun_meas_body_unit_1[6];
  real_T rtb_Merge_k[4];
  real_T rtb_TmpSignalConversionAtquat_a[4];
  real_T rtb_MathFunction_k[3];
  real_T rtb_MathFunction_m[3];
  real_T rtb_Add_h_tmp;
  real_T rtb_Add_h_tmp_0;
  real_T rtb_Add_h_tmp_1;
  real_T rtb_Elementproduct_g_idx_2;
  real_T rtb_Elementproduct_g_idx_5;
  real_T rtb_Product1_f_tmp;
  real_T rtb_Product1_h;
  real_T rtb_Product3_bh;
  real_T rtb_Product3_e;
  real_T rtb_Product3_j_tmp;
  real_T rtb_Product3_j_tmp_0;
  real_T rtb_Product3_j_tmp_1;
  real_T rtb_Product5;
  real_T rtb_Sum_bq;
  int32_T aoffset;
  int32_T i;
  int32_T idxStart;
  int32_T rtb_Phi_tmp;
  int32_T rtb_Phi_tmp_0;
  int32_T tmp_0;
  int8_T Phi_22[9];
  int8_T b_I[9];
  int8_T rtAction;
  uint8_T rtb_Sum_mx;
  boolean_T rtb_Compare_e;
  boolean_T rtb_Switch_f1;
  boolean_T rtb_Switch_hl;
  boolean_T rtb_Switch_p;

  /* RelationalOperator: '<S117>/Compare' incorporates:
   *  Constant: '<S117>/Constant'
   */
  rtb_Compare_e = (rtu_sunsensor_valid != 0);

  /* Outputs for Atomic SubSystem: '<S115>/parallel_protection_lib' */
  rtb_Switch_p = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, 1.0);

  /* End of Outputs for SubSystem: '<S115>/parallel_protection_lib' */

  /* Sum: '<S115>/Sum' incorporates:
   *  Logic: '<S115>/AND'
   */
  rtb_Sum_mx = (uint8_T)((uint32_T)(rtb_Compare_e && rtu_mag_meas_valid &&
    rtu_gryo_meas_valid) + rtb_Switch_p);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_p = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtb_Compare_e, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_f);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S127>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_p) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Sum: '<S175>/Sum of Elements' incorporates:
     *  Math: '<S175>/Math Function'
     */
    rtb_Product3_e = (rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0] +
                      rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1]) +
      rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Math: '<S175>/Math Function1'
     *
     * About '<S175>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_e < 0.0) {
      rtb_Product3_e = -sqrt(fabs(rtb_Product3_e));
    } else {
      rtb_Product3_e = sqrt(rtb_Product3_e);
    }

    /* End of Math: '<S175>/Math Function1' */

    /* Switch: '<S175>/Switch' incorporates:
     *  Constant: '<S175>/Constant'
     *  Product: '<S175>/Product'
     */
    if (rtb_Product3_e > 0.0) {
      rtb_Merge_k[0] = rtu_mag_meas_body_T[0];
      rtb_Merge_k[1] = rtu_mag_meas_body_T[1];
      rtb_Merge_k[2] = rtu_mag_meas_body_T[2];
      rtb_Merge_k[3] = rtb_Product3_e;
    } else {
      rtb_Merge_k[0] = rtu_mag_meas_body_T[0] * 0.0;
      rtb_Merge_k[1] = rtu_mag_meas_body_T[1] * 0.0;
      rtb_Merge_k[2] = rtu_mag_meas_body_T[2] * 0.0;
      rtb_Merge_k[3] = 1.0;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Product: '<S175>/Divide' */
    rtb_MathFunction_k[0] = rtb_Merge_k[0] / rtb_Merge_k[3];
    rtb_MathFunction_k[1] = rtb_Merge_k[1] / rtb_Merge_k[3];
    rtb_MathFunction_k[2] = rtb_Merge_k[2] / rtb_Merge_k[3];

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib' */
    rtb_Switch_hl = parallel_protection_lib(rtu_sun_meas_body_unit,
      rtb_MathFunction_k, 1.0);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib' */

    /* Sum: '<S174>/Sum of Elements' incorporates:
     *  Math: '<S174>/Math Function'
     */
    rtb_Product3_e = (rtu_mag_eci_T[0] * rtu_mag_eci_T[0] + rtu_mag_eci_T[1] *
                      rtu_mag_eci_T[1]) + rtu_mag_eci_T[2] * rtu_mag_eci_T[2];

    /* Math: '<S174>/Math Function1'
     *
     * About '<S174>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_e < 0.0) {
      rtb_Product3_e = -sqrt(fabs(rtb_Product3_e));
    } else {
      rtb_Product3_e = sqrt(rtb_Product3_e);
    }

    /* End of Math: '<S174>/Math Function1' */

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  Product: '<S174>/Product'
     */
    if (rtb_Product3_e > 0.0) {
      rtb_Merge_k[0] = rtu_mag_eci_T[0];
      rtb_Merge_k[1] = rtu_mag_eci_T[1];
      rtb_Merge_k[2] = rtu_mag_eci_T[2];
      rtb_Merge_k[3] = rtb_Product3_e;
    } else {
      rtb_Merge_k[0] = rtu_mag_eci_T[0] * 0.0;
      rtb_Merge_k[1] = rtu_mag_eci_T[1] * 0.0;
      rtb_Merge_k[2] = rtu_mag_eci_T[2] * 0.0;
      rtb_Merge_k[3] = 1.0;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Product: '<S174>/Divide' */
    rtb_MathFunction_m[0] = rtb_Merge_k[0] / rtb_Merge_k[3];
    rtb_MathFunction_m[1] = rtb_Merge_k[1] / rtb_Merge_k[3];
    rtb_MathFunction_m[2] = rtb_Merge_k[2] / rtb_Merge_k[3];

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib1' */
    rtb_Switch_f1 = parallel_protection_lib(rtu_sc2sun_eci_unit,
      rtb_MathFunction_m, 1.0);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib1' */

    /* If: '<S125>/If' incorporates:
     *  Inport: '<S178>/quat_old'
     *  Logic: '<S125>/Logical Operator'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    if (rtb_Compare_e && rtu_mag_meas_valid && rtb_Switch_hl && rtb_Switch_f1) {
      /* Outputs for IfAction SubSystem: '<S125>/TriadAlgorithm' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* Product: '<S184>/Element product' */
      rtb_Product3_e = rtu_sun_meas_body_unit[2] * rtb_MathFunction_k[0];
      rtb_Elementproduct_g_idx_2 = rtu_sun_meas_body_unit[0] *
        rtb_MathFunction_k[1];
      rtb_Elementproduct_g_idx_5 = rtu_sun_meas_body_unit[1] *
        rtb_MathFunction_k[0];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[0] = rtu_sun_meas_body_unit[0];

      /* Sum: '<S184>/Add3' incorporates:
       *  Product: '<S184>/Element product'
       */
      rtb_MathFunction_k[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_k[2]
        - rtu_sun_meas_body_unit[2] * rtb_MathFunction_k[1];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[1] = rtu_sun_meas_body_unit[1];

      /* Sum: '<S184>/Add3' incorporates:
       *  Product: '<S184>/Element product'
       */
      rtb_MathFunction_k[1] = rtb_Product3_e - rtu_sun_meas_body_unit[0] *
        rtb_MathFunction_k[2];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[2] = rtu_sun_meas_body_unit[2];

      /* Sum: '<S184>/Add3' */
      rtb_MathFunction_k[2] = rtb_Elementproduct_g_idx_2 -
        rtb_Elementproduct_g_idx_5;

      /* S-Function (sdsp2norm2): '<S177>/Normalization6' */
      rtb_Product3_e = 1.0 / (sqrt((rtb_MathFunction_k[0] * rtb_MathFunction_k[0]
        + rtb_MathFunction_k[1] * rtb_MathFunction_k[1]) + rtb_MathFunction_k[2]
        * rtb_MathFunction_k[2]) + 1.0E-10);
      rtb_MathFunction_k[0] *= rtb_Product3_e;
      rtb_MathFunction_k[1] *= rtb_Product3_e;
      rtb_MathFunction_k[2] *= rtb_Product3_e;

      /* Product: '<S186>/Element product' */
      rtb_Product3_e = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m[0];
      rtb_Elementproduct_g_idx_2 = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m[1];
      rtb_Elementproduct_g_idx_5 = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m[0];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[3] = rtb_MathFunction_k[0];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];

      /* Sum: '<S186>/Add3' incorporates:
       *  Product: '<S186>/Element product'
       */
      rtb_MathFunction_m[0] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m[2] -
        rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m[1];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[4] = rtb_MathFunction_k[1];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];

      /* Sum: '<S186>/Add3' incorporates:
       *  Product: '<S186>/Element product'
       */
      rtb_MathFunction_m[1] = rtb_Product3_e - rtu_sc2sun_eci_unit[0] *
        rtb_MathFunction_m[2];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate2' */
      rtb_MatrixConcatenate2[5] = rtb_MathFunction_k[2];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Sum: '<S186>/Add3' */
      rtb_MathFunction_m[2] = rtb_Elementproduct_g_idx_2 -
        rtb_Elementproduct_g_idx_5;

      /* S-Function (sdsp2norm2): '<S177>/Normalization7' */
      rtb_Product3_e = 1.0 / (sqrt((rtb_MathFunction_m[0] * rtb_MathFunction_m[0]
        + rtb_MathFunction_m[1] * rtb_MathFunction_m[1]) + rtb_MathFunction_m[2]
        * rtb_MathFunction_m[2]) + 1.0E-10);
      rtb_MathFunction_m[0] *= rtb_Product3_e;
      rtb_MathFunction_m[1] *= rtb_Product3_e;
      rtb_MathFunction_m[2] *= rtb_Product3_e;

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[3] = rtb_MathFunction_m[0];

      /* Sum: '<S185>/Add3' incorporates:
       *  Product: '<S185>/Element product'
       */
      rtb_MatrixConcatenate2[6] = rtu_sun_meas_body_unit[1] *
        rtb_MathFunction_k[2] - rtu_sun_meas_body_unit[2] * rtb_MathFunction_k[1];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[4] = rtb_MathFunction_m[1];

      /* Sum: '<S185>/Add3' incorporates:
       *  Product: '<S185>/Element product'
       */
      rtb_MatrixConcatenate2[7] = rtu_sun_meas_body_unit[2] *
        rtb_MathFunction_k[0] - rtu_sun_meas_body_unit[0] * rtb_MathFunction_k[2];

      /* SignalConversion generated from: '<S177>/Matrix Concatenate3' */
      rtb_MatrixConcatenate3[5] = rtb_MathFunction_m[2];

      /* Sum: '<S185>/Add3' incorporates:
       *  Product: '<S185>/Element product'
       */
      rtb_MatrixConcatenate2[8] = rtu_sun_meas_body_unit[0] *
        rtb_MathFunction_k[1] - rtu_sun_meas_body_unit[1] * rtb_MathFunction_k[0];

      /* Sum: '<S187>/Add3' incorporates:
       *  Product: '<S187>/Element product'
       */
      rtb_MatrixConcatenate3[6] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m[2]
        - rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m[1];
      rtb_MatrixConcatenate3[7] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m[0]
        - rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m[2];
      rtb_MatrixConcatenate3[8] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m[1]
        - rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m[0];

      /* Product: '<S177>/Matrix Multiply1' incorporates:
       *  Concatenate: '<S177>/Matrix Concatenate2'
       *  Concatenate: '<S177>/Matrix Concatenate3'
       *  Math: '<S177>/Math Function1'
       */
      for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 3; rtb_Phi_tmp++) {
        for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 3; rtb_Phi_tmp_0++) {
          i = rtb_Phi_tmp + 3 * rtb_Phi_tmp_0;
          rtb_MathFunction1[i] = 0.0;
          rtb_MathFunction1[i] += rtb_MatrixConcatenate2[rtb_Phi_tmp] *
            rtb_MatrixConcatenate3[rtb_Phi_tmp_0];
          rtb_MathFunction1[i] += rtb_MatrixConcatenate2[rtb_Phi_tmp + 3] *
            rtb_MatrixConcatenate3[rtb_Phi_tmp_0 + 3];
          rtb_MathFunction1[i] += rtb_MatrixConcatenate2[rtb_Phi_tmp + 6] *
            rtb_MatrixConcatenate3[rtb_Phi_tmp_0 + 6];
        }
      }

      /* End of Product: '<S177>/Matrix Multiply1' */

      /* Sum: '<S192>/Add' */
      rtb_Elementproduct_g_idx_5 = (rtb_MathFunction1[0] + rtb_MathFunction1[4])
        + rtb_MathFunction1[8];

      /* If: '<S188>/If' */
      if (rtb_Elementproduct_g_idx_5 > 0.0) {
        /* Outputs for IfAction SubSystem: '<S188>/Positive Trace' incorporates:
         *  ActionPort: '<S190>/Action Port'
         */
        PositiveTrace(rtb_Elementproduct_g_idx_5, rtb_MathFunction1,
                      &localDW->Merge[0], &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S188>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S188>/Negative Trace' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        NegativeTrace(rtb_MathFunction1, localDW->Merge);

        /* End of Outputs for SubSystem: '<S188>/Negative Trace' */
      }

      /* End of If: '<S188>/If' */

      /* Signum: '<S177>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        rtb_Product3_e = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        rtb_Product3_e = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        rtb_Product3_e = 0.0;
      } else {
        rtb_Product3_e = (rtNaN);
      }

      /* End of Signum: '<S177>/Sign' */

      /* Product: '<S177>/Multiply' */
      rtb_Merge_k[0] = rtb_Product3_e * localDW->Merge[0];
      rtb_Merge_k[1] = rtb_Product3_e * localDW->Merge[1];
      rtb_Merge_k[2] = rtb_Product3_e * localDW->Merge[2];
      rtb_Merge_k[3] = rtb_Product3_e * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S125>/TriadAlgorithm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S125>/TriadBypass' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      rtb_Merge_k[0] = localDW->UnitDelay_DSTATE_g[0];
      rtb_Merge_k[1] = localDW->UnitDelay_DSTATE_g[1];
      rtb_Merge_k[2] = localDW->UnitDelay_DSTATE_g[2];
      rtb_Merge_k[3] = localDW->UnitDelay_DSTATE_g[3];

      /* End of Outputs for SubSystem: '<S125>/TriadBypass' */
    }

    /* End of If: '<S125>/If' */

    /* Sqrt: '<S182>/sqrt' incorporates:
     *  Product: '<S183>/Product'
     *  Product: '<S183>/Product1'
     *  Product: '<S183>/Product2'
     *  Product: '<S183>/Product3'
     *  Sum: '<S183>/Sum'
     */
    rtb_Product3_e = sqrt(((rtb_Merge_k[0] * rtb_Merge_k[0] + rtb_Merge_k[1] *
      rtb_Merge_k[1]) + rtb_Merge_k[2] * rtb_Merge_k[2]) + rtb_Merge_k[3] *
                          rtb_Merge_k[3]);

    /* SignalConversion generated from: '<S125>/quat_rectify_lib' incorporates:
     *  Product: '<S176>/Product'
     *  Product: '<S176>/Product1'
     *  Product: '<S176>/Product2'
     *  Product: '<S176>/Product3'
     */
    rtb_TmpSignalConversionAtquat_a[0] = rtb_Merge_k[0] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[1] = rtb_Merge_k[1] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[2] = rtb_Merge_k[2] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[3] = rtb_Merge_k[3] / rtb_Product3_e;

    /* Outputs for Atomic SubSystem: '<S125>/quat_rectify_lib' */
    quat_rectify_lib(rtb_TmpSignalConversionAtquat_a, rtb_Merge_k);

    /* End of Outputs for SubSystem: '<S125>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/TriadEstimator_lib' */
  } else {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    rtb_Merge_k[0] = localDW->UnitDelay3_DSTATE[0];
    rtb_Merge_k[1] = localDW->UnitDelay3_DSTATE[1];
    rtb_Merge_k[2] = localDW->UnitDelay3_DSTATE[2];
    rtb_Merge_k[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S116>/If Action Subsystem' */
  }

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S114>/P_chol_m'
   *  Inport: '<S114>/bias_m'
   *  Inport: '<S114>/q_m'
   *  Merge: '<S3>/P_chol_p_merge'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_mx > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Sqrt: '<S148>/sqrt' incorporates:
     *  Product: '<S149>/Product'
     *  Product: '<S149>/Product1'
     *  Product: '<S149>/Product2'
     *  Product: '<S149>/Product3'
     *  Sqrt: '<S154>/sqrt'
     *  Sum: '<S149>/Sum'
     */
    rtb_Sum_bq = sqrt(((rtb_Merge_k[0] * rtb_Merge_k[0] + rtb_Merge_k[1] *
                        rtb_Merge_k[1]) + rtb_Merge_k[2] * rtb_Merge_k[2]) +
                      rtb_Merge_k[3] * rtb_Merge_k[3]);

    /* Product: '<S144>/Product2' incorporates:
     *  Product: '<S150>/Product2'
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product5 = rtb_Merge_k[2] / rtb_Sum_bq;

    /* Product: '<S144>/Product3' incorporates:
     *  Product: '<S150>/Product3'
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product1_f_tmp = rtb_Merge_k[3] / rtb_Sum_bq;

    /* Product: '<S144>/Product1' incorporates:
     *  Product: '<S150>/Product1'
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Elementproduct_g_idx_2 = rtb_Merge_k[1] / rtb_Sum_bq;

    /* Product: '<S144>/Product' incorporates:
     *  Product: '<S150>/Product'
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product1_h = rtb_Merge_k[0] / rtb_Sum_bq;

    /* Product: '<S145>/Product7' incorporates:
     *  Product: '<S144>/Product3'
     *  Product: '<S146>/Product7'
     */
    rtb_Elementproduct_g_idx_5 = rtb_Product1_f_tmp * rtb_Product1_f_tmp;

    /* Product: '<S145>/Product' incorporates:
     *  Product: '<S144>/Product1'
     *  Product: '<S144>/Product2'
     *  Product: '<S146>/Product'
     */
    rtb_Product3_j_tmp = rtb_Elementproduct_g_idx_2 * rtb_Product5;

    /* Product: '<S145>/Product1' incorporates:
     *  Product: '<S144>/Product'
     *  Product: '<S144>/Product3'
     *  Product: '<S146>/Product1'
     */
    rtb_Product3_j_tmp_0 = rtb_Product1_h * rtb_Product1_f_tmp;

    /* Product: '<S145>/Product3' incorporates:
     *  Product: '<S144>/Product1'
     *  Product: '<S144>/Product3'
     *  Product: '<S147>/Product'
     */
    rtb_Sum_bq = rtb_Elementproduct_g_idx_2 * rtb_Product1_f_tmp;

    /* Product: '<S145>/Product2' incorporates:
     *  Product: '<S144>/Product'
     *  Product: '<S144>/Product2'
     *  Product: '<S147>/Product1'
     */
    rtb_Product3_bh = rtb_Product1_h * rtb_Product5;

    /* Product: '<S145>/Product6' incorporates:
     *  Product: '<S144>/Product2'
     *  Product: '<S147>/Product7'
     */
    rtb_Product3_j_tmp_1 = rtb_Product5 * rtb_Product5;

    /* Sum: '<S145>/Sum' incorporates:
     *  Constant: '<S145>/Constant'
     *  Gain: '<S145>/Gain'
     *  Gain: '<S145>/Gain1'
     *  Gain: '<S145>/Gain2'
     *  Product: '<S145>/Product'
     *  Product: '<S145>/Product1'
     *  Product: '<S145>/Product2'
     *  Product: '<S145>/Product3'
     *  Product: '<S145>/Product4'
     *  Product: '<S145>/Product5'
     *  Product: '<S145>/Product6'
     *  Product: '<S145>/Product7'
     *  Product: '<S145>/Product8'
     *  Sum: '<S145>/Sum1'
     *  Sum: '<S145>/Sum2'
     *  Sum: '<S145>/Sum3'
     */
    rtb_Product3_e = (((0.5 - rtb_Product3_j_tmp_1) - rtb_Elementproduct_g_idx_5)
                      * 2.0 * rtu_sc2sun_eci_unit[0] + (rtb_Product3_j_tmp +
      rtb_Product3_j_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[1]) + (rtb_Sum_bq -
      rtb_Product3_bh) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Product: '<S146>/Product3' incorporates:
     *  Product: '<S144>/Product2'
     *  Product: '<S144>/Product3'
     *  Product: '<S147>/Product3'
     */
    rtb_Add_h_tmp = rtb_Product5 * rtb_Product1_f_tmp;

    /* Product: '<S146>/Product2' incorporates:
     *  Product: '<S144>/Product'
     *  Product: '<S144>/Product1'
     *  Product: '<S147>/Product2'
     */
    rtb_Add_h_tmp_0 = rtb_Product1_h * rtb_Elementproduct_g_idx_2;

    /* Sum: '<S146>/Sum3' incorporates:
     *  Constant: '<S146>/Constant'
     *  Product: '<S144>/Product1'
     *  Product: '<S146>/Product6'
     *  Sum: '<S147>/Sum3'
     */
    rtb_Add_h_tmp_1 = 0.5 - rtb_Elementproduct_g_idx_2 *
      rtb_Elementproduct_g_idx_2;

    /* Sum: '<S146>/Sum' incorporates:
     *  Gain: '<S146>/Gain'
     *  Gain: '<S146>/Gain1'
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Product2'
     *  Product: '<S146>/Product3'
     *  Product: '<S146>/Product4'
     *  Product: '<S146>/Product5'
     *  Product: '<S146>/Product8'
     *  Sum: '<S146>/Sum1'
     *  Sum: '<S146>/Sum2'
     *  Sum: '<S146>/Sum3'
     */
    rtb_Elementproduct_g_idx_5 = ((rtb_Add_h_tmp_1 - rtb_Elementproduct_g_idx_5)
      * 2.0 * rtu_sc2sun_eci_unit[1] + (rtb_Product3_j_tmp -
      rtb_Product3_j_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[0]) + (rtb_Add_h_tmp_0 +
      rtb_Add_h_tmp) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Sum: '<S147>/Sum' incorporates:
     *  Gain: '<S147>/Gain'
     *  Gain: '<S147>/Gain1'
     *  Gain: '<S147>/Gain2'
     *  Product: '<S147>/Product4'
     *  Product: '<S147>/Product5'
     *  Product: '<S147>/Product8'
     *  Sum: '<S147>/Sum1'
     *  Sum: '<S147>/Sum2'
     *  Sum: '<S147>/Sum3'
     */
    rtb_Product3_bh = ((rtb_Sum_bq + rtb_Product3_bh) * 2.0 *
                       rtu_sc2sun_eci_unit[0] + (rtb_Add_h_tmp - rtb_Add_h_tmp_0)
                       * 2.0 * rtu_sc2sun_eci_unit[1]) + (rtb_Add_h_tmp_1 -
      rtb_Product3_j_tmp_1) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Product: '<S151>/Product7' incorporates:
     *  Product: '<S152>/Product7'
     */
    rtb_Add_h_tmp_1 = rtb_Product1_f_tmp * rtb_Product1_f_tmp;

    /* Product: '<S151>/Product' incorporates:
     *  Product: '<S152>/Product'
     */
    rtb_Product3_j_tmp = rtb_Elementproduct_g_idx_2 * rtb_Product5;

    /* Product: '<S151>/Product1' incorporates:
     *  Product: '<S152>/Product1'
     */
    rtb_Product3_j_tmp_0 = rtb_Product1_h * rtb_Product1_f_tmp;

    /* Product: '<S151>/Product3' incorporates:
     *  Product: '<S153>/Product'
     */
    rtb_Product3_j_tmp_1 = rtb_Elementproduct_g_idx_2 * rtb_Product1_f_tmp;

    /* Product: '<S151>/Product2' incorporates:
     *  Product: '<S153>/Product1'
     */
    rtb_Add_h_tmp = rtb_Product1_h * rtb_Product5;

    /* Product: '<S151>/Product6' incorporates:
     *  Product: '<S153>/Product7'
     */
    rtb_Add_h_tmp_0 = rtb_Product5 * rtb_Product5;

    /* Sum: '<S151>/Sum' incorporates:
     *  Constant: '<S151>/Constant'
     *  Gain: '<S151>/Gain'
     *  Gain: '<S151>/Gain1'
     *  Gain: '<S151>/Gain2'
     *  Product: '<S151>/Product'
     *  Product: '<S151>/Product1'
     *  Product: '<S151>/Product2'
     *  Product: '<S151>/Product3'
     *  Product: '<S151>/Product4'
     *  Product: '<S151>/Product5'
     *  Product: '<S151>/Product6'
     *  Product: '<S151>/Product7'
     *  Product: '<S151>/Product8'
     *  Sum: '<S151>/Sum1'
     *  Sum: '<S151>/Sum2'
     *  Sum: '<S151>/Sum3'
     */
    rtb_Sum_bq = (((0.5 - rtb_Add_h_tmp_0) - rtb_Add_h_tmp_1) * 2.0 *
                  rtu_mag_eci_T[0] + (rtb_Product3_j_tmp + rtb_Product3_j_tmp_0)
                  * 2.0 * rtu_mag_eci_T[1]) + (rtb_Product3_j_tmp_1 -
      rtb_Add_h_tmp) * 2.0 * rtu_mag_eci_T[2];

    /* Product: '<S152>/Product3' incorporates:
     *  Product: '<S153>/Product3'
     */
    rtb_Product1_f_tmp *= rtb_Product5;

    /* Product: '<S152>/Product2' incorporates:
     *  Product: '<S153>/Product2'
     */
    rtb_Product1_h *= rtb_Elementproduct_g_idx_2;

    /* Sum: '<S152>/Sum3' incorporates:
     *  Constant: '<S152>/Constant'
     *  Product: '<S152>/Product6'
     *  Sum: '<S153>/Sum3'
     */
    rtb_Elementproduct_g_idx_2 = 0.5 - rtb_Elementproduct_g_idx_2 *
      rtb_Elementproduct_g_idx_2;

    /* Sum: '<S152>/Sum' incorporates:
     *  Gain: '<S152>/Gain'
     *  Gain: '<S152>/Gain1'
     *  Gain: '<S152>/Gain2'
     *  Product: '<S152>/Product2'
     *  Product: '<S152>/Product3'
     *  Product: '<S152>/Product4'
     *  Product: '<S152>/Product5'
     *  Product: '<S152>/Product8'
     *  Sum: '<S152>/Sum1'
     *  Sum: '<S152>/Sum2'
     *  Sum: '<S152>/Sum3'
     */
    rtb_Product5 = ((rtb_Elementproduct_g_idx_2 - rtb_Add_h_tmp_1) * 2.0 *
                    rtu_mag_eci_T[1] + (rtb_Product3_j_tmp -
      rtb_Product3_j_tmp_0) * 2.0 * rtu_mag_eci_T[0]) + (rtb_Product1_h +
      rtb_Product1_f_tmp) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S153>/Sum' incorporates:
     *  Gain: '<S153>/Gain'
     *  Gain: '<S153>/Gain1'
     *  Gain: '<S153>/Gain2'
     *  Product: '<S153>/Product4'
     *  Product: '<S153>/Product5'
     *  Product: '<S153>/Product8'
     *  Sum: '<S153>/Sum1'
     *  Sum: '<S153>/Sum2'
     *  Sum: '<S153>/Sum3'
     */
    rtb_Elementproduct_g_idx_2 = ((rtb_Product3_j_tmp_1 + rtb_Add_h_tmp) * 2.0 *
      rtu_mag_eci_T[0] + (rtb_Product1_f_tmp - rtb_Product1_h) * 2.0 *
      rtu_mag_eci_T[1]) + (rtb_Elementproduct_g_idx_2 - rtb_Add_h_tmp_0) * 2.0 *
      rtu_mag_eci_T[2];

    /* SignalConversion generated from: '<S132>/Vertical Matrix Concatenate' */
    memset(&rtb_P_chol_p_merge[18], 0, 18U * sizeof(real_T));

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Product3_bh, rtb_Product3_e,
                        rtb_Elementproduct_g_idx_5, &rtb_Gain6[0]);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib' */

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Elementproduct_g_idx_2, rtb_Sum_bq, rtb_Product5,
                        rtb_MatrixConcatenate2);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S132>/Horizontal Matrix Concatenate' incorporates:
     *  Product: '<S119>/Product1'
     */
    memcpy(&rtb_MatrixConcatenate3[0], &rtb_Gain6[0], 9U * sizeof(real_T));
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 3; rtb_Phi_tmp++) {
      rtb_Gain6_0[6 * rtb_Phi_tmp] = rtb_MatrixConcatenate3[3 * rtb_Phi_tmp];
      rtb_Gain6_0[6 * rtb_Phi_tmp + 3] = rtb_MatrixConcatenate2[3 * rtb_Phi_tmp];
      i = 3 * rtb_Phi_tmp + 1;
      rtb_Gain6_0[6 * rtb_Phi_tmp + 1] = rtb_MatrixConcatenate3[i];
      rtb_Gain6_0[6 * rtb_Phi_tmp + 4] = rtb_MatrixConcatenate2[i];
      i = 3 * rtb_Phi_tmp + 2;
      rtb_Gain6_0[6 * rtb_Phi_tmp + 2] = rtb_MatrixConcatenate3[i];
      rtb_Gain6_0[6 * rtb_Phi_tmp + 5] = rtb_MatrixConcatenate2[i];
    }

    memcpy(&rtb_P_chol_p_merge[0], &rtb_Gain6_0[0], 18U * sizeof(real_T));

    /* End of Concatenate: '<S132>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S119>/QR_factorization' incorporates:
     *  Concatenate: '<S132>/Vertical Matrix Concatenate'
     *  Constant: '<S119>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
      idxStart = rtb_Phi_tmp * 6;
      for (i = 0; i < 6; i++) {
        aoffset = i * 6;
        rtb_Product1_h = 0.0;
        for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
          rtb_Product1_h += rtb_P_chol_p_merge[rtb_Phi_tmp_0 * 6 + rtb_Phi_tmp] *
            localDW->UnitDelay_DSTATE[aoffset + rtb_Phi_tmp_0];
        }

        K[idxStart + i] = rtb_Product1_h;
        rtb_Phi_tmp_0 = i + 12 * rtb_Phi_tmp;
        aoffset = 6 * i + rtb_Phi_tmp;
        tmp[rtb_Phi_tmp_0] = rtCP_Constant_Value_gj[aoffset];
        tmp_0 = i + 12 * (rtb_Phi_tmp + 6);
        tmp[tmp_0] = 0.0;
        tmp[rtb_Phi_tmp_0 + 6] = K[6 * rtb_Phi_tmp + i];
        tmp[tmp_0 + 6] = localDW->UnitDelay_DSTATE[aoffset];
      }
    }

    qr_v7LIxcTX(tmp, unusedU2, R);
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
      for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
        i = rtb_Phi_tmp_0 + 6 * rtb_Phi_tmp;
        rtb_P_chol_p_merge[i] = R[(rtb_Phi_tmp_0 + 6) * 12 + rtb_Phi_tmp];
        rtb_Phi[i] = R[12 * rtb_Phi_tmp_0 + rtb_Phi_tmp];
      }
    }

    mrdiv_01FAo0m2(rtb_P_chol_p_merge, rtb_Phi, K);
    if (!rtu_gryo_meas_valid) {
      for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
        K[6 * rtb_Phi_tmp + 3] = 0.0;
        K[6 * rtb_Phi_tmp + 4] = 0.0;
        K[6 * rtb_Phi_tmp + 5] = 0.0;
      }
    }

    /* Gain: '<S137>/Gain' */
    rtb_Gain6[0] = -rtb_Merge_k[1];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[1] = rtb_Merge_k[0];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[2] = rtb_Merge_k[3];

    /* Gain: '<S137>/Gain1' */
    rtb_Gain6[3] = -rtb_Merge_k[2];

    /* Gain: '<S137>/Gain2' */
    rtb_Gain6[4] = -rtb_Merge_k[2];

    /* Gain: '<S137>/Gain3' */
    rtb_Gain6[5] = -rtb_Merge_k[3];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[6] = rtb_Merge_k[0];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[7] = rtb_Merge_k[1];

    /* Gain: '<S137>/Gain4' */
    rtb_Gain6[8] = -rtb_Merge_k[3];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[9] = rtb_Merge_k[2];

    /* Gain: '<S137>/Gain5' */
    rtb_Gain6[10] = -rtb_Merge_k[1];

    /* SignalConversion generated from: '<S137>/Vector Concatenate' */
    rtb_Gain6[11] = rtb_Merge_k[0];

    /* Sum: '<S119>/CreateMeasResidual' */
    rtu_sun_meas_body_unit_0[0] = rtu_sun_meas_body_unit[0];
    rtu_sun_meas_body_unit_0[3] = rtu_mag_meas_body_T[0];
    rtu_sun_meas_body_unit_0[1] = rtu_sun_meas_body_unit[1];
    rtu_sun_meas_body_unit_0[4] = rtu_mag_meas_body_T[1];
    rtu_sun_meas_body_unit_0[2] = rtu_sun_meas_body_unit[2];
    rtu_sun_meas_body_unit_0[5] = rtu_mag_meas_body_T[2];
    rtb_Product3_j[0] = rtb_Product3_e;
    rtb_Product3_j[1] = rtb_Elementproduct_g_idx_5;
    rtb_Product3_j[2] = rtb_Product3_bh;
    rtb_Product3_j[3] = rtb_Sum_bq;
    rtb_Product3_j[4] = rtb_Product5;
    rtb_Product3_j[5] = rtb_Elementproduct_g_idx_2;
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
      /* SignalConversion generated from: '<S119>/P_chol_plus' incorporates:
       *  MATLAB Function: '<S119>/QR_factorization'
       *  Merge: '<S3>/P_chol_p_merge'
       */
      for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
        rtb_P_chol_p_merge[rtb_Phi_tmp_0 + 6 * rtb_Phi_tmp] = R[((rtb_Phi_tmp_0
          + 6) * 12 + rtb_Phi_tmp) + 6];
      }

      /* Sum: '<S119>/CreateMeasResidual' */
      rtu_sun_meas_body_unit_1[rtb_Phi_tmp] =
        rtu_sun_meas_body_unit_0[rtb_Phi_tmp] - rtb_Product3_j[rtb_Phi_tmp];
    }

    /* Product: '<S119>/Product1' incorporates:
     *  MATLAB Function: '<S119>/QR_factorization'
     */
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
      rtb_MatrixConcatenate2[rtb_Phi_tmp] = 0.0;
      for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
        rtb_MatrixConcatenate2[rtb_Phi_tmp] += K[6 * rtb_Phi_tmp_0 + rtb_Phi_tmp]
          * rtu_sun_meas_body_unit_1[rtb_Phi_tmp_0];
      }
    }

    /* End of Product: '<S119>/Product1' */

    /* Sum: '<S119>/Sum' incorporates:
     *  Concatenate: '<S137>/Vector Concatenate'
     *  Gain: '<S137>/Gain6'
     *  Product: '<S119>/Product'
     */
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 4; rtb_Phi_tmp++) {
      rtb_TmpSignalConversionAtquat_a[rtb_Phi_tmp] = ((rtb_Gain6[rtb_Phi_tmp + 4]
        * 0.5 * rtb_MatrixConcatenate2[1] + 0.5 * rtb_Gain6[rtb_Phi_tmp] *
        rtb_MatrixConcatenate2[0]) + rtb_Gain6[rtb_Phi_tmp + 8] * 0.5 *
        rtb_MatrixConcatenate2[2]) + rtb_Merge_k[rtb_Phi_tmp];
    }

    /* End of Sum: '<S119>/Sum' */

    /* Sqrt: '<S142>/sqrt' incorporates:
     *  Product: '<S143>/Product'
     *  Product: '<S143>/Product1'
     *  Product: '<S143>/Product2'
     *  Product: '<S143>/Product3'
     *  Sum: '<S143>/Sum'
     */
    rtb_Product3_e = sqrt(((rtb_TmpSignalConversionAtquat_a[0] *
      rtb_TmpSignalConversionAtquat_a[0] + rtb_TmpSignalConversionAtquat_a[1] *
      rtb_TmpSignalConversionAtquat_a[1]) + rtb_TmpSignalConversionAtquat_a[2] *
      rtb_TmpSignalConversionAtquat_a[2]) + rtb_TmpSignalConversionAtquat_a[3] *
                          rtb_TmpSignalConversionAtquat_a[3]);

    /* Product: '<S134>/Product' */
    rty_sc_quat[0] = rtb_TmpSignalConversionAtquat_a[0] / rtb_Product3_e;

    /* Product: '<S134>/Product1' */
    rty_sc_quat[1] = rtb_TmpSignalConversionAtquat_a[1] / rtb_Product3_e;

    /* Product: '<S134>/Product2' */
    rty_sc_quat[2] = rtb_TmpSignalConversionAtquat_a[2] / rtb_Product3_e;

    /* Product: '<S134>/Product3' */
    rty_sc_quat[3] = rtb_TmpSignalConversionAtquat_a[3] / rtb_Product3_e;

    /* Sum: '<S119>/UpdatingBetaBias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_Product3_e = rtb_MatrixConcatenate2[3] + localDW->UnitDelay1_DSTATE[0];

    /* Saturate: '<S119>/Saturation' */
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[0] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[0] = -0.01745;
    } else {
      rty_bias_radps[0] = rtb_Product3_e;
    }

    /* Sum: '<S119>/UpdatingBetaBias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_Product3_e = rtb_MatrixConcatenate2[4] + localDW->UnitDelay1_DSTATE[1];

    /* Saturate: '<S119>/Saturation' */
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[1] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[1] = -0.01745;
    } else {
      rty_bias_radps[1] = rtb_Product3_e;
    }

    /* Sum: '<S119>/UpdatingBetaBias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_Product3_e = rtb_MatrixConcatenate2[5] + localDW->UnitDelay1_DSTATE[2];

    /* Saturate: '<S119>/Saturation' */
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[2] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[2] = -0.01745;
    } else {
      rty_bias_radps[2] = rtb_Product3_e;
    }

    /* End of Outputs for SubSystem: '<S3>/MeasurementUpdate' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/BypassMeasUpdate' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    memcpy(&rtb_P_chol_p_merge[0], &localDW->UnitDelay_DSTATE[0], 36U * sizeof
           (real_T));
    rty_bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = localDW->UnitDelay1_DSTATE[2];
    rty_sc_quat[0] = rtb_Merge_k[0];
    rty_sc_quat[1] = rtb_Merge_k[1];
    rty_sc_quat[2] = rtb_Merge_k[2];
    rty_sc_quat[3] = rtb_Merge_k[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S118>/If' incorporates:
   *  Constant: '<S128>/Constant'
   *  Inport: '<S130>/mekf_mode'
   *  RelationalOperator: '<S128>/Compare'
   */
  if (rtb_Switch_p) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* SignalConversion generated from: '<S129>/mekf_triad' incorporates:
     *  Constant: '<S129>/Constant'
     */
    *rty_mekf_telem = 3U;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem' */
  } else if (rtb_Sum_mx < 2) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_mx;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    /* SignalConversion generated from: '<S131>/mekf_nom' incorporates:
     *  Constant: '<S131>/cnst'
     */
    *rty_mekf_telem = 0U;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem2' */
  }

  /* End of If: '<S118>/If' */

  /* Switch: '<S3>/NullRatesIfGyroInvalid ' */
  if (rtu_gryo_meas_valid) {
    rtb_MathFunction_k[0] = rtu_gyro_meas_body_radps[0];
    rtb_MathFunction_k[1] = rtu_gyro_meas_body_radps[1];
    rtb_MathFunction_k[2] = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_MathFunction_k[0] = 0.0;
    rtb_MathFunction_k[1] = 0.0;
    rtb_MathFunction_k[2] = 0.0;
  }

  /* End of Switch: '<S3>/NullRatesIfGyroInvalid ' */

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   */
  rtb_Compare_e = (rtb_Sum_mx == 2);

  /* RelationalOperator: '<S157>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Switch_p = ((int32_T)rtb_Compare_e > (int32_T)localDW->DelayInput1_DSTATE);

  /* Sum: '<S124>/Sum' */
  rty_body_rates_radps[0] = rtb_MathFunction_k[0] - rty_bias_radps[0];
  rty_body_rates_radps[1] = rtb_MathFunction_k[1] - rty_bias_radps[1];
  rty_body_rates_radps[2] = rtb_MathFunction_k[2] - rty_bias_radps[2];

  /* Math: '<S124>/Transpose' */
  rtb_MathFunction_k[0] = rty_body_rates_radps[0];
  rtb_MathFunction_k[1] = rty_body_rates_radps[1];
  rtb_MathFunction_k[2] = rty_body_rates_radps[2];

  /* Product: '<S124>/Matrix Multiply' */
  rtb_MathFunction_m[0] = rty_body_rates_radps[0];
  rtb_MathFunction_m[1] = rty_body_rates_radps[1];
  rtb_MathFunction_m[2] = rty_body_rates_radps[2];

  /* Sqrt: '<S124>/Sqrt' incorporates:
   *  Math: '<S124>/Transpose'
   *  Product: '<S124>/Matrix Multiply'
   */
  rtb_Product3_e = sqrt((rtb_MathFunction_k[0] * rtb_MathFunction_m[0] +
    rtb_MathFunction_k[1] * rtb_MathFunction_m[1]) + rtb_MathFunction_k[2] *
                        rtb_MathFunction_m[2]);

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_m(rty_body_rates_radps, rtb_MatrixConcatenate2);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S124>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S124>/Constant'
   *  Reshape: '<S169>/Reshape (9) to [3x3] column-major'
   */
  if (rtb_Product3_e < 1.0E-10) {
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 9; rtb_Phi_tmp++) {
      b_I[rtb_Phi_tmp] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 9; rtb_Phi_tmp++) {
      Phi_22[rtb_Phi_tmp] = 0;
    }

    for (i = 0; i < 3; i++) {
      Phi_22[i + 3 * i] = 1;
      rtb_Phi[6 * i] = b_I[3 * i];
      rtb_Phi_tmp_0 = 6 * (i + 3);
      rtb_Phi[rtb_Phi_tmp_0] = (real_T)a[3 * i] * 0.25;
      rtb_Phi[6 * i + 3] = 0.0;
      rtb_Phi_tmp = 3 * i + 1;
      rtb_Phi[6 * i + 1] = b_I[rtb_Phi_tmp];
      rtb_Phi[rtb_Phi_tmp_0 + 1] = (real_T)a[rtb_Phi_tmp] * 0.25;
      rtb_Phi[6 * i + 4] = 0.0;
      idxStart = 3 * i + 2;
      rtb_Phi[6 * i + 2] = b_I[idxStart];
      rtb_Phi[rtb_Phi_tmp_0 + 2] = (real_T)a[idxStart] * 0.25;
      rtb_Phi[6 * i + 5] = 0.0;
      rtb_Phi[rtb_Phi_tmp_0 + 3] = Phi_22[3 * i];
      rtb_Phi[rtb_Phi_tmp_0 + 4] = Phi_22[rtb_Phi_tmp];
      rtb_Phi[rtb_Phi_tmp_0 + 5] = Phi_22[idxStart];
    }
  } else {
    rtb_Sum_bq = sin(rtb_Product3_e * 0.25);
    rtb_Elementproduct_g_idx_5 = rtb_Sum_bq / rtb_Product3_e;
    rtb_Product1_h = cos(rtb_Product3_e * 0.25);
    rtb_Elementproduct_g_idx_2 = rtb_Product3_e * rtb_Product3_e;
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 9; rtb_Phi_tmp++) {
      b_I[rtb_Phi_tmp] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    rtb_Sum_bq = rtb_Product3_e * 0.25 - rtb_Sum_bq;
    rtb_Product5 = rt_powd_snf(rtb_Product3_e, 3.0);
    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 9; rtb_Phi_tmp++) {
      Phi_22[rtb_Phi_tmp] = 0;
    }

    for (i = 0; i < 3; i++) {
      Phi_22[i + 3 * i] = 1;
      for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 3; rtb_Phi_tmp++) {
        idxStart = i + 3 * rtb_Phi_tmp;
        rtb_MatrixConcatenate3[idxStart] = 0.0;
        rtb_MatrixConcatenate3[idxStart] += rtb_MatrixConcatenate2[3 *
          rtb_Phi_tmp] * rtb_MatrixConcatenate2[i];
        rtb_MatrixConcatenate3[idxStart] += rtb_MatrixConcatenate2[3 *
          rtb_Phi_tmp + 1] * rtb_MatrixConcatenate2[i + 3];
        rtb_MatrixConcatenate3[idxStart] += rtb_MatrixConcatenate2[3 *
          rtb_Phi_tmp + 2] * rtb_MatrixConcatenate2[i + 6];
      }
    }

    for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 3; rtb_Phi_tmp++) {
      rtb_Product1_f_tmp = rtb_MatrixConcatenate3[3 * rtb_Phi_tmp];
      rtb_Product3_bh = rtb_MatrixConcatenate2[3 * rtb_Phi_tmp];
      rtb_Phi[6 * rtb_Phi_tmp] = (1.0 - rtb_Product1_h) * rtb_Product1_f_tmp /
        rtb_Elementproduct_g_idx_2 + ((real_T)b_I[3 * rtb_Phi_tmp] -
        rtb_Product3_bh * rtb_Elementproduct_g_idx_5);
      rtb_Phi_tmp_0 = 6 * (rtb_Phi_tmp + 3);
      rtb_Phi[rtb_Phi_tmp_0] = ((1.0 - rtb_Product1_h) * rtb_Product3_bh /
        rtb_Elementproduct_g_idx_2 - (real_T)b_a[3 * rtb_Phi_tmp] * 0.25) -
        rtb_Product1_f_tmp * rtb_Sum_bq / rtb_Product5;
      rtb_Phi[6 * rtb_Phi_tmp + 3] = 0.0;
      rtb_Phi[rtb_Phi_tmp_0 + 3] = Phi_22[3 * rtb_Phi_tmp];
      idxStart = 3 * rtb_Phi_tmp + 1;
      rtb_Product1_f_tmp = rtb_MatrixConcatenate3[idxStart];
      rtb_Product3_bh = rtb_MatrixConcatenate2[idxStart];
      rtb_Phi[6 * rtb_Phi_tmp + 1] = ((real_T)b_I[idxStart] - rtb_Product3_bh *
        rtb_Elementproduct_g_idx_5) + (1.0 - rtb_Product1_h) *
        rtb_Product1_f_tmp / rtb_Elementproduct_g_idx_2;
      rtb_Phi[rtb_Phi_tmp_0 + 1] = ((1.0 - rtb_Product1_h) * rtb_Product3_bh /
        rtb_Elementproduct_g_idx_2 - (real_T)b_a[idxStart] * 0.25) -
        rtb_Product1_f_tmp * rtb_Sum_bq / rtb_Product5;
      rtb_Phi[6 * rtb_Phi_tmp + 4] = 0.0;
      rtb_Phi[rtb_Phi_tmp_0 + 4] = Phi_22[idxStart];
      idxStart = 3 * rtb_Phi_tmp + 2;
      rtb_Product1_f_tmp = rtb_MatrixConcatenate3[idxStart];
      rtb_Product3_bh = rtb_MatrixConcatenate2[idxStart];
      rtb_Phi[6 * rtb_Phi_tmp + 2] = ((real_T)b_I[idxStart] - rtb_Product3_bh *
        rtb_Elementproduct_g_idx_5) + (1.0 - rtb_Product1_h) *
        rtb_Product1_f_tmp / rtb_Elementproduct_g_idx_2;
      rtb_Phi[rtb_Phi_tmp_0 + 2] = ((1.0 - rtb_Product1_h) * rtb_Product3_bh /
        rtb_Elementproduct_g_idx_2 - (real_T)b_a[idxStart] * 0.25) -
        rtb_Product1_f_tmp * rtb_Sum_bq / rtb_Product5;
      rtb_Phi[6 * rtb_Phi_tmp + 5] = 0.0;
      rtb_Phi[rtb_Phi_tmp_0 + 5] = Phi_22[idxStart];
    }
  }

  /* End of MATLAB Function: '<S124>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S124>/MATLAB Function' incorporates:
   *  Constant: '<S124>/Constant13'
   *  Merge: '<S3>/P_chol_p_merge'
   */
  for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
    idxStart = rtb_Phi_tmp * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      rtb_Product1_h = 0.0;
      for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
        rtb_Product1_h += rtb_Phi[rtb_Phi_tmp_0 * 6 + rtb_Phi_tmp] *
          rtb_P_chol_p_merge[aoffset + rtb_Phi_tmp_0];
      }

      K[idxStart + i] = rtb_Product1_h;
      K_0[i + 12 * rtb_Phi_tmp] = K[6 * rtb_Phi_tmp + i];
      K_0[(i + 12 * rtb_Phi_tmp) + 6] = rtCP_Constant13_Value[6 * i +
        rtb_Phi_tmp];
    }
  }

  qr_MDOP2S80(K_0, unusedU2, R2);

  /* MATLABSystem: '<S121>/Moving Average' incorporates:
   *  DataTypeConversion: '<S121>/Cast To Double'
   */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  rtb_Elementproduct_g_idx_5 = obj->pCumRevIndex;
  rtb_Product1_h = obj->pCumSum;
  for (i = 0; i < 9; i++) {
    rtb_MatrixConcatenate2[i] = obj->pCumSumRev[i];
  }

  rtb_Product1_h += (real_T)rtb_Sum_mx;
  rtb_Elementproduct_g_idx_2 = rtb_MatrixConcatenate2[(int32_T)
    rtb_Elementproduct_g_idx_5 - 1] + rtb_Product1_h;
  rtb_MatrixConcatenate2[(int32_T)rtb_Elementproduct_g_idx_5 - 1] = rtb_Sum_mx;
  if (rtb_Elementproduct_g_idx_5 != 9.0) {
    rtb_Elementproduct_g_idx_5++;
  } else {
    rtb_Elementproduct_g_idx_5 = 1.0;
    rtb_Product1_h = 0.0;
    for (rtb_Phi_tmp_0 = 7; rtb_Phi_tmp_0 >= 0; rtb_Phi_tmp_0--) {
      rtb_MatrixConcatenate2[rtb_Phi_tmp_0] +=
        rtb_MatrixConcatenate2[rtb_Phi_tmp_0 + 1];
    }
  }

  obj->pCumSum = rtb_Product1_h;
  for (i = 0; i < 9; i++) {
    obj->pCumSumRev[i] = rtb_MatrixConcatenate2[i];
  }

  obj->pCumRevIndex = rtb_Elementproduct_g_idx_5;
  for (i = 0; i < 6; i++) {
    /* S-Function (sdspdiag2): '<S123>/Extract Diagonal' incorporates:
     *  Merge: '<S3>/P_chol_p_merge'
     */
    rty_threeSigma_rad[i] = rtb_P_chol_p_merge[i * 7];

    /* Abs: '<S123>/Abs' */
    rty_threeSigma_rad[i] = fabs(rty_threeSigma_rad[i]);

    /* Sqrt: '<S123>/Sqrt' */
    rty_threeSigma_rad[i] = sqrt(rty_threeSigma_rad[i]);

    /* Gain: '<S123>/multiply' */
    rty_threeSigma_rad[i] *= 3.0;
  }

  /* If: '<S164>/If' */
  if (rtb_Product3_e < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* SignalConversion generated from: '<S171>/Psi_zero' */
    rtb_MathFunction_k[0] = 0.0;
    rtb_MathFunction_k[1] = 0.0;
    rtb_MathFunction_k[2] = 0.0;

    /* End of Outputs for SubSystem: '<S164>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* Trigonometry: '<S170>/Sin' incorporates:
     *  Constant: '<S124>/Constant'
     *  Constant: '<S170>/Constant'
     *  Product: '<S170>/Divide'
     */
    rtb_Product1_h = sin(0.125 * rtb_Product3_e);

    /* Product: '<S170>/Divide1' */
    rtb_MathFunction_k[0] = rtb_Product1_h * rty_body_rates_radps[0] /
      rtb_Product3_e;
    rtb_MathFunction_k[1] = rtb_Product1_h * rty_body_rates_radps[1] /
      rtb_Product3_e;
    rtb_MathFunction_k[2] = rtb_Product1_h * rty_body_rates_radps[2] /
      rtb_Product3_e;

    /* End of Outputs for SubSystem: '<S164>/If Action Subsystem' */
  }

  /* End of If: '<S164>/If' */

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_m(rtb_MathFunction_k, &rtb_MatrixConcatenate2_l[0]);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib' */

  /* Trigonometry: '<S165>/Cos' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S165>/Constant'
   *  Product: '<S165>/Multiply'
   */
  rtb_Product3_e = cos(0.125 * rtb_Product3_e);

  /* Sum: '<S165>/Add1' incorporates:
   *  Product: '<S165>/Matrix Multiply2'
   *  S-Function (sdspeye): '<S165>/Id_3'
   */
  for (i = 0; i < 9; i++) {
    rtb_Gain6[i + 3] = rtb_Product3_e * localDW->Id_3[i] -
      rtb_MatrixConcatenate2_l[i];
  }

  /* End of Sum: '<S165>/Add1' */

  /* SignalConversion generated from: '<S165>/Matrix Concatenate' */
  rtb_Merge_k[0] = rtb_Product3_e;

  /* SignalConversion generated from: '<S165>/Matrix Concatenate1' */
  rtb_Gain6[0] = rtb_MathFunction_k[0];

  /* Math: '<S165>/Transpose2' incorporates:
   *  Gain: '<S165>/Gain'
   *  SignalConversion generated from: '<S165>/Matrix Concatenate1'
   */
  rtb_Merge_k[1] = -rtb_MathFunction_k[0];

  /* SignalConversion generated from: '<S165>/Matrix Concatenate1' */
  rtb_Gain6[1] = rtb_MathFunction_k[1];

  /* Math: '<S165>/Transpose2' incorporates:
   *  Gain: '<S165>/Gain'
   *  SignalConversion generated from: '<S165>/Matrix Concatenate1'
   */
  rtb_Merge_k[2] = -rtb_MathFunction_k[1];

  /* SignalConversion generated from: '<S165>/Matrix Concatenate1' */
  rtb_Gain6[2] = rtb_MathFunction_k[2];

  /* Math: '<S165>/Transpose2' incorporates:
   *  Gain: '<S165>/Gain'
   *  SignalConversion generated from: '<S165>/Matrix Concatenate1'
   */
  rtb_Merge_k[3] = -rtb_MathFunction_k[2];

  /* Concatenate: '<S165>/Matrix Concatenate2' incorporates:
   *  Concatenate: '<S165>/Matrix Concatenate1'
   *  Product: '<S124>/Product'
   */
  for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 4; rtb_Phi_tmp++) {
    i = rtb_Phi_tmp << 2;
    rtb_MatrixConcatenate2_l[i] = rtb_Merge_k[rtb_Phi_tmp];
    rtb_MatrixConcatenate2_l[i + 1] = rtb_Gain6[3 * rtb_Phi_tmp];
    rtb_MatrixConcatenate2_l[i + 2] = rtb_Gain6[3 * rtb_Phi_tmp + 1];
    rtb_MatrixConcatenate2_l[i + 3] = rtb_Gain6[3 * rtb_Phi_tmp + 2];
  }

  /* End of Concatenate: '<S165>/Matrix Concatenate2' */

  /* Product: '<S124>/Product' */
  for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 4; rtb_Phi_tmp++) {
    rtb_Product3_e = rtb_MatrixConcatenate2_l[rtb_Phi_tmp + 12] * rty_sc_quat[3]
      + (rtb_MatrixConcatenate2_l[rtb_Phi_tmp + 8] * rty_sc_quat[2] +
         (rtb_MatrixConcatenate2_l[rtb_Phi_tmp + 4] * rty_sc_quat[1] +
          rtb_MatrixConcatenate2_l[rtb_Phi_tmp] * rty_sc_quat[0]));
    rtb_Merge_k[rtb_Phi_tmp] = rtb_Product3_e;
  }

  /* End of Product: '<S124>/Product' */

  /* Sqrt: '<S172>/sqrt' incorporates:
   *  Product: '<S173>/Product'
   *  Product: '<S173>/Product1'
   *  Product: '<S173>/Product2'
   *  Product: '<S173>/Product3'
   *  Sum: '<S173>/Sum'
   */
  rtb_Product3_e = sqrt(((rtb_Merge_k[0] * rtb_Merge_k[0] + rtb_Merge_k[1] *
    rtb_Merge_k[1]) + rtb_Merge_k[2] * rtb_Merge_k[2]) + rtb_Merge_k[3] *
                        rtb_Merge_k[3]);

  /* SignalConversion generated from: '<S124>/quat_rectify_lib' incorporates:
   *  Product: '<S166>/Product'
   *  Product: '<S166>/Product1'
   *  Product: '<S166>/Product2'
   *  Product: '<S166>/Product3'
   */
  rtb_Merge_k[3] /= rtb_Product3_e;
  rtb_Merge_k[0] /= rtb_Product3_e;
  rtb_Merge_k[1] /= rtb_Product3_e;
  rtb_Merge_k[2] /= rtb_Product3_e;

  /* Outputs for Atomic SubSystem: '<S124>/quat_rectify_lib' */
  quat_rectify_lib(rtb_Merge_k, rtb_TmpSignalConversionAtquat_a);

  /* End of Outputs for SubSystem: '<S124>/quat_rectify_lib' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  for (rtb_Phi_tmp = 0; rtb_Phi_tmp < 6; rtb_Phi_tmp++) {
    for (rtb_Phi_tmp_0 = 0; rtb_Phi_tmp_0 < 6; rtb_Phi_tmp_0++) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S120>/Constant'
       *  MATLAB Function: '<S124>/MATLAB Function'
       */
      if (rtb_Switch_p) {
        localDW->UnitDelay_DSTATE[rtb_Phi_tmp_0 + 6 * rtb_Phi_tmp] =
          rtCP_Constant_Value_ga[6 * rtb_Phi_tmp + rtb_Phi_tmp_0];
      } else {
        localDW->UnitDelay_DSTATE[rtb_Phi_tmp_0 + 6 * rtb_Phi_tmp] = R2[12 *
          rtb_Phi_tmp_0 + rtb_Phi_tmp];
      }

      /* End of Switch: '<S120>/Switch' */
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Switch: '<S121>/Switch' incorporates:
   *  MATLABSystem: '<S121>/Moving Average'
   */
  if (rtb_Elementproduct_g_idx_2 / 10.0 >= 2.0) {
    /* Update for UnitDelay: '<S3>/Unit Delay1' */
    localDW->UnitDelay1_DSTATE[0] = rty_bias_radps[0];
    localDW->UnitDelay1_DSTATE[1] = rty_bias_radps[1];
    localDW->UnitDelay1_DSTATE[2] = rty_bias_radps[2];
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay1' */
    localDW->UnitDelay1_DSTATE[0] = 0.0;
    localDW->UnitDelay1_DSTATE[1] = 0.0;
    localDW->UnitDelay1_DSTATE[2] = 0.0;
  }

  /* End of Switch: '<S121>/Switch' */

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = rtb_TmpSignalConversionAtquat_a[0];
  localDW->UnitDelay3_DSTATE[1] = rtb_TmpSignalConversionAtquat_a[1];
  localDW->UnitDelay3_DSTATE[2] = rtb_TmpSignalConversionAtquat_a[2];
  localDW->UnitDelay3_DSTATE[3] = rtb_TmpSignalConversionAtquat_a[3];

  /* If: '<S3>/TRIAD_activation' */
  if (rtAction == 0) {
    /* Update for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Update for UnitDelay: '<S125>/Unit Delay' */
    localDW->UnitDelay_DSTATE_g[0] = rtb_TmpSignalConversionAtquat_a[0];
    localDW->UnitDelay_DSTATE_g[1] = rtb_TmpSignalConversionAtquat_a[1];
    localDW->UnitDelay_DSTATE_g[2] = rtb_TmpSignalConversionAtquat_a[2];
    localDW->UnitDelay_DSTATE_g[3] = rtb_TmpSignalConversionAtquat_a[3];

    /* End of Update for SubSystem: '<S3>/TriadEstimator_lib' */
  }

  /* Update for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_Compare_e;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
