/* crti.c for ARM - BPABI - use -std=c99 */
typedef void (*func_ptr)(void);
 
extern func_ptr _ctors_start[0], _ctors_end[0];
 
void cxx_invoke_constructors(void)
{
	for ( func_ptr* func = _ctors_start; func != _ctors_end; func++ )
		(*func)();
}
 
func_ptr _ctors_start[0] __attribute__ ((used, section(".ctors"), aligned(sizeof(func_ptr)))) = { };
