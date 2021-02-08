/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_types.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
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
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>
#ifndef DEFINED_TYPEDEF_FOR_sensor_bus_
#define DEFINED_TYPEDEF_FOR_sensor_bus_

typedef struct {
  real_T solar_panel_power_W[6];
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
  real_T target_latlonalt[3];
  real_T telecom[7];
  boolean_T triad_override;
} cdh_data;

#endif

#ifndef DEFINED_TYPEDEF_FOR_actuator_meas_
#define DEFINED_TYPEDEF_FOR_actuator_meas_

typedef struct {
  boolean_T mtq_valid[5];
  boolean_T rwa_valid[4];
  real_T rwa_power;
  real_T mtq_power;
  real_T rwa_rpm[4];
} actuator_meas;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RWA_
#define DEFINED_TYPEDEF_FOR_RWA_

typedef struct {
  real_T A[12];
  real_T max_norm_ellipsoid_R[3];
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
  real_T mtq_cmd_Am2[5];
  real_T gnc_telemetry[6];
} fsw_out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_zdWfWq33uVhqZPKXVHVxbB_
#define DEFINED_TYPEDEF_FOR_struct_zdWfWq33uVhqZPKXVHVxbB_

typedef struct {
  real_T SP_ON;
  real_T GG_ON;
  real_T ATMO_ON;
} struct_zdWfWq33uVhqZPKXVHVxbB;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_z8DClEC3cLlMTKRd9JCiK_
#define DEFINED_TYPEDEF_FOR_struct_z8DClEC3cLlMTKRd9JCiK_

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
} struct_z8DClEC3cLlMTKRd9JCiK;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_irgo3I0iOy67s9saFnOQhF_
#define DEFINED_TYPEDEF_FOR_struct_irgo3I0iOy67s9saFnOQhF_

typedef struct {
  real_T q_eci2body[4];
  real_T w_body_radps[3];
  real_T r_eci_km[3];
  real_T v_eci_kmps[3];
  real_T all[13];
  struct_ugDGsGgHJ4nVuOZYLPeQa rwa;
} struct_irgo3I0iOy67s9saFnOQhF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qwKhrzy6wVqKyFPwrYam8E_
#define DEFINED_TYPEDEF_FOR_struct_qwKhrzy6wVqKyFPwrYam8E_

typedef struct {
  real_T y_epoch;
  real_T DUT1;
  real_T TAI_offset;
  real_T DTT_TAI;
  real_T epoch_utc_s;
} struct_qwKhrzy6wVqKyFPwrYam8E;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_BneQ4nhYSHa1YjCQ1gpzGH_
#define DEFINED_TYPEDEF_FOR_struct_BneQ4nhYSHa1YjCQ1gpzGH_

typedef struct {
  real_T num_wheels;
  real_T inertia[16];
  real_T time_cnst[4];
  real_T cant_angle;
  real_T Aw[12];
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
  real_T rpm_variance;
} struct_BneQ4nhYSHa1YjCQ1gpzGH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_uWQb0v0SUQgmauAd71E9qF_
#define DEFINED_TYPEDEF_FOR_struct_uWQb0v0SUQgmauAd71E9qF_

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
} struct_uWQb0v0SUQgmauAd71E9qF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_iHi9HFmQQVZJuZqB5vnVV_
#define DEFINED_TYPEDEF_FOR_struct_iHi9HFmQQVZJuZqB5vnVV_

typedef struct {
  real_T sample_time_s;
  struct_BneQ4nhYSHa1YjCQ1gpzGH rwa;
  struct_uWQb0v0SUQgmauAd71E9qF mtq;
} struct_iHi9HFmQQVZJuZqB5vnVV;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_GiO7mBT6clBVP7vqwaDXa_
#define DEFINED_TYPEDEF_FOR_struct_GiO7mBT6clBVP7vqwaDXa_

typedef struct {
  real_T N_gyro;
  real_T sample_time_s;
  real_T seed_arw[9];
  real_T seed_rrw[9];
  real_T arw[3];
  real_T rrw[3];
  real_T resolution[3];
  real_T bias_init[9];
  real_T w_min[3];
  real_T w_max[3];
} struct_GiO7mBT6clBVP7vqwaDXa;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_MNfgVOlwHMaHgznKdT76fB_
#define DEFINED_TYPEDEF_FOR_struct_MNfgVOlwHMaHgznKdT76fB_

typedef struct {
  real_T sample_time_s;
  struct_erUuItUhpKAMZI8uGpZzOE mag;
  struct_GiO7mBT6clBVP7vqwaDXa gyro;
  struct_OlzxbWXdu0RMoiuBpgmlWB sun_sensor;
  struct_TF30b7bHfAybXZ0xOs5Si solar_panels;
  struct_vntiZsCO5pd7AmjHqO57CH photodiodes;
} struct_MNfgVOlwHMaHgznKdT76fB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_YSamKyMKpnxbaeOzgN7w8B_
#define DEFINED_TYPEDEF_FOR_struct_YSamKyMKpnxbaeOzgN7w8B_

