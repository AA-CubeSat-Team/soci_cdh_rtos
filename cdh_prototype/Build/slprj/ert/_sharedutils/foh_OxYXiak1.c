/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: foh_OxYXiak1.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "deriv_CsN416wG.h"
#include "eye_y3VYXK5u.h"
#include "linspace_dCtge7ie.h"
#include "foh_OxYXiak1.h"

/* Function for MATLAB Function: '<S438>/SOLVE' */
void foh_OxYXiak1(const real_T X_0[100], const real_T U[30], real_T s, const
                  real_T J[9], real_T EH[10000], real_T BE[3000], real_T ES[100],
                  real_T AR[100])
{
  real_T P0[190];
  real_T u[6];
  real_T tspan[10];
  real_T h;
  real_T k1[190];
  real_T k2[190];
  real_T k3[190];
  real_T k4[190];
  real_T Ad[100];
  int32_T k;
  int32_T k_;
  real_T a;
  real_T EH_tmp[100];
  real_T P0_0[190];
  real_T P0_1[100];
  real_T Ad_0[10];
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T i_2;
  int32_T BE_tmp;
  int32_T BE_tmp_0;
  int32_T tmp;
  real_T *P0_2;
  memset(&EH[0], 0, 10000U * sizeof(real_T));
  eye_y3VYXK5u(EH_tmp);
  for (i = 0; i < 10; i++) {
    memcpy(&EH[i * 100], &EH_tmp[i * 10], 10U * sizeof(real_T));
  }

  memset(&BE[0], 0, 3000U * sizeof(real_T));
  memset(&ES[0], 0, 100U * sizeof(real_T));
  memset(&AR[0], 0, 100U * sizeof(real_T));
  for (k = 0; k < 9; k++) {
    memcpy(&P0[0], &X_0[10 * k], 10U * sizeof(real_T));
    memcpy(&P0[10], &EH_tmp[0], 100U * sizeof(real_T));
    for (i = 0; i < 30; i++) {
      P0[i + 110] = 0.0;
      P0[i + 140] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      P0[i + 170] = 0.0;
      P0[i + 180] = 0.0;
    }

    i = 3 * k;
    tmp = (1 + k) * 3;
    u[0] = U[i];
    u[3] = U[tmp];
    u[1] = U[1 + i];
    u[4] = U[1 + tmp];
    u[2] = U[2 + i];
    u[5] = U[2 + tmp];
    linspace_dCtge7ie(0.1111111111111111 * (real_T)k, ((real_T)k + 1.0) *
                      0.1111111111111111, tspan);
    for (k_ = 0; k_ < 9; k_++) {
      h = tspan[k_ + 1] - tspan[k_];
      deriv_CsN416wG(tspan[k_], P0, u, tspan, s, J, k1);
      a = h / 2.0;
      for (i = 0; i < 190; i++) {
        P0_0[i] = a * k1[i] + P0[i];
      }

      deriv_CsN416wG(h / 2.0 + tspan[k_], P0_0, u, tspan, s, J, k2);
      a = h / 2.0;
      for (i = 0; i < 190; i++) {
        P0_0[i] = a * k2[i] + P0[i];
      }

      deriv_CsN416wG(h / 2.0 + tspan[k_], P0_0, u, tspan, s, J, k3);
      for (i = 0; i < 190; i++) {
        P0_0[i] = h * k3[i] + P0[i];
      }

      deriv_CsN416wG(tspan[k_] + h, P0_0, u, tspan, s, J, k4);
      h /= 6.0;
      for (i = 0; i < 190; i++) {
        P0[i] += (((2.0 * k2[i] + k1[i]) + 2.0 * k3[i]) + k4[i]) * h;
      }
    }

    for (i = 0; i < 100; i++) {
      h = P0[10 + i];
      Ad[i] = h;
      P0_1[i] = h;
    }

    i = (1 + k) * 10;
    k_ = 10 * k;
    for (i_0 = 0; i_0 < 10; i_0++) {
      memcpy(&EH[i_0 * 100 + (i + k_ * 100)], &P0_1[i_0 * 10], 10U * sizeof
             (real_T));
    }

    P0_2 = &P0[140];
    k_ = 3 * k;
    for (i_0 = 0; i_0 < 10; i_0++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        BE_tmp = i_1 + k_;
        BE_tmp_0 = (i_0 + i) + 100 * BE_tmp;
        BE[BE_tmp_0] = 0.0;
        for (i_2 = 0; i_2 < 10; i_2++) {
          BE[BE_tmp_0] = BE[(BE_tmp * 100 + i_0) + i] + Ad[10 * i_2 + i_0] *
            P0_2[10 * i_1 + i_2];
        }
      }
    }

    P0_2 = &P0[110];
    for (k_ = 0; k_ < 10; k_++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        BE_tmp = i_0 + tmp;
        BE_tmp_0 = (k_ + i) + 100 * BE_tmp;
        BE[BE_tmp_0] = 0.0;
        for (i_1 = 0; i_1 < 10; i_1++) {
          BE[BE_tmp_0] = BE[(BE_tmp * 100 + k_) + i] + Ad[10 * i_1 + k_] * P0_2
            [10 * i_0 + i_1];
        }
      }

      tspan[k_] = 0.0;
      for (i_0 = 0; i_0 < 10; i_0++) {
        tspan[k_] += Ad[10 * i_0 + k_] * P0[170 + i_0];
      }

      ES[k_ + i] = tspan[k_];
      Ad_0[k_] = 0.0;
      for (i_0 = 0; i_0 < 10; i_0++) {
        Ad_0[k_] += Ad[10 * i_0 + k_] * P0[180 + i_0];
      }

      AR[k_ + i] = Ad_0[k_];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
