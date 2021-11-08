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

void palindrom(char str[], int l, int *korrekt) {
    int i = 0;
    l = l - 1;
    *korrekt = 1;
    
    while (i < l && *korrekt) {
        *korrekt = str[i] == str[l];
        i = i + 1;
        l = l - 1;
    }
} // kein return wegen void

int palindrom2(char str[], int lo, int hi) {
    if (hi <= lo) return 1;
    if (str[lo] != str[hi]) return 0;
    return palindrom2(str, lo + 1, hi - 1);
} 


int main() {
    #define ANZ 20

    char str[ANZ];
    int korr;

    // Einlesen und Prüfen der Eingabe
    scanf("%[^\n]s", str);
    printf("str = %s\n",str);

    // berechne Länge des Strings
    int len = 0;
    while(str[len] != '\0')
        len++; 

    // fuer iterative Variante
    printf("iterative Variante: \n\t");
    palindrom(str, len, &korr);

    // drucke Palindrom-Eigenschaft aus
    if(korr == 1)
        printf("%s ist ein Palindrom.\n", str);
    else
        printf("%s ist kein Plaindrom.\n", str);
    
    // fuer rekursive Variante
    printf("rekursive Variante: \n\t");
    korr = palindrom2(str, 0, len - 1);
    if(korr == 1)
        printf("%s ist ein Palindrom.\n", str);
    else
        printf("%s ist kein Plaindrom.\n", str);

    return 0;
}