/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_MDOP2S80.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include "xgeqrf_J92VbJAL.h"
#include "xorgqr_jioZAUaB.h"
#include "qr_MDOP2S80.h"

/* Function for MATLAB Function: '<S124>/MATLAB Function' */
void qr_MDOP2S80(const real_T A[72], real_T Q[144], real_T R[72])
{
  real_T tau[12];
  int32_T i;
  int32_T j;
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 12; i++) {
      Q[i + 12 * j] = A[12 * j + i];
      Q[i + 12 * (j + 6)] = 0.0;
    }
  }

  xgeqrf_J92VbJAL(Q, tau);
  for (j = 0; j < 6; j++) {
    for (i = 0; i <= j; i++) {
      R[i + 12 * j] = Q[12 * j + i];
    }

    for (i = j + 1; i + 1 < 13; i++) {
      R[i + 12 * j] = 0.0;
    }
  }

  xorgqr_jioZAUaB(12, 12, 6, Q, 1, tau, 1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
