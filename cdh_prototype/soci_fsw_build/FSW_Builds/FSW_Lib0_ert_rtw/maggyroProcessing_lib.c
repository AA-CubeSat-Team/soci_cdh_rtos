/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.c
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

#include "maggyroProcessing_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * System initialize for action system:
 *    '<S11>/ThreeValid_MVS'
 *    '<S12>/ThreeValid_MVS'
 */
void ThreeValid_MVS_Init(DW_ThreeValid_MVS *localDW)
{
  /* InitializeConditions for S-Function (sdspmdn2): '<S25>/Median' */
  localDW->Median_Index[0] = 0U;
  localDW->Median_Index[1] = 3U;
  localDW->Median_Index[2] = 6U;
}

/*
 * Output and update for action system:
 *    '<S11>/ThreeValid_MVS'
 *    '<S12>/ThreeValid_MVS'
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
  real_T rtb_Sqrt_nf;
  real_T rtb_Sqrt_l;
  real_T rtb_Sqrt_h;
  real_T rtb_VariableSelector[3];
  real_T rtb_Median[3];
  real_T rtb_VariableSelector2_h[3];

  /* S-Function (sdspmdn2): '<S25>/Median' */
  c = 0;
  for (j = 0; j < 3; j++) {
    i0 = localDW->Median_Index[0];
    rtb_Sqrt_nf = rtu_sensor_meas_body_all[localDW->Median_Index[0] + j];
    i1 = localDW->Median_Index[1U];
    rtb_Sqrt_l = rtu_sensor_meas_body_all[localDW->Median_Index[1U] + j];
    if (rtb_Sqrt_nf > rtb_Sqrt_l) {
      localDW->Median_Index[1U] = localDW->Median_Index[0];
      localDW->Median_Index[0U] = i1;
    } else {
      rtb_Sqrt_nf = rtb_Sqrt_l;
      i0 = localDW->Median_Index[1U];
    }

    i1 = localDW->Median_Index[2U];
    rtb_Sqrt_l = rtu_sensor_meas_body_all[localDW->Median_Index[2U] + j];
    if (rtb_Sqrt_nf > rtb_Sqrt_l) {
      localDW->Median_Index[2U] = i0;
      if (rtu_sensor_meas_body_all[localDW->Median_Index[0U] + j] > rtb_Sqrt_l)
      {
        localDW->Median_Index[1U] = localDW->Median_Index[0U];
        j1 = 1;
      } else {
        j1 = 2;

        /* set loop index to break loop */
      }

      localDW->Median_Index[j1 - 1U] = i1;
    } else {
      rtb_Sqrt_nf = rtb_Sqrt_l;
    }

    rtb_Median[c] = rtu_sensor_meas_body_all[localDW->Median_Index[1] + j];
    c++;
  }

  /* End of S-Function (sdspmdn2): '<S25>/Median' */

  /* SignalConversion: '<S25>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[0] = rtb_Median[0];

  /* Sum: '<S25>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_Median[0] = rtu_sensor_meas_body_all[0] - rtu_sensor_meas_body_all[6];

  /* Sum: '<S25>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   */
  rtb_VariableSelector[0] = rtu_sensor_meas_body_all[0] -
    rtu_sensor_meas_body_all[3];

  /* Sum: '<S25>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_VariableSelector2_h[0] = rtu_sensor_meas_body_all[3] -
    rtu_sensor_meas_body_all[6];

  /* SignalConversion: '<S25>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[1] = rtb_Median[1];

  /* Sum: '<S25>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_Median[1] = rtu_sensor_meas_body_all[1] - rtu_sensor_meas_body_all[7];

  /* Sum: '<S25>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   */
  rtb_VariableSelector[1] = rtu_sensor_meas_body_all[1] -
    rtu_sensor_meas_body_all[4];

  /* Sum: '<S25>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_VariableSelector2_h[1] = rtu_sensor_meas_body_all[4] -
    rtu_sensor_meas_body_all[7];

  /* SignalConversion: '<S25>/OutportBufferForsensor_meas_body' */
  rty_sensor_meas_body[2] = rtb_Median[2];

  /* Sum: '<S25>/Subtract1' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_Median[2] = rtu_sensor_meas_body_all[2] - rtu_sensor_meas_body_all[8];

  /* Sum: '<S25>/Subtract' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector'
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   */
  rtb_VariableSelector[2] = rtu_sensor_meas_body_all[2] -
    rtu_sensor_meas_body_all[5];

  /* Sum: '<S25>/Subtract2' incorporates:
   *  S-Function (sdspperm2): '<S25>/Variable Selector1'
   *  S-Function (sdspperm2): '<S25>/Variable Selector2'
   */
  rtb_VariableSelector2_h[2] = rtu_sensor_meas_body_all[5] -
    rtu_sensor_meas_body_all[8];

  /* Outputs for Atomic SubSystem: '<S25>/twonorm' */
  rtb_Sqrt_nf = twonorm(rtb_VariableSelector);

  /* End of Outputs for SubSystem: '<S25>/twonorm' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm1' */
  rtb_Sqrt_l = twonorm(rtb_Median);

  /* End of Outputs for SubSystem: '<S25>/twonorm1' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm2' */
  rtb_Sqrt_h = twonorm(rtb_VariableSelector2_h);

  /* End of Outputs for SubSystem: '<S25>/twonorm2' */

  /* Logic: '<S25>/OR' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   *  RelationalOperator: '<S47>/Compare'
   */
  *rty_sensor_meas_valid = ((rtb_Sqrt_nf <= rtp_max_err) || (rtb_Sqrt_l <=
    rtp_max_err) || (rtb_Sqrt_h <= rtp_max_err));
}

