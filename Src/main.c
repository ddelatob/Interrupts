#include "main.h"
int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    uint8_t regIndex = BUTTON_PIN / 4U;
    uint8_t portSource = 1U;
    SYSCFG->EXTICR[regIndex] &= ~(0x7UL << ((BUTTON_PIN % 4U) * 4U));
    SYSCFG->EXTICR[regIndex] |= ((uint32_t)portSource << ((BUTTON_PIN % 4U) * 4U));

    EXTI->IMR1 |= (0x1UL << BUTTON_PIN);
    EXTI->RTSR1 &= ~(0x1UL << BUTTON_PIN);
    EXTI->RTSR1 |= (0x1UL << BUTTON_PIN);
}