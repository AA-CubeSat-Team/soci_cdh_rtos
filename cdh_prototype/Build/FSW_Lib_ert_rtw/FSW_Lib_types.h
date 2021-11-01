/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_types.h
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

#ifndef RTW_HEADER_FSW_Lib_types_h_
#define RTW_HEADER_FSW_Lib_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
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

#ifndef typedef_dsp_private_SlidingWindowAverag
#define typedef_dsp_private_SlidingWindowAverag

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[9];
  real_T pCumRevIndex;
} dsp_private_SlidingWindowAverag;

#endif                                 /*typedef_dsp_private_SlidingWindowAverag*/

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct {
  uint32_T f1[8];
} cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  dsp_private_SlidingWindowAverag *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage;

#endif                                 /*typedef_dsp_simulink_MovingAverage*/

/* Custom Type definition for MATLAB Function: '<S438>/SOLVE' */
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

/* Custom Type definition for MATLAB Function: '<S292>/MATLAB Function3' */
#ifndef struct_tag_sdlGDp4tlGndSwspcAWkcJF
#define struct_tag_sdlGDp4tlGndSwspcAWkcJF

struct tag_sdlGDp4tlGndSwspcAWkcJF
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
  real_T T2uT;
  real_T uT2T;
  real_T HR2SEC;
  real_T SEC2HR;
  real_T MIN2SEC;
  real_T SEC2MIN;
};

#endif                                 /*struct_tag_sdlGDp4tlGndSwspcAWkcJF*/

#ifndef typedef_sdlGDp4tlGndSwspcAWkcJF
#define typedef_sdlGDp4tlGndSwspcAWkcJF

typedef struct tag_sdlGDp4tlGndSwspcAWkcJF sdlGDp4tlGndSwspcAWkcJF;

#endif                                 /*typedef_sdlGDp4tlGndSwspcAWkcJF*/

/* Custom Type definition for MATLAB Function: '<S14>/MATLAB Function' */
#ifndef struct_tag_sKcCMs1uioYq9rfpRDTzCN
#define struct_tag_sKcCMs1uioYq9rfpRDTzCN

struct tag_sKcCMs1uioYq9rfpRDTzCN
{
  real_T supercycle_length;
  real_T mtq_cycles_on_before;
  real_T mag_cycles_on_after;
};

#endif                                 /*struct_tag_sKcCMs1uioYq9rfpRDTzCN*/

#ifndef typedef_sKcCMs1uioYq9rfpRDTzCN
#define typedef_sKcCMs1uioYq9rfpRDTzCN

typedef struct tag_sKcCMs1uioYq9rfpRDTzCN sKcCMs1uioYq9rfpRDTzCN;

#endif                                 /*typedef_sKcCMs1uioYq9rfpRDTzCN*/

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

#ifndef struct_tag_sMyvFY1T9gMoUuyl91POjEH
#define struct_tag_sMyvFY1T9gMoUuyl91POjEH

struct tag_sMyvFY1T9gMoUuyl91POjEH
{
  uint8_T gnc_mode_ic;
  real_T body_rate_threshold_max;
  real_T body_rate_threshold_min;
  real_T h_max;
  real_T h_min;
  real_T orbital_period_s;
  real_T desat_timer_buffer_s;
};

#endif                                 /*struct_tag_sMyvFY1T9gMoUuyl91POjEH*/

#ifndef typedef_sMyvFY1T9gMoUuyl91POjEH
#define typedef_sMyvFY1T9gMoUuyl91POjEH

typedef struct tag_sMyvFY1T9gMoUuyl91POjEH sMyvFY1T9gMoUuyl91POjEH;

#endif                                 /*typedef_sMyvFY1T9gMoUuyl91POjEH*/

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

/* Custom Type definition for MATLAB Function: '<S292>/MATLAB Function3' */
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

#ifndef struct_tag_sdmXjJoaSt2nVqqVAdgX7hG
#define struct_tag_sdmXjJoaSt2nVqqVAdgX7hG

struct tag_sdmXjJoaSt2nVqqVAdgX7hG
{
  sdlGDp4tlGndSwspcAWkcJF convert;
  sNSv6TMNL0MdS2T7gRyN8lD global;
};

#endif                                 /*struct_tag_sdmXjJoaSt2nVqqVAdgX7hG*/

#ifndef typedef_sdmXjJoaSt2nVqqVAdgX7hG
#define typedef_sdmXjJoaSt2nVqqVAdgX7hG

