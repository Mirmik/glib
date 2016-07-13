#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "genos/datastruct/dynbuf.h"
#include "mem/allocator.h"
#include "defines/size_t.h"

template<typename type>
class dynarray {
	dynbuf dbuf;
	size_t cappacity;

	dynarray() { 
		dynbuf_init(&dbuf);
		cappacity = 0; 
	}

	void reserve(size_t dim) {
		dynbuf_reserve(&dbuf, &malloc_ops, sizeof(type) * dim);
		cappacity = dim;
	}

	type& operator[](int i) {
		dynbuf_get(&dbuf,type,i);
	};
};

#endif