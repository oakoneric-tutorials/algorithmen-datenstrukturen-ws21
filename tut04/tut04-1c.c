/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 1 c
------------------------------------------------------------------------------
*/

#include <stdio.h>

int main(){
    int i,j,n;
    scanf("%d", &n);
    
    for ( i=1; i<=n ; i=i+1 ) {
        for ( j=1; j<=n ; j=j+1 ) {
            printf("%4d", i*j);
        }
        printf("\n");
    }
    return 0;
}