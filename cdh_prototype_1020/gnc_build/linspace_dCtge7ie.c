/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: linspace_dCtge7ie.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "linspace_dCtge7ie.h"

/* Function for MATLAB Function: '<S317>/SOLVE' */
void linspace_dCtge7ie(real_T d1, real_T d2, real_T y[10])
{
  real_T delta1;
  real_T delta2;
  int32_T b_k;
  y[9] = d2;
  y[0] = d1;
  if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307) ||
       (fabs(d2) > 8.9884656743115785E+307))) {
    delta1 = d1 / 9.0;
    delta2 = d2 / 9.0;
    for (b_k = 0; b_k < 8; b_k++) {
      y[b_k + 1] = ((1.0 + (real_T)b_k) * delta2 + d1) - (1.0 + (real_T)b_k) *
        delta1;
    }
  } else {
    delta1 = (d2 - d1) / 9.0;
    for (b_k = 0; b_k < 8; b_k++) {
      y[b_k + 1] = (1.0 + (real_T)b_k) * delta1 + d1;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
