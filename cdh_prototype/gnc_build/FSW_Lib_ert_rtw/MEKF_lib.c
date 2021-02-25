/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
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

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "mrdivide_helper_23K2DU9e.h"
#include "qr_c0VdrKOo.h"
#include "rt_powd_snf.h"
#include "xgeqrf_oLvid02n.h"

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
  TRIADActivation_lib_Init(&localDW->TRIADActivation_lib_a);

  /* End of SystemInitialize for SubSystem: '<S3>/TRIADActivation_lib' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S23>/Triad_alg' */
  /* SystemInitialize for Merge: '<S83>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S23>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[0] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S23>/Triad_alg' */
  /* SystemInitialize for Merge: '<S83>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S23>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S23>/Triad_alg' */
  /* SystemInitialize for Merge: '<S83>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S23>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S23>/Triad_alg' */
  /* SystemInitialize for Merge: '<S83>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S23>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[3] = 0.0;
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  /* Start for S-Function (sdspeye): '<S60>/Id_3' */
  memset(&localDW->Id_3[0], 0, 9U * sizeof(real_T));

  /* Fill in 1's on the diagonal. */
  localDW->Id_3[0] = 1.0;
  localDW->Id_3[4] = 1.0;
  localDW->Id_3[8] = 1.0;
}

