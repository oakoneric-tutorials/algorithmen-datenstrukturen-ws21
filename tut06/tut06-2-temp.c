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

typedef struct element *list;
struct element
{
    int value;
    list next;
};

typedef struct node *tree;
struct node
{
    int key;
    tree left, right;
};

// Teil (a)
tree createNode(int n, tree l, tree r)
{
}

// Teil (b)
void insertl(tree *tp, int n)
{
}

// Teil (c)
int leafprod(tree t)
{
}

// Teil (d)

void append(list *lp, int n)
{
    while (*lp != NULL)
        lp = &((*lp)->next);
    (*lp) = malloc(sizeof(struct element));
    (*lp)->value = n;
    (*lp)->next = NULL;
}

void treeToList_rec(tree t, list *lp)
{
}

/* ----------------------------------------- */

void printTree(tree t, int depth)
{ /* ausgabe eines baumes */
    if (t)
    {
        for (int i = 0; i < depth; i++)
            printf("\t");
        printf("%d\n", t->key);
        printTree(t->left, depth + 1);
        printTree(t->right, depth + 1);
    }
}

void printList(list l)
{ /* ausgabe einer liste */
    printf("[");
    while (l)
    {
        printf("%d", l->value);
        if (l->next)
            printf(", ");
        l = l->next;
    }
    printf("]\n");
}

int main()
{
    // zu Teil (a)
    /*
    printf("\n============ Teil (a) ========================\n");
    tree bsp =
        createNode(4,
                   createNode(5, NULL, NULL),
                   createNode(2,
                              createNode(0, NULL, NULL),
                              NULL));
    printf("bsp = ");
    printTree(bsp, 0);

    tree s = createNode(2, createNode(3, createNode(2, NULL, NULL), createNode(4, NULL, NULL)), createNode(1, NULL, NULL));
    printf("s = ");
    printTree(s, 0);

    tree t = createNode(2, createNode(2, NULL, NULL), createNode(3, NULL, NULL));
    printf("t = ");
    printTree(t, 0);
    */

    // zu Teil (b)
    /*
    printf("\n============ Teil (b) ========================\n");
    insertl(&bsp, 18);
    printf("bsp = ");
    printTree(bsp, 0);
    */

    // zu Teil (c)
    /*
    printf("\n============ Teil (c) ========================\n");
    int prod = leafprod(bsp);
    printf("leafprod(bsp) = %d\n", prod);
    prod = leafprod(s);
    printf("leafprod(s) = %d\n", prod);
    prod = leafprod(t);
    printf("leafprod(t) = %d\n", prod);
    */

    // zu Teil (d)
    /*
    printf("\n============ Teil (e) ========================\n");

    printf("\ntreeToList(bsp) = ");
    printList(treeToList(bsp));

    printf("\ntreeToList(s) = ");
    printList(treeToList(s));

    printf("\ntreeToList(t) = ");
    printList(treeToList(t));
    */

    return 0;
}