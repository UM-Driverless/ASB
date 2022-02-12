/* 
 * File:   TEMPORIZATIONS.h
 * Author: DAVIDJ
 *
 * Created on 24 de enero de 2022, 8:29
 */

#include "../ASB.X/mcc_generated_files/pin_manager.h"
#include "TEMPORIZATIONS.h"
#include "MESSAGES.h"
#include "ANALOG.h"

//VARIABLES
unsigned char ucCount500ms;
unsigned char ucCount1s;
unsigned char ucCount10s;
unsigned int uiCount30s;
unsigned int uiCount1min;


//FUNCIONES
void TEMPORIZATION_10ms (void)
{

}

void TEMPORIZATION_100ms (void)
{
    
}

void TEMPORIZATION_500ms (void)
{
    //ANALOG //EJECUTAR CADA 10HZ
    //ANALOG_RedAll();
    //CANWriteMessage ( ASB_ANALOG, 0x08, ucPICHDRPRES1, ucPICHDRPRES2, ucPICNPRES1, ucPICNPRES2, ucPICNPRES3, ucPICNPRES4, ucAN1, ucAN2 );
}

void TEMPORIZATION_1s (void)
{
    LED_Toggle();
}

void TEMPORIZATION_10s (void)
{

}

void TEMPORIZATION_30s (void)
{

}

void TEMPORIZATION_1mins (void)
{
    
}
