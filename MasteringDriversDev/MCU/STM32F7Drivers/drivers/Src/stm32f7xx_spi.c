/*
 * stm32f7xx_spi.c
 *
 *  Created on: 20 Aug 2020
 *      Author: ROG
 */
#include "stm32f7_spi.h"

static void spi_txe_interrupt_handle(SPI_Handle_t *pSPIHandle);
static void spi_rxe_interrupt_handle(SPI_Handle_t *pSPIHandle);
static void spi_error_interrupt_handle(SPI_Handle_t *pSPIHandle);

//Clock configuration
void SPI_PeriphClckControl(SPI_RegDef_t *SPIx , uint8_t Activation)
{
	if(Activation == ENABLE)
	{

		if(SPIx == SPI1)
		{
			SPI1_PERI_CLCK_EN();

		}else if (SPIx == SPI2)
		{
			SPI2_PERI_CLCK_EN();

		}else if (SPIx == SPI3)
		{
			SPI3_PERI_CLCK_EN();

		}else if (SPIx == SPI4)
		{
			SPI4_PERI_CLCK_EN();

		}else if (SPIx == SPI5)
		{
			SPI5_PERI_CLCK_EN();

		}else if (SPIx == SPI6)
		{
			SPI6_PERI_CLCK_EN();

		}
	}
	else
	{
		if(SPIx == SPI1)
		{
			SPI1_PERI_CLCK_DIS();

		}else if (SPIx == SPI2)
		{
			SPI2_PERI_CLCK_DIS();

		}else if (SPIx == SPI3)
		{
			SPI3_PERI_CLCK_DIS();

		}else if (SPIx == SPI4)
		{
			SPI4_PERI_CLCK_DIS();

		}else if (SPIx == SPI5)
		{
			SPI5_PERI_CLCK_DIS();

		}else if (SPIx == SPI6)
		{
			SPI6_PERI_CLCK_DIS();

		}

	}
}
//Initialisation
void SPI_Init(SPI_Handle_t *pSpiHandle)
{

	//First lets config SPI_CR1 register
	volatile uint32_t tempreg = 0 ;
	//Cr2 register temp
	volatile uint32_t tempreg_cr2 = 0x00000700;

	SPI_PeriphClckControl(pSpiHandle->Spix , ENABLE);
	//configure the device mode
	tempreg |= pSpiHandle->SPIConfig.SPI_Device_Mode << SPI_CR1_MASTR_MODE_BIT_POS;

	//Configure Bus Config
	if(pSpiHandle->SPIConfig.SPI_Bus_Config == SPI_BUS_CONFIG_FULLDUP)
	{
		//bidi mode should be cleared
		tempreg &= ~( 1 << SPI_CR1_BIDIMODE_BIT_POS);

	}else if(pSpiHandle->SPIConfig.SPI_Bus_Config == SPI_BUS_CONFIG_HALFDUP)
	{
		//bidi mode should be set
		tempreg |= ( 1 << SPI_CR1_BIDIMODE_BIT_POS);

	}else if(pSpiHandle->SPIConfig.SPI_Bus_Config == SPI_BUS_CONFIG_SIMPLEX_RX)
	{
		//bidi mode should be cleared
		tempreg &= ~( 1 << SPI_CR1_BIDIMODE_BIT_POS);
		//RXONLY bit must be set
		tempreg |= ( 1 << SPI_CR1_RXONLY_BIT_POS);

	}

	// 3.Configure SPI SCK speed (baud rate)
	tempreg |= ( pSpiHandle->SPIConfig.SPI_ClckSpeed << SPI_CR1_BR0);

	// 4. Configure the DS
	tempreg |= ( pSpiHandle->SPIConfig.SPI_DFF << SPI_CR2_DS0);
	// 5. Configure CPOL
	tempreg |= ( pSpiHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL_BIT_POS);

	// 6. Configure CPHA
	tempreg |= ( pSpiHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA_BIT_POS);
	//7. Software Slave management
	if(pSpiHandle->SPIConfig.SPI_SSM == SPI_SSM_EN)
	{
		//Set SSM bit and SSI bit
		tempreg |= (pSpiHandle->SPIConfig.SPI_SSM <<SPI_CR1_SSM_BIT_POS);
		tempreg |= (1 <<SPI_CR1_SSI);

	}else
	{
		//Clear SSI and SSM bits
		tempreg &= ~(1 <<SPI_CR1_SSM_BIT_POS);
		tempreg &= ~(1 <<SPI_CR1_SSI);
		if(pSpiHandle->SPIConfig.SPI_Device_Mode == SPI_DEVICE_MODE_MASTER )
		{
			tempreg_cr2 |= 1<<SPI_CR2_SSOE;
		}
	}
	pSpiHandle->Spix->CR1 = tempreg ;
	//For 8bit data need to configure CR2 Register
	pSpiHandle->Spix->CR2 = tempreg_cr2;

}
void SPI_Deinit(SPI_RegDef_t *pSPIx)
{


	if(pSPIx == SPI1)
	{
		SPI1_RESET();

	}else if (pSPIx == SPI2)
	{
		SPI2_RESET();

	}else if (pSPIx == SPI3)
	{
		SPI3_RESET();

	}else if (pSPIx == SPI4)
	{
		SPI4_RESET();

	}else if (pSPIx == SPI5)
	{
		SPI5_RESET();

	}else if (pSPIx == SPI6)
	{
		SPI6_RESET();

	}
}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

