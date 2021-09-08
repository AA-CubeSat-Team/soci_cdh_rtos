/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
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
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "rt_invd3x3_snf.h"

/* Output and update for atomic system: '<S5>/rwa_allocation_lib' */
void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_rpm[4], const boolean_T rtu_rwa_valid[4], real_T rty_torque_wheel_Nm[4],
  DW_rwa_allocation_lib *localDW)
{
  real_T temp[8];
  static const int8_T a[32] = { 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1 };

  real_T id_good[3];
  int32_T n_whl;
  uint8_T n_whl_0;
  real_T rtb_output_wheel[4];
  real_T rtb_output_wheel_b[4];
  real_T localProduct;
  real_T localProduct_0;
  real_T rtb_A_out[9];
  real_T tmp[9];
  int32_T rtb_A_out_tmp;
  boolean_T exitg1;

  /* If: '<S216>/If' incorporates:
   *  Gain: '<S250>/feedback_gain'
   *  Gain: '<S250>/rpm_2_radps'
   *  Gain: '<S250>/wheel_inertia_kgm2'
   *  Logic: '<S216>/Logical Operator'
   *  Sum: '<S250>/Sum'
   *  Sum: '<S250>/Sum1'
   *  Sum: '<S250>/Sum2'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S216>/If Action Subsystem' incorporates:
     *  ActionPort: '<S250>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S250>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, rtb_output_wheel_b);

    /* End of Outputs for SubSystem: '<S250>/L_inf_allocation_lib' */

    /* DiscreteIntegrator: '<S250>/Discrete-Time Integrator' */
    id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S250>/L_inf_allocation_lib1' */
    L_inf_allocation_lib(id_good, rtb_output_wheel);

    /* End of Outputs for SubSystem: '<S250>/L_inf_allocation_lib1' */
    rtb_output_wheel_b[0] += (rtb_output_wheel[0] - (0.10471975511965977 *
      rtu_rwa_rpm[0] * 2.9526E-5 - 0.0030919554896630744)) * 0.01;
    rtb_output_wheel_b[1] += (rtb_output_wheel[1] - (0.10471975511965977 *
      rtu_rwa_rpm[1] * 2.9526E-5 - -0.0030919554896630744)) * 0.01;
    rtb_output_wheel_b[2] += (rtb_output_wheel[2] - (0.10471975511965977 *
      rtu_rwa_rpm[2] * 2.9526E-5 - 0.0030919554896630744)) * 0.01;
    rtb_output_wheel_b[3] += (rtb_output_wheel[3] - (0.10471975511965977 *
      rtu_rwa_rpm[3] * 2.9526E-5 - -0.0030919554896630744)) * 0.01;

    /* Update for DiscreteIntegrator: '<S250>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S250>/feedback_gain'
     *  Gain: '<S250>/rpm_2_radps'
     *  Gain: '<S250>/wheel_inertia_kgm2'
     *  Sum: '<S250>/Sum'
     *  Sum: '<S250>/Sum1'
     *  Sum: '<S250>/Sum2'
     */
    localDW->DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtu_torque_body_Nm[2];

    /* End of Outputs for SubSystem: '<S216>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S216>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S251>/Action Port'
     */
    /* MATLAB Function: '<S251>/MATLAB Function' incorporates:
     *  Constant: '<S251>/Constant'
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
        rtb_A_out_tmp = ((int32_T)id_good[n_whl] - 1) * 3;
        rtb_A_out[3 * n_whl] = rtCP_Constant_Value_dp[rtb_A_out_tmp];
        rtb_A_out[1 + 3 * n_whl] = rtCP_Constant_Value_dp[rtb_A_out_tmp + 1];
        rtb_A_out[2 + 3 * n_whl] = rtCP_Constant_Value_dp[rtb_A_out_tmp + 2];
      }
      break;

     case 4:
      for (n_whl = 0; n_whl < 3; n_whl++) {
        rtb_A_out[3 * n_whl] = rtCP_Constant_Value_dp[3 * n_whl];
        rtb_A_out[1 + 3 * n_whl] = rtCP_Constant_Value_dp[3 * n_whl + 1];
        rtb_A_out[2 + 3 * n_whl] = rtCP_Constant_Value_dp[3 * n_whl + 2];
      }
      break;

     default:
      memset(&rtb_A_out[0], 0, 9U * sizeof(real_T));
      rtb_A_out[0] = 1.0;
      rtb_A_out[4] = 1.0;
      rtb_A_out[8] = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S251>/MATLAB Function' */

    /* Product: '<S257>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp);

    /* Product: '<S251>/Product' */
    for (n_whl = 0; n_whl < 3; n_whl++) {
      id_good[n_whl] = tmp[n_whl + 6] * rtu_torque_body_Nm[2] + (tmp[n_whl + 3] *
        rtu_torque_body_Nm[1] + tmp[n_whl] * rtu_torque_body_Nm[0]);
    }

    /* MATLAB Function: '<S251>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S251>/MATLAB Function1'
     */
    rtb_output_wheel_b[0] = 0.0;

    /* MATLAB Function: '<S251>/MATLAB Function1' incorporates:
     *  Product: '<S251>/Product'
     *  SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rtb_output_wheel_b[0] = id_good[0];
    }

    /* SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S251>/MATLAB Function1'
     */
    rtb_output_wheel_b[1] = 0.0;

    /* MATLAB Function: '<S251>/MATLAB Function1' incorporates:
     *  Product: '<S251>/Product'
     *  SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rtb_output_wheel_b[1] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S251>/MATLAB Function1'
     */
    rtb_output_wheel_b[2] = 0.0;

    /* MATLAB Function: '<S251>/MATLAB Function1' incorporates:
     *  Product: '<S251>/Product'
     *  SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rtb_output_wheel_b[2] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S251>/MATLAB Function1'
     */
    rtb_output_wheel_b[3] = 0.0;

    /* MATLAB Function: '<S251>/MATLAB Function1' incorporates:
     *  Product: '<S251>/Product'
     *  SignalConversion: '<S251>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rtb_output_wheel_b[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

    /* Assertion: '<S257>/Assertion' incorporates:
     *  Product: '<S260>/Product'
     *  Product: '<S260>/Product1'
     *  Product: '<S260>/Product2'
     *  Product: '<S260>/Product3'
     *  Product: '<S260>/Product4'
     *  Product: '<S260>/Product5'
     *  Sum: '<S260>/Sum'
     */
    utAssert(((((rtb_A_out[0] * rtb_A_out[4] * rtb_A_out[8] - rtb_A_out[0] *
                 rtb_A_out[5] * rtb_A_out[7]) - rtb_A_out[1] * rtb_A_out[3] *
                rtb_A_out[8]) + rtb_A_out[2] * rtb_A_out[3] * rtb_A_out[7]) +
              rtb_A_out[1] * rtb_A_out[5] * rtb_A_out[6]) - rtb_A_out[2] *
             rtb_A_out[4] * rtb_A_out[6] != 0.0);

    /* End of Outputs for SubSystem: '<S216>/If Action Subsystem1' */
  }

  /* End of If: '<S216>/If' */

  /* MATLAB Function: '<S249>/MATLAB Function' incorporates:
   *  Constant: '<S249>/Constant'
   */
  for (n_whl = 0; n_whl < 8; n_whl++) {
    temp[n_whl] = ((((real_T)a[n_whl + 8] * rtb_output_wheel_b[1] + (real_T)
                     a[n_whl] * rtb_output_wheel_b[0]) + (real_T)a[n_whl + 16] *
                    rtb_output_wheel_b[2]) + (real_T)a[n_whl + 24] *
                   rtb_output_wheel_b[3]) - 0.0032;
  }

  if (!rtIsNaN(temp[0])) {
    rtb_A_out_tmp = 0;
  } else {
    rtb_A_out_tmp = -1;
    n_whl = 2;
    exitg1 = false;
    while ((!exitg1) && (n_whl < 9)) {
      if (!rtIsNaN(temp[n_whl - 1])) {
        rtb_A_out_tmp = n_whl - 1;
        exitg1 = true;
      } else {
        n_whl++;
      }
    }
  }

  if (rtb_A_out_tmp + 1 == 0) {
    localProduct_0 = temp[0];
    rtb_A_out_tmp = 0;
  } else {
    localProduct_0 = temp[rtb_A_out_tmp];
    for (n_whl = rtb_A_out_tmp + 1; n_whl + 1 < 9; n_whl++) {
      if (localProduct_0 < temp[n_whl]) {
        localProduct_0 = temp[n_whl];
        rtb_A_out_tmp = n_whl;
      }
    }
  }

  localProduct = (((real_T)a[rtb_A_out_tmp + 8] * rtb_output_wheel_b[1] +
                   (real_T)a[rtb_A_out_tmp] * rtb_output_wheel_b[0]) + (real_T)
                  a[rtb_A_out_tmp + 16] * rtb_output_wheel_b[2]) + (real_T)
    a[rtb_A_out_tmp + 24] * rtb_output_wheel_b[3];
  if (localProduct_0 > 0.0) {
    rty_torque_wheel_Nm[0] = 0.0032 / localProduct * rtb_output_wheel_b[0];
    rty_torque_wheel_Nm[1] = 0.0032 / localProduct * rtb_output_wheel_b[1];
    rty_torque_wheel_Nm[2] = 0.0032 / localProduct * rtb_output_wheel_b[2];
    rty_torque_wheel_Nm[3] = 0.0032 / localProduct * rtb_output_wheel_b[3];
  } else {
    rty_torque_wheel_Nm[0] = rtb_output_wheel_b[0];
    rty_torque_wheel_Nm[1] = rtb_output_wheel_b[1];
    rty_torque_wheel_Nm[2] = rtb_output_wheel_b[2];
    rty_torque_wheel_Nm[3] = rtb_output_wheel_b[3];
  }

  /* End of MATLAB Function: '<S249>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
