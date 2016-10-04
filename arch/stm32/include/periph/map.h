#ifndef GENOS_STM32F407_REGS_MAP
#define GENOS_STM32F407_REGS_MAP

#include <periph/regs/gpio.h>

#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH(up to 1 MB) base address in the alias region                         */
#define CCMDATARAM_BASE       ((uint32_t)0x10000000) /*!< CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE            ((uint32_t)0x20000000) /*!< SRAM1(112 KB) base address in the alias region                             */
#define SRAM2_BASE            ((uint32_t)0x2001C000) /*!< SRAM2(16 KB) base address in the alias region                              */
#define SRAM3_BASE            ((uint32_t)0x20020000) /*!< SRAM3(64 KB) base address in the alias region                              */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE          ((uint32_t)0x40024000) /*!< Backup SRAM(4 KB) base address in the alias region                         */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)

/*GPIO base*/
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000)
#define GPIOJ_BASE            (AHB1PERIPH_BASE + 0x2400)
#define GPIOK_BASE            (AHB1PERIPH_BASE + 0x2800)

#define GPIOA ((struct gpio_regs *) GPIOA_BASE)
#define GPIOB ((struct gpio_regs *) GPIOB_BASE)
#define GPIOC ((struct gpio_regs *) GPIOC_BASE)
#define GPIOD ((struct gpio_regs *) GPIOD_BASE)
#define GPIOE ((struct gpio_regs *) GPIOE_BASE)
#define GPIOF ((struct gpio_regs *) GPIOF_BASE)
#define GPIOG ((struct gpio_regs *) GPIOG_BASE)
#define GPIOH ((struct gpio_regs *) GPIOH_BASE)
#define GPIOI ((struct gpio_regs *) GPIOI_BASE)
#define GPIOJ ((struct gpio_regs *) GPIOJ_BASE)
#define GPIOK ((struct gpio_regs *) GPIOK_BASE)

#define RCC_BASE        0x40023800
#define RCC_AHB1ENR     (volatile uint32_t*)(RCC_BASE + 0x30) 

#endif