/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rwa_allocation_lib.c
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

#include "rwa_allocation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Forward declaration for local functions */
static void rt_invd3x3_snf_l(const real_T u[9], real_T y[9],
  DW_rwa_allocation_lib *localDW);
static void rt_invd3x3_snf_l(const real_T u[9], real_T y[9],
  DW_rwa_allocation_lib *localDW)
{
  int32_T itmp;
  memcpy(&localDW->x[0], &u[0], 9U * sizeof(real_T));
  localDW->p1 = 0;
  localDW->p2 = 3;
  localDW->p3 = 6;
  localDW->absx11 = fabs(u[0]);
  localDW->absx21 = fabs(u[1]);
  localDW->absx31 = fabs(u[2]);
  if ((localDW->absx21 > localDW->absx11) && (localDW->absx21 > localDW->absx31))
  {
    localDW->p1 = 3;
    localDW->p2 = 0;
    localDW->x[0] = u[1];
    localDW->x[1] = u[0];
    localDW->x[3] = u[4];
    localDW->x[4] = u[3];
    localDW->x[6] = u[7];
    localDW->x[7] = u[6];
  } else {
    if (localDW->absx31 > localDW->absx11) {
      localDW->p1 = 6;
      localDW->p3 = 0;
      localDW->x[2] = localDW->x[0];
      localDW->x[0] = u[2];
      localDW->x[5] = localDW->x[3];
      localDW->x[3] = u[5];
      localDW->x[8] = localDW->x[6];
      localDW->x[6] = u[8];
    }
  }

  localDW->absx31 = localDW->x[1] / localDW->x[0];
  localDW->x[1] = localDW->absx31;
  localDW->absx11 = localDW->x[2] / localDW->x[0];
  localDW->x[2] = localDW->absx11;
  localDW->x[4] -= localDW->absx31 * localDW->x[3];
  localDW->x[5] -= localDW->absx11 * localDW->x[3];
  localDW->x[7] -= localDW->absx31 * localDW->x[6];
  localDW->x[8] -= localDW->absx11 * localDW->x[6];
  if (fabs(localDW->x[5]) > fabs(localDW->x[4])) {
    itmp = localDW->p2;
    localDW->p2 = localDW->p3;
    localDW->p3 = itmp;
    localDW->x[1] = localDW->absx11;
    localDW->x[2] = localDW->absx31;
    localDW->absx11 = localDW->x[4];
    localDW->x[4] = localDW->x[5];
    localDW->x[5] = localDW->absx11;
    localDW->absx11 = localDW->x[7];
    localDW->x[7] = localDW->x[8];
    localDW->x[8] = localDW->absx11;
  }

  localDW->absx31 = localDW->x[5] / localDW->x[4];
  localDW->x[8] -= localDW->absx31 * localDW->x[7];
  localDW->absx11 = (localDW->absx31 * localDW->x[1] - localDW->x[2]) /
    localDW->x[8];
  localDW->absx21 = -(localDW->x[7] * localDW->absx11 + localDW->x[1]) /
    localDW->x[4];
  y[localDW->p1] = ((1.0 - localDW->x[3] * localDW->absx21) - localDW->x[6] *
                    localDW->absx11) / localDW->x[0];
  y[localDW->p1 + 1] = localDW->absx21;
  y[localDW->p1 + 2] = localDW->absx11;
  localDW->absx11 = -localDW->absx31 / localDW->x[8];
  localDW->absx21 = (1.0 - localDW->x[7] * localDW->absx11) / localDW->x[4];
  y[localDW->p2] = -(localDW->x[3] * localDW->absx21 + localDW->x[6] *
                     localDW->absx11) / localDW->x[0];
  y[localDW->p2 + 1] = localDW->absx21;
  y[localDW->p2 + 2] = localDW->absx11;
  localDW->absx11 = 1.0 / localDW->x[8];
  localDW->absx21 = -localDW->x[7] * localDW->absx11 / localDW->x[4];
  y[localDW->p3] = -(localDW->x[3] * localDW->absx21 + localDW->x[6] *
                     localDW->absx11) / localDW->x[0];
  y[localDW->p3 + 1] = localDW->absx21;
  y[localDW->p3 + 2] = localDW->absx11;
}

