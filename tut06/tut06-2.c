/*
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze
Github: https://github.com/oakoneric/algorithmen-datenstrukturen-ws20
Website: https://oakoneric.github.io/aud20.html
------------------------------------------------------------------------------
Aufgabe 2
------------------------------------------------------------------------------
*/

#include <stdlib.h> // benötigt für malloc
#include <stdio.h>

typedef struct element *list;
struct element { int value; list next; };

void append(list *lp, int n){
    while(*lp != NULL)
        lp = &((*lp)->next) ;
            /* gehe bis zum ende der liste */

    (*lp) = malloc(sizeof(struct element));
        /* erstelle ein neues element */
    (*lp)->value  = n;
        /* fuelle den neuen container mit inhalt */
    (*lp)->next = NULL;
}

int sum_rec(list l) {
    if (l == NULL) return 0;
        /* nach letztem element nichts mehr addieren */

    return l->value + sum_rec(l->next);
        /* nehme immer einen key und addiere die summe der restliste */
}

int sum_it(list l) {
    int result = 0;

    while (l != NULL) {
        result += l->value; /* result = result + l -> value */
        l = l->next;        /* schalte "start"zeiger ein element weiter */
    }
    return result;
}


/*
problem: beim löschen des ersten listenelements geht der zugriff auf die liste verloren
ausweg: pointer auf pointer - erster pointer hält stets listenanfang fest
*/

void rmEvens_rec(list *lp) { /* *lp heißt: wir übergeben einen pointer (list pointer) */
    if (lp == NULL || *lp == NULL) return ;
    /* keine liste oder liste leer */

    if ((*lp)->value % 2 == 0) {
        list tmp = *lp;
        /* speicherung des zu löschenden elements (um speicher dann zu befreien, sonst speicherleichen) */
        *lp = (*lp)->next;
        /* weiterschalten des ersten pointers */
        free(tmp);
        /* speicher des zu löschenden elements befreien */
    } else {
        lp = &(*lp)->next;
        /* startpointer weiterschalten - kein löschen notwendig */
    }

    rmEvens_rec(lp);    /* verfahre so weiter mit der restlichen liste */
}

void rmEvens_it(list *lp) {
    while (lp != NULL && *lp != NULL) {
        if ((*lp)->value % 2 == 0) {
            list tmp = *lp;
            *lp = (*lp)->next;
            free(tmp);
        } else
            lp = &(*lp)->next;
    }
}

list odds(list lp){
    list erg = NULL; /* erzeuge neue liste - alte soll nicht verändert werden */

    while (lp != NULL ){            /* gehe durch ganze liste durch */
        if (lp->value % 2 != 0){    /* prüfe ob ungerade schluessel */
            append(&erg, lp->value);/* hänge ungerade schluessel an neue liste an */
        }
        lp = lp->next;              /* gehe in jedem fall ein element weiter */
    }
    return erg;
}


// zwei nuetzliche hilfsfunktionen, die nicht gefordert waren

// hilsfunktion zur erzeugung von listen:
list cons(int n, list next) {
    list l = malloc(sizeof(struct element));
                                 /* reserviere speicher für ein listenelement */
    l->value = n;                /* trage key ein */
    l->next = next;              /* pointer auf nächstes listenelement bzw. restliste */
    return l;
}

// hilfsfunktion zur ausgabe von listen:
void printList(list l) {
    printf("[");
    while(l) {    /* solange liste nicht leer ist (listpointer nicht null*/
        printf("%d", l->value);     /* ausgabe des keys */
        if(l->next) printf(", ");   /* wenn noch weitere elemente existieren (next-pointer nicht null */
        l = l->next;                /* pointer weiterschalten um restliste auszugeben */
    }
    printf("]\n");
}



int main() {
    /* erstelle eine liste [4,2,0,1] */
    list l = NULL;
    append(&l, 4);
    append(&l, 2);
    append(&l, 0);
    append(&l, 1);
    // list l2 = cons(4, cons(2, cons(0, cons(1, NULL))));

    printf("l: ");
    printList(l);

    printf("sum_rec(l): %d\n", sum_rec(l));
    printf("sum_it(l): %d\n\n", sum_it(l));

    list newList = odds(l);
    printf("newList: ");
    printList(newList);

    rmEvens_rec(&l);
    printf("l: ");
    printList(l);

    return 0;
}