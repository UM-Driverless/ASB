/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F26Q84
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "MESSAGES.h"
#include "GPIO.h"
#include "ANALOG.h"
#include "EBS.h"
#include "mcc_generated_files/pin_manager.h"
#include "SERVICEBRAKE.h"
#include "PARAMETERS.h"


unsigned int uiIndex;

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    CANDisableErrorInterrupt(DISABLE);

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    //INICIALIZACIONES HARD
    GPIO_Init();

    //Paramos Tmr0 de 1ms porque no usamos
    TMR0_StopTimer();
    
    //INICIALIZACIONES SOFT
    EBS_Init();
    //SERVICEBRAKE_Init();
    
    
    //DELAY_milliseconds(1000);

    /*DELAY_milliseconds(3000);
    AS_CLS_SDC_SetHigh();
    DELAY_milliseconds(10000);
    EBS_Watchdog(WD_DISABLE);*/
    //EBS_CheckUP_Routine();
    while (1)
    {
        // Add your application code
        //LED_Toggle();
        //MOSFET1_Toggle();
        //MOSFET2_Toggle();
        //EBSLEDACT_Toggle();
        //DELAY_milliseconds(1000);
        Nop();
        //EBSLEDACT_SetHigh();
        
        //PWM, conseguiriamos modificar la posici�n modificando solo el duty
        //GPIO_PWM1_Control(50, 600);
        //GPIO_PWM2_Control(25, 10);

        //PRUEBA DE SERVOMOTOR
        /*uiIndex++;
        if ( uiIndex < 10 )
        {
            GPIO_PWM1_Control(uiIndex, 50);
        }*/
        //GPIO_PWM1_Control(12, 50);
        
        if ( ucASMode == ASMode )
        {
            SERVICEBRAKE_Move(ucTargetBrake);
            MOSFET1_SetLow();
            MOSFET2_SetLow();
        }
        else
        {
            MOSFET1_SetHigh();
            MOSFET2_SetHigh();
        }
        
        //EBSLed();
        
        //
    }
}
/**
 End of File
*/