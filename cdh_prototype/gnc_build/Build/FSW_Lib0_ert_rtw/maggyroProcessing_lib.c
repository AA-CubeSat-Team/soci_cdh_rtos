/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.c
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

#include "maggyroProcessing_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S19>/If Action Subsystem'
 *    '<S63>/If Action Subsystem'
 */
void IfActionSubsystem(const real_T rtu_In1[3], const real_T rtu_In2[3], const
  real_T rtu_In3[3], real_T rty_avg[3])
{
  /* Gain: '<S40>/Gain' incorporates:
   *  Sum: '<S40>/Sum'
   */
  rty_avg[0] = ((rtu_In1[0] + rtu_In2[0]) + rtu_In3[0]) * 0.33333333333333331;
  rty_avg[1] = ((rtu_In1[1] + rtu_In2[1]) + rtu_In3[1]) * 0.33333333333333331;
  rty_avg[2] = ((rtu_In1[2] + rtu_In2[2]) + rtu_In3[2]) * 0.33333333333333331;
}

/*
 * Output and update for action system:
 *    '<S19>/If Action Subsystem1'
 *    '<S19>/If Action Subsystem2'
 *    '<S63>/If Action Subsystem1'
 *    '<S63>/If Action Subsystem2'
 */
void IfActionSubsystem1(const real_T rtu_In1[3], const real_T rtu_In2[3], real_T
  rty_avg[3])
{
  /* Gain: '<S41>/Gain' incorporates:
   *  Sum: '<S41>/Sum'
   */
  rty_avg[0] = (rtu_In1[0] + rtu_In2[0]) * 0.5;
  rty_avg[1] = (rtu_In1[1] + rtu_In2[1]) * 0.5;
  rty_avg[2] = (rtu_In1[2] + rtu_In2[2]) * 0.5;
}

/*
 * Output and update for action system:
 *    '<S19>/If Action Subsystem3'
 *    '<S63>/If Action Subsystem3'
 */
void IfActionSubsystem3(const real_T rtu_In1[3], const real_T rtu_In2[3], real_T
  rty_Out1[3])
{
  /* Gain: '<S43>/Gain' incorporates:
   *  Sum: '<S43>/Sum'
   */
  rty_Out1[0] = (rtu_In1[0] + rtu_In2[0]) * 0.5;
  rty_Out1[1] = (rtu_In1[1] + rtu_In2[1]) * 0.5;
  rty_Out1[2] = (rtu_In1[2] + rtu_In2[2]) * 0.5;
}

/*
 * Output and update for action system:
 *    '<S11>/TwoValid'
 *    '<S12>/TwoValid'
 */
void TwoValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_c, boolean_T
              rtu_sensor_valid_all_d, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_meas_valid, real_T rtp_max_err)
{
  real_T rtb_Sqrt_l;
  real_T rtb_VariableSelector6_ix[3];
  real_T rtb_Subtract_b[3];
  real_T rtb_Subtract_iz[3];
  real_T rtb_VariableSelector8_o_idx_2;
  real_T rtb_Merge_i_idx_2;
  real_T rtb_VariableSelector8_o_idx_1;
  real_T rtb_Merge_i_idx_1;
  real_T rtb_VariableSelector8_o_idx_0;
  real_T rtb_Merge_i_idx_0;

  /* S-Function (sdspperm2): '<S20>/Variable Selector8' */
  rtb_VariableSelector8_o_idx_0 = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_o_idx_1 = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_o_idx_2 = rtu_sensor_meas_body_all[8];

  /* If: '<S20>/If4' incorporates:
   *  Inport: '<S50>/In1'
   *  S-Function (sdspperm2): '<S20>/Variable Selector6'
   */
  if (rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    rtb_Merge_i_idx_0 = rtu_sensor_meas_body_all[0];
    rtb_Merge_i_idx_1 = rtu_sensor_meas_body_all[1];
    rtb_Merge_i_idx_2 = rtu_sensor_meas_body_all[2];

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* SignalConversion: '<S48>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_i_idx_0 = 0.0;

    /* Sum: '<S48>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_b[0] = rtu_sensor_meas_body_all[3] - rtu_sensor_meas_body_all[6];

    /* SignalConversion: '<S48>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_i_idx_1 = 0.0;

    /* Sum: '<S48>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_b[1] = rtu_sensor_meas_body_all[4] - rtu_sensor_meas_body_all[7];

    /* SignalConversion: '<S48>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Merge_i_idx_2 = 0.0;

    /* Sum: '<S48>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_b[2] = rtu_sensor_meas_body_all[5] - rtu_sensor_meas_body_all[8];

    /* Outputs for Atomic SubSystem: '<S48>/twonorm' */
    rtb_Sqrt_l = twonorm(rtb_Subtract_b);

    /* End of Outputs for SubSystem: '<S48>/twonorm' */

    /* RelationalOperator: '<S55>/Compare' incorporates:
     *  Constant: '<S55>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_l <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem14' */
  }

  /* End of If: '<S20>/If4' */

  /* If: '<S20>/If5' incorporates:
   *  Inport: '<S51>/In1'
   *  S-Function (sdspperm2): '<S20>/Variable Selector7'
   */
  if (rtu_sensor_valid_all_c) {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    rtb_Subtract_b[0] = rtu_sensor_meas_body_all[3];
    rtb_Subtract_b[1] = rtu_sensor_meas_body_all[4];
    rtb_Subtract_b[2] = rtu_sensor_meas_body_all[5];

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem8' */
  } else {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* SignalConversion: '<S47>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_b[0] = 0.0;

    /* Sum: '<S47>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_iz[0] = rtu_sensor_meas_body_all[0] - rtu_sensor_meas_body_all
      [6];

    /* SignalConversion: '<S47>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_b[1] = 0.0;

    /* Sum: '<S47>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_iz[1] = rtu_sensor_meas_body_all[1] - rtu_sensor_meas_body_all
      [7];

    /* SignalConversion: '<S47>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_Subtract_b[2] = 0.0;

    /* Sum: '<S47>/Subtract' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector8'
     */
    rtb_Subtract_iz[2] = rtu_sensor_meas_body_all[2] - rtu_sensor_meas_body_all
      [8];

    /* Outputs for Atomic SubSystem: '<S47>/twonorm' */
    rtb_Sqrt_l = twonorm(rtb_Subtract_iz);

    /* End of Outputs for SubSystem: '<S47>/twonorm' */

    /* RelationalOperator: '<S53>/Compare' incorporates:
     *  Constant: '<S53>/Constant'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_l <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem1' */
  }

  /* End of If: '<S20>/If5' */

  /* If: '<S20>/If6' incorporates:
   *  S-Function (sdspperm2): '<S20>/Variable Selector6'
   *  S-Function (sdspperm2): '<S20>/Variable Selector7'
   *  Sum: '<S49>/Subtract'
   */
  if (!rtu_sensor_valid_all_d) {
    /* Outputs for IfAction SubSystem: '<S20>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion: '<S49>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
    rtb_VariableSelector8_o_idx_0 = 0.0;
    rtb_VariableSelector6_ix[0] = rtu_sensor_meas_body_all[0] -
      rtu_sensor_meas_body_all[3];

    /* SignalConversion: '<S49>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  Sum: '<S49>/Subtract'
     */
    rtb_VariableSelector8_o_idx_1 = 0.0;
    rtb_VariableSelector6_ix[1] = rtu_sensor_meas_body_all[1] -
      rtu_sensor_meas_body_all[4];

    /* SignalConversion: '<S49>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  Sum: '<S49>/Subtract'
     */
    rtb_VariableSelector8_o_idx_2 = 0.0;
    rtb_VariableSelector6_ix[2] = rtu_sensor_meas_body_all[2] -
      rtu_sensor_meas_body_all[5];

    /* Outputs for Atomic SubSystem: '<S49>/twonorm' */
    rtb_Sqrt_l = twonorm(rtb_VariableSelector6_ix);

    /* End of Outputs for SubSystem: '<S49>/twonorm' */

    /* RelationalOperator: '<S57>/Compare' incorporates:
     *  Constant: '<S57>/Constant'
     *  S-Function (sdspperm2): '<S20>/Variable Selector6'
     *  S-Function (sdspperm2): '<S20>/Variable Selector7'
     *  Sum: '<S49>/Subtract'
     */
    *rty_sensor_meas_valid = (rtb_Sqrt_l <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S20>/If Action Subsystem2' */
  }

  /* End of If: '<S20>/If6' */

  /* Gain: '<S20>/Gain1' incorporates:
   *  Sum: '<S20>/Sum1'
   */
  rty_sensor_meas_body[0] = ((rtb_Merge_i_idx_0 + rtb_Subtract_b[0]) +
    rtb_VariableSelector8_o_idx_0) * 0.5;
  rty_sensor_meas_body[1] = ((rtb_Merge_i_idx_1 + rtb_Subtract_b[1]) +
    rtb_VariableSelector8_o_idx_1) * 0.5;
  rty_sensor_meas_body[2] = ((rtb_Merge_i_idx_2 + rtb_Subtract_b[2]) +
    rtb_VariableSelector8_o_idx_2) * 0.5;
}

/*
 * Output and update for action system:
 *    '<S17>/If Action Subsystem14'
 *    '<S17>/If Action Subsystem1'
 *    '<S17>/If Action Subsystem2'
 *    '<S61>/If Action Subsystem14'
 *    '<S61>/If Action Subsystem1'
 *    '<S61>/If Action Subsystem2'
 */
void IfActionSubsystem14(real_T rty_nullOut[3])
{
  /* SignalConversion: '<S22>/OutportBuffer_InsertedFor_nullOut_at_inport_0' */
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
              rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_m, boolean_T
              rtu_sensor_valid_all_a, real_T rty_sensor_meas_body[3], boolean_T *
              rty_sensor_valid)
{
  real_T rtb_VariableSelector6_e[3];
  real_T rtb_VariableSelector7_d[3];
  real_T rtb_VariableSelector8_b[3];

  /* S-Function (sdspperm2): '<S17>/Variable Selector6' */
  rtb_VariableSelector6_e[0] = rtu_sensor_meas_body_all[0];
  rtb_VariableSelector6_e[1] = rtu_sensor_meas_body_all[1];
  rtb_VariableSelector6_e[2] = rtu_sensor_meas_body_all[2];

  /* If: '<S17>/If4' */
  if (!rtu_sensor_valid_all) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector6_e);

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem14' */
  }

  /* End of If: '<S17>/If4' */

  /* S-Function (sdspperm2): '<S17>/Variable Selector7' */
  rtb_VariableSelector7_d[0] = rtu_sensor_meas_body_all[3];
  rtb_VariableSelector7_d[1] = rtu_sensor_meas_body_all[4];
  rtb_VariableSelector7_d[2] = rtu_sensor_meas_body_all[5];

  /* If: '<S17>/If5' */
  if (!rtu_sensor_valid_all_m) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector7_d);

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
  }

  /* End of If: '<S17>/If5' */

  /* S-Function (sdspperm2): '<S17>/Variable Selector8' */
  rtb_VariableSelector8_b[0] = rtu_sensor_meas_body_all[6];
  rtb_VariableSelector8_b[1] = rtu_sensor_meas_body_all[7];
  rtb_VariableSelector8_b[2] = rtu_sensor_meas_body_all[8];

  /* If: '<S17>/If6' */
  if (!rtu_sensor_valid_all_a) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    IfActionSubsystem14(rtb_VariableSelector8_b);

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem2' */
  }

  /* End of If: '<S17>/If6' */

  /* Gain: '<S17>/Gain1' incorporates:
   *  Sum: '<S17>/Sum1'
   */
  rty_sensor_meas_body[0] = (rtb_VariableSelector6_e[0] +
    rtb_VariableSelector7_d[0]) + rtb_VariableSelector8_b[0];
  rty_sensor_meas_body[1] = (rtb_VariableSelector6_e[1] +
    rtb_VariableSelector7_d[1]) + rtb_VariableSelector8_b[1];
  rty_sensor_meas_body[2] = (rtb_VariableSelector6_e[2] +
    rtb_VariableSelector7_d[2]) + rtb_VariableSelector8_b[2];

  /* SignalConversion: '<S17>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S17>/Constant'
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
  /* Gain: '<S16>/Gain' incorporates:
   *  S-Function (sdspperm2): '<S16>/Variable Selector3'
   *  S-Function (sdspperm2): '<S16>/Variable Selector4'
   *  S-Function (sdspperm2): '<S16>/Variable Selector5'
   *  Sum: '<S16>/Sum'
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

  /* SignalConversion: '<S16>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
   *  Constant: '<S16>/Constant'
   */
  *rty_sensor_valid = false;
}

