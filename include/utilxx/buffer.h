#ifndef GENOS_UTILXX_BUFFER_H
#define GENOS_UTILXX_BUFFER_H

#include "stdint.h"

namespace gxx {

class buffer
{
	char* data;
	size_t length;

	buffer(const char* ptr, size_t len) : data((char*)ptr), length(len) {};
};

};

#endif 