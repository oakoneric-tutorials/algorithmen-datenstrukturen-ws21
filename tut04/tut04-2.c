/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 2
------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int guess, number, n;

	scanf("%u", &n);
	
    number = 1 + rand() % n;
	
    while(1) {
		printf("Zahl raten: ");
		scanf("%u", &guess);
		if (guess == number) {
			printf("Sehr gut!\n");
			return 0;
		} else if (guess > number) {
			printf("Zahl ist kleiner!\n");
		} else {
			printf("Zahl ist groesser!\n");
		}
	}
	
    return 0;
}