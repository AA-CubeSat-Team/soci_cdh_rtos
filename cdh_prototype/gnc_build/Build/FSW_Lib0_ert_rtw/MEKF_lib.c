/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
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

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
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
  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Triad_alg' */
  /* SystemInitialize for Merge: '<S173>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S113>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[0] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Triad_alg' */
  /* SystemInitialize for Merge: '<S173>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S113>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Triad_alg' */
  /* SystemInitialize for Merge: '<S173>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S113>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S113>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Triad_alg' */
  /* SystemInitialize for Merge: '<S173>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S113>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[3] = 0.0;
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  /* Start for S-Function (sdspeye): '<S150>/Id_3' */
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
  real_T rtb_Merge_e[4];
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
  real_T rtb_Elementproduct_idx_5;
  real_T rtb_Elementproduct_idx_2;
  real_T rtb_Elementproduct_idx_1;
  boolean_T rtb_Sum_hx_tmp;
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_0;
  real_T rtb_Product3_i_tmp;
  real_T rtb_Product3_i_tmp_0;
  real_T rtb_Product3_i_tmp_1;
  real_T unusedExpr[12];

  /* Outputs for Atomic SubSystem: '<S106>/parallel_protection_lib' */
  rtb_Switch_ex = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, 1.0E-5);

  /* End of Outputs for SubSystem: '<S106>/parallel_protection_lib' */

  /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
   *  ActionPort: '<S113>/Action Port'
   */
  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Logic: '<S106>/AND'
   *  Logic: '<S113>/Logical Operator'
   */
  rtb_Sum_hx_tmp = (rtu_sunsensor_valid && rtu_mag_meas_valid);

  /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */

  /* Sum: '<S106>/Sum' incorporates:
   *  Logic: '<S106>/AND'
   */
  rtb_Sum_hy = (uint8_T)((uint32_T)(rtb_Sum_hx_tmp && rtu_gryo_meas_valid) +
    rtb_Switch_ex);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_ex = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtu_sunsensor_valid, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_a);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S115>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_ex) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    /* Sum: '<S161>/Sum of Elements' incorporates:
     *  Math: '<S161>/Math Function'
     */
    rtb_Product3_mx = (rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0] +
                       rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1]) +
      rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Math: '<S161>/Math Function1'
     *
     * About '<S161>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_mx < 0.0) {
      rtb_Product3_mx = -sqrt(fabs(rtb_Product3_mx));
    } else {
      rtb_Product3_mx = sqrt(rtb_Product3_mx);
    }

    /* End of Math: '<S161>/Math Function1' */

    /* Switch: '<S161>/Switch' incorporates:
     *  Constant: '<S161>/Constant'
     *  Product: '<S161>/Product'
     */
    if (rtb_Product3_mx > 0.0) {
      rtb_Merge_e[0] = rtu_mag_meas_body_T[0];
      rtb_Merge_e[1] = rtu_mag_meas_body_T[1];
      rtb_Merge_e[2] = rtu_mag_meas_body_T[2];
      rtb_Merge_e[3] = rtb_Product3_mx;
    } else {
      rtb_Merge_e[0] = rtu_mag_meas_body_T[0] * 0.0;
      rtb_Merge_e[1] = rtu_mag_meas_body_T[1] * 0.0;
      rtb_Merge_e[2] = rtu_mag_meas_body_T[2] * 0.0;
      rtb_Merge_e[3] = 1.0;
    }

    /* End of Switch: '<S161>/Switch' */

    /* Product: '<S161>/Divide' */
    rtb_MathFunction_iz[0] = rtb_Merge_e[0] / rtb_Merge_e[3];
    rtb_MathFunction_iz[1] = rtb_Merge_e[1] / rtb_Merge_e[3];
    rtb_MathFunction_iz[2] = rtb_Merge_e[2] / rtb_Merge_e[3];

    /* Sum: '<S160>/Sum of Elements' incorporates:
     *  Math: '<S160>/Math Function'
     */
    rtb_Product3_mx = (rtu_mag_eci_T[0] * rtu_mag_eci_T[0] + rtu_mag_eci_T[1] *
                       rtu_mag_eci_T[1]) + rtu_mag_eci_T[2] * rtu_mag_eci_T[2];

    /* Math: '<S160>/Math Function1'
     *
     * About '<S160>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product3_mx < 0.0) {
      rtb_Product3_mx = -sqrt(fabs(rtb_Product3_mx));
    } else {
      rtb_Product3_mx = sqrt(rtb_Product3_mx);
    }

    /* End of Math: '<S160>/Math Function1' */

    /* Switch: '<S160>/Switch' incorporates:
     *  Constant: '<S160>/Constant'
     *  Product: '<S160>/Product'
     */
    if (rtb_Product3_mx > 0.0) {
      rtb_Merge_e[0] = rtu_mag_eci_T[0];
      rtb_Merge_e[1] = rtu_mag_eci_T[1];
      rtb_Merge_e[2] = rtu_mag_eci_T[2];
      rtb_Merge_e[3] = rtb_Product3_mx;
    } else {
      rtb_Merge_e[0] = rtu_mag_eci_T[0] * 0.0;
      rtb_Merge_e[1] = rtu_mag_eci_T[1] * 0.0;
      rtb_Merge_e[2] = rtu_mag_eci_T[2] * 0.0;
      rtb_Merge_e[3] = 1.0;
    }

    /* End of Switch: '<S160>/Switch' */

    /* Product: '<S160>/Divide' */
    rtb_MathFunction_m3[0] = rtb_Merge_e[0] / rtb_Merge_e[3];
    rtb_MathFunction_m3[1] = rtb_Merge_e[1] / rtb_Merge_e[3];
    rtb_MathFunction_m3[2] = rtb_Merge_e[2] / rtb_Merge_e[3];

    /* Outputs for Atomic SubSystem: '<S113>/parallel_protection_lib' */
    rtb_Switch_g4 = parallel_protection_lib(rtu_sun_meas_body_unit,
      rtb_MathFunction_iz, 1.0E-5);

    /* End of Outputs for SubSystem: '<S113>/parallel_protection_lib' */

    /* Outputs for Atomic SubSystem: '<S113>/parallel_protection_lib1' */
    rtb_Switch_l = parallel_protection_lib(rtu_sc2sun_eci_unit,
      rtb_MathFunction_m3, 1.0E-5);

    /* End of Outputs for SubSystem: '<S113>/parallel_protection_lib1' */

    /* If: '<S113>/If' incorporates:
     *  Inport: '<S159>/quat_old'
     *  Logic: '<S113>/Logical Operator'
     *  UnitDelay: '<S113>/Unit Delay'
     */
    if (rtb_Sum_hx_tmp && rtb_Switch_g4 && rtb_Switch_l) {
      /* Outputs for IfAction SubSystem: '<S113>/Triad_alg' incorporates:
       *  ActionPort: '<S163>/Action Port'
       */
      /* Product: '<S169>/Element product' */
      rtb_Elementproduct_idx_1 = rtu_sun_meas_body_unit[2] *
        rtb_MathFunction_iz[0];
      rtb_Elementproduct_idx_2 = rtu_sun_meas_body_unit[0] *
        rtb_MathFunction_iz[1];
      rtb_Elementproduct_idx_5 = rtu_sun_meas_body_unit[1] *
        rtb_MathFunction_iz[0];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];

      /* Sum: '<S169>/Add3' incorporates:
       *  Product: '<S169>/Element product'
       */
      rtb_MathFunction_iz[0] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[2]
        - rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[1];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];

      /* Sum: '<S169>/Add3' incorporates:
       *  Product: '<S169>/Element product'
       */
      rtb_MathFunction_iz[1] = rtb_Elementproduct_idx_1 -
        rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[2];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In1' */
      rtb_MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Sum: '<S169>/Add3' */
      rtb_MathFunction_iz[2] = rtb_Elementproduct_idx_2 -
        rtb_Elementproduct_idx_5;

      /* S-Function (sdsp2norm2): '<S163>/Normalization6' */
      rtb_Product3_mx = 1.0 / (sqrt((rtb_MathFunction_iz[0] *
        rtb_MathFunction_iz[0] + rtb_MathFunction_iz[1] * rtb_MathFunction_iz[1])
        + rtb_MathFunction_iz[2] * rtb_MathFunction_iz[2]) + 1.0E-10);

      /* Product: '<S171>/Element product' */
      rtb_Elementproduct_idx_1 = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[0];
      rtb_Elementproduct_idx_2 = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3[1];
      rtb_Elementproduct_idx_5 = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[0];

      /* S-Function (sdsp2norm2): '<S163>/Normalization6' */
      rtb_MathFunction_iz[0] *= rtb_Product3_mx;

      /* Sum: '<S171>/Add3' incorporates:
       *  Product: '<S171>/Element product'
       */
      rtb_MathFunction_m3[0] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[2] -
        rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[1];

      /* S-Function (sdsp2norm2): '<S163>/Normalization6' */
      rtb_MathFunction_iz[1] *= rtb_Product3_mx;

      /* Sum: '<S171>/Add3' incorporates:
       *  Product: '<S171>/Element product'
       */
      rtb_MathFunction_m3[1] = rtb_Elementproduct_idx_1 - rtu_sc2sun_eci_unit[0]
        * rtb_MathFunction_m3[2];

      /* S-Function (sdsp2norm2): '<S163>/Normalization6' */
      rtb_MathFunction_iz[2] *= rtb_Product3_mx;

      /* Sum: '<S171>/Add3' */
      rtb_MathFunction_m3[2] = rtb_Elementproduct_idx_2 -
        rtb_Elementproduct_idx_5;

      /* S-Function (sdsp2norm2): '<S163>/Normalization7' */
      rtb_Product3_mx = 1.0 / (sqrt((rtb_MathFunction_m3[0] *
        rtb_MathFunction_m3[0] + rtb_MathFunction_m3[1] * rtb_MathFunction_m3[1])
        + rtb_MathFunction_m3[2] * rtb_MathFunction_m3[2]) + 1.0E-10);
      rtb_MathFunction_m3[0] *= rtb_Product3_mx;
      rtb_MathFunction_m3[1] *= rtb_Product3_mx;
      rtb_MathFunction_m3[2] *= rtb_Product3_mx;

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[3] = rtb_MathFunction_m3[0];

      /* Sum: '<S172>/Add3' incorporates:
       *  Product: '<S172>/Element product'
       */
      rtb_MatrixConcatenate3[6] = rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[2]
        - rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[1];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[4] = rtb_MathFunction_m3[1];

      /* Sum: '<S172>/Add3' incorporates:
       *  Product: '<S172>/Element product'
       */
      rtb_MatrixConcatenate3[7] = rtu_sc2sun_eci_unit[2] * rtb_MathFunction_m3[0]
        - rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3[2];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[5] = rtb_MathFunction_m3[2];

      /* Sum: '<S172>/Add3' incorporates:
       *  Product: '<S172>/Element product'
       */
      rtb_MatrixConcatenate3[8] = rtu_sc2sun_eci_unit[0] * rtb_MathFunction_m3[1]
        - rtu_sc2sun_eci_unit[1] * rtb_MathFunction_m3[0];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[0] = rtu_sun_meas_body_unit[0];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[3] = rtb_MathFunction_iz[0];

      /* Sum: '<S170>/Add3' incorporates:
       *  Product: '<S170>/Element product'
       */
      rtb_MathFunction1_m[6] = rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[2]
        - rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[1];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[1] = rtu_sun_meas_body_unit[1];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[4] = rtb_MathFunction_iz[1];

      /* Sum: '<S170>/Add3' incorporates:
       *  Product: '<S170>/Element product'
       */
      rtb_MathFunction1_m[7] = rtu_sun_meas_body_unit[2] * rtb_MathFunction_iz[0]
        - rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[2];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In1' */
      rtb_MathFunction1_m[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S163>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_m[5] = rtb_MathFunction_iz[2];

      /* Sum: '<S170>/Add3' incorporates:
       *  Product: '<S170>/Element product'
       */
      rtb_MathFunction1_m[8] = rtu_sun_meas_body_unit[0] * rtb_MathFunction_iz[1]
        - rtu_sun_meas_body_unit[1] * rtb_MathFunction_iz[0];

      /* Product: '<S163>/Matrix Multiply1' incorporates:
       *  Math: '<S163>/Math Function1'
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

      /* End of Product: '<S163>/Matrix Multiply1' */

      /* Sum: '<S177>/Add' */
      rtb_Elementproduct_idx_1 = (rtb_MatrixMultiply1[0] + rtb_MatrixMultiply1[4])
        + rtb_MatrixMultiply1[8];

      /* If: '<S173>/If' */
      if (rtb_Elementproduct_idx_1 > 0.0) {
        /* Outputs for IfAction SubSystem: '<S173>/Positive Trace' incorporates:
         *  ActionPort: '<S175>/Action Port'
         */
        PositiveTrace(rtb_Elementproduct_idx_1, rtb_MatrixMultiply1,
                      &localDW->Merge[0], &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S173>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S173>/Negative Trace' incorporates:
         *  ActionPort: '<S174>/Action Port'
         */
        NegativeTrace(rtb_MatrixMultiply1, localDW->Merge);

        /* End of Outputs for SubSystem: '<S173>/Negative Trace' */
      }

      /* End of If: '<S173>/If' */

      /* Signum: '<S163>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        rtb_Product3_mx = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        rtb_Product3_mx = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        rtb_Product3_mx = 0.0;
      } else {
        rtb_Product3_mx = (rtNaN);
      }

      /* End of Signum: '<S163>/Sign' */

      /* Product: '<S163>/Multiply' */
      rtb_Merge_e[0] = rtb_Product3_mx * localDW->Merge[0];
      rtb_Merge_e[1] = rtb_Product3_mx * localDW->Merge[1];
      rtb_Merge_e[2] = rtb_Product3_mx * localDW->Merge[2];
      rtb_Merge_e[3] = rtb_Product3_mx * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S113>/Triad_alg' */
    } else {
      /* Outputs for IfAction SubSystem: '<S113>/Bypass Triad' incorporates:
       *  ActionPort: '<S159>/Action Port'
       */
      rtb_Merge_e[0] = localDW->UnitDelay_DSTATE_p[0];
      rtb_Merge_e[1] = localDW->UnitDelay_DSTATE_p[1];
      rtb_Merge_e[2] = localDW->UnitDelay_DSTATE_p[2];
      rtb_Merge_e[3] = localDW->UnitDelay_DSTATE_p[3];

      /* End of Outputs for SubSystem: '<S113>/Bypass Triad' */
    }

    /* End of If: '<S113>/If' */

    /* Sqrt: '<S167>/sqrt' incorporates:
     *  Product: '<S168>/Product'
     *  Product: '<S168>/Product1'
     *  Product: '<S168>/Product2'
     *  Product: '<S168>/Product3'
     *  Sum: '<S168>/Sum'
     */
    rtb_Elementproduct_idx_1 = sqrt(((rtb_Merge_e[0] * rtb_Merge_e[0] +
      rtb_Merge_e[1] * rtb_Merge_e[1]) + rtb_Merge_e[2] * rtb_Merge_e[2]) +
      rtb_Merge_e[3] * rtb_Merge_e[3]);

    /* SignalConversion: '<S113>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
     *  Product: '<S162>/Product'
     *  Product: '<S162>/Product1'
     *  Product: '<S162>/Product2'
     *  Product: '<S162>/Product3'
     *  Sqrt: '<S167>/sqrt'
     */
    rtb_TmpSignalConversionAtquat_e[0] = rtb_Merge_e[0] /
      rtb_Elementproduct_idx_1;
    rtb_TmpSignalConversionAtquat_e[1] = rtb_Merge_e[1] /
      rtb_Elementproduct_idx_1;
    rtb_TmpSignalConversionAtquat_e[2] = rtb_Merge_e[2] /
      rtb_Elementproduct_idx_1;
    rtb_TmpSignalConversionAtquat_e[3] = rtb_Merge_e[3] /
      rtb_Elementproduct_idx_1;

    /* Outputs for Atomic SubSystem: '<S113>/quat_rectify_lib' */
    quat_rectify_lib(rtb_TmpSignalConversionAtquat_e, rtb_Merge_e);

    /* End of Outputs for SubSystem: '<S113>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */
  } else {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S107>/If Action Subsystem' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    rtb_Merge_e[0] = localDW->UnitDelay3_DSTATE[0];
    rtb_Merge_e[1] = localDW->UnitDelay3_DSTATE[1];
    rtb_Merge_e[2] = localDW->UnitDelay3_DSTATE[2];
    rtb_Merge_e[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S107>/If Action Subsystem' */
  }

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S105>/P_chol_m'
   *  Inport: '<S105>/bias_m'
   *  Inport: '<S105>/q_m'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_hy > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    /* SignalConversion: '<S120>/ConcatBufferAtVertical Matrix ConcatenateIn2' */
    memset(&rtb_P_cholmerge[18], 0, 18U * sizeof(real_T));

    /* Sqrt: '<S136>/sqrt' incorporates:
     *  Product: '<S137>/Product'
     *  Product: '<S137>/Product1'
     *  Product: '<S137>/Product2'
     *  Product: '<S137>/Product3'
     *  Sum: '<S137>/Sum'
     */
    rtb_Elementproduct_idx_5 = sqrt(((rtb_Merge_e[0] * rtb_Merge_e[0] +
      rtb_Merge_e[1] * rtb_Merge_e[1]) + rtb_Merge_e[2] * rtb_Merge_e[2]) +
      rtb_Merge_e[3] * rtb_Merge_e[3]);

    /* Product: '<S132>/Product2' incorporates:
     *  Sqrt: '<S136>/sqrt'
     */
    rtb_Product3_n = rtb_Merge_e[2] / rtb_Elementproduct_idx_5;

    /* Product: '<S132>/Product3' incorporates:
     *  Sqrt: '<S136>/sqrt'
     */
    rtb_Product1_h4 = rtb_Merge_e[3] / rtb_Elementproduct_idx_5;

    /* Product: '<S132>/Product1' incorporates:
     *  Sqrt: '<S136>/sqrt'
     */
    rtb_Elementproduct_idx_2 = rtb_Merge_e[1] / rtb_Elementproduct_idx_5;

    /* Product: '<S132>/Product' incorporates:
     *  Sqrt: '<S136>/sqrt'
     */
    rtb_Elementproduct_idx_5 = rtb_Merge_e[0] / rtb_Elementproduct_idx_5;

    /* Product: '<S133>/Product7' incorporates:
     *  Product: '<S134>/Product7'
     */
    rtb_Elementproduct_idx_1 = rtb_Product1_h4 * rtb_Product1_h4;

    /* Product: '<S133>/Product' incorporates:
     *  Product: '<S134>/Product'
     */
    rtb_Product3_i_tmp = rtb_Elementproduct_idx_2 * rtb_Product3_n;

    /* Product: '<S133>/Product1' incorporates:
     *  Product: '<S134>/Product1'
     */
    rtb_Product3_i_tmp_0 = rtb_Elementproduct_idx_5 * rtb_Product1_h4;

    /* Product: '<S133>/Product3' incorporates:
     *  Product: '<S135>/Product'
     */
    rtb_Product3_i_tmp_1 = rtb_Elementproduct_idx_2 * rtb_Product1_h4;

    /* Product: '<S133>/Product2' incorporates:
     *  Product: '<S135>/Product1'
     */
    rtb_Sum_k1 = rtb_Elementproduct_idx_5 * rtb_Product3_n;

    /* Product: '<S133>/Product6' incorporates:
     *  Product: '<S135>/Product7'
     */
    rtb_Product1_oy = rtb_Product3_n * rtb_Product3_n;

    /* Sum: '<S133>/Sum' incorporates:
     *  Constant: '<S133>/Constant'
     *  Gain: '<S133>/Gain'
     *  Gain: '<S133>/Gain1'
     *  Gain: '<S133>/Gain2'
     *  Product: '<S133>/Product'
     *  Product: '<S133>/Product1'
     *  Product: '<S133>/Product2'
     *  Product: '<S133>/Product3'
     *  Product: '<S133>/Product4'
     *  Product: '<S133>/Product5'
     *  Product: '<S133>/Product6'
     *  Product: '<S133>/Product7'
     *  Product: '<S133>/Product8'
     *  Sum: '<S133>/Sum1'
     *  Sum: '<S133>/Sum2'
     *  Sum: '<S133>/Sum3'
     */
    rtb_Product3_mx = (((0.5 - rtb_Product1_oy) - rtb_Elementproduct_idx_1) *
                       2.0 * rtu_sc2sun_eci_unit[0] + (rtb_Product3_i_tmp +
      rtb_Product3_i_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[1]) +
      (rtb_Product3_i_tmp_1 - rtb_Sum_k1) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Product: '<S134>/Product3' incorporates:
     *  Product: '<S135>/Product3'
     */
    rtb_Product3_n *= rtb_Product1_h4;

    /* Product: '<S134>/Product2' incorporates:
     *  Product: '<S135>/Product2'
     */
    rtb_Elementproduct_idx_5 *= rtb_Elementproduct_idx_2;

    /* Sum: '<S134>/Sum3' incorporates:
     *  Constant: '<S134>/Constant'
     *  Product: '<S134>/Product6'
     *  Sum: '<S135>/Sum3'
     */
    rtb_Elementproduct_idx_2 = 0.5 - rtb_Elementproduct_idx_2 *
      rtb_Elementproduct_idx_2;

    /* Sum: '<S134>/Sum' incorporates:
     *  Gain: '<S134>/Gain'
     *  Gain: '<S134>/Gain1'
     *  Gain: '<S134>/Gain2'
     *  Product: '<S134>/Product2'
     *  Product: '<S134>/Product3'
     *  Product: '<S134>/Product4'
     *  Product: '<S134>/Product5'
     *  Product: '<S134>/Product8'
     *  Sum: '<S134>/Sum1'
     *  Sum: '<S134>/Sum2'
     *  Sum: '<S134>/Sum3'
     */
    rtb_Elementproduct_idx_1 = ((rtb_Elementproduct_idx_2 -
      rtb_Elementproduct_idx_1) * 2.0 * rtu_sc2sun_eci_unit[1] +
      (rtb_Product3_i_tmp - rtb_Product3_i_tmp_0) * 2.0 * rtu_sc2sun_eci_unit[0])
      + (rtb_Elementproduct_idx_5 + rtb_Product3_n) * 2.0 * rtu_sc2sun_eci_unit
      [2];

    /* Sum: '<S135>/Sum' incorporates:
     *  Gain: '<S135>/Gain'
     *  Gain: '<S135>/Gain1'
     *  Gain: '<S135>/Gain2'
     *  Product: '<S135>/Product4'
     *  Product: '<S135>/Product5'
     *  Product: '<S135>/Product8'
     *  Sum: '<S135>/Sum1'
     *  Sum: '<S135>/Sum2'
     *  Sum: '<S135>/Sum3'
     */
    rtb_Elementproduct_idx_5 = ((rtb_Product3_i_tmp_1 + rtb_Sum_k1) * 2.0 *
      rtu_sc2sun_eci_unit[0] + (rtb_Product3_n - rtb_Elementproduct_idx_5) * 2.0
      * rtu_sc2sun_eci_unit[1]) + (rtb_Elementproduct_idx_2 - rtb_Product1_oy) *
      2.0 * rtu_sc2sun_eci_unit[2];

    /* Outputs for Atomic SubSystem: '<S120>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Elementproduct_idx_5, rtb_Product3_mx,
                        rtb_Elementproduct_idx_1, rtb_MatrixConcatenate3);

    /* End of Outputs for SubSystem: '<S120>/CrossProdMatrix_lib' */

    /* Sqrt: '<S142>/sqrt' incorporates:
     *  Product: '<S143>/Product'
     *  Product: '<S143>/Product1'
     *  Product: '<S143>/Product2'
     *  Product: '<S143>/Product3'
     *  Sum: '<S143>/Sum'
     */
    rtb_Product3_i_tmp_1 = sqrt(((rtb_Merge_e[0] * rtb_Merge_e[0] + rtb_Merge_e
      [1] * rtb_Merge_e[1]) + rtb_Merge_e[2] * rtb_Merge_e[2]) + rtb_Merge_e[3] *
      rtb_Merge_e[3]);

    /* Product: '<S138>/Product2' incorporates:
     *  Sqrt: '<S142>/sqrt'
     */
    rtb_Product1_oy = rtb_Merge_e[2] / rtb_Product3_i_tmp_1;

    /* Product: '<S138>/Product3' incorporates:
     *  Sqrt: '<S142>/sqrt'
     */
    rtb_Elementproduct_idx_2 = rtb_Merge_e[3] / rtb_Product3_i_tmp_1;

    /* Product: '<S138>/Product1' incorporates:
     *  Sqrt: '<S142>/sqrt'
     */
    rtb_Product1_h4 = rtb_Merge_e[1] / rtb_Product3_i_tmp_1;

    /* Product: '<S138>/Product' incorporates:
     *  Sqrt: '<S142>/sqrt'
     */
    rtb_Product3_i_tmp_1 = rtb_Merge_e[0] / rtb_Product3_i_tmp_1;

    /* Sum: '<S139>/Sum' incorporates:
     *  Constant: '<S139>/Constant'
     *  Gain: '<S139>/Gain'
     *  Gain: '<S139>/Gain1'
     *  Gain: '<S139>/Gain2'
     *  Product: '<S139>/Product'
     *  Product: '<S139>/Product1'
     *  Product: '<S139>/Product2'
     *  Product: '<S139>/Product3'
     *  Product: '<S139>/Product4'
     *  Product: '<S139>/Product5'
     *  Product: '<S139>/Product6'
     *  Product: '<S139>/Product7'
     *  Product: '<S139>/Product8'
     *  Sum: '<S139>/Sum1'
     *  Sum: '<S139>/Sum2'
     *  Sum: '<S139>/Sum3'
     */
    rtb_Product3_n = (((0.5 - rtb_Product1_oy * rtb_Product1_oy) -
                       rtb_Elementproduct_idx_2 * rtb_Elementproduct_idx_2) *
                      2.0 * rtu_mag_eci_T[0] + (rtb_Product1_h4 *
      rtb_Product1_oy + rtb_Product3_i_tmp_1 * rtb_Elementproduct_idx_2) * 2.0 *
                      rtu_mag_eci_T[1]) + (rtb_Product1_h4 *
      rtb_Elementproduct_idx_2 - rtb_Product3_i_tmp_1 * rtb_Product1_oy) * 2.0 *
      rtu_mag_eci_T[2];

    /* Sum: '<S140>/Sum' incorporates:
     *  Constant: '<S140>/Constant'
     *  Gain: '<S140>/Gain'
     *  Gain: '<S140>/Gain1'
     *  Gain: '<S140>/Gain2'
     *  Product: '<S140>/Product'
     *  Product: '<S140>/Product1'
     *  Product: '<S140>/Product2'
     *  Product: '<S140>/Product3'
     *  Product: '<S140>/Product4'
     *  Product: '<S140>/Product5'
     *  Product: '<S140>/Product6'
     *  Product: '<S140>/Product7'
     *  Product: '<S140>/Product8'
     *  Sum: '<S140>/Sum1'
     *  Sum: '<S140>/Sum2'
     *  Sum: '<S140>/Sum3'
     */
    rtb_Sum_k1 = (((0.5 - rtb_Product1_h4 * rtb_Product1_h4) -
                   rtb_Elementproduct_idx_2 * rtb_Elementproduct_idx_2) * 2.0 *
                  rtu_mag_eci_T[1] + (rtb_Product1_h4 * rtb_Product1_oy -
      rtb_Product3_i_tmp_1 * rtb_Elementproduct_idx_2) * 2.0 * rtu_mag_eci_T[0])
      + (rtb_Product3_i_tmp_1 * rtb_Product1_h4 + rtb_Product1_oy *
         rtb_Elementproduct_idx_2) * 2.0 * rtu_mag_eci_T[2];

    /* Sum: '<S141>/Sum' incorporates:
     *  Constant: '<S141>/Constant'
     *  Gain: '<S141>/Gain'
     *  Gain: '<S141>/Gain1'
     *  Gain: '<S141>/Gain2'
     *  Product: '<S141>/Product'
     *  Product: '<S141>/Product1'
     *  Product: '<S141>/Product2'
     *  Product: '<S141>/Product3'
     *  Product: '<S141>/Product4'
     *  Product: '<S141>/Product5'
     *  Product: '<S141>/Product6'
     *  Product: '<S141>/Product7'
     *  Product: '<S141>/Product8'
     *  Sum: '<S141>/Sum1'
     *  Sum: '<S141>/Sum2'
     *  Sum: '<S141>/Sum3'
     */
    rtb_Product1_h4 = ((rtb_Product1_h4 * rtb_Elementproduct_idx_2 +
                        rtb_Product3_i_tmp_1 * rtb_Product1_oy) * 2.0 *
                       rtu_mag_eci_T[0] + (rtb_Product1_oy *
      rtb_Elementproduct_idx_2 - rtb_Product3_i_tmp_1 * rtb_Product1_h4) * 2.0 *
                       rtu_mag_eci_T[1]) + ((0.5 - rtb_Product1_h4 *
      rtb_Product1_h4) - rtb_Product1_oy * rtb_Product1_oy) * 2.0 *
      rtu_mag_eci_T[2];

    /* Outputs for Atomic SubSystem: '<S120>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Product1_h4, rtb_Product3_n, rtb_Sum_k1,
                        rtb_MathFunction1_m);

    /* End of Outputs for SubSystem: '<S120>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S120>/Horizontal Matrix Concatenate' */
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

    /* End of Concatenate: '<S120>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S109>/QR_factorization' incorporates:
     *  Constant: '<S109>/Constant'
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

        tmp[idxStart + 12 * i] = rtCP_Constant_Value_gu[6 * idxStart + i];
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

    /* Gain: '<S125>/Gain' */
    rtb_VectorConcatenate[0] = -rtb_Merge_e[1];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_Merge_e[0];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_Merge_e[3];

    /* Gain: '<S125>/Gain1' */
    rtb_VectorConcatenate[3] = -rtb_Merge_e[2];

    /* Gain: '<S125>/Gain2' */
    rtb_VectorConcatenate[4] = -rtb_Merge_e[2];

    /* Gain: '<S125>/Gain3' */
    rtb_VectorConcatenate[5] = -rtb_Merge_e[3];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_Merge_e[0];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Merge_e[1];

    /* Gain: '<S125>/Gain4' */
    rtb_VectorConcatenate[8] = -rtb_Merge_e[3];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_Merge_e[2];

    /* Gain: '<S125>/Gain5' */
    rtb_VectorConcatenate[10] = -rtb_Merge_e[1];

    /* SignalConversion: '<S125>/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_Merge_e[0];

    /* Sum: '<S109>/CreateMeasResidual' */
    rtb_sigma[0] = rtu_sun_meas_body_unit[0];
    rtb_sigma[3] = rtu_mag_meas_body_T[0];
    rtb_sigma[1] = rtu_sun_meas_body_unit[1];
    rtb_sigma[4] = rtu_mag_meas_body_T[1];
    rtb_sigma[2] = rtu_sun_meas_body_unit[2];
    rtb_sigma[5] = rtu_mag_meas_body_T[2];
    rtb_Product3_i[0] = rtb_Product3_mx;
    rtb_Product3_i[1] = rtb_Elementproduct_idx_1;
    rtb_Product3_i[2] = rtb_Elementproduct_idx_5;
    rtb_Product3_i[3] = rtb_Product3_n;
    rtb_Product3_i[4] = rtb_Sum_k1;
    rtb_Product3_i[5] = rtb_Product1_h4;
    for (i = 0; i < 6; i++) {
      /* SignalConversion: '<S109>/OutportBufferForP_chol_plus' incorporates:
       *  MATLAB Function: '<S109>/QR_factorization'
       */
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_P_cholmerge[idxStart + 6 * i] = R[((6 + idxStart) * 12 + i) + 6];
      }

      /* Sum: '<S109>/CreateMeasResidual' */
      rtu_sun_meas_body_unit_0[i] = rtb_sigma[i] - rtb_Product3_i[i];
    }

    /* Product: '<S109>/Product1' incorporates:
     *  MATLAB Function: '<S109>/QR_factorization'
     */
    for (i = 0; i < 6; i++) {
      rtb_MathFunction1_m[i] = 0.0;
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MathFunction1_m[i] += rtb_Phi[6 * idxStart + i] *
          rtu_sun_meas_body_unit_0[idxStart];
      }
    }

    /* End of Product: '<S109>/Product1' */

    /* Sum: '<S109>/UpdatingBetaBias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rty_bias_radps[0] = rtb_MathFunction1_m[3] + localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = rtb_MathFunction1_m[4] + localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = rtb_MathFunction1_m[5] + localDW->UnitDelay1_DSTATE[2];

    /* Sum: '<S109>/Sum' incorporates:
     *  Gain: '<S125>/Gain6'
     *  Product: '<S109>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_TmpSignalConversionAtquat_e[i] = ((rtb_VectorConcatenate[i + 4] * 0.5 *
        rtb_MathFunction1_m[1] + 0.5 * rtb_VectorConcatenate[i] *
        rtb_MathFunction1_m[0]) + rtb_VectorConcatenate[i + 8] * 0.5 *
        rtb_MathFunction1_m[2]) + rtb_Merge_e[i];
    }

    /* End of Sum: '<S109>/Sum' */

    /* Sqrt: '<S130>/sqrt' incorporates:
     *  Product: '<S131>/Product'
     *  Product: '<S131>/Product1'
     *  Product: '<S131>/Product2'
     *  Product: '<S131>/Product3'
     *  Sum: '<S131>/Sum'
     */
    rtb_Product3_i_tmp_1 = sqrt(((rtb_TmpSignalConversionAtquat_e[0] *
      rtb_TmpSignalConversionAtquat_e[0] + rtb_TmpSignalConversionAtquat_e[1] *
      rtb_TmpSignalConversionAtquat_e[1]) + rtb_TmpSignalConversionAtquat_e[2] *
      rtb_TmpSignalConversionAtquat_e[2]) + rtb_TmpSignalConversionAtquat_e[3] *
      rtb_TmpSignalConversionAtquat_e[3]);

    /* Product: '<S122>/Product' */
    rty_sc_quat[0] = rtb_TmpSignalConversionAtquat_e[0] / rtb_Product3_i_tmp_1;

    /* Product: '<S122>/Product1' */
    rty_sc_quat[1] = rtb_TmpSignalConversionAtquat_e[1] / rtb_Product3_i_tmp_1;

    /* Product: '<S122>/Product2' */
    rty_sc_quat[2] = rtb_TmpSignalConversionAtquat_e[2] / rtb_Product3_i_tmp_1;

    /* Product: '<S122>/Product3' */
    rty_sc_quat[3] = rtb_TmpSignalConversionAtquat_e[3] / rtb_Product3_i_tmp_1;

    /* End of Outputs for SubSystem: '<S3>/MeasurementUpdate' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/BypassMeasUpdate' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    memcpy(&rtb_P_cholmerge[0], &localDW->UnitDelay_DSTATE[0], 36U * sizeof
           (real_T));
    rty_bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = localDW->UnitDelay1_DSTATE[2];
    rty_sc_quat[0] = rtb_Merge_e[0];
    rty_sc_quat[1] = rtb_Merge_e[1];
    rty_sc_quat[2] = rtb_Merge_e[2];
    rty_sc_quat[3] = rtb_Merge_e[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[0];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S112>/Sum' */
  rty_body_rates_radps[0] = rtb_Product3_mx - rty_bias_radps[0];

  /* Product: '<S112>/Matrix Multiply' incorporates:
   *  Math: '<S112>/Transpose'
   */
  rtb_Elementproduct_idx_1 = rty_body_rates_radps[0] * rty_body_rates_radps[0];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[1];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S112>/Sum' */
  rty_body_rates_radps[1] = rtb_Product3_mx - rty_bias_radps[1];

  /* Product: '<S112>/Matrix Multiply' incorporates:
   *  Math: '<S112>/Transpose'
   */
  rtb_Elementproduct_idx_1 += rty_body_rates_radps[1] * rty_body_rates_radps[1];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Product3_mx = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_Product3_mx = 0.0;
  }

  /* Sum: '<S112>/Sum' */
  rty_body_rates_radps[2] = rtb_Product3_mx - rty_bias_radps[2];

  /* Product: '<S112>/Matrix Multiply' incorporates:
   *  Math: '<S112>/Transpose'
   */
  rtb_Elementproduct_idx_1 += rty_body_rates_radps[2] * rty_body_rates_radps[2];

  /* Sqrt: '<S112>/Sqrt' incorporates:
   *  Product: '<S112>/Matrix Multiply'
   */
  rtb_Product3_mx = sqrt(rtb_Elementproduct_idx_1);

  /* Outputs for Atomic SubSystem: '<S112>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_d(rty_body_rates_radps, rtb_MatrixConcatenate3);

  /* End of Outputs for SubSystem: '<S112>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S112>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S112>/Constant'
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
    rtb_Elementproduct_idx_1 = rtb_Product3_n / rtb_Product3_mx;
    rtb_Elementproduct_idx_2 = cos(rtb_Product3_mx * 0.25);
    rtb_Elementproduct_idx_5 = rtb_Product3_mx * rtb_Product3_mx;
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
      rtb_Phi[6 * i] = (1.0 - rtb_Elementproduct_idx_2) * rtb_Product3_n /
        rtb_Elementproduct_idx_5 + ((real_T)b_I[3 * i] - rtb_Product1_h4 *
        rtb_Elementproduct_idx_1);
      rtb_MatrixMultiply1_tmp = 6 * (i + 3);
      rtb_Phi[rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_idx_2) *
        rtb_Product1_h4 / rtb_Elementproduct_idx_5 - (real_T)b_a[3 * i] * 0.25)
        - rtb_Product3_n * rtb_Sum_k1 / rtb_Product3_i_tmp_1;
      rtb_Phi[3 + 6 * i] = 0.0;
      rtb_Phi[3 + rtb_MatrixMultiply1_tmp] = Phi_22[3 * i];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 1;
      rtb_Phi[1 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Elementproduct_idx_1) + (1.0 -
        rtb_Elementproduct_idx_2) *
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_idx_5;
      rtb_Phi[1 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_idx_2) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_idx_5 - (real_T)b_a[rtb_MatrixMultiply1_tmp_0] * 0.25)
        - rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] * rtb_Sum_k1 /
        rtb_Product3_i_tmp_1;
      rtb_Phi[4 + 6 * i] = 0.0;
      rtb_Phi[4 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1_tmp_0 = 3 * i + 2;
      rtb_Phi[2 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] *
                            rtb_Elementproduct_idx_1) + (1.0 -
        rtb_Elementproduct_idx_2) *
        rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_idx_5;
      rtb_Phi[2 + rtb_MatrixMultiply1_tmp] = ((1.0 - rtb_Elementproduct_idx_2) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_tmp_0] /
        rtb_Elementproduct_idx_5 - (real_T)b_a[rtb_MatrixMultiply1_tmp_0] * 0.25)
        - rtb_MathFunction1_m[rtb_MatrixMultiply1_tmp_0] * rtb_Sum_k1 /
        rtb_Product3_i_tmp_1;
      rtb_Phi[5 + 6 * i] = 0.0;
      rtb_Phi[5 + rtb_MatrixMultiply1_tmp] = Phi_22[rtb_MatrixMultiply1_tmp_0];
    }
  }

  /* End of MATLAB Function: '<S112>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S112>/MATLAB Function' incorporates:
   *  Constant: '<S112>/Constant13'
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

  /* Trigonometry: '<S150>/Cos' incorporates:
   *  Constant: '<S112>/Constant'
   *  Constant: '<S150>/Constant'
   *  Product: '<S150>/Multiply'
   */
  rtb_Elementproduct_idx_1 = cos(0.125 * rtb_Product3_mx);

  /* SignalConversion: '<S150>/ConcatBufferAtMatrix ConcatenateIn1' */
  rtb_Merge_e[0] = rtb_Elementproduct_idx_1;

  /* If: '<S149>/If' */
  if (rtb_Product3_mx < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* SignalConversion: '<S156>/OutportBuffer_InsertedFor_Psi_zero_at_inport_0' */
    rtb_MathFunction_iz[0] = 0.0;
    rtb_MathFunction_iz[1] = 0.0;
    rtb_MathFunction_iz[2] = 0.0;

    /* End of Outputs for SubSystem: '<S149>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Trigonometry: '<S155>/Sin' incorporates:
     *  Constant: '<S112>/Constant'
     *  Constant: '<S155>/Constant'
     *  Product: '<S155>/Divide'
     */
    rtb_Product1_h4 = sin(0.125 * rtb_Product3_mx);

    /* Product: '<S155>/Divide1' */
    rtb_MathFunction_iz[0] = rtb_Product1_h4 * rty_body_rates_radps[0] /
      rtb_Product3_mx;
    rtb_MathFunction_iz[1] = rtb_Product1_h4 * rty_body_rates_radps[1] /
      rtb_Product3_mx;
    rtb_MathFunction_iz[2] = rtb_Product1_h4 * rty_body_rates_radps[2] /
      rtb_Product3_mx;

    /* End of Outputs for SubSystem: '<S149>/If Action Subsystem' */
  }

  /* End of If: '<S149>/If' */

  /* Math: '<S150>/Transpose2' incorporates:
   *  Gain: '<S150>/Gain'
   */
  rtb_Merge_e[1] = -rtb_MathFunction_iz[0];
  rtb_Merge_e[2] = -rtb_MathFunction_iz[1];
  rtb_Merge_e[3] = -rtb_MathFunction_iz[2];

  /* Outputs for Atomic SubSystem: '<S112>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_d(rtb_MathFunction_iz, &rtb_MatrixConcatenate2_n[0]);

  /* End of Outputs for SubSystem: '<S112>/CrossProdMatrix_lib' */

  /* S-Function (sdspdiag2): '<S111>/Extract Diagonal' */
  for (i = 0; i < 6; i++) {
    rtb_sigma[i] = rtb_P_cholmerge[i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S111>/Extract Diagonal' */

  /* Sum: '<S150>/Add1' incorporates:
   *  Product: '<S150>/Matrix Multiply2'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 3] = rtb_Elementproduct_idx_1 * localDW->Id_3[i] -
      rtb_MatrixConcatenate2_n[i];
  }

  /* End of Sum: '<S150>/Add1' */

  /* SignalConversion: '<S150>/ConcatBufferAtMatrix Concatenate1In1' */
  rtb_VectorConcatenate[0] = rtb_MathFunction_iz[0];
  rtb_VectorConcatenate[1] = rtb_MathFunction_iz[1];
  rtb_VectorConcatenate[2] = rtb_MathFunction_iz[2];
  for (i = 0; i < 6; i++) {
    /* Sqrt: '<S111>/Sqrt' incorporates:
     *  Abs: '<S111>/Abs'
     */
    rtb_Product3_mx = sqrt(fabs(rtb_sigma[i]));

    /* Gain: '<S111>/multiply' */
    rty_threeSigma_rad[i] = 3.0 * rtb_Product3_mx;

    /* Abs: '<S111>/Abs' */
    rtb_sigma[i] = rtb_Product3_mx;
  }

  /* Concatenate: '<S150>/Matrix Concatenate2' */
  for (i = 0; i < 4; i++) {
    idxStart = i << 2;
    rtb_MatrixConcatenate2_n[idxStart] = rtb_Merge_e[i];
    rtb_MatrixConcatenate2_n[1 + idxStart] = rtb_VectorConcatenate[3 * i];
    rtb_MatrixConcatenate2_n[2 + idxStart] = rtb_VectorConcatenate[3 * i + 1];
    rtb_MatrixConcatenate2_n[3 + idxStart] = rtb_VectorConcatenate[3 * i + 2];
  }

  /* End of Concatenate: '<S150>/Matrix Concatenate2' */

  /* Product: '<S112>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Product3_mx = rtb_MatrixConcatenate2_n[i + 12] * rty_sc_quat[3] +
      (rtb_MatrixConcatenate2_n[i + 8] * rty_sc_quat[2] +
       (rtb_MatrixConcatenate2_n[i + 4] * rty_sc_quat[1] +
        rtb_MatrixConcatenate2_n[i] * rty_sc_quat[0]));
    rtb_Merge_e[i] = rtb_Product3_mx;
  }

  /* End of Product: '<S112>/Product' */

  /* Sqrt: '<S157>/sqrt' incorporates:
   *  Product: '<S158>/Product'
   *  Product: '<S158>/Product1'
   *  Product: '<S158>/Product2'
   *  Product: '<S158>/Product3'
   *  Sum: '<S158>/Sum'
   */
  rtb_Elementproduct_idx_1 = sqrt(((rtb_Merge_e[0] * rtb_Merge_e[0] +
    rtb_Merge_e[1] * rtb_Merge_e[1]) + rtb_Merge_e[2] * rtb_Merge_e[2]) +
    rtb_Merge_e[3] * rtb_Merge_e[3]);

  /* SignalConversion: '<S112>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S151>/Product'
   *  Product: '<S151>/Product1'
   *  Product: '<S151>/Product2'
   *  Product: '<S151>/Product3'
   */
  rtb_Merge_e[3] /= rtb_Elementproduct_idx_1;
  rtb_Merge_e[0] /= rtb_Elementproduct_idx_1;
  rtb_Merge_e[1] /= rtb_Elementproduct_idx_1;
  rtb_Merge_e[2] /= rtb_Elementproduct_idx_1;

  /* Outputs for Atomic SubSystem: '<S112>/quat_rectify_lib' */
  quat_rectify_lib(rtb_Merge_e, rtb_TmpSignalConversionAtquat_e);

  /* End of Outputs for SubSystem: '<S112>/quat_rectify_lib' */

  /* If: '<S108>/If' incorporates:
   *  Constant: '<S116>/Constant'
   *  Inport: '<S118>/mekf_mode'
   *  RelationalOperator: '<S116>/Compare'
   */
  if (rtb_Switch_ex) {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    /* SignalConversion: '<S117>/OutportBuffer_InsertedFor_mekf_triad_at_inport_0' incorporates:
     *  Constant: '<S117>/Constant'
     */
    *rty_mekf_telem = 3U;

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem' */
  } else if (rtb_Sum_hy < 2) {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_hy;

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* SignalConversion: '<S119>/OutportBuffer_InsertedFor_mekf_nom_at_inport_0' incorporates:
     *  Constant: '<S119>/cnst'
     */
    *rty_mekf_telem = 0U;

    /* End of Outputs for SubSystem: '<S108>/If Action Subsystem2' */
  }

  /* End of If: '<S108>/If' */

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  MATLAB Function: '<S112>/MATLAB Function'
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
     *  ActionPort: '<S113>/Action Port'
     */
    /* Update for UnitDelay: '<S113>/Unit Delay' */
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
