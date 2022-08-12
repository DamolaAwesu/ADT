#include "adt.h"
#include "new.h"
#include "StringT.h"

static void * String_ctor(void * _self, va_list* ap)
{
    struct String * self = _self;

    const char * text = va_arg(*ap, const char *);

    self->text = malloc(strlen(text)+1);
    assert(self->text);
    strcpy(self->text, text);

    return self;
}

static void * String_dtor(void * _self)
{
    struct String * self = _self;

    free(self->text); self->text = 0;

    return self;
}

static int String_differ(const void * _self, const void * _obj)
{
    const struct String * self = _self;
    const struct String * obj = _obj;

    assert(self && obj);

    if(self == obj)
        return 0;

    if(!obj || (obj->adt != String))
        return 1;

    return strcmp(self->text, obj->text);
}

static const ADT _String =
{
    sizeof(struct String),
    String_ctor,
    String_dtor,
    String_differ
};
const void * String = &_String;
