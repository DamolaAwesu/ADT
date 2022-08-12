#include "stdio.h"
#include "StringT.h"
#include "queue.h"
#include "new.h"

int main(void)
{
    struct String * a = new_adt(String,"Hey");
    struct String * b = new_adt(String, "Hi");

    struct Queue * q = new_adt(Queue, 5, "String");

    printf("Size of a is %u\n",sizeOf(a));

    //Queue_insert(q, a);

    if(differ(a, b))
        printf("Different\n");
    printf("%s\n",a->text);

    delete_adt(a);
    delete_adt(b);


    return 0;
}
