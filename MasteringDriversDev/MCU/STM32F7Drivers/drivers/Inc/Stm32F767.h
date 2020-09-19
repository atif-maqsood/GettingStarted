/*
 * Stm32F767.h
 *
 *  Created on: Jun 20, 2020
 *      Author: ROG
 */

#ifndef STM32F767_H_
#define STM32F767_H_


#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include <sys/_stdint.h>
#include<stddef.h>
/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief STM32F7xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M7 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M7 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M7 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M7 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M7 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M7 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M7 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M7 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
  FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                              */
  SDMMC1_IRQn                 = 49,     /*!< SDMMC1 global Interrupt                                           */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
  ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
  OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
  OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
  DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
  RNG_IRQn                    = 80,     /*!< RNG global interrupt                                              */
  FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
  UART7_IRQn                  = 82,     /*!< UART7 global interrupt                                            */
  UART8_IRQn                  = 83,     /*!< UART8 global interrupt                                            */
  SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                             */
  SPI5_IRQn                   = 85,     /*!< SPI5 global Interrupt                                             */
  SPI6_IRQn                   = 86,     /*!< SPI6 global Interrupt                                             */
  SAI1_IRQn                   = 87,     /*!< SAI1 global Interrupt                                             */
  LTDC_IRQn                   = 88,     /*!< LTDC global Interrupt                                             */
  LTDC_ER_IRQn                = 89,     /*!< LTDC Error global Interrupt                                       */
  DMA2D_IRQn                  = 90,     /*!< DMA2D global Interrupt                                            */
  SAI2_IRQn                   = 91,     /*!< SAI2 global Interrupt                                             */
  QUADSPI_IRQn                = 92,     /*!< Quad SPI global interrupt                                         */
  LPTIM1_IRQn                 = 93,     /*!< LP TIM1 interrupt                                                 */
  CEC_IRQn                    = 94,     /*!< HDMI-CEC global Interrupt                                         */
  I2C4_EV_IRQn                = 95,     /*!< I2C4 Event Interrupt                                              */
  I2C4_ER_IRQn                = 96,     /*!< I2C4 Error Interrupt                                              */
  SPDIF_RX_IRQn               = 97,     /*!< SPDIF-RX global Interrupt                                         */
  DFSDM1_FLT0_IRQn	          = 99,     /*!< DFSDM1 Filter 0 global Interrupt                                  */
  DFSDM1_FLT1_IRQn	          = 100,    /*!< DFSDM1 Filter 1 global Interrupt                                  */
  DFSDM1_FLT2_IRQn	          = 101,    /*!< DFSDM1 Filter 2 global Interrupt                                  */
  DFSDM1_FLT3_IRQn	          = 102,    /*!< DFSDM1 Filter 3 global Interrupt                                  */
  SDMMC2_IRQn                 = 103,    /*!< SDMMC2 global Interrupt                                           */
  CAN3_TX_IRQn                = 104,    /*!< CAN3 TX Interrupt                                                 */
  CAN3_RX0_IRQn               = 105,    /*!< CAN3 RX0 Interrupt                                                */
  CAN3_RX1_IRQn               = 106,    /*!< CAN3 RX1 Interrupt                                                */
  CAN3_SCE_IRQn               = 107,    /*!< CAN3 SCE Interrupt                                                */
  JPEG_IRQn                   = 108,    /*!< JPEG global Interrupt                                             */
  MDIOS_IRQn                  = 109     /*!< MDIO Slave global Interrupt                                       */
} IRQn_Type;


/**
  * @}
  */
/**
 * @brief Configuration of the Cortex-M7 Processor and Core Peripherals
 */
