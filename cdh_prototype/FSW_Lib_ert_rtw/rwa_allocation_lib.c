/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "rwa_allocation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

void rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  real_T x[9];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  memcpy(&x[0], &u[0], 9U * sizeof(real_T));
  p1 = 1;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(u[0]);
  absx21 = fabs(u[1]);
  absx31 = fabs(u[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 4;
    p2 = 0;
    x[0] = u[1];
    x[1] = u[0];
    x[3] = u[4];
    x[4] = u[3];
    x[6] = u[7];
    x[7] = u[6];
  } else {
    if (absx31 > absx11) {
      p1 = 7;
      p3 = 0;
      x[2] = x[0];
      x[0] = u[2];
      x[5] = x[3];
      x[3] = u[5];
      x[8] = x[6];
      x[6] = u[8];
    }
  }

  absx31 = x[1] / x[0];
  x[1] = absx31;
  absx11 = x[2] / x[0];
  x[2] = absx11;
  x[4] -= absx31 * x[3];
  x[5] -= absx11 * x[3];
  x[7] -= absx31 * x[6];
  x[8] -= absx11 * x[6];
  if (fabs(x[5]) > fabs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    x[1] = absx11;
    x[2] = absx31;
    absx11 = x[4];
    x[4] = x[5];
    x[5] = absx11;
    absx11 = x[7];
    x[7] = x[8];
    x[8] = absx11;
  }

  absx31 = x[5] / x[4];
  x[8] -= absx31 * x[7];
  absx11 = (absx31 * x[1] - x[2]) / x[8];
  absx21 = -(x[7] * absx11 + x[1]) / x[4];
  y[p1 - 1] = ((1.0 - x[3] * absx21) - x[6] * absx11) / x[0];
  y[p1] = absx21;
  y[p1 + 1] = absx11;
  absx11 = -absx31 / x[8];
  absx21 = (1.0 - x[7] * absx11) / x[4];
  y[p2] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / x[8];
  absx21 = -x[7] * absx11 / x[4];
  y[p3] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

/* Output and update for atomic system: '<S6>/rwa_allocation_lib' */
void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_radps[4], const boolean_T rtu_rwa_valid[4], real_T
  rty_torque_wheel_Nm[4], const ConstB_rwa_allocation_lib *localC,
  DW_rwa_allocation_lib *localDW)
{
  static const int8_T a[32] = { 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1 };

  real_T rtb_A_out[9];
  real_T tmp_0[9];
  real_T temp[8];
  real_T h_err_null_norm[4];
  real_T id_good[3];
  real_T n_whl;
  real_T rtb_Product_da;
  real_T tmp_1;
  int32_T nz;
  int32_T rtb_A_out_tmp;
  uint8_T n_whl_0;
  boolean_T exitg1;
  boolean_T tmp;

  /* If: '<S91>/If' */
  if (localC->all_valid) {
    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem' incorporates:
     *  ActionPort: '<S134>/Action Port'
     */
    /* MATLAB Function: '<S137>/MATLAB Function' */
    h_err_null_norm[0] = 0.0029991968249731822 - rtu_rwa_radps[0] * 2.9526E-5;
    h_err_null_norm[1] = (-0.0030610359347664436 - rtu_rwa_radps[1] * 2.9526E-5)
      / -1.0;
    h_err_null_norm[2] = 0.0031228750445597051 - rtu_rwa_radps[2] * 2.9526E-5;
    h_err_null_norm[3] = (-0.003184714154352967 - rtu_rwa_radps[3] * 2.9526E-5) /
      -1.0;
    tmp = rtIsNaN(h_err_null_norm[0]);
    if (!tmp) {
      nz = 1;
    } else {
      nz = 0;
      rtb_A_out_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_A_out_tmp < 5)) {
        if (!rtIsNaN(h_err_null_norm[rtb_A_out_tmp - 1])) {
          nz = rtb_A_out_tmp;
          exitg1 = true;
        } else {
          rtb_A_out_tmp++;
        }
      }
    }

    if (nz == 0) {
      n_whl = h_err_null_norm[0];
    } else {
      n_whl = h_err_null_norm[nz - 1];
      while (nz + 1 <= 4) {
        if (n_whl < h_err_null_norm[nz]) {
          n_whl = h_err_null_norm[nz];
        }

        nz++;
      }
    }

    if (!tmp) {
      nz = 1;
    } else {
      nz = 0;
      rtb_A_out_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_A_out_tmp < 5)) {
        if (!rtIsNaN(h_err_null_norm[rtb_A_out_tmp - 1])) {
          nz = rtb_A_out_tmp;
          exitg1 = true;
        } else {
          rtb_A_out_tmp++;
        }
      }
    }

    if (nz == 0) {
      rtb_Product_da = h_err_null_norm[0];
    } else {
      rtb_Product_da = h_err_null_norm[nz - 1];
      while (nz + 1 <= 4) {
        if (rtb_Product_da > h_err_null_norm[nz]) {
          rtb_Product_da = h_err_null_norm[nz];
        }

        nz++;
      }
    }

    n_whl = -((n_whl + rtb_Product_da) / 2.0);
    for (nz = 0; nz < 4; nz++) {
      /* Sum: '<S134>/Sum1' incorporates:
       *  Constant: '<S134>/Constant'
       *  Product: '<S134>/Matrix Multiply'
       *  Product: '<S134>/Matrix Multiply1'
       *  Sum: '<S134>/Sum2'
       */
      rtb_Product_da = rtConstP.Constant_Value_i[nz + 4];
      tmp_1 = rtConstP.Constant_Value_i[nz + 8];

      /* Sum: '<S134>/Sum2' incorporates:
       *  Constant: '<S134>/Constant'
       *  Constant: '<S137>/Constant1'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  Gain: '<S134>/feedback_gain'
       *  Gain: '<S134>/wheel_inertia_kgm2'
       *  MATLAB Function: '<S137>/MATLAB Function'
       *  Product: '<S134>/Matrix Multiply'
       *  Product: '<S134>/Matrix Multiply1'
       *  Sum: '<S134>/Sum1'
       */
      rty_torque_wheel_Nm[nz] = (((rtb_Product_da *
        localDW->DiscreteTimeIntegrator_DSTATE[1] + rtConstP.Constant_Value_i[nz]
        * localDW->DiscreteTimeIntegrator_DSTATE[0]) + tmp_1 *
        localDW->DiscreteTimeIntegrator_DSTATE[2]) - n_whl *
        rtConstP.pooled1.nullvec[nz] / 2.9526E-5 * 2.9526000000000003E-6) * 0.01
        + ((rtb_Product_da * rtu_torque_body_Nm[1] +
            rtConstP.Constant_Value_i[nz] * rtu_torque_body_Nm[0]) + tmp_1 *
           rtu_torque_body_Nm[2]);
    }

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtu_torque_body_Nm[2];

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    /* MATLAB Function: '<S135>/MATLAB Function' incorporates:
     *  Constant: '<S135>/Constant'
     */
    switch ((uint8_T)(((rtu_rwa_valid[0] + rtu_rwa_valid[1]) + rtu_rwa_valid[2])
                      + rtu_rwa_valid[3])) {
     case 3:
      id_good[0] = 0.0;
      id_good[1] = 0.0;
      id_good[2] = 0.0;
      n_whl = 1.0;
      if (rtu_rwa_valid[0]) {
        id_good[0] = 1.0;
        n_whl = 2.0;
      }

      if (rtu_rwa_valid[1]) {
        id_good[(int32_T)n_whl - 1] = 2.0;
        n_whl++;
      }

      if (rtu_rwa_valid[2]) {
        id_good[(int32_T)n_whl - 1] = 3.0;
        n_whl++;
      }

      if (rtu_rwa_valid[3]) {
        id_good[(int32_T)n_whl - 1] = 4.0;
      }

      for (nz = 0; nz < 3; nz++) {
        rtb_A_out_tmp = ((int32_T)id_good[nz] - 1) * 3;
        rtb_A_out[3 * nz] = rtConstP.pooled13[rtb_A_out_tmp];
        rtb_A_out[3 * nz + 1] = rtConstP.pooled13[rtb_A_out_tmp + 1];
        rtb_A_out[3 * nz + 2] = rtConstP.pooled13[rtb_A_out_tmp + 2];
      }
      break;

     case 4:
      for (nz = 0; nz < 3; nz++) {
        rtb_A_out[3 * nz] = rtConstP.pooled13[3 * nz];
        rtb_A_out_tmp = 3 * nz + 1;
        rtb_A_out[rtb_A_out_tmp] = rtConstP.pooled13[rtb_A_out_tmp];
        rtb_A_out_tmp = 3 * nz + 2;
        rtb_A_out[rtb_A_out_tmp] = rtConstP.pooled13[rtb_A_out_tmp];
      }
      break;

     default:
      memset(&rtb_A_out[0], 0, 9U * sizeof(real_T));
      rtb_A_out[0] = 1.0;
      rtb_A_out[4] = 1.0;
      rtb_A_out[8] = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S135>/MATLAB Function' */

    /* Assertion: '<S139>/Assertion' incorporates:
     *  Product: '<S142>/Product'
     *  Product: '<S142>/Product1'
     *  Product: '<S142>/Product2'
     *  Product: '<S142>/Product3'
     *  Product: '<S142>/Product4'
     *  Product: '<S142>/Product5'
     *  Sum: '<S142>/Sum'
     */
    utAssert(((((rtb_A_out[0] * rtb_A_out[4] * rtb_A_out[8] - rtb_A_out[0] *
                 rtb_A_out[5] * rtb_A_out[7]) - rtb_A_out[1] * rtb_A_out[3] *
                rtb_A_out[8]) + rtb_A_out[2] * rtb_A_out[3] * rtb_A_out[7]) +
              rtb_A_out[1] * rtb_A_out[5] * rtb_A_out[6]) - rtb_A_out[2] *
             rtb_A_out[4] * rtb_A_out[6] != 0.0);

    /* Product: '<S139>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp_0);

    /* Product: '<S135>/Product' */
    for (nz = 0; nz < 3; nz++) {
      id_good[nz] = tmp_0[nz + 6] * rtu_torque_body_Nm[2] + (tmp_0[nz + 3] *
        rtu_torque_body_Nm[1] + tmp_0[nz] * rtu_torque_body_Nm[0]);
    }

    /* End of Product: '<S135>/Product' */

    /* MATLAB Function: '<S135>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion generated from: '<S135>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S135>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[0] = 0.0;

    /* MATLAB Function: '<S135>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S135>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rty_torque_wheel_Nm[0] = id_good[0];
    }

    /* SignalConversion generated from: '<S135>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S135>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[1] = 0.0;

    /* MATLAB Function: '<S135>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S135>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      nz = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[1] = id_good[(uint8_T)nz - 1];
    }

    /* SignalConversion generated from: '<S135>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S135>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[2] = 0.0;

    /* MATLAB Function: '<S135>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S135>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      nz = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[2] = id_good[(uint8_T)nz - 1];
    }

    /* SignalConversion generated from: '<S135>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S135>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[3] = 0.0;

    /* MATLAB Function: '<S135>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S135>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rty_torque_wheel_Nm[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem1' */
  }

  /* End of If: '<S91>/If' */

  /* MATLAB Function: '<S133>/MATLAB Function' incorporates:
   *  Constant: '<S133>/Constant'
   */
  for (nz = 0; nz < 8; nz++) {
    temp[nz] = ((((real_T)a[nz + 8] * rty_torque_wheel_Nm[1] + (real_T)a[nz] *
                  rty_torque_wheel_Nm[0]) + (real_T)a[nz + 16] *
                 rty_torque_wheel_Nm[2]) + (real_T)a[nz + 24] *
                rty_torque_wheel_Nm[3]) - 0.0032;
  }

  if (!rtIsNaN(temp[0])) {
    nz = 0;
  } else {
    nz = -1;
    rtb_A_out_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (rtb_A_out_tmp < 9)) {
      if (!rtIsNaN(temp[rtb_A_out_tmp - 1])) {
        nz = rtb_A_out_tmp - 1;
        exitg1 = true;
      } else {
        rtb_A_out_tmp++;
      }
    }
  }

  if (nz + 1 == 0) {
    n_whl = temp[0];
    nz = 0;
  } else {
    n_whl = temp[nz];
    for (rtb_A_out_tmp = nz + 1; rtb_A_out_tmp < 8; rtb_A_out_tmp++) {
      if (n_whl < temp[rtb_A_out_tmp]) {
        n_whl = temp[rtb_A_out_tmp];
        nz = rtb_A_out_tmp;
      }
    }
  }

  if (n_whl > 0.0) {
    rtb_Product_da = 0.0032 / ((((real_T)a[nz + 8] * rty_torque_wheel_Nm[1] +
      (real_T)a[nz] * rty_torque_wheel_Nm[0]) + (real_T)a[nz + 16] *
      rty_torque_wheel_Nm[2]) + (real_T)a[nz + 24] * rty_torque_wheel_Nm[3]);
    rty_torque_wheel_Nm[0] *= rtb_Product_da;
    rty_torque_wheel_Nm[1] *= rtb_Product_da;
    rty_torque_wheel_Nm[2] *= rtb_Product_da;
    rty_torque_wheel_Nm[3] *= rtb_Product_da;
  }

  /* End of MATLAB Function: '<S133>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