typedef struct tag_sdmXjJoaSt2nVqqVAdgX7hG sdmXjJoaSt2nVqqVAdgX7hG;

#endif                                 /*typedef_sdmXjJoaSt2nVqqVAdgX7hG*/

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

#ifndef struct_tag_sDucowpxqlB5DUe8ejlJ74G
#define struct_tag_sDucowpxqlB5DUe8ejlJ74G

struct tag_sDucowpxqlB5DUe8ejlJ74G
{
  real_T max_current_uA;
  real_T I_out_uApW[6];
  real_T I_cutoff_uA;
};

#endif                                 /*struct_tag_sDucowpxqlB5DUe8ejlJ74G*/

#ifndef typedef_sDucowpxqlB5DUe8ejlJ74G
#define typedef_sDucowpxqlB5DUe8ejlJ74G

typedef struct tag_sDucowpxqlB5DUe8ejlJ74G sDucowpxqlB5DUe8ejlJ74G;

#endif                                 /*typedef_sDucowpxqlB5DUe8ejlJ74G*/

#ifndef struct_tag_s4xbvtSY5L582vzuVYrHppD
#define struct_tag_s4xbvtSY5L582vzuVYrHppD

struct tag_s4xbvtSY5L582vzuVYrHppD
{
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
};

#endif                                 /*struct_tag_s4xbvtSY5L582vzuVYrHppD*/

#ifndef typedef_s4xbvtSY5L582vzuVYrHppD
#define typedef_s4xbvtSY5L582vzuVYrHppD

typedef struct tag_s4xbvtSY5L582vzuVYrHppD s4xbvtSY5L582vzuVYrHppD;

#endif                                 /*typedef_s4xbvtSY5L582vzuVYrHppD*/

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

/* Custom Type definition for MATLAB Function: '<S14>/MATLAB Function' */
#ifndef struct_tag_sTrGJsuc3DKnGCyDY2w84GG
#define struct_tag_sTrGJsuc3DKnGCyDY2w84GG

struct tag_sTrGJsuc3DKnGCyDY2w84GG
{
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
};

#endif                                 /*struct_tag_sTrGJsuc3DKnGCyDY2w84GG*/

#ifndef typedef_sTrGJsuc3DKnGCyDY2w84GG
#define typedef_sTrGJsuc3DKnGCyDY2w84GG

typedef struct tag_sTrGJsuc3DKnGCyDY2w84GG sTrGJsuc3DKnGCyDY2w84GG;

#endif                                 /*typedef_sTrGJsuc3DKnGCyDY2w84GG*/

#ifndef struct_tag_sj6pP1GMgfHL5A3aVWCfeW
#define struct_tag_sj6pP1GMgfHL5A3aVWCfeW

struct tag_sj6pP1GMgfHL5A3aVWCfeW
{
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
  sKcCMs1uioYq9rfpRDTzCN duty_cycle;
  real_T time_offset;
};

#endif                                 /*struct_tag_sj6pP1GMgfHL5A3aVWCfeW*/

#ifndef typedef_sj6pP1GMgfHL5A3aVWCfeW
#define typedef_sj6pP1GMgfHL5A3aVWCfeW

typedef struct tag_sj6pP1GMgfHL5A3aVWCfeW sj6pP1GMgfHL5A3aVWCfeW;

#endif                                 /*typedef_sj6pP1GMgfHL5A3aVWCfeW*/

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

#ifndef struct_tag_sZdRDXFu6i7o3zsuzlN8YhB
#define struct_tag_sZdRDXFu6i7o3zsuzlN8YhB

struct tag_sZdRDXFu6i7o3zsuzlN8YhB
{
  real_T I_max_uA;
  real_T I_thresh_uA;
  real_T Kp[9];
  real_T Kd[9];
};

#endif                                 /*struct_tag_sZdRDXFu6i7o3zsuzlN8YhB*/

#ifndef typedef_sZdRDXFu6i7o3zsuzlN8YhB
#define typedef_sZdRDXFu6i7o3zsuzlN8YhB

typedef struct tag_sZdRDXFu6i7o3zsuzlN8YhB sZdRDXFu6i7o3zsuzlN8YhB;

#endif                                 /*typedef_sZdRDXFu6i7o3zsuzlN8YhB*/

#ifndef struct_tag_spwiWNa4Y4GztNUaU109sHG
#define struct_tag_spwiWNa4Y4GztNUaU109sHG

