#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct Node Node;

typedef struct {
    const void * adt;
    struct Node * root;
    int height;
}Tree;

extern const void * tree;

int Tree_contains(Tree * self, const int value);
Tree * Tree_insertNode(Tree * _self, const int _data);
Tree * Tree_deleteNode(Tree * _self, const int _data);

#endif // TREE_H_INCLUDED
