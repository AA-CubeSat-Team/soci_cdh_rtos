/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_Lib_h_
#define RTW_HEADER_FSW_Lib_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
#define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Child system includes */
#include "PD_Controller_Lib.h"
#include "asmController_lib.h"
#include "mode_select_lib.h"
#include "null_control_lib.h"
#include "quat_err_lib.h"
#include "rt_sys_FSW_Lib_12.h"
#include "rt_sys_FSW_Lib_16.h"
#include "rt_sys_FSW_Lib_23.h"
#include "rwa_allocation_lib.h"
#include "sunSeek_lib.h"
#include "target_generation_lib.h"
#include "target_groundpass_lib.h"
#include "twonorm.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_mode_select_lib mode_select_lib_p;/* '<S1>/mode_select_lib' */
  DW_rwa_allocation_lib rwa_allocation_lib_m;/* '<S6>/rwa_allocation_lib' */
  real_T Merge[3];                     /* '<S87>/Merge' */
  real_T Merge1[3];                    /* '<S87>/Merge1' */
  real_T Merge_f[4];                   /* '<S162>/Merge' */
  real_T Merge_l[4];                   /* '<S47>/Merge' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S92>/Discrete-Time Integrator' */
  real_T Divide_DWORK4;                /* '<S111>/Divide' */
  real_T Divide_DWORK4_o;              /* '<S103>/Divide' */
  uint32_T Median_Index[3];            /* '<S153>/Median' */
  uint32_T Median_Index_e[3];          /* '<S154>/Median' */
  boolean_T Relay_Mode[2];             /* '<S159>/Relay' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Switch;                 /* '<S89>/Switch' */
  const real_T CreateDiagonalMatrix[16];/* '<S109>/Create Diagonal Matrix' */
  const real_T h_w_nom_body_Nms[3];    /* '<S109>/Matrix Multiply4' */
  const real_T CreateDiagonalMatrix_e[16];/* '<S101>/Create Diagonal Matrix' */
  const real_T h_w_nom_body_Nms_m[3];  /* '<S101>/Matrix Multiply4' */
  ConstB_mode_select_lib mode_select_lib_p;/* '<S1>/mode_select_lib' */
  ConstB_rwa_allocation_lib rwa_allocation_lib_m;/* '<S6>/rwa_allocation_lib' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: fswParams.allocator)
   * Referenced by:
   *   '<S133>/Constant'
   *   '<S137>/Constant1'
   */
  RWA pooled1;

  /* Pooled Parameter (Expression: -eye(3))
   * Referenced by:
   *   '<S77>/Bias1'
   *   '<S196>/Bias1'
   */
  real_T pooled9[9];

  /* Expression: fswParams.controllers.asmc.C
   * Referenced by: '<S98>/Constant'
   */
  real_T Constant_Value_a[9];

  /* Pooled Parameter (Expression: fswParams.allocator.A_wheel2body)
   * Referenced by:
   *   '<S143>/A_wheel2body '
   *   '<S135>/Constant'
   *   '<S101>/A_wheel2body '
   *   '<S109>/A_wheel2body '
   */
  real_T pooled13[12];

  /* Pooled Parameter (Expression: fswParams.scParams.J)
   * Referenced by:
   *   '<S143>/scParams.J '
   *   '<S101>/scParams.J '
   *   '<S109>/scParams.J '
   */
  real_T pooled16[9];

  /* Pooled Parameter (Expression: fswParams.desatcontrollerParams.gain)
   * Referenced by:
   *   '<S103>/Gain3'
   *   '<S111>/Gain3'
   */
  real_T pooled17[9];

  /* Expression: fswParams.controllers.sunseek.Kd
   * Referenced by: '<S116>/Kd'
   */
  real_T Kd_Gain[9];

  /* Expression: fswParams.controllers.sunseek.Kp
   * Referenced by: '<S116>/Kp'
   */
  real_T Kp_Gain[9];

  /* Expression: pinv
   * Referenced by: '<S134>/Constant'
   */
  real_T Constant_Value_i[12];

  /* Expression: simParams.sensors.sun_sensor.ss2body
   * Referenced by: '<S152>/Constant1'
   */
  real_T Constant1_Value[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S153>/Constant13'
   *   '<S153>/Constant20'
   *   '<S153>/Constant22'
   */
  real_T pooled25[9];

  /* Expression: fswParams.sensors.mag_rotate(:,:,1)
   * Referenced by: '<S154>/Constant13'
   */
  real_T Constant13_Value[9];

  /* Expression: fswParams.sensors.mag_rotate(:,:,2)
   * Referenced by: '<S154>/Constant20'
   */
  real_T Constant20_Value[9];

  /* Expression: fswParams.sensors.mag_rotate(:,:,3)
   * Referenced by: '<S154>/Constant22'
   */
  real_T Constant22_Value[9];

  /* Expression: [true;true;true;true]
   * Referenced by: '<S1>/Constant20'
   */
  boolean_T Constant20_Value_b[4];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T photodiodes_uA[5];            /* '<Root>/photodiodes_uA' */
  real_T mag_mag_uT[9];                /* '<Root>/mag_mag_uT' */
  boolean_T mag_meas_valid[3];         /* '<Root>/mag_meas_valid' */
  real_T sun_meas_ss_deg[2];           /* '<Root>/sun_meas_ss_deg' */
  boolean_T sun_meas_valid;            /* '<Root>/sun_meas_valid' */
  real_T gyro_gyro_radps[9];           /* '<Root>/gyro_gyro_radps' */
  boolean_T gyro_meas_valid[3];        /* '<Root>/gyro_meas_valid' */
  real_T orbit_tle[9];                 /* '<Root>/orbit_tle' */
  real_T MET_utc_s;                    /* '<Root>/MET_utc_s' */
  real_T MET_soar_utc_s;               /* '<Root>/MET_soar_utc_s' */
  real_T quat_soar_cmd[4];             /* '<Root>/quat_soar_cmd' */
  real_T target_latlonalt[3];          /* '<Root>/target_latlonalt' */
  real_T telecom[6];                   /* '<Root>/telecom' */
  boolean_T triad_override;            /* '<Root>/triad_override' */
  boolean_T mtq_valid[5];              /* '<Root>/mtq_valid' */
  boolean_T rwa_valid[4];              /* '<Root>/rwa_valid' */
  real_T rwa_rpm[4];                   /* '<Root>/rwa_rpm' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T rwa_cmd_rpm[4];               /* '<Root>/rwa_cmd_rpm' */
  real_T mtq_cmd_Am2[5];               /* '<Root>/mtq_cmd_Am2' */
  uint8_T gnc_mode;                    /* '<Root>/gnc_mode' */
  real_T sc_quat[4];                   /* '<Root>/sc_quat' */
  real_T sc_body_rates_radps[3];       /* '<Root>/sc_body_rates_radps' */
  real_T cmd_quat[4];                  /* '<Root>/cmd_quat' */
  real_T cmd_body_rates_radps[3];      /* '<Root>/cmd_body_rates_radps' */
  real_T mekf_3sigma_rad[6];           /* '<Root>/mekf_3sigma_rad' */
  real_T mekf_bias_radps[3];           /* '<Root>/mekf_bias_radps' */
  uint8_T mekf_telem;                  /* '<Root>/mekf_telem' */
  real_T r_eci_m[3];                   /* '<Root>/r_eci_m' */
  real_T ace_err;                      /* '<Root>/ace_err' */
  boolean_T eclipse;                   /* '<Root>/eclipse' */
  uint8_T sgp4_flag;                   /* '<Root>/sgp4_flag' */
  boolean_T sc_above_gs;               /* '<Root>/sc_above_gs' */
  boolean_T sc_above_targ;             /* '<Root>/sc_above_targ' */
  uint8_T target_gen_flag;             /* '<Root>/target_gen_flag' */
  real_T elev_gs_rad;                  /* '<Root>/elev_gs_rad' */
  real_T elev_targ_rad;                /* '<Root>/elev_targ_rad' */
  uint8_T ss_valid;                    /* '<Root>/ss_valid' */
  soar_telemetry soar_telemetry_e;     /* '<Root>/soar_telemetry' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */
extern const soar_telemetry FSW_Lib_rtZsoar_telemetry;/* soar_telemetry ground */
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void FSW_Lib_initialize(void);
extern void FSW_Lib_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S1>/Display4' : Unused code path elimination
 * Block '<S1>/Display6' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S99>/DutyCycleAdjustment' : Unused code path elimination
 * Block '<S102>/Gain' : Unused code path elimination
 * Block '<S102>/Identity Matrix' : Unused code path elimination
 * Block '<S102>/Matrix Multiply7' : Unused code path elimination
 * Block '<S102>/Matrix Multiply8' : Unused code path elimination
 * Block '<S102>/Reshape' : Unused code path elimination
 * Block '<S102>/Reshape1' : Unused code path elimination
 * Block '<S102>/Subtract2' : Unused code path elimination
 * Block '<S107>/DutyCycleAdjustment' : Unused code path elimination
 * Block '<S110>/Gain' : Unused code path elimination
 * Block '<S110>/Identity Matrix' : Unused code path elimination
 * Block '<S110>/Matrix Multiply7' : Unused code path elimination
 * Block '<S110>/Matrix Multiply8' : Unused code path elimination
 * Block '<S110>/Reshape' : Unused code path elimination
 * Block '<S110>/Reshape1' : Unused code path elimination
 * Block '<S110>/Subtract2' : Unused code path elimination
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S8>/Constant10' : Unused code path elimination
 * Block '<S8>/Constant11' : Unused code path elimination
 * Block '<S8>/Constant12' : Unused code path elimination
 * Block '<S8>/Constant13' : Unused code path elimination
 * Block '<S8>/Constant14' : Unused code path elimination
 * Block '<S8>/Constant15' : Unused code path elimination
 * Block '<S8>/Constant16' : Unused code path elimination
 * Block '<S8>/Constant17' : Unused code path elimination
 * Block '<S8>/Constant18' : Unused code path elimination
 * Block '<S8>/Constant19' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Constant4' : Unused code path elimination
 * Block '<S8>/Constant5' : Unused code path elimination
 * Block '<S8>/Constant6' : Unused code path elimination
 * Block '<S8>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant8' : Unused code path elimination
 * Block '<S8>/Constant9' : Unused code path elimination
 * Block '<S160>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Rate Transition8' : Unused code path elimination
 * Block '<S2>/Reshape' : Reshape block reduction
 * Block '<S3>/Reshape' : Reshape block reduction
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S31>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S42>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S47>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S77>/Reshape' : Reshape block reduction
 * Block '<S84>/Reshape' : Reshape block reduction
 * Block '<S142>/Reshape' : Reshape block reduction
 * Block '<S162>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S196>/Reshape' : Reshape block reduction
 * Block '<S203>/Reshape' : Reshape block reduction
 * Block '<S11>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S1>/Constant21' : Unused code path elimination
 * Block '<S86>/mtq_off_cmd' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Main_Sim_Build/FSW_Lib')    - opens subsystem Main_Sim_Build/FSW_Lib
 * hilite_system('Main_Sim_Build/FSW_Lib/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main_Sim_Build'
 * '<S1>'   : 'Main_Sim_Build/FSW_Lib'
 * '<S2>'   : 'Main_Sim_Build/FSW_Lib/Convert 2-D to 1-D'
 * '<S3>'   : 'Main_Sim_Build/FSW_Lib/Convert 2-D to 1-D1'
 * '<S4>'   : 'Main_Sim_Build/FSW_Lib/Subsystem'
 * '<S5>'   : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm'
 * '<S6>'   : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib'
 * '<S7>'   : 'Main_Sim_Build/FSW_Lib/fsw_out_bus'
 * '<S8>'   : 'Main_Sim_Build/FSW_Lib/fsw_telemetry_bus'
 * '<S9>'   : 'Main_Sim_Build/FSW_Lib/mode_select_lib'
 * '<S10>'  : 'Main_Sim_Build/FSW_Lib/sensor_processing'
 * '<S11>'  : 'Main_Sim_Build/FSW_Lib/target_generation_lib'
 * '<S12>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/MATLAB Function'
 * '<S13>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/MATLAB Function1'
 * '<S14>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/MATLAB Function3'
 * '<S15>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib'
 * '<S16>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/sunVectorEclipse_lib'
 * '<S17>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1'
 * '<S18>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1'
 * '<S19>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/MATLAB Function'
 * '<S20>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/magField_custom_lib'
 * '<S21>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A11'
 * '<S22>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A12'
 * '<S23>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A13'
 * '<S24>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A21'
 * '<S25>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A22'
 * '<S26>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A23'
 * '<S27>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A31'
 * '<S28>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A32'
 * '<S29>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/A33'
 * '<S30>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/Angle Conversion'
 * '<S31>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/Direction Cosine Matrix ECEF to NED1/Create Transformation Matrix'
 * '<S32>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/magField_lib/magField_custom_lib/MATLAB Function'
 * '<S33>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/sunVectorEclipse_lib/MATLAB Function'
 * '<S34>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/sunVectorEclipse_lib/Normalize Vector'
 * '<S35>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/sunVectorEclipse_lib/eclipseCheck_lib'
 * '<S36>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/sunVectorEclipse_lib/eclipseCheck_lib/MATLAB Function'
 * '<S37>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/Compare To Constant'
 * '<S38>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/Normalize Vector'
 * '<S39>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/Normalize Vector1'
 * '<S40>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/get_C_F2T'
 * '<S41>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/twonorm'
 * '<S42>'  : 'Main_Sim_Build/FSW_Lib/Subsystem/target_groundpass_lib1/get_C_F2T/Create 3x3 Matrix'
 * '<S43>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Cross Product4'
 * '<S44>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Cross Product5'
 * '<S45>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Cross Product6'
 * '<S46>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Cross Product7'
 * '<S47>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2'
 * '<S48>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace'
 * '<S49>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace'
 * '<S50>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM'
 * '<S51>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/trace(DCM)'
 * '<S52>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S53>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S54>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S55>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/diag(DCM)'
 * '<S56>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S57>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S58>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S59>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S60>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S61>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S62>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S63>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S64>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S65>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S66>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S67>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S68>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S69>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S70>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S71>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S72>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S73>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S74>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error'
 * '<S75>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S76>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper'
 * '<S77>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S78>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper'
 * '<S79>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S80>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S81>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S82>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S83>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S84>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S85>'  : 'Main_Sim_Build/FSW_Lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S86>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/command_converter_lib'
 * '<S87>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib'
 * '<S88>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/degree error'
 * '<S89>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib'
 * '<S90>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib'
 * '<S91>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib'
 * '<S92>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/command_converter_lib/torque-2-RPM'
 * '<S93>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm'
 * '<S94>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation'
 * '<S95>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control'
 * '<S96>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation'
 * '<S97>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek'
 * '<S98>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/asmController_lib'
 * '<S99>'  : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib'
 * '<S100>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Normalize Vector'
 * '<S101>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem'
 * '<S102>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem1'
 * '<S103>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem2'
 * '<S104>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/twonorm'
 * '<S105>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem2/Cross Product1'
 * '<S106>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/PD_Controller_Lib'
 * '<S107>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib'
 * '<S108>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Normalize Vector'
 * '<S109>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem'
 * '<S110>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem1'
 * '<S111>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem2'
 * '<S112>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/twonorm'
 * '<S113>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem2/Cross Product1'
 * '<S114>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control/null_control_lib1'
 * '<S115>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation/PD_Controller_Lib'
 * '<S116>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib'
 * '<S117>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis'
 * '<S118>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis/Cross Product'
 * '<S119>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis/Normalize Vector'
 * '<S120>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem'
 * '<S121>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem1'
 * '<S122>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem2'
 * '<S123>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem3'
 * '<S124>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem4'
 * '<S125>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem5'
 * '<S126>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Conjugate'
 * '<S127>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication'
 * '<S128>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/quat_rectify_lib'
 * '<S129>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q0'
 * '<S130>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q1'
 * '<S131>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q2'
 * '<S132>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q3'
 * '<S133>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/DirPreservingSaturation'
 * '<S134>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem'
 * '<S135>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1'
 * '<S136>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/DirPreservingSaturation/MATLAB Function'
 * '<S137>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/null_allocation_lib'
 * '<S138>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/null_allocation_lib/MATLAB Function'
 * '<S139>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix'
 * '<S140>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function'
 * '<S141>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function1'
 * '<S142>' : 'Main_Sim_Build/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix/Determinant of 3x3 Matrix'
 * '<S143>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/RPM_2_desat_check'
 * '<S144>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/Subsystem'
 * '<S145>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/mode_select'
 * '<S146>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/twonorm'
 * '<S147>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/RPM_2_desat_check/twonorm1'
 * '<S148>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant'
 * '<S149>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant1'
 * '<S150>' : 'Main_Sim_Build/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant2'
 * '<S151>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/Subsystem'
 * '<S152>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/angles_to_unit_vector'
 * '<S153>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/gyro_processing'
 * '<S154>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/mag_processing'
 * '<S155>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/sun_validity_logic'
 * '<S156>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/Subsystem/MATLAB Function'
 * '<S157>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/angles_to_unit_vector/create_sz'
 * '<S158>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/sun_validity_logic/sunSensorIsNotValid'
 * '<S159>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/sun_validity_logic/sunSensorIsValid'
 * '<S160>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/sun_validity_logic/sunSensorIsValid/Interval Test'
 * '<S161>' : 'Main_Sim_Build/FSW_Lib/sensor_processing/sun_validity_logic/sunSensorIsValid/Interval Test1'
 * '<S162>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions'
 * '<S163>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Normalize Vector1'
 * '<S164>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Subsystem'
 * '<S165>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/quat_rectify_lib'
 * '<S166>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/target_gen'
 * '<S167>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S168>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S169>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM'
 * '<S170>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S171>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S172>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S173>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S174>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S175>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S176>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S177>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S178>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S179>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S180>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S181>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S182>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S183>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S184>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S185>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S186>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S187>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S188>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S189>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S190>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S191>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S192>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S193>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
 * '<S194>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S195>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
 * '<S196>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S197>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
 * '<S198>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S199>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S200>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S201>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S202>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S203>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S204>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S205>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Subsystem/Compare To Constant'
 * '<S206>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Subsystem/Compare To Constant1'
 * '<S207>' : 'Main_Sim_Build/FSW_Lib/target_generation_lib/Subsystem/Compare To Constant2'
 */

/*-
 * Requirements for '<Root>': FSW_Lib
 */
#endif                                 /* RTW_HEADER_FSW_Lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
