/**
  ******************************************************************************
  * File Name          : USART.c
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
//static uint8_t flag = 0;

uint8_t aRxBuffer[RXBUFFERSIZE];//HAL库使用的串口接收缓冲
/* USER CODE END 0 */

UART_HandleTypeDef UartHandle;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//    UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&UartHandle) != HAL_OK)
    {
        Error_Handler();
    }
    __HAL_UART_ENABLE(&UartHandle);
    __HAL_UART_ENABLE_IT(&UartHandle,UART_IT_RXNE);

//    HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(uartHandle->Instance==USART1)
    {
        /* USER CODE BEGIN USART1_MspInit 0 */

        /* USER CODE END USART1_MspInit 0 */
        /* USART1 clock enable */
        __HAL_RCC_USART1_CLK_ENABLE();

        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**USART1 GPIO Configuration
        PA9     ------> USART1_TX
        PA10     ------> USART1_RX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* USART1 interrupt Init */
//        HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
//        HAL_NVIC_EnableIRQ(USART1_IRQn);
        /* USER CODE BEGIN USART1_MspInit 1 */

        __HAL_UART_ENABLE(&UartHandle);
        __HAL_UART_ENABLE_IT(&UartHandle,UART_IT_RXNE);
        __HAL_UART_ENABLE_IT(&UartHandle, UART_IT_ERR);

        /* USER CODE END USART1_MspInit 1 */
    }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

    if(uartHandle->Instance==USART1)
    {
        /* USER CODE BEGIN USART1_MspDeInit 0 */

        /* USER CODE END USART1_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_USART1_CLK_DISABLE();

        /**USART1 GPIO Configuration
        PA9     ------> USART1_TX
        PA10     ------> USART1_RX
        */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

        /* USART1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(USART1_IRQn);
        /* USER CODE BEGIN USART1_MspDeInit 1 */

        /* USER CODE END USART1_MspDeInit 1 */
    }
}

/* USER CODE BEGIN 1 */

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//    static uint32_t cnt = 0;

//    if(huart->Instance==USART1)//如果是串口 1
//    {
//        SEGGER_RTT_printf(0,"[%s]<%d>----\r\n",__func__,__LINE__);
//        flag = 1;
//    }

//}
///**
//  * @brief  Print a string on the HyperTerminal
//  * @param  s: The string to be printed
//  * @retval None
//  */
//void Serial_PutString(uint8_t *s)
//{
//    while (*s != '\0')
//    {
//        SerialPutChar(*s);
//        s++;
//    }
//}


///**
//  * @brief  Test to see if a key has been pressed on the HyperTerminal
//  * @param  key: The key pressed
//  * @retval 1: Correct
//  *         0: Error
//  */
//uint32_t SerialKeyPressed(uint8_t *key)
//{
//    uint8_t res = 0;
//    if(flag==1)
//    {
//        *key = aRxBuffer[0];
//        flag = 0;
//        SEGGER_RTT_printf(0,"[%s]<%d>----\r\n",__func__,__LINE__);
//        res = 1;
//    }
//    return res;
//}

///**
//  * @brief  Get a key from the HyperTerminal
//  * @param  None
//  * @retval The Key Pressed
//  */
//uint8_t GetKey(int timeout)
//{
//    uint8_t key = 0;

//    /* Waiting for user input */
//    do
//    {
//        if (SerialKeyPressed((uint8_t*)&key)) break;
//        HAL_Delay(1);
//    }while ((timeout == -1) || (timeout--));
//    return key;

//}


///**
//  * @brief  Print a character on the HyperTerminal
//  * @param  c: The character to be printed
//  * @retval None
//  */
//void SerialPutChar(uint8_t c)
//{

//    HAL_UART_Transmit(&UartHandle,&c,1,1000);
//    while(__HAL_UART_GET_FLAG(&UartHandle, UART_FLAG_TC)!=SET); //等待发送结束
//    __HAL_UART_CLEAR_FLAG(&UartHandle,UART_FLAG_TC);
//}

///**
//  * @brief  Convert an Integer to a string
//  * @param  str: The string
//  * @param  intnum: The intger to be converted
//  * @retval None
//  */
//void Int2Str(uint8_t* str, int32_t intnum)
//{
//    uint32_t i, Div = 1000000000, j = 0, Status = 0;

//    for (i = 0; i < 10; i++)
//    {
//        str[j++] = (intnum / Div) + 48;

//        intnum = intnum % Div;
//        Div /= 10;
//        if ((str[j-1] == '0') & (Status == 0))
//        {
//            j = 0;
//        }
//        else
//        {
//            Status++;
//        }
//    }
//}



///**
//  * @brief  Convert a string to an integer
//  * @param  inputstr: The string to be converted
//  * @param  intnum: The intger value
//  * @retval 1: Correct
//  *         0: Error
//  */
//uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum)
//{
//    uint32_t i = 0, res = 0;
//    uint32_t val = 0;

//    if (inputstr[0] == '0' && (inputstr[1] == 'x' || inputstr[1] == 'X'))
//    {
//        if (inputstr[2] == '\0')
//        {
//            return 0;
//        }
//        for (i = 2; i < 11; i++)
//        {
//            if (inputstr[i] == '\0')
//            {
//                *intnum = val;
//                /* return 1; */
//                res = 1;
//                break;
//            }
//            if (ISVALIDHEX(inputstr[i]))
//            {
//                val = (val << 4) + CONVERTHEX(inputstr[i]);
//            }
//            else
//            {
//                /* return 0, Invalid input */
//                res = 0;
//                break;
//            }
//        }
//        /* over 8 digit hex --invalid */
//        if (i >= 11)
//        {
//            res = 0;
//        }
//    }
//    else /* max 10-digit decimal input */
//    {
//        for (i = 0; i < 11; i++)
//        {
//            if (inputstr[i] == '\0')
//            {
//                *intnum = val;
//                /* return 1 */
//                res = 1;
//                break;
//            }
//            else if ((inputstr[i] == 'k' || inputstr[i] == 'K') && (i > 0))
//            {
//                val = val << 10;
//                *intnum = val;
//                res = 1;
//                break;
//            }
//            else if ((inputstr[i] == 'm' || inputstr[i] == 'M') && (i > 0))
//            {
//                val = val << 20;
//                *intnum = val;
//                res = 1;
//                break;
//            }
//            else if (ISVALIDDEC(inputstr[i]))
//            {
//                val = val * 10 + CONVERTDEC(inputstr[i]);
//            }
//            else
//            {
//                /* return 0, Invalid input */
//                res = 0;
//                break;
//            }
//        }
//        /* Over 10 digit decimal --invalid */
//        if (i >= 11)
//        {
//            res = 0;
//        }
//    }

//    return res;
//}





///* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
