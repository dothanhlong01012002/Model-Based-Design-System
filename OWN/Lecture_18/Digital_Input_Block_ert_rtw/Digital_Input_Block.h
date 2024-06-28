/*
 * File: Digital_Input_Block.h
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

#ifndef RTW_HEADER_Digital_Input_Block_h_
#define RTW_HEADER_Digital_Input_Block_h_
#include <stddef.h>
#ifndef Digital_Input_Block_COMMON_INCLUDES_
#define Digital_Input_Block_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                /* Digital_Input_Block_COMMON_INCLUDES_ */

#include "Digital_Input_Block_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Switch;                       /* '<S9>/Switch' */
} B_Digital_Input_Block_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Button' */
  codertarget_arduinobase_blo_d_T obj_n;/* '<Root>/LED 8' */
  codertarget_arduinobase_blo_d_T obj_e;/* '<Root>/LED 7' */
  codertarget_arduinobase_blo_d_T obj_l;/* '<Root>/LED 6' */
  codertarget_arduinobase_blo_d_T obj_k;/* '<Root>/LED 5' */
  codertarget_arduinobase_blo_d_T obj_l0;/* '<Root>/LED 4' */
  codertarget_arduinobase_blo_d_T obj_nv;/* '<Root>/LED 3' */
  codertarget_arduinobase_blo_d_T obj_g;/* '<Root>/LED 2' */
  codertarget_arduinobase_blo_d_T obj_p;/* '<Root>/LED 1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint8_T Output_DSTATE;               /* '<S11>/Output' */
} DW_Digital_Input_Block_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem ' */
} PrevZCX_Digital_Input_Block_T;

/* Parameters (default storage) */
struct P_Digital_Input_Block_T_ {
  real_T RepeatingSequenceStair_OutValue[8];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S10>/Vector'
                               */
  real_T Bit0_const;                   /* Mask Parameter: Bit0_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Bit1_const;                   /* Mask Parameter: Bit1_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Bit2_const;                   /* Mask Parameter: Bit2_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Bit3_const;                   /* Mask Parameter: Bit3_const
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Bit4_const;                   /* Mask Parameter: Bit4_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Bit5_const;                   /* Mask Parameter: Bit5_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Bit6_const;                   /* Mask Parameter: Bit6_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Bit7_const;                   /* Mask Parameter: Bit7_const
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S13>/FixPt Switch'
                                        */
  real_T Button_SampleTime;            /* Expression: 1e-3
                                        * Referenced by: '<Root>/Button'
                                        */
  real_T Constant_Value;               /* Expression: 7
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S9>/Out1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 500
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 250
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint8_T Constant_Value_e;            /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S11>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S12>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Digital_Input_Block_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Digital_Input_Block_T Digital_Input_Block_P;

/* Block signals (default storage) */
extern B_Digital_Input_Block_T Digital_Input_Block_B;

/* Block states (default storage) */
extern DW_Digital_Input_Block_T Digital_Input_Block_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Digital_Input_Block_T Digital_Input_Block_PrevZCX;

/* Model entry point functions */
extern void Digital_Input_Block_initialize(void);
extern void Digital_Input_Block_step(void);
extern void Digital_Input_Block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Digital_Input_Block_T *const Digital_Input_Block_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'Digital_Input_Block'
 * '<S1>'   : 'Digital_Input_Block/Bit 0'
 * '<S2>'   : 'Digital_Input_Block/Bit 1'
 * '<S3>'   : 'Digital_Input_Block/Bit 2'
 * '<S4>'   : 'Digital_Input_Block/Bit 3'
 * '<S5>'   : 'Digital_Input_Block/Bit 4'
 * '<S6>'   : 'Digital_Input_Block/Bit 5'
 * '<S7>'   : 'Digital_Input_Block/Bit 6'
 * '<S8>'   : 'Digital_Input_Block/Bit 7'
 * '<S9>'   : 'Digital_Input_Block/Triggered Subsystem '
 * '<S10>'  : 'Digital_Input_Block/Triggered Subsystem /Repeating Sequence Stair'
 * '<S11>'  : 'Digital_Input_Block/Triggered Subsystem /Repeating Sequence Stair/LimitedCounter'
 * '<S12>'  : 'Digital_Input_Block/Triggered Subsystem /Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S13>'  : 'Digital_Input_Block/Triggered Subsystem /Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Digital_Input_Block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
