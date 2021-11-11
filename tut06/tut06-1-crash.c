/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 1
------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct element *list;
struct element
{
    int value;
    list next;
};

/*
problem: beim löschen des ersten listenelements geht der zugriff auf die liste verloren
ausweg: pointer auf pointer - erster pointer hält stets listenanfang fest
*/

void rmEvens_it(list lp)
{
    while (lp != NULL)
    {
        if (lp->value % 2 == 0)
        {
            list tmp = lp;
            lp = lp->next;
            free(tmp);
        }
        else
            lp = lp->next;
    }
}

// alternative zur erzeugung von listen:
list cons(int n, list next)
{
    list l = malloc(sizeof(*l)); /* reserviere speicher für ein listenelement */
    l->value = n;                /* trage key ein */
    l->next = next;              /* pointer auf nächstes listenelement bzw. restliste */
    return l;
}

// hilfsfunktion zur ausgabe von listen:
void printList(list l)
{
    printf("[");
    while (l)
    {                           /* solange liste nicht leer ist (listpointer nicht null*/
        printf("%d", l->value); /* ausgabe des keys */
        if (l->next)
            printf(", "); /* wenn noch weitere elemente existieren (next-pointer nicht null */
        l = l->next;      /* pointer weiterschalten um restliste auszugeben */
    }
    printf("]\n");
}

int main()
{
    /* erstelle eine liste [4,2,0,1] */
    list l = cons(4, cons(2, cons(0, cons(1, NULL))));

    printf("l: ");
    printList(l);

    rmEvens_it(l);
    printf("l: ");
    printList(l);

    // tipp: ausfuehrung in der commandozeile mit strg+c abbrechen ;)

    return 0;
}