#ifndef NEW_H_INCLUDED
#define NEW_H_INCLUDED

#include "stdarg.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"

void * new_adt(const void * _adt,...);
void delete_adt(void * self);
int differ(const void * self, const void * obj);
size_t sizeOf(const void * self);
#endif // NEW_H_INCLUDED
