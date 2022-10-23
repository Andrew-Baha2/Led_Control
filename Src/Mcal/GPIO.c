/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \File:  <GPIO.c>
 *       \Module:  GPIO
 *
 *		\Author: Andrew Bahaa
 *
 *  \Description:  <Source File for GPIO Module Driver.>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "GPIO.h"

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

/* Function for GPIO PIN initialization */
void GPIO_initPin(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction, GPIO_PullType pull)
{
  volatile uint32 delay;
  /* Guarding condition for invalid port_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {  
    switch(port_num)
    {
    case PORTA_ID:
      /* Need To create a guarding condition for invalid pin_num */
      if(pin_num >= NUM_OF_PINS_PER_PORTA)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R = 0b00000001;        /* Enable clock for PORTA and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R; 
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTA_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTA_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */
        
        GPIO_PORTA_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTA_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTA_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTA_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));     /* Clear PMCx bits for the pin to use it as GPIO pin */
   
        switch(direction)
        {
        case PIN_OUTPUT:
          SET_BIT(GPIO_PORTA_DIR_R,pin_num);
          break;
        case PIN_INPUT:
          CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num);
          break;
        }
      }
      break;
      
    case PORTB_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTB)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R |= 0b00000010;         /* Enable clock for PORTB and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R;        
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTB_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTB_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */        
        
        GPIO_PORTB_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTB_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTB_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTB_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));       /* Clear PMCx bits for the pin to use it as GPIO pin */
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTB_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
        }
      }
      break; 
      
    case PORTC_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTC)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R |= 0b00000100;         /* Enable clock for PORTC and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R;        
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTC_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTC_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */
        
        GPIO_PORTC_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTC_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTC_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTC_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));       /* Clear PMCx bits for the pin to use it as GPIO pin */
        if((pin_num == PIN0_ID) || (pin_num == PIN1_ID) || (pin_num == PIN2_ID) || (pin_num == PIN3_ID))    /* JTAG pins that're needed to be unlocked */
        {
          GPIO_PORTC_LOCK_R = 0X4C4F434B;
          GPIO_PORTC_CR_R   |= (1<<pin_num);
        }
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTC_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
        }
      }
      break;
      
    case PORTD_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTD)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R |= 0b00001000;         /* Enable clock for PORTD and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R;        
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTD_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTD_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */
        
        GPIO_PORTD_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTD_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTD_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTD_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));       /* Clear PMCx bits for the pin to use it as GPIO pin */
        
          GPIO_PORTD_LOCK_R = 0X4C4F434B;
          GPIO_PORTD_CR_R   |= (1<<pin_num);
      
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTD_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
        }
      }
      break;
      
    case PORTE_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTE)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R |= 0b00010000;         /* Enable clock for PORTE and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R;        
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTE_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTE_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */
        
        GPIO_PORTE_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTE_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTE_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTE_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));      /* Clear PMCx bits for the pin to use it as GPIO pin */
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTE_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
        }
      }
      break;
      
    case PORTF_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTF)
      {
        /* Do Nothing */
      }
      else
      {
        SYSCTL_RCGCGPIO_R |= 0b00100000;         /* Enable clock for PORTF and allow time for clock to start */
        delay = SYSCTL_RCGCGPIO_R;
        
        /* First configure if the pin needed to be pulled up or down */
        if(pull == PULL_UP)
          GPIO_PORTF_PUR_R   |= (1<<pin_num);     /* Enable pull-up on DIO pin */
        else if(pull == PULL_DOWN)
          GPIO_PORTF_PDR_R   |= (1<<pin_num);     /* Enable pull-down on DIO pin */
        
        GPIO_PORTF_AMSEL_R &= ~(1<<pin_num);                          /* Disable Analog function for DIO pin */
        GPIO_PORTF_AFSEL_R &= ~(1<<pin_num);                          /* Disable alternative function on DIO pin */
        GPIO_PORTF_DEN_R   |= (1<<pin_num);                           /* Enable Digital I/O on DIO pin */
        GPIO_PORTF_PCTL_R  = 0xFFFFFFFF & ~(0xF << (pin_num*4));      /* Clear PMCx bits for the pin to use it as GPIO pin */
         
        
       if(pin_num == PIN0_ID || pin_num == PIN4_ID)    /* Pin that's needed to be unlocked */
        {
        GPIO_PORTF_LOCK_R = 0X4C4F434B;
          GPIO_PORTF_CR_R   |= (1<<pin_num); 
        }
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTF_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);
        }
      }
      break;    
    }
  }
}
/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
  /* Need To create a guarding condition for invalid port_num or pin_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      /* Need To create a guarding condition for invalid pin_num */
      if(pin_num >= NUM_OF_PINS_PER_PORTA)
      {
        /* Do Nothing */
      }
      else
      {
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTA_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTA_DATA_R,pin_num);
        }
      }
      break;
      
    case PORTB_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTB)
      {
        /* Do Nothing */
      }
      else
      {
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTB_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTB_DATA_R,pin_num);
        }
      }
      break;
      
    case PORTC_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTC)
      {
        /* Do Nothing */
      }
      else
      {
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTC_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTC_DATA_R,pin_num);
        } 
      }
      break;
      
    case PORTD_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTD)
      {
        /* Do Nothing */
      }
      else
      {
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTD_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTD_DATA_R,pin_num);
        } 
      }      
      break;
      
    case PORTE_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTE)
      {
        /* Do Nothing */
      }
      else
      { 
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTE_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTE_DATA_R,pin_num);
        } 
      }
      break;
      
    case PORTF_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTF)
      {
        /* Do Nothing */
      }
      else
      {
        if(value == LOGIC_HIGH)
        {
          SET_BIT(GPIO_PORTF_DATA_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTF_DATA_R,pin_num);
        }
      }
      break;
    }  
  }
}

