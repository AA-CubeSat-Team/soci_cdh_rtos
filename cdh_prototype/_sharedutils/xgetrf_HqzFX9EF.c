/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xgetrf_HqzFX9EF.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "xgetrf_HqzFX9EF.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void xgetrf_HqzFX9EF(real_T A[100], int32_T ipiv[10], int32_T *info)
{
  real_T smax;
  real_T y;
  int32_T c;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int32_T jA;
  for (j = 0; j < 10; j++) {
    ipiv[j] = j + 1;
  }

  *info = 0;
  for (j = 0; j < 9; j++) {
    c = j * 11;
    jA = 0;
    ix = c;
    smax = fabs(A[c]);
    for (iy = 2; iy <= 10 - j; iy++) {
      ix++;
      y = fabs(A[ix]);
      if (y > smax) {
        jA = iy - 1;
        smax = y;
      }
    }

    if (A[c + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = iy + 1;
        ix = j;
        for (jA = 0; jA < 10; jA++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 10;
          iy += 10;
        }
      }

      jA = (c - j) + 10;
      for (ix = c + 1; ix < jA; ix++) {
        A[ix] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    jA = c;
    ix = c + 10;
    for (iy = 0; iy <= 8 - j; iy++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (jA - j) + 20;
        for (ijA = jA + 11; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 10;
      jA += 10;
    }
  }

  if ((*info == 0) && (!(A[99] != 0.0))) {
    *info = 10;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
