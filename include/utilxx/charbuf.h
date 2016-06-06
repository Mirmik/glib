#ifndef GENOS_CHARBUF_H
#define GENOS_CHARBUF_H

namespace gxx {

template<unsigned int size>
class charbuf
{
public:
	char data[size + 1];
	char& operator[](int i)
	{
		return data[i];
	};

	char* to_buf()
	{
		return data;
	};

	char* c_str()
	{
		return data;
	};

	int length()
	{
		return size;
	};

//	uint32_t controlsum()
//	{
//		uint32_t sum = 0;
//		for (int i = 0; i < size; i++)
//		sum += *(data + i);
//		return sum;	
//	};

	charbuf<size>& operator= (const charbuf<size>& src)
	{
		memcpy(data, src.data, size);
	};

	charbuf<size>& operator= (volatile const charbuf<size>& src)
	{
		memcpy(data, (const char*)src.data, size);
	};

	charbuf() { data[size] = 0; };

	charbuf(const char* str) { memcpy(data, str, size); };
};

class buffer
{
public:
	const char* buf;
	int len;
	buffer(const char* _buf, int _len) : buf(_buf), len(_len) {};
};

};

#endif