#ifndef GENOS_DRIVERS_UART_DEVICE_H
#define GENOS_DRIVERS_UART_DEVICE_H

#include "inttypes.h"

struct uart;

enum uart_parity {
	UART_EVEN,UART_ODD,UART_NONE
};

struct uart_params {
	uint32_t baud_rate;
	uint8_t parity;
	uint8_t n_stop;
	uint8_t n_bits;
};

struct uart_ops {
	int (*uart_getc)(struct uart *dev);
	int (*uart_putc)(struct uart *dev, int symbol);
	int (*uart_hasrx)(struct uart *dev);
	int (*uart_maytx)(struct uart *dev);
	int (*uart_setup)(struct uart *dev, const struct uart_params *params);
};

struct uart_irqops
{
	void(*uart_rx)(struct uart *dev);
	void(*uart_tx)(struct uart *dev);
	void(*uart_tx_empty)(struct uart *dev);
};

struct uart {
	const struct uart_ops *uart_ops;
	struct uart_irqops* uart_irqops;
	void* private_data;
};

#endif

