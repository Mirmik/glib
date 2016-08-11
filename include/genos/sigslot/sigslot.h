#ifndef GENOS_SIGSLOT_H
#define GENOS_SIGSLOT_H

#include <genos/sigslot/delegate.h>
#include <gxx/container/vector.h>

namespace genos {

template<typename ... Args>	class slot; 
template<typename ... Args>	class signal;
template<typename ... Args> 
	void connect(signal<Args...>* sig, slot<Args...>* slt);

template<typename ... Args>
class signal {
public:

	using dlg_t = delegate<void, Args ... >;
	using fnc_t = void (*)(Args ...);
	
	template <typename Abstract>
	using member = void (Abstract::*)(Args ...);
	
	gxx::vector<delegate<void,Args...>> vect;

	void operator()(Args ... args) {
		for(auto dlg : vect) {
			dlg(args ...);
		}
	}

	template <typename T>
	void connect(T* obj, member<T> mbr) {
		vect.emplace_back(obj, mbr);
	}

	void connect(fnc_t func) {
		vect.emplace_back(func);
	}
};

};

#endif