#ifndef KERNEL_PANIC
#define KERNEL_PANIC

#include "debug/dprint.h"

void panic()
{
	debug_print("AllBad");
	while(1);
}

#endif