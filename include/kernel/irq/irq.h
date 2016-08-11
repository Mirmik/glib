#ifndef GENOS_IRQ_H
#define GENOS_IRQ_H

#include <asm/irq.h>
#include <inttypes.h>

struct irq_record {
	const char* name;
	uint16_t count;
	void(*handler)();
};

extern irq_record irqtbl[IRQS_TOTAL];

void irqtbl_init();
void irq_set_name(const char* name);

#endif