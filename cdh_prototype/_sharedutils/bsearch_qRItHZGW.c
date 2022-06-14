/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bsearch_qRItHZGW.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include "bsearch_qRItHZGW.h"

/* Function for MATLAB Function: '<S385>/soar_INTERP' */
int32_T bsearch_qRItHZGW(const real_T x[10], real_T xi)
{
  int32_T high_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T n;
  n = 1;
  low_ip1 = 2;
  high_i = 10;
  while (high_i > low_ip1) {
    mid_i = (n + high_i) >> 1;
    if (xi >= x[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
