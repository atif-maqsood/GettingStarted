
#include "stm32F7xx_gpio.h"

//Clock configuration
void PeriphClckControl(GPIO_REG_DEF_t *pGPIOx , uint8_t Activation)
{

	if(Activation == ENABLE)
	{

		if(pGPIOx == GPIOA)
		{
			GPIOA_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOF)
		{
			GPIOF_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOG)
		{
			GPIOG_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOI)
		{
			GPIOI_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOJ)
		{
			GPIOJ_PERIPH_CLCK_EN();

		}else if (pGPIOx == GPIOK)
		{
			GPIOK_PERIPH_CLCK_EN();

		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOF)
		{
			GPIOF_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOG)
		{
			GPIOG_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOI)
		{
			GPIOI_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOJ)
		{
			GPIOJ_PERIPH_CLCK_DIS();

		}else if (pGPIOx == GPIOK)
		{
			GPIOK_PERIPH_CLCK_DIS();

		}


	}
}
//Initialisation
void GPIO_Init(GPIO_Handle_t *pGpioHandle)
{
	uint32_t temp = 0 ;
	//Enable Peripheral Clock
	PeriphClckControl(pGpioHandle->pGPIOx , ENABLE);
	//Configure mode
	if(pGpioHandle->GPIO_PinConfig.PinMode<=GPIO_ANA)
	{
		temp = pGpioHandle->GPIO_PinConfig.PinMode<< 2*pGpioHandle->GPIO_PinConfig.PinNum;
		pGpioHandle->pGPIOx->MODER &= ~(TWO_BITS<<2*pGpioHandle->GPIO_PinConfig.PinNum);
		pGpioHandle->pGPIOx->MODER |= temp;


	}
	else
	{
		if(pGpioHandle->GPIO_PinConfig.PinMode == GPIO_IT_FALLING)
		{
			//Configure FTSR
			EXTI->FTSR |= (1<<pGpioHandle->GPIO_PinConfig.PinNum);
			//Clear corresponding RTSR bit
			EXTI->RTSR &= ~(1<<pGpioHandle->GPIO_PinConfig.PinNum);


		}else if(pGpioHandle->GPIO_PinConfig.PinMode == GPIO_IT_RISING)
		{
			//Configure RTSR
			EXTI->RTSR |= (1<<pGpioHandle->GPIO_PinConfig.PinNum);
			//Clear corresponding RTSR bit
			EXTI->FTSR &= ~(1<<pGpioHandle->GPIO_PinConfig.PinNum);


		}else if(pGpioHandle->GPIO_PinConfig.PinMode == GPIO_IT_RISE_FALL)
		{
			//Configure both
			EXTI->FTSR |= (1<<pGpioHandle->GPIO_PinConfig.PinNum);
			EXTI->RTSR |= (1<<pGpioHandle->GPIO_PinConfig.PinNum);
		}
		// 2. Configure GPIO port selection in SYSCFG_EXTICR
		uint8_t temp1 = pGpioHandle->GPIO_PinConfig.PinNum / 4;
		uint8_t temp2 = pGpioHandle->GPIO_PinConfig.PinNum % 4;
		uint8_t portcode = GPIO_BASE_ADDR_TO_CODE(pGpioHandle->pGPIOx);
		SYSCFG_PERI_CLCK_EN();
		SYSCFG->EXTICR[temp1] = portcode << (temp2 * 4);


		// 3. Enable EXTI interrupt delivery using IMR
		EXTI->IMR |= (1<<pGpioHandle->GPIO_PinConfig.PinNum);
		// To do later for IT
	}
	temp = 0;
	//speed
	temp = pGpioHandle->GPIO_PinConfig.PinSpeed << 2*pGpioHandle->GPIO_PinConfig.PinNum;
	pGpioHandle->pGPIOx->OSPEEDR &= ~(TWO_BITS<<2*pGpioHandle->GPIO_PinConfig.PinNum);
	pGpioHandle->pGPIOx->OSPEEDR |= temp;
	//pupdr
	temp = 0;
	temp = pGpioHandle->GPIO_PinConfig.PinPupDr << 2*pGpioHandle->GPIO_PinConfig.PinNum;
	pGpioHandle->pGPIOx->PUPDR &= ~(TWO_BITS<<2*pGpioHandle->GPIO_PinConfig.PinNum);
	pGpioHandle->pGPIOx->PUPDR |= temp;

	//optype
	temp = 0;
	temp = pGpioHandle->GPIO_PinConfig.PinOPType << pGpioHandle->GPIO_PinConfig.PinNum;
	pGpioHandle->pGPIOx->OTYPER &= ~(1<<pGpioHandle->GPIO_PinConfig.PinNum);
	pGpioHandle->pGPIOx->OTYPER |= temp;
	temp = 0;
	//alt func
	if(pGpioHandle->GPIO_PinConfig.PinMode == GPIO_ALT)
	{
		if (pGpioHandle->GPIO_PinConfig.PinNum<8)
		{
			temp = pGpioHandle->GPIO_PinConfig.PinAltFunMode << 4*pGpioHandle->GPIO_PinConfig.PinNum;
			pGpioHandle->pGPIOx->AFRL &= ~(FOUR_BITS<<4*pGpioHandle->GPIO_PinConfig.PinNum);
			pGpioHandle->pGPIOx->AFRL |= temp;
		}else
		{
			temp = pGpioHandle->GPIO_PinConfig.PinAltFunMode << 4*(pGpioHandle->GPIO_PinConfig.PinNum%8);
			pGpioHandle->pGPIOx->AFRH &= ~(FOUR_BITS<< 4*(pGpioHandle->GPIO_PinConfig.PinNum%8));
			pGpioHandle->pGPIOx->AFRH |= temp;

		}


	}


}
void GPIO_Deinit(GPIO_REG_DEF_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_RESET();

	}else if (pGPIOx == GPIOB)
	{
		GPIOB_RESET();

	}else if (pGPIOx == GPIOC)
	{
		GPIOC_RESET();

	}else if (pGPIOx == GPIOD)
	{
		GPIOD_RESET();

	}else if (pGPIOx == GPIOE)
	{
		GPIOE_RESET();

	}else if (pGPIOx == GPIOF)
	{
		GPIOF_RESET();

	}else if (pGPIOx == GPIOG)
	{
		GPIOG_RESET();

	}else if (pGPIOx == GPIOH)
	{
		GPIOH_RESET();

	}else if (pGPIOx == GPIOI)
	{
		GPIOI_RESET();

	}else if (pGPIOx == GPIOJ)
	{
		GPIOJ_RESET();

	}else if (pGPIOx == GPIOK)
	{
		GPIOK_RESET();

	}

}

