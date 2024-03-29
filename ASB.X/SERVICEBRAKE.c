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
#include "PARAMETERS.h"


//VARIABLES
unsigned int uiDutyServomotor;
unsigned char ucServoLmin;
unsigned char ucServoLmax;
unsigned char ucServoLDif;
unsigned char ucASBBeatSupervisor = FALSE; 
unsigned char ucASBFlagSupervisor = FALSE; 


//FUNCIONES
void SERVICEBRAKE_Move (unsigned char ucTargetMove)
{
    /*ucServoLDif = ucServoLmax - ucServoLmin;
    uiDutyServomotor = ( ucServoLDif * ucTargetMove );
    uiDutyServomotor = ( uiDutyServomotor / 100 );
    uiDutyServomotor += ucServoLmin;*/
    if (ucASBFlagSupervisor==TRUE)
    {
        if ( ucASMode == ASMode )
        {
            uiDutyServomotor = ucTargetMove * 60;
            uiDutyServomotor = uiDutyServomotor / 100;
            uiDutyServomotor = (uiDutyServomotor & 0xFF);
            GPIO_PWM1_Control(uiDutyServomotor, 300);
            //LIMITAR EL MOVIMIENTO ENTRE UNOS LIMITES EL VALOR DE ucDuty
            /*if ( ( uiDutyServomotor >= ucServoLmin ) && ( uiDutyServomotor <= ucServoLmax ) )
            {
                if ( ( uiDutyServomotor < 0 ) && ( uiDutyServomotor > 12 ) ) //0-180� con 50Hz
                {
                    GPIO_PWM1_Control(uiDutyServomotor, 50);
                }
            }
            else
            {
                //generar error de rango
            }*/
        }
    }

    else //no recibimos nada frenamos
    {
         //GPIO_PWM1_Control(60, 300);
    }
}

//movimiento en el caso de poner motor para mover el pedal, no compatible con WD
void ETC_Move (unsigned char ucTargetMove)
{
    uiDutyServomotor = ucTargetMove * 60;
    uiDutyServomotor = uiDutyServomotor / 100;
    uiDutyServomotor = (uiDutyServomotor & 0xFF);
    GPIO_PWM2_Control(uiDutyServomotor, 300);

}


void SERVICEBRAKE_Init (void)
{
    //PONER SERVO DEL PEDAL A 0
    GPIO_PWM1_Control(0, 300);
    //GPIO_PWM2_Control(0, 300);
}

void ASBSupervisor(void)
{
    
    Nop();
    if ( ucASBBeatSupervisor == TRUE )
    {
        ucASBFlagSupervisor = TRUE; //PERMITO MOVIMIENTO
    }
    else
    {
        ucASBFlagSupervisor = FALSE; //NO PERMITO MOVER 
        //poner freno a 100
        //GPIO_PWM1_Control(60, 300); //60 ES EL PUNTO MAXIMO
        //GPIO_PWM1_Control(0, 300); //60 ES EL PUNTO MAXIMO
    }
}