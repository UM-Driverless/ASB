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
#define CAN_TX_BUFF  "BUFFERCAN"
 
CAN_MSG_OBJ msg;
uint8_t CANDATAdata[32] = CAN_TX_BUFF;
    
//DEFINICION DE FUNCIONES    
void CANWriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
    


#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGE_H */
