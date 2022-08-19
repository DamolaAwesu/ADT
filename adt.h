#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include "stdarg.h"
#include "stddef.h"

typedef struct{
    size_t _size;
    void *(*ctor)(void * self, va_list * vlist);
    void *(*dtor)(void * self);
    int (*differ)(const void * self, const void * obj);
    void (*display)(const void * self);
}ADT;

#endif // ADT_H_INCLUDED
