/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_types.h
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

#ifndef RTW_HEADER_FSW_Lib_types_h_
#define RTW_HEADER_FSW_Lib_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_sensor_bus_
#define DEFINED_TYPEDEF_FOR_sensor_bus_

typedef struct {
  real_T photodiodes_uA[5];
  real_T mag_mag_uT[9];
  boolean_T mag_meas_valid[3];
  real_T sun_meas_ss_deg[2];
  boolean_T sun_meas_valid;
  real_T gyro_gyro_radps[9];
  boolean_T gyro_meas_valid[3];
} sensor_bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_cdh_data_
#define DEFINED_TYPEDEF_FOR_cdh_data_

typedef struct {
  real_T orbit_tle[9];
  real_T MET_utc_s;
  real_T MET_soar_utc_s;
  real_T quat_soar_cmd[4];
  real_T target_latlonalt[3];
  real_T telecom[6];
  boolean_T triad_override;
} cdh_data;

#endif

#ifndef DEFINED_TYPEDEF_FOR_actuator_meas_
#define DEFINED_TYPEDEF_FOR_actuator_meas_

typedef struct {
  boolean_T mtq_valid[5];
  boolean_T rwa_valid[4];
  real_T rwa_rpm[4];
} actuator_meas;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RWA_
#define DEFINED_TYPEDEF_FOR_RWA_

typedef struct {
  real_T A_wheel2body[12];
  real_T inertia[4];
  real_T inv_inertia[4];
  real_T max_torque_Nm;
  real_T max_RPM;
  uint8_T num_facet;
  real_T h_targ_wheel_Nms[4];
  real_T feedback_gain;
  real_T nullvec[4];
  real_T b_sat[2];
  uint8_T id_facet[12];
  uint8_T id_facet_complement[12];
  real_T w_facet[18];
  real_T g_facet[6];
  real_T inrm2[6];
} RWA;

#endif

#ifndef DEFINED_TYPEDEF_FOR_fsw_out_
#define DEFINED_TYPEDEF_FOR_fsw_out_

typedef struct {
  real_T rwa_cmd_rpm[4];
  real_T mtq_cmd_Am2[5];
} fsw_out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_soar_telemetry_
#define DEFINED_TYPEDEF_FOR_soar_telemetry_

typedef struct {
  real_T opt_state[100];
  real_T opt_ctrl_Nm[30];
  real_T final_time_s;
  real_T exitcode[17];
  uint32_T soar_count;
} soar_telemetry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_fsw_telemetry_
#define DEFINED_TYPEDEF_FOR_fsw_telemetry_

typedef struct {
  uint8_T gnc_mode;
  real_T sc_quat[4];
  real_T sc_body_rates_radps[3];
  real_T cmd_quat[4];
  real_T cmd_body_rates_radps[3];
  real_T mekf_3sigma_rad[6];
  real_T mekf_bias_radps[3];
  uint8_T mekf_telem;
  real_T r_eci_m[3];
  real_T ace_err;
  boolean_T eclipse;
  uint8_T sgp4_flag;
  boolean_T sc_above_gs;
  boolean_T sc_above_targ;
  uint8_T target_gen_flag;
  real_T elev_gs_rad;
  real_T elev_targ_rad;
  uint8_T ss_valid;
  soar_telemetry soar_telemetry;
} fsw_telemetry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_uC8Xc175cGBtSSOvSj41EH_
#define DEFINED_TYPEDEF_FOR_struct_uC8Xc175cGBtSSOvSj41EH_

typedef struct {
  real_T M2KM;
  real_T KM2M;
  real_T DEG2RAD;
  real_T RAD2DEG;
  real_T DAY2SEC;
  real_T SEC2DAY;
  real_T RPS2RPM;
  real_T RPM2RPS;
  real_T AU2KM;
  real_T nT2T;
  real_T T2uT;
  real_T uT2T;
  real_T HR2SEC;
  real_T SEC2HR;
  real_T MIN2SEC;
  real_T SEC2MIN;
} struct_uC8Xc175cGBtSSOvSj41EH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_LsbUp1xYs692VVhI5UzbQ_
#define DEFINED_TYPEDEF_FOR_struct_LsbUp1xYs692VVhI5UzbQ_

typedef struct {
  real_T small;
  real_T w_earth_rads[3];
  real_T mu_earth_km3s2;
  real_T r_earth_km;
  real_T JDJ2000;
  real_T reorientation_controller_threshold_max;
  real_T reorientation_controller_threshold_min;
} struct_LsbUp1xYs692VVhI5UzbQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_GZOflLxJTmjoWqiNgReVGF_
#define DEFINED_TYPEDEF_FOR_struct_GZOflLxJTmjoWqiNgReVGF_

