#include "kernel/irq.h"
#include "debug/dprint.h"

void do_irq(uint8_t irq) {
	debug_print("do_irq\r\n");
	struct irq_record* record = &irqtable[irq];
	++record->count;
	record->handler();
}