/*
 * Output and update for action system:
 *    '<S11>/TwoValid'
 *    '<S12>/TwoValid'
 */
void TwoValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_e, boolean_T
              rtu_sensor_valid_all_o, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_meas_valid, real_T rtp_max_err)
{
  real_T rtb_Sqrt_j1;
  real_T rtb_VariableSelector6_d[3];
  real_T rtb_Subtract_o[3];
  real_T rtb_Subtract_g[3];
  real_T rtb_VariableSelector8_d_idx_2;
  real_T rtb_Merge_a_idx_2;
  real_T rtb_VariableSelector8_d_idx_1;
  real_T rtb_Merge_a_idx_1;
  real_T rtb_VariableSelector8_d_idx_0;
  real_T rtb_Merge_a_idx_0;

  /* S-Function (sdspperm2): '<S26>/Variable Selector8' */
  rtb_VariableSelector8_d_idx_0 = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_d_idx_1 = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_d_idx_2 = rtu_sensor_meas_body_all[8];

  /* If: '<S26>/If4' incorporates:
   *  Inport: '<S54>/In1'
   *  S-Function (sdspperm2): '<S26>/Variable Selector6'
   */
  if (rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    rtb_Merge_a_idx_0 = rtu_sensor_meas_body_all[0];
    rtb_Merge_a_idx_1 = rtu_sensor_meas_body_all[1];
    rtb_Merge_a_idx_2 = rtu_sensor_meas_body_all[2];

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_a_idx_0 = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_o[0] = rtu_sensor_meas_body_all[3] - rtu_sensor_meas_body_all[6];

    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_a_idx_1 = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_o[1] = rtu_sensor_meas_body_all[4] - rtu_sensor_meas_body_all[7];

    /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_a_idx_2 = 0.0;

    /* Sum: '<S52>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_o[2] = rtu_sensor_meas_body_all[5] - rtu_sensor_meas_body_all[8];

    /* Outputs for Atomic SubSystem: '<S52>/twonorm' */
    rtb_Sqrt_j1 = twonorm(rtb_Subtract_o);

    /* End of Outputs for SubSystem: '<S52>/twonorm' */

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_j1 <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem14' */
  }

  /* End of If: '<S26>/If4' */

  /* If: '<S26>/If5' incorporates:
   *  Inport: '<S55>/In1'
   *  S-Function (sdspperm2): '<S26>/Variable Selector7'
   */
  if (rtu_sensor_valid_all_e) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    rtb_Subtract_o[0] = rtu_sensor_meas_body_all[3];
    rtb_Subtract_o[1] = rtu_sensor_meas_body_all[4];
    rtb_Subtract_o[2] = rtu_sensor_meas_body_all[5];

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem8' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* SignalConversion: '<S51>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_o[0] = 0.0;

    /* Sum: '<S51>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_g[0] = rtu_sensor_meas_body_all[0] - rtu_sensor_meas_body_all[6];

    /* SignalConversion: '<S51>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_o[1] = 0.0;

    /* Sum: '<S51>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_g[1] = rtu_sensor_meas_body_all[1] - rtu_sensor_meas_body_all[7];

    /* SignalConversion: '<S51>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_o[2] = 0.0;

    /* Sum: '<S51>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector8'
     */
    rtb_Subtract_g[2] = rtu_sensor_meas_body_all[2] - rtu_sensor_meas_body_all[8];

    /* Outputs for Atomic SubSystem: '<S51>/twonorm' */
    rtb_Sqrt_j1 = twonorm(rtb_Subtract_g);

    /* End of Outputs for SubSystem: '<S51>/twonorm' */

    /* RelationalOperator: '<S57>/Compare' incorporates:
     *  Constant: '<S57>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_j1 <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */
  }

  /* End of If: '<S26>/If5' */

  /* If: '<S26>/If6' incorporates:
   *  S-Function (sdspperm2): '<S26>/Variable Selector6'
   *  S-Function (sdspperm2): '<S26>/Variable Selector7'
   *  Sum: '<S53>/Subtract'
   */
  if (!rtu_sensor_valid_all_o) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_VariableSelector8_d_idx_0 = 0.0;
    rtb_VariableSelector6_d[0] = rtu_sensor_meas_body_all[0] -
      rtu_sensor_meas_body_all[3];

    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  Sum: '<S53>/Subtract'
     */
    rtb_VariableSelector8_d_idx_1 = 0.0;
    rtb_VariableSelector6_d[1] = rtu_sensor_meas_body_all[1] -
      rtu_sensor_meas_body_all[4];

    /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  Sum: '<S53>/Subtract'
     */
    rtb_VariableSelector8_d_idx_2 = 0.0;
    rtb_VariableSelector6_d[2] = rtu_sensor_meas_body_all[2] -
      rtu_sensor_meas_body_all[5];

    /* Outputs for Atomic SubSystem: '<S53>/twonorm' */
    rtb_Sqrt_j1 = twonorm(rtb_VariableSelector6_d);

    /* End of Outputs for SubSystem: '<S53>/twonorm' */

    /* RelationalOperator: '<S61>/Compare' incorporates:
     *  Constant: '<S61>/Constant'
     *  S-Function (sdspperm2): '<S26>/Variable Selector6'
     *  S-Function (sdspperm2): '<S26>/Variable Selector7'
     *  Sum: '<S53>/Subtract'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_j1 <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem2' */
  }

  /* End of If: '<S26>/If6' */

  /* Gain: '<S26>/Gain1' incorporates:
   *  Sum: '<S26>/Sum1'
   */
  rty_sensor_meas_body[0] = ((rtb_Merge_a_idx_0 + rtb_Subtract_o[0]) +
    rtb_VariableSelector8_d_idx_0) * 0.5;
  rty_sensor_meas_body[1] = ((rtb_Merge_a_idx_1 + rtb_Subtract_o[1]) +
    rtb_VariableSelector8_d_idx_1) * 0.5;
  rty_sensor_meas_body[2] = ((rtb_Merge_a_idx_2 + rtb_Subtract_o[2]) +
    rtb_VariableSelector8_d_idx_2) * 0.5;
}

