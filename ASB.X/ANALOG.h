/* 
 * File:   ANALOG.h
 * Author: DavidJU
 *
 * Created on November 6, 2021, 11:08 PM
 */

#ifndef ANALOG_H
#define	ANALOG_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//DEFINICIONES
//Entradas analógicas     
#define AN_PICHDRPRES1         0
#define AN_PICHDRPRES2         1
#define AN_PICNPRES1           2
#define AN_PICNPRES2           3
#define AN_PICNPRES3           4
#define AN_PICNPRES4           5
#define AN_A1                  6
#define AN_A2                  7
    
    
//VARIABLES
extern unsigned int ucPICHDRPRES1;
extern unsigned int ucPICHDRPRES2;
extern unsigned int ucPICNPRES1;
extern unsigned int ucPICNPRES2;
extern unsigned int ucPICNPRES3;
extern unsigned int ucPICNPRES4;
extern unsigned int ucAN1;
extern unsigned int ucAN2;


//FUNCIONES
unsigned char ANALOG_GetVoltage (unsigned char ucEntradaAnalogica);
void ANALOG_RedAll (void);


#ifdef	__cplusplus
}
#endif

#endif	/* ANALOG_H */

