#include "stdio.h"
#include "StringT.h"
#include "queue.h"
#include "tree.h"
#include "new.h"
#include "version.h"

//#define QUEUE_TEST

int main(void)
{
    printf("**********************************************\n");
    printf("OOP PRACTICE - ADTs v%s\n",FULLVERSION_STRING);
    printf("**********************************************\n\n");

    #ifdef QUEUE_TEST
    struct StringT * a = new_adt(String,"Hey");
    struct StringT * b = new_adt(String, "Hi");
    struct StringT * c = new_adt(String, "Hello");
    struct StringT * d = new_adt(String, "World!");
    struct StringT * e = new_adt(String, "Let's");
    struct StringT * f = new_adt(String, "Go!");
    struct StringT * result, *result2;
    struct Queue * q = new_adt(Queue, 6, "String");

    printf("Size of a is %u\n",sizeOf(a));
    printf("Queue length is %d\n", q->nbElem);
    printf("Queue element type is %s\n", ((q->dataType == 0)?"String":"Unsupported"));

    Queue_enqueue(q, a);
    Queue_enqueue(q, b);
    Queue_enqueue(q, c);
    Queue_enqueue(q, d);
    Queue_enqueue(q, e);
    Queue_enqueue(q, f);

    printf("Size of elem struct is %u and size of queue is %u\n",sizeof(struct elem),sizeOf(q));

    Queue_displayElements(q);

    printf("%d\n", Queue_contains(q,"Go!"));

    result = (struct StringT *) Queue_dequeue(q);
    printf("%s ", result->text);
    result2 = (struct StringT *) Queue_dequeue(q);
    printf("%s\n", result2->text);

    Queue_displayElements(q);

    delete_adt(q);
    #else
    Tree * t = new_adt(tree);
    Tree * t2 = new_adt(tree);

    printf("%d\n",differ(t, t2));

    printf("Size of t is %u\n", sizeOf(t));

    Tree_insertNode(t, 15);
    Tree_insertNode(t, 5);
    Tree_insertNode(t, 25);
    Tree_insertNode(t, 17);
    Tree_insertNode(t, 1);
    Tree_insertNode(t, 16);
    Tree_insertNode(t, 38);
    Tree_insertNode(t, 30);
    Tree_insertNode(t, 28);
    Tree_insertNode(t, 35);
    Tree_insertNode(t, 40);

    Tree_deleteNode(t, 25);

    printf("%s\n", (Tree_contains(t, 17) ? "Yes":"No"));


    #endif
    return 0;
}
