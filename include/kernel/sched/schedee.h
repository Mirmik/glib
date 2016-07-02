#ifndef GENOS_SCHEDEE_H
#define GENOS_SCHEDEE_H

#include "inttypes.h"
#include "genos/datastruct/dlist_head.h"
#include "genos/datastruct/hlist_head.h"
#include "kernel/sched/pid.h"

#define SCHEDEE_READY 			0x0001
#define SCHEDEE_STOP			0x0002
#define SCHEDEE_BLOCKED_SEND 	0x0004
#define SCHEDEE_BLOCKED_RECEIVE	0x0008
#define SCHEDEE_BLOCKED_REPLY	0x0010
#define SCHEDEE_ZOMBIE			0x0020

#define SCHEDEE_STATE_MASK		0x003F
#define SCHEDEE_STATE_WAIT_MASK	0x001E
//#define SCHEDEE_
//#define SCHEDEE_UNINTERATIBLE	0x0100

//Флаг указывает, что передачу управления диспетчеру при
//вызове блокирующих операций процесс берёт на себя.
//Кроме того, он не может вытесняться.
#define SCHEDEE_NONPREEMPTIBLE	0x1000

struct schedee;

struct schedee_operations
{
	void (*execute)(struct schedee*);
};

struct schedee {
	struct dlist_head lnk;
	struct hlist_node hnode;
	pid_t pid;
	uint16_t flags;
	struct schedee_operations* ops;
	int8_t dyn_prio;
	int8_t sta_prio;
};

#endif