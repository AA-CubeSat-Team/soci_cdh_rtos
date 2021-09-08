/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.h
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

#ifndef RTW_HEADER_maggyroProcessing_lib_h_
#define RTW_HEADER_maggyroProcessing_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "twonorm.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<S2>/maggyroProcessing_lib' */
typedef struct {
  void* Assertion_slioAccessor;        /* '<S29>/Assertion' */
  void* Assertion_slioAccessor_g;      /* '<S28>/Assertion' */
  void* Assertion_slioAccessor_p;      /* '<S27>/Assertion' */
} DW_maggyroProcessing_lib;

/* Block signals and states (default storage) for system '<S2>/maggyroProcessing_lib1' */
typedef struct {
  void* Assertion_slioAccessor;        /* '<S73>/Assertion' */
  void* Assertion_slioAccessor_l;      /* '<S72>/Assertion' */
  void* Assertion_slioAccessor_c;      /* '<S71>/Assertion' */
} DW_maggyroProcessing_lib_j;

extern void IfActionSubsystem(const real_T rtu_In1[3], const real_T rtu_In2[3],
  const real_T rtu_In3[3], real_T rty_avg[3]);
extern void IfActionSubsystem1(const real_T rtu_In1[3], const real_T rtu_In2[3],
  real_T rty_avg[3]);
extern void IfActionSubsystem3(const real_T rtu_In1[3], const real_T rtu_In2[3],
  real_T rty_Out1[3]);
extern void TwoValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
                     rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_c,
                     boolean_T rtu_sensor_valid_all_d, real_T
                     rty_sensor_meas_body[3], boolean_T *rty_sensor_meas_valid,
                     real_T rtp_max_err);
extern void IfActionSubsystem14(real_T rty_nullOut[3]);
extern void OneValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
                     rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_m,
                     boolean_T rtu_sensor_valid_all_a, real_T
                     rty_sensor_meas_body[3], boolean_T *rty_sensor_valid);
extern void NoneValid(const real_T rtu_sensor_meas_body_all[9], real_T
                      rty_sensor_meas_body[3], boolean_T *rty_sensor_valid);
extern void IfActionSubsystem2(boolean_T *rty_Out1);
extern void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, real_T rtp_max_err, const real_T
  rtp_offset_calibration_matrix[9], real_T rtp_static_range_max_value, real_T
  rtp_Gain);
extern void maggyroProcessing_lib1(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, real_T rtp_max_err, const real_T
  rtp_offset_calibration_matrix[9], real_T rtp_static_range_max_value, real_T
  rtp_Gain);

#endif                                 /* RTW_HEADER_maggyroProcessing_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
