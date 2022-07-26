/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: schur_ZrGmuypS.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "eml_dlahqr_9Xlai4UO.h"
#include "xgehrd_oBoAXf5H.h"
#include "xzlarf_Ddk2Tem0.h"
#include "schur_ZrGmuypS.h"

/* Function for MATLAB Function: '<S210>/INITIALIZE' */
void schur_ZrGmuypS(const real_T A[16], real_T V[16], real_T T[16])
{
  real_T work[4];
  real_T tau[3];
  real_T A_0;
  int32_T itau;
  boolean_T p;
  p = true;
  for (itau = 0; itau < 16; itau++) {
    A_0 = A[itau];
    if (p && (rtIsInf(A_0) || rtIsNaN(A_0))) {
      p = false;
    }
  }

  if (!p) {
    for (itau = 0; itau < 16; itau++) {
      V[itau] = (rtNaN);
    }

    for (itau = 2; itau < 5; itau++) {
      V[itau - 1] = 0.0;
    }

    for (itau = 3; itau < 5; itau++) {
      V[itau + 3] = 0.0;
    }

    V[11] = 0.0;
    for (itau = 0; itau < 16; itau++) {
      T[itau] = (rtNaN);
    }
  } else {
    memcpy(&T[0], &A[0], sizeof(real_T) << 4U);
    xgehrd_oBoAXf5H(T, tau);
    memcpy(&V[0], &T[0], sizeof(real_T) << 4U);
    for (itau = 0; itau < 3; itau++) {
      V[itau + 12] = 0.0;
    }

    for (itau = 0; itau < 2; itau++) {
      V[itau + 8] = 0.0;
    }

    for (itau = 1; itau + 3 < 5; itau++) {
      V[itau + 10] = V[itau + 6];
    }

    V[4] = 0.0;
    for (itau = 0; itau + 3 < 5; itau++) {
      V[itau + 6] = V[itau + 2];
    }

    work[0] = 0.0;
    V[1] = 0.0;
    work[1] = 0.0;
    V[2] = 0.0;
    work[2] = 0.0;
    V[3] = 0.0;
    work[3] = 0.0;
    V[0] = 1.0;
    V[15] = 1.0 - tau[2];
    for (itau = 0; itau < 2; itau++) {
      V[14 - itau] = 0.0;
    }

    V[10] = 1.0;
    xzlarf_Ddk2Tem0(2, 1, 11, tau[1], V, 15, work);
    for (itau = 11; itau < 12; itau++) {
      V[itau] *= -tau[1];
    }

    V[10] = 1.0 - tau[1];
    V[9] = 0.0;
    V[5] = 1.0;
    xzlarf_Ddk2Tem0(3, 2, 6, tau[0], V, 10, work);
    for (itau = 6; itau < 8; itau++) {
      V[itau] *= -tau[0];
    }

    V[5] = 1.0 - tau[0];
    eml_dlahqr_9Xlai4UO(T, V);
    T[3] = 0.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
