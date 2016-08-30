#ifndef GENOS_IRQ_H
#define GENOS_IRQ_H

#include <asm/irq.h>
#include <inttypes.h>
#include <compiler.h>

struct irq_record {
	const char* name;
	uint16_t count;
	void(*handler)();
};

extern struct irq_record irqtable[IRQS_TOTAL];

__BEGIN_DECLS

void irqtable_init();

__END_DECLS

#endif