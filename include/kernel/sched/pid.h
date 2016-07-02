#ifndef GENOS_PID_H
#define GENOS_PID_H

#include "inttypes.h"

typedef uint32_t pid_t;

#include "compiler.h"
#include "kernel/sched/sched.h"

__BEGIN_DECLS

pid_t getpid_new();
uint32_t pidhash(pid_t k);
int32_t pidcmp(pid_t k0, pid_t k1);

__END_DECLS

#endif