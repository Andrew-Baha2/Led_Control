/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED_PWM.c
 *        \brief  Controling the application functions
 *
 *				\Author: Andrew Bahaa
 *
 *      \details  Contains all application layer functions used
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "LED_PWM.h"
#include "../HAL/LED.h"
#include "../Mcal/GPIO.h"
#include "../Mcal/GPT.h"
#include "../Mcal/NVIC.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void Led_Init(void)
{
    GPT_ConfigType Timer0Cfg = {TIMER0, 12500, 0xFFFFFFFF, CONTINUOUS};

    Gpt_Init(&Timer0Cfg);
    Gpt_DisableIntNotification(TIMER0);

    NVIC_Init();

    GPIO_initPin(PORTF_ID, PIN1_ID, PIN_OUTPUT, NO_PULL);
    Led_init(PORTF_ID, PIN1_ID, LOGIC_HIGH);
}


void Led_Pwm(uint16 OnCounts,uint16 OffCounts)
{
    Led_init(PORTF_ID, PIN1_ID, LOGIC_LOW);
    Gpt_StartTimer(TIMER0, OnCounts);

    Led_init(PORTF_ID, PIN1_ID, LOGIC_HIGH);
    Gpt_StartTimer(TIMER0, OffCounts);

}

/**********************************************************************************************************************
 *  END OF FILE: LED_PWM.c
 *********************************************************************************************************************/