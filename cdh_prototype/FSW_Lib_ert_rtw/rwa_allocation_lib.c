/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rwa_allocation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "rt_invd3x3_snf.h"

/* Output and update for atomic system: '<S5>/rwa_allocation_lib' */
void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_radps[4], const boolean_T rtu_rwa_valid[4], real_T
  rty_torque_wheel_Nm[4], DW_rwa_allocation_lib *localDW)
{
  static const int8_T a[32] = { 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1 };

  real_T rtb_A_out[9];
  real_T tmp_0[9];
  real_T temp[8];
  real_T h_err_null_norm[4];
  real_T rtb_output_wheel[4];
  real_T id_good[3];
  real_T n_whl;
  real_T rtb_Product_j;
  int32_T nz;
  int32_T rtb_A_out_tmp;
  uint8_T n_whl_0;
  boolean_T exitg1;
  boolean_T tmp;

  /* If: '<S232>/If' incorporates:
   *  Logic: '<S232>/Logical Operator'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem' incorporates:
     *  ActionPort: '<S275>/Action Port'
     */
    /* DiscreteIntegrator: '<S275>/Discrete-Time Integrator' */
    id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S275>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, rty_torque_wheel_Nm);

    /* End of Outputs for SubSystem: '<S275>/L_inf_allocation_lib' */

    /* Outputs for Atomic SubSystem: '<S275>/L_inf_allocation_lib1' */
    L_inf_allocation_lib(id_good, rtb_output_wheel);

    /* End of Outputs for SubSystem: '<S275>/L_inf_allocation_lib1' */

    /* MATLAB Function: '<S280>/MATLAB Function' */
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
      rtb_Product_j = h_err_null_norm[0];
    } else {
      rtb_Product_j = h_err_null_norm[nz - 1];
      while (nz + 1 <= 4) {
        if (rtb_Product_j > h_err_null_norm[nz]) {
          rtb_Product_j = h_err_null_norm[nz];
        }

        nz++;
      }
    }

    n_whl = -((n_whl + rtb_Product_j) / 2.0);

    /* Gain: '<S275>/wheel_inertia_kgm2' incorporates:
     *  MATLAB Function: '<S280>/MATLAB Function'
     */
    rtb_Product_j = n_whl / 2.9526E-5 * 2.9526E-5;

    /* Sum: '<S275>/Sum2' incorporates:
     *  Gain: '<S275>/feedback_gain'
     *  Gain: '<S275>/wheel_inertia_kgm2'
     *  Sum: '<S275>/Sum1'
     */
    rty_torque_wheel_Nm[0] += (rtb_output_wheel[0] - rtb_Product_j) * 0.01;

    /* Gain: '<S275>/wheel_inertia_kgm2' incorporates:
     *  MATLAB Function: '<S280>/MATLAB Function'
     */
    n_whl = -n_whl / 2.9526E-5 * 2.9526E-5;

    /* Sum: '<S275>/Sum2' incorporates:
     *  Gain: '<S275>/feedback_gain'
     *  Gain: '<S275>/wheel_inertia_kgm2'
     *  Sum: '<S275>/Sum1'
     */
    rty_torque_wheel_Nm[1] += (rtb_output_wheel[1] - n_whl) * 0.01;
    rty_torque_wheel_Nm[2] += (rtb_output_wheel[2] - rtb_Product_j) * 0.01;
    rty_torque_wheel_Nm[3] += (rtb_output_wheel[3] - n_whl) * 0.01;

    /* Update for DiscreteIntegrator: '<S275>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtu_torque_body_Nm[2];

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S276>/Action Port'
     */
    /* MATLAB Function: '<S276>/MATLAB Function' incorporates:
     *  Constant: '<S276>/Constant'
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
        rtb_A_out[3 * nz] = rtCP_Constant_Value_h5[rtb_A_out_tmp];
        rtb_A_out[3 * nz + 1] = rtCP_Constant_Value_h5[rtb_A_out_tmp + 1];
        rtb_A_out[3 * nz + 2] = rtCP_Constant_Value_h5[rtb_A_out_tmp + 2];
      }
      break;

     case 4:
      for (nz = 0; nz < 3; nz++) {
        rtb_A_out[3 * nz] = rtCP_Constant_Value_h5[3 * nz];
        rtb_A_out_tmp = 3 * nz + 1;
        rtb_A_out[rtb_A_out_tmp] = rtCP_Constant_Value_h5[rtb_A_out_tmp];
        rtb_A_out_tmp = 3 * nz + 2;
        rtb_A_out[rtb_A_out_tmp] = rtCP_Constant_Value_h5[rtb_A_out_tmp];
      }
      break;

     default:
      memset(&rtb_A_out[0], 0, 9U * sizeof(real_T));
      rtb_A_out[0] = 1.0;
      rtb_A_out[4] = 1.0;
      rtb_A_out[8] = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S276>/MATLAB Function' */

    /* Assertion: '<S284>/Assertion' incorporates:
     *  Product: '<S287>/Product'
     *  Product: '<S287>/Product1'
     *  Product: '<S287>/Product2'
     *  Product: '<S287>/Product3'
     *  Product: '<S287>/Product4'
     *  Product: '<S287>/Product5'
     *  Sum: '<S287>/Sum'
     */
    utAssert(((((rtb_A_out[0] * rtb_A_out[4] * rtb_A_out[8] - rtb_A_out[0] *
                 rtb_A_out[5] * rtb_A_out[7]) - rtb_A_out[1] * rtb_A_out[3] *
                rtb_A_out[8]) + rtb_A_out[2] * rtb_A_out[3] * rtb_A_out[7]) +
              rtb_A_out[1] * rtb_A_out[5] * rtb_A_out[6]) - rtb_A_out[2] *
             rtb_A_out[4] * rtb_A_out[6] != 0.0);

    /* Product: '<S284>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp_0);

    /* Product: '<S276>/Product' */
    for (nz = 0; nz < 3; nz++) {
      id_good[nz] = tmp_0[nz + 6] * rtu_torque_body_Nm[2] + (tmp_0[nz + 3] *
        rtu_torque_body_Nm[1] + tmp_0[nz] * rtu_torque_body_Nm[0]);
    }

    /* MATLAB Function: '<S276>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion generated from: '<S276>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[0] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion generated from: '<S276>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rty_torque_wheel_Nm[0] = id_good[0];
    }

    /* SignalConversion generated from: '<S276>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[1] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion generated from: '<S276>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      nz = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[1] = id_good[(uint8_T)nz - 1];
    }

    /* SignalConversion generated from: '<S276>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[2] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion generated from: '<S276>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      nz = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[2] = id_good[(uint8_T)nz - 1];
    }

    /* SignalConversion generated from: '<S276>/torque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[3] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion generated from: '<S276>/torque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rty_torque_wheel_Nm[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem1' */
  }

  /* End of If: '<S232>/If' */

  /* MATLAB Function: '<S274>/MATLAB Function' incorporates:
   *  Constant: '<S274>/Constant'
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
    rtb_Product_j = 0.0032 / ((((real_T)a[nz + 8] * rty_torque_wheel_Nm[1] +
      (real_T)a[nz] * rty_torque_wheel_Nm[0]) + (real_T)a[nz + 16] *
      rty_torque_wheel_Nm[2]) + (real_T)a[nz + 24] * rty_torque_wheel_Nm[3]);
    rty_torque_wheel_Nm[0] *= rtb_Product_j;
    rty_torque_wheel_Nm[1] *= rtb_Product_j;
    rty_torque_wheel_Nm[2] *= rtb_Product_j;
    rty_torque_wheel_Nm[3] *= rtb_Product_j;
  }

  /* End of MATLAB Function: '<S274>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
