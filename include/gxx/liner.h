#ifndef GENOS_LINER_H
#define GENOS_LINER_H

#include <defines/size_t.h>
#include <gxx/allocator.h>
#include <gxx/stream/writer.h>
#include <gxx/buffer.h>
//#include <util/math.h>

namespace gxx {

template <typename Allocator = gxx::system_allocator<char>>
class liner : public writer {
	gxx::buffer buf;
	size_t cursor;

	Allocator alloc;
public:

	liner() : buf(), cursor(0) {};

	void create_buffer(size_t sz) {
		buf.allocate<Allocator>(sz);
		cursor = 0;
	}

	void shrink_buffer() {
		buf.reallocate<Allocator>(cursor + 1);
	}

	gxx::buffer unlink_buffer() {
		gxx::buffer ret = buf;
		buf.invalidate();
		return ret;
	}

	int putc(const char c) {
		assert(buf.is_valid());
		if (room() <= 0) return 0;
		buf.data[cursor++] = c;
		return 1;
	}
	
	int write(const char* str, size_t len) {
		assert(buf.is_valid());
		size_t __room = room();
		len = min(len, __room);
		memcpy(buf.data + cursor, str, len);
		cursor = cursor + len;
		return len;
	}

	int room() {
		return buf.size - cursor;
	}
};

}

#endif