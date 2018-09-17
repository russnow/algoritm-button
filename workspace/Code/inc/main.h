#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"
#include "pwm.h"
#include "buttons.h"
//-----------------------------------------------------------------
//
//-----------------------------------------------------------------

#define GREEN_LD6_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_15)
#define GREEN_LD6_OFF()			GPIO_ResetBits (GPIOE, GPIO_Pin_15)

#define ORANGE_LD8_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_14)
#define ORANGE_LD8_OFF()		GPIO_ResetBits (GPIOE, GPIO_Pin_14)

#define RED_LD10_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_13)
#define RED_LD10_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_13)

#define BLUE_LD9_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_12)
#define BLUE_LD9_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_12)

#define GREEN_LD7_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_11)
#define GREEN_LD7_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_11)

#define ORANGE_LD5_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_10)
#define ORANGE_LD5_OFF()		GPIO_ResetBits(GPIOE, GPIO_Pin_10)

#define RED_LD3_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_9)
#define RED_LD3_OFF()				GPIO_ResetBits(GPIOE, GPIO_Pin_9)

#define BLUE_LD4_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_8)
#define BLUE_LD4_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_8)

//--------------------------------------------------------------
//
//--------------------------------------------------------------

#define DELAY						1000 

//-------------------------------------------------------------
// Propisyvayem rezhimy miganiya diodov
//-------------------------------------------------------------

#define MODE_GREEN_LD6	0
#define MODE_ORANGE_LD8	1
#define MODE_RED_LD10		2
#define MODE_BLUE_LD9		3
#define MODE_GREEN_LD7  4
#define MODE_ORANGE_LD5 5
#define MODE_RED_LD3		6
#define MODE_BLUE_LD4		7

//-------------------------
//rezhim oryzhiya
//-------------------------
#define MODE_PISTOLET 	8
#define MODE_AK_47			9

//-------------------------------------------------------------
//Zadayom funkthiyu chteniya knopke user
//-------------------------------------------------------------

#define BUTTON_READ()					GPIO_ReadInputDataBit (GPIOA, GPIO_Pin_0)

#define BUTTON_PRESSED_FLAG 	0
#define BUTTON_UNPRESSED_FLAG	1

//-------------------------------------------------------------
//Zadayom funkthiyu chteniya kontsevicam
//-------------------------------------------------------------

#define START_READ()			GPIO_ReadInputDataBit (GPIOD, GPIO_Pin_15)
#define SA_1_1_READ()			GPIO_ReadInputDataBit (GPIOD, GPIO_Pin_14)
#define SA_2_0_READ()			GPIO_ReadInputDataBit (GPIOD, GPIO_Pin_13)
#define SA_2_1_READ()			GPIO_ReadInputDataBit (GPIOD, GPIO_Pin_12)

//--------------------------------------------------------------------
//vkl i vykl H-most portov
//--------------------------------------------------------------------

#define EN_1_ON()				GPIO_SetBits(GPIOD, GPIO_Pin_11)
#define EN_1_OFF()			GPIO_ResetBits (GPIOD, GPIO_Pin_11)

#define IN_1_ON()				GPIO_SetBits(GPIOD, GPIO_Pin_10)
#define IN_1_OFF()			GPIO_ResetBits (GPIOD, GPIO_Pin_10)

#define IN_2_ON()				GPIO_SetBits(GPIOD, GPIO_Pin_9)
#define IN_2_OFF()			GPIO_ResetBits(GPIOD, GPIO_Pin_9)

#define EN_2_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_15)
#define EN_2_OFF()			GPIO_ResetBits(GPIOB, GPIO_Pin_15)

#define IN_4_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_14)
#define IN_4_OFF()			GPIO_ResetBits(GPIOB, GPIO_Pin_14)

#define IN_3_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_13)
#define IN_3_OFF()			GPIO_ResetBits(GPIOB, GPIO_Pin_13)

#endif

