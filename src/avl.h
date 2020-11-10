#ifndef AVL_H
#define AVL_H

struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
}; 

struct AVLNode* newNode (int key);

struct AVLNode* rightRotation (struct AVLNode* y);

struct AVLNode* leftRotation (struct AVLNode* x);

struct AVLNode* AVL_add (struct AVLNode* node, int key);

void printTree (struct AVLNode* node);

int height (struct AVLNode* node);

int getBalance (struct AVLNode* node);

int max (int a, int b);

#endif
