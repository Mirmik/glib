#ifndef GENOS_EVIDENT_TYPES
#define GENOS_EVIDENT_TYPES

#define EVITYPE_NIL 0
#define EVITYPE_INT8 1
#define EVITYPE_INT16 2
#define EVITYPE_INT32 3
#define EVITYPE_INT64 4
#define EVITYPE_UINT8 5
#define EVITYPE_UINT16 6
#define EVITYPE_UINT32 7
#define EVITYPE_UINT64 8


template <typename type> struct evitype;

template<> struct evitype<int32_t> {
	static constexpr uint16_t id = 3;
};

#endif