#define __CM7_REV                 0x0100U  /*!< Cortex-M7 revision r1p0                       */
#define __MPU_PRESENT             1       /*!< CM7 provides an MPU                           */
#define __NVIC_PRIO_BITS          4       /*!< CM7 uses 4 Bits for the Priority Levels       */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1       /*!< FPU present                                   */
#define __ICACHE_PRESENT          1       /*!< CM7 instruction cache present                 */
#define __DCACHE_PRESENT          1       /*!< CM7 data cache present                        */
//#include "core_cm7.h"                     /*!< Cortex-M7 processor and core peripherals      */
#define NVIC_ISER0         ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1         ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2         ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3         ((volatile uint32_t*)0xE000E10c)
#define NVIC_ISER4         ((volatile uint32_t*)0xE000E110)
#define NVIC_ISER5         ((volatile uint32_t*)0xE000E114)
#define NVIC_ISER6         ((volatile uint32_t*)0xE000E118)
#define NVIC_ISER7         ((volatile uint32_t*)0xE000E11c)

#define NVIC_ICER0         ((volatile uint32_t*)0XE000E180)
#define NVIC_ICER1         ((volatile uint32_t*)0XE000E184)
#define NVIC_ICER2         ((volatile uint32_t*)0XE000E188)
#define NVIC_ICER3         ((volatile uint32_t*)0XE000E18c)
#define NVIC_ICER4         ((volatile uint32_t*)0XE000E190)
#define NVIC_ICER5         ((volatile uint32_t*)0XE000E194)
#define NVIC_ICER6         ((volatile uint32_t*)0XE000E198)
#define NVIC_ICER7         ((volatile uint32_t*)0XE000E19c)


// NVIC Priority registers base addresses
#define NVIC_PR_BASE_ADDRESS  ((volatile uint32_t*) 0xE000E400)

#define FLASH_BASE_ADDRESS  0x08000000UL
#define SRAM1_BASE_ADDRESS  0x20020000UL
#define SRAM2_BASE_ADDRESS  0x2007C000UL
#define ROM_BASE_ADDRESS    0x1FF00000UL

// AHB and APB bus peripheral Base Addresses
#define PERIPHERAL_BASE_ADDRESS 0x40000000UL
#define APB1_BASE_ADDRESS  PERIPHERAL_BASE_ADDRESS
#define APB2_BASE_ADDRESS  0x40010000UL
#define AHB1_BASE_ADDRESS  0x40020000UL
#define AHB2_BASE_ADDRESS  0x50000000UL
#define AHB3_BASE_ADDRESS  0x60000000UL

//Base Addresses of Peripheral on AHB1
#define GPIO_A_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x0000)
#define GPIO_B_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x0400)
#define GPIO_C_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x0800)
#define GPIO_D_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x0C00)
#define GPIO_E_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x1000)
#define GPIO_F_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x1400)
#define GPIO_G_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x1800)
#define GPIO_H_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x1C00)
#define GPIO_I_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x2000)
#define GPIO_J_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x2400)
#define GPIO_K_BASE_ADDRESS  (AHB1_BASE_ADDRESS + 0x2800)

#define CRC_BASE_ADDRESS     (AHB1_BASE_ADDRESS + 0x3000)
#define RCC_BASE_ADDRESS     (AHB1_BASE_ADDRESS + 0x3800)
#define DMA1_BASE_ADDRESS    (AHB1_BASE_ADDRESS + 0x6000)
#define DMA2_BASE_ADDRESS    (AHB1_BASE_ADDRESS + 0x6400)


// Base Address of Peripherals on APB1 BUS
#define TIM2_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x0000)
#define TIM3_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x0400)
#define TIM4_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x0800)
#define TIM5_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x0C00)
#define TIM6_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x1000)
#define TIM7_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x1400)
#define TIM12_BASE_ADDRESS   (APB1_BASE_ADDRESS + 0x1800)
#define TIM13_BASE_ADDRESS   (APB1_BASE_ADDRESS + 0x1C00)
#define TIM14_BASE_ADDRESS   (APB1_BASE_ADDRESS + 0x2000)
#define LPTIM1_BASE_ADDRESS  (APB1_BASE_ADDRESS + 0x2400)
#define RTC_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x2800)

#define WWDG_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x2C00)
#define IWDG_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x3000)
#define CAN3_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x3400)
#define SPI2_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x3800)
#define SPI3_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x3C00)
#define USART2_BASE_ADDRESS   (APB1_BASE_ADDRESS + 0x4400)
#define USART3_BASE_ADDRESS   (APB1_BASE_ADDRESS + 0x4800)
#define UART4_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x4C00)
#define UART5_BASE_ADDRESS    (APB1_BASE_ADDRESS + 0x5000)

