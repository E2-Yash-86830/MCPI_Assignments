/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/


#include "timer.h"
#include "led.h"

void Timer_Init(uint32_t ms) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	TIM7->PSC = (PR-1);
	uint32_t cnt = (TCLK / 1000) * ms / PR;
	TIM7->ARR = (cnt-1);
	TIM7->CNT = 0;
	TIM7->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(55);
	TIM7->CR1 |= TIM_CR1_CEN;
}
volatile int count = 0;
void TIM7_IRQHandler(void) {
	if(TIM7->SR & TIM_SR_UIF) {
		TIM7->SR &= ~TIM_SR_UIF;
		LedToggle(LED_BLUE_PIN);
		count++;
	}
}
