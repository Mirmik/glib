#ifndef GENOS_ALLOCATOR_OPS
#define GENOS_ALLOCATOR_OPS

#include "defines/size_t.h"
#include "compiler.h"

__BEGIN_DECLS

struct allocator_ops
{
	void* (*allocate) (size_t);
	void (*deallocate) (void*);
	void* (*reallocate) (void*, size_t sz);
};

typedef struct allocator_ops alloc_ops;

extern struct allocator_ops malloc_ops;
extern struct allocator_ops ctrl_malloc_ops;

__END_DECLS

#endif