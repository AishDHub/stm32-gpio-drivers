#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_C

#include <stm32f103x8.h>

/* for CRL and CRH */
typedef enum{

	GPIO_ANALOG_INPUT_MODE = 0x00,
	GPIO_FLOATING_INPUT_MODE = 0x04,
	GPIO_PUPD_INPUT_MODE = 0x08,

	GPIO_OUT_PUPL_MODE_10 = 0x01,
	GPIO_OUT_PUPL_MODE_2 =  0x02,
	GPIO_OUT_PUPL_MODE_50 = 0x03,

	GPIO_OUT_OPDIN_MODE_10 = 0x05,
	GPIO_OUT_OPDIN_MODE_2 = 0x06,
	GPIO_OUT_OPDIN_MODE_50 = 0x07,

	GPIO_AF_PP_OUT_MODE_10 = 0x09,
	GPIO_AF_PP_OUT_MODE_2 = 0xA,
	GPIO_AF_PP_OUT_MODE_50 = 0xB,

	GPIO_AF_OD_OUT_MODE_10 = 0xD,
	GPIO_AF_OD_OUT_MODE_2 = 0xE,
	GPIO_AF_OD_OUT_MODE_50 = 0xF

}GPIO_MODE_T;

/*to set or reset pin state*/
typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1
} GPIO_PinState;

/*structure for a GPIO pin*/
typedef struct{

	uint8_t pin;
	GPIO_MODE_T mode;
	uint8_t alternatefunc;

}GPIO_PINCONFIG_T;

/*function declaration*/

void GPIO_Init(GPIO_regdef *port,GPIO_PINCONFIG_T* PinConfig);
void GPIO_Deinit(GPIO_regdef *port,GPIO_PINCONFIG_T* PinConfig);

void GPIO_TogglePin(GPIO_regdef* port,uint8_t pin);
void GPIO_SetPin(GPIO_regdef* port,uint8_t pin);
uint8_t GPIO_ReadPin(GPIO_regdef* port,uint8_t pin);
void GPIO_Write_Port(GPIO_regdef* port,uint32_t portVal);
uint8_t GPIO_Read_Port(GPIO_regdef* port);
void GPIO_Lock(GPIO_regdef* port,uint8_t pin);


#endif
