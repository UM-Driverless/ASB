# 1 "PARAMETERS.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/panze/.mchp_packs/Microchip/PIC18F-Q_DFP/1.11.185/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "PARAMETERS.c" 2








# 1 "./PARAMETERS.h" 1
# 27 "./PARAMETERS.h"
extern unsigned char HDRPRES_min;
extern unsigned char HDRPRES_max;
extern unsigned char NPRES_min;
extern unsigned char NPRES_max;



void PARAMETERS_Init (void);
# 9 "PARAMETERS.c" 2



unsigned char HDRPRES_min;
unsigned char HDRPRES_max;
unsigned char NPRES_min;
unsigned char NPRES_max;


void PARAMETERS_Init (void)
{
    HDRPRES_min = 120;
    HDRPRES_max = 2000;
    NPRES_min = 5;
    NPRES_max = 10;
}
