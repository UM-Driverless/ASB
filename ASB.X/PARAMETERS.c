/* 
 * File:   PARAMETERS.h
 * Author: DavidJU
 *
 * Created on November 6, 2021, 10:41 PM
 */

//INCLUDES
#include "PARAMETERS.h"

//DECLARACIONES 
unsigned char HDRPRES_min;
unsigned char HDRPRES_max;
unsigned char NPRES_min;
unsigned char NPRES_max;

//FUNCIONES
void PARAMETERS_Init (void)
{
    HDRPRES_min = 120;
    HDRPRES_max = 2000;
    NPRES_min = 5;
    NPRES_max = 10;
}