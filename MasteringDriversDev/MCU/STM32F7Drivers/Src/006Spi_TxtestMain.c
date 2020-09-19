/*
 * 006Spi_TxtestMain.c
 *
 *  Created on: 22 Aug 2020
 *      Author: ROG
 */

#include "Stm32f767.h"
#include "stm32F7xx_gpio.h"
#include "stm32f7_spi.h"
#include "stm32f7_i2c.h"
#include <string.h>

/* Alternate function mode : 5
 * PB15 ---> SPI2-MOSI
 * PB14 ---> SPI2-MISO
 * PB13 ---> SPI2-SCK
 * PB12 ---> SPI2-NSS
 */
void SPI2_GPIOInits()
{
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx  = GPIOB;
	SPIPins.GPIO_PinConfig.PinMode = GPIO_ALT ;
	SPIPins.GPIO_PinConfig.PinAltFunMode = 5;

	SPIPins.GPIO_PinConfig.PinSpeed = GPIO_SPEED_VERY_HIGH;
	SPIPins.GPIO_PinConfig.PinOPType = GPIO_PUSH_PULL;
	SPIPins.GPIO_PinConfig.PinPupDr = GPIO_PUPDR_PULLUP;

	//Sclk
	SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN13; //SPI2
	//SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN3; // SPI3
	GPIO_Init(&SPIPins);
	//MosI
	SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN15; //SPI2
	//SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN5; // SPI3
    GPIO_Init(&SPIPins);
   /* //Miso
    SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN14;
    GPIO_Init(&SPIPins);
    //NSS
    SPIPins.GPIO_PinConfig.PinNum = GPIO_PIN12;
    GPIO_Init(&SPIPins);*/




}
void SPI2_Inits()
{
	SPI_Handle_t SPI2Handle;
	SPI2Handle.Spix = SPI2;
	SPI2Handle.SPIConfig.SPI_Bus_Config = SPI_BUS_CONFIG_FULLDUP;
	SPI2Handle.SPIConfig.SPI_Device_Mode = SPI_DEVICE_MODE_MASTER ;
	SPI2Handle.SPIConfig.SPI_ClckSpeed = SPI_SCLK_SPEED_DIV2 ;
	SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_EN;
	SPI_Init(&SPI2Handle);
}

int main()
{
	 char user_data[] = "Hello World";
	//This function is used to initialise GPIO pins for SPI2
	SPI2_GPIOInits();
	//This function is used to initialise SPI peripheral parameters
	SPI2_Inits();
	//enable SPI2 peripheral
	SPIPeripheralControl(SPI2, ENABLE);
	SPITransmit(SPI2,(uint8_t*)user_data,strlen(user_data));
	//disable SPI2 peripheral
	SPIPeripheralControl(SPI2, DISABLE);
	while(1)
	{

	}
}
