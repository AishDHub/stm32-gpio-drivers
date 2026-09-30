#include "GPIO_driver.h"

/*This function initializes ports and pins*/
void GPIO_Init(GPIO_regdef *port,GPIO_PINCONFIG_T* PinConfig)
{

    uint8_t pin = PinConfig->pin;
    uint32_t mode_val = (uint32_t)PinConfig->mode;

    if (pin < 8)
        {
            // Calculate shift position: 4 bits per pin
            uint8_t shift = pin * 4;

            // Clear the 4 bits for this pin in CRL
            port->CRL &= ~(0x0F << shift);

            // Set the 4-bit mode configuration in CRL
            port->CRL |= (mode_val << shift);
        }
      else if(pin >= 8 && pin <= 15)
        {
            // Calculate shift position for pins 8-15 in CRH
            uint8_t shift = (pin - 8) * 4;

            // Clear the 4 bits for this pin in CRH
            port->CRH &= ~(0x0F << shift);

            // Set the 4-bit mode configuration in CRH
            port->CRH |= (mode_val << shift);
        }
}

/*This function de-initializes when the ports and pins no longer needed for use*/
void GPIO_Deinit(GPIO_regdef *port,GPIO_PINCONFIG_T* PinConfig){

	uint8_t pin = PinConfig->pin;
    uint32_t mode_val = (uint32_t)PinConfig->mode;

    if (pin < 8)
           {
               // Calculate shift position: 4 bits per pin
               uint8_t shift = pin * 4;

               // Clear the 4 bits for this pin in CRL
               port->CRL &= ~(0x0F << shift);


           }
     else if(pin >= 8 && pin <= 15)
           {
               // Calculate shift position for pins 8-15 in CRH
               uint8_t shift = (pin - 8) * 4;

               // Clear the 4 bits for this pin in CRH
               port->CRH &= ~(0x0F << shift);


           }

}

/*This function toggle pins from on to off and vice versa*/
void GPIO_TogglePin(GPIO_regdef* port,uint8_t pin){

	// Toggle bit in output data register (ODR)
	    port->ODR ^= (1 << pin);

}

/*This function set pin on or off registers writes on it*/
void GPIO_SetPin(GPIO_regdef* port,uint8_t pin){

	// Set pin using bit Set/Reset register (BSRR)
	    port->BSRR = (1 << pin);

}

/*This function reads the pins*/
uint8_t GPIO_ReadPin(GPIO_regdef* port,uint8_t pin){

	// Read bit state from Input Data Register (IDR)
	    return (uint8_t)((port->IDR >> pin) & 0x01);

}

/*This function writes on the port to on or off by registers*/
void GPIO_Write_Port(GPIO_regdef* port,uint32_t portVal){

	port->ODR |= portVal;

}

/*This function reads port*/
uint8_t GPIO_Read_Port(GPIO_regdef* port){

	return (uint8_t)(port->IDR & 0xFFFF);

}

/*This function locks the port and pin*/
void GPIO_Lock(GPIO_regdef* port,uint8_t pin){

}
