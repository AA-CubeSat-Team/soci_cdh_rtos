/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.c
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

#include "maggyroProcessing_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * System initialize for action system:
 *    '<S12>/ThreeValid_MVS'
 *    '<S13>/ThreeValid_MVS'
 */
void ThreeValid_MVS_Init(DW_ThreeValid_MVS *localDW)
{
  /* InitializeConditions for S-Function (sdspmdn2): '<S26>/Median' */
  localDW->Median_Index[0] = 0U;
  localDW->Median_Index[1] = 3U;
  localDW->Median_Index[2] = 6U;
}

/*
 * Output and update for action system:
 *    '<S12>/ThreeValid_MVS'
 *    '<S13>/ThreeValid_MVS'
 */
void ThreeValid_MVS(const real_T rtu_sensor_meas_body_all[9], real_T
                    rty_sensor_meas_body[3], boolean_T *rty_sensor_meas_valid,
                    DW_ThreeValid_MVS *localDW, real_T rtp_max_err)
{
  int32_T c;
  int32_T j;
  uint32_T i0;
  uint32_T i1;
  int32_T j1;
  real_T rtb_Sqrt_d;
  real_T rtb_Sqrt_dk;
  real_T rtb_Sqrt_o;
  real_T rtb_VariableSelector[3];
  real_T rtb_Median[3];
  real_T rtb_VariableSelector2_ky[3];

  /* S-Function (sdspmdn2): '<S26>/Median' */
  c = 0;
  for (j = 0; j < 3; j++) {
    i0 = localDW->Median_Index[0];
    rtb_Sqrt_d = rtu_sensor_meas_body_all[localDW->Median_Index[0] + j];
    i1 = localDW->Median_Index[1U];
    rtb_Sqrt_dk = rtu_sensor_meas_body_all[localDW->Median_Index[1U] + j];
    if (rtb_Sqrt_d > rtb_Sqrt_dk) {
      localDW->Median_Index[1U] = localDW->Median_Index[0];
      localDW->Median_Index[0U] = i1;
    } else {
      rtb_Sqrt_d = rtb_Sqrt_dk;
      i0 = localDW->Median_Index[1U];
    }

    i1 = localDW->Median_Index[2U];
    rtb_Sqrt_dk = rtu_sensor_meas_body_all[localDW->Median_Index[2U] + j];
    if (rtb_Sqrt_d > rtb_Sqrt_dk) {
      localDW->Median_Index[2U] = i0;
      if (rtu_sensor_meas_body_all[localDW->Median_Index[0U] + j] > rtb_Sqrt_dk)
      {
        localDW->Median_Index[1U] = localDW->Median_Index[0U];
        j1 = 1;
      } else {
        j1 = 2;

        /* set loop index to break loop */
      }

      localDW->Median_Index[j1 - 1U] = i1;
    } else {
      rtb_Sqrt_d = rtb_Sqrt_dk;
    }

    rtb_Median[c] = rtu_sensor_meas_body_all[localDW->Median_Index[1] + j];
    c++;
  }

  /* End of S-Function (sdspmdn2): '<S26>/Median' */

  /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[0] = rtb_Median[0];

  /* Sum: '<S26>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_Median[0] = rtu_sensor_meas_body_all[0] - rtu_sensor_meas_body_all[6];

  /* Sum: '<S26>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   */
  rtb_VariableSelector[0] = rtu_sensor_meas_body_all[0] -
    rtu_sensor_meas_body_all[3];

  /* Sum: '<S26>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_VariableSelector2_ky[0] = rtu_sensor_meas_body_all[3] -
    rtu_sensor_meas_body_all[6];

  /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[1] = rtb_Median[1];

  /* Sum: '<S26>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_Median[1] = rtu_sensor_meas_body_all[1] - rtu_sensor_meas_body_all[7];

  /* Sum: '<S26>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   */
  rtb_VariableSelector[1] = rtu_sensor_meas_body_all[1] -
    rtu_sensor_meas_body_all[4];

  /* Sum: '<S26>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_VariableSelector2_ky[1] = rtu_sensor_meas_body_all[4] -
    rtu_sensor_meas_body_all[7];

  /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[2] = rtb_Median[2];

  /* Sum: '<S26>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_Median[2] = rtu_sensor_meas_body_all[2] - rtu_sensor_meas_body_all[8];

  /* Sum: '<S26>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector'
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   */
  rtb_VariableSelector[2] = rtu_sensor_meas_body_all[2] -
    rtu_sensor_meas_body_all[5];

  /* Sum: '<S26>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector1'
   *  S-Function (sdspperm2): '<S26>/Variable Selector2'
   */
  rtb_VariableSelector2_ky[2] = rtu_sensor_meas_body_all[5] -
    rtu_sensor_meas_body_all[8];

  /* Outputs for Atomic SubSystem: '<S26>/twonorm' */
  rtb_Sqrt_d = twonorm(rtb_VariableSelector);

  /* End of Outputs for SubSystem: '<S26>/twonorm' */

  /* Outputs for Atomic SubSystem: '<S26>/twonorm1' */
  rtb_Sqrt_dk = twonorm(rtb_Median);

  /* End of Outputs for SubSystem: '<S26>/twonorm1' */

  /* Outputs for Atomic SubSystem: '<S26>/twonorm2' */
  rtb_Sqrt_o = twonorm(rtb_VariableSelector2_ky);

  /* End of Outputs for SubSystem: '<S26>/twonorm2' */

  /* Logic: '<S26>/OR' incorporates:
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  RelationalOperator: '<S46>/Compare'
   *  RelationalOperator: '<S47>/Compare'
   *  RelationalOperator: '<S48>/Compare'
   */
  *rty_sensor_meas_valid = ((rtb_Sqrt_d <= rtp_max_err) || (rtb_Sqrt_dk <=
    rtp_max_err) || (rtb_Sqrt_o <= rtp_max_err));
}

