
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \File:  <main.c>
 *
 *       \Author: Andrew Bahaa
 * 
 *  \Description:  <main application (program entry)>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "../Services/LED_PWM.h"

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

int main (void)
{
    Led_Init();
    while(1)
    {
        /*
         * The input for the fuction is number of counts
         * used in the timer to stay ON or OFF.
         * Ex. As we use a 16bit timer (65536 counts)
         * The 65536 counts equivalent to 1 second
         */
        Led_Pwm(2,2);
    }
}