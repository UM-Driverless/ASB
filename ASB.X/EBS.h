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

    
//FUNCIONES
void EBS_Init (void);
void EBS_CheckUP_Routine (void);
void EBS_Watchdog (unsigned char ucWDState);


#ifdef	__cplusplus
}
#endif

#endif	/* EBS_H */

