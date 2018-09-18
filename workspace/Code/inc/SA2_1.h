#ifndef SA2_1H
#define SA2_1H

#include "stm32f30x.h"
#include "main.h"

void systick_SA2_1_(void);
uint8_t getSA2_1_Flag (uint8_t num);
void clearSA2_1_Flag(uint8_t num);
void LED_state4_Change(void);
//void clearButtonFlag(uint8_t num);
//uint8_t getButtonFlag (uint8_t num);
//void LED_state_Change(void);


#endif