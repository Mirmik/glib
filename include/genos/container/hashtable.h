#ifndef GENOS_HASH_TABLE
#define GENOS_HASH_TABLE

#include "genos/datastruct/hashtable_head.h"
#include "genos/gstl/algorithm.h"
#include "mem/allocator.h"

template <typename type, hlist_node type::* link, typename keytype, keytype type::* keyfield>
class hashtable
{
	using hash_fn_t = uint(*)(keytype);
	using cmp_fn_t = int(*)(keytype,keytype);

private:
	hashtable_head ht;

	hash_fn_t hash;
	cmp_fn_t  cmp;

	allocator_ops* alloc;
	int (*strategy) (hashtable_head*); 


	inline struct hlist<type,link>* eval_cell(const keytype& key)
	{
		return reinterpret_cast<hlist<type,link>*>
		(ht.table + (hash(key) % ht.table_size));
	}

	inline struct hlist<type,link>* to_cell(struct hlist_head* ptr)
	{
		return reinterpret_cast<hlist<type,link>*>(ptr);
	}

	inline void relocate(hashtable_head* dst)
	{
		for (int i = 0; i < ht.table_size; i++)
		{
			hlist<type,link>* srccell = to_cell(ht.table + i);
			
			auto c = srccell->begin();
			while(c != srccell->end())
			{
				auto next = c.next(); 
				struct hlist<type,link>* dstcell = reinterpret_cast<hlist<type,link>*>
											(dst->table + (hash(*c.*keyfield) % dst->table_size));
				dstcell->push_front(*c);
				c = next;
			};
		};
	};

	inline void memstrategy()
	{
		int newsz;
		if (strategy) newsz = strategy(&ht);
		if (newsz == 0) return;

		void* buf = alloc->allocate(newsz * sizeof(hlist<type,link>));
 	
		if (!ht.table) 
		{
			hashtable_locate(&ht,buf,newsz * sizeof(hlist<type,link>));
			return;
		}

		hashtable_head nht;
		hashtable_locate(&nht,buf,newsz * sizeof(hlist<type,link>));

		relocate(&nht);
		ht.table = nht.table;
		ht.table_size = nht.table_size;
		return;
 	}

public:
	hashtable() : cmp(nullptr), hash(nullptr), alloc(nullptr), strategy(nullptr) 
	{
		hashtable_head_init(&ht);
	};

	void init(void* buf, int len, hash_fn_t _hash, cmp_fn_t _cmp)
	{
		hashtable_locate(&ht, buf, len);
		hash = _hash;
		cmp = _cmp;
	};

	void init(hash_fn_t _hash, cmp_fn_t _cmp)
	{
		hash = _hash;
		cmp = _cmp;
	};

	void set_memstrategy(allocator_ops* _alloc, int (*_strategy) (hashtable_head*))
	{
		alloc = _alloc;
		strategy = _strategy;
	}

	void put(type& item)
	{
		assert(hash);
		assert(ht.table || strategy);
		memstrategy();
		ht.total++;
		struct hlist<type,link>* cell = eval_cell(item.*keyfield);
		cell->push_front(item);
	};

	type* get(const keytype& key)
	{
		assert(hash);
		assert(cmp);
		assert(ht.table);
		
		struct hlist<type,link>* cell = eval_cell(key);
		auto end = cell->end();
		auto begin = cell->begin();
		auto res = gxx::find_if(begin,end,[=](type& item)
		{
			return cmp(item.*keyfield, key) == 0;
		});
		return res == end ? (type*)0 : &*res;												
	};

	type* del(const keytype& key)
	{
		assert(hash);
		assert(cmp);
		assert(ht.table);
		
		struct hlist<type,link>* cell = eval_cell(key);
		auto end = cell->end();
		auto begin = cell->begin();
		auto res = gxx::find_if(begin,end,[=](type& item)
		{
			return cmp(item.*keyfield, key) == 0;
		});
		if (res == end) return 0;
		cell->pop(*res);
		ht.total--;
		memstrategy();
		return &*res;
	};

	gxx::string to_info()
	{
		gxx::string str;
		str.reserve(128);
		str << "[";
		for(int i = 0; i < ht.table_size; i++)
			str << to_cell(ht.table + i)->total() << gxx::string(",");
		str << "]";
		return str;
	}
};

static int hash_memstrat70(hashtable_head* ht)
{
	assert(ht);

	if (ht->table == nullptr)
	{
		return 4;
	};

	if (ht->total < 4) return 0;

	if (ht->total >= ht->table_size) // > 100%
	{
		return ht->table_size + (ht->table_size >> 1); //150%
	};

	if (ht->total <= (ht->table_size >> 1)) // < 50%
	{
		return ht->table_size >> 1; //50%
	};

	return 0;
};

#endif