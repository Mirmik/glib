#ifndef GENOS_KERNEL_CSECTION_H
#define GENOS_KERNEL_CSECTION_H

#include <hal/ipl.h>

namespace Kernel {

	ipl_t enter_critical_section();
	void leave_critical_section(ipl_t);

};

#endif