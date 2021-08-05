/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: deriv_iDMkweTP.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "get_f_vals_jXwFdfw5.h"
#include "mldivide_JgAM3Jry.h"
#include "mldivide_gjtSm7pm.h"
#include "deriv_iDMkweTP.h"

/* Function for MATLAB Function: '<S412>/SOLVE' */
void deriv_iDMkweTP(real_T t, const real_T X_1[190], const real_T u[6], const
                    real_T tspan[10], real_T s, const real_T J[9], real_T DX[190])
{
  real_T Bdp_dot[30];
  real_T Bdm_dot[30];
  real_T Sd_dot[10];
  real_T Zd_dot[10];
  real_T f[10];
  real_T A[100];
  real_T X_2[100];
  real_T s_0[100];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T s_tmp;
  get_f_vals_jXwFdfw5(t, &X_1[0], u, tspan, J, f, A, Bdp_dot, Bdm_dot, Zd_dot);
  for (i = 0; i < 30; i++) {
    Bdp_dot[i] *= s;
  }

  mldivide_gjtSm7pm(&X_1[10], Bdp_dot);
  for (i = 0; i < 30; i++) {
    Bdm_dot[i] *= s;
  }

  mldivide_gjtSm7pm(&X_1[10], Bdm_dot);
  memcpy(&Sd_dot[0], &f[0], 10U * sizeof(real_T));
  mldivide_JgAM3Jry(&X_1[10], Sd_dot);
  for (i = 0; i < 10; i++) {
    Zd_dot[i] *= s;
  }

  mldivide_JgAM3Jry(&X_1[10], Zd_dot);
  memcpy(&X_2[0], &X_1[10], 100U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    for (i_0 = 0; i_0 < 10; i_0++) {
      s_tmp = i + 10 * i_0;
      s_0[s_tmp] = 0.0;
      for (i_1 = 0; i_1 < 10; i_1++) {
        s_0[s_tmp] = A[10 * i_1 + i] * s * X_2[10 * i_0 + i_1] + s_0[10 * i_0 +
          i];
      }
    }

    DX[i] = s * f[i];
  }

  memcpy(&DX[10], &s_0[0], 100U * sizeof(real_T));
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
