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
In print_tree.h bzw. print_tree.c wird eine Ausgabe für Bäume definiert (c) Joshua Uhlig.
Die dafür notwendige Datenstruktur wurde mit ausgelagert und ist daher hier auskommentiert.
Compile mit "gcc print_tree.c tut09-2.c -o tut09-2"
*/

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
    int hr = height(t->right);

    return (hl > hr) ? hl + 1 : hr + 1;
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

// Teil (b)

void lRot(tree *tp)
{
    if (tp == NULL || *tp == NULL)
        return;

    tree rightChild = (*tp)->right;
    (*tp)->right = rightChild->left;
    rightChild->left = *tp;
    *tp = rightChild;
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
    printf("\n============ Teil (a) ========================\n");
    tree t =
        createNode(1,
                   createNode(2,
                              NULL,
                              createNode(4, NULL, NULL)),
                   createNode(3, NULL, NULL));
    printf("t = \n");
    print_t(t);

    tree s = bfs(t);
    printf("s = bfs(t) = \n");
    print_t(s);

    printf("\n============ Teil (b) ========================\n");
    // Beispiel aus Aufgabe 1, erster Baum
    tree t2 = createNode(2,
                         createNode(1, NULL, NULL),
                         createNode(3,
                                    NULL,
                                    createNode(4,
                                               NULL,
                                               createNode(5, NULL, NULL))));
    printf("t2 = \n");
    print_t(t2);

    printf("bfs(t2) = \n");
    print_t(bfs(t2));

    printf("lRot(t2->right) = \n");
    lRot(&(t2->right));

    printf("t2 = \n");
    print_t(t2);

    printf("bfs(t2) = \n");
    print_t(bfs(t2));

    return 0;
}