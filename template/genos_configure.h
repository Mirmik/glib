#ifndef GENOS_CONFIGURE_H
#define GENOS_CONFIGURE_H

#define sysalloc malloc
#define sysrealloc realloc
#define sysfree free

#define GQ_DEFAULT_ALLOCATOR &gQ::ctrlmalloc
#define GENOS_SERIAL_ORDER PROTOORD_LITTLE

#endif