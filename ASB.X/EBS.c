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

unsigned char ucCheckUPError=0;

//FUNCIONES
void EBS_Init (void)
{
    MOSFET1_SetHigh();
    MOSFET2_SetHigh();
    EBS_Watchdog(WD_ENABLE);
    //Test LED EBS init
    EBSLEDACT_SetHigh();
    DELAY_milliseconds(500);
    EBSLEDACT_SetLow();
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
        while ( ucSDC == FALSE )
        {
            /*if ( ucSDC == TRUE )
            {
                ucCheck = 3;
                break;
            }*/
        }
        ucCheck = 3;
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
        if ( SDC_IS_READY_GetValue() == FALSE )
        {
            ucCheck = 5;
        }
        else
        {
           EBSError(SDC_IS_RDY_ERROR);
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
        if ( ( ANALOG_GetVoltage(AN_PICNPRES1) >= NPRES_min ) && ( ANALOG_GetVoltage(AN_PICNPRES2) >= NPRES_min ) && ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= NPRES_max ) && ( ANALOG_GetVoltage(AN_PICHDRPRES2) <= NPRES_max ) )
        {
            ucCheck = 7;
        }
        else
        {
            EBSError(NPRES_STORAGE_ERROR);
        }
    }
    
    //7 Check EBS neumatic storage sensors 3 y 4
    //NO TENEMOS ESTOS SENSORES AL FINAL
    if ( ucCheck == 7 )
    {
        ucCheck = 8;
        /*if ( ( ANALOG_GetVoltage(AN_PICNPRES3) <= NPRES_atm ) && ( ANALOG_GetVoltage(AN_PICNPRES4) <= NPRES_atm ) )
        {
            ucCheck = 8;
        }
        else
        {
            EBSError(NPRES_ACT_ERROR);
        }*/
    }
    //8.Check brake pressure sensors
    if ( ucCheck == 8 )
    {
        //Revisar valores
        if ( ( ANALOG_GetVoltage(AN_PICHDRPRES1) >= HDRPRES_min ) && ( ANALOG_GetVoltage(AN_PICHDRPRES2) >= HDRPRES_min ) && ( ANALOG_GetVoltage(AN_PICHDRPRES1) <= HDRPRES_max ) && ( ANALOG_GetVoltage(AN_PICHDRPRES2) <= HDRPRES_max ))
        {
            ucCheck = 9;
        }
        else
        {
            EBSError(BPRES_ERROR);
        }
    }
    //9.Enable TS activation through AS_close_SDC
    if (ucCheck == 10)
    {
        while (uiRPM <= 2000)
        {
            Nop();
        }
        ucCheck++;
    }
    ucCheck = 11;
    //11.Disable EBS EV1
    if ( ucCheck == 11 )
    {
        MOSFET1_SetLow();
        MOSFET2_SetHigh();
        ucCheck = 12;
    }
    //12.Check brake pressure is buildUP
    if ( ucCheck == 12 )
    {
        DELAY_milliseconds(1000);
        if ( ( ANALOG_GetVoltage(AN_PICHDRPRES1) >= HDRPRES_braking ) && ( ANALOG_GetVoltage(AN_PICHDRPRES1) >= HDRPRES_braking ) 
                && ( ANALOG_GetVoltage(AN_PICNPRES3) >= NPRES_braking ) && ( ANALOG_GetVoltage(AN_PICNPRES4) >= NPRES_atm ))
        {
            ucCheck = 13;
        }
        else
        {
            EBSError(BPRES_NPRES1_ERROR);
        }
    }
    //13.Enable EBS EV1
    if ( ucCheck == 13 )
    {
        MOSFET1_SetHigh();
        MOSFET2_SetHigh();
        DELAY_milliseconds(1000);
        ucCheck = 13;
    }
    //14.Disable EBS EV2
    if ( ucCheck == 14 )
    {
        MOSFET2_SetLow();
        MOSFET1_SetHigh();
        ucCheck = 15;
    }
    //15.Check brake pressure is buildUP
    if ( ucCheck == 15 )
    {
        DELAY_milliseconds(1000);
        if ( ( HDRPRES1_GetValue() >= HDRPRES_max ) & ( HDRPRES2_GetValue() >= HDRPRES_max ) )
        {
            ucCheck = 15;
        }
        else
        {
            EBSError(BPRES_NPRES2_ERROR);
        }
    }
    //16.Enable EBS EV2
    if ( ucCheck == 16 )
    {
        MOSFET2_SetHigh();
        MOSFET1_SetHigh();
        DELAY_milliseconds(1000);
        //ucCheck = 17;
        ucASRequesState = AS_READY;
    }
    //16.Transition request to ready state
    if ( ucCheck == 17 )
    {
        //CANWriteMessage ( ASB_STATE, DataLength_8, ucASBState, ucASRequesState, ucCheckUPError, 0, 0, 0, 0, 0 );
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
            GPIO_PWM2_Control(50, 30);
            break;
    }
}

void EBSLed (void)
{
    if ( ( SDC_IS_READY_GetValue() == FALSE ) && ( ucSDC == FALSE ) )
    {
        EBSLEDACT_SetHigh();
    }
    else
    {
        EBSLEDACT_SetLow();
    }
}

void EBSError (unsigned char Error)
{
    ucCheckUPError = Error;
    EBSLEDACT_SetHigh();
    ucASRequesState = AS_EMERGENCY;
}