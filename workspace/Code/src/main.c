#include "main.h"

uint16_t delay_count=0;
uint8_t Mode=0;
uint16_t Mode_count=0;
uint8_t Mode_new=0;

//uint8_t Button_count=0; // ubirAYEM DREBEZG
//uint8_t Button_state=0;

//------------------------------------------------------------------------------------------------
//Functsiu budet vyzyvat kazduy 1ms
//------------------------------------------------------------------------------------------------
void SysTick_Handler(void)
{
						if (delay_count > 0)
						{
							delay_count--;
						}
						//--------------------
						if (Mode_count > 0)
						{
							Mode_count--;
						}
						
						//--------------------------
								//Systick_PWM();
								//PWM_LED_On();
								//PWM_LED_Off();
								//BUTTON();
								systick_button();
								systick_kurok();
								systick_SA2_1_();
								systick_SA2_0_();
								systick_SA1_1_();
							
								
							
					
}					

//------------------------------------------------------------------------------------------------
//gdem poka delay count ne stanet raven nulyu
//------------------------------------------------------------------------------------------------
void delay_ms(uint16_t delay_temp)
{
	delay_count = delay_temp;
	while(delay_count) //gdem poka delay count ne stanet raven nulyu
	{
		
	}
}

//------------------------------------------------------------------------------------------------
//Podklyutchaem peremennuy i initsializiruyem systemnyi timer //1ms
//------------------------------------------------------------------------------------------------
int main (void)
	{
		
		LEDs_ini();
		Button_ini();
		Buttons_ini();
		M_2_ini();
		M_1_ini();
		SysTick_Config(SystemCoreClock/1000); //initsializiruyem systemnyi timer //1ms	
		
		//Hard_PWM();
		Mode_count = DELAY;
		Mode=MODE_GREEN_LD6;
		
		
		//-------------------------------------------------------------------------------
		//vkluchenie i vykluchenie zelenogo dioda
		//---------------------------------------------------------------------------------
		while(1)
			{ 
				//LED_state_Change();
//				GREEN_LD6_ON();
				//EN_2_ON();
				//IN_3_ON();
				//IN_4_OFF();
				//LED_On();
				//delay_ms(2000);
				//LED_Off();
				//EN_2_ON();
				//IN_3_ON();
				//IN_4_OFF();
				//delay_ms(2000);
			}
	}
