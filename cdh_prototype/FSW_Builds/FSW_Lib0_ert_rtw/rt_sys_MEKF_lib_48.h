/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_48.h
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

#ifndef RTW_HEADER_rt_sys_MEKF_lib_48_h_
#define RTW_HEADER_rt_sys_MEKF_lib_48_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"
#include "rt_assert.h"

/* Block signals and states (default storage) for system '<S190>/If Warning//Error' */
typedef struct {
  void* Assertion_slioAccessor;        /* '<S219>/Assertion' */
  void* Assertion_slioAccessor_l;      /* '<S220>/Assertion' */
  void* Assertion_slioAccessor_f;      /* '<S221>/Assertion' */
  void* Assertion_slioAccessor_g;      /* '<S222>/Assertion' */
} DW_IfWarningError;

extern void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
  rtp_tolerance);

#endif                                 /* RTW_HEADER_rt_sys_MEKF_lib_48_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
