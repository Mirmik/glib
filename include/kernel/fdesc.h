#ifndef GENOS_FILE_DESCRIPTOR_H
#define GENOS_FILE_DESCRIPTOR_H

#include "genos/container/hashtable.h"

struct file
{
	hlist_node link;
	int id;
};

extern hashtable<file,&file::link,int,&file::id> fdesc_table;

void init_fdesc_table();

#endif