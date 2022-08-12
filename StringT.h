#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

struct String{
    const void * adt;
    char * text;
};

extern const void * String;

#endif // STRING_H_INCLUDED
