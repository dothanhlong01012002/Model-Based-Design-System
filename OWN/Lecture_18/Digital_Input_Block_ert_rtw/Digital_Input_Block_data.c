/*
 * File: Digital_Input_Block_data.c
 *
 * Code generated for Simulink model 'Digital_Input_Block'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 14:25:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Digital_Input_Block.h"
#include "Digital_Input_Block_private.h"

/* Block parameters (default storage) */
P_Digital_Input_Block_T Digital_Input_Block_P = {
  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S10>/Vector'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 },

  /* Mask Parameter: Bit0_const
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Mask Parameter: Bit1_const
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Mask Parameter: Bit2_const
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Mask Parameter: Bit3_const
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Mask Parameter: Bit4_const
   * Referenced by: '<S5>/Constant'
   */
  4.0,

  /* Mask Parameter: Bit5_const
   * Referenced by: '<S6>/Constant'
   */
  5.0,

  /* Mask Parameter: Bit6_const
   * Referenced by: '<S7>/Constant'
   */
  6.0,

  /* Mask Parameter: Bit7_const
   * Referenced by: '<S8>/Constant'
   */
  7.0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S13>/FixPt Switch'
   */
  7U,

  /* Expression: 1e-3
   * Referenced by: '<Root>/Button'
   */
  0.001,

  /* Expression: 7
   * Referenced by: '<S9>/Constant'
   */
  7.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S9>/Out1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S9>/Switch'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 500
   * Referenced by: '<Root>/Pulse Generator'
   */
  500.0,

  /* Expression: 250
   * Referenced by: '<Root>/Pulse Generator'
   */
  250.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S13>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S11>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S12>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
