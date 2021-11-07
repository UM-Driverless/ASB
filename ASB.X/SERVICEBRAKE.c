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
        GPIO_PWM1_Control(ucDutyServomotor, 600);
    }
    else
    {
        //generar error de rango
    }
}