
#ifndef GENOS_GSTL_UTILITY
	#define GENOS_GSTL_UTILITY


#include <cstddef>

//Реализации разбиты по нескольким файлам, дабы не было лапши из кода.
//Некоторые шаблоны могут врать... Извините.
//UNDER_CONSTRUCTED

//#include <genos/gstl/algorithm.h>

namespace gxx{
#include "genos/gstl/utility/prototype.hpp"

#include "genos/gstl/utility/pair.hpp"
#include "genos/gstl/utility/utility.hpp"
#include "genos/gstl/utility/type_traits.hpp"
#include "genos/gstl/utility/type_transform.hpp"
#include "genos/gstl/utility/type_relation.hpp"
#include "genos/gstl/utility/move.hpp"
};


#endif