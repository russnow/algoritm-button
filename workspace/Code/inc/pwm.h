#ifndef PWM_H
#define PWM_H

#include "stm32f30x.h"
#include "main.h"
#include "stm32f30x_tim.h"


void Systick_PWM(void);
void PWM_LED_Off(void);
void PWM_LED_On(void);

void LED_On(void);
void LED_Off(void);
void Set_PWM_A(uint8_t temp);

void Hard_PWM(void);
#endif
