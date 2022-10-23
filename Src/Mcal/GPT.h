/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \File:  Gpt_Interface.h
 *       \Module:  GPT
 *
 *	\Author: Andrew Bahaa
 *
 *  \Description:  header file for GPT Module   
 *  
 *********************************************************************************************************************/
#ifndef GPT_INTERFACE_H
#define GPT_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../Common/common_macros.h"
#include "../Common/Std_Types.h"
#include "../Common/tm4c123gh6pm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define F_CPU 16000000UL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
    TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5, TIMER0_W, TIMER1_W, TIMER2_W, TIMER3_W, TIMER4_W, TIMER5_W
}GPT_ChannelId;

typedef enum{
    CONTINUOUS, ONESHOT
}GPT_ChannelMode;

typedef uint32 GPT_ValueType;

 typedef enum{
    NORMAL, CONCATENATE
}GPT_Config; 

typedef struct{
    GPT_ChannelId GPT_Id;
    uint32 GPT_TickFrequency;
    GPT_ValueType GPT_val;
    GPT_ChannelMode GPT_mode;
    void (*callBackFn)(void);
}GPT_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Functon to initialize specific timer */
void Gpt_Init(const GPT_ConfigType *configPtr);

/* Functon to Enable timer's interrupt notification */
void Gpt_EnableIntNotification(GPT_ChannelId id);

/* Functon to Disable timer's interrupt notification */
void Gpt_DisableIntNotification(GPT_ChannelId id);

/* Functon to begin the timer */
void Gpt_StartTimer(GPT_ChannelId id, GPT_ValueType val);

/* Function to stop the timer */
void Gpt_StopTimer(GPT_ChannelId id);

/* ISR for TIMER0 Channel A */
void TIMER0A_Handler(void);

 
#endif  /* GPT_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
