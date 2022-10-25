
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

float on_time=2;
float off_time=2;

int main (void)
{
    Led_Init();
    while(1)
    {
        /*
         * The input for the fuction is number of counts
         * used in the timer to stay ON or OFF.
         * Ex. As we use a 16bit timer (65536 counts)
         * The 65536 counts equivalent to 1 msecond
         */
				uint16 x = GPIO_readPin(PORTF_ID,PIN0_ID);
				uint16 y = GPIO_readPin(PORTF_ID,PIN4_ID);
			
				uint16 last_state_x=1;
				uint16 last_state_y =1;
			
				if (x==0 && last_state_x==1){
			
				on_time++;
				off_time--;
			
				}
				if(y==0 && last_state_y ==1){
				on_time--;
				off_time++;
				}
				Led_Pwm(on_time,off_time);
    }
}
