/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xgeqrf_oLvid02n.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_hypotd_snf.h"
#include "xgemv_yhLPhpBF.h"
#include "xgerc_DRnL5EPl.h"
#include "xnrm2_BCgvJNRK.h"
#include "xgeqrf_oLvid02n.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void xgeqrf_oLvid02n(real_T A[144], real_T tau[12])
{
  real_T work[12];
  int32_T i_i;
  real_T b_atmp;
  int32_T i;
  real_T xnorm;
  int32_T knt;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memset(&work[0], 0, 12U * sizeof(real_T));
  for (i = 0; i < 12; i++) {
    i_i = i * 12 + i;
    if (1 + i < 12) {
      b_atmp = A[i_i];
      tau[i] = 0.0;
      xnorm = xnrm2_BCgvJNRK(11 - i, A, i_i + 2);
      if (xnorm != 0.0) {
        xnorm = rt_hypotd_snf(A[i_i], xnorm);
        if (A[i_i] >= 0.0) {
          xnorm = -xnorm;
        }

        if (fabs(xnorm) < 1.0020841800044864E-292) {
          knt = -1;
          lastv = i_i - i;
          do {
            knt++;
            for (lastc = i_i + 1; lastc < lastv + 12; lastc++) {
              A[lastc] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            b_atmp *= 9.9792015476736E+291;
          } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

          xnorm = rt_hypotd_snf(b_atmp, xnrm2_BCgvJNRK(11 - i, A, i_i + 2));
          if (b_atmp >= 0.0) {
            xnorm = -xnorm;
          }

          tau[i] = (xnorm - b_atmp) / xnorm;
          b_atmp = 1.0 / (b_atmp - xnorm);
          lastv = i_i - i;
          for (lastc = i_i + 1; lastc < lastv + 12; lastc++) {
            A[lastc] *= b_atmp;
          }

          for (lastv = 0; lastv <= knt; lastv++) {
            xnorm *= 1.0020841800044864E-292;
          }

          b_atmp = xnorm;
        } else {
          tau[i] = (xnorm - A[i_i]) / xnorm;
          b_atmp = 1.0 / (A[i_i] - xnorm);
          knt = i_i - i;
          for (lastv = i_i + 1; lastv < knt + 12; lastv++) {
            A[lastv] *= b_atmp;
          }

          b_atmp = xnorm;
        }
      }

      A[i_i] = b_atmp;
      b_atmp = A[i_i];
      A[i_i] = 1.0;
      knt = ((1 + i) * 12 + i) + 1;
      if (tau[i] != 0.0) {
        lastv = 12 - i;
        lastc = i_i - i;
        while ((lastv > 0) && (A[lastc + 11] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 11 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 12 + knt;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        xgemv_yhLPhpBF(lastv, lastc, A, knt, A, i_i + 1, work);
        xgerc_DRnL5EPl(lastv, lastc, -tau[i], i_i + 1, work, A, knt);
      }

      A[i_i] = b_atmp;
    } else {
      tau[11] = 0.0;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
