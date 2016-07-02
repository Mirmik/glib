#ifndef GENOS_SCHEDULER_H
#define GENOS_SCHEDULER_H

#include "compiler.h"
#include "kernel/sched/schedee.h"

#define PRIORITY_TOTAL 5
#define ERRSCHEDBLOCK -2

__BEGIN_DECLS

void scheduler_init();

void schedee_init(struct schedee* sch);

void schedee_set_ready(struct schedee* sch, int8_t opt);

void schedee_set_wait(struct schedee* sch, uint16_t state);

uint8_t schedee_is_ready(struct schedee* sch);

struct schedee* const schedee_current_get();

void schedee_current_set(struct schedee* sch);


void schedee_hashtable_registry (struct schedee* sch);

struct schedee* schedee_hashtable_find (pid_t pid);

int scheduler();

__END_DECLS

#endif