#include "adt.h"
#include "new.h"

void * new_adt(const void * _adt, ...)
{
    const ADT* adt = _adt;
    void *new_ptr = calloc(1, adt->_size);

    assert(new_ptr);

    *(const ADT**)new_ptr = adt;

    if(adt->ctor)
    {
        va_list ap;
        va_start(ap,_adt);
        new_ptr = adt->ctor(new_ptr,&ap);
        va_end(ap);
    }

    return new_ptr;
}

void delete_adt(void * self)
{
    const ADT ** adt = self;

    if(self && *adt && (*adt)->dtor)
        self = (*adt)->dtor(self);
    free(self);
}

int differ(const void * self, const void * obj)
{
    const ADT * const * adt_ptr = self;

    assert(self && *adt_ptr && (*adt_ptr)->differ);

    return (*adt_ptr)->differ(self,obj);
}

size_t sizeOf(const void * self)
{
    const ADT * const * adt_ptr = self;

    assert(self);

    return (*adt_ptr)->_size;
}
