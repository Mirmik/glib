#include "util/bits.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "hal/arch.h"
#include "kernel/diag.h"
#include "kernel/panic.h"
#include "kernel/irq.h"

extern struct diag_ops usart0_diag;

int usart0_diag_init();
int usart0_diag_putchar(char c);

void arch_init() {
	
	irqtable_init();

	//bits_set(TCCR0B, _BV(CS01) | _BV(CS00));
	//set_clock_param(F_CPU, 256 * 64, 256);
	//bits_set(TIMSK0, _BV(TOIE0));

	usart0_diag.init = usart0_diag_init;
	usart0_diag.putc = usart0_diag_putchar;
	usart0_diag.write = diag_write_stub;
	current_diag = &usart0_diag;



}

void arch_idle()
{
	
}

void arch_shutdown(arch_shutdown_mode_t mode){
	switch(mode)
	{
		case ARCH_SHUTDOWN_MODE_HALT:
		break;
		case ARCH_SHUTDOWN_MODE_REBOOT:
		break;
		case ARCH_SHUTDOWN_MODE_ABORT:
		break;
	};
	cli();
	while(1);
}