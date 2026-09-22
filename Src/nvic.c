#include "nvic.h"
#include "stm32l432xx.h"
#include "pins.h"
#include "helpers.h"

void EXTI2_IRQHandler(void) {
    if (EXTI->PR1 & (0x1UL << BUTTON_PIN)){
        EXTI->PR1 = (0x1UL << BUTTON_PIN);
        toggleLEDGPIOPA1();
    }
}