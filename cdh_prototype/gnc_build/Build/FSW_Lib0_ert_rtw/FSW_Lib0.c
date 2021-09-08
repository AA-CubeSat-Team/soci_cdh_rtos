/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0.c
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

#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "factorial_DisWLItj.h"
#include "jseconds2ymdhms_ModKEhLD.h"
#include "mod_49nNZZ0V.h"
#include "norm_2e9Xj4lM.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"
#include "sort_E8F8dFL3.h"

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

/* Model step function for TID0 */
void FSW_Lib0_step0(void)              /* Sample time: [0.0125s, 0.0s] */
{
  int32_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0125s, 0.0s] to Sample time: [0.25s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 19) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition' incorporates:
   *  Inport: '<Root>/telecommands'
   *  RateTransition: '<S1>/Rate Transition4'
   */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.MET_utc_s = rtU.telecommands.MET_utc_s;

    /* RateTransition: '<S2>/Rate Transition5' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    rtDW.RateTransition5 = rtU.sensor_meas.sun_meas_valid;

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition2[0] = rtU.sensor_meas.sun_meas_ss_deg[0];
    rtDW.RateTransition2[1] = rtU.sensor_meas.sun_meas_ss_deg[1];

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_b[0] = rtU.sensor_meas.mag_meas_valid[0];
    rtDW.RateTransition6_b[1] = rtU.sensor_meas.mag_meas_valid[1];
    rtDW.RateTransition6_b[2] = rtU.sensor_meas.mag_meas_valid[2];
    memcpy(&rtDW.orbit_tle[0], &rtU.telecommands.orbit_tle[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition3' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    memcpy(&rtDW.RateTransition3[0], &rtU.sensor_meas.mag_mag_uT[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition4' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    memcpy(&rtDW.RateTransition4[0], &rtU.sensor_meas.gyro_gyro_radps[0], 9U *
           sizeof(real_T));

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition7[0] = rtU.sensor_meas.gyro_meas_valid[0];
    rtDW.RateTransition7[1] = rtU.sensor_meas.gyro_meas_valid[1];
    rtDW.RateTransition7[2] = rtU.sensor_meas.gyro_meas_valid[2];
    rtDW.triad_override = rtU.telecommands.triad_override;
    rtDW.MET_soar_utc_s = rtU.telecommands.MET_soar_utc_s;

    /* RateTransition: '<S4>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     *  Inport: '<Root>/telecommands'
     */
    rtDW.RateTransition1[0] = rtU.actuator_meas_l.rwa_rpm[0];
    rtDW.RateTransition1[1] = rtU.actuator_meas_l.rwa_rpm[1];
    rtDW.RateTransition1[2] = rtU.actuator_meas_l.rwa_rpm[2];
    rtDW.RateTransition1[3] = rtU.actuator_meas_l.rwa_rpm[3];
    rtDW.target_latlonalt[0] = rtU.telecommands.target_latlonalt[0];
    rtDW.target_latlonalt[1] = rtU.telecommands.target_latlonalt[1];
    rtDW.target_latlonalt[2] = rtU.telecommands.target_latlonalt[2];
    rtDW.quat_soar_cmd[0] = rtU.telecommands.quat_soar_cmd[0];
    rtDW.quat_soar_cmd[1] = rtU.telecommands.quat_soar_cmd[1];
    rtDW.quat_soar_cmd[2] = rtU.telecommands.quat_soar_cmd[2];
    rtDW.quat_soar_cmd[3] = rtU.telecommands.quat_soar_cmd[3];

    /* RateTransition: '<S2>/Rate Transition1' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    for (i = 0; i < 6; i++) {
      rtDW.telecom[i] = rtU.telecommands.telecom[i];
      rtDW.RateTransition1_h[i] = rtU.sensor_meas.photodiodes_uA[i];
    }

    /* End of RateTransition: '<S2>/Rate Transition1' */

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_l[0] = rtU.actuator_meas_l.rwa_valid[0];

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.rwa_cmd_rpm[0] = rtDW.RateTransition3_1_Buffer0[0];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_l[1] = rtU.actuator_meas_l.rwa_valid[1];

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.rwa_cmd_rpm[1] = rtDW.RateTransition3_1_Buffer0[1];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_l[2] = rtU.actuator_meas_l.rwa_valid[2];

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.rwa_cmd_rpm[2] = rtDW.RateTransition3_1_Buffer0[2];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_l[3] = rtU.actuator_meas_l.rwa_valid[3];

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.rwa_cmd_rpm[3] = rtDW.RateTransition3_1_Buffer0[3];
    rtDW.mtq_cmd_Am2[0] = rtDW.RateTransition3_2_Buffer0[0];
    rtDW.mtq_cmd_Am2[1] = rtDW.RateTransition3_2_Buffer0[1];
    rtDW.mtq_cmd_Am2[2] = rtDW.RateTransition3_2_Buffer0[2];
    rtDW.gnc_mode = rtDW.RateTransition4_1_Buffer0;
    rtDW.sc_quat[0] = rtDW.RateTransition4_2_Buffer0[0];
    rtDW.sc_quat[1] = rtDW.RateTransition4_2_Buffer0[1];
    rtDW.sc_quat[2] = rtDW.RateTransition4_2_Buffer0[2];
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
    rtDW.soar_telemetry_d = rtDW.RateTransition4_18_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_fsw_out_at_inport_0' incorporates:
   *  Outport: '<Root>/fsw_out'
   */
  rtY.fsw_out_n.rwa_cmd_rpm[0] = rtDW.rwa_cmd_rpm[0];
  rtY.fsw_out_n.rwa_cmd_rpm[1] = rtDW.rwa_cmd_rpm[1];
  rtY.fsw_out_n.rwa_cmd_rpm[2] = rtDW.rwa_cmd_rpm[2];
  rtY.fsw_out_n.rwa_cmd_rpm[3] = rtDW.rwa_cmd_rpm[3];
  rtY.fsw_out_n.mtq_cmd_Am2[0] = rtDW.mtq_cmd_Am2[0];
  rtY.fsw_out_n.mtq_cmd_Am2[1] = rtDW.mtq_cmd_Am2[1];
  rtY.fsw_out_n.mtq_cmd_Am2[2] = rtDW.mtq_cmd_Am2[2];

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
  rtY.fsw_telem.soar_telemetry = rtDW.soar_telemetry_d;

  /* End of BusCreator: '<Root>/BusConversion_InsertedFor_fsw_telem_at_inport_0' */
}

