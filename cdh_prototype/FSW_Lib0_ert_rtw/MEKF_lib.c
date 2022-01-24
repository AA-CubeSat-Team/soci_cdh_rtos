/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "MEKF_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "rt_hypotd_snf.h"
#include "rt_powd_snf.h"

/* Forward declaration for local functions */
static real_T xnrm2_BCgvJNRK_n(int32_T n, const real_T x[144], int32_T ix0,
  DW_MEKF_lib *localDW);
static void xgemv_yhLPhpBF_l(int32_T m, int32_T n, const real_T A[144], int32_T
  ia0, const real_T x[144], int32_T ix0, real_T y[12], DW_MEKF_lib *localDW);
static void xgerc_DRnL5EPl_o(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[12], real_T A[144], int32_T ia0, DW_MEKF_lib *localDW);
static void xgeqrf_oLvid02n_g(real_T A[144], real_T tau[12], DW_MEKF_lib
  *localDW);
static void qr_c0VdrKOo_k(const real_T A[144], real_T Q[144], real_T R[144],
  DW_MEKF_lib *localDW);
static void mrdivide_helper_23K2DU9e_j(real_T A[36], const real_T B_0[36],
  DW_MEKF_lib *localDW);
static void SystemCore_release(dsp_simulink_MovingAverage *obj);
static void SystemCore_delete(dsp_simulink_MovingAverage *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage *obj);

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static real_T xnrm2_BCgvJNRK_n(int32_T n, const real_T x[144], int32_T ix0,
  DW_MEKF_lib *localDW)
{
  real_T y;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      localDW->scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > localDW->scale) {
          t = localDW->scale / absxk;
          y = y * t * t + 1.0;
          localDW->scale = absxk;
        } else {
          t = absxk / localDW->scale;
          y += t * t;
        }
      }

      y = localDW->scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static void xgemv_yhLPhpBF_l(int32_T m, int32_T n, const real_T A[144], int32_T
  ia0, const real_T x[144], int32_T ix0, real_T y[12], DW_MEKF_lib *localDW)
{
  int32_T ix;
  int32_T b_iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 12 + ia0;
    for (iac = ia0; iac <= b; iac += 12) {
      ix = ix0;
      localDW->c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        localDW->c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += localDW->c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static void xgerc_DRnL5EPl_o(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[12], real_T A[144], int32_T ia0, DW_MEKF_lib *localDW)
{
  int32_T jA;
  int32_T jy;
  int32_T ix;
  int32_T j;
  int32_T b;
  int32_T ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        localDW->temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * localDW->temp;
          ix++;
        }
      }

      jy++;
      jA += 12;
    }
  }
}

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static void xgeqrf_oLvid02n_g(real_T A[144], real_T tau[12], DW_MEKF_lib
  *localDW)
{
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memset(&localDW->work_c[0], 0, 12U * sizeof(real_T));
  for (localDW->i_g = 0; localDW->i_g < 12; localDW->i_g++) {
    localDW->i_i = localDW->i_g * 12 + localDW->i_g;
    if (1 + localDW->i_g < 12) {
      localDW->b_atmp = A[localDW->i_i];
      tau[localDW->i_g] = 0.0;
      localDW->xnorm = xnrm2_BCgvJNRK_n(11 - localDW->i_g, A, localDW->i_i + 2,
        localDW);
      if (localDW->xnorm != 0.0) {
        localDW->xnorm = rt_hypotd_snf(A[localDW->i_i], localDW->xnorm);
        if (A[localDW->i_i] >= 0.0) {
          localDW->xnorm = -localDW->xnorm;
        }

        if (fabs(localDW->xnorm) < 1.0020841800044864E-292) {
          localDW->knt = -1;
          localDW->lastv_m = localDW->i_i - localDW->i_g;
          do {
            localDW->knt++;
            localDW->lastc_n = localDW->i_i + 1;
            while (localDW->lastc_n + 1 <= localDW->lastv_m + 12) {
              A[localDW->lastc_n] *= 9.9792015476736E+291;
              localDW->lastc_n++;
            }

            localDW->xnorm *= 9.9792015476736E+291;
            localDW->b_atmp *= 9.9792015476736E+291;
          } while (!(fabs(localDW->xnorm) >= 1.0020841800044864E-292));

          localDW->xnorm = rt_hypotd_snf(localDW->b_atmp, xnrm2_BCgvJNRK_n(11 -
            localDW->i_g, A, localDW->i_i + 2, localDW));
          if (localDW->b_atmp >= 0.0) {
            localDW->xnorm = -localDW->xnorm;
          }

          tau[localDW->i_g] = (localDW->xnorm - localDW->b_atmp) /
            localDW->xnorm;
          localDW->b_atmp = 1.0 / (localDW->b_atmp - localDW->xnorm);
          localDW->lastv_m = localDW->i_i - localDW->i_g;
          localDW->lastc_n = localDW->i_i + 1;
          while (localDW->lastc_n + 1 <= localDW->lastv_m + 12) {
            A[localDW->lastc_n] *= localDW->b_atmp;
            localDW->lastc_n++;
          }

          localDW->lastv_m = 0;
          while (localDW->lastv_m <= localDW->knt) {
            localDW->xnorm *= 1.0020841800044864E-292;
            localDW->lastv_m++;
          }

          localDW->b_atmp = localDW->xnorm;
        } else {
          tau[localDW->i_g] = (localDW->xnorm - A[localDW->i_i]) /
            localDW->xnorm;
          localDW->b_atmp = 1.0 / (A[localDW->i_i] - localDW->xnorm);
          localDW->knt = localDW->i_i - localDW->i_g;
          localDW->lastv_m = localDW->i_i + 1;
          while (localDW->lastv_m + 1 <= localDW->knt + 12) {
            A[localDW->lastv_m] *= localDW->b_atmp;
            localDW->lastv_m++;
          }

          localDW->b_atmp = localDW->xnorm;
        }
      }

      A[localDW->i_i] = localDW->b_atmp;
      localDW->b_atmp = A[localDW->i_i];
      A[localDW->i_i] = 1.0;
      localDW->knt = ((1 + localDW->i_g) * 12 + localDW->i_g) + 1;
      if (tau[localDW->i_g] != 0.0) {
        localDW->lastv_m = 12 - localDW->i_g;
        localDW->lastc_n = localDW->i_i - localDW->i_g;
        while ((localDW->lastv_m > 0) && (A[localDW->lastc_n + 11] == 0.0)) {
          localDW->lastv_m--;
          localDW->lastc_n--;
        }

        localDW->lastc_n = 11 - localDW->i_g;
        exitg2 = false;
        while ((!exitg2) && (localDW->lastc_n > 0)) {
          coltop = (localDW->lastc_n - 1) * 12 + localDW->knt;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + localDW->lastv_m) - 1) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              localDW->lastc_n--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localDW->lastv_m = 0;
        localDW->lastc_n = 0;
      }

      if (localDW->lastv_m > 0) {
        xgemv_yhLPhpBF_l(localDW->lastv_m, localDW->lastc_n, A, localDW->knt, A,
                         localDW->i_i + 1, localDW->work_c, localDW);
        xgerc_DRnL5EPl_o(localDW->lastv_m, localDW->lastc_n, -tau[localDW->i_g],
                         localDW->i_i + 1, localDW->work_c, A, localDW->knt,
                         localDW);
      }

      A[localDW->i_i] = localDW->b_atmp;
    } else {
      tau[11] = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static void qr_c0VdrKOo_k(const real_T A[144], real_T Q[144], real_T R[144],
  DW_MEKF_lib *localDW)
{
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&localDW->b_A[0], &A[0], 144U * sizeof(real_T));
  xgeqrf_oLvid02n_g(localDW->b_A, localDW->tau, localDW);
  for (localDW->itau = 0; localDW->itau < 12; localDW->itau++) {
    localDW->d_i = 0;
    while (localDW->d_i <= localDW->itau) {
      R[localDW->d_i + 12 * localDW->itau] = localDW->b_A[12 * localDW->itau +
        localDW->d_i];
      localDW->d_i++;
    }

    localDW->d_i = localDW->itau;
    while (localDW->d_i + 2 < 13) {
      R[(localDW->d_i + 12 * localDW->itau) + 1] = 0.0;
      localDW->d_i++;
    }

    localDW->work[localDW->itau] = 0.0;
  }

  localDW->itau = 11;
  for (localDW->d_i = 11; localDW->d_i >= 0; localDW->d_i--) {
    localDW->iaii = (localDW->d_i * 12 + localDW->d_i) + 1;
    if (localDW->d_i + 1 < 12) {
      localDW->b_A[localDW->iaii - 1] = 1.0;
      if (localDW->tau[localDW->itau] != 0.0) {
        localDW->lastv = 12 - localDW->d_i;
        localDW->lastc = (localDW->iaii - localDW->d_i) + 10;
        while ((localDW->lastv > 0) && (localDW->b_A[localDW->lastc] == 0.0)) {
          localDW->lastv--;
          localDW->lastc--;
        }

        localDW->lastc = 11 - localDW->d_i;
        exitg2 = false;
        while ((!exitg2) && (localDW->lastc > 0)) {
          localDW->coltop = ((localDW->lastc - 1) * 12 + localDW->iaii) + 11;
          localDW->ia = localDW->coltop;
          do {
            exitg1 = 0;
            if (localDW->ia + 1 <= localDW->coltop + localDW->lastv) {
              if (localDW->b_A[localDW->ia] != 0.0) {
                exitg1 = 1;
              } else {
                localDW->ia++;
              }
            } else {
              localDW->lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localDW->lastv = 0;
        localDW->lastc = 0;
      }

      if (localDW->lastv > 0) {
        xgemv_yhLPhpBF_l(localDW->lastv, localDW->lastc, localDW->b_A,
                         localDW->iaii + 12, localDW->b_A, localDW->iaii,
                         localDW->work, localDW);
        xgerc_DRnL5EPl_o(localDW->lastv, localDW->lastc, -localDW->tau
                         [localDW->itau], localDW->iaii, localDW->work,
                         localDW->b_A, localDW->iaii + 12, localDW);
      }

      localDW->lastv = (localDW->iaii - localDW->d_i) + 11;
      localDW->lastc = localDW->iaii;
      while (localDW->lastc + 1 <= localDW->lastv) {
        localDW->b_A[localDW->lastc] *= -localDW->tau[localDW->itau];
        localDW->lastc++;
      }
    }

    localDW->b_A[localDW->iaii - 1] = 1.0 - localDW->tau[localDW->itau];
    localDW->lastv = 0;
    while (localDW->lastv <= localDW->d_i - 1) {
      localDW->b_A[(localDW->iaii - localDW->lastv) - 2] = 0.0;
      localDW->lastv++;
    }

    localDW->itau--;
  }

  for (localDW->itau = 0; localDW->itau < 12; localDW->itau++) {
    memcpy(&Q[localDW->itau * 12], &localDW->b_A[localDW->itau * 12], 12U *
           sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S119>/QR_factorization' */
static void mrdivide_helper_23K2DU9e_j(real_T A[36], const real_T B_0[36],
  DW_MEKF_lib *localDW)
{
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&localDW->b_A_k[0], &B_0[0], 36U * sizeof(real_T));
  for (d = 0; d < 6; d++) {
    localDW->ipiv[d] = (int8_T)(1 + d);
  }

  for (j = 0; j < 5; j++) {
    jBcol = j * 7;
    iy = 0;
    ix = jBcol;
    localDW->smax = fabs(localDW->b_A_k[jBcol]);
    for (kBcol = 2; kBcol <= 6 - j; kBcol++) {
      ix++;
      localDW->s = fabs(localDW->b_A_k[ix]);
      if (localDW->s > localDW->smax) {
        iy = kBcol - 1;
        localDW->smax = localDW->s;
      }
    }

    if (localDW->b_A_k[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        localDW->ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          localDW->smax = localDW->b_A_k[ix];
          localDW->b_A_k[ix] = localDW->b_A_k[iy];
          localDW->b_A_k[iy] = localDW->smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - j) + 6;
      for (ix = jBcol + 1; ix < iy; ix++) {
        localDW->b_A_k[ix] /= localDW->b_A_k[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 0; kBcol <= 4 - j; kBcol++) {
      if (localDW->b_A_k[ix] != 0.0) {
        localDW->smax = -localDW->b_A_k[ix];
        c_ix = jBcol + 1;
        d = (iy - j) + 12;
        for (ijA = 7 + iy; ijA < d; ijA++) {
          localDW->b_A_k[ijA] += localDW->b_A_k[c_ix] * localDW->smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    iy = 6 * j;
    for (ix = 0; ix < j; ix++) {
      kBcol = 6 * ix;
      localDW->smax = localDW->b_A_k[ix + iy];
      if (localDW->smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          A[d] -= localDW->smax * A[c_ix + kBcol];
        }
      }
    }

    localDW->smax = 1.0 / localDW->b_A_k[j + iy];
    for (iy = 0; iy < 6; iy++) {
      d = iy + jBcol;
      A[d] *= localDW->smax;
    }
  }

  for (j = 5; j >= 0; j--) {
    jBcol = 6 * j;
    iy = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 6;
      localDW->smax = localDW->b_A_k[ix + iy];
      if (localDW->smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jBcol] -= localDW->smax * A[c_ix + kBcol];
        }
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    if (j + 1 != localDW->ipiv[j]) {
      jBcol = localDW->ipiv[j] - 1;
      for (iy = 0; iy < 6; iy++) {
        localDW->smax = A[6 * j + iy];
        A[iy + 6 * j] = A[6 * jBcol + iy];
        A[iy + 6 * jBcol] = localDW->smax;
      }
    }
  }
}

static void SystemCore_release(dsp_simulink_MovingAverage *obj)
{
  dsp_private_SlidingWindowAverag *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void SystemCore_delete(dsp_simulink_MovingAverage *obj)
{
  SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete(obj);
  }
}

/* System initialize for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW, P_MEKF_lib
                   *localP)
{
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0], &rtP.fswParams.estimation.ic.Pchol_init
         [0], 36U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE[0] = rtP.fswParams.estimation.ic.Beta_init[0];
  localDW->UnitDelay1_DSTATE[1] = rtP.fswParams.estimation.ic.Beta_init[1];
  localDW->UnitDelay1_DSTATE[2] = rtP.fswParams.estimation.ic.Beta_init[2];

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = rtP.fswParams.estimation.ic.quat_est_init[0];
  localDW->UnitDelay3_DSTATE[1] = rtP.fswParams.estimation.ic.quat_est_init[1];
  localDW->UnitDelay3_DSTATE[2] = rtP.fswParams.estimation.ic.quat_est_init[2];
  localDW->UnitDelay3_DSTATE[3] = rtP.fswParams.estimation.ic.quat_est_init[3];

  /* InitializeConditions for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = localP->DetectRisePositive_vinit;

  /* SystemInitialize for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  TRIADActivation_lib_Init(&localDW->TRIADActivation_lib_f,
    &localP->TRIADActivation_lib_f);

  /* End of SystemInitialize for SubSystem: '<S3>/TRIADActivation_lib' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/TriadEstimator_lib' */
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[0] = rtP.fswParams.estimation.ic.quat_est_init[0];

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[0] = localP->Merge_InitialOutput[0];

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[1] = rtP.fswParams.estimation.ic.quat_est_init[1];

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[1] = localP->Merge_InitialOutput[1];

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[2] = rtP.fswParams.estimation.ic.quat_est_init[2];

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[2] = localP->Merge_InitialOutput[2];

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_g[3] = rtP.fswParams.estimation.ic.quat_est_init[3];

  /* SystemInitialize for IfAction SubSystem: '<S125>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S188>/Merge' */
  localDW->Merge[3] = localP->Merge_InitialOutput[3];

  /* End of SystemInitialize for SubSystem: '<S125>/TriadAlgorithm' */
  /* End of SystemInitialize for SubSystem: '<S3>/TriadEstimator_lib' */

  /* SystemInitialize for Merge: '<S3>/q_p_merge' */
  rty_sc_quat[0] = localP->q_p_merge_InitialOutput;
  rty_sc_quat[1] = localP->q_p_merge_InitialOutput;
  rty_sc_quat[2] = localP->q_p_merge_InitialOutput;
  rty_sc_quat[3] = localP->q_p_merge_InitialOutput;

  /* InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 9U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S121>/Moving Average' */
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  /* Start for If: '<S3>/TRIAD_activation' */
  localDW->TRIAD_activation_ActiveSubsyste = -1;

  /* Start for S-Function (sdspeye): '<S165>/Id_3' */
  memset(&localDW->Id_3[0], 0, 9U * sizeof(real_T));

  /* Fill in 1's on the diagonal. */
  localDW->Id_3[0] = 1.0;
  localDW->Id_3[4] = 1.0;
  localDW->Id_3[8] = 1.0;

  /* Start for MATLABSystem: '<S121>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->gobj_0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/* Output and update for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib(const real_T rtu_sc2sun_eci_unit[3], const real_T rtu_mag_eci_T[3],
              const real_T rtu_sun_meas_body_unit[3], const real_T
              rtu_mag_meas_body_T[3], const real_T rtu_gyro_meas_body_radps[3],
              uint8_T rtu_sunsensor_valid, boolean_T rtu_mag_meas_valid,
              boolean_T rtu_gryo_meas_valid, boolean_T rtu_triad_activate,
              real_T rty_sc_quat[4], real_T rty_body_rates_radps[3], real_T
              rty_threeSigma_rad[6], real_T rty_bias_radps[3], uint8_T
              *rty_mekf_telem, DW_MEKF_lib *localDW, P_MEKF_lib *localP)
{
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  boolean_T rtb_Compare_e;
  boolean_T rtb_Switch_i4;
  uint8_T rtb_Sum_fj;
  boolean_T rtb_Switch_hl;
  boolean_T rtb_Switch_os;

  /* RelationalOperator: '<S117>/Compare' incorporates:
   *  Constant: '<S117>/Constant'
   */
  rtb_Compare_e = (rtu_sunsensor_valid != localP->CompareToConstant_const);

  /* Outputs for Atomic SubSystem: '<S115>/parallel_protection_lib' */
  rtb_Switch_i4 = parallel_protection_lib(rtu_sun_meas_body_unit,
    rtu_mag_meas_body_T, &localP->parallel_protection_lib_d,
    rtP.fswParams.estimation.triad_parallel_tol_deg);

  /* End of Outputs for SubSystem: '<S115>/parallel_protection_lib' */

  /* Sum: '<S115>/Sum' incorporates:
   *  Logic: '<S115>/AND'
   */
  rtb_Sum_fj = (uint8_T)((uint32_T)(rtb_Compare_e && rtu_mag_meas_valid &&
    rtu_gryo_meas_valid) + rtb_Switch_i4);

  /* Outputs for Atomic SubSystem: '<S3>/TRIADActivation_lib' */
  rtb_Switch_i4 = TRIADActivation_lib(rtu_triad_activate, rtu_gryo_meas_valid,
    rtb_Compare_e, rtu_mag_meas_valid, &localDW->TRIADActivation_lib_f);

  /* End of Outputs for SubSystem: '<S3>/TRIADActivation_lib' */

  /* If: '<S3>/TRIAD_activation' incorporates:
   *  Inport: '<S127>/In1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  if (rtb_Switch_i4) {
    localDW->TRIAD_activation_ActiveSubsyste = 0;

    /* Outputs for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Math: '<S175>/Math Function' */
    localDW->MathFunction_j[0] = rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0];
    localDW->MathFunction_j[1] = rtu_mag_meas_body_T[1] * rtu_mag_meas_body_T[1];
    localDW->MathFunction_j[2] = rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2];

    /* Sum: '<S175>/Sum of Elements' */
    localDW->Product3_j = (localDW->MathFunction_j[0] + localDW->MathFunction_j
      [1]) + localDW->MathFunction_j[2];

    /* Math: '<S175>/Math Function1'
     *
     * About '<S175>/Math Function1':
     *  Operator: sqrt
     */
    if (localDW->Product3_j < 0.0) {
      localDW->Product3_j = -sqrt(fabs(localDW->Product3_j));
    } else {
      localDW->Product3_j = sqrt(localDW->Product3_j);
    }

    /* End of Math: '<S175>/Math Function1' */

    /* Switch: '<S175>/Switch' incorporates:
     *  Constant: '<S175>/Constant'
     */
    if (localDW->Product3_j > localP->NormalizeVector1_maxzero) {
      localDW->Merge_i[0] = rtu_mag_meas_body_T[0];
      localDW->Merge_i[1] = rtu_mag_meas_body_T[1];
      localDW->Merge_i[2] = rtu_mag_meas_body_T[2];
      localDW->Merge_i[3] = localDW->Product3_j;
    } else {
      /* Product: '<S175>/Product' */
      localDW->MathFunction_j[0] = rtu_mag_meas_body_T[0] * 0.0;
      localDW->MathFunction_j[1] = rtu_mag_meas_body_T[1] * 0.0;
      localDW->MathFunction_j[2] = rtu_mag_meas_body_T[2] * 0.0;
      localDW->Merge_i[0] = localDW->MathFunction_j[0];
      localDW->Merge_i[1] = localDW->MathFunction_j[1];
      localDW->Merge_i[2] = localDW->MathFunction_j[2];
      localDW->Merge_i[3] = localP->Constant_Value_cb;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Product: '<S175>/Divide' */
    localDW->MathFunction_j[0] = localDW->Merge_i[0] / localDW->Merge_i[3];
    localDW->MathFunction_j[1] = localDW->Merge_i[1] / localDW->Merge_i[3];
    localDW->MathFunction_j[2] = localDW->Merge_i[2] / localDW->Merge_i[3];

    /* Math: '<S174>/Math Function' */
    localDW->MathFunction_p[0] = rtu_mag_eci_T[0] * rtu_mag_eci_T[0];
    localDW->MathFunction_p[1] = rtu_mag_eci_T[1] * rtu_mag_eci_T[1];
    localDW->MathFunction_p[2] = rtu_mag_eci_T[2] * rtu_mag_eci_T[2];

    /* Sum: '<S174>/Sum of Elements' */
    localDW->Product3_j = (localDW->MathFunction_p[0] + localDW->MathFunction_p
      [1]) + localDW->MathFunction_p[2];

    /* Math: '<S174>/Math Function1'
     *
     * About '<S174>/Math Function1':
     *  Operator: sqrt
     */
    if (localDW->Product3_j < 0.0) {
      localDW->Product3_j = -sqrt(fabs(localDW->Product3_j));
    } else {
      localDW->Product3_j = sqrt(localDW->Product3_j);
    }

    /* End of Math: '<S174>/Math Function1' */

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     */
    if (localDW->Product3_j > localP->NormalizeVector_maxzero) {
      localDW->Merge_i[0] = rtu_mag_eci_T[0];
      localDW->Merge_i[1] = rtu_mag_eci_T[1];
      localDW->Merge_i[2] = rtu_mag_eci_T[2];
      localDW->Merge_i[3] = localDW->Product3_j;
    } else {
      /* Product: '<S174>/Product' */
      localDW->MathFunction_p[0] = rtu_mag_eci_T[0] * 0.0;
      localDW->MathFunction_p[1] = rtu_mag_eci_T[1] * 0.0;
      localDW->MathFunction_p[2] = rtu_mag_eci_T[2] * 0.0;
      localDW->Merge_i[0] = localDW->MathFunction_p[0];
      localDW->Merge_i[1] = localDW->MathFunction_p[1];
      localDW->Merge_i[2] = localDW->MathFunction_p[2];
      localDW->Merge_i[3] = localP->Constant_Value_e;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Product: '<S174>/Divide' */
    localDW->MathFunction_p[0] = localDW->Merge_i[0] / localDW->Merge_i[3];
    localDW->MathFunction_p[1] = localDW->Merge_i[1] / localDW->Merge_i[3];
    localDW->MathFunction_p[2] = localDW->Merge_i[2] / localDW->Merge_i[3];

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib' */
    rtb_Switch_hl = parallel_protection_lib(rtu_sun_meas_body_unit,
      localDW->MathFunction_j, &localP->parallel_protection_lib_c,
      rtP.fswParams.estimation.triad_parallel_tol_deg);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib' */

    /* Outputs for Atomic SubSystem: '<S125>/parallel_protection_lib1' */
    rtb_Switch_os = parallel_protection_lib(rtu_sc2sun_eci_unit,
      localDW->MathFunction_p, &localP->parallel_protection_lib1,
      rtP.fswParams.estimation.triad_parallel_tol_deg);

    /* End of Outputs for SubSystem: '<S125>/parallel_protection_lib1' */

    /* If: '<S125>/If' incorporates:
     *  Inport: '<S178>/quat_old'
     *  Logic: '<S125>/Logical Operator'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    if (rtb_Compare_e && rtu_mag_meas_valid && rtb_Switch_hl && rtb_Switch_os) {
      /* Outputs for IfAction SubSystem: '<S125>/TriadAlgorithm' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate3In1' */
      localDW->MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];
      localDW->MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];
      localDW->MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Product: '<S184>/Element product' */
      localDW->Elementproduct_g[0] = rtu_sun_meas_body_unit[1] *
        localDW->MathFunction_j[2];
      localDW->Elementproduct_g[1] = rtu_sun_meas_body_unit[2] *
        localDW->MathFunction_j[0];
      localDW->Elementproduct_g[2] = rtu_sun_meas_body_unit[0] *
        localDW->MathFunction_j[1];
      localDW->Elementproduct_g[3] = rtu_sun_meas_body_unit[2] *
        localDW->MathFunction_j[1];
      localDW->Elementproduct_g[4] = rtu_sun_meas_body_unit[0] *
        localDW->MathFunction_j[2];
      localDW->Elementproduct_g[5] = rtu_sun_meas_body_unit[1] *
        localDW->MathFunction_j[0];

      /* Sum: '<S184>/Add3' */
      localDW->MathFunction_j[0] = localDW->Elementproduct_g[0] -
        localDW->Elementproduct_g[3];
      localDW->MathFunction_j[1] = localDW->Elementproduct_g[1] -
        localDW->Elementproduct_g[4];
      localDW->MathFunction_j[2] = localDW->Elementproduct_g[2] -
        localDW->Elementproduct_g[5];

      /* S-Function (sdsp2norm2): '<S177>/Normalization6' */
      localDW->Product3_j = 1.0 / (sqrt((localDW->MathFunction_j[0] *
        localDW->MathFunction_j[0] + localDW->MathFunction_j[1] *
        localDW->MathFunction_j[1]) + localDW->MathFunction_j[2] *
        localDW->MathFunction_j[2]) + localP->Normalization6_Bias);
      localDW->MathFunction_j[0] *= localDW->Product3_j;
      localDW->MathFunction_j[1] *= localDW->Product3_j;
      localDW->MathFunction_j[2] *= localDW->Product3_j;

      /* Product: '<S186>/Element product' */
      localDW->Elementproduct_g[0] = rtu_sc2sun_eci_unit[1] *
        localDW->MathFunction_p[2];
      localDW->Elementproduct_g[1] = rtu_sc2sun_eci_unit[2] *
        localDW->MathFunction_p[0];
      localDW->Elementproduct_g[2] = rtu_sc2sun_eci_unit[0] *
        localDW->MathFunction_p[1];
      localDW->Elementproduct_g[3] = rtu_sc2sun_eci_unit[2] *
        localDW->MathFunction_p[1];
      localDW->Elementproduct_g[4] = rtu_sc2sun_eci_unit[0] *
        localDW->MathFunction_p[2];
      localDW->Elementproduct_g[5] = rtu_sc2sun_eci_unit[1] *
        localDW->MathFunction_p[0];

      /* Sum: '<S186>/Add3' */
      localDW->MathFunction_p[0] = localDW->Elementproduct_g[0] -
        localDW->Elementproduct_g[3];
      localDW->MathFunction_p[1] = localDW->Elementproduct_g[1] -
        localDW->Elementproduct_g[4];
      localDW->MathFunction_p[2] = localDW->Elementproduct_g[2] -
        localDW->Elementproduct_g[5];

      /* S-Function (sdsp2norm2): '<S177>/Normalization7' */
      localDW->Product3_j = 1.0 / (sqrt((localDW->MathFunction_p[0] *
        localDW->MathFunction_p[0] + localDW->MathFunction_p[1] *
        localDW->MathFunction_p[1]) + localDW->MathFunction_p[2] *
        localDW->MathFunction_p[2]) + localP->Normalization7_Bias);
      localDW->MathFunction_p[0] *= localDW->Product3_j;
      localDW->MathFunction_p[1] *= localDW->Product3_j;
      localDW->MathFunction_p[2] *= localDW->Product3_j;

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate3In2' */
      localDW->MatrixConcatenate3[3] = localDW->MathFunction_p[0];
      localDW->MatrixConcatenate3[4] = localDW->MathFunction_p[1];
      localDW->MatrixConcatenate3[5] = localDW->MathFunction_p[2];

      /* Product: '<S187>/Element product' */
      localDW->MathFunction1_k[0] = rtu_sc2sun_eci_unit[1] *
        localDW->MathFunction_p[2];
      localDW->MathFunction1_k[1] = rtu_sc2sun_eci_unit[2] *
        localDW->MathFunction_p[0];
      localDW->MathFunction1_k[2] = rtu_sc2sun_eci_unit[0] *
        localDW->MathFunction_p[1];
      localDW->MathFunction1_k[3] = rtu_sc2sun_eci_unit[2] *
        localDW->MathFunction_p[1];
      localDW->MathFunction1_k[4] = rtu_sc2sun_eci_unit[0] *
        localDW->MathFunction_p[2];
      localDW->MathFunction1_k[5] = rtu_sc2sun_eci_unit[1] *
        localDW->MathFunction_p[0];

      /* Sum: '<S187>/Add3' */
      localDW->MatrixConcatenate3[6] = localDW->MathFunction1_k[0] -
        localDW->MathFunction1_k[3];
      localDW->MatrixConcatenate3[7] = localDW->MathFunction1_k[1] -
        localDW->MathFunction1_k[4];
      localDW->MatrixConcatenate3[8] = localDW->MathFunction1_k[2] -
        localDW->MathFunction1_k[5];

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate2In1' */
      localDW->MathFunction1_k[0] = rtu_sun_meas_body_unit[0];
      localDW->MathFunction1_k[1] = rtu_sun_meas_body_unit[1];
      localDW->MathFunction1_k[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S177>/ConcatBufferAtMatrix Concatenate2In2' */
      localDW->MathFunction1_k[3] = localDW->MathFunction_j[0];
      localDW->MathFunction1_k[4] = localDW->MathFunction_j[1];
      localDW->MathFunction1_k[5] = localDW->MathFunction_j[2];

      /* Product: '<S185>/Element product' */
      localDW->Elementproduct_g[0] = rtu_sun_meas_body_unit[1] *
        localDW->MathFunction_j[2];
      localDW->Elementproduct_g[1] = rtu_sun_meas_body_unit[2] *
        localDW->MathFunction_j[0];
      localDW->Elementproduct_g[2] = rtu_sun_meas_body_unit[0] *
        localDW->MathFunction_j[1];
      localDW->Elementproduct_g[3] = rtu_sun_meas_body_unit[2] *
        localDW->MathFunction_j[1];
      localDW->Elementproduct_g[4] = rtu_sun_meas_body_unit[0] *
        localDW->MathFunction_j[2];
      localDW->Elementproduct_g[5] = rtu_sun_meas_body_unit[1] *
        localDW->MathFunction_j[0];

      /* Sum: '<S185>/Add3' */
      localDW->MathFunction1_k[6] = localDW->Elementproduct_g[0] -
        localDW->Elementproduct_g[3];
      localDW->MathFunction1_k[7] = localDW->Elementproduct_g[1] -
        localDW->Elementproduct_g[4];
      localDW->MathFunction1_k[8] = localDW->Elementproduct_g[2] -
        localDW->Elementproduct_g[5];

      /* Product: '<S177>/Matrix Multiply1' incorporates:
       *  Math: '<S177>/Math Function1'
       */
      for (localDW->i = 0; localDW->i < 3; localDW->i++) {
        for (localDW->idxStart = 0; localDW->idxStart < 3; localDW->idxStart++)
        {
          localDW->rtb_MatrixMultiply1_tmp = localDW->i + 3 * localDW->idxStart;
          localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp] = 0.0;
          localDW->rtb_MatrixMultiply1_tmp_g = 3 * localDW->idxStart +
            localDW->i;
          localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp] =
            localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp_g] +
            localDW->MathFunction1_k[localDW->i] * localDW->
            MatrixConcatenate3[localDW->idxStart];
          localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp] =
            localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp_g] +
            localDW->MathFunction1_k[localDW->i + 3] *
            localDW->MatrixConcatenate3[localDW->idxStart + 3];
          localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp] =
            localDW->MatrixMultiply1[localDW->rtb_MatrixMultiply1_tmp_g] +
            localDW->MathFunction1_k[localDW->i + 6] *
            localDW->MatrixConcatenate3[localDW->idxStart + 6];
        }
      }

      /* End of Product: '<S177>/Matrix Multiply1' */

      /* If: '<S191>/If1' incorporates:
       *  Constant: '<S191>/Constant'
       */
      if (localP->DirectionCosineMatrixtoQuaterni != 1.0) {
        /* Outputs for IfAction SubSystem: '<S191>/If Warning//Error' incorporates:
         *  ActionPort: '<S215>/if'
         */
        IfWarningError(localDW->MatrixMultiply1, &localDW->IfWarningError_o,
                       &localP->IfWarningError_o,
                       localP->DirectionCosineMatrixtoQuaterni,
                       localP->DirectionCosineMatrixtoQuater_o);

        /* End of Outputs for SubSystem: '<S191>/If Warning//Error' */
      }

      /* End of If: '<S191>/If1' */

      /* Sum: '<S192>/Add' */
      localDW->Add_h = (localDW->MatrixMultiply1[0] + localDW->MatrixMultiply1[4])
        + localDW->MatrixMultiply1[8];

      /* If: '<S188>/If' */
      if (localDW->Add_h > 0.0) {
        /* Outputs for IfAction SubSystem: '<S188>/Positive Trace' incorporates:
         *  ActionPort: '<S190>/Action Port'
         */
        PositiveTrace(localDW->Add_h, localDW->MatrixMultiply1, &localDW->Merge
                      [0], &localDW->Merge[1], &localP->PositiveTrace_a);

        /* End of Outputs for SubSystem: '<S188>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S188>/Negative Trace' incorporates:
         *  ActionPort: '<S189>/Action Port'
         */
        NegativeTrace(localDW->MatrixMultiply1, localDW->Merge,
                      &localP->NegativeTrace_g);

        /* End of Outputs for SubSystem: '<S188>/Negative Trace' */
      }

      /* End of If: '<S188>/If' */

      /* Signum: '<S177>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        localDW->Product3_j = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        localDW->Product3_j = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        localDW->Product3_j = 0.0;
      } else {
        localDW->Product3_j = (rtNaN);
      }

      /* End of Signum: '<S177>/Sign' */

      /* Product: '<S177>/Multiply' */
      localDW->Merge_i[0] = localDW->Product3_j * localDW->Merge[0];
      localDW->Merge_i[1] = localDW->Product3_j * localDW->Merge[1];
      localDW->Merge_i[2] = localDW->Product3_j * localDW->Merge[2];
      localDW->Merge_i[3] = localDW->Product3_j * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S125>/TriadAlgorithm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S125>/TriadBypass' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      localDW->Merge_i[0] = localDW->UnitDelay_DSTATE_g[0];
      localDW->Merge_i[1] = localDW->UnitDelay_DSTATE_g[1];
      localDW->Merge_i[2] = localDW->UnitDelay_DSTATE_g[2];
      localDW->Merge_i[3] = localDW->UnitDelay_DSTATE_g[3];

      /* End of Outputs for SubSystem: '<S125>/TriadBypass' */
    }

    /* End of If: '<S125>/If' */

    /* Sqrt: '<S182>/sqrt' incorporates:
     *  Product: '<S183>/Product'
     *  Product: '<S183>/Product1'
     *  Product: '<S183>/Product2'
     *  Product: '<S183>/Product3'
     *  Sum: '<S183>/Sum'
     */
    localDW->Product3_j = sqrt(((localDW->Merge_i[0] * localDW->Merge_i[0] +
      localDW->Merge_i[1] * localDW->Merge_i[1]) + localDW->Merge_i[2] *
      localDW->Merge_i[2]) + localDW->Merge_i[3] * localDW->Merge_i[3]);

    /* SignalConversion: '<S125>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
     *  Product: '<S176>/Product'
     *  Product: '<S176>/Product1'
     *  Product: '<S176>/Product2'
     *  Product: '<S176>/Product3'
     *  Sqrt: '<S182>/sqrt'
     */
    localDW->TmpSignalConversionAtquat_e[0] = localDW->Merge_i[0] /
      localDW->Product3_j;
    localDW->TmpSignalConversionAtquat_e[1] = localDW->Merge_i[1] /
      localDW->Product3_j;
    localDW->TmpSignalConversionAtquat_e[2] = localDW->Merge_i[2] /
      localDW->Product3_j;
    localDW->TmpSignalConversionAtquat_e[3] = localDW->Merge_i[3] /
      localDW->Product3_j;

    /* Outputs for Atomic SubSystem: '<S125>/quat_rectify_lib' */
    quat_rectify_lib(localDW->TmpSignalConversionAtquat_e, localDW->Merge_i,
                     &localP->quat_rectify_lib_m);

    /* End of Outputs for SubSystem: '<S125>/quat_rectify_lib' */
    /* End of Outputs for SubSystem: '<S3>/TriadEstimator_lib' */
  } else {
    localDW->TRIAD_activation_ActiveSubsyste = 1;

    /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    localDW->Merge_i[0] = localDW->UnitDelay3_DSTATE[0];
    localDW->Merge_i[1] = localDW->UnitDelay3_DSTATE[1];
    localDW->Merge_i[2] = localDW->UnitDelay3_DSTATE[2];
    localDW->Merge_i[3] = localDW->UnitDelay3_DSTATE[3];

    /* End of Outputs for SubSystem: '<S116>/If Action Subsystem' */
  }

  /* End of If: '<S3>/TRIAD_activation' */

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S114>/P_chol_m'
   *  Inport: '<S114>/bias_m'
   *  Inport: '<S114>/q_m'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_Sum_fj > 1) {
    /* Outputs for IfAction SubSystem: '<S3>/MeasurementUpdate' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Sqrt: '<S148>/sqrt' incorporates:
     *  Product: '<S149>/Product'
     *  Product: '<S149>/Product1'
     *  Product: '<S149>/Product2'
     *  Product: '<S149>/Product3'
     *  Sum: '<S149>/Sum'
     */
    localDW->rtb_Product5_b_b = sqrt(((localDW->Merge_i[0] * localDW->Merge_i[0]
      + localDW->Merge_i[1] * localDW->Merge_i[1]) + localDW->Merge_i[2] *
      localDW->Merge_i[2]) + localDW->Merge_i[3] * localDW->Merge_i[3]);

    /* Product: '<S144>/Product2' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    localDW->Product3_pe = localDW->Merge_i[2] / localDW->rtb_Product5_b_b;

    /* Product: '<S144>/Product3' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    localDW->Product1_k = localDW->Merge_i[3] / localDW->rtb_Product5_b_b;

    /* Product: '<S145>/Product7' incorporates:
     *  Product: '<S146>/Product7'
     */
    localDW->Product1_f = localDW->Product1_k * localDW->Product1_k;

    /* Product: '<S145>/Product6' incorporates:
     *  Product: '<S147>/Product7'
     */
    localDW->Product2_da = localDW->Product3_pe * localDW->Product3_pe;

    /* Product: '<S145>/Product8' incorporates:
     *  Constant: '<S145>/Constant'
     *  Gain: '<S145>/Gain2'
     *  Product: '<S145>/Product6'
     *  Product: '<S145>/Product7'
     *  Sum: '<S145>/Sum3'
     */
    localDW->Product8 = ((localP->Constant_Value_c - localDW->Product2_da) -
                         localDW->Product1_f) * localP->Gain2_Gain *
      rtu_sc2sun_eci_unit[0];

    /* Product: '<S144>/Product1' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    localDW->Product2_at = localDW->Merge_i[1] / localDW->rtb_Product5_b_b;

    /* Product: '<S144>/Product' incorporates:
     *  Sqrt: '<S148>/sqrt'
     */
    localDW->rtb_Product5_b_b = localDW->Merge_i[0] / localDW->rtb_Product5_b_b;

    /* Product: '<S145>/Product' incorporates:
     *  Product: '<S146>/Product'
     */
    localDW->rtb_Product1_kn_tmp = localDW->Product2_at * localDW->Product3_pe;

    /* Product: '<S145>/Product1' incorporates:
     *  Product: '<S146>/Product1'
     */
    localDW->Add_h = localDW->rtb_Product5_b_b * localDW->Product1_k;

    /* Product: '<S145>/Product4' incorporates:
     *  Gain: '<S145>/Gain'
     *  Product: '<S145>/Product'
     *  Product: '<S145>/Product1'
     *  Sum: '<S145>/Sum1'
     */
    localDW->Product1_kn = (localDW->rtb_Product1_kn_tmp + localDW->Add_h) *
      localP->Gain_Gain * rtu_sc2sun_eci_unit[1];

    /* Product: '<S145>/Product3' incorporates:
     *  Product: '<S147>/Product'
     */
    localDW->rtb_sqrt_m_tmp = localDW->Product2_at * localDW->Product1_k;

    /* Product: '<S145>/Product2' incorporates:
     *  Product: '<S147>/Product1'
     */
    localDW->rtb_sqrt_m_tmp_p = localDW->rtb_Product5_b_b * localDW->Product3_pe;

    /* Product: '<S145>/Product5' incorporates:
     *  Gain: '<S145>/Gain1'
     *  Product: '<S145>/Product2'
     *  Product: '<S145>/Product3'
     *  Sum: '<S145>/Sum2'
     */
    localDW->sqrt_m = (localDW->rtb_sqrt_m_tmp - localDW->rtb_sqrt_m_tmp_p) *
      localP->Gain1_Gain * rtu_sc2sun_eci_unit[2];

    /* Sum: '<S145>/Sum' */
    localDW->Product3_j = (localDW->Product8 + localDW->Product1_kn) +
      localDW->sqrt_m;

    /* Product: '<S146>/Product4' incorporates:
     *  Gain: '<S146>/Gain'
     *  Sum: '<S146>/Sum1'
     */
    localDW->sqrt_m = (localDW->rtb_Product1_kn_tmp - localDW->Add_h) *
      localP->Gain_Gain_b * rtu_sc2sun_eci_unit[0];

    /* Product: '<S146>/Product6' incorporates:
     *  Product: '<S147>/Product6'
     */
    localDW->rtb_Product1_kn_tmp = localDW->Product2_at * localDW->Product2_at;

    /* Product: '<S146>/Product8' incorporates:
     *  Constant: '<S146>/Constant'
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Product6'
     *  Sum: '<S146>/Sum3'
     */
    localDW->Product1_kn = ((localP->Constant_Value_b -
      localDW->rtb_Product1_kn_tmp) - localDW->Product1_f) *
      localP->Gain2_Gain_h * rtu_sc2sun_eci_unit[1];

    /* Product: '<S146>/Product3' incorporates:
     *  Product: '<S147>/Product3'
     */
    localDW->Product1_f = localDW->Product3_pe * localDW->Product1_k;

    /* Product: '<S146>/Product2' incorporates:
     *  Product: '<S147>/Product2'
     */
    localDW->Product2_at *= localDW->rtb_Product5_b_b;

    /* Product: '<S146>/Product5' incorporates:
     *  Gain: '<S146>/Gain1'
     *  Product: '<S146>/Product2'
     *  Product: '<S146>/Product3'
     *  Sum: '<S146>/Sum2'
     */
    localDW->Product8 = (localDW->Product2_at + localDW->Product1_f) *
      localP->Gain1_Gain_b * rtu_sc2sun_eci_unit[2];

    /* Sum: '<S146>/Sum' */
    localDW->Add_h = (localDW->sqrt_m + localDW->Product1_kn) +
      localDW->Product8;

    /* Product: '<S147>/Product4' incorporates:
     *  Gain: '<S147>/Gain'
     *  Sum: '<S147>/Sum1'
     */
    localDW->sqrt_m = (localDW->rtb_sqrt_m_tmp + localDW->rtb_sqrt_m_tmp_p) *
      localP->Gain_Gain_n * rtu_sc2sun_eci_unit[0];

    /* Product: '<S147>/Product5' incorporates:
     *  Gain: '<S147>/Gain1'
     *  Sum: '<S147>/Sum2'
     */
    localDW->Product1_kn = (localDW->Product1_f - localDW->Product2_at) *
      localP->Gain1_Gain_j * rtu_sc2sun_eci_unit[1];

    /* Product: '<S147>/Product8' incorporates:
     *  Constant: '<S147>/Constant'
     *  Gain: '<S147>/Gain2'
     *  Sum: '<S147>/Sum3'
     */
    localDW->Product2_at = ((localP->Constant_Value_h -
      localDW->rtb_Product1_kn_tmp) - localDW->Product2_da) *
      localP->Gain2_Gain_b * rtu_sc2sun_eci_unit[2];

    /* Sum: '<S147>/Sum' */
    localDW->Product1_f = (localDW->sqrt_m + localDW->Product1_kn) +
      localDW->Product2_at;

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(localDW->Product1_f, localDW->Product3_j, localDW->Add_h,
                        localDW->MatrixConcatenate3,
                        &localP->CrossProdMatrix_lib_ma);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib' */

    /* Sqrt: '<S154>/sqrt' incorporates:
     *  Product: '<S155>/Product'
     *  Product: '<S155>/Product1'
     *  Product: '<S155>/Product2'
     *  Product: '<S155>/Product3'
     *  Sum: '<S155>/Sum'
     */
    localDW->sqrt_m = sqrt(((localDW->Merge_i[0] * localDW->Merge_i[0] +
      localDW->Merge_i[1] * localDW->Merge_i[1]) + localDW->Merge_i[2] *
      localDW->Merge_i[2]) + localDW->Merge_i[3] * localDW->Merge_i[3]);

    /* Product: '<S150>/Product2' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    localDW->Product1_kn = localDW->Merge_i[2] / localDW->sqrt_m;

    /* Product: '<S150>/Product3' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    localDW->Product2_at = localDW->Merge_i[3] / localDW->sqrt_m;

    /* Product: '<S151>/Product8' incorporates:
     *  Constant: '<S151>/Constant'
     *  Gain: '<S151>/Gain2'
     *  Product: '<S151>/Product6'
     *  Product: '<S151>/Product7'
     *  Sum: '<S151>/Sum3'
     */
    localDW->Product3_pe = ((localP->Constant_Value_bh - localDW->Product1_kn *
      localDW->Product1_kn) - localDW->Product2_at * localDW->Product2_at) *
      localP->Gain2_Gain_c * rtu_mag_eci_T[0];

    /* Product: '<S150>/Product1' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    localDW->Product1_k = localDW->Merge_i[1] / localDW->sqrt_m;

    /* Product: '<S150>/Product' incorporates:
     *  Sqrt: '<S154>/sqrt'
     */
    localDW->sqrt_m = localDW->Merge_i[0] / localDW->sqrt_m;

    /* Product: '<S151>/Product4' incorporates:
     *  Gain: '<S151>/Gain'
     *  Product: '<S151>/Product'
     *  Product: '<S151>/Product1'
     *  Sum: '<S151>/Sum1'
     */
    localDW->Product8 = (localDW->Product1_k * localDW->Product1_kn +
                         localDW->sqrt_m * localDW->Product2_at) *
      localP->Gain_Gain_m * rtu_mag_eci_T[1];

    /* Product: '<S151>/Product5' incorporates:
     *  Gain: '<S151>/Gain1'
     *  Product: '<S151>/Product2'
     *  Product: '<S151>/Product3'
     *  Sum: '<S151>/Sum2'
     */
    localDW->rtb_Product5_b_b = (localDW->Product1_k * localDW->Product2_at -
      localDW->sqrt_m * localDW->Product1_kn) * localP->Gain1_Gain_bj *
      rtu_mag_eci_T[2];

    /* Sum: '<S151>/Sum' */
    localDW->Product2_da = (localDW->Product3_pe + localDW->Product8) +
      localDW->rtb_Product5_b_b;

    /* Product: '<S152>/Product4' incorporates:
     *  Gain: '<S152>/Gain'
     *  Product: '<S152>/Product'
     *  Product: '<S152>/Product1'
     *  Sum: '<S152>/Sum1'
     */
    localDW->Product3_pe = (localDW->Product1_k * localDW->Product1_kn -
      localDW->sqrt_m * localDW->Product2_at) * localP->Gain_Gain_e *
      rtu_mag_eci_T[0];

    /* Product: '<S152>/Product8' incorporates:
     *  Constant: '<S152>/Constant'
     *  Gain: '<S152>/Gain2'
     *  Product: '<S152>/Product6'
     *  Product: '<S152>/Product7'
     *  Sum: '<S152>/Sum3'
     */
    localDW->Product8 = ((localP->Constant_Value_cg - localDW->Product1_k *
                          localDW->Product1_k) - localDW->Product2_at *
                         localDW->Product2_at) * localP->Gain2_Gain_l *
      rtu_mag_eci_T[1];

    /* Product: '<S152>/Product5' incorporates:
     *  Gain: '<S152>/Gain1'
     *  Product: '<S152>/Product2'
     *  Product: '<S152>/Product3'
     *  Sum: '<S152>/Sum2'
     */
    localDW->rtb_Product5_b_b = (localDW->sqrt_m * localDW->Product1_k +
      localDW->Product1_kn * localDW->Product2_at) * localP->Gain1_Gain_o *
      rtu_mag_eci_T[2];

    /* Sum: '<S152>/Sum' */
    localDW->rtb_Product5_b_b += localDW->Product3_pe + localDW->Product8;

    /* Product: '<S153>/Product4' incorporates:
     *  Gain: '<S153>/Gain'
     *  Product: '<S153>/Product'
     *  Product: '<S153>/Product1'
     *  Sum: '<S153>/Sum1'
     */
    localDW->Product3_pe = (localDW->Product1_k * localDW->Product2_at +
      localDW->sqrt_m * localDW->Product1_kn) * localP->Gain_Gain_f *
      rtu_mag_eci_T[0];

    /* Product: '<S153>/Product5' incorporates:
     *  Gain: '<S153>/Gain1'
     *  Product: '<S153>/Product2'
     *  Product: '<S153>/Product3'
     *  Sum: '<S153>/Sum2'
     */
    localDW->sqrt_m = (localDW->Product1_kn * localDW->Product2_at -
                       localDW->sqrt_m * localDW->Product1_k) *
      localP->Gain1_Gain_oh * rtu_mag_eci_T[1];

    /* Product: '<S153>/Product8' incorporates:
     *  Constant: '<S153>/Constant'
     *  Gain: '<S153>/Gain2'
     *  Product: '<S153>/Product6'
     *  Product: '<S153>/Product7'
     *  Sum: '<S153>/Sum3'
     */
    localDW->Product1_kn = ((localP->Constant_Value_m - localDW->Product1_k *
      localDW->Product1_k) - localDW->Product1_kn * localDW->Product1_kn) *
      localP->Gain2_Gain_e * rtu_mag_eci_T[2];

    /* Sum: '<S153>/Sum' */
    localDW->Product3_pe = (localDW->Product3_pe + localDW->sqrt_m) +
      localDW->Product1_kn;

    /* Outputs for Atomic SubSystem: '<S132>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(localDW->Product3_pe, localDW->Product2_da,
                        localDW->rtb_Product5_b_b, localDW->MathFunction1_k,
                        &localP->CrossProdMatrix_lib1_j);

    /* End of Outputs for SubSystem: '<S132>/CrossProdMatrix_lib1' */
    for (localDW->i = 0; localDW->i < 3; localDW->i++) {
      /* Concatenate: '<S132>/Horizontal Matrix Concatenate' */
      localDW->P_chol_p_merge[6 * localDW->i] = localDW->MatrixConcatenate3[3 *
        localDW->i];
      localDW->P_chol_p_merge[3 + 6 * localDW->i] = localDW->MathFunction1_k[3 *
        localDW->i];

      /* Concatenate: '<S132>/Horizontal Matrix Concatenate1' incorporates:
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       */
      localDW->P_chol_p_merge[6 * localDW->i + 18] = localP->Constant2_Value[3 *
        localDW->i];
      localDW->P_chol_p_merge[6 * localDW->i + 21] = localP->Constant1_Value[3 *
        localDW->i];

      /* Concatenate: '<S132>/Horizontal Matrix Concatenate' incorporates:
       *  Concatenate: '<S132>/Horizontal Matrix Concatenate1'
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       */
      localDW->rtb_MatrixMultiply1_tmp_g = 3 * localDW->i + 1;
      localDW->P_chol_p_merge[1 + 6 * localDW->i] = localDW->
        MatrixConcatenate3[localDW->rtb_MatrixMultiply1_tmp_g];
      localDW->P_chol_p_merge[4 + 6 * localDW->i] = localDW->
        MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g];

      /* Concatenate: '<S132>/Horizontal Matrix Concatenate1' incorporates:
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       */
      localDW->P_chol_p_merge[6 * localDW->i + 19] = localP->
        Constant2_Value[localDW->rtb_MatrixMultiply1_tmp_g];
      localDW->P_chol_p_merge[6 * localDW->i + 22] = localP->
        Constant1_Value[localDW->rtb_MatrixMultiply1_tmp_g];

      /* Concatenate: '<S132>/Horizontal Matrix Concatenate' incorporates:
       *  Concatenate: '<S132>/Horizontal Matrix Concatenate1'
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       */
      localDW->rtb_MatrixMultiply1_tmp_g = 3 * localDW->i + 2;
      localDW->P_chol_p_merge[2 + 6 * localDW->i] = localDW->
        MatrixConcatenate3[localDW->rtb_MatrixMultiply1_tmp_g];
      localDW->P_chol_p_merge[5 + 6 * localDW->i] = localDW->
        MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g];

      /* Concatenate: '<S132>/Horizontal Matrix Concatenate1' incorporates:
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       */
      localDW->P_chol_p_merge[6 * localDW->i + 20] = localP->
        Constant2_Value[localDW->rtb_MatrixMultiply1_tmp_g];
      localDW->P_chol_p_merge[6 * localDW->i + 23] = localP->
        Constant1_Value[localDW->rtb_MatrixMultiply1_tmp_g];
    }

    /* MATLAB Function: '<S119>/QR_factorization' incorporates:
     *  Constant: '<S119>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
        localDW->rtb_MatrixMultiply1_tmp = localDW->i + 6 * localDW->idxStart;
        localDW->Phi[localDW->rtb_MatrixMultiply1_tmp] = 0.0;
        for (localDW->rtb_MatrixMultiply1_tmp_g = 0;
             localDW->rtb_MatrixMultiply1_tmp_g < 6;
             localDW->rtb_MatrixMultiply1_tmp_g++) {
          localDW->Phi[localDW->rtb_MatrixMultiply1_tmp] =
            localDW->UnitDelay_DSTATE[6 * localDW->i +
            localDW->rtb_MatrixMultiply1_tmp_g] * localDW->P_chol_p_merge[6 *
            localDW->rtb_MatrixMultiply1_tmp_g + localDW->idxStart] +
            localDW->Phi[6 * localDW->idxStart + localDW->i];
        }

        localDW->dv0[localDW->idxStart + 12 * localDW->i] =
          rtP.fswParams.estimation.Rchol[6 * localDW->idxStart + localDW->i];
        localDW->dv0[localDW->idxStart + 12 * (localDW->i + 6)] = 0.0;
      }
    }

    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
        localDW->dv0[(localDW->idxStart + 12 * localDW->i) + 6] = localDW->Phi[6
          * localDW->i + localDW->idxStart];
        localDW->dv0[(localDW->idxStart + 12 * (localDW->i + 6)) + 6] =
          localDW->UnitDelay_DSTATE[6 * localDW->idxStart + localDW->i];
      }
    }

    qr_c0VdrKOo_k(localDW->dv0, localDW->unusedU2, localDW->R, localDW);
    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
        localDW->rtb_MatrixMultiply1_tmp = localDW->idxStart + 6 * localDW->i;
        localDW->Phi[localDW->rtb_MatrixMultiply1_tmp] = localDW->R[(6 +
          localDW->idxStart) * 12 + localDW->i];
        localDW->P_chol_p_merge[localDW->rtb_MatrixMultiply1_tmp] = localDW->R
          [12 * localDW->idxStart + localDW->i];
      }
    }

    mrdivide_helper_23K2DU9e_j(localDW->Phi, localDW->P_chol_p_merge, localDW);
    if (!rtu_gryo_meas_valid) {
      for (localDW->i = 0; localDW->i < 6; localDW->i++) {
        localDW->Phi[3 + 6 * localDW->i] = 0.0;
        localDW->Phi[4 + 6 * localDW->i] = 0.0;
        localDW->Phi[5 + 6 * localDW->i] = 0.0;
      }
    }

    /* SignalConversion: '<S119>/OutportBufferForP_chol_plus' incorporates:
     *  MATLAB Function: '<S119>/QR_factorization'
     */
    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
        localDW->P_chol_p_merge[localDW->idxStart + 6 * localDW->i] = localDW->
          R[((6 + localDW->idxStart) * 12 + localDW->i) + 6];
      }
    }

    /* Gain: '<S137>/Gain' */
    localDW->VectorConcatenate_d[0] = localP->Gain_Gain_c * localDW->Merge_i[1];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn2' */
    localDW->VectorConcatenate_d[1] = localDW->Merge_i[0];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn3' */
    localDW->VectorConcatenate_d[2] = localDW->Merge_i[3];

    /* Gain: '<S137>/Gain1' */
    localDW->VectorConcatenate_d[3] = localP->Gain1_Gain_k * localDW->Merge_i[2];

    /* Gain: '<S137>/Gain2' */
    localDW->VectorConcatenate_d[4] = localP->Gain2_Gain_ld * localDW->Merge_i[2];

    /* Gain: '<S137>/Gain3' */
    localDW->VectorConcatenate_d[5] = localP->Gain3_Gain * localDW->Merge_i[3];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn7' */
    localDW->VectorConcatenate_d[6] = localDW->Merge_i[0];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn8' */
    localDW->VectorConcatenate_d[7] = localDW->Merge_i[1];

    /* Gain: '<S137>/Gain4' */
    localDW->VectorConcatenate_d[8] = localP->Gain4_Gain * localDW->Merge_i[3];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn10' */
    localDW->VectorConcatenate_d[9] = localDW->Merge_i[2];

    /* Gain: '<S137>/Gain5' */
    localDW->VectorConcatenate_d[10] = localP->Gain5_Gain * localDW->Merge_i[1];

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn12' */
    localDW->VectorConcatenate_d[11] = localDW->Merge_i[0];

    /* Sum: '<S119>/CreateMeasResidual' */
    localDW->Elementproduct_g[0] = rtu_sun_meas_body_unit[0] -
      localDW->Product3_j;
    localDW->Elementproduct_g[1] = rtu_sun_meas_body_unit[1] - localDW->Add_h;
    localDW->Elementproduct_g[2] = rtu_sun_meas_body_unit[2] -
      localDW->Product1_f;
    localDW->Elementproduct_g[3] = rtu_mag_meas_body_T[0] - localDW->Product2_da;
    localDW->Elementproduct_g[4] = rtu_mag_meas_body_T[1] -
      localDW->rtb_Product5_b_b;
    localDW->Elementproduct_g[5] = rtu_mag_meas_body_T[2] - localDW->Product3_pe;

    /* Product: '<S119>/Product1' incorporates:
     *  MATLAB Function: '<S119>/QR_factorization'
     */
    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      localDW->MathFunction1_k[localDW->i] = 0.0;
      for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
        localDW->MathFunction1_k[localDW->i] += localDW->Phi[6 *
          localDW->idxStart + localDW->i] * localDW->Elementproduct_g
          [localDW->idxStart];
      }
    }

    /* End of Product: '<S119>/Product1' */

    /* Sum: '<S119>/Sum' incorporates:
     *  Gain: '<S137>/Gain6'
     *  Product: '<S119>/Product'
     */
    for (localDW->i = 0; localDW->i < 4; localDW->i++) {
      localDW->TmpSignalConversionAtquat_e[localDW->i] =
        ((localDW->VectorConcatenate_d[localDW->i + 4] * localP->Gain6_Gain *
          localDW->MathFunction1_k[1] + localP->Gain6_Gain *
          localDW->VectorConcatenate_d[localDW->i] * localDW->MathFunction1_k[0])
         + localDW->VectorConcatenate_d[localDW->i + 8] * localP->Gain6_Gain *
         localDW->MathFunction1_k[2]) + localDW->Merge_i[localDW->i];
    }

    /* End of Sum: '<S119>/Sum' */

    /* Sqrt: '<S142>/sqrt' incorporates:
     *  Product: '<S143>/Product'
     *  Product: '<S143>/Product1'
     *  Product: '<S143>/Product2'
     *  Product: '<S143>/Product3'
     *  Sum: '<S143>/Sum'
     */
    localDW->sqrt_m = sqrt(((localDW->TmpSignalConversionAtquat_e[0] *
      localDW->TmpSignalConversionAtquat_e[0] +
      localDW->TmpSignalConversionAtquat_e[1] *
      localDW->TmpSignalConversionAtquat_e[1]) +
      localDW->TmpSignalConversionAtquat_e[2] *
      localDW->TmpSignalConversionAtquat_e[2]) +
      localDW->TmpSignalConversionAtquat_e[3] *
      localDW->TmpSignalConversionAtquat_e[3]);

    /* Product: '<S134>/Product' */
    rty_sc_quat[0] = localDW->TmpSignalConversionAtquat_e[0] / localDW->sqrt_m;

    /* Product: '<S134>/Product1' */
    rty_sc_quat[1] = localDW->TmpSignalConversionAtquat_e[1] / localDW->sqrt_m;

    /* Product: '<S134>/Product2' */
    rty_sc_quat[2] = localDW->TmpSignalConversionAtquat_e[2] / localDW->sqrt_m;

    /* Product: '<S134>/Product3' */
    rty_sc_quat[3] = localDW->TmpSignalConversionAtquat_e[3] / localDW->sqrt_m;

    /* Saturate: '<S119>/Saturation' incorporates:
     *  Sum: '<S119>/UpdatingBetaBias '
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    localDW->Product3_j = localDW->MathFunction1_k[3] +
      localDW->UnitDelay1_DSTATE[0];
    if (localDW->Product3_j > rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[0] = rtP.fswParams.estimation.bias_max;
    } else if (localDW->Product3_j < -rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[0] = -rtP.fswParams.estimation.bias_max;
    } else {
      rty_bias_radps[0] = localDW->Product3_j;
    }

    localDW->Product3_j = localDW->MathFunction1_k[4] +
      localDW->UnitDelay1_DSTATE[1];
    if (localDW->Product3_j > rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[1] = rtP.fswParams.estimation.bias_max;
    } else if (localDW->Product3_j < -rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[1] = -rtP.fswParams.estimation.bias_max;
    } else {
      rty_bias_radps[1] = localDW->Product3_j;
    }

    localDW->Product3_j = localDW->MathFunction1_k[5] +
      localDW->UnitDelay1_DSTATE[2];
    if (localDW->Product3_j > rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[2] = rtP.fswParams.estimation.bias_max;
    } else if (localDW->Product3_j < -rtP.fswParams.estimation.bias_max) {
      rty_bias_radps[2] = -rtP.fswParams.estimation.bias_max;
    } else {
      rty_bias_radps[2] = localDW->Product3_j;
    }

    /* End of Saturate: '<S119>/Saturation' */
    /* End of Outputs for SubSystem: '<S3>/MeasurementUpdate' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/BypassMeasUpdate' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    memcpy(&localDW->P_chol_p_merge[0], &localDW->UnitDelay_DSTATE[0], 36U *
           sizeof(real_T));
    rty_bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_bias_radps[2] = localDW->UnitDelay1_DSTATE[2];
    rty_sc_quat[0] = localDW->Merge_i[0];
    rty_sc_quat[1] = localDW->Merge_i[1];
    rty_sc_quat[2] = localDW->Merge_i[2];
    rty_sc_quat[3] = localDW->Merge_i[3];

    /* End of Outputs for SubSystem: '<S3>/BypassMeasUpdate' */
  }

  /* End of If: '<S3>/If' */

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   */
  rtb_Compare_e = ((rtb_Sum_fj == localP->CompareToConstant_const_b) > (int32_T)
                   localP->Constant_Value_d);

  /* RelationalOperator: '<S157>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Switch_hl = ((int32_T)rtb_Compare_e > (int32_T)localDW->DelayInput1_DSTATE);

  /* Switch: '<S3>/NullRatesIfGyroInvalid ' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (rtu_gryo_meas_valid) {
    localDW->MathFunction_j[0] = rtu_gyro_meas_body_radps[0];
    localDW->MathFunction_j[1] = rtu_gyro_meas_body_radps[1];
    localDW->MathFunction_j[2] = rtu_gyro_meas_body_radps[2];
  } else {
    localDW->MathFunction_j[0] = localP->Constant_Value[0];
    localDW->MathFunction_j[1] = localP->Constant_Value[1];
    localDW->MathFunction_j[2] = localP->Constant_Value[2];
  }

  /* End of Switch: '<S3>/NullRatesIfGyroInvalid ' */

  /* Sum: '<S124>/Sum' */
  localDW->Product3_j = localDW->MathFunction_j[0] - rty_bias_radps[0];
  localDW->Add_h = localDW->MathFunction_j[1] - rty_bias_radps[1];
  localDW->Product1_kn = localDW->MathFunction_j[2] - rty_bias_radps[2];
  rty_body_rates_radps[0] = localDW->Product3_j;
  rty_body_rates_radps[1] = localDW->Add_h;
  rty_body_rates_radps[2] = localDW->Product1_kn;

  /* Math: '<S124>/Transpose' */
  localDW->MathFunction_j[0] = rty_body_rates_radps[0];
  localDW->MathFunction_j[1] = rty_body_rates_radps[1];
  localDW->MathFunction_j[2] = rty_body_rates_radps[2];

  /* Product: '<S124>/Matrix Multiply' */
  localDW->Product3_j = localDW->MathFunction_j[0] * rty_body_rates_radps[0];
  localDW->Product3_j += localDW->MathFunction_j[1] * rty_body_rates_radps[1];
  localDW->Product3_j += localDW->MathFunction_j[2] * rty_body_rates_radps[2];

  /* Sqrt: '<S124>/Sqrt' incorporates:
   *  Product: '<S124>/Matrix Multiply'
   */
  localDW->Product3_j = sqrt(localDW->Product3_j);

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_m(rty_body_rates_radps, localDW->MatrixConcatenate3,
                        &localP->CrossProdMatrix_lib1);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S124>/CreateStateTransitionMatrix' incorporates:
   *  Constant: '<S124>/Constant'
   */
  if (localDW->Product3_j < 1.0E-10) {
    for (localDW->i = 0; localDW->i < 9; localDW->i++) {
      localDW->b_I[localDW->i] = 0;
      localDW->Phi_22[localDW->i] = 0;
    }

    localDW->b_I[0] = 1;
    localDW->b_I[4] = 1;
    localDW->b_I[8] = 1;
    for (localDW->idxStart = 0; localDW->idxStart < 3; localDW->idxStart++) {
      localDW->Phi_22[localDW->idxStart + 3 * localDW->idxStart] = 1;
      localDW->Phi[6 * localDW->idxStart] = localDW->b_I[3 * localDW->idxStart];
      localDW->rtb_MatrixMultiply1_tmp = 6 * (localDW->idxStart + 3);
      localDW->Phi[localDW->rtb_MatrixMultiply1_tmp] = (real_T)a[3 *
        localDW->idxStart] * rtP.fswParams.estimation.dt;
      localDW->Phi[3 + 6 * localDW->idxStart] = 0.0;
      localDW->i = 3 * localDW->idxStart + 1;
      localDW->Phi[1 + 6 * localDW->idxStart] = localDW->b_I[localDW->i];
      localDW->Phi[1 + localDW->rtb_MatrixMultiply1_tmp] = (real_T)a[localDW->i]
        * rtP.fswParams.estimation.dt;
      localDW->Phi[4 + 6 * localDW->idxStart] = 0.0;
      localDW->i = 3 * localDW->idxStart + 2;
      localDW->Phi[2 + 6 * localDW->idxStart] = localDW->b_I[localDW->i];
      localDW->Phi[2 + localDW->rtb_MatrixMultiply1_tmp] = (real_T)a[localDW->i]
        * rtP.fswParams.estimation.dt;
      localDW->Phi[5 + 6 * localDW->idxStart] = 0.0;
    }

    for (localDW->i = 0; localDW->i < 3; localDW->i++) {
      localDW->rtb_MatrixMultiply1_tmp = 6 * (localDW->i + 3);
      localDW->Phi[3 + localDW->rtb_MatrixMultiply1_tmp] = localDW->Phi_22[3 *
        localDW->i];
      localDW->Phi[4 + localDW->rtb_MatrixMultiply1_tmp] = localDW->Phi_22[3 *
        localDW->i + 1];
      localDW->Phi[5 + localDW->rtb_MatrixMultiply1_tmp] = localDW->Phi_22[3 *
        localDW->i + 2];
    }
  } else {
    for (localDW->i = 0; localDW->i < 9; localDW->i++) {
      localDW->b_I[localDW->i] = 0;
      localDW->Phi_22[localDW->i] = 0;
    }

    localDW->b_I[0] = 1;
    localDW->b_I[4] = 1;
    localDW->b_I[8] = 1;
    localDW->Product1_kn = localDW->Product3_j * rtP.fswParams.estimation.dt;
    localDW->Product2_at = sin(localDW->Product1_kn);
    localDW->Add_h = localDW->Product2_at / localDW->Product3_j;
    localDW->Product8 = cos(localDW->Product1_kn);
    localDW->sqrt_m = localDW->Product3_j * localDW->Product3_j;
    localDW->Product2_at = localDW->Product1_kn - localDW->Product2_at;
    localDW->Product1_kn = rt_powd_snf(localDW->Product3_j, 3.0);
    for (localDW->idxStart = 0; localDW->idxStart < 3; localDW->idxStart++) {
      localDW->Phi_22[localDW->idxStart + 3 * localDW->idxStart] = 1;
      for (localDW->i = 0; localDW->i < 3; localDW->i++) {
        localDW->rtb_MatrixMultiply1_tmp_g = localDW->idxStart + 3 * localDW->i;
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] = 0.0;
        localDW->rtb_MatrixMultiply1_tmp = 3 * localDW->i + localDW->idxStart;
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] =
          localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp] +
          localDW->MatrixConcatenate3[3 * localDW->i] *
          localDW->MatrixConcatenate3[localDW->idxStart];
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] =
          localDW->MatrixConcatenate3[3 * localDW->i + 1] *
          localDW->MatrixConcatenate3[localDW->idxStart + 3] +
          localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp];
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] =
          localDW->MatrixConcatenate3[3 * localDW->i + 2] *
          localDW->MatrixConcatenate3[localDW->idxStart + 6] +
          localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp];
      }
    }

    for (localDW->i = 0; localDW->i < 3; localDW->i++) {
      localDW->rtb_Product5_b_b = localDW->MathFunction1_k[3 * localDW->i];
      localDW->Product3_pe = localDW->MatrixConcatenate3[3 * localDW->i];
      localDW->Phi[6 * localDW->i] = (1.0 - localDW->Product8) *
        localDW->rtb_Product5_b_b / localDW->sqrt_m + ((real_T)localDW->b_I[3 *
        localDW->i] - localDW->Product3_pe * localDW->Add_h);
      localDW->rtb_MatrixMultiply1_tmp = 6 * (localDW->i + 3);
      localDW->Phi[localDW->rtb_MatrixMultiply1_tmp] = ((1.0 - localDW->Product8)
        * localDW->Product3_pe / localDW->sqrt_m - (real_T)b_a[3 * localDW->i] *
        rtP.fswParams.estimation.dt) - localDW->rtb_Product5_b_b *
        localDW->Product2_at / localDW->Product1_kn;
      localDW->Phi[3 + 6 * localDW->i] = 0.0;
      localDW->Phi[3 + localDW->rtb_MatrixMultiply1_tmp] = localDW->Phi_22[3 *
        localDW->i];
      localDW->rtb_MatrixMultiply1_tmp_g = 3 * localDW->i + 1;
      localDW->Phi[1 + 6 * localDW->i] = ((real_T)localDW->b_I
        [localDW->rtb_MatrixMultiply1_tmp_g] - localDW->
        MatrixConcatenate3[localDW->rtb_MatrixMultiply1_tmp_g] * localDW->Add_h)
        + (1.0 - localDW->Product8) * localDW->MathFunction1_k
        [localDW->rtb_MatrixMultiply1_tmp_g] / localDW->sqrt_m;
      localDW->Phi[1 + localDW->rtb_MatrixMultiply1_tmp] = ((1.0 -
        localDW->Product8) * localDW->MatrixConcatenate3
        [localDW->rtb_MatrixMultiply1_tmp_g] / localDW->sqrt_m - (real_T)
        b_a[localDW->rtb_MatrixMultiply1_tmp_g] * rtP.fswParams.estimation.dt) -
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] *
        localDW->Product2_at / localDW->Product1_kn;
      localDW->Phi[4 + 6 * localDW->i] = 0.0;
      localDW->Phi[4 + localDW->rtb_MatrixMultiply1_tmp] = localDW->
        Phi_22[localDW->rtb_MatrixMultiply1_tmp_g];
      localDW->rtb_MatrixMultiply1_tmp_g = 3 * localDW->i + 2;
      localDW->Phi[2 + 6 * localDW->i] = ((real_T)localDW->b_I
        [localDW->rtb_MatrixMultiply1_tmp_g] - localDW->
        MatrixConcatenate3[localDW->rtb_MatrixMultiply1_tmp_g] * localDW->Add_h)
        + (1.0 - localDW->Product8) * localDW->MathFunction1_k
        [localDW->rtb_MatrixMultiply1_tmp_g] / localDW->sqrt_m;
      localDW->Phi[2 + localDW->rtb_MatrixMultiply1_tmp] = ((1.0 -
        localDW->Product8) * localDW->MatrixConcatenate3
        [localDW->rtb_MatrixMultiply1_tmp_g] / localDW->sqrt_m - (real_T)
        b_a[localDW->rtb_MatrixMultiply1_tmp_g] * rtP.fswParams.estimation.dt) -
        localDW->MathFunction1_k[localDW->rtb_MatrixMultiply1_tmp_g] *
        localDW->Product2_at / localDW->Product1_kn;
      localDW->Phi[5 + 6 * localDW->i] = 0.0;
      localDW->Phi[5 + localDW->rtb_MatrixMultiply1_tmp] = localDW->
        Phi_22[localDW->rtb_MatrixMultiply1_tmp_g];
    }
  }

  /* End of MATLAB Function: '<S124>/CreateStateTransitionMatrix' */

  /* MATLAB Function: '<S124>/MATLAB Function' incorporates:
   *  Constant: '<S124>/Constant13'
   */
  for (localDW->i = 0; localDW->i < 6; localDW->i++) {
    for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
      localDW->rtb_MatrixMultiply1_tmp_g = localDW->i + 6 * localDW->idxStart;
      localDW->rtb_P_chol_p_merge_m[localDW->rtb_MatrixMultiply1_tmp_g] = 0.0;
      for (localDW->rtb_MatrixMultiply1_tmp = 0;
           localDW->rtb_MatrixMultiply1_tmp < 6;
           localDW->rtb_MatrixMultiply1_tmp++) {
        localDW->rtb_P_chol_p_merge_m[localDW->rtb_MatrixMultiply1_tmp_g] =
          localDW->P_chol_p_merge[6 * localDW->i +
          localDW->rtb_MatrixMultiply1_tmp] * localDW->Phi[6 *
          localDW->rtb_MatrixMultiply1_tmp + localDW->idxStart] +
          localDW->rtb_P_chol_p_merge_m[6 * localDW->idxStart + localDW->i];
      }
    }
  }

  for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
    for (localDW->i = 0; localDW->i < 6; localDW->i++) {
      localDW->rtb_MatrixMultiply1_tmp = localDW->i + 12 * localDW->idxStart;
      localDW->C[localDW->rtb_MatrixMultiply1_tmp] =
        localDW->rtb_P_chol_p_merge_m[6 * localDW->idxStart + localDW->i];
      localDW->C[localDW->rtb_MatrixMultiply1_tmp + 6] =
        rtP.fswParams.estimation.Qchol[6 * localDW->i + localDW->idxStart];
    }

    for (localDW->i = 0; localDW->i < 12; localDW->i++) {
      localDW->unusedU2[localDW->i + 12 * localDW->idxStart] = localDW->C[12 *
        localDW->idxStart + localDW->i];
      localDW->unusedU2[localDW->i + 12 * (localDW->idxStart + 6)] = 0.0;
    }
  }

  xgeqrf_oLvid02n_g(localDW->unusedU2, localDW->unusedExpr, localDW);
  for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
    localDW->i = 0;
    while (localDW->i <= localDW->idxStart) {
      localDW->C[localDW->i + 12 * localDW->idxStart] = localDW->unusedU2[12 *
        localDW->idxStart + localDW->i];
      localDW->i++;
    }

    localDW->i = localDW->idxStart;
    while (localDW->i + 2 < 13) {
      localDW->C[(localDW->i + 12 * localDW->idxStart) + 1] = 0.0;
      localDW->i++;
    }
  }

  /* Trigonometry: '<S165>/Cos' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S165>/Constant'
   *  Product: '<S165>/Multiply'
   */
  localDW->Add_h = cos(rtP.fswParams.estimation.dt * localP->Constant_Value_f *
                       localDW->Product3_j);

  /* SignalConversion: '<S165>/ConcatBufferAtMatrix ConcatenateIn1' */
  localDW->Merge_i[0] = localDW->Add_h;

  /* If: '<S164>/If' */
  if (localDW->Product3_j < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    /* SignalConversion: '<S171>/OutportBuffer_InsertedFor_Psi_zero_at_inport_0' incorporates:
     *  Constant: '<S171>/Constant'
     */
    localDW->MathFunction_j[0] = localP->Constant_Value_g[0];
    localDW->MathFunction_j[1] = localP->Constant_Value_g[1];
    localDW->MathFunction_j[2] = localP->Constant_Value_g[2];

    /* End of Outputs for SubSystem: '<S164>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* Trigonometry: '<S170>/Sin' incorporates:
     *  Constant: '<S124>/Constant'
     *  Constant: '<S170>/Constant'
     *  Product: '<S170>/Divide'
     */
    localDW->Product1_f = sin(rtP.fswParams.estimation.dt *
      localP->Constant_Value_hd * localDW->Product3_j);

    /* Product: '<S170>/Divide1' */
    localDW->MathFunction_j[0] = localDW->Product1_f * rty_body_rates_radps[0] /
      localDW->Product3_j;
    localDW->MathFunction_j[1] = localDW->Product1_f * rty_body_rates_radps[1] /
      localDW->Product3_j;
    localDW->MathFunction_j[2] = localDW->Product1_f * rty_body_rates_radps[2] /
      localDW->Product3_j;

    /* End of Outputs for SubSystem: '<S164>/If Action Subsystem' */
  }

  /* End of If: '<S164>/If' */

  /* Math: '<S165>/Transpose2' incorporates:
   *  Gain: '<S165>/Gain'
   */
  localDW->Merge_i[1] = localP->Gain_Gain_ne * localDW->MathFunction_j[0];
  localDW->Merge_i[2] = localP->Gain_Gain_ne * localDW->MathFunction_j[1];
  localDW->Merge_i[3] = localP->Gain_Gain_ne * localDW->MathFunction_j[2];

  /* Outputs for Atomic SubSystem: '<S124>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_m(localDW->MathFunction_j, &localDW->MatrixConcatenate2_i
                        [0], &localP->CrossProdMatrix_lib_mu);

  /* End of Outputs for SubSystem: '<S124>/CrossProdMatrix_lib' */

  /* S-Function (sdspdiag2): '<S123>/Extract Diagonal' */
  for (localDW->i = 0; localDW->i < 6; localDW->i++) {
    localDW->sigma[localDW->i] = localDW->P_chol_p_merge[localDW->i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S123>/Extract Diagonal' */

  /* Sum: '<S165>/Add1' incorporates:
   *  Product: '<S165>/Matrix Multiply2'
   */
  for (localDW->i = 0; localDW->i < 9; localDW->i++) {
    localDW->VectorConcatenate_d[localDW->i + 3] = localDW->Add_h *
      localDW->Id_3[localDW->i] - localDW->MatrixConcatenate2_i[localDW->i];
  }

  /* End of Sum: '<S165>/Add1' */

  /* SignalConversion: '<S165>/ConcatBufferAtMatrix Concatenate1In1' */
  localDW->VectorConcatenate_d[0] = localDW->MathFunction_j[0];
  localDW->VectorConcatenate_d[1] = localDW->MathFunction_j[1];
  localDW->VectorConcatenate_d[2] = localDW->MathFunction_j[2];
  for (localDW->i = 0; localDW->i < 6; localDW->i++) {
    /* Abs: '<S123>/Abs' incorporates:
     *  Sqrt: '<S123>/Sqrt'
     */
    localDW->sigma[localDW->i] = sqrt(fabs(localDW->sigma[localDW->i]));
  }

  /* Gain: '<S123>/multiply' */
  for (localDW->i = 0; localDW->i < 6; localDW->i++) {
    rty_threeSigma_rad[localDW->i] = localP->multiply_Gain * localDW->
      sigma[localDW->i];
  }

  /* End of Gain: '<S123>/multiply' */

  /* Concatenate: '<S165>/Matrix Concatenate2' */
  for (localDW->i = 0; localDW->i < 4; localDW->i++) {
    localDW->idxStart = localDW->i << 2;
    localDW->MatrixConcatenate2_i[localDW->idxStart] = localDW->Merge_i
      [localDW->i];
    localDW->MatrixConcatenate2_i[1 + localDW->idxStart] =
      localDW->VectorConcatenate_d[3 * localDW->i];
    localDW->MatrixConcatenate2_i[2 + localDW->idxStart] =
      localDW->VectorConcatenate_d[3 * localDW->i + 1];
    localDW->MatrixConcatenate2_i[3 + localDW->idxStart] =
      localDW->VectorConcatenate_d[3 * localDW->i + 2];
  }

  /* End of Concatenate: '<S165>/Matrix Concatenate2' */

  /* Product: '<S124>/Product' */
  for (localDW->i = 0; localDW->i < 4; localDW->i++) {
    localDW->Product3_j = localDW->MatrixConcatenate2_i[localDW->i] *
      rty_sc_quat[0];
    localDW->Product3_j += localDW->MatrixConcatenate2_i[localDW->i + 4] *
      rty_sc_quat[1];
    localDW->Product3_j += localDW->MatrixConcatenate2_i[localDW->i + 8] *
      rty_sc_quat[2];
    localDW->Product3_j += localDW->MatrixConcatenate2_i[localDW->i + 12] *
      rty_sc_quat[3];
    localDW->Merge_i[localDW->i] = localDW->Product3_j;
  }

  /* End of Product: '<S124>/Product' */

  /* Sqrt: '<S172>/sqrt' incorporates:
   *  Product: '<S173>/Product'
   *  Product: '<S173>/Product1'
   *  Product: '<S173>/Product2'
   *  Product: '<S173>/Product3'
   *  Sum: '<S173>/Sum'
   */
  localDW->Add_h = sqrt(((localDW->Merge_i[0] * localDW->Merge_i[0] +
    localDW->Merge_i[1] * localDW->Merge_i[1]) + localDW->Merge_i[2] *
    localDW->Merge_i[2]) + localDW->Merge_i[3] * localDW->Merge_i[3]);

  /* SignalConversion: '<S124>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S166>/Product'
   *  Product: '<S166>/Product1'
   *  Product: '<S166>/Product2'
   *  Product: '<S166>/Product3'
   */
  localDW->Merge_i[3] /= localDW->Add_h;
  localDW->Merge_i[0] /= localDW->Add_h;
  localDW->Merge_i[1] /= localDW->Add_h;
  localDW->Merge_i[2] /= localDW->Add_h;

  /* Outputs for Atomic SubSystem: '<S124>/quat_rectify_lib' */
  quat_rectify_lib(localDW->Merge_i, localDW->TmpSignalConversionAtquat_e,
                   &localP->quat_rectify_lib_c);

  /* End of Outputs for SubSystem: '<S124>/quat_rectify_lib' */

  /* MATLABSystem: '<S121>/Moving Average' incorporates:
   *  DataTypeConversion: '<S121>/Cast To Double'
   */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    localDW->obj.pStatistic->pCumSum = 0.0;
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
    localDW->obj.pStatistic->isSetupComplete = true;
    localDW->obj.pStatistic->pCumSum = 0.0;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 9U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  localDW->Product3_j = localDW->obj.pStatistic->pCumRevIndex;
  localDW->Add_h = localDW->obj.pStatistic->pCumSum;
  for (localDW->i = 0; localDW->i < 9; localDW->i++) {
    localDW->MatrixConcatenate3[localDW->i] = localDW->
      obj.pStatistic->pCumSumRev[localDW->i];
  }

  localDW->Add_h += (real_T)rtb_Sum_fj;
  localDW->i = (int32_T)localDW->Product3_j - 1;
  localDW->Product1_f = localDW->MatrixConcatenate3[localDW->i] + localDW->Add_h;
  localDW->MatrixConcatenate3[localDW->i] = rtb_Sum_fj;
  if (localDW->Product3_j != 9.0) {
    localDW->Product3_j++;
  } else {
    localDW->Product3_j = 1.0;
    localDW->Add_h = 0.0;
    for (localDW->i = 7; localDW->i >= 0; localDW->i--) {
      localDW->MatrixConcatenate3[localDW->i] += localDW->
        MatrixConcatenate3[localDW->i + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = localDW->Add_h;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &localDW->MatrixConcatenate3[0],
         9U * sizeof(real_T));
  localDW->obj.pStatistic->pCumRevIndex = localDW->Product3_j;

  /* Switch: '<S121>/Switch' incorporates:
   *  MATLABSystem: '<S121>/Moving Average'
   */
  if (localDW->Product1_f / 10.0 >= localP->Switch_Threshold) {
    /* Update for UnitDelay: '<S3>/Unit Delay1' */
    localDW->UnitDelay1_DSTATE[0] = rty_bias_radps[0];
    localDW->UnitDelay1_DSTATE[1] = rty_bias_radps[1];
    localDW->UnitDelay1_DSTATE[2] = rty_bias_radps[2];
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
     *  Constant: '<S121>/Constant'
     */
    localDW->UnitDelay1_DSTATE[0] = rtP.fswParams.estimation.ic.Beta_init[0];
    localDW->UnitDelay1_DSTATE[1] = rtP.fswParams.estimation.ic.Beta_init[1];
    localDW->UnitDelay1_DSTATE[2] = rtP.fswParams.estimation.ic.Beta_init[2];
  }

  /* End of Switch: '<S121>/Switch' */

  /* If: '<S118>/If' incorporates:
   *  Constant: '<S128>/Constant'
   *  Inport: '<S130>/mekf_mode'
   *  RelationalOperator: '<S128>/Compare'
   */
  if (rtb_Switch_i4) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* SignalConversion: '<S129>/OutportBuffer_InsertedFor_mekf_triad_at_inport_0' incorporates:
     *  Constant: '<S129>/Constant'
     */
    *rty_mekf_telem = localP->Constant_Value_m0;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem' */
  } else if (rtb_Sum_fj < localP->CompareToConstant_const_n) {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    *rty_mekf_telem = rtb_Sum_fj;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    /* SignalConversion: '<S131>/OutportBuffer_InsertedFor_mekf_nom_at_inport_0' incorporates:
     *  Constant: '<S131>/cnst'
     */
    *rty_mekf_telem = localP->cnst_Value;

    /* End of Outputs for SubSystem: '<S118>/If Action Subsystem2' */
  }

  /* End of If: '<S118>/If' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  for (localDW->i = 0; localDW->i < 6; localDW->i++) {
    for (localDW->idxStart = 0; localDW->idxStart < 6; localDW->idxStart++) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S120>/Constant'
       *  MATLAB Function: '<S124>/MATLAB Function'
       */
      if (rtb_Switch_hl) {
        localDW->UnitDelay_DSTATE[localDW->idxStart + 6 * localDW->i] =
          rtP.fswParams.estimation.ic.Pchol_init[6 * localDW->i +
          localDW->idxStart];
      } else {
        localDW->UnitDelay_DSTATE[localDW->idxStart + 6 * localDW->i] =
          localDW->C[12 * localDW->idxStart + localDW->i];
      }

      /* End of Switch: '<S120>/Switch' */
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE[0] = localDW->TmpSignalConversionAtquat_e[0];
  localDW->UnitDelay3_DSTATE[1] = localDW->TmpSignalConversionAtquat_e[1];
  localDW->UnitDelay3_DSTATE[2] = localDW->TmpSignalConversionAtquat_e[2];
  localDW->UnitDelay3_DSTATE[3] = localDW->TmpSignalConversionAtquat_e[3];

  /* Update for If: '<S3>/TRIAD_activation' */
  if (localDW->TRIAD_activation_ActiveSubsyste == 0) {
    /* Update for IfAction SubSystem: '<S3>/TriadEstimator_lib' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Update for UnitDelay: '<S125>/Unit Delay' */
    localDW->UnitDelay_DSTATE_g[0] = localDW->TmpSignalConversionAtquat_e[0];
    localDW->UnitDelay_DSTATE_g[1] = localDW->TmpSignalConversionAtquat_e[1];
    localDW->UnitDelay_DSTATE_g[2] = localDW->TmpSignalConversionAtquat_e[2];
    localDW->UnitDelay_DSTATE_g[3] = localDW->TmpSignalConversionAtquat_e[3];

    /* End of Update for SubSystem: '<S3>/TriadEstimator_lib' */
  }

  /* End of Update for If: '<S3>/TRIAD_activation' */

  /* Update for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_Compare_e;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
