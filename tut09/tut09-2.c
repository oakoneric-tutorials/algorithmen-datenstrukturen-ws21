/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 2
------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "print_tree.h"

/* 
typedef struct node *tree;
struct node
{
    int key;
    tree left, right;
}; 
*/

// Teil (a)

int height(tree t)
{
    if (t == NULL)
        return 0;
    int hl = height(t->left);
    int hr = heigth(t->right);
    if (hl > hr)
        return hl + 1;
    return hr + 1;
}

tree bfs(tree t)
{
    if (t == NULL)
        return NULL;
    tree bf = malloc(sizeof(struct node));
    bf->key = height(t->right) - height(t->left);
    bf->left = bfs(t->left);
    bf->right = bfs(t->right);
    return bf;
}

void lRot(tree *root)
{
    if (root == NULL || *root == NULL)
        return;

    tree rightChild = (*root)->right;
    (*root)->right = rightChild->left;
    rightChild->left = *root;
    *root = rightChild;
}

/* ----------------------------------------- */

tree createNode(int n, tree l, tree r)
{
    tree t = malloc(sizeof(struct node));
    t->left = l;
    t->right = r;
    t->key = n;
    return t;
}

int main()
{
    // zu Teil (a)
    printf("\n============ Teil (a) ========================\n");
    tree bsp =
        createNode(4,
                   createNode(5, NULL, NULL),
                   createNode(2,
                              createNode(0, NULL, NULL),
                              NULL));
    printf("bsp = \n");
    print_t(bsp);

    tree t1 = createNode(8,
                         createNode(5,
                                    createNode(3, createNode(2, NULL, NULL), createNode(4, NULL, NULL)),
                                    createNode(7, createNode(6, NULL, NULL), NULL)),
                         createNode(10,
                                    createNode(9, NULL, NULL),
                                    createNode(11, NULL, NULL)));
    printf("t1 = \n");
    print_t(t1);

    tree s = createNode(2, createNode(3, createNode(2, NULL, NULL), createNode(4, NULL, NULL)), createNode(1, NULL, NULL));
    printf("s = \n");
    print_t(s);

    tree t = createNode(2, createNode(2, NULL, NULL), createNode(3, NULL, NULL));
    printf("t = \n");
    print_t(t);

    return 0;
}