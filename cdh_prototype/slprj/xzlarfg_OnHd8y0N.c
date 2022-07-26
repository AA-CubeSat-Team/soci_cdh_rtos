/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xzlarfg_OnHd8y0N.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "xnrm2_nrXTaW8D.h"
#include "xzlarfg_OnHd8y0N.h"

/* Function for MATLAB Function: '<S210>/INITIALIZE' */
real_T xzlarfg_OnHd8y0N(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  real_T xnorm;
  int32_T b_k;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2_nrXTaW8D(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = -1;
        do {
          knt++;
          for (b_k = 1; b_k < n; b_k++) {
            x[b_k] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = rt_hypotd_snf(*alpha1, xnrm2_nrXTaW8D(n - 1, x));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        for (b_k = 1; b_k < n; b_k++) {
          x[b_k] *= *alpha1;
        }

        for (b_k = 0; b_k <= knt; b_k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        for (knt = 1; knt < n; knt++) {
          x[knt] *= *alpha1;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
