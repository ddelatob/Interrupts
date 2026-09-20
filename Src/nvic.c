#include "nvic.h"
#include "stm32l432xx.h"
#include "pins.h"
void EXTI9_5_IRQHandler(void) {
    if (EXTI->PR1 & (0x1UL << BUTTON_PIN)){}
}