#include <gxx/future/archive.h>
#include <util/ascii_convert.h>

namespace gxx {

	void load(uint8_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 1);
		ar.m_cursor = ar.m_cursor + 2;
	}; 
	
	void load(uint16_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 2);
		ar.m_cursor = ar.m_cursor + 4;
	};
	
	void load(uint32_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 4);
		ar.m_cursor = ar.m_cursor + 8;
	};
	
	void load(uint64_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 8);
		ar.m_cursor = ar.m_cursor + 16;
	};
	
	void load(int8_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 1);
		ar.m_cursor = ar.m_cursor + 2;
	};
	
	void load(int16_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 2);
		ar.m_cursor = ar.m_cursor + 4;
	};
	
	void load(int32_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 4);
		ar.m_cursor = ar.m_cursor + 8;
	};
	
	void load(int64_t& ref, gxx::HexArchive& ar) {
		bhex2bytes(&ref, ar.m_cursor, 8);
		ar.m_cursor = ar.m_cursor + 16;
	};



	void save(uint8_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 1);
		ar.m_cursor = ar.m_cursor + 2;
	}; 
	
	void save(uint16_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 2);
		ar.m_cursor = ar.m_cursor + 4;
	};
	
	void save(uint32_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 4);
		ar.m_cursor = ar.m_cursor + 8;
	};
	
	void save(uint64_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 8);
		ar.m_cursor = ar.m_cursor + 16;
	};
	
	void save(int8_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 1);
		ar.m_cursor = ar.m_cursor + 2;
	};
	
	void save(int16_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 2);
		ar.m_cursor = ar.m_cursor + 4;
	};
	
	void save(int32_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 4);
		ar.m_cursor = ar.m_cursor + 8;
	};
	
	void save(int64_t& ref, gxx::HexArchive& ar) {
		bytes2bhex(ar.m_cursor, &ref, 8);
		ar.m_cursor = ar.m_cursor + 16;
	};

};