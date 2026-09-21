#include "helpers.h"
#include <stdint.h>
#include "stm32l432xx.h"
#include "pins.h"

void enableLEDGPIOClkA(void) {
    RCC->AHB2ENR |= (1UL << 0U);
}

void configGPIOPA1(void) {
    GPIOA->MODER &= (3UL << 2U);
    GPIOA->MODER |= (1UL << 2U);
}

void toggleLEDGPIOPA1(void) {
    GPIOA->ODR ^= (1UL << LED_PIN);
}
