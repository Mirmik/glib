#include "kernel/panic.h"
#include "debug/dprint.h"

void end_of_programm() {
	debug_print("PROGRAMM_END");
	arch_shutdown(ARCH_SHUTDOWN_MODE_ABORT);
};