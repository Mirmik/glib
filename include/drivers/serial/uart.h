#ifndef DRIVERS_USART_H
#define DRIVERS_USART_H

#include <drivers/chardev.h>

enum {
	UART_PARITY_NONE,
	UART_PARITY_EVEN,
	UART_PARITY_ODD,
};

struct UartParams {
	uint32_t baud_rate = 9600;
	uint8_t parity = UART_PARITY_NONE;
	uint8_t n_stop = 1;
	uint8_t n_bits = 8;
};

class Uart : public CharDevice {

	virtual void settings(const UartParams& params) = 0;

};

#endif