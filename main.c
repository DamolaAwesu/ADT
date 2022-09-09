#include "stdio.h"
#include "StringT.h"
#include "queue.h"
#include "tree.h"
#include "new.h"
#include "version.h"

int main(void)
{
    printf("**********************************************\n");
    printf("OOP PRACTICE - STRINGS AND QUEUES v%s\n",FULLVERSION_STRING);
    printf("**********************************************\n\n");
    struct StringT * a = new_adt(String,"Hey");
    struct StringT * b = new_adt(String, "Hi");
    struct StringT * c = new_adt(String, "Hello");
    struct StringT * d = new_adt(String, "World!");
    struct StringT * e = new_adt(String, "Let's");
    struct StringT * f = new_adt(String, "Go!");

    struct Queue * q = new_adt(Queue, 6, "String");
    Tree * t = new_adt(tree);
    Tree * t2 = new_adt(tree);

    printf("%d\n",differ(t, t2));

    printf("Size of t is %u\n", sizeOf(t));

    printf("Size of a is %u\n",sizeOf(a));
    printf("Queue length is %d\n", q->nbElem);
    printf("Queue element type is %s\n", ((q->dataType == 0)?"String":"Unsupported"));

    Queue_insert(q, a);
    Queue_insert(q, b);
    Queue_insert(q, c);
    Queue_insert(q, d);
    Queue_insert(q, e);
    Queue_insert(q, f);

    printf("Size of elem struct is %u and size of queue is %u\n",sizeof(struct elem),sizeOf(q));

    Queue_displayElements(q);

    printf("%d\n", Queue_contains(q,"Go!"));

    delete_adt(q);

    return 0;
}
