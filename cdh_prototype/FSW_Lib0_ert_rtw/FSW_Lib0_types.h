/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_types.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Oct 28 23:55:11 2021
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

#ifndef DEFINED_TYPEDEF_FOR_fsw_out_
#define DEFINED_TYPEDEF_FOR_fsw_out_

typedef struct {
  real_T rwa_cmd_rpm[4];
  real_T mtq_cmd_Am2[5];
} fsw_out;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_FSW_Lib0_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
