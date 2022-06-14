/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
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
#include "factorial_sZPOa6fO.h"
#include "jseconds2ymdhms_eXoGXxIT.h"
#include "mod_TpoWkbJk.h"
#include "norm_EzB1R8di.h"
#include "rt_atan2d_snf.h"
#include "rt_modd_snf.h"
#include "rt_powd_snf.h"
#include "rt_remd_snf.h"
#include "sort_Z8R2ikQI.h"

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/*
 * Output and update for action system:
 *    '<S230>/If Action Subsystem'
 *    '<S230>/If Action Subsystem3'
 */
void IfActionSubsystem(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S261>/Out1' incorporates:
   *  Constant: '<S261>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S230>/If Action Subsystem1'
 *    '<S230>/If Action Subsystem4'
 */
void IfActionSubsystem1(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S262>/Out1' incorporates:
   *  Constant: '<S262>/Constant'
   */
  *rty_Out1 = 2.0;
}

/*
 * Output and update for action system:
 *    '<S230>/If Action Subsystem2'
 *    '<S230>/If Action Subsystem5'
 */
void IfActionSubsystem2_p(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S263>/Out1' incorporates:
   *  Constant: '<S263>/Constant'
   */
  *rty_Out1 = 0.0;
}

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

  /* RateTransition: '<S2>/Rate Transition1' incorporates:
   *  Gain: '<S2>/deg2rad'
   *  Inport: '<Root>/gyro_gyro_radps'
   *  Inport: '<Root>/photodiodes_uA'
   *  RateTransition: '<S2>/Rate Transition4'
   */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    for (i = 0; i < 5; i++) {
      rtDW.RateTransition1_Buffer[i] = rtU.photodiodes_uA[i];
    }

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  Inport: '<Root>/photodiodes_uA'
     *  Inport: '<Root>/sun_meas_ss_deg'
     */
    rtDW.RateTransition2_Buffer[0] = rtU.sun_meas_ss_deg[0];
    rtDW.RateTransition2_Buffer[1] = rtU.sun_meas_ss_deg[1];

    /* RateTransition: '<S2>/Rate Transition3' incorporates:
     *  Inport: '<Root>/mag_mag_uT'
     */
    memcpy(&rtDW.RateTransition3_Buffer[0], &rtU.mag_mag_uT[0], 9U * sizeof
           (real_T));
    for (i = 0; i < 9; i++) {
      rtDW.RateTransition4_Buffer[i] = 0.017453292519943295 *
        rtU.gyro_gyro_radps[i];
    }

    /* RateTransition: '<S2>/Rate Transition5' incorporates:
     *  Gain: '<S2>/deg2rad'
     *  Inport: '<Root>/gyro_gyro_radps'
     *  Inport: '<Root>/sun_meas_valid'
     */
    rtDW.RateTransition5_Buffer = rtU.sun_meas_valid;

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/mag_meas_valid'
     */
    rtDW.RateTransition6_Buffer[0] = rtU.mag_meas_valid[0];
    rtDW.RateTransition6_Buffer[1] = rtU.mag_meas_valid[1];
    rtDW.RateTransition6_Buffer[2] = rtU.mag_meas_valid[2];

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/gyro_meas_valid'
     */
    rtDW.RateTransition7_Buffer[0] = rtU.gyro_meas_valid[0];
    rtDW.RateTransition7_Buffer[1] = rtU.gyro_meas_valid[1];
    rtDW.RateTransition7_Buffer[2] = rtU.gyro_meas_valid[2];

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/orbit_tle'
     */
    memcpy(&rtDW.RateTransition_1_Buffer[0], &rtU.orbit_tle[0], 9U * sizeof
           (real_T));

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/MET_utc_s'
     */
    rtDW.RateTransition_2_Buffer = rtU.MET_utc_s;

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/MET_soar_utc_s'
     */
    rtDW.RateTransition_3_Buffer = rtU.MET_soar_utc_s;

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/quat_soar_cmd'
     */
    rtDW.RateTransition_4_Buffer[0] = rtU.quat_soar_cmd[0];
    rtDW.RateTransition_4_Buffer[1] = rtU.quat_soar_cmd[1];
    rtDW.RateTransition_4_Buffer[2] = rtU.quat_soar_cmd[2];
    rtDW.RateTransition_4_Buffer[3] = rtU.quat_soar_cmd[3];

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/target_latlonalt'
     */
    rtDW.RateTransition_5_Buffer[0] = rtU.target_latlonalt[0];
    rtDW.RateTransition_5_Buffer[1] = rtU.target_latlonalt[1];
    rtDW.RateTransition_5_Buffer[2] = rtU.target_latlonalt[2];

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecom'
     */
    for (i = 0; i < 6; i++) {
      rtDW.RateTransition_6_Buffer[i] = rtU.telecom[i];
    }

    /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/triad_override'
     */
    rtDW.RateTransition_7_Buffer = rtU.triad_override;

    /* RateTransition: '<S4>/Rate Transition1' incorporates:
     *  Inport: '<Root>/rwa_rpm'
     */
    rtDW.RateTransition1_Buffer_a[0] = rtU.rwa_rpm[0];
    rtDW.RateTransition1_Buffer_a[1] = rtU.rwa_rpm[1];
    rtDW.RateTransition1_Buffer_a[2] = rtU.rwa_rpm[2];
    rtDW.RateTransition1_Buffer_a[3] = rtU.rwa_rpm[3];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/rwa_valid'
     */
    rtDW.RateTransition2_Buffer_o[0] = rtU.rwa_valid[0];
    rtDW.RateTransition2_Buffer_o[1] = rtU.rwa_valid[1];
    rtDW.RateTransition2_Buffer_o[2] = rtU.rwa_valid[2];
    rtDW.RateTransition2_Buffer_o[3] = rtU.rwa_valid[3];
  }

  /* End of RateTransition: '<S2>/Rate Transition1' */
}

