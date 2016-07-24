#include <utilxx/new.h>
#include <mem/sysalloc.h>

void * operator new(size_t, void *ptr) {
	return ptr;
};

void * operator new(size_t sz) {
	return sysalloc(sz);
};

void operator delete(void* ptr) {
	return sysfree(ptr);
};