/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
  uint8 pinValue = LOGIC_LOW;
  
  /* Need To create a guarding condition for invalid port_num or pin_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTA)
      {
        /* Do Nothing */
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTA_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        } 
      }
      break;
      
    case PORTB_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTB)
      {
        /* Do Nothing */
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTB_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        } 
      }
      break;
      
    case PORTC_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTC)
      {
        /* Do Nothing */
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTC_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        } 
      }
      break;
      
    case PORTD_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTD)
      {
        /* Do Nothing */
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTD_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        } 
      }
      break;
      
    case PORTE_ID:
      if(pin_num >= NUM_OF_PINS_PER_PORTE)
      {
        /* Do Nothing */
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTE_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        }
      }
      break;
      
    case PORTF_ID:
     /* if(pin_num >= NUM_OF_PINS_PER_PORTF)
      {
        // Do Nothing 
      }
      else
      {
        if(BIT_IS_SET(GPIO_PORTF_DATA_R, pin_num))
        {
          pinValue = LOGIC_HIGH;
        }
        else
        {
          pinValue = LOGIC_LOW;
        } 
      }*/
      
      pinValue = GET_BIT(GPIO_PORTF_DATA_R,pin_num );
      break;   
    }
  }
  return pinValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_initPort(uint8 port_num, GPIO_PortDirectionType direction, GPIO_PullType pull)
{
  /* Need To create a guarding condition for invalid port_num or pin_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    volatile unsigned long delay = 0;
    
    switch(port_num)
    {
    case PORTA_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000001;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTA_PUR_R |= 0xFF;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTA_PDR_R |= 0xFF;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTA_AMSEL_R &= ~(0xFF);             /* Disable Analog function for DIO pin */
      GPIO_PORTA_AFSEL_R &= ~(0xFF);             /* Disable alternative function on DIO pin */
      GPIO_PORTA_DEN_R   |= 0xFF;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTA_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTA_DIR_R = direction;
      break;
      
    case PORTB_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000002;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTB_PUR_R |= 0xFF;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTB_PDR_R |= 0xFF;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTB_AMSEL_R &= ~(0xFF);             /* Disable Analog function for DIO pin */
      GPIO_PORTB_AFSEL_R &= ~(0xFF);             /* Disable alternative function on DIO pin */
      GPIO_PORTB_DEN_R   |= 0xFF;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTB_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTB_DIR_R = direction;
      break;
      
    case PORTC_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000004;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTC_PUR_R |= 0xFF;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTC_PDR_R |= 0xFF;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTC_AMSEL_R &= ~(0xFF);             /* Disable Analog function for DIO pin */
      GPIO_PORTC_AFSEL_R &= ~(0xFF);             /* Disable alternative function on DIO pin */
      GPIO_PORTC_DEN_R   |= 0xFF;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTC_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTC_DIR_R = direction;
      break;
      
    case PORTD_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000008;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTD_PUR_R |= 0xFF;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTD_PDR_R |= 0xFF;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTD_AMSEL_R &= ~(0xFF);             /* Disable Analog function for DIO pin */
      GPIO_PORTD_AFSEL_R &= ~(0xFF);             /* Disable alternative function on DIO pin */
      GPIO_PORTD_DEN_R   |= 0xFF;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTD_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTD_DIR_R = direction;
      break;
      
    case PORTE_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000010;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTE_PUR_R |= 0x3F;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTE_PDR_R |= 0x3F;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTE_AMSEL_R &= ~(0x3F);             /* Disable Analog function for DIO pin */
      GPIO_PORTE_AFSEL_R &= ~(0x3F);             /* Disable alternative function on DIO pin */
      GPIO_PORTE_DEN_R   |= 0x3F;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTE_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTE_DIR_R = direction;
      break;
      
    case PORTF_ID:
      SYSCTL_RCGCGPIO_R |= 0x00000020;          /* Enable clock for PORTA and allow time for clock to start */
      delay = SYSCTL_RCGCGPIO_R; 
      
      /* First configure if the port needed to be pulled up or down */
      if(pull == PULL_UP)
        GPIO_PORTF_PUR_R |= 0x1F;     /* Enable pull-up on DIO pin */
      else if(pull == PULL_DOWN)
        GPIO_PORTF_PDR_R |= 0x1F;     /* Enable pull-down on DIO pin */
      
      GPIO_PORTF_AMSEL_R &= ~(0x1F);             /* Disable Analog function for DIO pin */
      GPIO_PORTF_AFSEL_R &= ~(0x1F);             /* Disable alternative function on DIO pin */
      GPIO_PORTF_DEN_R   |= 0x1F;                /* Enable Digital I/O on DIO pin */
      GPIO_PORTF_PCTL_R  &= ~(0xFFFFFFFF);       /* Clear PMCx bits for the pin to use it as GPIO pin */
      
      GPIO_PORTF_DIR_R = direction;
      break;
    }
  }
}

