

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	SystemInit();
	LedInit(LED_GREEN_PIN);
	LedInit(LED_ORANGE_PIN);
	LedInit(LED_RED_PIN);
	LedInit(LED_BLUE_PIN);
	while(1) {
		LedBlink(LED_GREEN_PIN, 100);
		LedBlink(LED_ORANGE_PIN, 0);
		LedBlink(LED_RED_PIN, 100);
		LedBlink(LED_BLUE_PIN, 0);
	}
	return 0;
}








