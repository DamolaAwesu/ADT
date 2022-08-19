#include "adt.h"
#include "new.h"
#include "queue.h"
#include "StringT.h"
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
    const struct elem * self = _obj;
    if(sizeOf(self->data) == 16)
        return 0;
    else
        return 1;
}

static const void * Queue_getElementValue(struct elem * _element)
{
    const struct StringT * data = _element->data;
    const char * val = data->text;

    return val;
}

static const ADT _Queue =
{
    sizeof(struct Queue),
    Queue_ctor,
    Queue_dtor,
    Queue_differ,
    NULL
};
const void * Queue = &_Queue;


struct Queue * Queue_insert(struct Queue * _self, const void * _data)
{
    struct Queue * q = _self;
    void * data = (void *)_data;
    struct elem * gElement = malloc(sizeof(struct elem));

    assert(q && _data && gElement);

    gElement->data = (const void *)data;
    gElement->next = (struct elem *)NULL;

    if((Queue_checkDataType((const void *)gElement) == q->dataType))
    {
        if(q->head == NULL)
        {
            q->head = gElement;
            q->tail = q->head;
            q->elemCount++;
        }
        else if((q->elemCount < q->nbElem))
        {
            struct elem * curr = q->head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = gElement;
            q->tail = curr->next;
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

int Queue_contains(const struct Queue * _self, const void * value)
{
    const struct Queue * self = _self;
    struct elem * curr = self->head;
    int i = 0;

    while(i < self->elemCount)
    {
        if(strcmp(Queue_getElementValue(curr),value) == 0)
            return 1;
        curr = curr->next;
        i++;
    }
    return 0;
}

void Queue_displayElements(const struct Queue * _self)
{
    const struct Queue * self = _self;
    struct elem * curr = self->head;
    int i = 0;

    while(i < self->elemCount)
    {
        displayElement(curr->data);
        curr = curr->next;
        i++;
    }
}

