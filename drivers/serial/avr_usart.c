#include "hal/reg.h"
#include "drivers/serial/uart_device.h"

struct uart_regs {
	reg_t udr;
	reg_t ubbr_h;
	reg_t ubbr_l;
	reg_t reserve0;
	reg_t ucsr_c;
	reg_t ucsr_b;
	reg_t ucsr_a;
} __attribute__((packed));

int avr_uart_getc(struct uart* dev) {
	struct uart_regs* regs = dev->private_data;
}

int avr_uart_putc(struct uart* dev, int c) {
	struct uart_regs* regs = dev->private_data;
}

int avr_uart_hasrx(struct uart* dev) {
	struct uart_regs* regs = dev->private_data;
}

int avr_uart_maytx(struct uart* dev) {
	struct uart_regs* regs = dev->private_data;
}

int avr_uart_setup(struct uart* dev, const struct uart_params *params) {
	struct uart_regs* regs = dev->private_data;
}

const struct uart_ops avr_uart_ops = {
	avr_uart_getc,
	avr_uart_putc,
	avr_uart_hasrx,
	avr_uart_maytx,
	avr_uart_setup
};