#define I2C1_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x5400)
#define I2C2_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x5800)
#define I2C3_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x5C00)
#define I2C4_BASE_ADDRESS     (APB1_BASE_ADDRESS + 0x6000)


// Base Address of Peripherals on APB2 BUS

#define USART1_BASE_ADDRESS   (APB2_BASE_ADDRESS + 0x1000)
#define USART6_BASE_ADDRESS   (APB2_BASE_ADDRESS + 0x1400)
#define EXTI_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x3C00)
#define SYSCFG_BASE_ADDRESS   (APB2_BASE_ADDRESS + 0x3800)
#define SPI1_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x3000)
#define SPI4_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x3400)
#define SPI5_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x5000)
#define SPI6_BASE_ADDRESS     (APB2_BASE_ADDRESS + 0x5400)
//Peripheral register typecast to base address

#define GPIOA     ((GPIO_REG_DEF_t*)GPIO_A_BASE_ADDRESS)
#define GPIOB     ((GPIO_REG_DEF_t*)GPIO_B_BASE_ADDRESS)
#define GPIOC     ((GPIO_REG_DEF_t*)GPIO_C_BASE_ADDRESS)
#define GPIOD     ((GPIO_REG_DEF_t*)GPIO_D_BASE_ADDRESS)
#define GPIOE     ((GPIO_REG_DEF_t*)GPIO_E_BASE_ADDRESS)
#define GPIOF     ((GPIO_REG_DEF_t*)GPIO_F_BASE_ADDRESS)
#define GPIOG     ((GPIO_REG_DEF_t*)GPIO_G_BASE_ADDRESS)
#define GPIOH     ((GPIO_REG_DEF_t*)GPIO_H_BASE_ADDRESS)
#define GPIOI     ((GPIO_REG_DEF_t*)GPIO_I_BASE_ADDRESS)
#define GPIOJ     ((GPIO_REG_DEF_t*)GPIO_J_BASE_ADDRESS)
#define GPIOK     ((GPIO_REG_DEF_t*)GPIO_K_BASE_ADDRESS)

#define RCC       ((RCC_REG_Def_t*) RCC_BASE_ADDRESS)

#define EXTI      ((EXTI_REG_Def_t*) EXTI_BASE_ADDRESS)

#define SYSCFG    ((SYSCFG_REG_Def_t*) SYSCFG_BASE_ADDRESS)


/*
 * SPI Device definitions
 */

#define SPI1    ((SPI_RegDef_t*)SPI1_BASE_ADDRESS)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASE_ADDRESS)
#define SPI3    ((SPI_RegDef_t*)SPI3_BASE_ADDRESS)
#define SPI4    ((SPI_RegDef_t*)SPI4_BASE_ADDRESS)
#define SPI5    ((SPI_RegDef_t*)SPI5_BASE_ADDRESS)
#define SPI6    ((SPI_RegDef_t*)SPI6_BASE_ADDRESS)

/*
 * I2C Device definitions
 */

#define I2C1    ((I2C_REG_Def_t*)I2C1_BASE_ADDRESS)
#define I2C2    ((I2C_REG_Def_t*)I2C2_BASE_ADDRESS)
#define I2C3    ((I2C_REG_Def_t*)I2C3_BASE_ADDRESS)
#define I2C4    ((I2C_REG_Def_t*)I2C4_BASE_ADDRESS)


/**
 * @brief Reset and Clock Control
 */

typedef struct
{
	volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
	volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
	volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
	volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
	volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
	volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
	volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
	volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
	volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
	uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
	volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
	volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
	volatile uint32_t DCKCFGR1;      /*!< RCC Dedicated Clocks configuration register1,                 Address offset: 0x8C */
	volatile uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x90 */

} RCC_REG_Def_t;

//GPIO registers mapped

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;

}GPIO_REG_DEF_t;

