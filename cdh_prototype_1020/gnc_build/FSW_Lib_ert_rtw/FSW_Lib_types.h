/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_types.h
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

#ifndef RTW_HEADER_FSW_Lib_types_h_
#define RTW_HEADER_FSW_Lib_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_sensor_bus_
#define DEFINED_TYPEDEF_FOR_sensor_bus_

typedef struct {
  real_T photodiodes_A[6];
  real_T mag_body_T[9];
  boolean_T mag_meas_valid[3];
  real_T sun_meas_ss_deg[2];
  boolean_T sun_meas_valid;
  real_T gyro_body_radps[9];
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
  real_T mtq_cmd_Am2[3];
} fsw_out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_soar_telemetry_
#define DEFINED_TYPEDEF_FOR_soar_telemetry_

typedef struct {
  real_T opt_state[100];
  real_T opt_ctrl_Nm[30];
  real_T final_time_s;
  real_T exitcode[17];
  real_T slv_time_s[15];
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
  soar_telemetry soar_telemetry;
} fsw_telemetry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5hkPKMa0FDcFxgrgxJgfyF_
#define DEFINED_TYPEDEF_FOR_struct_5hkPKMa0FDcFxgrgxJgfyF_

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
  real_T HR2SEC;
  real_T SEC2HR;
  real_T MIN2SEC;
  real_T SEC2MIN;
} struct_5hkPKMa0FDcFxgrgxJgfyF;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_sBnKn22Hqg8SkfywUX92c_
#define DEFINED_TYPEDEF_FOR_struct_sBnKn22Hqg8SkfywUX92c_

typedef struct {
  struct_5hkPKMa0FDcFxgrgxJgfyF convert;
  struct_LsbUp1xYs692VVhI5UzbQ global;
} struct_sBnKn22Hqg8SkfywUX92c;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_fNaRzVs7tldK54a1kNVrp_
#define DEFINED_TYPEDEF_FOR_struct_fNaRzVs7tldK54a1kNVrp_

typedef struct {
  real_T k;
  real_T gain_tol;
  real_T k2;
  real_T B;
  real_T B_vec[3];
  real_T maxDipole;
  real_T T[25];
  real_T Jw;
  real_T ht_Nms[4];
  real_T spindown_torque_Nm;
  real_T spindown_tol;
} struct_fNaRzVs7tldK54a1kNVrp;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_2XPAZWfg9oLVe8np3girRH_
#define DEFINED_TYPEDEF_FOR_struct_2XPAZWfg9oLVe8np3girRH_

typedef struct {
  real_T I_max_A[6];
  real_T I_thresh_A[6];
  real_T Kp[9];
  real_T Kd[9];
} struct_2XPAZWfg9oLVe8np3girRH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_gIzAAeLjPY0mT6FpiovTwE_
#define DEFINED_TYPEDEF_FOR_struct_gIzAAeLjPY0mT6FpiovTwE_

typedef struct {
  struct_J2UklKDOwboHskfNE7JQOD asmc;
  struct_4mAysgmjVCepNgQ3iGFExC reorientation;
  struct_E7pklKk8fUDfDlISOX4J2E tracking;
  struct_fNaRzVs7tldK54a1kNVrp desaturation;
  struct_2XPAZWfg9oLVe8np3girRH sunseek;
} struct_gIzAAeLjPY0mT6FpiovTwE;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_lz0fPaz3Z8TTtZHs2W9TdG_
#define DEFINED_TYPEDEF_FOR_struct_lz0fPaz3Z8TTtZHs2W9TdG_

typedef struct {
  struct_sjGR4uJoghqpNi58kA44jH ic;
  real_T dt;
  real_T sample_time_s;
  real_T Qchol[36];
  real_T Rchol[36];
  real_T triad_parallel_tol_deg;
  real_T triad_cycles;
} struct_lz0fPaz3Z8TTtZHs2W9TdG;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_hx0U0gkXPDexOeaCkvdAhE_
#define DEFINED_TYPEDEF_FOR_struct_hx0U0gkXPDexOeaCkvdAhE_

typedef struct {
  uint8_T gnc_mode_ic;
  real_T body_rate_threshold_max;
  real_T body_rate_threshold_min;
  real_T RWA_RPM_threshold_max_inf;
  real_T RWA_RPM_threshold_min_inf;
  real_T RWA_RPM_threshold_max_2norm;
  real_T RWA_RPM_threshold_min_2norm;
  real_T orbital_period_s;
  real_T desat_timer_buffer_s;
} struct_hx0U0gkXPDexOeaCkvdAhE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8mf3xToKJnyppB5pwGzpM_
#define DEFINED_TYPEDEF_FOR_struct_8mf3xToKJnyppB5pwGzpM_

typedef struct {
  real_T sample_time_s;
  struct_sBnKn22Hqg8SkfywUX92c constants;
  struct_hcMqPYcWPjLMA5nqS4HlhF scParams;
  RWA allocator;
  struct_gIzAAeLjPY0mT6FpiovTwE controllers;
  struct_lz0fPaz3Z8TTtZHs2W9TdG estimation;
  struct_uvZZXEmcGmqC8NnG7wMTaF ground_targs[2];
  struct_hx0U0gkXPDexOeaCkvdAhE mode_select;
} struct_8mf3xToKJnyppB5pwGzpM;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_5aFhqg3TClW2Srid1ddWkC_
#define DEFINED_TYPEDEF_FOR_struct_5aFhqg3TClW2Srid1ddWkC_

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
  real_T seed[3];
} struct_5aFhqg3TClW2Srid1ddWkC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_STJWXKDSLcFpk2Piq0wdm_
#define DEFINED_TYPEDEF_FOR_struct_STJWXKDSLcFpk2Piq0wdm_

typedef struct {
  real_T sample_time_s;
  struct_UuJXqXb00ns8Mq33CIqEgF rwa;
  struct_5aFhqg3TClW2Srid1ddWkC mtq;
} struct_STJWXKDSLcFpk2Piq0wdm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XgREHZ6dPIxctYstc2hl9G_
#define DEFINED_TYPEDEF_FOR_struct_XgREHZ6dPIxctYstc2hl9G_

typedef struct {
  real_T B_eci_T[3];
} struct_XgREHZ6dPIxctYstc2hl9G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_erUuItUhpKAMZI8uGpZzOE_
#define DEFINED_TYPEDEF_FOR_struct_erUuItUhpKAMZI8uGpZzOE_

typedef struct {
  real_T N_mag;
  real_T sample_time_s;
  struct_XgREHZ6dPIxctYstc2hl9G ic;
  boolean_T noise[3];
  real_T seed[3];
  real_T err_T[9];
  real_T B_min_T[3];
  real_T B_max_T[3];
} struct_erUuItUhpKAMZI8uGpZzOE;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_vntiZsCO5pd7AmjHqO57CH_
#define DEFINED_TYPEDEF_FOR_struct_vntiZsCO5pd7AmjHqO57CH_

typedef struct {
  real_T I_out_ApW;
  real_T I_cutoff_A[6];
} struct_vntiZsCO5pd7AmjHqO57CH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eonpuErkY5TLFvayma83kB_
#define DEFINED_TYPEDEF_FOR_struct_eonpuErkY5TLFvayma83kB_

typedef struct {
  real_T sample_time_s;
  struct_erUuItUhpKAMZI8uGpZzOE mag;
  struct_hznt7ii3Hz9dAKRGeTMWFD gyro;
  struct_OlzxbWXdu0RMoiuBpgmlWB sun_sensor;
  struct_TF30b7bHfAybXZ0xOs5Si solar_panels;
  struct_vntiZsCO5pd7AmjHqO57CH photodiodes;
} struct_eonpuErkY5TLFvayma83kB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ekk7PRFrO5tcwjOzq3M2kH_
#define DEFINED_TYPEDEF_FOR_struct_ekk7PRFrO5tcwjOzq3M2kH_

typedef struct {
  struct_mXHmnFZbCKtZPydMLAMkZ opts;
  real_T sample_time_s;
  struct_sBnKn22Hqg8SkfywUX92c constants;
  struct_hcMqPYcWPjLMA5nqS4HlhF scParams;
  struct_JbgCpa8V0l2Kc8SnhaB5PB time;
  struct_apbxn7DeDmDM4RVkXhXRyD initialConditions;
  real_T orbit_tle[9];
  struct_UeVLhi9OFruBZjlrfb864 solarPressure;
  struct_STJWXKDSLcFpk2Piq0wdm actuators;
  struct_eonpuErkY5TLFvayma83kB sensors;
} struct_ekk7PRFrO5tcwjOzq3M2kH;

#endif

/* Custom Type definition for MATLAB Function: '<S320>/SOLVE' */
#ifndef struct_tag_spK1YOgs4pY8UFC2YcSXAaD
#define struct_tag_spK1YOgs4pY8UFC2YcSXAaD

struct tag_spK1YOgs4pY8UFC2YcSXAaD
{
  real_T quat_in[4];
  real_T quat_cmd[4];
  real_T cmd_state[10];
};

#endif                                 /*struct_tag_spK1YOgs4pY8UFC2YcSXAaD*/

#ifndef typedef_spK1YOgs4pY8UFC2YcSXAaD
#define typedef_spK1YOgs4pY8UFC2YcSXAaD

typedef struct tag_spK1YOgs4pY8UFC2YcSXAaD spK1YOgs4pY8UFC2YcSXAaD;

#endif                                 /*typedef_spK1YOgs4pY8UFC2YcSXAaD*/

#ifndef struct_tag_sMmiHugone66OG2OjltJFsG
#define struct_tag_sMmiHugone66OG2OjltJFsG

struct tag_sMmiHugone66OG2OjltJFsG
{
  spK1YOgs4pY8UFC2YcSXAaD ic;
  char_T config[3];
  real_T N;
  real_T dt;
  real_T sample_time_s;
  real_T interp_sample_time_s;
  int32_T c_size;
  int32_T Air_size;
  int32_T Ajc_size;
  int32_T Apr_size;
  int32_T b_size;
  int32_T Gir_size;
  int32_T Gjc_size;
  int32_T Gpr_size;
  int32_T h_size;
  int32_T q_size;
  int32_T y_size;
  int32_T l_dim;
  int32_T soc_dim[21];
  real_T inertia[9];
  real_T w_max;
  real_T T_max;
  real_T s_min;
  real_T s_max;
  real_T w_v;
};

#endif                                 /*struct_tag_sMmiHugone66OG2OjltJFsG*/

