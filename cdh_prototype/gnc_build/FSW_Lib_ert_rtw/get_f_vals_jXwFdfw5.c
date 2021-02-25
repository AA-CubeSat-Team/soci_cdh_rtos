/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: get_f_vals_jXwFdfw5.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include "Q_linearize_4x0wWNNK.h"
#include "get_f_vals_jXwFdfw5.h"

/* Function for MATLAB Function: '<S317>/SOLVE' */
void get_f_vals_jXwFdfw5(real_T t, const real_T x[10], const real_T u[6], const
  real_T tspan[10], const real_T J[9], real_T f[10], real_T A[100], real_T Bp[30],
  real_T Bm[30], real_T Z[10])
{
  real_T lam_km;
  real_T lam_kp;
  real_T u_tau[3];
  static const int8_T b[30] = { 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1 };

  int8_T Bp_tmp[30];
  real_T A_0[100];
  real_T A_1[10];
  int32_T i;
  int32_T i_0;
  lam_kp = tspan[9] - tspan[0];
  lam_km = (tspan[9] - t) / lam_kp;
  lam_kp = (t - tspan[0]) / lam_kp;
  u_tau[0] = lam_km * u[0] + lam_kp * u[3];
  u_tau[1] = lam_km * u[1] + lam_kp * u[4];
  u_tau[2] = lam_km * u[2] + lam_kp * u[5];
  Q_linearize_4x0wWNNK(x, u_tau, J, A, f);
  for (i = 0; i < 30; i++) {
    Bp[i] = lam_kp * (real_T)b[i];
    Bm[i] = lam_km * (real_T)b[i];
    Bp_tmp[i] = b[i];
  }

  for (i = 0; i < 100; i++) {
    A_0[i] = -A[i];
  }

  for (i = 0; i < 10; i++) {
    A_1[i] = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      A_1[i] += A_0[10 * i_0 + i] * x[i_0];
    }

    Z[i] = A_1[i] - ((real_T)Bp_tmp[i + 20] * u_tau[2] + ((real_T)Bp_tmp[i + 10]
      * u_tau[1] + (real_T)Bp_tmp[i] * u_tau[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
