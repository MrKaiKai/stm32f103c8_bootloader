/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */

#define RXBUFFERSIZE   1 					//缓存大小
extern uint8_t aRxBuffer[RXBUFFERSIZE];			//HAL库USART接收Buffer

/* Common routines */
//#define IS_AF(c)             ((c >= 'A') && (c <= 'F'))
//#define IS_af(c)             ((c >= 'a') && (c <= 'f'))
//#define IS_09(c)             ((c >= '0') && (c <= '9'))
//#define ISVALIDHEX(c)        IS_AF(c) || IS_af(c) || IS_09(c)
//#define ISVALIDDEC(c)        IS_09(c)
//#define CONVERTDEC(c)        (c - '0')

//#define CONVERTHEX_alpha(c)  (IS_AF(c) ? (c - 'A'+10) : (c - 'a'+10))
//#define CONVERTHEX(c)        (IS_09(c) ? (c - '0') : CONVERTHEX_alpha(c))


//#define SerialPutString(x)   Serial_PutString((uint8_t*)(x))

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */
//void SerialPutChar(uint8_t c);
//uint32_t SerialKeyPressed(uint8_t *key);
//uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum);
//void Int2Str(uint8_t* str, int32_t intnum);
//void Serial_PutString(uint8_t *s);
////uint8_t GetKey(void);
//uint8_t GetKey(int timeout);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
