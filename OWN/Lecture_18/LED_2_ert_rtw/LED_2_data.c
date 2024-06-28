/*
 * File: LED_2_data.c
 *
 * Code generated for Simulink model 'LED_2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Dec 19 22:00:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LED_2.h"
#include "LED_2_private.h"

/* Block parameters (default storage) */
P_LED_2_T LED_2_P = {
  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S9>/Vector'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S5>/Constant'
   */
  4.0,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S6>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant6_const
   * Referenced by: '<S7>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S8>/Constant'
   */
  7.0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S12>/FixPt Switch'
   */
  7U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S12>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S10>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S11>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
