#ifndef GXX_ARCHIVE_H
#define GXX_ARCHIVE_H

#include <stdlib.h>
#include <stdint.h>

namespace gxx {

	class HexArchive {
	public:
		char* m_data;
		char* m_cursor;
		size_t m_size;

	public:
		HexArchive(const char* data, size_t size) : m_data((char*)data), m_cursor((char*)data), m_size(size) {}
	};

	template<typename T>
	void load(T& ref, gxx::HexArchive& ar) {
		ref.load(ar);
	};

	void load(uint8_t& ref, gxx::HexArchive& ar);
	void load(uint16_t& ref, gxx::HexArchive& ar);
	void load(uint32_t& ref, gxx::HexArchive& ar);
	void load(uint64_t& ref, gxx::HexArchive& ar);
	void load(int8_t& ref, gxx::HexArchive& ar);
	void load(int16_t& ref, gxx::HexArchive& ar);
	void load(int32_t& ref, gxx::HexArchive& ar);
	void load(int64_t& ref, gxx::HexArchive& ar);

	template<typename T>
	void save(T& ref, gxx::HexArchive& ar) {
		ref.save(ar);
	};

	void save(uint8_t& ref, gxx::HexArchive& ar);
	void save(uint16_t& ref, gxx::HexArchive& ar);
	void save(uint32_t& ref, gxx::HexArchive& ar);
	void save(uint64_t& ref, gxx::HexArchive& ar);
	void save(int8_t& ref, gxx::HexArchive& ar);
	void save(int16_t& ref, gxx::HexArchive& ar);
	void save(int32_t& ref, gxx::HexArchive& ar);
	void save(int64_t& ref, gxx::HexArchive& ar);

}

template<typename T>
void operator<<(T& ref, gxx::HexArchive& ar) {
	gxx::load(ref, ar);	
}

template<typename T>
void operator>>(T& ref, gxx::HexArchive& ar) {
	gxx::save(ref, ar);	
}

#endif 