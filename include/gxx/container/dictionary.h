#ifndef GENOS_DICTIONARY_H
#define GENOS_DICTIONARY_H

#include "mem/allocator.h"
#include "gxx/container/hashtable.h"
#include "gxx/container/traits.h"

template <typename keytype, typename valtype>
struct dictnode {
	hlist_node hnode;
	keytype key;
	valtype val;

	dictnode(const keytype& _key, const valtype& _val) 
	: key(_key), val(_val) {};
};

template <
	typename keytype, 
	typename valtype 	
	> 
class dictionary {
	
	using hashtable_t = hashtable<
	dictnode<keytype,valtype>, &dictnode<keytype,valtype>::hnode, 
	keytype, &dictnode<keytype,valtype>::key
	>;

private:
	hashtable_t ht;

	alloc_ops* alloc;

public:
	dictionary(alloc_ops* _alloc) {
		alloc = _alloc;
		ht.init(traits<keytype>::hash_fn,traits<keytype>::cmp_fn);
		ht.memstrategy(_alloc, hash_memstrat70);
	};

	void insert(const keytype& key,const valtype& val) {
		dictnode<keytype,valtype>* dn = new dictnode<keytype,valtype>(key,val);
		ht.put(*dn);
	};

	valtype operator[](const keytype& key) {
		return ht.get(key)->val;
	};

	const hashtable_t& get_table() {
		return ht;
	};
};

#endif