/*
 * File: Analog_Input_Block.c
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

#include "Analog_Input_Block.h"
#include "Analog_Input_Block_private.h"

/* Block states (default storage) */
DW_Analog_Input_Block_T Analog_Input_Block_DW;

/* Real-time model */
static RT_MODEL_Analog_Input_Block_T Analog_Input_Block_M_;
RT_MODEL_Analog_Input_Block_T *const Analog_Input_Block_M =
  &Analog_Input_Block_M_;

/* Model step function */
void Analog_Input_Block_step(void)
{
  codertarget_arduinobase_int_p_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Gain;
  uint16_T rtb_AnalogInput_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Analog_Input_Block_DW.obj.SampleTime !=
      Analog_Input_Block_P.AnalogInput_SampleTime) {
    Analog_Input_Block_DW.obj.SampleTime =
      Analog_Input_Block_P.AnalogInput_SampleTime;
  }

  obj = &Analog_Input_Block_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (Analog_Input_Block_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput_0, 3);

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &Analog_Input_Block_DW.obj_gg;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  rtb_Gain = floor(Analog_Input_Block_P.Gain1_Gain * (real_T)rtb_AnalogInput_0);
  if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain = fmod(rtb_Gain, 256.0);
  }

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  MW_PWM_SetDutyCycle(Analog_Input_Block_DW.obj_gg.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)(rtb_Gain < 0.0 ? (int16_T)(uint8_T)-(int8_T)
    (uint8_T)-rtb_Gain : (int16_T)(uint8_T)rtb_Gain));

  /* Gain: '<Root>/Gain' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  rtb_Gain = Analog_Input_Block_P.Gain_Gain * (real_T)rtb_AnalogInput_0;

  /* MATLABSystem: '<Root>/LED 1' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  writeDigitalPin(10, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit0_const));

  /* MATLABSystem: '<Root>/LED 2' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  writeDigitalPin(9, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit1_const));

  /* MATLABSystem: '<Root>/LED 3' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit2_const));

  /* MATLABSystem: '<Root>/LED 4' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  writeDigitalPin(7, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit3_const));

  /* MATLABSystem: '<Root>/LED 5' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  writeDigitalPin(6, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit4_const));

  /* MATLABSystem: '<Root>/LED 6' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  writeDigitalPin(5, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit5_const));

  /* MATLABSystem: '<Root>/LED 7' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  writeDigitalPin(4, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit6_const));

  /* MATLABSystem: '<Root>/LED 8' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  writeDigitalPin(3, (uint8_T)(rtb_Gain >= Analog_Input_Block_P.Bit7_const));
}

/* Model initialize function */
void Analog_Input_Block_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_int_p_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Analog_Input_Block_DW.obj.matlabCodegenIsDeleted = true;
    Analog_Input_Block_DW.obj.isInitialized = 0L;
    Analog_Input_Block_DW.obj.SampleTime = -1.0;
    Analog_Input_Block_DW.obj.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj.SampleTime =
      Analog_Input_Block_P.AnalogInput_SampleTime;
    obj = &Analog_Input_Block_DW.obj;
    Analog_Input_Block_DW.obj.isSetupComplete = false;
    Analog_Input_Block_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    Analog_Input_Block_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Analog_Input_Block_DW.obj_gg.matlabCodegenIsDeleted = true;
    Analog_Input_Block_DW.obj_gg.isInitialized = 0L;
    Analog_Input_Block_DW.obj_gg.matlabCodegenIsDeleted = false;
    obj_0 = &Analog_Input_Block_DW.obj_gg;
    Analog_Input_Block_DW.obj_gg.isSetupComplete = false;
    Analog_Input_Block_DW.obj_gg.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    Analog_Input_Block_DW.obj_gg.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 1' */
    Analog_Input_Block_DW.obj_p.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(10, 1);
    Analog_Input_Block_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 2' */
    Analog_Input_Block_DW.obj_g.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(9, 1);
    Analog_Input_Block_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 3' */
    Analog_Input_Block_DW.obj_nv.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_nv.isInitialized = 1L;
    digitalIOSetup(8, 1);
    Analog_Input_Block_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 4' */
    Analog_Input_Block_DW.obj_l0.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_l0.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Analog_Input_Block_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 5' */
    Analog_Input_Block_DW.obj_k.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_k.isInitialized = 1L;
    digitalIOSetup(6, 1);
    Analog_Input_Block_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 6' */
    Analog_Input_Block_DW.obj_l.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Analog_Input_Block_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 7' */
    Analog_Input_Block_DW.obj_e.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(4, 1);
    Analog_Input_Block_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED 8' */
    Analog_Input_Block_DW.obj_n.matlabCodegenIsDeleted = false;
    Analog_Input_Block_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(3, 1);
    Analog_Input_Block_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void Analog_Input_Block_terminate(void)
{
  codertarget_arduinobase_int_p_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &Analog_Input_Block_DW.obj;
  if (!Analog_Input_Block_DW.obj.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj.matlabCodegenIsDeleted = true;
    if ((Analog_Input_Block_DW.obj.isInitialized == 1L) &&
        Analog_Input_Block_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (Analog_Input_Block_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &Analog_Input_Block_DW.obj_gg;
  if (!Analog_Input_Block_DW.obj_gg.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_gg.matlabCodegenIsDeleted = true;
    if ((Analog_Input_Block_DW.obj_gg.isInitialized == 1L) &&
        Analog_Input_Block_DW.obj_gg.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Analog_Input_Block_DW.obj_gg.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Analog_Input_Block_DW.obj_gg.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/LED 1' */
  if (!Analog_Input_Block_DW.obj_p.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 1' */

  /* Terminate for MATLABSystem: '<Root>/LED 2' */
  if (!Analog_Input_Block_DW.obj_g.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 2' */

  /* Terminate for MATLABSystem: '<Root>/LED 3' */
  if (!Analog_Input_Block_DW.obj_nv.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_nv.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 3' */

  /* Terminate for MATLABSystem: '<Root>/LED 4' */
  if (!Analog_Input_Block_DW.obj_l0.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 4' */

  /* Terminate for MATLABSystem: '<Root>/LED 5' */
  if (!Analog_Input_Block_DW.obj_k.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 5' */

  /* Terminate for MATLABSystem: '<Root>/LED 6' */
  if (!Analog_Input_Block_DW.obj_l.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 6' */

  /* Terminate for MATLABSystem: '<Root>/LED 7' */
  if (!Analog_Input_Block_DW.obj_e.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 7' */

  /* Terminate for MATLABSystem: '<Root>/LED 8' */
  if (!Analog_Input_Block_DW.obj_n.matlabCodegenIsDeleted) {
    Analog_Input_Block_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
