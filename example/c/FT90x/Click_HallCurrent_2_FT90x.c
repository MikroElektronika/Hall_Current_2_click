/*
Example for HallCurrent_2 Click

    Date          : Feb 2018.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module and INT pin as INPUT and RST pin as OUTPUT
- Application Initialization - Initializes Driver init and reset chip
- Application Task - (code snippet) - Reads current and logs on usbuart every 1 second.
                                      It was tested with 1V voltage at the input and with a load of 1 - 2A.
*/

#include "Click_HallCurrent_2_types.h"
#include "Click_HallCurrent_2_config.h"

char text[256];
int16_t CurrentData;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT2_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    
    mikrobus_logWrite("--- System Init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
     hallcurrent2_i2cDriverInit( (T_HALLCURRENT2_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT2_P)&_MIKROBUS1_I2C, 0x4D );
     hallcurrent2_reset();
}

void applicationTask()
{
    CurrentData = hallcurrent2_getCurrent();
    IntToStr(CurrentData, text);
    mikrobus_logWrite("--- Current :", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_TEXT);
    mikrobus_logWrite(" mA", _LOG_LINE);
    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}