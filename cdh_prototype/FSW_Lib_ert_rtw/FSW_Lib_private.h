/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_private.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_Lib_private_h_
#define RTW_HEADER_FSW_Lib_private_h_
#include "rtwtypes.h"
#include "FSW_Lib.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rt_invd3x3_snf(const real_T u[9], real_T y[9]);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern void IfActionSubsystem(real_T *rty_Out1);
extern void IfActionSubsystem1(real_T *rty_Out1);
extern void IfActionSubsystem2(real_T *rty_Out1);

#endif                                 /* RTW_HEADER_FSW_Lib_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
