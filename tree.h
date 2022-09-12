#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct Node {
    int val;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};

typedef struct {
    const void * adt;
    struct Node * root;
    int height;
}Tree;

extern const void * tree;

int Tree_contains(const Tree * _self, const void * value);
Tree * Tree_insertNode(Tree * _self, const int _data);
void Tree_displayElements(const Tree * _self);

#endif // TREE_H_INCLUDED
