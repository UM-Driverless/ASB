/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F26Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set HDRPRES1 aliases
#define HDRPRES1_TRIS                 TRISAbits.TRISA0
#define HDRPRES1_LAT                  LATAbits.LATA0
#define HDRPRES1_PORT                 PORTAbits.RA0
#define HDRPRES1_WPU                  WPUAbits.WPUA0
#define HDRPRES1_OD                   ODCONAbits.ODCA0
#define HDRPRES1_ANS                  ANSELAbits.ANSELA0
#define HDRPRES1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define HDRPRES1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define HDRPRES1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define HDRPRES1_GetValue()           PORTAbits.RA0
#define HDRPRES1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define HDRPRES1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define HDRPRES1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define HDRPRES1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define HDRPRES1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define HDRPRES1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define HDRPRES1_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define HDRPRES1_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set HDRPRES2 aliases
#define HDRPRES2_TRIS                 TRISAbits.TRISA1
#define HDRPRES2_LAT                  LATAbits.LATA1
#define HDRPRES2_PORT                 PORTAbits.RA1
#define HDRPRES2_WPU                  WPUAbits.WPUA1
#define HDRPRES2_OD                   ODCONAbits.ODCA1
#define HDRPRES2_ANS                  ANSELAbits.ANSELA1
#define HDRPRES2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define HDRPRES2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define HDRPRES2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define HDRPRES2_GetValue()           PORTAbits.RA1
#define HDRPRES2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define HDRPRES2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define HDRPRES2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define HDRPRES2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define HDRPRES2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define HDRPRES2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define HDRPRES2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define HDRPRES2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA4
#define LED_LAT                  LATAbits.LATA4
#define LED_PORT                 PORTAbits.RA4
#define LED_WPU                  WPUAbits.WPUA4
#define LED_OD                   ODCONAbits.ODCA4
#define LED_ANS                  ANSELAbits.ANSELA4
#define LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_GetValue()           PORTAbits.RA4
#define LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set AS_CLS_SDC aliases
#define AS_CLS_SDC_TRIS                 TRISBbits.TRISB0
#define AS_CLS_SDC_LAT                  LATBbits.LATB0
#define AS_CLS_SDC_PORT                 PORTBbits.RB0
#define AS_CLS_SDC_WPU                  WPUBbits.WPUB0
#define AS_CLS_SDC_OD                   ODCONBbits.ODCB0
#define AS_CLS_SDC_ANS                  ANSELBbits.ANSELB0
#define AS_CLS_SDC_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define AS_CLS_SDC_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define AS_CLS_SDC_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define AS_CLS_SDC_GetValue()           PORTBbits.RB0
#define AS_CLS_SDC_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define AS_CLS_SDC_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define AS_CLS_SDC_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define AS_CLS_SDC_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define AS_CLS_SDC_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define AS_CLS_SDC_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define AS_CLS_SDC_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define AS_CLS_SDC_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set MOSFET2 aliases
#define MOSFET2_TRIS                 TRISBbits.TRISB1
#define MOSFET2_LAT                  LATBbits.LATB1
#define MOSFET2_PORT                 PORTBbits.RB1
#define MOSFET2_WPU                  WPUBbits.WPUB1
#define MOSFET2_OD                   ODCONBbits.ODCB1
#define MOSFET2_ANS                  ANSELBbits.ANSELB1
#define MOSFET2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MOSFET2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MOSFET2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MOSFET2_GetValue()           PORTBbits.RB1
#define MOSFET2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MOSFET2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MOSFET2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MOSFET2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MOSFET2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MOSFET2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MOSFET2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define MOSFET2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set MOSFET1 aliases
#define MOSFET1_TRIS                 TRISBbits.TRISB2
#define MOSFET1_LAT                  LATBbits.LATB2
#define MOSFET1_PORT                 PORTBbits.RB2
#define MOSFET1_WPU                  WPUBbits.WPUB2
#define MOSFET1_OD                   ODCONBbits.ODCB2
#define MOSFET1_ANS                  ANSELBbits.ANSELB2
#define MOSFET1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MOSFET1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MOSFET1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MOSFET1_GetValue()           PORTBbits.RB2
#define MOSFET1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MOSFET1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MOSFET1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define MOSFET1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define MOSFET1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define MOSFET1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define MOSFET1_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define MOSFET1_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set CANSTBY aliases
#define CANSTBY_TRIS                 TRISBbits.TRISB5
#define CANSTBY_LAT                  LATBbits.LATB5
#define CANSTBY_PORT                 PORTBbits.RB5
#define CANSTBY_WPU                  WPUBbits.WPUB5
#define CANSTBY_OD                   ODCONBbits.ODCB5
#define CANSTBY_ANS                  ANSELBbits.ANSELB5
#define CANSTBY_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define CANSTBY_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define CANSTBY_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define CANSTBY_GetValue()           PORTBbits.RB5
#define CANSTBY_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define CANSTBY_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define CANSTBY_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define CANSTBY_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define CANSTBY_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define CANSTBY_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define CANSTBY_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define CANSTBY_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set SDC_IS_READY aliases
#define SDC_IS_READY_TRIS                 TRISCbits.TRISC2
#define SDC_IS_READY_LAT                  LATCbits.LATC2
#define SDC_IS_READY_PORT                 PORTCbits.RC2
#define SDC_IS_READY_WPU                  WPUCbits.WPUC2
#define SDC_IS_READY_OD                   ODCONCbits.ODCC2
#define SDC_IS_READY_ANS                  ANSELCbits.ANSELC2
#define SDC_IS_READY_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDC_IS_READY_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDC_IS_READY_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDC_IS_READY_GetValue()           PORTCbits.RC2
#define SDC_IS_READY_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDC_IS_READY_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDC_IS_READY_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDC_IS_READY_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDC_IS_READY_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDC_IS_READY_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDC_IS_READY_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define SDC_IS_READY_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set NPRES3 aliases
#define NPRES3_TRIS                 TRISCbits.TRISC3
#define NPRES3_LAT                  LATCbits.LATC3
#define NPRES3_PORT                 PORTCbits.RC3
#define NPRES3_WPU                  WPUCbits.WPUC3
#define NPRES3_OD                   ODCONCbits.ODCC3
#define NPRES3_ANS                  ANSELCbits.ANSELC3
#define NPRES3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define NPRES3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define NPRES3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define NPRES3_GetValue()           PORTCbits.RC3
#define NPRES3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define NPRES3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define NPRES3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define NPRES3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define NPRES3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define NPRES3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define NPRES3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define NPRES3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set NPRES4 aliases
#define NPRES4_TRIS                 TRISCbits.TRISC4
#define NPRES4_LAT                  LATCbits.LATC4
#define NPRES4_PORT                 PORTCbits.RC4
#define NPRES4_WPU                  WPUCbits.WPUC4
#define NPRES4_OD                   ODCONCbits.ODCC4
#define NPRES4_ANS                  ANSELCbits.ANSELC4
#define NPRES4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define NPRES4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define NPRES4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define NPRES4_GetValue()           PORTCbits.RC4
#define NPRES4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define NPRES4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define NPRES4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define NPRES4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define NPRES4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define NPRES4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define NPRES4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define NPRES4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set EBSLEDACT aliases
#define EBSLEDACT_TRIS                 TRISCbits.TRISC5
#define EBSLEDACT_LAT                  LATCbits.LATC5
#define EBSLEDACT_PORT                 PORTCbits.RC5
#define EBSLEDACT_WPU                  WPUCbits.WPUC5
#define EBSLEDACT_OD                   ODCONCbits.ODCC5
#define EBSLEDACT_ANS                  ANSELCbits.ANSELC5
#define EBSLEDACT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define EBSLEDACT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define EBSLEDACT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define EBSLEDACT_GetValue()           PORTCbits.RC5
#define EBSLEDACT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define EBSLEDACT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define EBSLEDACT_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define EBSLEDACT_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define EBSLEDACT_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define EBSLEDACT_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define EBSLEDACT_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define EBSLEDACT_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set NPRES2 aliases
#define NPRES2_TRIS                 TRISCbits.TRISC6
#define NPRES2_LAT                  LATCbits.LATC6
#define NPRES2_PORT                 PORTCbits.RC6
#define NPRES2_WPU                  WPUCbits.WPUC6
#define NPRES2_OD                   ODCONCbits.ODCC6
#define NPRES2_ANS                  ANSELCbits.ANSELC6
#define NPRES2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define NPRES2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define NPRES2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define NPRES2_GetValue()           PORTCbits.RC6
#define NPRES2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define NPRES2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define NPRES2_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define NPRES2_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define NPRES2_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define NPRES2_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define NPRES2_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define NPRES2_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set NPRES1 aliases
#define NPRES1_TRIS                 TRISCbits.TRISC7
#define NPRES1_LAT                  LATCbits.LATC7
#define NPRES1_PORT                 PORTCbits.RC7
#define NPRES1_WPU                  WPUCbits.WPUC7
#define NPRES1_OD                   ODCONCbits.ODCC7
#define NPRES1_ANS                  ANSELCbits.ANSELC7
#define NPRES1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define NPRES1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define NPRES1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define NPRES1_GetValue()           PORTCbits.RC7
#define NPRES1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define NPRES1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define NPRES1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define NPRES1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define NPRES1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define NPRES1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define NPRES1_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define NPRES1_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/