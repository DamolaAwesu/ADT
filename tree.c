#include "adt.h"
#include "new.h"
#include "tree.h"

struct Node {
    int val;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};

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

    assert(self);

    while(self->root != NULL)
    {
        self = Tree_deleteNode(self,self->root->val);
    }

    return self;
}

static uint8_t Tree_differ(const void * _self, const void * _obj)
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

static void Tree_inorder(struct Node * root)
{
    if(root != NULL)
    {
        Tree_inorder(root->left);
        printf("%d ", root->val);
        Tree_inorder(root->right);
    }
}

static void Tree_preorder(struct Node * root)
{
    if(root != NULL)
    {
        printf("%d ", root->val);
        Tree_preorder(root->left);
        Tree_preorder(root->right);
    }
}

static void Tree_postorder(struct Node * root)
{
    if(root != NULL)
    {
        Tree_postorder(root->left);
        Tree_postorder(root->right);
        printf("%d ", root->val);
    }
}

static void Tree_displayElements(const void * _self, va_list * ap)
{
    const Tree * self = _self;
    const char * traversalType = va_arg(*ap, const char *);

    struct Node * root = self->root;

    assert(self && root);

    if(strcmp(traversalType,"inorder"))
    {
        Tree_inorder(root);
        printf("\n");
    }
    else if(strcmp(traversalType,"preorder"))
    {
        Tree_preorder(root);
        printf("\n");
    }
    else if(strcmp(traversalType,"postorder"))
    {
        Tree_postorder(root);
        printf("\n");
    }
    else
    {
        printf("Invalid tree traversal mode\n");
    }
}

static uint32_t Tree_length(const void * _self)
{
    const Tree * self = _self;

    assert(self);

    return (self->height);
}

static const ADT _Tree =
{
    sizeof(Tree),
    Tree_ctor,
    Tree_dtor,
    Tree_differ,
    Tree_displayElements,
    Tree_length
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

    if(node->right != NULL)
    {
        temp = node_min(node->right);
    }
    else
    {
        temp = node;
    }

    return temp;
}

static struct Node * node_predecessor(struct Node * node)
{
    struct Node * temp = NULL;

    if(node->left != NULL)
    {
        temp = node_max(node->left);
    }
    return temp;
}

static struct Node * Tree_findNodeInTree(Tree * self, const int data)
{
    struct Node * curr = self->root;

    while((curr != NULL)&&(data != curr->val))
    {
        if(data < curr->val)
        {
            curr = curr->left;
        }
        else if(data > curr->val)
        {
            curr = curr->right;
        }
    }
    return curr;
}

static Tree * update_tree(Tree * self, struct Node * nodeToBeReplaced, struct Node * nodeToReplaceWith)
{
    assert(self && nodeToBeReplaced);

    if(nodeToBeReplaced->parent == NULL)
    {
        self->root = nodeToReplaceWith;
    }
    else if(nodeToBeReplaced->parent->left == nodeToBeReplaced)
    {
        nodeToBeReplaced->parent->left = nodeToReplaceWith;
    }
    else if(nodeToBeReplaced->parent->right == nodeToBeReplaced)
    {
        nodeToBeReplaced->parent->right = nodeToReplaceWith;
    }

    if(nodeToReplaceWith != NULL)
    {
        nodeToReplaceWith->parent = nodeToBeReplaced->parent;
    }

    return self;
}

/*******************************************************
********************************************************
* Class Methods (Operations)
********************************************************
********************************************************
*/

uint8_t Tree_contains(Tree * self, const uint32_t value)
{
    struct Node * node = Tree_findNodeInTree(self, value);

    if(node != NULL)
        return 1;
    else
        return 0;
}

/** \brief Insert new node to the one side of last leaf node
 *
 * \param  _self: pointer to tree object
 * \param  data: key value to be stored
 * \return self: pointer to the modified tree object
 *
 */

Tree * Tree_insertNode(Tree * _self, const uint32_t data)
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

Tree * Tree_deleteNode(Tree * _self, const uint32_t data)
{
    Tree * self = _self;
    assert(self);

    struct Node * node = Tree_findNodeInTree(self, data);
    assert(self && node);

    if(node->left == NULL)
    {
        update_tree(self, node, node->right);
    }
    else if(node->right == NULL)
    {
        update_tree(self, node, node->left);
    }
    else
    {
        struct Node * successor = node_successor(node);

        if((successor->parent != node))
        {
            update_tree(self, successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        update_tree(self, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;

        free(node);
    }
    self->height--;

    return self;
}


