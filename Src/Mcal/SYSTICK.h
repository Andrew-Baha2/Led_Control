/******************************************************************************
*
* Module: SYSTICK
*
* File Name: SYSTICK.h
*
*	\Author: Andrew Bahaa
*
* Description: Header file for the TIVA-C DIO driver
*
* 
*
*******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../Common/tm4c123gh6pm.h"
#include "../Common/std_types.h"
#include "../Common/common_macros.h"


/*******************************************************************************
*                              Functions Prototypes                           *
*******************************************************************************/


void SystickEnable (void);
void SystickDisable (void);
void SystickPeriodSet(uint32 uin32Period);
uint8 Systick_Is_Time_out(void);
uint32 GetValue();
uint32 GetPeriod();
void SysDelays(uint32 time);

#endif /* DIO_H_ */