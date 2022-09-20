#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include "stdarg.h"
#include "stddef.h"
#include "stdint.h"

typedef struct{
    uint8_t _size;
    void *(*ctor)(void * self, va_list * vlist);
    void *(*dtor)(void * self);
    uint8_t (*differ)(const void * self, const void * obj);
    void (*display)(const void * self, va_list * vlist);
    uint32_t (*length)(const void * self);
}ADT;

#endif // ADT_H_INCLUDED
