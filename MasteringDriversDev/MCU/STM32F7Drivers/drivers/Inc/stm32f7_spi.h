/*
 * stm32f7_spi.h
 *
 *  Created on: 20 Aug 2020
 *      Author: ROG
 */

#ifndef STM32F7_SPI_H_
#define STM32F7_SPI_H_

#include "Stm32F767.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Configuration structure for SPIx peripheral
 */
typedef struct
{
	uint8_t SPI_Device_Mode;
	uint8_t SPI_Bus_Config;
	uint8_t SPI_ClckSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPI_CONFIG_t;

/*
 * SPIx peripheral Handle structure
 */
typedef struct
{
	SPI_RegDef_t *Spix;  // this holds the base address of the SPI
	SPI_CONFIG_t SPIConfig;
	uint8_t *pTxBuffer; //To Store Tx Buff Address
	uint8_t *pRxBuffer; //To Store Rx Buffer address
	uint32_t TxLen;//To Store Tx length
	uint32_t RxLen;//To Store Rx length
	uint8_t TxState; //To Store Tx state
	uint8_t RxState; //To Store Rx state
}SPI_Handle_t;

/*
 * @SPI_DeviceMode
 *
 */
#define SPI_DEVICE_MODE_MASTER    1
#define SPI_DEVICE_MODE_SLAVE     0

/*
 * @SPI_Bus_Config
 *
 */

#define SPI_BUS_CONFIG_FULLDUP          1
#define SPI_BUS_CONFIG_HALFDUP          2
//#define SPI_BUS_CONFIG_SIMPLEX_TX       3
#define SPI_BUS_CONFIG_SIMPLEX_RX       3
/*
 * @SPI_ClckSpeed
 *
 */

#define SPI_SCLK_SPEED_DIV2              0
#define SPI_SCLK_SPEED_DIV4              1
#define SPI_SCLK_SPEED_DIV8              2
#define SPI_SCLK_SPEED_DIV16             3
#define SPI_SCLK_SPEED_DIV32             4
#define SPI_SCLK_SPEED_DIV64             5
#define SPI_SCLK_SPEED_DIV128            6
#define SPI_SCLK_SPEED_DIV256            7
/*
 * @SPI_DFF
 *
 */

#define SPI_DFF_8BITS                     0
#define SPI_DFF_16BITS                    1
/*
 * @SPI_CPOL
 *
 */
#define SPI_CPOL_HIGH                     1
#define SPI_CPOL_LOW                      0

/*
 * @SPI_CPHA
 *
 */
#define SPI_CPHA_HIGH                     1
#define SPI_CPHA_LOW                      0

/*
 * @SPI_SSM
 *
 */
#define SPI_SSM_EN                         1
#define SPI_SSM_DIS                        0     //default

/*
 * @SPI Possible states
 *
 */
#define SPI_READY                           0
#define SPI_BUSY_IN_RX                      1
#define SPI_BUSY_IN_TX                      2
/*
 * SPI Application Events
 */
#define SPI_EVENT_TX_COMPLT                1
#define SPI_EVENT_RX_COMPLT                2
#define SPI_EVENT_OVR_ERROR                3
#define SPI_EVENT_CRC_ERROR                4


/*
 * Other SPI Macros
 */

#define SPI_TXNE_FLAG            (1 << SPI_SR_TXNE)
#define SPI_RXNE_FLAG            (1 << SPI_SR_RXNE)
#define SPI_BSY_FLAG             (1 << SPI_SR_BSY)

#define SPI_8BIT_DATA            (uint32_t)7
#define SPI_16BIT_DATA           (uint32_t)15



//SPI CR1 Register Macros
#define SPI_CR1_CPHA_BIT_POS              0
#define SPI_CR1_CPOL_BIT_POS              1
#define SPI_CR1_MASTR_MODE_BIT_POS            2
#define SPI_CR1_BR0                       3
#define SPI_CR1_BR1                       4
#define SPI_CR1_BR2                       5
#define SPI_CR1_SPE_BIT_POS               6
#define SPI_CR1_LSBFIRST                  7
#define SPI_CR1_SSI                       8
#define SPI_CR1_SSM_BIT_POS               9
#define SPI_CR1_RXONLY_BIT_POS                10
#define SPI_CR1_BIDIOE_BIT_POS                14
#define SPI_CR1_BIDIMODE_BIT_POS              15




//SPI CR2 BIT MACROS
#define SPI_CR2_SSOE                      2
#define SPI_CR2_FRF                       4
#define SPI_CR2_ERRIE                     5
#define SPI_CR2_RXNEIE                    6
#define SPI_CR2_TXEIE                     7
#define SPI_CR2_DS0                       8
#define SPI_CR2_DS1                       9
#define SPI_CR2_DS2                       10
#define SPI_CR2_DS3                       11
#define SPI_CR2_FRXTH                     12

//SPI SR Register BIT MACRO
#define SPI_SR_RXNE                       0
#define SPI_SR_TXNE                       1
#define SPI_SR_MODF                       5
#define SPI_SR_OVR                        6
#define SPI_SR_BSY                        7
#define SPI_SR_FRE                        8
#define SPI_SR_FRLVL0                     9
#define SPI_SR_FRLVL1                     10
#define SPI_SR_FTLVL0                     11
#define SPI_SR_FTLVL1                     12

/* API functions for SPI driver
 * Required for SPI configuration
 * More information in source file
 * */
//Enable SPI peripheral
void SPIPeripheralControl(SPI_RegDef_t *SPIx,uint8_t Activation);
//Clock configuration
void SPI_PeriphClckControl(SPI_RegDef_t *SPIx , uint8_t Activation);
//Initialisation
void SPI_Init(SPI_Handle_t *pSpiHandle);
void SPI_Deinit(SPI_RegDef_t *pSPIx);

/*
 *  SPI data Send and Receive without Interrupt
 */
void SPITransmit(SPI_RegDef_t *pSPIx, uint8_t *pTxBuff, uint32_t len);
void SPIReceive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuff, uint32_t len);

/*
 *  SPI data Send and Receive with Interrupt
 */
uint8_t SPITransmitIT(SPI_Handle_t *pSPIHandle, uint8_t *pTxBuff, uint32_t len);
uint8_t SPIReceiveIT(SPI_Handle_t *pSPIHandle, uint8_t *pRxBuff, uint32_t len);


/*
 * SPI IRQ configuration and IRQ handling
 */
void SPI_IRQITConfig(uint8_t IRQNum, uint8_t Activation);
void SPI_IRQHandler(SPI_Handle_t *pSpiHandle);
void SPI_IRQPriorityConfig(uint8_t IRQNum, uint32_t IRQPriority);
/*
 * Other functions
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);
void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx);
void SPI_CloseTransmisson(SPI_Handle_t *pSPIHandle);
void SPI_CloseReception(SPI_Handle_t *pSPIHandle);


/*
 * Application callback
 */
void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle,uint8_t AppEv);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* STM32F7_SPI_H_ */
