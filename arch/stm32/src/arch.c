#include <hal/arch.h>
#include <hal/ipl.h>

#include <kernel/diag.h>

extern struct diag_ops diag_operations; 
void diag_operations_init();
void diag_operations_putchar();

void arch_init() {
	diag_operations.init = diag_operations_init;
	diag_operations.putc = diag_operations_putchar;
	diag_operations.write = diag_write_stub;
	current_diag = &diag_operations;

	diag_init();
}

void arch_shutdown(arch_shutdown_mode_t mode) {
	switch(mode)
	{
		case ARCH_SHUTDOWN_MODE_HALT:
		break;
		case ARCH_SHUTDOWN_MODE_REBOOT:
		break;
		case ARCH_SHUTDOWN_MODE_ABORT:
		break;
	};
	ipl_disable();
	while(1);
}