/*
 * Output and update for action system:
 *    '<S12>/TwoValid'
 *    '<S13>/TwoValid'
 */
void TwoValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_o, boolean_T
              rtu_sensor_valid_all_c, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_meas_valid, real_T rtp_max_err)
{
  real_T rtb_Sqrt_i;
  real_T rtb_VariableSelector6_h[3];
  real_T rtb_Subtract_f[3];
  real_T rtb_Subtract_n[3];
  real_T rtb_VariableSelector8_k_idx_2;
  real_T rtb_Merge_j_idx_2;
  real_T rtb_VariableSelector8_k_idx_1;
  real_T rtb_Merge_j_idx_1;
  real_T rtb_VariableSelector8_k_idx_0;
  real_T rtb_Merge_j_idx_0;

  /* S-Function (sdspperm2): '<S27>/Variable Selector8' */
  rtb_VariableSelector8_k_idx_0 = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_k_idx_1 = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_k_idx_2 = rtu_sensor_meas_body_all[8];

  /* If: '<S27>/If4' incorporates:
   *  Inport: '<S55>/In1'
   *  S-Function (sdspperm2): '<S27>/Variable Selector6'
   */
  if (rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    rtb_Merge_j_idx_0 = rtu_sensor_meas_body_all[0];
    rtb_Merge_j_idx_1 = rtu_sensor_meas_body_all[1];
    rtb_Merge_j_idx_2 = rtu_sensor_meas_body_all[2];

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_j_idx_0 = 0.0;

    /* Sum: '<S53>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_f[0] = rtu_sensor_meas_body_all[3] - rtu_sensor_meas_body_all[6];

    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_j_idx_1 = 0.0;

    /* Sum: '<S53>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_f[1] = rtu_sensor_meas_body_all[4] - rtu_sensor_meas_body_all[7];

    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_j_idx_2 = 0.0;

    /* Sum: '<S53>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_f[2] = rtu_sensor_meas_body_all[5] - rtu_sensor_meas_body_all[8];

    /* Outputs for Atomic SubSystem: '<S53>/twonorm' */
    rtb_Sqrt_i = twonorm(rtb_Subtract_f);

    /* End of Outputs for SubSystem: '<S53>/twonorm' */

    /* RelationalOperator: '<S60>/Compare' incorporates:
     *  Constant: '<S60>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_i <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem14' */
  }

  /* End of If: '<S27>/If4' */

  /* If: '<S27>/If5' incorporates:
   *  Inport: '<S56>/In1'
   *  S-Function (sdspperm2): '<S27>/Variable Selector7'
   */
  if (rtu_sensor_valid_all_o) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    rtb_Subtract_f[0] = rtu_sensor_meas_body_all[3];
    rtb_Subtract_f[1] = rtu_sensor_meas_body_all[4];
    rtb_Subtract_f[2] = rtu_sensor_meas_body_all[5];

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem8' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_f[0] = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_n[0] = rtu_sensor_meas_body_all[0] - rtu_sensor_meas_body_all[6];

    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_f[1] = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_n[1] = rtu_sensor_meas_body_all[1] - rtu_sensor_meas_body_all[7];

    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_f[2] = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector8'
     */
    rtb_Subtract_n[2] = rtu_sensor_meas_body_all[2] - rtu_sensor_meas_body_all[8];

    /* Outputs for Atomic SubSystem: '<S52>/twonorm' */
    rtb_Sqrt_i = twonorm(rtb_Subtract_n);

    /* End of Outputs for SubSystem: '<S52>/twonorm' */

    /* RelationalOperator: '<S58>/Compare' incorporates:
     *  Constant: '<S58>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_i <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */
  }

  /* End of If: '<S27>/If5' */

  /* If: '<S27>/If6' incorporates:
   *  S-Function (sdspperm2): '<S27>/Variable Selector6'
   *  S-Function (sdspperm2): '<S27>/Variable Selector7'
   *  Sum: '<S54>/Subtract'
   */
  if (!rtu_sensor_valid_all_c) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_VariableSelector8_k_idx_0 = 0.0;
    rtb_VariableSelector6_h[0] = rtu_sensor_meas_body_all[0] -
      rtu_sensor_meas_body_all[3];

    /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  Sum: '<S54>/Subtract'
     */
    rtb_VariableSelector8_k_idx_1 = 0.0;
    rtb_VariableSelector6_h[1] = rtu_sensor_meas_body_all[1] -
      rtu_sensor_meas_body_all[4];

    /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  Sum: '<S54>/Subtract'
     */
    rtb_VariableSelector8_k_idx_2 = 0.0;
    rtb_VariableSelector6_h[2] = rtu_sensor_meas_body_all[2] -
      rtu_sensor_meas_body_all[5];

    /* Outputs for Atomic SubSystem: '<S54>/twonorm' */
    rtb_Sqrt_i = twonorm(rtb_VariableSelector6_h);

    /* End of Outputs for SubSystem: '<S54>/twonorm' */

    /* RelationalOperator: '<S62>/Compare' incorporates:
     *  Constant: '<S62>/Constant'
     *  S-Function (sdspperm2): '<S27>/Variable Selector6'
     *  S-Function (sdspperm2): '<S27>/Variable Selector7'
     *  Sum: '<S54>/Subtract'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_i <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem2' */
  }

  /* End of If: '<S27>/If6' */

  /* Gain: '<S27>/Gain1' incorporates:
   *  Sum: '<S27>/Sum1'
   */
  rty_sensor_meas_body[0] = ((rtb_Merge_j_idx_0 + rtb_Subtract_f[0]) +
    rtb_VariableSelector8_k_idx_0) * 0.5;
  rty_sensor_meas_body[1] = ((rtb_Merge_j_idx_1 + rtb_Subtract_f[1]) +
    rtb_VariableSelector8_k_idx_1) * 0.5;
  rty_sensor_meas_body[2] = ((rtb_Merge_j_idx_2 + rtb_Subtract_f[2]) +
    rtb_VariableSelector8_k_idx_2) * 0.5;
}

