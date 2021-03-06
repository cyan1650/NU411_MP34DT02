/**
  @page SMARTACOUSTIC1 Smartrt Audio IN-OUT software expansion for STM32Cube
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    readme.txt  
  * @author  Central Labs
  * @version V 1.1.0
  * @date    1-Sep-2016
  * @brief   Description of the SmartAcoustic1.
  ******************************************************************************
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
  @endverbatim

@par Application Description 

This document provides a description of the microphone streaming application based 
on Nucleo boards and X-NUCLEO-CCA02M1 expansion board. It allows acquisition of 
up to 4 digital MEMS microphones, PDM to PCM decimation and streaming towards 
a host PC via a dedicated USB Audio Input driver.
It is designed to be compatible with different MCU families, thus NUCLEO-F401RE, 
NUCLEO-F072RB, NUCLEO-L053R8, NUCLEO-L476 or Nucleo-144-F746 boards can be adopted. 
Depending on the MCU and the resources, different 
performances can be achieved, in terms of maximum number of microphones and 
maximum sampling frequency: using STM32F4 or STM32F7 is possible to acquire up to four 
microphones at a maximum sampling frequency of 48 KHz, using STM32F0 or 
STM32L0 you can acquire up to two microphone  at 16 KHz. Exploiting STM32L4 hardware
capabilities, acquisition can be performed for up to 4 microphonse at 96KHz

A digital MEMS microphone can be acquired by using different peripherals, 
such as SPI, I2S, GPIO or DFSDM. It requires an input clock and it outputs a PDM 
stream at the same frequency of the input clock. This PDM stream is further filtered 
and decimated in order to be converted in PCM format, that is the main standard 
for audio transmission. Two different digital MEMS microphones can be connected 
on the same data line configuring the first to generate a valid data on the rising
edge of the clock and the other on the falling edge by setting the L/R pin of 
each microphone in an opposite way. In the X-NUCLEO-CCA02M1 expansion board 
two microphones share the same data line.  

Depending on the adopted MCU, the X-NUCLEO-CCA02M1 expansion board can
connect microphone lines to the right peripheral:

When STM32F4, STM32L0, STM32F0 or STM32F7 is used, microphones are routed to nucleo I2S 
peripheral (the first and the second) and SPI peripheral (the third and the fourth). 
In this scenario the microphones acquisition works in this way: a precise clock 
is generated by I2S peripheral while SPI is configured in slave mode
and is fed by the same timing signal generated by I2S. This clock is then 
halved by a timer and given in input to the microphones: the SPI and I2S peripherals 
are working at a frequency that is twice the microphone frequency, so that they 
can read data on both the rising and falling edge of the microphone clock, 
thus reading the bits of two microphones each. A software step of
demuxing is required in order to separate the signal from the two microphones 
and allows further processing like PDM to PCM conversion. 

When STM32L4 is adopted, the Digital Filter for Sigma Delta Modulator hardware peripheral (DFSDM)
is used: DFSDM channels are adopted in order to acquire 
4 microphones and hardware filters are then used to perform PCM conversion. The clock 
signal is generated by DFSDM peripheral and given in input to the microphones.
All the acquisitions and conversion are synchronous with Filter 1.

DMA is used to transfer data from acquisition peripherals to internal SRAM. 

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals. 
Then the SystemClock_Config() function is used to configure the system clock (SYSCLK). 
The resulting system clock speed depends on the MCU used and it's equal to 84 MHz for 
STM32F401, 32 MHz for STM32F0 and STM32L0, 80MHz for STM32L4 and 200MHz for STM32F7.

At this point the following steps are required:

- USB Audio In configuration:
At first the USB descriptor is set up according to the number of channels 
to be streamed and the desired frequency. This allows the device to be 
recognized as a standard USB microphone with the requested configuration. 
Then the firmware initializes USB core and start USB functionalities 
with the standard USB Device functions.

- Audio peripheral configuration and start of the acquisition: 
Using BSP layer and Middlewares functionalities, all the required peripherals and 
libraries are configured, basing on the number of channels to be streamed and the 
desired sampling frequency to be achieved. These steps start inside the 
usbd_audio_if.c file, whose functions are called in response to the USB enumeration 
that starts when the device is connected to the PC. 
An alternative approach would be to manage the configuration and starting of the 
audio peripherals by calling directly the BSP functionalities from the application
space.
In the firmware, audio-related parts, concerning action to be performed in response 
to DMA callbacks, are collected in the audio_application.c 

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - MicrophoneStreaming/Src/stm32xx_it.c                  Interrupt handlers file 
  - MicrophoneStreaming/Src/system_stm32f4xx.c            STM32F4xx system clock configuration file
  - MicrophoneStreaming/Src/system_stm32f0xx.c            STM32F0xx system clock configuration file
  - MicrophoneStreaming/Src/system_stm32l0xx.c            STM32L0xx system clock configuration file 
  - MicrophoneStreaming/Src/system_stm32l4xx.c            STM32L4xx system clock configuration file
  - MicrophoneStreaming/Src/system_stm32f7xx.c            STM32F7xx system clock configuration file
  - MicrophoneStreaming/Src/usbd_audio_if.c	          USBD Audio-input interface  
  - MicrophoneStreaming/Src/usbd_conf_f4.c    	          USB device driver Configuration file for STM32F4
  - MicrophoneStreaming/Src/usbd_conf_f0.c    	         USB device driver Configuration file for STM32F0
  - MicrophoneStreaming/Src/usbd_conf_l0.c    	        USB device driver Configuration file for STM32L0
  - MicrophoneStreaming/Src/usbd_conf_l4.c    		USB device driver Configuration file for STM32L4
  - MicrophoneStreaming/Src/usbd_conf_f7.c    		USB device driver Configuration file for STM32F7
  - MicrophoneStreaming/Src/usbd_desc.c    			USB device AUDIO-input descriptor   
  - MicrophoneStreaming/Src/cube_hal_f4.c           Clock configuration file for STM32F4
  - MicrophoneStreaming/Src/cube_hal_f0.c           Clock configuration file for STM32F0
  - MicrophoneStreaming/Src/cube_hal_l0.c           Clock configuration file for STM32L0  
  - MicrophoneStreaming/Src/cube_hal_l4.c           Clock configuration file for STM32L4
  - MicrophoneStreaming/Src/cube_hal_f7.c           Clock configuration file for STM32F7 
  - MicrophoneStreaming/Src/main.c                  Main program	
  - MicrophoneStreaming/Src/audio_application.c     Audio application file  
  - MicrophoneStreaming/Inc/stm32f4xx_hal_conf.h    HAL configuration file for STM32F4
  - MicrophoneStreaming/Inc/stm32f0xx_hal_conf.h    HAL configuration file for STM32F0
  - MicrophoneStreaming/Inc/stm32l0xx_hal_conf.h    HAL configuration file for STM32L0
  - MicrophoneStreaming/Inc/stm32l4xx_hal_conf.h    HAL configuration file for STM32L4
  - MicrophoneStreaming/Inc/stm32f7xx_hal_conf.h    HAL configuration file for STM32F7
  - MicrophoneStreaming/Inc/stm32xx_it.h          Interrupt handlers header file 
  - MicrophoneStreaming/Inc/main.h                  Main program header file
  - MicrophoneStreaming/Inc/cube_hal.h			    X-CUBE includes file
  - MicrophoneStreaming/Inc/audio_application.h  	Application header file
  - MicrophoneStreaming/Inc/usbd_audio_if.h		    USBD Audio-input interface header file  
  - MicrophoneStreaming/Inc/usbd_conf.h    			USB device driver Configuration file
  - MicrophoneStreaming/Inc/usbd_desc.h    			USB device AUDIO-input descriptor header file   	
  - MicrophoneStreaming/Inc/usbd_desc.h    			USB device AUDIO-input descriptor header file   	

@par Hardware and Software environment

  - This example runs on STM32F401RE, STM32F072RB, STM32L053R8, STM32L476RG and STM32746ZG devices.
    
  - This example has been tested with STMicroelectronics STM32F401-Nucleo, 
    STM32L476-Nucleo, STM32L053-Nucleo, STM32F746-Nucleo-144 and STM32F072-Nucleo 
    boards and can be easily tailored to any other supported device 
    and development board.
    

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 - In order to stream audio via USB, connect X-NUCLEO-CCA02M1 USB connector to a host PC

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
