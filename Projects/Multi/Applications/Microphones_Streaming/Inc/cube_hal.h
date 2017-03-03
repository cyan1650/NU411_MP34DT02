/**
  ******************************************************************************
  * @file    cube_hal.h
  * @author  Central Labs
  * @version V1.1.0
  * @date    11-Jan-2016
  * @brief   X-CUBE includes file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

#ifndef _CUBE_HAL_H_
#define _CUBE_HAL_H_

/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32F4XX_NUCLEO
#define USB_IRQHandler OTG_FS_IRQHandler
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32xx_it.h"
#include "stm32f4xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_f4.h"
#endif

#ifdef USE_STM32F0XX_NUCLEO
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "stm32xx_it.h"
#include "stm32f0xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_f0.h"
#endif

#ifdef USE_STM32L0XX_NUCLEO
#include "stm32l0xx_hal.h"
#include "stm32l0xx.h"
#include "stm32xx_it.h"
#include "stm32l0xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_l0.h"
#endif

#ifdef USE_STM32L4XX_NUCLEO
#define USB_IRQHandler OTG_FS_IRQHandler
#include "stm32l4xx_hal.h"
#include "stm32l4xx.h"
#include "stm32xx_it.h"
#include "stm32l4xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_l4.h"
#endif

#ifdef USE_STM32F7XX_NUCLEO_144
#define USB_IRQHandler OTG_FS_IRQHandler
#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32xx_it.h"
#include "stm32f7xx_nucleo_144.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_f7.h"
#endif

#ifdef USE_STM32F3XX_NUCLEO
#define USB_IRQHandler USB_LP_CAN_RX0_IRQHandler
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#include "stm32xx_it.h"
#include "stm32f3xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "x_nucleo_cca02m1_audio_f3.h"
#endif

void SystemClock_Config(void);

#endif //_CUBE_HAL_H_
