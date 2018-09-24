#ifndef BUTTONS_H
#define BUTTONS_H

#include "stm32f30x.h"
#include "main.h"


//void UZUMYMW (void);
//void BUTTON(void);
void systick_button (void);
void clearButtonFlag(uint8_t num);
uint8_t getButtonFlag (uint8_t num);
void LED_state_Change(void);
void Rezhim1(void);
void Rezhim2(void);
//void START(void);
//void SA_1_1(void);
//void SA_2_0 (void);

#endif