/*
 * Output and update for action system:
 *    '<S23>/If Action Subsystem14'
 *    '<S23>/If Action Subsystem1'
 *    '<S23>/If Action Subsystem2'
 *    '<S65>/If Action Subsystem14'
 *    '<S65>/If Action Subsystem1'
 *    '<S65>/If Action Subsystem2'
 */
void IfActionSubsystem14(real_T rty_nullOut[3])
{
  /* SignalConversion: '<S28>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
  rty_nullOut[0] = 0.0;
  rty_nullOut[1] = 0.0;
  rty_nullOut[2] = 0.0;
}

/*
 * Output and update for action system:
 *    '<S11>/OneValid'
 *    '<S12>/OneValid'
 */
void OneValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_n, boolean_T
              rtu_sensor_valid_all_f, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_valid)
{
  real_T rtb_VariableSelector6_k[3];
  real_T rtb_VariableSelector7_l[3];
  real_T rtb_VariableSelector8_i[3];

  /* S-Function (sdspperm2): '<S23>/Variable Selector6' */
  rtb_VariableSelector6_k[0] = rtu_sensor_meas_body_all[0];
  rtb_VariableSelector6_k[1] = rtu_sensor_meas_body_all[1];
  rtb_VariableSelector6_k[2] = rtu_sensor_meas_body_all[2];

  /* If: '<S23>/If4' */
  if (!rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector6_k);

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem14' */
  }

  /* End of If: '<S23>/If4' */

  /* S-Function (sdspperm2): '<S23>/Variable Selector7' */
  rtb_VariableSelector7_l[0] = rtu_sensor_meas_body_all[3];
  rtb_VariableSelector7_l[1] = rtu_sensor_meas_body_all[4];
  rtb_VariableSelector7_l[2] = rtu_sensor_meas_body_all[5];

  /* If: '<S23>/If5' */
  if (!rtu_sensor_valid_all_n) {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector7_l);

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */
  }

  /* End of If: '<S23>/If5' */

  /* S-Function (sdspperm2): '<S23>/Variable Selector8' */
  rtb_VariableSelector8_i[0] = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_i[1] = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_i[2] = rtu_sensor_meas_body_all[8];

  /* If: '<S23>/If6' */
  if (!rtu_sensor_valid_all_f) {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector8_i);

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem2' */
  }

  /* End of If: '<S23>/If6' */

  /* Gain: '<S23>/Gain1' incorporates:
   *  Sum: '<S23>/Sum1'
   */
  rty_sensor_meas_body[0] = (rtb_VariableSelector6_k[0] +
    rtb_VariableSelector7_l[0]) + rtb_VariableSelector8_i[0];
  rty_sensor_meas_body[1] = (rtb_VariableSelector6_k[1] +
    rtb_VariableSelector7_l[1]) + rtb_VariableSelector8_i[1];
  rty_sensor_meas_body[2] = (rtb_VariableSelector6_k[2] +
    rtb_VariableSelector7_l[2]) + rtb_VariableSelector8_i[2];

  /* SignalConversion: '<S23>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S23>/Constant'
   */
  *rty_sensor_valid = true;
}

