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
    struct Node * curr = self->root;

    assert(self && curr);

    while(curr != NULL)
    {
        /** TODO (aawesu#1#): handle destruction of tree objects (most likely just a call to free() */
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


/*******************************************************
********************************************************
* Helper Functions
********************************************************
********************************************************
*/

static struct Node * new_node(const int data)
{
    struct Node * node = malloc(sizeof(struct Node));

    assert(node);

    node->val = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

static struct Node * node_max(struct Node * node)
{
    struct Node * max = node;

    if (max == NULL)
        return NULL;

    while(max->right != NULL)
        max = max->right;

    return max;
}

static struct Node * node_min(struct Node * node)
{
    struct Node * min = node;

    if (min == NULL)
        return NULL;

    while(min->left != NULL)
        min = min->left;

    return min;
}

static struct Node * node_successor(struct Node * node)
{
    struct Node * temp = NULL;
    struct Node * curr = NULL;

    if(node->right != NULL)
    {
        temp = node_min(node->right);
    }

    if(temp != NULL)
    {
        curr = temp->parent;

        while((curr != NULL) && (node == curr->right))
        {
            temp = curr->right;
            curr = curr->parent;
        }
    }

    return temp;
}

static struct Node * node_predecessor(struct Node * node)
{
    struct Node * temp = NULL;
    struct Node * curr = NULL;

    if(node->left != NULL)
    {
        temp = node_max(node->left);
    }
    return temp;
}

static struct Node * update_tree(Tree * _self, struct Node * nodeToBeReplaced, struct Node * nodeToReplaceWith)
{
    return NULL;
}

/*******************************************************
********************************************************
* Class Methods (Operations)
********************************************************
********************************************************
*/

/** \brief Insert new node to the one side of last leaf node
 *
 * \param  _self: pointer to tree object
 * \param  data: key value to be stored
 * \return self: pointer to the modified tree object
 *
 */

Tree * Tree_insertNode(Tree * _self, const int data)
{
    Tree * self = _self;
    struct Node * node = new_node(data);

    assert(self && node);

    struct Node * curr = self->root;
    struct Node * temp = NULL;
    while(curr != NULL)
    {
        temp = curr;
        if(node->val <= curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(temp == NULL)
        self->root = node;
    else
    {
        node->parent = temp;
        if(node->val <= temp->val)
            temp->left = node;
        else
            temp->right = node;
    }
    self->height++;

    return self;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Tree * Tree_deleteNode(Tree * _self, const int data)
{
    Tree * self = _self;
    struct Node * curr = self->root;

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

