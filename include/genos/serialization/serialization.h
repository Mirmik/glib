#ifndef GENOS_SERIALIZATION_H
#define GENOS_SERIALIZATION_H

#include "inttypes.h"
#include "compiler.h"
#include "utilxx/buffer.h"
#include "utilxx/gstring.h"

enum Ser
{
	SER,
	DESER
};

template <typename type>
unsigned int serialization(char* buf, type& obj, uint8_t flag)
{
	obj.serialization(buf,flag);
};

unsigned int serialization(char* buf, int8_t&, uint8_t flag);
unsigned int serialization(char* buf, int16_t&, uint8_t flag);
unsigned int serialization(char* buf, int32_t&, uint8_t flag);
unsigned int serialization(char* buf, int64_t&, uint8_t flag);
unsigned int serialization(char* buf, uint8_t&, uint8_t flag);
unsigned int serialization(char* buf, uint16_t&, uint8_t flag);
unsigned int serialization(char* buf, uint32_t&, uint8_t flag);
unsigned int serialization(char* buf, uint64_t&, uint8_t flag);

//unsigned int serialization(char* buf, real32_t&, uint8_t flag);

unsigned int serialization(char* buf, gxx::string& ref, uint8_t flag);

unsigned int serialization_raw(char* buf, char* ptr, size_t* len, uint8_t flag);

#endif
