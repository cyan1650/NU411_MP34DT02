/**
******************************************************************************
* @file    x_nucleo_cca02m1_audio_f4.h
* @author  Central Labs
* @version V1.3.1
* @date    01-Sep-2016
* @brief   This file contains the common defines and functions prototypes for
*          x_nucleo_cca02m1_audio_f4.c driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __X_NUCLEO_CCA02M1_AUDIO_F4_H
#define __X_NUCLEO_CCA02M1_AUDIO_F4_H

#ifdef __cplusplus
extern "C" {
#endif 
  
  /* Includes ------------------------------------------------------------------*/
  
#include "../../../Middlewares/ST/STM32_Audio/Addons/PDM/pdm_filter.h"

  /** @addtogroup BSP
  * @{
  */
  
  /** @addtogroup X-NUCLEO-CCA02M1
  * @{
  */
  
  /** @addtogroup X-NUCLEO-CCA02M1_AUDIO_F4
  * @{
  */
  
  /** @defgroup X-NUCLEO-CCA02M1_AUDIO_F4_Private_Types 
  * @{
  */  
  
/*#define USE_SPI3*/
  /*If you wanto to use SPI3 instead of SPI2 for M3 and M4, uncomment this define and 
  close SB20 and SB21*/

  /** 
  * @brief   Microphone internal structure definition  
  */ 
  typedef struct
  {      
    uint32_t MicChannels;       /*!< Specifies the number of channels */

    uint32_t PdmBufferSize;     /*!< Specifies the size of the PDM double buffer for 1 microphone and 1 ms in bytes*/
    
    uint32_t Sampling_Freq;     /*!< Specifies the desired sampling frequency */
    
    uint32_t DecimationFactor;  /*!< Specifies the PDM to PCM decimation factor */
    
    uint16_t * PDM_Data;	/*!< Takes track of the external PDM data buffer as passed by the user in the start function*/

  }X_NUCLEO_CCA02M1_HandlerTypeDef;
  
  /**
  * @}
  */ 
  
  /** @defgroup X-NUCLEO-CCA02M1_AUDIO_F4_Exported_Constants 
  * @{
  */   

  /* I2S Configuration defines */
#if 0
#define AUDIO_IN_I2S_INSTANCE                                    SPI2
#define AUDIO_IN_I2S_CLK_ENABLE()                                __SPI2_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_PIN                                     GPIO_PIN_13
#define AUDIO_IN_I2S_SCK_GPIO_PORT                               GPIOB
#define AUDIO_IN_I2S_SCK_GPIO_CLK_ENABLE()                       __GPIOB_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_AF                                      GPIO_AF5_SPI2  
#define AUDIO_IN_I2S_MOSI_PIN                                    GPIO_PIN_15
#define AUDIO_IN_I2S_MOSI_GPIO_PORT                              GPIOB
#define AUDIO_IN_I2S_MOSI_GPIO_CLK_ENABLE()                      __GPIOB_CLK_ENABLE();
#define AUDIO_IN_I2S_MOSI_AF                                     GPIO_AF5_SPI2
#else

#define AUDIO_IN_I2S_INSTANCE                                    SPI2
#define AUDIO_IN_I2S_CLK_ENABLE()                            __SPI2_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_PIN                                        GPIO_PIN_13
#define AUDIO_IN_I2S_SCK_GPIO_PORT                               GPIOB
#define AUDIO_IN_I2S_SCK_GPIO_CLK_ENABLE()                       __GPIOB_CLK_ENABLE()
#define AUDIO_IN_I2S_SCK_AF                                      GPIO_AF5_SPI2  
#define AUDIO_IN_I2S_MOSI_PIN                                    GPIO_PIN_3
#define AUDIO_IN_I2S_MOSI_GPIO_PORT                              GPIOC
#define AUDIO_IN_I2S_MOSI_GPIO_CLK_ENABLE()                      __GPIOC_CLK_ENABLE();
#define AUDIO_IN_I2S_MOSI_AF                                     GPIO_AF5_SPI2

#endif

  
  /* I2S DMA definitions */
#define AUDIO_IN_I2S_DMAx_CLK_ENABLE()                          __DMA1_CLK_ENABLE()
#define AUDIO_IN_I2S_DMAx_STREAM                                DMA1_Stream3
#define AUDIO_IN_I2S_DMAx_CHANNEL                               DMA_CHANNEL_0
#define AUDIO_IN_I2S_DMAx_IRQ                                   DMA1_Stream3_IRQn
#define AUDIO_IN_I2S_DMAx_PERIPH_DATA_SIZE                      DMA_PDATAALIGN_HALFWORD
#define AUDIO_IN_I2S_DMAx_MEM_DATA_SIZE                         DMA_MDATAALIGN_HALFWORD  
#define AUDIO_IN_I2S_IRQHandler                                 DMA1_Stream3_IRQHandler
  
  /* Select the interrupt preemption priority  */
