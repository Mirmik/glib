#ifndef GENOS_UTILXX_BUFFER_H
#define GENOS_UTILXX_BUFFER_H

#include "stdint.h"
#include "defines/size_t.h"
#include <string.h>
#include <assert.h>
#include <mem/sysalloc.h>

namespace gxx {

class buffer {
private:
	void* _data;
	size_t _size;

public:
	buffer(void* __data, size_t __size)
		: _data(__data), _size(__size) {};
	
	void* data() const {
		return _data;
	}

	size_t size()  const {
		return _size;
	}
};

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

void buffer_fill(const buffer& buffer, char c);

};

#endif 