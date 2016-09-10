#include "kernel/irq.h"
#include "debug/dprint.h"

bool __interrupt_context = false;

void do_irq(uint8_t irq) {
	__interrupt_context = true;
	Kernel::IRQTable.execute(irq);
	__interrupt_context = false;
}

bool is_interrupt_context() {
	return __interrupt_context;
}