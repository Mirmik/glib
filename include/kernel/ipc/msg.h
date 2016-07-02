#ifndef GENOS_MESSAGE_IPC
#define GENOS_MESSAGE_IPC

#include "compiler.h"
#include "defines/size_t.h"
#include "kernel/sched/sched.h"


__BEGIN_DECLS

void Send(pid_t pid, void* smsg, size_t slen, 
						void* rmsg, size_t rlen);

pid_t Recv(pid_t from, void* msg, size_t mlen);

pid_t Crecv(pid_t from, void* msg, size_t mlen);

void Reply(pid_t pid, void* reply, size_t rlen);

   // Creceivemx();
   // Readmsgmx();
   // Receivemx();
   // Replymx();
   // Sendmx();
   // Writemsgmx().

//qnx_proxy_attach()
//Trigger

__END_DECLS

#endif