/*
 * File: Analog_Input_Block.h
 *
 * Code generated for Simulink model 'Analog_Input_Block'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 16:36:49 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Analog_Input_Block_h_
#define RTW_HEADER_Analog_Input_Block_h_
#include <math.h>
#include <stddef.h>
#ifndef Analog_Input_Block_COMMON_INCLUDES_
#define Analog_Input_Block_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* Analog_Input_Block_COMMON_INCLUDES_ */

#include "Analog_Input_Block_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/LED 8' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/LED 7' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/LED 6' */
  codertarget_arduinobase_block_T obj_k;/* '<Root>/LED 5' */
  codertarget_arduinobase_block_T obj_l0;/* '<Root>/LED 4' */
  codertarget_arduinobase_block_T obj_nv;/* '<Root>/LED 3' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/LED 2' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/LED 1' */
  codertarget_arduinobase_int_p_T obj_gg;/* '<Root>/PWM' */
} DW_Analog_Input_Block_T;

/* Parameters (default storage) */
struct P_Analog_Input_Block_T_ {
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
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/1023
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Analog_Input_Block_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Analog_Input_Block_T Analog_Input_Block_P;

/* Block states (default storage) */
extern DW_Analog_Input_Block_T Analog_Input_Block_DW;

/* Model entry point functions */
extern void Analog_Input_Block_initialize(void);
extern void Analog_Input_Block_step(void);
extern void Analog_Input_Block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Analog_Input_Block_T *const Analog_Input_Block_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Analog_Input_Block'
 * '<S1>'   : 'Analog_Input_Block/Bit 0'
 * '<S2>'   : 'Analog_Input_Block/Bit 1'
 * '<S3>'   : 'Analog_Input_Block/Bit 2'
 * '<S4>'   : 'Analog_Input_Block/Bit 3'
 * '<S5>'   : 'Analog_Input_Block/Bit 4'
 * '<S6>'   : 'Analog_Input_Block/Bit 5'
 * '<S7>'   : 'Analog_Input_Block/Bit 6'
 * '<S8>'   : 'Analog_Input_Block/Bit 7'
 */
#endif                                 /* RTW_HEADER_Analog_Input_Block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
