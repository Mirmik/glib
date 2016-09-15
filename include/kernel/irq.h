#ifndef GENOS_IRQ_H
#define GENOS_IRQ_H

#include <asm/irq.h>
#include <inttypes.h>
#include <genos/sigslot/delegate.h>
#include <kernel/panic.h>

namespace Kernel {

	typedef fastdelegate<void> IRQHandler;

	static void error_handler(void* irqno) {
		dpr((int)irqno);
		panic(" error_handler");
	}

	class IRQTableClass {

		struct record {
			volatile IRQHandler handler;
			volatile uint16_t count;
		};

	public:
		record table[IRQS_TOTAL];

	public:
		inline void setHandler(int irqno, const IRQHandler& handler) {
			table[irqno].handler = handler;
		}

		inline void init() {
			for (int i = 0; i < IRQS_TOTAL; i++) {
				table[i].handler = IRQHandler(error_handler, (void*)i);
			}
		}

		inline void execute(uint8_t irqno) {
			table[irqno].count++;
			table[irqno].handler();
		}
	};

	extern IRQTableClass IRQTable;

};

extern "C" void do_irq(uint8_t irq) __attribute__((section(".handlers")));
extern "C" bool is_interrupt_context();

#endif