/*
 * Output and update for action system:
 *    '<S24>/If Action Subsystem14'
 *    '<S24>/If Action Subsystem1'
 *    '<S24>/If Action Subsystem2'
 *    '<S66>/If Action Subsystem14'
 *    '<S66>/If Action Subsystem1'
 *    '<S66>/If Action Subsystem2'
 */
void IfActionSubsystem14(real_T rty_nullOut[3])
{
  /* SignalConversion: '<S29>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
  rty_nullOut[0] = 0.0;
  rty_nullOut[1] = 0.0;
  rty_nullOut[2] = 0.0;
}

/*
 * Output and update for action system:
 *    '<S12>/OneValid'
 *    '<S13>/OneValid'
 */
void OneValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_c, boolean_T
              rtu_sensor_valid_all_n, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_valid)
{
  real_T rtb_VariableSelector6_e[3];
  real_T rtb_VariableSelector7_g[3];
  real_T rtb_VariableSelector8_l[3];

  /* S-Function (sdspperm2): '<S24>/Variable Selector6' */
  rtb_VariableSelector6_e[0] = rtu_sensor_meas_body_all[0];
  rtb_VariableSelector6_e[1] = rtu_sensor_meas_body_all[1];
  rtb_VariableSelector6_e[2] = rtu_sensor_meas_body_all[2];

  /* If: '<S24>/If4' */
  if (!rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector6_e);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem14' */
  }

  /* End of If: '<S24>/If4' */

  /* S-Function (sdspperm2): '<S24>/Variable Selector7' */
  rtb_VariableSelector7_g[0] = rtu_sensor_meas_body_all[3];
  rtb_VariableSelector7_g[1] = rtu_sensor_meas_body_all[4];
  rtb_VariableSelector7_g[2] = rtu_sensor_meas_body_all[5];

  /* If: '<S24>/If5' */
  if (!rtu_sensor_valid_all_c) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector7_g);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
  }

  /* End of If: '<S24>/If5' */

  /* S-Function (sdspperm2): '<S24>/Variable Selector8' */
  rtb_VariableSelector8_l[0] = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_l[1] = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_l[2] = rtu_sensor_meas_body_all[8];

  /* If: '<S24>/If6' */
  if (!rtu_sensor_valid_all_n) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector8_l);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem2' */
  }

  /* End of If: '<S24>/If6' */

  /* Gain: '<S24>/Gain1' incorporates:
   *  Sum: '<S24>/Sum1'
   */
  rty_sensor_meas_body[0] = (rtb_VariableSelector6_e[0] +
    rtb_VariableSelector7_g[0]) + rtb_VariableSelector8_l[0];
  rty_sensor_meas_body[1] = (rtb_VariableSelector6_e[1] +
    rtb_VariableSelector7_g[1]) + rtb_VariableSelector8_l[1];
  rty_sensor_meas_body[2] = (rtb_VariableSelector6_e[2] +
    rtb_VariableSelector7_g[2]) + rtb_VariableSelector8_l[2];

  /* SignalConversion: '<S24>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S24>/Constant'
   */
  *rty_sensor_valid = true;
}

