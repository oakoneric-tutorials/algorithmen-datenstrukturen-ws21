#include <stdio.h>
#include <stdlib.h>

typedef struct element *list;
struct element {
    int value;
    list next;
};


void print(list lp) {
    printf("[");
    
    while(lp != NULL) {
        printf("%d, ", lp->value);
        lp = lp->next;
    }
    
    printf("]\n");
}


// einfache Referenzen - Problem: leere Liste
void append_p(list lp, int n) {
    while(lp->next != NULL)
        lp = lp->next;

    struct element *c = malloc(sizeof(struct element));
    c->value = n;
    c->next = NULL;
    
    lp->next = c;
}


/*
// erster Ausweg: beachtet leere Listen
void append_p(list lp, int n) {
    while(lp != NULL)
        lp = lp->next;
    
    struct element *c = malloc(sizeof(struct element));
    c->value = n;
    c->next = NULL;
    
    lp = c;
}
*/


// doppelte Referenzen
void append_pp(list *lp, int n) {
    while(*lp != NULL)
        lp = &(*lp)->next;

    struct element *c = malloc(sizeof(struct element));
    c->value = n;
    c->next = NULL;

    *lp = c;
}


int main(void) {
    list l = NULL;
    
    /*
    append_p(l, 4);
    append_p(l, 2);
    */

    append_pp(&l, 4);
    append_pp(&l, 2);
    
    print(l);
}
