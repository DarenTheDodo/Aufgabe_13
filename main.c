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


int fehlerAusgabe(int fehler){
    switch (fehler) {
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
            printf("Gl\x81""ck gehabt, auf ein Neues!\n");
            break;
    }
    return 0;
}


int main() {
    int bool = 1;
    while (bool == 1) {
        char wort[255] = "";
        char wort2[255] = "";
        int alter;
        int rateVersuche;
        int fehler = 12;
        int richtigGeraten = 0;
        char eingabe;
        int anzbuch;

        //  Set L??sungswort
        printf("L\x94sungswort eingeben: ");
        scanf(" %s", wort);
        strcpy(wort2, wort);
        anzbuch= strlen(wort);
        // Set L??sungswort to lower case
        for (int i = 0; i < anzbuch; i++) {
            wort[i] = tolower(wort[i]);
        }

        printf("\n");

        // Set placerHolder string "____", genauso lange wie die Antwort
        //    F---h
        //TODO Bei einer zweiten Runde mit einem Wort strlen<2 wird ein buchstabe zuviel ausgegeben
        char lw[255];
        for (int i = 0; i < anzbuch; i++) {
            lw[i] = '_';
        }
        lw[anzbuch]= '\0';


        // Set alter
        printf("Alter eingeben: ");
        scanf("%i", &alter);
        rateVersuche = versuche(alter);


        // Errechne Rateversuche
        printf("Sie erhalten : %i Versuche um das Wort zu erraten\n", rateVersuche);
        fehler = fehler - rateVersuche;
        fehlerAusgabe(fehler);


        //Aufgabe8
        //Schleife l??uft solange wie fehler oder anzahl buchstaben nicht erreicht ist
        while (fehler != 12 && richtigGeraten != anzbuch) {
            int treffer = 0;

            printf("%s\n\n", lw); //todo
            printf("Eingabe: ");
            scanf(" %c", &eingabe);
            eingabe = tolower(eingabe);

            //vergleiche eingabe mit Antwort
            for (int i = 0; i < anzbuch; i++) {

                if (wort[i] == eingabe) {
                    lw[i] = eingabe;
                    wort[i] = '0';
                    treffer++;
                }
            }

            //Z??hle treffer hoch
            //Todo Switch oder if Doz Fragen!
//        if(treffer > 0){
//            richtigGeraten = richtigGeraten + treffer;
//            fehlerAusgabe(fehler);
//        }
//        else{
//            fehler++;
//            fehlerAusgabe(fehler);
//        }

            switch (treffer) {
                case 0:
                    fehler++;
                    rateVersuche--;
                    fehlerAusgabe(fehler);
                    break;
                default:
                    richtigGeraten = richtigGeraten + treffer;
                    fehlerAusgabe(fehler);
                    break;
            }

            printf("Fehler: %i\n", fehler);
            if (rateVersuche > 1) {
                printf("Sie haben noch %i Versuche \x81""brig \n", rateVersuche);
            } else if (rateVersuche == 1) {
                printf("Sie haben noch %i Versuch \x81""brig \n", rateVersuche);
            } else {
                printf("\n");
            }

        }
        if (richtigGeraten == anzbuch) {
            printf("SIE HABEN GEWONNEN!\n");
        } else {
            printf("SIE HABEN VERLOREN!\n");
           printf("Das Wort lautete: %s\n", wort2);
        }
        printf("Dr\x81""cken sie 1 um nochmal zu spielen!\n");
        scanf("%i", &bool);
    }
 printf("Danke f\x81""rs Spielen!");

    return 0;
}
