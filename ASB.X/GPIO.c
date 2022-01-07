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
#include "mcc_generated_files/pin_manager.h"
#include "PARAMETERS.h"
#include "ANALOG.h"
#include "SERVICEBRAKE.h"

//VARIABLES
unsigned char ucLEDState;
unsigned char ucPedalPos;
unsigned char ucPICHDRPRES1min;
unsigned char ucPICHDRPRES2min;

//FUNCIONES
void GPIO_Init (void)
{
    //ANALOGICAS
    HDRPRES1_SetAnalogMode();
    HDRPRES2_SetAnalogMode();
    NPRES1_SetAnalogMode();
    NPRES2_SetAnalogMode();
    NPRES3_SetAnalogMode();
    NPRES4_SetAnalogMode();
    
    //DIGITALES
    LED_SetDigitalOutput();
    AS_CLS_SDC_SetDigitalOutput();
    MOSFET1_SetDigitalOutput();
    MOSFET2_SetDigitalOutput();
    CANSTBY_SetDigitalOutput();
    SDC_IS_READY_SetDigitalInput();
    EBSLEDACT_SetDigitalOutput();
}


/****GPIO_PWM1_Control****/
//uiDutyCycle 0 - 100% 
//Servomotores van a 50Hz DC:2-12% GPIO_PWM1_Control(12, 50);
//uiFreq Hz
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq)
{
    unsigned int uiConvertedPeriod;
    unsigned int uiConvertedDC;
    
    //Conversiones
    uiConvertedPeriod = ( ( 39241/uiFreq ) - 1.1508 );
    uiConvertedDC = ( uiDutyCycle * 4 ) * ( 100/uiFreq );
            
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


/****GPIO_LED****/
//Control del LED
void GPIO_LED(unsigned char ucMode)
{
    switch (ucMode)
    {
        case LED_TMR0:
            //ejecutar con TM 1s
            if (ucLEDState == LED_HEARTBEAT)    
            {
                LED_Toggle();
            }
            break;
        case LED_TMR1:
            //ejecutar con TM 100ms
            if (ucLEDState == LED_ERROR)
            {
                LED_Toggle();
            }
            break;
        default:
            LED_SetLow();
            break;
    }
}

void GPIO_BrakePedalAtRest (void)
{
    ucPedalPos = RA5_GetValue();
    if ( ucPedalPos == TRUE )   //Pedal de freno en reposo
    {
        //Consideramos presion HDR como la mínima tarada
        ucPICHDRPRES1min = ANALOG_GetVoltage(AN_PICHDRPRES1);
        ucPICHDRPRES2min = ANALOG_GetVoltage(AN_PICHDRPRES2);
        
        //Consideramos que el duty mínimo es el de esta posición
        ucServoLmin = uiDutyServomotor;
    }
    else    //Pedal de freno en cualquier otra posicion
    {
        
    }
}

