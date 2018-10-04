#include "SA2_0.h"
uint8_t counter3=0;
uint8_t SA2_0_State=0;
uint8_t SA2_0_Flags[2];

//------------------------------------------------------
//gasym drebezg
//------------------------------------------------------
void systick_SA2_0_(void)
	
{		
		uint8_t temp3;
		temp3 = SA_2_0_READ();
		if (temp3 == 0)
		{
			if (counter3>0)
			{
				counter3--;
			}
			else
			{
				if (SA2_0_State == 1)
				{
					SA2_0_Flags[SA_2_0_UNPRESSED_FLAG]++;
					SA2_0_State = 0;
				}
			}
		}
			else
			{
				if ( counter3<5 )
				{
					counter3++;
				}
				else
				{
					if (SA2_0_State == 0)
						SA2_0_Flags[SA_2_0_PRESSED_FLAG]++;
					SA2_0_State =1;
				}
			}
}

//-------------------------------------------------------------
//vozvrachaem znachenie s parapetrom num
//-------------------------------------------------------------
uint8_t getSA2_0_Flag (uint8_t num)
{
	return SA2_0_Flags[num];
}

//-------------------------------------------------------------
//sbrosit v 0
//-------------------------------------------------------------
void clearSA2_0_Flag(uint8_t num)
{
	if (SA2_0_Flags[num]>0)
	{
	SA2_0_Flags[num] --;
	}
}

//--------------------------------------------------------------
//
//--------------------------------------------------------------
void LED_state3_Change(void)
{
	if (getSA2_0_Flag(BUTTON_PRESSED_FLAG)>0) //esli knopka zazhata 
	{
		clearSA2_0_Flag(BUTTON_PRESSED_FLAG); //sbros
	ORANGE_LD8_ON();
	}
	if (getSA2_0_Flag(SA_2_0_UNPRESSED_FLAG)>0) //esli knopka otzhata
	{
		clearSA2_0_Flag(SA_2_0_UNPRESSED_FLAG);
		ORANGE_LD8_OFF();
	}
}