#define AUDIO_IN_IRQ_PREPRIO          6     
  
#ifdef USE_SPI3
    /* SPI Configuration defines */  
  
#define AUDIO_IN_SPI_INSTANCE                                            SPI3
#define AUDIO_IN_SPI_CLK_ENABLE()                               __SPI3_CLK_ENABLE()
#define AUDIO_IN_SPI_SCK_GPIO_CLK_ENABLE()                      __GPIOC_CLK_ENABLE()
#define AUDIO_IN_SPI_MISO_GPIO_CLK_ENABLE()                     __GPIOC_CLK_ENABLE() 
#define AUDIO_IN_SPI_MOSI_GPIO_CLK_ENABLE()                     __GPIOC_CLK_ENABLE()   
#define AUDIO_IN_SPI_FORCE_RESET()                              __SPI3_FORCE_RESET()
#define AUDIO_IN_SPI_RELEASE_RESET()                            __SPI3_RELEASE_RESET()
#define AUDIO_IN_SPI_SCK_PIN                                    GPIO_PIN_10
#define AUDIO_IN_SPI_SCK_GPIO_PORT                              GPIOC
#define AUDIO_IN_SPI_SCK_AF                                     GPIO_AF6_SPI3
#define AUDIO_IN_SPI_MOSI_PIN                                   GPIO_PIN_12
#define AUDIO_IN_SPI_MOSI_GPIO_PORT                             GPIOC
#define AUDIO_IN_SPI_MOSI_AF                                    GPIO_AF6_SPI3
  
  /* SPI DMA definitions */
#define AUDIO_IN_SPI_DMAx_CLK_ENABLE()                          __DMA1_CLK_ENABLE()
#define AUDIO_IN_SPI_RX_DMA_CHANNEL                             DMA_CHANNEL_0
#define AUDIO_IN_SPI_RX_DMA_STREAM                              DMA1_Stream2 
#define AUDIO_IN_SPI_DMA_RX_IRQn                                DMA2_Stream2_IRQn
#define AUDIO_IN_SPI_DMA_RX_IRQHandler                          DMA2_Stream2_IRQHandler
  
#else
  /* SPI Configuration defines */  
#define AUDIO_IN_SPI_INSTANCE                                            SPI1
#define AUDIO_IN_SPI_CLK_ENABLE()                               __SPI1_CLK_ENABLE()
#define AUDIO_IN_SPI_SCK_GPIO_CLK_ENABLE()                      __GPIOA_CLK_ENABLE()
#define AUDIO_IN_SPI_MISO_GPIO_CLK_ENABLE()                     __GPIOA_CLK_ENABLE() 
#define AUDIO_IN_SPI_MOSI_GPIO_CLK_ENABLE()                     __GPIOA_CLK_ENABLE()   
#define AUDIO_IN_SPI_FORCE_RESET()                              __SPI1_FORCE_RESET()
#define AUDIO_IN_SPI_RELEASE_RESET()                            __SPI1_RELEASE_RESET()
#define AUDIO_IN_SPI_SCK_PIN                                    GPIO_PIN_5
#define AUDIO_IN_SPI_SCK_GPIO_PORT                              GPIOA
#define AUDIO_IN_SPI_SCK_AF                                     GPIO_AF5_SPI1
#define AUDIO_IN_SPI_MOSI_PIN                                   GPIO_PIN_7
#define AUDIO_IN_SPI_MOSI_GPIO_PORT                             GPIOA
#define AUDIO_IN_SPI_MOSI_AF                                    GPIO_AF5_SPI1
  
  /* SPI DMA definitions */
#define AUDIO_IN_SPI_DMAx_CLK_ENABLE()                          __DMA2_CLK_ENABLE()
#define AUDIO_IN_SPI_RX_DMA_CHANNEL                             DMA_CHANNEL_3
#define AUDIO_IN_SPI_RX_DMA_STREAM                              DMA2_Stream2 
#define AUDIO_IN_SPI_DMA_RX_IRQn                                DMA2_Stream2_IRQn
#define AUDIO_IN_SPI_DMA_RX_IRQHandler                          DMA2_Stream2_IRQHandler
  
#endif
  /* AUDIO TIMER definitions */
	
	#if 0
#define AUDIO_IN_TIMER                                     TIM3
#define AUDIO_IN_TIMER_CLK_ENABLE()                        __TIM3_CLK_ENABLE()  
#define AUDIO_IN_TIMER_CHOUT_AF                            GPIO_AF2_TIM3
#define AUDIO_IN_TIMER_CHOUT_PIN                           GPIO_PIN_5
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT                     GPIOB
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT_CLK_ENABLE()        __GPIOB_CLK_ENABLE()  
#define AUDIO_IN_TIMER_CHIN_AF                             GPIO_AF2_TIM3
#define AUDIO_IN_TIMER_CHIN_PIN                            GPIO_PIN_4
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT                      GPIOB
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT_CLK_ENABLE()         __GPIOB_CLK_ENABLE()   
  #else