#ifndef typedef_sMmiHugone66OG2OjltJFsG
#define typedef_sMmiHugone66OG2OjltJFsG

typedef struct tag_sMmiHugone66OG2OjltJFsG sMmiHugone66OG2OjltJFsG;

#endif                                 /*typedef_sMmiHugone66OG2OjltJFsG*/

/* Custom Type definition for MATLAB Function: '<S173>/MATLAB Function3' */
#ifndef struct_tag_sDhqqHSaWgekpUC3I3OzHlF
#define struct_tag_sDhqqHSaWgekpUC3I3OzHlF

struct tag_sDhqqHSaWgekpUC3I3OzHlF
{
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
  real_T HR2SEC;
  real_T SEC2HR;
  real_T MIN2SEC;
  real_T SEC2MIN;
};

#endif                                 /*struct_tag_sDhqqHSaWgekpUC3I3OzHlF*/

#ifndef typedef_sDhqqHSaWgekpUC3I3OzHlF
#define typedef_sDhqqHSaWgekpUC3I3OzHlF

typedef struct tag_sDhqqHSaWgekpUC3I3OzHlF sDhqqHSaWgekpUC3I3OzHlF;

#endif                                 /*typedef_sDhqqHSaWgekpUC3I3OzHlF*/

/* Custom Type definition for MATLAB Function: '<S11>/MATLAB Function' */
#ifndef struct_tag_sGQM4myGiYiBxOQ9ywaOf1B
#define struct_tag_sGQM4myGiYiBxOQ9ywaOf1B

struct tag_sGQM4myGiYiBxOQ9ywaOf1B
{
  real_T Kd[3];
  real_T Kp[3];
  real_T qd[4];
};

#endif                                 /*struct_tag_sGQM4myGiYiBxOQ9ywaOf1B*/

#ifndef typedef_sGQM4myGiYiBxOQ9ywaOf1B
#define typedef_sGQM4myGiYiBxOQ9ywaOf1B

typedef struct tag_sGQM4myGiYiBxOQ9ywaOf1B sGQM4myGiYiBxOQ9ywaOf1B;

#endif                                 /*typedef_sGQM4myGiYiBxOQ9ywaOf1B*/

#ifndef struct_tag_sZcxJKWLgD1dFbRZRCJVkmD
#define struct_tag_sZcxJKWLgD1dFbRZRCJVkmD

struct tag_sZcxJKWLgD1dFbRZRCJVkmD
{
  uint8_T gnc_mode_ic;
  real_T body_rate_threshold_max;
  real_T body_rate_threshold_min;
  real_T RWA_RPM_threshold_max_inf;
  real_T RWA_RPM_threshold_min_inf;
  real_T RWA_RPM_threshold_max_2norm;
  real_T RWA_RPM_threshold_min_2norm;
  real_T orbital_period_s;
  real_T desat_timer_buffer_s;
};

#endif                                 /*struct_tag_sZcxJKWLgD1dFbRZRCJVkmD*/

#ifndef typedef_sZcxJKWLgD1dFbRZRCJVkmD
#define typedef_sZcxJKWLgD1dFbRZRCJVkmD

typedef struct tag_sZcxJKWLgD1dFbRZRCJVkmD sZcxJKWLgD1dFbRZRCJVkmD;

#endif                                 /*typedef_sZcxJKWLgD1dFbRZRCJVkmD*/

#ifndef struct_tag_spGKsvEVm7uA89hv31XX4LH
#define struct_tag_spGKsvEVm7uA89hv31XX4LH

struct tag_spGKsvEVm7uA89hv31XX4LH
{
  uint32_T MissingPlacement;
  uint32_T ComparisonMethod;
};

#endif                                 /*struct_tag_spGKsvEVm7uA89hv31XX4LH*/

#ifndef typedef_spGKsvEVm7uA89hv31XX4LH
#define typedef_spGKsvEVm7uA89hv31XX4LH

typedef struct tag_spGKsvEVm7uA89hv31XX4LH spGKsvEVm7uA89hv31XX4LH;

#endif                                 /*typedef_spGKsvEVm7uA89hv31XX4LH*/

/* Custom Type definition for MATLAB Function: '<S173>/MATLAB Function3' */
#ifndef struct_tag_sNSv6TMNL0MdS2T7gRyN8lD
#define struct_tag_sNSv6TMNL0MdS2T7gRyN8lD

struct tag_sNSv6TMNL0MdS2T7gRyN8lD
{
  real_T small;
  real_T w_earth_rads[3];
  real_T mu_earth_km3s2;
  real_T r_earth_km;
  real_T JDJ2000;
  real_T c_reorientation_controller_thre;
  real_T d_reorientation_controller_thre;
};

#endif                                 /*struct_tag_sNSv6TMNL0MdS2T7gRyN8lD*/

#ifndef typedef_sNSv6TMNL0MdS2T7gRyN8lD
#define typedef_sNSv6TMNL0MdS2T7gRyN8lD

typedef struct tag_sNSv6TMNL0MdS2T7gRyN8lD sNSv6TMNL0MdS2T7gRyN8lD;

#endif                                 /*typedef_sNSv6TMNL0MdS2T7gRyN8lD*/

#ifndef struct_tag_sX4S3ZufBB2jGJFwPj3TpCE
#define struct_tag_sX4S3ZufBB2jGJFwPj3TpCE

