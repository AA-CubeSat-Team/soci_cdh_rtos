/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
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

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "mrdivide_helper_23K2DU9e.h"
#include "qr_c0VdrKOo.h"
#include "rt_powd_snf.h"
#include "xgeqrf_oLvid02n.h"

/* Forward declaration for local functions */
static void SystemCore_release(dsp_simulink_MovingAverage *obj);
static void SystemCore_delete(dsp_simulink_MovingAverage *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage *obj);
static void SystemCore_release(dsp_simulink_MovingAverage *obj)
{
  dsp_private_SlidingWindowAverag *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void SystemCore_delete(dsp_simulink_MovingAverage *obj)
{
  SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete(obj);
  }
}

/* System initialize for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW)
{
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0], &rtCP_UnitDelay_InitialConditi_e[0], 36U
         * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = 1.0;
  localDW->UnitDelay3_DSTATE[1] = 0.0;
  localDW->UnitDelay3_DSTATE[2] = 0.0;
  localDW->UnitDelay3_DSTATE[3] = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  TRIADActivation_lib_Init(&localDW->TRIADActivation_lib_f);

  /* End of SystemInitialize for SubSystem: '<S3>/TRIADActivation_lib' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* SystemInitialize for Merge: '<S3>/q_p_merge' */
  rty_sc_quat[0] = 0.0;
  rty_sc_quat[1] = 0.0;
  rty_sc_quat[2] = 0.0;
  rty_sc_quat[3] = 0.0;

  /* InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 9U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  /* Start for If: '<S3>/TRIAD_activation' */
  localDW->TRIAD_activation_ActiveSubsyste = -1;

  /* Start for S-Function (sdspeye): '<S165>/Id_3' */
  memset(&localDW->Id_3[0], 0, 9U * sizeof(real_T));

  /* Fill in 1's on the diagonal. */
  localDW->Id_3[0] = 1.0;
  localDW->Id_3[4] = 1.0;
  localDW->Id_3[8] = 1.0;

  /* Start for MATLABSystem: '<S121>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->gobj_0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
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
  int8_T Phi_22[9];
  int8_T b_I[9];
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T C[72];
  real_T unusedU2[144];
  real_T R[144];
  real_T rtb_MatrixConcatenate2_l[16];
  boolean_T rtb_Compare_e;
  boolean_T rtb_Switch_i4;
  uint8_T rtb_Sum_fj;
  real_T rtb_sigma[6];
  real_T rtb_MathFunction_n[3];
  real_T rtb_Product3_e;
  real_T rtb_MathFunction_o0[3];
  boolean_T rtb_Switch_hl;
  boolean_T rtb_Switch_os;
  real_T rtb_Product2_ma;
  real_T rtb_Product1_pi;
  real_T rtb_TmpSignalConversionAtquat_a[4];
  real_T rtb_Merge_a[4];
  real_T rtb_Product8;
  real_T rtb_Product1_f;
  real_T rtb_Product3_bh;
  real_T rtb_Product2_e;
  real_T rtb_Product1_a;
  real_T rtb_sqrt_jy;
  real_T rtb_VectorConcatenate[12];
  real_T rtb_MatrixConcatenate3[9];
  real_T rtb_Elementproduct_a[6];
  int32_T idxStart;
  int32_T i;
  real_T rtb_MathFunction1_f[9];
  real_T rtb_Add_mm;
  real_T rtb_P_chol_p_merge[36];
  real_T rtb_Phi[36];
  real_T rtb_MatrixMultiply1[9];
  real_T tmp[144];
  real_T rtb_P_chol_p_merge_0[36];
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_0;
  real_T rtb_Product5_b_0;
  real_T rtb_Product1_kn_tmp;
  real_T rtb_sqrt_m_tmp;
  real_T rtb_sqrt_m_tmp_0;
  real_T unusedExpr[12];

  /* RelationalOperator: '<S117>/Compare' incorporates:
   *  Constant: '<S117>/Constant'
   */
  rtb_Compare_e = (rtu_sunsensor_valid != 0);

  /* Outputs for Atomic SubSystem: '<S115>/parallel_protection_lib' */
  rtb_Switch_i4 = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, 1.0);

  /* End of Outputs for SubSystem: '<S115>/parallel_protection_lib' */

  /* Sum: '<S115>/Sum' incorporates:
   *  Logic: '<S115>/AND'
   */
  rtb_Sum_fj = (uint8_T)((uint32_T)(rtb_Compare_e && rtu_mag_meas_valid &&
    rtu_gryo_meas_valid) + rtb_Switch_i4);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_i4 = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtb_Compare_e, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_f);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S127>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_i4) {
    localDW->TRIAD_activation_ActiveSubsyste = 0;

    /* Outputs for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Math: '<S175>/Math Function' */
    rtb_MathFunction_n[0] = rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0];
    rtb_MathFunction_n[1] = rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1];
    rtb_MathFunction_n[2] = rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Sum: '<S175>/Sum of Elements' */
    rtb_Product3_e = (rtb_MathFunction_n[0] + rtb_MathFunction_n[1]) +
      rtb_MathFunction_n[2];

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
     */
    if (rtb_Product3_e > 0.0) {
      rtb_Merge_a[0] = rtu_mag_meas_body_T[0];
      rtb_Merge_a[1] = rtu_mag_meas_body_T[1];
      rtb_Merge_a[2] = rtu_mag_meas_body_T[2];
      rtb_Merge_a[3] = rtb_Product3_e;
    } else {
      /* Product: '<S175>/Product' */
      rtb_MathFunction_n[0] = rtu_mag_meas_body_T[0] * 0.0;
      rtb_MathFunction_n[1] = rtu_mag_meas_body_T[1] * 0.0;
      rtb_MathFunction_n[2] = rtu_mag_meas_body_T[2] * 0.0;
      rtb_Merge_a[0] = rtb_MathFunction_n[0];
      rtb_Merge_a[1] = rtb_MathFunction_n[1];
      rtb_Merge_a[2] = rtb_MathFunction_n[2];
      rtb_Merge_a[3] = 1.0;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Product: '<S175>/Divide' */
    rtb_MathFunction_n[0] = rtb_Merge_a[0] / rtb_Merge_a[3];
    rtb_MathFunction_n[1] = rtb_Merge_a[1] / rtb_Merge_a[3];
    rtb_MathFunction_n[2] = rtb_Merge_a[2] / rtb_Merge_a[3];

    /* Math: '<S174>/Math Function' */
    rtb_MathFunction_o0[0] = rtu_mag_eci_T[0] * rtu_mag_eci_T[0];
    rtb_MathFunction_o0[1] = rtu_mag_eci_T[1] * rtu_mag_eci_T[1];
    rtb_MathFunction_o0[2] = rtu_mag_eci_T[2] * rtu_mag_eci_T[2];

    /* Sum: '<S174>/Sum of Elements' */
    rtb_Product3_e = (rtb_MathFunction_o0[0] + rtb_MathFunction_o0[1]) +
      rtb_MathFunction_o0[2];

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
     */
    if (rtb_Product3_e > 0.0) {
      rtb_Merge_a[0] = rtu_mag_eci_T[0];
      rtb_Merge_a[1] = rtu_mag_eci_T[1];
      rtb_Merge_a[2] = rtu_mag_eci_T[2];
      rtb_Merge_a[3] = rtb_Product3_e;
    } else {
      /* Product: '<S174>/Product' */
      rtb_MathFunction_o0[0] = rtu_mag_eci_T[0] * 0.0;
      rtb_MathFunction_o0[1] = rtu_mag_eci_T[1] * 0.0;
      rtb_MathFunction_o0[2] = rtu_mag_eci_T[2] * 0.0;
      rtb_Merge_a[0] = rtb_MathFunction_o0[0];
      rtb_Merge_a[1] = rtb_MathFunction_o0[1];
      rtb_Merge_a[2] = rtb_MathFunction_o0[2];
      rtb_Merge_a[3] = 1.0;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Product: '<S174>/Divide' */
    rtb_MathFunction_o0[0] = rtb_Merge_a[0] / rtb_Merge_a[3];
    rtb_MathFunction_o0[1] = rtb_Merge_a[1] / rtb_Merge_a[3];
    rtb_MathFunction_o0[2] = rtb_Merge_a[2] / rtb_Merge_a[3];

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib' */
    rtb_Switch_hl = parallel_protection_lib(rtu_sun_meas_body_unit,
      rtb_MathFunction_n, 1.0);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib' */

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib1' */
    rtb_Switch_os = parallel_protection_lib(rtu_sc2sun_eci_unit,
      rtb_MathFunction_o0, 1.0);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib1' */

    /* If: '<S125>/If' incorporates:
     *  Inport: '<S178>/quat_old'
     *  Logic: '<S125>/Logical Operator'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    if (rtb_Compare_e && rtu_mag_meas_valid && rtb_Switch_hl && rtb_Switch_os) {
      /* Outputs for IfAction SubSystem: '<S125>/TriadAlgorithm' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];
      rtb_MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];
      rtb_MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Product: '<S184>/Element product' */
      rtb_Elementproduct_a[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_n[2];
      rtb_Elementproduct_a[1] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_n[0];
      rtb_Elementproduct_a[2] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_n[1];
      rtb_Elementproduct_a[3] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_n[1];
      rtb_Elementproduct_a[4] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_n[2];
      rtb_Elementproduct_a[5] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_n[0];

      /* Sum: '<S184>/Add3' */
      rtb_MathFunction_n[0] = rtb_Elementproduct_a[0] - rtb_Elementproduct_a[3];
      rtb_MathFunction_n[1] = rtb_Elementproduct_a[1] - rtb_Elementproduct_a[4];
      rtb_MathFunction_n[2] = rtb_Elementproduct_a[2] - rtb_Elementproduct_a[5];

      /* S-Function (sdsp2norm2): '<S177>/Normalization6' */
      rtb_Product3_e = 1.0 / (sqrt((rtb_MathFunction_n[0] * rtb_MathFunction_n[0]
        + rtb_MathFunction_n[1] * rtb_MathFunction_n[1]) + rtb_MathFunction_n[2]
        * rtb_MathFunction_n[2]) + 1.0E-10);
      rtb_MathFunction_n[0] *= rtb_Product3_e;
      rtb_MathFunction_n[1] *= rtb_Product3_e;
      rtb_MathFunction_n[2] *= rtb_Product3_e;

      /* Product: '<S186>/Element product' */
      rtb_Elementproduct_a[0] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_o0[2];
      rtb_Elementproduct_a[1] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_o0[0];
      rtb_Elementproduct_a[2] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_o0[1];
      rtb_Elementproduct_a[3] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_o0[1];
      rtb_Elementproduct_a[4] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_o0[2];
      rtb_Elementproduct_a[5] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_o0[0];

      /* Sum: '<S186>/Add3' */
      rtb_MathFunction_o0[0] = rtb_Elementproduct_a[0] - rtb_Elementproduct_a[3];
      rtb_MathFunction_o0[1] = rtb_Elementproduct_a[1] - rtb_Elementproduct_a[4];
      rtb_MathFunction_o0[2] = rtb_Elementproduct_a[2] - rtb_Elementproduct_a[5];

      /* S-Function (sdsp2norm2): '<S177>/Normalization7' */
      rtb_Product3_e = 1.0 / (sqrt((rtb_MathFunction_o0[0] *
        rtb_MathFunction_o0[0] + rtb_MathFunction_o0[1] * rtb_MathFunction_o0[1])
        + rtb_MathFunction_o0[2] * rtb_MathFunction_o0[2]) + 1.0E-10);
      rtb_MathFunction_o0[0] *= rtb_Product3_e;
      rtb_MathFunction_o0[1] *= rtb_Product3_e;
      rtb_MathFunction_o0[2] *= rtb_Product3_e;

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[3] = rtb_MathFunction_o0[0];
      rtb_MatrixConcatenate3[4] = rtb_MathFunction_o0[1];
      rtb_MatrixConcatenate3[5] = rtb_MathFunction_o0[2];

      /* Product: '<S187>/Element product' */
      rtb_MathFunction1_f[0] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_o0[2];
      rtb_MathFunction1_f[1] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_o0[0];
      rtb_MathFunction1_f[2] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_o0[1];
      rtb_MathFunction1_f[3] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_o0[1];
      rtb_MathFunction1_f[4] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_o0[2];
      rtb_MathFunction1_f[5] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_o0[0];

      /* Sum: '<S187>/Add3' */
      rtb_MatrixConcatenate3[6] = rtb_MathFunction1_f[0] - rtb_MathFunction1_f[3];
      rtb_MatrixConcatenate3[7] = rtb_MathFunction1_f[1] - rtb_MathFunction1_f[4];
      rtb_MatrixConcatenate3[8] = rtb_MathFunction1_f[2] - rtb_MathFunction1_f[5];

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_f[0] = rtu_sun_meas_body_unit[0];
      rtb_MathFunction1_f[1] = rtu_sun_meas_body_unit[1];
      rtb_MathFunction1_f[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_f[3] = rtb_MathFunction_n[0];
      rtb_MathFunction1_f[4] = rtb_MathFunction_n[1];
      rtb_MathFunction1_f[5] = rtb_MathFunction_n[2];

      /* Product: '<S185>/Element product' */
      rtb_Elementproduct_a[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_n[2];
      rtb_Elementproduct_a[1] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_n[0];
      rtb_Elementproduct_a[2] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_n[1];
      rtb_Elementproduct_a[3] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_n[1];
      rtb_Elementproduct_a[4] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_n[2];
      rtb_Elementproduct_a[5] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_n[0];

      /* Sum: '<S185>/Add3' */
      rtb_MathFunction1_f[6] = rtb_Elementproduct_a[0] - rtb_Elementproduct_a[3];
      rtb_MathFunction1_f[7] = rtb_Elementproduct_a[1] - rtb_Elementproduct_a[4];
      rtb_MathFunction1_f[8] = rtb_Elementproduct_a[2] - rtb_Elementproduct_a[5];

      /* Product: '<S177>/Matrix Multiply1' incorporates:
       *  Math: '<S177>/Math Function1'
       */
      for (i = 0; i < 3; i++) {
        for (idxStart = 0; idxStart < 3; idxStart++) {
          rtb_MatrixMultiply1_tmp = i + 3 * idxStart;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = 0.0;
          rtb_MatrixMultiply1_tmp_0 = 3 * idxStart + i;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_f[i] * rtb_MatrixConcatenate3[idxStart];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_f[i + 3] * rtb_MatrixConcatenate3[idxStart + 3];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_f[i + 6] * rtb_MatrixConcatenate3[idxStart + 6];
        }
      }

      /* End of Product: '<S177>/Matrix Multiply1' */

      /* Sum: '<S192>/Add' */
      rtb_Add_mm = (rtb_MatrixMultiply1[0] + rtb_MatrixMultiply1[4]) +
        rtb_MatrixMultiply1[8];

      /* If: '<S188>/If' */
      if (rtb_Add_mm > 0.0) {
        /* Outputs for IfAction SubSystem: '<S188>/Positive Trace' incorporates:
         *  ActionPort: '<S190>/Action Port'
         */
        PositiveTrace(rtb_Add_mm, rtb_MatrixMultiply1, &localDW->Merge[0],
                      &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S188>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S188>/Negative Trace' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        NegativeTrace(rtb_MatrixMultiply1, localDW->Merge);

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
      rtb_Merge_a[0] = rtb_Product3_e * localDW->Merge[0];
      rtb_Merge_a[1] = rtb_Product3_e * localDW->Merge[1];
      rtb_Merge_a[2] = rtb_Product3_e * localDW->Merge[2];
      rtb_Merge_a[3] = rtb_Product3_e * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S125>/TriadAlgorithm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S125>/TriadBypass' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      rtb_Merge_a[0] = localDW->UnitDelay_DSTATE_g[0];
      rtb_Merge_a[1] = localDW->UnitDelay_DSTATE_g[1];
      rtb_Merge_a[2] = localDW->UnitDelay_DSTATE_g[2];
      rtb_Merge_a[3] = localDW->UnitDelay_DSTATE_g[3];

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
    rtb_Product3_e = sqrt(((rtb_Merge_a[0] * rtb_Merge_a[0] + rtb_Merge_a[1] *
      rtb_Merge_a[1]) + rtb_Merge_a[2] * rtb_Merge_a[2]) + rtb_Merge_a[3] *
                          rtb_Merge_a[3]);

    /* SignalConversion: '<S125>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
     *  Product: '<S176>/Product'
     *  Product: '<S176>/Product1'
     *  Product: '<S176>/Product2'
     *  Product: '<S176>/Product3'
     *  Sqrt: '<S182>/sqrt'
     */
    rtb_TmpSignalConversionAtquat_a[0] = rtb_Merge_a[0] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[1] = rtb_Merge_a[1] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[2] = rtb_Merge_a[2] / rtb_Product3_e;
    rtb_TmpSignalConversionAtquat_a[3] = rtb_Merge_a[3] / rtb_Product3_e;

    /* Outputs for Atomic SubSystem: '<S125>/quat_rectify_lib' */
    quat_rectify_lib(rtb_TmpSignalConversionAtquat_a, rtb_Merge_a);

    /* End of Outputs for SubSystem: '<S125>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/TriadEstimator_lib' */
  } else {
    localDW->TRIAD_activation_ActiveSubsyste = 1;

    /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    rtb_Merge_a[0] = localDW->UnitDelay3_DSTATE[0];
    rtb_Merge_a[1] = localDW->UnitDelay3_DSTATE[1];
    rtb_Merge_a[2] = localDW->UnitDelay3_DSTATE[2];
    rtb_Merge_a[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S116>/If Action Subsystem' */
  }

  /* End of If: '<S3>/TRIAD_activation' */

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S114>/P_chol_m'
   *  Inport: '<S114>/bias_m'
   *  Inport: '<S114>/q_m'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_fj > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* SignalConversion: '<S132>/ConcatBufferAtVertical Matrix ConcatenateIn2' */
    memset(&rtb_P_chol_p_merge[18], 0, 18U * sizeof(real_T));

    /* Sqrt: '<S148>/sqrt' incorporates:
     *  Product: '<S149>/Product'
     *  Product: '<S149>/Product1'
     *  Product: '<S149>/Product2'
     *  Product: '<S149>/Product3'
     *  Sum: '<S149>/Sum'
     */
    rtb_Product5_b_0 = sqrt(((rtb_Merge_a[0] * rtb_Merge_a[0] + rtb_Merge_a[1] *
      rtb_Merge_a[1]) + rtb_Merge_a[2] * rtb_Merge_a[2]) + rtb_Merge_a[3] *
      rtb_Merge_a[3]);

    /* Product: '<S144>/Product2' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product3_bh = rtb_Merge_a[2] / rtb_Product5_b_0;

    /* Product: '<S144>/Product3' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product1_f = rtb_Merge_a[3] / rtb_Product5_b_0;

    /* Product: '<S145>/Product7' incorporates:
     *  Product: '<S146>/Product7'
     */
    rtb_Product1_pi = rtb_Product1_f * rtb_Product1_f;

    /* Product: '<S145>/Product6' incorporates:
     *  Product: '<S147>/Product7'
     */
    rtb_Product2_ma = rtb_Product3_bh * rtb_Product3_bh;

    /* Product: '<S145>/Product8' incorporates:
     *  Constant: '<S145>/Constant'
     *  Gain: '<S145>/Gain2'
     *  Product: '<S145>/Product6'
     *  Product: '<S145>/Product7'
     *  Sum: '<S145>/Sum3'
     */
    rtb_Product8 = ((0.5 - rtb_Product2_ma) - rtb_Product1_pi) * 2.0 *
      rtu_sc2sun_eci_unit[0];

    /* Product: '<S144>/Product1' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product2_e = rtb_Merge_a[1] / rtb_Product5_b_0;

    /* Product: '<S144>/Product' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    rtb_Product5_b_0 = rtb_Merge_a[0] / rtb_Product5_b_0;

    /* Product: '<S145>/Product' incorporates:
     *  Product: '<S146>/Product'
     */
    rtb_Product1_kn_tmp = rtb_Product2_e * rtb_Product3_bh;

    /* Product: '<S145>/Product1' incorporates:
     *  Product: '<S146>/Product1'
     */
    rtb_Add_mm = rtb_Product5_b_0 * rtb_Product1_f;

    /* Product: '<S145>/Product4' incorporates:
     *  Gain: '<S145>/Gain'
     *  Product: '<S145>/Product'
     *  Product: '<S145>/Product1'
     *  Sum: '<S145>/Sum1'
     */
    rtb_Product1_a = (rtb_Product1_kn_tmp + rtb_Add_mm) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S145>/Product3' incorporates:
     *  Product: '<S147>/Product'
     */
    rtb_sqrt_m_tmp = rtb_Product2_e * rtb_Product1_f;

    /* Product: '<S145>/Product2' incorporates:
     *  Product: '<S147>/Product1'
     */
    rtb_sqrt_m_tmp_0 = rtb_Product5_b_0 * rtb_Product3_bh;

    /* Product: '<S145>/Product5' incorporates:
     *  Gain: '<S145>/Gain1'
     *  Product: '<S145>/Product2'
     *  Product: '<S145>/Product3'
     *  Sum: '<S145>/Sum2'
     */
    rtb_sqrt_jy = (rtb_sqrt_m_tmp - rtb_sqrt_m_tmp_0) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S145>/Sum' */
    rtb_Product3_e = (rtb_Product8 + rtb_Product1_a) + rtb_sqrt_jy;

    /* Product: '<S146>/Product4' incorporates:
     *  Gain: '<S146>/Gain'
     *  Sum: '<S146>/Sum1'
     */
    rtb_sqrt_jy = (rtb_Product1_kn_tmp - rtb_Add_mm) * 2.0 *
      rtu_sc2sun_eci_unit[0];

    /* Sum: '<S146>/Sum3' incorporates:
     *  Constant: '<S146>/Constant'
     *  Product: '<S146>/Product6'
     *  Sum: '<S147>/Sum3'
     */
    rtb_Product1_kn_tmp = 0.5 - rtb_Product2_e * rtb_Product2_e;

    /* Product: '<S146>/Product8' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Sum: '<S146>/Sum3'
     */
    rtb_Product1_a = (rtb_Product1_kn_tmp - rtb_Product1_pi) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S146>/Product3' incorporates:
     *  Product: '<S147>/Product3'
     */
    rtb_Product1_pi = rtb_Product3_bh * rtb_Product1_f;

    /* Product: '<S146>/Product2' incorporates:
     *  Product: '<S147>/Product2'
     */
    rtb_Product2_e *= rtb_Product5_b_0;

    /* Product: '<S146>/Product5' incorporates:
     *  Gain: '<S146>/Gain1'
     *  Product: '<S146>/Product2'
     *  Product: '<S146>/Product3'
     *  Sum: '<S146>/Sum2'
     */
    rtb_Product8 = (rtb_Product2_e + rtb_Product1_pi) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S146>/Sum' */
    rtb_Add_mm = (rtb_sqrt_jy + rtb_Product1_a) + rtb_Product8;

    /* Product: '<S147>/Product4' incorporates:
     *  Gain: '<S147>/Gain'
     *  Sum: '<S147>/Sum1'
     */
    rtb_sqrt_jy = (rtb_sqrt_m_tmp + rtb_sqrt_m_tmp_0) * 2.0 *
      rtu_sc2sun_eci_unit[0];

    /* Product: '<S147>/Product5' incorporates:
     *  Gain: '<S147>/Gain1'
     *  Sum: '<S147>/Sum2'
     */
    rtb_Product1_a = (rtb_Product1_pi - rtb_Product2_e) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S147>/Product8' incorporates:
     *  Gain: '<S147>/Gain2'
     *  Sum: '<S147>/Sum3'
     */
    rtb_Product2_e = (rtb_Product1_kn_tmp - rtb_Product2_ma) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S147>/Sum' */
    rtb_Product1_pi = (rtb_sqrt_jy + rtb_Product1_a) + rtb_Product2_e;

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Product1_pi, rtb_Product3_e, rtb_Add_mm,
                        rtb_MatrixConcatenate3);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib' */

    /* Sqrt: '<S154>/sqrt' incorporates:
     *  Product: '<S155>/Product'
     *  Product: '<S155>/Product1'
     *  Product: '<S155>/Product2'
     *  Product: '<S155>/Product3'
     *  Sum: '<S155>/Sum'
     */
    rtb_sqrt_jy = sqrt(((rtb_Merge_a[0] * rtb_Merge_a[0] + rtb_Merge_a[1] *
                         rtb_Merge_a[1]) + rtb_Merge_a[2] * rtb_Merge_a[2]) +
                       rtb_Merge_a[3] * rtb_Merge_a[3]);

    /* Product: '<S150>/Product2' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    rtb_Product1_a = rtb_Merge_a[2] / rtb_sqrt_jy;

    /* Product: '<S150>/Product3' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    rtb_Product2_e = rtb_Merge_a[3] / rtb_sqrt_jy;

    /* Product: '<S151>/Product8' incorporates:
     *  Constant: '<S151>/Constant'
     *  Gain: '<S151>/Gain2'
     *  Product: '<S151>/Product6'
     *  Product: '<S151>/Product7'
     *  Sum: '<S151>/Sum3'
     */
    rtb_Product3_bh = ((0.5 - rtb_Product1_a * rtb_Product1_a) - rtb_Product2_e *
                       rtb_Product2_e) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S150>/Product1' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    rtb_Product1_f = rtb_Merge_a[1] / rtb_sqrt_jy;

    /* Product: '<S150>/Product' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    rtb_sqrt_jy = rtb_Merge_a[0] / rtb_sqrt_jy;

    /* Product: '<S151>/Product4' incorporates:
     *  Gain: '<S151>/Gain'
     *  Product: '<S151>/Product'
     *  Product: '<S151>/Product1'
     *  Sum: '<S151>/Sum1'
     */
    rtb_Product8 = (rtb_Product1_f * rtb_Product1_a + rtb_sqrt_jy *
                    rtb_Product2_e) * 2.0 * rtu_mag_eci_T[1];

    /* Product: '<S151>/Product5' incorporates:
     *  Gain: '<S151>/Gain1'
     *  Product: '<S151>/Product2'
     *  Product: '<S151>/Product3'
     *  Sum: '<S151>/Sum2'
     */
    rtb_Product5_b_0 = (rtb_Product1_f * rtb_Product2_e - rtb_sqrt_jy *
                        rtb_Product1_a) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S151>/Sum' */
    rtb_Product2_ma = (rtb_Product3_bh + rtb_Product8) + rtb_Product5_b_0;

    /* Product: '<S152>/Product4' incorporates:
     *  Gain: '<S152>/Gain'
     *  Product: '<S152>/Product'
     *  Product: '<S152>/Product1'
     *  Sum: '<S152>/Sum1'
     */
    rtb_Product3_bh = (rtb_Product1_f * rtb_Product1_a - rtb_sqrt_jy *
                       rtb_Product2_e) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S152>/Product8' incorporates:
     *  Constant: '<S152>/Constant'
     *  Gain: '<S152>/Gain2'
     *  Product: '<S152>/Product6'
     *  Product: '<S152>/Product7'
     *  Sum: '<S152>/Sum3'
     */
    rtb_Product8 = ((0.5 - rtb_Product1_f * rtb_Product1_f) - rtb_Product2_e *
                    rtb_Product2_e) * 2.0 * rtu_mag_eci_T[1];

    /* Product: '<S152>/Product5' incorporates:
     *  Gain: '<S152>/Gain1'
     *  Product: '<S152>/Product2'
     *  Product: '<S152>/Product3'
     *  Sum: '<S152>/Sum2'
     */
    rtb_Product5_b_0 = (rtb_sqrt_jy * rtb_Product1_f + rtb_Product1_a *
                        rtb_Product2_e) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S152>/Sum' */
    rtb_Product5_b_0 += rtb_Product3_bh + rtb_Product8;

    /* Product: '<S153>/Product4' incorporates:
     *  Gain: '<S153>/Gain'
     *  Product: '<S153>/Product'
     *  Product: '<S153>/Product1'
     *  Sum: '<S153>/Sum1'
     */
    rtb_Product3_bh = (rtb_Product1_f * rtb_Product2_e + rtb_sqrt_jy *
                       rtb_Product1_a) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S153>/Product5' incorporates:
     *  Gain: '<S153>/Gain1'
     *  Product: '<S153>/Product2'
     *  Product: '<S153>/Product3'
     *  Sum: '<S153>/Sum2'
     */
    rtb_sqrt_jy = (rtb_Product1_a * rtb_Product2_e - rtb_sqrt_jy *
                   rtb_Product1_f) * 2.0 * rtu_mag_eci_T[1];

    /* Product: '<S153>/Product8' incorporates:
     *  Constant: '<S153>/Constant'
     *  Gain: '<S153>/Gain2'
     *  Product: '<S153>/Product6'
     *  Product: '<S153>/Product7'
     *  Sum: '<S153>/Sum3'
     */
    rtb_Product1_a = ((0.5 - rtb_Product1_f * rtb_Product1_f) - rtb_Product1_a *
                      rtb_Product1_a) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S153>/Sum' */
    rtb_Product3_bh = (rtb_Product3_bh + rtb_sqrt_jy) + rtb_Product1_a;

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Product3_bh, rtb_Product2_ma, rtb_Product5_b_0,
                        rtb_MathFunction1_f);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S132>/Horizontal Matrix Concatenate' */
    for (i = 0; i < 3; i++) {
      rtb_P_chol_p_merge[6 * i] = rtb_MatrixConcatenate3[3 * i];
      rtb_P_chol_p_merge[3 + 6 * i] = rtb_MathFunction1_f[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_P_chol_p_merge[1 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0];
      rtb_P_chol_p_merge[4 + 6 * i] =
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_P_chol_p_merge[2 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0];
      rtb_P_chol_p_merge[5 + 6 * i] =
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0];
    }

    /* End of Concatenate: '<S132>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S119>/QR_factorization' incorporates:
     *  Constant: '<S119>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1_tmp = i + 6 * idxStart;
        rtb_Phi[rtb_MatrixMultiply1_tmp] = 0.0;
        for (rtb_MatrixMultiply1_tmp_0 = 0; rtb_MatrixMultiply1_tmp_0 < 6;
             rtb_MatrixMultiply1_tmp_0++) {
          rtb_Phi[rtb_MatrixMultiply1_tmp] = localDW->UnitDelay_DSTATE[6 * i +
            rtb_MatrixMultiply1_tmp_0] * rtb_P_chol_p_merge[6 *
            rtb_MatrixMultiply1_tmp_0 + idxStart] + rtb_Phi[6 * idxStart + i];
        }

        tmp[idxStart + 12 * i] = rtCP_Constant_Value_gj[6 * idxStart + i];
        tmp[idxStart + 12 * (i + 6)] = 0.0;
      }
    }

    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        tmp[(idxStart + 12 * i) + 6] = rtb_Phi[6 * i + idxStart];
        tmp[(idxStart + 12 * (i + 6)) + 6] = localDW->UnitDelay_DSTATE[6 *
          idxStart + i];
      }
    }

    qr_c0VdrKOo(tmp, unusedU2, R);
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1_tmp = idxStart + 6 * i;
        rtb_Phi[rtb_MatrixMultiply1_tmp] = R[(6 + idxStart) * 12 + i];
        rtb_P_chol_p_merge[rtb_MatrixMultiply1_tmp] = R[12 * idxStart + i];
      }
    }

    mrdivide_helper_23K2DU9e(rtb_Phi, rtb_P_chol_p_merge);
    if (!rtu_gryo_meas_valid) {
      for (i = 0; i < 6; i++) {
        rtb_Phi[3 + 6 * i] = 0.0;
        rtb_Phi[4 + 6 * i] = 0.0;
        rtb_Phi[5 + 6 * i] = 0.0;
      }
    }

    /* SignalConversion: '<S119>/OutportBufferForP_chol_plus' incorporates:
     *  MATLAB Function: '<S119>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_P_chol_p_merge[idxStart + 6 * i] = R[((6 + idxStart) * 12 + i) + 6];
      }
    }

    /* Gain: '<S137>/Gain' */
    rtb_VectorConcatenate[0] = -rtb_Merge_a[1];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_Merge_a[0];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_Merge_a[3];

    /* Gain: '<S137>/Gain1' */
    rtb_VectorConcatenate[3] = -rtb_Merge_a[2];

    /* Gain: '<S137>/Gain2' */
    rtb_VectorConcatenate[4] = -rtb_Merge_a[2];

    /* Gain: '<S137>/Gain3' */
    rtb_VectorConcatenate[5] = -rtb_Merge_a[3];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_Merge_a[0];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Merge_a[1];

    /* Gain: '<S137>/Gain4' */
    rtb_VectorConcatenate[8] = -rtb_Merge_a[3];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_Merge_a[2];

    /* Gain: '<S137>/Gain5' */
    rtb_VectorConcatenate[10] = -rtb_Merge_a[1];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_Merge_a[0];

    /* Sum: '<S119>/CreateMeasResidual' */
    rtb_Elementproduct_a[0] = rtu_sun_meas_body_unit[0] - rtb_Product3_e;
    rtb_Elementproduct_a[1] = rtu_sun_meas_body_unit[1] - rtb_Add_mm;
    rtb_Elementproduct_a[2] = rtu_sun_meas_body_unit[2] - rtb_Product1_pi;
    rtb_Elementproduct_a[3] = rtu_mag_meas_body_T[0] - rtb_Product2_ma;
    rtb_Elementproduct_a[4] = rtu_mag_meas_body_T[1] - rtb_Product5_b_0;
    rtb_Elementproduct_a[5] = rtu_mag_meas_body_T[2] - rtb_Product3_bh;

    /* Product: '<S119>/Product1' incorporates:
     *  MATLAB Function: '<S119>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      rtb_MathFunction1_f[i] = 0.0;
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MathFunction1_f[i] += rtb_Phi[6 * idxStart + i] *
          rtb_Elementproduct_a[idxStart];
      }
    }

    /* End of Product: '<S119>/Product1' */

    /* Sum: '<S119>/Sum' incorporates:
     *  Gain: '<S137>/Gain6'
     *  Product: '<S119>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_TmpSignalConversionAtquat_a[i] = ((rtb_VectorConcatenate[i + 4] * 0.5 *
        rtb_MathFunction1_f[1] + 0.5 * rtb_VectorConcatenate[i] *
        rtb_MathFunction1_f[0]) + rtb_VectorConcatenate[i + 8] * 0.5 *
        rtb_MathFunction1_f[2]) + rtb_Merge_a[i];
    }

    /* End of Sum: '<S119>/Sum' */

    /* Sqrt: '<S142>/sqrt' incorporates:
     *  Product: '<S143>/Product'
     *  Product: '<S143>/Product1'
     *  Product: '<S143>/Product2'
     *  Product: '<S143>/Product3'
     *  Sum: '<S143>/Sum'
     */
    rtb_sqrt_jy = sqrt(((rtb_TmpSignalConversionAtquat_a[0] *
                         rtb_TmpSignalConversionAtquat_a[0] +
                         rtb_TmpSignalConversionAtquat_a[1] *
                         rtb_TmpSignalConversionAtquat_a[1]) +
                        rtb_TmpSignalConversionAtquat_a[2] *
                        rtb_TmpSignalConversionAtquat_a[2]) +
                       rtb_TmpSignalConversionAtquat_a[3] *
                       rtb_TmpSignalConversionAtquat_a[3]);

    /* Product: '<S134>/Product' */
    rty_sc_quat[0] = rtb_TmpSignalConversionAtquat_a[0] / rtb_sqrt_jy;

    /* Product: '<S134>/Product1' */
    rty_sc_quat[1] = rtb_TmpSignalConversionAtquat_a[1] / rtb_sqrt_jy;

    /* Product: '<S134>/Product2' */
    rty_sc_quat[2] = rtb_TmpSignalConversionAtquat_a[2] / rtb_sqrt_jy;

    /* Product: '<S134>/Product3' */
    rty_sc_quat[3] = rtb_TmpSignalConversionAtquat_a[3] / rtb_sqrt_jy;

    /* Saturate: '<S119>/Saturation' incorporates:
     *  Sum: '<S119>/UpdatingBetaBias '
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_Product3_e = rtb_MathFunction1_f[3] + localDW->UnitDelay1_DSTATE[0];
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[0] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[0] = -0.01745;
    } else {
      rty_bias_radps[0] = rtb_Product3_e;
    }

    rtb_Product3_e = rtb_MathFunction1_f[4] + localDW->UnitDelay1_DSTATE[1];
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[1] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[1] = -0.01745;
    } else {
      rty_bias_radps[1] = rtb_Product3_e;
    }

    rtb_Product3_e = rtb_MathFunction1_f[5] + localDW->UnitDelay1_DSTATE[2];
    if (rtb_Product3_e > 0.01745) {
      rty_bias_radps[2] = 0.01745;
    } else if (rtb_Product3_e < -0.01745) {
      rty_bias_radps[2] = -0.01745;
    } else {
      rty_bias_radps[2] = rtb_Product3_e;
    }

    /* End of Saturate: '<S119>/Saturation' */
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
    rty_sc_quat[0] = rtb_Merge_a[0];
    rty_sc_quat[1] = rtb_Merge_a[1];
    rty_sc_quat[2] = rtb_Merge_a[2];
    rty_sc_quat[3] = rtb_Merge_a[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   */
  rtb_Compare_e = (rtb_Sum_fj == 2);

  /* RelationalOperator: '<S157>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Switch_hl = ((int32_T)rtb_Compare_e > (int32_T)localDW->DelayInput1_DSTATE);

  /* Switch: '<S3>/NullRatesIfGyroInvalid ' */
  if (rtu_gryo_meas_valid) {
    rtb_MathFunction_n[0] = rtu_gyro_meas_body_radps[0];
    rtb_MathFunction_n[1] = rtu_gyro_meas_body_radps[1];
    rtb_MathFunction_n[2] = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_MathFunction_n[0] = 0.0;
    rtb_MathFunction_n[1] = 0.0;
    rtb_MathFunction_n[2] = 0.0;
  }

  /* End of Switch: '<S3>/NullRatesIfGyroInvalid ' */

  /* Sum: '<S124>/Sum' */
  rtb_Product3_e = rtb_MathFunction_n[0] - rty_bias_radps[0];
  rtb_Add_mm = rtb_MathFunction_n[1] - rty_bias_radps[1];
  rtb_Product1_a = rtb_MathFunction_n[2] - rty_bias_radps[2];
  rty_body_rates_radps[0] = rtb_Product3_e;
  rty_body_rates_radps[1] = rtb_Add_mm;
  rty_body_rates_radps[2] = rtb_Product1_a;

  /* Math: '<S124>/Transpose' */
  rtb_MathFunction_n[0] = rty_body_rates_radps[0];
  rtb_MathFunction_n[1] = rty_body_rates_radps[1];
  rtb_MathFunction_n[2] = rty_body_rates_radps[2];

  /* Product: '<S124>/Matrix Multiply' */
  rtb_Product3_e = rtb_MathFunction_n[0] * rty_body_rates_radps[0];
  rtb_Product3_e += rtb_MathFunction_n[1] * rty_body_rates_radps[1];
  rtb_Product3_e += rtb_MathFunction_n[2] * rty_body_rates_radps[2];

  /* Sqrt: '<S124>/Sqrt' incorporates:
   *  Product: '<S124>/Matrix Multiply'
   */
  rtb_Product3_e = sqrt(rtb_Product3_e);

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_m(rty_body_rates_radps, rtb_MatrixConcatenate3);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S124>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S124>/Constant'
   */
  if (rtb_Product3_e < 1.0E-10) {
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
      Phi_22[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      rtb_Phi[6 * idxStart] = b_I[3 * idxStart];
      rtb_MatrixMultiply1_tmp = 6 * (idxStart + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp] = (real_T)a[3 * idxStart] * 0.25;
      rtb_Phi[3 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 1;
      rtb_Phi[1 + 6 * idxStart] = b_I[i];
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp] = (real_T)a[i] * 0.25;
      rtb_Phi[4 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 2;
      rtb_Phi[2 + 6 * idxStart] = b_I[i];
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp] = (real_T)a[i] * 0.25;
      rtb_Phi[5 + 6 * idxStart] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_MatrixMultiply1_tmp = 6 * (i + 3);
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i];
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i + 1];
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i + 2];
    }
  } else {
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
      Phi_22[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    rtb_Product1_a = sin(rtb_Product3_e * 0.25);
    rtb_Add_mm = rtb_Product1_a / rtb_Product3_e;
    rtb_Product8 = cos(rtb_Product3_e * 0.25);
    rtb_sqrt_jy = rtb_Product3_e * rtb_Product3_e;
    rtb_Product2_e = rtb_Product3_e * 0.25 - rtb_Product1_a;
    rtb_Product1_a = rt_powd_snf(rtb_Product3_e, 3.0);
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      for (i = 0; i < 3; i++) {
        rtb_MatrixMultiply1_tmp_0 = idxStart + 3 * i;
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] = 0.0;
        rtb_MatrixMultiply1_tmp = 3 * i + idxStart;
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] =
          rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp] + rtb_MatrixConcatenate3
          [3 * i] * rtb_MatrixConcatenate3[idxStart];
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] = rtb_MatrixConcatenate3
          [3 * i + 1] * rtb_MatrixConcatenate3[idxStart + 3] +
          rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp];
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] = rtb_MatrixConcatenate3
          [3 * i + 2] * rtb_MatrixConcatenate3[idxStart + 6] +
          rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Product5_b_0 = rtb_MathFunction1_f[3 * i];
      rtb_Product3_bh = rtb_MatrixConcatenate3[3 * i];
      rtb_Phi[6 * i] = (1.0 - rtb_Product8) * rtb_Product5_b_0 / rtb_sqrt_jy +
        ((real_T)b_I[3 * i] - rtb_Product3_bh * rtb_Add_mm);
      rtb_MatrixMultiply1_tmp = 6 * (i + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Product8) * rtb_Product3_bh
        / rtb_sqrt_jy - (real_T)b_a[3 * i] * 0.25) - rtb_Product5_b_0 *
        rtb_Product2_e / rtb_Product1_a;
      rtb_Phi[3 + 6 * i] = 0.0;
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_Phi[1 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Add_mm) + (1.0 - rtb_Product8) *
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] / rtb_sqrt_jy;
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Product8) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] / rtb_sqrt_jy -
        (real_T)b_a[rtb_MatrixMultiply1_tmp_0] * 0.25) -
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] * rtb_Product2_e /
        rtb_Product1_a;
      rtb_Phi[4 + 6 * i] = 0.0;
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_Phi[2 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Add_mm) + (1.0 - rtb_Product8) *
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] / rtb_sqrt_jy;
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Product8) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] / rtb_sqrt_jy -
        (real_T)b_a[rtb_MatrixMultiply1_tmp_0] * 0.25) -
        rtb_MathFunction1_f[rtb_MatrixMultiply1_tmp_0] * rtb_Product2_e /
        rtb_Product1_a;
      rtb_Phi[5 + 6 * i] = 0.0;
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
    }
  }

  /* End of MATLAB Function: '<S124>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S124>/MATLAB Function' incorporates:
   *  Constant: '<S124>/Constant13'
   */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      rtb_MatrixMultiply1_tmp_0 = i + 6 * idxStart;
      rtb_P_chol_p_merge_0[rtb_MatrixMultiply1_tmp_0] = 0.0;
      for (rtb_MatrixMultiply1_tmp = 0; rtb_MatrixMultiply1_tmp < 6;
           rtb_MatrixMultiply1_tmp++) {
        rtb_P_chol_p_merge_0[rtb_MatrixMultiply1_tmp_0] = rtb_P_chol_p_merge[6 *
          i + rtb_MatrixMultiply1_tmp] * rtb_Phi[6 * rtb_MatrixMultiply1_tmp +
          idxStart] + rtb_P_chol_p_merge_0[6 * idxStart + i];
      }
    }
  }

  for (idxStart = 0; idxStart < 6; idxStart++) {
    for (i = 0; i < 6; i++) {
      rtb_MatrixMultiply1_tmp = i + 12 * idxStart;
      C[rtb_MatrixMultiply1_tmp] = rtb_P_chol_p_merge_0[6 * idxStart + i];
      C[rtb_MatrixMultiply1_tmp + 6] = rtCP_Constant13_Value[6 * i + idxStart];
    }

    for (i = 0; i < 12; i++) {
      unusedU2[i + 12 * idxStart] = C[12 * idxStart + i];
      unusedU2[i + 12 * (idxStart + 6)] = 0.0;
    }
  }

  xgeqrf_oLvid02n(unusedU2, unusedExpr);
  for (idxStart = 0; idxStart < 6; idxStart++) {
    for (i = 0; i <= idxStart; i++) {
      C[i + 12 * idxStart] = unusedU2[12 * idxStart + i];
    }

    for (i = idxStart; i + 2 < 13; i++) {
      C[(i + 12 * idxStart) + 1] = 0.0;
    }
  }

  /* Trigonometry: '<S165>/Cos' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S165>/Constant'
   *  Product: '<S165>/Multiply'
   */
  rtb_Add_mm = cos(0.125 * rtb_Product3_e);

  /* SignalConversion: '<S165>/ConcatBufferAtMatrix ConcatenateIn1' */
  rtb_Merge_a[0] = rtb_Add_mm;

  /* If: '<S164>/If' */
  if (rtb_Product3_e < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* SignalConversion: '<S171>/OutportBuffer_InsertedFor_Psi_zero_at_inport_0' */
    rtb_MathFunction_n[0] = 0.0;
    rtb_MathFunction_n[1] = 0.0;
    rtb_MathFunction_n[2] = 0.0;

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
    rtb_Product1_pi = sin(0.125 * rtb_Product3_e);

    /* Product: '<S170>/Divide1' */
    rtb_MathFunction_n[0] = rtb_Product1_pi * rty_body_rates_radps[0] /
      rtb_Product3_e;
    rtb_MathFunction_n[1] = rtb_Product1_pi * rty_body_rates_radps[1] /
      rtb_Product3_e;
    rtb_MathFunction_n[2] = rtb_Product1_pi * rty_body_rates_radps[2] /
      rtb_Product3_e;

    /* End of Outputs for SubSystem: '<S164>/If Action Subsystem' */
  }

  /* End of If: '<S164>/If' */

  /* Math: '<S165>/Transpose2' incorporates:
   *  Gain: '<S165>/Gain'
   */
  rtb_Merge_a[1] = -rtb_MathFunction_n[0];
  rtb_Merge_a[2] = -rtb_MathFunction_n[1];
  rtb_Merge_a[3] = -rtb_MathFunction_n[2];

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_m(rtb_MathFunction_n, &rtb_MatrixConcatenate2_l[0]);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib' */

  /* S-Function (sdspdiag2): '<S123>/Extract Diagonal' */
  for (i = 0; i < 6; i++) {
    rtb_sigma[i] = rtb_P_chol_p_merge[i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S123>/Extract Diagonal' */

  /* Sum: '<S165>/Add1' incorporates:
   *  Product: '<S165>/Matrix Multiply2'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 3] = rtb_Add_mm * localDW->Id_3[i] -
      rtb_MatrixConcatenate2_l[i];
  }

  /* End of Sum: '<S165>/Add1' */

  /* SignalConversion: '<S165>/ConcatBufferAtMatrix Concatenate1In1' */
  rtb_VectorConcatenate[0] = rtb_MathFunction_n[0];
  rtb_VectorConcatenate[1] = rtb_MathFunction_n[1];
  rtb_VectorConcatenate[2] = rtb_MathFunction_n[2];
  for (i = 0; i < 6; i++) {
    /* Abs: '<S123>/Abs' incorporates:
     *  Sqrt: '<S123>/Sqrt'
     */
    rtb_sigma[i] = sqrt(fabs(rtb_sigma[i]));
  }

  /* Gain: '<S123>/multiply' */
  for (i = 0; i < 6; i++) {
    rty_threeSigma_rad[i] = 3.0 * rtb_sigma[i];
  }

  /* End of Gain: '<S123>/multiply' */

  /* Concatenate: '<S165>/Matrix Concatenate2' */
  for (i = 0; i < 4; i++) {
    idxStart = i << 2;
    rtb_MatrixConcatenate2_l[idxStart] = rtb_Merge_a[i];
    rtb_MatrixConcatenate2_l[1 + idxStart] = rtb_VectorConcatenate[3 * i];
    rtb_MatrixConcatenate2_l[2 + idxStart] = rtb_VectorConcatenate[3 * i + 1];
    rtb_MatrixConcatenate2_l[3 + idxStart] = rtb_VectorConcatenate[3 * i + 2];
  }

  /* End of Concatenate: '<S165>/Matrix Concatenate2' */

  /* Product: '<S124>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Product3_e = rtb_MatrixConcatenate2_l[i] * rty_sc_quat[0];
    rtb_Product3_e += rtb_MatrixConcatenate2_l[i + 4] * rty_sc_quat[1];
    rtb_Product3_e += rtb_MatrixConcatenate2_l[i + 8] * rty_sc_quat[2];
    rtb_Product3_e += rtb_MatrixConcatenate2_l[i + 12] * rty_sc_quat[3];
    rtb_Merge_a[i] = rtb_Product3_e;
  }

  /* End of Product: '<S124>/Product' */

  /* Sqrt: '<S172>/sqrt' incorporates:
   *  Product: '<S173>/Product'
   *  Product: '<S173>/Product1'
   *  Product: '<S173>/Product2'
   *  Product: '<S173>/Product3'
   *  Sum: '<S173>/Sum'
   */
  rtb_Add_mm = sqrt(((rtb_Merge_a[0] * rtb_Merge_a[0] + rtb_Merge_a[1] *
                      rtb_Merge_a[1]) + rtb_Merge_a[2] * rtb_Merge_a[2]) +
                    rtb_Merge_a[3] * rtb_Merge_a[3]);

  /* SignalConversion: '<S124>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S166>/Product'
   *  Product: '<S166>/Product1'
   *  Product: '<S166>/Product2'
   *  Product: '<S166>/Product3'
   */
  rtb_Merge_a[3] /= rtb_Add_mm;
  rtb_Merge_a[0] /= rtb_Add_mm;
  rtb_Merge_a[1] /= rtb_Add_mm;
  rtb_Merge_a[2] /= rtb_Add_mm;

  /* Outputs for Atomic SubSystem: '<S124>/quat_rectify_lib' */
  quat_rectify_lib(rtb_Merge_a, rtb_TmpSignalConversionAtquat_a);

  /* End of Outputs for SubSystem: '<S124>/quat_rectify_lib' */

  /* MATLABSystem: '<S121>/Moving Average' incorporates:
   *  DataTypeConversion: '<S121>/Cast To Double'
   */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    localDW->obj.pStatistic->pCumSum = 0.0;
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
    localDW->obj.pStatistic->isSetupComplete = true;
    localDW->obj.pStatistic->pCumSum = 0.0;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 9U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  rtb_Product3_e = localDW->obj.pStatistic->pCumRevIndex;
  rtb_Add_mm = localDW->obj.pStatistic->pCumSum;
  for (i = 0; i < 9; i++) {
    rtb_MatrixConcatenate3[i] = localDW->obj.pStatistic->pCumSumRev[i];
  }

  rtb_Add_mm += (real_T)rtb_Sum_fj;
  i = (int32_T)rtb_Product3_e - 1;
  rtb_Product1_pi = rtb_MatrixConcatenate3[i] + rtb_Add_mm;
  rtb_MatrixConcatenate3[i] = rtb_Sum_fj;
  if (rtb_Product3_e != 9.0) {
    rtb_Product3_e++;
  } else {
    rtb_Product3_e = 1.0;
    rtb_Add_mm = 0.0;
    for (i = 7; i >= 0; i--) {
      rtb_MatrixConcatenate3[i] += rtb_MatrixConcatenate3[i + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = rtb_Add_mm;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &rtb_MatrixConcatenate3[0], 9U
         * sizeof(real_T));
  localDW->obj.pStatistic->pCumRevIndex = rtb_Product3_e;

  /* Switch: '<S121>/Switch' incorporates:
   *  MATLABSystem: '<S121>/Moving Average'
   */
  if (rtb_Product1_pi / 10.0 >= 2.0) {
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

  /* If: '<S118>/If' incorporates:
   *  Constant: '<S128>/Constant'
   *  Inport: '<S130>/mekf_mode'
   *  RelationalOperator: '<S128>/Compare'
   */
  if (rtb_Switch_i4) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* SignalConversion: '<S129>/OutportBuffer_InsertedFor_mekf_triad_at_inport_0' incorporates:
     *  Constant: '<S129>/Constant'
     */
    *rty_mekf_telem = 3U;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem' */
  } else if (rtb_Sum_fj < 2) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_fj;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    /* SignalConversion: '<S131>/OutportBuffer_InsertedFor_mekf_nom_at_inport_0' incorporates:
     *  Constant: '<S131>/cnst'
     */
    *rty_mekf_telem = 0U;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem2' */
  }

  /* End of If: '<S118>/If' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S120>/Constant'
       *  MATLAB Function: '<S124>/MATLAB Function'
       */
      if (rtb_Switch_hl) {
        localDW->UnitDelay_DSTATE[idxStart + 6 * i] = rtCP_Constant_Value_ga[6 *
          i + idxStart];
      } else {
        localDW->UnitDelay_DSTATE[idxStart + 6 * i] = C[12 * idxStart + i];
      }

      /* End of Switch: '<S120>/Switch' */
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = rtb_TmpSignalConversionAtquat_a[0];
  localDW->UnitDelay3_DSTATE[1] = rtb_TmpSignalConversionAtquat_a[1];
  localDW->UnitDelay3_DSTATE[2] = rtb_TmpSignalConversionAtquat_a[2];
  localDW->UnitDelay3_DSTATE[3] = rtb_TmpSignalConversionAtquat_a[3];

  /* Update for If: '<S3>/TRIAD_activation' */
  if (localDW->TRIAD_activation_ActiveSubsyste == 0) {
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

  /* End of Update for If: '<S3>/TRIAD_activation' */

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
