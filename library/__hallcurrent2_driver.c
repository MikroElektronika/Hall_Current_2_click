/*
    __hallcurrent2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__hallcurrent2_driver.h"
#include "__hallcurrent2_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HALLCURRENT2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HALLCURRENT2_DRV_SPI__

void hallcurrent2_spiDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HALLCURRENT2_DRV_I2C__

void hallcurrent2_i2cDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HALLCURRENT2_DRV_UART__

void hallcurrent2_uartDriverInit(T_HALLCURRENT2_P gpioObj, T_HALLCURRENT2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void hallcurrent2_gpioDriverInit(T_HALLCURRENT2_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void hallcurrent2_reset()
{
    hal_gpio_rstSet(0);
    Delay_10ms();
    hal_gpio_rstSet(1);
    Delay_100ms();
    hal_gpio_rstSet(0);
}

int16_t hallcurrent2_getData()
{
    uint8_t writeReg[1];
    uint8_t readReg[2];
    int16_t dataValue;
    writeReg[0] = 0x00;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART );
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP );
    
    dataValue = readReg[0];
    dataValue = dataValue << 8;
    dataValue = dataValue | readReg[1];
    dataValue = dataValue & 0x0FFF;
    
    return dataValue;
}

int16_t hallcurrent2_getCurrent()
{
    int16_t Current;
    int16_t CurrentData;
    
    Current = hallcurrent2_getData();
    
    CurrentData = Current - 2047;
    CurrentData *= 100;
    CurrentData = (CurrentData / 136) * 10;
    
    return CurrentData;
}





/* -------------------------------------------------------------------------- */
/*
  __hallcurrent2_driver.c

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