#ifndef SA1_1H
#define SA1_1H

#include "stm32f30x.h"
#include "main.h"
#include "kurok.h"

void systick_SA1_1_(void);
uint8_t getSA1_1_Flag (uint8_t num);
void clearSA1_1_Flag(uint8_t num);
void LED_state2_Change(void);


#endif