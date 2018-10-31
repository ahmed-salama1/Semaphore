/*
 * inp.c
 *
 *  Created on: Oct 30, 2018
 *      Author: ahmed
 */

#include "stm32f4xx.h"

/*init Input pa9*/
void init_gpio(void){

	/*Enable CK*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*input*/
	GPIOA->MODER &= ~GPIO_MODER_MODER9;

	/*PULLDOWN*/
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR9;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;

	/*input*/
	GPIOA->MODER &= ~GPIO_MODER_MODER8;

	/*PULLDOWN*/
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR8;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR8_0;

}
