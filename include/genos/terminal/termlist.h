#ifndef GENOS_TERM_LIST_H
#define GENOS_TERM_LIST_H

#include "genos/container/hashtable.h"
#include "genos/sigslot/delegate.h"
#include "mem/allocator.h"
#include "crypto/crc.h"

template<typename R, typename ... Args>
struct termlist_elem
{
	hlist_node link;
	const char* name;
	delegate<R, Args ...> func;
};

template<typename R, typename ... Args>
class termlist
{
	using elem_t = termlist_elem<R,Args...>;
	using deleg_t = delegate<R,Args...>;

private:
	hashtable<
	elem_t, 
	&elem_t::link, 
	const char*, 
	&elem_t::name
	> ht;

public:
	termlist()
	{
		ht.init(strcrc8,strcmp);
		ht.set_memstrategy(&malloc_ops, hash_memstrat70);
	}

	void add(const char* name, const deleg_t& d)
	{
		elem_t* t = (elem_t*) malloc(sizeof(elem_t));
		t->name = name;
		t->func = d;
		ht.put(*t);
	}

	deleg_t find(const char* name)
	{
		elem_t* t = ht.get(name);
		return t == 0 ? 0 : t->func; 
	};
};

#endif