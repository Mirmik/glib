#include "kernel/sched/testschedee.h"
#include "kernel/sched/sched.h"
#include "util/retype.h"
#include "debug/dprint.h"

void testschedee_execute(struct schedee* sch) {
	RETYPE(struct testschedee*, tsch, sch);
	debug_print(tsch->msg);
};

struct schedee_operations testschedee_ops = {
	.execute = testschedee_execute
};

void testschedee_init(struct testschedee* tsch) {
	schedee_init(&tsch->sch);
	tsch->sch.flags = SCHEDEE_NONPREEMPTIBLE;
	tsch->sch.sta_prio = tsch->sch.dyn_prio =
		PRIORITY_TOTAL - 1; 
	tsch->sch.ops = &testschedee_ops;
};

void debug_print_testschedee(struct testschedee* tsch) {
	debug_printhex_ptr(tsch); dln();
}