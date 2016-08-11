#ifndef GENOS_GQ_BYTE_ARRAY_H
#define GENOS_GQ_BYTE_ARRAY_H

#include <gQ/gQByteAllocated.h>
#include <gQ/gQTraits.h>
#include <gxx/utility.h>
#include <gxx/algorithm.h>
#include <debug/dprint.h>

#include <string.h>
#include <assert.h>

class gQByteArray : public gQRefAllocatedArray<uint8_t> {
public:
	gQByteArray() : gQRefAllocatedArray<uint8_t>() {};
	gQByteArray(const gQByteArray& other) : gQRefAllocatedArray<uint8_t>(other) {};
	gQByteArray(gQByteArray&& other) : gQRefAllocatedArray<uint8_t>(gxx::forward<gQByteArray>(other)) {};

	gQByteArray(const char* str, size_t sz) : gQRefAllocatedArray<uint8_t>() {
		resize(sz);
		memcpy(getBuffer(), str, sz);
	}
};

#endif