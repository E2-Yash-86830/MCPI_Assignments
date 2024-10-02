/*
Author: Hardik-87298
Date: Sep 30, 2024
*/

#include "stm32f4xx.h"

#ifndef TIMER_H_
#define TIMER_H_

#define TCLK	16000000UL
#define PR		16000

void Timer_Init(void);
void Timer_Delay(uint32_t ms);

#endif /* TIMER_H_ */
