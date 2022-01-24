/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.h
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

#ifndef RTW_HEADER_mode_select_lib_h_
#define RTW_HEADER_mode_select_lib_h_
#include <string.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "twonorm.h"

/* Block signals and states (default storage) for system '<S1>/mode_select_lib' */
typedef struct {
  real_T CreateDiagonalMatrix_o[16];   /* '<S382>/Create Diagonal Matrix' */
  real_T rtb_CreateDiagonalMatrix_o_m[4];
  boolean_T Relay3_Mode;               /* '<S382>/Relay3' */
  boolean_T Relay_Mode;                /* '<S9>/Relay' */
} DW_mode_select_lib;

/* Parameters for system: '<S1>/mode_select_lib' */
struct P_mode_select_lib_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S387>/Constant'
                                        */
  real_T CompareToConstant2_const;     /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S389>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S388>/Constant'
                                        */
  real_T Relay3_YOn;                   /* Expression: 1
                                        * Referenced by: '<S382>/Relay3'
                                        */
  real_T Relay3_YOff;                  /* Expression: 0
                                        * Referenced by: '<S382>/Relay3'
                                        */
  real_T Relay_YOn;                    /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S9>/Relay'
                                        */
  real_T Relay_YOff;                   /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S9>/Relay'
                                        */
};

extern uint8_T mode_select_lib(const real_T rtu_telecom[6], boolean_T
  rtu_eclipse, uint8_T rtu_ss_valid, boolean_T rtu_sc_above_targ, const real_T
  rtu_body_rates_radps[3], real_T rtu_MET_utc_s, real_T rtu_MET_soar_utc_s,
  const real_T rtu_RWA_rpm[4], DW_mode_select_lib *localDW, P_mode_select_lib
  *localP);

#endif                                 /* RTW_HEADER_mode_select_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
