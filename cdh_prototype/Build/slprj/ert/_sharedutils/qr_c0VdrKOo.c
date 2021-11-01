/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_c0VdrKOo.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "xgemv_yhLPhpBF.h"
#include "xgeqrf_oLvid02n.h"
#include "xgerc_DRnL5EPl.h"
#include "qr_c0VdrKOo.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void qr_c0VdrKOo(const real_T A[144], real_T Q[144], real_T R[144])
{
  real_T b_A[144];
  real_T tau[12];
  int32_T d_i;
  int32_T itau;
  real_T work[12];
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 144U * sizeof(real_T));
  xgeqrf_oLvid02n(b_A, tau);
  for (itau = 0; itau < 12; itau++) {
    for (d_i = 0; d_i <= itau; d_i++) {
      R[d_i + 12 * itau] = b_A[12 * itau + d_i];
    }

    for (d_i = itau; d_i + 2 < 13; d_i++) {
      R[(d_i + 12 * itau) + 1] = 0.0;
    }

    work[itau] = 0.0;
  }

  itau = 11;
  for (d_i = 11; d_i >= 0; d_i--) {
    iaii = (d_i * 12 + d_i) + 1;
    if (d_i + 1 < 12) {
      b_A[iaii - 1] = 1.0;
      if (tau[itau] != 0.0) {
        lastv = 12 - d_i;
        lastc = (iaii - d_i) + 10;
        while ((lastv > 0) && (b_A[lastc] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 11 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 12 + iaii) + 11;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + lastv) {
              if (b_A[ia] != 0.0) {
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
        xgemv_yhLPhpBF(lastv, lastc, b_A, iaii + 12, b_A, iaii, work);
        xgerc_DRnL5EPl(lastv, lastc, -tau[itau], iaii, work, b_A, iaii + 12);
      }

      lastv = (iaii - d_i) + 11;
      for (lastc = iaii; lastc < lastv; lastc++) {
        b_A[lastc] *= -tau[itau];
      }
    }

    b_A[iaii - 1] = 1.0 - tau[itau];
    for (lastv = 0; lastv < d_i; lastv++) {
      b_A[(iaii - lastv) - 2] = 0.0;
    }

    itau--;
  }

  for (itau = 0; itau < 12; itau++) {
    memcpy(&Q[itau * 12], &b_A[itau * 12], 12U * sizeof(real_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
