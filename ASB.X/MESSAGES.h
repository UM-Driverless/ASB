/* 
 * File:   MESSAGE.c
 * Author: 93Urbano
 *
 * Created on September 20, 2021, 10:50 AM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//INCLUDES
#include "mcc_generated_files/mcc.h"
    
    
//DEFINICION DE CONSTANTES    
#define CAN_TX_BUFF  {0,0,0,0,0,0,0,0}
 
CAN_MSG_OBJ msgTransmit;
CAN_MSG_OBJ msgReceipt;

//VARIABLES
extern unsigned char CANDATAdata[8];

extern unsigned char ucTargetAccelerator;
extern unsigned char ucTargetClutch;
extern unsigned char ucTargetBrake;
extern unsigned char ucTargetDirection;
extern unsigned char ucTargetGear;

//DEFINICIONES
#define DataLength_0        			0
#define DataLength_1        			1
#define DataLength_2        			2
#define DataLength_3        			3
#define DataLength_4        			4
#define DataLength_5        			5
#define DataLength_6        			6
#define DataLength_7        			7
#define DataLength_8        			8

//CAN MESSAGES
#define TRAJECTORY_ACT  0x320
#define ASB_ANALOG      0x360
#define ASB_SIGNALS     0x361
#define ASB_STATE       0x362
    
//DEFINICION DE FUNCIONES    
void CANWriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
void CANReadMessage (void);


#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGE_H */