/*
 *  SPI data Send and Receive
 */
void SPITransmit(SPI_RegDef_t *pSPIx, uint8_t *pTxBuff, uint32_t len)
{
	if(len> 0)
	{
		while(len>0)
		{
			//1. wait untill TXE is set
			while(SPI_GetFlagStatus(pSPIx, SPI_TXNE_FLAG) == FLAG_RESET){}
			//2. Check the data size in CR1
			//if(pSPIx->CR2 & ((SPI_16BIT_DATA<<SPI_CR2_DS0)))
			/*	if(SPI2Handle.SPIConfig.SPI_DFF == SPI_DFF_16BITS)
				{

					pSPIx->DR = *((uint16_t*)pTxBuff);
					len--;
					len--;
					(uint16_t*)pTxBuff++;

				}//else if(pSPIx->CR2 & ((SPI_8BIT_DATA<<SPI_CR2_DS0)))
				else if(SPI2Handle.SPIConfig.SPI_DFF == SPI_DFF_8BITS)
				{*/
			*(volatile uint8_t*)(&pSPIx->DR)= *pTxBuff;
			len--;
			pTxBuff++;

			//				}




		}
	}
}
//
void SPIReceive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuff, uint32_t len)
{
	if(len> 0)
	{
		while(len>0)
		{
			//1. wait until RXNE is set
			while(SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG) == FLAG_RESET){}
			//2. Check the data size in CR1
			//if(pSPIx->CR2 & ((SPI_16BIT_DATA<<SPI_CR2_DS0)))
			/*	if(SPI2Handle.SPIConfig.SPI_DFF == SPI_DFF_16BITS)
					{

						pSPIx->DR = *((uint16_t*)pTxBuff);
						len--;
						len--;
						(uint16_t*)pTxBuff++;

					}//else if(pSPIx->CR2 & ((SPI_8BIT_DATA<<SPI_CR2_DS0)))
					else if(SPI2Handle.SPIConfig.SPI_DFF == SPI_DFF_8BITS)
					{*/
			*pRxBuff =   *(volatile uint8_t*)(&pSPIx->DR);
			len--;
			pRxBuff++;

			//				}




		}
	}


}

/*
 * SPI IRQ configuration and IRQ handling
 */
void SPI_IRQITConfig(uint8_t IRQNum, uint8_t Activation)
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
void spi_txe_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
	*(volatile uint8_t*)(&pSPIHandle->Spix->DR)= *pSPIHandle->pTxBuffer;
	pSPIHandle->TxLen--;
	pSPIHandle->pTxBuffer++;
	if(!pSPIHandle->TxLen)
	{
		//If Tx length is zero then close the SPI transmission and inform application that spi tx is over
		//this prevents interrupt from setting up TXE flag
		SPI_CloseTransmisson(pSPIHandle);
		SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_TX_COMPLT);

	}

}
void spi_rxe_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
	*pSPIHandle->pTxBuffer = *(volatile uint8_t*)(&pSPIHandle->Spix->DR);
		pSPIHandle->RxLen--;
		pSPIHandle->pRxBuffer++;
		if(!pSPIHandle->RxLen)
		{
			//If Tx length is zero then close the SPI transmission and inform application that spi tx is over
			//this prevents interrupt from setting up TXE flag
			SPI_CloseReception(pSPIHandle);
			SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_RX_COMPLT);

		}


}
void spi_error_interrupt_handle(SPI_Handle_t *pSPIHandle)
{
	uint8_t temp = 0;
	//1. Clear Ovr flag
if(pSPIHandle->TxState != SPI_BUSY_IN_TX)
{
	temp = pSPIHandle->Spix->DR;
	temp = pSPIHandle->Spix->SR;

}
(void)temp;
	//2. Inform the Application
SPI_ApplicationEventCallback(pSPIHandle,SPI_EVENT_OVR_ERROR);


}

