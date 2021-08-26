/*
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze
Github: https://github.com/oakoneric/algorithmen-datenstrukturen-ws20
Website: https://oakoneric.github.io/aud20.html
------------------------------------------------------------------------------
Aufgabe 1
------------------------------------------------------------------------------
*/

#include <stdio.h>

palindrom(char feld[], int l, int korrekt) {
    int i = 1;
    l = l - 1;
    while (i < l && korrekt) {
        korrekt = feld[i] == feld[l];
        i = i + 1;
    }
    return korrekt;
}

void palindrom1(char feld[], int l, int *korrekt) {
    int i = 0;    // muss mit 0 statt 1 initialisiert werden
    l = l - 1;
    *korrekt = 1; // muss mit 1 initialisiert werden
    while (i < l && *korrekt) {
        *korrekt = feld[i] == feld[l];
        i = i + 1;
        l = l - 1;  // l muss dekrementiert werden
    }
    // kein return, weil rueckgabetyp void
}

int palindrom2(char feld[], int lo, int hi) {
    if (hi <= lo) return 1;
    if (feld[lo] != feld[hi]) return 0;
    return palindrom2(feld, lo + 1, hi - 1);
}


int main() {
    #define ANZ 4

    char pal[4] = { 'o', 't', 't', 'o' };
    char nopal[5] = { 't', 'o', 't', 'o', 'd' };
    int ispal;
    palindrom1(pal, 4, &ispal);
    if (ispal) printf("otto ist ein Palindrom.\n");
    palindrom1(nopal, 5, &ispal);
    if (ispal) printf("totod ist ein Palindrom.\n");


    char feld[ANZ] = { 'o', 't', 't', 'o' };
    int korr;

    korr = palindrom2(feld, 0, ANZ-1);
    printf("korr = %d\n", korr);

    return 0;
}