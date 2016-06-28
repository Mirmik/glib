#include "drivers/gpio.h"

#include "debug/dprint.h"

void gpio_set_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level)
{
	if (level) gpio->port |= mask;
	else gpio->port &= ~mask;	
}

gpio_mask_t gpio_get_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level)
{
	return gpio->pin;
}

void gpio_tgl_level(struct gpio* gpio, gpio_mask_t mask)
{
	gpio->pin = mask;
}