struct tag_sX4S3ZufBB2jGJFwPj3TpCE
{
  sDhqqHSaWgekpUC3I3OzHlF convert;
  sNSv6TMNL0MdS2T7gRyN8lD global;
};

#endif                                 /*struct_tag_sX4S3ZufBB2jGJFwPj3TpCE*/

#ifndef typedef_sX4S3ZufBB2jGJFwPj3TpCE
#define typedef_sX4S3ZufBB2jGJFwPj3TpCE

typedef struct tag_sX4S3ZufBB2jGJFwPj3TpCE sX4S3ZufBB2jGJFwPj3TpCE;

#endif                                 /*typedef_sX4S3ZufBB2jGJFwPj3TpCE*/

#ifndef struct_tag_s5tYIlxQip0ggvIGvthlXkD
#define struct_tag_s5tYIlxQip0ggvIGvthlXkD

struct tag_s5tYIlxQip0ggvIGvthlXkD
{
  real_T SP_ON;
  real_T GG_ON;
  real_T ATMO_ON;
  real_T sensor_noise;
  real_T actuator_model;
};

#endif                                 /*struct_tag_s5tYIlxQip0ggvIGvthlXkD*/

#ifndef typedef_s5tYIlxQip0ggvIGvthlXkD
#define typedef_s5tYIlxQip0ggvIGvthlXkD

typedef struct tag_s5tYIlxQip0ggvIGvthlXkD s5tYIlxQip0ggvIGvthlXkD;

#endif                                 /*typedef_s5tYIlxQip0ggvIGvthlXkD*/

#ifndef struct_tag_sqSqGNn3gUTKt4KSSCrpoWF
#define struct_tag_sqSqGNn3gUTKt4KSSCrpoWF

struct tag_sqSqGNn3gUTKt4KSSCrpoWF
{
  real_T DUT1;
  real_T TAI_offset;
  real_T DTT_TAI;
  real_T Y_epoch;
  real_T epoch_utc_s;
};

#endif                                 /*struct_tag_sqSqGNn3gUTKt4KSSCrpoWF*/

#ifndef typedef_sqSqGNn3gUTKt4KSSCrpoWF
#define typedef_sqSqGNn3gUTKt4KSSCrpoWF

typedef struct tag_sqSqGNn3gUTKt4KSSCrpoWF sqSqGNn3gUTKt4KSSCrpoWF;

#endif                                 /*typedef_sqSqGNn3gUTKt4KSSCrpoWF*/

#ifndef struct_tag_suUCPVD2VlFkYMXiAW6aqn
#define struct_tag_suUCPVD2VlFkYMXiAW6aqn

struct tag_suUCPVD2VlFkYMXiAW6aqn
{
  real_T rpm[4];
  real_T radps[4];
  real_T h_wheel_Nms[4];
  real_T h_body_Nms[3];
  real_T power_W[4];
  real_T torque_wheel_Nm[4];
  real_T torque_body_Nm[3];
  real_T rt1;
  real_T deriv1;
};

#endif                                 /*struct_tag_suUCPVD2VlFkYMXiAW6aqn*/

#ifndef typedef_suUCPVD2VlFkYMXiAW6aqn
#define typedef_suUCPVD2VlFkYMXiAW6aqn

typedef struct tag_suUCPVD2VlFkYMXiAW6aqn suUCPVD2VlFkYMXiAW6aqn;

#endif                                 /*typedef_suUCPVD2VlFkYMXiAW6aqn*/

#ifndef struct_tag_sB337z0fL6GYO7sKWdgRIbD
#define struct_tag_sB337z0fL6GYO7sKWdgRIbD

struct tag_sB337z0fL6GYO7sKWdgRIbD
{
  real_T psrp;
};

#endif                                 /*struct_tag_sB337z0fL6GYO7sKWdgRIbD*/

#ifndef typedef_sB337z0fL6GYO7sKWdgRIbD
#define typedef_sB337z0fL6GYO7sKWdgRIbD

typedef struct tag_sB337z0fL6GYO7sKWdgRIbD sB337z0fL6GYO7sKWdgRIbD;

#endif                                 /*typedef_sB337z0fL6GYO7sKWdgRIbD*/

#ifndef struct_tag_snvPWZWIlUgojQcxP1R4llD
#define struct_tag_snvPWZWIlUgojQcxP1R4llD

struct tag_snvPWZWIlUgojQcxP1R4llD
{
  real_T kp;
  real_T ki;
  real_T kd;
  real_T filter_coeff;
  real_T setpt_weight_b;
  real_T setpt_weight_c;
};

#endif                                 /*struct_tag_snvPWZWIlUgojQcxP1R4llD*/

#ifndef typedef_snvPWZWIlUgojQcxP1R4llD
#define typedef_snvPWZWIlUgojQcxP1R4llD

typedef struct tag_snvPWZWIlUgojQcxP1R4llD snvPWZWIlUgojQcxP1R4llD;

#endif                                 /*typedef_snvPWZWIlUgojQcxP1R4llD*/

#ifndef struct_tag_sPlirOq7zE6BnsbUaorrKU
#define struct_tag_sPlirOq7zE6BnsbUaorrKU

struct tag_sPlirOq7zE6BnsbUaorrKU
{
  real_T B_eci_T[3];
};