/* Model step function for TID1 */
void FSW_Lib0_step1(void)              /* Sample time: [0.25s, 0.0s] */
{
  real_T epsb_1980;
  real_T M_moon;
  real_T M_sun;
  real_T u_moon;
  real_T D_sun;
  real_T O_moon;
  real_T dpsi_1980;
  real_T deps_1980;
  real_T api;
  real_T eqe_1980;
  static const real_T nc[300] = { 1.0, 9.0, 31.0, 2.0, 10.0, 32.0, 11.0, 33.0,
    34.0, 12.0, 35.0, 13.0, 36.0, 38.0, 37.0, 40.0, 39.0, 41.0, 14.0, 3.0, 42.0,
    45.0, 43.0, 44.0, 46.0, 15.0, 47.0, 16.0, 18.0, 48.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, -1.0, 1.0, 2.0,
    -2.0, 0.0, 2.0, 2.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 0.0,
    0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, 0.0,
    0.0, 0.0, -2.0, 0.0, 0.0, -2.0, -2.0, -2.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0,
    -2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, -2.0, 0.0, 0.0, -2.0, 2.0, 1.0, 2.0,
    2.0, 2.0, 0.0, 0.0, 2.0, 1.0, 2.0, 2.0, 0.0, 1.0, 2.0, 1.0, 0.0, 2.0, 1.0,
    1.0, 0.0, 1.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 2.0, 1.0, -171996.0,
    -13187.0, -2274.0, 2062.0, 1426.0, 712.0, -517.0, -386.0, -301.0, 217.0,
    -158.0, 129.0, 123.0, 63.0, 63.0, -59.0, -58.0, -51.0, 48.0, 46.0, -38.0,
    -31.0, 29.0, 29.0, 26.0, -22.0, 21.0, 17.0, -16.0, 16.0, -174.2, -1.6, -0.2,
    0.2, -3.4, 0.1, 1.2, -0.4, 0.0, -0.5, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.1, 0.1, 0.0, 92025.0,
    5736.0, 977.0, -895.0, 54.0, -7.0, 224.0, 200.0, 129.0, -95.0, -1.0, -70.0,
    -53.0, -33.0, -2.0, 26.0, 32.0, 27.0, 1.0, -24.0, 16.0, 13.0, -1.0, -12.0,
    -1.0, 0.0, -10.0, 0.0, 7.0, -8.0, 8.9, -3.1, -0.5, 0.5, -0.1, 0.0, -0.6, 0.0,
    -0.1, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T M_o;
  real_T n_o;
  real_T tsince_JD;
  real_T d_1;
  real_T a_o_pp;
  boolean_T lowAlt;
  real_T xi;
  real_T b_o;
  real_T eta;
  real_T C_5;
  real_T D_2;
  real_T D_3;
  real_T D_4;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T d_w;
  real_T d_M;
  int32_T iter;
  real_T eps;
  real_T sp[13];
  real_T cp[13];
  real_T P_0[196];
  static const real_T g[156] = { -29438.2, -2444.5, 1351.8, 907.5, -232.9, 69.4,
    81.7, 24.2, 5.5, -2.0, 3.0, -2.0, -1493.5, 3014.7, -2351.6, 814.8, 360.1,
    67.7, -75.9, 8.9, 8.8, -6.1, -1.4, -0.1, 0.0, 1679.0, 1223.6, 117.8, 191.7,
    72.3, -7.1, -16.9, 3.0, 0.2, -2.3, 0.5, 0.0, 0.0, 582.3, -335.6, -141.3,
    -129.1, 52.2, -3.1, -3.2, 0.6, 2.1, 1.2, 0.0, 0.0, 0.0, 69.7, -157.2, -28.4,
    15.0, -20.7, 0.6, -0.5, -0.8, -0.9, 0.0, 0.0, 0.0, 0.0, 7.7, 13.6, 9.1, 13.3,
    -13.2, 1.8, 0.6, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, -70.3, -3.0, 11.6, -0.1, -0.7,
    -0.7, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.9, -16.3, 8.7, 2.2, 0.1, 0.6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.1, -9.1, 2.4, 1.7, -0.4, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -10.4, -1.8, -0.2, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -3.6, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.5, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T dg[156] = { 7.0, -11.0, 2.4, -0.8, -0.3, -0.8, -0.3, -0.1,
    -0.1, 0.0, 0.0, 0.0, 9.0, -6.2, -5.7, -0.9, 0.6, -0.5, -0.2, 0.2, -0.1, 0.0,
    0.0, 0.0, 0.0, 0.3, 2.0, -6.5, -0.8, -0.1, -0.3, -0.2, 0.0, -0.1, 0.0, 0.0,
    0.0, 0.0, -11.0, 5.2, 0.1, 1.6, 0.9, 0.5, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0,
    -4.0, 1.2, -1.6, 0.1, -0.1, -0.4, -0.1, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 1.4,
    0.0, -0.6, 0.4, 0.0, -0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, -0.9,
    0.4, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7, -0.1, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, -0.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.3, -0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.1 };

  static const real_T h[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 4796.3, -2842.4, -113.7, 283.3, 46.9, -20.1, -54.3, 10.1,
    -21.8, 3.3, 0.0, -1.0, 0.0, -638.8, 246.5, -188.6, 196.5, 32.8, -19.5, -18.3,
    10.7, -0.4, 2.1, 0.3, 0.0, 0.0, -537.4, 180.7, -119.9, 59.1, 6.0, 13.3, 11.8,
    4.6, -0.6, 1.8, 0.0, 0.0, 0.0, -330.0, 16.0, -67.1, 24.5, -14.5, -6.8, 4.4,
    -1.1, -2.2, 0.0, 0.0, 0.0, 0.0, 100.6, 8.1, 3.5, 16.2, -6.9, -7.9, 0.7, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 61.9, -27.7, 6.0, 7.9, -0.6, -0.2, 0.7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -2.9, -9.2, 1.0, -4.2, -2.1, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 2.4, -3.9, -2.9, -1.5, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 8.5, -1.1, -2.6, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -8.8,
    -2.0, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.3, -0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.8 };

  static const real_T dh[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -30.2, -29.6, 6.5, -0.4, 0.2, 0.3, 0.6, -0.4, -0.3, 0.0, 0.0,
    0.0, 0.0, -17.3, -0.8, 5.8, 2.3, -1.5, 0.5, 0.6, 0.1, 0.1, 0.1, 0.0, 0.0,
    0.0, -2.0, 3.8, 0.0, -1.2, -0.8, -0.1, -0.4, -0.2, 0.0, -0.1, 0.0, 0.0, 0.0,
    -3.5, 3.3, 0.4, -0.2, 0.6, 0.3, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, -0.6, 0.2,
    -1.1, -0.2, 0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.3, 0.1, -0.5,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.5, -0.1, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.5, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.1 };

  boolean_T light;
  real_T x[6];
  int32_T iidx[6];
  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  real_T rtb_Gain[3];
  real_T rtb_M2KM[3];
  real_T rtb_AU2KM[3];
  real_T rtb_MathFunction[3];
  real_T rtb_Switch_dq[4];
  real_T rtb_MatrixMultiply[3];
  int8_T s339_iter;
  real_T rtb_MathFunction1_i[9];
  real_T rtb_Switch2[3];
  real_T rtb_nT2T[3];
  real_T rtb_ss_2_body[3];
  real_T rtb_MathFunction1_m[9];
  real_T rtb_MathFunction_b[9];
  real_T rtb_radps_2_rpm[4];
  uint8_T rtb_gnc_mode;
  real_T rtb_input_wheel_sat[4];
  uint8_T rtb_Merge;
  uint8_T rtb_flag_c;
  boolean_T rtb_Compare_m;
  uint8_T rtb_flag;
  real_T rtb_YMDHMS_UTC[6];
  real_T rtb_pos_teme_km[3];
  real_T rtb_mod_to_gcrf[9];
  real_T rtb_UnitConversion_e[3];
  real_T rtb_Gain_h_tmp[9];
  real_T rtb_Gain_h[9];
  real_T rtb_Gain_h_0[9];
  real_T rtb_Gain_h_1[9];
  real_T rtb_MathFunction1_fo[9];
  int32_T i;
  int32_T lowAlt_0;
  real_T epsb_1980_tmp;
  int32_T rtb_mod_to_gcrf_tmp;
  real_T C_1_tmp;
  real_T C_1_tmp_0;
  real_T M_DF_tmp;
  real_T M_DF_tmp_0;
  real_T M_DF_tmp_tmp;
  real_T d_1_tmp;
  real_T C_1_tmp_tmp;
  real_T C_1_tmp_1;
  int32_T P_tmp;
  int32_T P_tmp_0;
  int32_T P_tmp_1;
  int32_T P_tmp_2;

  /* MATLAB Function: '<S265>/MATLAB Function3' */
  jseconds2ymdhms_ModKEhLD(rtDW.MET_utc_s, &rtb_YMDHMS_UTC[0], &rtb_YMDHMS_UTC[1],
    &rtb_YMDHMS_UTC[2], &rtb_YMDHMS_UTC[3], &rtb_YMDHMS_UTC[4], &rtb_YMDHMS_UTC
    [5], &eqe_1980, &tsince_JD);
  jseconds2ymdhms_ModKEhLD(rtDW.MET_utc_s + -0.0361535, &epsb_1980, &M_moon,
    &M_sun, &eqe_1980, &O_moon, &dpsi_1980, &eps, &u_moon);
  jseconds2ymdhms_ModKEhLD((rtDW.MET_utc_s + 37.0) + 32.184, &epsb_1980, &M_moon,
    &M_sun, &O_moon, &dpsi_1980, &u_moon, &eqe_1980, &D_sun);

  /* MATLAB Function: '<S353>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S265>/MATLAB Function3'
   */
  n_o = eqe_1980 * eqe_1980;
  epsb_1980_tmp = rt_powd_snf(eqe_1980, 3.0);
  epsb_1980 = (((23.439291 - 0.0130042 * eqe_1980) - n_o * 1.64E-7) + 5.04E-7 *
               epsb_1980_tmp) * 0.017453292519943295;
  M_moon = (((477198.8673981 * eqe_1980 + 134.96298139) + n_o * 0.0086972) +
            1.78E-5 * epsb_1980_tmp) * 0.017453292519943295;
  M_sun = (((35999.05034 * eqe_1980 + 357.52772333) - n_o * 0.0001603) - 3.3E-6 *
           epsb_1980_tmp) * 0.017453292519943295;
  u_moon = (((483202.0175381 * eqe_1980 + 93.27191028) - n_o * 0.0036825) +
            3.1E-6 * epsb_1980_tmp) * 0.017453292519943295;
  D_sun = (((445267.11148 * eqe_1980 + 297.85036306) - n_o * 0.0019142) + 5.3E-6
           * epsb_1980_tmp) * 0.017453292519943295;
  O_moon = (((125.04452222 - 1934.1362608 * eqe_1980) + n_o * 0.0020708) +
            2.2E-6 * epsb_1980_tmp) * 0.017453292519943295;
  dpsi_1980 = 0.0;
  deps_1980 = 0.0;
  for (iter = 0; iter < 30; iter++) {
    api = (((nc[30 + iter] * M_moon + nc[60 + iter] * M_sun) + nc[90 + iter] *
            u_moon) + nc[120 + iter] * D_sun) + nc[150 + iter] * O_moon;
    dpsi_1980 += (nc[210 + iter] * eqe_1980 + nc[180 + iter]) * 0.0001 * sin(api);
    deps_1980 += (nc[270 + iter] * eqe_1980 + nc[240 + iter]) * 0.0001 * cos(api);
  }

  M_moon = 4.84813681109536E-6 * deps_1980 + epsb_1980;
  M_sun = 4.84813681109536E-6 * dpsi_1980;
  D_sun = ((n_o * 0.30188 + 2306.2181 * eqe_1980) + 0.017998 * epsb_1980_tmp) *
    4.84813681109536E-6;
  u_moon = ((n_o * 1.09468 + 2306.2181 * eqe_1980) + 0.018203 * epsb_1980_tmp) *
    4.84813681109536E-6;
  eqe_1980 = -(((2004.3109 * eqe_1980 - n_o * 0.42665) - 0.041833 *
                epsb_1980_tmp) * 4.84813681109536E-6);
  deps_1980 = cos(D_sun);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(D_sun);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  deps_1980 = cos(eqe_1980);
  rtb_mod_to_gcrf[0] = deps_1980;
  rtb_mod_to_gcrf[3] = 0.0;
  D_sun = sin(eqe_1980);
  rtb_mod_to_gcrf[6] = -D_sun;
  rtb_Gain[0] = 1.0;
  rtb_MathFunction1_fo[2] = 0.0;
  rtb_mod_to_gcrf[1] = 0.0;
  rtb_MatrixMultiply[0] = 0.0;
  rtb_Gain[1] = 0.0;
  rtb_MathFunction1_fo[5] = 0.0;
  rtb_mod_to_gcrf[4] = 1.0;
  rtb_MatrixMultiply[1] = 0.0;
  rtb_Gain[2] = 0.0;
  rtb_MathFunction1_fo[8] = 1.0;
  rtb_mod_to_gcrf[7] = 0.0;
  rtb_MatrixMultiply[2] = 1.0;
  rtb_mod_to_gcrf[2] = D_sun;
  rtb_mod_to_gcrf[5] = 0.0;
  rtb_mod_to_gcrf[8] = deps_1980;
  deps_1980 = cos(u_moon);
  rtb_Gain_h_0[0] = deps_1980;
  D_sun = sin(u_moon);
  rtb_Gain_h_0[3] = D_sun;
  rtb_Gain_h_0[6] = 0.0;
  rtb_Gain_h_0[1] = -D_sun;
  rtb_Gain_h_0[4] = deps_1980;
  rtb_Gain_h_0[7] = 0.0;
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    for (i = 0; i < 3; i++) {
      rtb_mod_to_gcrf_tmp = lowAlt_0 + 3 * i;
      rtb_Gain_h[rtb_mod_to_gcrf_tmp] = 0.0;
      iter = 3 * i + lowAlt_0;
      rtb_Gain_h[rtb_mod_to_gcrf_tmp] = rtb_Gain_h[iter] + rtb_mod_to_gcrf[3 * i]
        * rtb_MathFunction1_fo[lowAlt_0];
      rtb_Gain_h[rtb_mod_to_gcrf_tmp] = rtb_mod_to_gcrf[3 * i + 1] *
        rtb_MathFunction1_fo[lowAlt_0 + 3] + rtb_Gain_h[iter];
      rtb_Gain_h[rtb_mod_to_gcrf_tmp] = rtb_mod_to_gcrf[3 * i + 2] *
        rtb_MathFunction1_fo[lowAlt_0 + 6] + rtb_Gain_h[iter];
    }

    rtb_Gain_h_0[2 + 3 * lowAlt_0] = rtb_MatrixMultiply[lowAlt_0];
  }

  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    for (i = 0; i < 3; i++) {
      iter = i + 3 * lowAlt_0;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * lowAlt_0 + i;
      rtb_mod_to_gcrf[iter] = rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] +
        rtb_Gain_h_0[3 * lowAlt_0] * rtb_Gain_h[i];
      rtb_mod_to_gcrf[iter] = rtb_Gain_h_0[3 * lowAlt_0 + 1] * rtb_Gain_h[i + 3]
        + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
      rtb_mod_to_gcrf[iter] = rtb_Gain_h_0[3 * lowAlt_0 + 2] * rtb_Gain_h[i + 6]
        + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
    }
  }

  eqe_1980 = ((dpsi_1980 * cos(epsb_1980) + 0.00264 * sin(O_moon)) + sin(2.0 *
    O_moon) * 6.3E-5) * 4.84813681109536E-6;
  dpsi_1980 = ((3.1644001848128662E+9 * eps + 67310.54841) + eps * eps *
               0.093104) - 6.2E-6 * rt_powd_snf(eps, 3.0);
  if (dpsi_1980 < 0.0) {
    O_moon = -1.0;
  } else if (dpsi_1980 > 0.0) {
    O_moon = 1.0;
  } else if (dpsi_1980 == 0.0) {
    O_moon = 0.0;
  } else {
    O_moon = (rtNaN);
  }

  O_moon *= 86400.0;
  D_sun = dpsi_1980;
  if ((!rtIsInf(dpsi_1980)) && (!rtIsNaN(dpsi_1980)) && (!rtIsNaN(O_moon))) {
    if (dpsi_1980 == 0.0) {
      D_sun = O_moon * 0.0;
    } else {
      if (O_moon != 0.0) {
        D_sun = fmod(dpsi_1980, O_moon);
        if (D_sun == 0.0) {
          D_sun = O_moon * 0.0;
        } else {
          if ((dpsi_1980 < 0.0) != (O_moon < 0.0)) {
            D_sun += O_moon;
          }
        }
      }
    }
  } else {
    if (O_moon != 0.0) {
      D_sun = (rtNaN);
    }
  }

  dpsi_1980 = D_sun / 240.0;
  if ((!rtIsInf(dpsi_1980)) && (!rtIsNaN(dpsi_1980))) {
    if (dpsi_1980 == 0.0) {
      O_moon = 0.0;
    } else {
      O_moon = fmod(dpsi_1980, 360.0);
      if (O_moon == 0.0) {
        O_moon = 0.0;
      } else {
        if (dpsi_1980 < 0.0) {
          O_moon += 360.0;
        }
      }
    }
  } else {
    O_moon = (rtNaN);
  }

  O_moon = -(0.017453292519943295 * O_moon + eqe_1980);

  /* MATLAB Function: '<S263>/MATLAB Function' incorporates:
   *  Constant: '<S263>/JD_J2000'
   *  MATLAB Function: '<S265>/MATLAB Function3'
   *  Sum: '<S263>/Sum'
   */
  D_sun = 1.88027916E-9;
  u_moon = 1.01222928;
  rtb_flag_c = 0U;
  dpsi_1980 = rtDW.orbit_tle[3] * 0.0174532925;
  deps_1980 = rtDW.orbit_tle[6] * 0.0174532925;
  M_o = rtDW.orbit_tle[7] * 0.0174532925;
  n_o = rtDW.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtDW.orbit_tle[5] >= 1.0) || (rtDW.orbit_tle[5] <= 0.0)) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag_c = 1U;
  } else if (n_o == 0.0) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag_c = 2U;
  } else {
    tsince_JD = (tsince_JD - 2.451545E+6) - rtDW.orbit_tle[1];
    if (fabs(tsince_JD) < 1.0E-8) {
      tsince_JD = 0.0;
    } else {
      if (tsince_JD < 0.0) {
        tsince_JD = 0.0;
      }
    }

    api = 1440.0 * tsince_JD;
    tsince_JD = rt_powd_snf(0.0743669161 / n_o, 0.66666666666666663);
    epsb_1980_tmp = cos(dpsi_1980);
    d_M = 1.0 - rtDW.orbit_tle[5] * rtDW.orbit_tle[5];
    d_1 = (epsb_1980_tmp * epsb_1980_tmp * 3.0 - 1.0) / rt_powd_snf(d_M, 1.5) *
      (0.000541308 / (tsince_JD * tsince_JD) * 1.5);
    tsince_JD *= ((1.0 - 0.33333333333333331 * d_1) - d_1 * d_1) -
      1.654320987654321 * rt_powd_snf(d_1, 3.0);
    d_1 = (epsb_1980_tmp * epsb_1980_tmp * 3.0 - 1.0) / rt_powd_snf(1.0 -
      rtDW.orbit_tle[5] * rtDW.orbit_tle[5], 1.5) * (0.000541308 / (tsince_JD *
      tsince_JD) * 1.5);
    n_o /= 1.0 + d_1;
    a_o_pp = tsince_JD / (1.0 - d_1);
    xi = (1.0 - rtDW.orbit_tle[5]) * a_o_pp;
    tsince_JD = (xi - 1.0) * 6378.137;
    if (xi < 1.0344928307435228) {
      lowAlt = true;
      rtb_flag_c = 3U;
    } else {
      lowAlt = false;
    }

    if ((tsince_JD >= 98.0) && (tsince_JD <= 156.0)) {
      u_moon = (xi - 1.01222928) + 1.0;
      D_sun = rt_powd_snf(1.0188142770258546 - ((xi - 1.01222928) + 1.0), 4.0);
    } else {
      if (tsince_JD < 98.0) {
        D_sun = 6.0426196528035638E-8;
        u_moon = 1.0031357118857749;
      }
    }

    xi = 1.0 / (a_o_pp - u_moon);
    b_o = sqrt(d_M);
    eta = a_o_pp * rtDW.orbit_tle[5] * xi;
    if (eta == 1.0) {
      rtb_pos_teme_km[0] = 6378.137;
      rtb_pos_teme_km[1] = 6378.137;
      rtb_pos_teme_km[2] = 6878.137;
      rtb_flag_c = 4U;
    } else {
      d_w = eta * eta;
      d_M = rt_powd_snf(xi, 4.0);
      C_1_tmp = rt_powd_snf(1.0 - eta * eta, -3.5);
      C_1_tmp_tmp = rt_powd_snf(eta, 3.0);
      C_1_tmp_0 = rtDW.orbit_tle[5] * C_1_tmp_tmp;
      C_1_tmp_1 = d_w * 1.5;
      tsince_JD = ((((C_1_tmp_1 + 1.0) + 4.0 * rtDW.orbit_tle[5] * eta) +
                    C_1_tmp_0) * a_o_pp + (epsb_1980_tmp * epsb_1980_tmp * 1.5 +
        -0.5) * (0.00081196200000000006 * xi) * ((d_w * 24.0 + 8.0) + 3.0 *
        rt_powd_snf(eta, 4.0)) / (1.0 - d_w)) * (D_sun * d_M * n_o * C_1_tmp) *
        rtDW.orbit_tle[2];
      C_5 = 0.0;
      D_2 = 0.0;
      D_3 = 0.0;
      D_4 = 0.0;
      IL3 = 0.0;
      IL4 = 0.0;
      IL5 = 0.0;
      if (!lowAlt) {
        C_5 = 2.0 * D_sun * d_M * a_o_pp * (b_o * b_o) * C_1_tmp * ((2.75 * eta *
          (eta + rtDW.orbit_tle[5]) + 1.0) + C_1_tmp_0);
        d_1 = tsince_JD * tsince_JD;
        D_2 = 4.0 * a_o_pp * xi * d_1;
        IL4 = rt_powd_snf(tsince_JD, 3.0);
        D_3 = 1.3333333333333333 * a_o_pp * (xi * xi) * (17.0 * a_o_pp + u_moon)
          * IL4;
        M_DF = rt_powd_snf(tsince_JD, 4.0);
        D_4 = 0.66666666666666663 * a_o_pp * rt_powd_snf(xi, 3.0) * (221.0 *
          a_o_pp + 31.0 * u_moon) * M_DF;
        IL3 = d_1 * 2.0 + D_2;
        IL4 = ((12.0 * tsince_JD * D_2 + 3.0 * D_3) + 10.0 * IL4) * 0.25;
        IL5 = ((((12.0 * tsince_JD * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + d_1 *
                30.0 * D_2) + 15.0 * M_DF) * 0.2;
      }

      d_1 = rt_powd_snf(epsb_1980_tmp, 4.0);
      M_DF_tmp_tmp = rt_powd_snf(a_o_pp, 4.0);
      M_DF_tmp = 16.0 * M_DF_tmp_tmp;
      u_moon = a_o_pp * a_o_pp;
      M_DF_tmp_0 = u_moon * 2.0 * rt_powd_snf(b_o, 3.0);
      M_DF = (((epsb_1980_tmp * epsb_1980_tmp * 3.0 - 1.0) *
               0.0016239240000000001 / M_DF_tmp_0 + 1.0) + ((13.0 -
                epsb_1980_tmp * epsb_1980_tmp * 78.0) + 137.0 * d_1) *
              8.7904305259200008E-7 / (M_DF_tmp * rt_powd_snf(b_o, 7.0))) * n_o *
        api + M_o;
      d_1_tmp = rt_powd_snf(b_o, 8.0);
      d_1 = ((((7.0 - epsb_1980_tmp * epsb_1980_tmp * 114.0) + 395.0 * d_1) *
              8.7904305259200008E-7 / (M_DF_tmp * d_1_tmp) + (1.0 -
               epsb_1980_tmp * epsb_1980_tmp * 5.0) * -0.0016239240000000001 /
              M_DF_tmp_0) + ((3.0 - epsb_1980_tmp * epsb_1980_tmp * 36.0) + 49.0
              * d_1) * 3.1049437500000002E-6 / (4.0 * M_DF_tmp_tmp * d_1_tmp)) *
        n_o * api + deps_1980;
      M_DF_tmp = 2.0 * M_DF_tmp_tmp * d_1_tmp;
      d_1_tmp = api * api;
      M_DF_tmp_tmp = epsb_1980_tmp * epsb_1980_tmp * 7.0;
      u_moon = ((((4.0 * epsb_1980_tmp - 19.0 * rt_powd_snf(epsb_1980_tmp, 3.0))
                  * 8.7904305259200008E-7 / M_DF_tmp + -0.0016239240000000001 *
                  epsb_1980_tmp / (u_moon * rt_powd_snf(b_o, 4.0))) + (3.0 -
                  M_DF_tmp_tmp) * (3.1049437500000002E-6 * epsb_1980_tmp) /
                 M_DF_tmp) * n_o * api + rtDW.orbit_tle[4] * 0.0174532925) - n_o
        * 0.000541308 * epsb_1980_tmp / (u_moon * (b_o * b_o)) * 10.5 *
        tsince_JD * d_1_tmp;
      if (!lowAlt) {
        d_w = D_sun * rt_powd_snf(xi, 5.0) * 2.538815E-6 * n_o * sin(dpsi_1980) /
          (0.000541308 * rtDW.orbit_tle[5]) * rtDW.orbit_tle[2] * cos(deps_1980)
          * api;
        d_M = -0.66666666666666663 * D_sun * rtDW.orbit_tle[2] * d_M * (1.0 /
          (rtDW.orbit_tle[5] * eta)) * (rt_powd_snf(eta * cos(M_DF) + 1.0, 3.0)
          - rt_powd_snf(eta * cos(M_o) + 1.0, 3.0));
        M_DF = (M_DF + d_w) + d_M;
        d_1 = (d_1 - d_w) - d_M;
        D_sun = (rtDW.orbit_tle[5] - ((((rtDW.orbit_tle[5] * eta + 1.0) * (2.0 *
          eta) + 0.5 * rtDW.orbit_tle[5]) + 0.5 * rt_powd_snf(eta, 3.0)) -
                  ((((1.0 - eta * eta * 1.5) - 2.0 * rtDW.orbit_tle[5] * eta) -
                    0.5 * rtDW.orbit_tle[5] * rt_powd_snf(eta, 3.0)) * ((1.0 -
          epsb_1980_tmp * epsb_1980_tmp * 3.0) * 3.0) + ((eta * eta * 2.0 -
          rtDW.orbit_tle[5] * eta) - rtDW.orbit_tle[5] * rt_powd_snf(eta, 3.0)) *
                   ((1.0 - epsb_1980_tmp * epsb_1980_tmp) * 0.75) * cos(2.0 *
                    deps_1980)) * (0.001082616 * xi / ((1.0 - eta * eta) *
                    a_o_pp))) * (2.0 * n_o * D_sun * rt_powd_snf(xi, 4.0) *
                  a_o_pp * (b_o * b_o) * C_1_tmp) * rtDW.orbit_tle[2] * api) -
          rtDW.orbit_tle[2] * C_5 * (sin(M_DF) - sin(M_o));
        xi = rt_powd_snf(api, 3.0);
        d_M = rt_powd_snf(api, 4.0);
        deps_1980 = (((1.0 - tsince_JD * api) - d_1_tmp * D_2) - D_3 * xi) - D_4
          * d_M;
        M_o = deps_1980 * deps_1980 * a_o_pp;
        a_o_pp = (((1.5 * tsince_JD * d_1_tmp + IL3 * xi) + IL4 * d_M) + IL5 *
                  rt_powd_snf(api, 5.0)) * n_o + ((M_DF + d_1) + u_moon);
      } else {
        M_o = 1.0 - tsince_JD * api;
        M_o = M_o * M_o * a_o_pp;
        D_2 = rtDW.orbit_tle[5] * eta;
        D_sun = rtDW.orbit_tle[5] - ((((D_2 + 1.0) * (2.0 * eta) + 0.5 *
          rtDW.orbit_tle[5]) + 0.5 * C_1_tmp_tmp) - ((((1.0 - C_1_tmp_1) - 2.0 *
          rtDW.orbit_tle[5] * eta) - 0.5 * rtDW.orbit_tle[5] * C_1_tmp_tmp) *
          ((1.0 - epsb_1980_tmp * epsb_1980_tmp * 3.0) * 3.0) + ((d_w * 2.0 -
          D_2) - C_1_tmp_0) * ((1.0 - epsb_1980_tmp * epsb_1980_tmp) * 0.75) *
          cos(2.0 * deps_1980)) * (0.001082616 * xi / ((1.0 - eta * eta) *
          a_o_pp))) * (2.0 * n_o * D_sun * d_M * a_o_pp * (b_o * b_o) * C_1_tmp)
          * rtDW.orbit_tle[2] * api;
        a_o_pp = 1.5 * tsince_JD * n_o * d_1_tmp + ((M_DF + d_1) + u_moon);
      }

      if ((M_o == 0.0) || (D_sun >= 1.0)) {
        rtb_pos_teme_km[0] = 6378.137;
        rtb_pos_teme_km[1] = 6378.137;
        rtb_pos_teme_km[2] = 6878.137;
        rtb_flag_c = 5U;
      } else {
        n_o = sqrt(1.0 - D_sun * D_sun);
        xi = cos(d_1);
        deps_1980 = D_sun * xi;
        n_o *= n_o;
        tsince_JD = 2.538815E-6 * sin(dpsi_1980);
        api = tsince_JD / (0.002165232 * M_o * n_o) + D_sun * sin(d_1);
        n_o = (tsince_JD / (0.004330464 * M_o * n_o) * D_sun * xi * ((5.0 *
                 epsb_1980_tmp + 3.0) / (1.0 + epsb_1980_tmp)) + a_o_pp) -
          u_moon;
        if ((!rtIsInf(n_o)) && (!rtIsNaN(n_o))) {
          if (n_o == 0.0) {
            D_sun = 0.0;
          } else {
            D_sun = fmod(n_o, 6.2831853071795862);
            lowAlt = (D_sun == 0.0);
            if (!lowAlt) {
              d_1 = fabs(n_o / 6.2831853071795862);
              lowAlt = (fabs(d_1 - floor(d_1 + 0.5)) <= 2.2204460492503131E-16 *
                        d_1);
            }

            if (lowAlt) {
              D_sun = 0.0;
            } else {
              if (n_o < 0.0) {
                D_sun += 6.2831853071795862;
              }
            }
          }
        } else {
          D_sun = (rtNaN);
        }

        n_o = D_sun;
        d_1 = 0.0;
        iter = 0;
        while ((fabs(n_o - d_1) > 1.0E-8) && (iter < 10)) {
          n_o = d_1;
          d_1 += (((D_sun - api * cos(d_1)) + deps_1980 * sin(d_1)) - d_1) /
            ((-api * sin(d_1) - deps_1980 * cos(d_1)) + 1.0);
          iter++;
        }

        d_w = cos(d_1);
        d_M = sin(d_1);
        tsince_JD = deps_1980 * d_M - api * d_w;
        a_o_pp = sqrt(deps_1980 * deps_1980 + api * api);
        a_o_pp = 1.0 - a_o_pp * a_o_pp;
        n_o = a_o_pp * M_o;
        D_sun = (1.0 - (deps_1980 * d_w + api * d_M)) * M_o;
        if ((D_sun == 0.0) || (n_o == 0.0)) {
          rtb_pos_teme_km[0] = 6378.137;
          rtb_pos_teme_km[1] = 6378.137;
          rtb_pos_teme_km[2] = 6878.137;
          rtb_flag_c = 6U;
        } else {
          a_o_pp = sqrt(a_o_pp);
          xi = M_o / D_sun;
          deps_1980 = rt_atan2d_snf(((d_M - api) - deps_1980 * tsince_JD /
            (a_o_pp + 1.0)) * xi, (api * tsince_JD / (a_o_pp + 1.0) + (d_w -
            deps_1980)) * xi);
          D_2 = n_o * n_o;
          M_o = cos(2.0 * deps_1980);
          D_sun = (1.0 - a_o_pp * 0.00081196200000000006 * (epsb_1980_tmp *
                    epsb_1980_tmp * 3.0 - 1.0) / D_2) * D_sun + 0.000541308 /
            (2.0 * n_o) * (1.0 - epsb_1980_tmp * epsb_1980_tmp) * M_o;
          n_o = sin(2.0 * deps_1980);
          api = -(0.000541308 / (D_2 * 4.0)) * (M_DF_tmp_tmp - 1.0) * n_o +
            deps_1980;
          M_DF_tmp = 0.0016239240000000001 * epsb_1980_tmp / (D_2 * 2.0);
          u_moon += M_DF_tmp * n_o;
          dpsi_1980 += M_DF_tmp * sin(dpsi_1980) * M_o;
          tsince_JD = sin(api);
          deps_1980 = cos(api);
          api = cos(u_moon);
          n_o = cos(dpsi_1980);
          u_moon = sin(u_moon);
          rtb_pos_teme_km[0] = (-u_moon * n_o * tsince_JD + api * deps_1980) *
            D_sun * 6378.137;
          rtb_pos_teme_km[1] = (api * n_o * tsince_JD + u_moon * deps_1980) *
            D_sun * 6378.137;
          rtb_pos_teme_km[2] = (sin(dpsi_1980) * tsince_JD + 0.0 * deps_1980) *
            D_sun * 6378.137;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S263>/MATLAB Function' */

  /* MATLAB Function: '<S353>/MATLAB Function' */
  rtb_Gain_h[1] = 0.0;
  dpsi_1980 = cos(-epsb_1980);
  rtb_Gain_h[4] = dpsi_1980;
  epsb_1980 = sin(-epsb_1980);
  rtb_Gain_h[7] = epsb_1980;
  rtb_Gain_h[2] = 0.0;
  rtb_Gain_h[5] = -epsb_1980;
  rtb_Gain_h[8] = dpsi_1980;
  deps_1980 = cos(M_sun);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(M_sun);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  rtb_Gain_h[0] = 1.0;
  rtb_MathFunction1_fo[2] = 0.0;
  rtb_Gain_h[3] = 0.0;
  rtb_MathFunction1_fo[5] = 0.0;
  rtb_Gain_h[6] = 0.0;
  rtb_MathFunction1_fo[8] = 1.0;
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    for (i = 0; i < 3; i++) {
      iter = lowAlt_0 + 3 * i;
      rtb_Gain_h_0[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + lowAlt_0;
      rtb_Gain_h_0[iter] = rtb_Gain_h_0[rtb_mod_to_gcrf_tmp] +
        rtb_MathFunction1_fo[3 * i] * rtb_Gain_h[lowAlt_0];
      rtb_Gain_h_0[iter] = rtb_MathFunction1_fo[3 * i + 1] * rtb_Gain_h[lowAlt_0
        + 3] + rtb_Gain_h_0[rtb_mod_to_gcrf_tmp];
      rtb_Gain_h_0[iter] = rtb_MathFunction1_fo[3 * i + 2] * rtb_Gain_h[lowAlt_0
        + 6] + rtb_Gain_h_0[rtb_mod_to_gcrf_tmp];
    }

    rtb_Gain_h_1[3 * lowAlt_0] = rtb_Gain[lowAlt_0];
  }

  rtb_Gain_h_1[1] = 0.0;
  dpsi_1980 = cos(M_moon);
  rtb_Gain_h_1[4] = dpsi_1980;
  epsb_1980 = sin(M_moon);
  rtb_Gain_h_1[7] = epsb_1980;
  rtb_Gain_h_1[2] = 0.0;
  rtb_Gain_h_1[5] = -epsb_1980;
  rtb_Gain_h_1[8] = dpsi_1980;
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    for (i = 0; i < 3; i++) {
      iter = i + 3 * lowAlt_0;
      rtb_Gain_h[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * lowAlt_0 + i;
      rtb_Gain_h[iter] = rtb_Gain_h[rtb_mod_to_gcrf_tmp] + rtb_Gain_h_1[3 *
        lowAlt_0] * rtb_Gain_h_0[i];
      rtb_Gain_h[iter] = rtb_Gain_h_1[3 * lowAlt_0 + 1] * rtb_Gain_h_0[i + 3] +
        rtb_Gain_h[rtb_mod_to_gcrf_tmp];
      rtb_Gain_h[iter] = rtb_Gain_h_1[3 * lowAlt_0 + 2] * rtb_Gain_h_0[i + 6] +
        rtb_Gain_h[rtb_mod_to_gcrf_tmp];
    }
  }

  deps_1980 = cos(-eqe_1980);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(-eqe_1980);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    for (i = 0; i < 3; i++) {
      iter = lowAlt_0 + 3 * i;
      rtb_Gain_h_tmp[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + lowAlt_0;
      rtb_Gain_h_tmp[iter] = rtb_Gain_h_tmp[rtb_mod_to_gcrf_tmp] + rtb_Gain_h[3 *
        i] * rtb_mod_to_gcrf[lowAlt_0];
      rtb_Gain_h_tmp[iter] = rtb_Gain_h[3 * i + 1] * rtb_mod_to_gcrf[lowAlt_0 +
        3] + rtb_Gain_h_tmp[rtb_mod_to_gcrf_tmp];
      rtb_Gain_h_tmp[iter] = rtb_Gain_h[3 * i + 2] * rtb_mod_to_gcrf[lowAlt_0 +
        6] + rtb_Gain_h_tmp[rtb_mod_to_gcrf_tmp];
    }

    rtb_MathFunction1_fo[2 + 3 * lowAlt_0] = rtb_MatrixMultiply[lowAlt_0];
  }

  /* MATLAB Function: '<S264>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S265>/MATLAB Function3'
   */
  M_moon = mod_49nNZZ0V((35999.05034 * eps + 357.5277233) * 0.017453292519943295);
  epsb_1980 = (mod_49nNZZ0V((36000.77 * eps + 280.46) * 0.017453292519943295) +
               0.033417233996490527 * sin(M_moon)) + sin(2.0 * M_moon) *
    0.00034897235311083654;
  eps = (23.439291 - 0.0130042 * eps) * 0.017453292519943295;
  D_sun = (1.000140612 - 0.016708617 * cos(M_moon)) - cos(2.0 * M_moon) *
    0.000139589;
  M_sun = D_sun * cos(epsb_1980);
  M_moon = sin(epsb_1980);
  epsb_1980 = cos(eps) * M_moon * D_sun;
  eps = sin(eps) * M_moon * D_sun;
  for (i = 0; i < 3; i++) {
    /* Product: '<S263>/Product' */
    rtb_UnitConversion_e[i] = 0.0;
    for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
      /* MATLAB Function: '<S353>/MATLAB Function' incorporates:
       *  Product: '<S263>/Product'
       */
      iter = i + 3 * lowAlt_0;
      rtb_Gain_h[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * lowAlt_0 + i;
      rtb_Gain_h[iter] = rtb_Gain_h[rtb_mod_to_gcrf_tmp] + rtb_MathFunction1_fo
        [3 * lowAlt_0] * rtb_Gain_h_tmp[i];
      rtb_Gain_h[iter] = rtb_MathFunction1_fo[3 * lowAlt_0 + 1] *
        rtb_Gain_h_tmp[i + 3] + rtb_Gain_h[rtb_mod_to_gcrf_tmp];
      rtb_Gain_h[iter] = rtb_MathFunction1_fo[3 * lowAlt_0 + 2] *
        rtb_Gain_h_tmp[i + 6] + rtb_Gain_h[rtb_mod_to_gcrf_tmp];

      /* Product: '<S263>/Product' */
      rtb_UnitConversion_e[i] += rtb_Gain_h[rtb_mod_to_gcrf_tmp] *
        rtb_pos_teme_km[lowAlt_0];
    }

    /* Gain: '<S263>/Gain' */
    M_moon = 1000.0 * rtb_UnitConversion_e[i];

    /* Gain: '<S6>/M2KM' */
    rtb_M2KM[i] = 0.001 * M_moon;

    /* Gain: '<S264>/AU2KM' incorporates:
     *  Product: '<S264>/Product'
     */
    rtb_AU2KM[i] = 1.49598073E+8 * (rtb_mod_to_gcrf[i + 6] * eps +
      (rtb_mod_to_gcrf[i + 3] * epsb_1980 + rtb_mod_to_gcrf[i] * M_sun));

    /* Gain: '<S263>/Gain' */
    rtb_Gain[i] = M_moon;
  }

  /* Sum: '<S264>/Subtract' */
  eps = rtb_AU2KM[0] - rtb_M2KM[0];

  /* Math: '<S349>/Math Function' */
  rtb_MathFunction[0] = eps * eps;

  /* Sum: '<S264>/Subtract' */
  rtb_pos_teme_km[0] = eps;
  eps = rtb_AU2KM[1] - rtb_M2KM[1];

  /* Math: '<S349>/Math Function' */
  rtb_MathFunction[1] = eps * eps;

  /* Sum: '<S264>/Subtract' */
  rtb_pos_teme_km[1] = eps;
  eps = rtb_AU2KM[2] - rtb_M2KM[2];
  rtb_pos_teme_km[2] = eps;

  /* Sum: '<S349>/Sum of Elements' incorporates:
   *  Math: '<S349>/Math Function'
   */
  api = (rtb_MathFunction[0] + rtb_MathFunction[1]) + eps * eps;

  /* Math: '<S349>/Math Function1'
   *
   * About '<S349>/Math Function1':
   *  Operator: sqrt
   */
  if (api < 0.0) {
    api = -sqrt(fabs(api));
  } else {
    api = sqrt(api);
  }

  /* End of Math: '<S349>/Math Function1' */

  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S349>/Constant'
   *  Product: '<S349>/Product'
   */
  if (api > 0.0) {
    rtb_Switch_dq[0] = rtb_pos_teme_km[0];
    rtb_Switch_dq[1] = rtb_pos_teme_km[1];
    rtb_Switch_dq[2] = eps;
    rtb_Switch_dq[3] = api;
  } else {
    rtb_Switch_dq[0] = rtb_pos_teme_km[0] * 0.0;
    rtb_Switch_dq[1] = rtb_pos_teme_km[1] * 0.0;
    rtb_Switch_dq[2] = eps * 0.0;
    rtb_Switch_dq[3] = 1.0;
  }

  /* End of Switch: '<S349>/Switch' */

  /* MATLAB Function: '<S353>/MATLAB Function' */
  deps_1980 = cos(O_moon);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(O_moon);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  for (i = 0; i < 3; i++) {
    /* Product: '<S349>/Divide' */
    rtb_MathFunction[i] = rtb_Switch_dq[i] / rtb_Switch_dq[3];

    /* MATLAB Function: '<S353>/MATLAB Function' */
    rtb_MathFunction1_fo[2 + 3 * i] = rtb_MatrixMultiply[i];

    /* Product: '<S262>/MatrixMultiply' */
    rtb_MatrixMultiply[i] = 0.0;
    for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
      /* Math: '<S265>/Transpose' incorporates:
       *  MATLAB Function: '<S353>/MATLAB Function'
       *  Product: '<S262>/MatrixMultiply'
       */
      iter = i + 3 * lowAlt_0;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * lowAlt_0 + i;
      rtb_mod_to_gcrf[iter] = rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] +
        rtb_MathFunction1_fo[3 * i] * rtb_Gain_h_tmp[lowAlt_0];
      rtb_mod_to_gcrf[iter] = rtb_MathFunction1_fo[3 * i + 1] *
        rtb_Gain_h_tmp[lowAlt_0 + 3] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
      rtb_mod_to_gcrf[iter] = rtb_MathFunction1_fo[3 * i + 2] *
        rtb_Gain_h_tmp[lowAlt_0 + 6] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];

      /* Product: '<S262>/MatrixMultiply' */
      rtb_MatrixMultiply[i] += rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] *
        rtb_Gain[lowAlt_0];
    }
  }

  /* Sqrt: '<S337>/sqrt' incorporates:
   *  Product: '<S337>/Product2'
   *  Product: '<S337>/Product3'
   *  Sum: '<S337>/Sum2'
   */
  epsb_1980 = sqrt(rtb_MatrixMultiply[0] * rtb_MatrixMultiply[0] +
                   rtb_MatrixMultiply[1] * rtb_MatrixMultiply[1]);

  /* Outputs for Iterator SubSystem: '<S322>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S339>/While Iterator'
   */
  s339_iter = 1;
  do {
    api = rtDW.Memory_PreviousInput;
    if (s339_iter <= 0) {
      api = rt_atan2d_snf(rtb_MatrixMultiply[2], 0.99664718933525254 * epsb_1980);
    }

    eps = sin(api);
    M_sun = cos(api);
    eps *= 42841.31151331366 * eps * eps;
    eps += rtb_MatrixMultiply[2];
    M_moon = rt_atan2d_snf(eps, epsb_1980 - M_sun * M_sun * M_sun *
      0.00669437999014133 * 6.378137E+6);
    M_sun = sin(M_moon);
    D_sun = cos(M_moon);
    eps = rt_atan2d_snf(0.99664718933525254 * M_sun, D_sun);
    rtDW.Memory_PreviousInput = eps;
    s339_iter++;
  } while ((api != eps) && (s339_iter <= 5));

  /* End of Outputs for SubSystem: '<S322>/While Iterator Subsystem' */

  /* UnitConversion: '<S336>/Unit Conversion' incorporates:
   *  Trigonometry: '<S322>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  M_moon *= 57.295779513082323;
  O_moon = 57.295779513082323 * rt_atan2d_snf(rtb_MatrixMultiply[1],
    rtb_MatrixMultiply[0]);

  /* UnitConversion: '<S334>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  deps_1980 = 0.017453292519943295 * M_moon;

  /* Trigonometry: '<S321>/sincos' */
  eps = cos(deps_1980);

  /* UnitConversion: '<S334>/Unit Conversion' incorporates:
   *  Trigonometry: '<S321>/sincos'
   */
  dpsi_1980 = sin(deps_1980);
  deps_1980 = 0.017453292519943295 * O_moon;

  /* Trigonometry: '<S321>/sincos' */
  eqe_1980 = cos(deps_1980);
  deps_1980 = sin(deps_1980);

  /* UnaryMinus: '<S325>/Unary Minus' incorporates:
   *  Product: '<S325>/u(1)*u(4)'
   */
  rtb_MathFunction1_i[0] = -(dpsi_1980 * eqe_1980);

  /* UnaryMinus: '<S328>/Unary Minus' */
  rtb_MathFunction1_i[1] = -deps_1980;

  /* UnaryMinus: '<S331>/Unary Minus' incorporates:
   *  Product: '<S331>/u(3)*u(4)'
   */
  rtb_MathFunction1_i[2] = -(eps * eqe_1980);

  /* UnaryMinus: '<S326>/Unary Minus' incorporates:
   *  Product: '<S326>/u(1)*u(2)'
   */
  rtb_MathFunction1_i[3] = -(dpsi_1980 * deps_1980);

  /* SignalConversion: '<S335>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_MathFunction1_i[4] = eqe_1980;

  /* UnaryMinus: '<S332>/Unary Minus' incorporates:
   *  Product: '<S332>/u(2)*u(3)'
   */
  rtb_MathFunction1_i[5] = -(deps_1980 * eps);

  /* SignalConversion: '<S335>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_i[6] = eps;

  /* SignalConversion: '<S335>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S330>/Constant'
   */
  rtb_MathFunction1_i[7] = 0.0;

  /* UnaryMinus: '<S333>/Unary Minus' */
  rtb_MathFunction1_i[8] = -dpsi_1980;

  /* Math: '<S262>/Transpose' */
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    rtb_MathFunction1_fo[3 * lowAlt_0] = rtb_MathFunction1_i[lowAlt_0];
    rtb_MathFunction1_fo[1 + 3 * lowAlt_0] = rtb_MathFunction1_i[lowAlt_0 + 3];
    rtb_MathFunction1_fo[2 + 3 * lowAlt_0] = rtb_MathFunction1_i[lowAlt_0 + 6];
  }

  memcpy(&rtb_MathFunction1_i[0], &rtb_MathFunction1_fo[0], 9U * sizeof(real_T));

  /* End of Math: '<S262>/Transpose' */

  /* Product: '<S338>/Product2' */
  api = M_sun * 0.00669437999014133;

  /* Product: '<S338>/Product3' incorporates:
   *  Constant: '<S338>/Constant1'
   *  Constant: '<S338>/f'
   *  Product: '<S338>/Product1'
   *  Sqrt: '<S338>/sqrt'
   *  Sum: '<S338>/Sum'
   */
  eps = 6.378137E+6 / sqrt(1.0 - api * M_sun);

  /* Product: '<S338>/Product4' */
  api *= eps;

  /* Sum: '<S338>/Sum2' */
  api += rtb_MatrixMultiply[2];

  /* Sum: '<S338>/Sum3' incorporates:
   *  Product: '<S338>/Product5'
   *  Product: '<S338>/Product6'
   */
  epsb_1980 = (M_sun * api - eps) + D_sun * epsb_1980;

  /* MATLAB Function: '<S262>/MATLAB Function' */
  if ((!rtIsInf(rtb_YMDHMS_UTC[0])) && (!rtIsNaN(rtb_YMDHMS_UTC[0]))) {
    if (rtb_YMDHMS_UTC[0] == 0.0) {
      D_sun = 0.0;
    } else {
      D_sun = fmod(rtb_YMDHMS_UTC[0], 4.0);
      if (D_sun == 0.0) {
        D_sun = 0.0;
      } else {
        if (rtb_YMDHMS_UTC[0] < 0.0) {
          D_sun += 4.0;
        }
      }
    }
  } else {
    D_sun = (rtNaN);
  }

  if (D_sun == 0.0) {
    api = 366.0;
    iter = 29;
  } else {
    api = 365.25;
    iter = 28;
  }

  if (rtb_YMDHMS_UTC[1] == 1.0) {
    eps = rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 2.0) {
    eps = 31.0 + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 3.0) {
    eps = (31.0 + (real_T)iter) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 4.0) {
    eps = ((31.0 + (real_T)iter) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 5.0) {
    eps = (((31.0 + (real_T)iter) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 6.0) {
    eps = ((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 7.0) {
    eps = (((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 8.0) {
    eps = ((((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 9.0) {
    eps = (((((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
           31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 10.0) {
    eps = ((((((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
            31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 11.0) {
    eps = (((((((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0)
             + 31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else {
    eps = ((((((((((31.0 + (real_T)iter) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0)
              + 31.0) + 30.0) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  }

  api = (((rtb_YMDHMS_UTC[3] / 24.0 + eps) + rtb_YMDHMS_UTC[4] / 1440.0) +
         rtb_YMDHMS_UTC[5] / 86400.0) / api + rtb_YMDHMS_UTC[0];

  /* End of MATLAB Function: '<S262>/MATLAB Function' */

  /* MATLAB Function: '<S324>/MATLAB Function' */
  eps = 0.017453292519943295 * M_moon;
  M_moon = 0.017453292519943295 * O_moon;
  dpsi_1980 = sin(eps);
  memset(&sp[0], 0, 13U * sizeof(real_T));
  memset(&cp[0], 0, 13U * sizeof(real_T));
  sp[1] = sin(M_moon);
  cp[0] = 1.0;
  cp[1] = cos(M_moon);
  iter = 3;
  for (lowAlt_0 = 0; lowAlt_0 < 11; lowAlt_0++) {
    iter = 3 + lowAlt_0;
    M_sun = cp[lowAlt_0 + 1];
    sp[lowAlt_0 + 2] = M_sun * sp[1] + sp[lowAlt_0 + 1] * cp[1];
    cp[lowAlt_0 + 2] = M_sun * cp[1] - sp[lowAlt_0 + 1] * sp[1];
  }

  M_sun = 6.378137E+6 / sqrt(1.0 - dpsi_1980 * dpsi_1980 * 0.0066943799901413165);
  M_moon = (M_sun + epsb_1980) * cos(eps);
  u_moon = (M_sun * 0.99330562000985867 + epsb_1980) * dpsi_1980;
  D_sun = sqrt(M_moon * M_moon + u_moon * u_moon);
  epsb_1980 = asin(u_moon / D_sun);
  dpsi_1980 = sin(epsb_1980);
  M_moon = 6.3712E+6 / D_sun;
  M_sun = M_moon * M_moon;
  memset(&P_0[0], 0, 196U * sizeof(real_T));
  tsince_JD = sqrt(1.0 - dpsi_1980 * dpsi_1980);
  eqe_1980 = tan(epsb_1980);
  O_moon = 1.0 / cos(epsb_1980);
  P_0[0] = 1.0;
  P_0[1] = dpsi_1980;
  P_0[15] = -tsince_JD;
  lowAlt_0 = 2;
  for (i = 0; i < 12; i++) {
    lowAlt_0 = 2 + i;
    P_0[i + 2] = (((2.0 + (real_T)i) * 2.0 - 1.0) * dpsi_1980 * P_0[i + 1] -
                  ((2.0 + (real_T)i) - 1.0) * P_0[i]) * (1.0 / (2.0 + (real_T)i));
    iter = 1;
    for (rtb_mod_to_gcrf_tmp = 0; rtb_mod_to_gcrf_tmp <= i + 1;
         rtb_mod_to_gcrf_tmp++) {
      iter = 1 + rtb_mod_to_gcrf_tmp;
      P_tmp = 14 * rtb_mod_to_gcrf_tmp + i;
      P_tmp_0 = i - rtb_mod_to_gcrf_tmp;
      deps_1980 = i + rtb_mod_to_gcrf_tmp;
      P_tmp_1 = P_tmp + 1;
      P_tmp_2 = P_tmp + 2;
      P_0[(i + 14 * (rtb_mod_to_gcrf_tmp + 1)) + 2] = ((((real_T)P_tmp_0 + 1.0)
        + 1.0) * dpsi_1980 * P_0[P_tmp_2] - ((deps_1980 + 3.0) - 1.0) *
        P_0[P_tmp_1]) * (1.0 / tsince_JD);
      if ((1 + rtb_mod_to_gcrf_tmp > 1) && (P_tmp_0 + 1 > 0)) {
        u_moon = ((real_T)(i - rtb_mod_to_gcrf_tmp) - 1.0) + 1.0;
        factorial_DisWLItj(&u_moon);
        D_sun = (deps_1980 + 1.0) - 1.0;
        factorial_DisWLItj(&D_sun);
        P_0[i + 14 * rtb_mod_to_gcrf_tmp] = rt_powd_snf(-1.0, (1.0 + (real_T)
          rtb_mod_to_gcrf_tmp) - 1.0) * sqrt(2.0 * u_moon / D_sun) * P_0[P_tmp];
      }

      if ((1 + rtb_mod_to_gcrf_tmp > 1) && (2 + i == 13)) {
        u_moon = (real_T)(i - rtb_mod_to_gcrf_tmp) + 1.0;
        factorial_DisWLItj(&u_moon);
        D_sun = (deps_1980 + 2.0) - 1.0;
        factorial_DisWLItj(&D_sun);
        P_0[(i + 14 * rtb_mod_to_gcrf_tmp) + 1] = rt_powd_snf(-1.0, (1.0 +
          (real_T)rtb_mod_to_gcrf_tmp) - 1.0) * sqrt(2.0 * u_moon / D_sun) *
          P_0[P_tmp_1];
        u_moon = ((real_T)(i - rtb_mod_to_gcrf_tmp) + 1.0) + 1.0;
        factorial_DisWLItj(&u_moon);
        D_sun = ((real_T)(i + rtb_mod_to_gcrf_tmp) + 3.0) - 1.0;
        factorial_DisWLItj(&D_sun);
        P_0[(i + 14 * rtb_mod_to_gcrf_tmp) + 2] = rt_powd_snf(-1.0, (1.0 +
          (real_T)rtb_mod_to_gcrf_tmp) - 1.0) * sqrt(2.0 * u_moon / D_sun) *
          P_0[P_tmp_2];
      }
    }
  }

  n_o = lowAlt_0 - iter;
  factorial_DisWLItj(&n_o);
  dpsi_1980 = lowAlt_0 + iter;
  factorial_DisWLItj(&dpsi_1980);
  P_0[lowAlt_0 + 14 * iter] *= sqrt(2.0 * n_o / dpsi_1980) * rt_powd_snf(-1.0,
    (real_T)iter);
  dpsi_1980 = 0.0;
  tsince_JD = 0.0;
  u_moon = 0.0;
  for (iter = 0; iter < 12; iter++) {
    M_sun *= M_moon;
    for (lowAlt_0 = 0; lowAlt_0 <= iter + 1; lowAlt_0++) {
      i = 12 * lowAlt_0 + iter;
      D_sun = dg[i] * (api - 2015.0) + g[i];
      deps_1980 = dh[i] * (api - 2015.0) + h[i];
      i = 14 * lowAlt_0 + iter;
      n_o = P_0[i + 1];
      epsb_1980_tmp = D_sun * cp[lowAlt_0] + deps_1980 * sp[lowAlt_0];
      dpsi_1980 -= (((1.0 + (real_T)iter) + 1.0) * eqe_1980 * n_o - sqrt((iter +
        2) * (iter + 2) - lowAlt_0 * lowAlt_0) * O_moon * P_0[i + 2]) *
        (epsb_1980_tmp * M_sun);
      tsince_JD += (D_sun * sp[lowAlt_0] - deps_1980 * cp[lowAlt_0]) * (M_sun *
        (real_T)lowAlt_0) * n_o;
      u_moon -= ((1.0 + (real_T)iter) + 1.0) * M_sun * epsb_1980_tmp * n_o;
    }
  }

  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    /* Math: '<S262>/Transpose1' incorporates:
     *  Math: '<S261>/Math Function1'
     */
    rtb_Gain_h_tmp[3 * lowAlt_0] = rtb_mod_to_gcrf[lowAlt_0];
    rtb_Gain_h_tmp[1 + 3 * lowAlt_0] = rtb_mod_to_gcrf[lowAlt_0 + 3];
    rtb_Gain_h_tmp[2 + 3 * lowAlt_0] = rtb_mod_to_gcrf[lowAlt_0 + 6];
  }

  /* MATLAB Function: '<S324>/MATLAB Function' */
  n_o = epsb_1980 - eps;
  epsb_1980_tmp = sin(n_o);
  n_o = cos(n_o);
  rtb_MatrixMultiply[0] = n_o * dpsi_1980 - epsb_1980_tmp * u_moon;
  rtb_MatrixMultiply[1] = O_moon * tsince_JD;
  rtb_MatrixMultiply[2] = epsb_1980_tmp * dpsi_1980 + n_o * u_moon;

  /* Trigonometry: '<S14>/Tan1' incorporates:
   *  Gain: '<S14>/deg2rad'
   */
  eps = tan(0.017453292519943295 * rtDW.RateTransition2[0]);

  /* Trigonometry: '<S14>/Tan' incorporates:
   *  Gain: '<S14>/deg2rad'
   */
  M_sun = tan(0.017453292519943295 * rtDW.RateTransition2[1]);

  /* Sqrt: '<S104>/Sqrt' incorporates:
   *  Constant: '<S104>/Constant'
   *  Math: '<S104>/Math Function'
   *  Math: '<S104>/Math Function1'
   *  Math: '<S104>/Math Function2'
   *  Sum: '<S104>/Sum'
   *
   * About '<S104>/Math Function2':
   *  Operator: reciprocal
   */
  api = sqrt(1.0 / ((eps * eps + 1.0) + M_sun * M_sun));

  /* SignalConversion: '<S14>/TmpSignal ConversionAtss_2_bodyInport2' incorporates:
   *  Product: '<S14>/Matrix Multiply'
   *  Product: '<S14>/Matrix Multiply1'
   */
  rtb_Switch2[0] = eps * api;
  rtb_Switch2[1] = api * M_sun;
  rtb_Switch2[2] = api;
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    /* Product: '<S262>/Matrix Multiply1' */
    rtb_UnitConversion_e[lowAlt_0] = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S262>/Matrix Multiply' incorporates:
       *  Math: '<S262>/Transpose1'
       *  Product: '<S262>/Matrix Multiply1'
       */
      iter = lowAlt_0 + 3 * i;
      rtb_Gain_h[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + lowAlt_0;
      rtb_Gain_h[iter] = rtb_Gain_h[rtb_mod_to_gcrf_tmp] + rtb_MathFunction1_i[3
        * i] * rtb_Gain_h_tmp[lowAlt_0];
      rtb_Gain_h[iter] = rtb_MathFunction1_i[3 * i + 1] *
        rtb_Gain_h_tmp[lowAlt_0 + 3] + rtb_Gain_h[rtb_mod_to_gcrf_tmp];
      rtb_Gain_h[iter] = rtb_MathFunction1_i[3 * i + 2] *
        rtb_Gain_h_tmp[lowAlt_0 + 6] + rtb_Gain_h[rtb_mod_to_gcrf_tmp];

      /* Product: '<S262>/Matrix Multiply1' */
      rtb_UnitConversion_e[lowAlt_0] += rtb_Gain_h[rtb_mod_to_gcrf_tmp] *
        rtb_MatrixMultiply[i];
    }

    /* Gain: '<S262>/nT2T' */
    rtb_nT2T[lowAlt_0] = 1.0E-9 * rtb_UnitConversion_e[lowAlt_0];

    /* Product: '<S14>/ss_2_body' incorporates:
     *  Constant: '<S14>/Constant1'
     *  SignalConversion: '<S14>/TmpSignal ConversionAtss_2_bodyInport2'
     */
    rtb_ss_2_body[lowAlt_0] = rtCP_Constant1_Value_h[lowAlt_0 + 6] * api +
      (rtCP_Constant1_Value_h[lowAlt_0 + 3] * rtb_Switch2[1] +
       rtCP_Constant1_Value_h[lowAlt_0] * rtb_Switch2[0]);
  }

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  maggyroProcessing_lib(rtDW.RateTransition3, rtDW.RateTransition6_b,
                        rtb_UnitConversion_e, &rtDW.Merge1_f,
                        0.21629296228661718, rtCP_pooled1, 130.0, 1.0E-6);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  maggyroProcessing_lib1(rtDW.RateTransition4, rtDW.RateTransition7, rtb_Switch2,
    &rtDW.Merge1_j, 0.02, rtCP_pooled1, 4.3633, 1.0);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  /* Reshape: '<S2>/Reshape4' */
  MEKF_lib(rtb_MathFunction, rtb_nT2T, rtb_ss_2_body, rtb_UnitConversion_e,
           rtb_Switch2, rtDW.RateTransition5, rtDW.Merge1_f, rtDW.Merge1_j,
           rtDW.triad_override, rtDW.qmerge, rtb_MatrixMultiply, rtb_YMDHMS_UTC,
           rtb_pos_teme_km, &rtb_Merge, &rtDW.MEKF_lib_g);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* Product: '<S261>/Product3' incorporates:
   *  Math: '<S261>/Math Function1'
   */
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    rtb_nT2T[lowAlt_0] = rtb_Gain_h_tmp[lowAlt_0 + 6] * rtb_Gain[2] +
      (rtb_Gain_h_tmp[lowAlt_0 + 3] * rtb_Gain[1] + rtb_Gain_h_tmp[lowAlt_0] *
       rtb_Gain[0]);
  }

  /* End of Product: '<S261>/Product3' */

  /* Switch: '<S305>/Switch' incorporates:
   *  Abs: '<S305>/Abs'
   *  Bias: '<S305>/Bias'
   *  Bias: '<S305>/Bias1'
   *  Constant: '<S305>/Constant2'
   *  Constant: '<S306>/Constant'
   *  Math: '<S305>/Math Function1'
   *  RelationalOperator: '<S306>/Compare'
   */
  if (fabs(rtDW.target_latlonalt[0]) > 180.0) {
    eps = rt_modd_snf(rtDW.target_latlonalt[0] + 180.0, 360.0) + -180.0;
  } else {
    eps = rtDW.target_latlonalt[0];
  }

  /* End of Switch: '<S305>/Switch' */

  /* Abs: '<S302>/Abs1' */
  api = fabs(eps);

  /* RelationalOperator: '<S304>/Compare' incorporates:
   *  Constant: '<S304>/Constant'
   */
  lowAlt = (api > 90.0);

  /* Switch: '<S302>/Switch' incorporates:
   *  Bias: '<S302>/Bias'
   *  Bias: '<S302>/Bias1'
   *  Constant: '<S272>/Constant'
   *  Constant: '<S272>/Constant1'
   *  Gain: '<S302>/Gain'
   *  Product: '<S302>/Divide1'
   *  Switch: '<S272>/Switch1'
   */
  if (lowAlt) {
    /* Signum: '<S302>/Sign1' */
    if (eps < 0.0) {
      eps = -1.0;
    } else if (eps > 0.0) {
      eps = 1.0;
    } else if (eps == 0.0) {
      eps = 0.0;
    } else {
      eps = (rtNaN);
    }

    /* End of Signum: '<S302>/Sign1' */
    eps *= -(api + -90.0) + 90.0;
    lowAlt_0 = 180;
  } else {
    lowAlt_0 = 0;
  }

  /* End of Switch: '<S302>/Switch' */

  /* UnitConversion: '<S296>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  M_sun = 0.017453292519943295 * eps;

  /* Product: '<S271>/Product3' incorporates:
   *  Constant: '<S266>/Constant2'
   *  Trigonometry: '<S271>/sincos1'
   */
  dpsi_1980 = 0.0 * sin(M_sun);
  O_moon = 0.0 * cos(M_sun);

  /* Trigonometry: '<S271>/Trigonometric Function2' incorporates:
   *  Constant: '<S271>/f'
   *  Product: '<S271>/Product2'
   *  Trigonometry: '<S271>/Trigonometric Function1'
   */
  api = rt_atan2d_snf(tan(M_sun) * 0.99664718933525254 * 0.99664718933525254,
                      1.0);

  /* Trigonometry: '<S300>/Trigonometric Function' incorporates:
   *  UnitConversion: '<S297>/Unit Conversion'
   *  UnitConversion: '<S301>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  M_sun = sin(57.295779513082323 * api * 0.017453292519943295);

  /* Sqrt: '<S300>/sqrt' incorporates:
   *  Constant: '<S300>/Constant'
   *  Constant: '<S300>/Re'
   *  Product: '<S300>/Product2'
   *  Product: '<S300>/Product3'
   *  Sum: '<S300>/Sum2'
   */
  M_sun = sqrt(4.0680631590769E+13 / (M_sun * M_sun * 0.006739496742276474 + 1.0));

  /* Trigonometry: '<S271>/sincos' */
  epsb_1980 = cos(api);
  api = sin(api);

  /* Sum: '<S271>/Sum1' incorporates:
   *  Product: '<S271>/Product1'
   */
  dpsi_1980 += M_sun * api;

  /* UnitConversion: '<S298>/Unit Conversion' incorporates:
   *  Product: '<S271>/Product1'
   *  Sum: '<S271>/Sum1'
   *  Trigonometry: '<S271>/Trigonometric Function3'
   *  Trigonometry: '<S271>/sincos'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  api = rt_atan2d_snf(dpsi_1980, M_sun * epsb_1980 + O_moon) *
    57.295779513082323;

  /* Sum: '<S272>/Sum' */
  M_sun = (real_T)lowAlt_0 + rtDW.target_latlonalt[1];

  /* Switch: '<S303>/Switch' incorporates:
   *  Abs: '<S303>/Abs'
   *  Bias: '<S303>/Bias'
   *  Bias: '<S303>/Bias1'
   *  Constant: '<S303>/Constant2'
   *  Constant: '<S307>/Constant'
   *  Math: '<S303>/Math Function1'
   *  RelationalOperator: '<S307>/Compare'
   */
  if (fabs(M_sun) > 180.0) {
    M_sun = rt_modd_snf(M_sun + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S303>/Switch' */

  /* UnitConversion: '<S294>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  dpsi_1980 = 0.017453292519943295 * api;
  O_moon = 0.017453292519943295 * M_sun;

  /* Trigonometry: '<S270>/sincos' */
  M_moon = cos(dpsi_1980);
  dpsi_1980 = sin(dpsi_1980);
  epsb_1980 = cos(O_moon);
  O_moon = sin(O_moon);

  /* UnaryMinus: '<S285>/Unary Minus' incorporates:
   *  Product: '<S285>/u(1)*u(4)'
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[0] = -(dpsi_1980 * epsb_1980);

  /* UnaryMinus: '<S288>/Unary Minus' incorporates:
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[1] = -O_moon;

  /* UnaryMinus: '<S291>/Unary Minus' incorporates:
   *  Product: '<S291>/u(3)*u(4)'
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[2] = -(M_moon * epsb_1980);

  /* UnaryMinus: '<S286>/Unary Minus' incorporates:
   *  Product: '<S286>/u(1)*u(2)'
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[3] = -(dpsi_1980 * O_moon);

  /* SignalConversion: '<S295>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[4] = epsb_1980;

  /* UnaryMinus: '<S292>/Unary Minus' incorporates:
   *  Product: '<S292>/u(2)*u(3)'
   *  Trigonometry: '<S270>/sincos'
   */
  rtb_MathFunction1_m[5] = -(O_moon * M_moon);

  /* SignalConversion: '<S295>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_m[6] = M_moon;

  /* SignalConversion: '<S295>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S290>/Constant'
   */
  rtb_MathFunction1_m[7] = 0.0;

  /* UnaryMinus: '<S293>/Unary Minus' */
  rtb_MathFunction1_m[8] = -dpsi_1980;

  /* Math: '<S266>/Math Function1' */
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    rtb_MathFunction1_i[3 * lowAlt_0] = rtb_MathFunction1_m[lowAlt_0];
    rtb_MathFunction1_i[1 + 3 * lowAlt_0] = rtb_MathFunction1_m[lowAlt_0 + 3];
    rtb_MathFunction1_i[2 + 3 * lowAlt_0] = rtb_MathFunction1_m[lowAlt_0 + 6];
  }

  memcpy(&rtb_MathFunction1_m[0], &rtb_MathFunction1_i[0], 9U * sizeof(real_T));

  /* End of Math: '<S266>/Math Function1' */

  /* UnitConversion: '<S308>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  api *= 0.017453292519943295;

  /* Trigonometry: '<S273>/Trigonometric Function' */
  api = sin(api);

  /* UnitConversion: '<S283>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  dpsi_1980 = 0.017453292519943295 * eps;
  O_moon = 0.017453292519943295 * M_sun;

  /* Trigonometry: '<S269>/sincos' */
  eps = cos(dpsi_1980);
  dpsi_1980 = sin(dpsi_1980);
  eqe_1980 = cos(O_moon);
  deps_1980 = sin(O_moon);

  /* UnaryMinus: '<S274>/Unary Minus' incorporates:
   *  Product: '<S274>/u(1)*u(4)'
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[0] = -(dpsi_1980 * eqe_1980);

  /* UnaryMinus: '<S277>/Unary Minus' incorporates:
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[1] = -deps_1980;

  /* UnaryMinus: '<S280>/Unary Minus' incorporates:
   *  Product: '<S280>/u(3)*u(4)'
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[2] = -(eps * eqe_1980);

  /* UnaryMinus: '<S275>/Unary Minus' incorporates:
   *  Product: '<S275>/u(1)*u(2)'
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[3] = -(dpsi_1980 * deps_1980);

  /* SignalConversion: '<S284>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[4] = eqe_1980;

  /* UnaryMinus: '<S281>/Unary Minus' incorporates:
   *  Product: '<S281>/u(2)*u(3)'
   *  Trigonometry: '<S269>/sincos'
   */
  rtb_MathFunction_b[5] = -(deps_1980 * eps);

  /* SignalConversion: '<S284>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction_b[6] = eps;

  /* SignalConversion: '<S284>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S279>/Constant'
   */
  rtb_MathFunction_b[7] = 0.0;

  /* UnaryMinus: '<S282>/Unary Minus' */
  rtb_MathFunction_b[8] = -dpsi_1980;

  /* Math: '<S266>/Math Function' */
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    rtb_MathFunction1_i[3 * lowAlt_0] = rtb_MathFunction_b[lowAlt_0];
    rtb_MathFunction1_i[1 + 3 * lowAlt_0] = rtb_MathFunction_b[lowAlt_0 + 3];
    rtb_MathFunction1_i[2 + 3 * lowAlt_0] = rtb_MathFunction_b[lowAlt_0 + 6];
  }

  memcpy(&rtb_MathFunction_b[0], &rtb_MathFunction1_i[0], 9U * sizeof(real_T));

  /* End of Math: '<S266>/Math Function' */

  /* SignalConversion: '<S266>/TmpSignal ConversionAtProductInport2' incorporates:
   *  Constant: '<S266>/Constant1'
   *  UnaryMinus: '<S266>/Unary Minus1'
   */
  rtb_Switch2[0] = 0.0;
  rtb_Switch2[1] = 0.0;
  rtb_Switch2[2] = -rtDW.target_latlonalt[2];

  /* Sqrt: '<S273>/sqrt' incorporates:
   *  Constant: '<S273>/Constant'
   *  Constant: '<S273>/Re'
   *  Product: '<S273>/Product2'
   *  Product: '<S273>/Product3'
   *  Sum: '<S273>/Sum2'
   */
  deps_1980 = sqrt(4.0680631590769E+13 / (api * api * 0.006739496742276474 + 1.0));
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    /* Sum: '<S266>/Sum' incorporates:
     *  Product: '<S266>/Product'
     *  Product: '<S266>/Product1'
     *  Sqrt: '<S273>/sqrt'
     *  UnaryMinus: '<S266>/Unary Minus'
     */
    rtb_UnitConversion_e[lowAlt_0] = (rtb_MathFunction1_m[lowAlt_0 + 6] *
      -deps_1980 + (rtb_MathFunction1_m[lowAlt_0 + 3] * 0.0 +
                    rtb_MathFunction1_m[lowAlt_0] * 0.0)) +
      (rtb_MathFunction_b[lowAlt_0 + 6] * rtb_Switch2[2] +
       (rtb_MathFunction_b[lowAlt_0 + 3] * 0.0 + rtb_MathFunction_b[lowAlt_0] *
        0.0));
  }

  /* Outputs for Atomic SubSystem: '<S261>/target_groundpass_lib1' */
  target_groundpass_lib1(rtb_nT2T, rtb_UnitConversion_e, rtDW.target_latlonalt[0],
    rtDW.target_latlonalt[1], &lowAlt, &api, rtb_Switch2);

  /* End of Outputs for SubSystem: '<S261>/target_groundpass_lib1' */

  /* MATLAB Function: '<S350>/MATLAB Function' */
  light = false;
  epsb_1980 = norm_2e9Xj4lM(rtb_M2KM);
  eps = rtb_AU2KM[0] * 1.49598073E+8;
  dpsi_1980 = rtb_M2KM[0] * eps;
  rtb_AU2KM[0] = eps;
  eps = rtb_AU2KM[1] * 1.49598073E+8;
  dpsi_1980 += rtb_M2KM[1] * eps;
  rtb_AU2KM[1] = eps;
  eps = rtb_AU2KM[2] * 1.49598073E+8;
  n_o = rtb_M2KM[2] * eps;
  dpsi_1980 += n_o;
  rtb_AU2KM[2] = eps;
  deps_1980 = norm_2e9Xj4lM(rtb_AU2KM);
  M_sun = (rtb_M2KM[0] * rtb_AU2KM[0] + rtb_M2KM[1] * rtb_AU2KM[1]) + n_o;
  eps = (epsb_1980 * epsb_1980 - dpsi_1980) / ((epsb_1980 * epsb_1980 +
    deps_1980 * deps_1980) - M_sun * 2.0);
  if ((eps < 0.0) || (eps > 1.0)) {
    light = true;
  }

  if (M_sun * eps + (1.0 - eps) * (epsb_1980 * epsb_1980) >=
      4.0680631590768993E+7) {
    light = true;
  }

  light = !light;

  /* End of MATLAB Function: '<S350>/MATLAB Function' */

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  /* Reshape: '<S2>/Reshape4' */
  rtb_gnc_mode = mode_select_lib(rtDW.telecom, light, rtDW.RateTransition5,
    lowAlt, rtb_MatrixMultiply, rtDW.MET_utc_s, rtDW.MET_soar_utc_s,
    rtDW.RateTransition1, &rtDW.mode_select_lib_k);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */

  /* Product: '<S261>/Product1' */
  for (lowAlt_0 = 0; lowAlt_0 < 3; lowAlt_0++) {
    rtb_AU2KM[lowAlt_0] = rtb_mod_to_gcrf[lowAlt_0 + 6] * rtb_Switch2[2] +
      (rtb_mod_to_gcrf[lowAlt_0 + 3] * rtb_Switch2[1] + rtb_mod_to_gcrf[lowAlt_0]
       * rtb_Switch2[0]);
  }

  /* End of Product: '<S261>/Product1' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  /* Update for RateTransition: '<S1>/Rate Transition4' */
  target_generation_lib(rtb_gnc_mode, rtb_MathFunction, rtb_AU2KM, rtb_Gain,
                        rtDW.qmerge, rtb_MatrixMultiply, rtDW.RateTransition1,
                        rtDW.quat_soar_cmd, rtDW.MET_soar_utc_s, rtDW.MET_utc_s,
                        rtb_Switch_dq, rtb_M2KM, rtb_Switch2, &rtb_flag,
                        rtDW.X_f, rtDW.U, &rtDW.s, rtDW.exitcode, rtDW.time,
                        &rtDW.RateTransition4_18_Buffer0.soar_count);

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */

  /* Outputs for Atomic SubSystem: '<S5>/quat_err_lib' */
  quat_err_lib(rtb_Switch_dq, rtDW.qmerge, rtb_radps_2_rpm);

  /* End of Outputs for SubSystem: '<S5>/quat_err_lib' */

  /* MATLAB Function: '<S13>/MATLAB Function' */
  rtb_AU2KM[0] = 0.0;
  rtb_AU2KM[1] = 0.0;
  rtb_AU2KM[2] = 0.0;
  for (iter = 0; iter < 6; iter++) {
    if (rtDW.RateTransition1_h[iter] > 99.760095101689075) {
      rtb_AU2KM[0] += (real_T)normals[3 * iter];
      rtb_AU2KM[1] += (real_T)normals[3 * iter + 1];
      rtb_AU2KM[2] += (real_T)normals[3 * iter + 2];
    }
  }

  rtb_UnitConversion_e[0] = rtb_AU2KM[0];
  rtb_UnitConversion_e[1] = rtb_AU2KM[1] - -1.0;
  rtb_UnitConversion_e[2] = rtb_AU2KM[2];
  if (norm_2e9Xj4lM(rtb_UnitConversion_e) < 1.0E-8) {
    for (i = 0; i < 6; i++) {
      x[i] = rtDW.RateTransition1_h[i];
    }

    sort_E8F8dFL3(x, iidx);
    rtb_AU2KM[0] += (real_T)normals[(iidx[4] - 1) * 3];
    rtb_AU2KM[1] += (real_T)normals[(iidx[4] - 1) * 3 + 1];
    rtb_AU2KM[2] += (real_T)normals[(iidx[4] - 1) * 3 + 2];
  }

  deps_1980 = norm_2e9Xj4lM(rtb_AU2KM);
  if (deps_1980 < 1.0) {
    rtb_AU2KM[0] = 0.0;
    rtb_AU2KM[1] = 0.0;
    rtb_AU2KM[2] = -1.0;
  } else {
    rtb_AU2KM[0] /= deps_1980;
    rtb_AU2KM[1] /= deps_1980;
    rtb_AU2KM[2] /= deps_1980;
  }

  /* End of MATLAB Function: '<S13>/MATLAB Function' */

  /* Sum: '<S5>/Sum1' */
  rtb_MathFunction[0] = rtb_M2KM[0] - rtb_MatrixMultiply[0];
  rtb_MathFunction[1] = rtb_M2KM[1] - rtb_MatrixMultiply[1];
  rtb_MathFunction[2] = rtb_M2KM[2] - rtb_MatrixMultiply[2];

  /* SwitchCase: '<S213>/Switch Case' incorporates:
   *  Reshape: '<S2>/Reshape4'
   */
  switch (rtb_gnc_mode) {
   case 0:
   case 1:
   case 2:
    /* Outputs for IfAction SubSystem: '<S213>/case_null_control' incorporates:
     *  ActionPort: '<S220>/Action Port'
     */
    /* SignalConversion: '<S220>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = 0.0;

    /* SignalConversion: '<S220>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[0] = 0.0;

    /* SignalConversion: '<S220>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = 0.0;

    /* SignalConversion: '<S220>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[1] = 0.0;

    /* SignalConversion: '<S220>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = 0.0;

    /* SignalConversion: '<S220>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[2] = 0.0;

    /* End of Outputs for SubSystem: '<S213>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S213>/case_asm' incorporates:
     *  ActionPort: '<S218>/Action Port'
     */
    /* SignalConversion: '<S218>/OutportBuffer_InsertedFor_asm_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S218>/asmController_lib' */
    asmController_lib(rtb_MathFunction, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S218>/asmController_lib' */
    /* End of Outputs for SubSystem: '<S213>/case_asm' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S213>/case_desat' incorporates:
     *  ActionPort: '<S219>/Action Port'
     */
    /* SignalConversion: '<S219>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = rtConstB.null_control_lib_g.null_control_input[0];

    /* SignalConversion: '<S219>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[0] = rtConstB.null_control_lib_g.null_control_input[0];

    /* SignalConversion: '<S219>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = rtConstB.null_control_lib_g.null_control_input[1];

    /* SignalConversion: '<S219>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[1] = rtConstB.null_control_lib_g.null_control_input[1];

    /* SignalConversion: '<S219>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = rtConstB.null_control_lib_g.null_control_input[2];

    /* SignalConversion: '<S219>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[2] = rtConstB.null_control_lib_g.null_control_input[2];

    /* End of Outputs for SubSystem: '<S213>/case_desat' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S213>/case_sunseek' incorporates:
     *  ActionPort: '<S222>/Action Port'
     */
    /* SignalConversion: '<S222>/OutportBuffer_InsertedFor_sunseek_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S222>/sunSeek_lib' */
    sunSeek_lib(rtDW.RateTransition5, rtb_AU2KM, rtb_ss_2_body, rtb_MathFunction,
                rtDW.Merge);

    /* End of Outputs for SubSystem: '<S222>/sunSeek_lib' */
    /* End of Outputs for SubSystem: '<S213>/case_sunseek' */
    break;

   case 6:
   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S213>/case_reorientation' incorporates:
     *  ActionPort: '<S221>/Action Port'
     */
    /* SignalConversion: '<S221>/OutportBuffer_InsertedFor_tracking_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S221>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_radps_2_rpm, rtb_MathFunction, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S221>/PD_Controller_Lib' */
    /* End of Outputs for SubSystem: '<S213>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S213>/Switch Case' */

  /* Sum: '<S5>/Sum' */
  rtb_Switch2[0] += rtDW.Merge[0];
  rtb_Switch2[1] += rtDW.Merge[1];
  rtb_Switch2[2] += rtDW.Merge[2];

  /* Outputs for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
  rwa_allocation_lib(rtb_Switch2, rtDW.RateTransition1, rtDW.RateTransition2_l,
                     rtb_input_wheel_sat, &rtDW.rwa_allocation_lib_o);

  /* End of Outputs for SubSystem: '<S5>/rwa_allocation_lib' */

  /* Outputs for Atomic SubSystem: '<S261>/target_groundpass_lib' */
  /* Constant: '<S261>/Constant' */
  target_groundpass_lib(rtb_nT2T, rtCP_Constant_Value_jp, &rtb_Compare_m, &eps,
                        rtb_AU2KM, &rtConstB.target_groundpass_lib_i);

  /* End of Outputs for SubSystem: '<S261>/target_groundpass_lib' */

  /* Gain: '<S217>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S217>/Discrete-Time Integrator'
   *  Product: '<S217>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtb_input_wheel_sat[0];

  /* Saturate: '<S217>/Saturation' */
  if (epsb_1980 > 6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[0] = 6500.0;
  } else if (epsb_1980 < -6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[0] = -6500.0;
  } else {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[0] = epsb_1980;
  }

  /* Gain: '<S217>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S217>/Discrete-Time Integrator'
   *  Product: '<S217>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtb_input_wheel_sat[1];

  /* Saturate: '<S217>/Saturation' */
  if (epsb_1980 > 6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[1] = 6500.0;
  } else if (epsb_1980 < -6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[1] = -6500.0;
  } else {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[1] = epsb_1980;
  }

  /* Gain: '<S217>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S217>/Discrete-Time Integrator'
   *  Product: '<S217>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtb_input_wheel_sat[2];

  /* Saturate: '<S217>/Saturation' */
  if (epsb_1980 > 6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[2] = 6500.0;
  } else if (epsb_1980 < -6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[2] = -6500.0;
  } else {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[2] = epsb_1980;
  }

  /* Gain: '<S217>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S217>/Discrete-Time Integrator'
   *  Product: '<S217>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += 0.25 * rtb_input_wheel_sat[3];

  /* Saturate: '<S217>/Saturation' */
  if (epsb_1980 > 6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[3] = 6500.0;
  } else if (epsb_1980 < -6500.0) {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[3] = -6500.0;
  } else {
    /* Update for RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3_1_Buffer0[3] = epsb_1980;
  }

  /* Update for RateTransition: '<S1>/Rate Transition3' */
  rtDW.RateTransition3_2_Buffer0[0] = rtDW.Merge1[0];
  rtDW.RateTransition3_2_Buffer0[1] = rtDW.Merge1[1];
  rtDW.RateTransition3_2_Buffer0[2] = rtDW.Merge1[2];

  /* Update for RateTransition: '<S1>/Rate Transition4' */
  rtDW.RateTransition4_1_Buffer0 = rtb_gnc_mode;
  rtDW.RateTransition4_2_Buffer0[0] = rtDW.qmerge[0];
  rtDW.RateTransition4_2_Buffer0[1] = rtDW.qmerge[1];
  rtDW.RateTransition4_2_Buffer0[2] = rtDW.qmerge[2];
  rtDW.RateTransition4_2_Buffer0[3] = rtDW.qmerge[3];
  rtDW.RateTransition4_3_Buffer0[0] = rtb_MatrixMultiply[0];
  rtDW.RateTransition4_3_Buffer0[1] = rtb_MatrixMultiply[1];
  rtDW.RateTransition4_3_Buffer0[2] = rtb_MatrixMultiply[2];
  rtDW.RateTransition4_4_Buffer0[0] = rtb_Switch_dq[0];
  rtDW.RateTransition4_4_Buffer0[1] = rtb_Switch_dq[1];
  rtDW.RateTransition4_4_Buffer0[2] = rtb_Switch_dq[2];
  rtDW.RateTransition4_4_Buffer0[3] = rtb_Switch_dq[3];
  rtDW.RateTransition4_5_Buffer0[0] = rtb_M2KM[0];
  rtDW.RateTransition4_5_Buffer0[1] = rtb_M2KM[1];
  rtDW.RateTransition4_5_Buffer0[2] = rtb_M2KM[2];
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition4_6_Buffer0[i] = rtb_YMDHMS_UTC[i];
  }

  rtDW.RateTransition4_7_Buffer0[0] = rtb_pos_teme_km[0];
  rtDW.RateTransition4_7_Buffer0[1] = rtb_pos_teme_km[1];
  rtDW.RateTransition4_7_Buffer0[2] = rtb_pos_teme_km[2];
  rtDW.RateTransition4_8_Buffer0 = rtb_Merge;
  rtDW.RateTransition4_9_Buffer0[0] = rtb_Gain[0];
  rtDW.RateTransition4_9_Buffer0[1] = rtb_Gain[1];
  rtDW.RateTransition4_9_Buffer0[2] = rtb_Gain[2];

  /* Saturate: '<S214>/Saturation' */
  if (rtb_radps_2_rpm[0] > 1.0) {
    epsb_1980 = 1.0;
  } else if (rtb_radps_2_rpm[0] < -1.0) {
    epsb_1980 = -1.0;
  } else {
    epsb_1980 = rtb_radps_2_rpm[0];
  }

  /* End of Saturate: '<S214>/Saturation' */

  /* Update for RateTransition: '<S1>/Rate Transition4' incorporates:
   *  Abs: '<S214>/Abs'
   *  BusCreator: '<S1>/BusConversion_InsertedFor_Bus Assignment1_at_inport_18'
   *  Gain: '<S214>/Gain'
   *  Gain: '<S214>/RAD2DEG'
   *  Trigonometry: '<S214>/Acos'
   */
  rtDW.RateTransition4_10_Buffer0 = fabs(2.0 * acos(epsb_1980) *
    57.295779513082323);
  rtDW.RateTransition4_11_Buffer0 = light;
  rtDW.RateTransition4_12_Buffer0 = rtb_flag_c;
  rtDW.RateTransition4_13_Buffer0 = rtb_Compare_m;
  rtDW.RateTransition4_14_Buffer0 = lowAlt;
  rtDW.RateTransition4_15_Buffer0 = rtb_flag;
  rtDW.RateTransition4_16_Buffer0 = eps;
  rtDW.RateTransition4_17_Buffer0 = api;
  memcpy(&rtDW.RateTransition4_18_Buffer0.opt_state[0], &rtDW.X_f[0], 100U *
         sizeof(real_T));
  memcpy(&rtDW.RateTransition4_18_Buffer0.opt_ctrl_Nm[0], &rtDW.U[0], 30U *
         sizeof(real_T));
  rtDW.RateTransition4_18_Buffer0.final_time_s = rtDW.s;
  memcpy(&rtDW.RateTransition4_18_Buffer0.exitcode[0], &rtDW.exitcode[0], 17U *
         sizeof(real_T));
  memcpy(&rtDW.RateTransition4_18_Buffer0.slv_time_s[0], &rtDW.time[0], 15U *
         sizeof(real_T));
}

/* Model initialize function */
void FSW_Lib0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Start(&rtDW.MEKF_lib_g);

  /* End of Start for SubSystem: '<S1>/MEKF_lib' */
  rtPrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[1] = -0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[2] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[3] = -0.0030919554896630744;

  /* SystemInitialize for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Init(rtDW.qmerge, &rtDW.MEKF_lib_g);

  /* End of SystemInitialize for SubSystem: '<S1>/MEKF_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/mode_select_lib' */
  mode_select_lib_Init(&rtDW.mode_select_lib_k);

  /* End of SystemInitialize for SubSystem: '<S1>/mode_select_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/target_generation_lib' */
  target_generation_lib_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/target_generation_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
