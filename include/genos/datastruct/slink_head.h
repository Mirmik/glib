#ifndef GENOS_SLINK_HEAD_H
#define GENOS_SLINK_HEAD_H

#include "defines/decltypeof.h"
#include "kernel/kassert.h"
#include "util/member.h"

struct slink_head
{
	slink_head* next;
};

void slink_init(struct slink_head* link)
{
	kassert(link);
	link->next = 0;
}

void slink_connect_after(struct slink_head* link, struct slink_head* head)
{
	kassert(link);
	kassert(head);
	link->next = head->next;
	head->next = link;
};

void slink_connect_last(struct slink_head* link, struct slink_head* head)
{
	kassert(link);
	kassert(head);
	struct slink_head* iter = head;
	while(iter->next != 0) iter = iter->next;
	slink_connect_after(link, iter);
};

void _slink_del(struct slink_head* link, struct slink_head* prev)
{
	assert(prev->next == link);
	prev->next = link->next;
}

#define slink_entry(ptr,type,member)							\
container_of(ptr, type, member)

#define slink_for_each(ptr,head)								\
for (ptr = head; ptr != 0; ptr = ptr->next)

//#define slink_for_each_safe(ptr,head)								\
//for (ptr = head; ptr != 0; ptr = ptr->next)

#define slink_next_entry(pos, member) 							\
slink_entry((pos)->member.next, decltypeof(*(pos)), member)

#define slink_first_entry(ptr, type, member) 					\
slink_entry((ptr)->next, type, member)

#define slink_for_each_entry(pos, head, member)					\
for (pos = slink_first_entry(head, decltypeof(*pos), member);	\
&pos->member != 0;												\
pos = slink_next_entry(pos, member))

#define slink_for_each_entry_safe(pos, prevlnk, head, member)		\
for (prevlnk = head, pos = slink_first_entry(head, decltypeof(*pos), member);	\
&pos->member != 0; prevlnk = &pos->member, 								\
pos = slink_next_entry(pos, member))

#endif