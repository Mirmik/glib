#include "genos/serialization/serialization.h"
#include "string.h"
#include "debug/dprint.h"
#include "hal/arch.h"
#include "util/bits.h"

bool is_need_reverse(uint8_t order) {
#if BYTE_ORDER == __LITTLE_ENDIAN
	//dprln("here1");
	if (order == PROTOORD_BIG) return true;
	return false;
#elif BYTE_ORDER == __BIG_ENDIAN
	//dprln("here2");
	if (order == PROTOORD_LITTLE) return true;
	return false;
#else
	#error "Architecture error!"
#endif
};

void memcpy_swap(void* dst, void* src, size_t sz) {
	//dprln("here");
	char* _dst = (char*) dst + sz -1;
	char* _src = (char*) src;
	char* _end = _src + sz;

	while(_src != _end) {
		*_dst-- = *_src++; 
	}
};

unsigned int __rserial
	(char* buf, void* ref, uint16_t len, uint8_t flag) {
	bool reverse = is_need_reverse(bits_mask(flag, PROTOORD_MASK));
	if (bits_mask_eq(flag, SERDIR_MASK, SER)) {
		if (reverse) memcpy_swap(buf, ref, len); 
		else memcpy(buf, ref, len);	
	}
	else { 
		if (reverse) memcpy_swap(ref, buf, len);
		else memcpy(ref, buf, len);
	}
	return len;
}


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