#endif                                 /*struct_tag_sPlirOq7zE6BnsbUaorrKU*/

#ifndef typedef_sPlirOq7zE6BnsbUaorrKU
#define typedef_sPlirOq7zE6BnsbUaorrKU

typedef struct tag_sPlirOq7zE6BnsbUaorrKU sPlirOq7zE6BnsbUaorrKU;

#endif                                 /*typedef_sPlirOq7zE6BnsbUaorrKU*/

#ifndef struct_tag_sceQFFiSPmohIdeDgtFqdpE
#define struct_tag_sceQFFiSPmohIdeDgtFqdpE

struct tag_sceQFFiSPmohIdeDgtFqdpE
{
  real_T I_out_ApW;
  real_T I_cutoff_A[6];
};

#endif                                 /*struct_tag_sceQFFiSPmohIdeDgtFqdpE*/

#ifndef typedef_sceQFFiSPmohIdeDgtFqdpE
#define typedef_sceQFFiSPmohIdeDgtFqdpE

typedef struct tag_sceQFFiSPmohIdeDgtFqdpE sceQFFiSPmohIdeDgtFqdpE;

#endif                                 /*typedef_sceQFFiSPmohIdeDgtFqdpE*/

#ifndef struct_tag_sIIsAqBdfUcnX36HXXlqwpE
#define struct_tag_sIIsAqBdfUcnX36HXXlqwpE

struct tag_sIIsAqBdfUcnX36HXXlqwpE
{
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
};

#endif                                 /*struct_tag_sIIsAqBdfUcnX36HXXlqwpE*/

#ifndef typedef_sIIsAqBdfUcnX36HXXlqwpE
#define typedef_sIIsAqBdfUcnX36HXXlqwpE

typedef struct tag_sIIsAqBdfUcnX36HXXlqwpE sIIsAqBdfUcnX36HXXlqwpE;

#endif                                 /*typedef_sIIsAqBdfUcnX36HXXlqwpE*/

/* Custom Type definition for MATLAB Function: '<S11>/MATLAB Function' */
#ifndef struct_tag_shLwpDRaC1Zw3TVrzQq09JH
#define struct_tag_shLwpDRaC1Zw3TVrzQq09JH

struct tag_shLwpDRaC1Zw3TVrzQq09JH
{
  real_T A_wheel2body[12];
  real_T inertia[4];
  real_T inv_inertia[4];
  real_T max_torque_Nm;
  real_T max_RPM;
  uint8_T num_facet;
  real_T h_targ_wheel_Nms[4];
  real_T feedback_gain;
  uint8_T id_facet[12];
  uint8_T id_facet_complement[12];
  real_T w_facet[18];
  real_T g_facet[6];
  real_T inrm2[6];
};

#endif                                 /*struct_tag_shLwpDRaC1Zw3TVrzQq09JH*/

#ifndef typedef_shLwpDRaC1Zw3TVrzQq09JH
#define typedef_shLwpDRaC1Zw3TVrzQq09JH

typedef struct tag_shLwpDRaC1Zw3TVrzQq09JH shLwpDRaC1Zw3TVrzQq09JH;

#endif                                 /*typedef_shLwpDRaC1Zw3TVrzQq09JH*/

#ifndef struct_tag_s9WykccdPGX0bqXWeAbrqdG
#define struct_tag_s9WykccdPGX0bqXWeAbrqdG

struct tag_s9WykccdPGX0bqXWeAbrqdG
{
  real_T C[9];
};

#endif                                 /*struct_tag_s9WykccdPGX0bqXWeAbrqdG*/

#ifndef typedef_s9WykccdPGX0bqXWeAbrqdG
#define typedef_s9WykccdPGX0bqXWeAbrqdG

typedef struct tag_s9WykccdPGX0bqXWeAbrqdG s9WykccdPGX0bqXWeAbrqdG;

#endif                                 /*typedef_s9WykccdPGX0bqXWeAbrqdG*/

#ifndef struct_tag_s2J2oLRGiuyx0bH5TSh3byB
#define struct_tag_s2J2oLRGiuyx0bH5TSh3byB

struct tag_s2J2oLRGiuyx0bH5TSh3byB
{
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
};

#endif                                 /*struct_tag_s2J2oLRGiuyx0bH5TSh3byB*/

#ifndef typedef_s2J2oLRGiuyx0bH5TSh3byB
#define typedef_s2J2oLRGiuyx0bH5TSh3byB

typedef struct tag_s2J2oLRGiuyx0bH5TSh3byB s2J2oLRGiuyx0bH5TSh3byB;

#endif                                 /*typedef_s2J2oLRGiuyx0bH5TSh3byB*/

#ifndef struct_tag_sHlnVihx3qQ0PmoTWhfayQE
#define struct_tag_sHlnVihx3qQ0PmoTWhfayQE

struct tag_sHlnVihx3qQ0PmoTWhfayQE
{
  real_T k;
  real_T gain_tol;
  real_T k2;
  real_T B;
  real_T B_vec[3];
  real_T maxDipole;
  real_T T[25];
  real_T Jw;
  real_T ht_Nms[4];
  real_T spindown_torque_Nm;
  real_T spindown_tol;
};

#endif                                 /*struct_tag_sHlnVihx3qQ0PmoTWhfayQE*/

