/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0.c
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

#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "factorial_DisWLItj.h"

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void jseconds2ymdhms_ModKEhLD_i(real_T time_s_J2000, real_T *Year, real_T
  *Month, real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000,
  real_T *JD);
static real_T rt_powd_snf_k(real_T u0, real_T u1);
static real_T rt_atan2d_snf_k(real_T u0, real_T u1);
static real_T mod_49nNZZ0V_p(real_T x);
static real_T rt_modd_snf_k(real_T u0, real_T u1);
static real_T norm_2e9Xj4lM_j(const real_T x[3]);
static void merge_9L7gC4KK_f(int32_T idx[6], real_T x[6], int32_T offset,
  int32_T np, int32_T nq, int32_T iwork[6], real_T xwork[6]);
static void sort_E8F8dFL3_j(real_T x[6], int32_T idx[6]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void FSW_Lib0_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  rtM->Timing.RateInteraction.TID0_1 = (rtM->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.25s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S230>/If Action Subsystem'
 *    '<S230>/If Action Subsystem1'
 *    '<S230>/If Action Subsystem2'
 *    '<S230>/If Action Subsystem3'
 *    '<S230>/If Action Subsystem4'
 *    '<S230>/If Action Subsystem5'
 */
void IfActionSubsystem(real_T *rty_Out1, P_IfActionSubsystem *localP)
{
  /* SignalConversion: '<S261>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S261>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Function for MATLAB Function: '<S292>/MATLAB Function3' */
static void jseconds2ymdhms_ModKEhLD_i(real_T time_s_J2000, real_T *Year, real_T
  *Month, real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000,
  real_T *JD)
{
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  for (rtDW.i0_f = 0; rtDW.i0_f < 12; rtDW.i0_f++) {
    rtDW.LMonth[rtDW.i0_f] = b[rtDW.i0_f];
  }

  *JD = time_s_J2000 / 86400.0 + 2.451545E+6;
  *JC_J2000 = (*JD - 2.451545E+6) / 36525.0;
  rtDW.sum = floor((*JD - 2.4150195E+6) / 365.25);
  *Year = 1900.0 + rtDW.sum;
  rtDW.T_1900 = (*JD - 2.4150195E+6) - (floor((((1900.0 + rtDW.sum) - 1900.0) -
    1.0) * 0.25) + ((1900.0 + rtDW.sum) - 1900.0) * 365.0);
  if (rtDW.T_1900 < 1.0) {
    *Year = (1900.0 + rtDW.sum) - 1.0;
    rtDW.T_1900 = (*JD - 2.4150195E+6) - (floor(((((1900.0 + rtDW.sum) - 1.0) -
      1900.0) - 1.0) * 0.25) + (((1900.0 + rtDW.sum) - 1.0) - 1900.0) * 365.0);
  }

  if ((!rtIsInf(*Year)) && (!rtIsNaN(*Year))) {
    if (*Year == 0.0) {
      rtDW.sum = 0.0;
    } else {
      rtDW.sum = fmod(*Year, 4.0);
      if (rtDW.sum == 0.0) {
        rtDW.sum = 0.0;
      } else {
        if (*Year < 0.0) {
          rtDW.sum += 4.0;
        }
      }
    }
  } else {
    rtDW.sum = (rtNaN);
  }

  if (rtDW.sum == 0.0) {
    rtDW.LMonth[1] = 29;
  }

  *Day = floor(rtDW.T_1900);
  rtDW.sum = 0.0;
  *Month = 0.0;
  while (rtDW.sum < *Day) {
    (*Month)++;
    rtDW.sum += (real_T)rtDW.LMonth[(int32_T)*Month - 1];
  }

  rtDW.T_1900 = (rtDW.T_1900 - *Day) * 24.0;
  *Hour = floor(rtDW.T_1900);
  rtDW.T_1900 -= *Hour;
  *Min = floor(rtDW.T_1900 * 60.0);
  *Sec = (rtDW.T_1900 - *Min / 60.0) * 3600.0;
}

static real_T rt_powd_snf_k(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    rtDW.d2 = fabs(u0);
    rtDW.d3 = fabs(u1);
    if (rtIsInf(u1)) {
      if (rtDW.d2 == 1.0) {
        y = 1.0;
      } else if (rtDW.d2 > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (rtDW.d3 == 0.0) {
      y = 1.0;
    } else if (rtDW.d3 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static real_T rt_atan2d_snf_k(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      rtDW.u0 = 1;
    } else {
      rtDW.u0 = -1;
    }

    if (u1 > 0.0) {
      rtDW.u1 = 1;
    } else {
      rtDW.u1 = -1;
    }

    y = atan2(rtDW.u0, rtDW.u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S291>/MATLAB Function' */
static real_T mod_49nNZZ0V_p(real_T x)
{
  real_T r;
  boolean_T rEQ0;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 6.2831853071795862);
      rEQ0 = (r == 0.0);
      if (!rEQ0) {
        rtDW.q_d = fabs(x / 6.2831853071795862);
        rEQ0 = (fabs(rtDW.q_d - floor(rtDW.q_d + 0.5)) <= 2.2204460492503131E-16
                * rtDW.q_d);
      }

      if (rEQ0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 6.2831853071795862;
        }
      }
    }
  } else {
    r = (rtNaN);
  }

  return r;
}

static real_T rt_modd_snf_k(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  y = u0;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        rtDW.q_l = fabs(u0 / u1);
        yEq = !(fabs(rtDW.q_l - floor(rtDW.q_l + 0.5)) > DBL_EPSILON * rtDW.q_l);
      }

      if (yEq) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S14>/MATLAB Function' */
static real_T norm_2e9Xj4lM_j(const real_T x[3])
{
  real_T y;
  rtDW.scale_jw = 3.3121686421112381E-170;
  rtDW.absxk_d = fabs(x[0]);
  if (rtDW.absxk_d > 3.3121686421112381E-170) {
    y = 1.0;
    rtDW.scale_jw = rtDW.absxk_d;
  } else {
    rtDW.t_g = rtDW.absxk_d / 3.3121686421112381E-170;
    y = rtDW.t_g * rtDW.t_g;
  }

  rtDW.absxk_d = fabs(x[1]);
  if (rtDW.absxk_d > rtDW.scale_jw) {
    rtDW.t_g = rtDW.scale_jw / rtDW.absxk_d;
    y = y * rtDW.t_g * rtDW.t_g + 1.0;
    rtDW.scale_jw = rtDW.absxk_d;
  } else {
    rtDW.t_g = rtDW.absxk_d / rtDW.scale_jw;
    y += rtDW.t_g * rtDW.t_g;
  }

  rtDW.absxk_d = fabs(x[2]);
  if (rtDW.absxk_d > rtDW.scale_jw) {
    rtDW.t_g = rtDW.scale_jw / rtDW.absxk_d;
    y = y * rtDW.t_g * rtDW.t_g + 1.0;
    rtDW.scale_jw = rtDW.absxk_d;
  } else {
    rtDW.t_g = rtDW.absxk_d / rtDW.scale_jw;
    y += rtDW.t_g * rtDW.t_g;
  }

  return rtDW.scale_jw * sqrt(y);
}

/* Function for MATLAB Function: '<S14>/MATLAB Function' */
static void merge_9L7gC4KK_f(int32_T idx[6], real_T x[6], int32_T offset,
  int32_T np, int32_T nq, int32_T iwork[6], real_T xwork[6])
{
  int32_T exitg1;
  if ((np != 0) && (nq != 0)) {
    rtDW.n_tmp = np + nq;
    rtDW.q_j = 0;
    while (rtDW.q_j <= rtDW.n_tmp - 1) {
      rtDW.iout = offset + rtDW.q_j;
      iwork[rtDW.q_j] = idx[rtDW.iout];
      xwork[rtDW.q_j] = x[rtDW.iout];
      rtDW.q_j++;
    }

    rtDW.n_b = 0;
    rtDW.q_j = np;
    rtDW.iout = offset - 1;
    do {
      exitg1 = 0;
      rtDW.iout++;
      if (xwork[rtDW.n_b] <= xwork[rtDW.q_j]) {
        idx[rtDW.iout] = iwork[rtDW.n_b];
        x[rtDW.iout] = xwork[rtDW.n_b];
        if (rtDW.n_b + 1 < np) {
          rtDW.n_b++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[rtDW.iout] = iwork[rtDW.q_j];
        x[rtDW.iout] = xwork[rtDW.q_j];
        if (rtDW.q_j + 1 < rtDW.n_tmp) {
          rtDW.q_j++;
        } else {
          rtDW.q_j = rtDW.iout - rtDW.n_b;
          while (rtDW.n_b + 1 <= np) {
            rtDW.iout = (rtDW.q_j + rtDW.n_b) + 1;
            idx[rtDW.iout] = iwork[rtDW.n_b];
            x[rtDW.iout] = xwork[rtDW.n_b];
            rtDW.n_b++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<S14>/MATLAB Function' */
static void sort_E8F8dFL3_j(real_T x[6], int32_T idx[6])
{
  rtDW.x4[0] = 0.0;
  rtDW.idx4[0] = 0;
  rtDW.x4[1] = 0.0;
  rtDW.idx4[1] = 0;
  rtDW.x4[2] = 0.0;
  rtDW.idx4[2] = 0;
  rtDW.x4[3] = 0.0;
  rtDW.idx4[3] = 0;
  for (rtDW.i_e = 0; rtDW.i_e < 6; rtDW.i_e++) {
    idx[rtDW.i_e] = 0;
    rtDW.xwork[rtDW.i_e] = 0.0;
  }

  rtDW.nNaNs = 0;
  rtDW.i_e = -1;
  for (rtDW.m_b = 0; rtDW.m_b < 6; rtDW.m_b++) {
    if (rtIsNaN(x[rtDW.m_b])) {
      idx[5 - rtDW.nNaNs] = rtDW.m_b + 1;
      rtDW.xwork[5 - rtDW.nNaNs] = x[rtDW.m_b];
      rtDW.nNaNs++;
    } else {
      rtDW.i_e++;
      rtDW.idx4[rtDW.i_e] = (int8_T)(rtDW.m_b + 1);
      rtDW.x4[rtDW.i_e] = x[rtDW.m_b];
      if (rtDW.i_e + 1 == 4) {
        rtDW.i_e = rtDW.m_b - rtDW.nNaNs;
        if (rtDW.x4[0] <= rtDW.x4[1]) {
          rtDW.i1_l = 1;
          rtDW.i2_h = 2;
        } else {
          rtDW.i1_l = 2;
          rtDW.i2_h = 1;
        }

        if (rtDW.x4[2] <= rtDW.x4[3]) {
          rtDW.i3_b = 3;
          rtDW.i4_d = 4;
        } else {
          rtDW.i3_b = 4;
          rtDW.i4_d = 3;
        }

        rtDW.d0_l = rtDW.x4[rtDW.i1_l - 1];
        rtDW.d1 = rtDW.x4[rtDW.i3_b - 1];
        if (rtDW.d0_l <= rtDW.d1) {
          if (rtDW.x4[rtDW.i2_h - 1] <= rtDW.d1) {
            rtDW.perm[0] = (int8_T)rtDW.i1_l;
            rtDW.perm[1] = (int8_T)rtDW.i2_h;
            rtDW.perm[2] = (int8_T)rtDW.i3_b;
            rtDW.perm[3] = (int8_T)rtDW.i4_d;
          } else if (rtDW.x4[rtDW.i2_h - 1] <= rtDW.x4[rtDW.i4_d - 1]) {
            rtDW.perm[0] = (int8_T)rtDW.i1_l;
            rtDW.perm[1] = (int8_T)rtDW.i3_b;
            rtDW.perm[2] = (int8_T)rtDW.i2_h;
            rtDW.perm[3] = (int8_T)rtDW.i4_d;
          } else {
            rtDW.perm[0] = (int8_T)rtDW.i1_l;
            rtDW.perm[1] = (int8_T)rtDW.i3_b;
            rtDW.perm[2] = (int8_T)rtDW.i4_d;
            rtDW.perm[3] = (int8_T)rtDW.i2_h;
          }
        } else {
          rtDW.d1 = rtDW.x4[rtDW.i4_d - 1];
          if (rtDW.d0_l <= rtDW.d1) {
            if (rtDW.x4[rtDW.i2_h - 1] <= rtDW.d1) {
              rtDW.perm[0] = (int8_T)rtDW.i3_b;
              rtDW.perm[1] = (int8_T)rtDW.i1_l;
              rtDW.perm[2] = (int8_T)rtDW.i2_h;
              rtDW.perm[3] = (int8_T)rtDW.i4_d;
            } else {
              rtDW.perm[0] = (int8_T)rtDW.i3_b;
              rtDW.perm[1] = (int8_T)rtDW.i1_l;
              rtDW.perm[2] = (int8_T)rtDW.i4_d;
              rtDW.perm[3] = (int8_T)rtDW.i2_h;
            }
          } else {
            rtDW.perm[0] = (int8_T)rtDW.i3_b;
            rtDW.perm[1] = (int8_T)rtDW.i4_d;
            rtDW.perm[2] = (int8_T)rtDW.i1_l;
            rtDW.perm[3] = (int8_T)rtDW.i2_h;
          }
        }

        rtDW.i1_l = rtDW.perm[0] - 1;
        idx[rtDW.i_e - 3] = rtDW.idx4[rtDW.i1_l];
        rtDW.i2_h = rtDW.perm[1] - 1;
        idx[rtDW.i_e - 2] = rtDW.idx4[rtDW.i2_h];
        rtDW.i3_b = rtDW.perm[2] - 1;
        idx[rtDW.i_e - 1] = rtDW.idx4[rtDW.i3_b];
        rtDW.i4_d = rtDW.perm[3] - 1;
        idx[rtDW.i_e] = rtDW.idx4[rtDW.i4_d];
        x[rtDW.i_e - 3] = rtDW.x4[rtDW.i1_l];
        x[rtDW.i_e - 2] = rtDW.x4[rtDW.i2_h];
        x[rtDW.i_e - 1] = rtDW.x4[rtDW.i3_b];
        x[rtDW.i_e] = rtDW.x4[rtDW.i4_d];
        rtDW.i_e = -1;
      }
    }
  }

  if (rtDW.i_e + 1 > 0) {
    rtDW.perm[1] = 0;
    rtDW.perm[2] = 0;
    rtDW.perm[3] = 0;
    switch (rtDW.i_e + 1) {
     case 1:
      rtDW.perm[0] = 1;
      break;

     case 2:
      if (rtDW.x4[0] <= rtDW.x4[1]) {
        rtDW.perm[0] = 1;
        rtDW.perm[1] = 2;
      } else {
        rtDW.perm[0] = 2;
        rtDW.perm[1] = 1;
      }
      break;

     default:
      if (rtDW.x4[0] <= rtDW.x4[1]) {
        if (rtDW.x4[1] <= rtDW.x4[2]) {
          rtDW.perm[0] = 1;
          rtDW.perm[1] = 2;
          rtDW.perm[2] = 3;
        } else if (rtDW.x4[0] <= rtDW.x4[2]) {
          rtDW.perm[0] = 1;
          rtDW.perm[1] = 3;
          rtDW.perm[2] = 2;
        } else {
          rtDW.perm[0] = 3;
          rtDW.perm[1] = 1;
          rtDW.perm[2] = 2;
        }
      } else if (rtDW.x4[0] <= rtDW.x4[2]) {
        rtDW.perm[0] = 2;
        rtDW.perm[1] = 1;
        rtDW.perm[2] = 3;
      } else if (rtDW.x4[1] <= rtDW.x4[2]) {
        rtDW.perm[0] = 2;
        rtDW.perm[1] = 3;
        rtDW.perm[2] = 1;
      } else {
        rtDW.perm[0] = 3;
        rtDW.perm[1] = 2;
        rtDW.perm[2] = 1;
      }
      break;
    }

    rtDW.m_b = 0;
    while (rtDW.m_b <= rtDW.i_e) {
      rtDW.i1_l = rtDW.perm[rtDW.m_b] - 1;
      rtDW.i2_h = ((rtDW.m_b - rtDW.nNaNs) - rtDW.i_e) + 5;
      idx[rtDW.i2_h] = rtDW.idx4[rtDW.i1_l];
      x[rtDW.i2_h] = rtDW.x4[rtDW.i1_l];
      rtDW.m_b++;
    }
  }

  rtDW.m_b = (rtDW.nNaNs >> 1) + 6;
  rtDW.i_e = 6;
  while (rtDW.i_e - 6 <= rtDW.m_b - 7) {
    rtDW.i2_h = rtDW.i_e - rtDW.nNaNs;
    rtDW.i1_l = idx[rtDW.i2_h];
    idx[rtDW.i2_h] = idx[11 - rtDW.i_e];
    idx[11 - rtDW.i_e] = rtDW.i1_l;
    x[rtDW.i2_h] = rtDW.xwork[11 - rtDW.i_e];
    x[11 - rtDW.i_e] = rtDW.xwork[rtDW.i2_h];
    rtDW.i_e++;
  }

  if ((rtDW.nNaNs & 1U) != 0U) {
    rtDW.i_e = rtDW.m_b - rtDW.nNaNs;
    x[rtDW.i_e] = rtDW.xwork[rtDW.i_e];
  }

  if (6 - rtDW.nNaNs > 1) {
    for (rtDW.i_e = 0; rtDW.i_e < 6; rtDW.i_e++) {
      rtDW.iwork[rtDW.i_e] = 0;
    }

    rtDW.i_e = (6 - rtDW.nNaNs) >> 2;
    rtDW.m_b = 4;
    while (rtDW.i_e > 1) {
      if ((rtDW.i_e & 1U) != 0U) {
        rtDW.i_e--;
        rtDW.i1_l = rtDW.m_b * rtDW.i_e;
        rtDW.i2_h = 6 - (rtDW.nNaNs + rtDW.i1_l);
        if (rtDW.i2_h > rtDW.m_b) {
          merge_9L7gC4KK_f(idx, x, rtDW.i1_l, rtDW.m_b, rtDW.i2_h - rtDW.m_b,
                           rtDW.iwork, rtDW.xwork);
        }
      }

      rtDW.i1_l = rtDW.m_b << 1;
      rtDW.i_e >>= 1;
      rtDW.i2_h = 0;
      while (rtDW.i2_h <= rtDW.i_e - 1) {
        merge_9L7gC4KK_f(idx, x, rtDW.i2_h * rtDW.i1_l, rtDW.m_b, rtDW.m_b,
                         rtDW.iwork, rtDW.xwork);
        rtDW.i2_h++;
      }

      rtDW.m_b = rtDW.i1_l;
    }

    if (6 - rtDW.nNaNs > rtDW.m_b) {
      merge_9L7gC4KK_f(idx, x, 0, rtDW.m_b, 6 - (rtDW.nNaNs + rtDW.m_b),
                       rtDW.iwork, rtDW.xwork);
    }
  }
}

/* Model step function for TID0 */
void FSW_Lib0_step0(void)              /* Sample time: [0.0125s, 0.0s] */
{
  int32_T i;

  {                                    /* Sample time: [0.0125s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S1>/Rate Transition' incorporates:
   *  Inport: '<Root>/telecommands'
   */
  if (rtM->Timing.RateInteraction.TID0_1) {
    rtDW.MET_utc_s = rtU.telecommands.MET_utc_s;

    /* RateTransition: '<S2>/Rate Transition5' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    rtDW.RateTransition5 = rtU.sensor_meas.sun_meas_valid;

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition2[0] = rtU.sensor_meas.sun_meas_ss_deg[0];
    rtDW.RateTransition2[1] = rtU.sensor_meas.sun_meas_ss_deg[1];
    memcpy(&rtDW.orbit_tle[0], &rtU.telecommands.orbit_tle[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition3' incorporates:
     *  Inport: '<Root>/sensor_meas'
     *  Inport: '<Root>/telecommands'
     */
    memcpy(&rtDW.RateTransition3[0], &rtU.sensor_meas.mag_mag_uT[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S2>/Rate Transition6' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition6_l[0] = rtU.sensor_meas.mag_meas_valid[0];
    rtDW.RateTransition6_l[1] = rtU.sensor_meas.mag_meas_valid[1];
    rtDW.RateTransition6_l[2] = rtU.sensor_meas.mag_meas_valid[2];
  }

  /* Gain: '<S2>/deg2rad' incorporates:
   *  Inport: '<Root>/sensor_meas'
   */
  for (i = 0; i < 9; i++) {
    rtDW.deg2rad[i] = rtP.fswParams.constants.convert.DEG2RAD *
      rtU.sensor_meas.gyro_gyro_radps[i];
  }

  /* End of Gain: '<S2>/deg2rad' */

  /* RateTransition: '<S2>/Rate Transition4' */
  if (rtM->Timing.RateInteraction.TID0_1) {
    memcpy(&rtDW.RateTransition4[0], &rtDW.deg2rad[0], 9U * sizeof(real_T));

    /* RateTransition: '<S2>/Rate Transition7' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    rtDW.RateTransition7[0] = rtU.sensor_meas.gyro_meas_valid[0];
    rtDW.RateTransition7[1] = rtU.sensor_meas.gyro_meas_valid[1];
    rtDW.RateTransition7[2] = rtU.sensor_meas.gyro_meas_valid[2];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    rtDW.triad_override = rtU.telecommands.triad_override;
    rtDW.MET_soar_utc_s = rtU.telecommands.MET_soar_utc_s;

    /* RateTransition: '<S4>/Rate Transition1' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition1[0] = rtU.actuator_meas_p.rwa_rpm[0];
    rtDW.RateTransition1[1] = rtU.actuator_meas_p.rwa_rpm[1];
    rtDW.RateTransition1[2] = rtU.actuator_meas_p.rwa_rpm[2];
    rtDW.RateTransition1[3] = rtU.actuator_meas_p.rwa_rpm[3];

    /* RateTransition: '<S1>/Rate Transition' incorporates:
     *  Inport: '<Root>/telecommands'
     */
    for (i = 0; i < 6; i++) {
      rtDW.telecom[i] = rtU.telecommands.telecom[i];
    }

    rtDW.target_latlonalt[0] = rtU.telecommands.target_latlonalt[0];
    rtDW.target_latlonalt[1] = rtU.telecommands.target_latlonalt[1];
    rtDW.target_latlonalt[2] = rtU.telecommands.target_latlonalt[2];
    rtDW.quat_soar_cmd[0] = rtU.telecommands.quat_soar_cmd[0];
    rtDW.quat_soar_cmd[1] = rtU.telecommands.quat_soar_cmd[1];
    rtDW.quat_soar_cmd[2] = rtU.telecommands.quat_soar_cmd[2];
    rtDW.quat_soar_cmd[3] = rtU.telecommands.quat_soar_cmd[3];

    /* RateTransition: '<S2>/Rate Transition1' incorporates:
     *  Inport: '<Root>/sensor_meas'
     */
    for (i = 0; i < 5; i++) {
      rtDW.RateTransition1_l[i] = rtU.sensor_meas.photodiodes_uA[i];
    }

    /* End of RateTransition: '<S2>/Rate Transition1' */

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.gnc_mode = rtDW.RateTransition4_1_Buffer0;

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_p[0] = rtU.actuator_meas_p.rwa_valid[0];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[0] = rtDW.RateTransition4_2_Buffer0[0];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_p[1] = rtU.actuator_meas_p.rwa_valid[1];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[1] = rtDW.RateTransition4_2_Buffer0[1];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_p[2] = rtU.actuator_meas_p.rwa_valid[2];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[2] = rtDW.RateTransition4_2_Buffer0[2];

    /* RateTransition: '<S4>/Rate Transition2' incorporates:
     *  Inport: '<Root>/act_meas'
     */
    rtDW.RateTransition2_p[3] = rtU.actuator_meas_p.rwa_valid[3];

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.sc_quat[3] = rtDW.RateTransition4_2_Buffer0[3];
    rtDW.sc_body_rates_radps[0] = rtDW.RateTransition4_3_Buffer0[0];
    rtDW.sc_body_rates_radps[1] = rtDW.RateTransition4_3_Buffer0[1];
    rtDW.sc_body_rates_radps[2] = rtDW.RateTransition4_3_Buffer0[2];
    rtDW.cmd_quat[0] = rtDW.RateTransition4_4_Buffer0[0];
    rtDW.cmd_quat[1] = rtDW.RateTransition4_4_Buffer0[1];
    rtDW.cmd_quat[2] = rtDW.RateTransition4_4_Buffer0[2];
    rtDW.cmd_quat[3] = rtDW.RateTransition4_4_Buffer0[3];
    rtDW.cmd_body_rates_radps[0] = rtDW.RateTransition4_5_Buffer0[0];
    rtDW.cmd_body_rates_radps[1] = rtDW.RateTransition4_5_Buffer0[1];
    rtDW.cmd_body_rates_radps[2] = rtDW.RateTransition4_5_Buffer0[2];
    for (i = 0; i < 6; i++) {
      rtDW.mekf_3sigma_rad[i] = rtDW.RateTransition4_6_Buffer0[i];
    }

    rtDW.mekf_telem = rtDW.RateTransition4_8_Buffer0;
    rtDW.mekf_bias_radps[0] = rtDW.RateTransition4_7_Buffer0[0];
    rtDW.r_eci_m[0] = rtDW.RateTransition4_9_Buffer0[0];
    rtDW.mekf_bias_radps[1] = rtDW.RateTransition4_7_Buffer0[1];
    rtDW.r_eci_m[1] = rtDW.RateTransition4_9_Buffer0[1];
    rtDW.mekf_bias_radps[2] = rtDW.RateTransition4_7_Buffer0[2];
    rtDW.r_eci_m[2] = rtDW.RateTransition4_9_Buffer0[2];
    rtDW.ace_err = rtDW.RateTransition4_10_Buffer0;
    rtDW.eclipse = rtDW.RateTransition4_11_Buffer0;
    rtDW.sgp4_flag = rtDW.RateTransition4_12_Buffer0;
    rtDW.sc_above_gs = rtDW.RateTransition4_13_Buffer0;
    rtDW.sc_above_targ = rtDW.RateTransition4_14_Buffer0;
    rtDW.target_gen_flag = rtDW.RateTransition4_15_Buffer0;
    rtDW.elev_gs_rad = rtDW.RateTransition4_16_Buffer0;
    rtDW.elev_targ_rad = rtDW.RateTransition4_17_Buffer0;
    rtDW.ss_valid = rtDW.RateTransition4_18_Buffer0;
    rtDW.soar_telemetry_n = rtDW.RateTransition4_19_Buffer0;
  }

  /* End of RateTransition: '<S2>/Rate Transition4' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_fsw_telem_at_inport_0' incorporates:
   *  Outport: '<Root>/fsw_telem'
   */
  rtY.fsw_telem.gnc_mode = rtDW.gnc_mode;
  rtY.fsw_telem.sc_quat[0] = rtDW.sc_quat[0];
  rtY.fsw_telem.sc_quat[1] = rtDW.sc_quat[1];
  rtY.fsw_telem.sc_quat[2] = rtDW.sc_quat[2];
  rtY.fsw_telem.sc_quat[3] = rtDW.sc_quat[3];
  rtY.fsw_telem.sc_body_rates_radps[0] = rtDW.sc_body_rates_radps[0];
  rtY.fsw_telem.sc_body_rates_radps[1] = rtDW.sc_body_rates_radps[1];
  rtY.fsw_telem.sc_body_rates_radps[2] = rtDW.sc_body_rates_radps[2];
  rtY.fsw_telem.cmd_quat[0] = rtDW.cmd_quat[0];
  rtY.fsw_telem.cmd_quat[1] = rtDW.cmd_quat[1];
  rtY.fsw_telem.cmd_quat[2] = rtDW.cmd_quat[2];
  rtY.fsw_telem.cmd_quat[3] = rtDW.cmd_quat[3];
  rtY.fsw_telem.cmd_body_rates_radps[0] = rtDW.cmd_body_rates_radps[0];
  rtY.fsw_telem.cmd_body_rates_radps[1] = rtDW.cmd_body_rates_radps[1];
  rtY.fsw_telem.cmd_body_rates_radps[2] = rtDW.cmd_body_rates_radps[2];
  for (i = 0; i < 6; i++) {
    rtY.fsw_telem.mekf_3sigma_rad[i] = rtDW.mekf_3sigma_rad[i];
  }

  rtY.fsw_telem.mekf_telem = rtDW.mekf_telem;
  rtY.fsw_telem.mekf_bias_radps[0] = rtDW.mekf_bias_radps[0];
  rtY.fsw_telem.r_eci_m[0] = rtDW.r_eci_m[0];
  rtY.fsw_telem.mekf_bias_radps[1] = rtDW.mekf_bias_radps[1];
  rtY.fsw_telem.r_eci_m[1] = rtDW.r_eci_m[1];
  rtY.fsw_telem.mekf_bias_radps[2] = rtDW.mekf_bias_radps[2];
  rtY.fsw_telem.r_eci_m[2] = rtDW.r_eci_m[2];
  rtY.fsw_telem.ace_err = rtDW.ace_err;
  rtY.fsw_telem.eclipse = rtDW.eclipse;
  rtY.fsw_telem.sgp4_flag = rtDW.sgp4_flag;
  rtY.fsw_telem.sc_above_gs = rtDW.sc_above_gs;
  rtY.fsw_telem.sc_above_targ = rtDW.sc_above_targ;
  rtY.fsw_telem.target_gen_flag = rtDW.target_gen_flag;
  rtY.fsw_telem.elev_gs_rad = rtDW.elev_gs_rad;
  rtY.fsw_telem.elev_targ_rad = rtDW.elev_targ_rad;
  rtY.fsw_telem.ss_valid = rtDW.ss_valid;
  rtY.fsw_telem.soar_telemetry = rtDW.soar_telemetry_n;

  /* End of BusCreator: '<Root>/BusConversion_InsertedFor_fsw_telem_at_inport_0' */
}

/* Model step function for TID1 */
void FSW_Lib0_step1(void)              /* Sample time: [0.25s, 0.0s] */
{
  static const real_T nc[300] = { 1.0, 9.0, 31.0, 2.0, 10.0, 32.0, 11.0, 33.0,
    34.0, 12.0, 35.0, 13.0, 36.0, 38.0, 37.0, 40.0, 39.0, 41.0, 14.0, 3.0, 42.0,
    45.0, 43.0, 44.0, 46.0, 15.0, 47.0, 16.0, 18.0, 48.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, -1.0, 1.0, 2.0,
    -2.0, 0.0, 2.0, 2.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 0.0,
    0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, 0.0,
    0.0, 0.0, -2.0, 0.0, 0.0, -2.0, -2.0, -2.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0,
    -2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, -2.0, 0.0, 0.0, -2.0, 2.0, 1.0, 2.0,
    2.0, 2.0, 0.0, 0.0, 2.0, 1.0, 2.0, 2.0, 0.0, 1.0, 2.0, 1.0, 0.0, 2.0, 1.0,
    1.0, 0.0, 1.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 2.0, 1.0, -171996.0,
    -13187.0, -2274.0, 2062.0, 1426.0, 712.0, -517.0, -386.0, -301.0, 217.0,
    -158.0, 129.0, 123.0, 63.0, 63.0, -59.0, -58.0, -51.0, 48.0, 46.0, -38.0,
    -31.0, 29.0, 29.0, 26.0, -22.0, 21.0, 17.0, -16.0, 16.0, -174.2, -1.6, -0.2,
    0.2, -3.4, 0.1, 1.2, -0.4, 0.0, -0.5, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.1, 0.1, 0.0, 92025.0,
    5736.0, 977.0, -895.0, 54.0, -7.0, 224.0, 200.0, 129.0, -95.0, -1.0, -70.0,
    -53.0, -33.0, -2.0, 26.0, 32.0, 27.0, 1.0, -24.0, 16.0, 13.0, -1.0, -12.0,
    -1.0, 0.0, -10.0, 0.0, 7.0, -8.0, 8.9, -3.1, -0.5, 0.5, -0.1, 0.0, -0.6, 0.0,
    -0.1, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T g[156] = { -29438.2, -2444.5, 1351.8, 907.5, -232.9, 69.4,
    81.7, 24.2, 5.5, -2.0, 3.0, -2.0, -1493.5, 3014.7, -2351.6, 814.8, 360.1,
    67.7, -75.9, 8.9, 8.8, -6.1, -1.4, -0.1, 0.0, 1679.0, 1223.6, 117.8, 191.7,
    72.3, -7.1, -16.9, 3.0, 0.2, -2.3, 0.5, 0.0, 0.0, 582.3, -335.6, -141.3,
    -129.1, 52.2, -3.1, -3.2, 0.6, 2.1, 1.2, 0.0, 0.0, 0.0, 69.7, -157.2, -28.4,
    15.0, -20.7, 0.6, -0.5, -0.8, -0.9, 0.0, 0.0, 0.0, 0.0, 7.7, 13.6, 9.1, 13.3,
    -13.2, 1.8, 0.6, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, -70.3, -3.0, 11.6, -0.1, -0.7,
    -0.7, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.9, -16.3, 8.7, 2.2, 0.1, 0.6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.1, -9.1, 2.4, 1.7, -0.4, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -10.4, -1.8, -0.2, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -3.6, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.5, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T dg[156] = { 7.0, -11.0, 2.4, -0.8, -0.3, -0.8, -0.3, -0.1,
    -0.1, 0.0, 0.0, 0.0, 9.0, -6.2, -5.7, -0.9, 0.6, -0.5, -0.2, 0.2, -0.1, 0.0,
    0.0, 0.0, 0.0, 0.3, 2.0, -6.5, -0.8, -0.1, -0.3, -0.2, 0.0, -0.1, 0.0, 0.0,
    0.0, 0.0, -11.0, 5.2, 0.1, 1.6, 0.9, 0.5, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0,
    -4.0, 1.2, -1.6, 0.1, -0.1, -0.4, -0.1, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 1.4,
    0.0, -0.6, 0.4, 0.0, -0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, -0.9,
    0.4, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7, -0.1, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, -0.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.3, -0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.1 };

  static const real_T h[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 4796.3, -2842.4, -113.7, 283.3, 46.9, -20.1, -54.3, 10.1,
    -21.8, 3.3, 0.0, -1.0, 0.0, -638.8, 246.5, -188.6, 196.5, 32.8, -19.5, -18.3,
    10.7, -0.4, 2.1, 0.3, 0.0, 0.0, -537.4, 180.7, -119.9, 59.1, 6.0, 13.3, 11.8,
    4.6, -0.6, 1.8, 0.0, 0.0, 0.0, -330.0, 16.0, -67.1, 24.5, -14.5, -6.8, 4.4,
    -1.1, -2.2, 0.0, 0.0, 0.0, 0.0, 100.6, 8.1, 3.5, 16.2, -6.9, -7.9, 0.7, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 61.9, -27.7, 6.0, 7.9, -0.6, -0.2, 0.7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -2.9, -9.2, 1.0, -4.2, -2.1, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 2.4, -3.9, -2.9, -1.5, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 8.5, -1.1, -2.6, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -8.8,
    -2.0, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.3, -0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.8 };

  static const real_T dh[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -30.2, -29.6, 6.5, -0.4, 0.2, 0.3, 0.6, -0.4, -0.3, 0.0, 0.0,
    0.0, 0.0, -17.3, -0.8, 5.8, 2.3, -1.5, 0.5, 0.6, 0.1, 0.1, 0.1, 0.0, 0.0,
    0.0, -2.0, 3.8, 0.0, -1.2, -0.8, -0.1, -0.4, -0.2, 0.0, -0.1, 0.0, 0.0, 0.0,
    -3.5, 3.3, 0.4, -0.2, 0.6, 0.3, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, -0.6, 0.2,
    -1.1, -0.2, 0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.3, 0.1, -0.5,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.5, -0.1, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.5, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.1 };

  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  /* Sum: '<S292>/Sum' incorporates:
   *  Constant: '<S292>/Constant1'
   */
  rtDW.Sum_o = rtDW.MET_utc_s + rtP.fswParams.sensors.time_offset;

  /* MATLAB Function: '<S292>/MATLAB Function3' */
  jseconds2ymdhms_ModKEhLD_i(rtDW.Sum_o, &rtDW.YMDHMS_UTC[0], &rtDW.YMDHMS_UTC[1],
    &rtDW.YMDHMS_UTC[2], &rtDW.YMDHMS_UTC[3], &rtDW.YMDHMS_UTC[4],
    &rtDW.YMDHMS_UTC[5], &rtDW.u_moon, &rtDW.tsince_JD);
  jseconds2ymdhms_ModKEhLD_i(rtDW.Sum_o + -0.0361535, &rtDW.epsb_1980,
    &rtDW.M_moon, &rtDW.M_sun, &rtDW.u_moon, &rtDW.D_sun, &rtDW.Sum1_m,
    &rtDW.eps, &rtDW.O_moon);
  jseconds2ymdhms_ModKEhLD_i((rtDW.Sum_o + 37.0) + 32.184, &rtDW.epsb_1980,
    &rtDW.M_moon, &rtDW.M_sun, &rtDW.u_moon, &rtDW.D_sun, &rtDW.O_moon,
    &rtDW.Sum1_m, &rtDW.dpsi_1980);

  /* MATLAB Function: '<S380>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S292>/MATLAB Function3'
   */
  rtDW.QOMS4 = rtDW.Sum1_m * rtDW.Sum1_m;
  rtDW.w_o = rt_powd_snf_k(rtDW.Sum1_m, 3.0);
  rtDW.epsb_1980 = (((23.439291 - 0.0130042 * rtDW.Sum1_m) - rtDW.QOMS4 *
                     1.64E-7) + 5.04E-7 * rtDW.w_o) * 0.017453292519943295;
  rtDW.M_moon = (((477198.8673981 * rtDW.Sum1_m + 134.96298139) + rtDW.QOMS4 *
                  0.0086972) + 1.78E-5 * rtDW.w_o) * 0.017453292519943295;
  rtDW.M_sun = (((35999.05034 * rtDW.Sum1_m + 357.52772333) - rtDW.QOMS4 *
                 0.0001603) - 3.3E-6 * rtDW.w_o) * 0.017453292519943295;
  rtDW.u_moon = (((483202.0175381 * rtDW.Sum1_m + 93.27191028) - rtDW.QOMS4 *
                  0.0036825) + 3.1E-6 * rtDW.w_o) * 0.017453292519943295;
  rtDW.D_sun = (((445267.11148 * rtDW.Sum1_m + 297.85036306) - rtDW.QOMS4 *
                 0.0019142) + 5.3E-6 * rtDW.w_o) * 0.017453292519943295;
  rtDW.O_moon = (((125.04452222 - 1934.1362608 * rtDW.Sum1_m) + rtDW.QOMS4 *
                  0.0020708) + 2.2E-6 * rtDW.w_o) * 0.017453292519943295;
  rtDW.dpsi_1980 = 0.0;
  rtDW.deps_1980 = 0.0;
  for (rtDW.iter = 0; rtDW.iter < 30; rtDW.iter++) {
    rtDW.api = (((nc[30 + rtDW.iter] * rtDW.M_moon + nc[60 + rtDW.iter] *
                  rtDW.M_sun) + nc[90 + rtDW.iter] * rtDW.u_moon) + nc[120 +
                rtDW.iter] * rtDW.D_sun) + nc[150 + rtDW.iter] * rtDW.O_moon;
    rtDW.dpsi_1980 += (nc[210 + rtDW.iter] * rtDW.Sum1_m + nc[180 + rtDW.iter]) *
      0.0001 * sin(rtDW.api);
    rtDW.deps_1980 += (nc[270 + rtDW.iter] * rtDW.Sum1_m + nc[240 + rtDW.iter]) *
      0.0001 * cos(rtDW.api);
  }

  rtDW.M_sun = 4.84813681109536E-6 * rtDW.deps_1980 + rtDW.epsb_1980;
  rtDW.u_moon = 4.84813681109536E-6 * rtDW.dpsi_1980;
  rtDW.Gain_d[0] = 1.0;
  rtDW.tod_to_mod_tmp[0] = 0.0;
  rtDW.Gain_d[1] = 0.0;
  rtDW.tod_to_mod_tmp[1] = 0.0;
  rtDW.Gain_d[2] = 0.0;
  rtDW.tod_to_mod_tmp[2] = 1.0;
  rtDW.D_sun = ((rtDW.QOMS4 * 0.30188 + 2306.2181 * rtDW.Sum1_m) + 0.017998 *
                rtDW.w_o) * 4.84813681109536E-6;
  rtDW.M_moon = ((rtDW.QOMS4 * 1.09468 + 2306.2181 * rtDW.Sum1_m) + 0.018203 *
                 rtDW.w_o) * 4.84813681109536E-6;
  rtDW.Sum1_m = -(((2004.3109 * rtDW.Sum1_m - rtDW.QOMS4 * 0.42665) - 0.041833 *
                   rtDW.w_o) * 4.84813681109536E-6);
  rtDW.O_moon = ((rtDW.dpsi_1980 * cos(rtDW.epsb_1980) + 0.00264 * sin
                  (rtDW.O_moon)) + sin(2.0 * rtDW.O_moon) * 6.3E-5) *
    4.84813681109536E-6;
  rtDW.deps_1980 = ((3.1644001848128662E+9 * rtDW.eps + 67310.54841) + rtDW.eps *
                    rtDW.eps * 0.093104) - 6.2E-6 * rt_powd_snf_k(rtDW.eps, 3.0);
  if (rtDW.deps_1980 < 0.0) {
    rtDW.dpsi_1980 = -1.0;
  } else if (rtDW.deps_1980 > 0.0) {
    rtDW.dpsi_1980 = 1.0;
  } else if (rtDW.deps_1980 == 0.0) {
    rtDW.dpsi_1980 = 0.0;
  } else {
    rtDW.dpsi_1980 = (rtNaN);
  }

  rtDW.dpsi_1980 *= 86400.0;
  rtDW.QOMS4 = rtDW.deps_1980;
  if ((!rtIsInf(rtDW.deps_1980)) && (!rtIsNaN(rtDW.deps_1980)) && (!rtIsNaN
       (rtDW.dpsi_1980))) {
    if (rtDW.deps_1980 == 0.0) {
      rtDW.QOMS4 = rtDW.dpsi_1980 * 0.0;
    } else {
      if (rtDW.dpsi_1980 != 0.0) {
        rtDW.QOMS4 = fmod(rtDW.deps_1980, rtDW.dpsi_1980);
        if (rtDW.QOMS4 == 0.0) {
          rtDW.QOMS4 = rtDW.dpsi_1980 * 0.0;
        } else {
          if ((rtDW.deps_1980 < 0.0) != (rtDW.dpsi_1980 < 0.0)) {
            rtDW.QOMS4 += rtDW.dpsi_1980;
          }
        }
      }
    }
  } else {
    if (rtDW.dpsi_1980 != 0.0) {
      rtDW.QOMS4 = (rtNaN);
    }
  }

  rtDW.deps_1980 = rtDW.QOMS4 / 240.0;
  if ((!rtIsInf(rtDW.deps_1980)) && (!rtIsNaN(rtDW.deps_1980))) {
    if (rtDW.deps_1980 == 0.0) {
      rtDW.dpsi_1980 = 0.0;
    } else {
      rtDW.dpsi_1980 = fmod(rtDW.deps_1980, 360.0);
      if (rtDW.dpsi_1980 == 0.0) {
        rtDW.dpsi_1980 = 0.0;
      } else {
        if (rtDW.deps_1980 < 0.0) {
          rtDW.dpsi_1980 += 360.0;
        }
      }
    }
  } else {
    rtDW.dpsi_1980 = (rtNaN);
  }

  rtDW.dpsi_1980 = -(0.017453292519943295 * rtDW.dpsi_1980 + rtDW.O_moon);

  /* MATLAB Function: '<S290>/MATLAB Function' incorporates:
   *  Constant: '<S290>/JD_J2000'
   *  MATLAB Function: '<S292>/MATLAB Function3'
   *  Sum: '<S290>/Sum'
   */
  rtDW.QOMS4 = 1.88027916E-9;
  rtDW.api = 1.01222928;
  rtDW.flag_b1 = 0U;
  rtDW.deps_1980 = rtDW.orbit_tle[3] * 0.0174532925;
  rtDW.w_o = rtDW.orbit_tle[6] * 0.0174532925;
  rtDW.M_o = rtDW.orbit_tle[7] * 0.0174532925;
  rtDW.n_o = rtDW.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtDW.orbit_tle[5] >= 1.0) || (rtDW.orbit_tle[5] <= 0.0)) {
    rtDW.pos_teme_km[0] = 6378.137;
    rtDW.pos_teme_km[1] = 6378.137;
    rtDW.pos_teme_km[2] = 6878.137;
    rtDW.flag_b1 = 1U;
  } else if (rtDW.n_o == 0.0) {
    rtDW.pos_teme_km[0] = 6378.137;
    rtDW.pos_teme_km[1] = 6378.137;
    rtDW.pos_teme_km[2] = 6878.137;
    rtDW.flag_b1 = 2U;
  } else {
    rtDW.tsince_JD = (rtDW.tsince_JD - rtP.fswParams.constants.global.JDJ2000) -
      rtDW.orbit_tle[1];
    if (fabs(rtDW.tsince_JD) < 1.0E-8) {
      rtDW.tsince_JD = 0.0;
    } else {
      if (rtDW.tsince_JD < 0.0) {
        rtDW.tsince_JD = 0.0;
      }
    }

    rtDW.tsince = 1440.0 * rtDW.tsince_JD;
    rtDW.tsince_JD = rt_powd_snf_k(0.0743669161 / rtDW.n_o, 0.66666666666666663);
    rtDW.d_1_tmp = cos(rtDW.deps_1980);
    rtDW.d_M = 1.0 - rtDW.orbit_tle[5] * rtDW.orbit_tle[5];
    rtDW.d_1 = (rtDW.d_1_tmp * rtDW.d_1_tmp * 3.0 - 1.0) / rt_powd_snf_k
      (rtDW.d_M, 1.5) * (0.000541308 / (rtDW.tsince_JD * rtDW.tsince_JD) * 1.5);
    rtDW.tsince_JD *= ((1.0 - 0.33333333333333331 * rtDW.d_1) - rtDW.d_1 *
                       rtDW.d_1) - 1.654320987654321 * rt_powd_snf_k(rtDW.d_1,
      3.0);
    rtDW.d_1 = (rtDW.d_1_tmp * rtDW.d_1_tmp * 3.0 - 1.0) / rt_powd_snf_k(1.0 -
      rtDW.orbit_tle[5] * rtDW.orbit_tle[5], 1.5) * (0.000541308 /
      (rtDW.tsince_JD * rtDW.tsince_JD) * 1.5);
    rtDW.n_o /= 1.0 + rtDW.d_1;
    rtDW.a_o_pp = rtDW.tsince_JD / (1.0 - rtDW.d_1);
    rtDW.xi_g = (1.0 - rtDW.orbit_tle[5]) * rtDW.a_o_pp;
    rtDW.tsince_JD = (rtDW.xi_g - 1.0) * 6378.137;
    if (rtDW.xi_g < 1.0344928307435228) {
      rtDW.lowAlt = true;
      rtDW.flag_b1 = 3U;
    } else {
      rtDW.lowAlt = false;
    }

    if ((rtDW.tsince_JD >= 98.0) && (rtDW.tsince_JD <= 156.0)) {
      rtDW.api = (rtDW.xi_g - 1.01222928) + 1.0;
      rtDW.QOMS4 = rt_powd_snf_k(1.0188142770258546 - ((rtDW.xi_g - 1.01222928)
        + 1.0), 4.0);
    } else {
      if (rtDW.tsince_JD < 98.0) {
        rtDW.QOMS4 = 6.0426196528035638E-8;
        rtDW.api = 1.0031357118857749;
      }
    }

    rtDW.xi_g = 1.0 / (rtDW.a_o_pp - rtDW.api);
    rtDW.b_o = sqrt(rtDW.d_M);
    rtDW.eta = rtDW.a_o_pp * rtDW.orbit_tle[5] * rtDW.xi_g;
    if (rtDW.eta == 1.0) {
      rtDW.pos_teme_km[0] = 6378.137;
      rtDW.pos_teme_km[1] = 6378.137;
      rtDW.pos_teme_km[2] = 6878.137;
      rtDW.flag_b1 = 4U;
    } else {
      rtDW.d_w = rtDW.eta * rtDW.eta;
      rtDW.d_M = rt_powd_snf_k(rtDW.xi_g, 4.0);
      rtDW.C_1_tmp = rt_powd_snf_k(1.0 - rtDW.eta * rtDW.eta, -3.5);
      rtDW.C_1_tmp_tmp = rt_powd_snf_k(rtDW.eta, 3.0);
      rtDW.C_1_tmp_g = rtDW.orbit_tle[5] * rtDW.C_1_tmp_tmp;
      rtDW.C_1_tmp_p = rtDW.d_w * 1.5;
      rtDW.tsince_JD = ((((rtDW.C_1_tmp_p + 1.0) + 4.0 * rtDW.orbit_tle[5] *
                          rtDW.eta) + rtDW.C_1_tmp_g) * rtDW.a_o_pp +
                        (rtDW.d_1_tmp * rtDW.d_1_tmp * 1.5 + -0.5) *
                        (0.00081196200000000006 * rtDW.xi_g) * ((rtDW.d_w * 24.0
        + 8.0) + 3.0 * rt_powd_snf_k(rtDW.eta, 4.0)) / (1.0 - rtDW.d_w)) *
        (rtDW.QOMS4 * rtDW.d_M * rtDW.n_o * rtDW.C_1_tmp) * rtDW.orbit_tle[2];
      rtDW.C_5 = 0.0;
      rtDW.D_2 = 0.0;
      rtDW.D_3 = 0.0;
      rtDW.D_4 = 0.0;
      rtDW.IL3 = 0.0;
      rtDW.IL4 = 0.0;
      rtDW.IL5 = 0.0;
      if (!rtDW.lowAlt) {
        rtDW.C_5 = 2.0 * rtDW.QOMS4 * rtDW.d_M * rtDW.a_o_pp * (rtDW.b_o *
          rtDW.b_o) * rtDW.C_1_tmp * ((2.75 * rtDW.eta * (rtDW.eta +
          rtDW.orbit_tle[5]) + 1.0) + rtDW.C_1_tmp_g);
        rtDW.d_1 = rtDW.tsince_JD * rtDW.tsince_JD;
        rtDW.D_2 = 4.0 * rtDW.a_o_pp * rtDW.xi_g * rtDW.d_1;
        rtDW.IL4 = rt_powd_snf_k(rtDW.tsince_JD, 3.0);
        rtDW.D_3 = 1.3333333333333333 * rtDW.a_o_pp * (rtDW.xi_g * rtDW.xi_g) *
          (17.0 * rtDW.a_o_pp + rtDW.api) * rtDW.IL4;
        rtDW.M_DF = rt_powd_snf_k(rtDW.tsince_JD, 4.0);
        rtDW.D_4 = 0.66666666666666663 * rtDW.a_o_pp * rt_powd_snf_k(rtDW.xi_g,
          3.0) * (221.0 * rtDW.a_o_pp + 31.0 * rtDW.api) * rtDW.M_DF;
        rtDW.IL3 = rtDW.d_1 * 2.0 + rtDW.D_2;
        rtDW.IL4 = ((12.0 * rtDW.tsince_JD * rtDW.D_2 + 3.0 * rtDW.D_3) + 10.0 *
                    rtDW.IL4) * 0.25;
        rtDW.IL5 = ((((12.0 * rtDW.tsince_JD * rtDW.D_3 + 3.0 * rtDW.D_4) +
                      rtDW.D_2 * rtDW.D_2 * 6.0) + rtDW.d_1 * 30.0 * rtDW.D_2) +
                    15.0 * rtDW.M_DF) * 0.2;
      }

      rtDW.d_1 = rt_powd_snf_k(rtDW.d_1_tmp, 4.0);
      rtDW.M_DF_tmp_tmp = rt_powd_snf_k(rtDW.a_o_pp, 4.0);
      rtDW.M_DF_tmp = 16.0 * rtDW.M_DF_tmp_tmp;
      rtDW.api = rtDW.a_o_pp * rtDW.a_o_pp;
      rtDW.M_DF_tmp_m = rtDW.api * 2.0 * rt_powd_snf_k(rtDW.b_o, 3.0);
      rtDW.M_DF = (((rtDW.d_1_tmp * rtDW.d_1_tmp * 3.0 - 1.0) *
                    0.0016239240000000001 / rtDW.M_DF_tmp_m + 1.0) + ((13.0 -
        rtDW.d_1_tmp * rtDW.d_1_tmp * 78.0) + 137.0 * rtDW.d_1) *
                   8.7904305259200008E-7 / (rtDW.M_DF_tmp * rt_powd_snf_k
        (rtDW.b_o, 7.0))) * rtDW.n_o * rtDW.tsince + rtDW.M_o;
      rtDW.d_1_tmp_n = rt_powd_snf_k(rtDW.b_o, 8.0);
      rtDW.d_1 = ((((7.0 - rtDW.d_1_tmp * rtDW.d_1_tmp * 114.0) + 395.0 *
                    rtDW.d_1) * 8.7904305259200008E-7 / (rtDW.M_DF_tmp *
        rtDW.d_1_tmp_n) + (1.0 - rtDW.d_1_tmp * rtDW.d_1_tmp * 5.0) *
                   -0.0016239240000000001 / rtDW.M_DF_tmp_m) + ((3.0 -
        rtDW.d_1_tmp * rtDW.d_1_tmp * 36.0) + 49.0 * rtDW.d_1) *
                  3.1049437500000002E-6 / (4.0 * rtDW.M_DF_tmp_tmp *
        rtDW.d_1_tmp_n)) * rtDW.n_o * rtDW.tsince + rtDW.w_o;
      rtDW.M_DF_tmp = 2.0 * rtDW.M_DF_tmp_tmp * rtDW.d_1_tmp_n;
      rtDW.d_1_tmp_n = rtDW.tsince * rtDW.tsince;
      rtDW.M_DF_tmp_tmp = rtDW.d_1_tmp * rtDW.d_1_tmp * 7.0;
      rtDW.api = ((((4.0 * rtDW.d_1_tmp - 19.0 * rt_powd_snf_k(rtDW.d_1_tmp, 3.0))
                    * 8.7904305259200008E-7 / rtDW.M_DF_tmp +
                    -0.0016239240000000001 * rtDW.d_1_tmp / (rtDW.api *
        rt_powd_snf_k(rtDW.b_o, 4.0))) + (3.0 - rtDW.M_DF_tmp_tmp) *
                   (3.1049437500000002E-6 * rtDW.d_1_tmp) / rtDW.M_DF_tmp) *
                  rtDW.n_o * rtDW.tsince + rtDW.orbit_tle[4] * 0.0174532925) -
        rtDW.n_o * 0.000541308 * rtDW.d_1_tmp / (rtDW.api * (rtDW.b_o * rtDW.b_o))
        * 10.5 * rtDW.tsince_JD * rtDW.d_1_tmp_n;
      if (!rtDW.lowAlt) {
        rtDW.d_w = rtDW.QOMS4 * rt_powd_snf_k(rtDW.xi_g, 5.0) * 2.538815E-6 *
          rtDW.n_o * sin(rtDW.deps_1980) / (0.000541308 * rtDW.orbit_tle[5]) *
          rtDW.orbit_tle[2] * cos(rtDW.w_o) * rtDW.tsince;
        rtDW.d_M = -0.66666666666666663 * rtDW.QOMS4 * rtDW.orbit_tle[2] *
          rtDW.d_M * (1.0 / (rtDW.orbit_tle[5] * rtDW.eta)) * (rt_powd_snf_k
          (rtDW.eta * cos(rtDW.M_DF) + 1.0, 3.0) - rt_powd_snf_k(rtDW.eta * cos
          (rtDW.M_o) + 1.0, 3.0));
        rtDW.M_DF = (rtDW.M_DF + rtDW.d_w) + rtDW.d_M;
        rtDW.d_1 = (rtDW.d_1 - rtDW.d_w) - rtDW.d_M;
        rtDW.QOMS4 = (rtDW.orbit_tle[5] - ((((rtDW.orbit_tle[5] * rtDW.eta + 1.0)
          * (2.0 * rtDW.eta) + 0.5 * rtDW.orbit_tle[5]) + 0.5 * rt_powd_snf_k
          (rtDW.eta, 3.0)) - ((((1.0 - rtDW.eta * rtDW.eta * 1.5) - 2.0 *
          rtDW.orbit_tle[5] * rtDW.eta) - 0.5 * rtDW.orbit_tle[5] *
          rt_powd_snf_k(rtDW.eta, 3.0)) * ((1.0 - rtDW.d_1_tmp * rtDW.d_1_tmp *
          3.0) * 3.0) + ((rtDW.eta * rtDW.eta * 2.0 - rtDW.orbit_tle[5] *
                          rtDW.eta) - rtDW.orbit_tle[5] * rt_powd_snf_k(rtDW.eta,
          3.0)) * ((1.0 - rtDW.d_1_tmp * rtDW.d_1_tmp) * 0.75) * cos(2.0 *
          rtDW.w_o)) * (0.001082616 * rtDW.xi_g / ((1.0 - rtDW.eta * rtDW.eta) *
          rtDW.a_o_pp))) * (2.0 * rtDW.n_o * rtDW.QOMS4 * rt_powd_snf_k
                            (rtDW.xi_g, 4.0) * rtDW.a_o_pp * (rtDW.b_o *
          rtDW.b_o) * rtDW.C_1_tmp) * rtDW.orbit_tle[2] * rtDW.tsince) -
          rtDW.orbit_tle[2] * rtDW.C_5 * (sin(rtDW.M_DF) - sin(rtDW.M_o));
        rtDW.xi_g = rt_powd_snf_k(rtDW.tsince, 3.0);
        rtDW.d_M = rt_powd_snf_k(rtDW.tsince, 4.0);
        rtDW.w_o = (((1.0 - rtDW.tsince_JD * rtDW.tsince) - rtDW.d_1_tmp_n *
                     rtDW.D_2) - rtDW.D_3 * rtDW.xi_g) - rtDW.D_4 * rtDW.d_M;
        rtDW.M_o = rtDW.w_o * rtDW.w_o * rtDW.a_o_pp;
        rtDW.a_o_pp = (((1.5 * rtDW.tsince_JD * rtDW.d_1_tmp_n + rtDW.IL3 *
                         rtDW.xi_g) + rtDW.IL4 * rtDW.d_M) + rtDW.IL5 *
                       rt_powd_snf_k(rtDW.tsince, 5.0)) * rtDW.n_o + ((rtDW.M_DF
          + rtDW.d_1) + rtDW.api);
      } else {
        rtDW.M_o = 1.0 - rtDW.tsince_JD * rtDW.tsince;
        rtDW.M_o = rtDW.M_o * rtDW.M_o * rtDW.a_o_pp;
        rtDW.D_2 = rtDW.orbit_tle[5] * rtDW.eta;
        rtDW.QOMS4 = rtDW.orbit_tle[5] - ((((rtDW.D_2 + 1.0) * (2.0 * rtDW.eta)
          + 0.5 * rtDW.orbit_tle[5]) + 0.5 * rtDW.C_1_tmp_tmp) - ((((1.0 -
          rtDW.C_1_tmp_p) - 2.0 * rtDW.orbit_tle[5] * rtDW.eta) - 0.5 *
          rtDW.orbit_tle[5] * rtDW.C_1_tmp_tmp) * ((1.0 - rtDW.d_1_tmp *
          rtDW.d_1_tmp * 3.0) * 3.0) + ((rtDW.d_w * 2.0 - rtDW.D_2) -
          rtDW.C_1_tmp_g) * ((1.0 - rtDW.d_1_tmp * rtDW.d_1_tmp) * 0.75) * cos
          (2.0 * rtDW.w_o)) * (0.001082616 * rtDW.xi_g / ((1.0 - rtDW.eta *
          rtDW.eta) * rtDW.a_o_pp))) * (2.0 * rtDW.n_o * rtDW.QOMS4 * rtDW.d_M *
          rtDW.a_o_pp * (rtDW.b_o * rtDW.b_o) * rtDW.C_1_tmp) * rtDW.orbit_tle[2]
          * rtDW.tsince;
        rtDW.a_o_pp = 1.5 * rtDW.tsince_JD * rtDW.n_o * rtDW.d_1_tmp_n +
          ((rtDW.M_DF + rtDW.d_1) + rtDW.api);
      }

      if ((rtDW.M_o == 0.0) || (rtDW.QOMS4 >= 1.0)) {
        rtDW.pos_teme_km[0] = 6378.137;
        rtDW.pos_teme_km[1] = 6378.137;
        rtDW.pos_teme_km[2] = 6878.137;
        rtDW.flag_b1 = 5U;
      } else {
        rtDW.n_o = sqrt(1.0 - rtDW.QOMS4 * rtDW.QOMS4);
        rtDW.xi_g = cos(rtDW.d_1);
        rtDW.w_o = rtDW.QOMS4 * rtDW.xi_g;
        rtDW.n_o *= rtDW.n_o;
        rtDW.tsince_JD = 2.538815E-6 * sin(rtDW.deps_1980);
        rtDW.tsince = rtDW.tsince_JD / (0.002165232 * rtDW.M_o * rtDW.n_o) +
          rtDW.QOMS4 * sin(rtDW.d_1);
        rtDW.n_o = (rtDW.tsince_JD / (0.004330464 * rtDW.M_o * rtDW.n_o) *
                    rtDW.QOMS4 * rtDW.xi_g * ((5.0 * rtDW.d_1_tmp + 3.0) / (1.0
          + rtDW.d_1_tmp)) + rtDW.a_o_pp) - rtDW.api;
        if ((!rtIsInf(rtDW.n_o)) && (!rtIsNaN(rtDW.n_o))) {
          if (rtDW.n_o == 0.0) {
            rtDW.QOMS4 = 0.0;
          } else {
            rtDW.QOMS4 = fmod(rtDW.n_o, 6.2831853071795862);
            rtDW.lowAlt = (rtDW.QOMS4 == 0.0);
            if (!rtDW.lowAlt) {
              rtDW.d_1 = fabs(rtDW.n_o / 6.2831853071795862);
              rtDW.lowAlt = (fabs(rtDW.d_1 - floor(rtDW.d_1 + 0.5)) <=
                             2.2204460492503131E-16 * rtDW.d_1);
            }

            if (rtDW.lowAlt) {
              rtDW.QOMS4 = 0.0;
            } else {
              if (rtDW.n_o < 0.0) {
                rtDW.QOMS4 += 6.2831853071795862;
              }
            }
          }
        } else {
          rtDW.QOMS4 = (rtNaN);
        }

        rtDW.n_o = rtDW.QOMS4;
        rtDW.d_1 = 0.0;
        rtDW.iter = 0;
        while ((fabs(rtDW.n_o - rtDW.d_1) > 1.0E-8) && (rtDW.iter < 10)) {
          rtDW.n_o = rtDW.d_1;
          rtDW.d_1 += (((rtDW.QOMS4 - rtDW.tsince * cos(rtDW.d_1)) + rtDW.w_o *
                        sin(rtDW.d_1)) - rtDW.d_1) / ((-rtDW.tsince * sin
            (rtDW.d_1) - rtDW.w_o * cos(rtDW.d_1)) + 1.0);
          rtDW.iter++;
        }

        rtDW.d_w = cos(rtDW.d_1);
        rtDW.d_M = sin(rtDW.d_1);
        rtDW.tsince_JD = rtDW.w_o * rtDW.d_M - rtDW.tsince * rtDW.d_w;
        rtDW.a_o_pp = sqrt(rtDW.w_o * rtDW.w_o + rtDW.tsince * rtDW.tsince);
        rtDW.a_o_pp = 1.0 - rtDW.a_o_pp * rtDW.a_o_pp;
        rtDW.n_o = rtDW.a_o_pp * rtDW.M_o;
        rtDW.QOMS4 = (1.0 - (rtDW.w_o * rtDW.d_w + rtDW.tsince * rtDW.d_M)) *
          rtDW.M_o;
        if ((rtDW.QOMS4 == 0.0) || (rtDW.n_o == 0.0)) {
          rtDW.pos_teme_km[0] = 6378.137;
          rtDW.pos_teme_km[1] = 6378.137;
          rtDW.pos_teme_km[2] = 6878.137;
          rtDW.flag_b1 = 6U;
        } else {
          rtDW.a_o_pp = sqrt(rtDW.a_o_pp);
          rtDW.xi_g = rtDW.M_o / rtDW.QOMS4;
          rtDW.w_o = rt_atan2d_snf_k(((rtDW.d_M - rtDW.tsince) - rtDW.w_o *
            rtDW.tsince_JD / (rtDW.a_o_pp + 1.0)) * rtDW.xi_g, (rtDW.tsince *
            rtDW.tsince_JD / (rtDW.a_o_pp + 1.0) + (rtDW.d_w - rtDW.w_o)) *
            rtDW.xi_g);
          rtDW.D_2 = rtDW.n_o * rtDW.n_o;
          rtDW.M_o = cos(2.0 * rtDW.w_o);
          rtDW.QOMS4 = (1.0 - rtDW.a_o_pp * 0.00081196200000000006 *
                        (rtDW.d_1_tmp * rtDW.d_1_tmp * 3.0 - 1.0) / rtDW.D_2) *
            rtDW.QOMS4 + 0.000541308 / (2.0 * rtDW.n_o) * (1.0 - rtDW.d_1_tmp *
            rtDW.d_1_tmp) * rtDW.M_o;
          rtDW.n_o = sin(2.0 * rtDW.w_o);
          rtDW.tsince = -(0.000541308 / (rtDW.D_2 * 4.0)) * (rtDW.M_DF_tmp_tmp -
            1.0) * rtDW.n_o + rtDW.w_o;
          rtDW.M_DF_tmp = 0.0016239240000000001 * rtDW.d_1_tmp / (rtDW.D_2 * 2.0);
          rtDW.api += rtDW.M_DF_tmp * rtDW.n_o;
          rtDW.deps_1980 += rtDW.M_DF_tmp * sin(rtDW.deps_1980) * rtDW.M_o;
          rtDW.tsince_JD = sin(rtDW.tsince);
          rtDW.w_o = cos(rtDW.tsince);
          rtDW.n_o = cos(rtDW.api);
          rtDW.tsince = cos(rtDW.deps_1980);
          rtDW.d_1_tmp = sin(rtDW.api);
          rtDW.pos_teme_km[0] = (-rtDW.d_1_tmp * rtDW.tsince * rtDW.tsince_JD +
            rtDW.n_o * rtDW.w_o) * rtDW.QOMS4 * 6378.137;
          rtDW.pos_teme_km[1] = (rtDW.n_o * rtDW.tsince * rtDW.tsince_JD +
            rtDW.d_1_tmp * rtDW.w_o) * rtDW.QOMS4 * 6378.137;
          rtDW.pos_teme_km[2] = (sin(rtDW.deps_1980) * rtDW.tsince_JD + 0.0 *
            rtDW.w_o) * rtDW.QOMS4 * 6378.137;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S290>/MATLAB Function' */

  /* MATLAB Function: '<S380>/MATLAB Function' */
  rtDW.QOMS4 = cos(rtDW.D_sun);
  rtDW.rtb_Gain_d_tmp_f[0] = rtDW.QOMS4;
  rtDW.deps_1980 = sin(rtDW.D_sun);
  rtDW.rtb_Gain_d_tmp_f[3] = rtDW.deps_1980;
  rtDW.rtb_Gain_d_tmp_f[6] = 0.0;
  rtDW.rtb_Gain_d_tmp_f[1] = -rtDW.deps_1980;
  rtDW.rtb_Gain_d_tmp_f[4] = rtDW.QOMS4;
  rtDW.rtb_Gain_d_tmp_f[7] = 0.0;
  rtDW.QOMS4 = cos(rtDW.Sum1_m);
  rtDW.rtb_Gain_d_p[0] = rtDW.QOMS4;
  rtDW.rtb_Gain_d_p[3] = 0.0;
  rtDW.deps_1980 = sin(rtDW.Sum1_m);
  rtDW.rtb_Gain_d_p[6] = -rtDW.deps_1980;
  rtDW.rtb_Gain_d_tmp_f[2] = 0.0;
  rtDW.rtb_Gain_d_p[1] = 0.0;
  rtDW.rtb_Gain_d_tmp_f[5] = 0.0;
  rtDW.rtb_Gain_d_p[4] = 1.0;
  rtDW.rtb_Gain_d_tmp_f[8] = 1.0;
  rtDW.rtb_Gain_d_p[7] = 0.0;
  rtDW.rtb_Gain_d_p[2] = rtDW.deps_1980;
  rtDW.rtb_Gain_d_p[5] = 0.0;
  rtDW.rtb_Gain_d_p[8] = rtDW.QOMS4;
  rtDW.QOMS4 = cos(rtDW.M_moon);
  rtDW.dv1_k[0] = rtDW.QOMS4;
  rtDW.deps_1980 = sin(rtDW.M_moon);
  rtDW.dv1_k[3] = rtDW.deps_1980;
  rtDW.dv1_k[6] = 0.0;
  rtDW.dv1_k[1] = -rtDW.deps_1980;
  rtDW.dv1_k[4] = rtDW.QOMS4;
  rtDW.dv1_k[7] = 0.0;
  rtDW.rtb_Gain_d_c[1] = 0.0;
  rtDW.Sum1_m = cos(-rtDW.epsb_1980);
  rtDW.rtb_Gain_d_c[4] = rtDW.Sum1_m;
  rtDW.epsb_1980 = sin(-rtDW.epsb_1980);
  rtDW.rtb_Gain_d_c[7] = rtDW.epsb_1980;
  rtDW.rtb_Gain_d_c[2] = 0.0;
  rtDW.rtb_Gain_d_c[5] = -rtDW.epsb_1980;
  rtDW.rtb_Gain_d_c[8] = rtDW.Sum1_m;
  rtDW.QOMS4 = cos(rtDW.u_moon);
  rtDW.dv2_b[0] = rtDW.QOMS4;
  rtDW.deps_1980 = sin(rtDW.u_moon);
  rtDW.dv2_b[3] = rtDW.deps_1980;
  rtDW.dv2_b[6] = 0.0;
  rtDW.dv2_b[1] = -rtDW.deps_1980;
  rtDW.dv2_b[4] = rtDW.QOMS4;
  rtDW.dv2_b[7] = 0.0;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      rtDW.rtb_Gain_d_tmp_l = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.dv0_c[rtDW.rtb_Gain_d_tmp_l] = 0.0;
      rtDW.iter = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.dv0_c[rtDW.rtb_Gain_d_tmp_l] = rtDW.dv0_c[rtDW.iter] +
        rtDW.rtb_Gain_d_p[3 * rtDW.deps_1980_tmp] *
        rtDW.rtb_Gain_d_tmp_f[rtDW.i_d];
      rtDW.dv0_c[rtDW.rtb_Gain_d_tmp_l] = rtDW.rtb_Gain_d_p[3 *
        rtDW.deps_1980_tmp + 1] * rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] +
        rtDW.dv0_c[rtDW.iter];
      rtDW.dv0_c[rtDW.rtb_Gain_d_tmp_l] = rtDW.rtb_Gain_d_p[3 *
        rtDW.deps_1980_tmp + 2] * rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] +
        rtDW.dv0_c[rtDW.iter];
    }

    rtDW.deps_1980_tmp = 2 + 3 * rtDW.i_d;
    rtDW.dv1_k[rtDW.deps_1980_tmp] = rtDW.tod_to_mod_tmp[rtDW.i_d];
    rtDW.rtb_Gain_d_c[3 * rtDW.i_d] = rtDW.Gain_d[rtDW.i_d];
    rtDW.dv2_b[rtDW.deps_1980_tmp] = rtDW.tod_to_mod_tmp[rtDW.i_d];
  }

  rtDW.rtb_Gain_d_cv[1] = 0.0;
  rtDW.Sum1_m = cos(rtDW.M_sun);
  rtDW.rtb_Gain_d_cv[4] = rtDW.Sum1_m;
  rtDW.epsb_1980 = sin(rtDW.M_sun);
  rtDW.rtb_Gain_d_cv[7] = rtDW.epsb_1980;
  rtDW.rtb_Gain_d_cv[2] = 0.0;
  rtDW.rtb_Gain_d_cv[5] = -rtDW.epsb_1980;
  rtDW.rtb_Gain_d_cv[8] = rtDW.Sum1_m;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.rtb_Gain_d_cv[3 * rtDW.i_d] = rtDW.Gain_d[rtDW.i_d];
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      rtDW.iter = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.rtb_Gain_d_p[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.rtb_Gain_d_p[rtDW.iter] = rtDW.rtb_Gain_d_p[rtDW.rtb_Gain_d_tmp_l] +
        rtDW.dv2_b[3 * rtDW.deps_1980_tmp] * rtDW.rtb_Gain_d_c[rtDW.i_d];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] =
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l] + rtDW.dv1_k[3 *
        rtDW.deps_1980_tmp] * rtDW.dv0_c[rtDW.i_d];
      rtDW.rtb_Gain_d_tmp_o = 3 * rtDW.deps_1980_tmp + 1;
      rtDW.rtb_Gain_d_p[rtDW.iter] = rtDW.dv2_b[rtDW.rtb_Gain_d_tmp_o] *
        rtDW.rtb_Gain_d_c[rtDW.i_d + 3] +
        rtDW.rtb_Gain_d_p[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.dv1_k[rtDW.rtb_Gain_d_tmp_o] *
        rtDW.dv0_c[rtDW.i_d + 3] + rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp_o = 3 * rtDW.deps_1980_tmp + 2;
      rtDW.rtb_Gain_d_p[rtDW.iter] = rtDW.dv2_b[rtDW.rtb_Gain_d_tmp_o] *
        rtDW.rtb_Gain_d_c[rtDW.i_d + 6] +
        rtDW.rtb_Gain_d_p[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.dv1_k[rtDW.rtb_Gain_d_tmp_o] *
        rtDW.dv0_c[rtDW.i_d + 6] + rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];
    }
  }

  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      rtDW.iter = rtDW.deps_1980_tmp + 3 * rtDW.i_d;
      rtDW.rtb_Gain_d_c[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.i_d + rtDW.deps_1980_tmp;
      rtDW.rtb_Gain_d_c[rtDW.iter] = rtDW.rtb_Gain_d_c[rtDW.rtb_Gain_d_tmp_l] +
        rtDW.rtb_Gain_d_cv[3 * rtDW.i_d] * rtDW.rtb_Gain_d_p[rtDW.deps_1980_tmp];
      rtDW.rtb_Gain_d_c[rtDW.iter] = rtDW.rtb_Gain_d_cv[3 * rtDW.i_d + 1] *
        rtDW.rtb_Gain_d_p[rtDW.deps_1980_tmp + 3] +
        rtDW.rtb_Gain_d_c[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_c[rtDW.iter] = rtDW.rtb_Gain_d_cv[3 * rtDW.i_d + 2] *
        rtDW.rtb_Gain_d_p[rtDW.deps_1980_tmp + 6] +
        rtDW.rtb_Gain_d_c[rtDW.rtb_Gain_d_tmp_l];
    }
  }

  rtDW.QOMS4 = cos(-rtDW.O_moon);
  rtDW.rtb_Gain_d_p[0] = rtDW.QOMS4;
  rtDW.deps_1980 = sin(-rtDW.O_moon);
  rtDW.rtb_Gain_d_p[3] = rtDW.deps_1980;
  rtDW.rtb_Gain_d_p[6] = 0.0;
  rtDW.rtb_Gain_d_p[1] = -rtDW.deps_1980;
  rtDW.rtb_Gain_d_p[4] = rtDW.QOMS4;
  rtDW.rtb_Gain_d_p[7] = 0.0;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      rtDW.iter = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.rtb_Gain_d_tmp[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.rtb_Gain_d_tmp[rtDW.iter] = rtDW.rtb_Gain_d_tmp[rtDW.rtb_Gain_d_tmp_l]
        + rtDW.rtb_Gain_d_c[3 * rtDW.deps_1980_tmp] *
        rtDW.rtb_Gain_d_tmp_f[rtDW.i_d];
      rtDW.rtb_Gain_d_tmp[rtDW.iter] = rtDW.rtb_Gain_d_c[3 * rtDW.deps_1980_tmp
        + 1] * rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] +
        rtDW.rtb_Gain_d_tmp[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp[rtDW.iter] = rtDW.rtb_Gain_d_c[3 * rtDW.deps_1980_tmp
        + 2] * rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] +
        rtDW.rtb_Gain_d_tmp[rtDW.rtb_Gain_d_tmp_l];
    }

    rtDW.rtb_Gain_d_p[2 + 3 * rtDW.i_d] = rtDW.tod_to_mod_tmp[rtDW.i_d];
  }

  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    /* Product: '<S290>/Product' */
    rtDW.MathFunction_i[rtDW.i_d] = 0.0;
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      rtDW.iter = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] =
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l] + rtDW.rtb_Gain_d_p[3 *
        rtDW.deps_1980_tmp] * rtDW.rtb_Gain_d_tmp[rtDW.i_d];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.rtb_Gain_d_p[3 *
        rtDW.deps_1980_tmp + 1] * rtDW.rtb_Gain_d_tmp[rtDW.i_d + 3] +
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.rtb_Gain_d_p[3 *
        rtDW.deps_1980_tmp + 2] * rtDW.rtb_Gain_d_tmp[rtDW.i_d + 6] +
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];
      rtDW.MathFunction_i[rtDW.i_d] +=
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l] *
        rtDW.pos_teme_km[rtDW.deps_1980_tmp];
    }

    /* End of Product: '<S290>/Product' */

    /* Gain: '<S290>/Gain' */
    rtDW.Gain_d[rtDW.i_d] = rtP.Gain_Gain_ac * rtDW.MathFunction_i[rtDW.i_d];
  }

  /* MATLAB Function: '<S291>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S292>/MATLAB Function3'
   */
  rtDW.M_moon = mod_49nNZZ0V_p((35999.05034 * rtDW.eps + 357.5277233) *
    0.017453292519943295);
  rtDW.epsb_1980 = (mod_49nNZZ0V_p((36000.77 * rtDW.eps + 280.46) *
    0.017453292519943295) + 0.033417233996490527 * sin(rtDW.M_moon)) + sin(2.0 *
    rtDW.M_moon) * 0.00034897235311083654;
  rtDW.eps = (23.439291 - 0.0130042 * rtDW.eps) * 0.017453292519943295;
  rtDW.QOMS4 = (1.000140612 - 0.016708617 * cos(rtDW.M_moon)) - cos(2.0 *
    rtDW.M_moon) * 0.000139589;
  rtDW.u_moon = rtDW.QOMS4 * cos(rtDW.epsb_1980);
  rtDW.Sum1_m = sin(rtDW.epsb_1980);
  rtDW.epsb_1980 = cos(rtDW.eps) * rtDW.Sum1_m * rtDW.QOMS4;
  rtDW.M_moon = sin(rtDW.eps) * rtDW.Sum1_m * rtDW.QOMS4;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    /* Gain: '<S6>/M2KM' */
    rtDW.eps = rtP.fswParams.constants.convert.M2KM * rtDW.Gain_d[rtDW.i_d];

    /* Gain: '<S291>/AU2KM' incorporates:
     *  MATLAB Function: '<S380>/MATLAB Function'
     *  Product: '<S291>/Product'
     */
    rtDW.Sum1_m = rtP.fswParams.constants.convert.AU2KM *
      (rtDW.rtb_Gain_d_tmp[rtDW.i_d + 6] * rtDW.M_moon +
       (rtDW.rtb_Gain_d_tmp[rtDW.i_d + 3] * rtDW.epsb_1980 +
        rtDW.rtb_Gain_d_tmp[rtDW.i_d] * rtDW.u_moon));

    /* Sum: '<S291>/Subtract' */
    rtDW.M_sun = rtDW.Sum1_m - rtDW.eps;

    /* Math: '<S376>/Math Function' */
    rtDW.MathFunction_i[rtDW.i_d] = rtDW.M_sun * rtDW.M_sun;

    /* Gain: '<S6>/M2KM' */
    rtDW.pos_teme_km[rtDW.i_d] = rtDW.eps;

    /* Gain: '<S291>/AU2KM' */
    rtDW.AU2KM[rtDW.i_d] = rtDW.Sum1_m;

    /* Sum: '<S291>/Subtract' */
    rtDW.Subtract_a[rtDW.i_d] = rtDW.M_sun;
  }

  /* Sum: '<S376>/Sum of Elements' */
  rtDW.tsince = (rtDW.MathFunction_i[0] + rtDW.MathFunction_i[1]) +
    rtDW.MathFunction_i[2];

  /* Math: '<S376>/Math Function1'
   *
   * About '<S376>/Math Function1':
   *  Operator: sqrt
   */
  if (rtDW.tsince < 0.0) {
    rtDW.tsince = -sqrt(fabs(rtDW.tsince));
  } else {
    rtDW.tsince = sqrt(rtDW.tsince);
  }

  /* End of Math: '<S376>/Math Function1' */

  /* Switch: '<S376>/Switch' incorporates:
   *  Constant: '<S376>/Constant'
   *  Product: '<S376>/Product'
   */
  if (rtDW.tsince > rtP.NormalizeVector_maxzero_g) {
    rtDW.Switch_g[0] = rtDW.Subtract_a[0];
    rtDW.Switch_g[1] = rtDW.Subtract_a[1];
    rtDW.Switch_g[2] = rtDW.Subtract_a[2];
    rtDW.Switch_g[3] = rtDW.tsince;
  } else {
    rtDW.Switch_g[0] = rtDW.Subtract_a[0] * 0.0;
    rtDW.Switch_g[1] = rtDW.Subtract_a[1] * 0.0;
    rtDW.Switch_g[2] = rtDW.Subtract_a[2] * 0.0;
    rtDW.Switch_g[3] = rtP.Constant_Value_o;
  }

  /* End of Switch: '<S376>/Switch' */

  /* Product: '<S376>/Divide' */
  rtDW.Divide_a[0] = rtDW.Switch_g[0] / rtDW.Switch_g[3];
  rtDW.Divide_a[1] = rtDW.Switch_g[1] / rtDW.Switch_g[3];
  rtDW.Divide_a[2] = rtDW.Switch_g[2] / rtDW.Switch_g[3];

  /* If: '<S108>/If' */
  if (rtDW.RateTransition5) {
    /* Outputs for IfAction SubSystem: '<S108>/sunSensorIsValid' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    /* Abs: '<S111>/Abs' */
    rtDW.epsb_1980 = fabs(rtDW.RateTransition2[0]);

    /* Relay: '<S111>/Relay' */
    if (rtDW.epsb_1980 >= rtP.fswParams.sensors.sun_sensor_range_deg) {
      rtDW.Relay_Mode[0] = true;
    } else {
      if (rtDW.epsb_1980 <= rtP.fswParams.sensors.sunseek_hysteresis_deg) {
        rtDW.Relay_Mode[0] = false;
      }
    }

    /* Abs: '<S111>/Abs' */
    rtDW.epsb_1980 = fabs(rtDW.RateTransition2[1]);

    /* Relay: '<S111>/Relay' */
    if (rtDW.epsb_1980 >= rtP.fswParams.sensors.sun_sensor_range_deg) {
      rtDW.Relay_Mode[1] = true;
    } else {
      if (rtDW.epsb_1980 <= rtP.fswParams.sensors.sunseek_hysteresis_deg) {
        rtDW.Relay_Mode[1] = false;
      }
    }

    if (rtDW.Relay_Mode[0]) {
      rtDW.lowAlt = rtP.Relay_YOn;
    } else {
      rtDW.lowAlt = rtP.Relay_YOff;
    }

    if (rtDW.Relay_Mode[1]) {
      rtDW.light = rtP.Relay_YOn;
    } else {
      rtDW.light = rtP.Relay_YOff;
    }

    /* Sum: '<S111>/Sum' incorporates:
     *  Constant: '<S112>/Lower Limit'
     *  Constant: '<S112>/Upper Limit'
     *  Constant: '<S113>/Lower Limit'
     *  Constant: '<S113>/Upper Limit'
     *  Logic: '<S111>/AND'
     *  Logic: '<S111>/AND1'
     *  Logic: '<S112>/AND'
     *  Logic: '<S113>/AND'
     *  RelationalOperator: '<S112>/Lower Test'
     *  RelationalOperator: '<S112>/Upper Test'
     *  RelationalOperator: '<S113>/Lower Test'
     *  RelationalOperator: '<S113>/Upper Test'
     */
    rtDW.Merge_b = (uint8_T)((uint32_T)
      ((-rtP.fswParams.sensors.sun_sensor_range_deg <= rtDW.RateTransition2[0]) &&
       (rtDW.RateTransition2[0] <= rtP.fswParams.sensors.sun_sensor_range_deg) &&
       ((-rtP.fswParams.sensors.sun_sensor_range_deg <= rtDW.RateTransition2[1])
        && (rtDW.RateTransition2[1] <=
            rtP.fswParams.sensors.sun_sensor_range_deg))) + (rtDW.lowAlt &&
      rtDW.light));

    /* End of Outputs for SubSystem: '<S108>/sunSensorIsValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/sunSensorIsNotValid' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    /* SignalConversion: '<S110>/OutportBuffer_InsertedFor_ss_valid_false_at_inport_0' incorporates:
     *  Constant: '<S110>/Constant'
     */
    rtDW.Merge_b = rtP.Constant_Value_gq;

    /* End of Outputs for SubSystem: '<S108>/sunSensorIsNotValid' */
  }

  /* End of If: '<S108>/If' */

  /* MATLAB Function: '<S380>/MATLAB Function' incorporates:
   *  Product: '<S289>/MatrixMultiply'
   */
  rtDW.QOMS4 = cos(rtDW.dpsi_1980);
  rtDW.rtb_Gain_d_tmp_f[0] = rtDW.QOMS4;
  rtDW.deps_1980 = sin(rtDW.dpsi_1980);
  rtDW.rtb_Gain_d_tmp_f[3] = rtDW.deps_1980;
  rtDW.rtb_Gain_d_tmp_f[6] = 0.0;
  rtDW.rtb_Gain_d_tmp_f[1] = -rtDW.deps_1980;
  rtDW.rtb_Gain_d_tmp_f[4] = rtDW.QOMS4;
  rtDW.rtb_Gain_d_tmp_f[7] = 0.0;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.rtb_Gain_d_tmp_f[2 + 3 * rtDW.i_d] = rtDW.tod_to_mod_tmp[rtDW.i_d];

    /* Product: '<S289>/MatrixMultiply' incorporates:
     *  Product: '<S288>/Product3'
     */
    rtDW.tod_to_mod_tmp[rtDW.i_d] = 0.0;
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      /* Math: '<S292>/Transpose' incorporates:
       *  Product: '<S289>/MatrixMultiply'
       */
      rtDW.iter = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.Transpose[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.Transpose[rtDW.iter] = rtDW.Transpose[rtDW.rtb_Gain_d_tmp_l] +
        rtDW.rtb_Gain_d_tmp_f[3 * rtDW.i_d] *
        rtDW.rtb_Gain_d_tmp[rtDW.deps_1980_tmp];
      rtDW.Transpose[rtDW.iter] = rtDW.rtb_Gain_d_tmp_f[3 * rtDW.i_d + 1] *
        rtDW.rtb_Gain_d_tmp[rtDW.deps_1980_tmp + 3] +
        rtDW.Transpose[rtDW.rtb_Gain_d_tmp_l];
      rtDW.Transpose[rtDW.iter] = rtDW.rtb_Gain_d_tmp_f[3 * rtDW.i_d + 2] *
        rtDW.rtb_Gain_d_tmp[rtDW.deps_1980_tmp + 6] +
        rtDW.Transpose[rtDW.rtb_Gain_d_tmp_l];
      rtDW.tod_to_mod_tmp[rtDW.i_d] += rtDW.Transpose[rtDW.rtb_Gain_d_tmp_l] *
        rtDW.Gain_d[rtDW.deps_1980_tmp];
    }
  }

  /* Sqrt: '<S364>/sqrt' incorporates:
   *  Product: '<S289>/MatrixMultiply'
   *  Product: '<S364>/Product2'
   *  Product: '<S364>/Product3'
   *  Sum: '<S364>/Sum2'
   */
  rtDW.M_moon = sqrt(rtDW.tod_to_mod_tmp[0] * rtDW.tod_to_mod_tmp[0] +
                     rtDW.tod_to_mod_tmp[1] * rtDW.tod_to_mod_tmp[1]);

  /* Sum: '<S368>/Sum1' incorporates:
   *  Constant: '<S368>/Constant'
   *  Constant: '<S368>/Constant1'
   */
  rtDW.tsince = rtP.Constant_Value_g - rtP.Constant1_Value_j5;

  /* Product: '<S349>/Product1' incorporates:
   *  Constant: '<S349>/Constant'
   */
  rtDW.D_sun = rtP.Constant_Value_b * rtDW.tsince;

  /* Sum: '<S369>/Sum1' incorporates:
   *  Constant: '<S369>/Constant'
   *  Product: '<S369>/Product2'
   */
  rtDW.Sum1_m = rtP.Constant_Value_n - rtDW.tsince * rtDW.tsince;

  /* Product: '<S367>/Product2' incorporates:
   *  Constant: '<S367>/Constant'
   *  Sum: '<S367>/Sum1'
   */
  rtDW.O_moon = rtDW.Sum1_m / (rtP.Constant_Value_i - rtDW.Sum1_m);

  /* Outputs for Iterator SubSystem: '<S349>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S366>/While Iterator'
   */
  rtDW.s366_iter = 1;
  do {
    rtDW.eps = rtDW.Memory_PreviousInput;
    if (rtDW.s366_iter <= rtP.Switch_Threshold) {
      rtDW.eps = rt_atan2d_snf_k(rtDW.tod_to_mod_tmp[2], rtDW.tsince *
        rtDW.M_moon);
    }

    rtDW.epsb_1980 = sin(rtDW.eps);
    rtDW.u_moon = cos(rtDW.eps);
    rtDW.epsb_1980 *= rtDW.O_moon * rtDW.D_sun * rtDW.epsb_1980 * rtDW.epsb_1980;
    rtDW.epsb_1980 += rtDW.tod_to_mod_tmp[2];
    rtDW.M_sun = rt_atan2d_snf_k(rtDW.epsb_1980, rtDW.M_moon - rtDW.u_moon *
      rtDW.u_moon * rtDW.u_moon * rtDW.Sum1_m * rtP.Constant1_Value_j);
    rtDW.QOMS4 = sin(rtDW.M_sun);
    rtDW.w_o = cos(rtDW.M_sun);
    rtDW.epsb_1980 = rt_atan2d_snf_k(rtDW.tsince * rtDW.QOMS4, rtDW.w_o);
    rtDW.Memory_PreviousInput = rtDW.epsb_1980;
    rtDW.s366_iter++;
  } while ((rtDW.eps != rtDW.epsb_1980) && (rtDW.s366_iter <= 5));

  /* End of Outputs for SubSystem: '<S349>/While Iterator Subsystem' */

  /* UnitConversion: '<S363>/Unit Conversion' incorporates:
   *  Product: '<S289>/MatrixMultiply'
   *  Trigonometry: '<S349>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtDW.dpsi_1980 = 57.295779513082323 * rtDW.M_sun;
  rtDW.u_moon = 57.295779513082323 * rt_atan2d_snf_k(rtDW.tod_to_mod_tmp[1],
    rtDW.tod_to_mod_tmp[0]);

  /* UnitConversion: '<S361>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.epsb_1980 = 0.017453292519943295 * rtDW.dpsi_1980;

  /* Trigonometry: '<S348>/sincos' */
  rtDW.O_moon = cos(rtDW.epsb_1980);

  /* UnitConversion: '<S361>/Unit Conversion' incorporates:
   *  Trigonometry: '<S348>/sincos'
   */
  rtDW.M_sun = sin(rtDW.epsb_1980);
  rtDW.epsb_1980 = 0.017453292519943295 * rtDW.u_moon;

  /* Trigonometry: '<S348>/sincos' */
  rtDW.deps_1980 = cos(rtDW.epsb_1980);
  rtDW.epsb_1980 = sin(rtDW.epsb_1980);

  /* UnaryMinus: '<S352>/Unary Minus' incorporates:
   *  Product: '<S352>/u(1)*u(4)'
   */
  rtDW.NED2ECEF[0] = -(rtDW.M_sun * rtDW.deps_1980);

  /* UnaryMinus: '<S355>/Unary Minus' */
  rtDW.NED2ECEF[1] = -rtDW.epsb_1980;

  /* UnaryMinus: '<S358>/Unary Minus' incorporates:
   *  Product: '<S358>/u(3)*u(4)'
   */
  rtDW.NED2ECEF[2] = -(rtDW.O_moon * rtDW.deps_1980);

  /* UnaryMinus: '<S353>/Unary Minus' incorporates:
   *  Product: '<S353>/u(1)*u(2)'
   */
  rtDW.NED2ECEF[3] = -(rtDW.M_sun * rtDW.epsb_1980);

  /* SignalConversion: '<S362>/ConcatBufferAtVector ConcatenateIn5' */
  rtDW.NED2ECEF[4] = rtDW.deps_1980;

  /* UnaryMinus: '<S359>/Unary Minus' incorporates:
   *  Product: '<S359>/u(2)*u(3)'
   */
  rtDW.NED2ECEF[5] = -(rtDW.epsb_1980 * rtDW.O_moon);

  /* SignalConversion: '<S362>/ConcatBufferAtVector ConcatenateIn7' */
  rtDW.NED2ECEF[6] = rtDW.O_moon;

  /* Constant: '<S357>/Constant' */
  rtDW.NED2ECEF[7] = rtP.Constant_Value_nr;

  /* UnaryMinus: '<S360>/Unary Minus' */
  rtDW.NED2ECEF[8] = -rtDW.M_sun;

  /* Math: '<S289>/Transpose' */
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.rtb_Gain_d_tmp[3 * rtDW.i_d] = rtDW.NED2ECEF[rtDW.i_d];
    rtDW.rtb_Gain_d_tmp[1 + 3 * rtDW.i_d] = rtDW.NED2ECEF[rtDW.i_d + 3];
    rtDW.rtb_Gain_d_tmp[2 + 3 * rtDW.i_d] = rtDW.NED2ECEF[rtDW.i_d + 6];
  }

  memcpy(&rtDW.NED2ECEF[0], &rtDW.rtb_Gain_d_tmp[0], 9U * sizeof(real_T));

  /* End of Math: '<S289>/Transpose' */

  /* Product: '<S365>/Product2' */
  rtDW.tsince = rtDW.QOMS4 * rtDW.Sum1_m;

  /* Product: '<S365>/Product3' incorporates:
   *  Constant: '<S365>/Constant1'
   *  Constant: '<S365>/f'
   *  Product: '<S365>/Product1'
   *  Sqrt: '<S365>/sqrt'
   *  Sum: '<S365>/Sum'
   */
  rtDW.epsb_1980 = rtP.Constant1_Value_e / sqrt(rtP.f_Value - rtDW.tsince *
    rtDW.QOMS4);

  /* Product: '<S365>/Product4' */
  rtDW.tsince *= rtDW.epsb_1980;

  /* Sum: '<S365>/Sum2' incorporates:
   *  Product: '<S289>/MatrixMultiply'
   */
  rtDW.tsince += rtDW.tod_to_mod_tmp[2];

  /* Sum: '<S365>/Sum3' incorporates:
   *  Product: '<S365>/Product5'
   *  Product: '<S365>/Product6'
   */
  rtDW.epsb_1980 = (rtDW.QOMS4 * rtDW.tsince - rtDW.epsb_1980) + rtDW.w_o *
    rtDW.M_moon;

  /* MATLAB Function: '<S289>/MATLAB Function' */
  if ((!rtIsInf(rtDW.YMDHMS_UTC[0])) && (!rtIsNaN(rtDW.YMDHMS_UTC[0]))) {
    if (rtDW.YMDHMS_UTC[0] == 0.0) {
      rtDW.QOMS4 = 0.0;
    } else {
      rtDW.QOMS4 = fmod(rtDW.YMDHMS_UTC[0], 4.0);
      if (rtDW.QOMS4 == 0.0) {
        rtDW.QOMS4 = 0.0;
      } else {
        if (rtDW.YMDHMS_UTC[0] < 0.0) {
          rtDW.QOMS4 += 4.0;
        }
      }
    }
  } else {
    rtDW.QOMS4 = (rtNaN);
  }

  if (rtDW.QOMS4 == 0.0) {
    rtDW.tsince = 366.0;
    rtDW.iter = 29;
  } else {
    rtDW.tsince = 365.25;
    rtDW.iter = 28;
  }

  if (rtDW.YMDHMS_UTC[1] == 1.0) {
    rtDW.eps = rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 2.0) {
    rtDW.eps = 31.0 + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 3.0) {
    rtDW.eps = (31.0 + (real_T)rtDW.iter) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 4.0) {
    rtDW.eps = ((31.0 + (real_T)rtDW.iter) + 31.0) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 5.0) {
    rtDW.eps = (((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 6.0) {
    rtDW.eps = ((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) +
      rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 7.0) {
    rtDW.eps = (((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) + 30.0) +
      rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 8.0) {
    rtDW.eps = ((((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) + 30.0) +
                31.0) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 9.0) {
    rtDW.eps = (((((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) + 30.0)
                 + 31.0) + 31.0) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 10.0) {
    rtDW.eps = ((((((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) + 30.0)
                  + 31.0) + 31.0) + 30.0) + rtDW.YMDHMS_UTC[2];
  } else if (rtDW.YMDHMS_UTC[1] == 11.0) {
    rtDW.eps = (((((((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) + 30.0)
                   + 31.0) + 31.0) + 30.0) + 31.0) + rtDW.YMDHMS_UTC[2];
  } else {
    rtDW.eps = ((((((((((31.0 + (real_T)rtDW.iter) + 31.0) + 30.0) + 31.0) +
                     30.0) + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) +
      rtDW.YMDHMS_UTC[2];
  }

  rtDW.tsince = (((rtDW.YMDHMS_UTC[3] / 24.0 + rtDW.eps) + rtDW.YMDHMS_UTC[4] /
                  1440.0) + rtDW.YMDHMS_UTC[5] / 86400.0) / rtDW.tsince +
    rtDW.YMDHMS_UTC[0];

  /* End of MATLAB Function: '<S289>/MATLAB Function' */

  /* MATLAB Function: '<S351>/MATLAB Function' */
  rtDW.eps = 0.017453292519943295 * rtDW.dpsi_1980;
  rtDW.M_moon = 0.017453292519943295 * rtDW.u_moon;
  rtDW.Sum1_m = sin(rtDW.eps);
  memset(&rtDW.sp[0], 0, 13U * sizeof(real_T));
  memset(&rtDW.cp[0], 0, 13U * sizeof(real_T));
  rtDW.sp[1] = sin(rtDW.M_moon);
  rtDW.cp[0] = 1.0;
  rtDW.cp[1] = cos(rtDW.M_moon);
  rtDW.iter = 3;
  for (rtDW.i_d = 0; rtDW.i_d < 11; rtDW.i_d++) {
    rtDW.iter = 3 + rtDW.i_d;
    rtDW.dpsi_1980 = rtDW.cp[rtDW.i_d + 1];
    rtDW.sp[rtDW.i_d + 2] = rtDW.dpsi_1980 * rtDW.sp[1] + rtDW.sp[rtDW.i_d + 1] *
      rtDW.cp[1];
    rtDW.cp[rtDW.i_d + 2] = rtDW.dpsi_1980 * rtDW.cp[1] - rtDW.sp[rtDW.i_d + 1] *
      rtDW.sp[1];
  }

  rtDW.M_moon = 6.378137E+6 / sqrt(1.0 - rtDW.Sum1_m * rtDW.Sum1_m *
    0.0066943799901413165);
  rtDW.M_sun = (rtDW.M_moon + rtDW.epsb_1980) * cos(rtDW.eps);
  rtDW.M_moon = (rtDW.M_moon * 0.99330562000985867 + rtDW.epsb_1980) *
    rtDW.Sum1_m;
  rtDW.QOMS4 = sqrt(rtDW.M_sun * rtDW.M_sun + rtDW.M_moon * rtDW.M_moon);
  rtDW.epsb_1980 = asin(rtDW.M_moon / rtDW.QOMS4);
  rtDW.Sum1_m = sin(rtDW.epsb_1980);
  rtDW.M_moon = 6.3712E+6 / rtDW.QOMS4;
  rtDW.M_sun = rtDW.M_moon * rtDW.M_moon;
  memset(&rtDW.P_m[0], 0, 196U * sizeof(real_T));
  rtDW.dpsi_1980 = sqrt(1.0 - rtDW.Sum1_m * rtDW.Sum1_m);
  rtDW.u_moon = tan(rtDW.epsb_1980);
  rtDW.D_sun = 1.0 / cos(rtDW.epsb_1980);
  rtDW.P_m[0] = 1.0;
  rtDW.P_m[1] = rtDW.Sum1_m;
  rtDW.P_m[15] = -rtDW.dpsi_1980;
  rtDW.i_d = 2;
  for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 12; rtDW.deps_1980_tmp++) {
    rtDW.i_d = 2 + rtDW.deps_1980_tmp;
    rtDW.P_m[rtDW.deps_1980_tmp + 2] = (((2.0 + (real_T)rtDW.deps_1980_tmp) *
      2.0 - 1.0) * rtDW.Sum1_m * rtDW.P_m[rtDW.deps_1980_tmp + 1] - ((2.0 +
      (real_T)rtDW.deps_1980_tmp) - 1.0) * rtDW.P_m[rtDW.deps_1980_tmp]) * (1.0 /
      (2.0 + (real_T)rtDW.deps_1980_tmp));
    rtDW.iter = 1;
    rtDW.rtb_Gain_d_tmp_l = 0;
    while (rtDW.rtb_Gain_d_tmp_l <= rtDW.deps_1980_tmp + 1) {
      rtDW.iter = 1 + rtDW.rtb_Gain_d_tmp_l;
      rtDW.rtb_Gain_d_tmp_o = 14 * rtDW.rtb_Gain_d_tmp_l + rtDW.deps_1980_tmp;
      rtDW.P_tmp = rtDW.deps_1980_tmp - rtDW.rtb_Gain_d_tmp_l;
      rtDW.deps_1980 = rtDW.deps_1980_tmp + rtDW.rtb_Gain_d_tmp_l;
      rtDW.P_tmp_b = rtDW.rtb_Gain_d_tmp_o + 1;
      rtDW.P_tmp_n = rtDW.rtb_Gain_d_tmp_o + 2;
      rtDW.P_m[(rtDW.deps_1980_tmp + 14 * (rtDW.rtb_Gain_d_tmp_l + 1)) + 2] =
        ((((real_T)rtDW.P_tmp + 1.0) + 1.0) * rtDW.Sum1_m *
         rtDW.P_m[rtDW.P_tmp_n] - ((rtDW.deps_1980 + 3.0) - 1.0) *
         rtDW.P_m[rtDW.P_tmp_b]) * (1.0 / rtDW.dpsi_1980);
      if ((1 + rtDW.rtb_Gain_d_tmp_l > 1) && (rtDW.P_tmp + 1 > 0)) {
        rtDW.O_moon = ((real_T)(rtDW.deps_1980_tmp - rtDW.rtb_Gain_d_tmp_l) -
                       1.0) + 1.0;
        factorial_DisWLItj(&rtDW.O_moon);
        rtDW.QOMS4 = (rtDW.deps_1980 + 1.0) - 1.0;
        factorial_DisWLItj(&rtDW.QOMS4);
        rtDW.P_m[rtDW.deps_1980_tmp + 14 * rtDW.rtb_Gain_d_tmp_l] =
          rt_powd_snf_k(-1.0, (1.0 + (real_T)rtDW.rtb_Gain_d_tmp_l) - 1.0) *
          sqrt(2.0 * rtDW.O_moon / rtDW.QOMS4) * rtDW.P_m[rtDW.rtb_Gain_d_tmp_o];
      }

      if ((1 + rtDW.rtb_Gain_d_tmp_l > 1) && (2 + rtDW.deps_1980_tmp == 13)) {
        rtDW.O_moon = (real_T)(rtDW.deps_1980_tmp - rtDW.rtb_Gain_d_tmp_l) + 1.0;
        factorial_DisWLItj(&rtDW.O_moon);
        rtDW.deps_1980 = (rtDW.deps_1980 + 2.0) - 1.0;
        factorial_DisWLItj(&rtDW.deps_1980);
        rtDW.P_m[(rtDW.deps_1980_tmp + 14 * rtDW.rtb_Gain_d_tmp_l) + 1] =
          rt_powd_snf_k(-1.0, (1.0 + (real_T)rtDW.rtb_Gain_d_tmp_l) - 1.0) *
          sqrt(2.0 * rtDW.O_moon / rtDW.deps_1980) * rtDW.P_m[rtDW.P_tmp_b];
        rtDW.O_moon = ((real_T)(rtDW.deps_1980_tmp - rtDW.rtb_Gain_d_tmp_l) +
                       1.0) + 1.0;
        factorial_DisWLItj(&rtDW.O_moon);
        rtDW.deps_1980 = ((real_T)(rtDW.deps_1980_tmp + rtDW.rtb_Gain_d_tmp_l) +
                          3.0) - 1.0;
        factorial_DisWLItj(&rtDW.deps_1980);
        rtDW.P_m[(rtDW.deps_1980_tmp + 14 * rtDW.rtb_Gain_d_tmp_l) + 2] =
          rt_powd_snf_k(-1.0, (1.0 + (real_T)rtDW.rtb_Gain_d_tmp_l) - 1.0) *
          sqrt(2.0 * rtDW.O_moon / rtDW.deps_1980) * rtDW.P_m[rtDW.P_tmp_n];
      }

      rtDW.rtb_Gain_d_tmp_l++;
    }
  }

  rtDW.n_o = rtDW.i_d - rtDW.iter;
  factorial_DisWLItj(&rtDW.n_o);
  rtDW.Sum1_m = rtDW.i_d + rtDW.iter;
  factorial_DisWLItj(&rtDW.Sum1_m);
  rtDW.P_m[rtDW.i_d + 14 * rtDW.iter] *= sqrt(2.0 * rtDW.n_o / rtDW.Sum1_m) *
    rt_powd_snf_k(-1.0, (real_T)rtDW.iter);
  rtDW.Sum1_m = 0.0;
  rtDW.O_moon = 0.0;
  rtDW.dpsi_1980 = 0.0;
  for (rtDW.iter = 0; rtDW.iter < 12; rtDW.iter++) {
    rtDW.M_sun *= rtDW.M_moon;
    rtDW.i_d = 0;
    while (rtDW.i_d <= rtDW.iter + 1) {
      rtDW.deps_1980_tmp = 12 * rtDW.i_d + rtDW.iter;
      rtDW.deps_1980 = dg[rtDW.deps_1980_tmp] * (rtDW.tsince - 2015.0) +
        g[rtDW.deps_1980_tmp];
      rtDW.tsince_JD = dh[rtDW.deps_1980_tmp] * (rtDW.tsince - 2015.0) +
        h[rtDW.deps_1980_tmp];
      rtDW.deps_1980_tmp = 14 * rtDW.i_d + rtDW.iter;
      rtDW.QOMS4 = rtDW.P_m[rtDW.deps_1980_tmp + 1];
      rtDW.w_o = rtDW.deps_1980 * rtDW.cp[rtDW.i_d] + rtDW.tsince_JD *
        rtDW.sp[rtDW.i_d];
      rtDW.Sum1_m -= (((1.0 + (real_T)rtDW.iter) + 1.0) * rtDW.u_moon *
                      rtDW.QOMS4 - sqrt((rtDW.iter + 2) * (rtDW.iter + 2) -
        rtDW.i_d * rtDW.i_d) * rtDW.D_sun * rtDW.P_m[rtDW.deps_1980_tmp + 2]) *
        (rtDW.w_o * rtDW.M_sun);
      rtDW.O_moon += (rtDW.deps_1980 * rtDW.sp[rtDW.i_d] - rtDW.tsince_JD *
                      rtDW.cp[rtDW.i_d]) * (rtDW.M_sun * (real_T)rtDW.i_d) *
        rtDW.QOMS4;
      rtDW.dpsi_1980 -= ((1.0 + (real_T)rtDW.iter) + 1.0) * rtDW.M_sun *
        rtDW.w_o * rtDW.QOMS4;
      rtDW.i_d++;
    }
  }

  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    /* Math: '<S289>/Transpose1' incorporates:
     *  Math: '<S288>/Transpose'
     */
    rtDW.rtb_Gain_d_tmp[3 * rtDW.i_d] = rtDW.Transpose[rtDW.i_d];
    rtDW.rtb_Gain_d_tmp[1 + 3 * rtDW.i_d] = rtDW.Transpose[rtDW.i_d + 3];
    rtDW.rtb_Gain_d_tmp[2 + 3 * rtDW.i_d] = rtDW.Transpose[rtDW.i_d + 6];
  }

  /* MATLAB Function: '<S351>/MATLAB Function' */
  rtDW.QOMS4 = rtDW.epsb_1980 - rtDW.eps;
  rtDW.w_o = sin(rtDW.QOMS4);
  rtDW.QOMS4 = cos(rtDW.QOMS4);
  rtDW.bias_merge[0] = rtDW.QOMS4 * rtDW.Sum1_m - rtDW.w_o * rtDW.dpsi_1980;
  rtDW.bias_merge[1] = rtDW.D_sun * rtDW.O_moon;
  rtDW.bias_merge[2] = rtDW.w_o * rtDW.Sum1_m + rtDW.QOMS4 * rtDW.dpsi_1980;

  /* Trigonometry: '<S107>/Tan1' incorporates:
   *  Gain: '<S107>/deg2rad'
   */
  rtDW.epsb_1980 = tan(rtP.fswParams.constants.convert.DEG2RAD *
                       rtDW.RateTransition2[0]);

  /* Trigonometry: '<S107>/Tan' incorporates:
   *  Gain: '<S107>/deg2rad'
   */
  rtDW.u_moon = tan(rtP.fswParams.constants.convert.DEG2RAD *
                    rtDW.RateTransition2[1]);

  /* Math: '<S109>/Math Function' incorporates:
   *  Constant: '<S109>/Constant'
   *  Math: '<S109>/Square'
   *  Math: '<S109>/Square1'
   *  Sqrt: '<S109>/Sqrt'
   *  Sum: '<S109>/Sum'
   *
   * About '<S109>/Math Function':
   *  Operator: reciprocal
   */
  rtDW.tsince = 1.0 / sqrt((rtDW.epsb_1980 * rtDW.epsb_1980 +
    rtP.Constant_Value_p) + rtDW.u_moon * rtDW.u_moon);

  /* SignalConversion: '<S107>/TmpSignal ConversionAtss_2_bodyInport2' incorporates:
   *  Product: '<S107>/Matrix Multiply'
   *  Product: '<S107>/Matrix Multiply1'
   */
  rtDW.TmpSignalConversionAtProduc[0] = rtDW.epsb_1980 * rtDW.tsince;
  rtDW.TmpSignalConversionAtProduc[1] = rtDW.tsince * rtDW.u_moon;
  rtDW.TmpSignalConversionAtProduc[2] = rtDW.tsince;
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    /* Product: '<S289>/Matrix Multiply1' */
    rtDW.MathFunction_i[rtDW.i_d] = 0.0;
    for (rtDW.deps_1980_tmp = 0; rtDW.deps_1980_tmp < 3; rtDW.deps_1980_tmp++) {
      /* Product: '<S289>/Matrix Multiply' incorporates:
       *  Math: '<S289>/Transpose1'
       *  Product: '<S289>/Matrix Multiply1'
       */
      rtDW.iter = rtDW.i_d + 3 * rtDW.deps_1980_tmp;
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = 0.0;
      rtDW.rtb_Gain_d_tmp_l = 3 * rtDW.deps_1980_tmp + rtDW.i_d;
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] =
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l] + rtDW.NED2ECEF[3 *
        rtDW.deps_1980_tmp] * rtDW.rtb_Gain_d_tmp[rtDW.i_d];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.NED2ECEF[3 * rtDW.deps_1980_tmp +
        1] * rtDW.rtb_Gain_d_tmp[rtDW.i_d + 3] +
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];
      rtDW.rtb_Gain_d_tmp_f[rtDW.iter] = rtDW.NED2ECEF[3 * rtDW.deps_1980_tmp +
        2] * rtDW.rtb_Gain_d_tmp[rtDW.i_d + 6] +
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l];

      /* Product: '<S289>/Matrix Multiply1' */
      rtDW.MathFunction_i[rtDW.i_d] +=
        rtDW.rtb_Gain_d_tmp_f[rtDW.rtb_Gain_d_tmp_l] *
        rtDW.bias_merge[rtDW.deps_1980_tmp];
    }

    /* Gain: '<S289>/nT2T' */
    rtDW.nT2T[rtDW.i_d] = rtP.simParams.constants.convert.nT2T *
      rtDW.MathFunction_i[rtDW.i_d];

    /* Product: '<S107>/ss_2_body' incorporates:
     *  Constant: '<S107>/Constant1'
     *  SignalConversion: '<S107>/TmpSignal ConversionAtss_2_bodyInport2'
     */
    rtDW.ss_2_body[rtDW.i_d] = rtP.simParams.sensors.sun_sensor.ss2body[rtDW.i_d
      + 6] * rtDW.tsince + (rtP.simParams.sensors.sun_sensor.ss2body[rtDW.i_d +
      3] * rtDW.TmpSignalConversionAtProduc[1] +
      rtP.simParams.sensors.sun_sensor.ss2body[rtDW.i_d] *
      rtDW.TmpSignalConversionAtProduc[0]);
  }

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
  maggyroProcessing_lib(rtDW.RateTransition3, rtDW.RateTransition6_l,
                        rtDW.TmpSignalConversionAtProduc, &rtDW.Merge1_g2,
                        &rtDW.maggyroProcessing_lib_j,
                        &rtP.maggyroProcessing_lib_j,
                        rtP.fswParams.sensors.mag_max_err,
                        rtP.fswParams.sensors.mag_offset,
                        rtP.fswParams.sensors.mag_static_range,
                        rtP.fswParams.constants.convert.uT2T);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib' */

  /* UnitDelay: '<S19>/Output' */
  rtDW.Output = rtDW.Output_DSTATE;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S19>/Output'
   */
  if (rtDW.Output_DSTATE > rtP.CompareToConstant1_const_c) {
    rtDW.Subtract_a[0] = rtDW.TmpSignalConversionAtProduc[0];
    rtDW.Subtract_a[1] = rtDW.TmpSignalConversionAtProduc[1];
    rtDW.Subtract_a[2] = rtDW.TmpSignalConversionAtProduc[2];
  } else {
    rtDW.Subtract_a[0] = rtDW.UnitDelay_DSTATE[0];
    rtDW.Subtract_a[1] = rtDW.UnitDelay_DSTATE[1];
    rtDW.Subtract_a[2] = rtDW.UnitDelay_DSTATE[2];
  }

  /* End of Switch: '<S11>/Switch' */

  /* Outputs for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
  maggyroProcessing_lib(rtDW.RateTransition4, rtDW.RateTransition7,
                        rtDW.TmpSignalConversionAtProduc, &rtDW.Merge1_g,
                        &rtDW.maggyroProcessing_lib1,
                        &rtP.maggyroProcessing_lib1,
                        rtP.fswParams.sensors.gyro_max_err,
                        rtP.fswParams.sensors.gyro_offset,
                        rtP.fswParams.sensors.gyro_static_range,
                        rtP.maggyroProcessing_lib1_Gain);

  /* End of Outputs for SubSystem: '<S2>/maggyroProcessing_lib1' */

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib(rtDW.Divide_a, rtDW.nT2T, rtDW.ss_2_body, rtDW.Subtract_a,
           rtDW.TmpSignalConversionAtProduc, rtDW.Merge_b, rtDW.Merge1_g2,
           rtDW.Merge1_g, rtDW.triad_override, rtDW.q_p_merge,
           rtDW.MathFunction_i, rtDW.YMDHMS_UTC, rtDW.bias_merge,
           &rtDW.Merge_n_j, &rtDW.MEKF_lib_k, &rtP.MEKF_lib_k);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* Switch: '<S332>/Switch' incorporates:
   *  Abs: '<S332>/Abs'
   *  Bias: '<S332>/Bias'
   *  Bias: '<S332>/Bias1'
   *  Constant: '<S332>/Constant2'
   *  Constant: '<S333>/Constant'
   *  Math: '<S332>/Math Function1'
   *  RelationalOperator: '<S333>/Compare'
   */
  if (fabs(rtDW.target_latlonalt[0]) > rtP.CompareToConstant_const) {
    rtDW.epsb_1980 = rt_modd_snf_k(rtDW.target_latlonalt[0] + rtP.Bias_Bias_g,
      rtP.Constant2_Value_d) + rtP.Bias1_Bias_c;
  } else {
    rtDW.epsb_1980 = rtDW.target_latlonalt[0];
  }

  /* End of Switch: '<S332>/Switch' */

  /* Abs: '<S329>/Abs1' */
  rtDW.tsince = fabs(rtDW.epsb_1980);

  /* RelationalOperator: '<S331>/Compare' incorporates:
   *  Constant: '<S331>/Constant'
   */
  rtDW.lowAlt = (rtDW.tsince > rtP.CompareToConstant_const_o);

  /* Switch: '<S329>/Switch' incorporates:
   *  Bias: '<S329>/Bias'
   *  Bias: '<S329>/Bias1'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S299>/Constant1'
   *  Gain: '<S329>/Gain'
   *  Product: '<S329>/Divide1'
   *  Switch: '<S299>/Switch1'
   */
  if (rtDW.lowAlt) {
    /* Signum: '<S329>/Sign1' */
    if (rtDW.epsb_1980 < 0.0) {
      rtDW.epsb_1980 = -1.0;
    } else if (rtDW.epsb_1980 > 0.0) {
      rtDW.epsb_1980 = 1.0;
    } else if (rtDW.epsb_1980 == 0.0) {
      rtDW.epsb_1980 = 0.0;
    } else {
      rtDW.epsb_1980 = (rtNaN);
    }

    /* End of Signum: '<S329>/Sign1' */
    rtDW.epsb_1980 *= (rtDW.tsince + rtP.Bias_Bias) * rtP.Gain_Gain_g +
      rtP.Bias1_Bias;
    rtDW.dpsi_1980 = rtP.Constant_Value_ea;
  } else {
    rtDW.dpsi_1980 = rtP.Constant1_Value_d;
  }

  /* End of Switch: '<S329>/Switch' */

  /* UnitConversion: '<S323>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.u_moon = 0.017453292519943295 * rtDW.epsb_1980;

  /* Product: '<S298>/Product3' incorporates:
   *  Constant: '<S293>/Constant2'
   *  Trigonometry: '<S298>/sincos1'
   */
  rtDW.M_sun = rtP.Constant2_Value_nc * sin(rtDW.u_moon);
  rtDW.Sum1_m = rtP.Constant2_Value_nc * cos(rtDW.u_moon);

  /* Sum: '<S298>/Sum' incorporates:
   *  Constant: '<S298>/Constant'
   *  Constant: '<S298>/f'
   */
  rtDW.eps = rtP.f_Value_m - rtP.GeodetictoGeocentricLatitude_F;

  /* Trigonometry: '<S298>/Trigonometric Function2' incorporates:
   *  Constant: '<S298>/f'
   *  Product: '<S298>/Product2'
   *  Trigonometry: '<S298>/Trigonometric Function1'
   */
  rtDW.eps = rt_atan2d_snf_k(tan(rtDW.u_moon) * rtDW.eps * rtDW.eps,
    rtP.f_Value_m);

  /* Trigonometry: '<S327>/Trigonometric Function' incorporates:
   *  UnitConversion: '<S324>/Unit Conversion'
   *  UnitConversion: '<S328>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.u_moon = sin(57.295779513082323 * rtDW.eps * 0.017453292519943295);

  /* Sum: '<S327>/Sum' incorporates:
   *  Constant: '<S327>/Constant'
   *  Constant: '<S327>/f'
   */
  rtDW.tsince = rtP.Constant_Value_jh - rtP.GeodetictoGeocentricLatitude_F;

  /* Sqrt: '<S327>/sqrt' incorporates:
   *  Constant: '<S327>/Constant'
   *  Constant: '<S327>/Re'
   *  Product: '<S327>/Product1'
   *  Product: '<S327>/Product2'
   *  Product: '<S327>/Product3'
   *  Product: '<S327>/Product4'
   *  Sum: '<S327>/Sum1'
   *  Sum: '<S327>/Sum2'
   */
  rtDW.u_moon = sqrt(rtP.GeodetictoGeocentricLatitude_R *
                     rtP.GeodetictoGeocentricLatitude_R /
                     ((rtP.Constant_Value_jh / (rtDW.tsince * rtDW.tsince) -
                       rtP.Constant_Value_jh) * (rtDW.u_moon * rtDW.u_moon) +
                      rtP.Constant_Value_jh));

  /* Trigonometry: '<S298>/sincos' */
  rtDW.tsince = cos(rtDW.eps);
  rtDW.eps = sin(rtDW.eps);

  /* Sum: '<S298>/Sum1' incorporates:
   *  Product: '<S298>/Product1'
   */
  rtDW.M_sun += rtDW.u_moon * rtDW.eps;

  /* UnitConversion: '<S325>/Unit Conversion' incorporates:
   *  Product: '<S298>/Product1'
   *  Sum: '<S298>/Sum1'
   *  Trigonometry: '<S298>/Trigonometric Function3'
   *  Trigonometry: '<S298>/sincos'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtDW.eps = rt_atan2d_snf_k(rtDW.M_sun, rtDW.u_moon * rtDW.tsince + rtDW.Sum1_m)
    * 57.295779513082323;

  /* Sum: '<S299>/Sum' */
  rtDW.u_moon = rtDW.dpsi_1980 + rtDW.target_latlonalt[1];

  /* Switch: '<S330>/Switch' incorporates:
   *  Abs: '<S330>/Abs'
   *  Bias: '<S330>/Bias'
   *  Bias: '<S330>/Bias1'
   *  Constant: '<S330>/Constant2'
   *  Constant: '<S334>/Constant'
   *  Math: '<S330>/Math Function1'
   *  RelationalOperator: '<S334>/Compare'
   */
  if (fabs(rtDW.u_moon) > rtP.CompareToConstant_const_f) {
    rtDW.u_moon = rt_modd_snf_k(rtDW.u_moon + rtP.Bias_Bias_b,
      rtP.Constant2_Value_n) + rtP.Bias1_Bias_e;
  }

  /* End of Switch: '<S330>/Switch' */

  /* UnitConversion: '<S321>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.M_sun = 0.017453292519943295 * rtDW.eps;
  rtDW.Sum1_m = 0.017453292519943295 * rtDW.u_moon;

  /* Trigonometry: '<S297>/sincos' */
  rtDW.dpsi_1980 = cos(rtDW.M_sun);
  rtDW.M_sun = sin(rtDW.M_sun);
  rtDW.M_moon = cos(rtDW.Sum1_m);
  rtDW.Sum1_m = sin(rtDW.Sum1_m);

  /* UnaryMinus: '<S312>/Unary Minus' incorporates:
   *  Product: '<S312>/u(1)*u(4)'
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[0] = -(rtDW.M_sun * rtDW.M_moon);

  /* UnaryMinus: '<S315>/Unary Minus' incorporates:
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[1] = -rtDW.Sum1_m;

  /* UnaryMinus: '<S318>/Unary Minus' incorporates:
   *  Product: '<S318>/u(3)*u(4)'
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[2] = -(rtDW.dpsi_1980 * rtDW.M_moon);

  /* UnaryMinus: '<S313>/Unary Minus' incorporates:
   *  Product: '<S313>/u(1)*u(2)'
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[3] = -(rtDW.M_sun * rtDW.Sum1_m);

  /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[4] = rtDW.M_moon;

  /* UnaryMinus: '<S319>/Unary Minus' incorporates:
   *  Product: '<S319>/u(2)*u(3)'
   *  Trigonometry: '<S297>/sincos'
   */
  rtDW.MathFunction1_e[5] = -(rtDW.Sum1_m * rtDW.dpsi_1980);

  /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn7' */
  rtDW.MathFunction1_e[6] = rtDW.dpsi_1980;

  /* Constant: '<S317>/Constant' */
  rtDW.MathFunction1_e[7] = rtP.Constant_Value_ez;

  /* UnaryMinus: '<S320>/Unary Minus' */
  rtDW.MathFunction1_e[8] = -rtDW.M_sun;

  /* Math: '<S293>/Math Function1' */
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.Transpose[3 * rtDW.i_d] = rtDW.MathFunction1_e[rtDW.i_d];
    rtDW.Transpose[1 + 3 * rtDW.i_d] = rtDW.MathFunction1_e[rtDW.i_d + 3];
    rtDW.Transpose[2 + 3 * rtDW.i_d] = rtDW.MathFunction1_e[rtDW.i_d + 6];
  }

  memcpy(&rtDW.MathFunction1_e[0], &rtDW.Transpose[0], 9U * sizeof(real_T));

  /* End of Math: '<S293>/Math Function1' */

  /* UnitConversion: '<S335>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.eps *= 0.017453292519943295;

  /* Trigonometry: '<S300>/Trigonometric Function' */
  rtDW.eps = sin(rtDW.eps);

  /* Sum: '<S300>/Sum' incorporates:
   *  Constant: '<S300>/Constant'
   *  Constant: '<S300>/f'
   */
  rtDW.tsince = rtP.Constant_Value_nu - rtP.RadiusatGeocentricLatitude_F;

  /* UnitConversion: '<S310>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtDW.M_sun = 0.017453292519943295 * rtDW.epsb_1980;
  rtDW.Sum1_m = 0.017453292519943295 * rtDW.u_moon;

  /* Trigonometry: '<S296>/sincos' */
  rtDW.O_moon = cos(rtDW.M_sun);
  rtDW.M_sun = sin(rtDW.M_sun);
  rtDW.deps_1980 = cos(rtDW.Sum1_m);
  rtDW.epsb_1980 = sin(rtDW.Sum1_m);

  /* UnaryMinus: '<S301>/Unary Minus' incorporates:
   *  Product: '<S301>/u(1)*u(4)'
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[0] = -(rtDW.M_sun * rtDW.deps_1980);

  /* UnaryMinus: '<S304>/Unary Minus' incorporates:
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[1] = -rtDW.epsb_1980;

  /* UnaryMinus: '<S307>/Unary Minus' incorporates:
   *  Product: '<S307>/u(3)*u(4)'
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[2] = -(rtDW.O_moon * rtDW.deps_1980);

  /* UnaryMinus: '<S302>/Unary Minus' incorporates:
   *  Product: '<S302>/u(1)*u(2)'
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[3] = -(rtDW.M_sun * rtDW.epsb_1980);

  /* SignalConversion: '<S311>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[4] = rtDW.deps_1980;

  /* UnaryMinus: '<S308>/Unary Minus' incorporates:
   *  Product: '<S308>/u(2)*u(3)'
   *  Trigonometry: '<S296>/sincos'
   */
  rtDW.MathFunction_o[5] = -(rtDW.epsb_1980 * rtDW.O_moon);

  /* SignalConversion: '<S311>/ConcatBufferAtVector ConcatenateIn7' */
  rtDW.MathFunction_o[6] = rtDW.O_moon;

  /* Constant: '<S306>/Constant' */
  rtDW.MathFunction_o[7] = rtP.Constant_Value_jk;

  /* UnaryMinus: '<S309>/Unary Minus' */
  rtDW.MathFunction_o[8] = -rtDW.M_sun;

  /* Math: '<S293>/Math Function' */
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.Transpose[3 * rtDW.i_d] = rtDW.MathFunction_o[rtDW.i_d];
    rtDW.Transpose[1 + 3 * rtDW.i_d] = rtDW.MathFunction_o[rtDW.i_d + 3];
    rtDW.Transpose[2 + 3 * rtDW.i_d] = rtDW.MathFunction_o[rtDW.i_d + 6];
  }

  memcpy(&rtDW.MathFunction_o[0], &rtDW.Transpose[0], 9U * sizeof(real_T));

  /* End of Math: '<S293>/Math Function' */

  /* Sqrt: '<S300>/sqrt' incorporates:
   *  Constant: '<S300>/Constant'
   *  Constant: '<S300>/Re'
   *  Product: '<S300>/Product1'
   *  Product: '<S300>/Product2'
   *  Product: '<S300>/Product3'
   *  Product: '<S300>/Product4'
   *  Sum: '<S300>/Sum1'
   *  Sum: '<S300>/Sum2'
   */
  rtDW.QOMS4 = sqrt(rtP.RadiusatGeocentricLatitude_R *
                    rtP.RadiusatGeocentricLatitude_R / ((rtP.Constant_Value_nu /
    (rtDW.tsince * rtDW.tsince) - rtP.Constant_Value_nu) * (rtDW.eps * rtDW.eps)
    + rtP.Constant_Value_nu));
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    /* Sum: '<S293>/Sum' incorporates:
     *  Constant: '<S293>/Constant'
     *  Constant: '<S293>/Constant1'
     *  Product: '<S293>/Product'
     *  Product: '<S293>/Product1'
     *  Sqrt: '<S300>/sqrt'
     *  UnaryMinus: '<S293>/Unary Minus'
     *  UnaryMinus: '<S293>/Unary Minus1'
     */
    rtDW.TmpSignalConversionAtProduc[rtDW.i_d] = (rtDW.MathFunction1_e[rtDW.i_d
      + 6] * -rtDW.QOMS4 + (rtDW.MathFunction1_e[rtDW.i_d + 3] *
      rtP.Constant_Value_ey + rtDW.MathFunction1_e[rtDW.i_d] *
      rtP.Constant_Value_ey)) + (rtDW.MathFunction_o[rtDW.i_d + 6] *
      -rtDW.target_latlonalt[2] + (rtDW.MathFunction_o[rtDW.i_d + 3] *
      rtP.Constant1_Value_o + rtDW.MathFunction_o[rtDW.i_d] *
      rtP.Constant1_Value_o));
  }

  /* Outputs for Atomic SubSystem: '<S288>/target_groundpass_lib1' */
  target_groundpass_lib(rtDW.tod_to_mod_tmp, rtDW.TmpSignalConversionAtProduc,
                        rtDW.target_latlonalt[0], rtDW.target_latlonalt[1],
                        &rtDW.lowAlt, &rtDW.tsince, rtDW.nT2T,
                        &rtDW.target_groundpass_lib1,
                        &rtP.target_groundpass_lib1,
                        rtP.target_groundpass_lib1_id);

  /* End of Outputs for SubSystem: '<S288>/target_groundpass_lib1' */

  /* MATLAB Function: '<S377>/MATLAB Function' */
  rtDW.light = false;

  /* Gain: '<S291>/Gain' */
  rtDW.pos_teme_km[0] *= rtP.Gain_Gain_b;

  /* MATLAB Function: '<S377>/MATLAB Function' */
  rtDW.AU2KM[0] *= 1.49598073E+8;

  /* Gain: '<S291>/Gain' */
  rtDW.pos_teme_km[1] *= rtP.Gain_Gain_b;

  /* MATLAB Function: '<S377>/MATLAB Function' */
  rtDW.AU2KM[1] *= 1.49598073E+8;

  /* Gain: '<S291>/Gain' */
  rtDW.eps = rtP.Gain_Gain_b * rtDW.pos_teme_km[2];

  /* MATLAB Function: '<S377>/MATLAB Function' */
  rtDW.Sum1_m = rtDW.AU2KM[2] * 1.49598073E+8;

  /* Gain: '<S291>/Gain' */
  rtDW.pos_teme_km[2] = rtDW.eps;

  /* MATLAB Function: '<S377>/MATLAB Function' */
  rtDW.AU2KM[2] = rtDW.Sum1_m;
  rtDW.epsb_1980 = norm_2e9Xj4lM_j(rtDW.pos_teme_km);
  rtDW.w_o = norm_2e9Xj4lM_j(rtDW.AU2KM);
  rtDW.dpsi_1980 = (rtDW.pos_teme_km[0] * rtDW.AU2KM[0] + rtDW.pos_teme_km[1] *
                    rtDW.AU2KM[1]) + rtDW.eps * rtDW.Sum1_m;
  rtDW.eps = (rtDW.epsb_1980 * rtDW.epsb_1980 - rtDW.dpsi_1980) /
    ((rtDW.epsb_1980 * rtDW.epsb_1980 + rtDW.w_o * rtDW.w_o) - rtDW.dpsi_1980 *
     2.0);
  if ((rtDW.eps < 0.0) || (rtDW.eps > 1.0)) {
    rtDW.light = true;
  }

  if (rtDW.dpsi_1980 * rtDW.eps + (1.0 - rtDW.eps) * (rtDW.epsb_1980 *
       rtDW.epsb_1980) >= 4.0680631590768993E+7) {
    rtDW.light = true;
  }

  rtDW.light = !rtDW.light;

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  rtDW.gnc_mode_a = mode_select_lib(rtDW.telecom, rtDW.light, rtDW.Merge_b,
    rtDW.lowAlt, rtDW.MathFunction_i, rtDW.Sum_o, rtDW.MET_soar_utc_s,
    rtDW.RateTransition1, &rtDW.mode_select_lib_k, &rtP.mode_select_lib_k);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */

  /* Product: '<S288>/Product1' incorporates:
   *  Math: '<S288>/Transpose'
   */
  for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
    rtDW.TmpSignalConversionAtProduc[rtDW.i_d] = rtDW.rtb_Gain_d_tmp[rtDW.i_d +
      6] * rtDW.nT2T[2] + (rtDW.rtb_Gain_d_tmp[rtDW.i_d + 3] * rtDW.nT2T[1] +
      rtDW.rtb_Gain_d_tmp[rtDW.i_d] * rtDW.nT2T[0]);
  }

  /* End of Product: '<S288>/Product1' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  /* Update for RateTransition: '<S1>/Rate Transition4' */
  target_generation_lib(rtDW.gnc_mode_a, rtDW.Divide_a,
                        rtDW.TmpSignalConversionAtProduc, rtDW.Gain_d,
                        rtDW.q_p_merge, rtDW.MathFunction_i,
                        rtDW.RateTransition1, rtDW.quat_soar_cmd,
                        rtDW.MET_soar_utc_s, rtDW.Sum_o, rtDW.RateTransition6,
                        rtDW.AU2KM, rtDW.pos_teme_km, &rtDW.Switch3, rtDW.X_l,
                        rtDW.U, &rtDW.s, rtDW.exitcode,
                        &rtDW.RateTransition4_19_Buffer0.soar_count);

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */

  /* If: '<S230>/If' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtP.Constant_Value_mj[0] && rtP.Constant_Value_mj[1]) {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem' incorporates:
     *  ActionPort: '<S261>/Action Port'
     */
    IfActionSubsystem(&rtDW.Sum_o, &rtP.IfActionSubsystem_f);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem' */
  } else if (rtP.Constant_Value_mj[0] || rtP.Constant_Value_mj[1]) {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S262>/Action Port'
     */
    IfActionSubsystem(&rtDW.Sum_o, &rtP.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S263>/Action Port'
     */
    IfActionSubsystem(&rtDW.Sum_o, &rtP.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem2' */
  }

  /* End of If: '<S230>/If' */

  /* If: '<S230>/If1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtP.Constant_Value_mj[2] && rtP.Constant_Value_mj[3]) {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S264>/Action Port'
     */
    IfActionSubsystem(&rtDW.eps, &rtP.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem3' */
  } else if (rtP.Constant_Value_mj[2] || rtP.Constant_Value_mj[3]) {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S265>/Action Port'
     */
    IfActionSubsystem(&rtDW.eps, &rtP.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S230>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S266>/Action Port'
     */
    IfActionSubsystem(&rtDW.eps, &rtP.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S230>/If Action Subsystem5' */
  }

  /* End of If: '<S230>/If1' */
  for (rtDW.i_d = 0; rtDW.i_d < 5; rtDW.i_d++) {
    /* SignalConversion: '<S106>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S14>/MATLAB Function'
     */
    rtDW.TmpSignalConversionAtSFunct[rtDW.i_d] = rtDW.RateTransition1_l[rtDW.i_d];
  }

  /* SignalConversion: '<S106>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S14>/Constant'
   *  MATLAB Function: '<S14>/MATLAB Function'
   */
  rtDW.TmpSignalConversionAtSFunct[5] = rtP.Constant_Value_en;

  /* MATLAB Function: '<S14>/MATLAB Function' */
  rtDW.nT2T[0] = 0.0;
  rtDW.nT2T[1] = 0.0;
  rtDW.nT2T[2] = 0.0;
  for (rtDW.iter = 0; rtDW.iter < 6; rtDW.iter++) {
    if (rtDW.TmpSignalConversionAtSFunct[rtDW.iter] > 99.760095101689075) {
      rtDW.nT2T[0] += (real_T)normals[3 * rtDW.iter];
      rtDW.nT2T[1] += (real_T)normals[3 * rtDW.iter + 1];
      rtDW.nT2T[2] += (real_T)normals[3 * rtDW.iter + 2];
    }
  }

  rtDW.TmpSignalConversionAtProduc[0] = rtDW.nT2T[0];
  rtDW.TmpSignalConversionAtProduc[1] = rtDW.nT2T[1] - -1.0;
  rtDW.TmpSignalConversionAtProduc[2] = rtDW.nT2T[2];
  if (norm_2e9Xj4lM_j(rtDW.TmpSignalConversionAtProduc) < 1.0E-8) {
    sort_E8F8dFL3_j(rtDW.TmpSignalConversionAtSFunct, rtDW.iidx);
    rtDW.nT2T[0] += (real_T)normals[(rtDW.iidx[4] - 1) * 3];
    rtDW.nT2T[1] += (real_T)normals[(rtDW.iidx[4] - 1) * 3 + 1];
    rtDW.nT2T[2] += (real_T)normals[(rtDW.iidx[4] - 1) * 3 + 2];
  }

  rtDW.QOMS4 = norm_2e9Xj4lM_j(rtDW.nT2T);
  if (rtDW.QOMS4 < 1.0) {
    rtDW.nT2T[0] = 0.0;
    rtDW.nT2T[1] = 0.0;
    rtDW.nT2T[2] = -1.0;
  } else {
    rtDW.nT2T[0] /= rtDW.QOMS4;
    rtDW.nT2T[1] /= rtDW.QOMS4;
    rtDW.nT2T[2] /= rtDW.QOMS4;
  }

  /* Sum: '<S5>/Sum1' */
  rtDW.Divide_a[0] = rtDW.AU2KM[0] - rtDW.MathFunction_i[0];
  rtDW.Divide_a[1] = rtDW.AU2KM[1] - rtDW.MathFunction_i[1];
  rtDW.Divide_a[2] = rtDW.AU2KM[2] - rtDW.MathFunction_i[2];

  /* Outputs for Atomic SubSystem: '<S5>/quat_err_lib' */
  quat_err_lib(rtDW.RateTransition6, rtDW.q_p_merge, rtDW.Switch_g,
               &rtP.quat_err_lib_e);

  /* End of Outputs for SubSystem: '<S5>/quat_err_lib' */

  /* Gain: '<S5>/RPM2Radps' */
  rtDW.RPM2Radps[0] = rtP.fswParams.constants.convert.RPM2RPS *
    rtDW.RateTransition1[0];
  rtDW.RPM2Radps[1] = rtP.fswParams.constants.convert.RPM2RPS *
    rtDW.RateTransition1[1];
  rtDW.RPM2Radps[2] = rtP.fswParams.constants.convert.RPM2RPS *
    rtDW.RateTransition1[2];
  rtDW.RPM2Radps[3] = rtP.fswParams.constants.convert.RPM2RPS *
    rtDW.RateTransition1[3];

  /* SwitchCase: '<S228>/Switch Case' incorporates:
   *  Gain: '<S243>/Gain'
   *  Gain: '<S251>/Gain'
   *  Product: '<S243>/Matrix Multiply8'
   *  Product: '<S251>/Matrix Multiply8'
   */
  switch (rtDW.gnc_mode_a) {
   case 0:
   case 1:
   case 2:
   case 4:
    /* Outputs for IfAction SubSystem: '<S228>/case_null_control' incorporates:
     *  ActionPort: '<S236>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S236>/null_control_lib1' */
    null_control_lib(rtDW.Divide_a, &rtP.null_control_lib1);

    /* End of Outputs for SubSystem: '<S236>/null_control_lib1' */

    /* SignalConversion: '<S236>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[0] = rtDW.Divide_a[0];

    /* SignalConversion: '<S236>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[0] = rtDW.Divide_a[0];

    /* SignalConversion: '<S236>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[1] = rtDW.Divide_a[1];

    /* SignalConversion: '<S236>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[1] = rtDW.Divide_a[1];

    /* SignalConversion: '<S236>/OutportBufferFornull_MTQ_cmd_Am2' */
    rtDW.Merge1[2] = rtDW.Divide_a[2];

    /* SignalConversion: '<S236>/OutportBufferFornull_RWA_cmd_Nm' */
    rtDW.Merge[2] = rtDW.Divide_a[2];

    /* End of Outputs for SubSystem: '<S228>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S228>/case_asm' incorporates:
     *  ActionPort: '<S234>/Action Port'
     */
    /* S-Function (sdspdiag2): '<S242>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S242>/J_w_wheel_kgm2'
     */
    memset(&rtDW.CreateDiagonalMatrix_i[0], 0, sizeof(real_T) << 4U);
    rtDW.CreateDiagonalMatrix_i[0] = rtP.fswParams.allocator.inertia[0];
    rtDW.CreateDiagonalMatrix_i[5] = rtP.fswParams.allocator.inertia[1];
    rtDW.CreateDiagonalMatrix_i[10] = rtP.fswParams.allocator.inertia[2];
    rtDW.CreateDiagonalMatrix_i[15] = rtP.fswParams.allocator.inertia[3];

    /* Sum: '<S241>/Sum of Elements' incorporates:
     *  Math: '<S241>/Math Function'
     */
    rtDW.Sqrt_g = rtDW.Subtract_a[0] * rtDW.Subtract_a[0];
    rtDW.Sqrt_g += rtDW.Subtract_a[1] * rtDW.Subtract_a[1];
    rtDW.Sqrt_g += rtDW.Subtract_a[2] * rtDW.Subtract_a[2];

    /* Math: '<S241>/Math Function1'
     *
     * About '<S241>/Math Function1':
     *  Operator: sqrt
     */
    if (rtDW.Sqrt_g < 0.0) {
      rtDW.Sqrt_g = -sqrt(fabs(rtDW.Sqrt_g));
    } else {
      rtDW.Sqrt_g = sqrt(rtDW.Sqrt_g);
    }

    /* End of Math: '<S241>/Math Function1' */

    /* Switch: '<S241>/Switch' incorporates:
     *  Constant: '<S241>/Constant'
     *  Product: '<S241>/Product'
     */
    if (rtDW.Sqrt_g > rtP.NormalizeVector_maxzero) {
      rtDW.Switch_mo[0] = rtDW.Subtract_a[0];
      rtDW.Switch_mo[1] = rtDW.Subtract_a[1];
      rtDW.Switch_mo[2] = rtDW.Subtract_a[2];
      rtDW.Switch_mo[3] = rtDW.Sqrt_g;
    } else {
      rtDW.Switch_mo[0] = rtDW.Subtract_a[0] * 0.0;
      rtDW.Switch_mo[1] = rtDW.Subtract_a[1] * 0.0;
      rtDW.Switch_mo[2] = rtDW.Subtract_a[2] * 0.0;
      rtDW.Switch_mo[3] = rtP.Constant_Value_h;
    }

    /* End of Switch: '<S241>/Switch' */

    /* Product: '<S241>/Divide' */
    rtDW.nT2T[0] = rtDW.Switch_mo[0] / rtDW.Switch_mo[3];
    rtDW.nT2T[1] = rtDW.Switch_mo[1] / rtDW.Switch_mo[3];
    rtDW.nT2T[2] = rtDW.Switch_mo[2] / rtDW.Switch_mo[3];

    /* Product: '<S242>/Matrix Multiply1' incorporates:
     *  Constant: '<S242>/A_wheel2body '
     */
    for (rtDW.i_d = 0; rtDW.i_d < 4; rtDW.i_d++) {
      rtDW.epsb_1980 = rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 12] *
        rtDW.RPM2Radps[3] + (rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 8] *
        rtDW.RPM2Radps[2] + (rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 4] *
        rtDW.RPM2Radps[1] + rtDW.CreateDiagonalMatrix_i[rtDW.i_d] *
        rtDW.RPM2Radps[0]));
      rtDW.Switch_mo[rtDW.i_d] = rtDW.epsb_1980;
    }

    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      /* Sum: '<S242>/Subtract1' incorporates:
       *  Constant: '<S242>/A_wheel2body '
       *  Product: '<S242>/Matrix Multiply4'
       */
      rtDW.QOMS4 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 3];
      rtDW.deps_1980 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 6];
      rtDW.epsb_1980 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 9];
      rtDW.dpsi_1980 = rtDW.epsb_1980 * rtDW.Switch_mo[3] + (rtDW.deps_1980 *
        rtDW.Switch_mo[2] + (rtDW.QOMS4 * rtDW.Switch_mo[1] +
        rtP.fswParams.allocator.A_wheel2body[rtDW.i_d] * rtDW.Switch_mo[0]));

      /* Sum: '<S242>/Subtract1' incorporates:
       *  Constant: '<S242>/A_wheel2body '
       *  Constant: '<S242>/h_targ_wheel_Nms'
       *  Constant: '<S242>/scParams.J '
       *  Product: '<S242>/Matrix Multiply'
       *  Product: '<S242>/Matrix Multiply4'
       */
      rtDW.ss_2_body[rtDW.i_d] = ((((rtDW.QOMS4 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[1] +
        rtP.fswParams.allocator.A_wheel2body[rtDW.i_d] *
        rtP.fswParams.allocator.h_targ_wheel_Nms[0]) + rtDW.deps_1980 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[2]) + rtDW.epsb_1980 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[3]) - rtDW.dpsi_1980) -
        (rtP.fswParams.scParams.J[rtDW.i_d + 6] * rtDW.MathFunction_i[2] +
         (rtP.fswParams.scParams.J[rtDW.i_d + 3] * rtDW.MathFunction_i[1] +
          rtP.fswParams.scParams.J[rtDW.i_d] * rtDW.MathFunction_i[0]));
    }

    /* End of Product: '<S242>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S240>/twonorm' */
    rtDW.Sqrt_g = twonorm(rtDW.Subtract_a);

    /* End of Outputs for SubSystem: '<S240>/twonorm' */

    /* Sum: '<S246>/Add3' incorporates:
     *  Product: '<S246>/Element product'
     */
    rtDW.epsb_1980 = rtDW.ss_2_body[1] * rtDW.nT2T[2] - rtDW.ss_2_body[2] *
      rtDW.nT2T[1];
    rtDW.dpsi_1980 = rtDW.ss_2_body[2] * rtDW.nT2T[0] - rtDW.ss_2_body[0] *
      rtDW.nT2T[2];
    rtDW.u_moon = rtDW.ss_2_body[0] * rtDW.nT2T[1] - rtDW.ss_2_body[1] *
      rtDW.nT2T[0];
    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      /* Sum: '<S243>/Subtract2' incorporates:
       *  Product: '<S243>/Matrix Multiply7'
       */
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d] = rtConstB.IdentityMatrix_e[rtDW.i_d] -
        rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[0];
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] = rtConstB.IdentityMatrix_e[rtDW.i_d +
        3] - rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[1];
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] = rtConstB.IdentityMatrix_e[rtDW.i_d +
        6] - rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[2];

      /* Product: '<S244>/Divide' incorporates:
       *  Gain: '<S244>/Gain'
       *  Gain: '<S244>/Gain3'
       */
      rtDW.Merge1[rtDW.i_d] = rtP.Gain_Gain *
        (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 6] * rtDW.u_moon +
         (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 3] *
          rtDW.dpsi_1980 + rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d] *
          rtDW.epsb_1980)) / rtDW.Sqrt_g;
      rtDW.TmpSignalConversionAtProduc[rtDW.i_d] =
        rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] * rtDW.ss_2_body[2] +
        (rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] * rtDW.ss_2_body[1] +
         rtDW.rtb_Gain_d_tmp_f[rtDW.i_d] * rtDW.ss_2_body[0]);
    }

    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      rtDW.epsb_1980 = rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 6] *
        rtDW.TmpSignalConversionAtProduc[2] +
        (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 3] *
         rtDW.TmpSignalConversionAtProduc[1] +
         rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d] *
         rtDW.TmpSignalConversionAtProduc[0]);

      /* Gain: '<S240>/DutyCycleAdjustment' incorporates:
       *  Gain: '<S243>/Gain'
       */
      rtDW.nT2T[rtDW.i_d] = rtP.DutyCycleAdjustment_Gain * rtDW.epsb_1980;
      rtDW.ss_2_body[rtDW.i_d] = rtDW.epsb_1980;
    }

    /* Outputs for Atomic SubSystem: '<S234>/asmController_lib' */
    asmController_lib(rtDW.Divide_a, rtDW.ss_2_body);

    /* End of Outputs for SubSystem: '<S234>/asmController_lib' */

    /* Sum: '<S234>/Sum' incorporates:
     *  Gain: '<S243>/Gain'
     *  Product: '<S243>/Matrix Multiply8'
     */
    rtDW.Merge[0] = rtDW.ss_2_body[0] + rtDW.nT2T[0];
    rtDW.Merge[1] = rtDW.ss_2_body[1] + rtDW.nT2T[1];
    rtDW.Merge[2] = rtDW.ss_2_body[2] + rtDW.nT2T[2];

    /* End of Outputs for SubSystem: '<S228>/case_asm' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S228>/case_sunseek' incorporates:
     *  ActionPort: '<S238>/Action Port'
     */
    /* SignalConversion: '<S238>/OutportBuffer_InsertedFor_sunseek_MTQ_cmd_Am2_at_inport_0' incorporates:
     *  Constant: '<S238>/Constant'
     */
    rtDW.Merge1[0] = rtP.Constant_Value_l[0];
    rtDW.Merge1[1] = rtP.Constant_Value_l[1];
    rtDW.Merge1[2] = rtP.Constant_Value_l[2];

    /* Outputs for Atomic SubSystem: '<S238>/sunSeek_lib' */
    sunSeek_lib(rtDW.Merge_b, rtDW.nT2T, rtDW.ss_2_body, rtDW.Divide_a,
                rtDW.Merge, &rtDW.sunSeek_lib_j, &rtP.sunSeek_lib_j);

    /* End of Outputs for SubSystem: '<S238>/sunSeek_lib' */
    /* End of Outputs for SubSystem: '<S228>/case_sunseek' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S228>/case_desaturation' incorporates:
     *  ActionPort: '<S235>/Action Port'
     */
    /* S-Function (sdspdiag2): '<S250>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S250>/J_w_wheel_kgm2'
     */
    memset(&rtDW.CreateDiagonalMatrix_i[0], 0, sizeof(real_T) << 4U);
    rtDW.CreateDiagonalMatrix_i[0] = rtP.fswParams.allocator.inertia[0];
    rtDW.CreateDiagonalMatrix_i[5] = rtP.fswParams.allocator.inertia[1];
    rtDW.CreateDiagonalMatrix_i[10] = rtP.fswParams.allocator.inertia[2];
    rtDW.CreateDiagonalMatrix_i[15] = rtP.fswParams.allocator.inertia[3];

    /* Sum: '<S249>/Sum of Elements' incorporates:
     *  Math: '<S249>/Math Function'
     */
    rtDW.Sqrt_g = rtDW.Subtract_a[0] * rtDW.Subtract_a[0];
    rtDW.Sqrt_g += rtDW.Subtract_a[1] * rtDW.Subtract_a[1];
    rtDW.Sqrt_g += rtDW.Subtract_a[2] * rtDW.Subtract_a[2];

    /* Math: '<S249>/Math Function1'
     *
     * About '<S249>/Math Function1':
     *  Operator: sqrt
     */
    if (rtDW.Sqrt_g < 0.0) {
      rtDW.Sqrt_g = -sqrt(fabs(rtDW.Sqrt_g));
    } else {
      rtDW.Sqrt_g = sqrt(rtDW.Sqrt_g);
    }

    /* End of Math: '<S249>/Math Function1' */

    /* Switch: '<S249>/Switch' incorporates:
     *  Constant: '<S249>/Constant'
     *  Product: '<S249>/Product'
     */
    if (rtDW.Sqrt_g > rtP.NormalizeVector_maxzero_c) {
      rtDW.Switch_mo[0] = rtDW.Subtract_a[0];
      rtDW.Switch_mo[1] = rtDW.Subtract_a[1];
      rtDW.Switch_mo[2] = rtDW.Subtract_a[2];
      rtDW.Switch_mo[3] = rtDW.Sqrt_g;
    } else {
      rtDW.Switch_mo[0] = rtDW.Subtract_a[0] * 0.0;
      rtDW.Switch_mo[1] = rtDW.Subtract_a[1] * 0.0;
      rtDW.Switch_mo[2] = rtDW.Subtract_a[2] * 0.0;
      rtDW.Switch_mo[3] = rtP.Constant_Value_m;
    }

    /* End of Switch: '<S249>/Switch' */

    /* Product: '<S249>/Divide' */
    rtDW.nT2T[0] = rtDW.Switch_mo[0] / rtDW.Switch_mo[3];
    rtDW.nT2T[1] = rtDW.Switch_mo[1] / rtDW.Switch_mo[3];
    rtDW.nT2T[2] = rtDW.Switch_mo[2] / rtDW.Switch_mo[3];

    /* Product: '<S250>/Matrix Multiply1' incorporates:
     *  Constant: '<S250>/A_wheel2body '
     */
    for (rtDW.i_d = 0; rtDW.i_d < 4; rtDW.i_d++) {
      rtDW.epsb_1980 = rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 12] *
        rtDW.RPM2Radps[3] + (rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 8] *
        rtDW.RPM2Radps[2] + (rtDW.CreateDiagonalMatrix_i[rtDW.i_d + 4] *
        rtDW.RPM2Radps[1] + rtDW.CreateDiagonalMatrix_i[rtDW.i_d] *
        rtDW.RPM2Radps[0]));
      rtDW.Switch_mo[rtDW.i_d] = rtDW.epsb_1980;
    }

    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      /* Sum: '<S250>/Subtract1' incorporates:
       *  Constant: '<S250>/A_wheel2body '
       *  Product: '<S250>/Matrix Multiply4'
       */
      rtDW.QOMS4 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 3];
      rtDW.deps_1980 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 6];
      rtDW.epsb_1980 = rtP.fswParams.allocator.A_wheel2body[rtDW.i_d + 9];
      rtDW.dpsi_1980 = rtDW.epsb_1980 * rtDW.Switch_mo[3] + (rtDW.deps_1980 *
        rtDW.Switch_mo[2] + (rtDW.QOMS4 * rtDW.Switch_mo[1] +
        rtP.fswParams.allocator.A_wheel2body[rtDW.i_d] * rtDW.Switch_mo[0]));

      /* Sum: '<S250>/Subtract1' incorporates:
       *  Constant: '<S250>/A_wheel2body '
       *  Constant: '<S250>/h_targ_wheel_Nms'
       *  Constant: '<S250>/scParams.J '
       *  Product: '<S250>/Matrix Multiply'
       *  Product: '<S250>/Matrix Multiply4'
       */
      rtDW.ss_2_body[rtDW.i_d] = ((((rtDW.QOMS4 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[1] +
        rtP.fswParams.allocator.A_wheel2body[rtDW.i_d] *
        rtP.fswParams.allocator.h_targ_wheel_Nms[0]) + rtDW.deps_1980 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[2]) + rtDW.epsb_1980 *
        rtP.fswParams.allocator.h_targ_wheel_Nms[3]) - rtDW.dpsi_1980) -
        (rtP.fswParams.scParams.J[rtDW.i_d + 6] * rtDW.MathFunction_i[2] +
         (rtP.fswParams.scParams.J[rtDW.i_d + 3] * rtDW.MathFunction_i[1] +
          rtP.fswParams.scParams.J[rtDW.i_d] * rtDW.MathFunction_i[0]));
    }

    /* End of Product: '<S250>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S248>/twonorm' */
    rtDW.Sqrt_g = twonorm(rtDW.Subtract_a);

    /* End of Outputs for SubSystem: '<S248>/twonorm' */

    /* Sum: '<S254>/Add3' incorporates:
     *  Product: '<S254>/Element product'
     */
    rtDW.epsb_1980 = rtDW.ss_2_body[1] * rtDW.nT2T[2] - rtDW.ss_2_body[2] *
      rtDW.nT2T[1];
    rtDW.dpsi_1980 = rtDW.ss_2_body[2] * rtDW.nT2T[0] - rtDW.ss_2_body[0] *
      rtDW.nT2T[2];
    rtDW.u_moon = rtDW.ss_2_body[0] * rtDW.nT2T[1] - rtDW.ss_2_body[1] *
      rtDW.nT2T[0];
    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      /* Sum: '<S251>/Subtract2' incorporates:
       *  Product: '<S251>/Matrix Multiply7'
       */
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d] = rtConstB.IdentityMatrix[rtDW.i_d] -
        rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[0];
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] = rtConstB.IdentityMatrix[rtDW.i_d + 3]
        - rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[1];
      rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] = rtConstB.IdentityMatrix[rtDW.i_d + 6]
        - rtDW.nT2T[rtDW.i_d] * rtDW.nT2T[2];

      /* Product: '<S252>/Divide' incorporates:
       *  Gain: '<S252>/Gain'
       *  Gain: '<S252>/Gain3'
       */
      rtDW.Merge1[rtDW.i_d] = rtP.Gain_Gain_a *
        (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 6] * rtDW.u_moon +
         (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 3] *
          rtDW.dpsi_1980 + rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d] *
          rtDW.epsb_1980)) / rtDW.Sqrt_g;
      rtDW.TmpSignalConversionAtProduc[rtDW.i_d] =
        rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 6] * rtDW.ss_2_body[2] +
        (rtDW.rtb_Gain_d_tmp_f[rtDW.i_d + 3] * rtDW.ss_2_body[1] +
         rtDW.rtb_Gain_d_tmp_f[rtDW.i_d] * rtDW.ss_2_body[0]);
    }

    for (rtDW.i_d = 0; rtDW.i_d < 3; rtDW.i_d++) {
      rtDW.epsb_1980 = rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 6] *
        rtDW.TmpSignalConversionAtProduc[2] +
        (rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d + 3] *
         rtDW.TmpSignalConversionAtProduc[1] +
         rtP.fswParams.desatcontrollerParams.gain[rtDW.i_d] *
         rtDW.TmpSignalConversionAtProduc[0]);

      /* Gain: '<S248>/DutyCycleAdjustment' incorporates:
       *  Gain: '<S251>/Gain'
       */
      rtDW.nT2T[rtDW.i_d] = rtP.DutyCycleAdjustment_Gain_f * rtDW.epsb_1980;
      rtDW.ss_2_body[rtDW.i_d] = rtDW.epsb_1980;
    }

    /* Outputs for Atomic SubSystem: '<S235>/PD_Controller_Lib' */
    PD_Controller_Lib(rtDW.Switch_g, rtDW.Divide_a, rtDW.ss_2_body);

    /* End of Outputs for SubSystem: '<S235>/PD_Controller_Lib' */

    /* Sum: '<S235>/Sum' incorporates:
     *  Gain: '<S251>/Gain'
     *  Product: '<S251>/Matrix Multiply8'
     */
    rtDW.Merge[0] = rtDW.ss_2_body[0] + rtDW.nT2T[0];
    rtDW.Merge[1] = rtDW.ss_2_body[1] + rtDW.nT2T[1];
    rtDW.Merge[2] = rtDW.ss_2_body[2] + rtDW.nT2T[2];

    /* End of Outputs for SubSystem: '<S228>/case_desaturation' */
    break;

   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S228>/case_reorientation' incorporates:
     *  ActionPort: '<S237>/Action Port'
     */
    /* SignalConversion: '<S237>/OutportBuffer_InsertedFor_tracking_MTQ_cmd_Am2_at_inport_0' incorporates:
     *  Constant: '<S237>/Constant'
     */
    rtDW.Merge1[0] = rtP.Constant_Value_e[0];
    rtDW.Merge1[1] = rtP.Constant_Value_e[1];
    rtDW.Merge1[2] = rtP.Constant_Value_e[2];

    /* Outputs for Atomic SubSystem: '<S237>/PD_Controller_Lib' */
    PD_Controller_Lib(rtDW.Switch_g, rtDW.Divide_a, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S237>/PD_Controller_Lib' */
    /* End of Outputs for SubSystem: '<S228>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S228>/Switch Case' */

  /* Switch: '<S227>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  if (rtDW.Output <= rtP.CompareToConstant_const_p) {
    /* Product: '<S230>/Multiply2' */
    rtDW.Divide_a[0] = rtDW.Merge1[0] * rtDW.Sum_o;
    rtDW.Divide_a[1] = rtDW.Merge1[1] * rtDW.eps;

    /* Outport: '<Root>/fsw_out' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S5>/Constant'
     *  Product: '<S230>/Multiply'
     *  Product: '<S230>/Multiply1'
     */
    rtY.fsw_out_l.mtq_cmd_Am2[0] = rtDW.Divide_a[0] * rtP.Constant_Value[0] *
      (real_T)rtP.Constant_Value_mj[0];
    rtY.fsw_out_l.mtq_cmd_Am2[1] = rtDW.Divide_a[0] * rtP.Constant_Value[1] *
      (real_T)rtP.Constant_Value_mj[1];
    rtY.fsw_out_l.mtq_cmd_Am2[3] = rtDW.Divide_a[1] * rtP.Constant_Value[3] *
      (real_T)rtP.Constant_Value_mj[3];
    rtY.fsw_out_l.mtq_cmd_Am2[2] = rtDW.Divide_a[1] * rtP.Constant_Value[2] *
      (real_T)rtP.Constant_Value_mj[2];

    /* Switch: '<S230>/Switch' incorporates:
     *  Constant: '<S230>/Constant1'
     *  Constant: '<S230>/Constant2'
     *  Constant: '<S5>/Constant'
     */
    if (rtP.Constant_Value_mj[4]) {
      rtDW.QOMS4 = rtP.Constant1_Value;
    } else {
      rtDW.QOMS4 = rtP.Constant2_Value;
    }

    /* End of Switch: '<S230>/Switch' */

    /* Outport: '<Root>/fsw_out' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S5>/Constant'
     *  Product: '<S230>/Multiply'
     *  Product: '<S230>/Multiply1'
     *  Product: '<S230>/Multiply2'
     */
    rtY.fsw_out_l.mtq_cmd_Am2[4] = rtDW.Merge1[2] * rtDW.QOMS4 *
      rtP.Constant_Value[4] * (real_T)rtP.Constant_Value_mj[4];
  } else {
    /* Outport: '<Root>/fsw_out' incorporates:
     *  Constant: '<S227>/mtq_off_cmd'
     */
    for (rtDW.i_d = 0; rtDW.i_d < 5; rtDW.i_d++) {
      rtY.fsw_out_l.mtq_cmd_Am2[rtDW.i_d] = rtP.mtq_off_cmd_Value[rtDW.i_d];
    }
  }

  /* End of Switch: '<S227>/Switch' */

  /* Sum: '<S5>/Sum' */
  rtDW.pos_teme_km[0] += rtDW.Merge[0];
  rtDW.pos_teme_km[1] += rtDW.Merge[1];
  rtDW.pos_teme_km[2] += rtDW.Merge[2];

  /* Outputs for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
  rwa_allocation_lib(rtDW.pos_teme_km, rtDW.RPM2Radps, rtDW.RateTransition2_p,
                     rtDW.Switch_mo, &rtDW.rwa_allocation_lib_h,
                     &rtP.rwa_allocation_lib_h);

  /* End of Outputs for SubSystem: '<S5>/rwa_allocation_lib' */

  /* Outputs for Atomic SubSystem: '<S288>/target_groundpass_lib' */
  /* Constant: '<S288>/Constant' incorporates:
   *  Constant: '<S288>/Constant1'
   *  Constant: '<S288>/Constant2'
   */
  target_groundpass_lib(rtDW.tod_to_mod_tmp, rtP.fswParams.ground_targs[0].
                        ecef_m, rtP.fswParams.ground_targs[0].lat_gd_deg,
                        rtP.fswParams.ground_targs[0].lon_deg, &rtDW.Compare_mg,
                        &rtDW.Sqrt_g, rtDW.pos_teme_km,
                        &rtDW.target_groundpass_lib_f,
                        &rtP.target_groundpass_lib_f,
                        rtP.target_groundpass_lib_id);

  /* End of Outputs for SubSystem: '<S288>/target_groundpass_lib' */

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  Constant: '<S233>/Constant'
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  rtDW.Sum_o = rtP.fswParams.allocator.inv_inertia[0] *
    rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    rtP.fswParams.constants.convert.RPS2RPM;

  /* Saturate: '<S233>/Saturation' */
  if (rtDW.Sum_o > rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[0] = rtP.fswParams.allocator.max_RPM;
  } else if (rtDW.Sum_o < -rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[0] = -rtP.fswParams.allocator.max_RPM;
  } else {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[0] = rtDW.Sum_o;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  Constant: '<S233>/Constant'
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  rtDW.Sum_o = rtP.fswParams.allocator.inv_inertia[1] *
    rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    rtP.fswParams.constants.convert.RPS2RPM;

  /* Saturate: '<S233>/Saturation' */
  if (rtDW.Sum_o > rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[1] = rtP.fswParams.allocator.max_RPM;
  } else if (rtDW.Sum_o < -rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[1] = -rtP.fswParams.allocator.max_RPM;
  } else {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[1] = rtDW.Sum_o;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  Constant: '<S233>/Constant'
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  rtDW.Sum_o = rtP.fswParams.allocator.inv_inertia[2] *
    rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    rtP.fswParams.constants.convert.RPS2RPM;

  /* Saturate: '<S233>/Saturation' */
  if (rtDW.Sum_o > rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[2] = rtP.fswParams.allocator.max_RPM;
  } else if (rtDW.Sum_o < -rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[2] = -rtP.fswParams.allocator.max_RPM;
  } else {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[2] = rtDW.Sum_o;
  }

  /* Gain: '<S233>/radps_2_rpm' incorporates:
   *  Constant: '<S233>/Constant'
   *  DiscreteIntegrator: '<S233>/Discrete-Time Integrator'
   *  Product: '<S233>/Product'
   */
  rtDW.Sum_o = rtP.fswParams.allocator.inv_inertia[3] *
    rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    rtP.fswParams.constants.convert.RPS2RPM;

  /* Saturate: '<S233>/Saturation' */
  if (rtDW.Sum_o > rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[3] = rtP.fswParams.allocator.max_RPM;
  } else if (rtDW.Sum_o < -rtP.fswParams.allocator.max_RPM) {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[3] = -rtP.fswParams.allocator.max_RPM;
  } else {
    /* Outport: '<Root>/fsw_out' */
    rtY.fsw_out_l.rwa_cmd_rpm[3] = rtDW.Sum_o;
  }

  /* Saturate: '<S229>/Saturation' */
  if (rtDW.Switch_g[0] > rtP.Saturation_UpperSat) {
    rtDW.Sum_o = rtP.Saturation_UpperSat;
  } else if (rtDW.Switch_g[0] < rtP.Saturation_LowerSat) {
    rtDW.Sum_o = rtP.Saturation_LowerSat;
  } else {
    rtDW.Sum_o = rtDW.Switch_g[0];
  }

  /* End of Saturate: '<S229>/Saturation' */

  /* Sum: '<S20>/FixPt Sum1' incorporates:
   *  Constant: '<S20>/FixPt Constant'
   */
  rtDW.Output = (uint8_T)((uint32_T)rtDW.Output + rtP.FixPtConstant_Value);

  /* Switch: '<S21>/FixPt Switch' */
  if (rtDW.Output > rtP.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S19>/Output' incorporates:
     *  Constant: '<S21>/Constant'
     */
    rtDW.Output_DSTATE = rtP.Constant_Value_js;
  } else {
    /* Update for UnitDelay: '<S19>/Output' */
    rtDW.Output_DSTATE = rtDW.Output;
  }

  /* End of Switch: '<S21>/FixPt Switch' */

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = rtDW.Subtract_a[0];
  rtDW.UnitDelay_DSTATE[1] = rtDW.Subtract_a[1];
  rtDW.UnitDelay_DSTATE[2] = rtDW.Subtract_a[2];

  /* Update for DiscreteIntegrator: '<S233>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += rtP.DiscreteTimeIntegrator_gainval *
    rtDW.Switch_mo[0];
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += rtP.DiscreteTimeIntegrator_gainval *
    rtDW.Switch_mo[1];
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += rtP.DiscreteTimeIntegrator_gainval *
    rtDW.Switch_mo[2];
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += rtP.DiscreteTimeIntegrator_gainval *
    rtDW.Switch_mo[3];

  /* Update for RateTransition: '<S1>/Rate Transition4' */
  rtDW.RateTransition4_1_Buffer0 = rtDW.gnc_mode_a;
  rtDW.RateTransition4_2_Buffer0[0] = rtDW.q_p_merge[0];
  rtDW.RateTransition4_2_Buffer0[1] = rtDW.q_p_merge[1];
  rtDW.RateTransition4_2_Buffer0[2] = rtDW.q_p_merge[2];
  rtDW.RateTransition4_2_Buffer0[3] = rtDW.q_p_merge[3];
  rtDW.RateTransition4_3_Buffer0[0] = rtDW.MathFunction_i[0];
  rtDW.RateTransition4_3_Buffer0[1] = rtDW.MathFunction_i[1];
  rtDW.RateTransition4_3_Buffer0[2] = rtDW.MathFunction_i[2];
  rtDW.RateTransition4_4_Buffer0[0] = rtDW.RateTransition6[0];
  rtDW.RateTransition4_4_Buffer0[1] = rtDW.RateTransition6[1];
  rtDW.RateTransition4_4_Buffer0[2] = rtDW.RateTransition6[2];
  rtDW.RateTransition4_4_Buffer0[3] = rtDW.RateTransition6[3];
  rtDW.RateTransition4_5_Buffer0[0] = rtDW.AU2KM[0];
  rtDW.RateTransition4_5_Buffer0[1] = rtDW.AU2KM[1];
  rtDW.RateTransition4_5_Buffer0[2] = rtDW.AU2KM[2];
  for (rtDW.i_d = 0; rtDW.i_d < 6; rtDW.i_d++) {
    rtDW.RateTransition4_6_Buffer0[rtDW.i_d] = rtDW.YMDHMS_UTC[rtDW.i_d];
  }

  rtDW.RateTransition4_7_Buffer0[0] = rtDW.bias_merge[0];
  rtDW.RateTransition4_7_Buffer0[1] = rtDW.bias_merge[1];
  rtDW.RateTransition4_7_Buffer0[2] = rtDW.bias_merge[2];
  rtDW.RateTransition4_8_Buffer0 = rtDW.Merge_n_j;
  rtDW.RateTransition4_9_Buffer0[0] = rtDW.Gain_d[0];
  rtDW.RateTransition4_9_Buffer0[1] = rtDW.Gain_d[1];
  rtDW.RateTransition4_9_Buffer0[2] = rtDW.Gain_d[2];

  /* Trigonometry: '<S229>/Acos' */
  if (rtDW.Sum_o > 1.0) {
    rtDW.Sum_o = 1.0;
  } else {
    if (rtDW.Sum_o < -1.0) {
      rtDW.Sum_o = -1.0;
    }
  }

  /* Update for RateTransition: '<S1>/Rate Transition4' incorporates:
   *  Abs: '<S229>/Abs'
   *  BusCreator: '<S1>/BusConversion_InsertedFor_Bus Assignment1_at_inport_19'
   *  Gain: '<S229>/Gain'
   *  Gain: '<S229>/RAD2DEG'
   *  Trigonometry: '<S229>/Acos'
   */
  rtDW.RateTransition4_10_Buffer0 = fabs(rtP.Gain_Gain_h * acos(rtDW.Sum_o) *
    rtP.fswParams.constants.convert.RAD2DEG);
  rtDW.RateTransition4_11_Buffer0 = rtDW.light;
  rtDW.RateTransition4_12_Buffer0 = rtDW.flag_b1;
  rtDW.RateTransition4_13_Buffer0 = rtDW.Compare_mg;
  rtDW.RateTransition4_14_Buffer0 = rtDW.lowAlt;
  rtDW.RateTransition4_15_Buffer0 = rtDW.Switch3;
  rtDW.RateTransition4_16_Buffer0 = rtDW.Sqrt_g;
  rtDW.RateTransition4_17_Buffer0 = rtDW.tsince;
  rtDW.RateTransition4_18_Buffer0 = rtDW.Merge_b;
  memcpy(&rtDW.RateTransition4_19_Buffer0.opt_state[0], &rtDW.X_l[0], 100U *
         sizeof(real_T));
  memcpy(&rtDW.RateTransition4_19_Buffer0.opt_ctrl_Nm[0], &rtDW.U[0], 30U *
         sizeof(real_T));
  rtDW.RateTransition4_19_Buffer0.final_time_s = rtDW.s;
  memcpy(&rtDW.RateTransition4_19_Buffer0.exitcode[0], &rtDW.exitcode[0], 17U *
         sizeof(real_T));
}

/* Model initialize function */
void FSW_Lib0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;

    /* Start for Atomic SubSystem: '<S1>/MEKF_lib' */
    MEKF_lib_Start(&rtDW.MEKF_lib_k);

    /* End of Start for SubSystem: '<S1>/MEKF_lib' */

    /* Start for RateTransition: '<S1>/Rate Transition4' */
    rtDW.gnc_mode = rtP.RateTransition4_1_InitialCondit;
    rtDW.sc_quat[0] = rtP.RateTransition4_2_InitialCondit;
    rtDW.sc_quat[1] = rtP.RateTransition4_2_InitialCondit;
    rtDW.sc_quat[2] = rtP.RateTransition4_2_InitialCondit;
    rtDW.sc_quat[3] = rtP.RateTransition4_2_InitialCondit;
    rtDW.sc_body_rates_radps[0] = rtP.RateTransition4_3_InitialCondit;
    rtDW.sc_body_rates_radps[1] = rtP.RateTransition4_3_InitialCondit;
    rtDW.sc_body_rates_radps[2] = rtP.RateTransition4_3_InitialCondit;
    rtDW.cmd_quat[0] = rtP.RateTransition4_4_InitialCondit;
    rtDW.cmd_quat[1] = rtP.RateTransition4_4_InitialCondit;
    rtDW.cmd_quat[2] = rtP.RateTransition4_4_InitialCondit;
    rtDW.cmd_quat[3] = rtP.RateTransition4_4_InitialCondit;
    rtDW.cmd_body_rates_radps[0] = rtP.RateTransition4_5_InitialCondit;
    rtDW.cmd_body_rates_radps[1] = rtP.RateTransition4_5_InitialCondit;
    rtDW.cmd_body_rates_radps[2] = rtP.RateTransition4_5_InitialCondit;
    for (i = 0; i < 6; i++) {
      rtDW.mekf_3sigma_rad[i] = rtP.RateTransition4_6_InitialCondit;
    }

    rtDW.mekf_telem = rtP.RateTransition4_8_InitialCondit;
    rtDW.mekf_bias_radps[0] = rtP.RateTransition4_7_InitialCondit;
    rtDW.r_eci_m[0] = rtP.RateTransition4_9_InitialCondit;
    rtDW.mekf_bias_radps[1] = rtP.RateTransition4_7_InitialCondit;
    rtDW.r_eci_m[1] = rtP.RateTransition4_9_InitialCondit;
    rtDW.mekf_bias_radps[2] = rtP.RateTransition4_7_InitialCondit;
    rtDW.r_eci_m[2] = rtP.RateTransition4_9_InitialCondit;
    rtDW.ace_err = rtP.RateTransition4_10_InitialCondi;
    rtDW.eclipse = rtP.RateTransition4_11_InitialCondi;
    rtDW.sgp4_flag = rtP.RateTransition4_12_InitialCondi;
    rtDW.sc_above_gs = rtP.RateTransition4_13_InitialCondi;
    rtDW.sc_above_targ = rtP.RateTransition4_14_InitialCondi;
    rtDW.target_gen_flag = rtP.RateTransition4_15_InitialCondi;
    rtDW.elev_gs_rad = rtP.RateTransition4_16_InitialCondi;
    rtDW.elev_targ_rad = rtP.RateTransition4_17_InitialCondi;
    rtDW.ss_valid = rtP.RateTransition4_18_InitialCondi;
    rtDW.soar_telemetry_n = rtP.RateTransition4_19_InitialCondi;

    /* End of Start for RateTransition: '<S1>/Rate Transition4' */
    rtPrevZCX.ResettableDelay_Reset_ZCE = POS_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S19>/Output' */
    rtDW.Output_DSTATE = rtP.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    rtDW.UnitDelay_DSTATE[0] = rtP.UnitDelay_InitialCondition_p[0];
    rtDW.UnitDelay_DSTATE[1] = rtP.UnitDelay_InitialCondition_p[1];
    rtDW.UnitDelay_DSTATE[2] = rtP.UnitDelay_InitialCondition_p[2];

    /* InitializeConditions for DiscreteIntegrator: '<S233>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE[0] =
      rtP.simParams.initialConditions.rwa.h_wheel_Nms[0];
    rtDW.DiscreteTimeIntegrator_DSTATE[1] =
      rtP.simParams.initialConditions.rwa.h_wheel_Nms[1];
    rtDW.DiscreteTimeIntegrator_DSTATE[2] =
      rtP.simParams.initialConditions.rwa.h_wheel_Nms[2];
    rtDW.DiscreteTimeIntegrator_DSTATE[3] =
      rtP.simParams.initialConditions.rwa.h_wheel_Nms[3];

    /* InitializeConditions for RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4_1_Buffer0 = rtP.RateTransition4_1_InitialCondit;
    rtDW.RateTransition4_2_Buffer0[0] = rtP.RateTransition4_2_InitialCondit;
    rtDW.RateTransition4_2_Buffer0[1] = rtP.RateTransition4_2_InitialCondit;
    rtDW.RateTransition4_2_Buffer0[2] = rtP.RateTransition4_2_InitialCondit;
    rtDW.RateTransition4_2_Buffer0[3] = rtP.RateTransition4_2_InitialCondit;
    rtDW.RateTransition4_3_Buffer0[0] = rtP.RateTransition4_3_InitialCondit;
    rtDW.RateTransition4_3_Buffer0[1] = rtP.RateTransition4_3_InitialCondit;
    rtDW.RateTransition4_3_Buffer0[2] = rtP.RateTransition4_3_InitialCondit;
    rtDW.RateTransition4_4_Buffer0[0] = rtP.RateTransition4_4_InitialCondit;
    rtDW.RateTransition4_4_Buffer0[1] = rtP.RateTransition4_4_InitialCondit;
    rtDW.RateTransition4_4_Buffer0[2] = rtP.RateTransition4_4_InitialCondit;
    rtDW.RateTransition4_4_Buffer0[3] = rtP.RateTransition4_4_InitialCondit;
    rtDW.RateTransition4_5_Buffer0[0] = rtP.RateTransition4_5_InitialCondit;
    rtDW.RateTransition4_5_Buffer0[1] = rtP.RateTransition4_5_InitialCondit;
    rtDW.RateTransition4_5_Buffer0[2] = rtP.RateTransition4_5_InitialCondit;
    for (i = 0; i < 6; i++) {
      rtDW.RateTransition4_6_Buffer0[i] = rtP.RateTransition4_6_InitialCondit;
    }

    rtDW.RateTransition4_7_Buffer0[0] = rtP.RateTransition4_7_InitialCondit;
    rtDW.RateTransition4_7_Buffer0[1] = rtP.RateTransition4_7_InitialCondit;
    rtDW.RateTransition4_7_Buffer0[2] = rtP.RateTransition4_7_InitialCondit;
    rtDW.RateTransition4_8_Buffer0 = rtP.RateTransition4_8_InitialCondit;
    rtDW.RateTransition4_9_Buffer0[0] = rtP.RateTransition4_9_InitialCondit;
    rtDW.RateTransition4_9_Buffer0[1] = rtP.RateTransition4_9_InitialCondit;
    rtDW.RateTransition4_9_Buffer0[2] = rtP.RateTransition4_9_InitialCondit;
    rtDW.RateTransition4_10_Buffer0 = rtP.RateTransition4_10_InitialCondi;
    rtDW.RateTransition4_11_Buffer0 = rtP.RateTransition4_11_InitialCondi;
    rtDW.RateTransition4_12_Buffer0 = rtP.RateTransition4_12_InitialCondi;
    rtDW.RateTransition4_13_Buffer0 = rtP.RateTransition4_13_InitialCondi;
    rtDW.RateTransition4_14_Buffer0 = rtP.RateTransition4_14_InitialCondi;
    rtDW.RateTransition4_15_Buffer0 = rtP.RateTransition4_15_InitialCondi;
    rtDW.RateTransition4_16_Buffer0 = rtP.RateTransition4_16_InitialCondi;
    rtDW.RateTransition4_17_Buffer0 = rtP.RateTransition4_17_InitialCondi;
    rtDW.RateTransition4_18_Buffer0 = rtP.RateTransition4_18_InitialCondi;
    rtDW.RateTransition4_19_Buffer0 = rtP.RateTransition4_19_InitialCondi;

    /* End of InitializeConditions for RateTransition: '<S1>/Rate Transition4' */

    /* SystemInitialize for Iterator SubSystem: '<S349>/While Iterator Subsystem' */
    /* InitializeConditions for Memory: '<S372>/Memory' */
    rtDW.Memory_PreviousInput = rtP.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S349>/While Iterator Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib' */
    maggyroProcessing_lib_Init(&rtDW.maggyroProcessing_lib_j);

    /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib' */

    /* SystemInitialize for Atomic SubSystem: '<S2>/maggyroProcessing_lib1' */
    maggyroProcessing_lib_Init(&rtDW.maggyroProcessing_lib1);

    /* End of SystemInitialize for SubSystem: '<S2>/maggyroProcessing_lib1' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/MEKF_lib' */
    MEKF_lib_Init(rtDW.q_p_merge, &rtDW.MEKF_lib_k, &rtP.MEKF_lib_k);

    /* End of SystemInitialize for SubSystem: '<S1>/MEKF_lib' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/target_generation_lib' */
    target_generation_lib_Init(rtDW.X_l, rtDW.U, &rtDW.s, rtDW.exitcode);

    /* End of SystemInitialize for SubSystem: '<S1>/target_generation_lib' */

    /* SystemInitialize for Merge: '<S228>/Merge1' */
    rtDW.Merge1[0] = rtP.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S228>/Merge' */
    rtDW.Merge[0] = rtP.Merge_InitialOutput_f;

    /* SystemInitialize for Merge: '<S228>/Merge1' */
    rtDW.Merge1[1] = rtP.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S228>/Merge' */
    rtDW.Merge[1] = rtP.Merge_InitialOutput_f;

    /* SystemInitialize for Merge: '<S228>/Merge1' */
    rtDW.Merge1[2] = rtP.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S228>/Merge' */
    rtDW.Merge[2] = rtP.Merge_InitialOutput_f;

    /* SystemInitialize for Atomic SubSystem: '<S5>/rwa_allocation_lib' */
    rwa_allocation_lib_Init(&rtDW.rwa_allocation_lib_h,
      &rtP.rwa_allocation_lib_h);

    /* End of SystemInitialize for SubSystem: '<S5>/rwa_allocation_lib' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