/*
 * Output and update for action system:
 *    '<S18>/If Action Subsystem2'
 *    '<S18>/If Action Subsystem4'
 *    '<S18>/If Action Subsystem14'
 *    '<S62>/If Action Subsystem2'
 *    '<S62>/If Action Subsystem4'
 *    '<S62>/If Action Subsystem14'
 */
void IfActionSubsystem2(boolean_T *rty_Out1)
{
  /* SignalConversion: '<S33>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S33>/Constant'
   */
  *rty_Out1 = false;
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib' */
void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const boolean_T
  rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T
  *rty_sensor_valid, real_T rtp_max_err, const real_T
  rtp_offset_calibration_matrix[9], real_T rtp_static_range_max_value, real_T
  rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt_dr;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_a;
  boolean_T rtb_conjunction_l;
  real_T rtb_Merge_p[3];
  boolean_T rtb_Merge_k;
  boolean_T rtb_Merge1;
  boolean_T rtb_Merge2;
  real_T rtb_Sqrt_c1;
  real_T rtb_Sqrt;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  real_T rtb_VariableSelector1[3];
  real_T rtb_VariableSelector2[3];
  real_T rtb_VariableSelector[3];
  int32_T i;
  real_T u0;
  real_T u1;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S15>/Variable Selector' */
  rtb_Merge_p[0] = rtu_sensor_meas_data[0];
  rtb_Merge_p[1] = rtu_sensor_meas_data[1];
  rtb_Merge_p[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S15>/Matrix Multiply3' incorporates:
     *  Constant: '<S15>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_ps[i] * rtb_Merge_p[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_ps[i + 3] * rtb_Merge_p[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_ps[i + 6] * rtb_Merge_p[2];

    /* Product: '<S15>/Matrix Multiply2' incorporates:
     *  Constant: '<S15>/Constant2'
     *  S-Function (sdspperm2): '<S15>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S15>/Matrix Multiply1' incorporates:
     *  Constant: '<S15>/Constant1'
     *  S-Function (sdspperm2): '<S15>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S15>/Sum' */

  /* S-Function (sdspperm2): '<S18>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S18>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S18>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S18>/twonorm1' */
  rtb_Sqrt_dr = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S18>/twonorm1' */

  /* Logic: '<S27>/conjunction' incorporates:
   *  Constant: '<S27>/max_val'
   *  Constant: '<S27>/min_val'
   *  RelationalOperator: '<S27>/max_relop'
   *  RelationalOperator: '<S27>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt_dr) && (rtb_Sqrt_dr <=
    rtp_static_range_max_value));

  /* If: '<S18>/If4' incorporates:
   *  Inport: '<S30>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    rtb_Merge_k = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_k);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem14' */
  }

  /* End of If: '<S18>/If4' */

  /* Outputs for Atomic SubSystem: '<S18>/twonorm2' */
  rtb_Sqrt_dr = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S18>/twonorm2' */

  /* Logic: '<S28>/conjunction' incorporates:
   *  Constant: '<S28>/max_val'
   *  Constant: '<S28>/min_val'
   *  RelationalOperator: '<S28>/max_relop'
   *  RelationalOperator: '<S28>/min_relop'
   */
  rtb_conjunction_a = ((0.0 <= rtb_Sqrt_dr) && (rtb_Sqrt_dr <=
    rtp_static_range_max_value));

  /* If: '<S18>/If1' incorporates:
   *  Inport: '<S31>/In1'
   */
  if (rtb_conjunction_a) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    rtb_Merge1 = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem2' */
  }

  /* End of If: '<S18>/If1' */

  /* Outputs for Atomic SubSystem: '<S18>/twonorm3' */
  rtb_Sqrt_dr = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S18>/twonorm3' */

  /* Logic: '<S29>/conjunction' incorporates:
   *  Constant: '<S29>/max_val'
   *  Constant: '<S29>/min_val'
   *  RelationalOperator: '<S29>/max_relop'
   *  RelationalOperator: '<S29>/min_relop'
   */
  rtb_conjunction_l = ((0.0 <= rtb_Sqrt_dr) && (rtb_Sqrt_dr <=
    rtp_static_range_max_value));

  /* If: '<S18>/If2' incorporates:
   *  Inport: '<S34>/In1'
   */
  if (rtb_conjunction_l) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem4' */
  }

  /* End of If: '<S18>/If2' */

  /* If: '<S11>/If' */
  tmp = (rtb_Merge_k && rtb_Merge1);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S11>/ThreeValid' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* S-Function (sdspperm2): '<S19>/Variable Selector1' */
    rtb_VariableSelector1[0] = rtb_VectorConcatenate[3];
    rtb_VariableSelector1[1] = rtb_VectorConcatenate[4];
    rtb_VariableSelector1[2] = rtb_VectorConcatenate[5];

    /* S-Function (sdspperm2): '<S19>/Variable Selector2' */
    rtb_VariableSelector2[0] = rtb_VectorConcatenate[6];
    rtb_VariableSelector2[1] = rtb_VectorConcatenate[7];
    rtb_VariableSelector2[2] = rtb_VectorConcatenate[8];

    /* S-Function (sdspperm2): '<S19>/Variable Selector' */
    rtb_VariableSelector[0] = rtb_VectorConcatenate[0];

    /* Sum: '<S19>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S19>/Variable Selector1'
     *  S-Function (sdspperm2): '<S19>/Variable Selector2'
     */
    rtb_Merge_p[0] = rtb_VectorConcatenate[3] - rtb_VectorConcatenate[6];

    /* S-Function (sdspperm2): '<S19>/Variable Selector' */
    rtb_VariableSelector[1] = rtb_VectorConcatenate[1];

    /* Sum: '<S19>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S19>/Variable Selector1'
     *  S-Function (sdspperm2): '<S19>/Variable Selector2'
     */
    rtb_Merge_p[1] = rtb_VectorConcatenate[4] - rtb_VectorConcatenate[7];

    /* S-Function (sdspperm2): '<S19>/Variable Selector' */
    rtb_VariableSelector[2] = rtb_VectorConcatenate[2];

    /* Sum: '<S19>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S19>/Variable Selector1'
     *  S-Function (sdspperm2): '<S19>/Variable Selector2'
     */
    rtb_Merge_p[2] = rtb_VectorConcatenate[5] - rtb_VectorConcatenate[8];

    /* Outputs for Atomic SubSystem: '<S19>/twonorm3' */
    rtb_Sqrt_dr = twonorm(rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S19>/twonorm3' */

    /* Sum: '<S19>/Subtract2' incorporates:
     *  S-Function (sdspperm2): '<S19>/Variable Selector'
     *  S-Function (sdspperm2): '<S19>/Variable Selector2'
     */
    rtb_Merge_p[0] = rtb_VectorConcatenate[0] - rtb_VectorConcatenate[6];
    rtb_Merge_p[1] = rtb_VectorConcatenate[1] - rtb_VectorConcatenate[7];
    rtb_Merge_p[2] = rtb_VectorConcatenate[2] - rtb_VectorConcatenate[8];

    /* Outputs for Atomic SubSystem: '<S19>/twonorm2' */
    rtb_Sqrt = twonorm(rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S19>/twonorm2' */

    /* Sum: '<S19>/Subtract1' incorporates:
     *  S-Function (sdspperm2): '<S19>/Variable Selector'
     *  S-Function (sdspperm2): '<S19>/Variable Selector1'
     */
    rtb_Merge_p[0] = rtb_VectorConcatenate[0] - rtb_VectorConcatenate[3];
    rtb_Merge_p[1] = rtb_VectorConcatenate[1] - rtb_VectorConcatenate[4];
    rtb_Merge_p[2] = rtb_VectorConcatenate[2] - rtb_VectorConcatenate[5];

    /* Outputs for Atomic SubSystem: '<S19>/twonorm1' */
    rtb_Sqrt_c1 = twonorm(rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S19>/twonorm1' */

    /* If: '<S19>/If' */
    if ((rtb_Sqrt_c1 <= 0.21629296228661718) && (rtb_Sqrt <= 0.21629296228661718)
        && (rtb_Sqrt_dr <= 0.21629296228661718)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      IfActionSubsystem(rtb_VariableSelector, rtb_VariableSelector1,
                        rtb_VariableSelector2, rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */
    } else if ((rtb_Sqrt_c1 <= rtb_Sqrt) && (rtb_Sqrt_c1 <= rtb_Sqrt_dr)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      IfActionSubsystem1(rtb_VariableSelector, rtb_VariableSelector1,
                         rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
    } else if ((rtb_Sqrt <= rtb_Sqrt_dr) && (rtb_Sqrt <= rtb_Sqrt_c1)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      IfActionSubsystem1(rtb_VariableSelector, rtb_VariableSelector2,
                         rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      IfActionSubsystem3(rtb_VariableSelector1, rtb_VariableSelector2,
                         rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem3' */
    }

    /* End of If: '<S19>/If' */

    /* MinMax: '<S19>/MinMax' */
    u0 = rtb_Sqrt_dr;
    u1 = rtb_Sqrt;
    if ((u0 < u1) || rtIsNaN(u1)) {
      u1 = u0;
    }

    u0 = rtb_Sqrt_c1;
    if ((u1 < u0) || rtIsNaN(u0)) {
      rtb_Sqrt_dr = u1;
    } else {
      rtb_Sqrt_dr = u0;
    }

    /* End of MinMax: '<S19>/MinMax' */

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     */
    *rty_sensor_valid = (rtb_Sqrt_dr <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S11>/ThreeValid' */
  } else if (tmp || (rtb_Merge1 && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_k)) {
    /* Outputs for IfAction SubSystem: '<S11>/TwoValid' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_k, rtb_Merge1, rtb_Merge2,
             rtb_Merge_p, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S11>/TwoValid' */
  } else if (rtb_Merge_k || rtb_Merge1 || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S11>/OneValid' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_k, rtb_Merge1, rtb_Merge2,
             rtb_Merge_p, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S11>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/NoneValid' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_p, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S11>/NoneValid' */
  }

  /* End of If: '<S11>/If' */

  /* Gain: '<S11>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_p[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_p[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_p[2];

  /* Assertion: '<S29>/Assertion' */
  utAssert(rtb_conjunction_l);

  /* Assertion: '<S28>/Assertion' */
  utAssert(rtb_conjunction_a);

  /* Assertion: '<S27>/Assertion' */
  utAssert(rtb_conjunction);
}

/* Output and update for atomic system: '<S2>/maggyroProcessing_lib1' */
void maggyroProcessing_lib1(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, real_T rtp_max_err, const real_T
  rtp_offset_calibration_matrix[9], real_T rtp_static_range_max_value, real_T
  rtp_Gain)
{
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Sqrt;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_b;
  boolean_T rtb_conjunction_d;
  real_T rtb_Merge_f[3];
  boolean_T rtb_Merge_k;
  boolean_T rtb_Merge1;
  boolean_T rtb_Merge2;
  real_T rtb_Sqrt_k;
  real_T rtb_Sqrt_p;
  real_T rtb_VariableSelector6[3];
  real_T rtb_VariableSelector7[3];
  real_T rtb_VariableSelector8[3];
  real_T rtb_VariableSelector1[3];
  real_T rtb_VariableSelector2[3];
  real_T rtb_VariableSelector[3];
  int32_T i;
  real_T u0;
  real_T u1;
  boolean_T tmp;

  /* S-Function (sdspperm2): '<S59>/Variable Selector' */
  rtb_Merge_f[0] = rtu_sensor_meas_data[0];
  rtb_Merge_f[1] = rtu_sensor_meas_data[1];
  rtb_Merge_f[2] = rtu_sensor_meas_data[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S59>/Matrix Multiply3' incorporates:
     *  Constant: '<S59>/Constant'
     */
    rtb_VectorConcatenate[i] = 0.0;
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_a[i] * rtb_Merge_f[0];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_a[i + 3] * rtb_Merge_f[1];
    rtb_VectorConcatenate[i] += rtCP_Constant_Value_a[i + 6] * rtb_Merge_f[2];

    /* Product: '<S59>/Matrix Multiply2' incorporates:
     *  Constant: '<S59>/Constant2'
     *  S-Function (sdspperm2): '<S59>/Variable Selector2'
     */
    rtb_VectorConcatenate[6 + i] = 0.0;
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i] *
      rtu_sensor_meas_data[6];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i + 3] *
      rtu_sensor_meas_data[7];
    rtb_VectorConcatenate[6 + i] += rtCP_Constant2_Value_b[i + 6] *
      rtu_sensor_meas_data[8];

    /* Product: '<S59>/Matrix Multiply1' incorporates:
     *  Constant: '<S59>/Constant1'
     *  S-Function (sdspperm2): '<S59>/Variable Selector1'
     */
    rtb_VectorConcatenate[3 + i] = 0.0;
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_e[i] *
      rtu_sensor_meas_data[3];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_e[i + 3] *
      rtu_sensor_meas_data[4];
    rtb_VectorConcatenate[3 + i] += rtCP_Constant1_Value_e[i + 6] *
      rtu_sensor_meas_data[5];
  }

  /* Sum: '<S59>/Sum' incorporates:
   *  Constant: '<S59>/mag_offset'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i] += rtp_offset_calibration_matrix[i];
  }

  /* End of Sum: '<S59>/Sum' */

  /* S-Function (sdspperm2): '<S62>/Variable Selector6' */
  rtb_VariableSelector6[0] = rtb_VectorConcatenate[0];
  rtb_VariableSelector6[1] = rtb_VectorConcatenate[1];
  rtb_VariableSelector6[2] = rtb_VectorConcatenate[2];

  /* S-Function (sdspperm2): '<S62>/Variable Selector7' */
  rtb_VariableSelector7[0] = rtb_VectorConcatenate[3];
  rtb_VariableSelector7[1] = rtb_VectorConcatenate[4];
  rtb_VariableSelector7[2] = rtb_VectorConcatenate[5];

  /* S-Function (sdspperm2): '<S62>/Variable Selector8' */
  rtb_VariableSelector8[0] = rtb_VectorConcatenate[6];
  rtb_VariableSelector8[1] = rtb_VectorConcatenate[7];
  rtb_VariableSelector8[2] = rtb_VectorConcatenate[8];

  /* Outputs for Atomic SubSystem: '<S62>/twonorm1' */
  rtb_Sqrt = twonorm(rtb_VariableSelector6);

  /* End of Outputs for SubSystem: '<S62>/twonorm1' */

  /* Logic: '<S71>/conjunction' incorporates:
   *  Constant: '<S71>/max_val'
   *  Constant: '<S71>/min_val'
   *  RelationalOperator: '<S71>/max_relop'
   *  RelationalOperator: '<S71>/min_relop'
   */
  rtb_conjunction = ((0.0 <= rtb_Sqrt) && (rtb_Sqrt <=
    rtp_static_range_max_value));

  /* If: '<S62>/If4' incorporates:
   *  Inport: '<S74>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    rtb_Merge_k = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_k);

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem14' */
  }

  /* End of If: '<S62>/If4' */

  /* Outputs for Atomic SubSystem: '<S62>/twonorm2' */
  rtb_Sqrt = twonorm(rtb_VariableSelector7);

  /* End of Outputs for SubSystem: '<S62>/twonorm2' */

  /* Logic: '<S72>/conjunction' incorporates:
   *  Constant: '<S72>/max_val'
   *  Constant: '<S72>/min_val'
   *  RelationalOperator: '<S72>/max_relop'
   *  RelationalOperator: '<S72>/min_relop'
   */
  rtb_conjunction_b = ((0.0 <= rtb_Sqrt) && (rtb_Sqrt <=
    rtp_static_range_max_value));

  /* If: '<S62>/If1' incorporates:
   *  Inport: '<S75>/In1'
   */
  if (rtb_conjunction_b) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    rtb_Merge1 = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem2' */
  }

  /* End of If: '<S62>/If1' */

  /* Outputs for Atomic SubSystem: '<S62>/twonorm3' */
  rtb_Sqrt = twonorm(rtb_VariableSelector8);

  /* End of Outputs for SubSystem: '<S62>/twonorm3' */

  /* Logic: '<S73>/conjunction' incorporates:
   *  Constant: '<S73>/max_val'
   *  Constant: '<S73>/min_val'
   *  RelationalOperator: '<S73>/max_relop'
   *  RelationalOperator: '<S73>/min_relop'
   */
  rtb_conjunction_d = ((0.0 <= rtb_Sqrt) && (rtb_Sqrt <=
    rtp_static_range_max_value));

  /* If: '<S62>/If2' incorporates:
   *  Inport: '<S78>/In1'
   */
  if (rtb_conjunction_d) {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    rtb_Merge2 = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2);

    /* End of Outputs for SubSystem: '<S62>/If Action Subsystem4' */
  }

  /* End of If: '<S62>/If2' */

  /* If: '<S12>/If' */
  tmp = (rtb_Merge_k && rtb_Merge1);
  if (tmp && rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/ThreeValid' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    /* S-Function (sdspperm2): '<S63>/Variable Selector1' */
    rtb_VariableSelector1[0] = rtb_VectorConcatenate[3];
    rtb_VariableSelector1[1] = rtb_VectorConcatenate[4];
    rtb_VariableSelector1[2] = rtb_VectorConcatenate[5];

    /* S-Function (sdspperm2): '<S63>/Variable Selector2' */
    rtb_VariableSelector2[0] = rtb_VectorConcatenate[6];
    rtb_VariableSelector2[1] = rtb_VectorConcatenate[7];
    rtb_VariableSelector2[2] = rtb_VectorConcatenate[8];

    /* S-Function (sdspperm2): '<S63>/Variable Selector' */
    rtb_VariableSelector[0] = rtb_VectorConcatenate[0];

    /* Sum: '<S63>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S63>/Variable Selector1'
     *  S-Function (sdspperm2): '<S63>/Variable Selector2'
     */
    rtb_Merge_f[0] = rtb_VectorConcatenate[3] - rtb_VectorConcatenate[6];

    /* S-Function (sdspperm2): '<S63>/Variable Selector' */
    rtb_VariableSelector[1] = rtb_VectorConcatenate[1];

    /* Sum: '<S63>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S63>/Variable Selector1'
     *  S-Function (sdspperm2): '<S63>/Variable Selector2'
     */
    rtb_Merge_f[1] = rtb_VectorConcatenate[4] - rtb_VectorConcatenate[7];

    /* S-Function (sdspperm2): '<S63>/Variable Selector' */
    rtb_VariableSelector[2] = rtb_VectorConcatenate[2];

    /* Sum: '<S63>/Subtract3' incorporates:
     *  S-Function (sdspperm2): '<S63>/Variable Selector1'
     *  S-Function (sdspperm2): '<S63>/Variable Selector2'
     */
    rtb_Merge_f[2] = rtb_VectorConcatenate[5] - rtb_VectorConcatenate[8];

    /* Outputs for Atomic SubSystem: '<S63>/twonorm3' */
    rtb_Sqrt = twonorm(rtb_Merge_f);

    /* End of Outputs for SubSystem: '<S63>/twonorm3' */

    /* Sum: '<S63>/Subtract2' incorporates:
     *  S-Function (sdspperm2): '<S63>/Variable Selector'
     *  S-Function (sdspperm2): '<S63>/Variable Selector2'
     */
    rtb_Merge_f[0] = rtb_VectorConcatenate[0] - rtb_VectorConcatenate[6];
    rtb_Merge_f[1] = rtb_VectorConcatenate[1] - rtb_VectorConcatenate[7];
    rtb_Merge_f[2] = rtb_VectorConcatenate[2] - rtb_VectorConcatenate[8];

    /* Outputs for Atomic SubSystem: '<S63>/twonorm2' */
    rtb_Sqrt_p = twonorm(rtb_Merge_f);

    /* End of Outputs for SubSystem: '<S63>/twonorm2' */

    /* Sum: '<S63>/Subtract1' incorporates:
     *  S-Function (sdspperm2): '<S63>/Variable Selector'
     *  S-Function (sdspperm2): '<S63>/Variable Selector1'
     */
    rtb_Merge_f[0] = rtb_VectorConcatenate[0] - rtb_VectorConcatenate[3];
    rtb_Merge_f[1] = rtb_VectorConcatenate[1] - rtb_VectorConcatenate[4];
    rtb_Merge_f[2] = rtb_VectorConcatenate[2] - rtb_VectorConcatenate[5];

    /* Outputs for Atomic SubSystem: '<S63>/twonorm1' */
    rtb_Sqrt_k = twonorm(rtb_Merge_f);

    /* End of Outputs for SubSystem: '<S63>/twonorm1' */

    /* If: '<S63>/If' */
    if ((rtb_Sqrt_k <= 0.02) && (rtb_Sqrt_p <= 0.02) && (rtb_Sqrt <= 0.02)) {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      IfActionSubsystem(rtb_VariableSelector, rtb_VariableSelector1,
                        rtb_VariableSelector2, rtb_Merge_f);

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem' */
    } else if ((rtb_Sqrt_k <= rtb_Sqrt_p) && (rtb_Sqrt_k <= rtb_Sqrt)) {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S85>/Action Port'
       */
      IfActionSubsystem1(rtb_VariableSelector, rtb_VariableSelector1,
                         rtb_Merge_f);

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem1' */
    } else if ((rtb_Sqrt_p <= rtb_Sqrt) && (rtb_Sqrt_p <= rtb_Sqrt_k)) {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S86>/Action Port'
       */
      IfActionSubsystem1(rtb_VariableSelector, rtb_VariableSelector2,
                         rtb_Merge_f);

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S87>/Action Port'
       */
      IfActionSubsystem3(rtb_VariableSelector1, rtb_VariableSelector2,
                         rtb_Merge_f);

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem3' */
    }

    /* End of If: '<S63>/If' */

    /* MinMax: '<S63>/MinMax' */
    u0 = rtb_Sqrt;
    u1 = rtb_Sqrt_p;
    if ((u0 < u1) || rtIsNaN(u1)) {
      u1 = u0;
    }

    u0 = rtb_Sqrt_k;
    if ((u1 < u0) || rtIsNaN(u0)) {
      rtb_Sqrt = u1;
    } else {
      rtb_Sqrt = u0;
    }

    /* End of MinMax: '<S63>/MinMax' */

    /* RelationalOperator: '<S83>/Compare' incorporates:
     *  Constant: '<S83>/Constant'
     */
    *rty_sensor_valid = (rtb_Sqrt <= rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/ThreeValid' */
  } else if (tmp || (rtb_Merge1 && rtb_Merge2) || (rtb_Merge2 && rtb_Merge_k)) {
    /* Outputs for IfAction SubSystem: '<S12>/TwoValid' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    TwoValid(rtb_VectorConcatenate, rtb_Merge_k, rtb_Merge1, rtb_Merge2,
             rtb_Merge_f, rty_sensor_valid, rtp_max_err);

    /* End of Outputs for SubSystem: '<S12>/TwoValid' */
  } else if (rtb_Merge_k || rtb_Merge1 || rtb_Merge2) {
    /* Outputs for IfAction SubSystem: '<S12>/OneValid' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    OneValid(rtb_VectorConcatenate, rtb_Merge_k, rtb_Merge1, rtb_Merge2,
             rtb_Merge_f, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/NoneValid' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    NoneValid(rtb_VectorConcatenate, rtb_Merge_f, rty_sensor_valid);

    /* End of Outputs for SubSystem: '<S12>/NoneValid' */
  }

  /* End of If: '<S12>/If' */

  /* Gain: '<S12>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * rtb_Merge_f[0];
  rty_sensor_meas_body[1] = rtp_Gain * rtb_Merge_f[1];
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_f[2];

  /* Assertion: '<S73>/Assertion' */
  utAssert(rtb_conjunction_d);

  /* Assertion: '<S72>/Assertion' */
  utAssert(rtb_conjunction_b);

  /* Assertion: '<S71>/Assertion' */
  utAssert(rtb_conjunction);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
