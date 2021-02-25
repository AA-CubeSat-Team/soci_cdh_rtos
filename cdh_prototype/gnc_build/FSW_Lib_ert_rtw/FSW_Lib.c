/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.c
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

#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
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
void FSW_Lib_step0(void)               /* Sample time: [0.0125s, 0.0s] */
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
    rtDW.RateTransition5_i = rtU.sensor_meas.sun_meas_valid;

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition2[0] = rtU.sensor_meas.sun_meas_ss_deg[0];
    rtDW.RateTransition2[1] = rtU.sensor_meas.sun_meas_ss_deg[1];
    memcpy(&rtDW.orbit_tle[0], &rtU.telecommands.orbit_tle[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition3' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    memcpy(&rtDW.RateTransition3[0], &rtU.sensor_meas.mag_body_T[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition4' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    memcpy(&rtDW.RateTransition4[0], &rtU.sensor_meas.gyro_body_radps[0], 9U *
           sizeof(real_T));

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_b[0] = rtU.sensor_meas.mag_meas_valid[0];

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition7[0] = rtU.sensor_meas.gyro_meas_valid[0];

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_b[1] = rtU.sensor_meas.mag_meas_valid[1];

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition7[1] = rtU.sensor_meas.gyro_meas_valid[1];

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_b[2] = rtU.sensor_meas.mag_meas_valid[2];

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
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
      rtDW.RateTransition1_h[i] = rtU.sensor_meas.photodiodes_A[i];
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
void FSW_Lib_step1(void)               /* Sample time: [0.25s, 0.0s] */
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

  real_T x[6];
  int32_T iidx[6];
  static const real_T I_thresh_A[6] = { 1.2310454417957317, 1.2310454417957317,
    1.5389520412066509, 1.5389520412066509, 0.69714701753415664, 0.0 };

  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  real_T rtb_M2KM[3];
  real_T rtb_Subtract_f[3];
  real_T rtb_MathFunction[3];
  real_T rtb_Switch_dq[4];
  real_T rtb_MatrixMultiply[3];
  int8_T s247_iter;
  real_T rtb_MathFunction1_i[9];
  real_T rtb_Reshape3[3];
  boolean_T rtb_Compare_e;
  real_T rtb_MathFunction1_m[9];
  real_T rtb_MathFunction_b[9];
  real_T rtb_DiscreteTimeIntegrator[4];
  uint8_T rtb_Merge_i;
  uint8_T rtb_flag;
  boolean_T rtb_Compare_j5;
  real_T rtb_YMDHMS_UTC[6];
  real_T rtb_pos_teme_km[3];
  real_T rtb_mod_to_gcrf[9];
  real_T Gain_tmp[9];
  real_T rtb_M2KM_0[9];
  real_T rtb_M2KM_1[9];
  real_T rtb_M2KM_2[9];
  real_T Gain_tmp_0[3];
  real_T rtb_mod_to_gcrf_0[3];
  real_T rtb_MathFunction1_fo[9];
  int32_T i;
  int32_T rtb_Compare_h;
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

  /* MATLAB Function: '<S173>/MATLAB Function3' */
  jseconds2ymdhms_ModKEhLD(rtDW.MET_utc_s, &rtb_YMDHMS_UTC[0], &rtb_YMDHMS_UTC[1],
    &rtb_YMDHMS_UTC[2], &rtb_YMDHMS_UTC[3], &rtb_YMDHMS_UTC[4], &rtb_YMDHMS_UTC
    [5], &eqe_1980, &tsince_JD);
  jseconds2ymdhms_ModKEhLD(rtDW.MET_utc_s + -0.0361535, &epsb_1980, &M_moon,
    &M_sun, &eqe_1980, &O_moon, &dpsi_1980, &eps, &u_moon);
  jseconds2ymdhms_ModKEhLD((rtDW.MET_utc_s + 37.0) + 32.184, &epsb_1980, &M_moon,
    &M_sun, &O_moon, &dpsi_1980, &u_moon, &eqe_1980, &D_sun);

  /* MATLAB Function: '<S261>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S173>/MATLAB Function3'
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
  rtb_M2KM[0] = 1.0;
  rtb_MathFunction1_fo[2] = 0.0;
  rtb_mod_to_gcrf[1] = 0.0;
  rtb_MatrixMultiply[0] = 0.0;
  rtb_M2KM[1] = 0.0;
  rtb_MathFunction1_fo[5] = 0.0;
  rtb_mod_to_gcrf[4] = 1.0;
  rtb_MatrixMultiply[1] = 0.0;
  rtb_M2KM[2] = 0.0;
  rtb_MathFunction1_fo[8] = 1.0;
  rtb_mod_to_gcrf[7] = 0.0;
  rtb_MatrixMultiply[2] = 1.0;
  rtb_mod_to_gcrf[2] = D_sun;
  rtb_mod_to_gcrf[5] = 0.0;
  rtb_mod_to_gcrf[8] = deps_1980;
  deps_1980 = cos(u_moon);
  rtb_M2KM_1[0] = deps_1980;
  D_sun = sin(u_moon);
  rtb_M2KM_1[3] = D_sun;
  rtb_M2KM_1[6] = 0.0;
  rtb_M2KM_1[1] = -D_sun;
  rtb_M2KM_1[4] = deps_1980;
  rtb_M2KM_1[7] = 0.0;
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    for (i = 0; i < 3; i++) {
      rtb_mod_to_gcrf_tmp = rtb_Compare_h + 3 * i;
      rtb_M2KM_0[rtb_mod_to_gcrf_tmp] = 0.0;
      iter = 3 * i + rtb_Compare_h;
      rtb_M2KM_0[rtb_mod_to_gcrf_tmp] = rtb_M2KM_0[iter] + rtb_mod_to_gcrf[3 * i]
        * rtb_MathFunction1_fo[rtb_Compare_h];
      rtb_M2KM_0[rtb_mod_to_gcrf_tmp] = rtb_mod_to_gcrf[3 * i + 1] *
        rtb_MathFunction1_fo[rtb_Compare_h + 3] + rtb_M2KM_0[iter];
      rtb_M2KM_0[rtb_mod_to_gcrf_tmp] = rtb_mod_to_gcrf[3 * i + 2] *
        rtb_MathFunction1_fo[rtb_Compare_h + 6] + rtb_M2KM_0[iter];
    }

    rtb_M2KM_1[2 + 3 * rtb_Compare_h] = rtb_MatrixMultiply[rtb_Compare_h];
  }

  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    for (i = 0; i < 3; i++) {
      iter = i + 3 * rtb_Compare_h;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * rtb_Compare_h + i;
      rtb_mod_to_gcrf[iter] = rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] + rtb_M2KM_1
        [3 * rtb_Compare_h] * rtb_M2KM_0[i];
      rtb_mod_to_gcrf[iter] = rtb_M2KM_1[3 * rtb_Compare_h + 1] * rtb_M2KM_0[i +
        3] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
      rtb_mod_to_gcrf[iter] = rtb_M2KM_1[3 * rtb_Compare_h + 2] * rtb_M2KM_0[i +
        6] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
    }
  }

  eqe_1980 = ((dpsi_1980 * cos(epsb_1980) + 0.00264 * sin(O_moon)) + sin(2.0 *
    O_moon) * 6.3E-5) * 4.84813681109536E-6;
  dpsi_1980 = ((3.1644001848128662E+9 * eps + 67310.54841) + eps * eps *
               0.093104) - 6.2E-6 * rt_powd_snf(eps, 3.0);
  if (dpsi_1980 < 0.0) {
    D_sun = -1.0;
  } else if (dpsi_1980 > 0.0) {
    D_sun = 1.0;
  } else if (dpsi_1980 == 0.0) {
    D_sun = 0.0;
  } else {
    D_sun = (rtNaN);
  }

  O_moon = D_sun * 86400.0;
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

  /* MATLAB Function: '<S171>/MATLAB Function' incorporates:
   *  Constant: '<S171>/JD_J2000'
   *  MATLAB Function: '<S173>/MATLAB Function3'
   *  Sum: '<S171>/Sum'
   */
  D_sun = 1.88027916E-9;
  u_moon = 1.01222928;
  rtb_flag = 0U;
  dpsi_1980 = rtDW.orbit_tle[3] * 0.0174532925;
  deps_1980 = rtDW.orbit_tle[6] * 0.0174532925;
  M_o = rtDW.orbit_tle[7] * 0.0174532925;
  n_o = rtDW.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtDW.orbit_tle[5] >= 1.0) || (rtDW.orbit_tle[5] <= 0.0)) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag = 1U;
  } else if (n_o == 0.0) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag = 2U;
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
      rtb_flag = 3U;
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
      rtb_flag = 4U;
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
        rtb_flag = 5U;
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
          rtb_flag = 6U;
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

  /* End of MATLAB Function: '<S171>/MATLAB Function' */

  /* MATLAB Function: '<S261>/MATLAB Function' */
  rtb_M2KM_0[1] = 0.0;
  dpsi_1980 = cos(-epsb_1980);
  rtb_M2KM_0[4] = dpsi_1980;
  epsb_1980 = sin(-epsb_1980);
  rtb_M2KM_0[7] = epsb_1980;
  rtb_M2KM_0[2] = 0.0;
  rtb_M2KM_0[5] = -epsb_1980;
  rtb_M2KM_0[8] = dpsi_1980;
  deps_1980 = cos(M_sun);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(M_sun);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  rtb_M2KM_0[0] = 1.0;
  rtb_MathFunction1_fo[2] = 0.0;
  rtb_M2KM_0[3] = 0.0;
  rtb_MathFunction1_fo[5] = 0.0;
  rtb_M2KM_0[6] = 0.0;
  rtb_MathFunction1_fo[8] = 1.0;
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    for (i = 0; i < 3; i++) {
      iter = rtb_Compare_h + 3 * i;
      rtb_M2KM_1[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + rtb_Compare_h;
      rtb_M2KM_1[iter] = rtb_M2KM_1[rtb_mod_to_gcrf_tmp] + rtb_MathFunction1_fo
        [3 * i] * rtb_M2KM_0[rtb_Compare_h];
      rtb_M2KM_1[iter] = rtb_MathFunction1_fo[3 * i + 1] *
        rtb_M2KM_0[rtb_Compare_h + 3] + rtb_M2KM_1[rtb_mod_to_gcrf_tmp];
      rtb_M2KM_1[iter] = rtb_MathFunction1_fo[3 * i + 2] *
        rtb_M2KM_0[rtb_Compare_h + 6] + rtb_M2KM_1[rtb_mod_to_gcrf_tmp];
    }

    rtb_M2KM_2[3 * rtb_Compare_h] = rtb_M2KM[rtb_Compare_h];
  }

  rtb_M2KM_2[1] = 0.0;
  dpsi_1980 = cos(M_moon);
  rtb_M2KM_2[4] = dpsi_1980;
  epsb_1980 = sin(M_moon);
  rtb_M2KM_2[7] = epsb_1980;
  rtb_M2KM_2[2] = 0.0;
  rtb_M2KM_2[5] = -epsb_1980;
  rtb_M2KM_2[8] = dpsi_1980;
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    for (i = 0; i < 3; i++) {
      iter = i + 3 * rtb_Compare_h;
      rtb_M2KM_0[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * rtb_Compare_h + i;
      rtb_M2KM_0[iter] = rtb_M2KM_0[rtb_mod_to_gcrf_tmp] + rtb_M2KM_2[3 *
        rtb_Compare_h] * rtb_M2KM_1[i];
      rtb_M2KM_0[iter] = rtb_M2KM_2[3 * rtb_Compare_h + 1] * rtb_M2KM_1[i + 3] +
        rtb_M2KM_0[rtb_mod_to_gcrf_tmp];
      rtb_M2KM_0[iter] = rtb_M2KM_2[3 * rtb_Compare_h + 2] * rtb_M2KM_1[i + 6] +
        rtb_M2KM_0[rtb_mod_to_gcrf_tmp];
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
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    for (i = 0; i < 3; i++) {
      iter = rtb_Compare_h + 3 * i;
      Gain_tmp[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + rtb_Compare_h;
      Gain_tmp[iter] = Gain_tmp[rtb_mod_to_gcrf_tmp] + rtb_M2KM_0[3 * i] *
        rtb_mod_to_gcrf[rtb_Compare_h];
      Gain_tmp[iter] = rtb_M2KM_0[3 * i + 1] * rtb_mod_to_gcrf[rtb_Compare_h + 3]
        + Gain_tmp[rtb_mod_to_gcrf_tmp];
      Gain_tmp[iter] = rtb_M2KM_0[3 * i + 2] * rtb_mod_to_gcrf[rtb_Compare_h + 6]
        + Gain_tmp[rtb_mod_to_gcrf_tmp];
    }

    rtb_MathFunction1_fo[2 + 3 * rtb_Compare_h] =
      rtb_MatrixMultiply[rtb_Compare_h];
  }

  /* MATLAB Function: '<S172>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S173>/MATLAB Function3'
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
    /* Product: '<S171>/Product' */
    Gain_tmp_0[i] = 0.0;
    for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
      /* MATLAB Function: '<S261>/MATLAB Function' incorporates:
       *  Product: '<S171>/Product'
       */
      iter = i + 3 * rtb_Compare_h;
      rtb_M2KM_0[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * rtb_Compare_h + i;
      rtb_M2KM_0[iter] = rtb_M2KM_0[rtb_mod_to_gcrf_tmp] + rtb_MathFunction1_fo
        [3 * rtb_Compare_h] * Gain_tmp[i];
      rtb_M2KM_0[iter] = rtb_MathFunction1_fo[3 * rtb_Compare_h + 1] *
        Gain_tmp[i + 3] + rtb_M2KM_0[rtb_mod_to_gcrf_tmp];
      rtb_M2KM_0[iter] = rtb_MathFunction1_fo[3 * rtb_Compare_h + 2] *
        Gain_tmp[i + 6] + rtb_M2KM_0[rtb_mod_to_gcrf_tmp];

      /* Product: '<S171>/Product' */
      Gain_tmp_0[i] += rtb_M2KM_0[rtb_mod_to_gcrf_tmp] *
        rtb_pos_teme_km[rtb_Compare_h];
    }

    /* Gain: '<S171>/Gain' */
    rtDW.Gain[i] = 1000.0 * Gain_tmp_0[i];

    /* Gain: '<S6>/M2KM' */
    rtb_M2KM[i] = 0.001 * rtDW.Gain[i];

    /* Product: '<S172>/Product' */
    rtb_mod_to_gcrf_0[i] = rtb_mod_to_gcrf[i + 6] * eps + (rtb_mod_to_gcrf[i + 3]
      * epsb_1980 + rtb_mod_to_gcrf[i] * M_sun);
  }

  /* Gain: '<S172>/AU2KM' */
  epsb_1980_tmp = 1.49598073E+8 * rtb_mod_to_gcrf_0[0];

  /* Sum: '<S172>/Subtract' */
  eps = epsb_1980_tmp - rtb_M2KM[0];

  /* Math: '<S257>/Math Function' */
  rtb_MathFunction[0] = eps * eps;

  /* Gain: '<S172>/AU2KM' */
  rtb_pos_teme_km[0] = epsb_1980_tmp;

  /* Sum: '<S172>/Subtract' */
  rtb_Subtract_f[0] = eps;

  /* Gain: '<S172>/AU2KM' */
  epsb_1980_tmp = 1.49598073E+8 * rtb_mod_to_gcrf_0[1];

  /* Sum: '<S172>/Subtract' */
  eps = epsb_1980_tmp - rtb_M2KM[1];

  /* Math: '<S257>/Math Function' */
  rtb_MathFunction[1] = eps * eps;

  /* Gain: '<S172>/AU2KM' */
  rtb_pos_teme_km[1] = epsb_1980_tmp;

  /* Sum: '<S172>/Subtract' */
  rtb_Subtract_f[1] = eps;

  /* Gain: '<S172>/AU2KM' */
  epsb_1980_tmp = 1.49598073E+8 * rtb_mod_to_gcrf_0[2];

  /* Sum: '<S172>/Subtract' */
  eps = epsb_1980_tmp - rtb_M2KM[2];

  /* Sum: '<S257>/Sum of Elements' incorporates:
   *  Math: '<S257>/Math Function'
   */
  api = (rtb_MathFunction[0] + rtb_MathFunction[1]) + eps * eps;

  /* Math: '<S257>/Math Function1'
   *
   * About '<S257>/Math Function1':
   *  Operator: sqrt
   */
  if (api < 0.0) {
    api = -sqrt(fabs(api));
  } else {
    api = sqrt(api);
  }

  /* End of Math: '<S257>/Math Function1' */

  /* Switch: '<S257>/Switch' incorporates:
   *  Constant: '<S257>/Constant'
   *  Product: '<S257>/Product'
   */
  if (api > 0.0) {
    rtb_Switch_dq[0] = rtb_Subtract_f[0];
    rtb_Switch_dq[1] = rtb_Subtract_f[1];
    rtb_Switch_dq[2] = eps;
    rtb_Switch_dq[3] = api;
  } else {
    rtb_Switch_dq[0] = rtb_Subtract_f[0] * 0.0;
    rtb_Switch_dq[1] = rtb_Subtract_f[1] * 0.0;
    rtb_Switch_dq[2] = eps * 0.0;
    rtb_Switch_dq[3] = 1.0;
  }

  /* End of Switch: '<S257>/Switch' */

  /* Reshape: '<S2>/Reshape4' */
  rtDW.Reshape4 = rtDW.RateTransition5_i;

  /* MATLAB Function: '<S261>/MATLAB Function' */
  deps_1980 = cos(O_moon);
  rtb_MathFunction1_fo[0] = deps_1980;
  D_sun = sin(O_moon);
  rtb_MathFunction1_fo[3] = D_sun;
  rtb_MathFunction1_fo[6] = 0.0;
  rtb_MathFunction1_fo[1] = -D_sun;
  rtb_MathFunction1_fo[4] = deps_1980;
  rtb_MathFunction1_fo[7] = 0.0;
  for (i = 0; i < 3; i++) {
    /* Product: '<S257>/Divide' */
    rtDW.w_err_radps[i] = rtb_Switch_dq[i] / rtb_Switch_dq[3];

    /* MATLAB Function: '<S261>/MATLAB Function' */
    rtb_MathFunction1_fo[2 + 3 * i] = rtb_MatrixMultiply[i];

    /* Product: '<S170>/MatrixMultiply' */
    rtb_MatrixMultiply[i] = 0.0;
    for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
      /* Math: '<S173>/Transpose' incorporates:
       *  MATLAB Function: '<S261>/MATLAB Function'
       *  Product: '<S170>/MatrixMultiply'
       */
      iter = i + 3 * rtb_Compare_h;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * rtb_Compare_h + i;
      rtb_mod_to_gcrf[iter] = rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] +
        rtb_MathFunction1_fo[3 * i] * Gain_tmp[rtb_Compare_h];
      rtb_mod_to_gcrf[iter] = rtb_MathFunction1_fo[3 * i + 1] *
        Gain_tmp[rtb_Compare_h + 3] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];
      rtb_mod_to_gcrf[iter] = rtb_MathFunction1_fo[3 * i + 2] *
        Gain_tmp[rtb_Compare_h + 6] + rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp];

      /* Product: '<S170>/MatrixMultiply' */
      rtb_MatrixMultiply[i] += rtb_mod_to_gcrf[rtb_mod_to_gcrf_tmp] *
        rtDW.Gain[rtb_Compare_h];
    }
  }

  /* Sqrt: '<S245>/sqrt' incorporates:
   *  Product: '<S245>/Product2'
   *  Product: '<S245>/Product3'
   *  Sum: '<S245>/Sum2'
   */
  epsb_1980 = sqrt(rtb_MatrixMultiply[0] * rtb_MatrixMultiply[0] +
                   rtb_MatrixMultiply[1] * rtb_MatrixMultiply[1]);

  /* Outputs for Iterator SubSystem: '<S230>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S247>/While Iterator'
   */
  s247_iter = 1;
  do {
    api = rtDW.Memory_PreviousInput;
    if (s247_iter <= 0) {
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
    s247_iter++;
  } while ((api != eps) && (s247_iter <= 5));

  /* End of Outputs for SubSystem: '<S230>/While Iterator Subsystem' */

  /* UnitConversion: '<S244>/Unit Conversion' incorporates:
   *  Trigonometry: '<S230>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  M_moon *= 57.295779513082323;
  eqe_1980 = 57.295779513082323 * rt_atan2d_snf(rtb_MatrixMultiply[1],
    rtb_MatrixMultiply[0]);

  /* UnitConversion: '<S242>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  deps_1980 = 0.017453292519943295 * M_moon;

  /* Trigonometry: '<S229>/sincos' */
  eps = cos(deps_1980);

  /* UnitConversion: '<S242>/Unit Conversion' incorporates:
   *  Trigonometry: '<S229>/sincos'
   */
  dpsi_1980 = sin(deps_1980);
  deps_1980 = 0.017453292519943295 * eqe_1980;

  /* Trigonometry: '<S229>/sincos' */
  O_moon = cos(deps_1980);
  deps_1980 = sin(deps_1980);

  /* UnaryMinus: '<S233>/Unary Minus' incorporates:
   *  Product: '<S233>/u(1)*u(4)'
   */
  rtb_MathFunction1_i[0] = -(dpsi_1980 * O_moon);

  /* UnaryMinus: '<S236>/Unary Minus' */
  rtb_MathFunction1_i[1] = -deps_1980;

  /* UnaryMinus: '<S239>/Unary Minus' incorporates:
   *  Product: '<S239>/u(3)*u(4)'
   */
  rtb_MathFunction1_i[2] = -(eps * O_moon);

  /* UnaryMinus: '<S234>/Unary Minus' incorporates:
   *  Product: '<S234>/u(1)*u(2)'
   */
  rtb_MathFunction1_i[3] = -(dpsi_1980 * deps_1980);

  /* SignalConversion: '<S243>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_MathFunction1_i[4] = O_moon;

  /* UnaryMinus: '<S240>/Unary Minus' incorporates:
   *  Product: '<S240>/u(2)*u(3)'
   */
  rtb_MathFunction1_i[5] = -(deps_1980 * eps);

  /* SignalConversion: '<S243>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_i[6] = eps;

  /* SignalConversion: '<S243>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S238>/Constant'
   */
  rtb_MathFunction1_i[7] = 0.0;

  /* UnaryMinus: '<S241>/Unary Minus' */
  rtb_MathFunction1_i[8] = -dpsi_1980;

  /* Math: '<S170>/Transpose' */
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    rtb_MathFunction1_fo[3 * rtb_Compare_h] = rtb_MathFunction1_i[rtb_Compare_h];
    rtb_MathFunction1_fo[1 + 3 * rtb_Compare_h] =
      rtb_MathFunction1_i[rtb_Compare_h + 3];
    rtb_MathFunction1_fo[2 + 3 * rtb_Compare_h] =
      rtb_MathFunction1_i[rtb_Compare_h + 6];
  }

  memcpy(&rtb_MathFunction1_i[0], &rtb_MathFunction1_fo[0], 9U * sizeof(real_T));

  /* End of Math: '<S170>/Transpose' */

  /* Product: '<S246>/Product2' */
  api = M_sun * 0.00669437999014133;

  /* Product: '<S246>/Product3' incorporates:
   *  Constant: '<S246>/Constant1'
   *  Constant: '<S246>/f'
   *  Product: '<S246>/Product1'
   *  Sqrt: '<S246>/sqrt'
   *  Sum: '<S246>/Sum'
   */
  eps = 6.378137E+6 / sqrt(1.0 - api * M_sun);

  /* Product: '<S246>/Product4' */
  api *= eps;

  /* Sum: '<S246>/Sum2' */
  api += rtb_MatrixMultiply[2];

  /* Sum: '<S246>/Sum3' incorporates:
   *  Product: '<S246>/Product5'
   *  Product: '<S246>/Product6'
   */
  epsb_1980 = (M_sun * api - eps) + D_sun * epsb_1980;

  /* MATLAB Function: '<S170>/MATLAB Function' */
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

  /* End of MATLAB Function: '<S170>/MATLAB Function' */

  /* MATLAB Function: '<S232>/MATLAB Function' */
  eps = 0.017453292519943295 * M_moon;
  M_moon = 0.017453292519943295 * eqe_1980;
  dpsi_1980 = sin(eps);
  memset(&sp[0], 0, 13U * sizeof(real_T));
  memset(&cp[0], 0, 13U * sizeof(real_T));
  sp[1] = sin(M_moon);
  cp[0] = 1.0;
  cp[1] = cos(M_moon);
  iter = 3;
  for (rtb_Compare_h = 0; rtb_Compare_h < 11; rtb_Compare_h++) {
    iter = 3 + rtb_Compare_h;
    M_sun = cp[rtb_Compare_h + 1];
    sp[rtb_Compare_h + 2] = M_sun * sp[1] + sp[rtb_Compare_h + 1] * cp[1];
    cp[rtb_Compare_h + 2] = M_sun * cp[1] - sp[rtb_Compare_h + 1] * sp[1];
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
  rtb_Compare_h = 2;
  for (i = 0; i < 12; i++) {
    rtb_Compare_h = 2 + i;
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

  n_o = rtb_Compare_h - iter;
  factorial_DisWLItj(&n_o);
  dpsi_1980 = rtb_Compare_h + iter;
  factorial_DisWLItj(&dpsi_1980);
  P_0[rtb_Compare_h + 14 * iter] *= sqrt(2.0 * n_o / dpsi_1980) * rt_powd_snf
    (-1.0, (real_T)iter);
  dpsi_1980 = 0.0;
  tsince_JD = 0.0;
  u_moon = 0.0;
  for (iter = 0; iter < 12; iter++) {
    M_sun *= M_moon;
    for (rtb_Compare_h = 0; rtb_Compare_h <= iter + 1; rtb_Compare_h++) {
      i = 12 * rtb_Compare_h + iter;
      D_sun = dg[i] * (api - 2015.0) + g[i];
      deps_1980 = dh[i] * (api - 2015.0) + h[i];
      i = 14 * rtb_Compare_h + iter;
      n_o = P_0[i + 1];
      M_o = D_sun * cp[rtb_Compare_h] + deps_1980 * sp[rtb_Compare_h];
      dpsi_1980 -= (((1.0 + (real_T)iter) + 1.0) * eqe_1980 * n_o - sqrt((iter +
        2) * (iter + 2) - rtb_Compare_h * rtb_Compare_h) * O_moon * P_0[i + 2]) *
        (M_o * M_sun);
      tsince_JD += (D_sun * sp[rtb_Compare_h] - deps_1980 * cp[rtb_Compare_h]) *
        (M_sun * (real_T)rtb_Compare_h) * n_o;
      u_moon -= ((1.0 + (real_T)iter) + 1.0) * M_sun * M_o * n_o;
    }
  }

  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    /* Math: '<S170>/Transpose1' incorporates:
     *  Math: '<S169>/Math Function1'
     */
    Gain_tmp[3 * rtb_Compare_h] = rtb_mod_to_gcrf[rtb_Compare_h];
    Gain_tmp[1 + 3 * rtb_Compare_h] = rtb_mod_to_gcrf[rtb_Compare_h + 3];
    Gain_tmp[2 + 3 * rtb_Compare_h] = rtb_mod_to_gcrf[rtb_Compare_h + 6];
  }

  /* MATLAB Function: '<S232>/MATLAB Function' */
  n_o = epsb_1980 - eps;
  M_o = sin(n_o);
  n_o = cos(n_o);
  rtb_MatrixMultiply[0] = n_o * dpsi_1980 - M_o * u_moon;
  rtb_MatrixMultiply[1] = O_moon * tsince_JD;
  rtb_MatrixMultiply[2] = M_o * dpsi_1980 + n_o * u_moon;

  /* Trigonometry: '<S12>/Tan1' incorporates:
   *  Gain: '<S12>/deg2rad'
   */
  eps = tan(0.017453292519943295 * rtDW.RateTransition2[0]);

  /* Trigonometry: '<S12>/Tan' incorporates:
   *  Gain: '<S12>/deg2rad'
   */
  M_sun = tan(0.017453292519943295 * rtDW.RateTransition2[1]);

  /* Sqrt: '<S14>/Sqrt' incorporates:
   *  Constant: '<S14>/Constant'
   *  Math: '<S14>/Math Function'
   *  Math: '<S14>/Math Function1'
   *  Math: '<S14>/Math Function2'
   *  Sum: '<S14>/Sum'
   *
   * About '<S14>/Math Function2':
   *  Operator: reciprocal
   */
  api = sqrt(1.0 / ((eps * eps + 1.0) + M_sun * M_sun));

  /* SignalConversion: '<S12>/TmpSignal ConversionAtss_2_bodyInport2' incorporates:
   *  Product: '<S12>/Matrix Multiply'
   *  Product: '<S12>/Matrix Multiply1'
   */
  rtb_Subtract_f[0] = eps * api;
  rtb_Subtract_f[1] = api * M_sun;
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    /* Product: '<S170>/Matrix Multiply1' */
    Gain_tmp_0[rtb_Compare_h] = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S170>/Matrix Multiply' incorporates:
       *  Math: '<S170>/Transpose1'
       *  Product: '<S170>/Matrix Multiply1'
       */
      iter = rtb_Compare_h + 3 * i;
      rtb_M2KM_0[iter] = 0.0;
      rtb_mod_to_gcrf_tmp = 3 * i + rtb_Compare_h;
      rtb_M2KM_0[iter] = rtb_M2KM_0[rtb_mod_to_gcrf_tmp] + rtb_MathFunction1_i[3
        * i] * Gain_tmp[rtb_Compare_h];
      rtb_M2KM_0[iter] = rtb_MathFunction1_i[3 * i + 1] * Gain_tmp[rtb_Compare_h
        + 3] + rtb_M2KM_0[rtb_mod_to_gcrf_tmp];
      rtb_M2KM_0[iter] = rtb_MathFunction1_i[3 * i + 2] * Gain_tmp[rtb_Compare_h
        + 6] + rtb_M2KM_0[rtb_mod_to_gcrf_tmp];

      /* Product: '<S170>/Matrix Multiply1' */
      Gain_tmp_0[rtb_Compare_h] += rtb_M2KM_0[rtb_mod_to_gcrf_tmp] *
        rtb_MatrixMultiply[i];
    }

    /* Gain: '<S170>/nT2T' */
    rtb_MathFunction[rtb_Compare_h] = 1.0E-9 * Gain_tmp_0[rtb_Compare_h];

    /* Product: '<S12>/ss_2_body' incorporates:
     *  Constant: '<S12>/Constant1'
     *  SignalConversion: '<S12>/TmpSignal ConversionAtss_2_bodyInport2'
     */
    rtDW.ss_2_body[rtb_Compare_h] = 0.0;
    rtDW.ss_2_body[rtb_Compare_h] += rtCP_Constant1_Value_h[rtb_Compare_h] *
      rtb_Subtract_f[0];
    rtDW.ss_2_body[rtb_Compare_h] += rtCP_Constant1_Value_h[rtb_Compare_h + 3] *
      rtb_Subtract_f[1];
    rtDW.ss_2_body[rtb_Compare_h] += rtCP_Constant1_Value_h[rtb_Compare_h + 6] *
      api;
  }

  /* Reshape: '<S2>/Reshape3' incorporates:
   *  S-Function (sdspperm2): '<S2>/Variable Selector1'
   */
  rtb_Reshape3[0] = rtDW.RateTransition3[0];
  rtb_Reshape3[1] = rtDW.RateTransition3[1];
  rtb_Reshape3[2] = rtDW.RateTransition3[2];

  /* S-Function (sdspperm2): '<S2>/Variable Selector' */
  rtb_Subtract_f[0] = rtDW.RateTransition4[0];
  rtb_Subtract_f[1] = rtDW.RateTransition4[1];
  rtb_Subtract_f[2] = rtDW.RateTransition4[2];

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  /* Reshape: '<S2>/Reshape2' incorporates:
   *  S-Function (sdspperm2): '<S2>/Variable Selector2'
   *  S-Function (sdspperm2): '<S2>/Variable Selector3'
   */
  MEKF_lib(rtDW.w_err_radps, rtb_MathFunction, rtDW.ss_2_body, rtb_Reshape3,
           rtb_Subtract_f, rtDW.Reshape4, rtDW.RateTransition6_b[0],
           rtDW.RateTransition7[0], rtDW.triad_override, rtDW.qmerge, rtDW.Sum,
           rtb_YMDHMS_UTC, rtb_MatrixMultiply, &rtb_Merge_i, &rtDW.MEKF_lib_g);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* Product: '<S169>/Product3' incorporates:
   *  Math: '<S169>/Math Function1'
   */
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    rtb_MathFunction[rtb_Compare_h] = Gain_tmp[rtb_Compare_h + 6] * rtDW.Gain[2]
      + (Gain_tmp[rtb_Compare_h + 3] * rtDW.Gain[1] + Gain_tmp[rtb_Compare_h] *
         rtDW.Gain[0]);
  }

  /* End of Product: '<S169>/Product3' */

  /* Switch: '<S213>/Switch' incorporates:
   *  Abs: '<S213>/Abs'
   *  Bias: '<S213>/Bias'
   *  Bias: '<S213>/Bias1'
   *  Constant: '<S213>/Constant2'
   *  Constant: '<S214>/Constant'
   *  Math: '<S213>/Math Function1'
   *  RelationalOperator: '<S214>/Compare'
   */
  if (fabs(rtDW.target_latlonalt[0]) > 180.0) {
    eps = rt_modd_snf(rtDW.target_latlonalt[0] + 180.0, 360.0) + -180.0;
  } else {
    eps = rtDW.target_latlonalt[0];
  }

  /* End of Switch: '<S213>/Switch' */

  /* Abs: '<S210>/Abs1' */
  api = fabs(eps);

  /* RelationalOperator: '<S212>/Compare' incorporates:
   *  Constant: '<S212>/Constant'
   */
  rtb_Compare_e = (api > 90.0);

  /* Switch: '<S210>/Switch' incorporates:
   *  Bias: '<S210>/Bias'
   *  Bias: '<S210>/Bias1'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S180>/Constant1'
   *  Gain: '<S210>/Gain'
   *  Product: '<S210>/Divide1'
   *  Switch: '<S180>/Switch1'
   */
  if (rtb_Compare_e) {
    /* Signum: '<S210>/Sign1' */
    if (eps < 0.0) {
      eps = -1.0;
    } else if (eps > 0.0) {
      eps = 1.0;
    } else if (eps == 0.0) {
      eps = 0.0;
    } else {
      eps = (rtNaN);
    }

    /* End of Signum: '<S210>/Sign1' */
    eps *= -(api + -90.0) + 90.0;
    rtb_Compare_h = 180;
  } else {
    rtb_Compare_h = 0;
  }

  /* End of Switch: '<S210>/Switch' */

  /* UnitConversion: '<S204>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  M_sun = 0.017453292519943295 * eps;

  /* Product: '<S179>/Product3' incorporates:
   *  Constant: '<S174>/Constant2'
   *  Trigonometry: '<S179>/sincos1'
   */
  dpsi_1980 = 0.0 * sin(M_sun);
  D_sun = 0.0 * cos(M_sun);

  /* Trigonometry: '<S179>/Trigonometric Function2' incorporates:
   *  Constant: '<S179>/f'
   *  Product: '<S179>/Product2'
   *  Trigonometry: '<S179>/Trigonometric Function1'
   */
  api = rt_atan2d_snf(tan(M_sun) * 0.99664718933525254 * 0.99664718933525254,
                      1.0);

  /* Trigonometry: '<S208>/Trigonometric Function' incorporates:
   *  UnitConversion: '<S205>/Unit Conversion'
   *  UnitConversion: '<S209>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  M_sun = sin(57.295779513082323 * api * 0.017453292519943295);

  /* Sqrt: '<S208>/sqrt' incorporates:
   *  Constant: '<S208>/Constant'
   *  Constant: '<S208>/Re'
   *  Product: '<S208>/Product2'
   *  Product: '<S208>/Product3'
   *  Sum: '<S208>/Sum2'
   */
  M_sun = sqrt(4.0680631590769E+13 / (M_sun * M_sun * 0.006739496742276474 + 1.0));

  /* Trigonometry: '<S179>/sincos' */
  epsb_1980 = cos(api);
  api = sin(api);

  /* Sum: '<S179>/Sum1' incorporates:
   *  Product: '<S179>/Product1'
   */
  dpsi_1980 += M_sun * api;

  /* UnitConversion: '<S206>/Unit Conversion' incorporates:
   *  Product: '<S179>/Product1'
   *  Sum: '<S179>/Sum1'
   *  Trigonometry: '<S179>/Trigonometric Function3'
   *  Trigonometry: '<S179>/sincos'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  api = rt_atan2d_snf(dpsi_1980, M_sun * epsb_1980 + D_sun) * 57.295779513082323;

  /* Sum: '<S180>/Sum' */
  M_sun = (real_T)rtb_Compare_h + rtDW.target_latlonalt[1];

  /* Switch: '<S211>/Switch' incorporates:
   *  Abs: '<S211>/Abs'
   *  Bias: '<S211>/Bias'
   *  Bias: '<S211>/Bias1'
   *  Constant: '<S211>/Constant2'
   *  Constant: '<S215>/Constant'
   *  Math: '<S211>/Math Function1'
   *  RelationalOperator: '<S215>/Compare'
   */
  if (fabs(M_sun) > 180.0) {
    M_sun = rt_modd_snf(M_sun + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S211>/Switch' */

  /* UnitConversion: '<S202>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  dpsi_1980 = 0.017453292519943295 * api;
  D_sun = 0.017453292519943295 * M_sun;

  /* Trigonometry: '<S178>/sincos' */
  M_moon = cos(dpsi_1980);
  dpsi_1980 = sin(dpsi_1980);
  epsb_1980 = cos(D_sun);
  D_sun = sin(D_sun);

  /* UnaryMinus: '<S193>/Unary Minus' incorporates:
   *  Product: '<S193>/u(1)*u(4)'
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[0] = -(dpsi_1980 * epsb_1980);

  /* UnaryMinus: '<S196>/Unary Minus' incorporates:
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[1] = -D_sun;

  /* UnaryMinus: '<S199>/Unary Minus' incorporates:
   *  Product: '<S199>/u(3)*u(4)'
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[2] = -(M_moon * epsb_1980);

  /* UnaryMinus: '<S194>/Unary Minus' incorporates:
   *  Product: '<S194>/u(1)*u(2)'
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[3] = -(dpsi_1980 * D_sun);

  /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[4] = epsb_1980;

  /* UnaryMinus: '<S200>/Unary Minus' incorporates:
   *  Product: '<S200>/u(2)*u(3)'
   *  Trigonometry: '<S178>/sincos'
   */
  rtb_MathFunction1_m[5] = -(D_sun * M_moon);

  /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_m[6] = M_moon;

  /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S198>/Constant'
   */
  rtb_MathFunction1_m[7] = 0.0;

  /* UnaryMinus: '<S201>/Unary Minus' */
  rtb_MathFunction1_m[8] = -dpsi_1980;

  /* Math: '<S174>/Math Function1' */
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    rtb_MathFunction1_i[3 * rtb_Compare_h] = rtb_MathFunction1_m[rtb_Compare_h];
    rtb_MathFunction1_i[1 + 3 * rtb_Compare_h] =
      rtb_MathFunction1_m[rtb_Compare_h + 3];
    rtb_MathFunction1_i[2 + 3 * rtb_Compare_h] =
      rtb_MathFunction1_m[rtb_Compare_h + 6];
  }

  memcpy(&rtb_MathFunction1_m[0], &rtb_MathFunction1_i[0], 9U * sizeof(real_T));

  /* End of Math: '<S174>/Math Function1' */

  /* UnitConversion: '<S216>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  api *= 0.017453292519943295;

  /* Trigonometry: '<S181>/Trigonometric Function' */
  api = sin(api);

  /* UnitConversion: '<S191>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  dpsi_1980 = 0.017453292519943295 * eps;
  D_sun = 0.017453292519943295 * M_sun;

  /* Trigonometry: '<S177>/sincos' */
  eps = cos(dpsi_1980);
  dpsi_1980 = sin(dpsi_1980);
  O_moon = cos(D_sun);
  deps_1980 = sin(D_sun);

  /* UnaryMinus: '<S182>/Unary Minus' incorporates:
   *  Product: '<S182>/u(1)*u(4)'
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[0] = -(dpsi_1980 * O_moon);

  /* UnaryMinus: '<S185>/Unary Minus' incorporates:
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[1] = -deps_1980;

  /* UnaryMinus: '<S188>/Unary Minus' incorporates:
   *  Product: '<S188>/u(3)*u(4)'
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[2] = -(eps * O_moon);

  /* UnaryMinus: '<S183>/Unary Minus' incorporates:
   *  Product: '<S183>/u(1)*u(2)'
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[3] = -(dpsi_1980 * deps_1980);

  /* SignalConversion: '<S192>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[4] = O_moon;

  /* UnaryMinus: '<S189>/Unary Minus' incorporates:
   *  Product: '<S189>/u(2)*u(3)'
   *  Trigonometry: '<S177>/sincos'
   */
  rtb_MathFunction_b[5] = -(deps_1980 * eps);

  /* SignalConversion: '<S192>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction_b[6] = eps;

  /* SignalConversion: '<S192>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S187>/Constant'
   */
  rtb_MathFunction_b[7] = 0.0;

  /* UnaryMinus: '<S190>/Unary Minus' */
  rtb_MathFunction_b[8] = -dpsi_1980;

  /* Math: '<S174>/Math Function' */
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    rtb_MathFunction1_i[3 * rtb_Compare_h] = rtb_MathFunction_b[rtb_Compare_h];
    rtb_MathFunction1_i[1 + 3 * rtb_Compare_h] =
      rtb_MathFunction_b[rtb_Compare_h + 3];
    rtb_MathFunction1_i[2 + 3 * rtb_Compare_h] =
      rtb_MathFunction_b[rtb_Compare_h + 6];
  }

  memcpy(&rtb_MathFunction_b[0], &rtb_MathFunction1_i[0], 9U * sizeof(real_T));

  /* End of Math: '<S174>/Math Function' */

  /* SignalConversion: '<S174>/TmpSignal ConversionAtProductInport2' incorporates:
   *  Constant: '<S174>/Constant1'
   *  UnaryMinus: '<S174>/Unary Minus1'
   */
  rtb_Subtract_f[0] = 0.0;
  rtb_Subtract_f[1] = 0.0;
  rtb_Subtract_f[2] = -rtDW.target_latlonalt[2];

  /* Sqrt: '<S181>/sqrt' incorporates:
   *  Constant: '<S181>/Constant'
   *  Constant: '<S181>/Re'
   *  Product: '<S181>/Product2'
   *  Product: '<S181>/Product3'
   *  Sum: '<S181>/Sum2'
   */
  deps_1980 = sqrt(4.0680631590769E+13 / (api * api * 0.006739496742276474 + 1.0));
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    /* Sum: '<S174>/Sum' incorporates:
     *  Product: '<S174>/Product'
     *  Product: '<S174>/Product1'
     *  Sqrt: '<S181>/sqrt'
     *  UnaryMinus: '<S174>/Unary Minus'
     */
    rtb_Reshape3[rtb_Compare_h] = (rtb_MathFunction1_m[rtb_Compare_h + 6] *
      -deps_1980 + (rtb_MathFunction1_m[rtb_Compare_h + 3] * 0.0 +
                    rtb_MathFunction1_m[rtb_Compare_h] * 0.0)) +
      (rtb_MathFunction_b[rtb_Compare_h + 6] * rtb_Subtract_f[2] +
       (rtb_MathFunction_b[rtb_Compare_h + 3] * 0.0 +
        rtb_MathFunction_b[rtb_Compare_h] * 0.0));
  }

  /* Outputs for Atomic SubSystem: '<S169>/target_groundpass_lib1' */
  target_groundpass_lib1(rtb_MathFunction, rtb_Reshape3, rtDW.target_latlonalt[0],
    rtDW.target_latlonalt[1], &rtb_Compare_e, &api, rtb_Subtract_f);

  /* End of Outputs for SubSystem: '<S169>/target_groundpass_lib1' */

  /* MATLAB Function: '<S258>/MATLAB Function' */
  lowAlt = false;
  epsb_1980 = norm_2e9Xj4lM(rtb_M2KM);
  eps = rtb_pos_teme_km[0] * 1.49598073E+8;
  dpsi_1980 = rtb_M2KM[0] * eps;
  rtb_pos_teme_km[0] = eps;
  eps = rtb_pos_teme_km[1] * 1.49598073E+8;
  dpsi_1980 += rtb_M2KM[1] * eps;
  rtb_pos_teme_km[1] = eps;
  eps = epsb_1980_tmp * 1.49598073E+8;
  n_o = rtb_M2KM[2] * eps;
  dpsi_1980 += n_o;
  rtb_pos_teme_km[2] = eps;
  deps_1980 = norm_2e9Xj4lM(rtb_pos_teme_km);
  M_sun = (rtb_M2KM[0] * rtb_pos_teme_km[0] + rtb_M2KM[1] * rtb_pos_teme_km[1])
    + n_o;
  eps = (epsb_1980 * epsb_1980 - dpsi_1980) / ((epsb_1980 * epsb_1980 +
    deps_1980 * deps_1980) - M_sun * 2.0);
  if ((eps < 0.0) || (eps > 1.0)) {
    lowAlt = true;
  }

  if (M_sun * eps + (1.0 - eps) * (epsb_1980 * epsb_1980) >=
      4.0680631590768993E+7) {
    lowAlt = true;
  }

  lowAlt = !lowAlt;

  /* End of MATLAB Function: '<S258>/MATLAB Function' */

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  mode_select_lib(rtDW.telecom, lowAlt, rtDW.Reshape4, rtb_Compare_e, rtDW.Sum,
                  rtDW.MET_utc_s, rtDW.MET_soar_utc_s, rtDW.RateTransition1,
                  &rtDW.gnc_mode_b, &rtDW.mode_select_lib_k);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */

  /* Product: '<S169>/Product1' */
  for (rtb_Compare_h = 0; rtb_Compare_h < 3; rtb_Compare_h++) {
    rtDW.Product1[rtb_Compare_h] = 0.0;
    rtDW.Product1[rtb_Compare_h] += rtb_mod_to_gcrf[rtb_Compare_h] *
      rtb_Subtract_f[0];
    rtDW.Product1[rtb_Compare_h] += rtb_mod_to_gcrf[rtb_Compare_h + 3] *
      rtb_Subtract_f[1];
    rtDW.Product1[rtb_Compare_h] += rtb_mod_to_gcrf[rtb_Compare_h + 6] *
      rtb_Subtract_f[2];
  }

  /* End of Product: '<S169>/Product1' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  target_generation_lib();

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */

  /* Outputs for Atomic SubSystem: '<S5>/quat_err_lib' */
  quat_err_lib(rtDW.RateTransition6, rtDW.qmerge, rtb_DiscreteTimeIntegrator);

  /* End of Outputs for SubSystem: '<S5>/quat_err_lib' */

  /* MATLAB Function: '<S11>/MATLAB Function' */
  rtDW.sun_body_unit[0] = 0.0;
  rtDW.sun_body_unit[1] = 0.0;
  rtDW.sun_body_unit[2] = 0.0;
  for (iter = 0; iter < 6; iter++) {
    if (rtDW.RateTransition1_h[iter] > I_thresh_A[iter]) {
      rtDW.sun_body_unit[0] += (real_T)normals[3 * iter];
      rtDW.sun_body_unit[1] += (real_T)normals[3 * iter + 1];
      rtDW.sun_body_unit[2] += (real_T)normals[3 * iter + 2];
    }
  }

  rtb_pos_teme_km[0] = rtDW.sun_body_unit[0];
  rtb_pos_teme_km[1] = rtDW.sun_body_unit[1] - -1.0;
  rtb_pos_teme_km[2] = rtDW.sun_body_unit[2];
  if (norm_2e9Xj4lM(rtb_pos_teme_km) < 1.0E-8) {
    for (i = 0; i < 6; i++) {
      x[i] = rtDW.RateTransition1_h[i];
    }

    sort_E8F8dFL3(x, iidx);
    rtDW.sun_body_unit[0] += (real_T)normals[(iidx[4] - 1) * 3];
    rtDW.sun_body_unit[1] += (real_T)normals[(iidx[4] - 1) * 3 + 1];
    rtDW.sun_body_unit[2] += (real_T)normals[(iidx[4] - 1) * 3 + 2];
  }

  deps_1980 = norm_2e9Xj4lM(rtDW.sun_body_unit);
  if (deps_1980 < 1.0) {
    rtDW.sun_body_unit[0] = 0.0;
    rtDW.sun_body_unit[1] = 0.0;
    rtDW.sun_body_unit[2] = -1.0;
  } else {
    rtDW.sun_body_unit[0] /= deps_1980;
    rtDW.sun_body_unit[1] /= deps_1980;
    rtDW.sun_body_unit[2] /= deps_1980;
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* Sum: '<S5>/Sum1' */
  rtDW.w_err_radps[0] = rtDW.RateTransition2_h[0] - rtDW.Sum[0];
  rtDW.w_err_radps[1] = rtDW.RateTransition2_h[1] - rtDW.Sum[1];
  rtDW.w_err_radps[2] = rtDW.RateTransition2_h[2] - rtDW.Sum[2];

  /* SwitchCase: '<S123>/Switch Case' */
  switch (rtDW.gnc_mode_b) {
   case 0:
   case 1:
   case 2:
    /* Outputs for IfAction SubSystem: '<S123>/case_null_control' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    /* SignalConversion: '<S130>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = 0.0;

    /* SignalConversion: '<S130>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[0] = 0.0;

    /* SignalConversion: '<S130>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = 0.0;

    /* SignalConversion: '<S130>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[1] = 0.0;

    /* SignalConversion: '<S130>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = 0.0;

    /* SignalConversion: '<S130>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[2] = 0.0;

    /* End of Outputs for SubSystem: '<S123>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S123>/case_asm' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    /* SignalConversion: '<S128>/OutportBuffer_InsertedFor_asm_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S128>/asmController_lib' */
    asmController_lib();

    /* End of Outputs for SubSystem: '<S128>/asmController_lib' */
    /* End of Outputs for SubSystem: '<S123>/case_asm' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S123>/case_desat' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* SignalConversion: '<S129>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = rtConstB.null_control_lib_g.null_control_input[0];

    /* SignalConversion: '<S129>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[0] = rtConstB.null_control_lib_g.null_control_input[0];

    /* SignalConversion: '<S129>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = rtConstB.null_control_lib_g.null_control_input[1];

    /* SignalConversion: '<S129>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[1] = rtConstB.null_control_lib_g.null_control_input[1];

    /* SignalConversion: '<S129>/OutportBufferFordesat_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = rtConstB.null_control_lib_g.null_control_input[2];

    /* SignalConversion: '<S129>/OutportBufferFordesat_RWA_cmd_Nm' */
    rtDW.Merge[2] = rtConstB.null_control_lib_g.null_control_input[2];

    /* End of Outputs for SubSystem: '<S123>/case_desat' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S123>/case_sunseek' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    /* SignalConversion: '<S132>/OutportBuffer_InsertedFor_sunseek_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S132>/sunSeek_lib' */
    sunSeek_lib();

    /* End of Outputs for SubSystem: '<S132>/sunSeek_lib' */
    /* End of Outputs for SubSystem: '<S123>/case_sunseek' */
    break;

   case 6:
   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S123>/case_reorientation' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    /* SignalConversion: '<S131>/OutportBuffer_InsertedFor_tracking_MTQ_cmd_Am2_at_inport_0' */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* Outputs for Atomic SubSystem: '<S131>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_DiscreteTimeIntegrator, rtDW.w_err_radps, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S131>/PD_Controller_Lib' */
    /* End of Outputs for SubSystem: '<S123>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S123>/Switch Case' */

  /* Sum: '<S5>/Sum' */
  rtb_M2KM[0] = rtDW.Merge[0] + rtDW.RateTransition5[0];
  rtb_M2KM[1] = rtDW.Merge[1] + rtDW.RateTransition5[1];
  rtb_M2KM[2] = rtDW.Merge[2] + rtDW.RateTransition5[2];

  /* Outputs for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
  rwa_allocation_lib(rtb_M2KM, rtDW.RateTransition1, rtDW.RateTransition2_l,
                     rtb_Switch_dq, &rtDW.rwa_allocation_lib_o);

  /* End of Outputs for SubSystem: '<S5>/rwa_allocation_lib' */

  /* Outputs for Atomic SubSystem: '<S169>/target_groundpass_lib' */
  /* Constant: '<S169>/Constant' */
  target_groundpass_lib(rtb_MathFunction, rtCP_Constant_Value_jp,
                        &rtb_Compare_j5, &eps, rtb_M2KM,
                        &rtConstB.target_groundpass_lib_i);

  /* End of Outputs for SubSystem: '<S169>/target_groundpass_lib' */

  /* Gain: '<S127>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   *  Product: '<S127>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtb_Switch_dq[0];

  /* Saturate: '<S127>/Saturation' */
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

  /* Gain: '<S127>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   *  Product: '<S127>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtb_Switch_dq[1];

  /* Saturate: '<S127>/Saturation' */
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

  /* Gain: '<S127>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   *  Product: '<S127>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtb_Switch_dq[2];

  /* Saturate: '<S127>/Saturation' */
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

  /* Gain: '<S127>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   *  Product: '<S127>/Product'
   */
  epsb_1980 = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    9.5492965855137211;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += 0.25 * rtb_Switch_dq[3];

  /* Saturate: '<S127>/Saturation' */
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
  rtDW.RateTransition4_1_Buffer0 = rtDW.gnc_mode_b;
  rtDW.RateTransition4_2_Buffer0[0] = rtDW.qmerge[0];
  rtDW.RateTransition4_2_Buffer0[1] = rtDW.qmerge[1];
  rtDW.RateTransition4_2_Buffer0[2] = rtDW.qmerge[2];
  rtDW.RateTransition4_2_Buffer0[3] = rtDW.qmerge[3];
  rtDW.RateTransition4_3_Buffer0[0] = rtDW.Sum[0];
  rtDW.RateTransition4_3_Buffer0[1] = rtDW.Sum[1];
  rtDW.RateTransition4_3_Buffer0[2] = rtDW.Sum[2];
  rtDW.RateTransition4_4_Buffer0[0] = rtDW.RateTransition6[0];
  rtDW.RateTransition4_4_Buffer0[1] = rtDW.RateTransition6[1];
  rtDW.RateTransition4_4_Buffer0[2] = rtDW.RateTransition6[2];
  rtDW.RateTransition4_4_Buffer0[3] = rtDW.RateTransition6[3];
  rtDW.RateTransition4_5_Buffer0[0] = rtDW.RateTransition2_h[0];
  rtDW.RateTransition4_5_Buffer0[1] = rtDW.RateTransition2_h[1];
  rtDW.RateTransition4_5_Buffer0[2] = rtDW.RateTransition2_h[2];
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition4_6_Buffer0[i] = rtb_YMDHMS_UTC[i];
  }

  rtDW.RateTransition4_7_Buffer0[0] = rtb_MatrixMultiply[0];
  rtDW.RateTransition4_7_Buffer0[1] = rtb_MatrixMultiply[1];
  rtDW.RateTransition4_7_Buffer0[2] = rtb_MatrixMultiply[2];
  rtDW.RateTransition4_8_Buffer0 = rtb_Merge_i;
  rtDW.RateTransition4_9_Buffer0[0] = rtDW.Gain[0];
  rtDW.RateTransition4_9_Buffer0[1] = rtDW.Gain[1];
  rtDW.RateTransition4_9_Buffer0[2] = rtDW.Gain[2];

  /* Saturate: '<S124>/Saturation' */
  if (rtb_DiscreteTimeIntegrator[0] > 1.0) {
    epsb_1980 = 1.0;
  } else if (rtb_DiscreteTimeIntegrator[0] < -1.0) {
    epsb_1980 = -1.0;
  } else {
    epsb_1980 = rtb_DiscreteTimeIntegrator[0];
  }

  /* End of Saturate: '<S124>/Saturation' */

  /* Update for RateTransition: '<S1>/Rate Transition4' incorporates:
   *  Abs: '<S124>/Abs'
   *  BusCreator: '<S1>/BusConversion_InsertedFor_Bus Assignment1_at_inport_18'
   *  Gain: '<S124>/Gain'
   *  Gain: '<S124>/RAD2DEG'
   *  Trigonometry: '<S124>/Acos'
   */
  rtDW.RateTransition4_10_Buffer0 = fabs(2.0 * acos(epsb_1980) *
    57.295779513082323);
  rtDW.RateTransition4_11_Buffer0 = lowAlt;
  rtDW.RateTransition4_12_Buffer0 = rtb_flag;
  rtDW.RateTransition4_13_Buffer0 = rtb_Compare_j5;
  rtDW.RateTransition4_14_Buffer0 = rtb_Compare_e;
  rtDW.RateTransition4_15_Buffer0 = rtDW.RateTransition8;
  rtDW.RateTransition4_16_Buffer0 = eps;
  rtDW.RateTransition4_17_Buffer0 = api;
  memcpy(&rtDW.RateTransition4_18_Buffer0.opt_state[0], &rtDW.opt_state[0], 100U
         * sizeof(real_T));
  memcpy(&rtDW.RateTransition4_18_Buffer0.opt_ctrl_Nm[0], &rtDW.opt_ctrl_Nm[0],
         30U * sizeof(real_T));
  rtDW.RateTransition4_18_Buffer0.final_time_s = rtDW.final_time_s;
  memcpy(&rtDW.RateTransition4_18_Buffer0.exitcode[0], &rtDW.exitcode[0], 17U *
         sizeof(real_T));
  memcpy(&rtDW.RateTransition4_18_Buffer0.slv_time_s[0], &rtDW.slv_time_s[0],
         15U * sizeof(real_T));
  rtDW.RateTransition4_18_Buffer0.soar_count = rtDW.soar_count;
}

/* Model initialize function */
void FSW_Lib_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Start(&rtDW.MEKF_lib_g);

  /* End of Start for SubSystem: '<S1>/MEKF_lib' */
  rtPrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' */
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