typedef struct {
  struct_uC8Xc175cGBtSSOvSj41EH convert;
  struct_LsbUp1xYs692VVhI5UzbQ global;
} struct_GZOflLxJTmjoWqiNgReVGF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hcMqPYcWPjLMA5nqS4HlhF_
#define DEFINED_TYPEDEF_FOR_struct_hcMqPYcWPjLMA5nqS4HlhF_

typedef struct {
  real_T z_len;
  real_T x_len;
  real_T y_len;
  real_T m_2u;
  real_T xB_dir[3];
  real_T yB_dir[3];
  real_T zB_dir[3];
  real_T J[9];
  real_T point_of_pressure[3];
  real_T CD;
  real_T Ax;
  real_T Ay;
  real_T Az;
  real_T res_dipole_Am2[3];
  real_T ss_offset_rad;
} struct_hcMqPYcWPjLMA5nqS4HlhF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lN2YsXjCVtoPVWe7cEOXXE_
#define DEFINED_TYPEDEF_FOR_struct_lN2YsXjCVtoPVWe7cEOXXE_

typedef struct {
  real_T supercycle_length;
  real_T mtq_cycles_on_before;
  real_T mag_cycles_on_after;
} struct_lN2YsXjCVtoPVWe7cEOXXE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NCcOMvCWlps7sCVHML6Az_
#define DEFINED_TYPEDEF_FOR_struct_NCcOMvCWlps7sCVHML6Az_

typedef struct {
  real_T sunseek_hysteresis_deg;
  real_T sun_sensor_range_deg;
  real_T mag_rotate[27];
  real_T mag_offset[9];
  real_T mag_static_range;
  real_T mag_max_err;
  real_T gyro_rotate[27];
  real_T gyro_offset[9];
  real_T gyro_static_range;
  real_T gyro_max_err;
  struct_lN2YsXjCVtoPVWe7cEOXXE duty_cycle;
  real_T time_offset;
} struct_NCcOMvCWlps7sCVHML6Az;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_J2UklKDOwboHskfNE7JQOD_
#define DEFINED_TYPEDEF_FOR_struct_J2UklKDOwboHskfNE7JQOD_

typedef struct {
  real_T C[9];
} struct_J2UklKDOwboHskfNE7JQOD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4mAysgmjVCepNgQ3iGFExC_
#define DEFINED_TYPEDEF_FOR_struct_4mAysgmjVCepNgQ3iGFExC_

typedef struct {
  real_T J[9];
  real_T A[12];
  real_T Phi[12];
  real_T w_max;
  real_T torque_max;
  real_T T[16];
  real_T zeta;
  real_T wn;
  real_T qd[4];
  real_T q0[4];
  real_T K[9];
  real_T ep;
  real_T K_init[9];
  real_T P[9];
  real_T C[9];
  real_T saturation;
  real_T w0[3];
  real_T qd1[4];
} struct_4mAysgmjVCepNgQ3iGFExC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_E7pklKk8fUDfDlISOX4J2E_
#define DEFINED_TYPEDEF_FOR_struct_E7pklKk8fUDfDlISOX4J2E_

typedef struct {
  real_T Kd[3];
  real_T Kp[3];
  real_T qd[4];
} struct_E7pklKk8fUDfDlISOX4J2E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_KQTbCxf2e6F8dqBxCYNd3B_
#define DEFINED_TYPEDEF_FOR_struct_KQTbCxf2e6F8dqBxCYNd3B_

typedef struct {
  real_T I_max_uA;
  real_T I_thresh_uA;
  real_T Kp[9];
  real_T Kd[9];
} struct_KQTbCxf2e6F8dqBxCYNd3B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ygRvE79kyQHuDo9YHub4pE_
#define DEFINED_TYPEDEF_FOR_struct_ygRvE79kyQHuDo9YHub4pE_

typedef struct {
  struct_J2UklKDOwboHskfNE7JQOD asmc;
  struct_4mAysgmjVCepNgQ3iGFExC reorientation;
  struct_E7pklKk8fUDfDlISOX4J2E tracking;
  struct_KQTbCxf2e6F8dqBxCYNd3B sunseek;
} struct_ygRvE79kyQHuDo9YHub4pE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ALaTLbFFdrOQfrpiCzt8RC_
#define DEFINED_TYPEDEF_FOR_struct_ALaTLbFFdrOQfrpiCzt8RC_

typedef struct {
  real_T gain[9];
} struct_ALaTLbFFdrOQfrpiCzt8RC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_sjGR4uJoghqpNi58kA44jH_
#define DEFINED_TYPEDEF_FOR_struct_sjGR4uJoghqpNi58kA44jH_

