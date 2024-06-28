/*
 * File: Matlab_Function_1.h
 *
 * Code generated for Simulink model 'Matlab_Function_1'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 20:42:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Matlab_Function_1_h_
#define RTW_HEADER_Matlab_Function_1_h_
#include <stddef.h>
#ifndef Matlab_Function_1_COMMON_INCLUDES_
#define Matlab_Function_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Matlab_Function_1_COMMON_INCLUDES_ */

#include "Matlab_Function_1_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/LED 8' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/LED 7' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/LED 6' */
  codertarget_arduinobase_block_T obj_k;/* '<Root>/LED 5' */
  codertarget_arduinobase_block_T obj_l0;/* '<Root>/LED 4' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/LED 3' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/LED 2' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/LED 1' */
  uint8_T Output_DSTATE;               /* '<S3>/Output' */
} DW_Matlab_Function_1_T;

/* Parameters (default storage) */
struct P_Matlab_Function_1_T_ {
  real_T RepeatingSequenceStair_OutValue[8];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S2>/Vector'
                               */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S3>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S4>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Matlab_Function_1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Matlab_Function_1_T Matlab_Function_1_P;

/* Block states (default storage) */
extern DW_Matlab_Function_1_T Matlab_Function_1_DW;

/* External function called from main */
extern void Matlab_Function_1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Matlab_Function_1_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Matlab_Function_1_initialize(void);
extern void Matlab_Function_1_step0(void);
extern void Matlab_Function_1_step1(void);
extern void Matlab_Function_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Matlab_Function_1_T *const Matlab_Function_1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Matlab_Function_1'
 * '<S1>'   : 'Matlab_Function_1/MATLAB Function'
 * '<S2>'   : 'Matlab_Function_1/Repeating Sequence Stair'
 * '<S3>'   : 'Matlab_Function_1/Repeating Sequence Stair/LimitedCounter'
 * '<S4>'   : 'Matlab_Function_1/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S5>'   : 'Matlab_Function_1/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Matlab_Function_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
