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


//FUNCIONES
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq);
void GPIO_PWM2_Control (unsigned int uiDutyCycle, unsigned int uiFreq);

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

