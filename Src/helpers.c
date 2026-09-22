#include "helpers.h"
#include <stdint.h>
#include "stm32l432xx.h"
#include "pins.h"


void configGPIOPA1(void) {
    GPIOA->MODER &= ~(3UL << (LED_PIN * 2U));
    GPIOA->MODER |= (1UL << (LED_PIN * 2U));
}

void toggleLEDGPIOPA1(void) {
    GPIOA->ODR ^= (1UL << LED_PIN);
}
