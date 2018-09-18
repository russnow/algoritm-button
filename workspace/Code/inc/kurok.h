#ifndef KUROK_H
#define KUROK_H

#include "stm32f30x.h"
#include "main.h"


void systick_kurok(void);
void AK_47(void);
void clearKurokFlag(uint8_t num);
uint8_t getKurokFlag (uint8_t num);



#endif