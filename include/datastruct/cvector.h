#ifndef DATASTRUCT_CVECTOR_H
#define DATASTRUCT_CVECTOR_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <assert.h>

struct cvector_t {
	size_t elsz;
	void* data;
	size_t sz;
	size_t cap;
};

static inline void cvector_invalidate(struct cvector_t * cv) {
	if (cv->data) free(cv->data);
	cv->sz = cv->cap = 0;
}

static inline void cvector_init(struct cvector_t * cv, size_t elsz) {
	cv->sz = cv->cap = 0;
	cv->data = NULL;
	cv->elsz = elsz;
}

static inline void* cvector_change_buffer(struct cvector_t * cv, size_t cap) {
	cv->data = realloc(cv->data, cap * cv->elsz);
	if (cv->data) cv->cap = cap;
	return cv->data;
}

static inline void* cvector_change_buffer_paste(struct cvector_t * cv, size_t cap, size_t ppos, size_t psz) {
	void * newdata = malloc(cv->elsz * (cap));
	if (!newdata) return NULL;
	memcpy(newdata, cv->data, cv->elsz * ppos);
	memcpy((char*)newdata + cv->elsz * (ppos + psz), (char*)cv->data + cv->elsz * ppos, cv->elsz * (cv->sz - ppos));
	free(cv->data);
	cv->data = newdata;
	cv->cap = cap;
	return cv->data;
}

static inline void* cvector_paste(struct cvector_t * cv, size_t ppos, size_t psz) {
	if (cv->cap >= cv->sz + psz) {
		memmove((char*)cv->data + cv->elsz * (ppos + psz), (char*)cv->data + cv->elsz * ppos, cv->elsz * (cv->sz - ppos));	
	} else {
		void* ret = cvector_change_buffer_paste(cv, cv->sz + psz, ppos, psz);
		if (ret == NULL) return NULL;
	}
	cv->sz += psz;
	return (char*)cv->data + cv->elsz * ppos;
}

static inline void cvector_remove(struct cvector_t * cv, size_t ppos, size_t psz) {
	assert(cv->sz >= ppos + psz);

	memmove((char*)cv->data + cv->elsz * (ppos), (char*)cv->data + cv->elsz * (ppos + psz), cv->elsz * (cv->sz - ppos - psz));	
	cv->sz -= psz;
}

static inline unsigned char cvector_shrink(struct cvector_t * cv) {
	cvector_change_buffer(cv, cv->sz); 
}

static inline unsigned char cvector_reserve(struct cvector_t * cv, size_t cap) {
	return cv->cap >= cap ? 1 : cvector_change_buffer(cv, cap) ? 1 : 0; 
}

static inline void* cvector_cell(struct cvector_t * cv, size_t cell) {
	return (char*)cv->data + cv->elsz * cell; 
}

static inline unsigned char cvector_set_size(struct cvector_t * cv, size_t sz) {
	unsigned char ret = cvector_reserve(cv, sz);
	if (ret) cv->sz = sz;
	return ret;
}

static inline void* cvector_engage_back(struct cvector_t * cv) {
	unsigned char ret = cvector_reserve(cv, cv->sz + 1);
	if (ret == 0) return NULL;
	return (char*)cv->data + cv->elsz * cv->sz++;	
}

#define cvector_ref(cv,type,num) \
	(*(type*)cvector_cell(cv,num))

#define cvector_ptr(cv,type,num) \
	((type*)cvector_cell(cv,num))

#define cvector_array(cv,type) \
	((type*)(cv)->data)

#define cvector_pushback(cv,type,nelem) \
	(*(type*)cvector_engage_back(cv) = nelem)

#define cvector_pushfront(cv,type,nelem) \
	(*(type*)cvector_paste(cv,0,1) = nelem)

#define cvector_insert(cv,type,pos,nelem) \
	(*(type*)cvector_paste(cv,pos,1) = nelem)
	
#define cvector_popback(cv) \
	((cv)->sz--)

#define cvector_popfront(cv) \
	(cvector_remove(cv,0,1))

#define cvector_foreach(it,cv) \
	for (it = (typeof(it))((cv)->data); it != ((typeof(it))((cv)->data) + (cv)->sz); it++)

#endif