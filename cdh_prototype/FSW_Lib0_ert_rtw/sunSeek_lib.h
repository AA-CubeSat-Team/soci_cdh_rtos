/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.h
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

#ifndef RTW_HEADER_sunSeek_lib_h_
#define RTW_HEADER_sunSeek_lib_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Block signals and states (default storage) for system '<S238>/sunSeek_lib' */
typedef struct {
  real_T rtb_Kp_idx_1;
} DW_sunSeek_lib;

/* Parameters for system: '<S238>/sunSeek_lib' */
struct P_sunSeek_lib_ {
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S260>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S260>/Constant'
                                        */
  real_T sat_pm1_UpperSat;             /* Expression: 1
                                        * Referenced by: '<S258>/sat_pm1'
                                        */
  real_T sat_pm1_LowerSat;             /* Expression: -1
                                        * Referenced by: '<S258>/sat_pm1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S258>/Gain'
                                        */
};

extern void sunSeek_lib(uint8_T rtu_ss_valid, const real_T
  rtu_sc2sun_pd_body_unit[3], const real_T rtu_sc2sun_ss_body_unit[3], const
  real_T rtu_w_err_radps[3], real_T rty_torque_cmd_body_Nm[3], DW_sunSeek_lib
  *localDW, P_sunSeek_lib *localP);

#endif                                 /* RTW_HEADER_sunSeek_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
