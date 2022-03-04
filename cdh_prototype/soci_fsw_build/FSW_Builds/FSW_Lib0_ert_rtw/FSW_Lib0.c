/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0.c
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

#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "norm_2e9Xj4lM.h"
#include "sort_E8F8dFL3.h"

const soar_telemetry FSW_Lib0_rtZsoar_telemetry = {
  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* opt_state */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* opt_ctrl_Nm */
  0.0,                                 /* final_time_s */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 }
  ,                                    /* exitcode */
  0U                                   /* soar_count */
} ;                                    /* soar_telemetry ground */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/*
 * Output and update for action system:
 *    '<S229>/If Action Subsystem'
 *    '<S229>/If Action Subsystem3'
 */
void IfActionSubsystem(real_T *rty_Out1)
{
  /* SignalConversion: '<S260>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S260>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S229>/If Action Subsystem1'
 *    '<S229>/If Action Subsystem4'
 */
void IfActionSubsystem1(real_T *rty_Out1)
{
  /* SignalConversion: '<S261>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S261>/Constant'
   */
  *rty_Out1 = 2.0;
}

/*
 * Output and update for action system:
 *    '<S229>/If Action Subsystem2'
 *    '<S229>/If Action Subsystem5'
 */
void IfActionSubsystem2_i(real_T *rty_Out1)
{
  /* SignalConversion: '<S262>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S262>/Constant'
   */
  *rty_Out1 = 0.0;
}

/* Model step function for TID0 */
void FSW_Lib0_step0(void)              /* Sample time: [0.0125s, 0.0s] */
{
  real_T rtb_deg2rad[9];
  int32_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0125s, 0.0s] to Sample time: [0.25s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 19) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<S2>/Rate Transition3' incorporates:
   *  Inport: '<Root>/sensor_meas'
   */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    memcpy(&rtDW.RateTransition3[0], &rtU.sensor_meas.mag_mag_uT[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_k[0] = rtU.sensor_meas.mag_meas_valid[0];
    rtDW.RateTransition6_k[1] = rtU.sensor_meas.mag_meas_valid[1];
    rtDW.RateTransition6_k[2] = rtU.sensor_meas.mag_meas_valid[2];
  }

  /* End of RateTransition: '<S2>/Rate Transition3' */

  /* Gain: '<S2>/deg2rad' incorporates:
   *  Inport: '<Root>/sensor_meas'
   */
  for (i = 0; i < 9; i++) {
    rtb_deg2rad[i] = 0.017453292519943295 * rtU.sensor_meas.gyro_gyro_radps[i];
  }

  /* End of Gain: '<S2>/deg2rad' */

  /* RateTransition: '<S2>/Rate Transition4' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    memcpy(&rtDW.RateTransition4[0], &rtb_deg2rad[0], 9U * sizeof(real_T));

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition7[0] = rtU.sensor_meas.gyro_meas_valid[0];
    rtDW.RateTransition7[1] = rtU.sensor_meas.gyro_meas_valid[1];
    rtDW.RateTransition7[2] = rtU.sensor_meas.gyro_meas_valid[2];

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition2[0] = rtU.sensor_meas.sun_meas_ss_deg[0];
    rtDW.RateTransition2[1] = rtU.sensor_meas.sun_meas_ss_deg[1];

    /* RateTransition: '<S2>/Rate Transition5' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition5 = rtU.sensor_meas.sun_meas_valid;

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    rtDW.triad_override = rtU.telecommands.triad_override;
    rtDW.MET_soar_utc_s = rtU.telecommands.MET_soar_utc_s;
    rtDW.quat_soar_cmd[0] = rtU.telecommands.quat_soar_cmd[0];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_rpm[0] = rtU.actuator_meas_p.rwa_rpm[0];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    rtDW.quat_soar_cmd[1] = rtU.telecommands.quat_soar_cmd[1];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_rpm[1] = rtU.actuator_meas_p.rwa_rpm[1];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    rtDW.quat_soar_cmd[2] = rtU.telecommands.quat_soar_cmd[2];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_rpm[2] = rtU.actuator_meas_p.rwa_rpm[2];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    rtDW.quat_soar_cmd[3] = rtU.telecommands.quat_soar_cmd[3];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_rpm[3] = rtU.actuator_meas_p.rwa_rpm[3];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    for (i = 0; i < 6; i++) {
      rtDW.telecom[i] = rtU.telecommands.telecom[i];
    }

    /* RateTransition: '<S2>/Rate Transition1' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    for (i = 0; i < 5; i++) {
      rtDW.RateTransition1_i[i] = rtU.sensor_meas.photodiodes_uA[i];
    }

    /* End of RateTransition: '<S2>/Rate Transition1' */

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.gnc_mode = rtDW.RateTransition4_1_Buffer0;

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_valid[0] = rtU.actuator_meas_p.rwa_valid[0];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[0] = rtDW.RateTransition4_2_Buffer0[0];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_valid[1] = rtU.actuator_meas_p.rwa_valid[1];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[1] = rtDW.RateTransition4_2_Buffer0[1];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_valid[2] = rtU.actuator_meas_p.rwa_valid[2];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[2] = rtDW.RateTransition4_2_Buffer0[2];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.rwa_valid[3] = rtU.actuator_meas_p.rwa_valid[3];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[3] = rtDW.RateTransition4_2_Buffer0[3];
    rtDW.sc_body_rates_radps[0] = rtDW.RateTransition4_3_Buffer0[0];
    rtDW.sc_body_rates_radps[1] = rtDW.RateTransition4_3_Buffer0[1];
    rtDW.sc_body_rates_radps[2] = rtDW.RateTransition4_3_Buffer0[2];
    rtDW.cmd_quat[0] = rtDW.RateTransition4_4_Buffer0[0];
    rtDW.cmd_quat[1] = rtDW.RateTransition4_4_Buffer0[1];
    rtDW.cmd_quat[2] = rtDW.RateTransition4_4_Buffer0[2];
    rtDW.cmd_quat[3] = rtDW.RateTransition4_4_Buffer0[3];
    rtDW.cmd_body_rates_radps[0] = rtDW.RateTransition4_5_Buffer0[0];
    rtDW.cmd_body_rates_radps[1] = rtDW.RateTransition4_5_Buffer0[1];
    rtDW.cmd_body_rates_radps[2] = rtDW.RateTransition4_5_Buffer0[2];
    for (i = 0; i < 6; i++) {
      rtDW.mekf_3sigma_rad[i] = rtDW.RateTransition4_6_Buffer0[i];
    }

    rtDW.mekf_telem = rtDW.RateTransition4_8_Buffer0;
    rtDW.mekf_bias_radps[0] = rtDW.RateTransition4_7_Buffer0[0];
    rtDW.r_eci_m[0] = rtDW.RateTransition4_9_Buffer0[0];
    rtDW.mekf_bias_radps[1] = rtDW.RateTransition4_7_Buffer0[1];
    rtDW.r_eci_m[1] = rtDW.RateTransition4_9_Buffer0[1];
    rtDW.mekf_bias_radps[2] = rtDW.RateTransition4_7_Buffer0[2];
    rtDW.r_eci_m[2] = rtDW.RateTransition4_9_Buffer0[2];
    rtDW.ace_err = rtDW.RateTransition4_10_Buffer0;
    rtDW.eclipse = rtDW.RateTransition4_11_Buffer0;
    rtDW.sgp4_flag = rtDW.RateTransition4_12_Buffer0;
    rtDW.sc_above_gs = rtDW.RateTransition4_13_Buffer0;
    rtDW.sc_above_targ = rtDW.RateTransition4_14_Buffer0;
    rtDW.target_gen_flag = rtDW.RateTransition4_15_Buffer0;
    rtDW.elev_gs_rad = rtDW.RateTransition4_16_Buffer0;
    rtDW.elev_targ_rad = rtDW.RateTransition4_17_Buffer0;
    rtDW.ss_valid = rtDW.RateTransition4_18_Buffer0;
    rtDW.soar_telemetry_n = rtDW.RateTransition4_19_Buffer0;
  }

  /* End of RateTransition: '<S2>/Rate Transition4' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_fsw_telem_at_inport_0' incorporates:
   *  Outport: '<Root>/fsw_telem'
   */
  rtY.fsw_telem.gnc_mode = rtDW.gnc_mode;
  rtY.fsw_telem.sc_quat[0] = rtDW.sc_quat[0];
  rtY.fsw_telem.sc_quat[1] = rtDW.sc_quat[1];
  rtY.fsw_telem.sc_quat[2] = rtDW.sc_quat[2];
  rtY.fsw_telem.sc_quat[3] = rtDW.sc_quat[3];
  rtY.fsw_telem.sc_body_rates_radps[0] = rtDW.sc_body_rates_radps[0];
  rtY.fsw_telem.sc_body_rates_radps[1] = rtDW.sc_body_rates_radps[1];
  rtY.fsw_telem.sc_body_rates_radps[2] = rtDW.sc_body_rates_radps[2];
  rtY.fsw_telem.cmd_quat[0] = rtDW.cmd_quat[0];
  rtY.fsw_telem.cmd_quat[1] = rtDW.cmd_quat[1];
  rtY.fsw_telem.cmd_quat[2] = rtDW.cmd_quat[2];
  rtY.fsw_telem.cmd_quat[3] = rtDW.cmd_quat[3];
  rtY.fsw_telem.cmd_body_rates_radps[0] = rtDW.cmd_body_rates_radps[0];
  rtY.fsw_telem.cmd_body_rates_radps[1] = rtDW.cmd_body_rates_radps[1];
  rtY.fsw_telem.cmd_body_rates_radps[2] = rtDW.cmd_body_rates_radps[2];
  for (i = 0; i < 6; i++) {
    rtY.fsw_telem.mekf_3sigma_rad[i] = rtDW.mekf_3sigma_rad[i];
  }

  rtY.fsw_telem.mekf_telem = rtDW.mekf_telem;
  rtY.fsw_telem.mekf_bias_radps[0] = rtDW.mekf_bias_radps[0];
  rtY.fsw_telem.r_eci_m[0] = rtDW.r_eci_m[0];
  rtY.fsw_telem.mekf_bias_radps[1] = rtDW.mekf_bias_radps[1];
  rtY.fsw_telem.r_eci_m[1] = rtDW.r_eci_m[1];
  rtY.fsw_telem.mekf_bias_radps[2] = rtDW.mekf_bias_radps[2];
  rtY.fsw_telem.r_eci_m[2] = rtDW.r_eci_m[2];
  rtY.fsw_telem.ace_err = rtDW.ace_err;
  rtY.fsw_telem.eclipse = rtDW.eclipse;
  rtY.fsw_telem.sgp4_flag = rtDW.sgp4_flag;
  rtY.fsw_telem.sc_above_gs = rtDW.sc_above_gs;
  rtY.fsw_telem.sc_above_targ = rtDW.sc_above_targ;
  rtY.fsw_telem.target_gen_flag = rtDW.target_gen_flag;
  rtY.fsw_telem.elev_gs_rad = rtDW.elev_gs_rad;
  rtY.fsw_telem.elev_targ_rad = rtDW.elev_targ_rad;
  rtY.fsw_telem.ss_valid = rtDW.ss_valid;
  rtY.fsw_telem.soar_telemetry = rtDW.soar_telemetry_n;

  /* End of BusCreator: '<Root>/BusConversion_InsertedFor_fsw_telem_at_inport_0' */
}

