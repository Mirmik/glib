#ifndef GENOS_HSERIAL
#define GENOS_HSERIAL

#include "genos/serialization/serialization.h"

template <typename type>
unsigned int hserial(char* buf, type& obj, uint8_t flag)
{
	obj.hserial(buf,flag);
};

unsigned int hserial(char* buf, int8_t&, uint8_t flag);
unsigned int hserial(char* buf, int16_t&, uint8_t flag);
unsigned int hserial(char* buf, int32_t&, uint8_t flag);
unsigned int hserial(char* buf, int64_t&, uint8_t flag);
unsigned int hserial(char* buf, uint8_t&, uint8_t flag);
unsigned int hserial(char* buf, uint16_t&, uint8_t flag);
unsigned int hserial(char* buf, uint32_t&, uint8_t flag);
unsigned int hserial(char* buf, uint64_t&, uint8_t flag);



#endif