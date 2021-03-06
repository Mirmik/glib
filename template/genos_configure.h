#ifndef GENOS_CONFIGURE_H
#define GENOS_CONFIGURE_H

#define sysalloc malloc
#define sysrealloc realloc
#define sysfree free

#define GXX_DEFAULT_ALLOCATOR &gxx::mallocAllocator
#define GXX_DEFAULT_SEED 0xABCDEFAB
#define GENOS_SERIAL_ORDER PROTOORD_LITTLE

#endif