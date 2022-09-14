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


    displayElement(q);

    printf("%d\n", Queue_contains(q,"Go!"));

    Queue_dequeue(q);
    Queue_dequeue(q);

    displayElement(q);

    delete_adt(q);
    #else
    Tree * t = new_adt(tree);
    Tree * t2 = new_adt(tree);
    int arr[10];

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand()%100;
        Tree_insertNode(t, arr[i]);
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("%d\n",differ(t, t2));

    printf("Size of t is %u\n", sizeOf(t));

    Tree_deleteNode(t, arr[4]);

    printf("%s\n", (Tree_contains(t, arr[4]) ? "Yes":"No"));

    displayElement(t,"inorder");
    #endif

    return 0;
}
