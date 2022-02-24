/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_types.h
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

#ifndef RTW_HEADER_FSW_Lib0_types_h_
#define RTW_HEADER_FSW_Lib0_types_h_
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

/* Custom Type definition for MATLAB Function: '<S343>/SOLVE' */
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

/* Custom Type definition for MATLAB Function: '<S13>/MATLAB Function' */
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

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib0_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
