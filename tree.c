#include "adt.h"
#include "new.h"
#include "tree.h"

static void * Tree_ctor(void * _self, va_list * ap)
{
    Tree * self = _self;

    assert(self);

    self->root = NULL;
    self->height = 0;

    return self;
}

static void * Tree_dtor(void * _self)
{
    Tree * self = _self;
    struct key * curr = self->root;

    assert(self && curr);

    while(curr != NULL)
    {
        /** TODO (aawesu#1#): handle destruction of tree objects (most liely just a call to free() */
    }

    return self;
}

static int Tree_differ(const void * _self, const void * _obj)
{
    const Tree * self = _self;
    const Tree * obj = _obj;

    assert(self && obj);

    if(self == obj)
        return 0;

    if(!obj || ((obj->adt) != tree))
        return -1;

    return ((self->root == obj->root) && (self->height == obj->height));
}


static const ADT _Tree =
{
    sizeof(Tree),
    Tree_ctor,
    Tree_dtor,
    Tree_differ,
    NULL
};

const void * tree = &_Tree;

Tree * Tree_insertNode(Tree * _self, const int data)
{
    Tree * self = _self;
    struct key * temp = malloc(sizeof(struct key));

    assert(self && temp);

    temp->left = NULL;
    temp->right = NULL;
    temp->val = data;

    if(self->root == NULL)
    {
        self->root = temp;
        self->height++;
    }
    else
    {
        /** TODO (aawesu#1#): insert node left or right of the appropriate leaf node */
    }

    return self;
}

Tree * Tree_deleteNode(Tree * _self, const int data)
{
    Tree * self = _self;
    struct key * curr = self->root;

    assert(self && curr);

    /** TODO (aawesu#2#): check if value exists in tree */

    //if(exists in tree)
        //if(in root node), delete value but keep root pointer
        //else if leaf node, delete value and set pointer to NULL
        //else
            /** TODO (aawesu#2#): remove node and adjust nodes to cover empty space */
    //else, display not found message

    return self;
}