/*
 * Output and update for action system:
 *    '<S11>/NoneValid'
 *    '<S12>/NoneValid'
 */
void NoneValid(const real_T rtu_sensor_meas_body_all[9], real_T
               rty_sensor_meas_body[3], boolean_T *rty_sensor_valid)
{
  /* Gain: '<S22>/Gain' incorporates:
   *  S-Function (sdspperm2): '<S22>/Variable Selector3'
   *  S-Function (sdspperm2): '<S22>/Variable Selector4'
   *  S-Function (sdspperm2): '<S22>/Variable Selector5'
   *  Sum: '<S22>/Sum'
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

  /* SignalConversion: '<S22>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S22>/Constant'
   */
  *rty_sensor_valid = false;
}

/*
 * Output and update for action system:
 *    '<S24>/If Action Subsystem2'
 *    '<S24>/If Action Subsystem4'
 *    '<S24>/If Action Subsystem14'
 *    '<S66>/If Action Subsystem2'
 *    '<S66>/If Action Subsystem4'
 *    '<S66>/If Action Subsystem14'
 */
void IfActionSubsystem2(boolean_T *rty_Out1)
{
  /* SignalConversion: '<S39>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S39>/Constant'
   */
  *rty_Out1 = false;
}

/* System initialize for atomic system: '<S2>/maggyroProcessing_lib' */
void maggyroProcessing_lib_Init(DW_maggyroProcessing_lib *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S11>/ThreeValid_MVS' */
  ThreeValid_MVS_Init(&localDW->ThreeValid_MVS_l);

  /* End of SystemInitialize for SubSystem: '<S11>/ThreeValid_MVS' */
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib' */
void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const boolean_T
  rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T
  *rty_sensor_valid, DW_maggyroProcessing_lib *localDW, real_T rtp_max_err,
  const real_T rtp_offset_calibration_matrix[9], real_T
  rtp_static_range_max_value, real_T rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_e0;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_i;
  boolean_T rtb_conjunction_jv;
  real_T rtb_Merge_o[3];
  boolean_T rtb_Merge_lv;
  boolean_T rtb_Merge1_kw;
  boolean_T rtb_Merge2;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  int32_T i;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S21>/Variable Selector' */
  rtb_Merge_o[0] = rtu_sensor_meas_data[0];
  rtb_Merge_o[1] = rtu_sensor_meas_data[1];
  rtb_Merge_o[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S21>/Matrix Multiply3' incorporates:
     *  Constant: '<S21>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_im[i] * rtb_Merge_o[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_im[i + 3] * rtb_Merge_o[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_im[i + 6] * rtb_Merge_o[2];

    /* Product: '<S21>/Matrix Multiply2' incorporates:
     *  Constant: '<S21>/Constant2'
     *  S-Function (sdspperm2): '<S21>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S21>/Matrix Multiply1' incorporates:
     *  Constant: '<S21>/Constant1'
     *  S-Function (sdspperm2): '<S21>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_a[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_a[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_a[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S21>/Sum' incorporates:
   *  Constant: '<S21>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S21>/Sum' */

  /* S-Function (sdspperm2): '<S24>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S24>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S24>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S24>/twonorm1' */
  rtb_Sqrt_e0 = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S24>/twonorm1' */

  /* Logic: '<S33>/conjunction' incorporates:
   *  Constant: '<S33>/max_val'
   *  Constant: '<S33>/min_val'
   *  RelationalOperator: '<S33>/max_relop'
   *  RelationalOperator: '<S33>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt_e0) && (rtb_Sqrt_e0 <=
    rtp_static_range_max_value));

  /* If: '<S24>/If4' incorporates:
   *  Inport: '<S36>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    rtb_Merge_lv = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_lv);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem14' */
  }

  /* End of If: '<S24>/If4' */

  /* Outputs for Atomic SubSystem: '<S24>/twonorm2' */
  rtb_Sqrt_e0 = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S24>/twonorm2' */

  /* Logic: '<S34>/conjunction' incorporates:
   *  Constant: '<S34>/max_val'
   *  Constant: '<S34>/min_val'
   *  RelationalOperator: '<S34>/max_relop'
   *  RelationalOperator: '<S34>/min_relop'
   */
  rtb_conjunction_i = ((0.0 <= rtb_Sqrt_e0) && (rtb_Sqrt_e0 <=
    rtp_static_range_max_value));

  /* If: '<S24>/If1' incorporates:
   *  Inport: '<S37>/In1'
   */
  if (rtb_conjunction_i) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    rtb_Merge1_kw = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1_kw);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem2' */
  }

  /* End of If: '<S24>/If1' */

  /* Outputs for Atomic SubSystem: '<S24>/twonorm3' */
  rtb_Sqrt_e0 = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S24>/twonorm3' */

  /* Logic: '<S35>/conjunction' incorporates:
   *  Constant: '<S35>/max_val'
   *  Constant: '<S35>/min_val'
   *  RelationalOperator: '<S35>/max_relop'
   *  RelationalOperator: '<S35>/min_relop'
   */
  rtb_conjunction_jv = ((0.0 <= rtb_Sqrt_e0) && (rtb_Sqrt_e0 <=
    rtp_static_range_max_value));

  /* If: '<S24>/If2' incorporates:
   *  Inport: '<S40>/In1'
   */
  if (rtb_conjunction_jv) {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S24>/If Action Subsystem4' */
  }

  /* End of If: '<S24>/If2' */

  /* If: '<S11>/If' */
  tmp = (rtb_Merge_lv && rtb_Merge1_kw);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S11>/ThreeValid_MVS' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    ThreeValid_MVS(rtb_VectorConcatenate, rtb_Merge_o, rty_sensor_valid,
                   &localDW->ThreeValid_MVS_l, rtp_max_err);

    /* End of Outputs for SubSystem: '<S11>/ThreeValid_MVS' */
  } else if (tmp || (rtb_Merge1_kw && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_lv))
  {
    /* Outputs for IfAction SubSystem: '<S11>/TwoValid' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_lv, rtb_Merge1_kw, rtb_Merge2,
             rtb_Merge_o, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S11>/TwoValid' */
  } else if (rtb_Merge_lv || rtb_Merge1_kw || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S11>/OneValid' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_lv, rtb_Merge1_kw, rtb_Merge2,
             rtb_Merge_o, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S11>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/NoneValid' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_o, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S11>/NoneValid' */
  }

  /* End of If: '<S11>/If' */

  /* Gain: '<S11>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_o[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_o[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_o[2];

  /* Assertion: '<S35>/Assertion' */
  utAssert(rtb_conjunction_jv);

  /* Assertion: '<S34>/Assertion' */
  utAssert(rtb_conjunction_i);

  /* Assertion: '<S33>/Assertion' */
  utAssert(rtb_conjunction);
}

