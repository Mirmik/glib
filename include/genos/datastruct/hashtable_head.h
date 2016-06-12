#ifndef GENOS_HASHTABLE_HEAD
#define GENOS_HASHTABLE_HEAD

#include "genos/container/hlist.h"

struct hashtable_head
{
	hlist_head* table;
	size_t table_size;
	size_t total;
};

static struct hashtable_head* hashtable_head_init(struct hashtable_head* ht)
{
	ht->table = 0;
	ht->total = 0;
	ht->table_size = 0; 
};

static struct hashtable_head* hashtable_locate(struct hashtable_head* ht, void* buf, int len)
{
	ht->table = (hlist_head*) buf;
	ht->total = 0;
	ht->table_size = len / sizeof(hlist_head*); 

	for(int i = 0; i < ht->table_size; i++)
		hlist_head_init(ht->table + i);
};

#endif