void SPI_IRQHandler(SPI_Handle_t *pSpiHandle)
{
	uint8_t temp_sr,temp_cr2;
	// First check for TXE
	temp_sr = pSpiHandle->Spix->SR & (1<<SPI_SR_TXNE);
	temp_cr2 = pSpiHandle->Spix->CR2 & (1<<SPI_CR2_TXEIE);
	if(temp_sr & temp_cr2)
	{
		//Handle TXE
		spi_txe_interrupt_handle(pSpiHandle);
	}
	// then check for RXE
	temp_sr = pSpiHandle->Spix->SR & (1<<SPI_SR_RXNE);
	temp_cr2 = pSpiHandle->Spix->CR2 & (1<<SPI_CR2_RXNEIE);
	if(temp_sr & temp_cr2)
	{
		//Handle TXE
		spi_rxe_interrupt_handle(pSpiHandle);
	}
	// First check for OVR
	temp_sr = pSpiHandle->Spix->SR & (1<<SPI_SR_OVR);
	temp_cr2 = pSpiHandle->Spix->CR2 & (1<<SPI_CR2_ERRIE);
	if(temp_sr & temp_cr2)
	{
		//Handle TXE
		spi_error_interrupt_handle(pSpiHandle);
	}




}
void SPI_IRQPriorityConfig(uint8_t IRQNum, uint32_t IRQPriority)
{
	//1. first find out pr register
	uint8_t iprx = IRQNum / 4;
	uint8_t iprx_section = IRQNum % 4;
	uint8_t shift_amount = ((8 * iprx_section) + (8 - __NVIC_PRIO_BITS));

	*( NVIC_PR_BASE_ADDRESS + iprx) |= (IRQPriority << shift_amount);

}
void SPIPeripheralControl(SPI_RegDef_t *SPIx,uint8_t Activation)
{
	if(Activation)
	{
		SPIx->CR1 |= (1 << SPI_CR1_SPE_BIT_POS);
	}else
	{
		SPIx->CR1 &= ~(1 << SPI_CR1_SPE_BIT_POS);
	}
}
/*
 *  SPI data Send and Receive with Interrupt
 */
uint8_t SPITransmitIT(SPI_Handle_t *pSPIHandle, uint8_t *pTxBuff, uint32_t len)
{
	uint8_t temp_state = pSPIHandle->TxState;
	if(temp_state != SPI_BUSY_IN_TX)
	{

		//1- Save the Tx buffer and length information in some global variable
		pSPIHandle->pTxBuffer  = pTxBuff;
		pSPIHandle->TxLen      = len;

		//2- Set SPI peripheral state as busy so no other client can take over SPI until tx complete
		pSPIHandle->TxState = SPI_BUSY_IN_TX;

		//3- Enable TXEIE bit to set the interrupt whenever TXE flag is set in SR register of SPI
		pSPIHandle->Spix->CR2 |= 1<< SPI_CR2_TXEIE;

		//4- Data Transmission handled by ISR code

		//pSPIHandle->TxState = SPI_READY;
	}
	return temp_state;
}
uint8_t SPIReceiveIT(SPI_Handle_t *pSPIHandle, uint8_t *pRxBuff, uint32_t len)
{
	uint8_t temp_state = pSPIHandle->RxState;
	if(temp_state != SPI_BUSY_IN_RX)
	{

		//1- Save the Tx buffer and length information in some global variable
		pSPIHandle->pRxBuffer  = pRxBuff;
		pSPIHandle->RxLen      = len;

		//2- Set SPI peripheral state as busy so no other client can take over SPI until tx complete
		pSPIHandle->RxState = SPI_BUSY_IN_RX;

		//3- Enable TXEIE bit to set the interrupt whenever TXE flag is set in SR register of SPI
		pSPIHandle->Spix->CR2 |= 1<< SPI_CR2_RXNEIE;

		//4- Data Transmission handled by ISR code

		//	pSPIHandle->RxState = SPI_READY;
	}
	return temp_state;

}
void SPI_CloseTransmisson(SPI_Handle_t *pSPIHandle)
{
	pSPIHandle->Spix->CR2 &= ~( 1 << SPI_CR2_TXEIE);
	pSPIHandle->pTxBuffer = NULL;
	pSPIHandle->TxLen = 0;
	pSPIHandle->TxState = SPI_READY;

}

void SPI_CloseReception(SPI_Handle_t *pSPIHandle)
{
	pSPIHandle->Spix->CR2 &= ~( 1 << SPI_CR2_RXNEIE);
	pSPIHandle->pRxBuffer = NULL;
	pSPIHandle->RxLen = 0;
	pSPIHandle->RxState = SPI_READY;

}



void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx)
{
	uint8_t temp;
	temp = pSPIx->DR;
	temp = pSPIx->SR;
	(void)temp;

}



__weak void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle,uint8_t AppEv)
{

	//This is a weak implementation . the user application may override this function.
}

