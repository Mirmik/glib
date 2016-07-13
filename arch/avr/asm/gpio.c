#include "drivers/gpio.h"

#include "debug/dprint.h"

void gpio_set_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level) {
	if (level) gpio->port |= mask;
	else gpio->port &= ~mask;	
}

gpio_mask_t gpio_get_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level) {
	return gpio->pin;
}

void gpio_tgl_level(struct gpio* gpio, gpio_mask_t mask) {
	gpio->pin = mask;
}

int gpio_settings(struct gpio *gpio, gpio_mask_t mask, int32_t mode) {
	if ((mode & GPIO_MODE_OUT_SECTION) &&
		(mode & GPIO_MODE_IN_SECTION)) { /* mode is incorrect */
		return -1;
	}
	
	if (mode & GPIO_MODE_INPUT) {
		gpio->ddr &= ~mask; 
	};

	if (mode & GPIO_MODE_OUTPUT) {
		gpio->ddr |= mask;		
	};
};
