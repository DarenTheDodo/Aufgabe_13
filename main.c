#include <stdio.h>
#include <string.h>
// cgrahl3s, kzande3s
//
// Test:
// Ergebnis:

int aufgabe3(){
    int rateVersuche = 8;
    int alter;
    printf("Wie alt bist Du?");
    scanf("%i", &alter);
    if (alter < 10){
        rateVersuche = 12;
    }
    if (alter > 40){
        rateVersuche = 10;
    }
    if (alter % 2 == 0){
        rateVersuche++;
    }
    printf("Alter: %i", alter);
    printf("\n%i", rateVersuche);
    return 0;
}

int aufgabe5(){
    int fehler;
    scanf("%i", &fehler);
    switch (fehler) {
        case 1:
            printf("Der erste Galgenfuss wurde gebaut.\n");
            break;
        case 2:
            printf("Der Galgenpfahl wurde errichtet.\n");
            break;
        case 3:
            printf("Der Galgenstützbalken wurde gebaut.\n");
            break;
        case 4:
            printf("Der Galgenquerbalken wurde fertiggestellt.\n");
            break;
        case 5:
            printf("Das Seil wurde befestigt.\n");
            break;
        case 6:
            printf("Der Kopf des Hangman wurde aufgehangen.\n");
            break;
        case 7:
            printf("Der Rumpf des Hangman wurde gezeichnet.\n");
            break;
        case 8:
            printf("Der linke Arm des armen Manns wurde hinzugezeichnet.\n");
            break;
        case 9:
            printf("Der rechte Arm ist nun an seinem Platz.\n");
            break;
        case 10:
            printf("Das linke Bein ist nun ebenfalls sichtbar.\n");
            break;
        case 11:
            printf("Das rechte Bein ist auch vorhanden, letzte Chance!\n");
            break;
        case 12:
            printf("Sie hängen am Galgen und sind tot.\n");
            break;
        default:
            break;
    }
    return 0;
}





int main() {
    char wort[255] = "";
    int fehler = 0;
    int rateVersuche = 8;
    int richtigGeraten = 0;
    int anzahlBuchstaben = 6;
    int eingabe;


    scanf("%s", wort);

    //Aufgabe8
    //Schleife
    while (fehler != rateVersuche && richtigGeraten != anzahlBuchstaben) {
        scanf("%i", &eingabe);

        switch (eingabe) {
            case 1:
                fehler++;
                break;
            case 2:
                richtigGeraten++;
                break;
            default:
                break;
        }

    }


//Aufgabe12

    for (int i = 0; i <= strlen(wort); i++) {
        printf("%c", wort[i]);
        if (i == strlen(wort)) {
            printf("\n");
        }
    }

    return 0;
}