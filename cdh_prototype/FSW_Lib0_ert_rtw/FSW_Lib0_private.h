/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_private.h
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

#ifndef RTW_HEADER_FSW_Lib0_private_h_
#define RTW_HEADER_FSW_Lib0_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "FSW_Lib0.h"

extern void IfActionSubsystem(real_T *rty_Out1, P_IfActionSubsystem *localP);
extern void run_ecos(int32_T rtu_n, int32_T rtu_m, int32_T rtu_p, int32_T rtu_l,
                     int32_T rtu_ncones, const real_T rtu_c[332], const int32_T
                     rtu_Gjc[333], const int32_T rtu_Gir[834], const real_T
                     rtu_Gpr[834], const real_T rtu_h[474], const int32_T rtu_q
                     [21], const int32_T rtu_Ajc[333], const int32_T rtu_Air
                     [1278], const real_T rtu_Apr[1278], const real_T rtu_b[117],
                     real_T rty_y[333]);

#endif                                 /* RTW_HEADER_FSW_Lib0_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
