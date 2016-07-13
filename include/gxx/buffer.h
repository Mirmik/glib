#ifndef GENOS_UTILXX_BUFFER_H
#define GENOS_UTILXX_BUFFER_H

#include "stdint.h"
#include "defines/size_t.h"

namespace gxx {

class buffer
{
private:
	char* _data;
	size_t _length;
	size_t* _length_ptr;

public:
	buffer(const char* ptr, size_t len) 
		: _data((char*)ptr), _length(len), _length_ptr(nullptr) {};

	buffer(const char* ptr, size_t* lenptr) 
		: _data((char*)ptr), _length(*lenptr), _length_ptr(lenptr) {};

	inline char* data() const
	{
		return _data;
	}

	inline size_t length() const
	{
		return _length;
	}

	inline void length(size_t sz)
	{
		if (_length_ptr) *_length_ptr = sz; 
		_length = sz;
	}
};

};

#endif 