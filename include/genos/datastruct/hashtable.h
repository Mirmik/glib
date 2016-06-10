#ifndef UTIL_HASHTABLE_HEAD_H_
#define UTIL_HASHTABLE_HEAD_H_

#include "util/array.h"
#include "genos/datastruct/slink_head.h"

//Тип хэш-функции.
typedef size_t (*ht_hash_ft)(const void *key);

//Тип функции сравнения элементов (возвращает ноль, если равно).
typedef int (*ht_cmp_ft)(const void *key1, const void *key2);

struct hashtable_link
{
	slink_head link;
	const void* key;
};

struct hashtable_head
{
	slink_head* table;
	size_t table_size;
	ht_hash_ft hsh;
	ht_cmp_ft cmp;
	size_t total;
};

struct hashtable_head* hashtable_head_init(struct hashtable_head* ht, void* buf, unsigned int len,
	ht_hash_ft hsh, ht_cmp_ft cmp)
{
	ht->table = (struct slink_head *) buf;
	ht->hsh = hsh;
	ht->cmp = cmp;
	ht->total = 0;
	ht->table_size = len / sizeof(struct slink_head); 

	struct slink_head* l;
	array_for_each_ptr(l, ht->table, ht->table_size) 
		slink_init(l);

	return ht;
};

struct hashtable_link * hashtable_link_init(
		struct hashtable_link *item, const void *key)
{
	item->key = key;
	slink_init(&item->link);
	return item;
};

int hashtable_put_to_cell(struct hashtable_head* ht, struct hashtable_link* item, size_t index)
{
	slink_connect_after(&item->link, ht->table + index);
}

int hashtable_put(struct hashtable_head* ht, struct hashtable_link* item)
{
	assert(ht);
	assert(item);
	assert(ht->table_size);
	assert(item->key);

	size_t index = ht->hsh(item->key) % ht->table_size;

	ht->total++;

	hashtable_put_to_cell(ht, item, index);
}

struct hashtable_link *hashtable_get(struct hashtable_head *ht, const void* key)
{
	assert(ht);
	assert(ht->table_size);
	assert(key);

	size_t index = ht->hsh(key) % ht->table_size;
	struct hashtable_link * it;

	if ((ht->table + index)->next == 0) return 0;
	slink_for_each_entry(it, ht->table + index, link)
	{
		if (ht->cmp(key,it->key) == 0) return it;  
	};
	return 0;
}

struct hashtable_link *hashtable_del(struct hashtable_head *ht, void* key)
{
	assert(ht);
	assert(ht->table_size);
	assert(key);

	size_t index = ht->hsh(key) % ht->table_size;
	struct hashtable_link * it;
	struct slink_head * sl;

	slink_for_each_entry_safe(it, sl, ht->table + index, link)
	{
		if (ht->cmp(key,it->key) == 0) 
		{
			_slink_del(&it->link, sl);
			return it;
		};  
	};
	return 0;
}

#endif /* UTIL_HASHTABLE_H_ */