/*
 * Output and update for action system:
 *    '<S12>/NoneValid'
 *    '<S13>/NoneValid'
 */
void NoneValid(const real_T rtu_sensor_meas_body_all[9], real_T
               rty_sensor_meas_body[3], boolean_T *rty_sensor_valid)
{
  /* Gain: '<S23>/Gain' incorporates:
   *  S-Function (sdspperm2): '<S23>/Variable Selector3'
   *  S-Function (sdspperm2): '<S23>/Variable Selector4'
   *  S-Function (sdspperm2): '<S23>/Variable Selector5'
   *  Sum: '<S23>/Sum'
   */
  rty_sensor_meas_body[0] = ((rtu_sensor_meas_body_all[0] +
    rtu_sensor_meas_body_all[3]) + rtu_sensor_meas_body_all[6]) *
    0.33333333333333331;
  rty_sensor_meas_body[1] = ((rtu_sensor_meas_body_all[1] +
    rtu_sensor_meas_body_all[4]) + rtu_sensor_meas_body_all[7]) *
    0.33333333333333331;
  rty_sensor_meas_body[2] = ((rtu_sensor_meas_body_all[2] +
    rtu_sensor_meas_body_all[5]) + rtu_sensor_meas_body_all[8]) *
    0.33333333333333331;

  /* SignalConversion: '<S23>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S23>/Constant'
   */
  *rty_sensor_valid = false;
}

