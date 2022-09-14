#include "adt.h"
#include "new.h"
#include "StringT.h"

static void * String_ctor(void * _self, va_list* ap)
{
    struct StringT * self = _self;

    const char * text = va_arg(*ap, const char *);

    self->text = malloc(strlen(text)+1);
    assert(self->text);
    strcpy(self->text, text);

    return self;
}

static void * String_dtor(void * _self)
{
    struct StringT * self = _self;

    free(self->text); //self->text = 0;

    return self;
}

static int String_differ(const void * _self, const void * _obj)
{
    const struct StringT * self = _self;
    const struct StringT * obj = _obj;

    assert(self && obj);

    if(self == obj)
        return 0;

    if(!obj || (obj->adt != String))
        return 1;

    return strcmp(self->text, obj->text);
}

static void String_display(const void * _self, va_list * ap)
{
    const struct StringT * self = _self;
    assert(self);

    if(self->text != NULL)
        printf("%s\n", self->text);
}

static const ADT _String =
{
    sizeof(struct StringT),
    String_ctor,
    String_dtor,
    String_differ,
    String_display
};
const void * String = &_String;
