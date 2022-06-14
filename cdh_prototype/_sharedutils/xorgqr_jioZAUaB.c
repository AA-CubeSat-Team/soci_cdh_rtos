/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xorgqr_jioZAUaB.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "xgemv_gLgGfGIZ.h"
#include "xgerc_jhTkIWHW.h"
#include "xorgqr_jioZAUaB.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void xorgqr_jioZAUaB(int32_T m, int32_T n, int32_T k, real_T A[144], int32_T ia0,
                     const real_T tau[12], int32_T itau0)
{
  real_T work[12];
  int32_T b_ia;
  int32_T coltop;
  int32_T exitg1;
  int32_T i;
  int32_T iaii;
  int32_T itau;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  if (n >= 1) {
    for (itau = k; itau < n; itau++) {
      i = (itau * 12 + ia0) - 1;
      for (iaii = 0; iaii < m; iaii++) {
        A[i + iaii] = 0.0;
      }

      A[i + itau] = 1.0;
    }

    itau = (itau0 + k) - 2;
    memset(&work[0], 0, 12U * sizeof(real_T));
    for (i = k; i >= 1; i--) {
      iaii = (((i - 1) * 12 + ia0) + i) - 1;
      if (i < n) {
        A[iaii - 1] = 1.0;
        lastc = (m - i) - 1;
        if (tau[itau] != 0.0) {
          lastv = lastc + 2;
          lastc += iaii;
          while ((lastv > 0) && (A[lastc] == 0.0)) {
            lastv--;
            lastc--;
          }

          lastc = n - i;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            coltop = ((lastc - 1) * 12 + iaii) + 11;
            b_ia = coltop;
            do {
              exitg1 = 0;
              if (b_ia + 1 <= coltop + lastv) {
                if (A[b_ia] != 0.0) {
                  exitg1 = 1;
                } else {
                  b_ia++;
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
          xgemv_gLgGfGIZ(lastv, lastc, A, iaii + 12, A, iaii, work);
          xgerc_jhTkIWHW(lastv, lastc, -tau[itau], iaii, work, A, iaii + 12);
        }
      }

      if (i < m) {
        lastv = (iaii + m) - i;
        for (lastc = iaii; lastc < lastv; lastc++) {
          A[lastc] *= -tau[itau];
        }
      }

      A[iaii - 1] = 1.0 - tau[itau];
      for (lastv = 0; lastv <= i - 2; lastv++) {
        A[(iaii - lastv) - 2] = 0.0;
      }

      itau--;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
