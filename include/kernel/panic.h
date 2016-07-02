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
		debug_print("kernel panic:"); dln();		\
		debug_print_location(current_location()); 	\
		debug_print("message: ");					\
		debug_print(__VA_ARGS__);					\
		dln();										\
		arch_shutdown(ARCH_SHUTDOWN_MODE_HALT);		\
	} while (0)

#endif