/* Output and update for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib(const real_T rtu_sc2sun_eci_unit[3], const real_T rtu_mag_eci_T[3],
              const real_T rtu_sun_meas_body_unit[3], const real_T
              rtu_mag_meas_body_T[3], const real_T rtu_gyro_meas_body_radps[3],
              boolean_T rtu_sunsensor_valid, boolean_T rtu_mag_meas_valid,
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
  boolean_T rtb_Switch_ex;
  int8_T rtAction;
  uint8_T rtb_Sum_hy;
  real_T rtb_sigma[6];
  real_T rtb_MatrixConcatenate2_n[16];
  real_T rtb_MathFunction_iz[3];
  real_T rtb_Product3_mx;
  real_T rtb_MathFunction_m3[3];
  boolean_T rtb_Switch_g4;
  boolean_T rtb_Switch_l;
  real_T rtb_Product1_h4;
  real_T rtb_TmpSignalConversionAtquat_e[4];
  real_T rtb_Merge_bh[4];
  real_T rtb_Product3_n;
  real_T rtb_Product1_oy;
  real_T rtb_VectorConcatenate[12];
  real_T rtb_MatrixConcatenate3[9];
  int32_T idxStart;
  int32_T i;
  real_T rtb_MathFunction1_m[9];
  real_T rtb_Sum_k1;
  real_T rtb_P_cholmerge[36];
  real_T rtb_Phi[36];
  real_T rtb_MatrixMultiply1[9];
  real_T tmp[144];
  real_T rtb_P_cholmerge_0[36];
  real_T rtb_Product3_i[6];
  real_T rtu_sun_meas_body_unit_0[6];
  real_T rtb_Elementproduct_m_idx_5;
  real_T rtb_Elementproduct_m_idx_2;
  real_T rtb_Elementproduct_m_idx_1;
  boolean_T rtb_Sum_h_tmp;
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_0;
  real_T rtb_Product3_i_tmp;
  real_T rtb_Product3_i_tmp_0;
  real_T rtb_Product3_i_tmp_1;
  real_T unusedExpr[12];

  /* Outputs for Atomic SubSystem: '<S16>/parallel_protection_lib' */
  rtb_Switch_ex = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, 1.0E-5);

  /* End of Outputs for SubSystem: '<S16>/parallel_protection_lib' */

  /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
   *  ActionPort: '<S23>/Action Port'
   */
  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Logic: '<S16>/AND'
   *  Logic: '<S23>/Logical Operator'
   */
  rtb_Sum_h_tmp = (rtu_sunsensor_valid && rtu_mag_meas_valid);

  /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Logic: '<S16>/AND'
   */
  rtb_Sum_hy = (uint8_T)((uint32_T)(rtb_Sum_h_tmp && rtu_gryo_meas_valid) +
    rtb_Switch_ex);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_ex = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtu_sunsensor_valid, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_a);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S25>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_ex) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Sum: '<S71>/Sum of Elements' incorporates:
     *  Math: '<S71>/Math Function'
     */
    rtb_Product3_mx = (rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0] +
                       rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1]) +
      rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Math: '<S71>/Math Function1'
     *
     * About '<S71>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_mx < 0.0) {
      rtb_Product3_mx = -sqrt(fabs(rtb_Product3_mx));
    } else {
      rtb_Product3_mx = sqrt(rtb_Product3_mx);
    }

    /* End of Math: '<S71>/Math Function1' */

    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S71>/Constant'
     *  Product: '<S71>/Product'
     */
    if (rtb_Product3_mx > 0.0) {
      rtb_Merge_bh[0] = rtu_mag_meas_body_T[0];
      rtb_Merge_bh[1] = rtu_mag_meas_body_T[1];
      rtb_Merge_bh[2] = rtu_mag_meas_body_T[2];
      rtb_Merge_bh[3] = rtb_Product3_mx;
    } else {
      rtb_Merge_bh[0] = rtu_mag_meas_body_T[0] * 0.0;
      rtb_Merge_bh[1] = rtu_mag_meas_body_T[1] * 0.0;
      rtb_Merge_bh[2] = rtu_mag_meas_body_T[2] * 0.0;
      rtb_Merge_bh[3] = 1.0;
    }

    /* End of Switch: '<S71>/Switch' */

    /* Product: '<S71>/Divide' */
    rtb_MathFunction_iz[0] = rtb_Merge_bh[0] / rtb_Merge_bh[3];
    rtb_MathFunction_iz[1] = rtb_Merge_bh[1] / rtb_Merge_bh[3];
    rtb_MathFunction_iz[2] = rtb_Merge_bh[2] / rtb_Merge_bh[3];

    /* Sum: '<S70>/Sum of Elements' incorporates:
     *  Math: '<S70>/Math Function'
     */
    rtb_Product3_mx = (rtu_mag_eci_T[0] * rtu_mag_eci_T[0] + rtu_mag_eci_T[1] *
                       rtu_mag_eci_T[1]) + rtu_mag_eci_T[2] * rtu_mag_eci_T[2];

    /* Math: '<S70>/Math Function1'
     *
     * About '<S70>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_mx < 0.0) {
      rtb_Product3_mx = -sqrt(fabs(rtb_Product3_mx));
    } else {
      rtb_Product3_mx = sqrt(rtb_Product3_mx);
    }

    /* End of Math: '<S70>/Math Function1' */

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S70>/Constant'
     *  Product: '<S70>/Product'
     */
    if (rtb_Product3_mx > 0.0) {
      rtb_Merge_bh[0] = rtu_mag_eci_T[0];
      rtb_Merge_bh[1] = rtu_mag_eci_T[1];
      rtb_Merge_bh[2] = rtu_mag_eci_T[2];
      rtb_Merge_bh[3] = rtb_Product3_mx;
    } else {
      rtb_Merge_bh[0] = rtu_mag_eci_T[0] * 0.0;
      rtb_Merge_bh[1] = rtu_mag_eci_T[1] * 0.0;
      rtb_Merge_bh[2] = rtu_mag_eci_T[2] * 0.0;
      rtb_Merge_bh[3] = 1.0;
    }

    /* End of Switch: '<S70>/Switch' */

    /* Product: '<S70>/Divide' */
    rtb_MathFunction_m3[0] = rtb_Merge_bh[0] / rtb_Merge_bh[3];
    rtb_MathFunction_m3[1] = rtb_Merge_bh[1] / rtb_Merge_bh[3];
    rtb_MathFunction_m3[2] = rtb_Merge_bh[2] / rtb_Merge_bh[3];

    /* Outputs for Atomic SubSystem: '<S23>/parallel_protection_lib' */
    rtb_Switch_g4 = parallel_protection_lib(rtu_sun_meas_body_unit,
      rtb_MathFunction_iz, 1.0E-5);

    /* End of Outputs for SubSystem: '<S23>/parallel_protection_lib' */

    /* Outputs for Atomic SubSystem: '<S23>/parallel_protection_lib1' */
    rtb_Switch_l = parallel_protection_lib(rtu_sc2sun_eci_unit,
      rtb_MathFunction_m3, 1.0E-5);

    /* End of Outputs for SubSystem: '<S23>/parallel_protection_lib1' */

    /* If: '<S23>/If' incorporates:
     *  Inport: '<S69>/quat_old'
     *  Logic: '<S23>/Logical Operator'
     *  UnitDelay: '<S23>/Unit Delay'
     */
    if (rtb_Sum_h_tmp && rtb_Switch_g4 && rtb_Switch_l) {
      /* Outputs for IfAction SubSystem: '<S23>/Triad_alg' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* Product: '<S79>/Element product' */
      rtb_Elementproduct_m_idx_1 = rtu_sun_meas_body_unit[2] *
        rtb_MathFunction_iz[0];
      rtb_Elementproduct_m_idx_2 = rtu_sun_meas_body_unit[0] *
        rtb_MathFunction_iz[1];
      rtb_Elementproduct_m_idx_5 = rtu_sun_meas_body_unit[1] *
        rtb_MathFunction_iz[0];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];

      /* Sum: '<S79>/Add3' incorporates:
       *  Product: '<S79>/Element product'
       */
      rtb_MathFunction_iz[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[2]
        - rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[1];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];

      /* Sum: '<S79>/Add3' incorporates:
       *  Product: '<S79>/Element product'
       */
      rtb_MathFunction_iz[1] = rtb_Elementproduct_m_idx_1 -
        rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[2];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Sum: '<S79>/Add3' */
      rtb_MathFunction_iz[2] = rtb_Elementproduct_m_idx_2 -
        rtb_Elementproduct_m_idx_5;

      /* S-Function (sdsp2norm2): '<S73>/Normalization6' */
      rtb_Product3_mx = 1.0 / (sqrt((rtb_MathFunction_iz[0] *
        rtb_MathFunction_iz[0] + rtb_MathFunction_iz[1] * rtb_MathFunction_iz[1])
        + rtb_MathFunction_iz[2] * rtb_MathFunction_iz[2]) + 1.0E-10);

      /* Product: '<S81>/Element product' */
      rtb_Elementproduct_m_idx_1 = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3
        [0];
      rtb_Elementproduct_m_idx_2 = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3
        [1];
      rtb_Elementproduct_m_idx_5 = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3
        [0];

      /* S-Function (sdsp2norm2): '<S73>/Normalization6' */
      rtb_MathFunction_iz[0] *= rtb_Product3_mx;

      /* Sum: '<S81>/Add3' incorporates:
       *  Product: '<S81>/Element product'
       */
      rtb_MathFunction_m3[0] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[2] -
        rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[1];

      /* S-Function (sdsp2norm2): '<S73>/Normalization6' */
      rtb_MathFunction_iz[1] *= rtb_Product3_mx;

      /* Sum: '<S81>/Add3' incorporates:
       *  Product: '<S81>/Element product'
       */
      rtb_MathFunction_m3[1] = rtb_Elementproduct_m_idx_1 - rtu_sc2sun_eci_unit
        [0] * rtb_MathFunction_m3[2];

      /* S-Function (sdsp2norm2): '<S73>/Normalization6' */
      rtb_MathFunction_iz[2] *= rtb_Product3_mx;

      /* Sum: '<S81>/Add3' */
      rtb_MathFunction_m3[2] = rtb_Elementproduct_m_idx_2 -
        rtb_Elementproduct_m_idx_5;

      /* S-Function (sdsp2norm2): '<S73>/Normalization7' */
      rtb_Product3_mx = 1.0 / (sqrt((rtb_MathFunction_m3[0] *
        rtb_MathFunction_m3[0] + rtb_MathFunction_m3[1] * rtb_MathFunction_m3[1])
        + rtb_MathFunction_m3[2] * rtb_MathFunction_m3[2]) + 1.0E-10);
      rtb_MathFunction_m3[0] *= rtb_Product3_mx;
      rtb_MathFunction_m3[1] *= rtb_Product3_mx;
      rtb_MathFunction_m3[2] *= rtb_Product3_mx;

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[3] = rtb_MathFunction_m3[0];

      /* Sum: '<S82>/Add3' incorporates:
       *  Product: '<S82>/Element product'
       */
      rtb_MatrixConcatenate3[6] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[2]
        - rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[1];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[4] = rtb_MathFunction_m3[1];

      /* Sum: '<S82>/Add3' incorporates:
       *  Product: '<S82>/Element product'
       */
      rtb_MatrixConcatenate3[7] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[0]
        - rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3[2];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[5] = rtb_MathFunction_m3[2];

      /* Sum: '<S82>/Add3' incorporates:
       *  Product: '<S82>/Element product'
       */
      rtb_MatrixConcatenate3[8] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3[1]
        - rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[0];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[0] = rtu_sun_meas_body_unit[0];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[3] = rtb_MathFunction_iz[0];

      /* Sum: '<S80>/Add3' incorporates:
       *  Product: '<S80>/Element product'
       */
      rtb_MathFunction1_m[6] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[2]
        - rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[1];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[1] = rtu_sun_meas_body_unit[1];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[4] = rtb_MathFunction_iz[1];

      /* Sum: '<S80>/Add3' incorporates:
       *  Product: '<S80>/Element product'
       */
      rtb_MathFunction1_m[7] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[0]
        - rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[2];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[5] = rtb_MathFunction_iz[2];

      /* Sum: '<S80>/Add3' incorporates:
       *  Product: '<S80>/Element product'
       */
      rtb_MathFunction1_m[8] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[1]
        - rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[0];

      /* Product: '<S73>/Matrix Multiply1' incorporates:
       *  Math: '<S73>/Math Function1'
       */
      for (i = 0; i < 3; i++) {
        for (idxStart = 0; idxStart < 3; idxStart++) {
          rtb_MatrixMultiply1_tmp = i + 3 * idxStart;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = 0.0;
          rtb_MatrixMultiply1_tmp_0 = 3 * idxStart + i;
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_m[i] * rtb_MatrixConcatenate3[idxStart];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_m[i + 3] * rtb_MatrixConcatenate3[idxStart + 3];
          rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
            rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] +
            rtb_MathFunction1_m[i + 6] * rtb_MatrixConcatenate3[idxStart + 6];
        }
      }

      /* End of Product: '<S73>/Matrix Multiply1' */

      /* Sum: '<S87>/Add' */
      rtb_Elementproduct_m_idx_1 = (rtb_MatrixMultiply1[0] +
        rtb_MatrixMultiply1[4]) + rtb_MatrixMultiply1[8];

      /* If: '<S83>/If' */
      if (rtb_Elementproduct_m_idx_1 > 0.0) {
        /* Outputs for IfAction SubSystem: '<S83>/Positive Trace' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        PositiveTrace(rtb_Elementproduct_m_idx_1, rtb_MatrixMultiply1,
                      &localDW->Merge[0], &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S83>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S83>/Negative Trace' incorporates:
         *  ActionPort: '<S84>/Action Port'
         */
        NegativeTrace(rtb_MatrixMultiply1, localDW->Merge);

        /* End of Outputs for SubSystem: '<S83>/Negative Trace' */
      }

      /* End of If: '<S83>/If' */

      /* Signum: '<S73>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        rtb_Product3_mx = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        rtb_Product3_mx = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        rtb_Product3_mx = 0.0;
      } else {
        rtb_Product3_mx = (rtNaN);
      }

      /* End of Signum: '<S73>/Sign' */

      /* Product: '<S73>/Multiply' */
      rtb_Merge_bh[0] = rtb_Product3_mx * localDW->Merge[0];
      rtb_Merge_bh[1] = rtb_Product3_mx * localDW->Merge[1];
      rtb_Merge_bh[2] = rtb_Product3_mx * localDW->Merge[2];
      rtb_Merge_bh[3] = rtb_Product3_mx * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S23>/Triad_alg' */
    } else {
      /* Outputs for IfAction SubSystem: '<S23>/Bypass Triad' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      rtb_Merge_bh[0] = localDW->UnitDelay_DSTATE_p[0];
      rtb_Merge_bh[1] = localDW->UnitDelay_DSTATE_p[1];
      rtb_Merge_bh[2] = localDW->UnitDelay_DSTATE_p[2];
      rtb_Merge_bh[3] = localDW->UnitDelay_DSTATE_p[3];

      /* End of Outputs for SubSystem: '<S23>/Bypass Triad' */
    }

    /* End of If: '<S23>/If' */

    /* Sqrt: '<S77>/sqrt' incorporates:
     *  Product: '<S78>/Product'
     *  Product: '<S78>/Product1'
     *  Product: '<S78>/Product2'
     *  Product: '<S78>/Product3'
     *  Sum: '<S78>/Sum'
     */
    rtb_Elementproduct_m_idx_1 = sqrt(((rtb_Merge_bh[0] * rtb_Merge_bh[0] +
      rtb_Merge_bh[1] * rtb_Merge_bh[1]) + rtb_Merge_bh[2] * rtb_Merge_bh[2]) +
      rtb_Merge_bh[3] * rtb_Merge_bh[3]);

    /* SignalConversion: '<S23>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
     *  Product: '<S72>/Product'
     *  Product: '<S72>/Product1'
     *  Product: '<S72>/Product2'
     *  Product: '<S72>/Product3'
     *  Sqrt: '<S77>/sqrt'
     */
    rtb_TmpSignalConversionAtquat_e[0] = rtb_Merge_bh[0] /
      rtb_Elementproduct_m_idx_1;
    rtb_TmpSignalConversionAtquat_e[1] = rtb_Merge_bh[1] /
      rtb_Elementproduct_m_idx_1;
    rtb_TmpSignalConversionAtquat_e[2] = rtb_Merge_bh[2] /
      rtb_Elementproduct_m_idx_1;
    rtb_TmpSignalConversionAtquat_e[3] = rtb_Merge_bh[3] /
      rtb_Elementproduct_m_idx_1;

    /* Outputs for Atomic SubSystem: '<S23>/quat_rectify_lib' */
    quat_rectify_lib(rtb_TmpSignalConversionAtquat_e, rtb_Merge_bh);

    /* End of Outputs for SubSystem: '<S23>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */
  } else {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    rtb_Merge_bh[0] = localDW->UnitDelay3_DSTATE[0];
    rtb_Merge_bh[1] = localDW->UnitDelay3_DSTATE[1];
    rtb_Merge_bh[2] = localDW->UnitDelay3_DSTATE[2];
    rtb_Merge_bh[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
  }

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S15>/P_chol_m'
   *  Inport: '<S15>/bias_m'
   *  Inport: '<S15>/q_m'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_hy > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* SignalConversion: '<S30>/ConcatBufferAtVertical Matrix ConcatenateIn2' */
    memset(&rtb_P_cholmerge[18], 0, 18U * sizeof(real_T));

    /* Sqrt: '<S46>/sqrt' incorporates:
     *  Product: '<S47>/Product'
     *  Product: '<S47>/Product1'
     *  Product: '<S47>/Product2'
     *  Product: '<S47>/Product3'
     *  Sum: '<S47>/Sum'
     */
    rtb_Elementproduct_m_idx_5 = sqrt(((rtb_Merge_bh[0] * rtb_Merge_bh[0] +
      rtb_Merge_bh[1] * rtb_Merge_bh[1]) + rtb_Merge_bh[2] * rtb_Merge_bh[2]) +
      rtb_Merge_bh[3] * rtb_Merge_bh[3]);

    /* Product: '<S42>/Product2' incorporates:
     *  Sqrt: '<S46>/sqrt'
     */
    rtb_Product3_n = rtb_Merge_bh[2] / rtb_Elementproduct_m_idx_5;

    /* Product: '<S42>/Product3' incorporates:
     *  Sqrt: '<S46>/sqrt'
     */
    rtb_Product1_h4 = rtb_Merge_bh[3] / rtb_Elementproduct_m_idx_5;

    /* Product: '<S42>/Product1' incorporates:
     *  Sqrt: '<S46>/sqrt'
     */
    rtb_Elementproduct_m_idx_2 = rtb_Merge_bh[1] / rtb_Elementproduct_m_idx_5;

    /* Product: '<S42>/Product' incorporates:
     *  Sqrt: '<S46>/sqrt'
     */
    rtb_Elementproduct_m_idx_5 = rtb_Merge_bh[0] / rtb_Elementproduct_m_idx_5;

    /* Product: '<S43>/Product7' incorporates:
     *  Product: '<S44>/Product7'
     */
    rtb_Elementproduct_m_idx_1 = rtb_Product1_h4 * rtb_Product1_h4;

    /* Product: '<S43>/Product' incorporates:
     *  Product: '<S44>/Product'
     */
    rtb_Product3_i_tmp = rtb_Elementproduct_m_idx_2 * rtb_Product3_n;

    /* Product: '<S43>/Product1' incorporates:
     *  Product: '<S44>/Product1'
     */
    rtb_Product3_i_tmp_0 = rtb_Elementproduct_m_idx_5 * rtb_Product1_h4;

    /* Product: '<S43>/Product3' incorporates:
     *  Product: '<S45>/Product'
     */
    rtb_Product3_i_tmp_1 = rtb_Elementproduct_m_idx_2 * rtb_Product1_h4;

    /* Product: '<S43>/Product2' incorporates:
     *  Product: '<S45>/Product1'
     */
    rtb_Sum_k1 = rtb_Elementproduct_m_idx_5 * rtb_Product3_n;

    /* Product: '<S43>/Product6' incorporates:
     *  Product: '<S45>/Product7'
     */
    rtb_Product1_oy = rtb_Product3_n * rtb_Product3_n;

    /* Sum: '<S43>/Sum' incorporates:
     *  Constant: '<S43>/Constant'
     *  Gain: '<S43>/Gain'
     *  Gain: '<S43>/Gain1'
     *  Gain: '<S43>/Gain2'
     *  Product: '<S43>/Product'
     *  Product: '<S43>/Product1'
     *  Product: '<S43>/Product2'
     *  Product: '<S43>/Product3'
     *  Product: '<S43>/Product4'
     *  Product: '<S43>/Product5'
     *  Product: '<S43>/Product6'
     *  Product: '<S43>/Product7'
     *  Product: '<S43>/Product8'
     *  Sum: '<S43>/Sum1'
     *  Sum: '<S43>/Sum2'
     *  Sum: '<S43>/Sum3'
     */
    rtb_Product3_mx = (((0.5 - rtb_Product1_oy) - rtb_Elementproduct_m_idx_1) *
                       2.0 * rtu_sc2sun_eci_unit[0] + (rtb_Product3_i_tmp +
      rtb_Product3_i_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[1]) +
      (rtb_Product3_i_tmp_1 - rtb_Sum_k1) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Product: '<S44>/Product3' incorporates:
     *  Product: '<S45>/Product3'
     */
    rtb_Product3_n *= rtb_Product1_h4;

    /* Product: '<S44>/Product2' incorporates:
     *  Product: '<S45>/Product2'
     */
    rtb_Elementproduct_m_idx_5 *= rtb_Elementproduct_m_idx_2;

    /* Sum: '<S44>/Sum3' incorporates:
     *  Constant: '<S44>/Constant'
     *  Product: '<S44>/Product6'
     *  Sum: '<S45>/Sum3'
     */
    rtb_Elementproduct_m_idx_2 = 0.5 - rtb_Elementproduct_m_idx_2 *
      rtb_Elementproduct_m_idx_2;

    /* Sum: '<S44>/Sum' incorporates:
     *  Gain: '<S44>/Gain'
     *  Gain: '<S44>/Gain1'
     *  Gain: '<S44>/Gain2'
     *  Product: '<S44>/Product2'
     *  Product: '<S44>/Product3'
     *  Product: '<S44>/Product4'
     *  Product: '<S44>/Product5'
     *  Product: '<S44>/Product8'
     *  Sum: '<S44>/Sum1'
     *  Sum: '<S44>/Sum2'
     *  Sum: '<S44>/Sum3'
     */
    rtb_Elementproduct_m_idx_1 = ((rtb_Elementproduct_m_idx_2 -
      rtb_Elementproduct_m_idx_1) * 2.0 * rtu_sc2sun_eci_unit[1] +
      (rtb_Product3_i_tmp - rtb_Product3_i_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[0])
      + (rtb_Elementproduct_m_idx_5 + rtb_Product3_n) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S45>/Sum' incorporates:
     *  Gain: '<S45>/Gain'
     *  Gain: '<S45>/Gain1'
     *  Gain: '<S45>/Gain2'
     *  Product: '<S45>/Product4'
     *  Product: '<S45>/Product5'
     *  Product: '<S45>/Product8'
     *  Sum: '<S45>/Sum1'
     *  Sum: '<S45>/Sum2'
     *  Sum: '<S45>/Sum3'
     */
    rtb_Elementproduct_m_idx_5 = ((rtb_Product3_i_tmp_1 + rtb_Sum_k1) * 2.0 *
      rtu_sc2sun_eci_unit[0] + (rtb_Product3_n - rtb_Elementproduct_m_idx_5) *
      2.0 * rtu_sc2sun_eci_unit[1]) + (rtb_Elementproduct_m_idx_2 -
      rtb_Product1_oy) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Outputs for Atomic SubSystem: '<S30>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Elementproduct_m_idx_5, rtb_Product3_mx,
                        rtb_Elementproduct_m_idx_1, rtb_MatrixConcatenate3);

    /* End of Outputs for SubSystem: '<S30>/CrossProdMatrix_lib' */

    /* Sqrt: '<S52>/sqrt' incorporates:
     *  Product: '<S53>/Product'
     *  Product: '<S53>/Product1'
     *  Product: '<S53>/Product2'
     *  Product: '<S53>/Product3'
     *  Sum: '<S53>/Sum'
     */
    rtb_Product3_i_tmp_1 = sqrt(((rtb_Merge_bh[0] * rtb_Merge_bh[0] +
      rtb_Merge_bh[1] * rtb_Merge_bh[1]) + rtb_Merge_bh[2] * rtb_Merge_bh[2]) +
      rtb_Merge_bh[3] * rtb_Merge_bh[3]);

    /* Product: '<S48>/Product2' incorporates:
     *  Sqrt: '<S52>/sqrt'
     */
    rtb_Product1_oy = rtb_Merge_bh[2] / rtb_Product3_i_tmp_1;

    /* Product: '<S48>/Product3' incorporates:
     *  Sqrt: '<S52>/sqrt'
     */
    rtb_Elementproduct_m_idx_2 = rtb_Merge_bh[3] / rtb_Product3_i_tmp_1;

    /* Product: '<S48>/Product1' incorporates:
     *  Sqrt: '<S52>/sqrt'
     */
    rtb_Product1_h4 = rtb_Merge_bh[1] / rtb_Product3_i_tmp_1;

    /* Product: '<S48>/Product' incorporates:
     *  Sqrt: '<S52>/sqrt'
     */
    rtb_Product3_i_tmp_1 = rtb_Merge_bh[0] / rtb_Product3_i_tmp_1;

    /* Sum: '<S49>/Sum' incorporates:
     *  Constant: '<S49>/Constant'
     *  Gain: '<S49>/Gain'
     *  Gain: '<S49>/Gain1'
     *  Gain: '<S49>/Gain2'
     *  Product: '<S49>/Product'
     *  Product: '<S49>/Product1'
     *  Product: '<S49>/Product2'
     *  Product: '<S49>/Product3'
     *  Product: '<S49>/Product4'
     *  Product: '<S49>/Product5'
     *  Product: '<S49>/Product6'
     *  Product: '<S49>/Product7'
     *  Product: '<S49>/Product8'
     *  Sum: '<S49>/Sum1'
     *  Sum: '<S49>/Sum2'
     *  Sum: '<S49>/Sum3'
     */
    rtb_Product3_n = (((0.5 - rtb_Product1_oy * rtb_Product1_oy) -
                       rtb_Elementproduct_m_idx_2 * rtb_Elementproduct_m_idx_2) *
                      2.0 * rtu_mag_eci_T[0] + (rtb_Product1_h4 *
      rtb_Product1_oy + rtb_Product3_i_tmp_1 * rtb_Elementproduct_m_idx_2) * 2.0
                      * rtu_mag_eci_T[1]) + (rtb_Product1_h4 *
      rtb_Elementproduct_m_idx_2 - rtb_Product3_i_tmp_1 * rtb_Product1_oy) * 2.0
      * rtu_mag_eci_T[2];

    /* Sum: '<S50>/Sum' incorporates:
     *  Constant: '<S50>/Constant'
     *  Gain: '<S50>/Gain'
     *  Gain: '<S50>/Gain1'
     *  Gain: '<S50>/Gain2'
     *  Product: '<S50>/Product'
     *  Product: '<S50>/Product1'
     *  Product: '<S50>/Product2'
     *  Product: '<S50>/Product3'
     *  Product: '<S50>/Product4'
     *  Product: '<S50>/Product5'
     *  Product: '<S50>/Product6'
     *  Product: '<S50>/Product7'
     *  Product: '<S50>/Product8'
     *  Sum: '<S50>/Sum1'
     *  Sum: '<S50>/Sum2'
     *  Sum: '<S50>/Sum3'
     */
    rtb_Sum_k1 = (((0.5 - rtb_Product1_h4 * rtb_Product1_h4) -
                   rtb_Elementproduct_m_idx_2 * rtb_Elementproduct_m_idx_2) *
                  2.0 * rtu_mag_eci_T[1] + (rtb_Product1_h4 * rtb_Product1_oy -
      rtb_Product3_i_tmp_1 * rtb_Elementproduct_m_idx_2) * 2.0 * rtu_mag_eci_T[0])
      + (rtb_Product3_i_tmp_1 * rtb_Product1_h4 + rtb_Product1_oy *
         rtb_Elementproduct_m_idx_2) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S51>/Sum' incorporates:
     *  Constant: '<S51>/Constant'
     *  Gain: '<S51>/Gain'
     *  Gain: '<S51>/Gain1'
     *  Gain: '<S51>/Gain2'
     *  Product: '<S51>/Product'
     *  Product: '<S51>/Product1'
     *  Product: '<S51>/Product2'
     *  Product: '<S51>/Product3'
     *  Product: '<S51>/Product4'
     *  Product: '<S51>/Product5'
     *  Product: '<S51>/Product6'
     *  Product: '<S51>/Product7'
     *  Product: '<S51>/Product8'
     *  Sum: '<S51>/Sum1'
     *  Sum: '<S51>/Sum2'
     *  Sum: '<S51>/Sum3'
     */
    rtb_Product1_h4 = ((rtb_Product1_h4 * rtb_Elementproduct_m_idx_2 +
                        rtb_Product3_i_tmp_1 * rtb_Product1_oy) * 2.0 *
                       rtu_mag_eci_T[0] + (rtb_Product1_oy *
      rtb_Elementproduct_m_idx_2 - rtb_Product3_i_tmp_1 * rtb_Product1_h4) * 2.0
                       * rtu_mag_eci_T[1]) + ((0.5 - rtb_Product1_h4 *
      rtb_Product1_h4) - rtb_Product1_oy * rtb_Product1_oy) * 2.0 *
      rtu_mag_eci_T[2];

    /* Outputs for Atomic SubSystem: '<S30>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Product1_h4, rtb_Product3_n, rtb_Sum_k1,
                        rtb_MathFunction1_m);

    /* End of Outputs for SubSystem: '<S30>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S30>/Horizontal Matrix Concatenate' */
    for (i = 0; i < 3; i++) {
      rtb_P_cholmerge[6 * i] = rtb_MatrixConcatenate3[3 * i];
      rtb_P_cholmerge[3 + 6 * i] = rtb_MathFunction1_m[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_P_cholmerge[1 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0];
      rtb_P_cholmerge[4 + 6 * i] = rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_P_cholmerge[2 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0];
      rtb_P_cholmerge[5 + 6 * i] = rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0];
    }

    /* End of Concatenate: '<S30>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S19>/QR_factorization' incorporates:
     *  Constant: '<S19>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1_tmp = i + 6 * idxStart;
        rtb_Phi[rtb_MatrixMultiply1_tmp] = 0.0;
        for (rtb_MatrixMultiply1_tmp_0 = 0; rtb_MatrixMultiply1_tmp_0 < 6;
             rtb_MatrixMultiply1_tmp_0++) {
          rtb_Phi[rtb_MatrixMultiply1_tmp] = localDW->UnitDelay_DSTATE[6 * i +
            rtb_MatrixMultiply1_tmp_0] * rtb_P_cholmerge[6 *
            rtb_MatrixMultiply1_tmp_0 + idxStart] + rtb_Phi[6 * idxStart + i];
        }

        tmp[idxStart + 12 * i] = rtCP_Constant_Value_g[6 * idxStart + i];
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
        rtb_P_cholmerge[rtb_MatrixMultiply1_tmp] = R[12 * idxStart + i];
      }
    }

    mrdivide_helper_23K2DU9e(rtb_Phi, rtb_P_cholmerge);
    if (!rtu_gryo_meas_valid) {
      for (i = 0; i < 6; i++) {
        rtb_Phi[3 + 6 * i] = 0.0;
        rtb_Phi[4 + 6 * i] = 0.0;
        rtb_Phi[5 + 6 * i] = 0.0;
      }
    }

    /* Gain: '<S35>/Gain' */
    rtb_VectorConcatenate[0] = -rtb_Merge_bh[1];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_Merge_bh[0];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_Merge_bh[3];

    /* Gain: '<S35>/Gain1' */
    rtb_VectorConcatenate[3] = -rtb_Merge_bh[2];

    /* Gain: '<S35>/Gain2' */
    rtb_VectorConcatenate[4] = -rtb_Merge_bh[2];

    /* Gain: '<S35>/Gain3' */
    rtb_VectorConcatenate[5] = -rtb_Merge_bh[3];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_Merge_bh[0];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Merge_bh[1];

    /* Gain: '<S35>/Gain4' */
    rtb_VectorConcatenate[8] = -rtb_Merge_bh[3];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_Merge_bh[2];

    /* Gain: '<S35>/Gain5' */
    rtb_VectorConcatenate[10] = -rtb_Merge_bh[1];

    /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_Merge_bh[0];

    /* Sum: '<S19>/CreateMeasResidual' */
    rtb_sigma[0] = rtu_sun_meas_body_unit[0];
    rtb_sigma[3] = rtu_mag_meas_body_T[0];
    rtb_sigma[1] = rtu_sun_meas_body_unit[1];
    rtb_sigma[4] = rtu_mag_meas_body_T[1];
    rtb_sigma[2] = rtu_sun_meas_body_unit[2];
    rtb_sigma[5] = rtu_mag_meas_body_T[2];
    rtb_Product3_i[0] = rtb_Product3_mx;
    rtb_Product3_i[1] = rtb_Elementproduct_m_idx_1;
    rtb_Product3_i[2] = rtb_Elementproduct_m_idx_5;
    rtb_Product3_i[3] = rtb_Product3_n;
    rtb_Product3_i[4] = rtb_Sum_k1;
    rtb_Product3_i[5] = rtb_Product1_h4;
    for (i = 0; i < 6; i++) {
      /* SignalConversion: '<S19>/OutportBufferForP_chol_plus' incorporates:
       *  MATLAB Function: '<S19>/QR_factorization'
       */
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_P_cholmerge[idxStart + 6 * i] = R[((6 + idxStart) * 12 + i) + 6];
      }

      /* Sum: '<S19>/CreateMeasResidual' */
      rtu_sun_meas_body_unit_0[i] = rtb_sigma[i] - rtb_Product3_i[i];
    }

    /* Product: '<S19>/Product1' incorporates:
     *  MATLAB Function: '<S19>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      rtb_MathFunction1_m[i] = 0.0;
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MathFunction1_m[i] += rtb_Phi[6 * idxStart + i] *
          rtu_sun_meas_body_unit_0[idxStart];
      }
    }

    /* End of Product: '<S19>/Product1' */

    /* Sum: '<S19>/UpdatingBetaBias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rty_bias_radps[0] = rtb_MathFunction1_m[3] + localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = rtb_MathFunction1_m[4] + localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = rtb_MathFunction1_m[5] + localDW->UnitDelay1_DSTATE[2];

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S35>/Gain6'
     *  Product: '<S19>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_TmpSignalConversionAtquat_e[i] = ((rtb_VectorConcatenate[i + 4] * 0.5 *
        rtb_MathFunction1_m[1] + 0.5 * rtb_VectorConcatenate[i] *
        rtb_MathFunction1_m[0]) + rtb_VectorConcatenate[i + 8] * 0.5 *
        rtb_MathFunction1_m[2]) + rtb_Merge_bh[i];
    }

    /* End of Sum: '<S19>/Sum' */

    /* Sqrt: '<S40>/sqrt' incorporates:
     *  Product: '<S41>/Product'
     *  Product: '<S41>/Product1'
     *  Product: '<S41>/Product2'
     *  Product: '<S41>/Product3'
     *  Sum: '<S41>/Sum'
     */
    rtb_Product3_i_tmp_1 = sqrt(((rtb_TmpSignalConversionAtquat_e[0] *
      rtb_TmpSignalConversionAtquat_e[0] + rtb_TmpSignalConversionAtquat_e[1] *
      rtb_TmpSignalConversionAtquat_e[1]) + rtb_TmpSignalConversionAtquat_e[2] *
      rtb_TmpSignalConversionAtquat_e[2]) + rtb_TmpSignalConversionAtquat_e[3] *
      rtb_TmpSignalConversionAtquat_e[3]);

    /* Product: '<S32>/Product' */
    rty_sc_quat[0] = rtb_TmpSignalConversionAtquat_e[0] / rtb_Product3_i_tmp_1;

    /* Product: '<S32>/Product1' */
    rty_sc_quat[1] = rtb_TmpSignalConversionAtquat_e[1] / rtb_Product3_i_tmp_1;

    /* Product: '<S32>/Product2' */
    rty_sc_quat[2] = rtb_TmpSignalConversionAtquat_e[2] / rtb_Product3_i_tmp_1;

    /* Product: '<S32>/Product3' */
    rty_sc_quat[3] = rtb_TmpSignalConversionAtquat_e[3] / rtb_Product3_i_tmp_1;

    /* End of Outputs for SubSystem: '<S3>/MeasurementUpdate' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/BypassMeasUpdate' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    memcpy(&rtb_P_cholmerge[0], &localDW->UnitDelay_DSTATE[0], 36U * sizeof
           (real_T));
    rty_bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = localDW->UnitDelay1_DSTATE[2];
    rty_sc_quat[0] = rtb_Merge_bh[0];
    rty_sc_quat[1] = rtb_Merge_bh[1];
    rty_sc_quat[2] = rtb_Merge_bh[2];
    rty_sc_quat[3] = rtb_Merge_bh[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[0];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S22>/Sum' */
  rty_body_rates_radps[0] = rtb_Product3_mx - rty_bias_radps[0];

  /* Product: '<S22>/Matrix Multiply' incorporates:
   *  Math: '<S22>/Transpose'
   */
  rtb_Elementproduct_m_idx_1 = rty_body_rates_radps[0] * rty_body_rates_radps[0];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[1];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S22>/Sum' */
  rty_body_rates_radps[1] = rtb_Product3_mx - rty_bias_radps[1];

  /* Product: '<S22>/Matrix Multiply' incorporates:
   *  Math: '<S22>/Transpose'
   */
  rtb_Elementproduct_m_idx_1 += rty_body_rates_radps[1] * rty_body_rates_radps[1];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S22>/Sum' */
  rty_body_rates_radps[2] = rtb_Product3_mx - rty_bias_radps[2];

  /* Product: '<S22>/Matrix Multiply' incorporates:
   *  Math: '<S22>/Transpose'
   */
  rtb_Elementproduct_m_idx_1 += rty_body_rates_radps[2] * rty_body_rates_radps[2];

  /* Sqrt: '<S22>/Sqrt' incorporates:
   *  Product: '<S22>/Matrix Multiply'
   */
  rtb_Product3_mx = sqrt(rtb_Elementproduct_m_idx_1);

  /* Outputs for Atomic SubSystem: '<S22>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_d(rty_body_rates_radps, rtb_MatrixConcatenate3);

  /* End of Outputs for SubSystem: '<S22>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S22>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S22>/Constant'
   */
  if (rtb_Product3_mx < 1.0E-10) {
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
    rtb_Product3_n = sin(rtb_Product3_mx * 0.25);
    rtb_Elementproduct_m_idx_1 = rtb_Product3_n / rtb_Product3_mx;
    rtb_Elementproduct_m_idx_2 = cos(rtb_Product3_mx * 0.25);
    rtb_Elementproduct_m_idx_5 = rtb_Product3_mx * rtb_Product3_mx;
    rtb_Sum_k1 = rtb_Product3_mx * 0.25 - rtb_Product3_n;
    rtb_Product3_i_tmp_1 = rt_powd_snf(rtb_Product3_mx, 3.0);
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      for (i = 0; i < 3; i++) {
        rtb_MatrixMultiply1_tmp_0 = idxStart + 3 * i;
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] = 0.0;
        rtb_MatrixMultiply1_tmp = 3 * i + idxStart;
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] =
          rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp] + rtb_MatrixConcatenate3
          [3 * i] * rtb_MatrixConcatenate3[idxStart];
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] = rtb_MatrixConcatenate3
          [3 * i + 1] * rtb_MatrixConcatenate3[idxStart + 3] +
          rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp];
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] = rtb_MatrixConcatenate3
          [3 * i + 2] * rtb_MatrixConcatenate3[idxStart + 6] +
          rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Product3_n = rtb_MathFunction1_m[3 * i];
      rtb_Product1_h4 = rtb_MatrixConcatenate3[3 * i];
      rtb_Phi[6 * i] = (1.0 - rtb_Elementproduct_m_idx_2) * rtb_Product3_n /
        rtb_Elementproduct_m_idx_5 + ((real_T)b_I[3 * i] - rtb_Product1_h4 *
        rtb_Elementproduct_m_idx_1);
      rtb_MatrixMultiply1_tmp = 6 * (i + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_m_idx_2) *
        rtb_Product1_h4 / rtb_Elementproduct_m_idx_5 - (real_T)b_a[3 * i] * 0.25)
        - rtb_Product3_n * rtb_Sum_k1 / rtb_Product3_i_tmp_1;
      rtb_Phi[3 + 6 * i] = 0.0;
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_Phi[1 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Elementproduct_m_idx_1) + (1.0 -
        rtb_Elementproduct_m_idx_2) *
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_m_idx_5;
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_m_idx_2)
        * rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_m_idx_5 - (real_T)b_a[rtb_MatrixMultiply1_tmp_0] *
        0.25) - rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] * rtb_Sum_k1 /
        rtb_Product3_i_tmp_1;
      rtb_Phi[4 + 6 * i] = 0.0;
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_Phi[2 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Elementproduct_m_idx_1) + (1.0 -
        rtb_Elementproduct_m_idx_2) *
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_m_idx_5;
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_m_idx_2)
        * rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_m_idx_5 - (real_T)b_a[rtb_MatrixMultiply1_tmp_0] *
        0.25) - rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] * rtb_Sum_k1 /
        rtb_Product3_i_tmp_1;
      rtb_Phi[5 + 6 * i] = 0.0;
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
    }
  }

  /* End of MATLAB Function: '<S22>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
   *  Constant: '<S22>/Constant13'
   */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      rtb_MatrixMultiply1_tmp_0 = i + 6 * idxStart;
      rtb_P_cholmerge_0[rtb_MatrixMultiply1_tmp_0] = 0.0;
      for (rtb_MatrixMultiply1_tmp = 0; rtb_MatrixMultiply1_tmp < 6;
           rtb_MatrixMultiply1_tmp++) {
        rtb_P_cholmerge_0[rtb_MatrixMultiply1_tmp_0] = rtb_P_cholmerge[6 * i +
          rtb_MatrixMultiply1_tmp] * rtb_Phi[6 * rtb_MatrixMultiply1_tmp +
          idxStart] + rtb_P_cholmerge_0[6 * idxStart + i];
      }
    }
  }

  for (idxStart = 0; idxStart < 6; idxStart++) {
    for (i = 0; i < 6; i++) {
      rtb_MatrixMultiply1_tmp = i + 12 * idxStart;
      C[rtb_MatrixMultiply1_tmp] = rtb_P_cholmerge_0[6 * idxStart + i];
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

  /* Trigonometry: '<S60>/Cos' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S60>/Constant'
   *  Product: '<S60>/Multiply'
   */
  rtb_Elementproduct_m_idx_1 = cos(0.125 * rtb_Product3_mx);

  /* SignalConversion: '<S60>/ConcatBufferAtMatrix ConcatenateIn1' */
  rtb_Merge_bh[0] = rtb_Elementproduct_m_idx_1;

  /* If: '<S59>/If' */
  if (rtb_Product3_mx < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    /* SignalConversion: '<S66>/OutportBuffer_InsertedFor_Psi_zero_at_inport_0' */
    rtb_MathFunction_iz[0] = 0.0;
    rtb_MathFunction_iz[1] = 0.0;
    rtb_MathFunction_iz[2] = 0.0;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    /* Trigonometry: '<S65>/Sin' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S65>/Constant'
     *  Product: '<S65>/Divide'
     */
    rtb_Product1_h4 = sin(0.125 * rtb_Product3_mx);

    /* Product: '<S65>/Divide1' */
    rtb_MathFunction_iz[0] = rtb_Product1_h4 * rty_body_rates_radps[0] /
      rtb_Product3_mx;
    rtb_MathFunction_iz[1] = rtb_Product1_h4 * rty_body_rates_radps[1] /
      rtb_Product3_mx;
    rtb_MathFunction_iz[2] = rtb_Product1_h4 * rty_body_rates_radps[2] /
      rtb_Product3_mx;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
  }

  /* End of If: '<S59>/If' */

  /* Math: '<S60>/Transpose2' incorporates:
   *  Gain: '<S60>/Gain'
   */
  rtb_Merge_bh[1] = -rtb_MathFunction_iz[0];
  rtb_Merge_bh[2] = -rtb_MathFunction_iz[1];
  rtb_Merge_bh[3] = -rtb_MathFunction_iz[2];

  /* Outputs for Atomic SubSystem: '<S22>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_d(rtb_MathFunction_iz, &rtb_MatrixConcatenate2_n[0]);

  /* End of Outputs for SubSystem: '<S22>/CrossProdMatrix_lib' */

  /* S-Function (sdspdiag2): '<S21>/Extract Diagonal' */
  for (i = 0; i < 6; i++) {
    rtb_sigma[i] = rtb_P_cholmerge[i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S21>/Extract Diagonal' */

  /* Sum: '<S60>/Add1' incorporates:
   *  Product: '<S60>/Matrix Multiply2'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 3] = rtb_Elementproduct_m_idx_1 * localDW->Id_3[i]
      - rtb_MatrixConcatenate2_n[i];
  }

  /* End of Sum: '<S60>/Add1' */

  /* SignalConversion: '<S60>/ConcatBufferAtMatrix Concatenate1In1' */
  rtb_VectorConcatenate[0] = rtb_MathFunction_iz[0];
  rtb_VectorConcatenate[1] = rtb_MathFunction_iz[1];
  rtb_VectorConcatenate[2] = rtb_MathFunction_iz[2];
  for (i = 0; i < 6; i++) {
    /* Sqrt: '<S21>/Sqrt' incorporates:
     *  Abs: '<S21>/Abs'
     */
    rtb_Product3_mx = sqrt(fabs(rtb_sigma[i]));

    /* Gain: '<S21>/multiply' */
    rty_threeSigma_rad[i] = 3.0 * rtb_Product3_mx;

    /* Abs: '<S21>/Abs' */
    rtb_sigma[i] = rtb_Product3_mx;
  }

  /* Concatenate: '<S60>/Matrix Concatenate2' */
  for (i = 0; i < 4; i++) {
    idxStart = i << 2;
    rtb_MatrixConcatenate2_n[idxStart] = rtb_Merge_bh[i];
    rtb_MatrixConcatenate2_n[1 + idxStart] = rtb_VectorConcatenate[3 * i];
    rtb_MatrixConcatenate2_n[2 + idxStart] = rtb_VectorConcatenate[3 * i + 1];
    rtb_MatrixConcatenate2_n[3 + idxStart] = rtb_VectorConcatenate[3 * i + 2];
  }

  /* End of Concatenate: '<S60>/Matrix Concatenate2' */

  /* Product: '<S22>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Product3_mx = rtb_MatrixConcatenate2_n[i + 12] * rty_sc_quat[3] +
      (rtb_MatrixConcatenate2_n[i + 8] * rty_sc_quat[2] +
       (rtb_MatrixConcatenate2_n[i + 4] * rty_sc_quat[1] +
        rtb_MatrixConcatenate2_n[i] * rty_sc_quat[0]));
    rtb_Merge_bh[i] = rtb_Product3_mx;
  }

  /* End of Product: '<S22>/Product' */

  /* Sqrt: '<S67>/sqrt' incorporates:
   *  Product: '<S68>/Product'
   *  Product: '<S68>/Product1'
   *  Product: '<S68>/Product2'
   *  Product: '<S68>/Product3'
   *  Sum: '<S68>/Sum'
   */
  rtb_Elementproduct_m_idx_1 = sqrt(((rtb_Merge_bh[0] * rtb_Merge_bh[0] +
    rtb_Merge_bh[1] * rtb_Merge_bh[1]) + rtb_Merge_bh[2] * rtb_Merge_bh[2]) +
    rtb_Merge_bh[3] * rtb_Merge_bh[3]);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   *  Product: '<S61>/Product2'
   *  Product: '<S61>/Product3'
   */
  rtb_Merge_bh[3] /= rtb_Elementproduct_m_idx_1;
  rtb_Merge_bh[0] /= rtb_Elementproduct_m_idx_1;
  rtb_Merge_bh[1] /= rtb_Elementproduct_m_idx_1;
  rtb_Merge_bh[2] /= rtb_Elementproduct_m_idx_1;

  /* Outputs for Atomic SubSystem: '<S22>/quat_rectify_lib' */
  quat_rectify_lib(rtb_Merge_bh, rtb_TmpSignalConversionAtquat_e);

  /* End of Outputs for SubSystem: '<S22>/quat_rectify_lib' */

  /* If: '<S18>/If' incorporates:
   *  Constant: '<S26>/Constant'
   *  Inport: '<S28>/mekf_mode'
   *  RelationalOperator: '<S26>/Compare'
   */
  if (rtb_Switch_ex) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion: '<S27>/OutportBuffer_InsertedFor_mekf_triad_at_inport_0' incorporates:
     *  Constant: '<S27>/Constant'
     */
    *rty_mekf_telem = 3U;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
  } else if (rtb_Sum_hy < 2) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_hy;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* SignalConversion: '<S29>/OutportBuffer_InsertedFor_mekf_nom_at_inport_0' incorporates:
     *  Constant: '<S29>/cnst'
     */
    *rty_mekf_telem = 0U;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem2' */
  }

  /* End of If: '<S18>/If' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  MATLAB Function: '<S22>/MATLAB Function'
   */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      localDW->UnitDelay_DSTATE[idxStart + 6 * i] = C[12 * idxStart + i];
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE[0] = rty_bias_radps[0];
  localDW->UnitDelay1_DSTATE[1] = rty_bias_radps[1];
  localDW->UnitDelay1_DSTATE[2] = rty_bias_radps[2];

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = rtb_TmpSignalConversionAtquat_e[0];
  localDW->UnitDelay3_DSTATE[1] = rtb_TmpSignalConversionAtquat_e[1];
  localDW->UnitDelay3_DSTATE[2] = rtb_TmpSignalConversionAtquat_e[2];
  localDW->UnitDelay3_DSTATE[3] = rtb_TmpSignalConversionAtquat_e[3];

  /* If: '<S3>/TRIAD_activation' */
  if (rtAction == 0) {
    /* Update for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Update for UnitDelay: '<S23>/Unit Delay' */
    localDW->UnitDelay_DSTATE_p[0] = rtb_TmpSignalConversionAtquat_e[0];
    localDW->UnitDelay_DSTATE_p[1] = rtb_TmpSignalConversionAtquat_e[1];
    localDW->UnitDelay_DSTATE_p[2] = rtb_TmpSignalConversionAtquat_e[2];
    localDW->UnitDelay_DSTATE_p[3] = rtb_TmpSignalConversionAtquat_e[3];

    /* End of Update for SubSystem: '<S3>/Triad Estimator' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
