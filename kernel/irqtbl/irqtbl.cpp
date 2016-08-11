#include "kernel/irq/irq.h"
#include "util/stub.h"

irq_record irqtbl[IRQS_TOTAL];

static const char* nonameirq = "NoNameIRQ";

void irqtbl_init() {
	for(irq_record& rec : irqtbl) {
		rec.name = nonameirq;
		rec.count = 0;
		rec.handler = do_nothing;
	}
}