#define AUDIO_IN_TIMER                                     TIM2
#define AUDIO_IN_TIMER_CLK_ENABLE()                        __TIM2_CLK_ENABLE()  
#define AUDIO_IN_TIMER_CHOUT_AF                            GPIO_AF1_TIM2
#define AUDIO_IN_TIMER_CHOUT_PIN                           GPIO_PIN_1
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT                     GPIOA
#define AUDIO_IN_TIMER_CHOUT_GPIO_PORT_CLK_ENABLE()        __GPIOA_CLK_ENABLE()  
#define AUDIO_IN_TIMER_CHIN_AF                             GPIO_AF1_TIM2
#define AUDIO_IN_TIMER_CHIN_PIN                            GPIO_PIN_15
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT                      GPIOA
#define AUDIO_IN_TIMER_CHIN_GPIO_PORT_CLK_ENABLE()         __GPIOA_CLK_ENABLE()   
	#endif
	
/*------------------------------------------------------------------------------
             CONFIGURATION: Audio Driver Configuration parameters
------------------------------------------------------------------------------*/

  /* Audio status definition */     
#ifndef AUDIO_OK
#define AUDIO_OK                            ((uint8_t)0)
#endif  

#ifndef AUDIO_ERROR
#define AUDIO_ERROR                         ((uint8_t)1)
#endif 

#ifndef AUDIO_TIMEOUT
#define AUDIO_TIMEOUT                       ((uint8_t)2)
#endif 


#define AUDIOFREQ_48K                ((uint32_t)48000)
#define AUDIOFREQ_32K                ((uint32_t)32000)
#define AUDIOFREQ_16K                ((uint32_t)16000)
#define AUDIOFREQ_8K                 ((uint32_t)8000)


/* Those defines are used to allocate the right amount of RAM depending on the
   maximum number of microphone and frequency desired */
#define MAX_MIC_FREQ                 	  3072  /*KHz*/
#define MAX_AUDIO_IN_CHANNEL_NBR_PER_IF   2 

/*BSP internal buffer size in half words (16 bits)*/
#define PDM_INTERNAL_BUFFER_SIZE          ((MAX_MIC_FREQ / 8) * MAX_AUDIO_IN_CHANNEL_NBR_PER_IF)

  
  /**
  * @}
  */ 
  
  /** @defgroup X-NUCLEO-CCA02M1_AUDIO_F4_Exported_Variables 
  * @{
  */ 
extern I2S_HandleTypeDef                hAudioInI2s;
  /**
  * @}
  */ 
  
  /** @defgroup X-NUCLEO-CCA02M1_AUDIO_F4_Exported_Macros
  * @{
  */
#define DMA_MAX(_X_)                (((_X_) <= DMA_MAX_SZE)? (_X_):DMA_MAX_SZE)

  
  /**
  * @}
  */
  
  /** @defgroup X-NUCLEO-CCA02M1_AUDIO_F4_Exported_Functions 
  * @{
  */   
  
  uint8_t BSP_AUDIO_IN_Init(uint32_t AudioFreq, uint32_t BitRes, uint32_t ChnlNbr);
  uint8_t BSP_AUDIO_IN_Record(uint16_t* pbuf, uint32_t size);
  uint8_t BSP_AUDIO_IN_Stop(void);
  uint8_t BSP_AUDIO_IN_Pause(void);
  uint8_t BSP_AUDIO_IN_Resume(void);
  uint8_t BSP_AUDIO_IN_SetVolume(uint8_t Volume);
  uint8_t BSP_AUDIO_IN_PDMToPCM(uint16_t *PDMBuf, uint16_t *PCMBuf);
  uint8_t BSP_AUDIO_IN_ClockConfig(I2S_HandleTypeDef *hi2s, uint32_t AudioFreq, void *Params);
  uint8_t BSP_AUDIO_IN_PDMToPCM_Init(uint32_t AudioFreq, uint32_t ChnlNbrIn, uint32_t ChnlNbrOut);



  /* User Callbacks: user has to implement these functions in his code if they are needed. */
  /* This function should be implemented by the user application.
     It is called into this driver when the current buffer is filled to prepare the next
     buffer pointer and its size. */
  void BSP_AUDIO_IN_TransferComplete_CallBack(void);
  void BSP_AUDIO_IN_HalfTransfer_CallBack(void);
  void BSP_AUDIO_IN_Error_Callback(void);
  
  /**
  * @}
  */  
  
  /**
  * @}
  */   
  
  /**
  * @}
  */
  
  /**
  * @}
  */ 
  
#ifdef __cplusplus
}
#endif

#endif /* __X_NUCLEO_CCA02M1_AUDIO_F4_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
