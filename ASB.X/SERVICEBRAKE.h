/* 
 * File:   SERVICEBRAKE.h
 * Author: DavidJU
 *
 * Created on November 7, 2021, 12:24 AM
 */

#ifndef SERVICEBRAKE_H
#define	SERVICEBRAKE_H

#ifdef	__cplusplus
extern "C" {
#endif

    
//VARIABLES
extern unsigned int uiDutyServomotor;
extern unsigned char ucServoLmin;
extern unsigned char ucServoLmax;
extern unsigned char ucServoLDif;
extern unsigned char ucASBBeatSupervisor; 
extern unsigned char ucASBFlagSupervisor; 
//FUNCIONES
void SERVICEBRAKE_Move (unsigned char ucTargetMove);
void SERVICEBRAKE_Init (void);
void ETC_Move (unsigned char ucTargetMove);
void ASBSupervisor(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SERVICEBRAKE_H */