/*
 * Output and update for action system:
 *    '<S25>/If Action Subsystem2'
 *    '<S25>/If Action Subsystem4'
 *    '<S25>/If Action Subsystem14'
 *    '<S67>/If Action Subsystem2'
 *    '<S67>/If Action Subsystem4'
 *    '<S67>/If Action Subsystem14'
 */
void IfActionSubsystem2(boolean_T *rty_Out1)
{
  /* SignalConversion: '<S40>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S40>/Constant'
   */
  *rty_Out1 = false;
}

/* System initialize for atomic system: '<S2>/maggyroProcessing_lib' */
void maggyroProcessing_lib_Init(DW_maggyroProcessing_lib *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S12>/ThreeValid_MVS' */
  ThreeValid_MVS_Init(&localDW->ThreeValid_MVS_l);

  /* End of SystemInitialize for SubSystem: '<S12>/ThreeValid_MVS' */
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib' */
void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const boolean_T
  rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T
  *rty_sensor_valid, DW_maggyroProcessing_lib *localDW, real_T rtp_max_err,
  const real_T rtp_offset_calibration_matrix[9], real_T
  rtp_static_range_max_value, real_T rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_lj;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_l;
  boolean_T rtb_conjunction_h;
  real_T rtb_Merge_dq[3];
  boolean_T rtb_Merge_m;
  boolean_T rtb_Merge1_c;
  boolean_T rtb_Merge2;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  int32_T i;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S22>/Variable Selector' */
  rtb_Merge_dq[0] = rtu_sensor_meas_data[0];
  rtb_Merge_dq[1] = rtu_sensor_meas_data[1];
  rtb_Merge_dq[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S22>/Matrix Multiply3' incorporates:
     *  Constant: '<S22>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_j[i] * rtb_Merge_dq[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_j[i + 3] * rtb_Merge_dq[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_j[i + 6] * rtb_Merge_dq[2];

    /* Product: '<S22>/Matrix Multiply2' incorporates:
     *  Constant: '<S22>/Constant2'
     *  S-Function (sdspperm2): '<S22>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S22>/Matrix Multiply1' incorporates:
     *  Constant: '<S22>/Constant1'
     *  S-Function (sdspperm2): '<S22>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_d[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_d[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_d[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S22>/Sum' */

  /* S-Function (sdspperm2): '<S25>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S25>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S25>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S25>/twonorm1' */
  rtb_Sqrt_lj = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S25>/twonorm1' */

  /* Logic: '<S34>/conjunction' incorporates:
   *  Constant: '<S34>/max_val'
   *  Constant: '<S34>/min_val'
   *  RelationalOperator: '<S34>/max_relop'
   *  RelationalOperator: '<S34>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt_lj) && (rtb_Sqrt_lj <=
    rtp_static_range_max_value));

  /* If: '<S25>/If4' incorporates:
   *  Inport: '<S37>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    rtb_Merge_m = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_m);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem14' */
  }

  /* End of If: '<S25>/If4' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm2' */
  rtb_Sqrt_lj = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S25>/twonorm2' */

  /* Logic: '<S35>/conjunction' incorporates:
   *  Constant: '<S35>/max_val'
   *  Constant: '<S35>/min_val'
   *  RelationalOperator: '<S35>/max_relop'
   *  RelationalOperator: '<S35>/min_relop'
   */
  rtb_conjunction_l = ((0.0 <= rtb_Sqrt_lj) && (rtb_Sqrt_lj <=
    rtp_static_range_max_value));

  /* If: '<S25>/If1' incorporates:
   *  Inport: '<S38>/In1'
   */
  if (rtb_conjunction_l) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    rtb_Merge1_c = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1_c);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem2' */
  }

  /* End of If: '<S25>/If1' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm3' */
  rtb_Sqrt_lj = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S25>/twonorm3' */

  /* Logic: '<S36>/conjunction' incorporates:
   *  Constant: '<S36>/max_val'
   *  Constant: '<S36>/min_val'
   *  RelationalOperator: '<S36>/max_relop'
   *  RelationalOperator: '<S36>/min_relop'
   */
  rtb_conjunction_h = ((0.0 <= rtb_Sqrt_lj) && (rtb_Sqrt_lj <=
    rtp_static_range_max_value));

  /* If: '<S25>/If2' incorporates:
   *  Inport: '<S41>/In1'
   */
  if (rtb_conjunction_h) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem4' */
  }

  /* End of If: '<S25>/If2' */

  /* If: '<S12>/If' */
  tmp = (rtb_Merge_m && rtb_Merge1_c);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/ThreeValid_MVS' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    ThreeValid_MVS(rtb_VectorConcatenate, rtb_Merge_dq, rty_sensor_valid,
                   &localDW->ThreeValid_MVS_l, rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/ThreeValid_MVS' */
  } else if (tmp || (rtb_Merge1_c && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_m))
  {
    /* Outputs for IfAction SubSystem: '<S12>/TwoValid' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_m, rtb_Merge1_c, rtb_Merge2,
             rtb_Merge_dq, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/TwoValid' */
  } else if (rtb_Merge_m || rtb_Merge1_c || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/OneValid' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_m, rtb_Merge1_c, rtb_Merge2,
             rtb_Merge_dq, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/NoneValid' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_dq, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/NoneValid' */
  }

  /* End of If: '<S12>/If' */

  /* Gain: '<S12>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_dq[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_dq[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_dq[2];

  /* Assertion: '<S36>/Assertion' */
  utAssert(rtb_conjunction_h);

  /* Assertion: '<S35>/Assertion' */
  utAssert(rtb_conjunction_l);

  /* Assertion: '<S34>/Assertion' */
  utAssert(rtb_conjunction);
}

