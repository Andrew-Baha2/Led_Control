/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  General purpose timer
 *
 *				\Author: Andrew Bahaa
 *
 *      \details  The Driver Configure All MCU Timers for specific usage
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "GPT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

void (*PtrToCallBackFunctionTimer0)(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* Functon to initialize specific timer */
void Gpt_Init(const GPT_ConfigType *configPtr)
{
    switch (configPtr->GPT_Id)
    {
    case TIMER0:
      SYSCTL_RCGCTIMER_R |= 0x01;
      SET_BIT(TIMER0_CFG_R, 2);
    	SET_BIT(TIMER0_TAMR_R, 4);

        if(configPtr->GPT_mode == CONTINUOUS )
        {
			SET_BIT(TIMER0_TAMR_R, 1);
		}
        else if(configPtr->GPT_mode == ONESHOT)
        {
			SET_BIT(TIMER0_TAMR_R, 0);
		}

        TIMER0_TAPR_R = (F_CPU/configPtr->GPT_TickFrequency);
        PtrToCallBackFunctionTimer0 = configPtr ->callBackFn;
        break;
    default:
        break;
    }
}

/* Functon to Enable timer's interrupt notification */
void Gpt_EnableIntNotification(GPT_ChannelId id)
{
    switch(id)
    {
    case TIMER0:
        SET_BIT(TIMER0_IMR_R, 0);
        break;
    default:
        break;
    }
}

/* Functon to Disable timer's interrupt notification */
void Gpt_DisableIntNotification(GPT_ChannelId id)
{
    switch (id)
    {
    case TIMER0:
        CLEAR_BIT(TIMER0_IMR_R, 0);
        break;
    
    default:
        break;
    }
}

/* Functon to begin the timer */
void Gpt_StartTimer(GPT_ChannelId id, GPT_ValueType val)
{
    switch (id)
    {
    case TIMER0:
        TIMER0_CTL_R = 0x0;
        TIMER0_TAILR_R = val;
        TIMER0_TAPR_R = 0x02;
        TIMER0_ICR_R = 0x1; 
        TIMER0_CTL_R |= 0x03;
        /* while ((TIMER0_RIS_R & 0x1) == 0); */  // to use polling
        break;
    
    default:
        break;
    }
}

/* Function to stop the timer */
void Gpt_StopTimer(GPT_ChannelId id)
{
    switch(id)
    {
	case TIMER0:
    	CLEAR_BIT(TIMER0_CTL_R, 0);
		break;
	}
}

/* ISR for TIMER0 Channel A */
void TIMER0A_Handler(void)
{
    PtrToCallBackFunctionTimer0();
}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
