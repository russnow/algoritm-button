#include "kurok.h"
uint8_t counter1=0;
uint8_t KurokState=0;
uint8_t KurokFlags[2];

//------------------------------------------------------
//gasym drebezg
//------------------------------------------------------
void systick_kurok(void) //gasim drebezg
	
{		
		uint8_t temp1;
		temp1 = KUROK_READ();
		if (temp1 == 0)
		{
			if (counter1>0)
			{
				counter1--;
			}
			else
			{
				if (KurokState == 1)
				{
					KurokFlags[KUROK_UNPRESSED_FLAG]++;
					KurokState = 0;
				}
			}
		}
			else
			{
				if ( counter1<5 )
				{
					counter1++;
				}
				else
				{
					if (KurokState == 0)
						KurokFlags[KUROK_PRESSED_FLAG]++;
					KurokState =1;
				}
			}
}

//-------------------------------------------------------------
//vozvrachaem znachenie s parapetrom num
//-------------------------------------------------------------
uint8_t getKurokFlag (uint8_t num)
{
	return KurokFlags[num];
}

//-------------------------------------------------------------
//sbrosit v 0
//-------------------------------------------------------------
void clearKurokFlag(uint8_t num)
{
	if (KurokFlags[num]>0)
	{
	KurokFlags[num] --;
	}
}

//--------------------------------------------------------------
//
//--------------------------------------------------------------
uint8_t flag_sa11=0;
uint8_t flags_sa11=0;
void AK_47(void) //rezhim avtomata
{
	if (getKurokFlag(KUROK_PRESSED_FLAG)>0)
	{
		flags_sa11=1;
		clearKurokFlag(KUROK_PRESSED_FLAG);
		//EN_2_ON();
		//IN_3_ON();
		RED_LD10_ON();
		
	}
	
	if (getKurokFlag(KUROK_UNPRESSED_FLAG)>0)
	{
		
		//if (getSA1_1_Flag(SA_1_1_UNPRESSED_FLAG)>0)
	//{
		//clearSA1_1_Flag(SA_1_1_UNPRESSED_FLAG);
		clearKurokFlag(KUROK_UNPRESSED_FLAG);
		clearSA1_1_Flag(SA_1_1_UNPRESSED_FLAG);
		//RED_LD10_OFF();
		flag_sa11=1;
		//LED_state2_Change();
	}
	if (flag_sa11==1)
	{
		if (getSA1_1_Flag(SA_1_1_UNPRESSED_FLAG)>0)
		{
			RED_LD10_OFF();
			clearSA1_1_Flag(SA_1_1_UNPRESSED_FLAG);
			flag_sa11=0;
		}
	}
		//EN_2_OFF();
		//IN_3_OFF();
	//	RED_LD10_OFF();
	//}
}

void Pistol(void) //Rezhim odinochnogo vystrela
{
	//if(puli>net_patronov)
	//{
		//puli--;
			if (getKurokFlag(KUROK_PRESSED_FLAG)>0) //esli knopka zazhata
		{
			
			clearKurokFlag(KUROK_PRESSED_FLAG);//sbros
			//EN_2_ON();
			//IN_3_ON();
			BLUE_LD4_ON();
		}
	
		//if (getKurokFlag(KUROK_UNPRESSED_FLAG)>0)
		//{
			if (getSA1_1_Flag(SA_1_1_UNPRESSED_FLAG)>0) //esli knopka otzhata
		{
			clearSA1_1_Flag(SA_1_1_UNPRESSED_FLAG);
			
			//clearKurokFlag(KUROK_UNPRESSED_FLAG);
			BLUE_LD4_OFF();
		}
	//}
/*	else if (puli==net_patronov )
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
		//EN_2_OFF();
		//IN_3_OFF();
	//	RED_LD10_OFF();
	//}