/* Model step function for TID1 */
void FSW_Lib_step1(void)               /* Sample time: [0.25s, 0.0s] */
{
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

  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  real_T P_0[196];
  real_T cp[13];
  real_T sp[13];
  real_T rtb_Gain_d[9];
  real_T rtb_NED2ECEF[9];
  real_T rtb_mod_to_gcrf[9];
  real_T theta_0[9];
  real_T z_0[9];
  real_T zeta_0[9];
  real_T rtb_YMDHMS_UTC[6];
  real_T rtb_multiply[6];
  real_T rtb_RPM2Radps[4];
  real_T rtb_Switch_p[4];
  real_T rtb_input_wheel_sat[4];
  real_T tmp_0[4];
  real_T rtb_AU2KM[3];
  real_T rtb_Divide_m3[3];
  real_T rtb_Gain[3];
  real_T rtb_Gain_h[3];
  real_T rtb_LLAtoECEFPosition[3];
  real_T rtb_Product1_is[3];
  real_T rtb_Switch1[3];
  real_T rtb_pos_teme_km[3];
  real_T rtb_ss_2_body[3];
  real_T rtb_sun_body_unit[3];
  real_T tod_to_mod_tmp[3];
  real_T C_5;
  real_T D_2;
  real_T D_2_tmp;
  real_T D_3;
  real_T D_4;
  real_T D_sun;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T M_moon;
  real_T M_o;
  real_T M_p;
  real_T O_moon;
  real_T a_1;
  real_T api;
  real_T b_o;
  real_T d_1;
  real_T d_1_tmp_tmp_tmp;
  real_T d_M;
  real_T d_M_tmp;
  real_T d_o;
  real_T d_w;
  real_T d_w_tmp;
  real_T d_w_tmp_0;
  real_T deps_1980;
  real_T dpsi_1980;
  real_T dpsi_1980_tmp;
  real_T dpsi_1980_tmp_0;
  real_T dpsi_1980_tmp_1;
  real_T eps;
  real_T epsb_1980;
  real_T eta;
  real_T n_o;
  real_T rtb_Sqrt_e;
  real_T rtb_Sum;
  real_T theta;
  real_T tsince;
  real_T tsince_JD;
  real_T u_moon;
  real_T w_DF_tmp_tmp;
  real_T xi;
  real_T z;
  real_T zeta;
  int32_T iidx[6];
  int32_T P_tmp;
  int32_T P_tmp_0;
  int32_T i;
  int32_T iter;
  int32_T tmp;
  int32_T tsince_JD_tmp;
  uint32_T rtb_soar_count;
  uint8_T rtb_Merge_g;
  uint8_T rtb_Merge_l;
  uint8_T rtb_Switch3;
  uint8_T rtb_flag_p;
  uint8_T rtb_gnc_mode_o;
  boolean_T lowAlt;
  boolean_T rtb_eclipse_k;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.25s, 0.0s] to Sample time: [60.0s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_2)++;
  if ((rtM->Timing.RateInteraction.TID1_2) > 239) {
    rtM->Timing.RateInteraction.TID1_2 = 0;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  eps = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    9.5492965855137211;

  /* Saturate: '<S233>/Saturation' */
  if (eps > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = 6500.0;
  } else if (eps < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = eps;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  eps = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    9.5492965855137211;

  /* Saturate: '<S233>/Saturation' */
  if (eps > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = 6500.0;
  } else if (eps < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = eps;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  eps = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    9.5492965855137211;

  /* Saturate: '<S233>/Saturation' */
  if (eps > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = 6500.0;
  } else if (eps < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = eps;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  eps = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    9.5492965855137211;

  /* Saturate: '<S233>/Saturation' */
  if (eps > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = 6500.0;
  } else if (eps < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = eps;
  }

  /* Sum: '<S292>/Sum' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition'
   */
  rtb_Sum = rtDW.RateTransition_2_Buffer;

  /* MATLAB Function: '<S292>/MATLAB Function3' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition'
   */
  jseconds2ymdhms_eXoGXxIT(rtDW.RateTransition_2_Buffer, &rtb_YMDHMS_UTC[0],
    &rtb_YMDHMS_UTC[1], &rtb_YMDHMS_UTC[2], &rtb_YMDHMS_UTC[3], &rtb_YMDHMS_UTC
    [4], &rtb_YMDHMS_UTC[5], &D_sun, &tsince_JD);
  jseconds2ymdhms_eXoGXxIT(rtDW.RateTransition_2_Buffer + -0.0361535, &M_moon,
    &rtb_Sum, &u_moon, &D_sun, &deps_1980, &api, &eps, &z);
  jseconds2ymdhms_eXoGXxIT((rtDW.RateTransition_2_Buffer + 37.0) + 32.184,
    &M_moon, &rtb_Sum, &u_moon, &D_sun, &deps_1980, &api, &z, &epsb_1980);

  /* MATLAB Function: '<S328>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S292>/MATLAB Function3'
   */
  tsince = rt_powd_snf(z, 3.0);
  n_o = z * z;
  epsb_1980 = (((23.439291 - 0.0130042 * z) - n_o * 1.64E-7) + 5.04E-7 * tsince)
    * 0.017453292519943295;
  M_moon = (((477198.8673981 * z + 134.96298139) + n_o * 0.0086972) + 1.78E-5 *
            tsince) * 0.017453292519943295;
  rtb_Sum = (((35999.05034 * z + 357.52772333) - n_o * 0.0001603) - 3.3E-6 *
             tsince) * 0.017453292519943295;
  u_moon = (((483202.0175381 * z + 93.27191028) - n_o * 0.0036825) + 3.1E-6 *
            tsince) * 0.017453292519943295;
  D_sun = (((445267.11148 * z + 297.85036306) - n_o * 0.0019142) + 5.3E-6 *
           tsince) * 0.017453292519943295;
  O_moon = (((125.04452222 - 1934.1362608 * z) + n_o * 0.0020708) + 2.2E-6 *
            tsince) * 0.017453292519943295;
  dpsi_1980 = 0.0;
  deps_1980 = 0.0;
  for (iter = 0; iter < 30; iter++) {
    api = (((nc[iter + 30] * M_moon + nc[iter + 60] * rtb_Sum) + nc[iter + 90] *
            u_moon) + nc[iter + 120] * D_sun) + nc[iter + 150] * O_moon;
    dpsi_1980 += (nc[iter + 210] * z + nc[iter + 180]) * 0.0001 * sin(api);
    deps_1980 += (nc[iter + 270] * z + nc[iter + 240]) * 0.0001 * cos(api);
  }

  api = 4.84813681109536E-6 * deps_1980 + epsb_1980;
  M_o = 4.84813681109536E-6 * dpsi_1980;
  M_moon = sin(-epsb_1980);
  rtb_Sum = cos(-epsb_1980);
  u_moon = sin(M_o);
  D_sun = cos(M_o);
  deps_1980 = sin(api);
  api = cos(api);
  zeta = ((n_o * 0.30188 + 2306.2181 * z) + 0.017998 * tsince) *
    4.84813681109536E-6;
  theta = ((2004.3109 * z - n_o * 0.42665) - 0.041833 * tsince) *
    4.84813681109536E-6;
  z = ((n_o * 1.09468 + 2306.2181 * z) + 0.018203 * tsince) *
    4.84813681109536E-6;
  tsince = sin(zeta);
  zeta = cos(zeta);
  M_o = sin(-theta);
  theta = cos(-theta);
  n_o = sin(z);
  z = cos(z);
  rtb_mod_to_gcrf[0] = zeta;
  rtb_mod_to_gcrf[3] = tsince;
  rtb_mod_to_gcrf[6] = 0.0;
  rtb_mod_to_gcrf[1] = -tsince;
  rtb_mod_to_gcrf[4] = zeta;
  rtb_mod_to_gcrf[7] = 0.0;
  theta_0[0] = theta;
  theta_0[3] = 0.0;
  theta_0[6] = -M_o;
  rtb_Gain[0] = 1.0;
  rtb_mod_to_gcrf[2] = 0.0;
  theta_0[1] = 0.0;
  tod_to_mod_tmp[0] = 0.0;
  rtb_Gain[1] = 0.0;
  rtb_mod_to_gcrf[5] = 0.0;
  theta_0[4] = 1.0;
  tod_to_mod_tmp[1] = 0.0;
  rtb_Gain[2] = 0.0;
  rtb_mod_to_gcrf[8] = 1.0;
  theta_0[7] = 0.0;
  tod_to_mod_tmp[2] = 1.0;
  theta_0[2] = M_o;
  theta_0[5] = 0.0;
  theta_0[8] = theta;
  z_0[0] = z;
  z_0[3] = n_o;
  z_0[6] = 0.0;
  z_0[1] = -n_o;
  z_0[4] = z;
  z_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = i + 3 * tsince_JD_tmp;
      zeta_0[iter] = 0.0;
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp] * rtb_mod_to_gcrf[i];
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp + 1] * rtb_mod_to_gcrf[i + 3];
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp + 2] * rtb_mod_to_gcrf[i + 6];
    }

    z_0[3 * i + 2] = tod_to_mod_tmp[i];
  }

  for (i = 0; i < 3; i++) {
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = tsince_JD_tmp + 3 * i;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf[iter] += z_0[3 * i] * zeta_0[tsince_JD_tmp];
      rtb_mod_to_gcrf[iter] += z_0[3 * i + 1] * zeta_0[tsince_JD_tmp + 3];
      rtb_mod_to_gcrf[iter] += z_0[3 * i + 2] * zeta_0[tsince_JD_tmp + 6];
    }
  }

  epsb_1980 = ((dpsi_1980 * cos(epsb_1980) + 0.00264 * sin(O_moon)) + sin(2.0 *
    O_moon) * 6.3E-5) * 4.84813681109536E-6;
  O_moon = ((3.1644001848128662E+9 * eps + 67310.54841) + eps * eps * 0.093104)
    - 6.2E-6 * rt_powd_snf(eps, 3.0);
  if (O_moon < 0.0) {
    z = -1.0;
  } else if (O_moon > 0.0) {
    z = 1.0;
  } else if (O_moon == 0.0) {
    z = 0.0;
  } else {
    z = (rtNaN);
  }

  z *= 86400.0;
  tsince = O_moon;
  if (z == 0.0) {
    if (O_moon == 0.0) {
      tsince = z;
    }
  } else if (rtIsNaN(O_moon)) {
    tsince = (rtNaN);
  } else if (rtIsNaN(z)) {
    tsince = (rtNaN);
  } else if (rtIsInf(O_moon)) {
    tsince = (rtNaN);
  } else if (O_moon == 0.0) {
    tsince = 0.0 / z;
  } else {
    tsince = fmod(O_moon, z);
    if (tsince == 0.0) {
      tsince = z * 0.0;
    } else {
      if ((O_moon < 0.0) != (z < 0.0)) {
        tsince += z;
      }
    }
  }

  O_moon = tsince / 240.0;
  if (rtIsNaN(O_moon)) {
    z = (rtNaN);
  } else if (rtIsInf(O_moon)) {
    z = (rtNaN);
  } else if (O_moon == 0.0) {
    z = 0.0;
  } else {
    z = fmod(O_moon, 360.0);
    if (z == 0.0) {
      z = 0.0;
    } else {
      if (O_moon < 0.0) {
        z += 360.0;
      }
    }
  }

  z = -(0.017453292519943295 * z + epsb_1980);

  /* MATLAB Function: '<S290>/MATLAB Function' incorporates:
   *  Constant: '<S290>/JD_J2000'
   *  MATLAB Function: '<S292>/MATLAB Function3'
   *  RateTransition generated from: '<S1>/Rate Transition'
   *  Sum: '<S290>/Sum'
   */
  theta = 1.88027916E-9;
  dpsi_1980 = 1.01222928;
  rtb_flag_p = 0U;
  O_moon = rtDW.RateTransition_1_Buffer[3] * 0.0174532925;
  zeta = rtDW.RateTransition_1_Buffer[6] * 0.0174532925;
  M_o = rtDW.RateTransition_1_Buffer[7] * 0.0174532925;
  n_o = rtDW.RateTransition_1_Buffer[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtDW.RateTransition_1_Buffer[5] >= 1.0) || (rtDW.RateTransition_1_Buffer
       [5] <= 0.0)) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag_p = 1U;
  } else if (n_o == 0.0) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_flag_p = 2U;
  } else {
    tsince_JD = (tsince_JD - 2.451545E+6) - rtDW.RateTransition_1_Buffer[1];
    if (fabs(tsince_JD) < 1.0E-8) {
      tsince_JD = 0.0;
    } else {
      if (tsince_JD < 0.0) {
        tsince_JD = 0.0;
      }
    }

    tsince = 1440.0 * tsince_JD;
    a_1 = rt_powd_snf(0.0743669161 / n_o, 0.66666666666666663);
    tsince_JD = cos(O_moon);
    M_p = 1.0 - rtDW.RateTransition_1_Buffer[5] * rtDW.RateTransition_1_Buffer[5];
    d_w = tsince_JD * tsince_JD;
    d_1_tmp_tmp_tmp = d_w * 3.0;
    d_M = (d_1_tmp_tmp_tmp - 1.0) / rt_powd_snf(M_p, 1.5);
    d_1 = d_M * (0.000541308 / (a_1 * a_1) * 1.5);
    a_1 *= ((1.0 - 0.33333333333333331 * d_1) - d_1 * d_1) - 1.654320987654321 *
      rt_powd_snf(d_1, 3.0);
    d_o = d_M * (0.000541308 / (a_1 * a_1) * 1.5);
    n_o /= d_o + 1.0;
    d_o = a_1 / (1.0 - d_o);
    d_1 = (1.0 - rtDW.RateTransition_1_Buffer[5]) * d_o;
    a_1 = (d_1 - 1.0) * 6378.137;
    if (d_1 < 1.0344928307435228) {
      lowAlt = true;
      rtb_flag_p = 3U;
    } else {
      lowAlt = false;
    }

    if ((a_1 >= 98.0) && (a_1 <= 156.0)) {
      dpsi_1980 = (d_1 - 1.01222928) + 1.0;
      theta = rt_powd_snf(1.0188142770258546 - ((d_1 - 1.01222928) + 1.0), 4.0);
    } else {
      if (a_1 < 98.0) {
        theta = 6.0426196528035638E-8;
        dpsi_1980 = 1.0031357118857749;
      }
    }

    xi = 1.0 / (d_o - dpsi_1980);
    b_o = sqrt(M_p);
    eta = d_o * rtDW.RateTransition_1_Buffer[5] * xi;
    if (eta == 1.0) {
      rtb_pos_teme_km[0] = 6378.137;
      rtb_pos_teme_km[1] = 6378.137;
      rtb_pos_teme_km[2] = 6878.137;
      rtb_flag_p = 4U;
    } else {
      M_p = rt_powd_snf(xi, 4.0);
      d_w_tmp = eta * eta;
      d_w_tmp_0 = rt_powd_snf(1.0 - d_w_tmp, -3.5);
      d_M_tmp = rt_powd_snf(eta, 3.0);
      d_M = d_w_tmp * 1.5;
      d_1 = ((((d_M + 1.0) + 4.0 * rtDW.RateTransition_1_Buffer[5] * eta) +
              rtDW.RateTransition_1_Buffer[5] * d_M_tmp) * d_o + (d_w * 1.5 +
              -0.5) * (0.00081196200000000006 * xi) * ((d_w_tmp * 24.0 + 8.0) +
              3.0 * rt_powd_snf(eta, 4.0)) / (1.0 - eta * eta)) * (theta * M_p *
        n_o * d_w_tmp_0) * rtDW.RateTransition_1_Buffer[2];
      C_5 = 0.0;
      D_2 = 0.0;
      D_3 = 0.0;
      D_4 = 0.0;
      IL3 = 0.0;
      IL4 = 0.0;
      IL5 = 0.0;
      if (!lowAlt) {
        C_5 = 2.0 * theta * M_p * d_o * (b_o * b_o) * d_w_tmp_0 * ((2.75 * eta *
          (eta + rtDW.RateTransition_1_Buffer[5]) + 1.0) +
          rtDW.RateTransition_1_Buffer[5] * rt_powd_snf(eta, 3.0));
        D_2_tmp = d_1 * d_1;
        D_2 = 4.0 * d_o * xi * D_2_tmp;
        IL4 = rt_powd_snf(d_1, 3.0);
        D_3 = 1.3333333333333333 * d_o * (xi * xi) * (17.0 * d_o + dpsi_1980) *
          IL4;
        a_1 = rt_powd_snf(d_1, 4.0);
        D_4 = 0.66666666666666663 * d_o * rt_powd_snf(xi, 3.0) * (221.0 * d_o +
          31.0 * dpsi_1980) * a_1;
        IL3 = D_2_tmp * 2.0 + D_2;
        IL4 = ((12.0 * d_1 * D_2 + 3.0 * D_3) + 10.0 * IL4) * 0.25;
        IL5 = ((((12.0 * d_1 * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + D_2_tmp *
                30.0 * D_2) + 15.0 * a_1) * 0.2;
      }

      a_1 = rt_powd_snf(tsince_JD, 4.0);
      dpsi_1980_tmp = rt_powd_snf(d_o, 4.0);
      dpsi_1980 = d_o * d_o;
      D_2_tmp = dpsi_1980 * 2.0 * rt_powd_snf(b_o, 3.0);
      M_DF = (((d_1_tmp_tmp_tmp - 1.0) * 0.0016239240000000001 / D_2_tmp + 1.0)
              + ((13.0 - d_w * 78.0) + 137.0 * a_1) * 8.7904305259200008E-7 /
              (16.0 * dpsi_1980_tmp * rt_powd_snf(b_o, 7.0))) * n_o * tsince +
        M_o;
      w_DF_tmp_tmp = rt_powd_snf(b_o, 8.0);
      a_1 = ((((7.0 - d_w * 114.0) + 395.0 * a_1) * 8.7904305259200008E-7 /
              (16.0 * rt_powd_snf(d_o, 4.0) * w_DF_tmp_tmp) + (1.0 - d_w * 5.0) *
              -0.0016239240000000001 / D_2_tmp) + ((3.0 - d_w * 36.0) + 49.0 *
              a_1) * 3.1049437500000002E-6 / (4.0 * dpsi_1980_tmp * w_DF_tmp_tmp))
        * n_o * tsince + zeta;
      dpsi_1980_tmp_0 = b_o * b_o;
      dpsi_1980_tmp_1 = tsince * tsince;
      D_2_tmp = d_w * 7.0;
      dpsi_1980 = ((((4.0 * tsince_JD - 19.0 * rt_powd_snf(tsince_JD, 3.0)) *
                     8.7904305259200008E-7 / (2.0 * dpsi_1980_tmp * w_DF_tmp_tmp)
                     + -0.0016239240000000001 * tsince_JD / (dpsi_1980 *
        rt_powd_snf(b_o, 4.0))) + (3.0 - D_2_tmp) * (3.1049437500000002E-6 *
        tsince_JD) / (2.0 * dpsi_1980_tmp * w_DF_tmp_tmp)) * n_o * tsince +
                   rtDW.RateTransition_1_Buffer[4] * 0.0174532925) - n_o *
        0.000541308 * tsince_JD / (dpsi_1980 * dpsi_1980_tmp_0) * 10.5 * d_1 *
        dpsi_1980_tmp_1;
      if (!lowAlt) {
        d_w = theta * rt_powd_snf(xi, 5.0) * 2.538815E-6 * n_o * sin(O_moon) /
          (0.000541308 * rtDW.RateTransition_1_Buffer[5]) *
          rtDW.RateTransition_1_Buffer[2] * cos(zeta) * tsince;
        d_M = -0.66666666666666663 * theta * rtDW.RateTransition_1_Buffer[2] *
          M_p * (1.0 / (rtDW.RateTransition_1_Buffer[5] * eta)) * (rt_powd_snf
          (eta * cos(M_DF) + 1.0, 3.0) - rt_powd_snf(eta * cos(M_o) + 1.0, 3.0));
        M_p = (M_DF + d_w) + d_M;
        a_1 = (a_1 - d_w) - d_M;
        theta = (rtDW.RateTransition_1_Buffer[5] -
                 ((((rtDW.RateTransition_1_Buffer[5] * eta + 1.0) * (2.0 * eta)
                    + 0.5 * rtDW.RateTransition_1_Buffer[5]) + 0.5 * d_M_tmp) -
                  ((((1.0 - eta * eta * 1.5) - 2.0 *
                     rtDW.RateTransition_1_Buffer[5] * eta) - 0.5 *
                    rtDW.RateTransition_1_Buffer[5] * d_M_tmp) * ((1.0 -
          tsince_JD * tsince_JD * 3.0) * 3.0) + ((eta * eta * 2.0 -
          rtDW.RateTransition_1_Buffer[5] * eta) - rtDW.RateTransition_1_Buffer
                    [5] * rt_powd_snf(eta, 3.0)) * ((1.0 - tsince_JD * tsince_JD)
                    * 0.75) * cos(2.0 * zeta)) * (0.001082616 * xi / ((1.0 - eta
          * eta) * d_o))) * (2.0 * n_o * theta * rt_powd_snf(xi, 4.0) * d_o *
                             (b_o * b_o) * d_w_tmp_0) *
                 rtDW.RateTransition_1_Buffer[2] * tsince) -
          rtDW.RateTransition_1_Buffer[2] * C_5 * (sin(M_p) - sin(M_o));
        zeta = rt_powd_snf(tsince, 3.0);
        xi = rt_powd_snf(tsince, 4.0);
        d_w = tsince * tsince;
        M_o = (((1.0 - d_1 * tsince) - d_w * D_2) - D_3 * zeta) - D_4 * xi;
        M_o = M_o * M_o * d_o;
        d_1 = (((1.5 * d_1 * d_w + IL3 * zeta) + IL4 * xi) + IL5 * rt_powd_snf
               (tsince, 5.0)) * n_o + ((M_p + a_1) + dpsi_1980);
      } else {
        M_o = 1.0 - d_1 * tsince;
        M_o = M_o * M_o * d_o;
        D_3 = rtDW.RateTransition_1_Buffer[5] * eta;
        theta = rtDW.RateTransition_1_Buffer[5] - ((((D_3 + 1.0) * (2.0 * eta) +
          0.5 * rtDW.RateTransition_1_Buffer[5]) + 0.5 * d_M_tmp) - ((((1.0 -
          d_M) - 2.0 * rtDW.RateTransition_1_Buffer[5] * eta) - 0.5 *
          rtDW.RateTransition_1_Buffer[5] * d_M_tmp) * ((1.0 - d_1_tmp_tmp_tmp) *
          3.0) + ((d_w_tmp * 2.0 - D_3) - rtDW.RateTransition_1_Buffer[5] *
                  rt_powd_snf(eta, 3.0)) * ((1.0 - d_w) * 0.75) * cos(2.0 * zeta))
          * (0.001082616 * xi / ((1.0 - eta * eta) * d_o))) * (2.0 * n_o * theta
          * M_p * d_o * dpsi_1980_tmp_0 * d_w_tmp_0) *
          rtDW.RateTransition_1_Buffer[2] * tsince;
        d_1 = 1.5 * d_1 * n_o * dpsi_1980_tmp_1 + ((M_DF + a_1) + dpsi_1980);
      }

      if ((M_o == 0.0) || (theta >= 1.0)) {
        rtb_pos_teme_km[0] = 6378.137;
        rtb_pos_teme_km[1] = 6378.137;
        rtb_pos_teme_km[2] = 6878.137;
        rtb_flag_p = 5U;
      } else {
        tsince = sqrt(1.0 - theta * theta);
        IL3 = cos(a_1);
        n_o = theta * IL3;
        zeta = sin(O_moon);
        M_p = tsince * tsince;
        d_o = 2.538815E-6 * zeta / (0.002165232 * M_o * M_p) + theta * sin(a_1);
        theta = mod_TpoWkbJk((2.538815E-6 * sin(O_moon) / (0.004330464 * M_o *
          M_p) * theta * IL3 * ((5.0 * tsince_JD + 3.0) / (tsince_JD + 1.0)) +
                              d_1) - dpsi_1980);
        a_1 = theta;
        tsince = 0.0;
        iter = 0;
        while ((fabs(a_1 - tsince) > 1.0E-8) && (iter < 10)) {
          a_1 = tsince;
          d_1 = sin(tsince);
          xi = cos(tsince);
          tsince += (((theta - d_o * xi) + n_o * d_1) - tsince) / ((-d_o * d_1 -
            n_o * xi) + 1.0);
          iter++;
        }

        d_1 = sin(tsince);
        IL3 = cos(tsince);
        IL4 = n_o * d_1 - d_o * IL3;
        D_2 = sqrt(n_o * n_o + d_o * d_o);
        D_3 = 1.0 - D_2 * D_2;
        theta = D_3 * M_o;
        tsince = (1.0 - (n_o * cos(tsince) + d_o * d_1)) * M_o;
        if ((tsince == 0.0) || (theta == 0.0)) {
          rtb_pos_teme_km[0] = 6378.137;
          rtb_pos_teme_km[1] = 6378.137;
          rtb_pos_teme_km[2] = 6878.137;
          rtb_flag_p = 6U;
        } else {
          a_1 = sqrt(D_3);
          d_w = M_o / tsince;
          M_o = rt_atan2d_snf(((d_1 - d_o) - n_o * IL4 / (a_1 + 1.0)) * d_w,
                              (d_o * IL4 / (sqrt(1.0 - D_2 * D_2) + 1.0) + (IL3
            - n_o)) * d_w);
          n_o = cos(2.0 * M_o);
          d_1 = theta * theta;
          tsince = (1.0 - (d_1_tmp_tmp_tmp - 1.0) * (0.00081196200000000006 *
                     a_1) / d_1) * tsince + 0.000541308 / (2.0 * theta) * (1.0 -
            tsince_JD * tsince_JD) * n_o;
          d_o = sin(2.0 * M_o);
          M_o += -(0.000541308 / (d_1 * 4.0)) * (D_2_tmp - 1.0) * d_o;
          dpsi_1980_tmp = 0.0016239240000000001 * tsince_JD / (d_1 * 2.0);
          dpsi_1980 += dpsi_1980_tmp * d_o;
          O_moon += dpsi_1980_tmp * zeta * n_o;
          tsince_JD = sin(M_o);
          theta = cos(M_o);
          zeta = cos(O_moon);
          M_o = cos(dpsi_1980);
          dpsi_1980 = sin(dpsi_1980);
          rtb_pos_teme_km[0] = (-dpsi_1980 * zeta * tsince_JD + M_o * theta) *
            tsince * 6378.137;
          rtb_pos_teme_km[1] = (M_o * zeta * tsince_JD + dpsi_1980 * theta) *
            tsince * 6378.137;
          rtb_pos_teme_km[2] = (sin(O_moon) * tsince_JD + 0.0 * theta) * tsince *
            6378.137;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S290>/MATLAB Function' */

  /* MATLAB Function: '<S328>/MATLAB Function' */
  O_moon = sin(-epsb_1980);
  epsb_1980 = cos(-epsb_1980);
  zeta_0[1] = 0.0;
  zeta_0[4] = rtb_Sum;
  zeta_0[7] = M_moon;
  zeta_0[2] = 0.0;
  zeta_0[5] = -M_moon;
  zeta_0[8] = rtb_Sum;
  z_0[0] = D_sun;
  z_0[3] = u_moon;
  z_0[6] = 0.0;
  z_0[1] = -u_moon;
  z_0[4] = D_sun;
  z_0[7] = 0.0;
  zeta_0[0] = 1.0;
  z_0[2] = 0.0;
  zeta_0[3] = 0.0;
  z_0[5] = 0.0;
  zeta_0[6] = 0.0;
  z_0[8] = 1.0;
  for (i = 0; i < 3; i++) {
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = i + 3 * tsince_JD_tmp;
      theta_0[iter] = 0.0;
      theta_0[iter] += z_0[3 * tsince_JD_tmp] * zeta_0[i];
      theta_0[iter] += z_0[3 * tsince_JD_tmp + 1] * zeta_0[i + 3];
      theta_0[iter] += z_0[3 * tsince_JD_tmp + 2] * zeta_0[i + 6];
    }

    rtb_Gain_d[3 * i] = rtb_Gain[i];
  }

  rtb_Gain_d[1] = 0.0;
  rtb_Gain_d[4] = api;
  rtb_Gain_d[7] = deps_1980;
  rtb_Gain_d[2] = 0.0;
  rtb_Gain_d[5] = -deps_1980;
  rtb_Gain_d[8] = api;
  for (i = 0; i < 3; i++) {
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = tsince_JD_tmp + 3 * i;
      zeta_0[iter] = 0.0;
      zeta_0[iter] += rtb_Gain_d[3 * i] * theta_0[tsince_JD_tmp];
      zeta_0[iter] += rtb_Gain_d[3 * i + 1] * theta_0[tsince_JD_tmp + 3];
      zeta_0[iter] += rtb_Gain_d[3 * i + 2] * theta_0[tsince_JD_tmp + 6];
    }
  }

  theta_0[0] = epsb_1980;
  theta_0[3] = O_moon;
  theta_0[6] = 0.0;
  theta_0[1] = -O_moon;
  theta_0[4] = epsb_1980;
  theta_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = i + 3 * tsince_JD_tmp;
      z_0[iter] = 0.0;
      z_0[iter] += zeta_0[3 * tsince_JD_tmp] * rtb_mod_to_gcrf[i];
      z_0[iter] += zeta_0[3 * tsince_JD_tmp + 1] * rtb_mod_to_gcrf[i + 3];
      z_0[iter] += zeta_0[3 * tsince_JD_tmp + 2] * rtb_mod_to_gcrf[i + 6];
    }

    theta_0[3 * i + 2] = tod_to_mod_tmp[i];
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S290>/Product' */
    rtb_ss_2_body[i] = 0.0;
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      iter = i + 3 * tsince_JD_tmp;
      zeta_0[iter] = 0.0;
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp] * z_0[i];
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp + 1] * z_0[i + 3];
      zeta_0[iter] += theta_0[3 * tsince_JD_tmp + 2] * z_0[i + 6];
      rtb_ss_2_body[i] += zeta_0[iter] * rtb_pos_teme_km[tsince_JD_tmp];
    }

    /* End of Product: '<S290>/Product' */

    /* Gain: '<S290>/Gain' */
    rtb_Gain[i] = 1000.0 * rtb_ss_2_body[i];
  }

  /* MATLAB Function: '<S291>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S292>/MATLAB Function3'
   */
  rtb_Sum = mod_TpoWkbJk((35999.05034 * eps + 357.5277233) *
    0.017453292519943295);
  M_moon = (mod_TpoWkbJk((36000.77 * eps + 280.46) * 0.017453292519943295) +
            0.033417233996490527 * sin(rtb_Sum)) + sin(2.0 * rtb_Sum) *
    0.00034897235311083654;
  eps = (23.439291 - 0.0130042 * eps) * 0.017453292519943295;
  tsince = (1.000140612 - 0.016708617 * cos(rtb_Sum)) - cos(2.0 * rtb_Sum) *
    0.000139589;
  rtb_Sum = sin(M_moon);
  D_sun = tsince * cos(M_moon);
  O_moon = cos(eps) * rtb_Sum * tsince;
  eps = sin(eps) * rtb_Sum * tsince;

  /* MATLAB Function: '<S325>/MATLAB Function' */
  epsb_1980 = 0.0;
  rtb_Sum = 0.0;
  for (iter = 0; iter < 3; iter++) {
    /* Gain: '<S6>/M2KM' */
    u_moon = 0.001 * rtb_Gain[iter];

    /* Gain: '<S291>/Gain' */
    tsince_JD = 1.002 * u_moon;

    /* Gain: '<S291>/AU2KM' incorporates:
     *  Product: '<S291>/Product'
     */
    M_moon = 1.49598073E+8 * (rtb_mod_to_gcrf[iter + 6] * eps +
      (rtb_mod_to_gcrf[iter + 3] * O_moon + rtb_mod_to_gcrf[iter] * D_sun));

    /* MATLAB Function: '<S325>/MATLAB Function' */
    deps_1980 = M_moon * 1.49598073E+8;
    n_o = tsince_JD * deps_1980;
    epsb_1980 += n_o;
    rtb_Sum += n_o;

    /* Gain: '<S6>/M2KM' */
    rtb_pos_teme_km[iter] = u_moon;

    /* Gain: '<S291>/Gain' */
    rtb_Gain_h[iter] = tsince_JD;

    /* Gain: '<S291>/AU2KM' */
    rtb_AU2KM[iter] = M_moon;

    /* MATLAB Function: '<S325>/MATLAB Function' */
    rtb_Switch1[iter] = deps_1980;
  }

  /* MATLAB Function: '<S325>/MATLAB Function' */
  eps = norm_EzB1R8di(rtb_Gain_h);
  M_moon = norm_EzB1R8di(rtb_Switch1);
  D_sun = eps * eps;
  M_moon = (D_sun - epsb_1980) / ((D_sun + M_moon * M_moon) - 2.0 * rtb_Sum);
  rtb_eclipse_k = ((!(((rtb_Gain_h[0] * rtb_Switch1[0] + rtb_Gain_h[1] *
                        rtb_Switch1[1]) + rtb_Gain_h[2] * rtb_Switch1[2]) *
                      M_moon + (1.0 - M_moon) * D_sun >= 4.0680631590768993E+7))
                   && ((!(M_moon < 0.0)) && (!(M_moon > 1.0))));

  /* If: '<S108>/If' incorporates:
   *  RateTransition: '<S2>/Rate Transition5'
   */
  if (rtDW.RateTransition5_Buffer) {
    /* Outputs for IfAction SubSystem: '<S108>/sunSensorIsValid' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    /* Abs: '<S111>/Abs' incorporates:
     *  RateTransition: '<S2>/Rate Transition2'
     */
    M_moon = fabs(rtDW.RateTransition2_Buffer[0]);

    /* Relay: '<S111>/Relay' */
    if (M_moon >= 60.0) {
      rtDW.Relay_Mode[0] = true;
    } else {
      if (M_moon <= 10.0) {
        rtDW.Relay_Mode[0] = false;
      }
    }

    /* Abs: '<S111>/Abs' incorporates:
     *  RateTransition: '<S2>/Rate Transition2'
     */
    M_moon = fabs(rtDW.RateTransition2_Buffer[1]);

    /* Relay: '<S111>/Relay' */
    if (M_moon >= 60.0) {
      rtDW.Relay_Mode[1] = true;
    } else {
      if (M_moon <= 10.0) {
        rtDW.Relay_Mode[1] = false;
      }
    }

    /* Sum: '<S111>/Sum' incorporates:
     *  Constant: '<S112>/Lower Limit'
     *  Constant: '<S112>/Upper Limit'
     *  Constant: '<S113>/Lower Limit'
     *  Constant: '<S113>/Upper Limit'
     *  Logic: '<S111>/AND'
     *  Logic: '<S111>/AND1'
     *  Logic: '<S112>/AND'
     *  Logic: '<S113>/AND'
     *  RateTransition: '<S2>/Rate Transition2'
     *  RelationalOperator: '<S112>/Lower Test'
     *  RelationalOperator: '<S112>/Upper Test'
     *  RelationalOperator: '<S113>/Lower Test'
     *  RelationalOperator: '<S113>/Upper Test'
     *  Relay: '<S111>/Relay'
     */
    rtb_Merge_g = (uint8_T)((uint32_T)((-60.0 <= rtDW.RateTransition2_Buffer[0])
      && (rtDW.RateTransition2_Buffer[0] <= 60.0) && ((-60.0 <=
      rtDW.RateTransition2_Buffer[1]) && (rtDW.RateTransition2_Buffer[1] <= 60.0)))
      + ((!rtDW.Relay_Mode[0]) && (!rtDW.Relay_Mode[1])));

    /* End of Outputs for SubSystem: '<S108>/sunSensorIsValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/sunSensorIsNotValid' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    /* SignalConversion generated from: '<S110>/ss_valid_false' incorporates:
     *  Constant: '<S110>/Constant'
     */
    rtb_Merge_g = 0U;

    /* End of Outputs for SubSystem: '<S108>/sunSensorIsNotValid' */
  }

  /* End of If: '<S108>/If' */

  /* MATLAB Function: '<S328>/MATLAB Function' incorporates:
   *  Math: '<S288>/Transpose'
   *  Product: '<S288>/Product3'
   */
  eps = sin(z);
  M_moon = cos(z);
  zeta_0[0] = M_moon;
  zeta_0[3] = eps;
  zeta_0[6] = 0.0;
  zeta_0[1] = -eps;
  zeta_0[4] = M_moon;
  zeta_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    tmp = 3 * i + 2;
    zeta_0[tmp] = tod_to_mod_tmp[i];

    /* Product: '<S288>/Product3' incorporates:
     *  Product: '<S289>/MatrixMultiply'
     */
    tod_to_mod_tmp[i] = 0.0;
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      /* Math: '<S292>/Transpose' incorporates:
       *  Math: '<S288>/Transpose'
       *  Product: '<S288>/Product3'
       */
      iter = i + 3 * tsince_JD_tmp;
      rtb_mod_to_gcrf[iter] = 0.0;
      rtb_mod_to_gcrf[iter] += zeta_0[3 * i] * z_0[tsince_JD_tmp];
      rtb_mod_to_gcrf[iter] += zeta_0[3 * i + 1] * z_0[tsince_JD_tmp + 3];
      rtb_mod_to_gcrf[iter] += zeta_0[tmp] * z_0[tsince_JD_tmp + 6];
      tod_to_mod_tmp[i] += rtb_mod_to_gcrf[iter] * rtb_Gain[tsince_JD_tmp];
    }
  }

  /* LLA2ECEF: '<S288>/LLA to ECEF Position' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition'
   */
  M_moon = rtDW.RateTransition_5_Buffer[0] * 3.1415926535897931 / 180.0;
  u_moon = fabs(M_moon);
  eps = rtDW.RateTransition_5_Buffer[1] * 3.1415926535897931 / 180.0;
  if (u_moon > 3.1415926535897931) {
    M_moon = rt_modd_snf(M_moon + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
    u_moon = fabs(M_moon);
  }

  if (u_moon > 1.5707963267948966) {
    eps += 3.1415926535897931;
    if (M_moon < 0.0) {
      M_moon = -1.0;
    } else if (M_moon > 0.0) {
      M_moon = 1.0;
    } else if (M_moon == 0.0) {
      M_moon = 0.0;
    } else {
      M_moon = (rtNaN);
    }

    M_moon *= 1.5707963267948966 - (u_moon - 1.5707963267948966);
  }

  if (fabs(eps) > 3.1415926535897931) {
    D_sun = rt_remd_snf(eps, 6.2831853071795862);
    z = D_sun / 3.1415926535897931;
    if (z < 0.0) {
      z = ceil(z);
    } else {
      z = floor(z);
    }

    eps = D_sun - 6.2831853071795862 * z;
  }

  rtb_Sum = sin(M_moon);
  rtb_LLAtoECEFPosition[0] = (6.378137E+6 / sqrt(1.0 - rtb_Sum * rtb_Sum *
    0.0066943799901413165) + rtDW.RateTransition_5_Buffer[2]) * cos(M_moon) *
    cos(eps);
  rtb_LLAtoECEFPosition[1] = (6.378137E+6 / sqrt(1.0 - sin(M_moon) * sin(M_moon)
    * 0.0066943799901413165) + rtDW.RateTransition_5_Buffer[2]) * cos(M_moon) *
    sin(eps);
  rtb_LLAtoECEFPosition[2] = (6.378137E+6 / sqrt(1.0 - sin(M_moon) * sin(M_moon)
    * 0.0066943799901413165) * 0.99330562000985867 +
    rtDW.RateTransition_5_Buffer[2]) * rtb_Sum;

  /* End of LLA2ECEF: '<S288>/LLA to ECEF Position' */

  /* Outputs for Atomic SubSystem: '<S288>/target_groundpass_lib1' */
  /* RateTransition generated from: '<S1>/Rate Transition' */
  target_groundpass_lib1(tod_to_mod_tmp, rtb_LLAtoECEFPosition,
    rtDW.RateTransition_5_Buffer[0], rtDW.RateTransition_5_Buffer[1], &lowAlt,
    &eps, &rtb_input_wheel_sat[0]);

  /* End of Outputs for SubSystem: '<S288>/target_groundpass_lib1' */

  /* Sum: '<S291>/Subtract' */
  M_moon = rtb_AU2KM[0] - rtb_pos_teme_km[0];
  rtb_AU2KM[0] = M_moon;

  /* Math: '<S324>/Math Function' */
  rtb_pos_teme_km[0] = M_moon * M_moon;

  /* Sum: '<S291>/Subtract' */
  M_moon = rtb_AU2KM[1] - rtb_pos_teme_km[1];
  rtb_AU2KM[1] = M_moon;

  /* Math: '<S324>/Math Function' */
  rtb_pos_teme_km[1] = M_moon * M_moon;

  /* Sum: '<S291>/Subtract' */
  M_moon = rtb_AU2KM[2] - rtb_pos_teme_km[2];

  /* Math: '<S324>/Math Function' */
  rtb_Sum = M_moon * M_moon;
  rtb_pos_teme_km[2] = rtb_Sum;

  /* Sum: '<S324>/Sum of Elements' */
  tsince_JD = (rtb_pos_teme_km[0] + rtb_pos_teme_km[1]) + rtb_Sum;

  /* Math: '<S324>/Math Function1'
   *
   * About '<S324>/Math Function1':
   *  Operator: sqrt
   */
  if (tsince_JD < 0.0) {
    tsince_JD = -sqrt(fabs(tsince_JD));
  } else {
    tsince_JD = sqrt(tsince_JD);
  }

  /* End of Math: '<S324>/Math Function1' */

  /* Switch: '<S324>/Switch' incorporates:
   *  Constant: '<S324>/Constant'
   *  Product: '<S324>/Product'
   */
  if (tsince_JD > 0.0) {
    rtb_Switch_p[0] = rtb_AU2KM[0];
    rtb_Switch_p[1] = rtb_AU2KM[1];
    rtb_Switch_p[2] = M_moon;
    rtb_Switch_p[3] = tsince_JD;
  } else {
    rtb_Switch_p[0] = rtb_AU2KM[0] * 0.0;
    rtb_Switch_p[1] = rtb_AU2KM[1] * 0.0;
    rtb_Switch_p[2] = M_moon * 0.0;
    rtb_Switch_p[3] = 1.0;
  }

  /* End of Switch: '<S324>/Switch' */

  /* Product: '<S324>/Divide' */
  rtb_Divide_m3[0] = rtb_Switch_p[0] / rtb_Switch_p[3];
  rtb_Divide_m3[1] = rtb_Switch_p[1] / rtb_Switch_p[3];
  rtb_Divide_m3[2] = rtb_Switch_p[2] / rtb_Switch_p[3];

  /* ECEF2LLA: '<S289>/ECEF Position to LLA' incorporates:
   *  Product: '<S289>/MatrixMultiply'
   */
  tsince_JD = sqrt(tod_to_mod_tmp[0] * tod_to_mod_tmp[0] + tod_to_mod_tmp[1] *
                   tod_to_mod_tmp[1]);
  M_moon = rt_atan2d_snf(tod_to_mod_tmp[2], 0.99664718933525254 * tsince_JD);
  rtb_Sum = sin(M_moon);
  u_moon = cos(M_moon);
  rtb_Sum = rt_atan2d_snf(42841.311513313573 * rtb_Sum * rtb_Sum * rtb_Sum +
    tod_to_mod_tmp[2], tsince_JD - 42697.672707179969 * u_moon * u_moon * u_moon);
  u_moon = rt_atan2d_snf(0.99664718933525254 * sin(rtb_Sum), cos(rtb_Sum));
  iter = 0;
  while ((M_moon != u_moon) && (iter < 5)) {
    M_moon = u_moon;
    rtb_Sum = sin(u_moon);
    u_moon = cos(u_moon);
    rtb_Sum = rt_atan2d_snf(42841.311513313573 * rtb_Sum * rtb_Sum * rtb_Sum +
      tod_to_mod_tmp[2], tsince_JD - 42697.672707179969 * u_moon * u_moon *
      u_moon);
    u_moon = rt_atan2d_snf(0.99664718933525254 * sin(rtb_Sum), cos(rtb_Sum));
    iter++;
  }

  u_moon = fabs(rtb_Sum);
  M_moon = rtb_Sum;
  D_sun = rt_atan2d_snf(tod_to_mod_tmp[1], tod_to_mod_tmp[0]);
  if (u_moon > 3.1415926535897931) {
    M_moon = rt_modd_snf(rtb_Sum + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
    u_moon = fabs(M_moon);
  }

  if (u_moon > 1.5707963267948966) {
    D_sun += 3.1415926535897931;
    if (M_moon < 0.0) {
      M_moon = -1.0;
    } else if (M_moon > 0.0) {
      M_moon = 1.0;
    } else if (M_moon == 0.0) {
      M_moon = 0.0;
    } else {
      M_moon = (rtNaN);
    }

    M_moon *= 1.5707963267948966 - (u_moon - 1.5707963267948966);
  }

  if (fabs(D_sun) > 3.1415926535897931) {
    D_sun = rt_remd_snf(D_sun, 6.2831853071795862);
    z = D_sun / 3.1415926535897931;
    if (z < 0.0) {
      z = ceil(z);
    } else {
      z = floor(z);
    }

    D_sun -= 6.2831853071795862 * z;
  }

  z = M_moon * 180.0 / 3.1415926535897931;
  M_moon = sin(rtb_Sum);
  rtb_Sum = ((6.378137E+6 / sqrt(1.0 - M_moon * M_moon * 0.0066943799901413165) *
              0.0066943799901413165 * M_moon + tod_to_mod_tmp[2]) * M_moon +
             tsince_JD * cos(rtb_Sum)) - 6.378137E+6 / sqrt(1.0 - sin(rtb_Sum) *
    sin(rtb_Sum) * 0.0066943799901413165);

  /* UnitConversion: '<S319>/Unit Conversion' incorporates:
   *  MATLAB Function: '<S309>/MATLAB Function'
   */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  api = 0.017453292519943295 * z;

  /* Trigonometry: '<S307>/sincos' incorporates:
   *  UnitConversion: '<S319>/Unit Conversion'
   */
  z = cos(api);

  /* UnitConversion: '<S319>/Unit Conversion' incorporates:
   *  ECEF2LLA: '<S289>/ECEF Position to LLA'
   *  MATLAB Function: '<S309>/MATLAB Function'
   *  Trigonometry: '<S307>/sincos'
   */
  O_moon = sin(api);
  epsb_1980 = 0.017453292519943295 * (D_sun * 180.0 / 3.1415926535897931);

  /* Trigonometry: '<S307>/sincos' incorporates:
   *  UnitConversion: '<S319>/Unit Conversion'
   */
  D_sun = cos(epsb_1980);
  M_moon = sin(epsb_1980);

  /* UnaryMinus: '<S310>/Unary Minus' incorporates:
   *  Product: '<S310>/u(1)*u(4)'
   */
  rtb_NED2ECEF[0] = -(O_moon * D_sun);

  /* UnaryMinus: '<S313>/Unary Minus' */
  rtb_NED2ECEF[1] = -M_moon;

  /* UnaryMinus: '<S316>/Unary Minus' incorporates:
   *  Product: '<S316>/u(3)*u(4)'
   */
  rtb_NED2ECEF[2] = -(z * D_sun);

  /* UnaryMinus: '<S311>/Unary Minus' incorporates:
   *  Product: '<S311>/u(1)*u(2)'
   */
  rtb_NED2ECEF[3] = -(O_moon * M_moon);

  /* SignalConversion generated from: '<S320>/Vector Concatenate' */
  rtb_NED2ECEF[4] = D_sun;

  /* UnaryMinus: '<S317>/Unary Minus' incorporates:
   *  Product: '<S317>/u(2)*u(3)'
   */
  rtb_NED2ECEF[5] = -(M_moon * z);

  /* SignalConversion generated from: '<S320>/Vector Concatenate' */
  rtb_NED2ECEF[6] = z;

  /* SignalConversion generated from: '<S320>/Vector Concatenate' incorporates:
   *  Constant: '<S315>/Constant'
   */
  rtb_NED2ECEF[7] = 0.0;

  /* UnaryMinus: '<S318>/Unary Minus' */
  rtb_NED2ECEF[8] = -O_moon;

  /* Math: '<S289>/Transpose' */
  for (i = 0; i < 3; i++) {
    zeta_0[3 * i] = rtb_NED2ECEF[i];
    zeta_0[3 * i + 1] = rtb_NED2ECEF[i + 3];
    zeta_0[3 * i + 2] = rtb_NED2ECEF[i + 6];
  }

  memcpy(&rtb_NED2ECEF[0], &zeta_0[0], 9U * sizeof(real_T));

  /* End of Math: '<S289>/Transpose' */

  /* MATLAB Function: '<S289>/MATLAB Function' */
  if (rtIsNaN(rtb_YMDHMS_UTC[0])) {
    tsince = (rtNaN);
  } else if (rtIsInf(rtb_YMDHMS_UTC[0])) {
    tsince = (rtNaN);
  } else if (rtb_YMDHMS_UTC[0] == 0.0) {
    tsince = 0.0;
  } else {
    tsince = fmod(rtb_YMDHMS_UTC[0], 4.0);
    if (tsince == 0.0) {
      tsince = 0.0;
    } else {
      if (rtb_YMDHMS_UTC[0] < 0.0) {
        tsince += 4.0;
      }
    }
  }

  if (tsince == 0.0) {
    tsince_JD = 366.0;
    iter = 29;
  } else {
    tsince_JD = 365.25;
    iter = 28;
  }

  if (rtb_YMDHMS_UTC[1] == 1.0) {
    z = rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 2.0) {
    z = rtb_YMDHMS_UTC[2] + 31.0;
  } else if (rtb_YMDHMS_UTC[1] == 3.0) {
    z = ((real_T)iter + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 4.0) {
    z = (((real_T)iter + 31.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 5.0) {
    z = ((((real_T)iter + 31.0) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 6.0) {
    z = (((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 7.0) {
    z = ((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 8.0) {
    z = (((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 9.0) {
    z = ((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
         31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 10.0) {
    z = (((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
          31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 11.0) {
    z = ((((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
           31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else {
    z = (((((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
            31.0) + 30.0) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  }

  M_moon = (((rtb_YMDHMS_UTC[3] / 24.0 + z) + rtb_YMDHMS_UTC[4] / 1440.0) +
            rtb_YMDHMS_UTC[5] / 86400.0) / tsince_JD + rtb_YMDHMS_UTC[0];

  /* End of MATLAB Function: '<S289>/MATLAB Function' */

  /* MATLAB Function: '<S309>/MATLAB Function' */
  z = sin(api);
  memset(&sp[0], 0, 13U * sizeof(real_T));
  memset(&cp[0], 0, 13U * sizeof(real_T));
  sp[1] = sin(epsb_1980);
  cp[0] = 1.0;
  cp[1] = cos(epsb_1980);
  iter = 3;
  for (i = 0; i < 11; i++) {
    iter = i + 3;
    epsb_1980 = cp[i + 1];
    sp[i + 2] = epsb_1980 * sp[1] + sp[i + 1] * cp[1];
    cp[i + 2] = epsb_1980 * cp[1] - sp[i + 1] * sp[1];
  }

  D_sun = 6.378137E+6 / sqrt(1.0 - z * z * 0.0066943799901413165);
  u_moon = (D_sun + rtb_Sum) * cos(api);
  z *= D_sun * 0.99330562000985867 + rtb_Sum;
  tsince = sqrt(u_moon * u_moon + z * z);
  rtb_Sum = asin(z / tsince);
  z = sin(rtb_Sum);
  u_moon = 6.3712E+6 / tsince;
  D_sun = u_moon * u_moon;
  memset(&P_0[0], 0, 196U * sizeof(real_T));
  O_moon = sqrt(1.0 - z * z);
  deps_1980 = tan(rtb_Sum);
  M_o = 1.0 / cos(rtb_Sum);
  P_0[0] = 1.0;
  P_0[1] = z;
  P_0[15] = -O_moon;
  i = 2;
  for (tsince_JD_tmp = 0; tsince_JD_tmp < 12; tsince_JD_tmp++) {
    i = tsince_JD_tmp + 2;
    P_0[tsince_JD_tmp + 2] = ((((real_T)tsince_JD_tmp + 2.0) * 2.0 - 1.0) * z *
      P_0[tsince_JD_tmp + 1] - (((real_T)tsince_JD_tmp + 2.0) - 1.0) *
      P_0[tsince_JD_tmp]) * (1.0 / ((real_T)tsince_JD_tmp + 2.0));
    iter = 1;
    for (tmp = 0; tmp <= tsince_JD_tmp + 1; tmp++) {
      iter = tmp + 1;
      P_tmp = 14 * tmp + tsince_JD_tmp;
      P_tmp_0 = tsince_JD_tmp - tmp;
      tsince = tsince_JD_tmp + tmp;
      P_0[(tsince_JD_tmp + 14 * (tmp + 1)) + 2] = ((((real_T)P_tmp_0 + 1.0) +
        1.0) * z * P_0[P_tmp + 2] - ((tsince + 3.0) - 1.0) * P_0[P_tmp + 1]) *
        (1.0 / O_moon);
      if ((tmp + 1 > 1) && (P_tmp_0 + 1 > 0)) {
        epsb_1980 = ((real_T)(tsince_JD_tmp - tmp) - 1.0) + 1.0;
        factorial_sZPOa6fO(&epsb_1980);
        theta = (tsince + 1.0) - 1.0;
        factorial_sZPOa6fO(&theta);
        P_0[P_tmp] *= rt_powd_snf(-1.0, ((real_T)tmp + 1.0) - 1.0) * sqrt(2.0 *
          epsb_1980 / theta);
      }

      if ((tmp + 1 > 1) && (tsince_JD_tmp + 2 == 13)) {
        tsince_JD = (real_T)(tsince_JD_tmp - tmp) + 1.0;
        factorial_sZPOa6fO(&tsince_JD);
        dpsi_1980 = (tsince + 2.0) - 1.0;
        factorial_sZPOa6fO(&dpsi_1980);
        epsb_1980 = rt_powd_snf(-1.0, ((real_T)tmp + 1.0) - 1.0);
        P_0[P_tmp + 1] *= sqrt(2.0 * tsince_JD / dpsi_1980) * epsb_1980;
        tsince_JD = ((real_T)(tsince_JD_tmp - tmp) + 1.0) + 1.0;
        factorial_sZPOa6fO(&tsince_JD);
        dpsi_1980 = ((real_T)(tsince_JD_tmp + tmp) + 3.0) - 1.0;
        factorial_sZPOa6fO(&dpsi_1980);
        P_0[P_tmp + 2] *= sqrt(2.0 * tsince_JD / dpsi_1980) * epsb_1980;
      }
    }
  }

  tsince = i - iter;
  factorial_sZPOa6fO(&tsince);
  epsb_1980 = i + iter;
  factorial_sZPOa6fO(&epsb_1980);
  P_tmp = 14 * iter + i;
  P_0[P_tmp] *= sqrt(2.0 * tsince / epsb_1980) * rt_powd_snf(-1.0, (real_T)iter);
  z = 0.0;
  epsb_1980 = 0.0;
  O_moon = 0.0;
  for (iter = 0; iter < 12; iter++) {
    D_sun *= u_moon;
    for (i = 0; i <= iter + 1; i++) {
      tsince_JD_tmp = 12 * i + iter;
      tsince_JD = dg[tsince_JD_tmp] * (M_moon - 2015.0) + g[tsince_JD_tmp];
      dpsi_1980 = dh[tsince_JD_tmp] * (M_moon - 2015.0) + h[tsince_JD_tmp];
      tsince_JD_tmp = 14 * i + iter;
      tsince = P_0[tsince_JD_tmp + 1];
      z -= ((((real_T)iter + 1.0) + 1.0) * deps_1980 * tsince - sqrt((iter + 2) *
             (iter + 2) - i * i) * M_o * P_0[tsince_JD_tmp + 2]) * ((tsince_JD *
        cp[i] + dpsi_1980 * sp[i]) * D_sun);
      epsb_1980 += (tsince_JD * sp[i] - dpsi_1980 * cp[i]) * (D_sun * (real_T)i)
        * tsince;
      O_moon -= (((real_T)iter + 1.0) + 1.0) * D_sun * (tsince_JD * cp[i] +
        dpsi_1980 * sp[i]) * tsince;
    }
  }

  D_sun = rtb_Sum - api;
  M_moon = sin(D_sun);
  tsince_JD = cos(D_sun);
  for (i = 0; i < 3; i++) {
    /* Math: '<S289>/Transpose1' incorporates:
     *  Math: '<S288>/Transpose'
     */
    z_0[3 * i] = rtb_mod_to_gcrf[i];
    z_0[3 * i + 1] = rtb_mod_to_gcrf[i + 3];
    z_0[3 * i + 2] = rtb_mod_to_gcrf[i + 6];
  }

  /* MATLAB Function: '<S309>/MATLAB Function' */
  rtb_pos_teme_km[0] = z * tsince_JD - O_moon * M_moon;
  rtb_pos_teme_km[1] = M_o * epsb_1980;
  rtb_pos_teme_km[2] = z * M_moon + O_moon * tsince_JD;
  for (i = 0; i < 3; i++) {
    /* Product: '<S289>/Matrix Multiply1' */
    rtb_ss_2_body[i] = 0.0;
    for (tsince_JD_tmp = 0; tsince_JD_tmp < 3; tsince_JD_tmp++) {
      /* Product: '<S289>/Matrix Multiply' incorporates:
       *  Math: '<S289>/Transpose'
       *  Math: '<S289>/Transpose1'
       *  Product: '<S289>/Matrix Multiply1'
       */
      iter = i + 3 * tsince_JD_tmp;
      zeta_0[iter] = 0.0;
      zeta_0[iter] += rtb_NED2ECEF[3 * tsince_JD_tmp] * z_0[i];
      zeta_0[iter] += rtb_NED2ECEF[3 * tsince_JD_tmp + 1] * z_0[i + 3];
      zeta_0[iter] += rtb_NED2ECEF[3 * tsince_JD_tmp + 2] * z_0[i + 6];

      /* Product: '<S289>/Matrix Multiply1' */
      rtb_ss_2_body[i] += zeta_0[iter] * rtb_pos_teme_km[tsince_JD_tmp];
    }

    /* Gain: '<S289>/nT2T' */
    rtb_Gain_h[i] = 1.0E-9 * rtb_ss_2_body[i];
  }

  /* Trigonometry: '<S107>/Tan1' incorporates:
   *  Gain: '<S107>/deg2rad'
   *  RateTransition: '<S2>/Rate Transition2'
   */
  tsince_JD = tan(0.017453292519943295 * rtDW.RateTransition2_Buffer[0]);

  /* Trigonometry: '<S107>/Tan' incorporates:
   *  Gain: '<S107>/deg2rad'
   *  RateTransition: '<S2>/Rate Transition2'
   */
  M_moon = tan(0.017453292519943295 * rtDW.RateTransition2_Buffer[1]);

  /* Math: '<S109>/Math Function' incorporates:
   *  Constant: '<S109>/Constant'
   *  Math: '<S109>/Square'
   *  Math: '<S109>/Square1'
   *  Sqrt: '<S109>/Sqrt'
   *  Sum: '<S109>/Sum'
   *
   * About '<S109>/Math Function':
   *  Operator: reciprocal
   */
  rtb_Sum = 1.0 / sqrt((tsince_JD * tsince_JD + 1.0) + M_moon * M_moon);

  /* SignalConversion generated from: '<S107>/ss_2_body' incorporates:
   *  Product: '<S107>/Matrix Multiply'
   *  Product: '<S107>/Matrix Multiply1'
   */
  z = tsince_JD * rtb_Sum;
  epsb_1980 = rtb_Sum * M_moon;

  /* Product: '<S107>/ss_2_body' incorporates:
   *  Constant: '<S107>/Constant1'
   *  SignalConversion generated from: '<S107>/ss_2_body'
   */
  for (i = 0; i < 3; i++) {
    rtb_ss_2_body[i] = rtCP_Constant1_Value_ih[i + 6] * rtb_Sum +
      (rtCP_Constant1_Value_ih[i + 3] * epsb_1980 + rtCP_Constant1_Value_ih[i] *
       z);
  }

  /* End of Product: '<S107>/ss_2_body' */

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  /* RateTransition: '<S2>/Rate Transition3' incorporates:
   *  RateTransition: '<S2>/Rate Transition6'
   */
  maggyroProcessing_lib(rtDW.RateTransition3_Buffer, rtDW.RateTransition6_Buffer,
                        rtb_LLAtoECEFPosition, &rtDW.Merge1_g2,
                        &rtDW.maggyroProcessing_lib_j, 0.21629296228661718,
                        rtCP_pooled1, 130.0, 1.0E-6);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S19>/Output'
   */
  if (rtDW.Output_DSTATE > 5) {
    rtb_AU2KM[0] = rtb_LLAtoECEFPosition[0];
    rtb_AU2KM[1] = rtb_LLAtoECEFPosition[1];
    rtb_AU2KM[2] = rtb_LLAtoECEFPosition[2];
  } else {
    rtb_AU2KM[0] = rtDW.UnitDelay_DSTATE[0];
    rtb_AU2KM[1] = rtDW.UnitDelay_DSTATE[1];
    rtb_AU2KM[2] = rtDW.UnitDelay_DSTATE[2];
  }

  /* End of Switch: '<S11>/Switch' */

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  /* RateTransition: '<S2>/Rate Transition4' incorporates:
   *  RateTransition: '<S2>/Rate Transition7'
   */
  maggyroProcessing_lib1(rtDW.RateTransition4_Buffer,
    rtDW.RateTransition7_Buffer, rtb_LLAtoECEFPosition, &rtDW.Merge1_g,
    &rtDW.maggyroProcessing_lib1_i, 0.02, rtCP_pooled1, 4.3633, 1.0);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  /* RateTransition generated from: '<S1>/Rate Transition' */
  MEKF_lib(rtb_Divide_m3, rtb_Gain_h, rtb_ss_2_body, rtb_AU2KM,
           rtb_LLAtoECEFPosition, rtb_Merge_g, rtDW.Merge1_g2, rtDW.Merge1_g,
           rtDW.RateTransition_7_Buffer, rtDW.q_p_merge, rtb_LLAtoECEFPosition,
           rtb_multiply, rtb_pos_teme_km, &rtb_Merge_l, &rtDW.MEKF_lib_k);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  /* RateTransition generated from: '<S1>/Rate Transition' incorporates:
   *  RateTransition: '<S4>/Rate Transition1'
   */
  rtb_gnc_mode_o = mode_select_lib(rtDW.RateTransition_6_Buffer, rtb_eclipse_k,
    rtb_Merge_g, lowAlt, rtb_LLAtoECEFPosition, rtDW.RateTransition_2_Buffer,
    rtDW.RateTransition_3_Buffer, rtDW.RateTransition1_Buffer_a,
    &rtConstB.mode_select_lib_k, &rtDW.mode_select_lib_k);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */
  for (i = 0; i < 5; i++) {
    /* SignalConversion generated from: '<S106>/ SFunction ' incorporates:
     *  MATLAB Function: '<S14>/MATLAB Function'
     *  RateTransition: '<S2>/Rate Transition1'
     */
    rtb_YMDHMS_UTC[i] = rtDW.RateTransition1_Buffer[i];
  }

  /* SignalConversion generated from: '<S106>/ SFunction ' incorporates:
   *  Constant: '<S14>/Constant'
   *  MATLAB Function: '<S14>/MATLAB Function'
   */
  rtb_YMDHMS_UTC[5] = 0.0;

  /* MATLAB Function: '<S14>/MATLAB Function' */
  rtb_sun_body_unit[0] = 0.0;
  rtb_sun_body_unit[1] = 0.0;
  rtb_sun_body_unit[2] = 0.0;
  for (iter = 0; iter < 6; iter++) {
    if (rtb_YMDHMS_UTC[iter] > 99.760095101689075) {
      rtb_sun_body_unit[0] += (real_T)normals[3 * iter];
      rtb_sun_body_unit[1] += (real_T)normals[3 * iter + 1];
      rtb_sun_body_unit[2] += (real_T)normals[3 * iter + 2];
    }
  }

  rtb_Gain_h[0] = rtb_sun_body_unit[0];
  rtb_Gain_h[1] = rtb_sun_body_unit[1] - -1.0;
  rtb_Gain_h[2] = rtb_sun_body_unit[2];
  if (norm_EzB1R8di(rtb_Gain_h) < 1.0E-8) {
    sort_Z8R2ikQI(rtb_YMDHMS_UTC, iidx);
    i = (iidx[4] - 1) * 3;
    rtb_sun_body_unit[0] += (real_T)normals[i];
    rtb_sun_body_unit[1] += (real_T)normals[i + 1];
    rtb_sun_body_unit[2] += (real_T)normals[i + 2];
  }

  tsince_JD = norm_EzB1R8di(rtb_sun_body_unit);
  if (tsince_JD < 1.0) {
    rtb_sun_body_unit[0] = 0.0;
    rtb_sun_body_unit[1] = 0.0;
    rtb_sun_body_unit[2] = -1.0;
  } else {
    rtb_sun_body_unit[0] /= tsince_JD;
    rtb_sun_body_unit[1] /= tsince_JD;
    rtb_sun_body_unit[2] /= tsince_JD;
  }

  /* Product: '<S288>/Product1' incorporates:
   *  Math: '<S288>/Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product1_is[i] = z_0[i + 6] * rtb_input_wheel_sat[2] + (z_0[i + 3] *
      rtb_input_wheel_sat[1] + z_0[i] * rtb_input_wheel_sat[0]);
  }

  /* End of Product: '<S288>/Product1' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  /* RateTransition: '<S4>/Rate Transition1' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition'
   */
  target_generation_lib(rtb_gnc_mode_o, rtb_Divide_m3, rtb_Product1_is, rtb_Gain,
                        rtDW.q_p_merge, rtb_LLAtoECEFPosition,
                        rtDW.RateTransition1_Buffer_a,
                        rtDW.RateTransition_4_Buffer,
                        rtDW.RateTransition_3_Buffer,
                        rtDW.RateTransition_2_Buffer, rtb_Switch_p, rtb_Switch1,
                        rtb_Gain_h, &rtb_Switch3, rtDW.X_k, rtDW.U, &rtDW.s,
                        rtDW.exitcode, &rtb_soar_count);

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */

  /* Sum: '<S5>/Sum1' */
  rtb_Divide_m3[0] = rtb_Switch1[0] - rtb_LLAtoECEFPosition[0];
  rtb_Divide_m3[1] = rtb_Switch1[1] - rtb_LLAtoECEFPosition[1];
  rtb_Divide_m3[2] = rtb_Switch1[2] - rtb_LLAtoECEFPosition[2];

  /* Outputs for Atomic SubSystem: '<S5>/quat_err_lib' */
  quat_err_lib(rtb_Switch_p, rtDW.q_p_merge, rtb_input_wheel_sat);

  /* End of Outputs for SubSystem: '<S5>/quat_err_lib' */

  /* Gain: '<S5>/RPM2Radps' incorporates:
   *  RateTransition: '<S4>/Rate Transition1'
   */
  rtb_RPM2Radps[0] = 0.10471975511965977 * rtDW.RateTransition1_Buffer_a[0];
  rtb_RPM2Radps[1] = 0.10471975511965977 * rtDW.RateTransition1_Buffer_a[1];
  rtb_RPM2Radps[2] = 0.10471975511965977 * rtDW.RateTransition1_Buffer_a[2];
  rtb_RPM2Radps[3] = 0.10471975511965977 * rtDW.RateTransition1_Buffer_a[3];

  /* SwitchCase: '<S228>/Switch Case' */
  switch (rtb_gnc_mode_o) {
   case 0:
   case 1:
   case 2:
   case 4:
    /* Outputs for IfAction SubSystem: '<S228>/case_null_control' incorporates:
     *  ActionPort: '<S236>/Action Port'
     */
    /* Merge: '<S228>/Merge1' incorporates:
     *  SignalConversion generated from: '<S236>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;

    /* Merge: '<S228>/Merge' incorporates:
     *  SignalConversion generated from: '<S236>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[0] = 0.0;

    /* Merge: '<S228>/Merge1' incorporates:
     *  SignalConversion generated from: '<S236>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[1] = 0.0;

    /* Merge: '<S228>/Merge' incorporates:
     *  SignalConversion generated from: '<S236>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[1] = 0.0;

    /* Merge: '<S228>/Merge1' incorporates:
     *  SignalConversion generated from: '<S236>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[2] = 0.0;

    /* Merge: '<S228>/Merge' incorporates:
     *  SignalConversion generated from: '<S236>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[2] = 0.0;

    /* End of Outputs for SubSystem: '<S228>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S228>/case_asm' incorporates:
     *  ActionPort: '<S234>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S234>/asmController_lib' */
    asmController_lib(rtb_Divide_m3, rtb_ss_2_body);

    /* End of Outputs for SubSystem: '<S234>/asmController_lib' */

    /* Sum: '<S241>/Sum of Elements' incorporates:
     *  Math: '<S241>/Math Function'
     */
    rtb_Sqrt_e = rtb_AU2KM[0] * rtb_AU2KM[0];
    rtb_Sqrt_e += rtb_AU2KM[1] * rtb_AU2KM[1];
    rtb_Sqrt_e += rtb_AU2KM[2] * rtb_AU2KM[2];

    /* Math: '<S241>/Math Function1'
     *
     * About '<S241>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_e < 0.0) {
      rtb_Sqrt_e = -sqrt(fabs(rtb_Sqrt_e));
    } else {
      rtb_Sqrt_e = sqrt(rtb_Sqrt_e);
    }

    /* End of Math: '<S241>/Math Function1' */

    /* Switch: '<S241>/Switch' incorporates:
     *  Constant: '<S241>/Constant'
     *  Product: '<S241>/Product'
     */
    if (rtb_Sqrt_e > 0.0) {
      rtb_Sum = rtb_AU2KM[0];
      z = rtb_AU2KM[1];
      epsb_1980 = rtb_AU2KM[2];
      M_moon = rtb_Sqrt_e;
    } else {
      rtb_Sum = rtb_AU2KM[0] * 0.0;
      z = rtb_AU2KM[1] * 0.0;
      epsb_1980 = rtb_AU2KM[2] * 0.0;
      M_moon = 1.0;
    }

    /* End of Switch: '<S241>/Switch' */

    /* Product: '<S241>/Divide' */
    rtb_Divide_m3[0] = rtb_Sum / M_moon;
    rtb_Divide_m3[1] = z / M_moon;
    rtb_Divide_m3[2] = epsb_1980 / M_moon;

    /* Product: '<S242>/Matrix Multiply1' incorporates:
     *  Constant: '<S242>/A_wheel2body '
     *  S-Function (sdspdiag2): '<S242>/Create Diagonal Matrix'
     */
    for (i = 0; i < 4; i++) {
      rtb_Sum = rtConstB.CreateDiagonalMatrix_i[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix_i[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix_i[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix_i[i] * rtb_RPM2Radps[0]));
      tmp_0[i] = rtb_Sum;
    }

    for (i = 0; i < 3; i++) {
      rtb_Sum = rtCP_A_wheel2body_Value[i + 9] * tmp_0[3] +
        (rtCP_A_wheel2body_Value[i + 6] * tmp_0[2] + (rtCP_A_wheel2body_Value[i
          + 3] * tmp_0[1] + rtCP_A_wheel2body_Value[i] * tmp_0[0]));

      /* Sum: '<S243>/Subtract2' incorporates:
       *  Constant: '<S242>/A_wheel2body '
       *  Gain: '<S244>/Gain'
       *  Product: '<S243>/Matrix Multiply7'
       *  S-Function (sdspeye): '<S243>/Identity Matrix'
       */
      rtb_NED2ECEF[3 * i] = rtConstB.IdentityMatrix_e[3 * i] - rtb_Divide_m3[0] *
        rtb_Divide_m3[i];
      tsince_JD_tmp = 3 * i + 1;
      rtb_NED2ECEF[tsince_JD_tmp] = rtConstB.IdentityMatrix_e[tsince_JD_tmp] -
        rtb_Divide_m3[1] * rtb_Divide_m3[i];
      tsince_JD_tmp = 3 * i + 2;
      rtb_NED2ECEF[tsince_JD_tmp] = rtConstB.IdentityMatrix_e[tsince_JD_tmp] -
        rtb_Divide_m3[2] * rtb_Divide_m3[i];

      /* Sum: '<S242>/Subtract1' incorporates:
       *  Constant: '<S242>/scParams.J '
       *  Product: '<S242>/Matrix Multiply'
       */
      rtb_sun_body_unit[i] = (rtConstB.h_w_nom_body_Nms_i[i] - rtb_Sum) -
        ((rtCP_scParamsJ_Value[i + 3] * rtb_LLAtoECEFPosition[1] +
          rtCP_scParamsJ_Value[i] * rtb_LLAtoECEFPosition[0]) +
         rtCP_scParamsJ_Value[i + 6] * rtb_LLAtoECEFPosition[2]);
    }

    /* End of Product: '<S242>/Matrix Multiply1' */

    /* Product: '<S243>/Matrix Multiply8' */
    for (i = 0; i < 3; i++) {
      rtb_Product1_is[i] = rtb_NED2ECEF[i + 6] * rtb_sun_body_unit[2] +
        (rtb_NED2ECEF[i + 3] * rtb_sun_body_unit[1] + rtb_NED2ECEF[i] *
         rtb_sun_body_unit[0]);
    }

    /* End of Product: '<S243>/Matrix Multiply8' */
    for (i = 0; i < 3; i++) {
      /* Merge: '<S228>/Merge' incorporates:
       *  Gain: '<S240>/DutyCycleAdjustment'
       *  Gain: '<S243>/Gain'
       *  Sum: '<S234>/Sum'
       */
      rtDW.Merge[i] = 2.2 * (rtCP_Gain_Gain_k[i + 6] * rtb_Product1_is[2] +
        (rtCP_Gain_Gain_k[i + 3] * rtb_Product1_is[1] + rtCP_Gain_Gain_k[i] *
         rtb_Product1_is[0])) + rtb_ss_2_body[i];
    }

    /* Outputs for Atomic SubSystem: '<S240>/twonorm' */
    rtb_Sqrt_e = twonorm(rtb_AU2KM);

    /* End of Outputs for SubSystem: '<S240>/twonorm' */

    /* Sum: '<S246>/Add3' incorporates:
     *  Product: '<S246>/Element product'
     */
    rtb_Sum = rtb_sun_body_unit[1] * rtb_Divide_m3[2] - rtb_sun_body_unit[2] *
      rtb_Divide_m3[1];
    z = rtb_sun_body_unit[2] * rtb_Divide_m3[0] - rtb_sun_body_unit[0] *
      rtb_Divide_m3[2];
    epsb_1980 = rtb_sun_body_unit[0] * rtb_Divide_m3[1] - rtb_sun_body_unit[1] *
      rtb_Divide_m3[0];
    for (i = 0; i < 3; i++) {
      /* Merge: '<S228>/Merge1' incorporates:
       *  Gain: '<S244>/Gain'
       *  Gain: '<S244>/Gain3'
       *  Product: '<S244>/Divide'
       */
      rtDW.Merge1[i] = -(rtCP_Gain3_Gain_jj[i + 6] * epsb_1980 +
                         (rtCP_Gain3_Gain_jj[i + 3] * z + rtCP_Gain3_Gain_jj[i] *
                          rtb_Sum)) / rtb_Sqrt_e;
    }

    /* End of Outputs for SubSystem: '<S228>/case_asm' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S228>/case_sunseek' incorporates:
     *  ActionPort: '<S238>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S238>/sunSeek_lib' */
    sunSeek_lib(rtb_Merge_g, rtb_sun_body_unit, rtb_ss_2_body, rtb_Divide_m3,
                rtDW.Merge);

    /* End of Outputs for SubSystem: '<S238>/sunSeek_lib' */

    /* Merge: '<S228>/Merge1' incorporates:
     *  SignalConversion generated from: '<S238>/sunseek_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* End of Outputs for SubSystem: '<S228>/case_sunseek' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S228>/case_desaturation' incorporates:
     *  ActionPort: '<S235>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S235>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_input_wheel_sat, rtb_Divide_m3, rtb_ss_2_body);

    /* End of Outputs for SubSystem: '<S235>/PD_Controller_Lib' */

    /* Sum: '<S249>/Sum of Elements' incorporates:
     *  Math: '<S249>/Math Function'
     */
    rtb_Sqrt_e = rtb_AU2KM[0] * rtb_AU2KM[0];
    rtb_Sqrt_e += rtb_AU2KM[1] * rtb_AU2KM[1];
    rtb_Sqrt_e += rtb_AU2KM[2] * rtb_AU2KM[2];

    /* Math: '<S249>/Math Function1'
     *
     * About '<S249>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_e < 0.0) {
      rtb_Sqrt_e = -sqrt(fabs(rtb_Sqrt_e));
    } else {
      rtb_Sqrt_e = sqrt(rtb_Sqrt_e);
    }

    /* End of Math: '<S249>/Math Function1' */

    /* Switch: '<S249>/Switch' incorporates:
     *  Constant: '<S249>/Constant'
     *  Product: '<S249>/Product'
     */
    if (rtb_Sqrt_e > 0.0) {
      rtb_Sum = rtb_AU2KM[0];
      z = rtb_AU2KM[1];
      epsb_1980 = rtb_AU2KM[2];
      M_moon = rtb_Sqrt_e;
    } else {
      rtb_Sum = rtb_AU2KM[0] * 0.0;
      z = rtb_AU2KM[1] * 0.0;
      epsb_1980 = rtb_AU2KM[2] * 0.0;
      M_moon = 1.0;
    }

    /* End of Switch: '<S249>/Switch' */

    /* Product: '<S249>/Divide' */
    rtb_Divide_m3[0] = rtb_Sum / M_moon;
    rtb_Divide_m3[1] = z / M_moon;
    rtb_Divide_m3[2] = epsb_1980 / M_moon;

    /* Product: '<S250>/Matrix Multiply1' incorporates:
     *  Constant: '<S250>/A_wheel2body '
     *  S-Function (sdspdiag2): '<S250>/Create Diagonal Matrix'
     */
    for (i = 0; i < 4; i++) {
      rtb_Sum = rtConstB.CreateDiagonalMatrix[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix[i] * rtb_RPM2Radps[0]));
      tmp_0[i] = rtb_Sum;
    }

    for (i = 0; i < 3; i++) {
      rtb_Sum = rtCP_A_wheel2body_Value_a[i + 9] * tmp_0[3] +
        (rtCP_A_wheel2body_Value_a[i + 6] * tmp_0[2] +
         (rtCP_A_wheel2body_Value_a[i + 3] * tmp_0[1] +
          rtCP_A_wheel2body_Value_a[i] * tmp_0[0]));

      /* Sum: '<S251>/Subtract2' incorporates:
       *  Constant: '<S250>/A_wheel2body '
       *  Gain: '<S252>/Gain'
       *  Product: '<S251>/Matrix Multiply7'
       *  S-Function (sdspeye): '<S251>/Identity Matrix'
       */
      rtb_NED2ECEF[3 * i] = rtConstB.IdentityMatrix[3 * i] - rtb_Divide_m3[0] *
        rtb_Divide_m3[i];
      tsince_JD_tmp = 3 * i + 1;
      rtb_NED2ECEF[tsince_JD_tmp] = rtConstB.IdentityMatrix[tsince_JD_tmp] -
        rtb_Divide_m3[1] * rtb_Divide_m3[i];
      tsince_JD_tmp = 3 * i + 2;
      rtb_NED2ECEF[tsince_JD_tmp] = rtConstB.IdentityMatrix[tsince_JD_tmp] -
        rtb_Divide_m3[2] * rtb_Divide_m3[i];

      /* Sum: '<S250>/Subtract1' incorporates:
       *  Constant: '<S250>/scParams.J '
       *  Product: '<S250>/Matrix Multiply'
       */
      rtb_sun_body_unit[i] = (rtConstB.h_w_nom_body_Nms[i] - rtb_Sum) -
        ((rtCP_scParamsJ_Value_j[i + 3] * rtb_LLAtoECEFPosition[1] +
          rtCP_scParamsJ_Value_j[i] * rtb_LLAtoECEFPosition[0]) +
         rtCP_scParamsJ_Value_j[i + 6] * rtb_LLAtoECEFPosition[2]);
    }

    /* End of Product: '<S250>/Matrix Multiply1' */

    /* Product: '<S251>/Matrix Multiply8' */
    for (i = 0; i < 3; i++) {
      rtb_Product1_is[i] = rtb_NED2ECEF[i + 6] * rtb_sun_body_unit[2] +
        (rtb_NED2ECEF[i + 3] * rtb_sun_body_unit[1] + rtb_NED2ECEF[i] *
         rtb_sun_body_unit[0]);
    }

    /* End of Product: '<S251>/Matrix Multiply8' */
    for (i = 0; i < 3; i++) {
      /* Merge: '<S228>/Merge' incorporates:
       *  Gain: '<S248>/DutyCycleAdjustment'
       *  Gain: '<S251>/Gain'
       *  Sum: '<S235>/Sum'
       */
      rtDW.Merge[i] = 2.2 * (rtCP_Gain_Gain_pq[i + 6] * rtb_Product1_is[2] +
        (rtCP_Gain_Gain_pq[i + 3] * rtb_Product1_is[1] + rtCP_Gain_Gain_pq[i] *
         rtb_Product1_is[0])) + rtb_ss_2_body[i];
    }

    /* Outputs for Atomic SubSystem: '<S248>/twonorm' */
    rtb_Sqrt_e = twonorm(rtb_AU2KM);

    /* End of Outputs for SubSystem: '<S248>/twonorm' */

    /* Sum: '<S254>/Add3' incorporates:
     *  Product: '<S254>/Element product'
     */
    rtb_Sum = rtb_sun_body_unit[1] * rtb_Divide_m3[2] - rtb_sun_body_unit[2] *
      rtb_Divide_m3[1];
    z = rtb_sun_body_unit[2] * rtb_Divide_m3[0] - rtb_sun_body_unit[0] *
      rtb_Divide_m3[2];
    epsb_1980 = rtb_sun_body_unit[0] * rtb_Divide_m3[1] - rtb_sun_body_unit[1] *
      rtb_Divide_m3[0];
    for (i = 0; i < 3; i++) {
      /* Merge: '<S228>/Merge1' incorporates:
       *  Gain: '<S252>/Gain'
       *  Gain: '<S252>/Gain3'
       *  Product: '<S252>/Divide'
       */
      rtDW.Merge1[i] = -(rtCP_Gain3_Gain_i[i + 6] * epsb_1980 +
                         (rtCP_Gain3_Gain_i[i + 3] * z + rtCP_Gain3_Gain_i[i] *
                          rtb_Sum)) / rtb_Sqrt_e;
    }

    /* End of Outputs for SubSystem: '<S228>/case_desaturation' */
    break;

   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S228>/case_reorientation' incorporates:
     *  ActionPort: '<S237>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S237>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_input_wheel_sat, rtb_Divide_m3, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S237>/PD_Controller_Lib' */

    /* Merge: '<S228>/Merge1' incorporates:
     *  SignalConversion generated from: '<S237>/tracking_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* End of Outputs for SubSystem: '<S228>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S228>/Switch Case' */

  /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem' incorporates:
   *  ActionPort: '<S261>/Action Port'
   */
  /* If: '<S230>/If' */
  IfActionSubsystem(&rtb_Sum);

  /* End of Outputs for SubSystem: '<S230>/If Action Subsystem' */

  /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem3' incorporates:
   *  ActionPort: '<S264>/Action Port'
   */
  /* If: '<S230>/If1' */
  IfActionSubsystem(&rtb_Sqrt_e);

  /* End of Outputs for SubSystem: '<S230>/If Action Subsystem3' */

  /* Switch: '<S227>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  UnitDelay: '<S19>/Output'
   */
  if (rtDW.Output_DSTATE <= 4) {
    /* Product: '<S230>/Multiply2' */
    rtb_ss_2_body[0] = rtDW.Merge1[0] * rtb_Sum;
    rtb_ss_2_body[1] = rtDW.Merge1[1] * rtb_Sqrt_e;
    rtb_ss_2_body[2] = rtDW.Merge1[2] * rtConstB.Switch;

    /* Outport: '<Root>/mtq_cmd_Am2' incorporates:
     *  Product: '<S230>/Multiply'
     */
    rtY.mtq_cmd_Am2[0] = rtb_ss_2_body[0] * 0.5;
    rtY.mtq_cmd_Am2[1] = rtb_ss_2_body[0] * -0.5;
    rtY.mtq_cmd_Am2[3] = rtb_ss_2_body[1] * -0.5;
    rtY.mtq_cmd_Am2[2] = rtb_ss_2_body[1] * 0.5;
    rtY.mtq_cmd_Am2[4] = rtb_ss_2_body[2];
  } else {
    /* Outport: '<Root>/mtq_cmd_Am2' */
    for (i = 0; i < 5; i++) {
      rtY.mtq_cmd_Am2[i] = 0.0;
    }
  }

  /* End of Switch: '<S227>/Switch' */

  /* RateTransition generated from: '<S1>/Rate Transition4' incorporates:
   *  Abs: '<S229>/Abs'
   *  Gain: '<S229>/Gain'
   *  Gain: '<S229>/RAD2DEG'
   *  Trigonometry: '<S229>/Acos'
   */
  if (rtM->Timing.RateInteraction.TID1_2 == 1) {
    rtDW.RateTransition4_1_Buffer = rtb_gnc_mode_o;

    /* Saturate: '<S229>/Saturation' */
    if (rtb_input_wheel_sat[0] > 1.0) {
      rtb_Sum = 1.0;
    } else if (rtb_input_wheel_sat[0] < -1.0) {
      rtb_Sum = -1.0;
    } else {
      rtb_Sum = rtb_input_wheel_sat[0];
    }

    /* End of Saturate: '<S229>/Saturation' */
    rtDW.RateTransition4_10_Buffer = fabs(2.0 * acos(rtb_Sum) *
      57.295779513082323);
    rtDW.RateTransition4_11_Buffer = rtb_eclipse_k;
    rtDW.RateTransition4_12_Buffer = rtb_flag_p;
  }

  /* Outputs for Atomic SubSystem: '<S288>/target_groundpass_lib' */
  /* Constant: '<S288>/Constant' */
  target_groundpass_lib(tod_to_mod_tmp, rtCP_Constant_Value_dg, &rtb_eclipse_k,
                        &M_moon, rtb_ss_2_body,
                        &rtConstB.target_groundpass_lib_f);

  /* End of Outputs for SubSystem: '<S288>/target_groundpass_lib' */

  /* RateTransition generated from: '<S1>/Rate Transition4' incorporates:
   *  BusCreator generated from: '<S1>/Bus Assignment1'
   */
  if (rtM->Timing.RateInteraction.TID1_2 == 1) {
    rtDW.RateTransition4_13_Buffer = rtb_eclipse_k;
    rtDW.RateTransition4_14_Buffer = lowAlt;
    rtDW.RateTransition4_15_Buffer = rtb_Switch3;
    rtDW.RateTransition4_16_Buffer = M_moon;
    rtDW.RateTransition4_17_Buffer = eps;
    rtDW.RateTransition4_18_Buffer = rtb_Merge_g;
    memcpy(&rtDW.RateTransition4_19_Buffer.opt_state[0], &rtDW.X_k[0], 100U *
           sizeof(real_T));
    memcpy(&rtDW.RateTransition4_19_Buffer.opt_ctrl_Nm[0], &rtDW.U[0], 30U *
           sizeof(real_T));
    rtDW.RateTransition4_19_Buffer.final_time_s = rtDW.s;
    memcpy(&rtDW.RateTransition4_19_Buffer.exitcode[0], &rtDW.exitcode[0], 17U *
           sizeof(real_T));
    rtDW.RateTransition4_19_Buffer.soar_count = rtb_soar_count;
    rtDW.RateTransition4_2_Buffer[0] = rtDW.q_p_merge[0];
    rtDW.RateTransition4_2_Buffer[1] = rtDW.q_p_merge[1];
    rtDW.RateTransition4_2_Buffer[2] = rtDW.q_p_merge[2];
    rtDW.RateTransition4_2_Buffer[3] = rtDW.q_p_merge[3];
    rtDW.RateTransition4_3_Buffer[0] = rtb_LLAtoECEFPosition[0];
    rtDW.RateTransition4_3_Buffer[1] = rtb_LLAtoECEFPosition[1];
    rtDW.RateTransition4_3_Buffer[2] = rtb_LLAtoECEFPosition[2];
    rtDW.RateTransition4_4_Buffer[0] = rtb_Switch_p[0];
    rtDW.RateTransition4_4_Buffer[1] = rtb_Switch_p[1];
    rtDW.RateTransition4_4_Buffer[2] = rtb_Switch_p[2];
    rtDW.RateTransition4_4_Buffer[3] = rtb_Switch_p[3];
    rtDW.RateTransition4_5_Buffer[0] = rtb_Switch1[0];
    rtDW.RateTransition4_5_Buffer[1] = rtb_Switch1[1];
    rtDW.RateTransition4_5_Buffer[2] = rtb_Switch1[2];
    for (i = 0; i < 6; i++) {
      rtDW.RateTransition4_6_Buffer[i] = rtb_multiply[i];
    }

    rtDW.RateTransition4_7_Buffer[0] = rtb_pos_teme_km[0];
    rtDW.RateTransition4_7_Buffer[1] = rtb_pos_teme_km[1];
    rtDW.RateTransition4_7_Buffer[2] = rtb_pos_teme_km[2];
    rtDW.RateTransition4_8_Buffer = rtb_Merge_l;
    rtDW.RateTransition4_9_Buffer[0] = rtb_Gain[0];
    rtDW.RateTransition4_9_Buffer[1] = rtb_Gain[1];
    rtDW.RateTransition4_9_Buffer[2] = rtb_Gain[2];
  }

  /* Sum: '<S5>/Sum' */
  rtb_Gain_h[0] += rtDW.Merge[0];
  rtb_Gain_h[1] += rtDW.Merge[1];
  rtb_Gain_h[2] += rtDW.Merge[2];

  /* Outputs for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
  /* RateTransition: '<S4>/Rate Transition2' */
  rwa_allocation_lib(rtb_Gain_h, rtb_RPM2Radps, rtDW.RateTransition2_Buffer_o,
                     rtb_input_wheel_sat, &rtDW.rwa_allocation_lib_h);

  /* End of Outputs for SubSystem: '<S5>/rwa_allocation_lib' */

  /* Update for DiscreteIntegrator: '<S233>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtb_input_wheel_sat[0];
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtb_input_wheel_sat[1];
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtb_input_wheel_sat[2];
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += 0.25 * rtb_input_wheel_sat[3];

  /* Switch: '<S21>/FixPt Switch' incorporates:
   *  Constant: '<S20>/FixPt Constant'
   *  Sum: '<S20>/FixPt Sum1'
   *  UnitDelay: '<S19>/Output'
   */
  if ((uint8_T)(rtDW.Output_DSTATE + 1U) > 10) {
    /* Update for UnitDelay: '<S19>/Output' incorporates:
     *  Constant: '<S21>/Constant'
     */
    rtDW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S19>/Output' */
    rtDW.Output_DSTATE++;
  }

  /* End of Switch: '<S21>/FixPt Switch' */

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = rtb_AU2KM[0];
  rtDW.UnitDelay_DSTATE[1] = rtb_AU2KM[1];
  rtDW.UnitDelay_DSTATE[2] = rtb_AU2KM[2];
}

/* Model step function for TID2 */
void FSW_Lib_step2(void)               /* Sample time: [60.0s, 0.0s] */
{
  int32_T i;

  /* Outport: '<Root>/gnc_mode' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.gnc_mode = rtDW.RateTransition4_1_Buffer;

  /* Outport: '<Root>/sc_quat' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.sc_quat[0] = rtDW.RateTransition4_2_Buffer[0];
  rtY.sc_quat[1] = rtDW.RateTransition4_2_Buffer[1];
  rtY.sc_quat[2] = rtDW.RateTransition4_2_Buffer[2];
  rtY.sc_quat[3] = rtDW.RateTransition4_2_Buffer[3];

  /* Outport: '<Root>/sc_body_rates_radps' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.sc_body_rates_radps[0] = rtDW.RateTransition4_3_Buffer[0];
  rtY.sc_body_rates_radps[1] = rtDW.RateTransition4_3_Buffer[1];
  rtY.sc_body_rates_radps[2] = rtDW.RateTransition4_3_Buffer[2];

  /* Outport: '<Root>/cmd_quat' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.cmd_quat[0] = rtDW.RateTransition4_4_Buffer[0];
  rtY.cmd_quat[1] = rtDW.RateTransition4_4_Buffer[1];
  rtY.cmd_quat[2] = rtDW.RateTransition4_4_Buffer[2];
  rtY.cmd_quat[3] = rtDW.RateTransition4_4_Buffer[3];

  /* Outport: '<Root>/cmd_body_rates_radps' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.cmd_body_rates_radps[0] = rtDW.RateTransition4_5_Buffer[0];
  rtY.cmd_body_rates_radps[1] = rtDW.RateTransition4_5_Buffer[1];
  rtY.cmd_body_rates_radps[2] = rtDW.RateTransition4_5_Buffer[2];

  /* Outport: '<Root>/mekf_3sigma_rad' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  for (i = 0; i < 6; i++) {
    rtY.mekf_3sigma_rad[i] = rtDW.RateTransition4_6_Buffer[i];
  }

  /* End of Outport: '<Root>/mekf_3sigma_rad' */

  /* Outport: '<Root>/mekf_telem' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.mekf_telem = rtDW.RateTransition4_8_Buffer;

  /* Outport: '<Root>/mekf_bias_radps' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.mekf_bias_radps[0] = rtDW.RateTransition4_7_Buffer[0];

  /* Outport: '<Root>/r_eci_m' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.r_eci_m[0] = rtDW.RateTransition4_9_Buffer[0];

  /* Outport: '<Root>/mekf_bias_radps' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.mekf_bias_radps[1] = rtDW.RateTransition4_7_Buffer[1];

  /* Outport: '<Root>/r_eci_m' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.r_eci_m[1] = rtDW.RateTransition4_9_Buffer[1];

  /* Outport: '<Root>/mekf_bias_radps' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.mekf_bias_radps[2] = rtDW.RateTransition4_7_Buffer[2];

  /* Outport: '<Root>/r_eci_m' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.r_eci_m[2] = rtDW.RateTransition4_9_Buffer[2];

  /* Outport: '<Root>/ace_err' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.ace_err = rtDW.RateTransition4_10_Buffer;

  /* Outport: '<Root>/eclipse' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.eclipse = rtDW.RateTransition4_11_Buffer;

  /* Outport: '<Root>/sgp4_flag' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.sgp4_flag = rtDW.RateTransition4_12_Buffer;

  /* Outport: '<Root>/sc_above_gs' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.sc_above_gs = rtDW.RateTransition4_13_Buffer;

  /* Outport: '<Root>/sc_above_targ' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.sc_above_targ = rtDW.RateTransition4_14_Buffer;

  /* Outport: '<Root>/target_gen_flag' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.target_gen_flag = rtDW.RateTransition4_15_Buffer;

  /* Outport: '<Root>/elev_gs_rad' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.elev_gs_rad = rtDW.RateTransition4_16_Buffer;

  /* Outport: '<Root>/elev_targ_rad' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.elev_targ_rad = rtDW.RateTransition4_17_Buffer;

  /* Outport: '<Root>/ss_valid' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.ss_valid = rtDW.RateTransition4_18_Buffer;

  /* Outport: '<Root>/soar_telemetry' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  rtY.soar_telemetry_e = rtDW.RateTransition4_19_Buffer;
}

/* Model initialize function */
void FSW_Lib_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S233>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[1] = -0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[2] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[3] = -0.0030919554896630744;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = 0.0;
  rtDW.UnitDelay_DSTATE[1] = 0.0;
  rtDW.UnitDelay_DSTATE[2] = 1.0;

  /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  maggyroProcessing_lib_Init(&rtDW.maggyroProcessing_lib_j);

  /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  maggyroProcessing_lib1_Init(&rtDW.maggyroProcessing_lib1_i);

  /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Init(rtDW.q_p_merge, &rtDW.MEKF_lib_k);

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
