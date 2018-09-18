#ifndef SA2_0H
#define SA2_0H

#include "stm32f30x.h"
#include "main.h"

void systick_SA2_0_(void);
uint8_t getSA2_0_Flag (uint8_t num);
void clearSA2_0_Flag(uint8_t num);
void LED_state3_Change(void);
//void clearButtonFlag(uint8_t num);
//uint8_t getButtonFlag (uint8_t num);
//void LED_state_Change(void);


#endif