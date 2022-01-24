/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.h
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

#ifndef RTW_HEADER_rwa_allocation_lib_h_
#define RTW_HEADER_rwa_allocation_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "L_inf_allocation_lib.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<S5>/rwa_allocation_lib' */
typedef struct {
  DW_L_inf_allocation_lib L_inf_allocation_lib1;/* '<S275>/L_inf_allocation_lib1' */
  DW_L_inf_allocation_lib L_inf_allocation_lib_p;/* '<S275>/L_inf_allocation_lib' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S275>/Discrete-Time Integrator' */
  real_T Product_DWORK4[9];            /* '<S284>/Product' */
  real_T A_out[9];                     /* '<S276>/MATLAB Function' */
  real_T dv0[9];
  real_T x[9];
  real_T temp[8];
  real_T h_err_null_norm[4];
  real_T output_wheel[4];              /* '<S279>/MATLAB Function' */
  real_T output_wheel_a[4];            /* '<S278>/MATLAB Function' */
  real_T id_good[3];
  real_T localProduct;
  real_T localProduct_m;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T idx;
  int32_T n_whl;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  void* Assertion_slioAccessor;        /* '<S284>/Assertion' */
} DW_rwa_allocation_lib;

/* Parameters for system: '<S5>/rwa_allocation_lib' */
struct P_rwa_allocation_lib_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S275>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S275>/Discrete-Time Integrator'
                                        */
};

extern void rwa_allocation_lib_Init(DW_rwa_allocation_lib *localDW,
  P_rwa_allocation_lib *localP);
extern void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_radps[4], const boolean_T rtu_rwa_valid[4], real_T
  rty_torque_wheel_Nm[4], DW_rwa_allocation_lib *localDW, P_rwa_allocation_lib
  *localP);

#endif                                 /* RTW_HEADER_rwa_allocation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
