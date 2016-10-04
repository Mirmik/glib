#ifndef DRIVERS_USART_H
#define DRIVERS_USART_H

//#include <drivers/chardev.h>

struct uart_driver;

struct uart_ops {
	int (*putc)(struct uart_driver* dev, char c);
	int (*getc)(struct uart_driver* dev);
	int (*init)(struct uart_driver* dev);
};

struct uart_driver {
	struct uart_ops* ops;
	void* priv;
};

#define uart_init(uart) (uart)->ops->init(uart)
#define uart_getc(uart) (uart)->ops->getc(uart)
#define uart_putc(uart,c) (uart)->ops->putc(uart,c)

/*enum {
	UART_PARITY_NONE,
	UART_PARITY_EVEN,
	UART_PARITY_ODD,
};



class Uart : public UartDeviceDriver {
	virtual void settings(const UartParams& params) = 0;
};*/

#endif