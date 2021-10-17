# 1 "GPIO.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/panze/.mchp_packs/Microchip/PIC18F-Q_DFP/1.12.193/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "GPIO.c" 2








# 1 "./GPIO.h" 1
# 17 "./GPIO.h"
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq);
void GPIO_PWM2_Control (unsigned int uiDutyCycle, unsigned int uiFreq);
# 9 "GPIO.c" 2

# 1 "./mcc_generated_files/pwm1_16bit.h" 1
# 54 "./mcc_generated_files/pwm1_16bit.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 54 "./mcc_generated_files/pwm1_16bit.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdbool.h" 1 3
# 55 "./mcc_generated_files/pwm1_16bit.h" 2








void PWM1_16BIT_Initialize(void);






void PWM1_16BIT_Enable();
# 79 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_Disable();
# 96 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_WritePeriodRegister(uint16_t periodCount);
# 114 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_SetSlice1Output1DutyCycleRegister(uint16_t value);
# 131 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_SetSlice1Output2DutyCycleRegister(uint16_t value);
# 148 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_LoadBufferRegisters(void);






void PWM1_16BIT_PWMI_ISR(void);






void PWM1_16BIT_PWMPI_ISR(void);
# 182 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_Slice1Output1_SetInterruptHandler(void (* InterruptHandler)(void));
# 202 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_Slice1Output2_SetInterruptHandler(void (* InterruptHandler)(void));
# 222 "./mcc_generated_files/pwm1_16bit.h"
void PWM1_16BIT_Period_SetInterruptHandler(void (* InterruptHandler)(void));
# 10 "GPIO.c" 2

# 1 "./mcc_generated_files/pwm2_16bit.h" 1
# 63 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_Initialize(void);






void PWM2_16BIT_Enable();
# 79 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_Disable();
# 96 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_WritePeriodRegister(uint16_t periodCount);
# 114 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_SetSlice1Output1DutyCycleRegister(uint16_t value);
# 131 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_SetSlice1Output2DutyCycleRegister(uint16_t value);
# 148 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_LoadBufferRegisters(void);






void PWM2_16BIT_PWMI_ISR(void);






void PWM2_16BIT_PWMPI_ISR(void);
# 182 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_Slice1Output1_SetInterruptHandler(void (* InterruptHandler)(void));
# 202 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_Slice1Output2_SetInterruptHandler(void (* InterruptHandler)(void));
# 222 "./mcc_generated_files/pwm2_16bit.h"
void PWM2_16BIT_Period_SetInterruptHandler(void (* InterruptHandler)(void));
# 11 "GPIO.c" 2
# 20 "GPIO.c"
void GPIO_PWM1_Control (unsigned int uiDutyCycle, unsigned int uiFreq)
{
    unsigned int uiConvertedPeriod;
    unsigned int uiConvertedDC;


    uiConvertedPeriod = ( ( 39241/uiFreq ) - 1.1508 );
    uiConvertedDC = uiDutyCycle * 4;


    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(uiConvertedDC);
    PWM1_16BIT_WritePeriodRegister(uiConvertedPeriod);
    PWM1_16BIT_LoadBufferRegisters();
}




void GPIO_PWM2_Control (unsigned int uiDutyCycle, unsigned int uiFreq)
{
    unsigned int uiConvertedPeriod;
    unsigned int uiConvertedDC;


    uiConvertedPeriod = ( ( 39241/uiFreq ) - 1.1508 );
    uiConvertedDC = ( uiDutyCycle * 4 ) * ( 100/uiFreq );


    PWM2_16BIT_SetSlice1Output1DutyCycleRegister(uiConvertedDC);
    PWM2_16BIT_WritePeriodRegister(uiConvertedPeriod);
    PWM2_16BIT_LoadBufferRegisters();
}
