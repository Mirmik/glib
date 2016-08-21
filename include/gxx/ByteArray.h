#ifndef GENOS_BYTEARRAY_H
#define GENOS_BYTEARRAY_H

#include <inttypes.h>
#include <gxx/Allocator.h>

namespace gxx {

	class ByteArray : public BasicAllocated {
	
		char* m_data;
		size_t m_capacity;
		size_t m_size;
	
	public:
		ByteArray();
		ByteArray(const ByteArray& other);
		ByteArray(ByteArray&& other);
		~ByteArray();

		ByteArray & operator= (const ByteArray& other);
		ByteArray & operator= (ByteArray&& other);

		ByteArray(const char* str);
		void release();

		size_t size() const;
		size_t capacity() const;
		char* data() const;
		uint8_t reserve(size_t sz);
		uint8_t changeBuffer(size_t sz);
	
		const char* c_str();
		char* begin();
		char* end();
		
		ByteArray & copy(const char *cstr, size_t length);
		void move(ByteArray &rhs);
		
		unsigned char concat(const char *cstr, size_t length);
		unsigned char concat(const char *cstr);
		unsigned char concat(char cstr);
		
		unsigned char concat(uint8_t num, uint8_t base = 10);
		unsigned char concat(uint16_t num, uint8_t base = 10);
		unsigned char concat(uint32_t num, uint8_t base = 10);
		unsigned char concat(uint64_t num, uint8_t base = 10);
		
		unsigned char concat(int8_t num, uint8_t base = 10);
		unsigned char concat(int16_t num, uint8_t base = 10);
		unsigned char concat(int32_t num, uint8_t base = 10);
		unsigned char concat(int64_t num, uint8_t base = 10);		
		unsigned char concat(const ByteArray& other);

		static ByteArray number(uint8_t num, uint8_t base = 10);
		static ByteArray number(uint16_t num, uint8_t base = 10);
		static ByteArray number(uint32_t num, uint8_t base = 10);
		static ByteArray number(uint64_t num, uint8_t base = 10);
		
		static ByteArray number(int8_t num, uint8_t base = 10);
		static ByteArray number(int16_t num, uint8_t base = 10);
		static ByteArray number(int32_t num, uint8_t base = 10);
		static ByteArray number(int64_t num, uint8_t base = 10);

		static ByteArray number(double num, char format, uint8_t prec);

		static ByteArray format(const char* fmt, ...);

		template<typename T>
		ByteArray & operator+= (T obj) {
			concat(obj);
			return *this;
		}

		template<typename T>
		ByteArray & operator<< (T obj) {
			concat(obj);
			return *this;
		}

		void invalidate();
		ByteArray & shrink();
		ByteArray & shrink_to_print();
	};
	
	using string = ByteArray;
	
};

#endif