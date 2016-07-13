
#ifndef GENOS_GSTL_UTILITY
	#define GENOS_GSTL_UTILITY

//Реализации разбиты по нескольким файлам, дабы не было лапши из кода.
//Некоторые шаблоны могут врать... Извините.
//UNDER_CONSTRUCTED

//#include <genos/gstl/algorithm.h>

#include "defines/nullptr_t.h"
#include "defines/size_t.h"

namespace gxx{
using size_t = ::size_t;

#include "gxx/utility/prototype.hpp"

#include "gxx/utility/pair.hpp"
#include "gxx/utility/utility.hpp"
#include "gxx/utility/type_traits.hpp"
#include "gxx/utility/type_transform.hpp"
#include "gxx/utility/type_relation.hpp"
#include "gxx/utility/move.hpp"
};


#endif