#ifndef typedef_sHlnVihx3qQ0PmoTWhfayQE
#define typedef_sHlnVihx3qQ0PmoTWhfayQE

typedef struct tag_sHlnVihx3qQ0PmoTWhfayQE sHlnVihx3qQ0PmoTWhfayQE;

#endif                                 /*typedef_sHlnVihx3qQ0PmoTWhfayQE*/

#ifndef struct_tag_sZV0ePCFGwwPB6DzTOdFxM
#define struct_tag_sZV0ePCFGwwPB6DzTOdFxM

struct tag_sZV0ePCFGwwPB6DzTOdFxM
{
  real_T I_max_A[6];
  real_T I_thresh_A[6];
  real_T Kp[9];
  real_T Kd[9];
};

#endif                                 /*struct_tag_sZV0ePCFGwwPB6DzTOdFxM*/

#ifndef typedef_sZV0ePCFGwwPB6DzTOdFxM
#define typedef_sZV0ePCFGwwPB6DzTOdFxM

typedef struct tag_sZV0ePCFGwwPB6DzTOdFxM sZV0ePCFGwwPB6DzTOdFxM;

#endif                                 /*typedef_sZV0ePCFGwwPB6DzTOdFxM*/

#ifndef struct_tag_stdB3pfuAB5xNY4S7jL5ONC
#define struct_tag_stdB3pfuAB5xNY4S7jL5ONC

struct tag_stdB3pfuAB5xNY4S7jL5ONC
{
  s9WykccdPGX0bqXWeAbrqdG asmc;
  s2J2oLRGiuyx0bH5TSh3byB reorientation;
  sGQM4myGiYiBxOQ9ywaOf1B tracking;
  sHlnVihx3qQ0PmoTWhfayQE desaturation;
  sZV0ePCFGwwPB6DzTOdFxM sunseek;
};

#endif                                 /*struct_tag_stdB3pfuAB5xNY4S7jL5ONC*/

#ifndef typedef_stdB3pfuAB5xNY4S7jL5ONC
#define typedef_stdB3pfuAB5xNY4S7jL5ONC

typedef struct tag_stdB3pfuAB5xNY4S7jL5ONC stdB3pfuAB5xNY4S7jL5ONC;

#endif                                 /*typedef_stdB3pfuAB5xNY4S7jL5ONC*/

#ifndef struct_tag_sNa8bVLO2Wc0cuWeHZ2pbKD
#define struct_tag_sNa8bVLO2Wc0cuWeHZ2pbKD

struct tag_sNa8bVLO2Wc0cuWeHZ2pbKD
{
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
};

#endif                                 /*struct_tag_sNa8bVLO2Wc0cuWeHZ2pbKD*/

#ifndef typedef_sNa8bVLO2Wc0cuWeHZ2pbKD
#define typedef_sNa8bVLO2Wc0cuWeHZ2pbKD

typedef struct tag_sNa8bVLO2Wc0cuWeHZ2pbKD sNa8bVLO2Wc0cuWeHZ2pbKD;

#endif                                 /*typedef_sNa8bVLO2Wc0cuWeHZ2pbKD*/

#ifndef struct_tag_sSQ7EYW1PaOrHAfjwrslAuE
#define struct_tag_sSQ7EYW1PaOrHAfjwrslAuE

struct tag_sSQ7EYW1PaOrHAfjwrslAuE
{
  sNa8bVLO2Wc0cuWeHZ2pbKD ic;
  real_T dt;
  real_T sample_time_s;
  real_T Qchol[36];
  real_T Rchol[36];
  real_T triad_parallel_tol_deg;
  real_T triad_cycles;
};

#endif                                 /*struct_tag_sSQ7EYW1PaOrHAfjwrslAuE*/

#ifndef typedef_sSQ7EYW1PaOrHAfjwrslAuE
#define typedef_sSQ7EYW1PaOrHAfjwrslAuE

typedef struct tag_sSQ7EYW1PaOrHAfjwrslAuE sSQ7EYW1PaOrHAfjwrslAuE;

#endif                                 /*typedef_sSQ7EYW1PaOrHAfjwrslAuE*/

#ifndef struct_tag_s4UGWrK5T4vXCYuUQmez9lD
#define struct_tag_s4UGWrK5T4vXCYuUQmez9lD

struct tag_s4UGWrK5T4vXCYuUQmez9lD
{
  real_T lat_gd_deg;
  real_T lon_deg;
  real_T alt_m;
  real_T ll_deg[2];
  real_T C_F2T[9];
  real_T ecef_m[3];
  real_T min_elev_rad;
};

#endif                                 /*struct_tag_s4UGWrK5T4vXCYuUQmez9lD*/

#ifndef typedef_s4UGWrK5T4vXCYuUQmez9lD
#define typedef_s4UGWrK5T4vXCYuUQmez9lD

typedef struct tag_s4UGWrK5T4vXCYuUQmez9lD s4UGWrK5T4vXCYuUQmez9lD;

#endif                                 /*typedef_s4UGWrK5T4vXCYuUQmez9lD*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E
#define typedef_sJCxfmxS8gBOONUZjbjUd9E

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E;

#endif                                 /*typedef_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef struct_tag_somWgQ2sydVuuNGkq028sMC
#define struct_tag_somWgQ2sydVuuNGkq028sMC

