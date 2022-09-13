#include "adt.h"
#include "new.h"
#include "queue.h"
#include "StringT.h"

/** \brief  Queue Constructor
 *
 * \param   _self: pointer to memory location for queue
 * \param   ap: variable arg list containing
 *          elementNb: number of elements queue can hold
 *          type: string specifying the element datatype
 *
 * \return  self: void pointer to new Queue instance
 *
 */

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

/** \brief Queue destructor
 *
 * \param
 * \param
 * \return
 *
 */

static void * Queue_dtor(void * _self)
{
    struct Queue * self = _self;
    struct elem * curr = self->head;

    assert(self && curr);
    while(curr != NULL)
    {
        self->head = curr->next;
        delete_adt(curr->data);
        curr = curr->next;
    }

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

static const ADT _Queue =
{
    sizeof(struct Queue),
    Queue_ctor,
    Queue_dtor,
    Queue_differ,
    NULL
};
const void * Queue = &_Queue;


/*******************************************************
********************************************************
* Helper Functions
********************************************************
********************************************************
*/

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


/*******************************************************
********************************************************
* Class Methods (Operations)
********************************************************
********************************************************
*/

struct Queue * Queue_enqueue(struct Queue * _self, const void * _data)
{
    struct Queue * q = _self;
    void * data = (void *)_data;
    struct elem * gElement = malloc(sizeof(struct elem));

    assert(q && _data && gElement);

    gElement->data = data;
    gElement->next = (struct elem *)NULL;

    if((Queue_checkDataType((const void *)gElement) == q->dataType))
    {
        clock_t start = clock();
        if(q->head == NULL)
        {
            q->head = gElement;
            q->tail = q->head;
            q->elemCount++;
        }
        else if((q->elemCount < q->nbElem))
        {
            q->tail->next = gElement;
            q->elemCount++;
            q->tail = q->tail->next;
        }
        else
        {
            printf("Queue full!\n");
        }
        clock_t stop = clock();
        double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        printf("Insert time in ms: %.4f\n", elapsed);
    }
    else
    {
        printf("Invalid element!\n");
    }

    return q;
}

void * Queue_dequeue(struct Queue * self)
{
    assert(self);

    struct elem * head = self->head;
    struct elem * new_head = head->next;

    void * data = head->data;

    self->head = new_head;
    self->elemCount--;

    return data;
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

