/* 
 * File:   ANALOG.h
 * Author: DavidJU
 *
 * Created on November 6, 2021, 11:08 PM
 */

#include "ANALOG.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/pin_manager.h"


//VARIABLES
unsigned int ucPICHDRPRES1;
unsigned int ucPICHDRPRES2;
unsigned int ucPICNPRES1;
unsigned int ucPICNPRES2;
unsigned int ucPICNPRES3;
unsigned int ucPICNPRES4;
unsigned int ucAN1;
unsigned int ucAN2;

//**********ANALOG_GetVoltage***********//
//Funcion que devuelve el valor del voltaje calculado de las analogicas)
unsigned char ANALOG_GetVoltage (unsigned char ucEntradaAnalogica)
{
    uint16_t uiValorAnalog;
    uint16_t uiValorVoltage;
    uint16_t uiValorCalculado;
    unsigned char ucValor;
    
    unsigned char ucFlag;
    
    switch (ucEntradaAnalogica)
    {
        case AN_PICHDRPRES1:
            ADC_DisableChannelSequencer();    //Disable scanner
            ADC_SelectContext(CONTEXT_1);
            uiValorAnalog = ADC_GetSingleConversion(HDRPRES1);
            ucFlag = 1;
            break;
        case AN_PICHDRPRES2:
            ADC_DisableChannelSequencer();    //Disable scanner
            ADC_SelectContext(CONTEXT_2);
            uiValorAnalog = ADC_GetSingleConversion(HDRPRES2);
            ucFlag = 1;
            break;
        case AN_PICNPRES1:
            ADC_DisableChannelSequencer();    //Disable scanner
            ADC_SelectContext(CONTEXT_3);
            uiValorAnalog = ADC_GetSingleConversion(NPRES1);
            ucFlag = 2;
            break;
        case AN_PICNPRES2:
            ADC_DisableChannelSequencer();    //Disable scanner
            ADC_SelectContext(CONTEXT_3);
            uiValorAnalog = ADC_GetSingleConversion(NPRES2);
            ucFlag = 2;
            break;
        case AN_PICNPRES3:
            //ADC_DisableChannelSequencer();    //Disable scanner
            //ADC_SelectContext(CONTEXT_3);
            uiValorAnalog = NPRES3_GetValue();
            ucFlag = 2;
            break;
        case AN_PICNPRES4:
            //ADC_DisableChannelSequencer();    //Disable scanner
            //ADC_SelectContext(CONTEXT_3);
            uiValorAnalog = NPRES4_GetValue();
            ucFlag = 2;
            break;
        default:
            ucFlag = 0xFF;
            break;
    }
    
    if ( ucFlag == 1 ) //PRESIONES HDR
    {
        //EXTRAPOLACION LINEAL DE LA GRAFICA
        uiValorVoltage = ((1.1444*uiValorAnalog)-5.2658);
        
        if ( uiValorVoltage > 5000 )
        {
            //fallo de sobrevoltaje
            //o variable da la vuelta
        }
        else //ANALIZAR AQUI EL VOLTAJE EN mV
        {
            uiValorCalculado = ( uiValorVoltage / 5);
            uiValorCalculado = ( uiValorCalculado - 100 );
            uiValorCalculado = ( uiValorCalculado * 10 );
            uiValorCalculado = ( uiValorCalculado / 232 ); //sale el valor en bar
            ucValor = ( uiValorCalculado & 0xFF );
            return (ucValor); //conversion a uc (5V->255)
        }   
    }
    else if ( ucFlag == 2 ) //PRESIONES NEUMATICAS
    {
        //EXTRAPOLACION LINEAL DE LA GRAFICA
        uiValorVoltage = ((1.1444*uiValorAnalog)-5.2658);
        
        if ( uiValorVoltage > 5000 )
        {
            //fallo de sobrevoltaje
            //o variable da la vuelta
        }
        else //ANALIZAR AQUI EL VOLTAJE EN mV
        {
            uiValorCalculado = ( uiValorVoltage * 2 );
            uiValorCalculado = ( uiValorCalculado / 100 );
            ucValor = ( uiValorCalculado & 0xFF );
            return (ucValor); //conversion a uc (5V->255)
        }  
    }
    else
    {
        //fallo en ucFlag
    }

}


void ANALOG_RedAll (void)   //EJECUTAR CON UN TIMER 
{
    ucPICHDRPRES1 = ANALOG_GetVoltage(AN_PICHDRPRES1);
    ucPICHDRPRES2 = ANALOG_GetVoltage(AN_PICHDRPRES2);
    ucPICNPRES1 = ANALOG_GetVoltage(AN_PICNPRES1);
    ucPICNPRES2 = ANALOG_GetVoltage(AN_PICNPRES2);
    ucPICNPRES3 = ANALOG_GetVoltage(AN_PICNPRES3);
    ucPICNPRES4 = ANALOG_GetVoltage(AN_PICNPRES4);
    //ucAN1 = ANALOG_GetVoltage(AN_A1);
    //ucAN2 = ANALOG_GetVoltage(AN_A2);
    
}

