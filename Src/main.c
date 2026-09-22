#include "main.h"
#include <stdint.h>
#include "stm32l4xx.h"
#include "pins.h"
#include "helpers.h"

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    RCC->AHB2ENR |= (1UL << 0U);

    GPIOA->MODER &= ~(3UL << (BUTTON_PIN * 2U));
    GPIOA->PUPDR &= ~(3UL << (BUTTON_PIN * 2U));
    GPIOA->PUPDR |= (1UL << (BUTTON_PIN * 2U));

    configGPIOPA1();

    uint8_t regIndex = BUTTON_PIN / 4U;
    uint8_t portSource = 0U;
    SYSCFG->EXTICR[regIndex] &= ~(0x7UL << ((BUTTON_PIN % 4U) * 4U));
    SYSCFG->EXTICR[regIndex] |= ((uint32_t)portSource << ((BUTTON_PIN % 4U) * 4U));

    EXTI->IMR1 |= (0x1UL << BUTTON_PIN);
    EXTI->RTSR1 &= ~(0x1UL << BUTTON_PIN);
    EXTI->FTSR1  |= (0x1UL << BUTTON_PIN);

    uint8_t interruptPos = EXTI2_IRQn;
    NVIC->IPR[interruptPos] = ((uint8_t)(0x3UL << 4U));
    NVIC->ISER[interruptPos >> 5U] |= (0x1UL << (interruptPos & 0x1FU));


    while (1) {
        __ASM("nop");
    }
}