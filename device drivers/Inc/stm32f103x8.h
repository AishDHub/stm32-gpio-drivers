#ifndef STM32F103X8_H
#define STM32F103X8_H

#include <stdint.h>

/*Macros related to all peripherals address,sram,flash
 * Data structures related to peripherals
 * Peripherals bit definition*/

#define FLASH_BASEADDR          0x08000000U
#define FLASH_ENDADDR           0x0801FFFFU
#define SYSTEM_BASEADDR         0x1FFFF000U
#define OPTBYTE_BASEADDR        0x1FFFF800U
#define SRAM_BASEADDR           0x20000000U
#define SRAM_ENDADDR            0x20004FFFU

/*APB & AHB peripherals*/

#define APB1PERIPH_BASEADDR     0x40000000U
#define APB2PERIPH_BASEADDR     0x40010000U
#define AHBPERIPH_BASEADDR      0x40018000U

/*RCC peripherals address*/

#define RCC_BASEADDR            0x40021000U


/*GPIO peripheral address*/

#define GPIOA_BASEADDR          (APB2PERIPH_BASEADDR + 0X0800)
#define GPIOB_BASEADDR          (APB2PERIPH_BASEADDR + 0X0C00)
#define GPIOC_BASEADDR          (APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR          (APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR          (APB2PERIPH_BASEADDR + 0x1800)

/*GPIO structure definitions*/

typedef struct{


	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;


} GPIO_regdef;

/*RCC structure definitions*/

typedef struct{

	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_regdef;

/*GPIO structure Macros for easier accessing like GPIOA -> ODR = 1 means it can directly access GPIOA's ODR address with the help of these type casting of the base address with the structure variable*/

#define GPIOA   ((GPIO_regdef*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_regdef*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_regdef*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_regdef*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_regdef*)GPIOE_BASEADDR)

/* RCC pointer to structure Macros accessing can be like RCC -> CFGR = 1 */

#define RCC     ((RCC_regdef*)RCC_BASEADDR)


#endif
