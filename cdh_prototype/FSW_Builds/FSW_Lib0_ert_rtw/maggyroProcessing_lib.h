/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.h
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

/* Block signals and states (default storage) for system '<S11>/ThreeValid_MVS' */
typedef struct {
  uint32_T Median_Index[3];            /* '<S25>/Median' */
} DW_ThreeValid_MVS;

/* Block signals and states (default storage) for system '<S2>/maggyroProcessing_lib' */
typedef struct {
  DW_ThreeValid_MVS ThreeValid_MVS_l;  /* '<S11>/ThreeValid_MVS' */
  void* Assertion_slioAccessor;        /* '<S35>/Assertion' */
  void* Assertion_slioAccessor_p;      /* '<S34>/Assertion' */
  void* Assertion_slioAccessor_pu;     /* '<S33>/Assertion' */
} DW_maggyroProcessing_lib;

/* Block signals and states (default storage) for system '<S2>/maggyroProcessing_lib1' */
typedef struct {
  DW_ThreeValid_MVS ThreeValid_MVS_b;  /* '<S12>/ThreeValid_MVS' */
  void* Assertion_slioAccessor;        /* '<S77>/Assertion' */
  void* Assertion_slioAccessor_d;      /* '<S76>/Assertion' */
  void* Assertion_slioAccessor_b;      /* '<S75>/Assertion' */
} DW_maggyroProcessing_lib_h;

extern void ThreeValid_MVS_Init(DW_ThreeValid_MVS *localDW);
extern void ThreeValid_MVS(const real_T rtu_sensor_meas_body_all[9], real_T
  rty_sensor_meas_body[3], boolean_T *rty_sensor_meas_valid, DW_ThreeValid_MVS
  *localDW, real_T rtp_max_err);
extern void TwoValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
                     rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_e,
                     boolean_T rtu_sensor_valid_all_o, real_T
                     rty_sensor_meas_body[3], boolean_T *rty_sensor_meas_valid,
                     real_T rtp_max_err);
extern void IfActionSubsystem14(real_T rty_nullOut[3]);
extern void OneValid(const real_T rtu_sensor_meas_body_all[9], boolean_T
                     rtu_sensor_valid_all, boolean_T rtu_sensor_valid_all_n,
                     boolean_T rtu_sensor_valid_all_f, real_T
                     rty_sensor_meas_body[3], boolean_T *rty_sensor_valid);
extern void NoneValid(const real_T rtu_sensor_meas_body_all[9], real_T
                      rty_sensor_meas_body[3], boolean_T *rty_sensor_valid);
extern void IfActionSubsystem2(boolean_T *rty_Out1);
extern void maggyroProcessing_lib_Init(DW_maggyroProcessing_lib *localDW);
extern void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, DW_maggyroProcessing_lib *localDW, real_T rtp_max_err, const
  real_T rtp_offset_calibration_matrix[9], real_T rtp_static_range_max_value,
  real_T rtp_Gain);
extern void maggyroProcessing_lib1_Init(DW_maggyroProcessing_lib_h *localDW);
extern void maggyroProcessing_lib1(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, DW_maggyroProcessing_lib_h *localDW, real_T rtp_max_err,
  const real_T rtp_offset_calibration_matrix[9], real_T
  rtp_static_range_max_value, real_T rtp_Gain);

#endif                                 /* RTW_HEADER_maggyroProcessing_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
