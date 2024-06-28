/*
 * lecture_3A_Model1_data.cpp
 *
 * Code generation for model "lecture_3A_Model1".
 *
 * Model version              : 1.45
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Tue Dec 19 15:01:40 2023
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lecture_3A_Model1.h"
#include "lecture_3A_Model1_private.h"

/* Invariant block signals (default storage) */
const ConstB_lecture_3A_Model1_T lecture_3A_Model1_ConstB = {
  3.0
  ,                                    /* '<S3>/Saturation1' */
  3.0
  ,                                    /* '<S3>/Rounding Function' */
  4.0
  /* '<S3>/Divide1' */
};

/* Constant parameters (default storage) */
const ConstP_lecture_3A_Model1_T lecture_3A_Model1_ConstP = {
  /* Expression: [0.4 0.4 0.3 0.2 0]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.4, 0.4, 0.3, 0.2, 0.0 },

  /* Expression: [0 1000 2000 3000 4000]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.0, 1000.0, 2000.0, 3000.0, 4000.0 }
};
