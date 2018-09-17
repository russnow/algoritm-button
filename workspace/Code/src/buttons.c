#include "buttons.h"


uint8_t Pistolet=1 , Pulemet = 0;
uint8_t Mode_vkl=0 , Mode_counter =0;

uint8_t Button_count=0; // ubirAYEM DREBEZG
uint8_t Button_state=0;

//------------------------------------------------------------------------------------------------
//Functsiu budet vyzyvat kazduy 1ms
//------------------------------------------------------------------------------------------------

void BUTTON(void)
{
						//----------------------
						//Nazhatie i othatie cnopki
						//----------------------
						if (BUTTON_READ()==1)
						{
							
												if (Button_count <5)
												{
													Button_count++;
												}
												
													else
														if (Button_state ==0)
													{
														Button_state=1;
														GPIO_ToggleBits(GPIOB, GPIO_Pin_15 | GPIO_Pin_14);//vkluchaem dvigatel
														GPIO_ToggleBits(GPIOE, GPIO_Pin_15);
													}
						}
						//---------------------------
								else
								{
										if (Button_count>0)
										{
											Button_count--;
										}
									
									else
										{
											Button_state=0;
										}
								}
								
}
//----------------------------------------------
//
//-----------------------------------------------

uint8_t counter=0;
uint8_t ButtonState=0;
uint8_t ButtonFlags[2];

/*void systick_button (void)
	
{		
		uint8_t temp;
		temp = BUTTON_READ();
		if (temp == 0)
		{
			if (counter>0)
			{
				counter--;
			}
			else
			{
				if (ButtonState == 1)
				{
					ButtonFlags[BUTTON_UNPRESSED_FLAG]=1;
				ButtonState = 0;
				}
			}
		}
			else
			{
				if ( counter<5 )
				{
					counter++;
				}
				else
				{
					if (ButtonState == 0)
						ButtonFlags[BUTTON_PRESSED_FLAG]=1;
					ButtonState =1;
				}
			}
}*/



