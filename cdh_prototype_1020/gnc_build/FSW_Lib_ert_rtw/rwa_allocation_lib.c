/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
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
  rtu_rwa_rpm[4], const boolean_T rtu_rwa_valid[4], real_T rty_torque_wheel_Nm[4],
  DW_rwa_allocation_lib *localDW)
{
  real_T id_good[3];
  int32_T n_whl;
  uint8_T n_whl_0;
  real_T rtb_output_wheel[4];
  real_T rtb_output_wheel_b[4];
  real_T rtb_A_out[9];
  real_T tmp[9];
  int32_T rtb_A_out_tmp;

  /* If: '<S126>/If' incorporates:
   *  Logic: '<S126>/Logical Operator'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S159>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, rtb_output_wheel_b);

    /* End of Outputs for SubSystem: '<S159>/L_inf_allocation_lib' */

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S159>/L_inf_allocation_lib1' */
    L_inf_allocation_lib(id_good, rtb_output_wheel);

    /* End of Outputs for SubSystem: '<S159>/L_inf_allocation_lib1' */

    /* Sum: '<S159>/Sum2' incorporates:
     *  Gain: '<S159>/feedback_gain'
     *  Gain: '<S159>/rpm_2_radps'
     *  Gain: '<S159>/wheel_inertia_kgm2'
     *  Sum: '<S159>/Sum'
     *  Sum: '<S159>/Sum1'
     */
    rty_torque_wheel_Nm[0] = (rtb_output_wheel[0] - (0.10471975511965977 *
      rtu_rwa_rpm[0] * 2.9526E-5 - 0.0030919554896630744)) * 0.01 +
      rtb_output_wheel_b[0];
    rty_torque_wheel_Nm[1] = (rtb_output_wheel[1] - (0.10471975511965977 *
      rtu_rwa_rpm[1] * 2.9526E-5 - -0.0030919554896630744)) * 0.01 +
      rtb_output_wheel_b[1];
    rty_torque_wheel_Nm[2] = (rtb_output_wheel[2] - (0.10471975511965977 *
      rtu_rwa_rpm[2] * 2.9526E-5 - 0.0030919554896630744)) * 0.01 +
      rtb_output_wheel_b[2];
    rty_torque_wheel_Nm[3] = (rtb_output_wheel[3] - (0.10471975511965977 *
      rtu_rwa_rpm[3] * 2.9526E-5 - -0.0030919554896630744)) * 0.01 +
      rtb_output_wheel_b[3];

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtu_torque_body_Nm[2];

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* MATLAB Function: '<S160>/MATLAB Function' incorporates:
     *  Constant: '<S160>/Constant'
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

    /* End of MATLAB Function: '<S160>/MATLAB Function' */

    /* Product: '<S165>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp);

    /* Product: '<S160>/Product' */
    for (n_whl = 0; n_whl < 3; n_whl++) {
      id_good[n_whl] = tmp[n_whl + 6] * rtu_torque_body_Nm[2] + (tmp[n_whl + 3] *
        rtu_torque_body_Nm[1] + tmp[n_whl] * rtu_torque_body_Nm[0]);
    }

    /* MATLAB Function: '<S160>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S160>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[0] = 0.0;

    /* MATLAB Function: '<S160>/MATLAB Function1' incorporates:
     *  Product: '<S160>/Product'
     *  SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rty_torque_wheel_Nm[0] = id_good[0];
    }

    /* SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S160>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[1] = 0.0;

    /* MATLAB Function: '<S160>/MATLAB Function1' incorporates:
     *  Product: '<S160>/Product'
     *  SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[1] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S160>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[2] = 0.0;

    /* MATLAB Function: '<S160>/MATLAB Function1' incorporates:
     *  Product: '<S160>/Product'
     *  SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[2] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S160>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[3] = 0.0;

    /* MATLAB Function: '<S160>/MATLAB Function1' incorporates:
     *  Product: '<S160>/Product'
     *  SignalConversion: '<S160>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rty_torque_wheel_Nm[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

    /* Assertion: '<S165>/Assertion' incorporates:
     *  Product: '<S168>/Product'
     *  Product: '<S168>/Product1'
     *  Product: '<S168>/Product2'
     *  Product: '<S168>/Product3'
     *  Product: '<S168>/Product4'
     *  Product: '<S168>/Product5'
     *  Sum: '<S168>/Sum'
     */
    utAssert(((((rtb_A_out[0] * rtb_A_out[4] * rtb_A_out[8] - rtb_A_out[0] *
                 rtb_A_out[5] * rtb_A_out[7]) - rtb_A_out[1] * rtb_A_out[3] *
                rtb_A_out[8]) + rtb_A_out[2] * rtb_A_out[3] * rtb_A_out[7]) +
              rtb_A_out[1] * rtb_A_out[5] * rtb_A_out[6]) - rtb_A_out[2] *
             rtb_A_out[4] * rtb_A_out[6] != 0.0);

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem1' */
  }

  /* End of If: '<S126>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
