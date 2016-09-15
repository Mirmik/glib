#include <kernel/csection.h>
#include <kernel/irq.h>

namespace Kernel {

	ipl_t enter_critical_section() {
		if (!is_interrupt_context()) {
			return ipl_save();
		}
	}

	void leave_critical_section(ipl_t save) {
		if (!is_interrupt_context()) {
			ipl_restore(save);
			return;
		}
	}

};