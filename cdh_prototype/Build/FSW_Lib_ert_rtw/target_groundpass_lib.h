/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.h
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

#ifndef RTW_HEADER_target_groundpass_lib_h_
#define RTW_HEADER_target_groundpass_lib_h_
#include <math.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Child system includes */
#include "twonorm.h"

/* Invariant block signals for system '<S288>/target_groundpass_lib' */
typedef struct {
  const real_T VectorConcatenate[9];   /* '<S341>/Vector Concatenate' */
} ConstB_target_groundpass_lib;

extern void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad,
  real_T rty_sc2target_ecef_unit[3], const ConstB_target_groundpass_lib *localC);
extern void target_groundpass_lib1(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3]);

#endif                                 /* RTW_HEADER_target_groundpass_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
