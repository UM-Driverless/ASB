/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on October 16, 2021, 11:52 AM
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

    
//DECLARACIONES
#define LED_HEARTBEAT   0
#define LED_ERROR       1
    
#define LED_TMR0   0
#define LED_TMR1   1
    
//VARIABLES
extern unsigned char ucLEDState;
extern unsigned char ucPedalPos;
extern unsigned char ucPICHDRPRES1min;
extern unsigned char ucPICHDRPRES2min;

//FUNCIONES
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq);
void GPIO_PWM2_Control (unsigned int uiDutyCycle, unsigned int uiFreq);
void GPIO_LED(unsigned char ucMode);
void GPIO_BrakePedalAtRest (void);



#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

