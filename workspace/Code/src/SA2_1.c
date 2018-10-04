#include "SA2_1.h"
uint8_t counter4=0;
uint8_t SA2_1_State=0;
uint8_t SA2_1_Flags[2];

//------------------------------------------------------
//gasym drebezg
//------------------------------------------------------
void systick_SA2_1_(void)
	
{		
		uint8_t temp4;
		temp4 = SA_2_1_READ();
		if (temp4 == 0)
		{
			if (counter4>0)
			{
				counter4--;
			}
			else
			{
				if (SA2_1_State == 1)
				{
					SA2_1_Flags[SA_2_1_UNPRESSED_FLAG]++;
					SA2_1_State = 0;
				}
			}
		}
			else
			{
				if ( counter4<5 )
				{
					counter4++;
				}
				else
				{
					if (SA2_1_State == 0)
					SA2_1_Flags[SA_2_1_PRESSED_FLAG]++;
					SA2_1_State =1;
				}
			}
}

//-------------------------------------------------------------
//vozvrachaem znachenie s parapetrom num
//-------------------------------------------------------------
uint8_t getSA2_1_Flag (uint8_t num)
{
	return SA2_1_Flags[num];
}

//-------------------------------------------------------------
//sbrosit v 0
//-------------------------------------------------------------
void clearSA2_1_Flag(uint8_t num)
{
	if (SA2_1_Flags[num]>0)
	{
	SA2_1_Flags[num] --;
	}
}

//--------------------------------------------------------------
//
//--------------------------------------------------------------
void LED_state4_Change(void)
{
	if (getSA2_1_Flag(BUTTON_PRESSED_FLAG)>0) //esli knopka zazhata
	{
		clearSA2_1_Flag(BUTTON_PRESSED_FLAG); //sbros
		BLUE_LD9_ON();
	}
	if (getSA2_1_Flag(SA_2_1_UNPRESSED_FLAG)>0) //esli knopka otzhata
	{
		clearSA2_1_Flag(SA_2_1_UNPRESSED_FLAG);
		BLUE_LD9_OFF();
	}
}