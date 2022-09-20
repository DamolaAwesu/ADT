#ifndef NEW_H_INCLUDED
#define NEW_H_INCLUDED

#include "stdarg.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"
#include "time.h"
#include "stdio.h"

void * new_adt(const void * _adt,...);
void delete_adt(void * self);
uint8_t differ(const void * self, const void * obj);
void displayElement(const void * self, ...);
uint8_t sizeOf(const void * self);
uint32_t get_length(const void * self);
#endif // NEW_H_INCLUDED
