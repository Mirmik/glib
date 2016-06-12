#include "mem/allocator.h"
#include "stdlib.h"

struct allocator_ops malloc_ops = {malloc, free};