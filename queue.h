#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "stdio.h"

struct elem {
    const void * data;
    struct elem * next;
};

struct Queue {
    const void * adt;
    int dataType;     /* 0: for string, 1 for int */
    int nbElem;
    struct elem * head;
    struct elem * tail;
    int elemCount;
};

extern const void * Queue;

int Queue_contains(const struct Queue * self, const void * element);

#endif // QUEUE_H_INCLUDED
