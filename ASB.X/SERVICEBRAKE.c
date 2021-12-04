/* 
 * File:   SERVICEBRAKE.h
 * Author: DavidJU
 *
 * Created on November 7, 2021, 12:24 AM
 */

//INCLUDES
#include "GPIO.h"
#include "MESSAGES.h"


//VARIABLES
unsigned char ucDutyServomotor;
unsigned char ucServoLmin;
unsigned char ucServoLmax;



//FUNCIONES
void SERVICEBRAKE_Move (unsigned char ucTargetMove)
{
    //CONSIDERAMOS QUE ucServoLmin fisico es cuando ucTargetBrake = 0
    ucDutyServomotor = ucServoLmin + ucTargetMove;
    //LIMITAR EL MOVIMIENTO ENTRE UNOS LIMITES EL VALOD DE ucDuty
    if ( ( ucDutyServomotor >= ucServoLmin ) && ( ucDutyServomotor <= ucServoLmax ) )
    {
        if ( ( ucDutyServomotor < 0 ) && ( ucDutyServomotor > 12 ) ) //0-180º con 50Hz
        {
            GPIO_PWM1_Control(ucDutyServomotor, 50);
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