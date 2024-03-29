/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TRIADActivation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TRIADActivation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* System initialize for atomic system: '<S3>/TRIADActivation_lib' */
void TRIADActivation_lib_Init(DW_TRIADActivation_lib *localDW)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  for (i = 0; i < 10; i++) {
    localDW->Delay_DSTATE[i] = true;
  }

  /* End of InitializeConditions for Delay: '<S158>/Delay' */
}

/* Output and update for atomic system: '<S3>/TRIADActivation_lib' */
boolean_T TRIADActivation_lib(boolean_T rtu_TriadGroundCmd, boolean_T
  rtu_gyro_valid, boolean_T rtu_sunsensor_valid, boolean_T rtu_mag_valid,
  DW_TRIADActivation_lib *localDW)
{
  boolean_T rty_TriadActivate_0;
  int_T idxDelay;
  boolean_T rtb_NAND2;

  /* Logic: '<S121>/NAND2' */
  rtb_NAND2 = (rtu_sunsensor_valid && rtu_mag_valid);

  /* Logic: '<S121>/OR4' incorporates:
   *  Delay: '<S158>/Delay'
   *  Logic: '<S121>/Logical Operator'
   *  Logic: '<S121>/Logical Operator1'
   *  Logic: '<S158>/AND'
   */
  rty_TriadActivate_0 = (rtu_TriadGroundCmd || (!rtu_gyro_valid) || (rtb_NAND2 &&
    localDW->Delay_DSTATE[0]));

  /* Update for Delay: '<S158>/Delay' incorporates:
   *  Logic: '<S158>/NOT'
   */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    localDW->Delay_DSTATE[idxDelay] = localDW->Delay_DSTATE[idxDelay + 1];
  }

  localDW->Delay_DSTATE[9] = !rtb_NAND2;

  /* End of Update for Delay: '<S158>/Delay' */
  return rty_TriadActivate_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
