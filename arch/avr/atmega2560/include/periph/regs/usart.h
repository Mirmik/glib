#ifndef AVR2560_USART_H
#define AVR2560_USART_H

#include <hal/reg.h>
#include <kernel/irq.h>

struct usart_regs {
	reg_t ucsr_a;
	reg_t ucsr_b;
	reg_t ucsr_c;
	reg_t reserve0;
	reg_t ubrr_l;
	reg_t ubrr_h;
	reg_t udr;
} __attribute__((packed));

struct usart_irq_nums {
	uint8_t tx;
	uint8_t rx;
	uint8_t udre;
};

#define USART_BASE_0 0xC0
#define USART_BASE_1 0xC8
#define USART_BASE_2 0xD0

#define USART0 ((volatile struct usart_regs *)(USART_BASE_0))
#define USART1 ((volatile struct usart_regs *)(USART_BASE_1))
#define USART2 ((volatile struct usart_regs *)(USART_BASE_2))

const struct usart_irq_nums USART0_IRQS = {.tx = ATMEGA_IRQ_U0TX, .rx = ATMEGA_IRQ_U0RX, .udre = ATMEGA_IRQ_U0DRE};
const struct usart_irq_nums USART1_IRQS = {.tx = ATMEGA_IRQ_U1TX, .rx = ATMEGA_IRQ_U1RX, .udre = ATMEGA_IRQ_U1DRE};
const struct usart_irq_nums USART2_IRQS = {.tx = ATMEGA_IRQ_U2TX, .rx = ATMEGA_IRQ_U2RX, .udre = ATMEGA_IRQ_U2DRE};

#endif 