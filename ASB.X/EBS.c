/* 
 * File:   EBS.h
 * Author: 93Urbano
 *
 * Created on 16 de noviembre de 2021, 11:36
 */

//INCLUDES
#include "EBS.h"
#include "GPIO.h"
#include "mcc_generated_files/pwm2_16bit.h"
#include "mcc_generated_files/pin_manager.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "ANALOG.h"

//FUNCIONES
void EBS_Init (void)
{
    MOSFET1_SetHigh();
    MOSFET2_SetHigh();
    EBS_Watchdog(WD_ENABLE);
}

void EBS_CheckUP_Routine (void)
{
    unsigned char ucCheck;
    
    //0.Check if SDC_is_ready=LOW
    if ( SDC_IS_READY_GetValue() == FALSE )
    {
        ucCheck = 1;
    }
    //1.Start WD
    if ( ucCheck == 1 )
    {
        EBS_Watchdog(WD_ENABLE);
        ucCheck = 2;
    }
    //2.Wait to SDC_is_ready=HIGH
    if ( ucCheck == 2 )
    {
        while ( SDC_IS_READY_GetValue() == FALSE )
        {
            if ( SDC_IS_READY_GetValue() == TRUE )
            {
                ucCheck = 3;
                break;
            }
        }
    }
    //3.Stop WD
    if ( ucCheck == 3 )
    {
        EBS_Watchdog(WD_DISABLE);
        ucCheck = 4;
    }
    //4.Check if SDC_is_ready=LOW, else failure
    if ( ucCheck == 4 )
    {
        while ( SDC_IS_READY_GetValue() == TRUE )
        {
            if ( SDC_IS_READY_GetValue() == FALSE )
            {
                ucCheck = 5;
                break;
            }
        }
    }
    //5.Restart WD
    if ( ucCheck == 5 )
    {
        EBS_Watchdog(WD_ENABLE);
        ucCheck = 6;
    }
    //6.Check EBS neumatic storage sensors
    if ( ucCheck == 6 )
    {
        if ( ( ANALOG_GetVoltage(AN_PICNPRES1) >= NPRES_min ) & ( ANALOG_GetVoltage(AN_PICNPRES1) >= NPRES_min ) )
        {
            ucCheck = 7;
        }
    }
    //7.Check brake pressure sensors
    if ( ucCheck == 7 )
    {
        if ( ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= HDRPRES_min ) & ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= HDRPRES_min ) )
        {
            ucCheck = 8;
        }
    }
    //8.Enable TS activation through AS_close_SDC
    
    //9.Wait for TS being activated
    
    //10.Disable EBS EV1
    if ( ucCheck == 10 )
    {
        MOSFET1_SetLow();
        ucCheck = 11;
    }
    //11.Check brake pressure is buildUP
    if ( ucCheck == 11 )
    {
        DELAY_milliseconds(1000);
        if ( ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= HDRPRES_min ) & ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= HDRPRES_min ) )
        {
            ucCheck = 12;
        }
    }
    //12.Enable EBS EV1
    if ( ucCheck == 12 )
    {
        MOSFET1_SetHigh();
        DELAY_milliseconds(1000);
        ucCheck = 13;
    }
    //13.Disable EBS EV2
    if ( ucCheck == 13 )
    {
        MOSFET2_SetLow();
        ucCheck = 14;
    }
    //14.Check brake pressure is buildUP
    if ( ucCheck == 14 )
    {
        DELAY_milliseconds(1000);
        if ( ( HDRPRES1_GetValue() >= HDRPRES_max ) & ( HDRPRES2_GetValue() >= HDRPRES_max ) )
        {
            ucCheck = 15;
        }
    }
    //15.Enable EBS EV2
    if ( ucCheck == 15 )
    {
        MOSFET2_SetHigh();
        DELAY_milliseconds(1000);
        ucCheck = 16;
        ucASRequesState = AS_READY;
    }
    //16.Transition request to ready state
    if ( ucCheck == 16 )
    {
        CANWriteMessage ( ASB_STATE, DataLength_8, ucASBState, ucASRequesState, 0, 0, 0, 0, 0, 0 );
    }
    
}

void EBS_Watchdog (unsigned char ucWDState)
{
    switch ( ucWDState )
    {
        case WD_DISABLE:
            PWM2_16BIT_Disable();
            break;
        case WD_ENABLE:
            PWM2_16BIT_Enable();
            GPIO_PWM2_Control(50, 100);
            break;
    }
}
