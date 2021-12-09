#include <stdio.h>
#include <string.h>
#include <ctype.h>
// cgrahl3s, kzande3s
// Das fertige Hangman Spiel
// Test:
// Ergebnis:

//Aufgabe 3
int versuche(int alter) {
    int rateVersuche;
    printf("%i\n", alter);
    if (alter < 10) {
        rateVersuche = 12;
    }
    else if (alter > 40){
        rateVersuche = 10;
    }
    else{
        rateVersuche = 8;
    }
    if (alter % 2 == 0){
        rateVersuche++;
    }
    return rateVersuche;
}


int aufgabe5(){
    int fehler;
    scanf("%i", &fehler);
    switch (fehler) {
        case 0:
            printf("Glueck gehabt, auf ein Neues!\n");
            break;
        case 1:
            printf("Der erste Galgenfuss wurde gebaut.\n");
            break;
        case 2:
            printf("Der Galgenpfahl wurde errichtet.\n");
            break;
        case 3:
            printf("Der Galgenst\x81tzbalken wurde gebaut.\n");
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
            printf("Der linke Arm des armen Manns wurde platziert.\n");
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
            printf("Sie h\x84ngen am Galgen und sind tot.\n");
            break;
        default:
            printf("WTF \n");
            break;
    }
    return 0;
}


int main() {
    char wort[255] = "";
    int alter;
    int rateVersuche;
    int fehler = 12;
    int richtigGeraten = 0;
    char eingabe;

    //  Set Lösungswort
    printf("Loesungswort eingeben: ");
    scanf("%s", wort);

    // Set Loesungswort to lower case
    for (int i = 0; i < strlen(wort); i++){
        wort[i] = tolower(wort[i]);
    }

    printf("%s\n", wort);

    // Set placerHolder string "____", genauso lange wie die Antwort
    //    F---h
    char lw[strlen(wort)];
    for (int i = 0; i < strlen(wort); i++){
        lw[i] = '_';
    }
    printf(" %s\n", lw);



    // Set alter
    printf("Alter eingeben: ");
    scanf("%i", &alter);
    rateVersuche = versuche(alter);
    // Errechne Rateversuche
    printf("rateVersuche: %i\n", rateVersuche);
    fehler = fehler - rateVersuche;
    fehlerAusgabe(fehler);


    //Aufgabe8
    //Schleife läuft solange wie fehler oder anzahl buchstaben nicht erreicht ist
    //TODO 12 durch Variable RateVersuche Richtig machen!
    while (fehler != 12 && richtigGeraten != strlen(wort)) {
        int treffer = 0;

        printf("Fehler: %i \n", fehler);
        printf("Eingabe: ");
        scanf(" %c", &eingabe);
        eingabe = tolower(eingabe);

        //vergleiche eingabe mit Antwort
        for (int i = 0; i < strlen(wort); i++){

            if (wort[i] == eingabe){
                lw[i] = eingabe;
                treffer++;
            }
        }

        //Zaehle treffer hoch
        //Todo Switch oder if Doz Fragen!
//        if(treffer > 0){
//            richtigGeraten = richtigGeraten + treffer;
//            fehlerAusgabe(fehler);
//        }
//        else{
//            fehler++;
//            fehlerAusgabe(fehler);
//        }

        switch (treffer){
            case 0:
            fehler++;
                fehlerAusgabe(fehler);
                break;
            default:
                richtigGeraten = richtigGeraten + treffer;
                fehlerAusgabe(fehler);
                break;
        }
        printf("%s\n", lw);

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