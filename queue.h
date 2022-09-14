#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct elem elem;

struct Queue {
    const void * adt;
    int dataType;     /* 0: for string, 1 for int */
    int nbElem;
    struct elem * head;
    struct elem * tail;
    int elemCount;
};

extern const void * Queue;

int Queue_contains(const struct Queue * _self, const void * value);
struct Queue * Queue_enqueue(struct Queue * _self, const void * _data);
void * Queue_dequeue(struct Queue * self);
//void Queue_displayElements(const struct Queue * _self);

#endif // QUEUE_H_INCLUDED
