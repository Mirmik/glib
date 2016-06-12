#ifndef GENOS_HLIST_HEAD
#define GENOS_HLIST_HEAD

#include "compiler.h"
#include "assert.h"

struct hlist_node
{
	hlist_node* next;
	hlist_node** pprev;
};

struct hlist_head
{
	hlist_node* first;
};

__BEGIN_DECLS

static inline struct hlist_head* hlist_head_init(struct hlist_head* list)
{
	list->first = 0; 
	return list;
}

static inline void hlist_add_next(struct hlist_node* list, struct hlist_node** hnext)
{
	assert(list);
	assert(hnext);

	list->pprev = hnext;
	list->next = *hnext;
	if (list->next) list->next->pprev = &(list->next);
	*hnext = list;
}

static inline void hlist_del(struct hlist_node* list)
{
	assert(list);

	list->next->pprev = list->pprev;	
	*list->pprev = list->next;
}

__END_DECLS


#define hlist_for_each(pos, head) \
for (pos = (head)->first; pos != 0; pos = pos->next)

#endif