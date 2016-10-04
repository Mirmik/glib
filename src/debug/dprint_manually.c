#include "debug/dprint.h"

//debug_putchar реализуется в основной программе.
	
void debug_write(const char*c, int i)
{
	while(i--) 
		debug_putchar(*c++);
};
	