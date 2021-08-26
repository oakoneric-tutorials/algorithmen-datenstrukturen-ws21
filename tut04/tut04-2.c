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

#include <stdio.h>

int main() {
    int matches, turn;
    int z;
    
    scanf("%d", &matches);
    turn = 1;
    
    while ( matches > 0 ){
        if (turn == 1){
            // Zug des Computers
            z = (matches - 1) % 4;
            if (z == 0)
                z = 1;
            matches = matches - z;
            turn = 0;
            // Bekanntgabe der verbleibenden Streichhoelzer
            printf("Der Computer zog %d Strichhoelzer;\n", z);
            printf("somit verbleiben %d Streichhoelzer.\n", matches);
        } else {
            // Zug des Menschen
            scanf("%d", &z);
            matches = matches - z;
            turn = 1;
        }
    }
    
    // Bekanntgabe des Gewinners
    if (turn == 1)
        printf("Der Computer gewinnt.");
    else
        printf("Der Mensch gewinnt.");
    
    return 0;
}