/* Model step function for TID1 */
void FSW_Lib0_step1(void)              /* Sample time: [0.25s, 0.0s] */
{
  int32_T iidx[6];
  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  uint8_T rtb_Output;
  real_T rtb_Tan1;
  real_T rtb_Tan;
  real_T rtb_MathFunction;
  real_T rtb_Switch1[3];
  real_T rtb_ss_2_body[3];
  real_T rtb_RPM2Radps[4];
  real_T rtb_Sum[3];
  real_T rtb_Switch2[3];
  uint8_T rtb_FixPtSum1;
  real_T rtb_Switch_os[3];
  uint8_T rtb_Merge_l;
  real_T rtb_Sqrt_l;
  real_T rtb_sun_body_unit[3];
  real_T rtb_multiply[6];
  uint8_T rtb_Merge_j;
  real_T rtb_Multiply[4];
  int32_T i;
  real_T rtb_sun_body_unit_0[3];
  real_T tmp[4];
  real_T tmp_0[9];
  real_T rtb_Switch_b_idx_3;

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  maggyroProcessing_lib(rtDW.RateTransition3, rtDW.RateTransition6_k, rtb_Sum,
                        &rtDW.Merge1_j, &rtDW.maggyroProcessing_lib_k,
                        0.21629296228661718, rtCP_pooled2, 130.0, 1.0E-6);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* UnitDelay: '<S18>/Output' incorporates:
   *  Constant: '<S19>/FixPt Constant'
   *  Sum: '<S19>/FixPt Sum1'
   */
  rtb_Output = (uint8_T)(rtDW.Output_DSTATE + 1U);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  UnitDelay: '<S10>/Unit Delay'
   *  UnitDelay: '<S18>/Output'
   */
  if (rtDW.Output_DSTATE > 5) {
    rtb_Switch_os[0] = rtb_Sum[0];
    rtb_Switch_os[1] = rtb_Sum[1];
    rtb_Switch_os[2] = rtb_Sum[2];
  } else {
    rtb_Switch_os[0] = rtDW.UnitDelay_DSTATE[0];
    rtb_Switch_os[1] = rtDW.UnitDelay_DSTATE[1];
    rtb_Switch_os[2] = rtDW.UnitDelay_DSTATE[2];
  }

  /* End of Switch: '<S10>/Switch' */

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  maggyroProcessing_lib1(rtDW.RateTransition4, rtDW.RateTransition7, rtb_Sum,
    &rtDW.Merge1_h, &rtDW.maggyroProcessing_lib1_o, 0.02, rtCP_pooled2, 4.3633,
    1.0);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* Trigonometry: '<S106>/Tan1' incorporates:
   *  Gain: '<S106>/deg2rad'
   */
  rtb_Tan1 = tan(0.017453292519943295 * rtDW.RateTransition2[0]);

  /* Trigonometry: '<S106>/Tan' incorporates:
   *  Gain: '<S106>/deg2rad'
   */
  rtb_Tan = tan(0.017453292519943295 * rtDW.RateTransition2[1]);

  /* Math: '<S108>/Math Function' incorporates:
   *  Constant: '<S108>/Constant'
   *  Math: '<S108>/Square'
   *  Math: '<S108>/Square1'
   *  Sqrt: '<S108>/Sqrt'
   *  Sum: '<S108>/Sum'
   *
   * About '<S108>/Math Function':
   *  Operator: reciprocal
   */
  rtb_MathFunction = 1.0 / sqrt((rtb_Tan1 * rtb_Tan1 + 1.0) + rtb_Tan * rtb_Tan);

  /* SignalConversion: '<S106>/TmpSignal ConversionAtss_2_bodyInport2' incorporates:
   *  Product: '<S106>/Matrix Multiply'
   *  Product: '<S106>/Matrix Multiply1'
   */
  rtb_Switch1[0] = rtb_Tan1 * rtb_MathFunction;
  rtb_Switch1[1] = rtb_MathFunction * rtb_Tan;
  rtb_Switch1[2] = rtb_MathFunction;

  /* Product: '<S106>/ss_2_body' incorporates:
   *  Constant: '<S106>/Constant1'
   *  SignalConversion: '<S106>/TmpSignal ConversionAtss_2_bodyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_ss_2_body[i] = rtCP_Constant1_Value_na[i + 6] * rtb_MathFunction +
      (rtCP_Constant1_Value_na[i + 3] * rtb_Switch1[1] +
       rtCP_Constant1_Value_na[i] * rtb_Switch1[0]);
  }

  /* End of Product: '<S106>/ss_2_body' */

  /* If: '<S107>/If' */
  if (rtDW.RateTransition5) {
    /* Outputs for IfAction SubSystem: '<S107>/sunSensorIsValid' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    /* Abs: '<S110>/Abs' */
    rtb_Tan1 = fabs(rtDW.RateTransition2[0]);

    /* Relay: '<S110>/Relay' */
    if (rtb_Tan1 >= 60.0) {
      rtDW.Relay_Mode[0] = true;
    } else {
      if (rtb_Tan1 <= 10.0) {
        rtDW.Relay_Mode[0] = false;
      }
    }

    /* Abs: '<S110>/Abs' */
    rtb_Tan1 = fabs(rtDW.RateTransition2[1]);

    /* Relay: '<S110>/Relay' */
    if (rtb_Tan1 >= 60.0) {
      rtDW.Relay_Mode[1] = true;
    } else {
      if (rtb_Tan1 <= 10.0) {
        rtDW.Relay_Mode[1] = false;
      }
    }

    /* Sum: '<S110>/Sum' incorporates:
     *  Constant: '<S111>/Lower Limit'
     *  Constant: '<S111>/Upper Limit'
     *  Constant: '<S112>/Lower Limit'
     *  Constant: '<S112>/Upper Limit'
     *  Logic: '<S110>/AND'
     *  Logic: '<S110>/AND1'
     *  Logic: '<S111>/AND'
     *  Logic: '<S112>/AND'
     *  RelationalOperator: '<S111>/Lower Test'
     *  RelationalOperator: '<S111>/Upper Test'
     *  RelationalOperator: '<S112>/Lower Test'
     *  RelationalOperator: '<S112>/Upper Test'
     *  Relay: '<S110>/Relay'
     */
    rtb_Merge_l = (uint8_T)((uint32_T)((-60.0 <= rtDW.RateTransition2[0]) &&
      (rtDW.RateTransition2[0] <= 60.0) && ((-60.0 <= rtDW.RateTransition2[1]) &&
      (rtDW.RateTransition2[1] <= 60.0))) + ((!rtDW.Relay_Mode[0]) &&
      (!rtDW.Relay_Mode[1])));

    /* End of Outputs for SubSystem: '<S107>/sunSensorIsValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S107>/sunSensorIsNotValid' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    /* SignalConversion: '<S109>/OutportBuffer_InsertedFor_ss_valid_false_at_inport_0' incorporates:
     *  Constant: '<S109>/Constant'
     */
    rtb_Merge_l = 0U;

    /* End of Outputs for SubSystem: '<S107>/sunSensorIsNotValid' */
  }

  /* End of If: '<S107>/If' */

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  /* Constant: '<S1>/Constant23' incorporates:
   *  Constant: '<S1>/Constant'
   */
  MEKF_lib(rtCP_Constant23_Value, rtCP_Constant_Value_ob, rtb_ss_2_body,
           rtb_Switch_os, rtb_Sum, rtb_Merge_l, rtDW.Merge1_j, rtDW.Merge1_h,
           rtDW.triad_override, rtDW.q_p_merge, rtb_Sum, rtb_multiply,
           rtb_Switch2, &rtb_Merge_j, &rtConstB.MEKF_lib_d, &rtDW.MEKF_lib_d);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* RateTransition: '<S4>/Rate Transition1' */
  rtDW.RateTransition1[0] = rtDW.rwa_rpm[0];
  rtDW.RateTransition1[1] = rtDW.rwa_rpm[1];
  rtDW.RateTransition1[2] = rtDW.rwa_rpm[2];
  rtDW.RateTransition1[3] = rtDW.rwa_rpm[3];

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  /* Constant: '<S1>/Constant18' incorporates:
   *  Constant: '<S1>/Constant25'
   *  Constant: '<S1>/Constant28'
   */
  rtb_FixPtSum1 = mode_select_lib(rtDW.telecom, true, rtb_Merge_l, false,
    rtb_Sum, 0.0, rtDW.MET_soar_utc_s, rtDW.RateTransition1,
    &rtConstB.mode_select_lib_n, &rtDW.mode_select_lib_n);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  /* Constant: '<S1>/Constant23' incorporates:
   *  Constant: '<S1>/Constant24'
   *  Constant: '<S1>/Constant25'
   *  Constant: '<S1>/Constant29'
   */
  target_generation_lib(rtb_FixPtSum1, rtCP_Constant23_Value,
                        rtCP_Constant29_Value, rtCP_Constant24_Value,
                        rtDW.q_p_merge, rtb_Sum, rtDW.RateTransition1,
                        rtDW.quat_soar_cmd, rtDW.MET_soar_utc_s, 0.0,
                        rtDW.RateTransition6, rtb_Switch1, rtb_Switch2);

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */
  for (i = 0; i < 5; i++) {
    /* SignalConversion: '<S105>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S13>/MATLAB Function'
     */
    rtb_multiply[i] = rtDW.RateTransition1_i[i];
  }

  /* SignalConversion: '<S105>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S13>/Constant'
   *  MATLAB Function: '<S13>/MATLAB Function'
   */
  rtb_multiply[5] = 0.0;

  /* MATLAB Function: '<S13>/MATLAB Function' */
  rtb_sun_body_unit[0] = 0.0;
  rtb_sun_body_unit[1] = 0.0;
  rtb_sun_body_unit[2] = 0.0;
  for (i = 0; i < 6; i++) {
    if (rtb_multiply[i] > 99.760095101689075) {
      rtb_sun_body_unit[0] += (real_T)normals[3 * i];
      rtb_sun_body_unit[1] += (real_T)normals[3 * i + 1];
      rtb_sun_body_unit[2] += (real_T)normals[3 * i + 2];
    }
  }

  rtb_sun_body_unit_0[0] = rtb_sun_body_unit[0];
  rtb_sun_body_unit_0[1] = rtb_sun_body_unit[1] - -1.0;
  rtb_sun_body_unit_0[2] = rtb_sun_body_unit[2];
  if (norm_2e9Xj4lM(rtb_sun_body_unit_0) < 1.0E-8) {
    sort_E8F8dFL3(rtb_multiply, iidx);
    rtb_sun_body_unit[0] += (real_T)normals[(iidx[4] - 1) * 3];
    rtb_sun_body_unit[1] += (real_T)normals[(iidx[4] - 1) * 3 + 1];
    rtb_sun_body_unit[2] += (real_T)normals[(iidx[4] - 1) * 3 + 2];
  }

  rtb_Tan1 = norm_2e9Xj4lM(rtb_sun_body_unit);
  if (rtb_Tan1 < 1.0) {
    rtb_sun_body_unit[0] = 0.0;
    rtb_sun_body_unit[1] = 0.0;
    rtb_sun_body_unit[2] = -1.0;
  } else {
    rtb_sun_body_unit[0] /= rtb_Tan1;
    rtb_sun_body_unit[1] /= rtb_Tan1;
    rtb_sun_body_unit[2] /= rtb_Tan1;
  }

  /* Gain: '<S5>/RPM2Radps' */
  rtb_RPM2Radps[0] = 0.10471975511965977 * rtDW.RateTransition1[0];
  rtb_RPM2Radps[1] = 0.10471975511965977 * rtDW.RateTransition1[1];
  rtb_RPM2Radps[2] = 0.10471975511965977 * rtDW.RateTransition1[2];
  rtb_RPM2Radps[3] = 0.10471975511965977 * rtDW.RateTransition1[3];

  /* Sum: '<S5>/Sum1' */
  rtb_Switch1[0] -= rtb_Sum[0];
  rtb_Switch1[1] -= rtb_Sum[1];
  rtb_Switch1[2] -= rtb_Sum[2];

  /* Outputs for Atomic SubSystem: '<S5>/quat_err_lib' */
  quat_err_lib(rtDW.RateTransition6, rtDW.q_p_merge, rtb_Multiply);

  /* End of Outputs for SubSystem: '<S5>/quat_err_lib' */

  /* SwitchCase: '<S227>/Switch Case' incorporates:
   *  Gain: '<S242>/Gain'
   *  Gain: '<S250>/Gain'
   *  Product: '<S242>/Matrix Multiply8'
   *  Product: '<S250>/Matrix Multiply8'
   */
  switch (rtb_FixPtSum1) {
   case 0:
   case 1:
   case 2:
   case 4:
    /* Outputs for IfAction SubSystem: '<S227>/case_null_control' incorporates:
     *  ActionPort: '<S235>/Action Port'
     */
    /* SignalConversion: '<S235>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = 0.0;

    /* SignalConversion: '<S235>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[0] = 0.0;

    /* SignalConversion: '<S235>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = 0.0;

    /* SignalConversion: '<S235>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[1] = 0.0;

    /* SignalConversion: '<S235>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = 0.0;

    /* SignalConversion: '<S235>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[2] = 0.0;

    /* End of Outputs for SubSystem: '<S227>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S227>/case_asm' incorporates:
     *  ActionPort: '<S233>/Action Port'
     */
    /* Sum: '<S240>/Sum of Elements' incorporates:
     *  Math: '<S240>/Math Function'
     */
    rtb_Sqrt_l = rtb_Switch_os[0] * rtb_Switch_os[0];
    rtb_Sqrt_l += rtb_Switch_os[1] * rtb_Switch_os[1];
    rtb_Sqrt_l += rtb_Switch_os[2] * rtb_Switch_os[2];

    /* Math: '<S240>/Math Function1'
     *
     * About '<S240>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_l < 0.0) {
      rtb_Sqrt_l = -sqrt(fabs(rtb_Sqrt_l));
    } else {
      rtb_Sqrt_l = sqrt(rtb_Sqrt_l);
    }

    /* End of Math: '<S240>/Math Function1' */

    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S240>/Constant'
     *  Product: '<S240>/Product'
     */
    if (rtb_Sqrt_l > 0.0) {
      rtb_Multiply[0] = rtb_Switch_os[0];
      rtb_Multiply[1] = rtb_Switch_os[1];
      rtb_Multiply[2] = rtb_Switch_os[2];
      rtb_Multiply[3] = rtb_Sqrt_l;
    } else {
      rtb_Multiply[0] = rtb_Switch_os[0] * 0.0;
      rtb_Multiply[1] = rtb_Switch_os[1] * 0.0;
      rtb_Multiply[2] = rtb_Switch_os[2] * 0.0;
      rtb_Multiply[3] = 1.0;
    }

    /* End of Switch: '<S240>/Switch' */

    /* Product: '<S240>/Divide' */
    rtb_sun_body_unit[0] = rtb_Multiply[0] / rtb_Multiply[3];
    rtb_sun_body_unit[1] = rtb_Multiply[1] / rtb_Multiply[3];
    rtb_sun_body_unit[2] = rtb_Multiply[2] / rtb_Multiply[3];

    /* Product: '<S241>/Matrix Multiply1' incorporates:
     *  Constant: '<S241>/A_wheel2body '
     */
    for (i = 0; i < 4; i++) {
      rtb_Tan1 = rtConstB.CreateDiagonalMatrix_p[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix_p[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix_p[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix_p[i] * rtb_RPM2Radps[0]));
      tmp[i] = rtb_Tan1;
    }

    for (i = 0; i < 3; i++) {
      rtb_Tan1 = rtCP_A_wheel2body_Value[i + 9] * tmp[3] +
        (rtCP_A_wheel2body_Value[i + 6] * tmp[2] + (rtCP_A_wheel2body_Value[i +
          3] * tmp[1] + rtCP_A_wheel2body_Value[i] * tmp[0]));

      /* Sum: '<S241>/Subtract1' incorporates:
       *  Constant: '<S241>/A_wheel2body '
       *  Constant: '<S241>/scParams.J '
       *  Product: '<S241>/Matrix Multiply'
       */
      rtb_ss_2_body[i] = (rtConstB.h_w_nom_body_Nms_g[i] - rtb_Tan1) -
        ((rtCP_scParamsJ_Value[i + 3] * rtb_Sum[1] + rtCP_scParamsJ_Value[i] *
          rtb_Sum[0]) + rtCP_scParamsJ_Value[i + 6] * rtb_Sum[2]);
    }

    /* End of Product: '<S241>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S239>/twonorm' */
    rtb_Sqrt_l = twonorm(rtb_Switch_os);

    /* End of Outputs for SubSystem: '<S239>/twonorm' */

    /* Sum: '<S245>/Add3' incorporates:
     *  Product: '<S245>/Element product'
     */
    rtb_Tan1 = rtb_ss_2_body[1] * rtb_sun_body_unit[2] - rtb_ss_2_body[2] *
      rtb_sun_body_unit[1];
    rtb_Tan = rtb_ss_2_body[2] * rtb_sun_body_unit[0] - rtb_ss_2_body[0] *
      rtb_sun_body_unit[2];
    rtb_MathFunction = rtb_ss_2_body[0] * rtb_sun_body_unit[1] - rtb_ss_2_body[1]
      * rtb_sun_body_unit[0];
    for (i = 0; i < 3; i++) {
      /* Sum: '<S242>/Subtract2' incorporates:
       *  Product: '<S242>/Matrix Multiply7'
       */
      tmp_0[i] = rtConstB.IdentityMatrix_o[i] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[0];
      tmp_0[i + 3] = rtConstB.IdentityMatrix_o[i + 3] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[1];
      tmp_0[i + 6] = rtConstB.IdentityMatrix_o[i + 6] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[2];

      /* Product: '<S243>/Divide' incorporates:
       *  Gain: '<S243>/Gain'
       *  Gain: '<S243>/Gain3'
       */
      rtDW.Merge1[i] = -(rtCP_Gain3_Gain_f[i + 6] * rtb_MathFunction +
                         (rtCP_Gain3_Gain_f[i + 3] * rtb_Tan +
                          rtCP_Gain3_Gain_f[i] * rtb_Tan1)) / rtb_Sqrt_l;
      rtb_sun_body_unit_0[i] = tmp_0[i + 6] * rtb_ss_2_body[2] + (tmp_0[i + 3] *
        rtb_ss_2_body[1] + tmp_0[i] * rtb_ss_2_body[0]);
    }

    for (i = 0; i < 3; i++) {
      rtb_Tan1 = rtCP_Gain_Gain_i[i + 6] * rtb_sun_body_unit_0[2] +
        (rtCP_Gain_Gain_i[i + 3] * rtb_sun_body_unit_0[1] + rtCP_Gain_Gain_i[i] *
         rtb_sun_body_unit_0[0]);

      /* Gain: '<S239>/DutyCycleAdjustment' incorporates:
       *  Gain: '<S242>/Gain'
       */
      rtb_Sum[i] = 2.2 * rtb_Tan1;
      rtb_ss_2_body[i] = rtb_Tan1;
    }

    /* Outputs for Atomic SubSystem: '<S233>/asmController_lib' */
    asmController_lib(rtb_Switch1, rtb_ss_2_body);

    /* End of Outputs for SubSystem: '<S233>/asmController_lib' */

    /* Sum: '<S233>/Sum' incorporates:
     *  Gain: '<S242>/Gain'
     *  Product: '<S242>/Matrix Multiply8'
     */
    rtDW.Merge[0] = rtb_ss_2_body[0] + rtb_Sum[0];
    rtDW.Merge[1] = rtb_ss_2_body[1] + rtb_Sum[1];
    rtDW.Merge[2] = rtb_ss_2_body[2] + rtb_Sum[2];

    /* End of Outputs for SubSystem: '<S227>/case_asm' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S227>/case_sunseek' incorporates:
     *  ActionPort: '<S237>/Action Port'
     */
    /* SignalConversion: '<S237>/OutportBuffer_InsertedFor_sunseek_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S237>/sunSeek_lib' */
    sunSeek_lib(rtb_Merge_l, rtb_sun_body_unit, rtb_ss_2_body, rtb_Switch1,
                rtDW.Merge);

    /* End of Outputs for SubSystem: '<S237>/sunSeek_lib' */
    /* End of Outputs for SubSystem: '<S227>/case_sunseek' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S227>/case_desaturation' incorporates:
     *  ActionPort: '<S234>/Action Port'
     */
    /* Sum: '<S248>/Sum of Elements' incorporates:
     *  Math: '<S248>/Math Function'
     */
    rtb_Sqrt_l = rtb_Switch_os[0] * rtb_Switch_os[0];
    rtb_Sqrt_l += rtb_Switch_os[1] * rtb_Switch_os[1];
    rtb_Sqrt_l += rtb_Switch_os[2] * rtb_Switch_os[2];

    /* Math: '<S248>/Math Function1'
     *
     * About '<S248>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_l < 0.0) {
      rtb_Sqrt_l = -sqrt(fabs(rtb_Sqrt_l));
    } else {
      rtb_Sqrt_l = sqrt(rtb_Sqrt_l);
    }

    /* End of Math: '<S248>/Math Function1' */

    /* Switch: '<S248>/Switch' incorporates:
     *  Constant: '<S248>/Constant'
     *  Product: '<S248>/Product'
     */
    if (rtb_Sqrt_l > 0.0) {
      rtb_Tan1 = rtb_Switch_os[0];
      rtb_Tan = rtb_Switch_os[1];
      rtb_MathFunction = rtb_Switch_os[2];
      rtb_Switch_b_idx_3 = rtb_Sqrt_l;
    } else {
      rtb_Tan1 = rtb_Switch_os[0] * 0.0;
      rtb_Tan = rtb_Switch_os[1] * 0.0;
      rtb_MathFunction = rtb_Switch_os[2] * 0.0;
      rtb_Switch_b_idx_3 = 1.0;
    }

    /* End of Switch: '<S248>/Switch' */

    /* Product: '<S248>/Divide' */
    rtb_sun_body_unit[0] = rtb_Tan1 / rtb_Switch_b_idx_3;
    rtb_sun_body_unit[1] = rtb_Tan / rtb_Switch_b_idx_3;
    rtb_sun_body_unit[2] = rtb_MathFunction / rtb_Switch_b_idx_3;

    /* Product: '<S249>/Matrix Multiply1' incorporates:
     *  Constant: '<S249>/A_wheel2body '
     */
    for (i = 0; i < 4; i++) {
      rtb_Tan1 = rtConstB.CreateDiagonalMatrix[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix[i] * rtb_RPM2Radps[0]));
      tmp[i] = rtb_Tan1;
    }

    for (i = 0; i < 3; i++) {
      rtb_Tan1 = rtCP_A_wheel2body_Value_d[i + 9] * tmp[3] +
        (rtCP_A_wheel2body_Value_d[i + 6] * tmp[2] +
         (rtCP_A_wheel2body_Value_d[i + 3] * tmp[1] +
          rtCP_A_wheel2body_Value_d[i] * tmp[0]));

      /* Sum: '<S249>/Subtract1' incorporates:
       *  Constant: '<S249>/A_wheel2body '
       *  Constant: '<S249>/scParams.J '
       *  Product: '<S249>/Matrix Multiply'
       */
      rtb_ss_2_body[i] = (rtConstB.h_w_nom_body_Nms[i] - rtb_Tan1) -
        ((rtCP_scParamsJ_Value_i[i + 3] * rtb_Sum[1] + rtCP_scParamsJ_Value_i[i]
          * rtb_Sum[0]) + rtCP_scParamsJ_Value_i[i + 6] * rtb_Sum[2]);
    }

    /* End of Product: '<S249>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S247>/twonorm' */
    rtb_Sqrt_l = twonorm(rtb_Switch_os);

    /* End of Outputs for SubSystem: '<S247>/twonorm' */

    /* Sum: '<S253>/Add3' incorporates:
     *  Product: '<S253>/Element product'
     */
    rtb_Tan1 = rtb_ss_2_body[1] * rtb_sun_body_unit[2] - rtb_ss_2_body[2] *
      rtb_sun_body_unit[1];
    rtb_Tan = rtb_ss_2_body[2] * rtb_sun_body_unit[0] - rtb_ss_2_body[0] *
      rtb_sun_body_unit[2];
    rtb_MathFunction = rtb_ss_2_body[0] * rtb_sun_body_unit[1] - rtb_ss_2_body[1]
      * rtb_sun_body_unit[0];
    for (i = 0; i < 3; i++) {
      /* Sum: '<S250>/Subtract2' incorporates:
       *  Product: '<S250>/Matrix Multiply7'
       */
      tmp_0[i] = rtConstB.IdentityMatrix[i] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[0];
      tmp_0[i + 3] = rtConstB.IdentityMatrix[i + 3] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[1];
      tmp_0[i + 6] = rtConstB.IdentityMatrix[i + 6] - rtb_sun_body_unit[i] *
        rtb_sun_body_unit[2];

      /* Product: '<S251>/Divide' incorporates:
       *  Gain: '<S251>/Gain'
       *  Gain: '<S251>/Gain3'
       */
      rtDW.Merge1[i] = -(rtCP_Gain3_Gain_a[i + 6] * rtb_MathFunction +
                         (rtCP_Gain3_Gain_a[i + 3] * rtb_Tan +
                          rtCP_Gain3_Gain_a[i] * rtb_Tan1)) / rtb_Sqrt_l;
      rtb_sun_body_unit_0[i] = tmp_0[i + 6] * rtb_ss_2_body[2] + (tmp_0[i + 3] *
        rtb_ss_2_body[1] + tmp_0[i] * rtb_ss_2_body[0]);
    }

    for (i = 0; i < 3; i++) {
      rtb_Tan1 = rtCP_Gain_Gain_bf[i + 6] * rtb_sun_body_unit_0[2] +
        (rtCP_Gain_Gain_bf[i + 3] * rtb_sun_body_unit_0[1] + rtCP_Gain_Gain_bf[i]
         * rtb_sun_body_unit_0[0]);

      /* Gain: '<S247>/DutyCycleAdjustment' incorporates:
       *  Gain: '<S250>/Gain'
       */
      rtb_Sum[i] = 2.2 * rtb_Tan1;
      rtb_ss_2_body[i] = rtb_Tan1;
    }

    /* Outputs for Atomic SubSystem: '<S234>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_Multiply, rtb_Switch1, rtb_ss_2_body);

    /* End of Outputs for SubSystem: '<S234>/PD_Controller_Lib' */

    /* Sum: '<S234>/Sum' incorporates:
     *  Gain: '<S250>/Gain'
     *  Product: '<S250>/Matrix Multiply8'
     */
    rtDW.Merge[0] = rtb_ss_2_body[0] + rtb_Sum[0];
    rtDW.Merge[1] = rtb_ss_2_body[1] + rtb_Sum[1];
    rtDW.Merge[2] = rtb_ss_2_body[2] + rtb_Sum[2];

    /* End of Outputs for SubSystem: '<S227>/case_desaturation' */
    break;

   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S227>/case_reorientation' incorporates:
     *  ActionPort: '<S236>/Action Port'
     */
    /* SignalConversion: '<S236>/OutportBuffer_InsertedFor_tracking_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S236>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_Multiply, rtb_Switch1, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S236>/PD_Controller_Lib' */
    /* End of Outputs for SubSystem: '<S227>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S227>/Switch Case' */

  /* Sum: '<S5>/Sum' */
  rtb_Switch2[0] += rtDW.Merge[0];
  rtb_Switch2[1] += rtDW.Merge[1];
  rtb_Switch2[2] += rtDW.Merge[2];

  /* RateTransition: '<S4>/Rate Transition2' */
  rtDW.RateTransition2_d[0] = rtDW.rwa_valid[0];
  rtDW.RateTransition2_d[1] = rtDW.rwa_valid[1];
  rtDW.RateTransition2_d[2] = rtDW.rwa_valid[2];
  rtDW.RateTransition2_d[3] = rtDW.rwa_valid[3];

  /* Outputs for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
  rwa_allocation_lib(rtb_Switch2, rtb_RPM2Radps, rtDW.RateTransition2_d,
                     rtb_Multiply, &rtDW.rwa_allocation_lib_o);

  /* End of Outputs for SubSystem: '<S5>/rwa_allocation_lib' */

  /* Sum: '<S19>/FixPt Sum1' */
  rtb_FixPtSum1 = rtb_Output;

  /* Outport: '<Root>/fsw_out' */
  rtY.fsw_out_l.rwa_cmd_rpm[0] = 0.0;
  rtY.fsw_out_l.rwa_cmd_rpm[1] = 0.0;
  rtY.fsw_out_l.rwa_cmd_rpm[2] = 0.0;
  rtY.fsw_out_l.rwa_cmd_rpm[3] = 0.0;
  for (i = 0; i < 5; i++) {
    rtY.fsw_out_l.mtq_cmd_Am2[i] = 0.0;
  }

  /* End of Outport: '<Root>/fsw_out' */

  /* Outputs for IfAction SubSystem: '<S229>/If Action Subsystem' incorporates:
   *  ActionPort: '<S260>/Action Port'
   */
  /* If: '<S229>/If' */
  IfActionSubsystem(&rtb_Tan1);

  /* End of Outputs for SubSystem: '<S229>/If Action Subsystem' */

  /* Outputs for IfAction SubSystem: '<S229>/If Action Subsystem3' incorporates:
   *  ActionPort: '<S263>/Action Port'
   */
  /* If: '<S229>/If1' */
  IfActionSubsystem(&rtb_Tan1);

  /* End of Outputs for SubSystem: '<S229>/If Action Subsystem3' */

  /* Switch: '<S20>/FixPt Switch' */
  if (rtb_FixPtSum1 > 10) {
    /* Update for UnitDelay: '<S18>/Output' incorporates:
     *  Constant: '<S20>/Constant'
     */
    rtDW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S18>/Output' */
    rtDW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S20>/FixPt Switch' */

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = rtb_Switch_os[0];
  rtDW.UnitDelay_DSTATE[1] = rtb_Switch_os[1];
  rtDW.UnitDelay_DSTATE[2] = rtb_Switch_os[2];

  /* Update for RateTransition: '<S1>/Rate Transition4' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant15'
   *  Constant: '<S1>/Constant19'
   *  Constant: '<S1>/Constant20'
   *  Constant: '<S1>/Constant21'
   *  Constant: '<S1>/Constant22'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   */
  rtDW.RateTransition4_1_Buffer0 = 0U;
  rtDW.RateTransition4_2_Buffer0[0] = 0.0;
  rtDW.RateTransition4_2_Buffer0[1] = 0.0;
  rtDW.RateTransition4_2_Buffer0[2] = 0.0;
  rtDW.RateTransition4_2_Buffer0[3] = 0.0;
  rtDW.RateTransition4_3_Buffer0[0] = 0.0;
  rtDW.RateTransition4_3_Buffer0[1] = 0.0;
  rtDW.RateTransition4_3_Buffer0[2] = 0.0;
  rtDW.RateTransition4_4_Buffer0[0] = 0.0;
  rtDW.RateTransition4_4_Buffer0[1] = 0.0;
  rtDW.RateTransition4_4_Buffer0[2] = 0.0;
  rtDW.RateTransition4_4_Buffer0[3] = 0.0;
  rtDW.RateTransition4_5_Buffer0[0] = 0.0;
  rtDW.RateTransition4_5_Buffer0[1] = 0.0;
  rtDW.RateTransition4_5_Buffer0[2] = 0.0;
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition4_6_Buffer0[i] = 0.0;
  }

  rtDW.RateTransition4_7_Buffer0[0] = 0.0;
  rtDW.RateTransition4_7_Buffer0[1] = 0.0;
  rtDW.RateTransition4_7_Buffer0[2] = 0.0;
  rtDW.RateTransition4_8_Buffer0 = 0U;
  rtDW.RateTransition4_9_Buffer0[0] = 0.0;
  rtDW.RateTransition4_9_Buffer0[1] = 0.0;
  rtDW.RateTransition4_9_Buffer0[2] = 0.0;
  rtDW.RateTransition4_10_Buffer0 = 0.0;
  rtDW.RateTransition4_11_Buffer0 = false;
  rtDW.RateTransition4_12_Buffer0 = 0U;
  rtDW.RateTransition4_13_Buffer0 = false;
  rtDW.RateTransition4_14_Buffer0 = false;
  rtDW.RateTransition4_15_Buffer0 = 0U;
  rtDW.RateTransition4_16_Buffer0 = 0.0;
  rtDW.RateTransition4_17_Buffer0 = 0.0;
  rtDW.RateTransition4_18_Buffer0 = 0U;
  rtDW.RateTransition4_19_Buffer0 = FSW_Lib0_rtZsoar_telemetry;

  /* End of Update for RateTransition: '<S1>/Rate Transition4' */
}

/* Model initialize function */
void FSW_Lib0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Start(&rtDW.MEKF_lib_d);

  /* End of Start for SubSystem: '<S1>/MEKF_lib' */
  rtPrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = 0.0;
  rtDW.UnitDelay_DSTATE[1] = 0.0;
  rtDW.UnitDelay_DSTATE[2] = 1.0;

  /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  maggyroProcessing_lib_Init(&rtDW.maggyroProcessing_lib_k);

  /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  maggyroProcessing_lib1_Init(&rtDW.maggyroProcessing_lib1_o);

  /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Init(rtDW.q_p_merge, &rtDW.MEKF_lib_d);

  /* End of SystemInitialize for SubSystem: '<S1>/MEKF_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/target_generation_lib' */
  target_generation_lib_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/target_generation_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
