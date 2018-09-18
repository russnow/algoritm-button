#include "pwm.h"

uint8_t PWM_Counter=0; 	//schetchik kotoryy bydet sravnivat
uint8_t PWM_A=20, PWM_B=20;	//A - opredelyaet period, B - skvazhnost period v ms

uint8_t PWM_LED_On_Counter=0; 	//scheetik plavnogo vkl LED
uint8_t PWM_LED_Off_Counter=0; //schetchik planogo vykl LED

uint8_t PWM_LED_On_flag=0;	 //flag o tom chto mozhno vkluchat svetodiod, kogda Led vkl flag sbrasyvaetsya
uint8_t PWM_LED_Off_flag=0;	//flag o tom chto mozhno vykluchit svetodiod, kogda Led vykl flag sbrasyvaetsya 

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------

void Systick_PWM(void) //podcluchaem cherez systick
{
	if (PWM_Counter >= PWM_B) //zachita ot ne izvestnyh oshibok
	{
		PWM_Counter = 0; //chetchik sbroshen vkl LED
		GREEN_LD6_ON ();
		EN_2_ON();
	}
	
	else if (PWM_Counter == PWM_A)
	{
		PWM_Counter++;
		GREEN_LD6_OFF(); //kak tolko pwm dostygayet A chetchick zapyskaetsya
		EN_2_OFF();
	}
	
	
	else 
	{
	PWM_Counter++;
	}
}

//----------------------------------------------------------------------------
// Plavnoe vkluchenie i vyklucheniye svetodiodov 
//----------------------------------------------------------------------------

void PWM_LED_On(void)
{
	if (PWM_LED_On_flag == 1)
	{
		
	
			if (PWM_LED_On_Counter >= 20)
			{
				PWM_LED_On_Counter = 0;
				if (PWM_A < PWM_B)
				{
					PWM_A++;
				}
				
				else 
					{
					PWM_LED_On_flag = 0;
					}
			}
			
			else 
			{
				PWM_LED_On_Counter++;
			}
	}
}

//-----------------------------------------------------------------------------------
//Plavnoye vykluchenie LED
//-----------------------------------------------------------------------------------

void PWM_LED_Off(void)
{
	if (PWM_LED_Off_flag == 1)
	{
		if (PWM_LED_Off_Counter >=20)
		{
			PWM_LED_Off_Counter = 0;
			if (PWM_A > 0)
			{
				PWM_A--;
			}
			else
			{
				PWM_LED_Off_flag = 0;
			}
		}
			else
			{
				PWM_LED_Off_Counter++;
			}
	}
	
}

//-------------------------------------------------------------------------------------
//vkluchenie flagov
//--------------------------------------------------------------------------------------
void LED_On(void)
{
	PWM_LED_On_flag = 1;
}

void LED_Off(void)
{
	PWM_LED_Off_flag = 1;
}

//--------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------

/*void Hard_PWM(void)
{
	TIM_TimeBaseInitTypeDef TIM_Time_user;
	GPIO_InitTypeDef GPIO_Init_LED;
	TIM_OCInitTypeDef Hard_PWM_ini;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	TIM_Time_user.TIM_Prescaler = 0;
	TIM_Time_user.TIM_CounterMode =TIM_CounterMode_Up;
	TIM_Time_user.TIM_Period = 1000;
	
	TIM_TimeBaseInit(TIM1, &TIM_Time_user);
	
	
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_LED.GPIO_Pin = GPIO_Pin_14;
		GPIO_Init_LED.GPIO_Mode = GPIO_Mode_AF;
		GPIO_Init_LED.GPIO_Speed =  GPIO_Speed_50MHz;
		GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOE , &GPIO_Init_LED);
	
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_2 );
	
	Hard_PWM_ini.TIM_OCMode = TIM_OCMode_PWM1 ;
	Hard_PWM_ini.TIM_OutputState = TIM_OutputState_Enable ;
	
	Hard_PWM_ini.TIM_Pulse = 500;
	Hard_PWM_ini.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC4Init(TIM1,&Hard_PWM_ini);

	TIM_Cmd(TIM1, ENABLE);
}
*/