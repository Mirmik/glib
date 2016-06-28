#ifndef GENOS_GPIO_H
#define GENOS_GPIO_H

#include "compiler.h"
#include "periph/gpio.h"

__BEGIN_DECLS

void gpio_set_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level);
gpio_mask_t gpio_get_level(struct gpio* gpio, gpio_mask_t mask, unsigned char level);
void gpio_tgl_level(struct gpio* gpio, gpio_mask_t mask);

__END_DECLS

#endif