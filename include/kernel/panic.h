#ifndef KERNEL_PANIC_H
#define KERNEL_PANIC_H

#include "debug/dprint.h"

#include <hal/arch.h>
#include <hal/ipl.h>
//#include <kernel/printk.h>
//#include <debug/whereami.h>
#include "util/location.h"

#define panic(...) 									\
	do { 											\
		ipl_disable();								\
		debug_print_location(current_location());	\
		arch_shutdown(ARCH_SHUTDOWN_MODE_HALT);		\
	} while (0)

#endif