#include "adt.h"
#include "new.h"
#include "queue.h"

static void * Queue_ctor(void * _self, va_list * ap)
{
    struct Queue * self = _self;

    int elementNb = va_arg(*ap, int);
    const char * type = va_arg(*ap, const char *);

    assert(self && type);
    assert(elementNb);

    self->head = NULL;
    self->tail = NULL;
    self->elemCount = 0;
    self->nbElem = elementNb;
    self->dataType = (strcmp(type, "String")? 1 : 0);

    return self;
}

static void * Queue_dtor(void * self)
{
    return self;
}

static int Queue_differ(const void * _self, const void * _obj)
{
    const struct Queue * self = _self;
    const struct Queue * obj = _obj;

    assert(self && obj);

    if(self == obj)
        return 0;

    if(!obj || (obj->adt != Queue))
        return -1;

    return ((self->head == obj->head) && (self->tail == obj->tail));
}

static int Queue_checkDataType(const void * _obj)
{
    const ADT* adt = _obj;
    assert(adt);

    if(adt->_size == 16)
        return 0;
    else
        return 1;
}

static const ADT _Queue =
{
    sizeof(struct Queue),
    Queue_ctor,
    Queue_dtor,
    Queue_differ
};
const void * Queue = &_Queue;


struct Queue * Queue_insert(struct Queue * _self, const void * _data)
{
    struct Queue * q = _self;
    void * data = (void *)_data;

    assert(q && data);

    struct elem * element = NULL;
    element->data = data;
    element->next = NULL;

    if((Queue_checkDataType((const void *)element) == q->dataType))
    {
        if(q->head == NULL)
        {
            q->head = element;
            q->tail = q->head;
            q->elemCount++;
        }
        else if((q->elemCount < q->nbElem))
        {
            struct elem * curr = q->head;
            while(curr != NULL)
            {
                curr = curr->next;
            }
            curr = element;
            q->tail = curr;
            q->elemCount++;
        }
        else
        {
            printf("Queue full!\n");
        }
    }
    else
    {
        printf("Invalid element!\n");
    }

    return q;
}

int Queue_contains(const struct Queue * self, const void * element)
{
    return 0;
}

