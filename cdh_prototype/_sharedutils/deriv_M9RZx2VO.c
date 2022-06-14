/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: deriv_M9RZx2VO.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "get_f_vals_QHwIX6tr.h"
#include "mldivide_CcWu5YGv.h"
#include "mldivide_Uh5i7tR8.h"
#include "deriv_M9RZx2VO.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void deriv_M9RZx2VO(real_T t, const real_T X_1[190], const real_T u[6], const
                    real_T tspan[10], real_T s, const real_T J[9], real_T DX[190])
{
  real_T A[100];
  real_T X_2[100];
  real_T s_1[100];
  real_T Bdm_dot[30];
  real_T Bdp_dot[30];
  real_T Bm[30];
  real_T s_0[30];
  real_T Sd_dot[10];
  real_T Zd_dot[10];
  real_T f[10];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T s_tmp;
  get_f_vals_QHwIX6tr(t, &X_1[0], u, tspan, J, f, A, Bdm_dot, Bm, Zd_dot);
  for (i = 0; i < 30; i++) {
    s_0[i] = s * Bdm_dot[i];
  }

  mldivide_Uh5i7tR8(&X_1[10], s_0, Bdp_dot);
  for (i = 0; i < 30; i++) {
    s_0[i] = s * Bm[i];
  }

  mldivide_Uh5i7tR8(&X_1[10], s_0, Bdm_dot);
  memcpy(&Sd_dot[0], &f[0], 10U * sizeof(real_T));
  mldivide_CcWu5YGv(&X_1[10], Sd_dot);
  for (i = 0; i < 10; i++) {
    Zd_dot[i] *= s;
  }

  mldivide_CcWu5YGv(&X_1[10], Zd_dot);
  memcpy(&X_2[0], &X_1[10], 100U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    for (i_0 = 0; i_0 < 10; i_0++) {
      s_tmp = i + 10 * i_0;
      s_1[s_tmp] = 0.0;
      for (i_1 = 0; i_1 < 10; i_1++) {
        s_1[s_tmp] += A[10 * i_1 + i] * s * X_2[10 * i_0 + i_1];
      }
    }

    DX[i] = s * f[i];
  }

  memcpy(&DX[10], &s_1[0], 100U * sizeof(real_T));
  for (i = 0; i < 30; i++) {
    DX[i + 110] = Bdp_dot[i];
    DX[i + 140] = Bdm_dot[i];
  }

  for (i = 0; i < 10; i++) {
    DX[i + 170] = Sd_dot[i];
    DX[i + 180] = Zd_dot[i];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
