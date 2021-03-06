/*
    __hallcurrent2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __hallcurrent2_driver.h
@brief    HallCurrent_2 Driver
@mainpage HallCurrent_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HALLCURRENT2
@brief      HallCurrent_2 Click Driver
@{

| Global Library Prefix | **HALLCURRENT2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HALLCURRENT2_H_
#define _HALLCURRENT2_H_

/** 
 * @macro T_HALLCURRENT2_P
 * @brief Driver Abstract type 
 */
#define T_HALLCURRENT2_P    const uint8_t*

/** @defgroup HALLCURRENT2_COMPILE Compilation Config */              /** @{ */

//  #define   __HALLCURRENT2_DRV_SPI__                            /**<     @macro __HALLCURRENT2_DRV_SPI__  @brief SPI driver selector */
   #define   __HALLCURRENT2_DRV_I2C__                            /**<     @macro __HALLCURRENT2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HALLCURRENT2_DRV_UART__                           /**<     @macro __HALLCURRENT2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HALLCURRENT2_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup HALLCURRENT2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HALLCURRENT2_INIT Driver Initialization */              /** @{ */

#ifdef   __HALLCURRENT2_DRV_SPI__
void hallcurrent2_spiDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P spiObj);
#endif
#ifdef   __HALLCURRENT2_DRV_I2C__
void hallcurrent2_i2cDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P i2cObj, uint8_t slave);
#endif
#ifdef   __HALLCURRENT2_DRV_UART__
void hallcurrent2_uartDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void hallcurrent2_gpioDriverInit(T_HALLCURRENT2_P gpioObj);
                                                                       /** @} */
/** @defgroup HALLCURRENT2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for reset chip
 */
void hallcurrent2_reset();

/**
 * @brief Reads current data
 *
 * @return current (12 bits) adc value
 *
 * On 0A loads at the input returns vcc / 2 (1.65V)
 */
int16_t hallcurrent2_getData();

/**
 * @brief Reads current in mV
 *
 * @return current value
 *
 * Max current value is +- 12,5A
 */
int16_t hallcurrent2_getCurrent();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_HallCurrent_2_STM.c
    @example Click_HallCurrent_2_TIVA.c
    @example Click_HallCurrent_2_CEC.c
    @example Click_HallCurrent_2_KINETIS.c
    @example Click_HallCurrent_2_MSP.c
    @example Click_HallCurrent_2_PIC.c
    @example Click_HallCurrent_2_PIC32.c
    @example Click_HallCurrent_2_DSPIC.c
    @example Click_HallCurrent_2_AVR.c
    @example Click_HallCurrent_2_FT90x.c
    @example Click_HallCurrent_2_STM.mbas
    @example Click_HallCurrent_2_TIVA.mbas
    @example Click_HallCurrent_2_CEC.mbas
    @example Click_HallCurrent_2_KINETIS.mbas
    @example Click_HallCurrent_2_MSP.mbas
    @example Click_HallCurrent_2_PIC.mbas
    @example Click_HallCurrent_2_PIC32.mbas
    @example Click_HallCurrent_2_DSPIC.mbas
    @example Click_HallCurrent_2_AVR.mbas
    @example Click_HallCurrent_2_FT90x.mbas
    @example Click_HallCurrent_2_STM.mpas
    @example Click_HallCurrent_2_TIVA.mpas
    @example Click_HallCurrent_2_CEC.mpas
    @example Click_HallCurrent_2_KINETIS.mpas
    @example Click_HallCurrent_2_MSP.mpas
    @example Click_HallCurrent_2_PIC.mpas
    @example Click_HallCurrent_2_PIC32.mpas
    @example Click_HallCurrent_2_DSPIC.mpas
    @example Click_HallCurrent_2_AVR.mpas
    @example Click_HallCurrent_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __hallcurrent2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */