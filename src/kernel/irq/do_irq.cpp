#include "kernel/irq.h"
#include "debug/dprint.h"

namespace Kernel {

	unsigned char __interrupt_context = 0;

	void do_irq(uint8_t irq) {
		__interrupt_context++;
		Kernel::IRQTable[irq].count++;
		Kernel::IRQTable[irq].handler(Kernel::IRQTable[irq].argument);
		__interrupt_context--;
	}

	unsigned char is_interrupt_context() {
		return __interrupt_context;
	}

}