/* System initialize for atomic system: '<S5>/rwa_allocation_lib' */
void rwa_allocation_lib_Init(DW_rwa_allocation_lib *localDW,
  P_rwa_allocation_lib *localP)
{
  /* SystemInitialize for IfAction SubSystem: '<S232>/If Action Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S275>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[0] = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_DSTATE[1] = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_DSTATE[2] = localP->DiscreteTimeIntegrator_IC;

  /* End of SystemInitialize for SubSystem: '<S232>/If Action Subsystem' */
}

/* Output and update for atomic system: '<S5>/rwa_allocation_lib' */
void rwa_allocation_lib(const real_T rtu_torque_body_Nm[3], const real_T
  rtu_rwa_radps[4], const boolean_T rtu_rwa_valid[4], real_T
  rty_torque_wheel_Nm[4], DW_rwa_allocation_lib *localDW, P_rwa_allocation_lib
  *localP)
{
  static const int8_T a[32] = { 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, -1 };

  uint8_T n_whl;
  boolean_T tmp;
  boolean_T exitg1;

  /* If: '<S232>/If' incorporates:
   *  Constant: '<S280>/Constant1'
   *  Gain: '<S275>/feedback_gain'
   *  Gain: '<S275>/wheel_inertia_kgm2'
   *  Logic: '<S232>/Logical Operator'
   *  MATLAB Function: '<S280>/MATLAB Function'
   *  Sum: '<S275>/Sum1'
   *  Sum: '<S275>/Sum2'
   */
  if (rtu_rwa_valid[0] && rtu_rwa_valid[1] && rtu_rwa_valid[2] && rtu_rwa_valid
      [3]) {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem' incorporates:
     *  ActionPort: '<S275>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S275>/L_inf_allocation_lib' */
    L_inf_allocation_lib(rtu_torque_body_Nm, localDW->output_wheel_a,
                         &localDW->L_inf_allocation_lib_p);

    /* End of Outputs for SubSystem: '<S275>/L_inf_allocation_lib' */

    /* DiscreteIntegrator: '<S275>/Discrete-Time Integrator' */
    localDW->id_good[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
    localDW->id_good[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];
    localDW->id_good[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S275>/L_inf_allocation_lib1' */
    L_inf_allocation_lib(localDW->id_good, localDW->output_wheel,
                         &localDW->L_inf_allocation_lib1);

    /* End of Outputs for SubSystem: '<S275>/L_inf_allocation_lib1' */

    /* MATLAB Function: '<S280>/MATLAB Function' incorporates:
     *  Constant: '<S280>/Constant1'
     */
    localDW->h_err_null_norm[0] = (rtP.fswParams.allocator.h_targ_wheel_Nms[0] -
      rtu_rwa_radps[0] * rtP.fswParams.allocator.inertia[0]) /
      rtP.fswParams.allocator.nullvec[0];
    localDW->h_err_null_norm[1] = (rtP.fswParams.allocator.h_targ_wheel_Nms[1] -
      rtu_rwa_radps[1] * rtP.fswParams.allocator.inertia[1]) /
      rtP.fswParams.allocator.nullvec[1];
    localDW->h_err_null_norm[2] = (rtP.fswParams.allocator.h_targ_wheel_Nms[2] -
      rtu_rwa_radps[2] * rtP.fswParams.allocator.inertia[2]) /
      rtP.fswParams.allocator.nullvec[2];
    localDW->h_err_null_norm[3] = (rtP.fswParams.allocator.h_targ_wheel_Nms[3] -
      rtu_rwa_radps[3] * rtP.fswParams.allocator.inertia[3]) /
      rtP.fswParams.allocator.nullvec[3];
    tmp = rtIsNaN(localDW->h_err_null_norm[0]);
    if (!tmp) {
      localDW->idx = 1;
    } else {
      localDW->idx = 0;
      localDW->n_whl = 2;
      exitg1 = false;
      while ((!exitg1) && (localDW->n_whl < 5)) {
        if (!rtIsNaN(localDW->h_err_null_norm[localDW->n_whl - 1])) {
          localDW->idx = localDW->n_whl;
          exitg1 = true;
        } else {
          localDW->n_whl++;
        }
      }
    }

    if (localDW->idx == 0) {
      localDW->localProduct_m = localDW->h_err_null_norm[0];
    } else {
      localDW->localProduct_m = localDW->h_err_null_norm[localDW->idx - 1];
      while (localDW->idx + 1 < 5) {
        if (localDW->localProduct_m < localDW->h_err_null_norm[localDW->idx]) {
          localDW->localProduct_m = localDW->h_err_null_norm[localDW->idx];
        }

        localDW->idx++;
      }
    }

    if (!tmp) {
      localDW->idx = 1;
    } else {
      localDW->idx = 0;
      localDW->n_whl = 2;
      exitg1 = false;
      while ((!exitg1) && (localDW->n_whl < 5)) {
        if (!rtIsNaN(localDW->h_err_null_norm[localDW->n_whl - 1])) {
          localDW->idx = localDW->n_whl;
          exitg1 = true;
        } else {
          localDW->n_whl++;
        }
      }
    }

    if (localDW->idx == 0) {
      localDW->localProduct = localDW->h_err_null_norm[0];
    } else {
      localDW->localProduct = localDW->h_err_null_norm[localDW->idx - 1];
      while (localDW->idx + 1 < 5) {
        if (localDW->localProduct > localDW->h_err_null_norm[localDW->idx]) {
          localDW->localProduct = localDW->h_err_null_norm[localDW->idx];
        }

        localDW->idx++;
      }
    }

    localDW->localProduct_m = -((localDW->localProduct_m + localDW->localProduct)
      / 2.0);
    localDW->output_wheel_a[0] += (localDW->output_wheel[0] -
      localDW->localProduct_m * rtP.fswParams.allocator.nullvec[0] /
      rtP.fswParams.allocator.inertia[0] * rtP.fswParams.allocator.inertia[0]) *
      rtP.fswParams.allocator.feedback_gain;
    localDW->output_wheel_a[1] += (localDW->output_wheel[1] -
      localDW->localProduct_m * rtP.fswParams.allocator.nullvec[1] /
      rtP.fswParams.allocator.inertia[1] * rtP.fswParams.allocator.inertia[1]) *
      rtP.fswParams.allocator.feedback_gain;
    localDW->output_wheel_a[2] += (localDW->output_wheel[2] -
      localDW->localProduct_m * rtP.fswParams.allocator.nullvec[2] /
      rtP.fswParams.allocator.inertia[2] * rtP.fswParams.allocator.inertia[2]) *
      rtP.fswParams.allocator.feedback_gain;
    localDW->output_wheel_a[3] += (localDW->output_wheel[3] -
      localDW->localProduct_m * rtP.fswParams.allocator.nullvec[3] /
      rtP.fswParams.allocator.inertia[3] * rtP.fswParams.allocator.inertia[3]) *
      rtP.fswParams.allocator.feedback_gain;

    /* Update for DiscreteIntegrator: '<S275>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S280>/Constant1'
     *  Gain: '<S275>/feedback_gain'
     *  Gain: '<S275>/wheel_inertia_kgm2'
     *  MATLAB Function: '<S280>/MATLAB Function'
     *  Sum: '<S275>/Sum1'
     *  Sum: '<S275>/Sum2'
     */
    localDW->DiscreteTimeIntegrator_DSTATE[0] +=
      localP->DiscreteTimeIntegrator_gainval * rtu_torque_body_Nm[0];
    localDW->DiscreteTimeIntegrator_DSTATE[1] +=
      localP->DiscreteTimeIntegrator_gainval * rtu_torque_body_Nm[1];
    localDW->DiscreteTimeIntegrator_DSTATE[2] +=
      localP->DiscreteTimeIntegrator_gainval * rtu_torque_body_Nm[2];

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
      memset(&localDW->A_out[0], 0, 9U * sizeof(real_T));
      localDW->A_out[0] = 1.0;
      localDW->A_out[4] = 1.0;
      localDW->A_out[8] = 1.0;
      break;

     case 3:
      localDW->id_good[0] = 0.0;
      localDW->id_good[1] = 0.0;
      localDW->id_good[2] = 0.0;
      localDW->n_whl = 1;
      if (rtu_rwa_valid[0]) {
        localDW->id_good[0] = 1.0;
        localDW->n_whl = 2;
      }

      if (rtu_rwa_valid[1]) {
        localDW->id_good[localDW->n_whl - 1] = 2.0;
        localDW->n_whl++;
      }

      if (rtu_rwa_valid[2]) {
        localDW->id_good[localDW->n_whl - 1] = 3.0;
        localDW->n_whl++;
      }

      if (rtu_rwa_valid[3]) {
        localDW->id_good[localDW->n_whl - 1] = 4.0;
      }

      for (localDW->n_whl = 0; localDW->n_whl < 3; localDW->n_whl++) {
        localDW->idx = ((int32_T)localDW->id_good[localDW->n_whl] - 1) * 3;
        localDW->A_out[3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[localDW->idx];
        localDW->A_out[1 + 3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[localDW->idx + 1];
        localDW->A_out[2 + 3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[localDW->idx + 2];
      }
      break;

     case 4:
      for (localDW->n_whl = 0; localDW->n_whl < 3; localDW->n_whl++) {
        localDW->A_out[3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[3 * localDW->n_whl];
        localDW->A_out[1 + 3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[3 * localDW->n_whl + 1];
        localDW->A_out[2 + 3 * localDW->n_whl] =
          rtP.fswParams.allocator.A_wheel2body[3 * localDW->n_whl + 2];
      }
      break;

     default:
      memset(&localDW->A_out[0], 0, 9U * sizeof(real_T));
      localDW->A_out[0] = 1.0;
      localDW->A_out[4] = 1.0;
      localDW->A_out[8] = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S276>/MATLAB Function' */

    /* Product: '<S284>/Product' */
    rt_invd3x3_snf_l(localDW->A_out, localDW->dv0, localDW);

    /* Product: '<S276>/Product' */
    for (localDW->n_whl = 0; localDW->n_whl < 3; localDW->n_whl++) {
      localDW->id_good[localDW->n_whl] = localDW->dv0[localDW->n_whl + 6] *
        rtu_torque_body_Nm[2] + (localDW->dv0[localDW->n_whl + 3] *
        rtu_torque_body_Nm[1] + localDW->dv0[localDW->n_whl] *
        rtu_torque_body_Nm[0]);
    }

    /* MATLAB Function: '<S276>/MATLAB Function1' */
    n_whl = 0U;

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    localDW->output_wheel_a[0] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[0]) {
      n_whl = 1U;
      localDW->output_wheel_a[0] = localDW->id_good[0];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    localDW->output_wheel_a[1] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[1]) {
      localDW->n_whl = (int32_T)(n_whl + 1U);
      n_whl++;
      localDW->output_wheel_a[1] = localDW->id_good[(uint8_T)localDW->n_whl - 1];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    localDW->output_wheel_a[2] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[2]) {
      localDW->n_whl = (int32_T)(n_whl + 1U);
      n_whl++;
      localDW->output_wheel_a[2] = localDW->id_good[(uint8_T)localDW->n_whl - 1];
    }

    /* SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm' incorporates:
     *  MATLAB Function: '<S276>/MATLAB Function1'
     */
    localDW->output_wheel_a[3] = 0.0;

    /* MATLAB Function: '<S276>/MATLAB Function1' incorporates:
     *  Product: '<S276>/Product'
     *  SignalConversion: '<S276>/OutportBufferFortorque_wheel_Nm'
     */
    if (rtu_rwa_valid[3]) {
      localDW->output_wheel_a[3] = localDW->id_good[(uint8_T)(n_whl + 1U) - 1];
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
    utAssert(((((localDW->A_out[0] * localDW->A_out[4] * localDW->A_out[8] -
                 localDW->A_out[0] * localDW->A_out[5] * localDW->A_out[7]) -
                localDW->A_out[1] * localDW->A_out[3] * localDW->A_out[8]) +
               localDW->A_out[2] * localDW->A_out[3] * localDW->A_out[7]) +
              localDW->A_out[1] * localDW->A_out[5] * localDW->A_out[6]) -
             localDW->A_out[2] * localDW->A_out[4] * localDW->A_out[6] != 0.0);

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem1' */
  }

  /* End of If: '<S232>/If' */

  /* MATLAB Function: '<S274>/MATLAB Function' incorporates:
   *  Constant: '<S274>/Constant'
   */
  for (localDW->n_whl = 0; localDW->n_whl < 8; localDW->n_whl++) {
    localDW->temp[localDW->n_whl] = ((((real_T)a[localDW->n_whl + 8] *
      localDW->output_wheel_a[1] + (real_T)a[localDW->n_whl] *
      localDW->output_wheel_a[0]) + (real_T)a[localDW->n_whl + 16] *
      localDW->output_wheel_a[2]) + (real_T)a[localDW->n_whl + 24] *
      localDW->output_wheel_a[3]) - rtP.fswParams.allocator.max_torque_Nm;
  }

  if (!rtIsNaN(localDW->temp[0])) {
    localDW->idx = 0;
  } else {
    localDW->idx = -1;
    localDW->n_whl = 2;
    exitg1 = false;
    while ((!exitg1) && (localDW->n_whl < 9)) {
      if (!rtIsNaN(localDW->temp[localDW->n_whl - 1])) {
        localDW->idx = localDW->n_whl - 1;
        exitg1 = true;
      } else {
        localDW->n_whl++;
      }
    }
  }

  if (localDW->idx + 1 == 0) {
    localDW->localProduct_m = localDW->temp[0];
    localDW->idx = 0;
  } else {
    localDW->localProduct_m = localDW->temp[localDW->idx];
    localDW->n_whl = localDW->idx + 1;
    while (localDW->n_whl + 1 < 9) {
      if (localDW->localProduct_m < localDW->temp[localDW->n_whl]) {
        localDW->localProduct_m = localDW->temp[localDW->n_whl];
        localDW->idx = localDW->n_whl;
      }

      localDW->n_whl++;
    }
  }

  if (localDW->localProduct_m > 0.0) {
    localDW->localProduct_m = rtP.fswParams.allocator.max_torque_Nm / ((((real_T)
      a[localDW->idx + 8] * localDW->output_wheel_a[1] + (real_T)a[localDW->idx]
      * localDW->output_wheel_a[0]) + (real_T)a[localDW->idx + 16] *
      localDW->output_wheel_a[2]) + (real_T)a[localDW->idx + 24] *
      localDW->output_wheel_a[3]);
    rty_torque_wheel_Nm[0] = localDW->localProduct_m * localDW->output_wheel_a[0];
    rty_torque_wheel_Nm[1] = localDW->localProduct_m * localDW->output_wheel_a[1];
    rty_torque_wheel_Nm[2] = localDW->localProduct_m * localDW->output_wheel_a[2];
    rty_torque_wheel_Nm[3] = localDW->localProduct_m * localDW->output_wheel_a[3];
  } else {
    rty_torque_wheel_Nm[0] = localDW->output_wheel_a[0];
    rty_torque_wheel_Nm[1] = localDW->output_wheel_a[1];
    rty_torque_wheel_Nm[2] = localDW->output_wheel_a[2];
    rty_torque_wheel_Nm[3] = localDW->output_wheel_a[3];
  }

  /* End of MATLAB Function: '<S274>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