typedef struct {
  real_T Beta_init[3];
  real_T quat_est_init[4];
  real_T activate_triad;
  real_T sun_valid_rt;
  real_T mag_valid_rt;
  real_T gyro_valid_rt;
  real_T sc2sun_eci_unit_rt[3];
  real_T B_eci_unit_rt[3];
  real_T sunsensor_body_rad_rt[3];
  real_T mag_body_rt[3];
  real_T gyro_meas_rt[3];
  real_T triad_input_rt;
  real_T Pchol_init[36];
} struct_sjGR4uJoghqpNi58kA44jH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_1d2yLpcXIEmznanXEUSVdG_
#define DEFINED_TYPEDEF_FOR_struct_1d2yLpcXIEmznanXEUSVdG_

typedef struct {
  struct_sjGR4uJoghqpNi58kA44jH ic;
  real_T dt;
  real_T sample_time_s;
  real_T Qchol[36];
  real_T Rchol[36];
  real_T triad_parallel_tol_deg;
  real_T triad_cycles;
  real_T slerp_parameter;
  real_T bias_max;
} struct_1d2yLpcXIEmznanXEUSVdG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_uvZZXEmcGmqC8NnG7wMTaF_
#define DEFINED_TYPEDEF_FOR_struct_uvZZXEmcGmqC8NnG7wMTaF_

typedef struct {
  real_T lat_gd_deg;
  real_T lon_deg;
  real_T alt_m;
  real_T ll_deg[2];
  real_T C_F2T[9];
  real_T ecef_m[3];
  real_T min_elev_rad;
} struct_uvZZXEmcGmqC8NnG7wMTaF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0BTTf8ytoovWMG04k485fG_
#define DEFINED_TYPEDEF_FOR_struct_0BTTf8ytoovWMG04k485fG_

typedef struct {
  uint8_T gnc_mode_ic;
  real_T body_rate_threshold_max;
  real_T body_rate_threshold_min;
  real_T h_max;
  real_T h_min;
  real_T orbital_period_s;
  real_T desat_timer_buffer_s;
} struct_0BTTf8ytoovWMG04k485fG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Fxs15VniWr6vzefGObgabH_
#define DEFINED_TYPEDEF_FOR_struct_Fxs15VniWr6vzefGObgabH_

typedef struct {
  real_T sample_time_s;
  struct_GZOflLxJTmjoWqiNgReVGF constants;
  struct_hcMqPYcWPjLMA5nqS4HlhF scParams;
  RWA allocator;
  struct_NCcOMvCWlps7sCVHML6Az sensors;
  struct_ygRvE79kyQHuDo9YHub4pE controllers;
  struct_ALaTLbFFdrOQfrpiCzt8RC desatcontrollerParams;
  struct_1d2yLpcXIEmznanXEUSVdG estimation;
  struct_uvZZXEmcGmqC8NnG7wMTaF ground_targs[2];
  struct_0BTTf8ytoovWMG04k485fG mode_select;
} struct_Fxs15VniWr6vzefGObgabH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mXHmnFZbCKtZPydMLAMkZ_
#define DEFINED_TYPEDEF_FOR_struct_mXHmnFZbCKtZPydMLAMkZ_

typedef struct {
  real_T SP_ON;
  real_T GG_ON;
  real_T ATMO_ON;
  real_T sensor_noise;
  real_T actuator_model;
} struct_mXHmnFZbCKtZPydMLAMkZ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JbgCpa8V0l2Kc8SnhaB5PB_
#define DEFINED_TYPEDEF_FOR_struct_JbgCpa8V0l2Kc8SnhaB5PB_

typedef struct {
  real_T DUT1;
  real_T TAI_offset;
  real_T DTT_TAI;
  real_T Y_epoch;
  real_T epoch_utc_s;
} struct_JbgCpa8V0l2Kc8SnhaB5PB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ugDGsGgHJ4nVuOZYLPeQa_
#define DEFINED_TYPEDEF_FOR_struct_ugDGsGgHJ4nVuOZYLPeQa_

typedef struct {
  real_T rpm[4];
  real_T radps[4];
  real_T h_wheel_Nms[4];
  real_T h_body_Nms[3];
  real_T power_W[4];
  real_T torque_wheel_Nm[4];
  real_T torque_body_Nm[3];
  real_T rt1;
  real_T deriv1;
} struct_ugDGsGgHJ4nVuOZYLPeQa;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_apbxn7DeDmDM4RVkXhXRyD_
#define DEFINED_TYPEDEF_FOR_struct_apbxn7DeDmDM4RVkXhXRyD_

