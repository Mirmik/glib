#include <kernel/diag.h>
#include <drivers/gpio.h>

#include <periph/map.h>

void diag_operations_init() {
}

void diag_operations_putchar() {
	gpio_set_level(GPIOD, 1 << 14, 1);	
}

struct diag_ops diag_operations;
