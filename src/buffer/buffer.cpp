#include <gxx/buffer.h>
#include <string.h>

void gxx::buffer_fill(const buffer& buffer, char c) {
	memset(buffer.data(), c, buffer.size());
};