#ifndef GENOS_AUTOM_SCHEDEE_H
#define GENOS_AUTOM_SCHEDEE_H

#include "compiler.h"
#include "kernel/sched/schedee.h"

struct autom_schedee
{
	struct schedee schedee;
	void(*func)(void*);
	void* arg;
};

__BEGIN_DECLS

void autom_schedee_execute(struct schedee* schedee)
{
	struct autom_schedee* asched = (struct autom_schedee*) schedee;
	asched->func(asched->arg);
}

__END_DECLS

#endif