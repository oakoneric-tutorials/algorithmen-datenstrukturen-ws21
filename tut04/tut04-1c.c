/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Github: https://github.com/oakoneric/algorithmen-datenstrukturen-ws20
Website: https://oakoneric.github.io/aud20.html
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