#include "mcu_ini.h"

//------------------------------------------------------------------------------------------------
//Zadayem peremennuy functsiu
//------------------------------------------------------------------------------------------------	
void LEDs_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_LED;
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_LED.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_8;
		GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_Init_LED.GPIO_Speed =  GPIO_Speed_2MHz;
		GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOE , &GPIO_Init_LED);
}
 
//---------------------------------------------------------------------------------------------------
//inithializiruyem cnopku podkluchayem registry
//---------------------------------------------------------------------------------------------------
void Button_ini (void)
{
	GPIO_InitTypeDef GPIO_Init_Button;
	
	RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOA, ENABLE);
	
	GPIO_Init_Button.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init_Button.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Button.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Button.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Button.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_Init_Button);
}

//-----------------------------------------------------------------------------------------------------
//inithializiruyem kontseviki, podkluchaeyem registry
//-----------------------------------------------------------------------------------------------------

void Buttons_ini (void)
{
		GPIO_InitTypeDef GPIO_Init_Button;
	
	RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOD, ENABLE);
	
	GPIO_Init_Button.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12;
	GPIO_Init_Button.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Button.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Button.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Button.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_Button);

}


//------------------------------------------------------------------------------------------------
//Zadayem registry dlya dvigatelya m2
//------------------------------------------------------------------------------------------------	
void M_2_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_M2;
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_M2.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13;
		GPIO_Init_M2.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_Init_M2.GPIO_Speed =  GPIO_Speed_2MHz;
		GPIO_Init_M2.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_M2.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOB , &GPIO_Init_M2);
}

//------------------------------------------------------------------------------------------------
//Zadayem registry dlya dvigatelya m1
//------------------------------------------------------------------------------------------------	
void M_1_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_M1;
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_M1.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9;
		GPIO_Init_M1.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_Init_M1.GPIO_Speed =  GPIO_Speed_2MHz;
		GPIO_Init_M1.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_M1.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD , &GPIO_Init_M1);
}
	
//-----------------------------------------------------------------------------------------------
//functsia dlya borby s drebezgom
//-----------------------------------------------------------------------------------------------
/*uint8_t counter=0;
void systick_button(void)
{
	uint8_t temp;
	
	temp=BUTTON_READ();
	if (temp == 0)
	{
		if(counter<5)
		{
			counter++
		}
	}
}*/