typedef struct {
  real_T YMDHMS_UTC[6];
  real_T JD_UTC;
  real_T ecef_2_eci[9];
  real_T q_eci2body[4];
  real_T w_body_radps[3];
  real_T r_eci_km[3];
  real_T v_eci_kmps[3];
  real_T lat_deg;
  real_T lon_deg;
  real_T alt_m;
  real_T all[13];
  struct_ugDGsGgHJ4nVuOZYLPeQa rwa;
} struct_apbxn7DeDmDM4RVkXhXRyD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_UeVLhi9OFruBZjlrfb864_
#define DEFINED_TYPEDEF_FOR_struct_UeVLhi9OFruBZjlrfb864_

typedef struct {
  real_T psrp;
} struct_UeVLhi9OFruBZjlrfb864;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ArOtCyB7VHXhd3MEIDl0fH_
#define DEFINED_TYPEDEF_FOR_struct_ArOtCyB7VHXhd3MEIDl0fH_

typedef struct {
  real_T kp;
  real_T ki;
  real_T kd;
  real_T filter_coeff;
  real_T setpt_weight_b;
  real_T setpt_weight_c;
} struct_ArOtCyB7VHXhd3MEIDl0fH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_UuJXqXb00ns8Mq33CIqEgF_
#define DEFINED_TYPEDEF_FOR_struct_UuJXqXb00ns8Mq33CIqEgF_

typedef struct {
  real_T num_wheels;
  real_T inertia[16];
  real_T time_cnst[4];
  real_T cant_angle;
  real_T A_wheel2body[12];
  real_T tf_num1[2];
  real_T tf_den1[2];
  real_T tf_num2[2];
  real_T tf_den2[2];
  struct_ArOtCyB7VHXhd3MEIDl0fH control;
  real_T max_RPM;
  real_T max_RADPS;
  real_T max_torque_Nm;
  real_T visc_fric_coef;
  real_T stall_torque;
  real_T mech_eff;
  real_T rpm_variance[4];
  real_T seed[4];
} struct_UuJXqXb00ns8Mq33CIqEgF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Gf3s5hEjTA9ZSpiBcpBY8B_
#define DEFINED_TYPEDEF_FOR_struct_Gf3s5hEjTA9ZSpiBcpBY8B_

typedef struct {
  real_T normals[15];
  real_T n_coils[3];
  real_T id_x[2];
  real_T id_y[2];
  real_T id_z;
  real_T max_dipoles_Am2[3];
  real_T voltage[3];
  real_T max_current[3];
  real_T P_max_W[3];
  real_T dipole_to_power[3];
  real_T noise;
  real_T variance;
  real_T seed[5];
} struct_Gf3s5hEjTA9ZSpiBcpBY8B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_jkRrmLpPW9kZwNixmayRsB_
#define DEFINED_TYPEDEF_FOR_struct_jkRrmLpPW9kZwNixmayRsB_

typedef struct {
  real_T sample_time_s;
  struct_UuJXqXb00ns8Mq33CIqEgF rwa;
  struct_Gf3s5hEjTA9ZSpiBcpBY8B mtq;
} struct_jkRrmLpPW9kZwNixmayRsB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XgREHZ6dPIxctYstc2hl9G_
#define DEFINED_TYPEDEF_FOR_struct_XgREHZ6dPIxctYstc2hl9G_

typedef struct {
  real_T B_eci_T[3];
} struct_XgREHZ6dPIxctYstc2hl9G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_uosaFTaL3hHze9ZZePOqMC_
#define DEFINED_TYPEDEF_FOR_struct_uosaFTaL3hHze9ZZePOqMC_

typedef struct {
  real_T N_mag;
  real_T sample_time_s;
  struct_XgREHZ6dPIxctYstc2hl9G ic;
  boolean_T noise[3];
  real_T seed[3];
  real_T err_uT[9];
  real_T B_min_uT[3];
  real_T B_max_uT[3];
} struct_uosaFTaL3hHze9ZZePOqMC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hznt7ii3Hz9dAKRGeTMWFD_
#define DEFINED_TYPEDEF_FOR_struct_hznt7ii3Hz9dAKRGeTMWFD_

typedef struct {
  real_T N_gyro;
  real_T sample_time_s;
  real_T seed_arw[9];
  real_T seed_rrw[9];
  real_T arw[3];
  real_T rrw[3];
  real_T bias_init[9];
  real_T resolution[3];
  real_T w_min[3];
  real_T w_max[3];
} struct_hznt7ii3Hz9dAKRGeTMWFD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OlzxbWXdu0RMoiuBpgmlWB_
#define DEFINED_TYPEDEF_FOR_struct_OlzxbWXdu0RMoiuBpgmlWB_