// Peripheral Registers Structure for EXTI
typedef struct
{
	volatile uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	volatile uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
	volatile uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	volatile uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	volatile uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	volatile uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */

}EXTI_REG_Def_t;

/**
 * @brief System configuration controller
 */

typedef struct
{
	volatile uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
	volatile uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
	volatile uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
	uint32_t      RESERVED;     /*!< Reserved, 0x18                                                               */
	volatile uint32_t CBR;          /*!< SYSCFG Class B register,                           Address offset: 0x1C      */
	volatile uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
}SYSCFG_REG_Def_t;



/**
  * @brief Serial Peripheral Interface (SPI)
  */

typedef struct
{
  volatile uint32_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  volatile uint32_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  volatile uint32_t SR;         /*!< SPI status register,                                Address offset: 0x08 */
  volatile uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  volatile uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  volatile uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  volatile uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  volatile uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  volatile uint32_t I2SPR;      /*!< SPI_I2S pre-scaler register,                         Address offset: 0x20 */
} SPI_RegDef_t;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  volatile uint32_t CR1;      /*!< I2C Control register 1,            Address offset: 0x00 */
  volatile uint32_t CR2;      /*!< I2C Control register 2,            Address offset: 0x04 */
  volatile uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  volatile uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  volatile uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  volatile uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  volatile uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  volatile uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  volatile uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  volatile uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  volatile uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_REG_Def_t;

// Clock enable Macros for GPIOs

#define GPIOA_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<8))
#define GPIOJ_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<9))
#define GPIOK_PERIPH_CLCK_EN()  (RCC->AHB1ENR |= (1<<10))

//GPIO peripheral reset macros

#define GPIOA_RESET()  do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_RESET()  do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1));} while(0)
#define GPIOC_RESET()  do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_RESET()  do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_RESET()  do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4));}while(0)
#define GPIOF_RESET()  do{(RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5));}while(0)
#define GPIOG_RESET()  do{(RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6));}while(0)
#define GPIOH_RESET()  do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7));}while(0)
#define GPIOI_RESET()  do{(RCC->AHB1RSTR |= (1<<8)); (RCC->AHB1RSTR &= ~(1<<8));}while(0)
#define GPIOJ_RESET()  do{(RCC->AHB1RSTR |= (1<<9)); (RCC->AHB1RSTR &= ~(1<<9));}while(0)
#define GPIOK_RESET()  do{(RCC->AHB1RSTR |= (1<<10));(RCC->AHB1RSTR &= ~(1<<10));}while(0)



//TIM Clock enable Macros

#define TIM2_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<0))
#define TIM3_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<1))
#define TIM4_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<2))
#define TIM5_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<3))
#define TIM6_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<4))
#define TIM7_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<5))



// Clock enable for I2Cs
#define I2C1_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<21))
#define I2C2_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<22))
#define I2C3_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<23))
#define I2C4_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<24))

//Clock enable for CAN
#define CAN3_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<13))

//Clock enable for SPIs
#define SPI2_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<14))
#define SPI3_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<15))

#define SPI1_PERI_CLCK_EN()  (RCC->APB2ENR |= (1<<12))
#define SPI4_PERI_CLCK_EN()  (RCC->APB2ENR |= (1<<13))
#define SPI5_PERI_CLCK_EN()  (RCC->APB2ENR |= (1<<20))
#define SPI6_PERI_CLCK_EN()  (RCC->APB2ENR |= (1<<21))

