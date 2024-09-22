#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "switch_intr.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define LED_COUNT 4
uint8_t current_led = 0;

int main(void) {
    SystemInit();
    SwitchInit();
    LedInit(LED_BLUE_PIN);
    LedInit(LED_RED_PIN);
    LedInit(LED_ORANGE_PIN);
    LedInit(LED_GREEN_PIN);

    while (1) {

        if (SwitchExtiFlag) {

           SwitchExtiFlag = 0;

            LedOff(LED_BLUE_PIN);
            LedOff(LED_RED_PIN);
            LedOff(LED_ORANGE_PIN);
            LedOff(LED_GREEN_PIN);

            switch (current_led) {
                case 0:
                    LedBlink(LED_BLUE_PIN, 1000);
                    break;
                case 1:
                    LedBlink(LED_RED_PIN, 1000);
                    break;
                case 2:
                    LedBlink(LED_ORANGE_PIN, 1000);
                    break;
                case 3:
                    LedBlink(LED_GREEN_PIN, 1000);
                   break;

            }

            current_led++;
            if (current_led >= LED_COUNT) {
                current_led = 0;
            }
        }
    }
    return 0;
}
