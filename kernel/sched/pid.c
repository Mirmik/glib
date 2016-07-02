#include "kernel/sched/pid.h"

static pid_t pid_counter = 0;

pid_t getpid_new() {
	return pid_counter++;
}

uint32_t pidhash(pid_t k) {
	return k;
}

int32_t pidcmp(pid_t k0, pid_t k1) {
	return k1 - k0;
}