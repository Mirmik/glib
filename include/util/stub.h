#ifndef GENOS_STUB_H
#define GENOS_STUB_H

//#include "genos/debug/debug.h"

#ifndef __cplusplus

static void do_nothing() {  };

#else

template <typename R = void,typename ... V> 
static R do_nothing(V...) { return (R)0; };

struct ignore_t
{
    template <class type>
    type& operator= (type& value) { return value; }
};
static ignore_t ignore;

class DoNothing
{public:
	template <typename R = void,typename ... V> 
	R do_nothing(V...) { return (R)0; };
};

#endif //__cplusplus	

#endif 