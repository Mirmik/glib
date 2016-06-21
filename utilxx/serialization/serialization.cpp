#include "genos/serialization/serialization.h"
#include "string.h"

inline unsigned int __serialization_old_type
	(char* buf, void* ptr, uint16_t sz, uint8_t flag)
{
	if (flag == SER)
	{
		memcpy(buf,ptr,sz);
		return sz;
	}
	else if(flag == DESER)
	{
		memcpy(ptr,buf,sz);
		return sz;	
	};
	return -1;
}

unsigned int serialization(char* buf, int8_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 1, flag);
};

unsigned int serialization(char* buf, int16_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 2, flag);
};

unsigned int serialization(char* buf, int32_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 4, flag);
};

unsigned int serialization(char* buf, int64_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 8, flag);
};

unsigned int serialization(char* buf, uint8_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 1, flag);
};

unsigned int serialization(char* buf, uint16_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 2, flag);
};

unsigned int serialization(char* buf, uint32_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 4, flag);
};

unsigned int serialization(char* buf, uint64_t& ref, uint8_t flag)
{
	return __serialization_old_type(buf, &ref, 8, flag);
};

unsigned int serialization(char* buf, gxx::string& ref, uint8_t flag)
{
	unsigned int bias = 0;
	uint16_t len;
	if (flag == SER)
	{
		len = ref.length();
		bias += serialization(buf,len,SER);
		bias += __serialization_old_type(buf + bias,
			(void*)ref.c_str(),len,SER);
		return bias;
	}
	else if(flag == DESER)
	{
		bias += serialization(buf,len,DESER);
		ref = gxx::buffer(buf + bias, len);
		return bias + len;
	};
	return -1;
};

unsigned int serialization_raw(char* buf, char* ptr, size_t* plen, uint8_t flag)
{
	unsigned int bias = 0;	
	bias += serialization(buf,*plen,flag);
	bias += __serialization_old_type(buf + bias, ptr, *plen, flag);
	return bias;
};

