/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include<stdio.h>

#define RCC_baseAddr		(0x40023800UL)
#define GPIOA_baseAddr		(0x40020000UL)
#define EXTI_baseAddr		(0x40013C00UL)
#define SYS_CFGR_baseAddr	(0x40013800UL)

volatile uint32_t *const pRCC_AHB1ENR=(uint32_t*)(RCC_baseAddr+0x30);
volatile uint32_t *const pRCC_APB2ENR=(uint32_t*)(RCC_baseAddr+0x44);
volatile uint32_t *const pGPIOA_mode=(uint32_t*)(GPIOA_baseAddr+0x00);
volatile uint32_t *const pGPIOA_PUPDR=(uint32_t*)(GPIOA_baseAddr+0x0C);
volatile uint32_t *const pEXTI_IMR=(uint32_t*)(EXTI_baseAddr+0x00);
volatile uint32_t *const pEXTI_FTSR=(uint32_t*)(EXTI_baseAddr+0x0C);
volatile uint32_t *const pEXTI_PR=(uint32_t*)(EXTI_baseAddr+0x14);
volatile uint32_t *const pNVIC_IRQ_en=(uint32_t*)(0xE000E100);
volatile uint32_t *const pSYSCFG_EXTICR1=(uint32_t*)(SYS_CFGR_baseAddr+0x08);


int main(void)
{
	printf("suru kar\n");
	//enable GPIOA clock
	*pRCC_AHB1ENR|=(1<<0);

	//GPIOA input mode set
	*pGPIOA_mode&=~(3<<0);

	//GPIOA PA0 pull up
	*pGPIOA_PUPDR&=~(3<<0);
	*pGPIOA_PUPDR|=(1<<0);

	//EXTI clock enable
	*pRCC_APB2ENR|=(1<<14);

	//SYSCFG PAO select for EXTIO
	*pSYSCFG_EXTICR1&=~(0xF<<0);

	//EXTI0 Unmask
	*pEXTI_IMR|=(1<<0);

	//EXTI0 falling edge select
	*pEXTI_FTSR|=(1<<0);

	//NVIC IRQ6 enable for EXTI0
	*pNVIC_IRQ_en|=(1<<6);


    /* Loop forever */
	for(;;);
}

void EXTI0_IRQHandler()
{
	printf("In the interrupt handler\n");
	*pEXTI_PR|=(1<<0);

}
