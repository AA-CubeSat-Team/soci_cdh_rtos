/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xzlarfg_J3AXVwxO.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "xnrm2_hQNiN0t8.h"
#include "xzlarfg_J3AXVwxO.h"

/* Function for MATLAB Function: '<S412>/INITIALIZE' */
real_T xzlarfg_J3AXVwxO(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  real_T xnorm;
  int32_T knt;
  int32_T c_k;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2_hQNiN0t8(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = -1;
        do {
          knt++;
          for (c_k = 1; c_k < n; c_k++) {
            x[c_k] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = rt_hypotd_snf(*alpha1, xnrm2_hQNiN0t8(n - 1, x));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        for (c_k = 1; c_k < n; c_k++) {
          x[c_k] *= *alpha1;
        }

        for (c_k = 0; c_k <= knt; c_k++) {
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
