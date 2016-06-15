
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

#include "genos/gstl/utility/prototype.hpp"

#include "genos/gstl/utility/pair.hpp"
#include "genos/gstl/utility/utility.hpp"
#include "genos/gstl/utility/type_traits.hpp"
#include "genos/gstl/utility/type_transform.hpp"
#include "genos/gstl/utility/type_relation.hpp"
#include "genos/gstl/utility/move.hpp"
};


#endif