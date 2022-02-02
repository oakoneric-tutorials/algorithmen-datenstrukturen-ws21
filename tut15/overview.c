#include <stdio.h>  // Bibliothek stdio.h für Input/Output einbinden
#include <stdlib.h> // Bibliothek stdlib.h z.B. für Speichermanagement (malloc)

int main () {  // main-Funktion: Kern des Programms, Rückgabe int (Fehlercode), keine Argumente
    int i;     // Variablendeklaration
    i = 1;     // Zuweisung, geht nur, wenn i bereits deklariert ist
    int j = 2; // Deklaration und Zuweisung in einem Schritt

    // OUTPUT
    printf("%d", i);    // Ouput: "%d" ist ein Formatstring, %d ist Platzhalter für eine int-Variable; i ist Variable, die an diese Stelle gedruckt wird
    printf("\nDie Variable i hat den Wert %d.\n", i); // Output in schön, \n steht für linebreak

    // INPUT
    int x;
    scanf("%d", &x);    // Nutzer muss Wert eingeben; Eingabe wird im Format %d erwartet und an Adresse von x (&x) geschrieben
    printf("x hat jetzt den Wert %d. \n", x);

    // SCHLEIFEN
    for (int k = 0; k <= 5; k++){   // k läuft von 0 bis 5 alle Werte durch und wird in jedem Schritt um eins vergrößert (k++); k ist nur in der Schleife sichtbar
        printf("Aktueller Wert von k = %d. \n", k);
    }
    // Beispiel: Summe aller geraden Zahlen zwischen 0 und 20
    int sum = 0;     // Speichervariable incl Initialisierung für die Zwischensumme
    for (int k = 0; k <= 20; k = k + 2){
        sum += k;   // Kurzschreibweise für sum = sum + k; in jedem Schritt wird ein neues k zur Zwischensumme addiert
    }
    printf("Die Summe ist %d. \n", sum);

    // Beispiel: Nutzereingabe bis Produkt 100 überschritten ist
    int zahl, prod = 1;
    while (prod <= 100){        // Abbruchbedingung wird direkt geprüft (Achtung, dafür muss prod definiert sein)
        scanf("%d", &zahl);     // neue Zahl einlesen
        prod *= zahl;           // neues Produkt berechnen (kurz für prod = prod * zahl)
    }
    printf("Das Produkt ist jetzt %d.\n", prod);

    // Beispiel: Nutzereingabe bis Produkt 100 überschritten ist
    int new_zahl, new_prod = 1;
    do {
        scanf("%d", &new_zahl);
        new_prod *= new_zahl;
    } while (new_prod <= 100);      // Abbruchbedingung wird erst am Ende geprüft 
    printf("Das Produkt ist jetzt %d.\n", new_prod);

    // ARRAYS
    int arr[5];     // definiert einen Array mit 5 Zellen (indiziert mit 0, ..., 4)
    arr[2] = 9;     // setzt den Wert der dritten Zelle in arr auf 9

    int vec[] = {1,4,7,2,6};       // definiert einen Array vec mit 5 Einträgen wie angegeben
    
    printf("\nvec = ");
    for (int k = 0; k < 5; k++)    // Ausgabe des Arrays vec (Achtung: k < 5 oder k <= 4 notwendig wegen Indizierung bei Null beginnend)
        printf("%d, ", vec[k]);    // bei einzeiligen Schleifenrümpfen können { } weggelassen werden

    printf("\narr = ");
    for (int k = 0; k < 5; k++)    // Ausgabe des Arrays vec (Achtung: k < 5 oder k <= 4 notwendig wegen Indizierung bei Null beginnend)
        printf("%d, ", arr[k]);

    // CHARACTERS & STRINGS
    // Strings sind Arrays mit Character Einträgen

    char symbol = 'k';      // ein einzelnes Symbol in einfachen Anführungszeichen

    char wort[] = "Hallo";  // Deklaration und Initialisierung mittels doppelten Anführungszeichen
    printf("\n%s", wort);   // Formatangabe %s druckt ganzen String aus

    wort[2] = symbol;       // ändere den dritten Buchstaben auf Symbol
    printf("\n%s", wort);

    printf("\n");   // nur damit der Output schön aussieht

    return 0;       // nicht notwendig; 0 steht für "kein Fehler aufgetreten"
}