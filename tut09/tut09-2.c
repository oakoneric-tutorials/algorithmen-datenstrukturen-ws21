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
In print_tree.h bzw. print_tree.c wird eine Ausgabe für Baeume definiert (c) Joshua Uhlig.
Compile mit "gcc print_tree.c tut09-2.c -o tut09-2" (print_tree.h und print_tree.c im gleichen Verzeichnis wie tut09-2.c).
Die dafuer notwendige Datenstruktur (tree und struct node) wurde mit ausgelagert und ist daher hier auskommentiert.

*/

/* 
typedef struct node *tree;
struct node
{
    int key;
    tree left, right;
}; 
*/

/* ----------------------------------------- */
/* Hilfsfunktion zum Erstellen von Baeumen   */

tree createNode(int n, tree l, tree r)
{
    tree t = malloc(sizeof(struct node));
    t->left = l;
    t->right = r;
    t->key = n;
    return t;
}

/* ----------------------------------------- */

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

    int b = height(t->right) - height(t->left);
    tree bf = createNode(b, bfs(t->left), bfs(t->right));

    /*
    tree bf = malloc(sizeof(struct node));
    bf->key = height(t->right) - height(t->left);
    bf->left = bfs(t->left);
    bf->right = bfs(t->right);
    */

    return bf;
}

// Teil (b)

void lRot(tree *tp)
{
    if (tp == NULL || *tp == NULL)
        return;

    tree rightChild = (*tp)->right;  // sichere Zugriff auf (altes) rechtes Kind der alten Wurzel
    (*tp)->right = rightChild->left; // Umklappen des inneren Astes
    rightChild->left = *tp;          // alte Wurzel wird zum linken Kind der neuen Wurzel (= altes rechtes Kind)
    *tp = rightChild;                // setze neue Wurzel
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