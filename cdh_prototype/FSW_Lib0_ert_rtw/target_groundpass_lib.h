/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_groundpass_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_target_groundpass_lib_h_
#define RTW_HEADER_target_groundpass_lib_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "twonorm.h"

/* Block signals and states (default storage) for system '<S288>/target_groundpass_lib' */
typedef struct {
  real_T VectorConcatenate_b[9];       /* '<S341>/Vector Concatenate' */
  real_T Sum_mr[3];                    /* '<S294>/Sum' */
  real_T MathFunction_oh[3];           /* '<S337>/Math Function' */
  real_T SinCos_o1;                    /* '<S339>/SinCos' */
  real_T deg2rad1;                     /* '<S294>/deg2rad1' */
  real_T deg2rad2;                     /* '<S294>/deg2rad2' */
} DW_target_groundpass_lib;

/* Parameters for system: '<S288>/target_groundpass_lib' */
struct P_target_groundpass_lib_ {
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S337>/Switch'
                                        */
  real_T NormalizeVector1_maxzero;     /* Mask Parameter: NormalizeVector1_maxzero
                                        * Referenced by: '<S338>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S337>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S338>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S339>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S339>/Gain'
                                        */
  real_T Constant_Value_h4;            /* Expression: 0
                                        * Referenced by: '<S339>/Constant'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S294>/Gain'
                                        */
};

extern void target_groundpass_lib(const real_T rtu_r_ecef_m[3], const real_T
  rtu_targ_ecef_m[3], real_T rtu_targ_gd_lat_deg, real_T rtu_targ_lon_deg,
  boolean_T *rty_sc_above_target, real_T *rty_elev_sez_rad, real_T
  rty_sc2target_ecef_unit[3], DW_target_groundpass_lib *localDW,
  P_target_groundpass_lib *localP, real_T rtp_id);

#endif                                 /* RTW_HEADER_target_groundpass_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
