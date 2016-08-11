#include <debug/dprint.h>

typedef void (*func_ptr)(void); 
//extern func_ptr __ctors_start[0], __ctors_end[0];
extern func_ptr _ctors_start[0], _ctors_end[0];
 
void cxx_invoke_constructors(void)
{
	debug_printhex_ptr(&_ctors_start);dln();
	debug_printhex_ptr(&_ctors_end);dln();

	for ( func_ptr* func = _ctors_start; func != _ctors_end; func++ )
	{
		debug_print("ctor\r\n");
		debug_printhex_ptr(*func);dln();		
		//(*func)();
	}
}
 
/*void __do_global_ctors_aux (void) { 
	debug_printhex_ptr(&_ctors_start);dln();
	debug_printhex_ptr(&_ctors_end);dln();

	for ( func_ptr* func = _ctors_start; func != _ctors_end; func++ )
	{
		debug_print("ctor\r\n");
		(*func)();
	} 
}*/

//func_ptr _ctors_start[0] __attribute__ ((used, section(".ctors"), aligned(sizeof(func_ptr)))) = { };
//func_ptr _ctors_end[0] __attribute__ ((used, section(".ctors"), aligned(sizeof(func_ptr)))) = { };

