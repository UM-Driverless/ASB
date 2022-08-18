/* 
 * File:   EBS.h
 * Author: 93Urbano
 *
 * Created on 16 de noviembre de 2021, 11:36
 */

#ifndef EBS_H
#define	EBS_H

#ifdef	__cplusplus
extern "C" {
#endif

//DEFINES
#define WD_DISABLE  0
#define WD_ENABLE   1
    
//ERRORES CHECKUP
#define SDC_IS_RDY_ERROR    1
#define NPRES_STORAGE_ERROR 2
#define NPRES_ACT_ERROR     3
#define BPRES_ERROR         4
#define BPRES_NPRES1_ERROR  5
#define BPRES_NPRES2_ERROR  6
    

extern unsigned char ucCheckUPError;
    
//FUNCIONES
void EBS_Init (void);
void EBS_CheckUP_Routine (void);
void EBS_Watchdog (unsigned char ucWDState);
void EBSLed (void);
void EBSError (unsigned char Error);


#ifdef	__cplusplus
}
#endif

#endif	/* EBS_H */

