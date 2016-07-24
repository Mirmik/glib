#ifndef DEBUG_WRITER
#define DEBUG_WRITER

#include <kernel/diag.h>
#include <gxx/stream/writer.h>

class DebugWriter : public gxx::writer {
public:
	int putc(const char c) {
		return diag_putc(c);
	};

	int write(const char* str, size_t sz) {
		return diag_write(str, sz);
	};

	int room() {
		return 0xFFFF;
	};

	DebugWriter(){};
};

static inline DebugWriter dwriter() {
	return DebugWriter();
}

#endif