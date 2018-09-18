#include "kurok.h"
uint8_t counter1=0;
uint8_t KurokState=0;
uint8_t KurokFlags[2];

void systick_kurok(void)
	
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
void AK_47(void)
{
	if (getKurokFlag(KUROK_PRESSED_FLAG)>0)
	{
		clearKurokFlag(KUROK_PRESSED_FLAG);
		EN_2_ON();
		IN_3_ON();
	}
	if (getKurokFlag(KUROK_UNPRESSED_FLAG)>0)
	{
		clearKurokFlag(KUROK_UNPRESSED_FLAG);
		//EN_2_OFF();
		//IN_3_OFF();
	}
}