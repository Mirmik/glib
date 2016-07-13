#ifndef EVIDENT_TYPES_H
#define EVIDENT_TYPES_H

#include "inttypes.h"
#include "defines/atomic_t.h"
#include "gxx/container/hashtable.h"
#include "gxx/string.h"
#include "gxx/to_string.h"
#include "util/retype.h"
#include "genos/evident/typeid.h"
#include "genos/evident/eviclass.h"

static struct memevi* memevi_construct(evident_class* eclass, size_t datasize);
static struct memevi* memevi_destruct(struct memevi* me);

struct memevi {
	atomic_t refs;
	evident_class* eclass;
	void* data;
};

class evident {
public:
	memevi* mevi;
protected:
	evident(){};

	evident(memevi* m) {
		mevi = m;
		m->refs++;
	}

public:
	~evident() {
		mevi->refs--;
//		if (mevi->refs == 0) memevi_destruct(mevi);	
	}

	evident operator+(const evident& rhs) {
//		auto m = memevi_construct("int32", sizeof(int32_t));
//		return evident(m);
	}

	gxx::string to_str() const {
	}
};

template<typename type>
class evi : public evident {
private:
	void init() {
//		mevi = memevi_construct(evitype<type>::name, sizeof(type));
		mevi->refs++;
	};

public:
	evi() : evident() {
		init();
		*(type*)mevi->data = 0;
	}

	evi(const type& val) : evident() {
		init();
		*(type*)mevi->data = val;
	} 

};

static struct memevi* memevi_construct(const char* type, size_t datasize) {
	RETYPE(struct memevi*, me, malloc(sizeof(struct memevi)));
	me -> data = malloc(datasize);
	//me -> type = type;
	me -> refs = 0;
	return me;
};

static struct memevi* memevi_destruct(struct memevi* me) {
	free(me -> data);
	free(me);
};

#endif