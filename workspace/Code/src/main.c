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
		//Mode_count = DELAY;
		Mode=MODE_GREEN_LD6;
		
		uint8_t Mode_new = 0;
		uint8_t Mode=MODE_PISTOLET;
		uint8_t puli=3;
		uint8_t net_patronov=0;
		//-------------------------------------------------------------------------------
		//vkluchenie i vykluchenie zelenogo dioda
		//---------------------------------------------------------------------------------
		while(1)
			{ 
				//AK_47();
				//Pistol();
				
				
				
			/*	if(Mode==MODE_PISTOLET)
				{	
				Mode_new=0;
				Rezhim1();
				Mode=MODE_AK_47;
					

				}	
					
			else	if(Mode==MODE_AK_47)
				{		
				Mode_new=1;
				Rezhim2();
				Mode=MODE_PISTOLET;
			
				}
									if (Mode_new==0)
												{
													Pistol();
												}
												
												else if(Mode_new==1)
												{
													AK_47();
												}
												
												
												
												
												if(puli>net_patronov )
	{
		puli--;
		Pistol();
	}
	else if (puli==net_patronov )
	{
			
			if (getButtonFlag(BUTTON_PRESSED_FLAG)>0)
			{
				clearButtonFlag(BUTTON_PRESSED_FLAG);
				puli=3;	
				//GREEN_LD6_ON();
				ORANGE_LD8_ON();
				
				
			}
				if (getButtonFlag(BUTTON_UNPRESSED_FLAG)>0)
			{
			clearButtonFlag(BUTTON_UNPRESSED_FLAG);
				
				
					ORANGE_LD8_OFF();
					//GREEN_LD6_OFF();
			}

					}*/
	
			}
			
	}

				
				//LED_state4_Change();
				//LED_state3_Change();
				//LED_state2_Change();
		/*	uint8_t rezhim;

		}*/		