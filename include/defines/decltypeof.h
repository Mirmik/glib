//Макрос decltypeof имитирует поведение typeof в С/С++ коде.
//Он используется в заголовочных файлах, которые одновременно могут 
//подключаться  как из С кода, так и из С++ кода.
//Макрос должен максимально повторять поведение typeof в С++ варианте.

#include <sys/cdefs.h>


#if __c_plusplus
#include <genos/gstl/utility.h>
#define decltypeof(a) typename gstd::remove_reference<decltype(a)>::type
#else
#define decltypeof(a) typeof(a)
#endif