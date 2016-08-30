#include "kernel/irq.h"
#include "util/stub.h"

struct irq_record irqtable[IRQS_TOTAL];

static const char* nonameirq = "NoNameIRQ";

void irqtable_init() {
	for(int i = 0; i < IRQS_TOTAL; ++i) {
		irqtable[i].name = nonameirq;
		irqtable[i].count = 0;
		irqtable[i].handler = do_nothing;
	}
}