#ifndef GENOS_SERIALIZATION_H
#define GENOS_SERIALIZATION_H

#include <defines/size_t.h>
#include <inttypes.h>
#include <string.h>

//serialization template
template <typename T>
size_t serialization(char* ptr, const T& ref, size_t maxlen) {
	return ref.serialization(ptr, maxlen);
}

//deserialization template
template <typename T>
size_t deserialization(char* ptr, T& ref, size_t maxlen) {
	return ref.deserialization(ptr, maxlen);
}

//serialsize template
template <typename T>
size_t serialSize(const T& ref) {
	return ref.serialSize();
}

//serialsize template
template <typename T> size_t deserialSize(char* ptr) {
	return T::deserialSize(ptr);
};

//unsigned integer type serialization
static inline size_t serialization(char* ptr, const uint8_t& ref, size_t maxlen) { 
	if (maxlen < 1) return 0; memcpy(ptr, &ref, 1); return 1;
};

static inline size_t serialization(char* ptr, const uint16_t& ref, size_t maxlen) { 
	if (maxlen < 2) return 0; memcpy(ptr, &ref, 2); return 2;
};

static inline size_t serialization(char* ptr, const uint32_t& ref, size_t maxlen) { 
	if (maxlen < 4) return 0; memcpy(ptr, &ref, 4); return 4;
};

static inline size_t serialization(char* ptr, const uint64_t& ref, size_t maxlen) { 
	if (maxlen < 8) return 0; memcpy(ptr, &ref, 8); return 8;
};

//signed integer type serialization
static inline size_t serialization(char* ptr, const int8_t& ref, size_t maxlen) { 
	if (maxlen < 1) return 0; memcpy(ptr, &ref, 1); return 1;
};

static inline size_t serialization(char* ptr, const int16_t& ref, size_t maxlen) { 
	if (maxlen < 2) return 0; memcpy(ptr, &ref, 2); return 2;
};

static inline size_t serialization(char* ptr, const int32_t& ref, size_t maxlen) { 
	if (maxlen < 4) return 0; memcpy(ptr, &ref, 4); return 4; 
};

static inline size_t serialization(char* ptr, const int64_t& ref, size_t maxlen) { 
	if (maxlen < 8) return 0; memcpy(ptr, &ref, 8); return 8;
};

static inline size_t __serialization(char* dst, void* src, uint16_t len, size_t maxlen) { 
	if (maxlen < len) return 0;	memcpy(dst, src, len); return len; 
};


//unsigned integer type deserialization
static inline size_t deserialization(char* ptr, uint8_t& ref, size_t maxlen) { 
	if (maxlen < 1) return 0; memcpy(&ref, ptr, 1); return 1;
};

static inline size_t deserialization(char* ptr, uint16_t& ref, size_t maxlen) { 
	if (maxlen < 2) return 0; memcpy(&ref, ptr, 2); return 2;
};

static inline size_t deserialization(char* ptr, uint32_t& ref, size_t maxlen) { 
	if (maxlen < 4) return 0; memcpy(&ref, ptr, 4); return 4;
};

static inline size_t deserialization(char* ptr, uint64_t& ref, size_t maxlen) { 
	if (maxlen < 8) return 0; memcpy(&ref, ptr, 8); return 8;
};

//signed integer type deserialization
static inline size_t deserialization(char* ptr, int8_t& ref, size_t maxlen) { 
	if (maxlen < 1) return 0; memcpy(&ref, ptr, 1); return 1;
};

static inline size_t deserialization(char* ptr, int16_t& ref, size_t maxlen) { 
	if (maxlen < 2) return 0; memcpy(&ref, ptr, 2); return 2;
};

static inline size_t deserialization(char* ptr, int32_t& ref, size_t maxlen) { 
	if (maxlen < 4) return 0; memcpy(&ref, ptr, 4); return 4;
};

static inline size_t deserialization(char* ptr, int64_t& ref, size_t maxlen) { 
	if (maxlen < 8) return 0; memcpy(&ref, ptr, 8); return 8;
};

static inline size_t __deserialization(char* dst, void* src, uint16_t len, size_t maxlen) { 
	if (maxlen < len) return 0;	memcpy(src, dst, len); return len; 
};

//unsigned integer type serialSize
static inline size_t serialSize(const uint8_t& ref) { return 1; };
static inline size_t serialSize(const uint16_t& ref) { return 2; };
static inline size_t serialSize(const uint32_t& ref) { return 4; };
static inline size_t serialSize(const uint64_t& ref) { return 8; };

//signed integer type serialSize
static inline size_t serialSize(const int8_t& ref) { return 1; };
static inline size_t serialSize(const int16_t& ref) { return 2; };
static inline size_t serialSize(const int32_t& ref) { return 4; };
static inline size_t serialSize(const int64_t& ref) { return 8; };

class DeserialBuffer {
	uint16_t m_size;
	char* m_data;

public:
	DeserialBuffer(char* buf, uint16_t sz) : m_data(buf), m_size(sz) {};

	template <typename T>
	unsigned char deserialization(const T& ref) {
		if (T::deserialSize(m_data) > m_size) return -1; 
		auto sz = ::deserialization(m_data, ref, m_size);
		if (sz == 0) return -1;
		m_data += sz;
		m_size -= sz;
		return 0;
	}
};

#endif