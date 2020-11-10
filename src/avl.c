#include <stdio.h> 
#include <stdlib.h>
#include "avl.h"
    
int height (struct AVLNode* node)
{
    if (node == NULL) return 0;
    return node->height;
}

int max (int a, int b)
{
    return (a > b) ? a : b;
}

struct AVLNode* newNode (int key)
{
    struct AVLNode* node = (struct AVLNode*) malloc (sizeof (struct AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rightRotation (struct AVLNode* y)
{
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + max (height (y->left), height (y->right));
    x->height = 1 + max (height (x->left), height (x->right));
    
    return x;
}

struct AVLNode* leftRotation (struct AVLNode* x)
{
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + max (height (x->left), height (x->right));
    y->height = 1 + max (height (y->left), height (y->right));
    
    return y;
}

int getBalance (struct AVLNode* node)
{
    if (node == NULL) return 0;
    return height (node->left) - height (node->right);
}

struct AVLNode* AVL_add (struct AVLNode* node, int key)
{
    if (node == NULL) return newNode (key);
    
    if (key < node->key) node->left = AVL_add (node->left, key);
    else if (key > node->key) node->right = AVL_add (node->right, key);
    else return node;
    
    node->height = 1 + max (height (node->left), height (node->right));
    
    int balance = getBalance (node);
    
    if ((balance > 1) && (key < node->left->key))
        return rightRotation (node); // LL
    
    if ((balance < -1) && (key > node->right->key))
        return leftRotation (node); // RR
    
    if ((balance > 1) && (key > node->left->key))
    {
        node->left = leftRotation (node->left);
        return rightRotation (node); // LR
    }
    
    if ((balance < -1) && (key < node->right->key))
    {
        node->right = rightRotation (node->right);
        return leftRotation(node);
    }
    
    return node;
}

void printTree (struct AVLNode* node)
{
    if (node != NULL)
    {
        printf ("%d ", node->key);
        printTree (node->left);
        printTree (node->right);
    }
} 
