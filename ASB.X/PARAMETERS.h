/* 
 * File:   PARAMETERS.h
 * Author: DavidJU
 *
 * Created on November 6, 2021, 10:41 PM
 */

#ifndef PARAMETERS_H
#define	PARAMETERS_H

#ifdef	__cplusplus
extern "C" {
#endif

//DEFINICIONES 
#define TRUE    1
#define FALSE   0
    
//AS STATES
#define AS_OFF          0
#define AS_READY        1
#define AS_DRIVING      2
#define AS_EMERGENCY    3
#define AS_FINISHED     4
    
//DECLARACIONES 
extern unsigned char HDRPRES_min;
extern unsigned char HDRPRES_max;
extern unsigned char NPRES_min;
extern unsigned char NPRES_max;


//FUNCIONES
void PARAMETERS_Init (void);


#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

