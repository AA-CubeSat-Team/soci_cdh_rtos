/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.h
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

#ifndef RTW_HEADER_mode_select_lib_h_
#define RTW_HEADER_mode_select_lib_h_
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
  boolean_T Relay3_Mode;               /* '<S287>/Relay3' */
  boolean_T Relay_Mode;                /* '<S8>/Relay' */
} DW_mode_select_lib;

/* Invariant block signals for system '<S1>/mode_select_lib' */
typedef struct {
  const real_T CreateDiagonalMatrix[16];/* '<S287>/Create Diagonal Matrix' */
} ConstB_mode_select_lib;

extern uint8_T mode_select_lib(const real_T rtu_telecom[6], boolean_T
  rtu_eclipse, uint8_T rtu_ss_valid, boolean_T rtu_sc_above_targ, const real_T
  rtu_body_rates_radps[3], real_T rtu_MET_utc_s, real_T rtu_MET_soar_utc_s,
  const real_T rtu_RWA_rpm[4], const ConstB_mode_select_lib *localC,
  DW_mode_select_lib *localDW);

#endif                                 /* RTW_HEADER_mode_select_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
