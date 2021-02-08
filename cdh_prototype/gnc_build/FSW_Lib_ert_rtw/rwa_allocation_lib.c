/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>
#include <gnc_build/FSW_Lib_ert_rtw/rwa_allocation_lib.h>

void rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  real_T x[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  memcpy(&x[0], &u[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(u[0]);
  absx21 = fabs(u[1]);
  absx31 = fabs(u[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    x[0] = u[1];
    x[1] = u[0];
    x[3] = u[4];
    x[4] = u[3];
    x[6] = u[7];
    x[7] = u[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
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
  y[p1] = ((1.0 - x[3] * absx21) - x[6] * absx11) / x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
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
  rtu_rwa_rpm[4], const boolean_T rtu_rwa_valid[4], real_T rty_torque_wheel_Nm[4],
  DW_rwa_allocation_lib *localDW)
{
  real_T id_good[3];
  int32_T n_whl;
  uint8_T n_whl_0;
  real_T rtb_A_out[9];
  real_T rtb_output_wheel[4];
  real_T rtb_output_wheel_b[4];
  real_T tmp[9];
  int32_T rtb_A_out_tmp;

  /* If: '<S116>/If' incorporates:
   *  Logic: '<S116>/Logical Operator'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S164>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, rtb_output_wheel_b);

    /* End of Outputs for SubSystem: '<S164>/L_inf_allocation_lib' */

    /* DiscreteIntegrator: '<S164>/Discrete-Time Integrator' */
    id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S164>/L_inf_allocation_lib1' */
    L_inf_allocation_lib(id_good, rtb_output_wheel);

    /* End of Outputs for SubSystem: '<S164>/L_inf_allocation_lib1' */
    for (n_whl = 0; n_whl < 4; n_whl++) {
      /* Sum: '<S164>/Sum2' incorporates:
       *  Constant: '<S164>/h_wheel_targ_Nms'
       *  Gain: '<S164>/feedback_gain'
       *  Gain: '<S164>/rpm_2_radps'
       *  Gain: '<S164>/wheel_inertia_kgm2'
       *  Sum: '<S164>/Sum'
       *  Sum: '<S164>/Sum1'
       */
      rty_torque_wheel_Nm[n_whl] = (rtb_output_wheel[n_whl] -
        ((((0.10471975511965977 * rtu_rwa_rpm[0] * rtConstP.pooled23[n_whl] +
            rtConstP.pooled23[n_whl + 4] * (0.10471975511965977 * rtu_rwa_rpm[1]))
           + rtConstP.pooled23[n_whl + 8] * (0.10471975511965977 * rtu_rwa_rpm[2]))
          + rtConstP.pooled23[n_whl + 12] * (0.10471975511965977 * rtu_rwa_rpm[3]))
         - rtConstP.pooled26[n_whl])) * 0.01 + rtb_output_wheel_b[n_whl];
    }

    /* Update for DiscreteIntegrator: '<S164>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[0] += 0.1 * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] += 0.1 * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] += 0.1 * rtu_torque_body_Nm[2];

    /* End of Outputs for SubSystem: '<S116>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* MATLAB Function: '<S165>/MATLAB Function' incorporates:
     *  Constant: '<S165>/Constant'
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
        rtb_A_out[3 * n_whl] = rtConstP.pooled29[rtb_A_out_tmp];
        rtb_A_out[1 + 3 * n_whl] = rtConstP.pooled29[rtb_A_out_tmp + 1];
        rtb_A_out[2 + 3 * n_whl] = rtConstP.pooled29[rtb_A_out_tmp + 2];
      }
      break;

     case 4:
      for (n_whl = 0; n_whl < 3; n_whl++) {
        rtb_A_out[3 * n_whl] = rtConstP.pooled29[3 * n_whl];
        rtb_A_out[1 + 3 * n_whl] = rtConstP.pooled29[3 * n_whl + 1];
        rtb_A_out[2 + 3 * n_whl] = rtConstP.pooled29[3 * n_whl + 2];
      }
      break;

     default:
      memset(&rtb_A_out[0], 0, 9U * sizeof(real_T));
      rtb_A_out[0] = 1.0;
      rtb_A_out[4] = 1.0;
      rtb_A_out[8] = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S165>/MATLAB Function' */

    /* Product: '<S170>/Product' */
    rt_invd3x3_snf(rtb_A_out, tmp);

    /* Product: '<S165>/Product' */
    for (n_whl = 0; n_whl < 3; n_whl++) {
      id_good[n_whl] = tmp[n_whl + 6] * rtu_torque_body_Nm[2] + (tmp[n_whl + 3] *
        rtu_torque_body_Nm[1] + tmp[n_whl] * rtu_torque_body_Nm[0]);
    }

    /* End of Product: '<S165>/Product' */

    /* MATLAB Function: '<S165>/MATLAB Function1' */
    n_whl_0 = 0U;

    /* SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S165>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[0] = 0.0;

    /* MATLAB Function: '<S165>/MATLAB Function1' incorporates:
     *  SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl_0 = 1U;
      rty_torque_wheel_Nm[0] = id_good[0];
    }

    /* SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S165>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[1] = 0.0;

    /* MATLAB Function: '<S165>/MATLAB Function1' incorporates:
     *  SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[1] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S165>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[2] = 0.0;

    /* MATLAB Function: '<S165>/MATLAB Function1' incorporates:
     *  SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      n_whl = (int32_T)(n_whl_0 + 1U);
      n_whl_0++;
      rty_torque_wheel_Nm[2] = id_good[(uint8_T)n_whl - 1];
    }

    /* SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S165>/MATLAB Function1'
     */
    rty_torque_wheel_Nm[3] = 0.0;

    /* MATLAB Function: '<S165>/MATLAB Function1' incorporates:
     *  SignalConversion: '<S165>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      rty_torque_wheel_Nm[3] = id_good[(uint8_T)(n_whl_0 + 1U) - 1];
    }

    /* Assertion: '<S170>/Assertion' incorporates:
     *  Product: '<S173>/Product'
     *  Product: '<S173>/Product1'
     *  Product: '<S173>/Product2'
     *  Product: '<S173>/Product3'
     *  Product: '<S173>/Product4'
     *  Product: '<S173>/Product5'
     *  Sum: '<S173>/Sum'
     */
    utAssert(((((rtb_A_out[0] * rtb_A_out[4] * rtb_A_out[8] - rtb_A_out[0] *
                 rtb_A_out[5] * rtb_A_out[7]) - rtb_A_out[1] * rtb_A_out[3] *
                rtb_A_out[8]) + rtb_A_out[2] * rtb_A_out[3] * rtb_A_out[7]) +
              rtb_A_out[1] * rtb_A_out[5] * rtb_A_out[6]) - rtb_A_out[2] *
             rtb_A_out[4] * rtb_A_out[6] != 0.0);

    /* End of Outputs for SubSystem: '<S116>/If Action Subsystem1' */
  }

  /* End of If: '<S116>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
