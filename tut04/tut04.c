/*
* Algorithmen & Datenstrukturen
* Übung 4
* Eric Kunze
* Website: oakoneric.github.io/aud21
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, number, guess, t, m;
    n = scanf("%d", &n);
    srand(time(0));
    number = 1 + rand() % n;

    while (1)
    {
        printf("Zahl raten: ");
        scanf("%d", &guess);

        if (guess == number)
        {
            printf("Gewonnen!\n");
            break;
        }
        else if (number < guess)
        {
            printf("Die echte Zahl ist kleiner.\n");
        }
        else
        {
            // number > guess
            printf("Die echte Zahl ist größer.\n");
        }
    }
}