typedef struct {
  struct_zdWfWq33uVhqZPKXVHVxbB opts;
  real_T sample_time_s;
  struct_sBnKn22Hqg8SkfywUX92c constants;
  struct_z8DClEC3cLlMTKRd9JCiK scParams;
  struct_irgo3I0iOy67s9saFnOQhF initialConditions;
  real_T orbit_tle[9];
  struct_qwKhrzy6wVqKyFPwrYam8E time;
  struct_UeVLhi9OFruBZjlrfb864 solarPressure;
  struct_iHi9HFmQQVZJuZqB5vnVV actuators;
  struct_MNfgVOlwHMaHgznKdT76fB sensors;
} struct_YSamKyMKpnxbaeOzgN7w8B;

#endif

/* Custom Type definition for MATLAB Function: '<S178>/MATLAB Function3' */
#ifndef struct_tag_swJB8fTkF7wwrO8Zwm7vPlC
#define struct_tag_swJB8fTkF7wwrO8Zwm7vPlC

struct tag_swJB8fTkF7wwrO8Zwm7vPlC
{
  real_T SP_ON;
  real_T GG_ON;
  real_T ATMO_ON;
};

#endif                                 /*struct_tag_swJB8fTkF7wwrO8Zwm7vPlC*/

#ifndef typedef_swJB8fTkF7wwrO8Zwm7vPlC
#define typedef_swJB8fTkF7wwrO8Zwm7vPlC

typedef struct tag_swJB8fTkF7wwrO8Zwm7vPlC swJB8fTkF7wwrO8Zwm7vPlC;

#endif                                 /*typedef_swJB8fTkF7wwrO8Zwm7vPlC*/

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

#ifndef struct_tag_sImOgELof9VGvYHP7lyGhx
#define struct_tag_sImOgELof9VGvYHP7lyGhx

struct tag_sImOgELof9VGvYHP7lyGhx
{
  real_T q_eci2body[4];
  real_T w_body_radps[3];
  real_T r_eci_km[3];
  real_T v_eci_kmps[3];
  real_T all[13];
  suUCPVD2VlFkYMXiAW6aqn rwa;
};

#endif                                 /*struct_tag_sImOgELof9VGvYHP7lyGhx*/

#ifndef typedef_sImOgELof9VGvYHP7lyGhx
#define typedef_sImOgELof9VGvYHP7lyGhx

typedef struct tag_sImOgELof9VGvYHP7lyGhx sImOgELof9VGvYHP7lyGhx;

#endif                                 /*typedef_sImOgELof9VGvYHP7lyGhx*/

#ifndef struct_tag_sGRScoq2M2IOdzeHtUdBTJE
#define struct_tag_sGRScoq2M2IOdzeHtUdBTJE

struct tag_sGRScoq2M2IOdzeHtUdBTJE
{
  real_T y_epoch;
  real_T DUT1;
  real_T TAI_offset;
  real_T DTT_TAI;
  real_T epoch_utc_s;
};

#endif                                 /*struct_tag_sGRScoq2M2IOdzeHtUdBTJE*/

#ifndef typedef_sGRScoq2M2IOdzeHtUdBTJE
#define typedef_sGRScoq2M2IOdzeHtUdBTJE

typedef struct tag_sGRScoq2M2IOdzeHtUdBTJE sGRScoq2M2IOdzeHtUdBTJE;

#endif                                 /*typedef_sGRScoq2M2IOdzeHtUdBTJE*/

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

#ifndef struct_tag_swjCqy598f424IXPwtSSeFB
#define struct_tag_swjCqy598f424IXPwtSSeFB

struct tag_swjCqy598f424IXPwtSSeFB
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
};

#endif                                 /*struct_tag_swjCqy598f424IXPwtSSeFB*/

#ifndef typedef_swjCqy598f424IXPwtSSeFB
#define typedef_swjCqy598f424IXPwtSSeFB

typedef struct tag_swjCqy598f424IXPwtSSeFB swjCqy598f424IXPwtSSeFB;

#endif                                 /*typedef_swjCqy598f424IXPwtSSeFB*/

#ifndef struct_tag_sh4RvurWQNvbClgcnBnaROD
#define struct_tag_sh4RvurWQNvbClgcnBnaROD

struct tag_sh4RvurWQNvbClgcnBnaROD
{
  real_T num_wheels;
  real_T inertia[16];
  real_T time_cnst[4];
  real_T cant_angle;
  real_T Aw[12];
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
  real_T rpm_variance;
};

#endif                                 /*struct_tag_sh4RvurWQNvbClgcnBnaROD*/

#ifndef typedef_sh4RvurWQNvbClgcnBnaROD
#define typedef_sh4RvurWQNvbClgcnBnaROD

typedef struct tag_sh4RvurWQNvbClgcnBnaROD sh4RvurWQNvbClgcnBnaROD;