typedef struct {
  real_T sample_time_s;
  real_T body2ss[9];
  real_T ss2body[9];
  boolean_T noise;
  real_T deg_var;
  real_T seed[2];
  real_T range_deg;
} struct_OlzxbWXdu0RMoiuBpgmlWB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TF30b7bHfAybXZ0xOs5Si_
#define DEFINED_TYPEDEF_FOR_struct_TF30b7bHfAybXZ0xOs5Si_

typedef struct {
  real_T normals[18];
  real_T eff;
  real_T maxPower[6];
  real_T num;
} struct_TF30b7bHfAybXZ0xOs5Si;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Y0TIJL31xiJD9Bgi4VXdrD_
#define DEFINED_TYPEDEF_FOR_struct_Y0TIJL31xiJD9Bgi4VXdrD_

typedef struct {
  real_T max_current_uA;
  real_T I_out_uApW[6];
  real_T I_cutoff_uA;
} struct_Y0TIJL31xiJD9Bgi4VXdrD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TWBC1APWq7re2OKy9fLYQH_
#define DEFINED_TYPEDEF_FOR_struct_TWBC1APWq7re2OKy9fLYQH_

typedef struct {
  real_T sample_time_s;
  struct_uosaFTaL3hHze9ZZePOqMC mag;
  struct_hznt7ii3Hz9dAKRGeTMWFD gyro;
  struct_OlzxbWXdu0RMoiuBpgmlWB sun_sensor;
  struct_TF30b7bHfAybXZ0xOs5Si solar_panels;
  struct_Y0TIJL31xiJD9Bgi4VXdrD photodiodes;
} struct_TWBC1APWq7re2OKy9fLYQH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ucFtiOnWkIw6wEJIZyncnD_
#define DEFINED_TYPEDEF_FOR_struct_ucFtiOnWkIw6wEJIZyncnD_

typedef struct {
  real_T radio_tx_W;
  real_T radio_rx_W;
  real_T cdh_W;
  real_T img_active_W;
  real_T img_idle_W;
  real_T sensors_w;
  real_T eps_system_W;
  real_T sp_eff;
  real_T eff;
  real_T batt_capacity;
  real_T init_dod;
} struct_ucFtiOnWkIw6wEJIZyncnD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8XGv1kQV9vs4SVMcdRefJC_
#define DEFINED_TYPEDEF_FOR_struct_8XGv1kQV9vs4SVMcdRefJC_

typedef struct {
  struct_mXHmnFZbCKtZPydMLAMkZ opts;
  real_T sample_time_s;
  struct_GZOflLxJTmjoWqiNgReVGF constants;
  struct_hcMqPYcWPjLMA5nqS4HlhF scParams;
  struct_JbgCpa8V0l2Kc8SnhaB5PB time;
  struct_apbxn7DeDmDM4RVkXhXRyD initialConditions;
  real_T orbit_tle[9];
  struct_UeVLhi9OFruBZjlrfb864 solarPressure;
  struct_jkRrmLpPW9kZwNixmayRsB actuators;
  struct_TWBC1APWq7re2OKy9fLYQH sensors;
  struct_ucFtiOnWkIw6wEJIZyncnD power;
} struct_8XGv1kQV9vs4SVMcdRefJC;

#endif

#ifndef struct_tag_80AwAGWuE9fVrIKDJpJKoC
#define struct_tag_80AwAGWuE9fVrIKDJpJKoC

struct tag_80AwAGWuE9fVrIKDJpJKoC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[9];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_80AwAGWuE9fVrIKDJpJKoC*/

#ifndef typedef_g_dsp_private_SlidingWindowAver
#define typedef_g_dsp_private_SlidingWindowAver

typedef struct tag_80AwAGWuE9fVrIKDJpJKoC g_dsp_private_SlidingWindowAver;

#endif                               /*typedef_g_dsp_private_SlidingWindowAver*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef struct_tag_RoFcBL3cgrPNAPUZAtdOnE
#define struct_tag_RoFcBL3cgrPNAPUZAtdOnE

struct tag_RoFcBL3cgrPNAPUZAtdOnE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_private_SlidingWindowAver *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAver _pobj0;
};

#endif                                 /*struct_tag_RoFcBL3cgrPNAPUZAtdOnE*/

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_RoFcBL3cgrPNAPUZAtdOnE dsp_simulink_MovingAverage;

#endif                                 /*typedef_dsp_simulink_MovingAverage*/

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
