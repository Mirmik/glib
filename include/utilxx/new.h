#ifndef PLACEMENT_NEW_H
#define PLACEMENT_NEW_H

#include "defines/size_t.h"

void * operator new(size_t, void *ptr);
void * operator new(size_t);
void operator delete(void*);

//template<typename Allocator> void * operator new(size_t, Allocator& alloc);
//template<typename Allocator> void operator delete(void*, Allocator& alloc);

#endif