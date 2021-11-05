/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 1 b
------------------------------------------------------------------------------
*/

#include <stdio.h>

void palindrom(char feld[], int l, int *korrekt) {
    int i = 0;
    l = l - 1;
    *korrekt = 1;
    
    while(feld[l] == '\0')
        l = l - 1;

    while (i < l && *korrekt) {
        *korrekt = feld[i] == feld[l];
        i = i + 1;
        l = l - 1;
    }
} // kein return wegen void

 


int main() {
    #define ANZ 20

    char feld[ANZ];
    int korr;

    // Einlesen und Prüfen der Eingabe
    scanf("%[^\n]s", feld);
    printf("feld = %s\n",feld);
    
    // berechne Länge des Strings
    int len = 0;
    while(feld[len] != '\0')
        len++; 

    // teste Palindrom-Eigenschaft
    palindrom1(feld, len, &korr);

    // drucke Palindrom-Eigenschaft aus
    if(korr == 1)
        printf("%s ist ein Palindrom.\n", feld);
    else
        printf("%s ist kein Plaindrom.\n", feld);
    
    return 0;
}