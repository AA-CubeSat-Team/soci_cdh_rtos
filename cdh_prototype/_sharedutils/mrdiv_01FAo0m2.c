/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mrdiv_01FAo0m2.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "mrdiv_01FAo0m2.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void mrdiv_01FAo0m2(const real_T A[36], const real_T B_0[36], real_T Y[36])
{
  real_T b_A[36];
  real_T smax;
  real_T y;
  int32_T c_ix;
  int32_T d;
  int32_T d_j;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T jBcol;
  int32_T kBcol;
  int8_T ipiv[6];
  int8_T ipiv_0;
  memcpy(&b_A[0], &B_0[0], 36U * sizeof(real_T));
  for (d_j = 0; d_j < 6; d_j++) {
    ipiv[d_j] = (int8_T)(d_j + 1);
  }

  for (d_j = 0; d_j < 5; d_j++) {
    jBcol = d_j * 7;
    iy = 0;
    ix = jBcol;
    smax = fabs(b_A[jBcol]);
    for (kBcol = 2; kBcol <= 6 - d_j; kBcol++) {
      ix++;
      y = fabs(b_A[ix]);
      if (y > smax) {
        iy = kBcol - 1;
        smax = y;
      }
    }

    if (b_A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += d_j;
        ipiv[d_j] = (int8_T)(iy + 1);
        ix = d_j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - d_j) + 6;
      for (ix = jBcol + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 0; kBcol <= 4 - d_j; kBcol++) {
      if (b_A[ix] != 0.0) {
        smax = -b_A[ix];
        c_ix = jBcol + 1;
        d = (iy - d_j) + 12;
        for (ijA = iy + 7; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  memcpy(&Y[0], &A[0], 36U * sizeof(real_T));
  for (d_j = 0; d_j < 6; d_j++) {
    jBcol = 6 * d_j;
    for (ix = 0; ix < d_j; ix++) {
      kBcol = 6 * ix;
      if (b_A[ix + jBcol] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          Y[d] -= b_A[ix + jBcol] * Y[c_ix + kBcol];
        }
      }
    }

    smax = 1.0 / b_A[d_j + jBcol];
    for (iy = 0; iy < 6; iy++) {
      d = iy + jBcol;
      Y[d] *= smax;
    }
  }

  for (d_j = 5; d_j >= 0; d_j--) {
    jBcol = 6 * d_j;
    iy = 6 * d_j - 1;
    for (ix = d_j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 6;
      if (b_A[ix + iy] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          Y[d] -= b_A[ix + iy] * Y[c_ix + kBcol];
        }
      }
    }
  }

  for (d_j = 4; d_j >= 0; d_j--) {
    ipiv_0 = ipiv[d_j];
    if (d_j + 1 != ipiv_0) {
      for (iy = 0; iy < 6; iy++) {
        ix = 6 * d_j + iy;
        smax = Y[ix];
        d = (ipiv_0 - 1) * 6 + iy;
        Y[ix] = Y[d];
        Y[d] = smax;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
