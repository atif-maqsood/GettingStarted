/*
 * Stm32F7xxRcc.h
 *
 *  Created on: 19 Sep 2020
 *      Author: ROG
 */

#ifndef STM32F7XXRCC_H_
#define STM32F7XXRCC_H_
#include "Stm32F767.h"

#ifdef __cplusplus

extern "C" {

#endif /* __cplusplus */


//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);

#ifdef __cplusplus

}

#endif /* __cplusplus */


#endif /* STM32F7XXRCC_H_ */
