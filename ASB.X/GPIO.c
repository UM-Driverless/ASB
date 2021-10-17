/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on October 16, 2021, 11:52 AM
 */

//INCLUDES
#include "GPIO.h"
#include "mcc_generated_files/pwm1_16bit.h"
#include "mcc_generated_files/pwm2_16bit.h"



//FUNCIONES

/****GPIO_PWM1_Control****/
//uiDutyCycle 0 - 100%
//uiFreq Hz
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq)
{
    unsigned int uiConvertedPeriod;
    unsigned int uiConvertedDC;
    
    //Conversiones
    uiConvertedPeriod = ( ( 39241/uiFreq ) - 1.1508 );
    uiConvertedDC = uiDutyCycle * 4;
            
    //Funciones
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(uiConvertedDC); 
    PWM1_16BIT_WritePeriodRegister(uiConvertedPeriod);
    PWM1_16BIT_LoadBufferRegisters();
}

/****GPIO_PWM2_Control****/
//uiDutyCycle 0 - 100%
//uiFreq Hz
void GPIO_PWM2_Control (unsigned int uiDutyCycle, unsigned int uiFreq)
{
    unsigned int uiConvertedPeriod;
    unsigned int uiConvertedDC;
    
    //Conversiones
    uiConvertedPeriod = ( ( 39241/uiFreq ) - 1.1508 );
    uiConvertedDC = ( uiDutyCycle * 4 ) * ( 100/uiFreq );
    
    //Funciones
    PWM2_16BIT_SetSlice1Output1DutyCycleRegister(uiConvertedDC); 
    PWM2_16BIT_WritePeriodRegister(uiConvertedPeriod);
    PWM2_16BIT_LoadBufferRegisters();
}