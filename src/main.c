#include <stdio.h> 
#include "avl.h"


int main () {
    
    struct AVLNode* tree = NULL;
    
    tree = AVL_add (tree, 10);
    tree = AVL_add (tree, 20);
    tree = AVL_add (tree, 30);
    tree = AVL_add (tree, 40);
    tree = AVL_add (tree, 50);
    tree = AVL_add (tree, 25);
    
    printf ("Preorder traversal of the constructed AVL tree is \n");
    printTree (tree);
    printf ("\n");
    
    return 0;
}