// SPI Peripheral Reset Macros
#define SPI1_RESET()  do{(RCC->APB2RSTR |= (1<<RCC_APB2RSTR_SPI1_RSTR)); (RCC->APB2RSTR &= ~(1<<RCC_APB2RSTR_SPI1_RSTR)); }while(0)
#define SPI2_RESET()  do{(RCC->APB1RSTR |= (1<<RCC_APB1RSTR_SPI2_RSTR)); (RCC->APB1RSTR &= ~(1<<RCC_APB1RSTR_SPI2_RSTR));} while(0)
#define SPI3_RESET()  do{(RCC->APB1RSTR |= (1<<RCC_APB1RSTR_SPI3_RSTR)); (RCC->APB1RSTR &= ~(1<<RCC_APB1RSTR_SPI3_RSTR));}while(0)
#define SPI4_RESET()  do{(RCC->APB2RSTR |= (1<<RCC_APB2RSTR_SPI4_RSTR)); (RCC->APB2RSTR &= ~(1<<RCC_APB2RSTR_SPI4_RSTR)); }while(0)
#define SPI5_RESET()  do{(RCC->APB2RSTR |= (1<<RCC_APB2RSTR_SPI5_RSTR)); (RCC->APB2RSTR &= ~(1<<RCC_APB2RSTR_SPI5_RSTR)); }while(0)
#define SPI6_RESET()  do{(RCC->APB2RSTR |= (1<<RCC_APB2RSTR_SPI6_RSTR)); (RCC->APB2RSTR &= ~(1<<RCC_APB2RSTR_SPI6_RSTR)); }while(0)

//Clock enable for UARTs
#define USART2_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<17))
#define USART3_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<18))
#define UART4_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<19))
#define UART5_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<20))
#define USART7_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<30))
#define USART8_PERI_CLCK_EN()  (RCC->APB1ENR |= (1<<31))

//SYSCFG peripheral clock enable


//
// Clock disable Macros for GPIOs

#define GPIOA_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<8))
#define GPIOJ_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<9))
#define GPIOK_PERIPH_CLCK_DIS()  (RCC->AHB1ENR &= ~(1<<10))

//TIM Clock disable Macros

#define TIM2_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<0))
#define TIM3_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<1))
#define TIM4_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<2))
#define TIM5_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<3))
#define TIM6_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<4))
#define TIM7_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<5))



// Clock disable for I2Cs
#define I2C1_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<21))
#define I2C2_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<22))
#define I2C3_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<23))
#define I2C4_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<24))

//Clock disable for CAN
#define CAN3_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<13))

//Clock disable for SPIs
#define SPI2_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<15))

#define SPI1_PERI_CLCK_DIS()  (RCC->APB2ENR &= ~(1<<12))
#define SPI4_PERI_CLCK_DIS()  (RCC->APB2ENR &= ~(1<<13))
#define SPI5_PERI_CLCK_DIS()  (RCC->APB2ENR &= ~(1<<20))
#define SPI6_PERI_CLCK_DIS()  (RCC->APB2ENR &= ~(1<<21))

//Clock disable for UARTs
#define USART2_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<17))
#define USART3_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<18))
#define UART4_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<19))
#define UART5_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<20))
#define USART7_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<30))
#define USART8_PERI_CLCK_DIS()  (RCC->APB1ENR &= ~(1<<31))

//SYSCFG peripheral clock enable
#define SYSCFG_PERI_CLCK_EN()     (RCC->APB2ENR |= (1<<14))

//SYSCFG peripheral clock disable
#define SYSCFG_PERI_CLCK_DIS()     (RCC->APB2ENR &= ~(1<<14))

//
#define GPIO_BASE_ADDR_TO_CODE(x)   ((x == GPIOA)?0:\
		                             (x == GPIOB)?1:\
				                     (x == GPIOC)?2:\
						             (x == GPIOD)?3:\
								     (x == GPIOE)?4:\
									 (x == GPIOF)?5:\
									 (x == GPIOG)?6:\
									 (x == GPIOH)?7:\
									 (x == GPIOI)?8:\
									 (x == GPIOJ)?9:\
									 (x == GPIOK)?10:0)

// RESET REGISTER BIT POSITION Macros
#define RCC_APB2RSTR_SPI1_RSTR               12
#define RCC_APB2RSTR_SPI4_RSTR               13
#define RCC_APB2RSTR_SPI5_RSTR               20
#define RCC_APB2RSTR_SPI6_RSTR               21
#define RCC_APB1RSTR_SPI2_RSTR               14
#define RCC_APB1RSTR_SPI3_RSTR               15
//General Macros
#define __weak __attribute__((weak))
#define ENABLE         1
#define DISABLE        0
#define FLAG_RESET     0
#define FLAG_SET       1

#include "stm32F7xx_gpio.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STM32F767_H_ */
