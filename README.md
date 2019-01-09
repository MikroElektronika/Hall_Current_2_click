![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# HallCurrent_2 Click

- **CIC Prefix**  : HALLCURRENT2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Feb 2018.

---

### Software Support

We provide a library for the Hall Current 2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2354/hall-current-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library provides basic functionality for reading the current value and controlling the click board.

Key functions :

- ```void hallcurrent2_reset();``` - Function for reseting the click board sensor. 
- ```int16_t hallcurrent2_getData();``` - Function that returns the 12bit digital value.
- ```int16_t hallcurrent2_getCurrent();``` - Function that returns the current value.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module and INT pin as INPUT and RST pin as OUTPUT
- Application Initialization - Initializes Driver init and reset chip
- Application Task - (code snippet) - Reads current and logs on usbuart every 1 second.
                                      It was tested with 1V voltage at the input and with a load of 1 - 2A.


```
void applicationTask()
{
    CurrentData = hallcurrent2_getCurrent();
    IntToStr(CurrentData, text);
    mikrobus_logWrite("--- Current :", _LOG_TEXT);
    mikrobus_logWrite(text, _LOG_TEXT);
    mikrobus_logWrite(" mA", _LOG_LINE);
    Delay_ms( 1000 );
}
```

${EXAMPLE_ADDITIONAL_FUNCTIONS}

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2354/hall-current-2-click) page.

Other mikroE Libraries used in the example:

- UART Library
- Conversions Library 
- C_String Library
- I2C Library

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
