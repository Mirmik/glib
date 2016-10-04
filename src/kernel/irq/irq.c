#include <kernel/irq.h>
#include <util/stub.h>

struct IRQTableRecord IRQTable[IRQS_TOTAL];

void irqtable_init() {
	for (int i = 0; i < IRQS_TOTAL; ++i) {
		IRQTable[i].handler = do_nothing;
		IRQTable[i].argument = 0;
	}
};

void setIRQHandler(int irqno, IRQHandler handler, void* arg) {
	IRQTable[irqno].handler = handler;
	IRQTable[irqno].argument = arg;
};
