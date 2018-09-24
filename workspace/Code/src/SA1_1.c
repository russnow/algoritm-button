#include "SA1_1.h"
uint8_t counter2=0;
uint8_t SA1_1_State=0;
uint8_t SA1_1_Flags[2];

//------------------------------------------------------
//gasym drebezg
//------------------------------------------------------
void systick_SA1_1_(void) //ubirayem drebezg kontsevica SA1.1
	
{		
		uint8_t temp2;
		temp2 = SA_1_1_READ();
		if (temp2 == 0)
		{
			if (counter2>0)
			{
				counter2--;
			}
			else
			{
				if (SA1_1_State == 1)
				{
					SA1_1_Flags[SA_1_1_UNPRESSED_FLAG]++;
					SA1_1_State = 0;
				}
			}
		}
			else
			{
				if ( counter2<5 )
				{
					counter2++;
				}
				else
				{
					if (SA1_1_State == 0)
						SA1_1_Flags[SA_1_1_PRESSED_FLAG]++;
					SA1_1_State =1;
				}
			}
}

//-------------------------------------------------------------
//vozvrachaem znachenie s parapetrom num
//-------------------------------------------------------------
uint8_t getSA1_1_Flag (uint8_t num)
{
	return SA1_1_Flags[num];
}

//-------------------------------------------------------------
//sbrosit v 0
//-------------------------------------------------------------
void clearSA1_1_Flag(uint8_t num)
{
	if (SA1_1_Flags[num]>0)
	{
	SA1_1_Flags[num] --;
	}
}

//--------------------------------------------------------------
//
//--------------------------------------------------------------
void LED_state2_Change(void)
{
	if (getSA1_1_Flag(SA_1_1_PRESSED_FLAG)>0) //esli knopka zazhata
	{
				clearSA1_1_Flag(SA_1_1_PRESSED_FLAG);//sbros
		GREEN_LD6_ON();
				
	}
	if (getSA1_1_Flag(SA_1_1_UNPRESSED_FLAG)>0) //esli knopka otzhata
	{ 
		clearSA1_1_Flag(SA_1_1_UNPRESSED_FLAG);
		RED_LD10_OFF();
		GREEN_LD6_OFF();
	}
}