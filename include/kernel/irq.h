#ifndef GENOS_IRQ_H
#define GENOS_IRQ_H

#include <compiler.h>
#include <kernel/panic.h>
#include <inttypes.h>

#include <arch/irq.h>

namespace Kernel {

	using IRQHandler = void(*)(void*);

	struct IRQTableRecord {
		IRQHandler 	handler;
		void* 		argument;
		volatile uint16_t count;
	};

	extern struct IRQTableRecord IRQTable[IRQS_TOTAL];

	void do_irq(uint8_t irq) __attribute__((section(".handlers")));
	unsigned char is_interrupt_context();

	void irqtable_init();

	void setIRQHandler(int irqno, IRQHandler handler, void* arg);

};

#endif