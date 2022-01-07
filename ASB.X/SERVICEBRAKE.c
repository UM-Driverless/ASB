/* 
 * File:   SERVICEBRAKE.h
 * Author: DavidJU
 *
 * Created on November 7, 2021, 12:24 AM
 */

//INCLUDES
#include "GPIO.h"
#include "MESSAGES.h"
#include "SERVICEBRAKE.h"


//VARIABLES
unsigned int uiDutyServomotor;
unsigned char ucServoLmin;
unsigned char ucServoLmax;
unsigned char ucServoLDif;

//FUNCIONES
void SERVICEBRAKE_Move (unsigned char ucTargetMove)
{
    ucServoLDif = ucServoLmax - ucServoLmin;
    uiDutyServomotor = ( ucServoLDif * ucTargetMove );
    uiDutyServomotor = ( uiDutyServomotor / 100 );
    uiDutyServomotor += ucServoLmin;
    
    //LIMITAR EL MOVIMIENTO ENTRE UNOS LIMITES EL VALOD DE ucDuty
    if ( ( uiDutyServomotor >= ucServoLmin ) && ( uiDutyServomotor <= ucServoLmax ) )
    {
        if ( ( uiDutyServomotor < 0 ) && ( uiDutyServomotor > 12 ) ) //0-180º con 50Hz
        {
            GPIO_PWM1_Control(uiDutyServomotor, 50);
        }
    }
    else
    {
        //generar error de rango
    }
}


void SERVICEBRAKE_Init (void)
{
    //PONER SERVO DEL PEDAL A 0
    GPIO_PWM1_Control(0, 50);
}