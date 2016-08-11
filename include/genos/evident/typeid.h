#ifndef GENOS_EVIDENT_TYPES
#define GENOS_EVIDENT_TYPES

enum EviTypeId : uint8_t {
	NIL = 0,
	INT8 = 1,
	INT16 = 3,
	INT32 = 4,
	INT64 = 5,
	TUPLE = 0x80
}

#define EVITYPE_NIL 0
#define EVITYPE_INT8 1
#define EVITYPE_INT16 2
#define EVITYPE_INT32 3
#define EVITYPE_INT64 4
#define EVITYPE_UINT8 5
#define EVITYPE_UINT16 6
#define EVITYPE_UINT32 7
#define EVITYPE_UINT64 8
#define EVITYPE_CSTR 9		/*строка с казанием числа байт*/
#define EVITYPE_NSTR 10		/*нуль терминированная строка*/
#define EVITYPE_SFLOAT 11	/*плавающее 4 байта*/
#define EVITYPE_DFLOAT 12	/*плавающее 8 байт*/


template <typename type> struct evitype;

template<> struct evitype<void> {
	static constexpr eviid_t id = EVITYPE_NIL;
};

template<> struct evitype<int8_t> {
	static constexpr eviid_t id = EVITYPE_INT8;
};

template<> struct evitype<int16_t> {
	static constexpr eviid_t id = EVITYPE_INT16;
};

template<> struct evitype<int32_t> {
	static constexpr eviid_t id = EVITYPE_INT32;
};

template<> struct evitype<int64_t> {
	static constexpr eviid_t id = EVITYPE_INT64;
};

template<> struct evitype<uint8_t> {
	static constexpr eviid_t id = EVITYPE_UINT8;
};

template<> struct evitype<uint16_t> {
	static constexpr eviid_t id = EVITYPE_UINT16;
};

template<> struct evitype<uint32_t> {
	static constexpr eviid_t id = EVITYPE_UINT32;
};

template<> struct evitype<uint64_t> {
	static constexpr eviid_t id = EVITYPE_UINT64;
};
#endif