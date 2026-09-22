#include "main.h"
#include <stdint.h>
#include "stm32l4xx.h"
#include "pins.h"

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    RCC->AHB2ENR |= (1UL << 1U);
    GPIOB->MODER &= ~(3UL << BUTTON_PIN);
    GPIOB->PUPDR &= ~(3UL << BUTTON_PIN);
    GPIOB->PUPDR |= (1UL << BUTTON_PIN);

    uint8_t regIndex = BUTTON_PIN / 4U;
    uint8_t portSource = 1U;
    SYSCFG->EXTICR[regIndex] &= ~(0x7UL << ((BUTTON_PIN % 4U) * 4U));
    SYSCFG->EXTICR[regIndex] |= ((uint32_t)portSource << ((BUTTON_PIN % 4U) * 4U));

    EXTI->IMR1 |= (0x1UL << BUTTON_PIN);
    EXTI->RTSR1 &= ~(0x1UL << BUTTON_PIN);
    EXTI->FTSR1  |= (0x1UL << BUTTON_PIN);

    uint8_t interruptPos = 23U;
    NVIC->IPR[interruptPos] = ((uint8_t)(0x3UL << 4U));
    NVIC->ISER[interruptPos >> 5U] |= (0x1UL << (interruptPos & 0x1FU));

    while (1) {
        __ASM("nop");
    }
}