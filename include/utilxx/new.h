#ifndef PLACEMENT_NEW_H
#define PLACEMENT_NEW_H

#include "defines/size_t.h"

void * operator new(size_t, void *ptr);

#endif