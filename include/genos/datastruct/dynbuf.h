#ifndef GENOS_DYNBUF_H
#define GENOS_DYNBUF_H

#include "inttypes.h"
#include <mem/allocator.h>

struct dynbuf
{
	void* buf; //buffer
	size_t cap; //capasity
	allocator_ops* alloc;
};

static inline int dynbuf_init(struct dynbuf* db, allocator_ops* alloc)
{
	db->buf = 0;
	db->cap = 0;
	db->alloc = alloc;
};

static inline int dynbuf_invalidate(struct dynbuf* db, size_t sz)
{
	if (db->buf) db->alloc->deallocate(db->buf);
	db->buf = 0;
	db->cap = 0;
	return 0;
};

static inline uint8_t dynbuf_change_buffer(struct dynbuf* db, size_t sz)
{
	void *newbuf = db->buf ? 
		db->alloc->reallocate(db->buf, sz) :
		db->alloc->allocate(sz);
	if (newbuf) {
		db->buf = newbuf;
		db->cap = sz;
		return 1;
	}
	return 0;
};

static inline uint8_t dynbuf_reserve(struct dynbuf* db, size_t sz)
{
	if (db->buf && db->cap >= sz) return 1;
	if (dynbuf_change_buffer(db,sz)) {
		return 1;
	}
	return 0;
};

#endif