#endif                                 /*typedef_sh4RvurWQNvbClgcnBnaROD*/

#ifndef struct_tag_s6hr2HnetpiUak1pzA3cWFB
#define struct_tag_s6hr2HnetpiUak1pzA3cWFB

struct tag_s6hr2HnetpiUak1pzA3cWFB
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
};

#endif                                 /*struct_tag_s6hr2HnetpiUak1pzA3cWFB*/

#ifndef typedef_s6hr2HnetpiUak1pzA3cWFB
#define typedef_s6hr2HnetpiUak1pzA3cWFB

typedef struct tag_s6hr2HnetpiUak1pzA3cWFB s6hr2HnetpiUak1pzA3cWFB;

#endif                                 /*typedef_s6hr2HnetpiUak1pzA3cWFB*/

#ifndef struct_tag_sqFz7hubuEkycecYECRhJiF
#define struct_tag_sqFz7hubuEkycecYECRhJiF

struct tag_sqFz7hubuEkycecYECRhJiF
{
  real_T sample_time_s;
  sh4RvurWQNvbClgcnBnaROD rwa;
  s6hr2HnetpiUak1pzA3cWFB mtq;
};

#endif                                 /*struct_tag_sqFz7hubuEkycecYECRhJiF*/

#ifndef typedef_sqFz7hubuEkycecYECRhJiF
#define typedef_sqFz7hubuEkycecYECRhJiF

typedef struct tag_sqFz7hubuEkycecYECRhJiF sqFz7hubuEkycecYECRhJiF;

#endif                                 /*typedef_sqFz7hubuEkycecYECRhJiF*/

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

#ifndef struct_tag_s9rNe35jkRRfWm7JjlywTFE
#define struct_tag_s9rNe35jkRRfWm7JjlywTFE

struct tag_s9rNe35jkRRfWm7JjlywTFE
{
  real_T N_gyro;
  real_T sample_time_s;
  real_T seed_arw[9];
  real_T seed_rrw[9];
  real_T arw[3];
  real_T rrw[3];
  real_T resolution[3];
  real_T bias_init[9];
  real_T w_min[3];
  real_T w_max[3];
};

#endif                                 /*struct_tag_s9rNe35jkRRfWm7JjlywTFE*/

#ifndef typedef_s9rNe35jkRRfWm7JjlywTFE
#define typedef_s9rNe35jkRRfWm7JjlywTFE

typedef struct tag_s9rNe35jkRRfWm7JjlywTFE s9rNe35jkRRfWm7JjlywTFE;

#endif                                 /*typedef_s9rNe35jkRRfWm7JjlywTFE*/

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

#ifndef struct_tag_szHNnE4U2kb4XCXP5IoMy
#define struct_tag_szHNnE4U2kb4XCXP5IoMy

struct tag_szHNnE4U2kb4XCXP5IoMy
{
  real_T sample_time_s;
  sdfmESDU8nWUj0aVGrXOJRB mag;
  s9rNe35jkRRfWm7JjlywTFE gyro;
  s9P56hx7Cs4V9mVm7uB788B sun_sensor;
  sA20pgyLLIq8SfspJg8FOE solar_panels;
  sceQFFiSPmohIdeDgtFqdpE photodiodes;
};

#endif                                 /*struct_tag_szHNnE4U2kb4XCXP5IoMy*/

#ifndef typedef_szHNnE4U2kb4XCXP5IoMy
#define typedef_szHNnE4U2kb4XCXP5IoMy

typedef struct tag_szHNnE4U2kb4XCXP5IoMy szHNnE4U2kb4XCXP5IoMy;

#endif                                 /*typedef_szHNnE4U2kb4XCXP5IoMy*/

#ifndef struct_tag_srwrGGQ2LDKNfla1gw1ClD
#define struct_tag_srwrGGQ2LDKNfla1gw1ClD

struct tag_srwrGGQ2LDKNfla1gw1ClD
{
  swJB8fTkF7wwrO8Zwm7vPlC opts;
  real_T sample_time_s;
  sX4S3ZufBB2jGJFwPj3TpCE constants;
  swjCqy598f424IXPwtSSeFB scParams;
  sImOgELof9VGvYHP7lyGhx initialConditions;
  real_T orbit_tle[9];
  sGRScoq2M2IOdzeHtUdBTJE time;
  sB337z0fL6GYO7sKWdgRIbD solarPressure;
  sqFz7hubuEkycecYECRhJiF actuators;
  szHNnE4U2kb4XCXP5IoMy sensors;
};

#endif                                 /*struct_tag_srwrGGQ2LDKNfla1gw1ClD*/

#ifndef typedef_srwrGGQ2LDKNfla1gw1ClD
#define typedef_srwrGGQ2LDKNfla1gw1ClD

typedef struct tag_srwrGGQ2LDKNfla1gw1ClD srwrGGQ2LDKNfla1gw1ClD;

#endif                                 /*typedef_srwrGGQ2LDKNfla1gw1ClD*/

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
