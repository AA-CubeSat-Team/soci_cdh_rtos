/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: foh_c1NVxM2u.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "deriv_M9RZx2VO.h"
#include "foh_c1NVxM2u.h"

/* Function for MATLAB Function: '<S210>/SOLVE' */
void foh_c1NVxM2u(const real_T X_0[100], const real_T U[30], real_T s, const
                  real_T J[9], real_T EH[10000], real_T BE[3000], real_T ES[100],
                  real_T AR[100])
{
  real_T P0[190];
  real_T P0_1[190];
  real_T k1[190];
  real_T k2[190];
  real_T k3[190];
  real_T k4[190];
  real_T Ad[100];
  real_T P0_0[100];
  real_T tspan[10];
  real_T u[6];
  real_T delta1;
  real_T h;
  real_T *P0_2;
  int32_T BE_tmp;
  int32_T BE_tmp_0;
  int32_T b_k;
  int32_T d_k;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T i_2;
  int32_T i_3;
  int8_T A0[100];
  memset(&EH[0], 0, 10000U * sizeof(real_T));
  memset(&A0[0], 0, 100U * sizeof(int8_T));
  for (b_k = 0; b_k < 10; b_k++) {
    A0[b_k + 10 * b_k] = 1;
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    for (i = 0; i < 10; i++) {
      EH[i + 100 * i_0] = A0[10 * i_0 + i];
    }
  }

  memset(&BE[0], 0, 3000U * sizeof(real_T));
  memset(&ES[0], 0, 100U * sizeof(real_T));
  memset(&AR[0], 0, 100U * sizeof(real_T));
  memset(&A0[0], 0, 100U * sizeof(int8_T));
  for (b_k = 0; b_k < 10; b_k++) {
    A0[b_k + 10 * b_k] = 1;
  }

  for (b_k = 0; b_k < 9; b_k++) {
    memcpy(&P0[0], &X_0[10 * b_k], 10U * sizeof(real_T));
    for (i_0 = 0; i_0 < 100; i_0++) {
      P0[i_0 + 10] = A0[i_0];
    }

    for (i_0 = 0; i_0 < 30; i_0++) {
      P0[i_0 + 110] = 0.0;
      P0[i_0 + 140] = 0.0;
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      P0[i_0 + 170] = 0.0;
      P0[i_0 + 180] = 0.0;
    }

    i_0 = 3 * b_k;
    i = (b_k + 1) * 3;
    u[0] = U[i_0];
    u[3] = U[i];
    u[1] = U[i_0 + 1];
    u[4] = U[i + 1];
    u[2] = U[i_0 + 2];
    u[5] = U[i + 2];
    h = 0.1111111111111111 * (real_T)b_k;
    delta1 = ((real_T)b_k + 1.0) * 0.1111111111111111;
    tspan[9] = delta1;
    tspan[0] = h;
    delta1 = (delta1 - h) / 9.0;
    for (d_k = 0; d_k < 8; d_k++) {
      tspan[d_k + 1] = ((real_T)d_k + 1.0) * delta1 + h;
    }

    for (d_k = 0; d_k < 9; d_k++) {
      h = tspan[d_k + 1] - tspan[d_k];
      deriv_M9RZx2VO(tspan[d_k], P0, u, tspan, s, J, k1);
      delta1 = h / 2.0;
      for (i_1 = 0; i_1 < 190; i_1++) {
        P0_1[i_1] = delta1 * k1[i_1] + P0[i_1];
      }

      deriv_M9RZx2VO(h / 2.0 + tspan[d_k], P0_1, u, tspan, s, J, k2);
      for (i_1 = 0; i_1 < 190; i_1++) {
        P0_1[i_1] = delta1 * k2[i_1] + P0[i_1];
      }

      deriv_M9RZx2VO(h / 2.0 + tspan[d_k], P0_1, u, tspan, s, J, k3);
      for (i_1 = 0; i_1 < 190; i_1++) {
        P0_1[i_1] = h * k3[i_1] + P0[i_1];
      }

      deriv_M9RZx2VO(tspan[d_k] + h, P0_1, u, tspan, s, J, k4);
      h /= 6.0;
      for (i_1 = 0; i_1 < 190; i_1++) {
        P0[i_1] += (((2.0 * k2[i_1] + k1[i_1]) + 2.0 * k3[i_1]) + k4[i_1]) * h;
      }
    }

    for (i_1 = 0; i_1 < 100; i_1++) {
      h = P0[i_1 + 10];
      Ad[i_1] = h;
      P0_0[i_1] = h;
    }

    i_1 = (b_k + 1) * 10;
    d_k = 10 * b_k;
    for (i_2 = 0; i_2 < 10; i_2++) {
      memcpy(&EH[i_2 * 100 + (i_1 + d_k * 100)], &P0_0[i_2 * 10], 10U * sizeof
             (real_T));
    }

    P0_2 = &P0[140];
    for (d_k = 0; d_k < 10; d_k++) {
      for (i_2 = 0; i_2 < 3; i_2++) {
        BE_tmp = 100 * (i_2 + i_0);
        BE_tmp_0 = (d_k + i_1) + BE_tmp;
        BE[BE_tmp_0] = 0.0;
        for (i_3 = 0; i_3 < 10; i_3++) {
          BE[BE_tmp_0] = BE[(BE_tmp + d_k) + i_1] + Ad[10 * i_3 + d_k] * P0_2[10
            * i_2 + i_3];
        }
      }
    }

    P0_2 = &P0[110];
    for (i_0 = 0; i_0 < 10; i_0++) {
      for (d_k = 0; d_k < 3; d_k++) {
        BE_tmp = 100 * (d_k + i);
        BE_tmp_0 = (i_0 + i_1) + BE_tmp;
        BE[BE_tmp_0] = 0.0;
        for (i_2 = 0; i_2 < 10; i_2++) {
          BE[BE_tmp_0] = BE[(BE_tmp + i_0) + i_1] + Ad[10 * i_2 + i_0] * P0_2[10
            * d_k + i_2];
        }
      }

      tspan[i_0] = 0.0;
      for (d_k = 0; d_k < 10; d_k++) {
        tspan[i_0] += Ad[10 * d_k + i_0] * P0[d_k + 170];
      }

      ES[i_0 + i_1] = tspan[i_0];
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      tspan[i_0] = 0.0;
      for (i = 0; i < 10; i++) {
        tspan[i_0] += Ad[10 * i + i_0] * P0[i + 180];
      }

      AR[i_0 + i_1] = tspan[i_0];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
