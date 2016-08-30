#ifndef AVR2560_USART_H
#define AVR2560_USART_H

#include <hal/reg.h>

struct uart_regs {
	reg_t udr;
	reg_t ubbr_h;
	reg_t ubbr_l;
	reg_t reserve0;
	reg_t ucsr_c;
	reg_t ucsr_b;
	reg_t ucsr_a;
} __attribute__((packed));

#define USART_BASE_0 0xC6
#define USART_BASE_1 0xCE
#define USART_BASE_2 0xD6

#define USART0 ((volatile struct uart_regs *)(USART_BASE_0))
#define USART1 ((volatile struct uart_regs *)(USART_BASE_1))
#define USART2 ((volatile struct uart_regs *)(USART_BASE_2))

#endif 