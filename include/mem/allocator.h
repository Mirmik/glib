#ifndef GENOS_ALLOCATOR_OPS
#define GENOS_ALLOCATOR_OPS

#include "compiler.h"

__BEGIN_DECLS

struct allocator_ops
{
	void* (*allocate) (size_t);
	void (*deallocata) (void*);
};

extern struct allocator_ops malloc_ops;

__END_DECLS

#endif