struct tag_spwiWNa4Y4GztNUaU109sHG
{
  s9WykccdPGX0bqXWeAbrqdG asmc;
  s2J2oLRGiuyx0bH5TSh3byB reorientation;
  sGQM4myGiYiBxOQ9ywaOf1B tracking;
  sZdRDXFu6i7o3zsuzlN8YhB sunseek;
};

#endif                                 /*struct_tag_spwiWNa4Y4GztNUaU109sHG*/

#ifndef typedef_spwiWNa4Y4GztNUaU109sHG
#define typedef_spwiWNa4Y4GztNUaU109sHG

typedef struct tag_spwiWNa4Y4GztNUaU109sHG spwiWNa4Y4GztNUaU109sHG;

#endif                                 /*typedef_spwiWNa4Y4GztNUaU109sHG*/

#ifndef struct_tag_scJKliufQEEtVzpQP9TDynD
#define struct_tag_scJKliufQEEtVzpQP9TDynD

struct tag_scJKliufQEEtVzpQP9TDynD
{
  real_T gain[9];
};

#endif                                 /*struct_tag_scJKliufQEEtVzpQP9TDynD*/

#ifndef typedef_scJKliufQEEtVzpQP9TDynD
#define typedef_scJKliufQEEtVzpQP9TDynD

typedef struct tag_scJKliufQEEtVzpQP9TDynD scJKliufQEEtVzpQP9TDynD;

#endif                                 /*typedef_scJKliufQEEtVzpQP9TDynD*/

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

#ifndef struct_tag_sikv9YhSpzXCzf5OgcSOFTG
#define struct_tag_sikv9YhSpzXCzf5OgcSOFTG

struct tag_sikv9YhSpzXCzf5OgcSOFTG
{
  sNa8bVLO2Wc0cuWeHZ2pbKD ic;
  real_T dt;
  real_T sample_time_s;
  real_T Qchol[36];
  real_T Rchol[36];
  real_T triad_parallel_tol_deg;
  real_T triad_cycles;
  real_T slerp_parameter;
  real_T bias_max;
};

#endif                                 /*struct_tag_sikv9YhSpzXCzf5OgcSOFTG*/

#ifndef typedef_sikv9YhSpzXCzf5OgcSOFTG
#define typedef_sikv9YhSpzXCzf5OgcSOFTG

typedef struct tag_sikv9YhSpzXCzf5OgcSOFTG sikv9YhSpzXCzf5OgcSOFTG;

#endif                                 /*typedef_sikv9YhSpzXCzf5OgcSOFTG*/

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

#ifndef struct_tag_sz7FCAqQYh967353PHZG01
#define struct_tag_sz7FCAqQYh967353PHZG01

struct tag_sz7FCAqQYh967353PHZG01
{
  real_T sample_time_s;
  sdmXjJoaSt2nVqqVAdgX7hG constants;
  sIIsAqBdfUcnX36HXXlqwpE scParams;
  sTrGJsuc3DKnGCyDY2w84GG allocator;
  sj6pP1GMgfHL5A3aVWCfeW sensors;
  spwiWNa4Y4GztNUaU109sHG controllers;
  scJKliufQEEtVzpQP9TDynD desatcontrollerParams;
  sikv9YhSpzXCzf5OgcSOFTG estimation;
  s4UGWrK5T4vXCYuUQmez9lD ground_targs[2];
  sMyvFY1T9gMoUuyl91POjEH mode_select;
};

#endif                                 /*struct_tag_sz7FCAqQYh967353PHZG01*/

#ifndef typedef_sz7FCAqQYh967353PHZG01
#define typedef_sz7FCAqQYh967353PHZG01

typedef struct tag_sz7FCAqQYh967353PHZG01 sz7FCAqQYh967353PHZG01;

#endif                                 /*typedef_sz7FCAqQYh967353PHZG01*/

/* Custom Type definition for MATLAB Function: '<S292>/MATLAB Function3' */
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

#ifndef struct_tag_stFPoKBzrDXUBYsfr24jlXG
#define struct_tag_stFPoKBzrDXUBYsfr24jlXG

struct tag_stFPoKBzrDXUBYsfr24jlXG
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
  real_T seed[5];
};

#endif                                 /*struct_tag_stFPoKBzrDXUBYsfr24jlXG*/

#ifndef typedef_stFPoKBzrDXUBYsfr24jlXG
#define typedef_stFPoKBzrDXUBYsfr24jlXG

