/*
 * File: LED_2.h
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

#ifndef RTW_HEADER_LED_2_h_
#define RTW_HEADER_LED_2_h_
#include <stddef.h>
#ifndef LED_2_COMMON_INCLUDES_
#define LED_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* LED_2_COMMON_INCLUDES_ */

#include "LED_2_types.h"
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
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output7' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Output6' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Output5' */
  codertarget_arduinobase_block_T obj_k;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_l0;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Output' */
  uint8_T Output_DSTATE;               /* '<S10>/Output' */
} DW_LED_2_T;

/* Parameters (default storage) */
struct P_LED_2_T_ {
  real_T RepeatingSequenceStair_OutValue[8];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S9>/Vector'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S3>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S4>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S5>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S6>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S7>/Constant'
                                      */
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S8>/Constant'
                                      */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S12>/FixPt Switch'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S10>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S11>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_LED_2_T {
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
extern P_LED_2_T LED_2_P;

/* Block states (default storage) */
extern DW_LED_2_T LED_2_DW;

/* External function called from main */
extern void LED_2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void LED_2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void LED_2_initialize(void);
extern void LED_2_step0(void);
extern void LED_2_step1(void);
extern void LED_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LED_2_T *const LED_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S9>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'LED_2'
 * '<S1>'   : 'LED_2/Compare To Constant'
 * '<S2>'   : 'LED_2/Compare To Constant1'
 * '<S3>'   : 'LED_2/Compare To Constant2'
 * '<S4>'   : 'LED_2/Compare To Constant3'
 * '<S5>'   : 'LED_2/Compare To Constant4'
 * '<S6>'   : 'LED_2/Compare To Constant5'
 * '<S7>'   : 'LED_2/Compare To Constant6'
 * '<S8>'   : 'LED_2/Compare To Constant7'
 * '<S9>'   : 'LED_2/Repeating Sequence Stair'
 * '<S10>'  : 'LED_2/Repeating Sequence Stair/LimitedCounter'
 * '<S11>'  : 'LED_2/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S12>'  : 'LED_2/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_LED_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