struct tag_somWgQ2sydVuuNGkq028sMC
{
  real_T sample_time_s;
  sX4S3ZufBB2jGJFwPj3TpCE constants;
  sIIsAqBdfUcnX36HXXlqwpE scParams;
  shLwpDRaC1Zw3TVrzQq09JH allocator;
  stdB3pfuAB5xNY4S7jL5ONC controllers;
  sSQ7EYW1PaOrHAfjwrslAuE estimation;
  s4UGWrK5T4vXCYuUQmez9lD ground_targs[2];
  sZcxJKWLgD1dFbRZRCJVkmD mode_select;
};

#endif                                 /*struct_tag_somWgQ2sydVuuNGkq028sMC*/

#ifndef typedef_somWgQ2sydVuuNGkq028sMC
#define typedef_somWgQ2sydVuuNGkq028sMC

typedef struct tag_somWgQ2sydVuuNGkq028sMC somWgQ2sydVuuNGkq028sMC;

#endif                                 /*typedef_somWgQ2sydVuuNGkq028sMC*/

/* Custom Type definition for MATLAB Function: '<S173>/MATLAB Function3' */
#ifndef struct_tag_sOnLmDaoKki9WcDzElHkUHH
#define struct_tag_sOnLmDaoKki9WcDzElHkUHH

struct tag_sOnLmDaoKki9WcDzElHkUHH
{
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
  suUCPVD2VlFkYMXiAW6aqn rwa;
};

#endif                                 /*struct_tag_sOnLmDaoKki9WcDzElHkUHH*/

#ifndef typedef_sOnLmDaoKki9WcDzElHkUHH
#define typedef_sOnLmDaoKki9WcDzElHkUHH

typedef struct tag_sOnLmDaoKki9WcDzElHkUHH sOnLmDaoKki9WcDzElHkUHH;

#endif                                 /*typedef_sOnLmDaoKki9WcDzElHkUHH*/

#ifndef struct_tag_sEKz4fwTXocCehpmdvpMWBE
#define struct_tag_sEKz4fwTXocCehpmdvpMWBE

struct tag_sEKz4fwTXocCehpmdvpMWBE
{
  real_T num_wheels;
  real_T inertia[16];
  real_T time_cnst[4];
  real_T cant_angle;
  real_T A_wheel2body[12];
  real_T tf_num1[2];
  real_T tf_den1[2];
  real_T tf_num2[2];
  real_T tf_den2[2];
  snvPWZWIlUgojQcxP1R4llD control;
  real_T max_RPM;
  real_T max_RADPS;
  real_T max_torque_Nm;
  real_T visc_fric_coef;
  real_T stall_torque;
  real_T mech_eff;
  real_T rpm_variance[4];
  real_T seed[4];
};

#endif                                 /*struct_tag_sEKz4fwTXocCehpmdvpMWBE*/

#ifndef typedef_sEKz4fwTXocCehpmdvpMWBE
#define typedef_sEKz4fwTXocCehpmdvpMWBE

typedef struct tag_sEKz4fwTXocCehpmdvpMWBE sEKz4fwTXocCehpmdvpMWBE;

#endif                                 /*typedef_sEKz4fwTXocCehpmdvpMWBE*/

#ifndef struct_tag_s38jRCRF5ppY5pD7idgzrAE
#define struct_tag_s38jRCRF5ppY5pD7idgzrAE

struct tag_s38jRCRF5ppY5pD7idgzrAE
{
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
  real_T seed[3];
};

#endif                                 /*struct_tag_s38jRCRF5ppY5pD7idgzrAE*/

#ifndef typedef_s38jRCRF5ppY5pD7idgzrAE
#define typedef_s38jRCRF5ppY5pD7idgzrAE

typedef struct tag_s38jRCRF5ppY5pD7idgzrAE s38jRCRF5ppY5pD7idgzrAE;

#endif                                 /*typedef_s38jRCRF5ppY5pD7idgzrAE*/

#ifndef struct_tag_s6jBSbfCvEiWdJOI06rDacG
#define struct_tag_s6jBSbfCvEiWdJOI06rDacG

struct tag_s6jBSbfCvEiWdJOI06rDacG
{
  real_T sample_time_s;
  sEKz4fwTXocCehpmdvpMWBE rwa;
  s38jRCRF5ppY5pD7idgzrAE mtq;
};

#endif                                 /*struct_tag_s6jBSbfCvEiWdJOI06rDacG*/

#ifndef typedef_s6jBSbfCvEiWdJOI06rDacG
#define typedef_s6jBSbfCvEiWdJOI06rDacG

typedef struct tag_s6jBSbfCvEiWdJOI06rDacG s6jBSbfCvEiWdJOI06rDacG;

#endif                                 /*typedef_s6jBSbfCvEiWdJOI06rDacG*/

#ifndef struct_tag_sdfmESDU8nWUj0aVGrXOJRB
#define struct_tag_sdfmESDU8nWUj0aVGrXOJRB

struct tag_sdfmESDU8nWUj0aVGrXOJRB
{
  real_T N_mag;
  real_T sample_time_s;
  sPlirOq7zE6BnsbUaorrKU ic;
  boolean_T noise[3];
  real_T seed[3];
  real_T err_T[9];
  real_T B_min_T[3];
  real_T B_max_T[3];
};

