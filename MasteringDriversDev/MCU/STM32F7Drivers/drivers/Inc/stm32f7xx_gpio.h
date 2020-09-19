/*
 * stm32f7xx_gpio.h
 *
 *  Created on: 21 Jun 2020
 *      Author: ROG
 */

#ifndef DRIVERS_INC_STM32F7XX_GPIO_H_
#define DRIVERS_INC_STM32F7XX_GPIO_H_

#include "Stm32F767.h"
//this is configuration struct for GPIO pins

typedef struct
{
	uint8_t PinNum;
	uint8_t PinMode;
	uint8_t PinSpeed;
	uint8_t PinPupDr;
	uint8_t PinOPType;
	uint8_t PinAltFunMode;


}GPIO_PinConfig_t;

//This is handle structure for GPIO pin

typedef struct
{
	GPIO_REG_DEF_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

//GPIO_PINS
 enum GPIO_PIN_e
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
};
#define GPIO_PIN0       0
#define GPIO_PIN1       1
#define GPIO_PIN2       2
#define GPIO_PIN3       3
#define GPIO_PIN4       4
#define GPIO_PIN5       5
#define GPIO_PIN6       6
#define GPIO_PIN7       7
#define GPIO_PIN8       8
#define GPIO_PIN9       9
#define GPIO_PIN10      10
#define GPIO_PIN11      11
#define GPIO_PIN12      12
#define GPIO_PIN13      13
#define GPIO_PIN14      14
#define GPIO_PIN15      15

//GPIO pin possible modes
#define GPIO_INPUT          0
#define GPIO_OUTPUT         1
#define GPIO_ALT            2
#define GPIO_ANA            3

#define TWO_BITS            3
#define FOUR_BITS           15
#define GPIO_IT_FALLING     4
#define GPIO_IT_RISING      5
#define GPIO_IT_RISE_FALL   6

//GPIO pin possible output types

#define GPIO_PUSH_PULL     0
#define GPIO_OPEN_DRAIN    1

//GPIO pin possible output speed

#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MED     1
#define GPIO_SPEED_HIGH    2
#define GPIO_SPEED_VERY_HIGH     3

//GPIO pin possible output pupdr types
#define GPIO_PUPDR_NOPULL    0
#define GPIO_PUPDR_PULLUP    1
#define GPIO_PUPDR_PULLDOWN  2

/* API functions for GPIO driver
 * Required for GPIO configuration
 * More information in source file
 * */
//Clock configuration
void PeriphClckControl(GPIO_REG_DEF_t *pGPIOx , uint8_t Activation);
//Initialisation
void GPIO_Init(GPIO_Handle_t *pGpioHandle);
void GPIO_Deinit(GPIO_REG_DEF_t *pGPIOx);

//Data Read Write
uint8_t ReadInputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber);
void ReadInputPort(GPIO_REG_DEF_t *pGPIOx);
void WriteToOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void WriteToOutputPort(GPIO_REG_DEF_t *pGPIOx, uint16_t value);

void ToggleOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber);

//IRQ of GPIO
void GPIO_IRQITConfig(uint8_t IRQNum, uint8_t Activation);
void GPIO_IRQHandler(uint8_t PinNumber);
void IRQPriorityConfig(uint8_t IRQNum, uint32_t IRQPriority);
#endif /* DRIVERS_INC_STM32F7XX_GPIO_H_ */
