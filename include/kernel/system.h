#ifndef GENOS_KERNEL_SYSTEM_H
#define GENOS_KERNEL_SYSTEM_H

#include "compiler.h"

__BEGIN_DECLS

void cxx_invoke_constructors(void);
void end_of_programm(void);
void __do_global_ctors(void);

__END_DECLS

#endif 