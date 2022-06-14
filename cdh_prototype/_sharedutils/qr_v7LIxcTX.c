/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_v7LIxcTX.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "xgeqrf_J92VbJAL.h"
#include "xorgqr_jioZAUaB.h"
#include "qr_v7LIxcTX.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void qr_v7LIxcTX(const real_T A[144], real_T Q[144], real_T R[144])
{
  real_T b_A[144];
  real_T tau[12];
  int32_T i;
  int32_T j;
  memcpy(&b_A[0], &A[0], 144U * sizeof(real_T));
  xgeqrf_J92VbJAL(b_A, tau);
  for (j = 0; j < 12; j++) {
    for (i = 0; i <= j; i++) {
      R[i + 12 * j] = b_A[12 * j + i];
    }

    for (i = j + 1; i + 1 < 13; i++) {
      R[i + 12 * j] = 0.0;
    }
  }

  xorgqr_jioZAUaB(12, 12, 12, b_A, 1, tau, 1);
  for (j = 0; j < 12; j++) {
    memcpy(&Q[j * 12], &b_A[j * 12], 12U * sizeof(real_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
