/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
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
  real_T temp[8];
  static const int8_T a[32] = { 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1 };

  real_T h_err_null_norm[4];
  int32_T idx;
  real_T id_good[3];
  int32_T n_whl;
  uint8_T n_whl_0;
  real_T rtb_output_wheel[4];
  real_T rtb_output_wheel_o[4];
  real_T localProduct;
  real_T localProduct_0;
  real_T rtb_A_out[9];
  real_T tmp[9];
  boolean_T tmp_0;
  boolean_T exitg1;

  /* If: '<S232>/If' incorporates:
   *  Gain: '<S275>/feedback_gain'
   *  Gain: '<S275>/wheel_inertia_kgm2'
   *  Logic: '<S232>/Logical Operator'
   *  Sum: '<S275>/Sum1'
   *  Sum: '<S275>/Sum2'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem' incorporates:
     *  ActionPort: '<S275>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S275>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, rtb_output_wheel_o);

    /* End of Outputs for SubSystem: '<S275>/L_inf_allocation_lib' */

    /* DiscreteIntegrator: '<S275>/Discrete-Time Integrator' */
    id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

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
    tmp_0 = rtIsNaN(h_err_null_norm[0]);
    if (!tmp_0) {
      idx = 1;
    } else {
      idx = 0;
      n_whl = 2;
      exitg1 = false;
      while ((!exitg1) && (n_whl < 5)) {
        if (!rtIsNaN(h_err_null_norm[n_whl - 1])) {
          idx = n_whl;
          exitg1 = true;
        } else {
          n_whl++;
        }
      }
    }

    if (idx == 0) {
      localProduct_0 = h_err_null_norm[0];
    } else {
      localProduct_0 = h_err_null_norm[idx - 1];
      while (idx + 1 < 5) {
        if (localProduct_0 < h_err_null_norm[idx]) {
          localProduct_0 = h_err_null_norm[idx];
        }

        idx++;
      }
    }

    if (!tmp_0) {
      idx = 1;
    } else {
      idx = 0;
      n_whl = 2;
      exitg1 = false;
      while ((!exitg1) && (n_whl < 5)) {
        if (!rtIsNaN(h_err_null_norm[n_whl - 1])) {
          idx = n_whl;
          exitg1 = true;
        } else {
          n_whl++;
        }
      }
    }

    if (idx == 0) {
      localProduct = h_err_null_norm[0];
    } else {
      localProduct = h_err_null_norm[idx - 1];
      while (idx + 1 < 5) {
        if (localProduct > h_err_null_norm[idx]) {
          localProduct = h_err_null_norm[idx];
        }

        idx++;
      }
    }

    localProduct_0 = -((localProduct_0 + localProduct) / 2.0);

    /* Gain: '<S275>/wheel_inertia_kgm2' incorporates:
     *  MATLAB Function: '<S280>/MATLAB Function'
     */
    localProduct = localProduct_0 / 2.9526E-5 * 2.9526E-5;
    rtb_output_wheel_o[0] += (rtb_output_wheel[0] - localProduct) * 0.01;

    /* Gain: '<S275>/wheel_inertia_kgm2' incorporates:
     *  Gain: '<S275>/feedback_gain'
     *  MATLAB Function: '<S280>/MATLAB Function'
     *  Sum: '<S275>/Sum1'
     *  Sum: '<S275>/Sum2'
     */
    localProduct_0 = -localProduct_0 / 2.9526E-5 * 2.9526E-5;
    rtb_output_wheel_o[1] += (rtb_output_wheel[1] - localProduct_0) * 0.01;
    rtb_output_wheel_o[2] += (rtb_output_wheel[2] - localProduct) * 0.01;
    rtb_output_wheel_o[3] += (rtb_output_wheel[3] - localProduct_0) * 0.01;

    /* Update for DiscreteIntegrator: '<S275>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S275>/feedback_gain'
     *  Gain: '<S275>/wheel_inertia_kgm2'
     *  Sum: '<S275>/Sum1'
     *  Sum: '<S275>/Sum2'
     */
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
     case 0:
     case 1:
     case 2:
      memset(&rtb_A_out[0], 0, 9U * sizeof(real_T));
      rtb_A_out[0] = 1.0;
      rtb_A_out[4] = 1.0;
      rtb_A_out[8] = 1.0;
      break;

     case 3:
      id_good[0] = 0.0;
      id_good[1] = 0.0;
      id_good[2] = 0.0;
      n_whl = 1;
      if (rtu_rwa_valid[0]) {
        id_good[0] = 1.0;
        n_whl = 2;
      }

      if (rtu_rwa_valid[1]) {
        id_good[n_whl - 1] = 2.0;
        n_whl++;
      }

      if (rtu_rwa_valid[2]) {
        id_good[n_whl - 1] = 3.0;
        n_whl++;
      }

      if (rtu_rwa_valid[3]) {
        id_good[n_whl - 1] = 4.0;
      }

      for (n_whl = 0; n_whl < 3; n_whl++) {
        idx = ((int32_T)id_good[n_whl] - 1) * 3;
        rtb_A_out[3 * n_whl] = rtCP_Constant_Value_h5[idx];
        rtb_A_out[1 + 3 * n_whl] = rtCP_Constant_Value_h5[idx + 1];
        rtb_A_out[2 + 3 * n_whl] = rtCP_Constant_Value_h5[idx + 2];
      }
      break;

     case 4:
      for (n_whl = 0; n_whl < 3; n_whl++) {
        rtb_A_out[3 * n_whl] = rtCP_Constant_Value_h5[3 * n_whl];
        rtb_A_out[1 + 3 * n_whl] = rtCP_Constant_Value_h5[3 * n_whl + 1];
        rtb_A_out[2 + 3 * n_whl] = rtCP_Constant_Value_h5[3 * n_whl + 2];
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

    /* Product: '<S284>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp);

    /* Product: '<S276>/Product' */
    for (n_whl = 0; n_whl < 3; n_whl++) {
      id_good[n_whl] = tmp[n_whl + 6] * rtu_torque_body_Nm[2] + (tmp[n_whl + 3] *
        rtu_torque_body_Nm[1] + tmp[n_whl] * rtu_torque_body_Nm[0]);
    }

    /* MATLAB Function: '<S276>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rtb_output_wheel_o[0] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rtb_output_wheel_o[0] = id_good[0];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rtb_output_wheel_o[1] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rtb_output_wheel_o[1] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rtb_output_wheel_o[2] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rtb_output_wheel_o[2] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    rtb_output_wheel_o[3] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rtb_output_wheel_o[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

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

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem1' */
  }

  /* End of If: '<S232>/If' */

  /* MATLAB Function: '<S274>/MATLAB Function' incorporates:
   *  Constant: '<S274>/Constant'
   */
  for (n_whl = 0; n_whl < 8; n_whl++) {
    temp[n_whl] = ((((real_T)a[n_whl + 8] * rtb_output_wheel_o[1] + (real_T)
                     a[n_whl] * rtb_output_wheel_o[0]) + (real_T)a[n_whl + 16] *
                    rtb_output_wheel_o[2]) + (real_T)a[n_whl + 24] *
                   rtb_output_wheel_o[3]) - 0.0032;
  }

  if (!rtIsNaN(temp[0])) {
    idx = 0;
  } else {
    idx = -1;
    n_whl = 2;
    exitg1 = false;
    while ((!exitg1) && (n_whl < 9)) {
      if (!rtIsNaN(temp[n_whl - 1])) {
        idx = n_whl - 1;
        exitg1 = true;
      } else {
        n_whl++;
      }
    }
  }

  if (idx + 1 == 0) {
    localProduct_0 = temp[0];
    idx = 0;
  } else {
    localProduct_0 = temp[idx];
    for (n_whl = idx + 1; n_whl + 1 < 9; n_whl++) {
      if (localProduct_0 < temp[n_whl]) {
        localProduct_0 = temp[n_whl];
        idx = n_whl;
      }
    }
  }

  localProduct = (((real_T)a[idx + 8] * rtb_output_wheel_o[1] + (real_T)a[idx] *
                   rtb_output_wheel_o[0]) + (real_T)a[idx + 16] *
                  rtb_output_wheel_o[2]) + (real_T)a[idx + 24] *
    rtb_output_wheel_o[3];
  if (localProduct_0 > 0.0) {
    rty_torque_wheel_Nm[0] = 0.0032 / localProduct * rtb_output_wheel_o[0];
    rty_torque_wheel_Nm[1] = 0.0032 / localProduct * rtb_output_wheel_o[1];
    rty_torque_wheel_Nm[2] = 0.0032 / localProduct * rtb_output_wheel_o[2];
    rty_torque_wheel_Nm[3] = 0.0032 / localProduct * rtb_output_wheel_o[3];
  } else {
    rty_torque_wheel_Nm[0] = rtb_output_wheel_o[0];
    rty_torque_wheel_Nm[1] = rtb_output_wheel_o[1];
    rty_torque_wheel_Nm[2] = rtb_output_wheel_o[2];
    rty_torque_wheel_Nm[3] = rtb_output_wheel_o[3];
  }

  /* End of MATLAB Function: '<S274>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
