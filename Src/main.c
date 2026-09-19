#include "main.h"
int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}