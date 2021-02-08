/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rwa_allocation_lib_h_
#define RTW_HEADER_rwa_allocation_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>

/* Child system includes */
#include <gnc_build/FSW_Lib_ert_rtw/L_inf_allocation_lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/rt_assert.h>

/* Block signals and states (default storage) for system '<S6>/rwa_allocation_lib' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S164>/Discrete-Time Integrator' */
  real_T Product_DWORK4[9];            /* '<S170>/Product' */
  void* Assertion_slioAccessor;        /* '<S170>/Assertion' */
} DW_rwa_allocation_lib;

extern void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_rpm[4], const boolean_T rtu_rwa_valid[4], real_T rty_torque_wheel_Nm[4],
  DW_rwa_allocation_lib *localDW);

#endif                                 /* RTW_HEADER_rwa_allocation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