//Data Read Write
uint8_t ReadInputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t temp_pin_value= (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x0001);

	return temp_pin_value;

}
void ReadInputPort(GPIO_REG_DEF_t *pGPIOx)
{

}
void WriteToOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{

}
void WriteToOutputPort(GPIO_REG_DEF_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}

void ToggleOutputPin(GPIO_REG_DEF_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}

//IRQ of GPIO
void GPIO_IRQITConfig(uint8_t IRQNum, uint8_t Activation)
{
	if(Activation)
	{
if( IRQNum <= 31)
{
//Program ISER0
	*NVIC_ISER0 |= (1<<IRQNum);

}else if( IRQNum > 31 && IRQNum < 64 )
{
//Program ISER1
	*NVIC_ISER1 |= (1<<IRQNum%32);

}else if( IRQNum >= 64 && IRQNum < 96 )
{
//Program ISER2
	*NVIC_ISER2 |= (1<<IRQNum%64);

}
	}else
	{

		if( IRQNum <= 31)
		{
		//Program ICER0
			*NVIC_ICER0 |= (1<<IRQNum);

		}else if( IRQNum > 31 && IRQNum < 64 )
		{
		//Program ICER1
			*NVIC_ICER1 |= (1<<IRQNum%32);

		}else if( IRQNum >= 64 && IRQNum < 96 )
		{
		//Program ICER2
			*NVIC_ICER2 |= (1<<IRQNum%64);

		}


	}

}
void IRQPriorityConfig(uint8_t IRQNum, uint32_t IRQPriority)
{
  //1. first find out pr register
	uint8_t iprx = IRQNum / 4;
	uint8_t iprx_section = IRQNum % 4;
	uint8_t shift_amount = ((8 * iprx_section) + (8 - __NVIC_PRIO_BITS));

	*( NVIC_PR_BASE_ADDRESS + iprx) |= (IRQPriority << shift_amount);
}
void GPIO_IRQHandler(uint8_t PinNumber)
{
	// Clear exti pr register
	if(EXTI->PR & 1<<PinNumber)
	{
		EXTI->PR |= (1<<PinNumber);
	}

}
