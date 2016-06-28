#include "util/bits.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "hal/arch.h"
#include "kernel/diag.h"
#include "kernel/panic.h"

//#include "genos/time/sysclock.h"

//#include "asm/Serial.h"
//#include "cpu/usart_control_struct.h"
//#include "util/stub.h"

extern struct diag_ops usart0_diag;
//extern volatile int64_t supertick;

int interrupt_checker();
void arch_init()
{
	//bits_set(TCCR0B, _BV(CS01) | _BV(CS00));
//	set_clock_param(F_CPU, 256 * 64, 256);
	//bits_set(TIMSK0, _BV(TOIE0));

	current_diag = &usart0_diag;

	//if (interrupt_checker() == 0) error_stub();	
	archxx_init();
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

ISR(__vector_default)
{
	panic("_default_vector");
	while(1);
};
