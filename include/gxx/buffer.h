#ifndef GENOS_UTILXX_BUFFER_H
#define GENOS_UTILXX_BUFFER_H

#include "stdint.h"
#include "defines/size_t.h"
#include <string.h>
#include <assert.h>
#include <mem/sysalloc.h>
#include <genos/serialization.h>

namespace gxx {

class buffer {
private:
	void* _data;
	uint16_t _size;

public:
	buffer(const void* __data, size_t __size)
		: _data((void*)__data), _size(__size) {};
	
	void* data() const {
		return _data;
	}

	size_t size()  const {
		return _size;
	}

	size_t serialization(char* ptr, size_t maxlen) const {
		size_t off = 0;
		off += ::serialization(ptr + off, _size, maxlen - off);
		off += __serialization(ptr + off, _data, _size, maxlen - off);
	}

	size_t deserialization(char* ptr, size_t maxlen) {
		size_t off = 0;
		off += ::deserialization(ptr + off, _size, maxlen - off);
		off += __deserialization(ptr + off, _data, _size, maxlen - off);
	}

	size_t serialSize() {
		return sizeof(uint16_t) + _size; 
	}

	static size_t deserialSize(char* ptr) {
		uint16_t sz;
		::deserialization(ptr, sz, sizeof(uint16_t));
		return sz + sizeof(uint16_t); 
	}
};
/*
class alocated_buffer : public buffer {
public:
	void* _data;
	size_t _size;

	alocated_buffer(size_t __size) 
		: buffer(sysalloc(__size), __size) {}

	~alocated_buffer() {
		sysfree(_data);
	}

	void reserve (size_t newsize) {
		_data = sysrealloc(_data, newsize);
	}
};
*/
void buffer_fill(const buffer& buffer, char c);

};

#endif 