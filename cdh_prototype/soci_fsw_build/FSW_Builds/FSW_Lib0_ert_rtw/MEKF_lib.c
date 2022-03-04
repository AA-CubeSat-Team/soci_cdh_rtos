/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
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

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
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
  TRIADActivation_lib_Init(&localDW->TRIADActivation_lib_p);

  /* End of SystemInitialize for SubSystem: '<S3>/TRIADActivation_lib' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S124>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S187>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S124>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S124>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S187>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S124>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S124>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S187>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S124>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S124>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S187>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S124>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* SystemInitialize for Merge: '<S3>/q_p_merge' */
  rty_sc_quat[0] = 0.0;
  rty_sc_quat[1] = 0.0;
  rty_sc_quat[2] = 0.0;
  rty_sc_quat[3] = 0.0;

  /* InitializeConditions for MATLABSystem: '<S120>/Moving Average' */
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 9U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S120>/Moving Average' */
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  /* Start for If: '<S3>/TRIAD_activation' */
  localDW->TRIAD_activation_ActiveSubsyste = -1;

  /* Start for S-Function (sdspeye): '<S164>/Id_3' */
  memset(&localDW->Id_3[0], 0, 9U * sizeof(real_T));

  /* Fill in 1's on the diagonal. */
  localDW->Id_3[0] = 1.0;
  localDW->Id_3[4] = 1.0;
  localDW->Id_3[8] = 1.0;

  /* Start for MATLABSystem: '<S120>/Moving Average' */
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
              *rty_mekf_telem, const ConstB_MEKF_lib *localC, DW_MEKF_lib
              *localDW)
{
  int8_T Phi_22[9];
  int8_T b_I[9];
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T C[72];
  real_T unusedU2[144];
  real_T R[144];
  real_T rtb_MatrixConcatenate2_n[16];
  boolean_T rtb_Compare_cj;
  boolean_T rtb_Switch_d;
  uint8_T rtb_Sum_a;
  real_T rtb_sigma[6];
  real_T rtb_MathFunction_i[3];
  real_T rtb_Product3_po;
  boolean_T rtb_Switch_o;
  boolean_T rtb_Switch_lt;
  real_T rtb_Product2_l2;
  real_T rtb_Product1_k;
  real_T rtb_TmpSignalConversionAtquat_n[4];
  real_T rtb_Merge_ki[4];
  real_T rtb_Product8;
  real_T rtb_Product1_db;
  real_T rtb_Product3_a;
  real_T rtb_Product2_e;
  real_T rtb_Product1_ke;
  real_T rtb_sqrt;
  real_T rtb_VectorConcatenate[12];
  real_T rtb_Elementproduct_bi[6];
  int32_T idxStart;
  int32_T i;
  real_T rtb_MatrixConcatenate2[9];
  real_T rtb_Add_n;
  real_T rtb_P_chol_p_merge[36];
  real_T rtb_Phi[36];
  real_T rtb_MatrixMultiply1[9];
  real_T tmp[144];
  real_T rtb_P_chol_p_merge_0[36];
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_0;
  real_T rtb_Product5_0;
  real_T rtb_Product1_d_tmp;
  real_T rtb_sqrt_tmp;
  real_T rtb_sqrt_tmp_0;
  real_T unusedExpr[12];

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Constant: '<S116>/Constant'
   */
  rtb_Compare_cj = (rtu_sunsensor_valid != 0);

  /* Outputs for Atomic SubSystem: '<S114>/parallel_protection_lib' */
  rtb_Switch_d = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, 1.0);

  /* End of Outputs for SubSystem: '<S114>/parallel_protection_lib' */

  /* Sum: '<S114>/Sum' incorporates:
   *  Logic: '<S114>/AND'
   */
  rtb_Sum_a = (uint8_T)((uint32_T)(rtb_Compare_cj && rtu_mag_meas_valid &&
    rtu_gryo_meas_valid) + rtb_Switch_d);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_d = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtb_Compare_cj, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_p);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S126>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_d) {
    localDW->TRIAD_activation_ActiveSubsyste = 0;

    /* Outputs for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Math: '<S174>/Math Function' */
    rtb_MathFunction_i[0] = rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0];
    rtb_MathFunction_i[1] = rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1];
    rtb_MathFunction_i[2] = rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Sum: '<S174>/Sum of Elements' */
    rtb_Product3_po = (rtb_MathFunction_i[0] + rtb_MathFunction_i[1]) +
      rtb_MathFunction_i[2];

    /* Math: '<S174>/Math Function1'
     *
     * About '<S174>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_po < 0.0) {
      rtb_Product3_po = -sqrt(fabs(rtb_Product3_po));
    } else {
      rtb_Product3_po = sqrt(rtb_Product3_po);
    }

    /* End of Math: '<S174>/Math Function1' */

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     */
    if (rtb_Product3_po > 0.0) {
      rtb_Merge_ki[0] = rtu_mag_meas_body_T[0];
      rtb_Merge_ki[1] = rtu_mag_meas_body_T[1];
      rtb_Merge_ki[2] = rtu_mag_meas_body_T[2];
      rtb_Merge_ki[3] = rtb_Product3_po;
    } else {
      /* Product: '<S174>/Product' */
      rtb_MathFunction_i[0] = rtu_mag_meas_body_T[0] * 0.0;
      rtb_MathFunction_i[1] = rtu_mag_meas_body_T[1] * 0.0;
      rtb_MathFunction_i[2] = rtu_mag_meas_body_T[2] * 0.0;
      rtb_Merge_ki[0] = rtb_MathFunction_i[0];
      rtb_Merge_ki[1] = rtb_MathFunction_i[1];
      rtb_Merge_ki[2] = rtb_MathFunction_i[2];
      rtb_Merge_ki[3] = 1.0;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Product: '<S174>/Divide' */
    rtb_MathFunction_i[0] = rtb_Merge_ki[0] / rtb_Merge_ki[3];
    rtb_MathFunction_i[1] = rtb_Merge_ki[1] / rtb_Merge_ki[3];
    rtb_MathFunction_i[2] = rtb_Merge_ki[2] / rtb_Merge_ki[3];

    /* Outputs for Atomic SubSystem: '<S124>/parallel_protection_lib' */
    rtb_Switch_o = parallel_protection_lib(rtu_sun_meas_body_unit,
      rtb_MathFunction_i, 1.0);

    /* End of Outputs for SubSystem: '<S124>/parallel_protection_lib' */

    /* Outputs for Atomic SubSystem: '<S124>/parallel_protection_lib1' */
    rtb_Switch_lt = parallel_protection_lib1(&localC->parallel_protection_lib1_c,
      1.0);

    /* End of Outputs for SubSystem: '<S124>/parallel_protection_lib1' */

    /* If: '<S124>/If' incorporates:
     *  Inport: '<S177>/quat_old'
     *  Logic: '<S124>/Logical Operator'
     *  UnitDelay: '<S124>/Unit Delay'
     */
    if (rtb_Compare_cj && rtu_mag_meas_valid && rtb_Switch_o && rtb_Switch_lt) {
      /* Outputs for IfAction SubSystem: '<S124>/TriadAlgorithm' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Product: '<S183>/Element product' */
      rtb_Elementproduct_bi[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_i
        [2];
      rtb_Elementproduct_bi[1] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_i
        [0];
      rtb_Elementproduct_bi[2] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_i
        [1];
      rtb_Elementproduct_bi[3] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_i
        [1];
      rtb_Elementproduct_bi[4] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_i
        [2];
      rtb_Elementproduct_bi[5] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_i
        [0];

      /* Sum: '<S183>/Add3' */
      rtb_MathFunction_i[0] = rtb_Elementproduct_bi[0] - rtb_Elementproduct_bi[3];
      rtb_MathFunction_i[1] = rtb_Elementproduct_bi[1] - rtb_Elementproduct_bi[4];
      rtb_MathFunction_i[2] = rtb_Elementproduct_bi[2] - rtb_Elementproduct_bi[5];

      /* S-Function (sdsp2norm2): '<S176>/Normalization6' */
      rtb_Product3_po = 1.0 / (sqrt((rtb_MathFunction_i[0] * rtb_MathFunction_i
        [0] + rtb_MathFunction_i[1] * rtb_MathFunction_i[1]) +
        rtb_MathFunction_i[2] * rtb_MathFunction_i[2]) + 1.0E-10);
      rtb_MathFunction_i[0] *= rtb_Product3_po;
      rtb_MathFunction_i[1] *= rtb_Product3_po;
      rtb_MathFunction_i[2] *= rtb_Product3_po;

      /* SignalConversion: '<S176>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MatrixConcatenate2[0] = rtu_sun_meas_body_unit[0];
      rtb_MatrixConcatenate2[1] = rtu_sun_meas_body_unit[1];
      rtb_MatrixConcatenate2[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S176>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MatrixConcatenate2[3] = rtb_MathFunction_i[0];
      rtb_MatrixConcatenate2[4] = rtb_MathFunction_i[1];
      rtb_MatrixConcatenate2[5] = rtb_MathFunction_i[2];

      /* Product: '<S184>/Element product' */
      rtb_Elementproduct_bi[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_i
        [2];
      rtb_Elementproduct_bi[1] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_i
        [0];
      rtb_Elementproduct_bi[2] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_i
        [1];
      rtb_Elementproduct_bi[3] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_i
        [1];
      rtb_Elementproduct_bi[4] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_i
        [2];
      rtb_Elementproduct_bi[5] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_i
        [0];

      /* Sum: '<S184>/Add3' */
      rtb_MatrixConcatenate2[6] = rtb_Elementproduct_bi[0] -
        rtb_Elementproduct_bi[3];
      rtb_MatrixConcatenate2[7] = rtb_Elementproduct_bi[1] -
        rtb_Elementproduct_bi[4];
      rtb_MatrixConcatenate2[8] = rtb_Elementproduct_bi[2] -
        rtb_Elementproduct_bi[5];

      /* Product: '<S176>/Matrix Multiply1' */
      for (i = 0; i < 3; i++) {
        for (idxStart = 0; idxStart < 3; idxStart++) {
          rtb_MatrixMultiply1_tmp = idxStart + 3 * i;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = 0.0;
          rtb_MatrixMultiply1_tmp_0 = 3 * i + idxStart;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            localC->MathFunction1_a[3 * i] * rtb_MatrixConcatenate2[idxStart];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = localC->
            MathFunction1_a[3 * i + 1] * rtb_MatrixConcatenate2[idxStart + 3] +
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = localC->
            MathFunction1_a[3 * i + 2] * rtb_MatrixConcatenate2[idxStart + 6] +
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
        }
      }

      /* End of Product: '<S176>/Matrix Multiply1' */

      /* Sum: '<S191>/Add' */
      rtb_Add_n = (rtb_MatrixMultiply1[0] + rtb_MatrixMultiply1[4]) +
        rtb_MatrixMultiply1[8];

      /* If: '<S187>/If' */
      if (rtb_Add_n > 0.0) {
        /* Outputs for IfAction SubSystem: '<S187>/Positive Trace' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        PositiveTrace(rtb_Add_n, rtb_MatrixMultiply1, &localDW->Merge[0],
                      &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S187>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S187>/Negative Trace' incorporates:
         *  ActionPort: '<S188>/Action Port'
         */
        NegativeTrace(rtb_MatrixMultiply1, localDW->Merge);

        /* End of Outputs for SubSystem: '<S187>/Negative Trace' */
      }

      /* End of If: '<S187>/If' */

      /* Signum: '<S176>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        rtb_Product3_po = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        rtb_Product3_po = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        rtb_Product3_po = 0.0;
      } else {
        rtb_Product3_po = (rtNaN);
      }

      /* End of Signum: '<S176>/Sign' */

      /* Product: '<S176>/Multiply' */
      rtb_Merge_ki[0] = rtb_Product3_po * localDW->Merge[0];
      rtb_Merge_ki[1] = rtb_Product3_po * localDW->Merge[1];
      rtb_Merge_ki[2] = rtb_Product3_po * localDW->Merge[2];
      rtb_Merge_ki[3] = rtb_Product3_po * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S124>/TriadAlgorithm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S124>/TriadBypass' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      rtb_Merge_ki[0] = localDW->UnitDelay_DSTATE_k[0];
      rtb_Merge_ki[1] = localDW->UnitDelay_DSTATE_k[1];
      rtb_Merge_ki[2] = localDW->UnitDelay_DSTATE_k[2];
      rtb_Merge_ki[3] = localDW->UnitDelay_DSTATE_k[3];

      /* End of Outputs for SubSystem: '<S124>/TriadBypass' */
    }

    /* End of If: '<S124>/If' */

    /* Sqrt: '<S181>/sqrt' incorporates:
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     *  Product: '<S182>/Product2'
     *  Product: '<S182>/Product3'
     *  Sum: '<S182>/Sum'
     */
    rtb_Product3_po = sqrt(((rtb_Merge_ki[0] * rtb_Merge_ki[0] + rtb_Merge_ki[1]
      * rtb_Merge_ki[1]) + rtb_Merge_ki[2] * rtb_Merge_ki[2]) + rtb_Merge_ki[3] *
      rtb_Merge_ki[3]);

    /* SignalConversion: '<S124>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
     *  Product: '<S175>/Product'
     *  Product: '<S175>/Product1'
     *  Product: '<S175>/Product2'
     *  Product: '<S175>/Product3'
     *  Sqrt: '<S181>/sqrt'
     */
    rtb_TmpSignalConversionAtquat_n[0] = rtb_Merge_ki[0] / rtb_Product3_po;
    rtb_TmpSignalConversionAtquat_n[1] = rtb_Merge_ki[1] / rtb_Product3_po;
    rtb_TmpSignalConversionAtquat_n[2] = rtb_Merge_ki[2] / rtb_Product3_po;
    rtb_TmpSignalConversionAtquat_n[3] = rtb_Merge_ki[3] / rtb_Product3_po;

    /* Outputs for Atomic SubSystem: '<S124>/quat_rectify_lib' */
    quat_rectify_lib(rtb_TmpSignalConversionAtquat_n, rtb_Merge_ki);

    /* End of Outputs for SubSystem: '<S124>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/TriadEstimator_lib' */
  } else {
    localDW->TRIAD_activation_ActiveSubsyste = 1;

    /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    rtb_Merge_ki[0] = localDW->UnitDelay3_DSTATE[0];
    rtb_Merge_ki[1] = localDW->UnitDelay3_DSTATE[1];
    rtb_Merge_ki[2] = localDW->UnitDelay3_DSTATE[2];
    rtb_Merge_ki[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S115>/If Action Subsystem' */
  }

  /* End of If: '<S3>/TRIAD_activation' */

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S113>/P_chol_m'
   *  Inport: '<S113>/bias_m'
   *  Inport: '<S113>/q_m'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_a > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* SignalConversion: '<S131>/ConcatBufferAtVertical Matrix ConcatenateIn2' */
    memset(&rtb_P_chol_p_merge[18], 0, 18U * sizeof(real_T));

    /* Sqrt: '<S147>/sqrt' incorporates:
     *  Product: '<S148>/Product'
     *  Product: '<S148>/Product1'
     *  Product: '<S148>/Product2'
     *  Product: '<S148>/Product3'
     *  Sum: '<S148>/Sum'
     */
    rtb_Product5_0 = sqrt(((rtb_Merge_ki[0] * rtb_Merge_ki[0] + rtb_Merge_ki[1] *
      rtb_Merge_ki[1]) + rtb_Merge_ki[2] * rtb_Merge_ki[2]) + rtb_Merge_ki[3] *
                          rtb_Merge_ki[3]);

    /* Product: '<S143>/Product2' incorporates:
     *  Sqrt: '<S147>/sqrt'
     */
    rtb_Product3_a = rtb_Merge_ki[2] / rtb_Product5_0;

    /* Product: '<S143>/Product3' incorporates:
     *  Sqrt: '<S147>/sqrt'
     */
    rtb_Product1_db = rtb_Merge_ki[3] / rtb_Product5_0;

    /* Product: '<S144>/Product7' incorporates:
     *  Product: '<S145>/Product7'
     */
    rtb_Product1_k = rtb_Product1_db * rtb_Product1_db;

    /* Product: '<S144>/Product6' incorporates:
     *  Product: '<S146>/Product7'
     */
    rtb_Product2_l2 = rtb_Product3_a * rtb_Product3_a;

    /* Product: '<S144>/Product8' incorporates:
     *  Constant: '<S144>/Constant'
     *  Gain: '<S144>/Gain2'
     *  Product: '<S144>/Product6'
     *  Product: '<S144>/Product7'
     *  Sum: '<S144>/Sum3'
     */
    rtb_Product8 = ((0.5 - rtb_Product2_l2) - rtb_Product1_k) * 2.0 *
      rtu_sc2sun_eci_unit[0];

    /* Product: '<S143>/Product1' incorporates:
     *  Sqrt: '<S147>/sqrt'
     */
    rtb_Product2_e = rtb_Merge_ki[1] / rtb_Product5_0;

    /* Product: '<S143>/Product' incorporates:
     *  Sqrt: '<S147>/sqrt'
     */
    rtb_Product5_0 = rtb_Merge_ki[0] / rtb_Product5_0;

    /* Product: '<S144>/Product' incorporates:
     *  Product: '<S145>/Product'
     */
    rtb_Product1_d_tmp = rtb_Product2_e * rtb_Product3_a;

    /* Product: '<S144>/Product1' incorporates:
     *  Product: '<S145>/Product1'
     */
    rtb_Add_n = rtb_Product5_0 * rtb_Product1_db;

    /* Product: '<S144>/Product4' incorporates:
     *  Gain: '<S144>/Gain'
     *  Product: '<S144>/Product'
     *  Product: '<S144>/Product1'
     *  Sum: '<S144>/Sum1'
     */
    rtb_Product1_ke = (rtb_Product1_d_tmp + rtb_Add_n) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S144>/Product3' incorporates:
     *  Product: '<S146>/Product'
     */
    rtb_sqrt_tmp = rtb_Product2_e * rtb_Product1_db;

    /* Product: '<S144>/Product2' incorporates:
     *  Product: '<S146>/Product1'
     */
    rtb_sqrt_tmp_0 = rtb_Product5_0 * rtb_Product3_a;

    /* Product: '<S144>/Product5' incorporates:
     *  Gain: '<S144>/Gain1'
     *  Product: '<S144>/Product2'
     *  Product: '<S144>/Product3'
     *  Sum: '<S144>/Sum2'
     */
    rtb_sqrt = (rtb_sqrt_tmp - rtb_sqrt_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Sum: '<S144>/Sum' */
    rtb_Product3_po = (rtb_Product8 + rtb_Product1_ke) + rtb_sqrt;

    /* Product: '<S145>/Product4' incorporates:
     *  Gain: '<S145>/Gain'
     *  Sum: '<S145>/Sum1'
     */
    rtb_sqrt = (rtb_Product1_d_tmp - rtb_Add_n) * 2.0 * rtu_sc2sun_eci_unit[0];

    /* Sum: '<S145>/Sum3' incorporates:
     *  Constant: '<S145>/Constant'
     *  Product: '<S145>/Product6'
     *  Sum: '<S146>/Sum3'
     */
    rtb_Product1_d_tmp = 0.5 - rtb_Product2_e * rtb_Product2_e;

    /* Product: '<S145>/Product8' incorporates:
     *  Gain: '<S145>/Gain2'
     *  Sum: '<S145>/Sum3'
     */
    rtb_Product1_ke = (rtb_Product1_d_tmp - rtb_Product1_k) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S145>/Product3' incorporates:
     *  Product: '<S146>/Product3'
     */
    rtb_Product1_k = rtb_Product3_a * rtb_Product1_db;

    /* Product: '<S145>/Product2' incorporates:
     *  Product: '<S146>/Product2'
     */
    rtb_Product2_e *= rtb_Product5_0;

    /* Product: '<S145>/Product5' incorporates:
     *  Gain: '<S145>/Gain1'
     *  Product: '<S145>/Product2'
     *  Product: '<S145>/Product3'
     *  Sum: '<S145>/Sum2'
     */
    rtb_Product8 = (rtb_Product2_e + rtb_Product1_k) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S145>/Sum' */
    rtb_Add_n = (rtb_sqrt + rtb_Product1_ke) + rtb_Product8;

    /* Product: '<S146>/Product4' incorporates:
     *  Gain: '<S146>/Gain'
     *  Sum: '<S146>/Sum1'
     */
    rtb_sqrt = (rtb_sqrt_tmp + rtb_sqrt_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[0];

    /* Product: '<S146>/Product5' incorporates:
     *  Gain: '<S146>/Gain1'
     *  Sum: '<S146>/Sum2'
     */
    rtb_Product1_ke = (rtb_Product1_k - rtb_Product2_e) * 2.0 *
      rtu_sc2sun_eci_unit[1];

    /* Product: '<S146>/Product8' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Sum: '<S146>/Sum3'
     */
    rtb_Product2_e = (rtb_Product1_d_tmp - rtb_Product2_l2) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S146>/Sum' */
    rtb_Product1_k = (rtb_sqrt + rtb_Product1_ke) + rtb_Product2_e;

    /* Outputs for Atomic SubSystem: '<S131>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Product1_k, rtb_Product3_po, rtb_Add_n,
                        rtb_MatrixConcatenate2);

    /* End of Outputs for SubSystem: '<S131>/CrossProdMatrix_lib' */

    /* Sqrt: '<S153>/sqrt' incorporates:
     *  Product: '<S154>/Product'
     *  Product: '<S154>/Product1'
     *  Product: '<S154>/Product2'
     *  Product: '<S154>/Product3'
     *  Sum: '<S154>/Sum'
     */
    rtb_sqrt = sqrt(((rtb_Merge_ki[0] * rtb_Merge_ki[0] + rtb_Merge_ki[1] *
                      rtb_Merge_ki[1]) + rtb_Merge_ki[2] * rtb_Merge_ki[2]) +
                    rtb_Merge_ki[3] * rtb_Merge_ki[3]);

    /* Product: '<S149>/Product2' incorporates:
     *  Sqrt: '<S153>/sqrt'
     */
    rtb_Product1_ke = rtb_Merge_ki[2] / rtb_sqrt;

    /* Product: '<S149>/Product3' incorporates:
     *  Sqrt: '<S153>/sqrt'
     */
    rtb_Product2_e = rtb_Merge_ki[3] / rtb_sqrt;

    /* Product: '<S150>/Product8' incorporates:
     *  Constant: '<S150>/Constant'
     *  Gain: '<S150>/Gain2'
     *  Product: '<S150>/Product6'
     *  Product: '<S150>/Product7'
     *  Sum: '<S150>/Sum3'
     */
    rtb_Product3_a = ((0.5 - rtb_Product1_ke * rtb_Product1_ke) - rtb_Product2_e
                      * rtb_Product2_e) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S149>/Product1' incorporates:
     *  Sqrt: '<S153>/sqrt'
     */
    rtb_Product1_db = rtb_Merge_ki[1] / rtb_sqrt;

    /* Product: '<S149>/Product' incorporates:
     *  Sqrt: '<S153>/sqrt'
     */
    rtb_sqrt = rtb_Merge_ki[0] / rtb_sqrt;

    /* Product: '<S150>/Product4' incorporates:
     *  Gain: '<S150>/Gain'
     *  Product: '<S150>/Product'
     *  Product: '<S150>/Product1'
     *  Sum: '<S150>/Sum1'
     */
    rtb_Product8 = (rtb_Product1_db * rtb_Product1_ke + rtb_sqrt *
                    rtb_Product2_e) * 2.0 * rtu_mag_eci_T[1];

    /* Product: '<S150>/Product5' incorporates:
     *  Gain: '<S150>/Gain1'
     *  Product: '<S150>/Product2'
     *  Product: '<S150>/Product3'
     *  Sum: '<S150>/Sum2'
     */
    rtb_Product5_0 = (rtb_Product1_db * rtb_Product2_e - rtb_sqrt *
                      rtb_Product1_ke) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S150>/Sum' */
    rtb_Product2_l2 = (rtb_Product3_a + rtb_Product8) + rtb_Product5_0;

    /* Product: '<S151>/Product4' incorporates:
     *  Gain: '<S151>/Gain'
     *  Product: '<S151>/Product'
     *  Product: '<S151>/Product1'
     *  Sum: '<S151>/Sum1'
     */
    rtb_Product3_a = (rtb_Product1_db * rtb_Product1_ke - rtb_sqrt *
                      rtb_Product2_e) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S151>/Product8' incorporates:
     *  Constant: '<S151>/Constant'
     *  Gain: '<S151>/Gain2'
     *  Product: '<S151>/Product6'
     *  Product: '<S151>/Product7'
     *  Sum: '<S151>/Sum3'
     */
    rtb_Product8 = ((0.5 - rtb_Product1_db * rtb_Product1_db) - rtb_Product2_e *
                    rtb_Product2_e) * 2.0 * rtu_mag_eci_T[1];

    /* Product: '<S151>/Product5' incorporates:
     *  Gain: '<S151>/Gain1'
     *  Product: '<S151>/Product2'
     *  Product: '<S151>/Product3'
     *  Sum: '<S151>/Sum2'
     */
    rtb_Product5_0 = (rtb_sqrt * rtb_Product1_db + rtb_Product1_ke *
                      rtb_Product2_e) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S151>/Sum' */
    rtb_Product5_0 += rtb_Product3_a + rtb_Product8;

    /* Product: '<S152>/Product4' incorporates:
     *  Gain: '<S152>/Gain'
     *  Product: '<S152>/Product'
     *  Product: '<S152>/Product1'
     *  Sum: '<S152>/Sum1'
     */
    rtb_Product3_a = (rtb_Product1_db * rtb_Product2_e + rtb_sqrt *
                      rtb_Product1_ke) * 2.0 * rtu_mag_eci_T[0];

    /* Product: '<S152>/Product5' incorporates:
     *  Gain: '<S152>/Gain1'
     *  Product: '<S152>/Product2'
     *  Product: '<S152>/Product3'
     *  Sum: '<S152>/Sum2'
     */
    rtb_sqrt = (rtb_Product1_ke * rtb_Product2_e - rtb_sqrt * rtb_Product1_db) *
      2.0 * rtu_mag_eci_T[1];

    /* Product: '<S152>/Product8' incorporates:
     *  Constant: '<S152>/Constant'
     *  Gain: '<S152>/Gain2'
     *  Product: '<S152>/Product6'
     *  Product: '<S152>/Product7'
     *  Sum: '<S152>/Sum3'
     */
    rtb_Product1_ke = ((0.5 - rtb_Product1_db * rtb_Product1_db) -
                       rtb_Product1_ke * rtb_Product1_ke) * 2.0 * rtu_mag_eci_T
      [2];

    /* Sum: '<S152>/Sum' */
    rtb_Product3_a = (rtb_Product3_a + rtb_sqrt) + rtb_Product1_ke;

    /* Outputs for Atomic SubSystem: '<S131>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Product3_a, rtb_Product2_l2, rtb_Product5_0,
                        rtb_MatrixMultiply1);

    /* End of Outputs for SubSystem: '<S131>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S131>/Horizontal Matrix Concatenate' */
    for (i = 0; i < 3; i++) {
      rtb_P_chol_p_merge[6 * i] = rtb_MatrixConcatenate2[3 * i];
      rtb_P_chol_p_merge[3 + 6 * i] = rtb_MatrixMultiply1[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_P_chol_p_merge[1 + 6 * i] =
        rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp_0];
      rtb_P_chol_p_merge[4 + 6 * i] =
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_P_chol_p_merge[2 + 6 * i] =
        rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp_0];
      rtb_P_chol_p_merge[5 + 6 * i] =
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
    }

    /* End of Concatenate: '<S131>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S118>/QR_factorization' incorporates:
     *  Constant: '<S118>/Constant'
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

        tmp[idxStart + 12 * i] = rtCP_Constant_Value_ns[6 * idxStart + i];
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
        rtb_MatrixMultiply1_tmp_0 = idxStart + 6 * i;
        rtb_Phi[rtb_MatrixMultiply1_tmp_0] = R[(6 + idxStart) * 12 + i];
        rtb_P_chol_p_merge[rtb_MatrixMultiply1_tmp_0] = R[12 * idxStart + i];
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

    /* SignalConversion: '<S118>/OutportBufferForP_chol_plus' incorporates:
     *  MATLAB Function: '<S118>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_P_chol_p_merge[idxStart + 6 * i] = R[((6 + idxStart) * 12 + i) + 6];
      }
    }

    /* Gain: '<S136>/Gain' */
    rtb_VectorConcatenate[0] = -rtb_Merge_ki[1];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_Merge_ki[0];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_Merge_ki[3];

    /* Gain: '<S136>/Gain1' */
    rtb_VectorConcatenate[3] = -rtb_Merge_ki[2];

    /* Gain: '<S136>/Gain2' */
    rtb_VectorConcatenate[4] = -rtb_Merge_ki[2];

    /* Gain: '<S136>/Gain3' */
    rtb_VectorConcatenate[5] = -rtb_Merge_ki[3];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_Merge_ki[0];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Merge_ki[1];

    /* Gain: '<S136>/Gain4' */
    rtb_VectorConcatenate[8] = -rtb_Merge_ki[3];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_Merge_ki[2];

    /* Gain: '<S136>/Gain5' */
    rtb_VectorConcatenate[10] = -rtb_Merge_ki[1];

    /* SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_Merge_ki[0];

    /* Sum: '<S118>/CreateMeasResidual' */
    rtb_Elementproduct_bi[0] = rtu_sun_meas_body_unit[0] - rtb_Product3_po;
    rtb_Elementproduct_bi[1] = rtu_sun_meas_body_unit[1] - rtb_Add_n;
    rtb_Elementproduct_bi[2] = rtu_sun_meas_body_unit[2] - rtb_Product1_k;
    rtb_Elementproduct_bi[3] = rtu_mag_meas_body_T[0] - rtb_Product2_l2;
    rtb_Elementproduct_bi[4] = rtu_mag_meas_body_T[1] - rtb_Product5_0;
    rtb_Elementproduct_bi[5] = rtu_mag_meas_body_T[2] - rtb_Product3_a;

    /* Product: '<S118>/Product1' incorporates:
     *  MATLAB Function: '<S118>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      rtb_MatrixMultiply1[i] = 0.0;
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1[i] += rtb_Phi[6 * idxStart + i] *
          rtb_Elementproduct_bi[idxStart];
      }
    }

    /* End of Product: '<S118>/Product1' */

    /* Sum: '<S118>/Sum' incorporates:
     *  Gain: '<S136>/Gain6'
     *  Product: '<S118>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_TmpSignalConversionAtquat_n[i] = ((rtb_VectorConcatenate[i + 4] * 0.5 *
        rtb_MatrixMultiply1[1] + 0.5 * rtb_VectorConcatenate[i] *
        rtb_MatrixMultiply1[0]) + rtb_VectorConcatenate[i + 8] * 0.5 *
        rtb_MatrixMultiply1[2]) + rtb_Merge_ki[i];
    }

    /* End of Sum: '<S118>/Sum' */

    /* Sqrt: '<S141>/sqrt' incorporates:
     *  Product: '<S142>/Product'
     *  Product: '<S142>/Product1'
     *  Product: '<S142>/Product2'
     *  Product: '<S142>/Product3'
     *  Sum: '<S142>/Sum'
     */
    rtb_sqrt = sqrt(((rtb_TmpSignalConversionAtquat_n[0] *
                      rtb_TmpSignalConversionAtquat_n[0] +
                      rtb_TmpSignalConversionAtquat_n[1] *
                      rtb_TmpSignalConversionAtquat_n[1]) +
                     rtb_TmpSignalConversionAtquat_n[2] *
                     rtb_TmpSignalConversionAtquat_n[2]) +
                    rtb_TmpSignalConversionAtquat_n[3] *
                    rtb_TmpSignalConversionAtquat_n[3]);

    /* Product: '<S133>/Product' */
    rty_sc_quat[0] = rtb_TmpSignalConversionAtquat_n[0] / rtb_sqrt;

    /* Product: '<S133>/Product1' */
    rty_sc_quat[1] = rtb_TmpSignalConversionAtquat_n[1] / rtb_sqrt;

    /* Product: '<S133>/Product2' */
    rty_sc_quat[2] = rtb_TmpSignalConversionAtquat_n[2] / rtb_sqrt;

    /* Product: '<S133>/Product3' */
    rty_sc_quat[3] = rtb_TmpSignalConversionAtquat_n[3] / rtb_sqrt;

    /* Saturate: '<S118>/Saturation' incorporates:
     *  Sum: '<S118>/UpdatingBetaBias '
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_Product3_po = rtb_MatrixMultiply1[3] + localDW->UnitDelay1_DSTATE[0];
    if (rtb_Product3_po > 0.01745) {
      rty_bias_radps[0] = 0.01745;
    } else if (rtb_Product3_po < -0.01745) {
      rty_bias_radps[0] = -0.01745;
    } else {
      rty_bias_radps[0] = rtb_Product3_po;
    }

    rtb_Product3_po = rtb_MatrixMultiply1[4] + localDW->UnitDelay1_DSTATE[1];
    if (rtb_Product3_po > 0.01745) {
      rty_bias_radps[1] = 0.01745;
    } else if (rtb_Product3_po < -0.01745) {
      rty_bias_radps[1] = -0.01745;
    } else {
      rty_bias_radps[1] = rtb_Product3_po;
    }

    rtb_Product3_po = rtb_MatrixMultiply1[5] + localDW->UnitDelay1_DSTATE[2];
    if (rtb_Product3_po > 0.01745) {
      rty_bias_radps[2] = 0.01745;
    } else if (rtb_Product3_po < -0.01745) {
      rty_bias_radps[2] = -0.01745;
    } else {
      rty_bias_radps[2] = rtb_Product3_po;
    }

    /* End of Saturate: '<S118>/Saturation' */
    /* End of Outputs for SubSystem: '<S3>/MeasurementUpdate' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/BypassMeasUpdate' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    memcpy(&rtb_P_chol_p_merge[0], &localDW->UnitDelay_DSTATE[0], 36U * sizeof
           (real_T));
    rty_bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = localDW->UnitDelay1_DSTATE[2];
    rty_sc_quat[0] = rtb_Merge_ki[0];
    rty_sc_quat[1] = rtb_Merge_ki[1];
    rty_sc_quat[2] = rtb_Merge_ki[2];
    rty_sc_quat[3] = rtb_Merge_ki[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* RelationalOperator: '<S157>/Compare' incorporates:
   *  Constant: '<S155>/Constant'
   *  Constant: '<S157>/Constant'
   *  RelationalOperator: '<S155>/Compare'
   */
  rtb_Compare_cj = (rtb_Sum_a == 2);

  /* RelationalOperator: '<S156>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S156>/Delay Input1'
   *
   * Block description for '<S156>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Switch_o = ((int32_T)rtb_Compare_cj > (int32_T)localDW->DelayInput1_DSTATE);

  /* Switch: '<S3>/NullRatesIfGyroInvalid ' */
  if (rtu_gryo_meas_valid) {
    rtb_MathFunction_i[0] = rtu_gyro_meas_body_radps[0];
    rtb_MathFunction_i[1] = rtu_gyro_meas_body_radps[1];
    rtb_MathFunction_i[2] = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_MathFunction_i[0] = 0.0;
    rtb_MathFunction_i[1] = 0.0;
    rtb_MathFunction_i[2] = 0.0;
  }

  /* End of Switch: '<S3>/NullRatesIfGyroInvalid ' */

  /* Sum: '<S123>/Sum' */
  rtb_Product3_po = rtb_MathFunction_i[0] - rty_bias_radps[0];
  rtb_Add_n = rtb_MathFunction_i[1] - rty_bias_radps[1];
  rtb_Product1_ke = rtb_MathFunction_i[2] - rty_bias_radps[2];
  rty_body_rates_radps[0] = rtb_Product3_po;
  rty_body_rates_radps[1] = rtb_Add_n;
  rty_body_rates_radps[2] = rtb_Product1_ke;

  /* Math: '<S123>/Transpose' */
  rtb_MathFunction_i[0] = rty_body_rates_radps[0];
  rtb_MathFunction_i[1] = rty_body_rates_radps[1];
  rtb_MathFunction_i[2] = rty_body_rates_radps[2];

  /* Product: '<S123>/Matrix Multiply' */
  rtb_Product3_po = rty_body_rates_radps[0];
  rtb_Add_n = rty_body_rates_radps[1];
  rtb_Product1_ke = rty_body_rates_radps[2];

  /* Sqrt: '<S123>/Sqrt' incorporates:
   *  Product: '<S123>/Matrix Multiply'
   */
  rtb_Product3_po = sqrt((rtb_MathFunction_i[0] * rtb_Product3_po +
    rtb_MathFunction_i[1] * rtb_Add_n) + rtb_MathFunction_i[2] * rtb_Product1_ke);

  /* Outputs for Atomic SubSystem: '<S123>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_j(rty_body_rates_radps, rtb_MatrixConcatenate2);

  /* End of Outputs for SubSystem: '<S123>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S123>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S123>/Constant'
   */
  if (rtb_Product3_po < 1.0E-10) {
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
      rtb_MatrixMultiply1_tmp_0 = 6 * (idxStart + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp_0] = (real_T)a[3 * idxStart] * 0.25;
      rtb_Phi[3 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 1;
      rtb_Phi[1 + 6 * idxStart] = b_I[i];
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp_0] = (real_T)a[i] * 0.25;
      rtb_Phi[4 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 2;
      rtb_Phi[2 + 6 * idxStart] = b_I[i];
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp_0] = (real_T)a[i] * 0.25;
      rtb_Phi[5 + 6 * idxStart] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_MatrixMultiply1_tmp_0 = 6 * (i + 3);
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp_0] = Phi_22[3 * i];
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp_0] = Phi_22[3 * i + 1];
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp_0] = Phi_22[3 * i + 2];
    }
  } else {
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
      Phi_22[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    rtb_Product1_ke = sin(rtb_Product3_po * 0.25);
    rtb_Add_n = rtb_Product1_ke / rtb_Product3_po;
    rtb_Product8 = cos(rtb_Product3_po * 0.25);
    rtb_sqrt = rtb_Product3_po * rtb_Product3_po;
    rtb_Product2_e = rtb_Product3_po * 0.25 - rtb_Product1_ke;
    rtb_Product1_ke = rt_powd_snf(rtb_Product3_po, 3.0);
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      for (i = 0; i < 3; i++) {
        rtb_MatrixMultiply1_tmp = idxStart + 3 * i;
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = 0.0;
        rtb_MatrixMultiply1_tmp_0 = 3 * i + idxStart;
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
          rtb_MatrixConcatenate2[3 * i] * rtb_MatrixConcatenate2[idxStart];
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = rtb_MatrixConcatenate2[3 *
          i + 1] * rtb_MatrixConcatenate2[idxStart + 3] +
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = rtb_MatrixConcatenate2[3 *
          i + 2] * rtb_MatrixConcatenate2[idxStart + 6] +
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Product5_0 = rtb_MatrixMultiply1[3 * i];
      rtb_Product3_a = rtb_MatrixConcatenate2[3 * i];
      rtb_Phi[6 * i] = (1.0 - rtb_Product8) * rtb_Product5_0 / rtb_sqrt +
        ((real_T)b_I[3 * i] - rtb_Product3_a * rtb_Add_n);
      rtb_MatrixMultiply1_tmp_0 = 6 * (i + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp_0] = ((1.0 - rtb_Product8) *
        rtb_Product3_a / rtb_sqrt - (real_T)b_a[3 * i] * 0.25) - rtb_Product5_0 *
        rtb_Product2_e / rtb_Product1_ke;
      rtb_Phi[3 + 6 * i] = 0.0;
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp_0] = Phi_22[3 * i];
      rtb_MatrixMultiply1_tmp = 3 * i + 1;
      rtb_Phi[1 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp] -
                            rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp] *
                            rtb_Add_n) + (1.0 - rtb_Product8) *
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] / rtb_sqrt;
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp_0] = ((1.0 - rtb_Product8) *
        rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp] / rtb_sqrt - (real_T)
        b_a[rtb_MatrixMultiply1_tmp] * 0.25) -
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] * rtb_Product2_e /
        rtb_Product1_ke;
      rtb_Phi[4 + 6 * i] = 0.0;
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp_0] = Phi_22[rtb_MatrixMultiply1_tmp];
      rtb_MatrixMultiply1_tmp = 3 * i + 2;
      rtb_Phi[2 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp] -
                            rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp] *
                            rtb_Add_n) + (1.0 - rtb_Product8) *
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] / rtb_sqrt;
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp_0] = ((1.0 - rtb_Product8) *
        rtb_MatrixConcatenate2[rtb_MatrixMultiply1_tmp] / rtb_sqrt - (real_T)
        b_a[rtb_MatrixMultiply1_tmp] * 0.25) -
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] * rtb_Product2_e /
        rtb_Product1_ke;
      rtb_Phi[5 + 6 * i] = 0.0;
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp_0] = Phi_22[rtb_MatrixMultiply1_tmp];
    }
  }

  /* End of MATLAB Function: '<S123>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S123>/MATLAB Function' incorporates:
   *  Constant: '<S123>/Constant13'
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

  /* Trigonometry: '<S164>/Cos' incorporates:
   *  Constant: '<S123>/Constant'
   *  Constant: '<S164>/Constant'
   *  Product: '<S164>/Multiply'
   */
  rtb_Add_n = cos(0.125 * rtb_Product3_po);

  /* SignalConversion: '<S164>/ConcatBufferAtMatrix ConcatenateIn1' */
  rtb_Merge_ki[0] = rtb_Add_n;

  /* If: '<S163>/If' */
  if (rtb_Product3_po < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S163>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* SignalConversion: '<S170>/OutportBuffer_InsertedFor_Psi_zero_at_inport_0' */
    rtb_MathFunction_i[0] = 0.0;
    rtb_MathFunction_i[1] = 0.0;
    rtb_MathFunction_i[2] = 0.0;

    /* End of Outputs for SubSystem: '<S163>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S163>/If Action Subsystem' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    /* Trigonometry: '<S169>/Sin' incorporates:
     *  Constant: '<S123>/Constant'
     *  Constant: '<S169>/Constant'
     *  Product: '<S169>/Divide'
     */
    rtb_Product1_k = sin(0.125 * rtb_Product3_po);

    /* Product: '<S169>/Divide1' */
    rtb_MathFunction_i[0] = rtb_Product1_k * rty_body_rates_radps[0] /
      rtb_Product3_po;
    rtb_MathFunction_i[1] = rtb_Product1_k * rty_body_rates_radps[1] /
      rtb_Product3_po;
    rtb_MathFunction_i[2] = rtb_Product1_k * rty_body_rates_radps[2] /
      rtb_Product3_po;

    /* End of Outputs for SubSystem: '<S163>/If Action Subsystem' */
  }

  /* End of If: '<S163>/If' */

  /* Math: '<S164>/Transpose2' incorporates:
   *  Gain: '<S164>/Gain'
   */
  rtb_Merge_ki[1] = -rtb_MathFunction_i[0];
  rtb_Merge_ki[2] = -rtb_MathFunction_i[1];
  rtb_Merge_ki[3] = -rtb_MathFunction_i[2];

  /* Outputs for Atomic SubSystem: '<S123>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_j(rtb_MathFunction_i, &rtb_MatrixConcatenate2_n[0]);

  /* End of Outputs for SubSystem: '<S123>/CrossProdMatrix_lib' */

  /* S-Function (sdspdiag2): '<S122>/Extract Diagonal' */
  for (i = 0; i < 6; i++) {
    rtb_sigma[i] = rtb_P_chol_p_merge[i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S122>/Extract Diagonal' */

  /* Sum: '<S164>/Add1' incorporates:
   *  Product: '<S164>/Matrix Multiply2'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 3] = rtb_Add_n * localDW->Id_3[i] -
      rtb_MatrixConcatenate2_n[i];
  }

  /* End of Sum: '<S164>/Add1' */

  /* SignalConversion: '<S164>/ConcatBufferAtMatrix Concatenate1In1' */
  rtb_VectorConcatenate[0] = rtb_MathFunction_i[0];
  rtb_VectorConcatenate[1] = rtb_MathFunction_i[1];
  rtb_VectorConcatenate[2] = rtb_MathFunction_i[2];
  for (i = 0; i < 6; i++) {
    /* Abs: '<S122>/Abs' incorporates:
     *  Sqrt: '<S122>/Sqrt'
     */
    rtb_sigma[i] = sqrt(fabs(rtb_sigma[i]));
  }

  /* Gain: '<S122>/multiply' */
  for (i = 0; i < 6; i++) {
    rty_threeSigma_rad[i] = 3.0 * rtb_sigma[i];
  }

  /* End of Gain: '<S122>/multiply' */

  /* Concatenate: '<S164>/Matrix Concatenate2' */
  for (i = 0; i < 4; i++) {
    idxStart = i << 2;
    rtb_MatrixConcatenate2_n[idxStart] = rtb_Merge_ki[i];
    rtb_MatrixConcatenate2_n[1 + idxStart] = rtb_VectorConcatenate[3 * i];
    rtb_MatrixConcatenate2_n[2 + idxStart] = rtb_VectorConcatenate[3 * i + 1];
    rtb_MatrixConcatenate2_n[3 + idxStart] = rtb_VectorConcatenate[3 * i + 2];
  }

  /* End of Concatenate: '<S164>/Matrix Concatenate2' */

  /* Product: '<S123>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Product3_po = rtb_MatrixConcatenate2_n[i] * rty_sc_quat[0];
    rtb_Product3_po += rtb_MatrixConcatenate2_n[i + 4] * rty_sc_quat[1];
    rtb_Product3_po += rtb_MatrixConcatenate2_n[i + 8] * rty_sc_quat[2];
    rtb_Product3_po += rtb_MatrixConcatenate2_n[i + 12] * rty_sc_quat[3];
    rtb_Merge_ki[i] = rtb_Product3_po;
  }

  /* End of Product: '<S123>/Product' */

  /* Sqrt: '<S171>/sqrt' incorporates:
   *  Product: '<S172>/Product'
   *  Product: '<S172>/Product1'
   *  Product: '<S172>/Product2'
   *  Product: '<S172>/Product3'
   *  Sum: '<S172>/Sum'
   */
  rtb_Add_n = sqrt(((rtb_Merge_ki[0] * rtb_Merge_ki[0] + rtb_Merge_ki[1] *
                     rtb_Merge_ki[1]) + rtb_Merge_ki[2] * rtb_Merge_ki[2]) +
                   rtb_Merge_ki[3] * rtb_Merge_ki[3]);

  /* SignalConversion: '<S123>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S165>/Product'
   *  Product: '<S165>/Product1'
   *  Product: '<S165>/Product2'
   *  Product: '<S165>/Product3'
   */
  rtb_Merge_ki[3] /= rtb_Add_n;
  rtb_Merge_ki[0] /= rtb_Add_n;
  rtb_Merge_ki[1] /= rtb_Add_n;
  rtb_Merge_ki[2] /= rtb_Add_n;

  /* Outputs for Atomic SubSystem: '<S123>/quat_rectify_lib' */
  quat_rectify_lib(rtb_Merge_ki, rtb_TmpSignalConversionAtquat_n);

  /* End of Outputs for SubSystem: '<S123>/quat_rectify_lib' */

  /* MATLABSystem: '<S120>/Moving Average' incorporates:
   *  DataTypeConversion: '<S120>/Cast To Double'
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

  rtb_Product3_po = localDW->obj.pStatistic->pCumRevIndex;
  rtb_Add_n = localDW->obj.pStatistic->pCumSum;
  for (i = 0; i < 9; i++) {
    rtb_MatrixConcatenate2[i] = localDW->obj.pStatistic->pCumSumRev[i];
  }

  rtb_Add_n += (real_T)rtb_Sum_a;
  i = (int32_T)rtb_Product3_po - 1;
  rtb_Product1_k = rtb_MatrixConcatenate2[i] + rtb_Add_n;
  rtb_MatrixConcatenate2[i] = rtb_Sum_a;
  if (rtb_Product3_po != 9.0) {
    rtb_Product3_po++;
  } else {
    rtb_Product3_po = 1.0;
    rtb_Add_n = 0.0;
    for (i = 7; i >= 0; i--) {
      rtb_MatrixConcatenate2[i] += rtb_MatrixConcatenate2[i + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = rtb_Add_n;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &rtb_MatrixConcatenate2[0], 9U
         * sizeof(real_T));
  localDW->obj.pStatistic->pCumRevIndex = rtb_Product3_po;

  /* Switch: '<S120>/Switch' incorporates:
   *  MATLABSystem: '<S120>/Moving Average'
   */
  if (rtb_Product1_k / 10.0 >= 2.0) {
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

  /* End of Switch: '<S120>/Switch' */

  /* If: '<S117>/If' incorporates:
   *  Constant: '<S127>/Constant'
   *  Inport: '<S129>/mekf_mode'
   *  RelationalOperator: '<S127>/Compare'
   */
  if (rtb_Switch_d) {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    /* SignalConversion: '<S128>/OutportBuffer_InsertedFor_mekf_triad_at_inport_0' incorporates:
     *  Constant: '<S128>/Constant'
     */
    *rty_mekf_telem = 3U;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem' */
  } else if (rtb_Sum_a < 2) {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_a;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    /* SignalConversion: '<S130>/OutportBuffer_InsertedFor_mekf_nom_at_inport_0' incorporates:
     *  Constant: '<S130>/cnst'
     */
    *rty_mekf_telem = 0U;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem2' */
  }

  /* End of If: '<S117>/If' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      /* Switch: '<S119>/Switch' incorporates:
       *  Constant: '<S119>/Constant'
       *  MATLAB Function: '<S123>/MATLAB Function'
       */
      if (rtb_Switch_o) {
        localDW->UnitDelay_DSTATE[idxStart + 6 * i] = rtCP_Constant_Value_ml[6 *
          i + idxStart];
      } else {
        localDW->UnitDelay_DSTATE[idxStart + 6 * i] = C[12 * idxStart + i];
      }

      /* End of Switch: '<S119>/Switch' */
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = rtb_TmpSignalConversionAtquat_n[0];
  localDW->UnitDelay3_DSTATE[1] = rtb_TmpSignalConversionAtquat_n[1];
  localDW->UnitDelay3_DSTATE[2] = rtb_TmpSignalConversionAtquat_n[2];
  localDW->UnitDelay3_DSTATE[3] = rtb_TmpSignalConversionAtquat_n[3];

  /* Update for If: '<S3>/TRIAD_activation' */
  if (localDW->TRIAD_activation_ActiveSubsyste == 0) {
    /* Update for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Update for UnitDelay: '<S124>/Unit Delay' */
    localDW->UnitDelay_DSTATE_k[0] = rtb_TmpSignalConversionAtquat_n[0];
    localDW->UnitDelay_DSTATE_k[1] = rtb_TmpSignalConversionAtquat_n[1];
    localDW->UnitDelay_DSTATE_k[2] = rtb_TmpSignalConversionAtquat_n[2];
    localDW->UnitDelay_DSTATE_k[3] = rtb_TmpSignalConversionAtquat_n[3];

    /* End of Update for SubSystem: '<S3>/TriadEstimator_lib' */
  }

  /* End of Update for If: '<S3>/TRIAD_activation' */

  /* Update for UnitDelay: '<S156>/Delay Input1'
   *
   * Block description for '<S156>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_Compare_cj;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