void GPIO_writePort(uint8 port_num, uint8 value)
{
  /* Need To create a guarding condition for invalid port_num or pin_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      GPIO_PORTA_DATA_R = value;
      break;
    case PORTB_ID:
      GPIO_PORTB_DATA_R = value;
      break;
    case PORTC_ID:
      GPIO_PORTC_DATA_R = value;
      break;
    case PORTD_ID:
      GPIO_PORTD_DATA_R = value;
      break;
    case PORTE_ID:
      GPIO_PORTE_DATA_R = value;
      break;
    case PORTF_ID:
      GPIO_PORTF_DATA_R = value;
      break;
    }
  }
}

uint8 GPIO_readPort(uint8 port_num)
{
  uint8 value = 0;
  
  /* Need To create a guarding condition for invalid port_num or pin_num */
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      value = GPIO_PORTA_DATA_R;
      break;
    case PORTB_ID:
      value = GPIO_PORTB_DATA_R;
      break;
    case PORTC_ID:
      value = GPIO_PORTC_DATA_R;
      break;
    case PORTD_ID:
      value = GPIO_PORTD_DATA_R;
      break;
    case PORTE_ID:
      value = GPIO_PORTE_DATA_R;
      break;
    case PORTF_ID:
      value = GPIO_PORTF_DATA_R;
      break;
    }
  }
  return value;
}
//////////////////////////////////////////////////////////////////
/*
void GPIO_Int_Init(char port_num, char pin_num){
  __asm("CPSIE I");

  switch (port_num){
    case PORTA_ID:
    SET_BIT(GPIO_PORTA_IM_R, pin_num);
    CLEAR_BIT(GPIO_PORTA_IS_R, pin_num);
    CLEAR_BIT(GPIO_PORTA_IBE_R, pin_num);
    CLEAR_BIT(GPIO_PORTA_IEV_R, pin_num);
    SET_BIT(GPIO_PORTA_ICR_R, pin_num);
    SET_BIT(GPIO_PORTA_IM_R, pin_num);
    SET_BIT(NVIC_EN0_R,0);
    break;

  case PORTF_ID:
    SET_BIT(GPIO_PORTF_IM_R, pin_num);
    CLEAR_BIT(GPIO_PORTF_IS_R, pin_num);
    CLEAR_BIT(GPIO_PORTF_IBE_R, pin_num);
    CLEAR_BIT(GPIO_PORTF_IEV_R, pin_num);
    SET_BIT(GPIO_PORTF_ICR_R, pin_num);
    SET_BIT(GPIO_PORTF_IM_R, pin_num);
    SET_BIT(NVIC_EN0_R,30);
    break;

  }
}
*/

/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
