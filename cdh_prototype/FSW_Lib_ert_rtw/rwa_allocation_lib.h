/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
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
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
#define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Child system includes */
#include "L_inf_allocation_lib.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<S5>/rwa_allocation_lib' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S275>/Discrete-Time Integrator' */
  real_T Product_DWORK4[9];            /* '<S284>/Product' */
} DW_rwa_allocation_lib;

extern void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_radps[4], const boolean_T rtu_rwa_valid[4], real_T
  rty_torque_wheel_Nm[4], DW_rwa_allocation_lib *localDW);

#endif                                 /* RTW_HEADER_rwa_allocation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
