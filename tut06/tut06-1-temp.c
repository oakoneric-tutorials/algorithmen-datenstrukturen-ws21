/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 1
------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h> // benötigt für malloc

typedef struct element *list;
struct element
{
    int value;
    list next;
};

void append(list *lp, int n)
{
}

// zwei nuetzliche hilfsfunktionen, die nicht gefordert waren

// hilsfunktion zur erzeugung von listen:
list cons(int n, list next)
{
    list l = malloc(sizeof(struct element));
    /* reserviere speicher für ein listenelement */
    l->value = n;   /* trage key ein */
    l->next = next; /* pointer auf nächstes listenelement bzw. restliste */
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
    /* erstelle eine liste [4,2,0] */
    // list l2 = cons(4, cons(2, cons(0, NULL)));

    // printf("l: ");
    // printList(l);

    // printf("sum_rec(l): %d\n", sum_rec(l));
    // printf("sum_it(l): %d\n\n", sum_it(l));

    // rmEvens_rec(&l);
    // printf("l: ");
    // printList(l);

    return 0;
}