/* System initialize for atomic system: '<S2>/maggyroProcessing_lib1' */
void maggyroProcessing_lib1_Init(DW_maggyroProcessing_lib_p *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S13>/ThreeValid_MVS' */
  ThreeValid_MVS_Init(&localDW->ThreeValid_MVS_i);

  /* End of SystemInitialize for SubSystem: '<S13>/ThreeValid_MVS' */
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib1' */
void maggyroProcessing_lib1(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, DW_maggyroProcessing_lib_p *localDW, real_T rtp_max_err,
  const real_T rtp_offset_calibration_matrix[9], real_T
  rtp_static_range_max_value, real_T rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_b;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_m;
  boolean_T rtb_conjunction_d;
  real_T rtb_Merge_ez[3];
  boolean_T rtb_Merge_ec;
  boolean_T rtb_Merge1_a;
  boolean_T rtb_Merge2;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  int32_T i;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S64>/Variable Selector' */
  rtb_Merge_ez[0] = rtu_sensor_meas_data[0];
  rtb_Merge_ez[1] = rtu_sensor_meas_data[1];
  rtb_Merge_ez[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S64>/Matrix Multiply3' incorporates:
     *  Constant: '<S64>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_nl[i] * rtb_Merge_ez[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_nl[i + 3] * rtb_Merge_ez[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_nl[i + 6] * rtb_Merge_ez[2];

    /* Product: '<S64>/Matrix Multiply2' incorporates:
     *  Constant: '<S64>/Constant2'
     *  S-Function (sdspperm2): '<S64>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_m[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_m[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_m[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S64>/Matrix Multiply1' incorporates:
     *  Constant: '<S64>/Constant1'
     *  S-Function (sdspperm2): '<S64>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_i[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_i[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_i[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S64>/Sum' incorporates:
   *  Constant: '<S64>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S64>/Sum' */

  /* S-Function (sdspperm2): '<S67>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S67>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S67>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S67>/twonorm1' */
  rtb_Sqrt_b = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S67>/twonorm1' */

  /* Logic: '<S76>/conjunction' incorporates:
   *  Constant: '<S76>/max_val'
   *  Constant: '<S76>/min_val'
   *  RelationalOperator: '<S76>/max_relop'
   *  RelationalOperator: '<S76>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt_b) && (rtb_Sqrt_b <=
    rtp_static_range_max_value));

  /* If: '<S67>/If4' incorporates:
   *  Inport: '<S79>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    rtb_Merge_ec = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_ec);

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem14' */
  }

  /* End of If: '<S67>/If4' */

  /* Outputs for Atomic SubSystem: '<S67>/twonorm2' */
  rtb_Sqrt_b = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S67>/twonorm2' */

  /* Logic: '<S77>/conjunction' incorporates:
   *  Constant: '<S77>/max_val'
   *  Constant: '<S77>/min_val'
   *  RelationalOperator: '<S77>/max_relop'
   *  RelationalOperator: '<S77>/min_relop'
   */
  rtb_conjunction_m = ((0.0 <= rtb_Sqrt_b) && (rtb_Sqrt_b <=
    rtp_static_range_max_value));

  /* If: '<S67>/If1' incorporates:
   *  Inport: '<S80>/In1'
   */
  if (rtb_conjunction_m) {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    rtb_Merge1_a = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1_a);

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem2' */
  }

  /* End of If: '<S67>/If1' */

  /* Outputs for Atomic SubSystem: '<S67>/twonorm3' */
  rtb_Sqrt_b = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S67>/twonorm3' */

  /* Logic: '<S78>/conjunction' incorporates:
   *  Constant: '<S78>/max_val'
   *  Constant: '<S78>/min_val'
   *  RelationalOperator: '<S78>/max_relop'
   *  RelationalOperator: '<S78>/min_relop'
   */
  rtb_conjunction_d = ((0.0 <= rtb_Sqrt_b) && (rtb_Sqrt_b <=
    rtp_static_range_max_value));

  /* If: '<S67>/If2' incorporates:
   *  Inport: '<S83>/In1'
   */
  if (rtb_conjunction_d) {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S67>/If Action Subsystem4' */
  }

  /* End of If: '<S67>/If2' */

  /* If: '<S13>/If' */
  tmp = (rtb_Merge_ec && rtb_Merge1_a);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S13>/ThreeValid_MVS' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    ThreeValid_MVS(rtb_VectorConcatenate, rtb_Merge_ez, rty_sensor_valid,
                   &localDW->ThreeValid_MVS_i, rtp_max_err);

    /* End of Outputs for SubSystem: '<S13>/ThreeValid_MVS' */
  } else if (tmp || (rtb_Merge1_a && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_ec))
  {
    /* Outputs for IfAction SubSystem: '<S13>/TwoValid' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_ec, rtb_Merge1_a, rtb_Merge2,
             rtb_Merge_ez, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S13>/TwoValid' */
  } else if (rtb_Merge_ec || rtb_Merge1_a || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S13>/OneValid' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_ec, rtb_Merge1_a, rtb_Merge2,
             rtb_Merge_ez, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S13>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/NoneValid' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_ez, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S13>/NoneValid' */
  }

  /* End of If: '<S13>/If' */

  /* Gain: '<S13>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_ez[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_ez[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_ez[2];

  /* Assertion: '<S78>/Assertion' */
  utAssert(rtb_conjunction_d);

  /* Assertion: '<S77>/Assertion' */
  utAssert(rtb_conjunction_m);

  /* Assertion: '<S76>/Assertion' */
  utAssert(rtb_conjunction);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
