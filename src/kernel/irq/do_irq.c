#include "kernel/irq.h"
#include "debug/dprint.h"

unsigned char __interrupt_context = 0;

void do_irq(uint8_t irq) {
	__interrupt_context = 1;
	IRQTable[irq].count++;
	IRQTable[irq].handler(IRQTable[irq].argument);
	__interrupt_context = 0;
}

unsigned char is_interrupt_context() {
	return __interrupt_context;
}