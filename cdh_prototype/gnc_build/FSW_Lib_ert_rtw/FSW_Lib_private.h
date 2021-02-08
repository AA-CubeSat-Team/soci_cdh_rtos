/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_private.h
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

#ifndef RTW_HEADER_FSW_Lib_private_h_
#define RTW_HEADER_FSW_Lib_private_h_
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void rt_invd3x3_snf(const real_T u[9], real_T y[9]);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void WhileIteratorSubsystem(real_T rtu_rho, real_T rtu_z, real_T rtu_b,
  real_T rtu_uf, real_T rtu_e2, real_T rtu_ep2, real_T *rty_phi,
  DW_WhileIteratorSubsystem *localDW);

#endif                                 /* RTW_HEADER_FSW_Lib_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
