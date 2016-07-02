#include <kernel/panic.h>
#include <kernel/sched/sched.h>
#include <util/bits.h>

#include "genos/container/dlist.h"
#include "genos/container/hashtable.h"

#include "kernel/sched/pid.h"

char hashbuf[sizeof(hlist_head) * 20];
hashtable<struct schedee, &schedee::hnode, pid_t, &schedee::pid> schedee_hashtable;

struct schedee* volatile __current_schedee;

dlist<schedee,&schedee::lnk> runlist[PRIORITY_TOTAL];
dlist<schedee,&schedee::lnk> stoplist;

uint8_t __nonschedule = 0;

void scheduler_init() {
	schedee_hashtable.init(
		hashbuf,
		sizeof(hlist_head)*20,
		pidhash,
		pidcmp
		);
}

void schedee_set_ready(struct schedee* sch, int8_t opt) {
	//debug_printbin_uint16(bits_mask(SCHEDEE_READY,SCHEDEE_STATE_MASK));dln();
	bits_mask_assign(sch->flags,SCHEDEE_STATE_MASK,SCHEDEE_READY);
	//debug_printbin_uint16(sch->flags);dln();
	int8_t prio = sch->dyn_prio;
	if (opt)
		runlist[sch->dyn_prio].push_front(*sch);
	else
		runlist[sch->dyn_prio].push_back(*sch);		
};

uint8_t schedee_is_ready(struct schedee* sch)
{
	//debug_printbin_uint16(sch->flags);
	return bits_mask(sch->flags,SCHEDEE_READY);
};

void schedee_init(struct schedee* sch) {
	dlist_init_list(&sch->lnk);
	//sch->hnode = 0;
	sch->pid = getpid_new();
	schedee_hashtable_registry(sch);
};

void schedee_set_wait(struct schedee* sch, uint16_t state) {
	bits_mask_assign(sch->flags,SCHEDEE_STATE_MASK,state);
	stoplist.push_front(*sch);
};

struct schedee* const schedee_current_get() {
	return __current_schedee;
}

void schedee_current_set(struct schedee* sch) {
	__current_schedee = sch;
}

void schedee_current_block(uint16_t state) {
	struct schedee* sch = schedee_current_get();
	schedee_set_wait(sch,state);
	if (bits_mask(sch->flags, SCHEDEE_NONPREEMPTIBLE)) 
		return;
	else 
		scheduler();
	return;
}

void schedee_hashtable_registry (struct schedee* sch) {
	schedee_hashtable.put(*sch);
}

struct schedee* schedee_hashtable_find (pid_t pid) {
	return schedee_hashtable.get(pid);
}

int scheduler() {
	if (__nonschedule) return ERRSCHEDBLOCK;

	int priolvl;
	for (priolvl = PRIORITY_TOTAL - 1; priolvl > 0; --priolvl)
	{
		if (!runlist[priolvl].is_empty()) goto runschedee;
	}
	panic("nobody to run");

	runschedee:
	struct schedee* sch = &*runlist[priolvl].begin();
	sch->ops->execute(sch);

	if (schedee_is_ready(sch)) 
		runlist[sch->dyn_prio].push_back(*sch);
};