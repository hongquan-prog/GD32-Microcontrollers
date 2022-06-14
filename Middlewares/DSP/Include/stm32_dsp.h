/**
  ******************************************************************************
  * @file STM32F10x_DSP_Lib/inc/stm32_dsp.h 
  * @author  MCD Application Team
  * @version  V2.0.0
  * @date  04/27/2009
  * @brief  This source file contains prototypes of DSP functions
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */ 


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_DSP_H
#define __STM32F10x_DSP_H

/* Includes ------------------------------------------------------------------*/
#include "gd32f30x.h"

/* Exported types ------------------------------------------------------------*/
/* for block FIR module */
typedef struct {
  uint16_t *h;
  uint32_t nh;
} COEFS;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Radix-4 complex FFT for STM32, in assembly  */
/* 64 points*/
void cr4_fft_64_stm32(void *pssOUT, void *pssIN, uint16_t Nbin);
/* 256 points */
void cr4_fft_256_stm32(void *pssOUT, void *pssIN, uint16_t Nbin);
/* 1024 points */
void cr4_fft_1024_stm32(void *pssOUT, void *pssIN, uint16_t Nbin);


#endif /* __STM32F10x_DSP_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
