#ifndef DATASTRUCT_DYNARRAY_H
#define DATASTRUCT_DYNARRAY_H

#include <util/math.h>

#include <assert.h>
#include <sys/cdefs.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <mem/alloc.h>

typedef struct {
	void* data;
	size_t cap;
	alloc_t * alloc;
} dynarray_t;

__BEGIN_DECLS

static inline void dynarray_init(dynarray_t * da) {
	da->data = NULL;
	da->cap = 0;
	da->alloc = default_allocator;
}

static inline void dynarray_invalidate(dynarray_t * da) {
	if (da->data) da->alloc->ops.deallocate(da->alloc, da->data);
	da->data = NULL;
	da->cap = 0;
}

static inline void dynarray_setAllocator(dynarray_t * da, alloc_t * alloc) {
	da->alloc = alloc;
};

static inline int8_t dynarray_changeBuffer(dynarray_t * da, size_t cap) {
	da->data = da->alloc->ops.reallocate(da->alloc, da->data, cap);
	if (da->data == NULL) return 0;
	da->cap = cap;
	return 1;
}

static inline int8_t dynarray_reserve(dynarray_t * da, size_t cap) {
	return cap <= da->cap ? 1 : dynarray_changeBuffer(da, cap);
}

static inline int8_t dynarray_changeBufferCopy(dynarray_t * da, size_t cap, size_t copy) {
	void* newdata = da->alloc->ops.allocate(da->alloc, cap);
	if (newdata == NULL) return 0;
	
	assert(copy <= min(da->cap, cap));

	memcpy(newdata, da->data, copy);
	if (da->data) da->alloc->ops.deallocate(da->alloc, da->data);
	da->data = newdata;
	da->cap = cap;
	
	return 1;
}

static inline int8_t dynarray_changeBufferCopyBias(dynarray_t * da, size_t cap, size_t copy, size_t biaspos, size_t biaslen) {
	void* newdata = da->alloc->ops.allocate(da->alloc, cap);
	if (newdata == NULL) return 0;
	
	assert(copy <= min(da->cap, cap)); 
	assert(copy >= biaspos + biaslen);

	memcpy(newdata, da->data, biaspos);
	memcpy((char*)newdata + biaspos + biaslen, (char*)da->data + biaspos, copy - biaspos);
	
	if (da->data) da->alloc->ops.deallocate(da->alloc, da->data);
	da->data = newdata;
	da->cap = cap;
	
	return 1;
}

static inline void* dynarray_paste (dynarray_t * da, size_t copy, size_t biaspos, size_t biaslen) {
	if (da->cap >= copy + biaslen) {
		memmove((char*)da->data + biaspos + biaslen, (char*)da->data + biaspos, copy - biaspos);	
	} else {
		int8_t ret = dynarray_changeBufferCopyBias(da, copy + biaslen, copy, biaspos, biaslen);
		if (ret == 0) return NULL;
	}
	return (char*)da->data + biaspos;
}

static inline void dynarray_remove(dynarray_t * da, size_t copy, size_t biaspos, size_t biaslen) {
	assert(copy >= biaspos + biaslen);
	memmove((char*)da->data + biaspos, (char*)da->data + biaspos + biaslen, copy - biaslen - biaspos);	
}

__END_DECLS

#define dynarray_ref(da,num) (*((char*)(da)->data + num))

#endif