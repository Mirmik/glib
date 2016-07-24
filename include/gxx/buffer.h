#ifndef GENOS_UTILXX_BUFFER_H
#define GENOS_UTILXX_BUFFER_H

#include "stdint.h"
#include "defines/size_t.h"
#include <assert.h>

namespace gxx {

class buffer
{
public:
	char* data;
	size_t size;

public:
	buffer(char* ptr, size_t len) 
		: data(ptr), size(len) {};


	buffer() 
		: data(nullptr), size(0) {};

	void invalidate() {
		data = nullptr;
		size = 0;
	}

	bool is_valid() {
		return data;
	}

	void set(char* _data, size_t _size) {
		data = _data;
		size = _size;
	}

	template < typename CharAllocator >
	void allocate(size_t sz) {
		assert(data == nullptr);
		CharAllocator alloc;
		data = alloc.allocate(sz);
		size = sz;
	}

	template < typename CharAllocator >
	void reallocate(size_t sz) {
		CharAllocator alloc;
		data = alloc.reallocate(data, sz);
		size = sz;
	}
};

};

#endif 