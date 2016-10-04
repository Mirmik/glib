#include "drivers/gpio.h"
#include "debug/dprint.h"

void gpio_set_level(struct gpio_regs* g, gpio_mask_t mask, unsigned char level) {
	if (level) g->ODR |= mask;
	else g->ODR &= ~mask;	
}

gpio_mask_t gpio_get_level(struct gpio_regs* g, gpio_mask_t mask, unsigned char level) {
	return g->ODR & mask;
}

void gpio_tgl_level(struct gpio_regs* g, gpio_mask_t mask) {
//	g->pin = mask;
}

int gpio_settings(struct gpio_regs* g, gpio_mask_t mask, int32_t mode) {
	if ((mode & GPIO_MODE_OUT_SECTION) &&
		(mode & GPIO_MODE_IN_SECTION)) { /* mode is incorrect */
		return -1;
	}
	
	uint8_t bit;
	uint32_t nmoder = 0;
	while(mask) {
		bit = __builtin_ctz(mask);
		nmoder |= (1 << (bit*2));
		mask &= ~(1 << bit);
	}

	if (mode & GPIO_MODE_INPUT) {
		g->MODER &= ~nmoder; 
		return 0;
	};

	if (mode & GPIO_MODE_OUTPUT) {
		g->MODER |= nmoder;		
		return 0;
	};
};
