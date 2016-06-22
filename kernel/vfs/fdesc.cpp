#include "kernel/fdesc.h"
#include "mem/allocator.h"

hashtable<file,&file::link,int,&file::id> fdesc_table;

uint fdesk_hash(int key)
{
	return key;
}

int fdesk_cmp(int key0, int key1)
{
	return key0 < key1;
}

void init_fdesc_table()
{
	fdesc_table.memstrategy(&malloc_ops, hash_memstrat70);
	fdesc_table.init(fdesk_hash, fdesk_cmp);
};