typedef struct tag_stFPoKBzrDXUBYsfr24jlXG stFPoKBzrDXUBYsfr24jlXG;

#endif                                 /*typedef_stFPoKBzrDXUBYsfr24jlXG*/

#ifndef struct_tag_ssQyMWDenM00TdmyM0Zn0iH
#define struct_tag_ssQyMWDenM00TdmyM0Zn0iH

struct tag_ssQyMWDenM00TdmyM0Zn0iH
{
  real_T sample_time_s;
  sEKz4fwTXocCehpmdvpMWBE rwa;
  stFPoKBzrDXUBYsfr24jlXG mtq;
};

#endif                                 /*struct_tag_ssQyMWDenM00TdmyM0Zn0iH*/

#ifndef typedef_ssQyMWDenM00TdmyM0Zn0iH
#define typedef_ssQyMWDenM00TdmyM0Zn0iH

typedef struct tag_ssQyMWDenM00TdmyM0Zn0iH ssQyMWDenM00TdmyM0Zn0iH;

#endif                                 /*typedef_ssQyMWDenM00TdmyM0Zn0iH*/

#ifndef struct_tag_seQMgXRlOAkdlwxpz3kjSk
#define struct_tag_seQMgXRlOAkdlwxpz3kjSk

struct tag_seQMgXRlOAkdlwxpz3kjSk
{
  real_T N_mag;
  real_T sample_time_s;
  sPlirOq7zE6BnsbUaorrKU ic;
  boolean_T noise[3];
  real_T seed[3];
  real_T err_uT[9];
  real_T B_min_uT[3];
  real_T B_max_uT[3];
};

#endif                                 /*struct_tag_seQMgXRlOAkdlwxpz3kjSk*/

#ifndef typedef_seQMgXRlOAkdlwxpz3kjSk
#define typedef_seQMgXRlOAkdlwxpz3kjSk

typedef struct tag_seQMgXRlOAkdlwxpz3kjSk seQMgXRlOAkdlwxpz3kjSk;

#endif                                 /*typedef_seQMgXRlOAkdlwxpz3kjSk*/

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

#ifndef struct_tag_spY15XNUI8Fubs56G6MzOQD
#define struct_tag_spY15XNUI8Fubs56G6MzOQD

struct tag_spY15XNUI8Fubs56G6MzOQD
{
  real_T sample_time_s;
  seQMgXRlOAkdlwxpz3kjSk mag;
  s60st6OZWiHigQ1rQ8UhjTF gyro;
  s9P56hx7Cs4V9mVm7uB788B sun_sensor;
  sA20pgyLLIq8SfspJg8FOE solar_panels;
  sDucowpxqlB5DUe8ejlJ74G photodiodes;
};

#endif                                 /*struct_tag_spY15XNUI8Fubs56G6MzOQD*/

#ifndef typedef_spY15XNUI8Fubs56G6MzOQD
#define typedef_spY15XNUI8Fubs56G6MzOQD

typedef struct tag_spY15XNUI8Fubs56G6MzOQD spY15XNUI8Fubs56G6MzOQD;

#endif                                 /*typedef_spY15XNUI8Fubs56G6MzOQD*/

#ifndef struct_tag_sHw966t9yoYYn7HDTq3imYB
#define struct_tag_sHw966t9yoYYn7HDTq3imYB

struct tag_sHw966t9yoYYn7HDTq3imYB
{
  s5tYIlxQip0ggvIGvthlXkD opts;
  real_T sample_time_s;
  sdmXjJoaSt2nVqqVAdgX7hG constants;
  sIIsAqBdfUcnX36HXXlqwpE scParams;
  sqSqGNn3gUTKt4KSSCrpoWF time;
  sOnLmDaoKki9WcDzElHkUHH initialConditions;
  real_T orbit_tle[9];
  sB337z0fL6GYO7sKWdgRIbD solarPressure;
  ssQyMWDenM00TdmyM0Zn0iH actuators;
  spY15XNUI8Fubs56G6MzOQD sensors;
  s4xbvtSY5L582vzuVYrHppD power;
};

#endif                                 /*struct_tag_sHw966t9yoYYn7HDTq3imYB*/

#ifndef typedef_sHw966t9yoYYn7HDTq3imYB
#define typedef_sHw966t9yoYYn7HDTq3imYB

typedef struct tag_sHw966t9yoYYn7HDTq3imYB sHw966t9yoYYn7HDTq3imYB;

#endif                                 /*typedef_sHw966t9yoYYn7HDTq3imYB*/

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
