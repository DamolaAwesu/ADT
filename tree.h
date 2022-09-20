#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "stdint.h"

typedef struct Node Node;

typedef struct {
    const void * adt;
    struct Node * root;
    uint32_t height;
}Tree;

extern const void * tree;

uint8_t Tree_contains(Tree * self, const uint32_t value);
Tree * Tree_insertNode(Tree * _self, const uint32_t _data);
Tree * Tree_deleteNode(Tree * _self, const uint32_t _data);

#endif // TREE_H_INCLUDED
