#ifndef GENOS_DATASTRUCT_ARGV_H
#define GENOS_DATASTRUCT_ARGV_H

#include "gxx/to_string.h"

struct argvc_t
{
	int c;
	char** v;

	gxx::string to_str()
	{
		gxx::string str;
		str.reserve(128);
		str << "[";
		for(int i = 0; i < c; i++)
			str << gxx::string(v[i]) << gxx::string(",");
		str << "]";
		return str;
	};
};
#endif