#endif                                 /*struct_tag_sdfmESDU8nWUj0aVGrXOJRB*/

#ifndef typedef_sdfmESDU8nWUj0aVGrXOJRB
#define typedef_sdfmESDU8nWUj0aVGrXOJRB

typedef struct tag_sdfmESDU8nWUj0aVGrXOJRB sdfmESDU8nWUj0aVGrXOJRB;

#endif                                 /*typedef_sdfmESDU8nWUj0aVGrXOJRB*/

#ifndef struct_tag_s60st6OZWiHigQ1rQ8UhjTF
#define struct_tag_s60st6OZWiHigQ1rQ8UhjTF

struct tag_s60st6OZWiHigQ1rQ8UhjTF
{
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
};

#endif                                 /*struct_tag_s60st6OZWiHigQ1rQ8UhjTF*/

#ifndef typedef_s60st6OZWiHigQ1rQ8UhjTF
#define typedef_s60st6OZWiHigQ1rQ8UhjTF

typedef struct tag_s60st6OZWiHigQ1rQ8UhjTF s60st6OZWiHigQ1rQ8UhjTF;

#endif                                 /*typedef_s60st6OZWiHigQ1rQ8UhjTF*/

#ifndef struct_tag_s9P56hx7Cs4V9mVm7uB788B
#define struct_tag_s9P56hx7Cs4V9mVm7uB788B

struct tag_s9P56hx7Cs4V9mVm7uB788B
{
  real_T sample_time_s;
  real_T body2ss[9];
  real_T ss2body[9];
  boolean_T noise;
  real_T deg_var;
  real_T seed[2];
  real_T range_deg;
};

#endif                                 /*struct_tag_s9P56hx7Cs4V9mVm7uB788B*/

#ifndef typedef_s9P56hx7Cs4V9mVm7uB788B
#define typedef_s9P56hx7Cs4V9mVm7uB788B

typedef struct tag_s9P56hx7Cs4V9mVm7uB788B s9P56hx7Cs4V9mVm7uB788B;

#endif                                 /*typedef_s9P56hx7Cs4V9mVm7uB788B*/

#ifndef struct_tag_sA20pgyLLIq8SfspJg8FOE
#define struct_tag_sA20pgyLLIq8SfspJg8FOE

struct tag_sA20pgyLLIq8SfspJg8FOE
{
  real_T normals[18];
  real_T eff;
  real_T maxPower[6];
  real_T num;
};

#endif                                 /*struct_tag_sA20pgyLLIq8SfspJg8FOE*/

#ifndef typedef_sA20pgyLLIq8SfspJg8FOE
#define typedef_sA20pgyLLIq8SfspJg8FOE

typedef struct tag_sA20pgyLLIq8SfspJg8FOE sA20pgyLLIq8SfspJg8FOE;

#endif                                 /*typedef_sA20pgyLLIq8SfspJg8FOE*/

#ifndef struct_tag_sDmwOs0lGDH5shSkZ89cj2F
#define struct_tag_sDmwOs0lGDH5shSkZ89cj2F

struct tag_sDmwOs0lGDH5shSkZ89cj2F
{
  real_T sample_time_s;
  sdfmESDU8nWUj0aVGrXOJRB mag;
  s60st6OZWiHigQ1rQ8UhjTF gyro;
  s9P56hx7Cs4V9mVm7uB788B sun_sensor;
  sA20pgyLLIq8SfspJg8FOE solar_panels;
  sceQFFiSPmohIdeDgtFqdpE photodiodes;
};

#endif                                 /*struct_tag_sDmwOs0lGDH5shSkZ89cj2F*/

#ifndef typedef_sDmwOs0lGDH5shSkZ89cj2F
#define typedef_sDmwOs0lGDH5shSkZ89cj2F

typedef struct tag_sDmwOs0lGDH5shSkZ89cj2F sDmwOs0lGDH5shSkZ89cj2F;

#endif                                 /*typedef_sDmwOs0lGDH5shSkZ89cj2F*/

#ifndef struct_tag_sBfAH4ICESoccsNqeUsMEP
#define struct_tag_sBfAH4ICESoccsNqeUsMEP

struct tag_sBfAH4ICESoccsNqeUsMEP
{
  s5tYIlxQip0ggvIGvthlXkD opts;
  real_T sample_time_s;
  sX4S3ZufBB2jGJFwPj3TpCE constants;
  sIIsAqBdfUcnX36HXXlqwpE scParams;
  sqSqGNn3gUTKt4KSSCrpoWF time;
  sOnLmDaoKki9WcDzElHkUHH initialConditions;
  real_T orbit_tle[9];
  sB337z0fL6GYO7sKWdgRIbD solarPressure;
  s6jBSbfCvEiWdJOI06rDacG actuators;
  sDmwOs0lGDH5shSkZ89cj2F sensors;
};

#endif                                 /*struct_tag_sBfAH4ICESoccsNqeUsMEP*/

#ifndef typedef_sBfAH4ICESoccsNqeUsMEP
#define typedef_sBfAH4ICESoccsNqeUsMEP

typedef struct tag_sBfAH4ICESoccsNqeUsMEP sBfAH4ICESoccsNqeUsMEP;

#endif                                 /*typedef_sBfAH4ICESoccsNqeUsMEP*/

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