/* System initialize for atomic system: '<S2>/maggyroProcessing_lib1' */
void maggyroProcessing_lib1_Init(DW_maggyroProcessing_lib_h *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S12>/ThreeValid_MVS' */
  ThreeValid_MVS_Init(&localDW->ThreeValid_MVS_b);

  /* End of SystemInitialize for SubSystem: '<S12>/ThreeValid_MVS' */
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib1' */
void maggyroProcessing_lib1(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, DW_maggyroProcessing_lib_h *localDW, real_T rtp_max_err,
  const real_T rtp_offset_calibration_matrix[9], real_T
  rtp_static_range_max_value, real_T rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_c;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_b;
  boolean_T rtb_conjunction_n;
  real_T rtb_Merge_ie[3];
  boolean_T rtb_Merge_ph;
  boolean_T rtb_Merge1_b;
  boolean_T rtb_Merge2;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  int32_T i;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S63>/Variable Selector' */
  rtb_Merge_ie[0] = rtu_sensor_meas_data[0];
  rtb_Merge_ie[1] = rtu_sensor_meas_data[1];
  rtb_Merge_ie[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S63>/Matrix Multiply3' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_h[i] * rtb_Merge_ie[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_h[i + 3] * rtb_Merge_ie[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_h[i + 6] * rtb_Merge_ie[2];

    /* Product: '<S63>/Matrix Multiply2' incorporates:
     *  Constant: '<S63>/Constant2'
     *  S-Function (sdspperm2): '<S63>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S63>/Matrix Multiply1' incorporates:
     *  Constant: '<S63>/Constant1'
     *  S-Function (sdspperm2): '<S63>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_o[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_o[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_o[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S63>/Sum' incorporates:
   *  Constant: '<S63>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S63>/Sum' */

  /* S-Function (sdspperm2): '<S66>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S66>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S66>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S66>/twonorm1' */
  rtb_Sqrt_c = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S66>/twonorm1' */

  /* Logic: '<S75>/conjunction' incorporates:
   *  Constant: '<S75>/max_val'
   *  Constant: '<S75>/min_val'
   *  RelationalOperator: '<S75>/max_relop'
   *  RelationalOperator: '<S75>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt_c) && (rtb_Sqrt_c <=
    rtp_static_range_max_value));

  /* If: '<S66>/If4' incorporates:
   *  Inport: '<S78>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    rtb_Merge_ph = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_ph);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem14' */
  }

  /* End of If: '<S66>/If4' */

  /* Outputs for Atomic SubSystem: '<S66>/twonorm2' */
  rtb_Sqrt_c = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S66>/twonorm2' */

  /* Logic: '<S76>/conjunction' incorporates:
   *  Constant: '<S76>/max_val'
   *  Constant: '<S76>/min_val'
   *  RelationalOperator: '<S76>/max_relop'
   *  RelationalOperator: '<S76>/min_relop'
   */
  rtb_conjunction_b = ((0.0 <= rtb_Sqrt_c) && (rtb_Sqrt_c <=
    rtp_static_range_max_value));

  /* If: '<S66>/If1' incorporates:
   *  Inport: '<S79>/In1'
   */
  if (rtb_conjunction_b) {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    rtb_Merge1_b = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1_b);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem2' */
  }

  /* End of If: '<S66>/If1' */

  /* Outputs for Atomic SubSystem: '<S66>/twonorm3' */
  rtb_Sqrt_c = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S66>/twonorm3' */

  /* Logic: '<S77>/conjunction' incorporates:
   *  Constant: '<S77>/max_val'
   *  Constant: '<S77>/min_val'
   *  RelationalOperator: '<S77>/max_relop'
   *  RelationalOperator: '<S77>/min_relop'
   */
  rtb_conjunction_n = ((0.0 <= rtb_Sqrt_c) && (rtb_Sqrt_c <=
    rtp_static_range_max_value));

  /* If: '<S66>/If2' incorporates:
   *  Inport: '<S82>/In1'
   */
  if (rtb_conjunction_n) {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem4' */
  }

  /* End of If: '<S66>/If2' */

  /* If: '<S12>/If' */
  tmp = (rtb_Merge_ph && rtb_Merge1_b);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/ThreeValid_MVS' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    ThreeValid_MVS(rtb_VectorConcatenate, rtb_Merge_ie, rty_sensor_valid,
                   &localDW->ThreeValid_MVS_b, rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/ThreeValid_MVS' */
  } else if (tmp || (rtb_Merge1_b && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_ph))
  {
    /* Outputs for IfAction SubSystem: '<S12>/TwoValid' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_ph, rtb_Merge1_b, rtb_Merge2,
             rtb_Merge_ie, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/TwoValid' */
  } else if (rtb_Merge_ph || rtb_Merge1_b || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/OneValid' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_ph, rtb_Merge1_b, rtb_Merge2,
             rtb_Merge_ie, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/NoneValid' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_ie, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/NoneValid' */
  }

  /* End of If: '<S12>/If' */

  /* Gain: '<S12>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_ie[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_ie[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_ie[2];

  /* Assertion: '<S77>/Assertion' */
  utAssert(rtb_conjunction_n);

  /* Assertion: '<S76>/Assertion' */
  utAssert(rtb_conjunction_b);

  /* Assertion: '<S75>/Assertion' */
  utAssert(rtb_conjunction);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
