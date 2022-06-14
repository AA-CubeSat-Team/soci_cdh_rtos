/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qrf_87AzkAFc.c
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
#include "rt_hypotd_snf.h"
#include "xgemv_gLgGfGIZ.h"
#include "xgerc_jhTkIWHW.h"
#include "xnrm2_oLi98ch9.h"
#include "qrf_87AzkAFc.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void qrf_87AzkAFc(real_T A[144], int32_T ia0, int32_T m, int32_T n, int32_T nfxd,
                  real_T tau[12])
{
  real_T work[12];
  real_T b_atmp;
  real_T beta1;
  int32_T b_i;
  int32_T c_k;
  int32_T exitg1;
  int32_T ii;
  int32_T knt;
  int32_T mmi;
  int32_T mmip1;
  boolean_T exitg2;
  memset(&work[0], 0, 12U * sizeof(real_T));
  for (b_i = 0; b_i < nfxd; b_i++) {
    ii = ((b_i * 12 + ia0) + b_i) - 1;
    mmi = m - b_i;
    if (b_i + 1 < m) {
      b_atmp = A[ii];
      tau[b_i] = 0.0;
      if (mmi > 0) {
        beta1 = xnrm2_oLi98ch9(mmi - 1, A, ii + 2);
        if (beta1 != 0.0) {
          beta1 = rt_hypotd_snf(A[ii], beta1);
          if (A[ii] >= 0.0) {
            beta1 = -beta1;
          }

          if (fabs(beta1) < 1.0020841800044864E-292) {
            knt = -1;
            c_k = ii + mmi;
            do {
              knt++;
              for (mmip1 = ii + 1; mmip1 < c_k; mmip1++) {
                A[mmip1] *= 9.9792015476736E+291;
              }

              beta1 *= 9.9792015476736E+291;
              b_atmp *= 9.9792015476736E+291;
            } while (!(fabs(beta1) >= 1.0020841800044864E-292));

            beta1 = rt_hypotd_snf(b_atmp, xnrm2_oLi98ch9(mmi - 1, A, ii + 2));
            if (b_atmp >= 0.0) {
              beta1 = -beta1;
            }

            tau[b_i] = (beta1 - b_atmp) / beta1;
            b_atmp = 1.0 / (b_atmp - beta1);
            c_k = ii + mmi;
            for (mmip1 = ii + 1; mmip1 < c_k; mmip1++) {
              A[mmip1] *= b_atmp;
            }

            for (c_k = 0; c_k <= knt; c_k++) {
              beta1 *= 1.0020841800044864E-292;
            }

            b_atmp = beta1;
          } else {
            tau[b_i] = (beta1 - A[ii]) / beta1;
            b_atmp = 1.0 / (A[ii] - beta1);
            knt = ii + mmi;
            for (c_k = ii + 1; c_k < knt; c_k++) {
              A[c_k] *= b_atmp;
            }

            b_atmp = beta1;
          }
        }
      }

      A[ii] = b_atmp;
    } else {
      tau[b_i] = 0.0;
    }

    if (b_i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      if (tau[b_i] != 0.0) {
        mmip1 = (ii + mmi) - 1;
        while ((mmi > 0) && (A[mmip1] == 0.0)) {
          mmi--;
          mmip1--;
        }

        mmip1 = (n - b_i) - 1;
        exitg2 = false;
        while ((!exitg2) && (mmip1 > 0)) {
          knt = ((mmip1 - 1) * 12 + ii) + 12;
          c_k = knt;
          do {
            exitg1 = 0;
            if (c_k + 1 <= knt + mmi) {
              if (A[c_k] != 0.0) {
                exitg1 = 1;
              } else {
                c_k++;
              }
            } else {
              mmip1--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        mmi = 0;
        mmip1 = 0;
      }

      if (mmi > 0) {
        xgemv_gLgGfGIZ(mmi, mmip1, A, ii + 13, A, ii + 1, work);
        xgerc_jhTkIWHW(mmi, mmip1, -tau[b_i], ii + 1, work, A, ii + 13);
      }

      A[ii] = b_atmp;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
