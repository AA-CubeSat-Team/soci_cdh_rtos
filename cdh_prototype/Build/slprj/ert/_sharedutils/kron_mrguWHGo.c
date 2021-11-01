/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: kron_mrguWHGo.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include "kron_mrguWHGo.h"

/* Function for MATLAB Function: '<S438>/SOLVE' */
void kron_mrguWHGo(const real_T A[100], const real_T B_4[9], real_T K[900])
{
  int32_T kidx;
  int32_T b_j1;
  int32_T j2;
  int32_T i1;
  real_T K_tmp;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 10; b_j1++) {
    for (j2 = 0; j2 < 3; j2++) {
      for (i1 = 0; i1 < 10; i1++) {
        kidx++;
        K_tmp = A[10 * b_j1 + i1];
        K[kidx] = K_tmp * B_4[3 * j2];
        kidx++;
        K[kidx] = K_tmp * B_4[3 * j2 + 1];
        kidx++;
        K[kidx] = K_tmp * B_4[3 * j2 + 2];
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
