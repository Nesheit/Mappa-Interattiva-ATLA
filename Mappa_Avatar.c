//
//  Mappa_Avatar.c
//
//  First created by Nesheit on 23/12/14.


#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <unistd.h>


typedef struct n {char Let; struct n * next;} Nodo;

typedef struct {char Coordinate[25];} CasellaSingola;

typedef struct {int n; int Posizione[2]; char Nome[50];} CasellaViaggio;

char scanSenzaInvio()

{
    char tasto_premuto;

    system("/bin/stty raw");

    tasto_premuto = getchar();

    system("/bin/stty cooked");

    return tasto_premuto;
}

void Cancella()

{
    system("clear");
}

void CoordinatePrecise (Nodo * Coordinata)

{
    while (Coordinata->Let != 'A' && Coordinata->Let != 'B' && Coordinata->Let != 'C' && Coordinata->Let != 'D' && Coordinata->Let != 'E' && Coordinata->Let != 'F' && Coordinata->Let != 'G' && Coordinata->Let != 'H' && Coordinata->Let != 'I' && Coordinata->Let != 'J' && Coordinata->Let != 'K' && Coordinata->Let != 'L' && Coordinata->Let != 'M' && Coordinata->Let != 'N' && Coordinata->Let != 'O' && Coordinata->Let != 'P' && Coordinata->Let != 'Q' && Coordinata->Let != 'R' && Coordinata->Let != 'S' && Coordinata->Let != 'T' && Coordinata->Let != 'U' && Coordinata->Let != 'V' && Coordinata->Let != 'W' && Coordinata->Let != 'X' && Coordinata->Let != 'Y' && Coordinata->Let != 'Z' && Coordinata->Let != 'a' && Coordinata->Let != 'b' && Coordinata->Let != 'c' && Coordinata->Let != 'd' && Coordinata->Let != 'e' && Coordinata->Let != 'f' && Coordinata->Let != 'g' && Coordinata->Let != 'h' && Coordinata->Let != 'i' && Coordinata->Let != 'j' && Coordinata->Let != 'k' && Coordinata->Let != 'l' && Coordinata->Let != 'm' && Coordinata->Let != 'n' && Coordinata->Let != 'o' && Coordinata->Let != 'p' && Coordinata->Let != 'q' && Coordinata->Let != 'r' && Coordinata->Let != 's' && Coordinata->Let != 't' && Coordinata->Let != 'u' && Coordinata->Let != 'v' && Coordinata->Let != 'w' && Coordinata->Let != 'x' && Coordinata->Let != 'y' && Coordinata->Let != 'z' && Coordinata->Let != '\n' && Coordinata->Let != '1' && Coordinata->Let != '2' && Coordinata->Let != '3' && Coordinata->Let != '4' && Coordinata->Let != '5' && Coordinata->Let != '6' && Coordinata->Let != '7' && Coordinata->Let != '8' && Coordinata->Let != '9' && Coordinata->Let != '.')
    {Coordinata->Let = scanSenzaInvio();}

    if (Coordinata->Let == '.') {Coordinata->Let = '\0'; return;}

    else {Coordinata->next = malloc(sizeof(Nodo)); Coordinata->next->Let = '0'; CoordinatePrecise(Coordinata->next);}

    return;
}

int ComparaCoordinatePrecise (Nodo * CoordinateUtente, int i, char Coordinate[])

{
    if (CoordinateUtente->Let == Coordinate[i] && Coordinate[i] == '\0') return 1;

    if ((CoordinateUtente->Let != Coordinate[i] && Coordinate[i] == '\0') || (CoordinateUtente->Let != Coordinate[i] && CoordinateUtente->Let == '\0') || CoordinateUtente->Let != Coordinate[i]) return 0;

    else return ComparaCoordinatePrecise(CoordinateUtente->next, i+1, &Coordinate[0]);

}

void Viaggio(int Passi[], char Mappa[], int riga, int colonna)

{
    if (Mappa[85 + colonna + (84*riga)] == 'm') Passi[0] = Passi[0] + 1;
    if (Mappa[85 + colonna + (84*riga)] == 'c') Passi[1] = Passi[1] + 1;
    if (Mappa[85 + colonna + (84*riga)] == 't') Passi[2] = Passi[2] + 1;

}

void StampaMappa(char a[])
{
    int riga, colonna, i, k;

    char * Mappa;

    Mappa = malloc(11500*sizeof(char));

    i = k = 0;

    Mappa[0] = '\n';

    k = k + 1;

    for (riga = 0; riga < 68; riga = riga + 1) {

        for (colonna = 0; colonna < 84 ; colonna = colonna + 1) {

            if (colonna == -1) printf("%d", i); /*DEBUG: CAMBIA IL NUMERO DELLA COLONNA PER VEDERE IN CHE POSTO DEL VETTORE "MAPPA" RISIEDONO LE CASELLE DELLA STESSA COLONNA*/

            else if (a[i] == 'm') {Mappa[k] = ' '; k = k + 1; Mappa[k] = ' ';}

            else if (a[i] != 'c' && a[i] != 't'){Mappa[k] = a[i]; k = k + 1; Mappa[k] = ' ';}

            else {Mappa[k] = '#'; if (riga == 1+4 && colonna == 1+48) {Mappa[k] = 'A';}if (riga == 1+5 && colonna == 1+38) {Mappa[k] = '3';}if (riga == 1+8 && colonna == 1+48) {Mappa[k] = '4';}if (riga == 1+16 && colonna == 1+68) {Mappa[k] = 'B';}if (riga == 1+17 && colonna == 1+62) {Mappa[k] = '5';}if (riga == 1+17 && colonna == 1+63) {Mappa[k] = '5';}if (riga == 1+18 && colonna == 1+9) {Mappa[k] = '2';}if (riga == 1+18 && colonna == 1+62) {Mappa[k] = '5';}if (riga == 1+18 && colonna == 1+63) {Mappa[k] = '5';}if (riga == 1+23 && colonna == 1+53) {Mappa[k] = 'C';}if (riga == 1+24 && colonna == 1+40) {Mappa[k] = 'D';}if (riga == 1+24 && colonna == 1+51) {Mappa[k] = 'E';}if (riga == 1+26 && colonna == 1+47) {Mappa[k] = 'F';}if (riga == 1+26 && colonna == 1+51) {Mappa[k] = 'G';}if (riga == 1+27 && colonna == 1+7) {Mappa[k] = 'H';}if (riga == 1+27 && colonna == 1+30) {Mappa[k] = 'I';}if (riga == 1+27 && colonna == 1+32) {Mappa[k] = 'J';}if (riga == 1+28 && colonna == 1+33) {Mappa[k] = 'K';}if (riga == 1+28 && colonna == 1+38) {Mappa[k] = 'L';}if (riga == 1+29 && colonna == 1+6) {Mappa[k] = '1';}if (riga == 1+29 && colonna == 1+42) {Mappa[k] = 'M';}if (riga == 1+30 && colonna == 1+55) {Mappa[k] = 'N';}if (riga == 1+31 && colonna == 1+14) {Mappa[k] = 'O';}if (riga == 1+32 && colonna == 1+16) {Mappa[k] = 'P';}if (riga == 1+32 && colonna == 1+27) {Mappa[k] = 'Q';}if (riga == 1+35 && colonna == 1+17) {Mappa[k] = 'R';}if (riga == 1+35 && colonna == 1+45) {Mappa[k] = 'S';}if (riga == 1+37 && colonna == 1+75) {Mappa[k] = '6';}if (riga == 1+45 && colonna == 1+39) {Mappa[k] = 'T';}if (riga == 1+45 && colonna == 1+54) {Mappa[k] = 'U';}if (riga == 1+48 && colonna == 1+31) {Mappa[k] = '8';}if (riga == 1+53 && colonna == 1+46) {Mappa[k] = 'V';}if (riga == 1+57 && colonna == 1+45) {Mappa[k] = 'W';}if (riga == 1+60 && colonna == 1+31) {Mappa[k] = '7';} k = k + 1; Mappa[k] = ' ';}

            k = k + 1;

            i = i + 1;
        }

        Mappa[k] = '\n';

        k = k + 1;
    }

    for (k = 0; k < 11500; k++) { /*PER STAMPARE I PASSI SE SI VOGLIONO FARE LE ORME CON I PUNTI*/
        if (Mappa[k] == '.') {Mappa[k+1] = '.'; k = k + 1;}
        if (Mappa[k] == ':') {Mappa[k+1] = ':'; k = k + 1;}
    }

    Mappa[11499] = '\0';

    printf("%s", Mappa);

    free(Mappa);

    return ;

}

void MuoviPartenza (int Coordinate[], char TastoPremuto, char Strada[], char Mappa[])

{
    if (TastoPremuto == 'a' || TastoPremuto == 'A') {Coordinate[1] = Coordinate[1] - 1;}
    if (TastoPremuto == 's' || TastoPremuto == 'S') {Coordinate[0] = Coordinate[0] + 1;}
    if (TastoPremuto == 'd' || TastoPremuto == 'D') {Coordinate[1] = Coordinate[1] + 1;}
    if (TastoPremuto == 'w' || TastoPremuto == 'W') {Coordinate[0] = Coordinate[0] - 1;}

    int i = 85, riga, colonna;

    for (riga = 0; riga < 67; riga = riga + 1) {
        for (colonna = 0; colonna < 83; colonna = colonna + 1) {
            if (Strada[i] == '+') {Strada[i] = Mappa[i];}
            if (riga == Coordinate[0] && colonna == Coordinate[1]) {Strada[i] = '+';}
            i = i + 1;
        }

        i = i + 1;
    }

    return ;

}

void MuoviArrivo (int Coordinate[], CasellaViaggio Pressi[], int Passi[], char TastoPremuto, char Strada[], char Mappa[])

{
    if (TastoPremuto == 'a' || TastoPremuto == 'A') {Coordinate[1] = Coordinate[1] - 1;}
    if (TastoPremuto == 's' || TastoPremuto == 'S') {Coordinate[0] = Coordinate[0] + 1;}
    if (TastoPremuto == 'd' || TastoPremuto == 'D') {Coordinate[1] = Coordinate[1] + 1;}
    if (TastoPremuto == 'w' || TastoPremuto == 'W') {Coordinate[0] = Coordinate[0] - 1;}

    int i = 85, riga, colonna, CoordiStrada[2], max = 0;

    for (riga = 0; riga < 30; riga = riga + 1) {if (Pressi[riga].n > max) max = Pressi[riga].n;} // IN QUESTO FOR "riga" É USATO COME UN INT QUALSIASI

    for (riga = 0; riga < 67; riga = riga + 1) {
        for (colonna = 0; colonna < 83; colonna = colonna + 1) {
            if (Strada[i] == '+') {

                if (TastoPremuto == 'a' || TastoPremuto == 'd' || TastoPremuto == 'A' || TastoPremuto == 'D')
                {Strada[i] = '-'; Viaggio(&Passi[0], &Mappa[0], riga, colonna);}

                if (TastoPremuto == 's' || TastoPremuto == 'w' || TastoPremuto == 'S' || TastoPremuto == 'W')
                {Strada[i] = '|'; Viaggio(&Passi[0], &Mappa[0], riga, colonna);}

                for (CoordiStrada[0] = riga - 1; CoordiStrada[0] < riga + 2; CoordiStrada[0] = CoordiStrada[0] + 1) {
                    for (CoordiStrada[1] = colonna - 1; CoordiStrada[1] < colonna + 2; CoordiStrada[1] = CoordiStrada[1] + 1) {

                        if (CoordiStrada[0] == 4 && Pressi[0].n == 0 && CoordiStrada[1] == 48) {Pressi[0].n = max+1;}
                        if (CoordiStrada[0] == 5 && Pressi[1].n == 0 && CoordiStrada[1] == 38) {Pressi[1].n = max+1;}
                        if (CoordiStrada[0] == 8 && Pressi[2].n == 0 && CoordiStrada[1] == 48) {Pressi[2].n = max+1;}
                        if (CoordiStrada[0] == 16 && Pressi[3].n == 0 && CoordiStrada[1] == 68) {Pressi[3].n = max+1;}
                        if (CoordiStrada[0] == 18 && Pressi[4].n == 0 && CoordiStrada[1] == 9) {Pressi[4].n = max+1;}
                        if (CoordiStrada[0] == 17 && Pressi[5].n == 0 && CoordiStrada[1] == 62) {Pressi[5].n = max+1;}
                        if (CoordiStrada[0] == 23 && Pressi[6].n == 0 && CoordiStrada[1] == 53) {Pressi[6].n = max+1;}
                        if (CoordiStrada[0] == 24 && Pressi[7].n == 0 && CoordiStrada[1] == 40) {Pressi[7].n = max+1;}
                        if (CoordiStrada[0] == 24 && Pressi[8].n == 0 && CoordiStrada[1] == 51) {Pressi[8].n = max+1;}
                        if (CoordiStrada[0] == 26 && Pressi[9].n == 0 && CoordiStrada[1] == 47) {Pressi[9].n = max+1;}
                        if (CoordiStrada[0] == 26 && Pressi[10].n == 0 && CoordiStrada[1] == 51) {Pressi[10].n = max+1;}
                        if (CoordiStrada[0] == 27 && Pressi[11].n == 0 && CoordiStrada[1] == 7) {Pressi[11].n = max+1;}
                        if (CoordiStrada[0] == 27 && Pressi[12].n == 0 && CoordiStrada[1] == 30) {Pressi[12].n = max+1;}
                        if (CoordiStrada[0] == 27 && Pressi[13].n == 0 && CoordiStrada[1] == 32) {Pressi[13].n = max+1;}
                        if (CoordiStrada[0] == 28 && Pressi[14].n == 0 && CoordiStrada[1] == 33) {Pressi[14].n = max+1;}
                        if (CoordiStrada[0] == 28 && Pressi[15].n == 0 && CoordiStrada[1] == 38) {Pressi[15].n = max+1;}
                        if (CoordiStrada[0] == 29 && Pressi[16].n == 0 && CoordiStrada[1] == 6) {Pressi[16].n = max+1;}
                        if (CoordiStrada[0] == 29 && Pressi[17].n == 0 && CoordiStrada[1] == 42) {Pressi[17].n = max+1;}
                        if (CoordiStrada[0] == 30 && Pressi[18].n == 0 && CoordiStrada[1] == 55) {Pressi[18].n = max+1;}
                        if (CoordiStrada[0] == 31 && Pressi[19].n == 0 && CoordiStrada[1] == 14) {Pressi[19].n = max+1;}
                        if (CoordiStrada[0] == 32 && Pressi[20].n == 0 && CoordiStrada[1] == 16) {Pressi[20].n = max+1;}
                        if (CoordiStrada[0] == 32 && Pressi[21].n == 0 && CoordiStrada[1] == 27) {Pressi[21].n = max+1;}
                        if (CoordiStrada[0] == 35 && Pressi[22].n == 0 && CoordiStrada[1] == 17) {Pressi[22].n = max+1;}
                        if (CoordiStrada[0] == 35 && Pressi[23].n == 0 && CoordiStrada[1] == 45) {Pressi[23].n = max+1;}
                        if (CoordiStrada[0] == 37 && Pressi[24].n == 0 && CoordiStrada[1] == 75) {Pressi[24].n = max+1;}
                        if (CoordiStrada[0] == 45 && Pressi[25].n == 0 && CoordiStrada[1] == 39) {Pressi[25].n = max+1;}
                        if (CoordiStrada[0] == 45 && Pressi[26].n == 0 && CoordiStrada[1] == 54) {Pressi[26].n = max+1;}
                        if (CoordiStrada[0] == 48 && Pressi[27].n == 0 && CoordiStrada[1] == 31) {Pressi[27].n = max+1;}
                        if (CoordiStrada[0] == 53 && Pressi[28].n == 0 && CoordiStrada[1] == 46) {Pressi[28].n = max+1;}
                        if (CoordiStrada[0] == 57 && Pressi[29].n == 0 && CoordiStrada[1] == 45) {Pressi[29].n = max+1;}
                        if (CoordiStrada[0] == 60 && Pressi[30].n == 0 && CoordiStrada[1] == 31) {Pressi[30].n = max+1;}

                    }
                }
            }
            if (riga == Coordinate[0] && colonna == Coordinate[1]) {Strada[i] = '+';}
            i = i + 1;
        }

        i = i + 1;
    }

    return ;

}


char SpostamentInterattivi(CasellaViaggio Pressi[], char Partenza_Arrivo, char Automatico_Interattivo, char spst, int Passi[], int Coordinate[], int Partenza[], char Strada[], char Mappa[], int flag)

{
    int k = 0;

    char t_p;

    if (Automatico_Interattivo == 'I') t_p = scanSenzaInvio();

    else t_p = spst;

    if ((t_p != 'k' && t_p != 'K' && t_p != 'a' && t_p != 'A' && t_p != 's' && t_p != 'S' && t_p != 'd' && t_p != 'D' && t_p != 'w' && t_p != 'W') || (t_p == 'a' && Coordinate[1] == 0) || (t_p == 'A' && Coordinate[1] == 0) || (t_p == 's' && Coordinate[0] == 66) || (t_p == 'S' && Coordinate[0] == 66) || (t_p == 'd' && Coordinate[1] == 82) || (t_p == 'D' && Coordinate[1] == 82) || (t_p == 'w' && Coordinate[0] == 0) || (t_p == 'W' && Coordinate[0] == 0)) {t_p = SpostamentInterattivi(&Pressi[0], Partenza_Arrivo, Automatico_Interattivo, spst, &Passi[0], &Coordinate[0], &Partenza[0], &Strada[0], &Mappa[0], flag);}

    if (t_p == 'k' || t_p == 'K') {k = 1;}

    if (k == 0)

    {
        if (Partenza_Arrivo == 'P' || (Coordinate[0] == Partenza[0] && Coordinate[1] == Partenza[1] && flag == 0))
        {MuoviPartenza(&Coordinate[0], t_p, &Strada[0], &Mappa[0]); flag = 1;}

        else if (Partenza_Arrivo == 'A') {MuoviArrivo(&Coordinate[0], &Pressi[0], &Passi[0], t_p, &Strada[0], &Mappa[0]);}

        if (Automatico_Interattivo == 'I') {Cancella(); StampaMappa(&Strada[0]);}

        if (Automatico_Interattivo == 'I') t_p = SpostamentInterattivi(&Pressi[0], Partenza_Arrivo, Automatico_Interattivo, spst, &Passi[0], &Coordinate[0], &Partenza[0], &Strada[0], &Mappa[0], flag);

        if (Automatico_Interattivo == 'A') t_p = SpostamentInterattivi(&Pressi[0], Partenza_Arrivo, Automatico_Interattivo, 'k', &Passi[0], &Coordinate[0], &Partenza[0], &Strada[0], &Mappa[0], flag);
    }

    return t_p;

}

char Risp1 (CasellaSingola Casella[], char P_A, char Strada[], int Partenza[], int Arrivo[], int Coordinate[])

{
    Nodo Primo;

    int riga, colonna, esito = 0, i = 0;

    Primo.Let = '0';

    printf("\n\nInserisci le coordinate concludendo con un punto (ATTENZIONE ALLE MAIUSCOLE!):\n\nEsempio di inserimento corretto:                                M rosso 6 bianco.             \n\n");

    CoordinatePrecise(&Primo);

    for (riga = 0; riga < 67 && esito == 0; riga = riga + 1) {

        for (colonna = 0; colonna < 83 && esito == 0; colonna = colonna + 1) {

            esito = ComparaCoordinatePrecise (&Primo, 0, &Casella[i].Coordinate[0]);

            i = i + 1;

        }

    }

    if (esito == 0) {

        printf("\n\nLe coordinate inserite non sono corrette, riprova:");

        printf("\n\n---V---");

        scanSenzaInvio();

        return '1';
    }

    if (P_A == 'P')

    {
        Partenza[0] = Coordinate[0] = riga - 1;

        Partenza[1] = Coordinate[1] = colonna - 1;
    }

    if (P_A == 'A')

    {
        Arrivo[0] = Coordinate[0] = riga - 1;

        Arrivo[1] = Coordinate[1] = colonna - 1;
    }

    i = 85;

    for (riga = 0; riga < 67; riga = riga + 1) {
        for (colonna = 0; colonna < 83; colonna = colonna + 1) {

            if (riga == Coordinate[0] && colonna == Coordinate[1]) {Strada[i] = '+';}
            i = i + 1;
        }

        i = i + 1;
    }

    return '0';
}

char Risp2 (char P_A, char Strada[], int Partenza[], int Arrivo[], int Coordinate[])

{
    char risp;

    printf("\n\nDigita il Carattere che identifica il tuo punto di partenza:\n\n1) Capitale della Nazione del Fuoco     2) Tempio dell’Aria dell'Ovest       3) Tribù dell’Acqua del Nord       4) Tempio dell’Aria del Nord\n\n5) Ba Sing Se                           6) Tempio dell’Aria dell'Est         7) Tribù dell’Acqua del Sud        8) Tempio dell’Aria del Sud       A) Tribù di ShaoQing\n\nB) Baia del Camaleonte                  C) Passo del Serpente                D) Senlin                          E) Baia della Luna Piena          F) Gaipan\n\nG) Grande Spaccatura                    H) La Roccia Bollente                I) Isola di Ember                  J) Isola di Roku                  K) Isola Mezzaluna\n\nL) Foresta di Wulong                    M) Gaoling                           N) Deserto di Si Wong              O) Fire Fountain City             P) Cancelli di Azulon\n\nQ) Jang Hui                             R) Shu Jing                          S) Omashu                          T) Isola Codadibalena             U) Tribù della Palude\n\nV) Isola di Kyoshi                      W) Tribù di HaiQuing\n\n");


    risp = scanSenzaInvio();

    if (risp == 'A' || risp == 'a'){Coordinate[0] = 4; Coordinate[1] = 48;}
    else if (risp == '3'){Coordinate[0] = 5; Coordinate[1] = 38;}
    else if (risp == '4'){Coordinate[0] = 8; Coordinate[1] = 48;}
    else if (risp == 'B' || risp == 'b'){Coordinate[0] = 16; Coordinate[1] = 68;}
    else if (risp == '2'){Coordinate[0] = 18; Coordinate[1] = 9;}
    else if (risp == '5'){Coordinate[0] = 17; Coordinate[1] = 62;}
    else if (risp == 'C' || risp == 'c'){Coordinate[0] = 23; Coordinate[1] = 53;}
    else if (risp == 'D' || risp == 'd'){Coordinate[0] = 24; Coordinate[1] = 40;}
    else if (risp == 'E' || risp == 'e'){Coordinate[0] = 24; Coordinate[1] = 51;}
    else if (risp == 'F' || risp == 'f'){Coordinate[0] = 26; Coordinate[1] = 47;}
    else if (risp == 'G' || risp == 'g'){Coordinate[0] = 26; Coordinate[1] = 51;}
    else if (risp == 'H' || risp == 'h'){Coordinate[0] = 27; Coordinate[1] = 7;}
    else if (risp == 'I' || risp == 'i'){Coordinate[0] = 27; Coordinate[1] = 30;}
    else if (risp == 'J' || risp == 'j'){Coordinate[0] = 27; Coordinate[1] = 32;}
    else if (risp == 'K' || risp == 'k'){Coordinate[0] = 28; Coordinate[1] = 33;}
    else if (risp == 'L' || risp == 'l'){Coordinate[0] = 28; Coordinate[1] = 38;}
    else if (risp == '1'){Coordinate[0] = 29; Coordinate[1] = 6;}
    else if (risp == 'M' || risp == 'm'){Coordinate[0] = 29; Coordinate[1] = 42;}
    else if (risp == 'N' || risp == 'n'){Coordinate[0] = 30; Coordinate[1] = 55;}
    else if (risp == 'O' || risp == 'o'){Coordinate[0] = 31; Coordinate[1] = 14;}
    else if (risp == 'P' || risp == 'p'){Coordinate[0] = 32; Coordinate[1] = 16;}
    else if (risp == 'Q' || risp == 'q'){Coordinate[0] = 32; Coordinate[1] = 27;}
    else if (risp == 'R' || risp == 'r'){Coordinate[0] = 35; Coordinate[1] = 17;}
    else if (risp == 'S' || risp == 's'){Coordinate[0] = 35; Coordinate[1] = 45;}
    else if (risp == '6'){Coordinate[0] = 37; Coordinate[1] = 75;}
    else if (risp == 'T' || risp == 't'){Coordinate[0] = 45; Coordinate[1] = 39;}
    else if (risp == 'U' || risp == 'u'){Coordinate[0] = 45; Coordinate[1] = 54;}
    else if (risp == '8'){Coordinate[0] = 48; Coordinate[1] = 31;}
    else if (risp == 'V' || risp == 'v'){Coordinate[0] = 53; Coordinate[1] = 46;}
    else if (risp == 'W' || risp == 'w'){Coordinate[0] = 57; Coordinate[1] = 45;}
    else if (risp == '7'){Coordinate[0] = 60; Coordinate[1] = 31;}
    else {

        printf("\nIl carattere digitato non indica nessun luogo.\nInseriscine uno adeguato:\n\n");

        printf("\n\n---V---");

        scanSenzaInvio();

        return '2';
    }

    if (P_A == 'P')

    {
        Partenza[0] = Coordinate[0];

        Partenza[1] = Coordinate[1];
    }

    if (P_A == 'A')

    {
        Arrivo[0] = Coordinate[0];

        Arrivo[1] = Coordinate[1];
    }

    int i = 85, riga, colonna;

    for (riga = 0; riga < 67; riga = riga + 1) {
        for (colonna = 0; colonna < 83; colonna = colonna + 1) {

            if (riga == Coordinate[0] && colonna == Coordinate[1]) {Strada[i] = '+';}
            i = i + 1;
        }

        i = i + 1;
    }

    return '0';
}

char Risp3 (CasellaViaggio Pressi[], char P_A, char Strada[], char Mappa[], int Partenza[], int Arrivo[], int Passi[], int Coordinate[])

{
    if (P_A == 'P') {

        Coordinate[0] = 38;

        Coordinate[1] = 34;

    }

    int i = 85, riga, colonna;

    for (riga = 0; riga < 67; riga = riga + 1) {
        for (colonna = 0; colonna < 83; colonna = colonna + 1) {

            if (riga == Coordinate[0] && colonna == Coordinate[1]) {Strada[i] = '+';}
            i = i + 1;
        }

        i = i + 1;
    }

    Cancella(); StampaMappa(&Strada[0]);

    SpostamentInterattivi(&Pressi[0], 'P', 'I', 'm', &Passi[0], &Coordinate[0], &Partenza[0], &Strada[0], &Mappa[0], 0);

    if (P_A == 'P')

    {
        Partenza[0] = Coordinate[0];

        Partenza[1] = Coordinate[1];
    }

    if (P_A == 'A')

    {
        Arrivo[0] = Coordinate[0];

        Arrivo[1] = Coordinate[1];
    }

    return '0';
}

void StampaCoordinate (char Coordinate[])

{
    int i = 0;

    printf ("%c ", Coordinate[i]);

    i = i + 1;

    while (Coordinate[i] > 57)

    {
        printf ("%c", Coordinate[i]);

        i = i + 1;
    }

    printf (" %c ", Coordinate[i]);

    i = i + 1;

    while (Coordinate[i] > 57)

    {
        printf ("%c", Coordinate[i]);

        i = i + 1;
    }

    return ;
}

int StampaPosti (int CoordPosto[])

{
    if (CoordPosto[0] == 4 && CoordPosto[1] == 48) {printf("la Tribù di ShaoQuing"); return 1;}
    if (CoordPosto[0] == 5 && CoordPosto[1] == 38) {printf("la Tribù dell'Acqua del Nord"); return 1;}
    if (CoordPosto[0] == 8 && CoordPosto[1] == 48) {printf("il Tempio dell'Aria del Nord"); return 1;}
    if (CoordPosto[0] == 16 && CoordPosto[1] == 68) {printf("la Baia del Camaleonte"); return 1;}
    if(CoordPosto[0] == 18 && CoordPosto[1] == 9) {printf("il Tempio dell'Aria dell'Ovest"); return 1;}
    if(CoordPosto[0] == 17 && CoordPosto[1] == 62) {printf("Ba Sing Se (Sezione Nord-Ovest)"); return 1;}
    if(CoordPosto[0] == 17 && CoordPosto[1] == 63) {printf("Ba Sing Se (Sezione Nord-Est)"); return 1;}
    if (CoordPosto[0] == 18 && CoordPosto[1] == 62) {printf("Ba Sing Se (Sezione Nord-Ovest)"); return 1;}
    if (CoordPosto[0] == 18 && CoordPosto[1] == 63) {printf("Ba Sing Se (Sezione Nord-Est)"); return 1;}
    if (CoordPosto[0] == 23 && CoordPosto[1] == 53) {printf("il Passo del Serpente"); return 1;}
    if (CoordPosto[0] == 24 && CoordPosto[1] == 40) {printf("Senlin"); return 1;}
    if (CoordPosto[0] == 24 && CoordPosto[1] == 51) {printf("la Baia della Luna Piena"); return 1;}
    if (CoordPosto[0] == 26 && CoordPosto[1] == 47) {printf("Gaipan"); return 1;}
    if (CoordPosto[0] == 26 && CoordPosto[1] == 51) {printf("la Grande Spaccatura"); return 1;}
    if (CoordPosto[0] == 27 && CoordPosto[1] == 7) {printf("La Roccia Bollente"); return 1;}
    if (CoordPosto[0] == 27 && CoordPosto[1] == 30) {printf("l'Isola di Ember"); return 1;}
    if (CoordPosto[0] == 27 && CoordPosto[1] == 32) {printf("l'Isola di Roku"); return 1;}
    if (CoordPosto[0] == 28 && CoordPosto[1] == 33) {printf("l'Isola Mezzaluna"); return 1;}
    if (CoordPosto[0] == 28 && CoordPosto[1] == 38) {printf("la Foresta di Wulong"); return 1;}
    if (CoordPosto[0] == 29 && CoordPosto[1] == 6) {printf("la Capitale della Nazione del Fuoco"); return 1;}
    if (CoordPosto[0] == 29 && CoordPosto[1] == 42) {printf("Gaoling"); return 1;}
    if (CoordPosto[0] == 30 && CoordPosto[1] == 55) {printf("il Deserto di Si Wong"); return 1;}
    if (CoordPosto[0] == 31 && CoordPosto[1] == 14) {printf("Fire Fountain City"); return 1;}
    if (CoordPosto[0] == 32 && CoordPosto[1] == 16) {printf("i Cancelli di Azulon"); return 1;}
    if (CoordPosto[0] == 32 && CoordPosto[1] == 27) {printf("Jang Hui"); return 1;}
    if (CoordPosto[0] == 35 && CoordPosto[1] == 17) {printf("Shu Jing"); return 1;}
    if (CoordPosto[0] == 35 && CoordPosto[1] == 45) {printf("Omashu"); return 1;}
    if (CoordPosto[0] == 37 && CoordPosto[1] == 75) {printf("il Tempio dell’Aria dell'Est"); return 1;}
    if (CoordPosto[0] == 45 && CoordPosto[1] == 39) {printf("l'Isola Codadibalena"); return 1;}
    if (CoordPosto[0] == 45 && CoordPosto[1] == 54) {printf("la Tribù della Palude"); return 1;}
    if (CoordPosto[0] == 48 && CoordPosto[1] == 31) {printf("il Tempio dell’Aria del Sud"); return 1;}
    if (CoordPosto[0] == 53 && CoordPosto[1] == 46) {printf("l'Isola di Kyoshi"); return 1;}
    if (CoordPosto[0] == 57 && CoordPosto[1] == 45) {printf("la Tribù di HaiQuing"); return 1;}
    if (CoordPosto[0] == 60 && CoordPosto[1] == 31) {printf("la Tribù dell’Acqua del Sud"); return 1;}

    return 0;

}

int StamPartenzArrivo (int Posto[], char PartenzAoArrivO[], char CharID[])

{
    if (Posto[0] == 4 && Posto[1] == 48) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la A\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 5 && Posto[1] == 38) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 3\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 8 && Posto[1] == 48) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 4\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 16 && Posto[1] == 68) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la B\nLe sue Coordinate sono: "); return 1;}
    if(Posto[0] == 18 && Posto[1] == 9) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 2\nLe sue Coordinate sono: "); return 1;}
    if(Posto[0] == 17 && Posto[1] == 62) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 5\nLe sue Coordinate sono: "); return 1;}
    if(Posto[0] == 17 && Posto[1] == 63) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 5\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 18 && Posto[1] == 62) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 5\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 18 && Posto[1] == 63) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 5\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 23 && Posto[1] == 53) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la C\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 24 && Posto[1] == 40) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la D\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 24 && Posto[1] == 51) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la E\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 26 && Posto[1] == 47) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la F\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 26 && Posto[1] == 51) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la G\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 27 && Posto[1] == 7) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la H\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 27 && Posto[1] == 30) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la I\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 27 && Posto[1] == 32) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la J\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 28 && Posto[1] == 33) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la K\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 28 && Posto[1] == 38) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la L\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 29 && Posto[1] == 6) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è l'1\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 29 && Posto[1] == 42) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la M\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 30 && Posto[1] == 55) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la N\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 31 && Posto[1] == 14) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la O\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 32 && Posto[1] == 16) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la P\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 32 && Posto[1] == 27) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la Q\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 35 && Posto[1] == 17) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la R\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 35 && Posto[1] == 45) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la S\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 37 && Posto[1] == 75) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 6\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 45 && Posto[1] == 39) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la T\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 45 && Posto[1] == 54) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la U\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 48 && Posto[1] == 31) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è l'8 \nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 53 && Posto[1] == 46) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la V\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 57 && Posto[1] == 45) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è la W\nLe sue Coordinate sono: "); return 1;}
    if (Posto[0] == 60 && Posto[1] == 31) {printf("%s è ", PartenzAoArrivO); StampaPosti(&Posto[0]); printf("\nSulla Mappa il suo Carattere Identificativo è il 7\nLe sue Coordinate sono: "); return 1;}

    return 0;
}

int main()

{
    CasellaSingola Casella[5561];

    strcpy(Casella[0].Coordinate, "Abianco1bianco");
    strcpy(Casella[1].Coordinate, "Bbianco1bianco");
    strcpy(Casella[2].Coordinate, "Cbianco1bianco");
    strcpy(Casella[3].Coordinate, "Dbianco1bianco");
    strcpy(Casella[4].Coordinate, "Ebianco1bianco");
    strcpy(Casella[5].Coordinate, "Fbianco1bianco");
    strcpy(Casella[6].Coordinate, "Gbianco1bianco");
    strcpy(Casella[7].Coordinate, "Hbianco1bianco");
    strcpy(Casella[8].Coordinate, "Ibianco1bianco");
    strcpy(Casella[9].Coordinate, "Jbianco1bianco");
    strcpy(Casella[10].Coordinate, "Kbianco1bianco");
    strcpy(Casella[11].Coordinate, "Lbianco1bianco");
    strcpy(Casella[12].Coordinate, "Mbianco1bianco");
    strcpy(Casella[13].Coordinate, "Nbianco1bianco");
    strcpy(Casella[14].Coordinate, "Obianco1bianco");
    strcpy(Casella[15].Coordinate, "Pbianco1bianco");
    strcpy(Casella[16].Coordinate, "Qbianco1bianco");
    strcpy(Casella[17].Coordinate, "Rbianco1bianco");
    strcpy(Casella[18].Coordinate, "Sbianco1bianco");
    strcpy(Casella[19].Coordinate, "Tbianco1bianco");
    strcpy(Casella[20].Coordinate, "Ubianco1bianco");
    strcpy(Casella[21].Coordinate, "Vbianco1bianco");
    strcpy(Casella[22].Coordinate, "Wbianco1bianco");
    strcpy(Casella[23].Coordinate, "Xbianco1bianco");
    strcpy(Casella[24].Coordinate, "Ybianco1bianco");
    strcpy(Casella[25].Coordinate, "Zbianco1bianco");
    strcpy(Casella[26].Coordinate, "Arosso1bianco");
    strcpy(Casella[27].Coordinate, "Brosso1bianco");
    strcpy(Casella[28].Coordinate, "Crosso1bianco");
    strcpy(Casella[29].Coordinate, "Drosso1bianco");
    strcpy(Casella[30].Coordinate, "Erosso1bianco");
    strcpy(Casella[31].Coordinate, "Frosso1bianco");
    strcpy(Casella[32].Coordinate, "Grosso1bianco");
    strcpy(Casella[33].Coordinate, "Hrosso1bianco");
    strcpy(Casella[34].Coordinate, "Irosso1bianco");
    strcpy(Casella[35].Coordinate, "Jrosso1bianco");
    strcpy(Casella[36].Coordinate, "Krosso1bianco");
    strcpy(Casella[37].Coordinate, "Lrosso1bianco");
    strcpy(Casella[38].Coordinate, "Mrosso1bianco");
    strcpy(Casella[39].Coordinate, "Nrosso1bianco");
    strcpy(Casella[40].Coordinate, "Orosso1bianco");
    strcpy(Casella[41].Coordinate, "Prosso1bianco");
    strcpy(Casella[42].Coordinate, "Qrosso1bianco");
    strcpy(Casella[43].Coordinate, "Rrosso1bianco");
    strcpy(Casella[44].Coordinate, "Srosso1bianco");
    strcpy(Casella[45].Coordinate, "Trosso1bianco");
    strcpy(Casella[46].Coordinate, "Urosso1bianco");
    strcpy(Casella[47].Coordinate, "Vrosso1bianco");
    strcpy(Casella[48].Coordinate, "Wrosso1bianco");
    strcpy(Casella[49].Coordinate, "Xrosso1bianco");
    strcpy(Casella[50].Coordinate, "Yrosso1bianco");
    strcpy(Casella[51].Coordinate, "Zrosso1bianco");
    strcpy(Casella[52].Coordinate, "Aazzurro1bianco");
    strcpy(Casella[53].Coordinate, "Bazzurro1bianco");
    strcpy(Casella[54].Coordinate, "Cazzurro1bianco");
    strcpy(Casella[55].Coordinate, "Dazzurro1bianco");
    strcpy(Casella[56].Coordinate, "Eazzurro1bianco");
    strcpy(Casella[57].Coordinate, "Fazzurro1bianco");
    strcpy(Casella[58].Coordinate, "Gazzurro1bianco");
    strcpy(Casella[59].Coordinate, "Hazzurro1bianco");
    strcpy(Casella[60].Coordinate, "Iazzurro1bianco");
    strcpy(Casella[61].Coordinate, "Jazzurro1bianco");
    strcpy(Casella[62].Coordinate, "Kazzurro1bianco");
    strcpy(Casella[63].Coordinate, "Lazzurro1bianco");
    strcpy(Casella[64].Coordinate, "Mazzurro1bianco");
    strcpy(Casella[65].Coordinate, "Nazzurro1bianco");
    strcpy(Casella[66].Coordinate, "Oazzurro1bianco");
    strcpy(Casella[67].Coordinate, "Pazzurro1bianco");
    strcpy(Casella[68].Coordinate, "Qazzurro1bianco");
    strcpy(Casella[69].Coordinate, "Razzurro1bianco");
    strcpy(Casella[70].Coordinate, "Sazzurro1bianco");
    strcpy(Casella[71].Coordinate, "Tazzurro1bianco");
    strcpy(Casella[72].Coordinate, "Uazzurro1bianco");
    strcpy(Casella[73].Coordinate, "Vazzurro1bianco");
    strcpy(Casella[74].Coordinate, "Wazzurro1bianco");
    strcpy(Casella[75].Coordinate, "Xazzurro1bianco");
    strcpy(Casella[76].Coordinate, "Yazzurro1bianco");
    strcpy(Casella[77].Coordinate, "Zazzurro1bianco");
    strcpy(Casella[78].Coordinate, "Agiallo1bianco");
    strcpy(Casella[79].Coordinate, "Bgiallo1bianco");
    strcpy(Casella[80].Coordinate, "Cgiallo1bianco");
    strcpy(Casella[81].Coordinate, "Dgiallo1bianco");
    strcpy(Casella[82].Coordinate, "Egiallo1bianco");
    strcpy(Casella[83].Coordinate, "Abianco2bianco");
    strcpy(Casella[84].Coordinate, "Bbianco2bianco");
    strcpy(Casella[85].Coordinate, "Cbianco2bianco");
    strcpy(Casella[86].Coordinate, "Dbianco2bianco");
    strcpy(Casella[87].Coordinate, "Ebianco2bianco");
    strcpy(Casella[88].Coordinate, "Fbianco2bianco");
    strcpy(Casella[89].Coordinate, "Gbianco2bianco");
    strcpy(Casella[90].Coordinate, "Hbianco2bianco");
    strcpy(Casella[91].Coordinate, "Ibianco2bianco");
    strcpy(Casella[92].Coordinate, "Jbianco2bianco");
    strcpy(Casella[93].Coordinate, "Kbianco2bianco");
    strcpy(Casella[94].Coordinate, "Lbianco2bianco");
    strcpy(Casella[95].Coordinate, "Mbianco2bianco");
    strcpy(Casella[96].Coordinate, "Nbianco2bianco");
    strcpy(Casella[97].Coordinate, "Obianco2bianco");
    strcpy(Casella[98].Coordinate, "Pbianco2bianco");
    strcpy(Casella[99].Coordinate, "Qbianco2bianco");
    strcpy(Casella[100].Coordinate, "Rbianco2bianco");
    strcpy(Casella[101].Coordinate, "Sbianco2bianco");
    strcpy(Casella[102].Coordinate, "Tbianco2bianco");
    strcpy(Casella[103].Coordinate, "Ubianco2bianco");
    strcpy(Casella[104].Coordinate, "Vbianco2bianco");
    strcpy(Casella[105].Coordinate, "Wbianco2bianco");
    strcpy(Casella[106].Coordinate, "Xbianco2bianco");
    strcpy(Casella[107].Coordinate, "Ybianco2bianco");
    strcpy(Casella[108].Coordinate, "Zbianco2bianco");
    strcpy(Casella[109].Coordinate, "Arosso2bianco");
    strcpy(Casella[110].Coordinate, "Brosso2bianco");
    strcpy(Casella[111].Coordinate, "Crosso2bianco");
    strcpy(Casella[112].Coordinate, "Drosso2bianco");
    strcpy(Casella[113].Coordinate, "Erosso2bianco");
    strcpy(Casella[114].Coordinate, "Frosso2bianco");
    strcpy(Casella[115].Coordinate, "Grosso2bianco");
    strcpy(Casella[116].Coordinate, "Hrosso2bianco");
    strcpy(Casella[117].Coordinate, "Irosso2bianco");
    strcpy(Casella[118].Coordinate, "Jrosso2bianco");
    strcpy(Casella[119].Coordinate, "Krosso2bianco");
    strcpy(Casella[120].Coordinate, "Lrosso2bianco");
    strcpy(Casella[121].Coordinate, "Mrosso2bianco");
    strcpy(Casella[122].Coordinate, "Nrosso2bianco");
    strcpy(Casella[123].Coordinate, "Orosso2bianco");
    strcpy(Casella[124].Coordinate, "Prosso2bianco");
    strcpy(Casella[125].Coordinate, "Qrosso2bianco");
    strcpy(Casella[126].Coordinate, "Rrosso2bianco");
    strcpy(Casella[127].Coordinate, "Srosso2bianco");
    strcpy(Casella[128].Coordinate, "Trosso2bianco");
    strcpy(Casella[129].Coordinate, "Urosso2bianco");
    strcpy(Casella[130].Coordinate, "Vrosso2bianco");
    strcpy(Casella[131].Coordinate, "Wrosso2bianco");
    strcpy(Casella[132].Coordinate, "Xrosso2bianco");
    strcpy(Casella[133].Coordinate, "Yrosso2bianco");
    strcpy(Casella[134].Coordinate, "Zrosso2bianco");
    strcpy(Casella[135].Coordinate, "Aazzurro2bianco");
    strcpy(Casella[136].Coordinate, "Bazzurro2bianco");
    strcpy(Casella[137].Coordinate, "Cazzurro2bianco");
    strcpy(Casella[138].Coordinate, "Dazzurro2bianco");
    strcpy(Casella[139].Coordinate, "Eazzurro2bianco");
    strcpy(Casella[140].Coordinate, "Fazzurro2bianco");
    strcpy(Casella[141].Coordinate, "Gazzurro2bianco");
    strcpy(Casella[142].Coordinate, "Hazzurro2bianco");
    strcpy(Casella[143].Coordinate, "Iazzurro2bianco");
    strcpy(Casella[144].Coordinate, "Jazzurro2bianco");
    strcpy(Casella[145].Coordinate, "Kazzurro2bianco");
    strcpy(Casella[146].Coordinate, "Lazzurro2bianco");
    strcpy(Casella[147].Coordinate, "Mazzurro2bianco");
    strcpy(Casella[148].Coordinate, "Nazzurro2bianco");
    strcpy(Casella[149].Coordinate, "Oazzurro2bianco");
    strcpy(Casella[150].Coordinate, "Pazzurro2bianco");
    strcpy(Casella[151].Coordinate, "Qazzurro2bianco");
    strcpy(Casella[152].Coordinate, "Razzurro2bianco");
    strcpy(Casella[153].Coordinate, "Sazzurro2bianco");
    strcpy(Casella[154].Coordinate, "Tazzurro2bianco");
    strcpy(Casella[155].Coordinate, "Uazzurro2bianco");
    strcpy(Casella[156].Coordinate, "Vazzurro2bianco");
    strcpy(Casella[157].Coordinate, "Wazzurro2bianco");
    strcpy(Casella[158].Coordinate, "Xazzurro2bianco");
    strcpy(Casella[159].Coordinate, "Yazzurro2bianco");
    strcpy(Casella[160].Coordinate, "Zazzurro2bianco");
    strcpy(Casella[161].Coordinate, "Agiallo2bianco");
    strcpy(Casella[162].Coordinate, "Bgiallo2bianco");
    strcpy(Casella[163].Coordinate, "Cgiallo2bianco");
    strcpy(Casella[164].Coordinate, "Dgiallo2bianco");
    strcpy(Casella[165].Coordinate, "Egiallo2bianco");
    strcpy(Casella[166].Coordinate, "Abianco3bianco");
    strcpy(Casella[167].Coordinate, "Bbianco3bianco");
    strcpy(Casella[168].Coordinate, "Cbianco3bianco");
    strcpy(Casella[169].Coordinate, "Dbianco3bianco");
    strcpy(Casella[170].Coordinate, "Ebianco3bianco");
    strcpy(Casella[171].Coordinate, "Fbianco3bianco");
    strcpy(Casella[172].Coordinate, "Gbianco3bianco");
    strcpy(Casella[173].Coordinate, "Hbianco3bianco");
    strcpy(Casella[174].Coordinate, "Ibianco3bianco");
    strcpy(Casella[175].Coordinate, "Jbianco3bianco");
    strcpy(Casella[176].Coordinate, "Kbianco3bianco");
    strcpy(Casella[177].Coordinate, "Lbianco3bianco");
    strcpy(Casella[178].Coordinate, "Mbianco3bianco");
    strcpy(Casella[179].Coordinate, "Nbianco3bianco");
    strcpy(Casella[180].Coordinate, "Obianco3bianco");
    strcpy(Casella[181].Coordinate, "Pbianco3bianco");
    strcpy(Casella[182].Coordinate, "Qbianco3bianco");
    strcpy(Casella[183].Coordinate, "Rbianco3bianco");
    strcpy(Casella[184].Coordinate, "Sbianco3bianco");
    strcpy(Casella[185].Coordinate, "Tbianco3bianco");
    strcpy(Casella[186].Coordinate, "Ubianco3bianco");
    strcpy(Casella[187].Coordinate, "Vbianco3bianco");
    strcpy(Casella[188].Coordinate, "Wbianco3bianco");
    strcpy(Casella[189].Coordinate, "Xbianco3bianco");
    strcpy(Casella[190].Coordinate, "Ybianco3bianco");
    strcpy(Casella[191].Coordinate, "Zbianco3bianco");
    strcpy(Casella[192].Coordinate, "Arosso3bianco");
    strcpy(Casella[193].Coordinate, "Brosso3bianco");
    strcpy(Casella[194].Coordinate, "Crosso3bianco");
    strcpy(Casella[195].Coordinate, "Drosso3bianco");
    strcpy(Casella[196].Coordinate, "Erosso3bianco");
    strcpy(Casella[197].Coordinate, "Frosso3bianco");
    strcpy(Casella[198].Coordinate, "Grosso3bianco");
    strcpy(Casella[199].Coordinate, "Hrosso3bianco");
    strcpy(Casella[200].Coordinate, "Irosso3bianco");
    strcpy(Casella[201].Coordinate, "Jrosso3bianco");
    strcpy(Casella[202].Coordinate, "Krosso3bianco");
    strcpy(Casella[203].Coordinate, "Lrosso3bianco");
    strcpy(Casella[204].Coordinate, "Mrosso3bianco");
    strcpy(Casella[205].Coordinate, "Nrosso3bianco");
    strcpy(Casella[206].Coordinate, "Orosso3bianco");
    strcpy(Casella[207].Coordinate, "Prosso3bianco");
    strcpy(Casella[208].Coordinate, "Qrosso3bianco");
    strcpy(Casella[209].Coordinate, "Rrosso3bianco");
    strcpy(Casella[210].Coordinate, "Srosso3bianco");
    strcpy(Casella[211].Coordinate, "Trosso3bianco");
    strcpy(Casella[212].Coordinate, "Urosso3bianco");
    strcpy(Casella[213].Coordinate, "Vrosso3bianco");
    strcpy(Casella[214].Coordinate, "Wrosso3bianco");
    strcpy(Casella[215].Coordinate, "Xrosso3bianco");
    strcpy(Casella[216].Coordinate, "Yrosso3bianco");
    strcpy(Casella[217].Coordinate, "Zrosso3bianco");
    strcpy(Casella[218].Coordinate, "Aazzurro3bianco");
    strcpy(Casella[219].Coordinate, "Bazzurro3bianco");
    strcpy(Casella[220].Coordinate, "Cazzurro3bianco");
    strcpy(Casella[221].Coordinate, "Dazzurro3bianco");
    strcpy(Casella[222].Coordinate, "Eazzurro3bianco");
    strcpy(Casella[223].Coordinate, "Fazzurro3bianco");
    strcpy(Casella[224].Coordinate, "Gazzurro3bianco");
    strcpy(Casella[225].Coordinate, "Hazzurro3bianco");
    strcpy(Casella[226].Coordinate, "Iazzurro3bianco");
    strcpy(Casella[227].Coordinate, "Jazzurro3bianco");
    strcpy(Casella[228].Coordinate, "Kazzurro3bianco");
    strcpy(Casella[229].Coordinate, "Lazzurro3bianco");
    strcpy(Casella[230].Coordinate, "Mazzurro3bianco");
    strcpy(Casella[231].Coordinate, "Nazzurro3bianco");
    strcpy(Casella[232].Coordinate, "Oazzurro3bianco");
    strcpy(Casella[233].Coordinate, "Pazzurro3bianco");
    strcpy(Casella[234].Coordinate, "Qazzurro3bianco");
    strcpy(Casella[235].Coordinate, "Razzurro3bianco");
    strcpy(Casella[236].Coordinate, "Sazzurro3bianco");
    strcpy(Casella[237].Coordinate, "Tazzurro3bianco");
    strcpy(Casella[238].Coordinate, "Uazzurro3bianco");
    strcpy(Casella[239].Coordinate, "Vazzurro3bianco");
    strcpy(Casella[240].Coordinate, "Wazzurro3bianco");
    strcpy(Casella[241].Coordinate, "Xazzurro3bianco");
    strcpy(Casella[242].Coordinate, "Yazzurro3bianco");
    strcpy(Casella[243].Coordinate, "Zazzurro3bianco");
    strcpy(Casella[244].Coordinate, "Agiallo3bianco");
    strcpy(Casella[245].Coordinate, "Bgiallo3bianco");
    strcpy(Casella[246].Coordinate, "Cgiallo3bianco");
    strcpy(Casella[247].Coordinate, "Dgiallo3bianco");
    strcpy(Casella[248].Coordinate, "Egiallo3bianco");
    strcpy(Casella[249].Coordinate, "Abianco4bianco");
    strcpy(Casella[250].Coordinate, "Bbianco4bianco");
    strcpy(Casella[251].Coordinate, "Cbianco4bianco");
    strcpy(Casella[252].Coordinate, "Dbianco4bianco");
    strcpy(Casella[253].Coordinate, "Ebianco4bianco");
    strcpy(Casella[254].Coordinate, "Fbianco4bianco");
    strcpy(Casella[255].Coordinate, "Gbianco4bianco");
    strcpy(Casella[256].Coordinate, "Hbianco4bianco");
    strcpy(Casella[257].Coordinate, "Ibianco4bianco");
    strcpy(Casella[258].Coordinate, "Jbianco4bianco");
    strcpy(Casella[259].Coordinate, "Kbianco4bianco");
    strcpy(Casella[260].Coordinate, "Lbianco4bianco");
    strcpy(Casella[261].Coordinate, "Mbianco4bianco");
    strcpy(Casella[262].Coordinate, "Nbianco4bianco");
    strcpy(Casella[263].Coordinate, "Obianco4bianco");
    strcpy(Casella[264].Coordinate, "Pbianco4bianco");
    strcpy(Casella[265].Coordinate, "Qbianco4bianco");
    strcpy(Casella[266].Coordinate, "Rbianco4bianco");
    strcpy(Casella[267].Coordinate, "Sbianco4bianco");
    strcpy(Casella[268].Coordinate, "Tbianco4bianco");
    strcpy(Casella[269].Coordinate, "Ubianco4bianco");
    strcpy(Casella[270].Coordinate, "Vbianco4bianco");
    strcpy(Casella[271].Coordinate, "Wbianco4bianco");
    strcpy(Casella[272].Coordinate, "Xbianco4bianco");
    strcpy(Casella[273].Coordinate, "Ybianco4bianco");
    strcpy(Casella[274].Coordinate, "Zbianco4bianco");
    strcpy(Casella[275].Coordinate, "Arosso4bianco");
    strcpy(Casella[276].Coordinate, "Brosso4bianco");
    strcpy(Casella[277].Coordinate, "Crosso4bianco");
    strcpy(Casella[278].Coordinate, "Drosso4bianco");
    strcpy(Casella[279].Coordinate, "Erosso4bianco");
    strcpy(Casella[280].Coordinate, "Frosso4bianco");
    strcpy(Casella[281].Coordinate, "Grosso4bianco");
    strcpy(Casella[282].Coordinate, "Hrosso4bianco");
    strcpy(Casella[283].Coordinate, "Irosso4bianco");
    strcpy(Casella[284].Coordinate, "Jrosso4bianco");
    strcpy(Casella[285].Coordinate, "Krosso4bianco");
    strcpy(Casella[286].Coordinate, "Lrosso4bianco");
    strcpy(Casella[287].Coordinate, "Mrosso4bianco");
    strcpy(Casella[288].Coordinate, "Nrosso4bianco");
    strcpy(Casella[289].Coordinate, "Orosso4bianco");
    strcpy(Casella[290].Coordinate, "Prosso4bianco");
    strcpy(Casella[291].Coordinate, "Qrosso4bianco");
    strcpy(Casella[292].Coordinate, "Rrosso4bianco");
    strcpy(Casella[293].Coordinate, "Srosso4bianco");
    strcpy(Casella[294].Coordinate, "Trosso4bianco");
    strcpy(Casella[295].Coordinate, "Urosso4bianco");
    strcpy(Casella[296].Coordinate, "Vrosso4bianco");
    strcpy(Casella[297].Coordinate, "Wrosso4bianco");
    strcpy(Casella[298].Coordinate, "Xrosso4bianco");
    strcpy(Casella[299].Coordinate, "Yrosso4bianco");
    strcpy(Casella[300].Coordinate, "Zrosso4bianco");
    strcpy(Casella[301].Coordinate, "Aazzurro4bianco");
    strcpy(Casella[302].Coordinate, "Bazzurro4bianco");
    strcpy(Casella[303].Coordinate, "Cazzurro4bianco");
    strcpy(Casella[304].Coordinate, "Dazzurro4bianco");
    strcpy(Casella[305].Coordinate, "Eazzurro4bianco");
    strcpy(Casella[306].Coordinate, "Fazzurro4bianco");
    strcpy(Casella[307].Coordinate, "Gazzurro4bianco");
    strcpy(Casella[308].Coordinate, "Hazzurro4bianco");
    strcpy(Casella[309].Coordinate, "Iazzurro4bianco");
    strcpy(Casella[310].Coordinate, "Jazzurro4bianco");
    strcpy(Casella[311].Coordinate, "Kazzurro4bianco");
    strcpy(Casella[312].Coordinate, "Lazzurro4bianco");
    strcpy(Casella[313].Coordinate, "Mazzurro4bianco");
    strcpy(Casella[314].Coordinate, "Nazzurro4bianco");
    strcpy(Casella[315].Coordinate, "Oazzurro4bianco");
    strcpy(Casella[316].Coordinate, "Pazzurro4bianco");
    strcpy(Casella[317].Coordinate, "Qazzurro4bianco");
    strcpy(Casella[318].Coordinate, "Razzurro4bianco");
    strcpy(Casella[319].Coordinate, "Sazzurro4bianco");
    strcpy(Casella[320].Coordinate, "Tazzurro4bianco");
    strcpy(Casella[321].Coordinate, "Uazzurro4bianco");
    strcpy(Casella[322].Coordinate, "Vazzurro4bianco");
    strcpy(Casella[323].Coordinate, "Wazzurro4bianco");
    strcpy(Casella[324].Coordinate, "Xazzurro4bianco");
    strcpy(Casella[325].Coordinate, "Yazzurro4bianco");
    strcpy(Casella[326].Coordinate, "Zazzurro4bianco");
    strcpy(Casella[327].Coordinate, "Agiallo4bianco");
    strcpy(Casella[328].Coordinate, "Bgiallo4bianco");
    strcpy(Casella[329].Coordinate, "Cgiallo4bianco");
    strcpy(Casella[330].Coordinate, "Dgiallo4bianco");
    strcpy(Casella[331].Coordinate, "Egiallo4bianco");
    strcpy(Casella[332].Coordinate, "Abianco5bianco");
    strcpy(Casella[333].Coordinate, "Bbianco5bianco");
    strcpy(Casella[334].Coordinate, "Cbianco5bianco");
    strcpy(Casella[335].Coordinate, "Dbianco5bianco");
    strcpy(Casella[336].Coordinate, "Ebianco5bianco");
    strcpy(Casella[337].Coordinate, "Fbianco5bianco");
    strcpy(Casella[338].Coordinate, "Gbianco5bianco");
    strcpy(Casella[339].Coordinate, "Hbianco5bianco");
    strcpy(Casella[340].Coordinate, "Ibianco5bianco");
    strcpy(Casella[341].Coordinate, "Jbianco5bianco");
    strcpy(Casella[342].Coordinate, "Kbianco5bianco");
    strcpy(Casella[343].Coordinate, "Lbianco5bianco");
    strcpy(Casella[344].Coordinate, "Mbianco5bianco");
    strcpy(Casella[345].Coordinate, "Nbianco5bianco");
    strcpy(Casella[346].Coordinate, "Obianco5bianco");
    strcpy(Casella[347].Coordinate, "Pbianco5bianco");
    strcpy(Casella[348].Coordinate, "Qbianco5bianco");
    strcpy(Casella[349].Coordinate, "Rbianco5bianco");
    strcpy(Casella[350].Coordinate, "Sbianco5bianco");
    strcpy(Casella[351].Coordinate, "Tbianco5bianco");
    strcpy(Casella[352].Coordinate, "Ubianco5bianco");
    strcpy(Casella[353].Coordinate, "Vbianco5bianco");
    strcpy(Casella[354].Coordinate, "Wbianco5bianco");
    strcpy(Casella[355].Coordinate, "Xbianco5bianco");
    strcpy(Casella[356].Coordinate, "Ybianco5bianco");
    strcpy(Casella[357].Coordinate, "Zbianco5bianco");
    strcpy(Casella[358].Coordinate, "Arosso5bianco");
    strcpy(Casella[359].Coordinate, "Brosso5bianco");
    strcpy(Casella[360].Coordinate, "Crosso5bianco");
    strcpy(Casella[361].Coordinate, "Drosso5bianco");
    strcpy(Casella[362].Coordinate, "Erosso5bianco");
    strcpy(Casella[363].Coordinate, "Frosso5bianco");
    strcpy(Casella[364].Coordinate, "Grosso5bianco");
    strcpy(Casella[365].Coordinate, "Hrosso5bianco");
    strcpy(Casella[366].Coordinate, "Irosso5bianco");
    strcpy(Casella[367].Coordinate, "Jrosso5bianco");
    strcpy(Casella[368].Coordinate, "Krosso5bianco");
    strcpy(Casella[369].Coordinate, "Lrosso5bianco");
    strcpy(Casella[370].Coordinate, "Mrosso5bianco");
    strcpy(Casella[371].Coordinate, "Nrosso5bianco");
    strcpy(Casella[372].Coordinate, "Orosso5bianco");
    strcpy(Casella[373].Coordinate, "Prosso5bianco");
    strcpy(Casella[374].Coordinate, "Qrosso5bianco");
    strcpy(Casella[375].Coordinate, "Rrosso5bianco");
    strcpy(Casella[376].Coordinate, "Srosso5bianco");
    strcpy(Casella[377].Coordinate, "Trosso5bianco");
    strcpy(Casella[378].Coordinate, "Urosso5bianco");
    strcpy(Casella[379].Coordinate, "Vrosso5bianco");
    strcpy(Casella[380].Coordinate, "Wrosso5bianco");
    strcpy(Casella[381].Coordinate, "Xrosso5bianco");
    strcpy(Casella[382].Coordinate, "Yrosso5bianco");
    strcpy(Casella[383].Coordinate, "Zrosso5bianco");
    strcpy(Casella[384].Coordinate, "Aazzurro5bianco");
    strcpy(Casella[385].Coordinate, "Bazzurro5bianco");
    strcpy(Casella[386].Coordinate, "Cazzurro5bianco");
    strcpy(Casella[387].Coordinate, "Dazzurro5bianco");
    strcpy(Casella[388].Coordinate, "Eazzurro5bianco");
    strcpy(Casella[389].Coordinate, "Fazzurro5bianco");
    strcpy(Casella[390].Coordinate, "Gazzurro5bianco");
    strcpy(Casella[391].Coordinate, "Hazzurro5bianco");
    strcpy(Casella[392].Coordinate, "Iazzurro5bianco");
    strcpy(Casella[393].Coordinate, "Jazzurro5bianco");
    strcpy(Casella[394].Coordinate, "Kazzurro5bianco");
    strcpy(Casella[395].Coordinate, "Lazzurro5bianco");
    strcpy(Casella[396].Coordinate, "Mazzurro5bianco");
    strcpy(Casella[397].Coordinate, "Nazzurro5bianco");
    strcpy(Casella[398].Coordinate, "Oazzurro5bianco");
    strcpy(Casella[399].Coordinate, "Pazzurro5bianco");
    strcpy(Casella[400].Coordinate, "Qazzurro5bianco");
    strcpy(Casella[401].Coordinate, "Razzurro5bianco");
    strcpy(Casella[402].Coordinate, "Sazzurro5bianco");
    strcpy(Casella[403].Coordinate, "Tazzurro5bianco");
    strcpy(Casella[404].Coordinate, "Uazzurro5bianco");
    strcpy(Casella[405].Coordinate, "Vazzurro5bianco");
    strcpy(Casella[406].Coordinate, "Wazzurro5bianco");
    strcpy(Casella[407].Coordinate, "Xazzurro5bianco");
    strcpy(Casella[408].Coordinate, "Yazzurro5bianco");
    strcpy(Casella[409].Coordinate, "Zazzurro5bianco");
    strcpy(Casella[410].Coordinate, "Agiallo5bianco");
    strcpy(Casella[411].Coordinate, "Bgiallo5bianco");
    strcpy(Casella[412].Coordinate, "Cgiallo5bianco");
    strcpy(Casella[413].Coordinate, "Dgiallo5bianco");
    strcpy(Casella[414].Coordinate, "Egiallo5bianco");
    strcpy(Casella[415].Coordinate, "Abianco6bianco");
    strcpy(Casella[416].Coordinate, "Bbianco6bianco");
    strcpy(Casella[417].Coordinate, "Cbianco6bianco");
    strcpy(Casella[418].Coordinate, "Dbianco6bianco");
    strcpy(Casella[419].Coordinate, "Ebianco6bianco");
    strcpy(Casella[420].Coordinate, "Fbianco6bianco");
    strcpy(Casella[421].Coordinate, "Gbianco6bianco");
    strcpy(Casella[422].Coordinate, "Hbianco6bianco");
    strcpy(Casella[423].Coordinate, "Ibianco6bianco");
    strcpy(Casella[424].Coordinate, "Jbianco6bianco");
    strcpy(Casella[425].Coordinate, "Kbianco6bianco");
    strcpy(Casella[426].Coordinate, "Lbianco6bianco");
    strcpy(Casella[427].Coordinate, "Mbianco6bianco");
    strcpy(Casella[428].Coordinate, "Nbianco6bianco");
    strcpy(Casella[429].Coordinate, "Obianco6bianco");
    strcpy(Casella[430].Coordinate, "Pbianco6bianco");
    strcpy(Casella[431].Coordinate, "Qbianco6bianco");
    strcpy(Casella[432].Coordinate, "Rbianco6bianco");
    strcpy(Casella[433].Coordinate, "Sbianco6bianco");
    strcpy(Casella[434].Coordinate, "Tbianco6bianco");
    strcpy(Casella[435].Coordinate, "Ubianco6bianco");
    strcpy(Casella[436].Coordinate, "Vbianco6bianco");
    strcpy(Casella[437].Coordinate, "Wbianco6bianco");
    strcpy(Casella[438].Coordinate, "Xbianco6bianco");
    strcpy(Casella[439].Coordinate, "Ybianco6bianco");
    strcpy(Casella[440].Coordinate, "Zbianco6bianco");
    strcpy(Casella[441].Coordinate, "Arosso6bianco");
    strcpy(Casella[442].Coordinate, "Brosso6bianco");
    strcpy(Casella[443].Coordinate, "Crosso6bianco");
    strcpy(Casella[444].Coordinate, "Drosso6bianco");
    strcpy(Casella[445].Coordinate, "Erosso6bianco");
    strcpy(Casella[446].Coordinate, "Frosso6bianco");
    strcpy(Casella[447].Coordinate, "Grosso6bianco");
    strcpy(Casella[448].Coordinate, "Hrosso6bianco");
    strcpy(Casella[449].Coordinate, "Irosso6bianco");
    strcpy(Casella[450].Coordinate, "Jrosso6bianco");
    strcpy(Casella[451].Coordinate, "Krosso6bianco");
    strcpy(Casella[452].Coordinate, "Lrosso6bianco");
    strcpy(Casella[453].Coordinate, "Mrosso6bianco");
    strcpy(Casella[454].Coordinate, "Nrosso6bianco");
    strcpy(Casella[455].Coordinate, "Orosso6bianco");
    strcpy(Casella[456].Coordinate, "Prosso6bianco");
    strcpy(Casella[457].Coordinate, "Qrosso6bianco");
    strcpy(Casella[458].Coordinate, "Rrosso6bianco");
    strcpy(Casella[459].Coordinate, "Srosso6bianco");
    strcpy(Casella[460].Coordinate, "Trosso6bianco");
    strcpy(Casella[461].Coordinate, "Urosso6bianco");
    strcpy(Casella[462].Coordinate, "Vrosso6bianco");
    strcpy(Casella[463].Coordinate, "Wrosso6bianco");
    strcpy(Casella[464].Coordinate, "Xrosso6bianco");
    strcpy(Casella[465].Coordinate, "Yrosso6bianco");
    strcpy(Casella[466].Coordinate, "Zrosso6bianco");
    strcpy(Casella[467].Coordinate, "Aazzurro6bianco");
    strcpy(Casella[468].Coordinate, "Bazzurro6bianco");
    strcpy(Casella[469].Coordinate, "Cazzurro6bianco");
    strcpy(Casella[470].Coordinate, "Dazzurro6bianco");
    strcpy(Casella[471].Coordinate, "Eazzurro6bianco");
    strcpy(Casella[472].Coordinate, "Fazzurro6bianco");
    strcpy(Casella[473].Coordinate, "Gazzurro6bianco");
    strcpy(Casella[474].Coordinate, "Hazzurro6bianco");
    strcpy(Casella[475].Coordinate, "Iazzurro6bianco");
    strcpy(Casella[476].Coordinate, "Jazzurro6bianco");
    strcpy(Casella[477].Coordinate, "Kazzurro6bianco");
    strcpy(Casella[478].Coordinate, "Lazzurro6bianco");
    strcpy(Casella[479].Coordinate, "Mazzurro6bianco");
    strcpy(Casella[480].Coordinate, "Nazzurro6bianco");
    strcpy(Casella[481].Coordinate, "Oazzurro6bianco");
    strcpy(Casella[482].Coordinate, "Pazzurro6bianco");
    strcpy(Casella[483].Coordinate, "Qazzurro6bianco");
    strcpy(Casella[484].Coordinate, "Razzurro6bianco");
    strcpy(Casella[485].Coordinate, "Sazzurro6bianco");
    strcpy(Casella[486].Coordinate, "Tazzurro6bianco");
    strcpy(Casella[487].Coordinate, "Uazzurro6bianco");
    strcpy(Casella[488].Coordinate, "Vazzurro6bianco");
    strcpy(Casella[489].Coordinate, "Wazzurro6bianco");
    strcpy(Casella[490].Coordinate, "Xazzurro6bianco");
    strcpy(Casella[491].Coordinate, "Yazzurro6bianco");
    strcpy(Casella[492].Coordinate, "Zazzurro6bianco");
    strcpy(Casella[493].Coordinate, "Agiallo6bianco");
    strcpy(Casella[494].Coordinate, "Bgiallo6bianco");
    strcpy(Casella[495].Coordinate, "Cgiallo6bianco");
    strcpy(Casella[496].Coordinate, "Dgiallo6bianco");
    strcpy(Casella[497].Coordinate, "Egiallo6bianco");
    strcpy(Casella[498].Coordinate, "Abianco7bianco");
    strcpy(Casella[499].Coordinate, "Bbianco7bianco");
    strcpy(Casella[500].Coordinate, "Cbianco7bianco");
    strcpy(Casella[501].Coordinate, "Dbianco7bianco");
    strcpy(Casella[502].Coordinate, "Ebianco7bianco");
    strcpy(Casella[503].Coordinate, "Fbianco7bianco");
    strcpy(Casella[504].Coordinate, "Gbianco7bianco");
    strcpy(Casella[505].Coordinate, "Hbianco7bianco");
    strcpy(Casella[506].Coordinate, "Ibianco7bianco");
    strcpy(Casella[507].Coordinate, "Jbianco7bianco");
    strcpy(Casella[508].Coordinate, "Kbianco7bianco");
    strcpy(Casella[509].Coordinate, "Lbianco7bianco");
    strcpy(Casella[510].Coordinate, "Mbianco7bianco");
    strcpy(Casella[511].Coordinate, "Nbianco7bianco");
    strcpy(Casella[512].Coordinate, "Obianco7bianco");
    strcpy(Casella[513].Coordinate, "Pbianco7bianco");
    strcpy(Casella[514].Coordinate, "Qbianco7bianco");
    strcpy(Casella[515].Coordinate, "Rbianco7bianco");
    strcpy(Casella[516].Coordinate, "Sbianco7bianco");
    strcpy(Casella[517].Coordinate, "Tbianco7bianco");
    strcpy(Casella[518].Coordinate, "Ubianco7bianco");
    strcpy(Casella[519].Coordinate, "Vbianco7bianco");
    strcpy(Casella[520].Coordinate, "Wbianco7bianco");
    strcpy(Casella[521].Coordinate, "Xbianco7bianco");
    strcpy(Casella[522].Coordinate, "Ybianco7bianco");
    strcpy(Casella[523].Coordinate, "Zbianco7bianco");
    strcpy(Casella[524].Coordinate, "Arosso7bianco");
    strcpy(Casella[525].Coordinate, "Brosso7bianco");
    strcpy(Casella[526].Coordinate, "Crosso7bianco");
    strcpy(Casella[527].Coordinate, "Drosso7bianco");
    strcpy(Casella[528].Coordinate, "Erosso7bianco");
    strcpy(Casella[529].Coordinate, "Frosso7bianco");
    strcpy(Casella[530].Coordinate, "Grosso7bianco");
    strcpy(Casella[531].Coordinate, "Hrosso7bianco");
    strcpy(Casella[532].Coordinate, "Irosso7bianco");
    strcpy(Casella[533].Coordinate, "Jrosso7bianco");
    strcpy(Casella[534].Coordinate, "Krosso7bianco");
    strcpy(Casella[535].Coordinate, "Lrosso7bianco");
    strcpy(Casella[536].Coordinate, "Mrosso7bianco");
    strcpy(Casella[537].Coordinate, "Nrosso7bianco");
    strcpy(Casella[538].Coordinate, "Orosso7bianco");
    strcpy(Casella[539].Coordinate, "Prosso7bianco");
    strcpy(Casella[540].Coordinate, "Qrosso7bianco");
    strcpy(Casella[541].Coordinate, "Rrosso7bianco");
    strcpy(Casella[542].Coordinate, "Srosso7bianco");
    strcpy(Casella[543].Coordinate, "Trosso7bianco");
    strcpy(Casella[544].Coordinate, "Urosso7bianco");
    strcpy(Casella[545].Coordinate, "Vrosso7bianco");
    strcpy(Casella[546].Coordinate, "Wrosso7bianco");
    strcpy(Casella[547].Coordinate, "Xrosso7bianco");
    strcpy(Casella[548].Coordinate, "Yrosso7bianco");
    strcpy(Casella[549].Coordinate, "Zrosso7bianco");
    strcpy(Casella[550].Coordinate, "Aazzurro7bianco");
    strcpy(Casella[551].Coordinate, "Bazzurro7bianco");
    strcpy(Casella[552].Coordinate, "Cazzurro7bianco");
    strcpy(Casella[553].Coordinate, "Dazzurro7bianco");
    strcpy(Casella[554].Coordinate, "Eazzurro7bianco");
    strcpy(Casella[555].Coordinate, "Fazzurro7bianco");
    strcpy(Casella[556].Coordinate, "Gazzurro7bianco");
    strcpy(Casella[557].Coordinate, "Hazzurro7bianco");
    strcpy(Casella[558].Coordinate, "Iazzurro7bianco");
    strcpy(Casella[559].Coordinate, "Jazzurro7bianco");
    strcpy(Casella[560].Coordinate, "Kazzurro7bianco");
    strcpy(Casella[561].Coordinate, "Lazzurro7bianco");
    strcpy(Casella[562].Coordinate, "Mazzurro7bianco");
    strcpy(Casella[563].Coordinate, "Nazzurro7bianco");
    strcpy(Casella[564].Coordinate, "Oazzurro7bianco");
    strcpy(Casella[565].Coordinate, "Pazzurro7bianco");
    strcpy(Casella[566].Coordinate, "Qazzurro7bianco");
    strcpy(Casella[567].Coordinate, "Razzurro7bianco");
    strcpy(Casella[568].Coordinate, "Sazzurro7bianco");
    strcpy(Casella[569].Coordinate, "Tazzurro7bianco");
    strcpy(Casella[570].Coordinate, "Uazzurro7bianco");
    strcpy(Casella[571].Coordinate, "Vazzurro7bianco");
    strcpy(Casella[572].Coordinate, "Wazzurro7bianco");
    strcpy(Casella[573].Coordinate, "Xazzurro7bianco");
    strcpy(Casella[574].Coordinate, "Yazzurro7bianco");
    strcpy(Casella[575].Coordinate, "Zazzurro7bianco");
    strcpy(Casella[576].Coordinate, "Agiallo7bianco");
    strcpy(Casella[577].Coordinate, "Bgiallo7bianco");
    strcpy(Casella[578].Coordinate, "Cgiallo7bianco");
    strcpy(Casella[579].Coordinate, "Dgiallo7bianco");
    strcpy(Casella[580].Coordinate, "Egiallo7bianco");
    strcpy(Casella[581].Coordinate, "Abianco8bianco");
    strcpy(Casella[582].Coordinate, "Bbianco8bianco");
    strcpy(Casella[583].Coordinate, "Cbianco8bianco");
    strcpy(Casella[584].Coordinate, "Dbianco8bianco");
    strcpy(Casella[585].Coordinate, "Ebianco8bianco");
    strcpy(Casella[586].Coordinate, "Fbianco8bianco");
    strcpy(Casella[587].Coordinate, "Gbianco8bianco");
    strcpy(Casella[588].Coordinate, "Hbianco8bianco");
    strcpy(Casella[589].Coordinate, "Ibianco8bianco");
    strcpy(Casella[590].Coordinate, "Jbianco8bianco");
    strcpy(Casella[591].Coordinate, "Kbianco8bianco");
    strcpy(Casella[592].Coordinate, "Lbianco8bianco");
    strcpy(Casella[593].Coordinate, "Mbianco8bianco");
    strcpy(Casella[594].Coordinate, "Nbianco8bianco");
    strcpy(Casella[595].Coordinate, "Obianco8bianco");
    strcpy(Casella[596].Coordinate, "Pbianco8bianco");
    strcpy(Casella[597].Coordinate, "Qbianco8bianco");
    strcpy(Casella[598].Coordinate, "Rbianco8bianco");
    strcpy(Casella[599].Coordinate, "Sbianco8bianco");
    strcpy(Casella[600].Coordinate, "Tbianco8bianco");
    strcpy(Casella[601].Coordinate, "Ubianco8bianco");
    strcpy(Casella[602].Coordinate, "Vbianco8bianco");
    strcpy(Casella[603].Coordinate, "Wbianco8bianco");
    strcpy(Casella[604].Coordinate, "Xbianco8bianco");
    strcpy(Casella[605].Coordinate, "Ybianco8bianco");
    strcpy(Casella[606].Coordinate, "Zbianco8bianco");
    strcpy(Casella[607].Coordinate, "Arosso8bianco");
    strcpy(Casella[608].Coordinate, "Brosso8bianco");
    strcpy(Casella[609].Coordinate, "Crosso8bianco");
    strcpy(Casella[610].Coordinate, "Drosso8bianco");
    strcpy(Casella[611].Coordinate, "Erosso8bianco");
    strcpy(Casella[612].Coordinate, "Frosso8bianco");
    strcpy(Casella[613].Coordinate, "Grosso8bianco");
    strcpy(Casella[614].Coordinate, "Hrosso8bianco");
    strcpy(Casella[615].Coordinate, "Irosso8bianco");
    strcpy(Casella[616].Coordinate, "Jrosso8bianco");
    strcpy(Casella[617].Coordinate, "Krosso8bianco");
    strcpy(Casella[618].Coordinate, "Lrosso8bianco");
    strcpy(Casella[619].Coordinate, "Mrosso8bianco");
    strcpy(Casella[620].Coordinate, "Nrosso8bianco");
    strcpy(Casella[621].Coordinate, "Orosso8bianco");
    strcpy(Casella[622].Coordinate, "Prosso8bianco");
    strcpy(Casella[623].Coordinate, "Qrosso8bianco");
    strcpy(Casella[624].Coordinate, "Rrosso8bianco");
    strcpy(Casella[625].Coordinate, "Srosso8bianco");
    strcpy(Casella[626].Coordinate, "Trosso8bianco");
    strcpy(Casella[627].Coordinate, "Urosso8bianco");
    strcpy(Casella[628].Coordinate, "Vrosso8bianco");
    strcpy(Casella[629].Coordinate, "Wrosso8bianco");
    strcpy(Casella[630].Coordinate, "Xrosso8bianco");
    strcpy(Casella[631].Coordinate, "Yrosso8bianco");
    strcpy(Casella[632].Coordinate, "Zrosso8bianco");
    strcpy(Casella[633].Coordinate, "Aazzurro8bianco");
    strcpy(Casella[634].Coordinate, "Bazzurro8bianco");
    strcpy(Casella[635].Coordinate, "Cazzurro8bianco");
    strcpy(Casella[636].Coordinate, "Dazzurro8bianco");
    strcpy(Casella[637].Coordinate, "Eazzurro8bianco");
    strcpy(Casella[638].Coordinate, "Fazzurro8bianco");
    strcpy(Casella[639].Coordinate, "Gazzurro8bianco");
    strcpy(Casella[640].Coordinate, "Hazzurro8bianco");
    strcpy(Casella[641].Coordinate, "Iazzurro8bianco");
    strcpy(Casella[642].Coordinate, "Jazzurro8bianco");
    strcpy(Casella[643].Coordinate, "Kazzurro8bianco");
    strcpy(Casella[644].Coordinate, "Lazzurro8bianco");
    strcpy(Casella[645].Coordinate, "Mazzurro8bianco");
    strcpy(Casella[646].Coordinate, "Nazzurro8bianco");
    strcpy(Casella[647].Coordinate, "Oazzurro8bianco");
    strcpy(Casella[648].Coordinate, "Pazzurro8bianco");
    strcpy(Casella[649].Coordinate, "Qazzurro8bianco");
    strcpy(Casella[650].Coordinate, "Razzurro8bianco");
    strcpy(Casella[651].Coordinate, "Sazzurro8bianco");
    strcpy(Casella[652].Coordinate, "Tazzurro8bianco");
    strcpy(Casella[653].Coordinate, "Uazzurro8bianco");
    strcpy(Casella[654].Coordinate, "Vazzurro8bianco");
    strcpy(Casella[655].Coordinate, "Wazzurro8bianco");
    strcpy(Casella[656].Coordinate, "Xazzurro8bianco");
    strcpy(Casella[657].Coordinate, "Yazzurro8bianco");
    strcpy(Casella[658].Coordinate, "Zazzurro8bianco");
    strcpy(Casella[659].Coordinate, "Agiallo8bianco");
    strcpy(Casella[660].Coordinate, "Bgiallo8bianco");
    strcpy(Casella[661].Coordinate, "Cgiallo8bianco");
    strcpy(Casella[662].Coordinate, "Dgiallo8bianco");
    strcpy(Casella[663].Coordinate, "Egiallo8bianco");
    strcpy(Casella[664].Coordinate, "Abianco9bianco");
    strcpy(Casella[665].Coordinate, "Bbianco9bianco");
    strcpy(Casella[666].Coordinate, "Cbianco9bianco");
    strcpy(Casella[667].Coordinate, "Dbianco9bianco");
    strcpy(Casella[668].Coordinate, "Ebianco9bianco");
    strcpy(Casella[669].Coordinate, "Fbianco9bianco");
    strcpy(Casella[670].Coordinate, "Gbianco9bianco");
    strcpy(Casella[671].Coordinate, "Hbianco9bianco");
    strcpy(Casella[672].Coordinate, "Ibianco9bianco");
    strcpy(Casella[673].Coordinate, "Jbianco9bianco");
    strcpy(Casella[674].Coordinate, "Kbianco9bianco");
    strcpy(Casella[675].Coordinate, "Lbianco9bianco");
    strcpy(Casella[676].Coordinate, "Mbianco9bianco");
    strcpy(Casella[677].Coordinate, "Nbianco9bianco");
    strcpy(Casella[678].Coordinate, "Obianco9bianco");
    strcpy(Casella[679].Coordinate, "Pbianco9bianco");
    strcpy(Casella[680].Coordinate, "Qbianco9bianco");
    strcpy(Casella[681].Coordinate, "Rbianco9bianco");
    strcpy(Casella[682].Coordinate, "Sbianco9bianco");
    strcpy(Casella[683].Coordinate, "Tbianco9bianco");
    strcpy(Casella[684].Coordinate, "Ubianco9bianco");
    strcpy(Casella[685].Coordinate, "Vbianco9bianco");
    strcpy(Casella[686].Coordinate, "Wbianco9bianco");
    strcpy(Casella[687].Coordinate, "Xbianco9bianco");
    strcpy(Casella[688].Coordinate, "Ybianco9bianco");
    strcpy(Casella[689].Coordinate, "Zbianco9bianco");
    strcpy(Casella[690].Coordinate, "Arosso9bianco");
    strcpy(Casella[691].Coordinate, "Brosso9bianco");
    strcpy(Casella[692].Coordinate, "Crosso9bianco");
    strcpy(Casella[693].Coordinate, "Drosso9bianco");
    strcpy(Casella[694].Coordinate, "Erosso9bianco");
    strcpy(Casella[695].Coordinate, "Frosso9bianco");
    strcpy(Casella[696].Coordinate, "Grosso9bianco");
    strcpy(Casella[697].Coordinate, "Hrosso9bianco");
    strcpy(Casella[698].Coordinate, "Irosso9bianco");
    strcpy(Casella[699].Coordinate, "Jrosso9bianco");
    strcpy(Casella[700].Coordinate, "Krosso9bianco");
    strcpy(Casella[701].Coordinate, "Lrosso9bianco");
    strcpy(Casella[702].Coordinate, "Mrosso9bianco");
    strcpy(Casella[703].Coordinate, "Nrosso9bianco");
    strcpy(Casella[704].Coordinate, "Orosso9bianco");
    strcpy(Casella[705].Coordinate, "Prosso9bianco");
    strcpy(Casella[706].Coordinate, "Qrosso9bianco");
    strcpy(Casella[707].Coordinate, "Rrosso9bianco");
    strcpy(Casella[708].Coordinate, "Srosso9bianco");
    strcpy(Casella[709].Coordinate, "Trosso9bianco");
    strcpy(Casella[710].Coordinate, "Urosso9bianco");
    strcpy(Casella[711].Coordinate, "Vrosso9bianco");
    strcpy(Casella[712].Coordinate, "Wrosso9bianco");
    strcpy(Casella[713].Coordinate, "Xrosso9bianco");
    strcpy(Casella[714].Coordinate, "Yrosso9bianco");
    strcpy(Casella[715].Coordinate, "Zrosso9bianco");
    strcpy(Casella[716].Coordinate, "Aazzurro9bianco");
    strcpy(Casella[717].Coordinate, "Bazzurro9bianco");
    strcpy(Casella[718].Coordinate, "Cazzurro9bianco");
    strcpy(Casella[719].Coordinate, "Dazzurro9bianco");
    strcpy(Casella[720].Coordinate, "Eazzurro9bianco");
    strcpy(Casella[721].Coordinate, "Fazzurro9bianco");
    strcpy(Casella[722].Coordinate, "Gazzurro9bianco");
    strcpy(Casella[723].Coordinate, "Hazzurro9bianco");
    strcpy(Casella[724].Coordinate, "Iazzurro9bianco");
    strcpy(Casella[725].Coordinate, "Jazzurro9bianco");
    strcpy(Casella[726].Coordinate, "Kazzurro9bianco");
    strcpy(Casella[727].Coordinate, "Lazzurro9bianco");
    strcpy(Casella[728].Coordinate, "Mazzurro9bianco");
    strcpy(Casella[729].Coordinate, "Nazzurro9bianco");
    strcpy(Casella[730].Coordinate, "Oazzurro9bianco");
    strcpy(Casella[731].Coordinate, "Pazzurro9bianco");
    strcpy(Casella[732].Coordinate, "Qazzurro9bianco");
    strcpy(Casella[733].Coordinate, "Razzurro9bianco");
    strcpy(Casella[734].Coordinate, "Sazzurro9bianco");
    strcpy(Casella[735].Coordinate, "Tazzurro9bianco");
    strcpy(Casella[736].Coordinate, "Uazzurro9bianco");
    strcpy(Casella[737].Coordinate, "Vazzurro9bianco");
    strcpy(Casella[738].Coordinate, "Wazzurro9bianco");
    strcpy(Casella[739].Coordinate, "Xazzurro9bianco");
    strcpy(Casella[740].Coordinate, "Yazzurro9bianco");
    strcpy(Casella[741].Coordinate, "Zazzurro9bianco");
    strcpy(Casella[742].Coordinate, "Agiallo9bianco");
    strcpy(Casella[743].Coordinate, "Bgiallo9bianco");
    strcpy(Casella[744].Coordinate, "Cgiallo9bianco");
    strcpy(Casella[745].Coordinate, "Dgiallo9bianco");
    strcpy(Casella[746].Coordinate, "Egiallo9bianco");
    strcpy(Casella[747].Coordinate, "Abianco1rosso");
    strcpy(Casella[748].Coordinate, "Bbianco1rosso");
    strcpy(Casella[749].Coordinate, "Cbianco1rosso");
    strcpy(Casella[750].Coordinate, "Dbianco1rosso");
    strcpy(Casella[751].Coordinate, "Ebianco1rosso");
    strcpy(Casella[752].Coordinate, "Fbianco1rosso");
    strcpy(Casella[753].Coordinate, "Gbianco1rosso");
    strcpy(Casella[754].Coordinate, "Hbianco1rosso");
    strcpy(Casella[755].Coordinate, "Ibianco1rosso");
    strcpy(Casella[756].Coordinate, "Jbianco1rosso");
    strcpy(Casella[757].Coordinate, "Kbianco1rosso");
    strcpy(Casella[758].Coordinate, "Lbianco1rosso");
    strcpy(Casella[759].Coordinate, "Mbianco1rosso");
    strcpy(Casella[760].Coordinate, "Nbianco1rosso");
    strcpy(Casella[761].Coordinate, "Obianco1rosso");
    strcpy(Casella[762].Coordinate, "Pbianco1rosso");
    strcpy(Casella[763].Coordinate, "Qbianco1rosso");
    strcpy(Casella[764].Coordinate, "Rbianco1rosso");
    strcpy(Casella[765].Coordinate, "Sbianco1rosso");
    strcpy(Casella[766].Coordinate, "Tbianco1rosso");
    strcpy(Casella[767].Coordinate, "Ubianco1rosso");
    strcpy(Casella[768].Coordinate, "Vbianco1rosso");
    strcpy(Casella[769].Coordinate, "Wbianco1rosso");
    strcpy(Casella[770].Coordinate, "Xbianco1rosso");
    strcpy(Casella[771].Coordinate, "Ybianco1rosso");
    strcpy(Casella[772].Coordinate, "Zbianco1rosso");
    strcpy(Casella[773].Coordinate, "Arosso1rosso");
    strcpy(Casella[774].Coordinate, "Brosso1rosso");
    strcpy(Casella[775].Coordinate, "Crosso1rosso");
    strcpy(Casella[776].Coordinate, "Drosso1rosso");
    strcpy(Casella[777].Coordinate, "Erosso1rosso");
    strcpy(Casella[778].Coordinate, "Frosso1rosso");
    strcpy(Casella[779].Coordinate, "Grosso1rosso");
    strcpy(Casella[780].Coordinate, "Hrosso1rosso");
    strcpy(Casella[781].Coordinate, "Irosso1rosso");
    strcpy(Casella[782].Coordinate, "Jrosso1rosso");
    strcpy(Casella[783].Coordinate, "Krosso1rosso");
    strcpy(Casella[784].Coordinate, "Lrosso1rosso");
    strcpy(Casella[785].Coordinate, "Mrosso1rosso");
    strcpy(Casella[786].Coordinate, "Nrosso1rosso");
    strcpy(Casella[787].Coordinate, "Orosso1rosso");
    strcpy(Casella[788].Coordinate, "Prosso1rosso");
    strcpy(Casella[789].Coordinate, "Qrosso1rosso");
    strcpy(Casella[790].Coordinate, "Rrosso1rosso");
    strcpy(Casella[791].Coordinate, "Srosso1rosso");
    strcpy(Casella[792].Coordinate, "Trosso1rosso");
    strcpy(Casella[793].Coordinate, "Urosso1rosso");
    strcpy(Casella[794].Coordinate, "Vrosso1rosso");
    strcpy(Casella[795].Coordinate, "Wrosso1rosso");
    strcpy(Casella[796].Coordinate, "Xrosso1rosso");
    strcpy(Casella[797].Coordinate, "Yrosso1rosso");
    strcpy(Casella[798].Coordinate, "Zrosso1rosso");
    strcpy(Casella[799].Coordinate, "Aazzurro1rosso");
    strcpy(Casella[800].Coordinate, "Bazzurro1rosso");
    strcpy(Casella[801].Coordinate, "Cazzurro1rosso");
    strcpy(Casella[802].Coordinate, "Dazzurro1rosso");
    strcpy(Casella[803].Coordinate, "Eazzurro1rosso");
    strcpy(Casella[804].Coordinate, "Fazzurro1rosso");
    strcpy(Casella[805].Coordinate, "Gazzurro1rosso");
    strcpy(Casella[806].Coordinate, "Hazzurro1rosso");
    strcpy(Casella[807].Coordinate, "Iazzurro1rosso");
    strcpy(Casella[808].Coordinate, "Jazzurro1rosso");
    strcpy(Casella[809].Coordinate, "Kazzurro1rosso");
    strcpy(Casella[810].Coordinate, "Lazzurro1rosso");
    strcpy(Casella[811].Coordinate, "Mazzurro1rosso");
    strcpy(Casella[812].Coordinate, "Nazzurro1rosso");
    strcpy(Casella[813].Coordinate, "Oazzurro1rosso");
    strcpy(Casella[814].Coordinate, "Pazzurro1rosso");
    strcpy(Casella[815].Coordinate, "Qazzurro1rosso");
    strcpy(Casella[816].Coordinate, "Razzurro1rosso");
    strcpy(Casella[817].Coordinate, "Sazzurro1rosso");
    strcpy(Casella[818].Coordinate, "Tazzurro1rosso");
    strcpy(Casella[819].Coordinate, "Uazzurro1rosso");
    strcpy(Casella[820].Coordinate, "Vazzurro1rosso");
    strcpy(Casella[821].Coordinate, "Wazzurro1rosso");
    strcpy(Casella[822].Coordinate, "Xazzurro1rosso");
    strcpy(Casella[823].Coordinate, "Yazzurro1rosso");
    strcpy(Casella[824].Coordinate, "Zazzurro1rosso");
    strcpy(Casella[825].Coordinate, "Agiallo1rosso");
    strcpy(Casella[826].Coordinate, "Bgiallo1rosso");
    strcpy(Casella[827].Coordinate, "Cgiallo1rosso");
    strcpy(Casella[828].Coordinate, "Dgiallo1rosso");
    strcpy(Casella[829].Coordinate, "Egiallo1rosso");
    strcpy(Casella[830].Coordinate, "Abianco2rosso");
    strcpy(Casella[831].Coordinate, "Bbianco2rosso");
    strcpy(Casella[832].Coordinate, "Cbianco2rosso");
    strcpy(Casella[833].Coordinate, "Dbianco2rosso");
    strcpy(Casella[834].Coordinate, "Ebianco2rosso");
    strcpy(Casella[835].Coordinate, "Fbianco2rosso");
    strcpy(Casella[836].Coordinate, "Gbianco2rosso");
    strcpy(Casella[837].Coordinate, "Hbianco2rosso");
    strcpy(Casella[838].Coordinate, "Ibianco2rosso");
    strcpy(Casella[839].Coordinate, "Jbianco2rosso");
    strcpy(Casella[840].Coordinate, "Kbianco2rosso");
    strcpy(Casella[841].Coordinate, "Lbianco2rosso");
    strcpy(Casella[842].Coordinate, "Mbianco2rosso");
    strcpy(Casella[843].Coordinate, "Nbianco2rosso");
    strcpy(Casella[844].Coordinate, "Obianco2rosso");
    strcpy(Casella[845].Coordinate, "Pbianco2rosso");
    strcpy(Casella[846].Coordinate, "Qbianco2rosso");
    strcpy(Casella[847].Coordinate, "Rbianco2rosso");
    strcpy(Casella[848].Coordinate, "Sbianco2rosso");
    strcpy(Casella[849].Coordinate, "Tbianco2rosso");
    strcpy(Casella[850].Coordinate, "Ubianco2rosso");
    strcpy(Casella[851].Coordinate, "Vbianco2rosso");
    strcpy(Casella[852].Coordinate, "Wbianco2rosso");
    strcpy(Casella[853].Coordinate, "Xbianco2rosso");
    strcpy(Casella[854].Coordinate, "Ybianco2rosso");
    strcpy(Casella[855].Coordinate, "Zbianco2rosso");
    strcpy(Casella[856].Coordinate, "Arosso2rosso");
    strcpy(Casella[857].Coordinate, "Brosso2rosso");
    strcpy(Casella[858].Coordinate, "Crosso2rosso");
    strcpy(Casella[859].Coordinate, "Drosso2rosso");
    strcpy(Casella[860].Coordinate, "Erosso2rosso");
    strcpy(Casella[861].Coordinate, "Frosso2rosso");
    strcpy(Casella[862].Coordinate, "Grosso2rosso");
    strcpy(Casella[863].Coordinate, "Hrosso2rosso");
    strcpy(Casella[864].Coordinate, "Irosso2rosso");
    strcpy(Casella[865].Coordinate, "Jrosso2rosso");
    strcpy(Casella[866].Coordinate, "Krosso2rosso");
    strcpy(Casella[867].Coordinate, "Lrosso2rosso");
    strcpy(Casella[868].Coordinate, "Mrosso2rosso");
    strcpy(Casella[869].Coordinate, "Nrosso2rosso");
    strcpy(Casella[870].Coordinate, "Orosso2rosso");
    strcpy(Casella[871].Coordinate, "Prosso2rosso");
    strcpy(Casella[872].Coordinate, "Qrosso2rosso");
    strcpy(Casella[873].Coordinate, "Rrosso2rosso");
    strcpy(Casella[874].Coordinate, "Srosso2rosso");
    strcpy(Casella[875].Coordinate, "Trosso2rosso");
    strcpy(Casella[876].Coordinate, "Urosso2rosso");
    strcpy(Casella[877].Coordinate, "Vrosso2rosso");
    strcpy(Casella[878].Coordinate, "Wrosso2rosso");
    strcpy(Casella[879].Coordinate, "Xrosso2rosso");
    strcpy(Casella[880].Coordinate, "Yrosso2rosso");
    strcpy(Casella[881].Coordinate, "Zrosso2rosso");
    strcpy(Casella[882].Coordinate, "Aazzurro2rosso");
    strcpy(Casella[883].Coordinate, "Bazzurro2rosso");
    strcpy(Casella[884].Coordinate, "Cazzurro2rosso");
    strcpy(Casella[885].Coordinate, "Dazzurro2rosso");
    strcpy(Casella[886].Coordinate, "Eazzurro2rosso");
    strcpy(Casella[887].Coordinate, "Fazzurro2rosso");
    strcpy(Casella[888].Coordinate, "Gazzurro2rosso");
    strcpy(Casella[889].Coordinate, "Hazzurro2rosso");
    strcpy(Casella[890].Coordinate, "Iazzurro2rosso");
    strcpy(Casella[891].Coordinate, "Jazzurro2rosso");
    strcpy(Casella[892].Coordinate, "Kazzurro2rosso");
    strcpy(Casella[893].Coordinate, "Lazzurro2rosso");
    strcpy(Casella[894].Coordinate, "Mazzurro2rosso");
    strcpy(Casella[895].Coordinate, "Nazzurro2rosso");
    strcpy(Casella[896].Coordinate, "Oazzurro2rosso");
    strcpy(Casella[897].Coordinate, "Pazzurro2rosso");
    strcpy(Casella[898].Coordinate, "Qazzurro2rosso");
    strcpy(Casella[899].Coordinate, "Razzurro2rosso");
    strcpy(Casella[900].Coordinate, "Sazzurro2rosso");
    strcpy(Casella[901].Coordinate, "Tazzurro2rosso");
    strcpy(Casella[902].Coordinate, "Uazzurro2rosso");
    strcpy(Casella[903].Coordinate, "Vazzurro2rosso");
    strcpy(Casella[904].Coordinate, "Wazzurro2rosso");
    strcpy(Casella[905].Coordinate, "Xazzurro2rosso");
    strcpy(Casella[906].Coordinate, "Yazzurro2rosso");
    strcpy(Casella[907].Coordinate, "Zazzurro2rosso");
    strcpy(Casella[908].Coordinate, "Agiallo2rosso");
    strcpy(Casella[909].Coordinate, "Bgiallo2rosso");
    strcpy(Casella[910].Coordinate, "Cgiallo2rosso");
    strcpy(Casella[911].Coordinate, "Dgiallo2rosso");
    strcpy(Casella[912].Coordinate, "Egiallo2rosso");
    strcpy(Casella[913].Coordinate, "Abianco3rosso");
    strcpy(Casella[914].Coordinate, "Bbianco3rosso");
    strcpy(Casella[915].Coordinate, "Cbianco3rosso");
    strcpy(Casella[916].Coordinate, "Dbianco3rosso");
    strcpy(Casella[917].Coordinate, "Ebianco3rosso");
    strcpy(Casella[918].Coordinate, "Fbianco3rosso");
    strcpy(Casella[919].Coordinate, "Gbianco3rosso");
    strcpy(Casella[920].Coordinate, "Hbianco3rosso");
    strcpy(Casella[921].Coordinate, "Ibianco3rosso");
    strcpy(Casella[922].Coordinate, "Jbianco3rosso");
    strcpy(Casella[923].Coordinate, "Kbianco3rosso");
    strcpy(Casella[924].Coordinate, "Lbianco3rosso");
    strcpy(Casella[925].Coordinate, "Mbianco3rosso");
    strcpy(Casella[926].Coordinate, "Nbianco3rosso");
    strcpy(Casella[927].Coordinate, "Obianco3rosso");
    strcpy(Casella[928].Coordinate, "Pbianco3rosso");
    strcpy(Casella[929].Coordinate, "Qbianco3rosso");
    strcpy(Casella[930].Coordinate, "Rbianco3rosso");
    strcpy(Casella[931].Coordinate, "Sbianco3rosso");
    strcpy(Casella[932].Coordinate, "Tbianco3rosso");
    strcpy(Casella[933].Coordinate, "Ubianco3rosso");
    strcpy(Casella[934].Coordinate, "Vbianco3rosso");
    strcpy(Casella[935].Coordinate, "Wbianco3rosso");
    strcpy(Casella[936].Coordinate, "Xbianco3rosso");
    strcpy(Casella[937].Coordinate, "Ybianco3rosso");
    strcpy(Casella[938].Coordinate, "Zbianco3rosso");
    strcpy(Casella[939].Coordinate, "Arosso3rosso");
    strcpy(Casella[940].Coordinate, "Brosso3rosso");
    strcpy(Casella[941].Coordinate, "Crosso3rosso");
    strcpy(Casella[942].Coordinate, "Drosso3rosso");
    strcpy(Casella[943].Coordinate, "Erosso3rosso");
    strcpy(Casella[944].Coordinate, "Frosso3rosso");
    strcpy(Casella[945].Coordinate, "Grosso3rosso");
    strcpy(Casella[946].Coordinate, "Hrosso3rosso");
    strcpy(Casella[947].Coordinate, "Irosso3rosso");
    strcpy(Casella[948].Coordinate, "Jrosso3rosso");
    strcpy(Casella[949].Coordinate, "Krosso3rosso");
    strcpy(Casella[950].Coordinate, "Lrosso3rosso");
    strcpy(Casella[951].Coordinate, "Mrosso3rosso");
    strcpy(Casella[952].Coordinate, "Nrosso3rosso");
    strcpy(Casella[953].Coordinate, "Orosso3rosso");
    strcpy(Casella[954].Coordinate, "Prosso3rosso");
    strcpy(Casella[955].Coordinate, "Qrosso3rosso");
    strcpy(Casella[956].Coordinate, "Rrosso3rosso");
    strcpy(Casella[957].Coordinate, "Srosso3rosso");
    strcpy(Casella[958].Coordinate, "Trosso3rosso");
    strcpy(Casella[959].Coordinate, "Urosso3rosso");
    strcpy(Casella[960].Coordinate, "Vrosso3rosso");
    strcpy(Casella[961].Coordinate, "Wrosso3rosso");
    strcpy(Casella[962].Coordinate, "Xrosso3rosso");
    strcpy(Casella[963].Coordinate, "Yrosso3rosso");
    strcpy(Casella[964].Coordinate, "Zrosso3rosso");
    strcpy(Casella[965].Coordinate, "Aazzurro3rosso");
    strcpy(Casella[966].Coordinate, "Bazzurro3rosso");
    strcpy(Casella[967].Coordinate, "Cazzurro3rosso");
    strcpy(Casella[968].Coordinate, "Dazzurro3rosso");
    strcpy(Casella[969].Coordinate, "Eazzurro3rosso");
    strcpy(Casella[970].Coordinate, "Fazzurro3rosso");
    strcpy(Casella[971].Coordinate, "Gazzurro3rosso");
    strcpy(Casella[972].Coordinate, "Hazzurro3rosso");
    strcpy(Casella[973].Coordinate, "Iazzurro3rosso");
    strcpy(Casella[974].Coordinate, "Jazzurro3rosso");
    strcpy(Casella[975].Coordinate, "Kazzurro3rosso");
    strcpy(Casella[976].Coordinate, "Lazzurro3rosso");
    strcpy(Casella[977].Coordinate, "Mazzurro3rosso");
    strcpy(Casella[978].Coordinate, "Nazzurro3rosso");
    strcpy(Casella[979].Coordinate, "Oazzurro3rosso");
    strcpy(Casella[980].Coordinate, "Pazzurro3rosso");
    strcpy(Casella[981].Coordinate, "Qazzurro3rosso");
    strcpy(Casella[982].Coordinate, "Razzurro3rosso");
    strcpy(Casella[983].Coordinate, "Sazzurro3rosso");
    strcpy(Casella[984].Coordinate, "Tazzurro3rosso");
    strcpy(Casella[985].Coordinate, "Uazzurro3rosso");
    strcpy(Casella[986].Coordinate, "Vazzurro3rosso");
    strcpy(Casella[987].Coordinate, "Wazzurro3rosso");
    strcpy(Casella[988].Coordinate, "Xazzurro3rosso");
    strcpy(Casella[989].Coordinate, "Yazzurro3rosso");
    strcpy(Casella[990].Coordinate, "Zazzurro3rosso");
    strcpy(Casella[991].Coordinate, "Agiallo3rosso");
    strcpy(Casella[992].Coordinate, "Bgiallo3rosso");
    strcpy(Casella[993].Coordinate, "Cgiallo3rosso");
    strcpy(Casella[994].Coordinate, "Dgiallo3rosso");
    strcpy(Casella[995].Coordinate, "Egiallo3rosso");
    strcpy(Casella[996].Coordinate, "Abianco4rosso");
    strcpy(Casella[997].Coordinate, "Bbianco4rosso");
    strcpy(Casella[998].Coordinate, "Cbianco4rosso");
    strcpy(Casella[999].Coordinate, "Dbianco4rosso");
    strcpy(Casella[1000].Coordinate, "Ebianco4rosso");
    strcpy(Casella[1001].Coordinate, "Fbianco4rosso");
    strcpy(Casella[1002].Coordinate, "Gbianco4rosso");
    strcpy(Casella[1003].Coordinate, "Hbianco4rosso");
    strcpy(Casella[1004].Coordinate, "Ibianco4rosso");
    strcpy(Casella[1005].Coordinate, "Jbianco4rosso");
    strcpy(Casella[1006].Coordinate, "Kbianco4rosso");
    strcpy(Casella[1007].Coordinate, "Lbianco4rosso");
    strcpy(Casella[1008].Coordinate, "Mbianco4rosso");
    strcpy(Casella[1009].Coordinate, "Nbianco4rosso");
    strcpy(Casella[1010].Coordinate, "Obianco4rosso");
    strcpy(Casella[1011].Coordinate, "Pbianco4rosso");
    strcpy(Casella[1012].Coordinate, "Qbianco4rosso");
    strcpy(Casella[1013].Coordinate, "Rbianco4rosso");
    strcpy(Casella[1014].Coordinate, "Sbianco4rosso");
    strcpy(Casella[1015].Coordinate, "Tbianco4rosso");
    strcpy(Casella[1016].Coordinate, "Ubianco4rosso");
    strcpy(Casella[1017].Coordinate, "Vbianco4rosso");
    strcpy(Casella[1018].Coordinate, "Wbianco4rosso");
    strcpy(Casella[1019].Coordinate, "Xbianco4rosso");
    strcpy(Casella[1020].Coordinate, "Ybianco4rosso");
    strcpy(Casella[1021].Coordinate, "Zbianco4rosso");
    strcpy(Casella[1022].Coordinate, "Arosso4rosso");
    strcpy(Casella[1023].Coordinate, "Brosso4rosso");
    strcpy(Casella[1024].Coordinate, "Crosso4rosso");
    strcpy(Casella[1025].Coordinate, "Drosso4rosso");
    strcpy(Casella[1026].Coordinate, "Erosso4rosso");
    strcpy(Casella[1027].Coordinate, "Frosso4rosso");
    strcpy(Casella[1028].Coordinate, "Grosso4rosso");
    strcpy(Casella[1029].Coordinate, "Hrosso4rosso");
    strcpy(Casella[1030].Coordinate, "Irosso4rosso");
    strcpy(Casella[1031].Coordinate, "Jrosso4rosso");
    strcpy(Casella[1032].Coordinate, "Krosso4rosso");
    strcpy(Casella[1033].Coordinate, "Lrosso4rosso");
    strcpy(Casella[1034].Coordinate, "Mrosso4rosso");
    strcpy(Casella[1035].Coordinate, "Nrosso4rosso");
    strcpy(Casella[1036].Coordinate, "Orosso4rosso");
    strcpy(Casella[1037].Coordinate, "Prosso4rosso");
    strcpy(Casella[1038].Coordinate, "Qrosso4rosso");
    strcpy(Casella[1039].Coordinate, "Rrosso4rosso");
    strcpy(Casella[1040].Coordinate, "Srosso4rosso");
    strcpy(Casella[1041].Coordinate, "Trosso4rosso");
    strcpy(Casella[1042].Coordinate, "Urosso4rosso");
    strcpy(Casella[1043].Coordinate, "Vrosso4rosso");
    strcpy(Casella[1044].Coordinate, "Wrosso4rosso");
    strcpy(Casella[1045].Coordinate, "Xrosso4rosso");
    strcpy(Casella[1046].Coordinate, "Yrosso4rosso");
    strcpy(Casella[1047].Coordinate, "Zrosso4rosso");
    strcpy(Casella[1048].Coordinate, "Aazzurro4rosso");
    strcpy(Casella[1049].Coordinate, "Bazzurro4rosso");
    strcpy(Casella[1050].Coordinate, "Cazzurro4rosso");
    strcpy(Casella[1051].Coordinate, "Dazzurro4rosso");
    strcpy(Casella[1052].Coordinate, "Eazzurro4rosso");
    strcpy(Casella[1053].Coordinate, "Fazzurro4rosso");
    strcpy(Casella[1054].Coordinate, "Gazzurro4rosso");
    strcpy(Casella[1055].Coordinate, "Hazzurro4rosso");
    strcpy(Casella[1056].Coordinate, "Iazzurro4rosso");
    strcpy(Casella[1057].Coordinate, "Jazzurro4rosso");
    strcpy(Casella[1058].Coordinate, "Kazzurro4rosso");
    strcpy(Casella[1059].Coordinate, "Lazzurro4rosso");
    strcpy(Casella[1060].Coordinate, "Mazzurro4rosso");
    strcpy(Casella[1061].Coordinate, "Nazzurro4rosso");
    strcpy(Casella[1062].Coordinate, "Oazzurro4rosso");
    strcpy(Casella[1063].Coordinate, "Pazzurro4rosso");
    strcpy(Casella[1064].Coordinate, "Qazzurro4rosso");
    strcpy(Casella[1065].Coordinate, "Razzurro4rosso");
    strcpy(Casella[1066].Coordinate, "Sazzurro4rosso");
    strcpy(Casella[1067].Coordinate, "Tazzurro4rosso");
    strcpy(Casella[1068].Coordinate, "Uazzurro4rosso");
    strcpy(Casella[1069].Coordinate, "Vazzurro4rosso");
    strcpy(Casella[1070].Coordinate, "Wazzurro4rosso");
    strcpy(Casella[1071].Coordinate, "Xazzurro4rosso");
    strcpy(Casella[1072].Coordinate, "Yazzurro4rosso");
    strcpy(Casella[1073].Coordinate, "Zazzurro4rosso");
    strcpy(Casella[1074].Coordinate, "Agiallo4rosso");
    strcpy(Casella[1075].Coordinate, "Bgiallo4rosso");
    strcpy(Casella[1076].Coordinate, "Cgiallo4rosso");
    strcpy(Casella[1077].Coordinate, "Dgiallo4rosso");
    strcpy(Casella[1078].Coordinate, "Egiallo4rosso");
    strcpy(Casella[1079].Coordinate, "Abianco5rosso");
    strcpy(Casella[1080].Coordinate, "Bbianco5rosso");
    strcpy(Casella[1081].Coordinate, "Cbianco5rosso");
    strcpy(Casella[1082].Coordinate, "Dbianco5rosso");
    strcpy(Casella[1083].Coordinate, "Ebianco5rosso");
    strcpy(Casella[1084].Coordinate, "Fbianco5rosso");
    strcpy(Casella[1085].Coordinate, "Gbianco5rosso");
    strcpy(Casella[1086].Coordinate, "Hbianco5rosso");
    strcpy(Casella[1087].Coordinate, "Ibianco5rosso");
    strcpy(Casella[1088].Coordinate, "Jbianco5rosso");
    strcpy(Casella[1089].Coordinate, "Kbianco5rosso");
    strcpy(Casella[1090].Coordinate, "Lbianco5rosso");
    strcpy(Casella[1091].Coordinate, "Mbianco5rosso");
    strcpy(Casella[1092].Coordinate, "Nbianco5rosso");
    strcpy(Casella[1093].Coordinate, "Obianco5rosso");
    strcpy(Casella[1094].Coordinate, "Pbianco5rosso");
    strcpy(Casella[1095].Coordinate, "Qbianco5rosso");
    strcpy(Casella[1096].Coordinate, "Rbianco5rosso");
    strcpy(Casella[1097].Coordinate, "Sbianco5rosso");
    strcpy(Casella[1098].Coordinate, "Tbianco5rosso");
    strcpy(Casella[1099].Coordinate, "Ubianco5rosso");
    strcpy(Casella[1100].Coordinate, "Vbianco5rosso");
    strcpy(Casella[1101].Coordinate, "Wbianco5rosso");
    strcpy(Casella[1102].Coordinate, "Xbianco5rosso");
    strcpy(Casella[1103].Coordinate, "Ybianco5rosso");
    strcpy(Casella[1104].Coordinate, "Zbianco5rosso");
    strcpy(Casella[1105].Coordinate, "Arosso5rosso");
    strcpy(Casella[1106].Coordinate, "Brosso5rosso");
    strcpy(Casella[1107].Coordinate, "Crosso5rosso");
    strcpy(Casella[1108].Coordinate, "Drosso5rosso");
    strcpy(Casella[1109].Coordinate, "Erosso5rosso");
    strcpy(Casella[1110].Coordinate, "Frosso5rosso");
    strcpy(Casella[1111].Coordinate, "Grosso5rosso");
    strcpy(Casella[1112].Coordinate, "Hrosso5rosso");
    strcpy(Casella[1113].Coordinate, "Irosso5rosso");
    strcpy(Casella[1114].Coordinate, "Jrosso5rosso");
    strcpy(Casella[1115].Coordinate, "Krosso5rosso");
    strcpy(Casella[1116].Coordinate, "Lrosso5rosso");
    strcpy(Casella[1117].Coordinate, "Mrosso5rosso");
    strcpy(Casella[1118].Coordinate, "Nrosso5rosso");
    strcpy(Casella[1119].Coordinate, "Orosso5rosso");
    strcpy(Casella[1120].Coordinate, "Prosso5rosso");
    strcpy(Casella[1121].Coordinate, "Qrosso5rosso");
    strcpy(Casella[1122].Coordinate, "Rrosso5rosso");
    strcpy(Casella[1123].Coordinate, "Srosso5rosso");
    strcpy(Casella[1124].Coordinate, "Trosso5rosso");
    strcpy(Casella[1125].Coordinate, "Urosso5rosso");
    strcpy(Casella[1126].Coordinate, "Vrosso5rosso");
    strcpy(Casella[1127].Coordinate, "Wrosso5rosso");
    strcpy(Casella[1128].Coordinate, "Xrosso5rosso");
    strcpy(Casella[1129].Coordinate, "Yrosso5rosso");
    strcpy(Casella[1130].Coordinate, "Zrosso5rosso");
    strcpy(Casella[1131].Coordinate, "Aazzurro5rosso");
    strcpy(Casella[1132].Coordinate, "Bazzurro5rosso");
    strcpy(Casella[1133].Coordinate, "Cazzurro5rosso");
    strcpy(Casella[1134].Coordinate, "Dazzurro5rosso");
    strcpy(Casella[1135].Coordinate, "Eazzurro5rosso");
    strcpy(Casella[1136].Coordinate, "Fazzurro5rosso");
    strcpy(Casella[1137].Coordinate, "Gazzurro5rosso");
    strcpy(Casella[1138].Coordinate, "Hazzurro5rosso");
    strcpy(Casella[1139].Coordinate, "Iazzurro5rosso");
    strcpy(Casella[1140].Coordinate, "Jazzurro5rosso");
    strcpy(Casella[1141].Coordinate, "Kazzurro5rosso");
    strcpy(Casella[1142].Coordinate, "Lazzurro5rosso");
    strcpy(Casella[1143].Coordinate, "Mazzurro5rosso");
    strcpy(Casella[1144].Coordinate, "Nazzurro5rosso");
    strcpy(Casella[1145].Coordinate, "Oazzurro5rosso");
    strcpy(Casella[1146].Coordinate, "Pazzurro5rosso");
    strcpy(Casella[1147].Coordinate, "Qazzurro5rosso");
    strcpy(Casella[1148].Coordinate, "Razzurro5rosso");
    strcpy(Casella[1149].Coordinate, "Sazzurro5rosso");
    strcpy(Casella[1150].Coordinate, "Tazzurro5rosso");
    strcpy(Casella[1151].Coordinate, "Uazzurro5rosso");
    strcpy(Casella[1152].Coordinate, "Vazzurro5rosso");
    strcpy(Casella[1153].Coordinate, "Wazzurro5rosso");
    strcpy(Casella[1154].Coordinate, "Xazzurro5rosso");
    strcpy(Casella[1155].Coordinate, "Yazzurro5rosso");
    strcpy(Casella[1156].Coordinate, "Zazzurro5rosso");
    strcpy(Casella[1157].Coordinate, "Agiallo5rosso");
    strcpy(Casella[1158].Coordinate, "Bgiallo5rosso");
    strcpy(Casella[1159].Coordinate, "Cgiallo5rosso");
    strcpy(Casella[1160].Coordinate, "Dgiallo5rosso");
    strcpy(Casella[1161].Coordinate, "Egiallo5rosso");
    strcpy(Casella[1162].Coordinate, "Abianco6rosso");
    strcpy(Casella[1163].Coordinate, "Bbianco6rosso");
    strcpy(Casella[1164].Coordinate, "Cbianco6rosso");
    strcpy(Casella[1165].Coordinate, "Dbianco6rosso");
    strcpy(Casella[1166].Coordinate, "Ebianco6rosso");
    strcpy(Casella[1167].Coordinate, "Fbianco6rosso");
    strcpy(Casella[1168].Coordinate, "Gbianco6rosso");
    strcpy(Casella[1169].Coordinate, "Hbianco6rosso");
    strcpy(Casella[1170].Coordinate, "Ibianco6rosso");
    strcpy(Casella[1171].Coordinate, "Jbianco6rosso");
    strcpy(Casella[1172].Coordinate, "Kbianco6rosso");
    strcpy(Casella[1173].Coordinate, "Lbianco6rosso");
    strcpy(Casella[1174].Coordinate, "Mbianco6rosso");
    strcpy(Casella[1175].Coordinate, "Nbianco6rosso");
    strcpy(Casella[1176].Coordinate, "Obianco6rosso");
    strcpy(Casella[1177].Coordinate, "Pbianco6rosso");
    strcpy(Casella[1178].Coordinate, "Qbianco6rosso");
    strcpy(Casella[1179].Coordinate, "Rbianco6rosso");
    strcpy(Casella[1180].Coordinate, "Sbianco6rosso");
    strcpy(Casella[1181].Coordinate, "Tbianco6rosso");
    strcpy(Casella[1182].Coordinate, "Ubianco6rosso");
    strcpy(Casella[1183].Coordinate, "Vbianco6rosso");
    strcpy(Casella[1184].Coordinate, "Wbianco6rosso");
    strcpy(Casella[1185].Coordinate, "Xbianco6rosso");
    strcpy(Casella[1186].Coordinate, "Ybianco6rosso");
    strcpy(Casella[1187].Coordinate, "Zbianco6rosso");
    strcpy(Casella[1188].Coordinate, "Arosso6rosso");
    strcpy(Casella[1189].Coordinate, "Brosso6rosso");
    strcpy(Casella[1190].Coordinate, "Crosso6rosso");
    strcpy(Casella[1191].Coordinate, "Drosso6rosso");
    strcpy(Casella[1192].Coordinate, "Erosso6rosso");
    strcpy(Casella[1193].Coordinate, "Frosso6rosso");
    strcpy(Casella[1194].Coordinate, "Grosso6rosso");
    strcpy(Casella[1195].Coordinate, "Hrosso6rosso");
    strcpy(Casella[1196].Coordinate, "Irosso6rosso");
    strcpy(Casella[1197].Coordinate, "Jrosso6rosso");
    strcpy(Casella[1198].Coordinate, "Krosso6rosso");
    strcpy(Casella[1199].Coordinate, "Lrosso6rosso");
    strcpy(Casella[1200].Coordinate, "Mrosso6rosso");
    strcpy(Casella[1201].Coordinate, "Nrosso6rosso");
    strcpy(Casella[1202].Coordinate, "Orosso6rosso");
    strcpy(Casella[1203].Coordinate, "Prosso6rosso");
    strcpy(Casella[1204].Coordinate, "Qrosso6rosso");
    strcpy(Casella[1205].Coordinate, "Rrosso6rosso");
    strcpy(Casella[1206].Coordinate, "Srosso6rosso");
    strcpy(Casella[1207].Coordinate, "Trosso6rosso");
    strcpy(Casella[1208].Coordinate, "Urosso6rosso");
    strcpy(Casella[1209].Coordinate, "Vrosso6rosso");
    strcpy(Casella[1210].Coordinate, "Wrosso6rosso");
    strcpy(Casella[1211].Coordinate, "Xrosso6rosso");
    strcpy(Casella[1212].Coordinate, "Yrosso6rosso");
    strcpy(Casella[1213].Coordinate, "Zrosso6rosso");
    strcpy(Casella[1214].Coordinate, "Aazzurro6rosso");
    strcpy(Casella[1215].Coordinate, "Bazzurro6rosso");
    strcpy(Casella[1216].Coordinate, "Cazzurro6rosso");
    strcpy(Casella[1217].Coordinate, "Dazzurro6rosso");
    strcpy(Casella[1218].Coordinate, "Eazzurro6rosso");
    strcpy(Casella[1219].Coordinate, "Fazzurro6rosso");
    strcpy(Casella[1220].Coordinate, "Gazzurro6rosso");
    strcpy(Casella[1221].Coordinate, "Hazzurro6rosso");
    strcpy(Casella[1222].Coordinate, "Iazzurro6rosso");
    strcpy(Casella[1223].Coordinate, "Jazzurro6rosso");
    strcpy(Casella[1224].Coordinate, "Kazzurro6rosso");
    strcpy(Casella[1225].Coordinate, "Lazzurro6rosso");
    strcpy(Casella[1226].Coordinate, "Mazzurro6rosso");
    strcpy(Casella[1227].Coordinate, "Nazzurro6rosso");
    strcpy(Casella[1228].Coordinate, "Oazzurro6rosso");
    strcpy(Casella[1229].Coordinate, "Pazzurro6rosso");
    strcpy(Casella[1230].Coordinate, "Qazzurro6rosso");
    strcpy(Casella[1231].Coordinate, "Razzurro6rosso");
    strcpy(Casella[1232].Coordinate, "Sazzurro6rosso");
    strcpy(Casella[1233].Coordinate, "Tazzurro6rosso");
    strcpy(Casella[1234].Coordinate, "Uazzurro6rosso");
    strcpy(Casella[1235].Coordinate, "Vazzurro6rosso");
    strcpy(Casella[1236].Coordinate, "Wazzurro6rosso");
    strcpy(Casella[1237].Coordinate, "Xazzurro6rosso");
    strcpy(Casella[1238].Coordinate, "Yazzurro6rosso");
    strcpy(Casella[1239].Coordinate, "Zazzurro6rosso");
    strcpy(Casella[1240].Coordinate, "Agiallo6rosso");
    strcpy(Casella[1241].Coordinate, "Bgiallo6rosso");
    strcpy(Casella[1242].Coordinate, "Cgiallo6rosso");
    strcpy(Casella[1243].Coordinate, "Dgiallo6rosso");
    strcpy(Casella[1244].Coordinate, "Egiallo6rosso");
    strcpy(Casella[1245].Coordinate, "Abianco7rosso");
    strcpy(Casella[1246].Coordinate, "Bbianco7rosso");
    strcpy(Casella[1247].Coordinate, "Cbianco7rosso");
    strcpy(Casella[1248].Coordinate, "Dbianco7rosso");
    strcpy(Casella[1249].Coordinate, "Ebianco7rosso");
    strcpy(Casella[1250].Coordinate, "Fbianco7rosso");
    strcpy(Casella[1251].Coordinate, "Gbianco7rosso");
    strcpy(Casella[1252].Coordinate, "Hbianco7rosso");
    strcpy(Casella[1253].Coordinate, "Ibianco7rosso");
    strcpy(Casella[1254].Coordinate, "Jbianco7rosso");
    strcpy(Casella[1255].Coordinate, "Kbianco7rosso");
    strcpy(Casella[1256].Coordinate, "Lbianco7rosso");
    strcpy(Casella[1257].Coordinate, "Mbianco7rosso");
    strcpy(Casella[1258].Coordinate, "Nbianco7rosso");
    strcpy(Casella[1259].Coordinate, "Obianco7rosso");
    strcpy(Casella[1260].Coordinate, "Pbianco7rosso");
    strcpy(Casella[1261].Coordinate, "Qbianco7rosso");
    strcpy(Casella[1262].Coordinate, "Rbianco7rosso");
    strcpy(Casella[1263].Coordinate, "Sbianco7rosso");
    strcpy(Casella[1264].Coordinate, "Tbianco7rosso");
    strcpy(Casella[1265].Coordinate, "Ubianco7rosso");
    strcpy(Casella[1266].Coordinate, "Vbianco7rosso");
    strcpy(Casella[1267].Coordinate, "Wbianco7rosso");
    strcpy(Casella[1268].Coordinate, "Xbianco7rosso");
    strcpy(Casella[1269].Coordinate, "Ybianco7rosso");
    strcpy(Casella[1270].Coordinate, "Zbianco7rosso");
    strcpy(Casella[1271].Coordinate, "Arosso7rosso");
    strcpy(Casella[1272].Coordinate, "Brosso7rosso");
    strcpy(Casella[1273].Coordinate, "Crosso7rosso");
    strcpy(Casella[1274].Coordinate, "Drosso7rosso");
    strcpy(Casella[1275].Coordinate, "Erosso7rosso");
    strcpy(Casella[1276].Coordinate, "Frosso7rosso");
    strcpy(Casella[1277].Coordinate, "Grosso7rosso");
    strcpy(Casella[1278].Coordinate, "Hrosso7rosso");
    strcpy(Casella[1279].Coordinate, "Irosso7rosso");
    strcpy(Casella[1280].Coordinate, "Jrosso7rosso");
    strcpy(Casella[1281].Coordinate, "Krosso7rosso");
    strcpy(Casella[1282].Coordinate, "Lrosso7rosso");
    strcpy(Casella[1283].Coordinate, "Mrosso7rosso");
    strcpy(Casella[1284].Coordinate, "Nrosso7rosso");
    strcpy(Casella[1285].Coordinate, "Orosso7rosso");
    strcpy(Casella[1286].Coordinate, "Prosso7rosso");
    strcpy(Casella[1287].Coordinate, "Qrosso7rosso");
    strcpy(Casella[1288].Coordinate, "Rrosso7rosso");
    strcpy(Casella[1289].Coordinate, "Srosso7rosso");
    strcpy(Casella[1290].Coordinate, "Trosso7rosso");
    strcpy(Casella[1291].Coordinate, "Urosso7rosso");
    strcpy(Casella[1292].Coordinate, "Vrosso7rosso");
    strcpy(Casella[1293].Coordinate, "Wrosso7rosso");
    strcpy(Casella[1294].Coordinate, "Xrosso7rosso");
    strcpy(Casella[1295].Coordinate, "Yrosso7rosso");
    strcpy(Casella[1296].Coordinate, "Zrosso7rosso");
    strcpy(Casella[1297].Coordinate, "Aazzurro7rosso");
    strcpy(Casella[1298].Coordinate, "Bazzurro7rosso");
    strcpy(Casella[1299].Coordinate, "Cazzurro7rosso");
    strcpy(Casella[1300].Coordinate, "Dazzurro7rosso");
    strcpy(Casella[1301].Coordinate, "Eazzurro7rosso");
    strcpy(Casella[1302].Coordinate, "Fazzurro7rosso");
    strcpy(Casella[1303].Coordinate, "Gazzurro7rosso");
    strcpy(Casella[1304].Coordinate, "Hazzurro7rosso");
    strcpy(Casella[1305].Coordinate, "Iazzurro7rosso");
    strcpy(Casella[1306].Coordinate, "Jazzurro7rosso");
    strcpy(Casella[1307].Coordinate, "Kazzurro7rosso");
    strcpy(Casella[1308].Coordinate, "Lazzurro7rosso");
    strcpy(Casella[1309].Coordinate, "Mazzurro7rosso");
    strcpy(Casella[1310].Coordinate, "Nazzurro7rosso");
    strcpy(Casella[1311].Coordinate, "Oazzurro7rosso");
    strcpy(Casella[1312].Coordinate, "Pazzurro7rosso");
    strcpy(Casella[1313].Coordinate, "Qazzurro7rosso");
    strcpy(Casella[1314].Coordinate, "Razzurro7rosso");
    strcpy(Casella[1315].Coordinate, "Sazzurro7rosso");
    strcpy(Casella[1316].Coordinate, "Tazzurro7rosso");
    strcpy(Casella[1317].Coordinate, "Uazzurro7rosso");
    strcpy(Casella[1318].Coordinate, "Vazzurro7rosso");
    strcpy(Casella[1319].Coordinate, "Wazzurro7rosso");
    strcpy(Casella[1320].Coordinate, "Xazzurro7rosso");
    strcpy(Casella[1321].Coordinate, "Yazzurro7rosso");
    strcpy(Casella[1322].Coordinate, "Zazzurro7rosso");
    strcpy(Casella[1323].Coordinate, "Agiallo7rosso");
    strcpy(Casella[1324].Coordinate, "Bgiallo7rosso");
    strcpy(Casella[1325].Coordinate, "Cgiallo7rosso");
    strcpy(Casella[1326].Coordinate, "Dgiallo7rosso");
    strcpy(Casella[1327].Coordinate, "Egiallo7rosso");
    strcpy(Casella[1328].Coordinate, "Abianco8rosso");
    strcpy(Casella[1329].Coordinate, "Bbianco8rosso");
    strcpy(Casella[1330].Coordinate, "Cbianco8rosso");
    strcpy(Casella[1331].Coordinate, "Dbianco8rosso");
    strcpy(Casella[1332].Coordinate, "Ebianco8rosso");
    strcpy(Casella[1333].Coordinate, "Fbianco8rosso");
    strcpy(Casella[1334].Coordinate, "Gbianco8rosso");
    strcpy(Casella[1335].Coordinate, "Hbianco8rosso");
    strcpy(Casella[1336].Coordinate, "Ibianco8rosso");
    strcpy(Casella[1337].Coordinate, "Jbianco8rosso");
    strcpy(Casella[1338].Coordinate, "Kbianco8rosso");
    strcpy(Casella[1339].Coordinate, "Lbianco8rosso");
    strcpy(Casella[1340].Coordinate, "Mbianco8rosso");
    strcpy(Casella[1341].Coordinate, "Nbianco8rosso");
    strcpy(Casella[1342].Coordinate, "Obianco8rosso");
    strcpy(Casella[1343].Coordinate, "Pbianco8rosso");
    strcpy(Casella[1344].Coordinate, "Qbianco8rosso");
    strcpy(Casella[1345].Coordinate, "Rbianco8rosso");
    strcpy(Casella[1346].Coordinate, "Sbianco8rosso");
    strcpy(Casella[1347].Coordinate, "Tbianco8rosso");
    strcpy(Casella[1348].Coordinate, "Ubianco8rosso");
    strcpy(Casella[1349].Coordinate, "Vbianco8rosso");
    strcpy(Casella[1350].Coordinate, "Wbianco8rosso");
    strcpy(Casella[1351].Coordinate, "Xbianco8rosso");
    strcpy(Casella[1352].Coordinate, "Ybianco8rosso");
    strcpy(Casella[1353].Coordinate, "Zbianco8rosso");
    strcpy(Casella[1354].Coordinate, "Arosso8rosso");
    strcpy(Casella[1355].Coordinate, "Brosso8rosso");
    strcpy(Casella[1356].Coordinate, "Crosso8rosso");
    strcpy(Casella[1357].Coordinate, "Drosso8rosso");
    strcpy(Casella[1358].Coordinate, "Erosso8rosso");
    strcpy(Casella[1359].Coordinate, "Frosso8rosso");
    strcpy(Casella[1360].Coordinate, "Grosso8rosso");
    strcpy(Casella[1361].Coordinate, "Hrosso8rosso");
    strcpy(Casella[1362].Coordinate, "Irosso8rosso");
    strcpy(Casella[1363].Coordinate, "Jrosso8rosso");
    strcpy(Casella[1364].Coordinate, "Krosso8rosso");
    strcpy(Casella[1365].Coordinate, "Lrosso8rosso");
    strcpy(Casella[1366].Coordinate, "Mrosso8rosso");
    strcpy(Casella[1367].Coordinate, "Nrosso8rosso");
    strcpy(Casella[1368].Coordinate, "Orosso8rosso");
    strcpy(Casella[1369].Coordinate, "Prosso8rosso");
    strcpy(Casella[1370].Coordinate, "Qrosso8rosso");
    strcpy(Casella[1371].Coordinate, "Rrosso8rosso");
    strcpy(Casella[1372].Coordinate, "Srosso8rosso");
    strcpy(Casella[1373].Coordinate, "Trosso8rosso");
    strcpy(Casella[1374].Coordinate, "Urosso8rosso");
    strcpy(Casella[1375].Coordinate, "Vrosso8rosso");
    strcpy(Casella[1376].Coordinate, "Wrosso8rosso");
    strcpy(Casella[1377].Coordinate, "Xrosso8rosso");
    strcpy(Casella[1378].Coordinate, "Yrosso8rosso");
    strcpy(Casella[1379].Coordinate, "Zrosso8rosso");
    strcpy(Casella[1380].Coordinate, "Aazzurro8rosso");
    strcpy(Casella[1381].Coordinate, "Bazzurro8rosso");
    strcpy(Casella[1382].Coordinate, "Cazzurro8rosso");
    strcpy(Casella[1383].Coordinate, "Dazzurro8rosso");
    strcpy(Casella[1384].Coordinate, "Eazzurro8rosso");
    strcpy(Casella[1385].Coordinate, "Fazzurro8rosso");
    strcpy(Casella[1386].Coordinate, "Gazzurro8rosso");
    strcpy(Casella[1387].Coordinate, "Hazzurro8rosso");
    strcpy(Casella[1388].Coordinate, "Iazzurro8rosso");
    strcpy(Casella[1389].Coordinate, "Jazzurro8rosso");
    strcpy(Casella[1390].Coordinate, "Kazzurro8rosso");
    strcpy(Casella[1391].Coordinate, "Lazzurro8rosso");
    strcpy(Casella[1392].Coordinate, "Mazzurro8rosso");
    strcpy(Casella[1393].Coordinate, "Nazzurro8rosso");
    strcpy(Casella[1394].Coordinate, "Oazzurro8rosso");
    strcpy(Casella[1395].Coordinate, "Pazzurro8rosso");
    strcpy(Casella[1396].Coordinate, "Qazzurro8rosso");
    strcpy(Casella[1397].Coordinate, "Razzurro8rosso");
    strcpy(Casella[1398].Coordinate, "Sazzurro8rosso");
    strcpy(Casella[1399].Coordinate, "Tazzurro8rosso");
    strcpy(Casella[1400].Coordinate, "Uazzurro8rosso");
    strcpy(Casella[1401].Coordinate, "Vazzurro8rosso");
    strcpy(Casella[1402].Coordinate, "Wazzurro8rosso");
    strcpy(Casella[1403].Coordinate, "Xazzurro8rosso");
    strcpy(Casella[1404].Coordinate, "Yazzurro8rosso");
    strcpy(Casella[1405].Coordinate, "Zazzurro8rosso");
    strcpy(Casella[1406].Coordinate, "Agiallo8rosso");
    strcpy(Casella[1407].Coordinate, "Bgiallo8rosso");
    strcpy(Casella[1408].Coordinate, "Cgiallo8rosso");
    strcpy(Casella[1409].Coordinate, "Dgiallo8rosso");
    strcpy(Casella[1410].Coordinate, "Egiallo8rosso");
    strcpy(Casella[1411].Coordinate, "Abianco9rosso");
    strcpy(Casella[1412].Coordinate, "Bbianco9rosso");
    strcpy(Casella[1413].Coordinate, "Cbianco9rosso");
    strcpy(Casella[1414].Coordinate, "Dbianco9rosso");
    strcpy(Casella[1415].Coordinate, "Ebianco9rosso");
    strcpy(Casella[1416].Coordinate, "Fbianco9rosso");
    strcpy(Casella[1417].Coordinate, "Gbianco9rosso");
    strcpy(Casella[1418].Coordinate, "Hbianco9rosso");
    strcpy(Casella[1419].Coordinate, "Ibianco9rosso");
    strcpy(Casella[1420].Coordinate, "Jbianco9rosso");
    strcpy(Casella[1421].Coordinate, "Kbianco9rosso");
    strcpy(Casella[1422].Coordinate, "Lbianco9rosso");
    strcpy(Casella[1423].Coordinate, "Mbianco9rosso");
    strcpy(Casella[1424].Coordinate, "Nbianco9rosso");
    strcpy(Casella[1425].Coordinate, "Obianco9rosso");
    strcpy(Casella[1426].Coordinate, "Pbianco9rosso");
    strcpy(Casella[1427].Coordinate, "Qbianco9rosso");
    strcpy(Casella[1428].Coordinate, "Rbianco9rosso");
    strcpy(Casella[1429].Coordinate, "Sbianco9rosso");
    strcpy(Casella[1430].Coordinate, "Tbianco9rosso");
    strcpy(Casella[1431].Coordinate, "Ubianco9rosso");
    strcpy(Casella[1432].Coordinate, "Vbianco9rosso");
    strcpy(Casella[1433].Coordinate, "Wbianco9rosso");
    strcpy(Casella[1434].Coordinate, "Xbianco9rosso");
    strcpy(Casella[1435].Coordinate, "Ybianco9rosso");
    strcpy(Casella[1436].Coordinate, "Zbianco9rosso");
    strcpy(Casella[1437].Coordinate, "Arosso9rosso");
    strcpy(Casella[1438].Coordinate, "Brosso9rosso");
    strcpy(Casella[1439].Coordinate, "Crosso9rosso");
    strcpy(Casella[1440].Coordinate, "Drosso9rosso");
    strcpy(Casella[1441].Coordinate, "Erosso9rosso");
    strcpy(Casella[1442].Coordinate, "Frosso9rosso");
    strcpy(Casella[1443].Coordinate, "Grosso9rosso");
    strcpy(Casella[1444].Coordinate, "Hrosso9rosso");
    strcpy(Casella[1445].Coordinate, "Irosso9rosso");
    strcpy(Casella[1446].Coordinate, "Jrosso9rosso");
    strcpy(Casella[1447].Coordinate, "Krosso9rosso");
    strcpy(Casella[1448].Coordinate, "Lrosso9rosso");
    strcpy(Casella[1449].Coordinate, "Mrosso9rosso");
    strcpy(Casella[1450].Coordinate, "Nrosso9rosso");
    strcpy(Casella[1451].Coordinate, "Orosso9rosso");
    strcpy(Casella[1452].Coordinate, "Prosso9rosso");
    strcpy(Casella[1453].Coordinate, "Qrosso9rosso");
    strcpy(Casella[1454].Coordinate, "Rrosso9rosso");
    strcpy(Casella[1455].Coordinate, "Srosso9rosso");
    strcpy(Casella[1456].Coordinate, "Trosso9rosso");
    strcpy(Casella[1457].Coordinate, "Urosso9rosso");
    strcpy(Casella[1458].Coordinate, "Vrosso9rosso");
    strcpy(Casella[1459].Coordinate, "Wrosso9rosso");
    strcpy(Casella[1460].Coordinate, "Xrosso9rosso");
    strcpy(Casella[1461].Coordinate, "Yrosso9rosso");
    strcpy(Casella[1462].Coordinate, "Zrosso9rosso");
    strcpy(Casella[1463].Coordinate, "Aazzurro9rosso");
    strcpy(Casella[1464].Coordinate, "Bazzurro9rosso");
    strcpy(Casella[1465].Coordinate, "Cazzurro9rosso");
    strcpy(Casella[1466].Coordinate, "Dazzurro9rosso");
    strcpy(Casella[1467].Coordinate, "Eazzurro9rosso");
    strcpy(Casella[1468].Coordinate, "Fazzurro9rosso");
    strcpy(Casella[1469].Coordinate, "Gazzurro9rosso");
    strcpy(Casella[1470].Coordinate, "Hazzurro9rosso");
    strcpy(Casella[1471].Coordinate, "Iazzurro9rosso");
    strcpy(Casella[1472].Coordinate, "Jazzurro9rosso");
    strcpy(Casella[1473].Coordinate, "Kazzurro9rosso");
    strcpy(Casella[1474].Coordinate, "Lazzurro9rosso");
    strcpy(Casella[1475].Coordinate, "Mazzurro9rosso");
    strcpy(Casella[1476].Coordinate, "Nazzurro9rosso");
    strcpy(Casella[1477].Coordinate, "Oazzurro9rosso");
    strcpy(Casella[1478].Coordinate, "Pazzurro9rosso");
    strcpy(Casella[1479].Coordinate, "Qazzurro9rosso");
    strcpy(Casella[1480].Coordinate, "Razzurro9rosso");
    strcpy(Casella[1481].Coordinate, "Sazzurro9rosso");
    strcpy(Casella[1482].Coordinate, "Tazzurro9rosso");
    strcpy(Casella[1483].Coordinate, "Uazzurro9rosso");
    strcpy(Casella[1484].Coordinate, "Vazzurro9rosso");
    strcpy(Casella[1485].Coordinate, "Wazzurro9rosso");
    strcpy(Casella[1486].Coordinate, "Xazzurro9rosso");
    strcpy(Casella[1487].Coordinate, "Yazzurro9rosso");
    strcpy(Casella[1488].Coordinate, "Zazzurro9rosso");
    strcpy(Casella[1489].Coordinate, "Agiallo9rosso");
    strcpy(Casella[1490].Coordinate, "Bgiallo9rosso");
    strcpy(Casella[1491].Coordinate, "Cgiallo9rosso");
    strcpy(Casella[1492].Coordinate, "Dgiallo9rosso");
    strcpy(Casella[1493].Coordinate, "Egiallo9rosso");
    strcpy(Casella[1494].Coordinate, "Abianco1azzurro");
    strcpy(Casella[1495].Coordinate, "Bbianco1azzurro");
    strcpy(Casella[1496].Coordinate, "Cbianco1azzurro");
    strcpy(Casella[1497].Coordinate, "Dbianco1azzurro");
    strcpy(Casella[1498].Coordinate, "Ebianco1azzurro");
    strcpy(Casella[1499].Coordinate, "Fbianco1azzurro");
    strcpy(Casella[1500].Coordinate, "Gbianco1azzurro");
    strcpy(Casella[1501].Coordinate, "Hbianco1azzurro");
    strcpy(Casella[1502].Coordinate, "Ibianco1azzurro");
    strcpy(Casella[1503].Coordinate, "Jbianco1azzurro");
    strcpy(Casella[1504].Coordinate, "Kbianco1azzurro");
    strcpy(Casella[1505].Coordinate, "Lbianco1azzurro");
    strcpy(Casella[1506].Coordinate, "Mbianco1azzurro");
    strcpy(Casella[1507].Coordinate, "Nbianco1azzurro");
    strcpy(Casella[1508].Coordinate, "Obianco1azzurro");
    strcpy(Casella[1509].Coordinate, "Pbianco1azzurro");
    strcpy(Casella[1510].Coordinate, "Qbianco1azzurro");
    strcpy(Casella[1511].Coordinate, "Rbianco1azzurro");
    strcpy(Casella[1512].Coordinate, "Sbianco1azzurro");
    strcpy(Casella[1513].Coordinate, "Tbianco1azzurro");
    strcpy(Casella[1514].Coordinate, "Ubianco1azzurro");
    strcpy(Casella[1515].Coordinate, "Vbianco1azzurro");
    strcpy(Casella[1516].Coordinate, "Wbianco1azzurro");
    strcpy(Casella[1517].Coordinate, "Xbianco1azzurro");
    strcpy(Casella[1518].Coordinate, "Ybianco1azzurro");
    strcpy(Casella[1519].Coordinate, "Zbianco1azzurro");
    strcpy(Casella[1520].Coordinate, "Arosso1azzurro");
    strcpy(Casella[1521].Coordinate, "Brosso1azzurro");
    strcpy(Casella[1522].Coordinate, "Crosso1azzurro");
    strcpy(Casella[1523].Coordinate, "Drosso1azzurro");
    strcpy(Casella[1524].Coordinate, "Erosso1azzurro");
    strcpy(Casella[1525].Coordinate, "Frosso1azzurro");
    strcpy(Casella[1526].Coordinate, "Grosso1azzurro");
    strcpy(Casella[1527].Coordinate, "Hrosso1azzurro");
    strcpy(Casella[1528].Coordinate, "Irosso1azzurro");
    strcpy(Casella[1529].Coordinate, "Jrosso1azzurro");
    strcpy(Casella[1530].Coordinate, "Krosso1azzurro");
    strcpy(Casella[1531].Coordinate, "Lrosso1azzurro");
    strcpy(Casella[1532].Coordinate, "Mrosso1azzurro");
    strcpy(Casella[1533].Coordinate, "Nrosso1azzurro");
    strcpy(Casella[1534].Coordinate, "Orosso1azzurro");
    strcpy(Casella[1535].Coordinate, "Prosso1azzurro");
    strcpy(Casella[1536].Coordinate, "Qrosso1azzurro");
    strcpy(Casella[1537].Coordinate, "Rrosso1azzurro");
    strcpy(Casella[1538].Coordinate, "Srosso1azzurro");
    strcpy(Casella[1539].Coordinate, "Trosso1azzurro");
    strcpy(Casella[1540].Coordinate, "Urosso1azzurro");
    strcpy(Casella[1541].Coordinate, "Vrosso1azzurro");
    strcpy(Casella[1542].Coordinate, "Wrosso1azzurro");
    strcpy(Casella[1543].Coordinate, "Xrosso1azzurro");
    strcpy(Casella[1544].Coordinate, "Yrosso1azzurro");
    strcpy(Casella[1545].Coordinate, "Zrosso1azzurro");
    strcpy(Casella[1546].Coordinate, "Aazzurro1azzurro");
    strcpy(Casella[1547].Coordinate, "Bazzurro1azzurro");
    strcpy(Casella[1548].Coordinate, "Cazzurro1azzurro");
    strcpy(Casella[1549].Coordinate, "Dazzurro1azzurro");
    strcpy(Casella[1550].Coordinate, "Eazzurro1azzurro");
    strcpy(Casella[1551].Coordinate, "Fazzurro1azzurro");
    strcpy(Casella[1552].Coordinate, "Gazzurro1azzurro");
    strcpy(Casella[1553].Coordinate, "Hazzurro1azzurro");
    strcpy(Casella[1554].Coordinate, "Iazzurro1azzurro");
    strcpy(Casella[1555].Coordinate, "Jazzurro1azzurro");
    strcpy(Casella[1556].Coordinate, "Kazzurro1azzurro");
    strcpy(Casella[1557].Coordinate, "Lazzurro1azzurro");
    strcpy(Casella[1558].Coordinate, "Mazzurro1azzurro");
    strcpy(Casella[1559].Coordinate, "Nazzurro1azzurro");
    strcpy(Casella[1560].Coordinate, "Oazzurro1azzurro");
    strcpy(Casella[1561].Coordinate, "Pazzurro1azzurro");
    strcpy(Casella[1562].Coordinate, "Qazzurro1azzurro");
    strcpy(Casella[1563].Coordinate, "Razzurro1azzurro");
    strcpy(Casella[1564].Coordinate, "Sazzurro1azzurro");
    strcpy(Casella[1565].Coordinate, "Tazzurro1azzurro");
    strcpy(Casella[1566].Coordinate, "Uazzurro1azzurro");
    strcpy(Casella[1567].Coordinate, "Vazzurro1azzurro");
    strcpy(Casella[1568].Coordinate, "Wazzurro1azzurro");
    strcpy(Casella[1569].Coordinate, "Xazzurro1azzurro");
    strcpy(Casella[1570].Coordinate, "Yazzurro1azzurro");
    strcpy(Casella[1571].Coordinate, "Zazzurro1azzurro");
    strcpy(Casella[1572].Coordinate, "Agiallo1azzurro");
    strcpy(Casella[1573].Coordinate, "Bgiallo1azzurro");
    strcpy(Casella[1574].Coordinate, "Cgiallo1azzurro");
    strcpy(Casella[1575].Coordinate, "Dgiallo1azzurro");
    strcpy(Casella[1576].Coordinate, "Egiallo1azzurro");
    strcpy(Casella[1577].Coordinate, "Abianco2azzurro");
    strcpy(Casella[1578].Coordinate, "Bbianco2azzurro");
    strcpy(Casella[1579].Coordinate, "Cbianco2azzurro");
    strcpy(Casella[1580].Coordinate, "Dbianco2azzurro");
    strcpy(Casella[1581].Coordinate, "Ebianco2azzurro");
    strcpy(Casella[1582].Coordinate, "Fbianco2azzurro");
    strcpy(Casella[1583].Coordinate, "Gbianco2azzurro");
    strcpy(Casella[1584].Coordinate, "Hbianco2azzurro");
    strcpy(Casella[1585].Coordinate, "Ibianco2azzurro");
    strcpy(Casella[1586].Coordinate, "Jbianco2azzurro");
    strcpy(Casella[1587].Coordinate, "Kbianco2azzurro");
    strcpy(Casella[1588].Coordinate, "Lbianco2azzurro");
    strcpy(Casella[1589].Coordinate, "Mbianco2azzurro");
    strcpy(Casella[1590].Coordinate, "Nbianco2azzurro");
    strcpy(Casella[1591].Coordinate, "Obianco2azzurro");
    strcpy(Casella[1592].Coordinate, "Pbianco2azzurro");
    strcpy(Casella[1593].Coordinate, "Qbianco2azzurro");
    strcpy(Casella[1594].Coordinate, "Rbianco2azzurro");
    strcpy(Casella[1595].Coordinate, "Sbianco2azzurro");
    strcpy(Casella[1596].Coordinate, "Tbianco2azzurro");
    strcpy(Casella[1597].Coordinate, "Ubianco2azzurro");
    strcpy(Casella[1598].Coordinate, "Vbianco2azzurro");
    strcpy(Casella[1599].Coordinate, "Wbianco2azzurro");
    strcpy(Casella[1600].Coordinate, "Xbianco2azzurro");
    strcpy(Casella[1601].Coordinate, "Ybianco2azzurro");
    strcpy(Casella[1602].Coordinate, "Zbianco2azzurro");
    strcpy(Casella[1603].Coordinate, "Arosso2azzurro");
    strcpy(Casella[1604].Coordinate, "Brosso2azzurro");
    strcpy(Casella[1605].Coordinate, "Crosso2azzurro");
    strcpy(Casella[1606].Coordinate, "Drosso2azzurro");
    strcpy(Casella[1607].Coordinate, "Erosso2azzurro");
    strcpy(Casella[1608].Coordinate, "Frosso2azzurro");
    strcpy(Casella[1609].Coordinate, "Grosso2azzurro");
    strcpy(Casella[1610].Coordinate, "Hrosso2azzurro");
    strcpy(Casella[1611].Coordinate, "Irosso2azzurro");
    strcpy(Casella[1612].Coordinate, "Jrosso2azzurro");
    strcpy(Casella[1613].Coordinate, "Krosso2azzurro");
    strcpy(Casella[1614].Coordinate, "Lrosso2azzurro");
    strcpy(Casella[1615].Coordinate, "Mrosso2azzurro");
    strcpy(Casella[1616].Coordinate, "Nrosso2azzurro");
    strcpy(Casella[1617].Coordinate, "Orosso2azzurro");
    strcpy(Casella[1618].Coordinate, "Prosso2azzurro");
    strcpy(Casella[1619].Coordinate, "Qrosso2azzurro");
    strcpy(Casella[1620].Coordinate, "Rrosso2azzurro");
    strcpy(Casella[1621].Coordinate, "Srosso2azzurro");
    strcpy(Casella[1622].Coordinate, "Trosso2azzurro");
    strcpy(Casella[1623].Coordinate, "Urosso2azzurro");
    strcpy(Casella[1624].Coordinate, "Vrosso2azzurro");
    strcpy(Casella[1625].Coordinate, "Wrosso2azzurro");
    strcpy(Casella[1626].Coordinate, "Xrosso2azzurro");
    strcpy(Casella[1627].Coordinate, "Yrosso2azzurro");
    strcpy(Casella[1628].Coordinate, "Zrosso2azzurro");
    strcpy(Casella[1629].Coordinate, "Aazzurro2azzurro");
    strcpy(Casella[1630].Coordinate, "Bazzurro2azzurro");
    strcpy(Casella[1631].Coordinate, "Cazzurro2azzurro");
    strcpy(Casella[1632].Coordinate, "Dazzurro2azzurro");
    strcpy(Casella[1633].Coordinate, "Eazzurro2azzurro");
    strcpy(Casella[1634].Coordinate, "Fazzurro2azzurro");
    strcpy(Casella[1635].Coordinate, "Gazzurro2azzurro");
    strcpy(Casella[1636].Coordinate, "Hazzurro2azzurro");
    strcpy(Casella[1637].Coordinate, "Iazzurro2azzurro");
    strcpy(Casella[1638].Coordinate, "Jazzurro2azzurro");
    strcpy(Casella[1639].Coordinate, "Kazzurro2azzurro");
    strcpy(Casella[1640].Coordinate, "Lazzurro2azzurro");
    strcpy(Casella[1641].Coordinate, "Mazzurro2azzurro");
    strcpy(Casella[1642].Coordinate, "Nazzurro2azzurro");
    strcpy(Casella[1643].Coordinate, "Oazzurro2azzurro");
    strcpy(Casella[1644].Coordinate, "Pazzurro2azzurro");
    strcpy(Casella[1645].Coordinate, "Qazzurro2azzurro");
    strcpy(Casella[1646].Coordinate, "Razzurro2azzurro");
    strcpy(Casella[1647].Coordinate, "Sazzurro2azzurro");
    strcpy(Casella[1648].Coordinate, "Tazzurro2azzurro");
    strcpy(Casella[1649].Coordinate, "Uazzurro2azzurro");
    strcpy(Casella[1650].Coordinate, "Vazzurro2azzurro");
    strcpy(Casella[1651].Coordinate, "Wazzurro2azzurro");
    strcpy(Casella[1652].Coordinate, "Xazzurro2azzurro");
    strcpy(Casella[1653].Coordinate, "Yazzurro2azzurro");
    strcpy(Casella[1654].Coordinate, "Zazzurro2azzurro");
    strcpy(Casella[1655].Coordinate, "Agiallo2azzurro");
    strcpy(Casella[1656].Coordinate, "Bgiallo2azzurro");
    strcpy(Casella[1657].Coordinate, "Cgiallo2azzurro");
    strcpy(Casella[1658].Coordinate, "Dgiallo2azzurro");
    strcpy(Casella[1659].Coordinate, "Egiallo2azzurro");
    strcpy(Casella[1660].Coordinate, "Abianco3azzurro");
    strcpy(Casella[1661].Coordinate, "Bbianco3azzurro");
    strcpy(Casella[1662].Coordinate, "Cbianco3azzurro");
    strcpy(Casella[1663].Coordinate, "Dbianco3azzurro");
    strcpy(Casella[1664].Coordinate, "Ebianco3azzurro");
    strcpy(Casella[1665].Coordinate, "Fbianco3azzurro");
    strcpy(Casella[1666].Coordinate, "Gbianco3azzurro");
    strcpy(Casella[1667].Coordinate, "Hbianco3azzurro");
    strcpy(Casella[1668].Coordinate, "Ibianco3azzurro");
    strcpy(Casella[1669].Coordinate, "Jbianco3azzurro");
    strcpy(Casella[1670].Coordinate, "Kbianco3azzurro");
    strcpy(Casella[1671].Coordinate, "Lbianco3azzurro");
    strcpy(Casella[1672].Coordinate, "Mbianco3azzurro");
    strcpy(Casella[1673].Coordinate, "Nbianco3azzurro");
    strcpy(Casella[1674].Coordinate, "Obianco3azzurro");
    strcpy(Casella[1675].Coordinate, "Pbianco3azzurro");
    strcpy(Casella[1676].Coordinate, "Qbianco3azzurro");
    strcpy(Casella[1677].Coordinate, "Rbianco3azzurro");
    strcpy(Casella[1678].Coordinate, "Sbianco3azzurro");
    strcpy(Casella[1679].Coordinate, "Tbianco3azzurro");
    strcpy(Casella[1680].Coordinate, "Ubianco3azzurro");
    strcpy(Casella[1681].Coordinate, "Vbianco3azzurro");
    strcpy(Casella[1682].Coordinate, "Wbianco3azzurro");
    strcpy(Casella[1683].Coordinate, "Xbianco3azzurro");
    strcpy(Casella[1684].Coordinate, "Ybianco3azzurro");
    strcpy(Casella[1685].Coordinate, "Zbianco3azzurro");
    strcpy(Casella[1686].Coordinate, "Arosso3azzurro");
    strcpy(Casella[1687].Coordinate, "Brosso3azzurro");
    strcpy(Casella[1688].Coordinate, "Crosso3azzurro");
    strcpy(Casella[1689].Coordinate, "Drosso3azzurro");
    strcpy(Casella[1690].Coordinate, "Erosso3azzurro");
    strcpy(Casella[1691].Coordinate, "Frosso3azzurro");
    strcpy(Casella[1692].Coordinate, "Grosso3azzurro");
    strcpy(Casella[1693].Coordinate, "Hrosso3azzurro");
    strcpy(Casella[1694].Coordinate, "Irosso3azzurro");
    strcpy(Casella[1695].Coordinate, "Jrosso3azzurro");
    strcpy(Casella[1696].Coordinate, "Krosso3azzurro");
    strcpy(Casella[1697].Coordinate, "Lrosso3azzurro");
    strcpy(Casella[1698].Coordinate, "Mrosso3azzurro");
    strcpy(Casella[1699].Coordinate, "Nrosso3azzurro");
    strcpy(Casella[1700].Coordinate, "Orosso3azzurro");
    strcpy(Casella[1701].Coordinate, "Prosso3azzurro");
    strcpy(Casella[1702].Coordinate, "Qrosso3azzurro");
    strcpy(Casella[1703].Coordinate, "Rrosso3azzurro");
    strcpy(Casella[1704].Coordinate, "Srosso3azzurro");
    strcpy(Casella[1705].Coordinate, "Trosso3azzurro");
    strcpy(Casella[1706].Coordinate, "Urosso3azzurro");
    strcpy(Casella[1707].Coordinate, "Vrosso3azzurro");
    strcpy(Casella[1708].Coordinate, "Wrosso3azzurro");
    strcpy(Casella[1709].Coordinate, "Xrosso3azzurro");
    strcpy(Casella[1710].Coordinate, "Yrosso3azzurro");
    strcpy(Casella[1711].Coordinate, "Zrosso3azzurro");
    strcpy(Casella[1712].Coordinate, "Aazzurro3azzurro");
    strcpy(Casella[1713].Coordinate, "Bazzurro3azzurro");
    strcpy(Casella[1714].Coordinate, "Cazzurro3azzurro");
    strcpy(Casella[1715].Coordinate, "Dazzurro3azzurro");
    strcpy(Casella[1716].Coordinate, "Eazzurro3azzurro");
    strcpy(Casella[1717].Coordinate, "Fazzurro3azzurro");
    strcpy(Casella[1718].Coordinate, "Gazzurro3azzurro");
    strcpy(Casella[1719].Coordinate, "Hazzurro3azzurro");
    strcpy(Casella[1720].Coordinate, "Iazzurro3azzurro");
    strcpy(Casella[1721].Coordinate, "Jazzurro3azzurro");
    strcpy(Casella[1722].Coordinate, "Kazzurro3azzurro");
    strcpy(Casella[1723].Coordinate, "Lazzurro3azzurro");
    strcpy(Casella[1724].Coordinate, "Mazzurro3azzurro");
    strcpy(Casella[1725].Coordinate, "Nazzurro3azzurro");
    strcpy(Casella[1726].Coordinate, "Oazzurro3azzurro");
    strcpy(Casella[1727].Coordinate, "Pazzurro3azzurro");
    strcpy(Casella[1728].Coordinate, "Qazzurro3azzurro");
    strcpy(Casella[1729].Coordinate, "Razzurro3azzurro");
    strcpy(Casella[1730].Coordinate, "Sazzurro3azzurro");
    strcpy(Casella[1731].Coordinate, "Tazzurro3azzurro");
    strcpy(Casella[1732].Coordinate, "Uazzurro3azzurro");
    strcpy(Casella[1733].Coordinate, "Vazzurro3azzurro");
    strcpy(Casella[1734].Coordinate, "Wazzurro3azzurro");
    strcpy(Casella[1735].Coordinate, "Xazzurro3azzurro");
    strcpy(Casella[1736].Coordinate, "Yazzurro3azzurro");
    strcpy(Casella[1737].Coordinate, "Zazzurro3azzurro");
    strcpy(Casella[1738].Coordinate, "Agiallo3azzurro");
    strcpy(Casella[1739].Coordinate, "Bgiallo3azzurro");
    strcpy(Casella[1740].Coordinate, "Cgiallo3azzurro");
    strcpy(Casella[1741].Coordinate, "Dgiallo3azzurro");
    strcpy(Casella[1742].Coordinate, "Egiallo3azzurro");
    strcpy(Casella[1743].Coordinate, "Abianco4azzurro");
    strcpy(Casella[1744].Coordinate, "Bbianco4azzurro");
    strcpy(Casella[1745].Coordinate, "Cbianco4azzurro");
    strcpy(Casella[1746].Coordinate, "Dbianco4azzurro");
    strcpy(Casella[1747].Coordinate, "Ebianco4azzurro");
    strcpy(Casella[1748].Coordinate, "Fbianco4azzurro");
    strcpy(Casella[1749].Coordinate, "Gbianco4azzurro");
    strcpy(Casella[1750].Coordinate, "Hbianco4azzurro");
    strcpy(Casella[1751].Coordinate, "Ibianco4azzurro");
    strcpy(Casella[1752].Coordinate, "Jbianco4azzurro");
    strcpy(Casella[1753].Coordinate, "Kbianco4azzurro");
    strcpy(Casella[1754].Coordinate, "Lbianco4azzurro");
    strcpy(Casella[1755].Coordinate, "Mbianco4azzurro");
    strcpy(Casella[1756].Coordinate, "Nbianco4azzurro");
    strcpy(Casella[1757].Coordinate, "Obianco4azzurro");
    strcpy(Casella[1758].Coordinate, "Pbianco4azzurro");
    strcpy(Casella[1759].Coordinate, "Qbianco4azzurro");
    strcpy(Casella[1760].Coordinate, "Rbianco4azzurro");
    strcpy(Casella[1761].Coordinate, "Sbianco4azzurro");
    strcpy(Casella[1762].Coordinate, "Tbianco4azzurro");
    strcpy(Casella[1763].Coordinate, "Ubianco4azzurro");
    strcpy(Casella[1764].Coordinate, "Vbianco4azzurro");
    strcpy(Casella[1765].Coordinate, "Wbianco4azzurro");
    strcpy(Casella[1766].Coordinate, "Xbianco4azzurro");
    strcpy(Casella[1767].Coordinate, "Ybianco4azzurro");
    strcpy(Casella[1768].Coordinate, "Zbianco4azzurro");
    strcpy(Casella[1769].Coordinate, "Arosso4azzurro");
    strcpy(Casella[1770].Coordinate, "Brosso4azzurro");
    strcpy(Casella[1771].Coordinate, "Crosso4azzurro");
    strcpy(Casella[1772].Coordinate, "Drosso4azzurro");
    strcpy(Casella[1773].Coordinate, "Erosso4azzurro");
    strcpy(Casella[1774].Coordinate, "Frosso4azzurro");
    strcpy(Casella[1775].Coordinate, "Grosso4azzurro");
    strcpy(Casella[1776].Coordinate, "Hrosso4azzurro");
    strcpy(Casella[1777].Coordinate, "Irosso4azzurro");
    strcpy(Casella[1778].Coordinate, "Jrosso4azzurro");
    strcpy(Casella[1779].Coordinate, "Krosso4azzurro");
    strcpy(Casella[1780].Coordinate, "Lrosso4azzurro");
    strcpy(Casella[1781].Coordinate, "Mrosso4azzurro");
    strcpy(Casella[1782].Coordinate, "Nrosso4azzurro");
    strcpy(Casella[1783].Coordinate, "Orosso4azzurro");
    strcpy(Casella[1784].Coordinate, "Prosso4azzurro");
    strcpy(Casella[1785].Coordinate, "Qrosso4azzurro");
    strcpy(Casella[1786].Coordinate, "Rrosso4azzurro");
    strcpy(Casella[1787].Coordinate, "Srosso4azzurro");
    strcpy(Casella[1788].Coordinate, "Trosso4azzurro");
    strcpy(Casella[1789].Coordinate, "Urosso4azzurro");
    strcpy(Casella[1790].Coordinate, "Vrosso4azzurro");
    strcpy(Casella[1791].Coordinate, "Wrosso4azzurro");
    strcpy(Casella[1792].Coordinate, "Xrosso4azzurro");
    strcpy(Casella[1793].Coordinate, "Yrosso4azzurro");
    strcpy(Casella[1794].Coordinate, "Zrosso4azzurro");
    strcpy(Casella[1795].Coordinate, "Aazzurro4azzurro");
    strcpy(Casella[1796].Coordinate, "Bazzurro4azzurro");
    strcpy(Casella[1797].Coordinate, "Cazzurro4azzurro");
    strcpy(Casella[1798].Coordinate, "Dazzurro4azzurro");
    strcpy(Casella[1799].Coordinate, "Eazzurro4azzurro");
    strcpy(Casella[1800].Coordinate, "Fazzurro4azzurro");
    strcpy(Casella[1801].Coordinate, "Gazzurro4azzurro");
    strcpy(Casella[1802].Coordinate, "Hazzurro4azzurro");
    strcpy(Casella[1803].Coordinate, "Iazzurro4azzurro");
    strcpy(Casella[1804].Coordinate, "Jazzurro4azzurro");
    strcpy(Casella[1805].Coordinate, "Kazzurro4azzurro");
    strcpy(Casella[1806].Coordinate, "Lazzurro4azzurro");
    strcpy(Casella[1807].Coordinate, "Mazzurro4azzurro");
    strcpy(Casella[1808].Coordinate, "Nazzurro4azzurro");
    strcpy(Casella[1809].Coordinate, "Oazzurro4azzurro");
    strcpy(Casella[1810].Coordinate, "Pazzurro4azzurro");
    strcpy(Casella[1811].Coordinate, "Qazzurro4azzurro");
    strcpy(Casella[1812].Coordinate, "Razzurro4azzurro");
    strcpy(Casella[1813].Coordinate, "Sazzurro4azzurro");
    strcpy(Casella[1814].Coordinate, "Tazzurro4azzurro");
    strcpy(Casella[1815].Coordinate, "Uazzurro4azzurro");
    strcpy(Casella[1816].Coordinate, "Vazzurro4azzurro");
    strcpy(Casella[1817].Coordinate, "Wazzurro4azzurro");
    strcpy(Casella[1818].Coordinate, "Xazzurro4azzurro");
    strcpy(Casella[1819].Coordinate, "Yazzurro4azzurro");
    strcpy(Casella[1820].Coordinate, "Zazzurro4azzurro");
    strcpy(Casella[1821].Coordinate, "Agiallo4azzurro");
    strcpy(Casella[1822].Coordinate, "Bgiallo4azzurro");
    strcpy(Casella[1823].Coordinate, "Cgiallo4azzurro");
    strcpy(Casella[1824].Coordinate, "Dgiallo4azzurro");
    strcpy(Casella[1825].Coordinate, "Egiallo4azzurro");
    strcpy(Casella[1826].Coordinate, "Abianco5azzurro");
    strcpy(Casella[1827].Coordinate, "Bbianco5azzurro");
    strcpy(Casella[1828].Coordinate, "Cbianco5azzurro");
    strcpy(Casella[1829].Coordinate, "Dbianco5azzurro");
    strcpy(Casella[1830].Coordinate, "Ebianco5azzurro");
    strcpy(Casella[1831].Coordinate, "Fbianco5azzurro");
    strcpy(Casella[1832].Coordinate, "Gbianco5azzurro");
    strcpy(Casella[1833].Coordinate, "Hbianco5azzurro");
    strcpy(Casella[1834].Coordinate, "Ibianco5azzurro");
    strcpy(Casella[1835].Coordinate, "Jbianco5azzurro");
    strcpy(Casella[1836].Coordinate, "Kbianco5azzurro");
    strcpy(Casella[1837].Coordinate, "Lbianco5azzurro");
    strcpy(Casella[1838].Coordinate, "Mbianco5azzurro");
    strcpy(Casella[1839].Coordinate, "Nbianco5azzurro");
    strcpy(Casella[1840].Coordinate, "Obianco5azzurro");
    strcpy(Casella[1841].Coordinate, "Pbianco5azzurro");
    strcpy(Casella[1842].Coordinate, "Qbianco5azzurro");
    strcpy(Casella[1843].Coordinate, "Rbianco5azzurro");
    strcpy(Casella[1844].Coordinate, "Sbianco5azzurro");
    strcpy(Casella[1845].Coordinate, "Tbianco5azzurro");
    strcpy(Casella[1846].Coordinate, "Ubianco5azzurro");
    strcpy(Casella[1847].Coordinate, "Vbianco5azzurro");
    strcpy(Casella[1848].Coordinate, "Wbianco5azzurro");
    strcpy(Casella[1849].Coordinate, "Xbianco5azzurro");
    strcpy(Casella[1850].Coordinate, "Ybianco5azzurro");
    strcpy(Casella[1851].Coordinate, "Zbianco5azzurro");
    strcpy(Casella[1852].Coordinate, "Arosso5azzurro");
    strcpy(Casella[1853].Coordinate, "Brosso5azzurro");
    strcpy(Casella[1854].Coordinate, "Crosso5azzurro");
    strcpy(Casella[1855].Coordinate, "Drosso5azzurro");
    strcpy(Casella[1856].Coordinate, "Erosso5azzurro");
    strcpy(Casella[1857].Coordinate, "Frosso5azzurro");
    strcpy(Casella[1858].Coordinate, "Grosso5azzurro");
    strcpy(Casella[1859].Coordinate, "Hrosso5azzurro");
    strcpy(Casella[1860].Coordinate, "Irosso5azzurro");
    strcpy(Casella[1861].Coordinate, "Jrosso5azzurro");
    strcpy(Casella[1862].Coordinate, "Krosso5azzurro");
    strcpy(Casella[1863].Coordinate, "Lrosso5azzurro");
    strcpy(Casella[1864].Coordinate, "Mrosso5azzurro");
    strcpy(Casella[1865].Coordinate, "Nrosso5azzurro");
    strcpy(Casella[1866].Coordinate, "Orosso5azzurro");
    strcpy(Casella[1867].Coordinate, "Prosso5azzurro");
    strcpy(Casella[1868].Coordinate, "Qrosso5azzurro");
    strcpy(Casella[1869].Coordinate, "Rrosso5azzurro");
    strcpy(Casella[1870].Coordinate, "Srosso5azzurro");
    strcpy(Casella[1871].Coordinate, "Trosso5azzurro");
    strcpy(Casella[1872].Coordinate, "Urosso5azzurro");
    strcpy(Casella[1873].Coordinate, "Vrosso5azzurro");
    strcpy(Casella[1874].Coordinate, "Wrosso5azzurro");
    strcpy(Casella[1875].Coordinate, "Xrosso5azzurro");
    strcpy(Casella[1876].Coordinate, "Yrosso5azzurro");
    strcpy(Casella[1877].Coordinate, "Zrosso5azzurro");
    strcpy(Casella[1878].Coordinate, "Aazzurro5azzurro");
    strcpy(Casella[1879].Coordinate, "Bazzurro5azzurro");
    strcpy(Casella[1880].Coordinate, "Cazzurro5azzurro");
    strcpy(Casella[1881].Coordinate, "Dazzurro5azzurro");
    strcpy(Casella[1882].Coordinate, "Eazzurro5azzurro");
    strcpy(Casella[1883].Coordinate, "Fazzurro5azzurro");
    strcpy(Casella[1884].Coordinate, "Gazzurro5azzurro");
    strcpy(Casella[1885].Coordinate, "Hazzurro5azzurro");
    strcpy(Casella[1886].Coordinate, "Iazzurro5azzurro");
    strcpy(Casella[1887].Coordinate, "Jazzurro5azzurro");
    strcpy(Casella[1888].Coordinate, "Kazzurro5azzurro");
    strcpy(Casella[1889].Coordinate, "Lazzurro5azzurro");
    strcpy(Casella[1890].Coordinate, "Mazzurro5azzurro");
    strcpy(Casella[1891].Coordinate, "Nazzurro5azzurro");
    strcpy(Casella[1892].Coordinate, "Oazzurro5azzurro");
    strcpy(Casella[1893].Coordinate, "Pazzurro5azzurro");
    strcpy(Casella[1894].Coordinate, "Qazzurro5azzurro");
    strcpy(Casella[1895].Coordinate, "Razzurro5azzurro");
    strcpy(Casella[1896].Coordinate, "Sazzurro5azzurro");
    strcpy(Casella[1897].Coordinate, "Tazzurro5azzurro");
    strcpy(Casella[1898].Coordinate, "Uazzurro5azzurro");
    strcpy(Casella[1899].Coordinate, "Vazzurro5azzurro");
    strcpy(Casella[1900].Coordinate, "Wazzurro5azzurro");
    strcpy(Casella[1901].Coordinate, "Xazzurro5azzurro");
    strcpy(Casella[1902].Coordinate, "Yazzurro5azzurro");
    strcpy(Casella[1903].Coordinate, "Zazzurro5azzurro");
    strcpy(Casella[1904].Coordinate, "Agiallo5azzurro");
    strcpy(Casella[1905].Coordinate, "Bgiallo5azzurro");
    strcpy(Casella[1906].Coordinate, "Cgiallo5azzurro");
    strcpy(Casella[1907].Coordinate, "Dgiallo5azzurro");
    strcpy(Casella[1908].Coordinate, "Egiallo5azzurro");
    strcpy(Casella[1909].Coordinate, "Abianco6azzurro");
    strcpy(Casella[1910].Coordinate, "Bbianco6azzurro");
    strcpy(Casella[1911].Coordinate, "Cbianco6azzurro");
    strcpy(Casella[1912].Coordinate, "Dbianco6azzurro");
    strcpy(Casella[1913].Coordinate, "Ebianco6azzurro");
    strcpy(Casella[1914].Coordinate, "Fbianco6azzurro");
    strcpy(Casella[1915].Coordinate, "Gbianco6azzurro");
    strcpy(Casella[1916].Coordinate, "Hbianco6azzurro");
    strcpy(Casella[1917].Coordinate, "Ibianco6azzurro");
    strcpy(Casella[1918].Coordinate, "Jbianco6azzurro");
    strcpy(Casella[1919].Coordinate, "Kbianco6azzurro");
    strcpy(Casella[1920].Coordinate, "Lbianco6azzurro");
    strcpy(Casella[1921].Coordinate, "Mbianco6azzurro");
    strcpy(Casella[1922].Coordinate, "Nbianco6azzurro");
    strcpy(Casella[1923].Coordinate, "Obianco6azzurro");
    strcpy(Casella[1924].Coordinate, "Pbianco6azzurro");
    strcpy(Casella[1925].Coordinate, "Qbianco6azzurro");
    strcpy(Casella[1926].Coordinate, "Rbianco6azzurro");
    strcpy(Casella[1927].Coordinate, "Sbianco6azzurro");
    strcpy(Casella[1928].Coordinate, "Tbianco6azzurro");
    strcpy(Casella[1929].Coordinate, "Ubianco6azzurro");
    strcpy(Casella[1930].Coordinate, "Vbianco6azzurro");
    strcpy(Casella[1931].Coordinate, "Wbianco6azzurro");
    strcpy(Casella[1932].Coordinate, "Xbianco6azzurro");
    strcpy(Casella[1933].Coordinate, "Ybianco6azzurro");
    strcpy(Casella[1934].Coordinate, "Zbianco6azzurro");
    strcpy(Casella[1935].Coordinate, "Arosso6azzurro");
    strcpy(Casella[1936].Coordinate, "Brosso6azzurro");
    strcpy(Casella[1937].Coordinate, "Crosso6azzurro");
    strcpy(Casella[1938].Coordinate, "Drosso6azzurro");
    strcpy(Casella[1939].Coordinate, "Erosso6azzurro");
    strcpy(Casella[1940].Coordinate, "Frosso6azzurro");
    strcpy(Casella[1941].Coordinate, "Grosso6azzurro");
    strcpy(Casella[1942].Coordinate, "Hrosso6azzurro");
    strcpy(Casella[1943].Coordinate, "Irosso6azzurro");
    strcpy(Casella[1944].Coordinate, "Jrosso6azzurro");
    strcpy(Casella[1945].Coordinate, "Krosso6azzurro");
    strcpy(Casella[1946].Coordinate, "Lrosso6azzurro");
    strcpy(Casella[1947].Coordinate, "Mrosso6azzurro");
    strcpy(Casella[1948].Coordinate, "Nrosso6azzurro");
    strcpy(Casella[1949].Coordinate, "Orosso6azzurro");
    strcpy(Casella[1950].Coordinate, "Prosso6azzurro");
    strcpy(Casella[1951].Coordinate, "Qrosso6azzurro");
    strcpy(Casella[1952].Coordinate, "Rrosso6azzurro");
    strcpy(Casella[1953].Coordinate, "Srosso6azzurro");
    strcpy(Casella[1954].Coordinate, "Trosso6azzurro");
    strcpy(Casella[1955].Coordinate, "Urosso6azzurro");
    strcpy(Casella[1956].Coordinate, "Vrosso6azzurro");
    strcpy(Casella[1957].Coordinate, "Wrosso6azzurro");
    strcpy(Casella[1958].Coordinate, "Xrosso6azzurro");
    strcpy(Casella[1959].Coordinate, "Yrosso6azzurro");
    strcpy(Casella[1960].Coordinate, "Zrosso6azzurro");
    strcpy(Casella[1961].Coordinate, "Aazzurro6azzurro");
    strcpy(Casella[1962].Coordinate, "Bazzurro6azzurro");
    strcpy(Casella[1963].Coordinate, "Cazzurro6azzurro");
    strcpy(Casella[1964].Coordinate, "Dazzurro6azzurro");
    strcpy(Casella[1965].Coordinate, "Eazzurro6azzurro");
    strcpy(Casella[1966].Coordinate, "Fazzurro6azzurro");
    strcpy(Casella[1967].Coordinate, "Gazzurro6azzurro");
    strcpy(Casella[1968].Coordinate, "Hazzurro6azzurro");
    strcpy(Casella[1969].Coordinate, "Iazzurro6azzurro");
    strcpy(Casella[1970].Coordinate, "Jazzurro6azzurro");
    strcpy(Casella[1971].Coordinate, "Kazzurro6azzurro");
    strcpy(Casella[1972].Coordinate, "Lazzurro6azzurro");
    strcpy(Casella[1973].Coordinate, "Mazzurro6azzurro");
    strcpy(Casella[1974].Coordinate, "Nazzurro6azzurro");
    strcpy(Casella[1975].Coordinate, "Oazzurro6azzurro");
    strcpy(Casella[1976].Coordinate, "Pazzurro6azzurro");
    strcpy(Casella[1977].Coordinate, "Qazzurro6azzurro");
    strcpy(Casella[1978].Coordinate, "Razzurro6azzurro");
    strcpy(Casella[1979].Coordinate, "Sazzurro6azzurro");
    strcpy(Casella[1980].Coordinate, "Tazzurro6azzurro");
    strcpy(Casella[1981].Coordinate, "Uazzurro6azzurro");
    strcpy(Casella[1982].Coordinate, "Vazzurro6azzurro");
    strcpy(Casella[1983].Coordinate, "Wazzurro6azzurro");
    strcpy(Casella[1984].Coordinate, "Xazzurro6azzurro");
    strcpy(Casella[1985].Coordinate, "Yazzurro6azzurro");
    strcpy(Casella[1986].Coordinate, "Zazzurro6azzurro");
    strcpy(Casella[1987].Coordinate, "Agiallo6azzurro");
    strcpy(Casella[1988].Coordinate, "Bgiallo6azzurro");
    strcpy(Casella[1989].Coordinate, "Cgiallo6azzurro");
    strcpy(Casella[1990].Coordinate, "Dgiallo6azzurro");
    strcpy(Casella[1991].Coordinate, "Egiallo6azzurro");
    strcpy(Casella[1992].Coordinate, "Abianco7azzurro");
    strcpy(Casella[1993].Coordinate, "Bbianco7azzurro");
    strcpy(Casella[1994].Coordinate, "Cbianco7azzurro");
    strcpy(Casella[1995].Coordinate, "Dbianco7azzurro");
    strcpy(Casella[1996].Coordinate, "Ebianco7azzurro");
    strcpy(Casella[1997].Coordinate, "Fbianco7azzurro");
    strcpy(Casella[1998].Coordinate, "Gbianco7azzurro");
    strcpy(Casella[1999].Coordinate, "Hbianco7azzurro");
    strcpy(Casella[2000].Coordinate, "Ibianco7azzurro");
    strcpy(Casella[2001].Coordinate, "Jbianco7azzurro");
    strcpy(Casella[2002].Coordinate, "Kbianco7azzurro");
    strcpy(Casella[2003].Coordinate, "Lbianco7azzurro");
    strcpy(Casella[2004].Coordinate, "Mbianco7azzurro");
    strcpy(Casella[2005].Coordinate, "Nbianco7azzurro");
    strcpy(Casella[2006].Coordinate, "Obianco7azzurro");
    strcpy(Casella[2007].Coordinate, "Pbianco7azzurro");
    strcpy(Casella[2008].Coordinate, "Qbianco7azzurro");
    strcpy(Casella[2009].Coordinate, "Rbianco7azzurro");
    strcpy(Casella[2010].Coordinate, "Sbianco7azzurro");
    strcpy(Casella[2011].Coordinate, "Tbianco7azzurro");
    strcpy(Casella[2012].Coordinate, "Ubianco7azzurro");
    strcpy(Casella[2013].Coordinate, "Vbianco7azzurro");
    strcpy(Casella[2014].Coordinate, "Wbianco7azzurro");
    strcpy(Casella[2015].Coordinate, "Xbianco7azzurro");
    strcpy(Casella[2016].Coordinate, "Ybianco7azzurro");
    strcpy(Casella[2017].Coordinate, "Zbianco7azzurro");
    strcpy(Casella[2018].Coordinate, "Arosso7azzurro");
    strcpy(Casella[2019].Coordinate, "Brosso7azzurro");
    strcpy(Casella[2020].Coordinate, "Crosso7azzurro");
    strcpy(Casella[2021].Coordinate, "Drosso7azzurro");
    strcpy(Casella[2022].Coordinate, "Erosso7azzurro");
    strcpy(Casella[2023].Coordinate, "Frosso7azzurro");
    strcpy(Casella[2024].Coordinate, "Grosso7azzurro");
    strcpy(Casella[2025].Coordinate, "Hrosso7azzurro");
    strcpy(Casella[2026].Coordinate, "Irosso7azzurro");
    strcpy(Casella[2027].Coordinate, "Jrosso7azzurro");
    strcpy(Casella[2028].Coordinate, "Krosso7azzurro");
    strcpy(Casella[2029].Coordinate, "Lrosso7azzurro");
    strcpy(Casella[2030].Coordinate, "Mrosso7azzurro");
    strcpy(Casella[2031].Coordinate, "Nrosso7azzurro");
    strcpy(Casella[2032].Coordinate, "Orosso7azzurro");
    strcpy(Casella[2033].Coordinate, "Prosso7azzurro");
    strcpy(Casella[2034].Coordinate, "Qrosso7azzurro");
    strcpy(Casella[2035].Coordinate, "Rrosso7azzurro");
    strcpy(Casella[2036].Coordinate, "Srosso7azzurro");
    strcpy(Casella[2037].Coordinate, "Trosso7azzurro");
    strcpy(Casella[2038].Coordinate, "Urosso7azzurro");
    strcpy(Casella[2039].Coordinate, "Vrosso7azzurro");
    strcpy(Casella[2040].Coordinate, "Wrosso7azzurro");
    strcpy(Casella[2041].Coordinate, "Xrosso7azzurro");
    strcpy(Casella[2042].Coordinate, "Yrosso7azzurro");
    strcpy(Casella[2043].Coordinate, "Zrosso7azzurro");
    strcpy(Casella[2044].Coordinate, "Aazzurro7azzurro");
    strcpy(Casella[2045].Coordinate, "Bazzurro7azzurro");
    strcpy(Casella[2046].Coordinate, "Cazzurro7azzurro");
    strcpy(Casella[2047].Coordinate, "Dazzurro7azzurro");
    strcpy(Casella[2048].Coordinate, "Eazzurro7azzurro");
    strcpy(Casella[2049].Coordinate, "Fazzurro7azzurro");
    strcpy(Casella[2050].Coordinate, "Gazzurro7azzurro");
    strcpy(Casella[2051].Coordinate, "Hazzurro7azzurro");
    strcpy(Casella[2052].Coordinate, "Iazzurro7azzurro");
    strcpy(Casella[2053].Coordinate, "Jazzurro7azzurro");
    strcpy(Casella[2054].Coordinate, "Kazzurro7azzurro");
    strcpy(Casella[2055].Coordinate, "Lazzurro7azzurro");
    strcpy(Casella[2056].Coordinate, "Mazzurro7azzurro");
    strcpy(Casella[2057].Coordinate, "Nazzurro7azzurro");
    strcpy(Casella[2058].Coordinate, "Oazzurro7azzurro");
    strcpy(Casella[2059].Coordinate, "Pazzurro7azzurro");
    strcpy(Casella[2060].Coordinate, "Qazzurro7azzurro");
    strcpy(Casella[2061].Coordinate, "Razzurro7azzurro");
    strcpy(Casella[2062].Coordinate, "Sazzurro7azzurro");
    strcpy(Casella[2063].Coordinate, "Tazzurro7azzurro");
    strcpy(Casella[2064].Coordinate, "Uazzurro7azzurro");
    strcpy(Casella[2065].Coordinate, "Vazzurro7azzurro");
    strcpy(Casella[2066].Coordinate, "Wazzurro7azzurro");
    strcpy(Casella[2067].Coordinate, "Xazzurro7azzurro");
    strcpy(Casella[2068].Coordinate, "Yazzurro7azzurro");
    strcpy(Casella[2069].Coordinate, "Zazzurro7azzurro");
    strcpy(Casella[2070].Coordinate, "Agiallo7azzurro");
    strcpy(Casella[2071].Coordinate, "Bgiallo7azzurro");
    strcpy(Casella[2072].Coordinate, "Cgiallo7azzurro");
    strcpy(Casella[2073].Coordinate, "Dgiallo7azzurro");
    strcpy(Casella[2074].Coordinate, "Egiallo7azzurro");
    strcpy(Casella[2075].Coordinate, "Abianco8azzurro");
    strcpy(Casella[2076].Coordinate, "Bbianco8azzurro");
    strcpy(Casella[2077].Coordinate, "Cbianco8azzurro");
    strcpy(Casella[2078].Coordinate, "Dbianco8azzurro");
    strcpy(Casella[2079].Coordinate, "Ebianco8azzurro");
    strcpy(Casella[2080].Coordinate, "Fbianco8azzurro");
    strcpy(Casella[2081].Coordinate, "Gbianco8azzurro");
    strcpy(Casella[2082].Coordinate, "Hbianco8azzurro");
    strcpy(Casella[2083].Coordinate, "Ibianco8azzurro");
    strcpy(Casella[2084].Coordinate, "Jbianco8azzurro");
    strcpy(Casella[2085].Coordinate, "Kbianco8azzurro");
    strcpy(Casella[2086].Coordinate, "Lbianco8azzurro");
    strcpy(Casella[2087].Coordinate, "Mbianco8azzurro");
    strcpy(Casella[2088].Coordinate, "Nbianco8azzurro");
    strcpy(Casella[2089].Coordinate, "Obianco8azzurro");
    strcpy(Casella[2090].Coordinate, "Pbianco8azzurro");
    strcpy(Casella[2091].Coordinate, "Qbianco8azzurro");
    strcpy(Casella[2092].Coordinate, "Rbianco8azzurro");
    strcpy(Casella[2093].Coordinate, "Sbianco8azzurro");
    strcpy(Casella[2094].Coordinate, "Tbianco8azzurro");
    strcpy(Casella[2095].Coordinate, "Ubianco8azzurro");
    strcpy(Casella[2096].Coordinate, "Vbianco8azzurro");
    strcpy(Casella[2097].Coordinate, "Wbianco8azzurro");
    strcpy(Casella[2098].Coordinate, "Xbianco8azzurro");
    strcpy(Casella[2099].Coordinate, "Ybianco8azzurro");
    strcpy(Casella[2100].Coordinate, "Zbianco8azzurro");
    strcpy(Casella[2101].Coordinate, "Arosso8azzurro");
    strcpy(Casella[2102].Coordinate, "Brosso8azzurro");
    strcpy(Casella[2103].Coordinate, "Crosso8azzurro");
    strcpy(Casella[2104].Coordinate, "Drosso8azzurro");
    strcpy(Casella[2105].Coordinate, "Erosso8azzurro");
    strcpy(Casella[2106].Coordinate, "Frosso8azzurro");
    strcpy(Casella[2107].Coordinate, "Grosso8azzurro");
    strcpy(Casella[2108].Coordinate, "Hrosso8azzurro");
    strcpy(Casella[2109].Coordinate, "Irosso8azzurro");
    strcpy(Casella[2110].Coordinate, "Jrosso8azzurro");
    strcpy(Casella[2111].Coordinate, "Krosso8azzurro");
    strcpy(Casella[2112].Coordinate, "Lrosso8azzurro");
    strcpy(Casella[2113].Coordinate, "Mrosso8azzurro");
    strcpy(Casella[2114].Coordinate, "Nrosso8azzurro");
    strcpy(Casella[2115].Coordinate, "Orosso8azzurro");
    strcpy(Casella[2116].Coordinate, "Prosso8azzurro");
    strcpy(Casella[2117].Coordinate, "Qrosso8azzurro");
    strcpy(Casella[2118].Coordinate, "Rrosso8azzurro");
    strcpy(Casella[2119].Coordinate, "Srosso8azzurro");
    strcpy(Casella[2120].Coordinate, "Trosso8azzurro");
    strcpy(Casella[2121].Coordinate, "Urosso8azzurro");
    strcpy(Casella[2122].Coordinate, "Vrosso8azzurro");
    strcpy(Casella[2123].Coordinate, "Wrosso8azzurro");
    strcpy(Casella[2124].Coordinate, "Xrosso8azzurro");
    strcpy(Casella[2125].Coordinate, "Yrosso8azzurro");
    strcpy(Casella[2126].Coordinate, "Zrosso8azzurro");
    strcpy(Casella[2127].Coordinate, "Aazzurro8azzurro");
    strcpy(Casella[2128].Coordinate, "Bazzurro8azzurro");
    strcpy(Casella[2129].Coordinate, "Cazzurro8azzurro");
    strcpy(Casella[2130].Coordinate, "Dazzurro8azzurro");
    strcpy(Casella[2131].Coordinate, "Eazzurro8azzurro");
    strcpy(Casella[2132].Coordinate, "Fazzurro8azzurro");
    strcpy(Casella[2133].Coordinate, "Gazzurro8azzurro");
    strcpy(Casella[2134].Coordinate, "Hazzurro8azzurro");
    strcpy(Casella[2135].Coordinate, "Iazzurro8azzurro");
    strcpy(Casella[2136].Coordinate, "Jazzurro8azzurro");
    strcpy(Casella[2137].Coordinate, "Kazzurro8azzurro");
    strcpy(Casella[2138].Coordinate, "Lazzurro8azzurro");
    strcpy(Casella[2139].Coordinate, "Mazzurro8azzurro");
    strcpy(Casella[2140].Coordinate, "Nazzurro8azzurro");
    strcpy(Casella[2141].Coordinate, "Oazzurro8azzurro");
    strcpy(Casella[2142].Coordinate, "Pazzurro8azzurro");
    strcpy(Casella[2143].Coordinate, "Qazzurro8azzurro");
    strcpy(Casella[2144].Coordinate, "Razzurro8azzurro");
    strcpy(Casella[2145].Coordinate, "Sazzurro8azzurro");
    strcpy(Casella[2146].Coordinate, "Tazzurro8azzurro");
    strcpy(Casella[2147].Coordinate, "Uazzurro8azzurro");
    strcpy(Casella[2148].Coordinate, "Vazzurro8azzurro");
    strcpy(Casella[2149].Coordinate, "Wazzurro8azzurro");
    strcpy(Casella[2150].Coordinate, "Xazzurro8azzurro");
    strcpy(Casella[2151].Coordinate, "Yazzurro8azzurro");
    strcpy(Casella[2152].Coordinate, "Zazzurro8azzurro");
    strcpy(Casella[2153].Coordinate, "Agiallo8azzurro");
    strcpy(Casella[2154].Coordinate, "Bgiallo8azzurro");
    strcpy(Casella[2155].Coordinate, "Cgiallo8azzurro");
    strcpy(Casella[2156].Coordinate, "Dgiallo8azzurro");
    strcpy(Casella[2157].Coordinate, "Egiallo8azzurro");
    strcpy(Casella[2158].Coordinate, "Abianco9azzurro");
    strcpy(Casella[2159].Coordinate, "Bbianco9azzurro");
    strcpy(Casella[2160].Coordinate, "Cbianco9azzurro");
    strcpy(Casella[2161].Coordinate, "Dbianco9azzurro");
    strcpy(Casella[2162].Coordinate, "Ebianco9azzurro");
    strcpy(Casella[2163].Coordinate, "Fbianco9azzurro");
    strcpy(Casella[2164].Coordinate, "Gbianco9azzurro");
    strcpy(Casella[2165].Coordinate, "Hbianco9azzurro");
    strcpy(Casella[2166].Coordinate, "Ibianco9azzurro");
    strcpy(Casella[2167].Coordinate, "Jbianco9azzurro");
    strcpy(Casella[2168].Coordinate, "Kbianco9azzurro");
    strcpy(Casella[2169].Coordinate, "Lbianco9azzurro");
    strcpy(Casella[2170].Coordinate, "Mbianco9azzurro");
    strcpy(Casella[2171].Coordinate, "Nbianco9azzurro");
    strcpy(Casella[2172].Coordinate, "Obianco9azzurro");
    strcpy(Casella[2173].Coordinate, "Pbianco9azzurro");
    strcpy(Casella[2174].Coordinate, "Qbianco9azzurro");
    strcpy(Casella[2175].Coordinate, "Rbianco9azzurro");
    strcpy(Casella[2176].Coordinate, "Sbianco9azzurro");
    strcpy(Casella[2177].Coordinate, "Tbianco9azzurro");
    strcpy(Casella[2178].Coordinate, "Ubianco9azzurro");
    strcpy(Casella[2179].Coordinate, "Vbianco9azzurro");
    strcpy(Casella[2180].Coordinate, "Wbianco9azzurro");
    strcpy(Casella[2181].Coordinate, "Xbianco9azzurro");
    strcpy(Casella[2182].Coordinate, "Ybianco9azzurro");
    strcpy(Casella[2183].Coordinate, "Zbianco9azzurro");
    strcpy(Casella[2184].Coordinate, "Arosso9azzurro");
    strcpy(Casella[2185].Coordinate, "Brosso9azzurro");
    strcpy(Casella[2186].Coordinate, "Crosso9azzurro");
    strcpy(Casella[2187].Coordinate, "Drosso9azzurro");
    strcpy(Casella[2188].Coordinate, "Erosso9azzurro");
    strcpy(Casella[2189].Coordinate, "Frosso9azzurro");
    strcpy(Casella[2190].Coordinate, "Grosso9azzurro");
    strcpy(Casella[2191].Coordinate, "Hrosso9azzurro");
    strcpy(Casella[2192].Coordinate, "Irosso9azzurro");
    strcpy(Casella[2193].Coordinate, "Jrosso9azzurro");
    strcpy(Casella[2194].Coordinate, "Krosso9azzurro");
    strcpy(Casella[2195].Coordinate, "Lrosso9azzurro");
    strcpy(Casella[2196].Coordinate, "Mrosso9azzurro");
    strcpy(Casella[2197].Coordinate, "Nrosso9azzurro");
    strcpy(Casella[2198].Coordinate, "Orosso9azzurro");
    strcpy(Casella[2199].Coordinate, "Prosso9azzurro");
    strcpy(Casella[2200].Coordinate, "Qrosso9azzurro");
    strcpy(Casella[2201].Coordinate, "Rrosso9azzurro");
    strcpy(Casella[2202].Coordinate, "Srosso9azzurro");
    strcpy(Casella[2203].Coordinate, "Trosso9azzurro");
    strcpy(Casella[2204].Coordinate, "Urosso9azzurro");
    strcpy(Casella[2205].Coordinate, "Vrosso9azzurro");
    strcpy(Casella[2206].Coordinate, "Wrosso9azzurro");
    strcpy(Casella[2207].Coordinate, "Xrosso9azzurro");
    strcpy(Casella[2208].Coordinate, "Yrosso9azzurro");
    strcpy(Casella[2209].Coordinate, "Zrosso9azzurro");
    strcpy(Casella[2210].Coordinate, "Aazzurro9azzurro");
    strcpy(Casella[2211].Coordinate, "Bazzurro9azzurro");
    strcpy(Casella[2212].Coordinate, "Cazzurro9azzurro");
    strcpy(Casella[2213].Coordinate, "Dazzurro9azzurro");
    strcpy(Casella[2214].Coordinate, "Eazzurro9azzurro");
    strcpy(Casella[2215].Coordinate, "Fazzurro9azzurro");
    strcpy(Casella[2216].Coordinate, "Gazzurro9azzurro");
    strcpy(Casella[2217].Coordinate, "Hazzurro9azzurro");
    strcpy(Casella[2218].Coordinate, "Iazzurro9azzurro");
    strcpy(Casella[2219].Coordinate, "Jazzurro9azzurro");
    strcpy(Casella[2220].Coordinate, "Kazzurro9azzurro");
    strcpy(Casella[2221].Coordinate, "Lazzurro9azzurro");
    strcpy(Casella[2222].Coordinate, "Mazzurro9azzurro");
    strcpy(Casella[2223].Coordinate, "Nazzurro9azzurro");
    strcpy(Casella[2224].Coordinate, "Oazzurro9azzurro");
    strcpy(Casella[2225].Coordinate, "Pazzurro9azzurro");
    strcpy(Casella[2226].Coordinate, "Qazzurro9azzurro");
    strcpy(Casella[2227].Coordinate, "Razzurro9azzurro");
    strcpy(Casella[2228].Coordinate, "Sazzurro9azzurro");
    strcpy(Casella[2229].Coordinate, "Tazzurro9azzurro");
    strcpy(Casella[2230].Coordinate, "Uazzurro9azzurro");
    strcpy(Casella[2231].Coordinate, "Vazzurro9azzurro");
    strcpy(Casella[2232].Coordinate, "Wazzurro9azzurro");
    strcpy(Casella[2233].Coordinate, "Xazzurro9azzurro");
    strcpy(Casella[2234].Coordinate, "Yazzurro9azzurro");
    strcpy(Casella[2235].Coordinate, "Zazzurro9azzurro");
    strcpy(Casella[2236].Coordinate, "Agiallo9azzurro");
    strcpy(Casella[2237].Coordinate, "Bgiallo9azzurro");
    strcpy(Casella[2238].Coordinate, "Cgiallo9azzurro");
    strcpy(Casella[2239].Coordinate, "Dgiallo9azzurro");
    strcpy(Casella[2240].Coordinate, "Egiallo9azzurro");
    strcpy(Casella[2241].Coordinate, "Abianco1giallo");
    strcpy(Casella[2242].Coordinate, "Bbianco1giallo");
    strcpy(Casella[2243].Coordinate, "Cbianco1giallo");
    strcpy(Casella[2244].Coordinate, "Dbianco1giallo");
    strcpy(Casella[2245].Coordinate, "Ebianco1giallo");
    strcpy(Casella[2246].Coordinate, "Fbianco1giallo");
    strcpy(Casella[2247].Coordinate, "Gbianco1giallo");
    strcpy(Casella[2248].Coordinate, "Hbianco1giallo");
    strcpy(Casella[2249].Coordinate, "Ibianco1giallo");
    strcpy(Casella[2250].Coordinate, "Jbianco1giallo");
    strcpy(Casella[2251].Coordinate, "Kbianco1giallo");
    strcpy(Casella[2252].Coordinate, "Lbianco1giallo");
    strcpy(Casella[2253].Coordinate, "Mbianco1giallo");
    strcpy(Casella[2254].Coordinate, "Nbianco1giallo");
    strcpy(Casella[2255].Coordinate, "Obianco1giallo");
    strcpy(Casella[2256].Coordinate, "Pbianco1giallo");
    strcpy(Casella[2257].Coordinate, "Qbianco1giallo");
    strcpy(Casella[2258].Coordinate, "Rbianco1giallo");
    strcpy(Casella[2259].Coordinate, "Sbianco1giallo");
    strcpy(Casella[2260].Coordinate, "Tbianco1giallo");
    strcpy(Casella[2261].Coordinate, "Ubianco1giallo");
    strcpy(Casella[2262].Coordinate, "Vbianco1giallo");
    strcpy(Casella[2263].Coordinate, "Wbianco1giallo");
    strcpy(Casella[2264].Coordinate, "Xbianco1giallo");
    strcpy(Casella[2265].Coordinate, "Ybianco1giallo");
    strcpy(Casella[2266].Coordinate, "Zbianco1giallo");
    strcpy(Casella[2267].Coordinate, "Arosso1giallo");
    strcpy(Casella[2268].Coordinate, "Brosso1giallo");
    strcpy(Casella[2269].Coordinate, "Crosso1giallo");
    strcpy(Casella[2270].Coordinate, "Drosso1giallo");
    strcpy(Casella[2271].Coordinate, "Erosso1giallo");
    strcpy(Casella[2272].Coordinate, "Frosso1giallo");
    strcpy(Casella[2273].Coordinate, "Grosso1giallo");
    strcpy(Casella[2274].Coordinate, "Hrosso1giallo");
    strcpy(Casella[2275].Coordinate, "Irosso1giallo");
    strcpy(Casella[2276].Coordinate, "Jrosso1giallo");
    strcpy(Casella[2277].Coordinate, "Krosso1giallo");
    strcpy(Casella[2278].Coordinate, "Lrosso1giallo");
    strcpy(Casella[2279].Coordinate, "Mrosso1giallo");
    strcpy(Casella[2280].Coordinate, "Nrosso1giallo");
    strcpy(Casella[2281].Coordinate, "Orosso1giallo");
    strcpy(Casella[2282].Coordinate, "Prosso1giallo");
    strcpy(Casella[2283].Coordinate, "Qrosso1giallo");
    strcpy(Casella[2284].Coordinate, "Rrosso1giallo");
    strcpy(Casella[2285].Coordinate, "Srosso1giallo");
    strcpy(Casella[2286].Coordinate, "Trosso1giallo");
    strcpy(Casella[2287].Coordinate, "Urosso1giallo");
    strcpy(Casella[2288].Coordinate, "Vrosso1giallo");
    strcpy(Casella[2289].Coordinate, "Wrosso1giallo");
    strcpy(Casella[2290].Coordinate, "Xrosso1giallo");
    strcpy(Casella[2291].Coordinate, "Yrosso1giallo");
    strcpy(Casella[2292].Coordinate, "Zrosso1giallo");
    strcpy(Casella[2293].Coordinate, "Aazzurro1giallo");
    strcpy(Casella[2294].Coordinate, "Bazzurro1giallo");
    strcpy(Casella[2295].Coordinate, "Cazzurro1giallo");
    strcpy(Casella[2296].Coordinate, "Dazzurro1giallo");
    strcpy(Casella[2297].Coordinate, "Eazzurro1giallo");
    strcpy(Casella[2298].Coordinate, "Fazzurro1giallo");
    strcpy(Casella[2299].Coordinate, "Gazzurro1giallo");
    strcpy(Casella[2300].Coordinate, "Hazzurro1giallo");
    strcpy(Casella[2301].Coordinate, "Iazzurro1giallo");
    strcpy(Casella[2302].Coordinate, "Jazzurro1giallo");
    strcpy(Casella[2303].Coordinate, "Kazzurro1giallo");
    strcpy(Casella[2304].Coordinate, "Lazzurro1giallo");
    strcpy(Casella[2305].Coordinate, "Mazzurro1giallo");
    strcpy(Casella[2306].Coordinate, "Nazzurro1giallo");
    strcpy(Casella[2307].Coordinate, "Oazzurro1giallo");
    strcpy(Casella[2308].Coordinate, "Pazzurro1giallo");
    strcpy(Casella[2309].Coordinate, "Qazzurro1giallo");
    strcpy(Casella[2310].Coordinate, "Razzurro1giallo");
    strcpy(Casella[2311].Coordinate, "Sazzurro1giallo");
    strcpy(Casella[2312].Coordinate, "Tazzurro1giallo");
    strcpy(Casella[2313].Coordinate, "Uazzurro1giallo");
    strcpy(Casella[2314].Coordinate, "Vazzurro1giallo");
    strcpy(Casella[2315].Coordinate, "Wazzurro1giallo");
    strcpy(Casella[2316].Coordinate, "Xazzurro1giallo");
    strcpy(Casella[2317].Coordinate, "Yazzurro1giallo");
    strcpy(Casella[2318].Coordinate, "Zazzurro1giallo");
    strcpy(Casella[2319].Coordinate, "Agiallo1giallo");
    strcpy(Casella[2320].Coordinate, "Bgiallo1giallo");
    strcpy(Casella[2321].Coordinate, "Cgiallo1giallo");
    strcpy(Casella[2322].Coordinate, "Dgiallo1giallo");
    strcpy(Casella[2323].Coordinate, "Egiallo1giallo");
    strcpy(Casella[2324].Coordinate, "Abianco2giallo");
    strcpy(Casella[2325].Coordinate, "Bbianco2giallo");
    strcpy(Casella[2326].Coordinate, "Cbianco2giallo");
    strcpy(Casella[2327].Coordinate, "Dbianco2giallo");
    strcpy(Casella[2328].Coordinate, "Ebianco2giallo");
    strcpy(Casella[2329].Coordinate, "Fbianco2giallo");
    strcpy(Casella[2330].Coordinate, "Gbianco2giallo");
    strcpy(Casella[2331].Coordinate, "Hbianco2giallo");
    strcpy(Casella[2332].Coordinate, "Ibianco2giallo");
    strcpy(Casella[2333].Coordinate, "Jbianco2giallo");
    strcpy(Casella[2334].Coordinate, "Kbianco2giallo");
    strcpy(Casella[2335].Coordinate, "Lbianco2giallo");
    strcpy(Casella[2336].Coordinate, "Mbianco2giallo");
    strcpy(Casella[2337].Coordinate, "Nbianco2giallo");
    strcpy(Casella[2338].Coordinate, "Obianco2giallo");
    strcpy(Casella[2339].Coordinate, "Pbianco2giallo");
    strcpy(Casella[2340].Coordinate, "Qbianco2giallo");
    strcpy(Casella[2341].Coordinate, "Rbianco2giallo");
    strcpy(Casella[2342].Coordinate, "Sbianco2giallo");
    strcpy(Casella[2343].Coordinate, "Tbianco2giallo");
    strcpy(Casella[2344].Coordinate, "Ubianco2giallo");
    strcpy(Casella[2345].Coordinate, "Vbianco2giallo");
    strcpy(Casella[2346].Coordinate, "Wbianco2giallo");
    strcpy(Casella[2347].Coordinate, "Xbianco2giallo");
    strcpy(Casella[2348].Coordinate, "Ybianco2giallo");
    strcpy(Casella[2349].Coordinate, "Zbianco2giallo");
    strcpy(Casella[2350].Coordinate, "Arosso2giallo");
    strcpy(Casella[2351].Coordinate, "Brosso2giallo");
    strcpy(Casella[2352].Coordinate, "Crosso2giallo");
    strcpy(Casella[2353].Coordinate, "Drosso2giallo");
    strcpy(Casella[2354].Coordinate, "Erosso2giallo");
    strcpy(Casella[2355].Coordinate, "Frosso2giallo");
    strcpy(Casella[2356].Coordinate, "Grosso2giallo");
    strcpy(Casella[2357].Coordinate, "Hrosso2giallo");
    strcpy(Casella[2358].Coordinate, "Irosso2giallo");
    strcpy(Casella[2359].Coordinate, "Jrosso2giallo");
    strcpy(Casella[2360].Coordinate, "Krosso2giallo");
    strcpy(Casella[2361].Coordinate, "Lrosso2giallo");
    strcpy(Casella[2362].Coordinate, "Mrosso2giallo");
    strcpy(Casella[2363].Coordinate, "Nrosso2giallo");
    strcpy(Casella[2364].Coordinate, "Orosso2giallo");
    strcpy(Casella[2365].Coordinate, "Prosso2giallo");
    strcpy(Casella[2366].Coordinate, "Qrosso2giallo");
    strcpy(Casella[2367].Coordinate, "Rrosso2giallo");
    strcpy(Casella[2368].Coordinate, "Srosso2giallo");
    strcpy(Casella[2369].Coordinate, "Trosso2giallo");
    strcpy(Casella[2370].Coordinate, "Urosso2giallo");
    strcpy(Casella[2371].Coordinate, "Vrosso2giallo");
    strcpy(Casella[2372].Coordinate, "Wrosso2giallo");
    strcpy(Casella[2373].Coordinate, "Xrosso2giallo");
    strcpy(Casella[2374].Coordinate, "Yrosso2giallo");
    strcpy(Casella[2375].Coordinate, "Zrosso2giallo");
    strcpy(Casella[2376].Coordinate, "Aazzurro2giallo");
    strcpy(Casella[2377].Coordinate, "Bazzurro2giallo");
    strcpy(Casella[2378].Coordinate, "Cazzurro2giallo");
    strcpy(Casella[2379].Coordinate, "Dazzurro2giallo");
    strcpy(Casella[2380].Coordinate, "Eazzurro2giallo");
    strcpy(Casella[2381].Coordinate, "Fazzurro2giallo");
    strcpy(Casella[2382].Coordinate, "Gazzurro2giallo");
    strcpy(Casella[2383].Coordinate, "Hazzurro2giallo");
    strcpy(Casella[2384].Coordinate, "Iazzurro2giallo");
    strcpy(Casella[2385].Coordinate, "Jazzurro2giallo");
    strcpy(Casella[2386].Coordinate, "Kazzurro2giallo");
    strcpy(Casella[2387].Coordinate, "Lazzurro2giallo");
    strcpy(Casella[2388].Coordinate, "Mazzurro2giallo");
    strcpy(Casella[2389].Coordinate, "Nazzurro2giallo");
    strcpy(Casella[2390].Coordinate, "Oazzurro2giallo");
    strcpy(Casella[2391].Coordinate, "Pazzurro2giallo");
    strcpy(Casella[2392].Coordinate, "Qazzurro2giallo");
    strcpy(Casella[2393].Coordinate, "Razzurro2giallo");
    strcpy(Casella[2394].Coordinate, "Sazzurro2giallo");
    strcpy(Casella[2395].Coordinate, "Tazzurro2giallo");
    strcpy(Casella[2396].Coordinate, "Uazzurro2giallo");
    strcpy(Casella[2397].Coordinate, "Vazzurro2giallo");
    strcpy(Casella[2398].Coordinate, "Wazzurro2giallo");
    strcpy(Casella[2399].Coordinate, "Xazzurro2giallo");
    strcpy(Casella[2400].Coordinate, "Yazzurro2giallo");
    strcpy(Casella[2401].Coordinate, "Zazzurro2giallo");
    strcpy(Casella[2402].Coordinate, "Agiallo2giallo");
    strcpy(Casella[2403].Coordinate, "Bgiallo2giallo");
    strcpy(Casella[2404].Coordinate, "Cgiallo2giallo");
    strcpy(Casella[2405].Coordinate, "Dgiallo2giallo");
    strcpy(Casella[2406].Coordinate, "Egiallo2giallo");
    strcpy(Casella[2407].Coordinate, "Abianco3giallo");
    strcpy(Casella[2408].Coordinate, "Bbianco3giallo");
    strcpy(Casella[2409].Coordinate, "Cbianco3giallo");
    strcpy(Casella[2410].Coordinate, "Dbianco3giallo");
    strcpy(Casella[2411].Coordinate, "Ebianco3giallo");
    strcpy(Casella[2412].Coordinate, "Fbianco3giallo");
    strcpy(Casella[2413].Coordinate, "Gbianco3giallo");
    strcpy(Casella[2414].Coordinate, "Hbianco3giallo");
    strcpy(Casella[2415].Coordinate, "Ibianco3giallo");
    strcpy(Casella[2416].Coordinate, "Jbianco3giallo");
    strcpy(Casella[2417].Coordinate, "Kbianco3giallo");
    strcpy(Casella[2418].Coordinate, "Lbianco3giallo");
    strcpy(Casella[2419].Coordinate, "Mbianco3giallo");
    strcpy(Casella[2420].Coordinate, "Nbianco3giallo");
    strcpy(Casella[2421].Coordinate, "Obianco3giallo");
    strcpy(Casella[2422].Coordinate, "Pbianco3giallo");
    strcpy(Casella[2423].Coordinate, "Qbianco3giallo");
    strcpy(Casella[2424].Coordinate, "Rbianco3giallo");
    strcpy(Casella[2425].Coordinate, "Sbianco3giallo");
    strcpy(Casella[2426].Coordinate, "Tbianco3giallo");
    strcpy(Casella[2427].Coordinate, "Ubianco3giallo");
    strcpy(Casella[2428].Coordinate, "Vbianco3giallo");
    strcpy(Casella[2429].Coordinate, "Wbianco3giallo");
    strcpy(Casella[2430].Coordinate, "Xbianco3giallo");
    strcpy(Casella[2431].Coordinate, "Ybianco3giallo");
    strcpy(Casella[2432].Coordinate, "Zbianco3giallo");
    strcpy(Casella[2433].Coordinate, "Arosso3giallo");
    strcpy(Casella[2434].Coordinate, "Brosso3giallo");
    strcpy(Casella[2435].Coordinate, "Crosso3giallo");
    strcpy(Casella[2436].Coordinate, "Drosso3giallo");
    strcpy(Casella[2437].Coordinate, "Erosso3giallo");
    strcpy(Casella[2438].Coordinate, "Frosso3giallo");
    strcpy(Casella[2439].Coordinate, "Grosso3giallo");
    strcpy(Casella[2440].Coordinate, "Hrosso3giallo");
    strcpy(Casella[2441].Coordinate, "Irosso3giallo");
    strcpy(Casella[2442].Coordinate, "Jrosso3giallo");
    strcpy(Casella[2443].Coordinate, "Krosso3giallo");
    strcpy(Casella[2444].Coordinate, "Lrosso3giallo");
    strcpy(Casella[2445].Coordinate, "Mrosso3giallo");
    strcpy(Casella[2446].Coordinate, "Nrosso3giallo");
    strcpy(Casella[2447].Coordinate, "Orosso3giallo");
    strcpy(Casella[2448].Coordinate, "Prosso3giallo");
    strcpy(Casella[2449].Coordinate, "Qrosso3giallo");
    strcpy(Casella[2450].Coordinate, "Rrosso3giallo");
    strcpy(Casella[2451].Coordinate, "Srosso3giallo");
    strcpy(Casella[2452].Coordinate, "Trosso3giallo");
    strcpy(Casella[2453].Coordinate, "Urosso3giallo");
    strcpy(Casella[2454].Coordinate, "Vrosso3giallo");
    strcpy(Casella[2455].Coordinate, "Wrosso3giallo");
    strcpy(Casella[2456].Coordinate, "Xrosso3giallo");
    strcpy(Casella[2457].Coordinate, "Yrosso3giallo");
    strcpy(Casella[2458].Coordinate, "Zrosso3giallo");
    strcpy(Casella[2459].Coordinate, "Aazzurro3giallo");
    strcpy(Casella[2460].Coordinate, "Bazzurro3giallo");
    strcpy(Casella[2461].Coordinate, "Cazzurro3giallo");
    strcpy(Casella[2462].Coordinate, "Dazzurro3giallo");
    strcpy(Casella[2463].Coordinate, "Eazzurro3giallo");
    strcpy(Casella[2464].Coordinate, "Fazzurro3giallo");
    strcpy(Casella[2465].Coordinate, "Gazzurro3giallo");
    strcpy(Casella[2466].Coordinate, "Hazzurro3giallo");
    strcpy(Casella[2467].Coordinate, "Iazzurro3giallo");
    strcpy(Casella[2468].Coordinate, "Jazzurro3giallo");
    strcpy(Casella[2469].Coordinate, "Kazzurro3giallo");
    strcpy(Casella[2470].Coordinate, "Lazzurro3giallo");
    strcpy(Casella[2471].Coordinate, "Mazzurro3giallo");
    strcpy(Casella[2472].Coordinate, "Nazzurro3giallo");
    strcpy(Casella[2473].Coordinate, "Oazzurro3giallo");
    strcpy(Casella[2474].Coordinate, "Pazzurro3giallo");
    strcpy(Casella[2475].Coordinate, "Qazzurro3giallo");
    strcpy(Casella[2476].Coordinate, "Razzurro3giallo");
    strcpy(Casella[2477].Coordinate, "Sazzurro3giallo");
    strcpy(Casella[2478].Coordinate, "Tazzurro3giallo");
    strcpy(Casella[2479].Coordinate, "Uazzurro3giallo");
    strcpy(Casella[2480].Coordinate, "Vazzurro3giallo");
    strcpy(Casella[2481].Coordinate, "Wazzurro3giallo");
    strcpy(Casella[2482].Coordinate, "Xazzurro3giallo");
    strcpy(Casella[2483].Coordinate, "Yazzurro3giallo");
    strcpy(Casella[2484].Coordinate, "Zazzurro3giallo");
    strcpy(Casella[2485].Coordinate, "Agiallo3giallo");
    strcpy(Casella[2486].Coordinate, "Bgiallo3giallo");
    strcpy(Casella[2487].Coordinate, "Cgiallo3giallo");
    strcpy(Casella[2488].Coordinate, "Dgiallo3giallo");
    strcpy(Casella[2489].Coordinate, "Egiallo3giallo");
    strcpy(Casella[2490].Coordinate, "Abianco4giallo");
    strcpy(Casella[2491].Coordinate, "Bbianco4giallo");
    strcpy(Casella[2492].Coordinate, "Cbianco4giallo");
    strcpy(Casella[2493].Coordinate, "Dbianco4giallo");
    strcpy(Casella[2494].Coordinate, "Ebianco4giallo");
    strcpy(Casella[2495].Coordinate, "Fbianco4giallo");
    strcpy(Casella[2496].Coordinate, "Gbianco4giallo");
    strcpy(Casella[2497].Coordinate, "Hbianco4giallo");
    strcpy(Casella[2498].Coordinate, "Ibianco4giallo");
    strcpy(Casella[2499].Coordinate, "Jbianco4giallo");
    strcpy(Casella[2500].Coordinate, "Kbianco4giallo");
    strcpy(Casella[2501].Coordinate, "Lbianco4giallo");
    strcpy(Casella[2502].Coordinate, "Mbianco4giallo");
    strcpy(Casella[2503].Coordinate, "Nbianco4giallo");
    strcpy(Casella[2504].Coordinate, "Obianco4giallo");
    strcpy(Casella[2505].Coordinate, "Pbianco4giallo");
    strcpy(Casella[2506].Coordinate, "Qbianco4giallo");
    strcpy(Casella[2507].Coordinate, "Rbianco4giallo");
    strcpy(Casella[2508].Coordinate, "Sbianco4giallo");
    strcpy(Casella[2509].Coordinate, "Tbianco4giallo");
    strcpy(Casella[2510].Coordinate, "Ubianco4giallo");
    strcpy(Casella[2511].Coordinate, "Vbianco4giallo");
    strcpy(Casella[2512].Coordinate, "Wbianco4giallo");
    strcpy(Casella[2513].Coordinate, "Xbianco4giallo");
    strcpy(Casella[2514].Coordinate, "Ybianco4giallo");
    strcpy(Casella[2515].Coordinate, "Zbianco4giallo");
    strcpy(Casella[2516].Coordinate, "Arosso4giallo");
    strcpy(Casella[2517].Coordinate, "Brosso4giallo");
    strcpy(Casella[2518].Coordinate, "Crosso4giallo");
    strcpy(Casella[2519].Coordinate, "Drosso4giallo");
    strcpy(Casella[2520].Coordinate, "Erosso4giallo");
    strcpy(Casella[2521].Coordinate, "Frosso4giallo");
    strcpy(Casella[2522].Coordinate, "Grosso4giallo");
    strcpy(Casella[2523].Coordinate, "Hrosso4giallo");
    strcpy(Casella[2524].Coordinate, "Irosso4giallo");
    strcpy(Casella[2525].Coordinate, "Jrosso4giallo");
    strcpy(Casella[2526].Coordinate, "Krosso4giallo");
    strcpy(Casella[2527].Coordinate, "Lrosso4giallo");
    strcpy(Casella[2528].Coordinate, "Mrosso4giallo");
    strcpy(Casella[2529].Coordinate, "Nrosso4giallo");
    strcpy(Casella[2530].Coordinate, "Orosso4giallo");
    strcpy(Casella[2531].Coordinate, "Prosso4giallo");
    strcpy(Casella[2532].Coordinate, "Qrosso4giallo");
    strcpy(Casella[2533].Coordinate, "Rrosso4giallo");
    strcpy(Casella[2534].Coordinate, "Srosso4giallo");
    strcpy(Casella[2535].Coordinate, "Trosso4giallo");
    strcpy(Casella[2536].Coordinate, "Urosso4giallo");
    strcpy(Casella[2537].Coordinate, "Vrosso4giallo");
    strcpy(Casella[2538].Coordinate, "Wrosso4giallo");
    strcpy(Casella[2539].Coordinate, "Xrosso4giallo");
    strcpy(Casella[2540].Coordinate, "Yrosso4giallo");
    strcpy(Casella[2541].Coordinate, "Zrosso4giallo");
    strcpy(Casella[2542].Coordinate, "Aazzurro4giallo");
    strcpy(Casella[2543].Coordinate, "Bazzurro4giallo");
    strcpy(Casella[2544].Coordinate, "Cazzurro4giallo");
    strcpy(Casella[2545].Coordinate, "Dazzurro4giallo");
    strcpy(Casella[2546].Coordinate, "Eazzurro4giallo");
    strcpy(Casella[2547].Coordinate, "Fazzurro4giallo");
    strcpy(Casella[2548].Coordinate, "Gazzurro4giallo");
    strcpy(Casella[2549].Coordinate, "Hazzurro4giallo");
    strcpy(Casella[2550].Coordinate, "Iazzurro4giallo");
    strcpy(Casella[2551].Coordinate, "Jazzurro4giallo");
    strcpy(Casella[2552].Coordinate, "Kazzurro4giallo");
    strcpy(Casella[2553].Coordinate, "Lazzurro4giallo");
    strcpy(Casella[2554].Coordinate, "Mazzurro4giallo");
    strcpy(Casella[2555].Coordinate, "Nazzurro4giallo");
    strcpy(Casella[2556].Coordinate, "Oazzurro4giallo");
    strcpy(Casella[2557].Coordinate, "Pazzurro4giallo");
    strcpy(Casella[2558].Coordinate, "Qazzurro4giallo");
    strcpy(Casella[2559].Coordinate, "Razzurro4giallo");
    strcpy(Casella[2560].Coordinate, "Sazzurro4giallo");
    strcpy(Casella[2561].Coordinate, "Tazzurro4giallo");
    strcpy(Casella[2562].Coordinate, "Uazzurro4giallo");
    strcpy(Casella[2563].Coordinate, "Vazzurro4giallo");
    strcpy(Casella[2564].Coordinate, "Wazzurro4giallo");
    strcpy(Casella[2565].Coordinate, "Xazzurro4giallo");
    strcpy(Casella[2566].Coordinate, "Yazzurro4giallo");
    strcpy(Casella[2567].Coordinate, "Zazzurro4giallo");
    strcpy(Casella[2568].Coordinate, "Agiallo4giallo");
    strcpy(Casella[2569].Coordinate, "Bgiallo4giallo");
    strcpy(Casella[2570].Coordinate, "Cgiallo4giallo");
    strcpy(Casella[2571].Coordinate, "Dgiallo4giallo");
    strcpy(Casella[2572].Coordinate, "Egiallo4giallo");
    strcpy(Casella[2573].Coordinate, "Abianco5giallo");
    strcpy(Casella[2574].Coordinate, "Bbianco5giallo");
    strcpy(Casella[2575].Coordinate, "Cbianco5giallo");
    strcpy(Casella[2576].Coordinate, "Dbianco5giallo");
    strcpy(Casella[2577].Coordinate, "Ebianco5giallo");
    strcpy(Casella[2578].Coordinate, "Fbianco5giallo");
    strcpy(Casella[2579].Coordinate, "Gbianco5giallo");
    strcpy(Casella[2580].Coordinate, "Hbianco5giallo");
    strcpy(Casella[2581].Coordinate, "Ibianco5giallo");
    strcpy(Casella[2582].Coordinate, "Jbianco5giallo");
    strcpy(Casella[2583].Coordinate, "Kbianco5giallo");
    strcpy(Casella[2584].Coordinate, "Lbianco5giallo");
    strcpy(Casella[2585].Coordinate, "Mbianco5giallo");
    strcpy(Casella[2586].Coordinate, "Nbianco5giallo");
    strcpy(Casella[2587].Coordinate, "Obianco5giallo");
    strcpy(Casella[2588].Coordinate, "Pbianco5giallo");
    strcpy(Casella[2589].Coordinate, "Qbianco5giallo");
    strcpy(Casella[2590].Coordinate, "Rbianco5giallo");
    strcpy(Casella[2591].Coordinate, "Sbianco5giallo");
    strcpy(Casella[2592].Coordinate, "Tbianco5giallo");
    strcpy(Casella[2593].Coordinate, "Ubianco5giallo");
    strcpy(Casella[2594].Coordinate, "Vbianco5giallo");
    strcpy(Casella[2595].Coordinate, "Wbianco5giallo");
    strcpy(Casella[2596].Coordinate, "Xbianco5giallo");
    strcpy(Casella[2597].Coordinate, "Ybianco5giallo");
    strcpy(Casella[2598].Coordinate, "Zbianco5giallo");
    strcpy(Casella[2599].Coordinate, "Arosso5giallo");
    strcpy(Casella[2600].Coordinate, "Brosso5giallo");
    strcpy(Casella[2601].Coordinate, "Crosso5giallo");
    strcpy(Casella[2602].Coordinate, "Drosso5giallo");
    strcpy(Casella[2603].Coordinate, "Erosso5giallo");
    strcpy(Casella[2604].Coordinate, "Frosso5giallo");
    strcpy(Casella[2605].Coordinate, "Grosso5giallo");
    strcpy(Casella[2606].Coordinate, "Hrosso5giallo");
    strcpy(Casella[2607].Coordinate, "Irosso5giallo");
    strcpy(Casella[2608].Coordinate, "Jrosso5giallo");
    strcpy(Casella[2609].Coordinate, "Krosso5giallo");
    strcpy(Casella[2610].Coordinate, "Lrosso5giallo");
    strcpy(Casella[2611].Coordinate, "Mrosso5giallo");
    strcpy(Casella[2612].Coordinate, "Nrosso5giallo");
    strcpy(Casella[2613].Coordinate, "Orosso5giallo");
    strcpy(Casella[2614].Coordinate, "Prosso5giallo");
    strcpy(Casella[2615].Coordinate, "Qrosso5giallo");
    strcpy(Casella[2616].Coordinate, "Rrosso5giallo");
    strcpy(Casella[2617].Coordinate, "Srosso5giallo");
    strcpy(Casella[2618].Coordinate, "Trosso5giallo");
    strcpy(Casella[2619].Coordinate, "Urosso5giallo");
    strcpy(Casella[2620].Coordinate, "Vrosso5giallo");
    strcpy(Casella[2621].Coordinate, "Wrosso5giallo");
    strcpy(Casella[2622].Coordinate, "Xrosso5giallo");
    strcpy(Casella[2623].Coordinate, "Yrosso5giallo");
    strcpy(Casella[2624].Coordinate, "Zrosso5giallo");
    strcpy(Casella[2625].Coordinate, "Aazzurro5giallo");
    strcpy(Casella[2626].Coordinate, "Bazzurro5giallo");
    strcpy(Casella[2627].Coordinate, "Cazzurro5giallo");
    strcpy(Casella[2628].Coordinate, "Dazzurro5giallo");
    strcpy(Casella[2629].Coordinate, "Eazzurro5giallo");
    strcpy(Casella[2630].Coordinate, "Fazzurro5giallo");
    strcpy(Casella[2631].Coordinate, "Gazzurro5giallo");
    strcpy(Casella[2632].Coordinate, "Hazzurro5giallo");
    strcpy(Casella[2633].Coordinate, "Iazzurro5giallo");
    strcpy(Casella[2634].Coordinate, "Jazzurro5giallo");
    strcpy(Casella[2635].Coordinate, "Kazzurro5giallo");
    strcpy(Casella[2636].Coordinate, "Lazzurro5giallo");
    strcpy(Casella[2637].Coordinate, "Mazzurro5giallo");
    strcpy(Casella[2638].Coordinate, "Nazzurro5giallo");
    strcpy(Casella[2639].Coordinate, "Oazzurro5giallo");
    strcpy(Casella[2640].Coordinate, "Pazzurro5giallo");
    strcpy(Casella[2641].Coordinate, "Qazzurro5giallo");
    strcpy(Casella[2642].Coordinate, "Razzurro5giallo");
    strcpy(Casella[2643].Coordinate, "Sazzurro5giallo");
    strcpy(Casella[2644].Coordinate, "Tazzurro5giallo");
    strcpy(Casella[2645].Coordinate, "Uazzurro5giallo");
    strcpy(Casella[2646].Coordinate, "Vazzurro5giallo");
    strcpy(Casella[2647].Coordinate, "Wazzurro5giallo");
    strcpy(Casella[2648].Coordinate, "Xazzurro5giallo");
    strcpy(Casella[2649].Coordinate, "Yazzurro5giallo");
    strcpy(Casella[2650].Coordinate, "Zazzurro5giallo");
    strcpy(Casella[2651].Coordinate, "Agiallo5giallo");
    strcpy(Casella[2652].Coordinate, "Bgiallo5giallo");
    strcpy(Casella[2653].Coordinate, "Cgiallo5giallo");
    strcpy(Casella[2654].Coordinate, "Dgiallo5giallo");
    strcpy(Casella[2655].Coordinate, "Egiallo5giallo");
    strcpy(Casella[2656].Coordinate, "Abianco6giallo");
    strcpy(Casella[2657].Coordinate, "Bbianco6giallo");
    strcpy(Casella[2658].Coordinate, "Cbianco6giallo");
    strcpy(Casella[2659].Coordinate, "Dbianco6giallo");
    strcpy(Casella[2660].Coordinate, "Ebianco6giallo");
    strcpy(Casella[2661].Coordinate, "Fbianco6giallo");
    strcpy(Casella[2662].Coordinate, "Gbianco6giallo");
    strcpy(Casella[2663].Coordinate, "Hbianco6giallo");
    strcpy(Casella[2664].Coordinate, "Ibianco6giallo");
    strcpy(Casella[2665].Coordinate, "Jbianco6giallo");
    strcpy(Casella[2666].Coordinate, "Kbianco6giallo");
    strcpy(Casella[2667].Coordinate, "Lbianco6giallo");
    strcpy(Casella[2668].Coordinate, "Mbianco6giallo");
    strcpy(Casella[2669].Coordinate, "Nbianco6giallo");
    strcpy(Casella[2670].Coordinate, "Obianco6giallo");
    strcpy(Casella[2671].Coordinate, "Pbianco6giallo");
    strcpy(Casella[2672].Coordinate, "Qbianco6giallo");
    strcpy(Casella[2673].Coordinate, "Rbianco6giallo");
    strcpy(Casella[2674].Coordinate, "Sbianco6giallo");
    strcpy(Casella[2675].Coordinate, "Tbianco6giallo");
    strcpy(Casella[2676].Coordinate, "Ubianco6giallo");
    strcpy(Casella[2677].Coordinate, "Vbianco6giallo");
    strcpy(Casella[2678].Coordinate, "Wbianco6giallo");
    strcpy(Casella[2679].Coordinate, "Xbianco6giallo");
    strcpy(Casella[2680].Coordinate, "Ybianco6giallo");
    strcpy(Casella[2681].Coordinate, "Zbianco6giallo");
    strcpy(Casella[2682].Coordinate, "Arosso6giallo");
    strcpy(Casella[2683].Coordinate, "Brosso6giallo");
    strcpy(Casella[2684].Coordinate, "Crosso6giallo");
    strcpy(Casella[2685].Coordinate, "Drosso6giallo");
    strcpy(Casella[2686].Coordinate, "Erosso6giallo");
    strcpy(Casella[2687].Coordinate, "Frosso6giallo");
    strcpy(Casella[2688].Coordinate, "Grosso6giallo");
    strcpy(Casella[2689].Coordinate, "Hrosso6giallo");
    strcpy(Casella[2690].Coordinate, "Irosso6giallo");
    strcpy(Casella[2691].Coordinate, "Jrosso6giallo");
    strcpy(Casella[2692].Coordinate, "Krosso6giallo");
    strcpy(Casella[2693].Coordinate, "Lrosso6giallo");
    strcpy(Casella[2694].Coordinate, "Mrosso6giallo");
    strcpy(Casella[2695].Coordinate, "Nrosso6giallo");
    strcpy(Casella[2696].Coordinate, "Orosso6giallo");
    strcpy(Casella[2697].Coordinate, "Prosso6giallo");
    strcpy(Casella[2698].Coordinate, "Qrosso6giallo");
    strcpy(Casella[2699].Coordinate, "Rrosso6giallo");
    strcpy(Casella[2700].Coordinate, "Srosso6giallo");
    strcpy(Casella[2701].Coordinate, "Trosso6giallo");
    strcpy(Casella[2702].Coordinate, "Urosso6giallo");
    strcpy(Casella[2703].Coordinate, "Vrosso6giallo");
    strcpy(Casella[2704].Coordinate, "Wrosso6giallo");
    strcpy(Casella[2705].Coordinate, "Xrosso6giallo");
    strcpy(Casella[2706].Coordinate, "Yrosso6giallo");
    strcpy(Casella[2707].Coordinate, "Zrosso6giallo");
    strcpy(Casella[2708].Coordinate, "Aazzurro6giallo");
    strcpy(Casella[2709].Coordinate, "Bazzurro6giallo");
    strcpy(Casella[2710].Coordinate, "Cazzurro6giallo");
    strcpy(Casella[2711].Coordinate, "Dazzurro6giallo");
    strcpy(Casella[2712].Coordinate, "Eazzurro6giallo");
    strcpy(Casella[2713].Coordinate, "Fazzurro6giallo");
    strcpy(Casella[2714].Coordinate, "Gazzurro6giallo");
    strcpy(Casella[2715].Coordinate, "Hazzurro6giallo");
    strcpy(Casella[2716].Coordinate, "Iazzurro6giallo");
    strcpy(Casella[2717].Coordinate, "Jazzurro6giallo");
    strcpy(Casella[2718].Coordinate, "Kazzurro6giallo");
    strcpy(Casella[2719].Coordinate, "Lazzurro6giallo");
    strcpy(Casella[2720].Coordinate, "Mazzurro6giallo");
    strcpy(Casella[2721].Coordinate, "Nazzurro6giallo");
    strcpy(Casella[2722].Coordinate, "Oazzurro6giallo");
    strcpy(Casella[2723].Coordinate, "Pazzurro6giallo");
    strcpy(Casella[2724].Coordinate, "Qazzurro6giallo");
    strcpy(Casella[2725].Coordinate, "Razzurro6giallo");
    strcpy(Casella[2726].Coordinate, "Sazzurro6giallo");
    strcpy(Casella[2727].Coordinate, "Tazzurro6giallo");
    strcpy(Casella[2728].Coordinate, "Uazzurro6giallo");
    strcpy(Casella[2729].Coordinate, "Vazzurro6giallo");
    strcpy(Casella[2730].Coordinate, "Wazzurro6giallo");
    strcpy(Casella[2731].Coordinate, "Xazzurro6giallo");
    strcpy(Casella[2732].Coordinate, "Yazzurro6giallo");
    strcpy(Casella[2733].Coordinate, "Zazzurro6giallo");
    strcpy(Casella[2734].Coordinate, "Agiallo6giallo");
    strcpy(Casella[2735].Coordinate, "Bgiallo6giallo");
    strcpy(Casella[2736].Coordinate, "Cgiallo6giallo");
    strcpy(Casella[2737].Coordinate, "Dgiallo6giallo");
    strcpy(Casella[2738].Coordinate, "Egiallo6giallo");
    strcpy(Casella[2739].Coordinate, "Abianco7giallo");
    strcpy(Casella[2740].Coordinate, "Bbianco7giallo");
    strcpy(Casella[2741].Coordinate, "Cbianco7giallo");
    strcpy(Casella[2742].Coordinate, "Dbianco7giallo");
    strcpy(Casella[2743].Coordinate, "Ebianco7giallo");
    strcpy(Casella[2744].Coordinate, "Fbianco7giallo");
    strcpy(Casella[2745].Coordinate, "Gbianco7giallo");
    strcpy(Casella[2746].Coordinate, "Hbianco7giallo");
    strcpy(Casella[2747].Coordinate, "Ibianco7giallo");
    strcpy(Casella[2748].Coordinate, "Jbianco7giallo");
    strcpy(Casella[2749].Coordinate, "Kbianco7giallo");
    strcpy(Casella[2750].Coordinate, "Lbianco7giallo");
    strcpy(Casella[2751].Coordinate, "Mbianco7giallo");
    strcpy(Casella[2752].Coordinate, "Nbianco7giallo");
    strcpy(Casella[2753].Coordinate, "Obianco7giallo");
    strcpy(Casella[2754].Coordinate, "Pbianco7giallo");
    strcpy(Casella[2755].Coordinate, "Qbianco7giallo");
    strcpy(Casella[2756].Coordinate, "Rbianco7giallo");
    strcpy(Casella[2757].Coordinate, "Sbianco7giallo");
    strcpy(Casella[2758].Coordinate, "Tbianco7giallo");
    strcpy(Casella[2759].Coordinate, "Ubianco7giallo");
    strcpy(Casella[2760].Coordinate, "Vbianco7giallo");
    strcpy(Casella[2761].Coordinate, "Wbianco7giallo");
    strcpy(Casella[2762].Coordinate, "Xbianco7giallo");
    strcpy(Casella[2763].Coordinate, "Ybianco7giallo");
    strcpy(Casella[2764].Coordinate, "Zbianco7giallo");
    strcpy(Casella[2765].Coordinate, "Arosso7giallo");
    strcpy(Casella[2766].Coordinate, "Brosso7giallo");
    strcpy(Casella[2767].Coordinate, "Crosso7giallo");
    strcpy(Casella[2768].Coordinate, "Drosso7giallo");
    strcpy(Casella[2769].Coordinate, "Erosso7giallo");
    strcpy(Casella[2770].Coordinate, "Frosso7giallo");
    strcpy(Casella[2771].Coordinate, "Grosso7giallo");
    strcpy(Casella[2772].Coordinate, "Hrosso7giallo");
    strcpy(Casella[2773].Coordinate, "Irosso7giallo");
    strcpy(Casella[2774].Coordinate, "Jrosso7giallo");
    strcpy(Casella[2775].Coordinate, "Krosso7giallo");
    strcpy(Casella[2776].Coordinate, "Lrosso7giallo");
    strcpy(Casella[2777].Coordinate, "Mrosso7giallo");
    strcpy(Casella[2778].Coordinate, "Nrosso7giallo");
    strcpy(Casella[2779].Coordinate, "Orosso7giallo");
    strcpy(Casella[2780].Coordinate, "Prosso7giallo");
    strcpy(Casella[2781].Coordinate, "Qrosso7giallo");
    strcpy(Casella[2782].Coordinate, "Rrosso7giallo");
    strcpy(Casella[2783].Coordinate, "Srosso7giallo");
    strcpy(Casella[2784].Coordinate, "Trosso7giallo");
    strcpy(Casella[2785].Coordinate, "Urosso7giallo");
    strcpy(Casella[2786].Coordinate, "Vrosso7giallo");
    strcpy(Casella[2787].Coordinate, "Wrosso7giallo");
    strcpy(Casella[2788].Coordinate, "Xrosso7giallo");
    strcpy(Casella[2789].Coordinate, "Yrosso7giallo");
    strcpy(Casella[2790].Coordinate, "Zrosso7giallo");
    strcpy(Casella[2791].Coordinate, "Aazzurro7giallo");
    strcpy(Casella[2792].Coordinate, "Bazzurro7giallo");
    strcpy(Casella[2793].Coordinate, "Cazzurro7giallo");
    strcpy(Casella[2794].Coordinate, "Dazzurro7giallo");
    strcpy(Casella[2795].Coordinate, "Eazzurro7giallo");
    strcpy(Casella[2796].Coordinate, "Fazzurro7giallo");
    strcpy(Casella[2797].Coordinate, "Gazzurro7giallo");
    strcpy(Casella[2798].Coordinate, "Hazzurro7giallo");
    strcpy(Casella[2799].Coordinate, "Iazzurro7giallo");
    strcpy(Casella[2800].Coordinate, "Jazzurro7giallo");
    strcpy(Casella[2801].Coordinate, "Kazzurro7giallo");
    strcpy(Casella[2802].Coordinate, "Lazzurro7giallo");
    strcpy(Casella[2803].Coordinate, "Mazzurro7giallo");
    strcpy(Casella[2804].Coordinate, "Nazzurro7giallo");
    strcpy(Casella[2805].Coordinate, "Oazzurro7giallo");
    strcpy(Casella[2806].Coordinate, "Pazzurro7giallo");
    strcpy(Casella[2807].Coordinate, "Qazzurro7giallo");
    strcpy(Casella[2808].Coordinate, "Razzurro7giallo");
    strcpy(Casella[2809].Coordinate, "Sazzurro7giallo");
    strcpy(Casella[2810].Coordinate, "Tazzurro7giallo");
    strcpy(Casella[2811].Coordinate, "Uazzurro7giallo");
    strcpy(Casella[2812].Coordinate, "Vazzurro7giallo");
    strcpy(Casella[2813].Coordinate, "Wazzurro7giallo");
    strcpy(Casella[2814].Coordinate, "Xazzurro7giallo");
    strcpy(Casella[2815].Coordinate, "Yazzurro7giallo");
    strcpy(Casella[2816].Coordinate, "Zazzurro7giallo");
    strcpy(Casella[2817].Coordinate, "Agiallo7giallo");
    strcpy(Casella[2818].Coordinate, "Bgiallo7giallo");
    strcpy(Casella[2819].Coordinate, "Cgiallo7giallo");
    strcpy(Casella[2820].Coordinate, "Dgiallo7giallo");
    strcpy(Casella[2821].Coordinate, "Egiallo7giallo");
    strcpy(Casella[2822].Coordinate, "Abianco8giallo");
    strcpy(Casella[2823].Coordinate, "Bbianco8giallo");
    strcpy(Casella[2824].Coordinate, "Cbianco8giallo");
    strcpy(Casella[2825].Coordinate, "Dbianco8giallo");
    strcpy(Casella[2826].Coordinate, "Ebianco8giallo");
    strcpy(Casella[2827].Coordinate, "Fbianco8giallo");
    strcpy(Casella[2828].Coordinate, "Gbianco8giallo");
    strcpy(Casella[2829].Coordinate, "Hbianco8giallo");
    strcpy(Casella[2830].Coordinate, "Ibianco8giallo");
    strcpy(Casella[2831].Coordinate, "Jbianco8giallo");
    strcpy(Casella[2832].Coordinate, "Kbianco8giallo");
    strcpy(Casella[2833].Coordinate, "Lbianco8giallo");
    strcpy(Casella[2834].Coordinate, "Mbianco8giallo");
    strcpy(Casella[2835].Coordinate, "Nbianco8giallo");
    strcpy(Casella[2836].Coordinate, "Obianco8giallo");
    strcpy(Casella[2837].Coordinate, "Pbianco8giallo");
    strcpy(Casella[2838].Coordinate, "Qbianco8giallo");
    strcpy(Casella[2839].Coordinate, "Rbianco8giallo");
    strcpy(Casella[2840].Coordinate, "Sbianco8giallo");
    strcpy(Casella[2841].Coordinate, "Tbianco8giallo");
    strcpy(Casella[2842].Coordinate, "Ubianco8giallo");
    strcpy(Casella[2843].Coordinate, "Vbianco8giallo");
    strcpy(Casella[2844].Coordinate, "Wbianco8giallo");
    strcpy(Casella[2845].Coordinate, "Xbianco8giallo");
    strcpy(Casella[2846].Coordinate, "Ybianco8giallo");
    strcpy(Casella[2847].Coordinate, "Zbianco8giallo");
    strcpy(Casella[2848].Coordinate, "Arosso8giallo");
    strcpy(Casella[2849].Coordinate, "Brosso8giallo");
    strcpy(Casella[2850].Coordinate, "Crosso8giallo");
    strcpy(Casella[2851].Coordinate, "Drosso8giallo");
    strcpy(Casella[2852].Coordinate, "Erosso8giallo");
    strcpy(Casella[2853].Coordinate, "Frosso8giallo");
    strcpy(Casella[2854].Coordinate, "Grosso8giallo");
    strcpy(Casella[2855].Coordinate, "Hrosso8giallo");
    strcpy(Casella[2856].Coordinate, "Irosso8giallo");
    strcpy(Casella[2857].Coordinate, "Jrosso8giallo");
    strcpy(Casella[2858].Coordinate, "Krosso8giallo");
    strcpy(Casella[2859].Coordinate, "Lrosso8giallo");
    strcpy(Casella[2860].Coordinate, "Mrosso8giallo");
    strcpy(Casella[2861].Coordinate, "Nrosso8giallo");
    strcpy(Casella[2862].Coordinate, "Orosso8giallo");
    strcpy(Casella[2863].Coordinate, "Prosso8giallo");
    strcpy(Casella[2864].Coordinate, "Qrosso8giallo");
    strcpy(Casella[2865].Coordinate, "Rrosso8giallo");
    strcpy(Casella[2866].Coordinate, "Srosso8giallo");
    strcpy(Casella[2867].Coordinate, "Trosso8giallo");
    strcpy(Casella[2868].Coordinate, "Urosso8giallo");
    strcpy(Casella[2869].Coordinate, "Vrosso8giallo");
    strcpy(Casella[2870].Coordinate, "Wrosso8giallo");
    strcpy(Casella[2871].Coordinate, "Xrosso8giallo");
    strcpy(Casella[2872].Coordinate, "Yrosso8giallo");
    strcpy(Casella[2873].Coordinate, "Zrosso8giallo");
    strcpy(Casella[2874].Coordinate, "Aazzurro8giallo");
    strcpy(Casella[2875].Coordinate, "Bazzurro8giallo");
    strcpy(Casella[2876].Coordinate, "Cazzurro8giallo");
    strcpy(Casella[2877].Coordinate, "Dazzurro8giallo");
    strcpy(Casella[2878].Coordinate, "Eazzurro8giallo");
    strcpy(Casella[2879].Coordinate, "Fazzurro8giallo");
    strcpy(Casella[2880].Coordinate, "Gazzurro8giallo");
    strcpy(Casella[2881].Coordinate, "Hazzurro8giallo");
    strcpy(Casella[2882].Coordinate, "Iazzurro8giallo");
    strcpy(Casella[2883].Coordinate, "Jazzurro8giallo");
    strcpy(Casella[2884].Coordinate, "Kazzurro8giallo");
    strcpy(Casella[2885].Coordinate, "Lazzurro8giallo");
    strcpy(Casella[2886].Coordinate, "Mazzurro8giallo");
    strcpy(Casella[2887].Coordinate, "Nazzurro8giallo");
    strcpy(Casella[2888].Coordinate, "Oazzurro8giallo");
    strcpy(Casella[2889].Coordinate, "Pazzurro8giallo");
    strcpy(Casella[2890].Coordinate, "Qazzurro8giallo");
    strcpy(Casella[2891].Coordinate, "Razzurro8giallo");
    strcpy(Casella[2892].Coordinate, "Sazzurro8giallo");
    strcpy(Casella[2893].Coordinate, "Tazzurro8giallo");
    strcpy(Casella[2894].Coordinate, "Uazzurro8giallo");
    strcpy(Casella[2895].Coordinate, "Vazzurro8giallo");
    strcpy(Casella[2896].Coordinate, "Wazzurro8giallo");
    strcpy(Casella[2897].Coordinate, "Xazzurro8giallo");
    strcpy(Casella[2898].Coordinate, "Yazzurro8giallo");
    strcpy(Casella[2899].Coordinate, "Zazzurro8giallo");
    strcpy(Casella[2900].Coordinate, "Agiallo8giallo");
    strcpy(Casella[2901].Coordinate, "Bgiallo8giallo");
    strcpy(Casella[2902].Coordinate, "Cgiallo8giallo");
    strcpy(Casella[2903].Coordinate, "Dgiallo8giallo");
    strcpy(Casella[2904].Coordinate, "Egiallo8giallo");
    strcpy(Casella[2905].Coordinate, "Abianco9giallo");
    strcpy(Casella[2906].Coordinate, "Bbianco9giallo");
    strcpy(Casella[2907].Coordinate, "Cbianco9giallo");
    strcpy(Casella[2908].Coordinate, "Dbianco9giallo");
    strcpy(Casella[2909].Coordinate, "Ebianco9giallo");
    strcpy(Casella[2910].Coordinate, "Fbianco9giallo");
    strcpy(Casella[2911].Coordinate, "Gbianco9giallo");
    strcpy(Casella[2912].Coordinate, "Hbianco9giallo");
    strcpy(Casella[2913].Coordinate, "Ibianco9giallo");
    strcpy(Casella[2914].Coordinate, "Jbianco9giallo");
    strcpy(Casella[2915].Coordinate, "Kbianco9giallo");
    strcpy(Casella[2916].Coordinate, "Lbianco9giallo");
    strcpy(Casella[2917].Coordinate, "Mbianco9giallo");
    strcpy(Casella[2918].Coordinate, "Nbianco9giallo");
    strcpy(Casella[2919].Coordinate, "Obianco9giallo");
    strcpy(Casella[2920].Coordinate, "Pbianco9giallo");
    strcpy(Casella[2921].Coordinate, "Qbianco9giallo");
    strcpy(Casella[2922].Coordinate, "Rbianco9giallo");
    strcpy(Casella[2923].Coordinate, "Sbianco9giallo");
    strcpy(Casella[2924].Coordinate, "Tbianco9giallo");
    strcpy(Casella[2925].Coordinate, "Ubianco9giallo");
    strcpy(Casella[2926].Coordinate, "Vbianco9giallo");
    strcpy(Casella[2927].Coordinate, "Wbianco9giallo");
    strcpy(Casella[2928].Coordinate, "Xbianco9giallo");
    strcpy(Casella[2929].Coordinate, "Ybianco9giallo");
    strcpy(Casella[2930].Coordinate, "Zbianco9giallo");
    strcpy(Casella[2931].Coordinate, "Arosso9giallo");
    strcpy(Casella[2932].Coordinate, "Brosso9giallo");
    strcpy(Casella[2933].Coordinate, "Crosso9giallo");
    strcpy(Casella[2934].Coordinate, "Drosso9giallo");
    strcpy(Casella[2935].Coordinate, "Erosso9giallo");
    strcpy(Casella[2936].Coordinate, "Frosso9giallo");
    strcpy(Casella[2937].Coordinate, "Grosso9giallo");
    strcpy(Casella[2938].Coordinate, "Hrosso9giallo");
    strcpy(Casella[2939].Coordinate, "Irosso9giallo");
    strcpy(Casella[2940].Coordinate, "Jrosso9giallo");
    strcpy(Casella[2941].Coordinate, "Krosso9giallo");
    strcpy(Casella[2942].Coordinate, "Lrosso9giallo");
    strcpy(Casella[2943].Coordinate, "Mrosso9giallo");
    strcpy(Casella[2944].Coordinate, "Nrosso9giallo");
    strcpy(Casella[2945].Coordinate, "Orosso9giallo");
    strcpy(Casella[2946].Coordinate, "Prosso9giallo");
    strcpy(Casella[2947].Coordinate, "Qrosso9giallo");
    strcpy(Casella[2948].Coordinate, "Rrosso9giallo");
    strcpy(Casella[2949].Coordinate, "Srosso9giallo");
    strcpy(Casella[2950].Coordinate, "Trosso9giallo");
    strcpy(Casella[2951].Coordinate, "Urosso9giallo");
    strcpy(Casella[2952].Coordinate, "Vrosso9giallo");
    strcpy(Casella[2953].Coordinate, "Wrosso9giallo");
    strcpy(Casella[2954].Coordinate, "Xrosso9giallo");
    strcpy(Casella[2955].Coordinate, "Yrosso9giallo");
    strcpy(Casella[2956].Coordinate, "Zrosso9giallo");
    strcpy(Casella[2957].Coordinate, "Aazzurro9giallo");
    strcpy(Casella[2958].Coordinate, "Bazzurro9giallo");
    strcpy(Casella[2959].Coordinate, "Cazzurro9giallo");
    strcpy(Casella[2960].Coordinate, "Dazzurro9giallo");
    strcpy(Casella[2961].Coordinate, "Eazzurro9giallo");
    strcpy(Casella[2962].Coordinate, "Fazzurro9giallo");
    strcpy(Casella[2963].Coordinate, "Gazzurro9giallo");
    strcpy(Casella[2964].Coordinate, "Hazzurro9giallo");
    strcpy(Casella[2965].Coordinate, "Iazzurro9giallo");
    strcpy(Casella[2966].Coordinate, "Jazzurro9giallo");
    strcpy(Casella[2967].Coordinate, "Kazzurro9giallo");
    strcpy(Casella[2968].Coordinate, "Lazzurro9giallo");
    strcpy(Casella[2969].Coordinate, "Mazzurro9giallo");
    strcpy(Casella[2970].Coordinate, "Nazzurro9giallo");
    strcpy(Casella[2971].Coordinate, "Oazzurro9giallo");
    strcpy(Casella[2972].Coordinate, "Pazzurro9giallo");
    strcpy(Casella[2973].Coordinate, "Qazzurro9giallo");
    strcpy(Casella[2974].Coordinate, "Razzurro9giallo");
    strcpy(Casella[2975].Coordinate, "Sazzurro9giallo");
    strcpy(Casella[2976].Coordinate, "Tazzurro9giallo");
    strcpy(Casella[2977].Coordinate, "Uazzurro9giallo");
    strcpy(Casella[2978].Coordinate, "Vazzurro9giallo");
    strcpy(Casella[2979].Coordinate, "Wazzurro9giallo");
    strcpy(Casella[2980].Coordinate, "Xazzurro9giallo");
    strcpy(Casella[2981].Coordinate, "Yazzurro9giallo");
    strcpy(Casella[2982].Coordinate, "Zazzurro9giallo");
    strcpy(Casella[2983].Coordinate, "Agiallo9giallo");
    strcpy(Casella[2984].Coordinate, "Bgiallo9giallo");
    strcpy(Casella[2985].Coordinate, "Cgiallo9giallo");
    strcpy(Casella[2986].Coordinate, "Dgiallo9giallo");
    strcpy(Casella[2987].Coordinate, "Egiallo9giallo");
    strcpy(Casella[2988].Coordinate, "Abianco1verde");
    strcpy(Casella[2989].Coordinate, "Bbianco1verde");
    strcpy(Casella[2990].Coordinate, "Cbianco1verde");
    strcpy(Casella[2991].Coordinate, "Dbianco1verde");
    strcpy(Casella[2992].Coordinate, "Ebianco1verde");
    strcpy(Casella[2993].Coordinate, "Fbianco1verde");
    strcpy(Casella[2994].Coordinate, "Gbianco1verde");
    strcpy(Casella[2995].Coordinate, "Hbianco1verde");
    strcpy(Casella[2996].Coordinate, "Ibianco1verde");
    strcpy(Casella[2997].Coordinate, "Jbianco1verde");
    strcpy(Casella[2998].Coordinate, "Kbianco1verde");
    strcpy(Casella[2999].Coordinate, "Lbianco1verde");
    strcpy(Casella[3000].Coordinate, "Mbianco1verde");
    strcpy(Casella[3001].Coordinate, "Nbianco1verde");
    strcpy(Casella[3002].Coordinate, "Obianco1verde");
    strcpy(Casella[3003].Coordinate, "Pbianco1verde");
    strcpy(Casella[3004].Coordinate, "Qbianco1verde");
    strcpy(Casella[3005].Coordinate, "Rbianco1verde");
    strcpy(Casella[3006].Coordinate, "Sbianco1verde");
    strcpy(Casella[3007].Coordinate, "Tbianco1verde");
    strcpy(Casella[3008].Coordinate, "Ubianco1verde");
    strcpy(Casella[3009].Coordinate, "Vbianco1verde");
    strcpy(Casella[3010].Coordinate, "Wbianco1verde");
    strcpy(Casella[3011].Coordinate, "Xbianco1verde");
    strcpy(Casella[3012].Coordinate, "Ybianco1verde");
    strcpy(Casella[3013].Coordinate, "Zbianco1verde");
    strcpy(Casella[3014].Coordinate, "Arosso1verde");
    strcpy(Casella[3015].Coordinate, "Brosso1verde");
    strcpy(Casella[3016].Coordinate, "Crosso1verde");
    strcpy(Casella[3017].Coordinate, "Drosso1verde");
    strcpy(Casella[3018].Coordinate, "Erosso1verde");
    strcpy(Casella[3019].Coordinate, "Frosso1verde");
    strcpy(Casella[3020].Coordinate, "Grosso1verde");
    strcpy(Casella[3021].Coordinate, "Hrosso1verde");
    strcpy(Casella[3022].Coordinate, "Irosso1verde");
    strcpy(Casella[3023].Coordinate, "Jrosso1verde");
    strcpy(Casella[3024].Coordinate, "Krosso1verde");
    strcpy(Casella[3025].Coordinate, "Lrosso1verde");
    strcpy(Casella[3026].Coordinate, "Mrosso1verde");
    strcpy(Casella[3027].Coordinate, "Nrosso1verde");
    strcpy(Casella[3028].Coordinate, "Orosso1verde");
    strcpy(Casella[3029].Coordinate, "Prosso1verde");
    strcpy(Casella[3030].Coordinate, "Qrosso1verde");
    strcpy(Casella[3031].Coordinate, "Rrosso1verde");
    strcpy(Casella[3032].Coordinate, "Srosso1verde");
    strcpy(Casella[3033].Coordinate, "Trosso1verde");
    strcpy(Casella[3034].Coordinate, "Urosso1verde");
    strcpy(Casella[3035].Coordinate, "Vrosso1verde");
    strcpy(Casella[3036].Coordinate, "Wrosso1verde");
    strcpy(Casella[3037].Coordinate, "Xrosso1verde");
    strcpy(Casella[3038].Coordinate, "Yrosso1verde");
    strcpy(Casella[3039].Coordinate, "Zrosso1verde");
    strcpy(Casella[3040].Coordinate, "Aazzurro1verde");
    strcpy(Casella[3041].Coordinate, "Bazzurro1verde");
    strcpy(Casella[3042].Coordinate, "Cazzurro1verde");
    strcpy(Casella[3043].Coordinate, "Dazzurro1verde");
    strcpy(Casella[3044].Coordinate, "Eazzurro1verde");
    strcpy(Casella[3045].Coordinate, "Fazzurro1verde");
    strcpy(Casella[3046].Coordinate, "Gazzurro1verde");
    strcpy(Casella[3047].Coordinate, "Hazzurro1verde");
    strcpy(Casella[3048].Coordinate, "Iazzurro1verde");
    strcpy(Casella[3049].Coordinate, "Jazzurro1verde");
    strcpy(Casella[3050].Coordinate, "Kazzurro1verde");
    strcpy(Casella[3051].Coordinate, "Lazzurro1verde");
    strcpy(Casella[3052].Coordinate, "Mazzurro1verde");
    strcpy(Casella[3053].Coordinate, "Nazzurro1verde");
    strcpy(Casella[3054].Coordinate, "Oazzurro1verde");
    strcpy(Casella[3055].Coordinate, "Pazzurro1verde");
    strcpy(Casella[3056].Coordinate, "Qazzurro1verde");
    strcpy(Casella[3057].Coordinate, "Razzurro1verde");
    strcpy(Casella[3058].Coordinate, "Sazzurro1verde");
    strcpy(Casella[3059].Coordinate, "Tazzurro1verde");
    strcpy(Casella[3060].Coordinate, "Uazzurro1verde");
    strcpy(Casella[3061].Coordinate, "Vazzurro1verde");
    strcpy(Casella[3062].Coordinate, "Wazzurro1verde");
    strcpy(Casella[3063].Coordinate, "Xazzurro1verde");
    strcpy(Casella[3064].Coordinate, "Yazzurro1verde");
    strcpy(Casella[3065].Coordinate, "Zazzurro1verde");
    strcpy(Casella[3066].Coordinate, "Agiallo1verde");
    strcpy(Casella[3067].Coordinate, "Bgiallo1verde");
    strcpy(Casella[3068].Coordinate, "Cgiallo1verde");
    strcpy(Casella[3069].Coordinate, "Dgiallo1verde");
    strcpy(Casella[3070].Coordinate, "Egiallo1verde");
    strcpy(Casella[3071].Coordinate, "Abianco2verde");
    strcpy(Casella[3072].Coordinate, "Bbianco2verde");
    strcpy(Casella[3073].Coordinate, "Cbianco2verde");
    strcpy(Casella[3074].Coordinate, "Dbianco2verde");
    strcpy(Casella[3075].Coordinate, "Ebianco2verde");
    strcpy(Casella[3076].Coordinate, "Fbianco2verde");
    strcpy(Casella[3077].Coordinate, "Gbianco2verde");
    strcpy(Casella[3078].Coordinate, "Hbianco2verde");
    strcpy(Casella[3079].Coordinate, "Ibianco2verde");
    strcpy(Casella[3080].Coordinate, "Jbianco2verde");
    strcpy(Casella[3081].Coordinate, "Kbianco2verde");
    strcpy(Casella[3082].Coordinate, "Lbianco2verde");
    strcpy(Casella[3083].Coordinate, "Mbianco2verde");
    strcpy(Casella[3084].Coordinate, "Nbianco2verde");
    strcpy(Casella[3085].Coordinate, "Obianco2verde");
    strcpy(Casella[3086].Coordinate, "Pbianco2verde");
    strcpy(Casella[3087].Coordinate, "Qbianco2verde");
    strcpy(Casella[3088].Coordinate, "Rbianco2verde");
    strcpy(Casella[3089].Coordinate, "Sbianco2verde");
    strcpy(Casella[3090].Coordinate, "Tbianco2verde");
    strcpy(Casella[3091].Coordinate, "Ubianco2verde");
    strcpy(Casella[3092].Coordinate, "Vbianco2verde");
    strcpy(Casella[3093].Coordinate, "Wbianco2verde");
    strcpy(Casella[3094].Coordinate, "Xbianco2verde");
    strcpy(Casella[3095].Coordinate, "Ybianco2verde");
    strcpy(Casella[3096].Coordinate, "Zbianco2verde");
    strcpy(Casella[3097].Coordinate, "Arosso2verde");
    strcpy(Casella[3098].Coordinate, "Brosso2verde");
    strcpy(Casella[3099].Coordinate, "Crosso2verde");
    strcpy(Casella[3100].Coordinate, "Drosso2verde");
    strcpy(Casella[3101].Coordinate, "Erosso2verde");
    strcpy(Casella[3102].Coordinate, "Frosso2verde");
    strcpy(Casella[3103].Coordinate, "Grosso2verde");
    strcpy(Casella[3104].Coordinate, "Hrosso2verde");
    strcpy(Casella[3105].Coordinate, "Irosso2verde");
    strcpy(Casella[3106].Coordinate, "Jrosso2verde");
    strcpy(Casella[3107].Coordinate, "Krosso2verde");
    strcpy(Casella[3108].Coordinate, "Lrosso2verde");
    strcpy(Casella[3109].Coordinate, "Mrosso2verde");
    strcpy(Casella[3110].Coordinate, "Nrosso2verde");
    strcpy(Casella[3111].Coordinate, "Orosso2verde");
    strcpy(Casella[3112].Coordinate, "Prosso2verde");
    strcpy(Casella[3113].Coordinate, "Qrosso2verde");
    strcpy(Casella[3114].Coordinate, "Rrosso2verde");
    strcpy(Casella[3115].Coordinate, "Srosso2verde");
    strcpy(Casella[3116].Coordinate, "Trosso2verde");
    strcpy(Casella[3117].Coordinate, "Urosso2verde");
    strcpy(Casella[3118].Coordinate, "Vrosso2verde");
    strcpy(Casella[3119].Coordinate, "Wrosso2verde");
    strcpy(Casella[3120].Coordinate, "Xrosso2verde");
    strcpy(Casella[3121].Coordinate, "Yrosso2verde");
    strcpy(Casella[3122].Coordinate, "Zrosso2verde");
    strcpy(Casella[3123].Coordinate, "Aazzurro2verde");
    strcpy(Casella[3124].Coordinate, "Bazzurro2verde");
    strcpy(Casella[3125].Coordinate, "Cazzurro2verde");
    strcpy(Casella[3126].Coordinate, "Dazzurro2verde");
    strcpy(Casella[3127].Coordinate, "Eazzurro2verde");
    strcpy(Casella[3128].Coordinate, "Fazzurro2verde");
    strcpy(Casella[3129].Coordinate, "Gazzurro2verde");
    strcpy(Casella[3130].Coordinate, "Hazzurro2verde");
    strcpy(Casella[3131].Coordinate, "Iazzurro2verde");
    strcpy(Casella[3132].Coordinate, "Jazzurro2verde");
    strcpy(Casella[3133].Coordinate, "Kazzurro2verde");
    strcpy(Casella[3134].Coordinate, "Lazzurro2verde");
    strcpy(Casella[3135].Coordinate, "Mazzurro2verde");
    strcpy(Casella[3136].Coordinate, "Nazzurro2verde");
    strcpy(Casella[3137].Coordinate, "Oazzurro2verde");
    strcpy(Casella[3138].Coordinate, "Pazzurro2verde");
    strcpy(Casella[3139].Coordinate, "Qazzurro2verde");
    strcpy(Casella[3140].Coordinate, "Razzurro2verde");
    strcpy(Casella[3141].Coordinate, "Sazzurro2verde");
    strcpy(Casella[3142].Coordinate, "Tazzurro2verde");
    strcpy(Casella[3143].Coordinate, "Uazzurro2verde");
    strcpy(Casella[3144].Coordinate, "Vazzurro2verde");
    strcpy(Casella[3145].Coordinate, "Wazzurro2verde");
    strcpy(Casella[3146].Coordinate, "Xazzurro2verde");
    strcpy(Casella[3147].Coordinate, "Yazzurro2verde");
    strcpy(Casella[3148].Coordinate, "Zazzurro2verde");
    strcpy(Casella[3149].Coordinate, "Agiallo2verde");
    strcpy(Casella[3150].Coordinate, "Bgiallo2verde");
    strcpy(Casella[3151].Coordinate, "Cgiallo2verde");
    strcpy(Casella[3152].Coordinate, "Dgiallo2verde");
    strcpy(Casella[3153].Coordinate, "Egiallo2verde");
    strcpy(Casella[3154].Coordinate, "Abianco3verde");
    strcpy(Casella[3155].Coordinate, "Bbianco3verde");
    strcpy(Casella[3156].Coordinate, "Cbianco3verde");
    strcpy(Casella[3157].Coordinate, "Dbianco3verde");
    strcpy(Casella[3158].Coordinate, "Ebianco3verde");
    strcpy(Casella[3159].Coordinate, "Fbianco3verde");
    strcpy(Casella[3160].Coordinate, "Gbianco3verde");
    strcpy(Casella[3161].Coordinate, "Hbianco3verde");
    strcpy(Casella[3162].Coordinate, "Ibianco3verde");
    strcpy(Casella[3163].Coordinate, "Jbianco3verde");
    strcpy(Casella[3164].Coordinate, "Kbianco3verde");
    strcpy(Casella[3165].Coordinate, "Lbianco3verde");
    strcpy(Casella[3166].Coordinate, "Mbianco3verde");
    strcpy(Casella[3167].Coordinate, "Nbianco3verde");
    strcpy(Casella[3168].Coordinate, "Obianco3verde");
    strcpy(Casella[3169].Coordinate, "Pbianco3verde");
    strcpy(Casella[3170].Coordinate, "Qbianco3verde");
    strcpy(Casella[3171].Coordinate, "Rbianco3verde");
    strcpy(Casella[3172].Coordinate, "Sbianco3verde");
    strcpy(Casella[3173].Coordinate, "Tbianco3verde");
    strcpy(Casella[3174].Coordinate, "Ubianco3verde");
    strcpy(Casella[3175].Coordinate, "Vbianco3verde");
    strcpy(Casella[3176].Coordinate, "Wbianco3verde");
    strcpy(Casella[3177].Coordinate, "Xbianco3verde");
    strcpy(Casella[3178].Coordinate, "Ybianco3verde");
    strcpy(Casella[3179].Coordinate, "Zbianco3verde");
    strcpy(Casella[3180].Coordinate, "Arosso3verde");
    strcpy(Casella[3181].Coordinate, "Brosso3verde");
    strcpy(Casella[3182].Coordinate, "Crosso3verde");
    strcpy(Casella[3183].Coordinate, "Drosso3verde");
    strcpy(Casella[3184].Coordinate, "Erosso3verde");
    strcpy(Casella[3185].Coordinate, "Frosso3verde");
    strcpy(Casella[3186].Coordinate, "Grosso3verde");
    strcpy(Casella[3187].Coordinate, "Hrosso3verde");
    strcpy(Casella[3188].Coordinate, "Irosso3verde");
    strcpy(Casella[3189].Coordinate, "Jrosso3verde");
    strcpy(Casella[3190].Coordinate, "Krosso3verde");
    strcpy(Casella[3191].Coordinate, "Lrosso3verde");
    strcpy(Casella[3192].Coordinate, "Mrosso3verde");
    strcpy(Casella[3193].Coordinate, "Nrosso3verde");
    strcpy(Casella[3194].Coordinate, "Orosso3verde");
    strcpy(Casella[3195].Coordinate, "Prosso3verde");
    strcpy(Casella[3196].Coordinate, "Qrosso3verde");
    strcpy(Casella[3197].Coordinate, "Rrosso3verde");
    strcpy(Casella[3198].Coordinate, "Srosso3verde");
    strcpy(Casella[3199].Coordinate, "Trosso3verde");
    strcpy(Casella[3200].Coordinate, "Urosso3verde");
    strcpy(Casella[3201].Coordinate, "Vrosso3verde");
    strcpy(Casella[3202].Coordinate, "Wrosso3verde");
    strcpy(Casella[3203].Coordinate, "Xrosso3verde");
    strcpy(Casella[3204].Coordinate, "Yrosso3verde");
    strcpy(Casella[3205].Coordinate, "Zrosso3verde");
    strcpy(Casella[3206].Coordinate, "Aazzurro3verde");
    strcpy(Casella[3207].Coordinate, "Bazzurro3verde");
    strcpy(Casella[3208].Coordinate, "Cazzurro3verde");
    strcpy(Casella[3209].Coordinate, "Dazzurro3verde");
    strcpy(Casella[3210].Coordinate, "Eazzurro3verde");
    strcpy(Casella[3211].Coordinate, "Fazzurro3verde");
    strcpy(Casella[3212].Coordinate, "Gazzurro3verde");
    strcpy(Casella[3213].Coordinate, "Hazzurro3verde");
    strcpy(Casella[3214].Coordinate, "Iazzurro3verde");
    strcpy(Casella[3215].Coordinate, "Jazzurro3verde");
    strcpy(Casella[3216].Coordinate, "Kazzurro3verde");
    strcpy(Casella[3217].Coordinate, "Lazzurro3verde");
    strcpy(Casella[3218].Coordinate, "Mazzurro3verde");
    strcpy(Casella[3219].Coordinate, "Nazzurro3verde");
    strcpy(Casella[3220].Coordinate, "Oazzurro3verde");
    strcpy(Casella[3221].Coordinate, "Pazzurro3verde");
    strcpy(Casella[3222].Coordinate, "Qazzurro3verde");
    strcpy(Casella[3223].Coordinate, "Razzurro3verde");
    strcpy(Casella[3224].Coordinate, "Sazzurro3verde");
    strcpy(Casella[3225].Coordinate, "Tazzurro3verde");
    strcpy(Casella[3226].Coordinate, "Uazzurro3verde");
    strcpy(Casella[3227].Coordinate, "Vazzurro3verde");
    strcpy(Casella[3228].Coordinate, "Wazzurro3verde");
    strcpy(Casella[3229].Coordinate, "Xazzurro3verde");
    strcpy(Casella[3230].Coordinate, "Yazzurro3verde");
    strcpy(Casella[3231].Coordinate, "Zazzurro3verde");
    strcpy(Casella[3232].Coordinate, "Agiallo3verde");
    strcpy(Casella[3233].Coordinate, "Bgiallo3verde");
    strcpy(Casella[3234].Coordinate, "Cgiallo3verde");
    strcpy(Casella[3235].Coordinate, "Dgiallo3verde");
    strcpy(Casella[3236].Coordinate, "Egiallo3verde");
    strcpy(Casella[3237].Coordinate, "Abianco4verde");
    strcpy(Casella[3238].Coordinate, "Bbianco4verde");
    strcpy(Casella[3239].Coordinate, "Cbianco4verde");
    strcpy(Casella[3240].Coordinate, "Dbianco4verde");
    strcpy(Casella[3241].Coordinate, "Ebianco4verde");
    strcpy(Casella[3242].Coordinate, "Fbianco4verde");
    strcpy(Casella[3243].Coordinate, "Gbianco4verde");
    strcpy(Casella[3244].Coordinate, "Hbianco4verde");
    strcpy(Casella[3245].Coordinate, "Ibianco4verde");
    strcpy(Casella[3246].Coordinate, "Jbianco4verde");
    strcpy(Casella[3247].Coordinate, "Kbianco4verde");
    strcpy(Casella[3248].Coordinate, "Lbianco4verde");
    strcpy(Casella[3249].Coordinate, "Mbianco4verde");
    strcpy(Casella[3250].Coordinate, "Nbianco4verde");
    strcpy(Casella[3251].Coordinate, "Obianco4verde");
    strcpy(Casella[3252].Coordinate, "Pbianco4verde");
    strcpy(Casella[3253].Coordinate, "Qbianco4verde");
    strcpy(Casella[3254].Coordinate, "Rbianco4verde");
    strcpy(Casella[3255].Coordinate, "Sbianco4verde");
    strcpy(Casella[3256].Coordinate, "Tbianco4verde");
    strcpy(Casella[3257].Coordinate, "Ubianco4verde");
    strcpy(Casella[3258].Coordinate, "Vbianco4verde");
    strcpy(Casella[3259].Coordinate, "Wbianco4verde");
    strcpy(Casella[3260].Coordinate, "Xbianco4verde");
    strcpy(Casella[3261].Coordinate, "Ybianco4verde");
    strcpy(Casella[3262].Coordinate, "Zbianco4verde");
    strcpy(Casella[3263].Coordinate, "Arosso4verde");
    strcpy(Casella[3264].Coordinate, "Brosso4verde");
    strcpy(Casella[3265].Coordinate, "Crosso4verde");
    strcpy(Casella[3266].Coordinate, "Drosso4verde");
    strcpy(Casella[3267].Coordinate, "Erosso4verde");
    strcpy(Casella[3268].Coordinate, "Frosso4verde");
    strcpy(Casella[3269].Coordinate, "Grosso4verde");
    strcpy(Casella[3270].Coordinate, "Hrosso4verde");
    strcpy(Casella[3271].Coordinate, "Irosso4verde");
    strcpy(Casella[3272].Coordinate, "Jrosso4verde");
    strcpy(Casella[3273].Coordinate, "Krosso4verde");
    strcpy(Casella[3274].Coordinate, "Lrosso4verde");
    strcpy(Casella[3275].Coordinate, "Mrosso4verde");
    strcpy(Casella[3276].Coordinate, "Nrosso4verde");
    strcpy(Casella[3277].Coordinate, "Orosso4verde");
    strcpy(Casella[3278].Coordinate, "Prosso4verde");
    strcpy(Casella[3279].Coordinate, "Qrosso4verde");
    strcpy(Casella[3280].Coordinate, "Rrosso4verde");
    strcpy(Casella[3281].Coordinate, "Srosso4verde");
    strcpy(Casella[3282].Coordinate, "Trosso4verde");
    strcpy(Casella[3283].Coordinate, "Urosso4verde");
    strcpy(Casella[3284].Coordinate, "Vrosso4verde");
    strcpy(Casella[3285].Coordinate, "Wrosso4verde");
    strcpy(Casella[3286].Coordinate, "Xrosso4verde");
    strcpy(Casella[3287].Coordinate, "Yrosso4verde");
    strcpy(Casella[3288].Coordinate, "Zrosso4verde");
    strcpy(Casella[3289].Coordinate, "Aazzurro4verde");
    strcpy(Casella[3290].Coordinate, "Bazzurro4verde");
    strcpy(Casella[3291].Coordinate, "Cazzurro4verde");
    strcpy(Casella[3292].Coordinate, "Dazzurro4verde");
    strcpy(Casella[3293].Coordinate, "Eazzurro4verde");
    strcpy(Casella[3294].Coordinate, "Fazzurro4verde");
    strcpy(Casella[3295].Coordinate, "Gazzurro4verde");
    strcpy(Casella[3296].Coordinate, "Hazzurro4verde");
    strcpy(Casella[3297].Coordinate, "Iazzurro4verde");
    strcpy(Casella[3298].Coordinate, "Jazzurro4verde");
    strcpy(Casella[3299].Coordinate, "Kazzurro4verde");
    strcpy(Casella[3300].Coordinate, "Lazzurro4verde");
    strcpy(Casella[3301].Coordinate, "Mazzurro4verde");
    strcpy(Casella[3302].Coordinate, "Nazzurro4verde");
    strcpy(Casella[3303].Coordinate, "Oazzurro4verde");
    strcpy(Casella[3304].Coordinate, "Pazzurro4verde");
    strcpy(Casella[3305].Coordinate, "Qazzurro4verde");
    strcpy(Casella[3306].Coordinate, "Razzurro4verde");
    strcpy(Casella[3307].Coordinate, "Sazzurro4verde");
    strcpy(Casella[3308].Coordinate, "Tazzurro4verde");
    strcpy(Casella[3309].Coordinate, "Uazzurro4verde");
    strcpy(Casella[3310].Coordinate, "Vazzurro4verde");
    strcpy(Casella[3311].Coordinate, "Wazzurro4verde");
    strcpy(Casella[3312].Coordinate, "Xazzurro4verde");
    strcpy(Casella[3313].Coordinate, "Yazzurro4verde");
    strcpy(Casella[3314].Coordinate, "Zazzurro4verde");
    strcpy(Casella[3315].Coordinate, "Agiallo4verde");
    strcpy(Casella[3316].Coordinate, "Bgiallo4verde");
    strcpy(Casella[3317].Coordinate, "Cgiallo4verde");
    strcpy(Casella[3318].Coordinate, "Dgiallo4verde");
    strcpy(Casella[3319].Coordinate, "Egiallo4verde");
    strcpy(Casella[3320].Coordinate, "Abianco5verde");
    strcpy(Casella[3321].Coordinate, "Bbianco5verde");
    strcpy(Casella[3322].Coordinate, "Cbianco5verde");
    strcpy(Casella[3323].Coordinate, "Dbianco5verde");
    strcpy(Casella[3324].Coordinate, "Ebianco5verde");
    strcpy(Casella[3325].Coordinate, "Fbianco5verde");
    strcpy(Casella[3326].Coordinate, "Gbianco5verde");
    strcpy(Casella[3327].Coordinate, "Hbianco5verde");
    strcpy(Casella[3328].Coordinate, "Ibianco5verde");
    strcpy(Casella[3329].Coordinate, "Jbianco5verde");
    strcpy(Casella[3330].Coordinate, "Kbianco5verde");
    strcpy(Casella[3331].Coordinate, "Lbianco5verde");
    strcpy(Casella[3332].Coordinate, "Mbianco5verde");
    strcpy(Casella[3333].Coordinate, "Nbianco5verde");
    strcpy(Casella[3334].Coordinate, "Obianco5verde");
    strcpy(Casella[3335].Coordinate, "Pbianco5verde");
    strcpy(Casella[3336].Coordinate, "Qbianco5verde");
    strcpy(Casella[3337].Coordinate, "Rbianco5verde");
    strcpy(Casella[3338].Coordinate, "Sbianco5verde");
    strcpy(Casella[3339].Coordinate, "Tbianco5verde");
    strcpy(Casella[3340].Coordinate, "Ubianco5verde");
    strcpy(Casella[3341].Coordinate, "Vbianco5verde");
    strcpy(Casella[3342].Coordinate, "Wbianco5verde");
    strcpy(Casella[3343].Coordinate, "Xbianco5verde");
    strcpy(Casella[3344].Coordinate, "Ybianco5verde");
    strcpy(Casella[3345].Coordinate, "Zbianco5verde");
    strcpy(Casella[3346].Coordinate, "Arosso5verde");
    strcpy(Casella[3347].Coordinate, "Brosso5verde");
    strcpy(Casella[3348].Coordinate, "Crosso5verde");
    strcpy(Casella[3349].Coordinate, "Drosso5verde");
    strcpy(Casella[3350].Coordinate, "Erosso5verde");
    strcpy(Casella[3351].Coordinate, "Frosso5verde");
    strcpy(Casella[3352].Coordinate, "Grosso5verde");
    strcpy(Casella[3353].Coordinate, "Hrosso5verde");
    strcpy(Casella[3354].Coordinate, "Irosso5verde");
    strcpy(Casella[3355].Coordinate, "Jrosso5verde");
    strcpy(Casella[3356].Coordinate, "Krosso5verde");
    strcpy(Casella[3357].Coordinate, "Lrosso5verde");
    strcpy(Casella[3358].Coordinate, "Mrosso5verde");
    strcpy(Casella[3359].Coordinate, "Nrosso5verde");
    strcpy(Casella[3360].Coordinate, "Orosso5verde");
    strcpy(Casella[3361].Coordinate, "Prosso5verde");
    strcpy(Casella[3362].Coordinate, "Qrosso5verde");
    strcpy(Casella[3363].Coordinate, "Rrosso5verde");
    strcpy(Casella[3364].Coordinate, "Srosso5verde");
    strcpy(Casella[3365].Coordinate, "Trosso5verde");
    strcpy(Casella[3366].Coordinate, "Urosso5verde");
    strcpy(Casella[3367].Coordinate, "Vrosso5verde");
    strcpy(Casella[3368].Coordinate, "Wrosso5verde");
    strcpy(Casella[3369].Coordinate, "Xrosso5verde");
    strcpy(Casella[3370].Coordinate, "Yrosso5verde");
    strcpy(Casella[3371].Coordinate, "Zrosso5verde");
    strcpy(Casella[3372].Coordinate, "Aazzurro5verde");
    strcpy(Casella[3373].Coordinate, "Bazzurro5verde");
    strcpy(Casella[3374].Coordinate, "Cazzurro5verde");
    strcpy(Casella[3375].Coordinate, "Dazzurro5verde");
    strcpy(Casella[3376].Coordinate, "Eazzurro5verde");
    strcpy(Casella[3377].Coordinate, "Fazzurro5verde");
    strcpy(Casella[3378].Coordinate, "Gazzurro5verde");
    strcpy(Casella[3379].Coordinate, "Hazzurro5verde");
    strcpy(Casella[3380].Coordinate, "Iazzurro5verde");
    strcpy(Casella[3381].Coordinate, "Jazzurro5verde");
    strcpy(Casella[3382].Coordinate, "Kazzurro5verde");
    strcpy(Casella[3383].Coordinate, "Lazzurro5verde");
    strcpy(Casella[3384].Coordinate, "Mazzurro5verde");
    strcpy(Casella[3385].Coordinate, "Nazzurro5verde");
    strcpy(Casella[3386].Coordinate, "Oazzurro5verde");
    strcpy(Casella[3387].Coordinate, "Pazzurro5verde");
    strcpy(Casella[3388].Coordinate, "Qazzurro5verde");
    strcpy(Casella[3389].Coordinate, "Razzurro5verde");
    strcpy(Casella[3390].Coordinate, "Sazzurro5verde");
    strcpy(Casella[3391].Coordinate, "Tazzurro5verde");
    strcpy(Casella[3392].Coordinate, "Uazzurro5verde");
    strcpy(Casella[3393].Coordinate, "Vazzurro5verde");
    strcpy(Casella[3394].Coordinate, "Wazzurro5verde");
    strcpy(Casella[3395].Coordinate, "Xazzurro5verde");
    strcpy(Casella[3396].Coordinate, "Yazzurro5verde");
    strcpy(Casella[3397].Coordinate, "Zazzurro5verde");
    strcpy(Casella[3398].Coordinate, "Agiallo5verde");
    strcpy(Casella[3399].Coordinate, "Bgiallo5verde");
    strcpy(Casella[3400].Coordinate, "Cgiallo5verde");
    strcpy(Casella[3401].Coordinate, "Dgiallo5verde");
    strcpy(Casella[3402].Coordinate, "Egiallo5verde");
    strcpy(Casella[3403].Coordinate, "Abianco6verde");
    strcpy(Casella[3404].Coordinate, "Bbianco6verde");
    strcpy(Casella[3405].Coordinate, "Cbianco6verde");
    strcpy(Casella[3406].Coordinate, "Dbianco6verde");
    strcpy(Casella[3407].Coordinate, "Ebianco6verde");
    strcpy(Casella[3408].Coordinate, "Fbianco6verde");
    strcpy(Casella[3409].Coordinate, "Gbianco6verde");
    strcpy(Casella[3410].Coordinate, "Hbianco6verde");
    strcpy(Casella[3411].Coordinate, "Ibianco6verde");
    strcpy(Casella[3412].Coordinate, "Jbianco6verde");
    strcpy(Casella[3413].Coordinate, "Kbianco6verde");
    strcpy(Casella[3414].Coordinate, "Lbianco6verde");
    strcpy(Casella[3415].Coordinate, "Mbianco6verde");
    strcpy(Casella[3416].Coordinate, "Nbianco6verde");
    strcpy(Casella[3417].Coordinate, "Obianco6verde");
    strcpy(Casella[3418].Coordinate, "Pbianco6verde");
    strcpy(Casella[3419].Coordinate, "Qbianco6verde");
    strcpy(Casella[3420].Coordinate, "Rbianco6verde");
    strcpy(Casella[3421].Coordinate, "Sbianco6verde");
    strcpy(Casella[3422].Coordinate, "Tbianco6verde");
    strcpy(Casella[3423].Coordinate, "Ubianco6verde");
    strcpy(Casella[3424].Coordinate, "Vbianco6verde");
    strcpy(Casella[3425].Coordinate, "Wbianco6verde");
    strcpy(Casella[3426].Coordinate, "Xbianco6verde");
    strcpy(Casella[3427].Coordinate, "Ybianco6verde");
    strcpy(Casella[3428].Coordinate, "Zbianco6verde");
    strcpy(Casella[3429].Coordinate, "Arosso6verde");
    strcpy(Casella[3430].Coordinate, "Brosso6verde");
    strcpy(Casella[3431].Coordinate, "Crosso6verde");
    strcpy(Casella[3432].Coordinate, "Drosso6verde");
    strcpy(Casella[3433].Coordinate, "Erosso6verde");
    strcpy(Casella[3434].Coordinate, "Frosso6verde");
    strcpy(Casella[3435].Coordinate, "Grosso6verde");
    strcpy(Casella[3436].Coordinate, "Hrosso6verde");
    strcpy(Casella[3437].Coordinate, "Irosso6verde");
    strcpy(Casella[3438].Coordinate, "Jrosso6verde");
    strcpy(Casella[3439].Coordinate, "Krosso6verde");
    strcpy(Casella[3440].Coordinate, "Lrosso6verde");
    strcpy(Casella[3441].Coordinate, "Mrosso6verde");
    strcpy(Casella[3442].Coordinate, "Nrosso6verde");
    strcpy(Casella[3443].Coordinate, "Orosso6verde");
    strcpy(Casella[3444].Coordinate, "Prosso6verde");
    strcpy(Casella[3445].Coordinate, "Qrosso6verde");
    strcpy(Casella[3446].Coordinate, "Rrosso6verde");
    strcpy(Casella[3447].Coordinate, "Srosso6verde");
    strcpy(Casella[3448].Coordinate, "Trosso6verde");
    strcpy(Casella[3449].Coordinate, "Urosso6verde");
    strcpy(Casella[3450].Coordinate, "Vrosso6verde");
    strcpy(Casella[3451].Coordinate, "Wrosso6verde");
    strcpy(Casella[3452].Coordinate, "Xrosso6verde");
    strcpy(Casella[3453].Coordinate, "Yrosso6verde");
    strcpy(Casella[3454].Coordinate, "Zrosso6verde");
    strcpy(Casella[3455].Coordinate, "Aazzurro6verde");
    strcpy(Casella[3456].Coordinate, "Bazzurro6verde");
    strcpy(Casella[3457].Coordinate, "Cazzurro6verde");
    strcpy(Casella[3458].Coordinate, "Dazzurro6verde");
    strcpy(Casella[3459].Coordinate, "Eazzurro6verde");
    strcpy(Casella[3460].Coordinate, "Fazzurro6verde");
    strcpy(Casella[3461].Coordinate, "Gazzurro6verde");
    strcpy(Casella[3462].Coordinate, "Hazzurro6verde");
    strcpy(Casella[3463].Coordinate, "Iazzurro6verde");
    strcpy(Casella[3464].Coordinate, "Jazzurro6verde");
    strcpy(Casella[3465].Coordinate, "Kazzurro6verde");
    strcpy(Casella[3466].Coordinate, "Lazzurro6verde");
    strcpy(Casella[3467].Coordinate, "Mazzurro6verde");
    strcpy(Casella[3468].Coordinate, "Nazzurro6verde");
    strcpy(Casella[3469].Coordinate, "Oazzurro6verde");
    strcpy(Casella[3470].Coordinate, "Pazzurro6verde");
    strcpy(Casella[3471].Coordinate, "Qazzurro6verde");
    strcpy(Casella[3472].Coordinate, "Razzurro6verde");
    strcpy(Casella[3473].Coordinate, "Sazzurro6verde");
    strcpy(Casella[3474].Coordinate, "Tazzurro6verde");
    strcpy(Casella[3475].Coordinate, "Uazzurro6verde");
    strcpy(Casella[3476].Coordinate, "Vazzurro6verde");
    strcpy(Casella[3477].Coordinate, "Wazzurro6verde");
    strcpy(Casella[3478].Coordinate, "Xazzurro6verde");
    strcpy(Casella[3479].Coordinate, "Yazzurro6verde");
    strcpy(Casella[3480].Coordinate, "Zazzurro6verde");
    strcpy(Casella[3481].Coordinate, "Agiallo6verde");
    strcpy(Casella[3482].Coordinate, "Bgiallo6verde");
    strcpy(Casella[3483].Coordinate, "Cgiallo6verde");
    strcpy(Casella[3484].Coordinate, "Dgiallo6verde");
    strcpy(Casella[3485].Coordinate, "Egiallo6verde");
    strcpy(Casella[3486].Coordinate, "Abianco7verde");
    strcpy(Casella[3487].Coordinate, "Bbianco7verde");
    strcpy(Casella[3488].Coordinate, "Cbianco7verde");
    strcpy(Casella[3489].Coordinate, "Dbianco7verde");
    strcpy(Casella[3490].Coordinate, "Ebianco7verde");
    strcpy(Casella[3491].Coordinate, "Fbianco7verde");
    strcpy(Casella[3492].Coordinate, "Gbianco7verde");
    strcpy(Casella[3493].Coordinate, "Hbianco7verde");
    strcpy(Casella[3494].Coordinate, "Ibianco7verde");
    strcpy(Casella[3495].Coordinate, "Jbianco7verde");
    strcpy(Casella[3496].Coordinate, "Kbianco7verde");
    strcpy(Casella[3497].Coordinate, "Lbianco7verde");
    strcpy(Casella[3498].Coordinate, "Mbianco7verde");
    strcpy(Casella[3499].Coordinate, "Nbianco7verde");
    strcpy(Casella[3500].Coordinate, "Obianco7verde");
    strcpy(Casella[3501].Coordinate, "Pbianco7verde");
    strcpy(Casella[3502].Coordinate, "Qbianco7verde");
    strcpy(Casella[3503].Coordinate, "Rbianco7verde");
    strcpy(Casella[3504].Coordinate, "Sbianco7verde");
    strcpy(Casella[3505].Coordinate, "Tbianco7verde");
    strcpy(Casella[3506].Coordinate, "Ubianco7verde");
    strcpy(Casella[3507].Coordinate, "Vbianco7verde");
    strcpy(Casella[3508].Coordinate, "Wbianco7verde");
    strcpy(Casella[3509].Coordinate, "Xbianco7verde");
    strcpy(Casella[3510].Coordinate, "Ybianco7verde");
    strcpy(Casella[3511].Coordinate, "Zbianco7verde");
    strcpy(Casella[3512].Coordinate, "Arosso7verde");
    strcpy(Casella[3513].Coordinate, "Brosso7verde");
    strcpy(Casella[3514].Coordinate, "Crosso7verde");
    strcpy(Casella[3515].Coordinate, "Drosso7verde");
    strcpy(Casella[3516].Coordinate, "Erosso7verde");
    strcpy(Casella[3517].Coordinate, "Frosso7verde");
    strcpy(Casella[3518].Coordinate, "Grosso7verde");
    strcpy(Casella[3519].Coordinate, "Hrosso7verde");
    strcpy(Casella[3520].Coordinate, "Irosso7verde");
    strcpy(Casella[3521].Coordinate, "Jrosso7verde");
    strcpy(Casella[3522].Coordinate, "Krosso7verde");
    strcpy(Casella[3523].Coordinate, "Lrosso7verde");
    strcpy(Casella[3524].Coordinate, "Mrosso7verde");
    strcpy(Casella[3525].Coordinate, "Nrosso7verde");
    strcpy(Casella[3526].Coordinate, "Orosso7verde");
    strcpy(Casella[3527].Coordinate, "Prosso7verde");
    strcpy(Casella[3528].Coordinate, "Qrosso7verde");
    strcpy(Casella[3529].Coordinate, "Rrosso7verde");
    strcpy(Casella[3530].Coordinate, "Srosso7verde");
    strcpy(Casella[3531].Coordinate, "Trosso7verde");
    strcpy(Casella[3532].Coordinate, "Urosso7verde");
    strcpy(Casella[3533].Coordinate, "Vrosso7verde");
    strcpy(Casella[3534].Coordinate, "Wrosso7verde");
    strcpy(Casella[3535].Coordinate, "Xrosso7verde");
    strcpy(Casella[3536].Coordinate, "Yrosso7verde");
    strcpy(Casella[3537].Coordinate, "Zrosso7verde");
    strcpy(Casella[3538].Coordinate, "Aazzurro7verde");
    strcpy(Casella[3539].Coordinate, "Bazzurro7verde");
    strcpy(Casella[3540].Coordinate, "Cazzurro7verde");
    strcpy(Casella[3541].Coordinate, "Dazzurro7verde");
    strcpy(Casella[3542].Coordinate, "Eazzurro7verde");
    strcpy(Casella[3543].Coordinate, "Fazzurro7verde");
    strcpy(Casella[3544].Coordinate, "Gazzurro7verde");
    strcpy(Casella[3545].Coordinate, "Hazzurro7verde");
    strcpy(Casella[3546].Coordinate, "Iazzurro7verde");
    strcpy(Casella[3547].Coordinate, "Jazzurro7verde");
    strcpy(Casella[3548].Coordinate, "Kazzurro7verde");
    strcpy(Casella[3549].Coordinate, "Lazzurro7verde");
    strcpy(Casella[3550].Coordinate, "Mazzurro7verde");
    strcpy(Casella[3551].Coordinate, "Nazzurro7verde");
    strcpy(Casella[3552].Coordinate, "Oazzurro7verde");
    strcpy(Casella[3553].Coordinate, "Pazzurro7verde");
    strcpy(Casella[3554].Coordinate, "Qazzurro7verde");
    strcpy(Casella[3555].Coordinate, "Razzurro7verde");
    strcpy(Casella[3556].Coordinate, "Sazzurro7verde");
    strcpy(Casella[3557].Coordinate, "Tazzurro7verde");
    strcpy(Casella[3558].Coordinate, "Uazzurro7verde");
    strcpy(Casella[3559].Coordinate, "Vazzurro7verde");
    strcpy(Casella[3560].Coordinate, "Wazzurro7verde");
    strcpy(Casella[3561].Coordinate, "Xazzurro7verde");
    strcpy(Casella[3562].Coordinate, "Yazzurro7verde");
    strcpy(Casella[3563].Coordinate, "Zazzurro7verde");
    strcpy(Casella[3564].Coordinate, "Agiallo7verde");
    strcpy(Casella[3565].Coordinate, "Bgiallo7verde");
    strcpy(Casella[3566].Coordinate, "Cgiallo7verde");
    strcpy(Casella[3567].Coordinate, "Dgiallo7verde");
    strcpy(Casella[3568].Coordinate, "Egiallo7verde");
    strcpy(Casella[3569].Coordinate, "Abianco8verde");
    strcpy(Casella[3570].Coordinate, "Bbianco8verde");
    strcpy(Casella[3571].Coordinate, "Cbianco8verde");
    strcpy(Casella[3572].Coordinate, "Dbianco8verde");
    strcpy(Casella[3573].Coordinate, "Ebianco8verde");
    strcpy(Casella[3574].Coordinate, "Fbianco8verde");
    strcpy(Casella[3575].Coordinate, "Gbianco8verde");
    strcpy(Casella[3576].Coordinate, "Hbianco8verde");
    strcpy(Casella[3577].Coordinate, "Ibianco8verde");
    strcpy(Casella[3578].Coordinate, "Jbianco8verde");
    strcpy(Casella[3579].Coordinate, "Kbianco8verde");
    strcpy(Casella[3580].Coordinate, "Lbianco8verde");
    strcpy(Casella[3581].Coordinate, "Mbianco8verde");
    strcpy(Casella[3582].Coordinate, "Nbianco8verde");
    strcpy(Casella[3583].Coordinate, "Obianco8verde");
    strcpy(Casella[3584].Coordinate, "Pbianco8verde");
    strcpy(Casella[3585].Coordinate, "Qbianco8verde");
    strcpy(Casella[3586].Coordinate, "Rbianco8verde");
    strcpy(Casella[3587].Coordinate, "Sbianco8verde");
    strcpy(Casella[3588].Coordinate, "Tbianco8verde");
    strcpy(Casella[3589].Coordinate, "Ubianco8verde");
    strcpy(Casella[3590].Coordinate, "Vbianco8verde");
    strcpy(Casella[3591].Coordinate, "Wbianco8verde");
    strcpy(Casella[3592].Coordinate, "Xbianco8verde");
    strcpy(Casella[3593].Coordinate, "Ybianco8verde");
    strcpy(Casella[3594].Coordinate, "Zbianco8verde");
    strcpy(Casella[3595].Coordinate, "Arosso8verde");
    strcpy(Casella[3596].Coordinate, "Brosso8verde");
    strcpy(Casella[3597].Coordinate, "Crosso8verde");
    strcpy(Casella[3598].Coordinate, "Drosso8verde");
    strcpy(Casella[3599].Coordinate, "Erosso8verde");
    strcpy(Casella[3600].Coordinate, "Frosso8verde");
    strcpy(Casella[3601].Coordinate, "Grosso8verde");
    strcpy(Casella[3602].Coordinate, "Hrosso8verde");
    strcpy(Casella[3603].Coordinate, "Irosso8verde");
    strcpy(Casella[3604].Coordinate, "Jrosso8verde");
    strcpy(Casella[3605].Coordinate, "Krosso8verde");
    strcpy(Casella[3606].Coordinate, "Lrosso8verde");
    strcpy(Casella[3607].Coordinate, "Mrosso8verde");
    strcpy(Casella[3608].Coordinate, "Nrosso8verde");
    strcpy(Casella[3609].Coordinate, "Orosso8verde");
    strcpy(Casella[3610].Coordinate, "Prosso8verde");
    strcpy(Casella[3611].Coordinate, "Qrosso8verde");
    strcpy(Casella[3612].Coordinate, "Rrosso8verde");
    strcpy(Casella[3613].Coordinate, "Srosso8verde");
    strcpy(Casella[3614].Coordinate, "Trosso8verde");
    strcpy(Casella[3615].Coordinate, "Urosso8verde");
    strcpy(Casella[3616].Coordinate, "Vrosso8verde");
    strcpy(Casella[3617].Coordinate, "Wrosso8verde");
    strcpy(Casella[3618].Coordinate, "Xrosso8verde");
    strcpy(Casella[3619].Coordinate, "Yrosso8verde");
    strcpy(Casella[3620].Coordinate, "Zrosso8verde");
    strcpy(Casella[3621].Coordinate, "Aazzurro8verde");
    strcpy(Casella[3622].Coordinate, "Bazzurro8verde");
    strcpy(Casella[3623].Coordinate, "Cazzurro8verde");
    strcpy(Casella[3624].Coordinate, "Dazzurro8verde");
    strcpy(Casella[3625].Coordinate, "Eazzurro8verde");
    strcpy(Casella[3626].Coordinate, "Fazzurro8verde");
    strcpy(Casella[3627].Coordinate, "Gazzurro8verde");
    strcpy(Casella[3628].Coordinate, "Hazzurro8verde");
    strcpy(Casella[3629].Coordinate, "Iazzurro8verde");
    strcpy(Casella[3630].Coordinate, "Jazzurro8verde");
    strcpy(Casella[3631].Coordinate, "Kazzurro8verde");
    strcpy(Casella[3632].Coordinate, "Lazzurro8verde");
    strcpy(Casella[3633].Coordinate, "Mazzurro8verde");
    strcpy(Casella[3634].Coordinate, "Nazzurro8verde");
    strcpy(Casella[3635].Coordinate, "Oazzurro8verde");
    strcpy(Casella[3636].Coordinate, "Pazzurro8verde");
    strcpy(Casella[3637].Coordinate, "Qazzurro8verde");
    strcpy(Casella[3638].Coordinate, "Razzurro8verde");
    strcpy(Casella[3639].Coordinate, "Sazzurro8verde");
    strcpy(Casella[3640].Coordinate, "Tazzurro8verde");
    strcpy(Casella[3641].Coordinate, "Uazzurro8verde");
    strcpy(Casella[3642].Coordinate, "Vazzurro8verde");
    strcpy(Casella[3643].Coordinate, "Wazzurro8verde");
    strcpy(Casella[3644].Coordinate, "Xazzurro8verde");
    strcpy(Casella[3645].Coordinate, "Yazzurro8verde");
    strcpy(Casella[3646].Coordinate, "Zazzurro8verde");
    strcpy(Casella[3647].Coordinate, "Agiallo8verde");
    strcpy(Casella[3648].Coordinate, "Bgiallo8verde");
    strcpy(Casella[3649].Coordinate, "Cgiallo8verde");
    strcpy(Casella[3650].Coordinate, "Dgiallo8verde");
    strcpy(Casella[3651].Coordinate, "Egiallo8verde");
    strcpy(Casella[3652].Coordinate, "Abianco9verde");
    strcpy(Casella[3653].Coordinate, "Bbianco9verde");
    strcpy(Casella[3654].Coordinate, "Cbianco9verde");
    strcpy(Casella[3655].Coordinate, "Dbianco9verde");
    strcpy(Casella[3656].Coordinate, "Ebianco9verde");
    strcpy(Casella[3657].Coordinate, "Fbianco9verde");
    strcpy(Casella[3658].Coordinate, "Gbianco9verde");
    strcpy(Casella[3659].Coordinate, "Hbianco9verde");
    strcpy(Casella[3660].Coordinate, "Ibianco9verde");
    strcpy(Casella[3661].Coordinate, "Jbianco9verde");
    strcpy(Casella[3662].Coordinate, "Kbianco9verde");
    strcpy(Casella[3663].Coordinate, "Lbianco9verde");
    strcpy(Casella[3664].Coordinate, "Mbianco9verde");
    strcpy(Casella[3665].Coordinate, "Nbianco9verde");
    strcpy(Casella[3666].Coordinate, "Obianco9verde");
    strcpy(Casella[3667].Coordinate, "Pbianco9verde");
    strcpy(Casella[3668].Coordinate, "Qbianco9verde");
    strcpy(Casella[3669].Coordinate, "Rbianco9verde");
    strcpy(Casella[3670].Coordinate, "Sbianco9verde");
    strcpy(Casella[3671].Coordinate, "Tbianco9verde");
    strcpy(Casella[3672].Coordinate, "Ubianco9verde");
    strcpy(Casella[3673].Coordinate, "Vbianco9verde");
    strcpy(Casella[3674].Coordinate, "Wbianco9verde");
    strcpy(Casella[3675].Coordinate, "Xbianco9verde");
    strcpy(Casella[3676].Coordinate, "Ybianco9verde");
    strcpy(Casella[3677].Coordinate, "Zbianco9verde");
    strcpy(Casella[3678].Coordinate, "Arosso9verde");
    strcpy(Casella[3679].Coordinate, "Brosso9verde");
    strcpy(Casella[3680].Coordinate, "Crosso9verde");
    strcpy(Casella[3681].Coordinate, "Drosso9verde");
    strcpy(Casella[3682].Coordinate, "Erosso9verde");
    strcpy(Casella[3683].Coordinate, "Frosso9verde");
    strcpy(Casella[3684].Coordinate, "Grosso9verde");
    strcpy(Casella[3685].Coordinate, "Hrosso9verde");
    strcpy(Casella[3686].Coordinate, "Irosso9verde");
    strcpy(Casella[3687].Coordinate, "Jrosso9verde");
    strcpy(Casella[3688].Coordinate, "Krosso9verde");
    strcpy(Casella[3689].Coordinate, "Lrosso9verde");
    strcpy(Casella[3690].Coordinate, "Mrosso9verde");
    strcpy(Casella[3691].Coordinate, "Nrosso9verde");
    strcpy(Casella[3692].Coordinate, "Orosso9verde");
    strcpy(Casella[3693].Coordinate, "Prosso9verde");
    strcpy(Casella[3694].Coordinate, "Qrosso9verde");
    strcpy(Casella[3695].Coordinate, "Rrosso9verde");
    strcpy(Casella[3696].Coordinate, "Srosso9verde");
    strcpy(Casella[3697].Coordinate, "Trosso9verde");
    strcpy(Casella[3698].Coordinate, "Urosso9verde");
    strcpy(Casella[3699].Coordinate, "Vrosso9verde");
    strcpy(Casella[3700].Coordinate, "Wrosso9verde");
    strcpy(Casella[3701].Coordinate, "Xrosso9verde");
    strcpy(Casella[3702].Coordinate, "Yrosso9verde");
    strcpy(Casella[3703].Coordinate, "Zrosso9verde");
    strcpy(Casella[3704].Coordinate, "Aazzurro9verde");
    strcpy(Casella[3705].Coordinate, "Bazzurro9verde");
    strcpy(Casella[3706].Coordinate, "Cazzurro9verde");
    strcpy(Casella[3707].Coordinate, "Dazzurro9verde");
    strcpy(Casella[3708].Coordinate, "Eazzurro9verde");
    strcpy(Casella[3709].Coordinate, "Fazzurro9verde");
    strcpy(Casella[3710].Coordinate, "Gazzurro9verde");
    strcpy(Casella[3711].Coordinate, "Hazzurro9verde");
    strcpy(Casella[3712].Coordinate, "Iazzurro9verde");
    strcpy(Casella[3713].Coordinate, "Jazzurro9verde");
    strcpy(Casella[3714].Coordinate, "Kazzurro9verde");
    strcpy(Casella[3715].Coordinate, "Lazzurro9verde");
    strcpy(Casella[3716].Coordinate, "Mazzurro9verde");
    strcpy(Casella[3717].Coordinate, "Nazzurro9verde");
    strcpy(Casella[3718].Coordinate, "Oazzurro9verde");
    strcpy(Casella[3719].Coordinate, "Pazzurro9verde");
    strcpy(Casella[3720].Coordinate, "Qazzurro9verde");
    strcpy(Casella[3721].Coordinate, "Razzurro9verde");
    strcpy(Casella[3722].Coordinate, "Sazzurro9verde");
    strcpy(Casella[3723].Coordinate, "Tazzurro9verde");
    strcpy(Casella[3724].Coordinate, "Uazzurro9verde");
    strcpy(Casella[3725].Coordinate, "Vazzurro9verde");
    strcpy(Casella[3726].Coordinate, "Wazzurro9verde");
    strcpy(Casella[3727].Coordinate, "Xazzurro9verde");
    strcpy(Casella[3728].Coordinate, "Yazzurro9verde");
    strcpy(Casella[3729].Coordinate, "Zazzurro9verde");
    strcpy(Casella[3730].Coordinate, "Agiallo9verde");
    strcpy(Casella[3731].Coordinate, "Bgiallo9verde");
    strcpy(Casella[3732].Coordinate, "Cgiallo9verde");
    strcpy(Casella[3733].Coordinate, "Dgiallo9verde");
    strcpy(Casella[3734].Coordinate, "Egiallo9verde");
    strcpy(Casella[3735].Coordinate, "Abianco1rosa");
    strcpy(Casella[3736].Coordinate, "Bbianco1rosa");
    strcpy(Casella[3737].Coordinate, "Cbianco1rosa");
    strcpy(Casella[3738].Coordinate, "Dbianco1rosa");
    strcpy(Casella[3739].Coordinate, "Ebianco1rosa");
    strcpy(Casella[3740].Coordinate, "Fbianco1rosa");
    strcpy(Casella[3741].Coordinate, "Gbianco1rosa");
    strcpy(Casella[3742].Coordinate, "Hbianco1rosa");
    strcpy(Casella[3743].Coordinate, "Ibianco1rosa");
    strcpy(Casella[3744].Coordinate, "Jbianco1rosa");
    strcpy(Casella[3745].Coordinate, "Kbianco1rosa");
    strcpy(Casella[3746].Coordinate, "Lbianco1rosa");
    strcpy(Casella[3747].Coordinate, "Mbianco1rosa");
    strcpy(Casella[3748].Coordinate, "Nbianco1rosa");
    strcpy(Casella[3749].Coordinate, "Obianco1rosa");
    strcpy(Casella[3750].Coordinate, "Pbianco1rosa");
    strcpy(Casella[3751].Coordinate, "Qbianco1rosa");
    strcpy(Casella[3752].Coordinate, "Rbianco1rosa");
    strcpy(Casella[3753].Coordinate, "Sbianco1rosa");
    strcpy(Casella[3754].Coordinate, "Tbianco1rosa");
    strcpy(Casella[3755].Coordinate, "Ubianco1rosa");
    strcpy(Casella[3756].Coordinate, "Vbianco1rosa");
    strcpy(Casella[3757].Coordinate, "Wbianco1rosa");
    strcpy(Casella[3758].Coordinate, "Xbianco1rosa");
    strcpy(Casella[3759].Coordinate, "Ybianco1rosa");
    strcpy(Casella[3760].Coordinate, "Zbianco1rosa");
    strcpy(Casella[3761].Coordinate, "Arosso1rosa");
    strcpy(Casella[3762].Coordinate, "Brosso1rosa");
    strcpy(Casella[3763].Coordinate, "Crosso1rosa");
    strcpy(Casella[3764].Coordinate, "Drosso1rosa");
    strcpy(Casella[3765].Coordinate, "Erosso1rosa");
    strcpy(Casella[3766].Coordinate, "Frosso1rosa");
    strcpy(Casella[3767].Coordinate, "Grosso1rosa");
    strcpy(Casella[3768].Coordinate, "Hrosso1rosa");
    strcpy(Casella[3769].Coordinate, "Irosso1rosa");
    strcpy(Casella[3770].Coordinate, "Jrosso1rosa");
    strcpy(Casella[3771].Coordinate, "Krosso1rosa");
    strcpy(Casella[3772].Coordinate, "Lrosso1rosa");
    strcpy(Casella[3773].Coordinate, "Mrosso1rosa");
    strcpy(Casella[3774].Coordinate, "Nrosso1rosa");
    strcpy(Casella[3775].Coordinate, "Orosso1rosa");
    strcpy(Casella[3776].Coordinate, "Prosso1rosa");
    strcpy(Casella[3777].Coordinate, "Qrosso1rosa");
    strcpy(Casella[3778].Coordinate, "Rrosso1rosa");
    strcpy(Casella[3779].Coordinate, "Srosso1rosa");
    strcpy(Casella[3780].Coordinate, "Trosso1rosa");
    strcpy(Casella[3781].Coordinate, "Urosso1rosa");
    strcpy(Casella[3782].Coordinate, "Vrosso1rosa");
    strcpy(Casella[3783].Coordinate, "Wrosso1rosa");
    strcpy(Casella[3784].Coordinate, "Xrosso1rosa");
    strcpy(Casella[3785].Coordinate, "Yrosso1rosa");
    strcpy(Casella[3786].Coordinate, "Zrosso1rosa");
    strcpy(Casella[3787].Coordinate, "Aazzurro1rosa");
    strcpy(Casella[3788].Coordinate, "Bazzurro1rosa");
    strcpy(Casella[3789].Coordinate, "Cazzurro1rosa");
    strcpy(Casella[3790].Coordinate, "Dazzurro1rosa");
    strcpy(Casella[3791].Coordinate, "Eazzurro1rosa");
    strcpy(Casella[3792].Coordinate, "Fazzurro1rosa");
    strcpy(Casella[3793].Coordinate, "Gazzurro1rosa");
    strcpy(Casella[3794].Coordinate, "Hazzurro1rosa");
    strcpy(Casella[3795].Coordinate, "Iazzurro1rosa");
    strcpy(Casella[3796].Coordinate, "Jazzurro1rosa");
    strcpy(Casella[3797].Coordinate, "Kazzurro1rosa");
    strcpy(Casella[3798].Coordinate, "Lazzurro1rosa");
    strcpy(Casella[3799].Coordinate, "Mazzurro1rosa");
    strcpy(Casella[3800].Coordinate, "Nazzurro1rosa");
    strcpy(Casella[3801].Coordinate, "Oazzurro1rosa");
    strcpy(Casella[3802].Coordinate, "Pazzurro1rosa");
    strcpy(Casella[3803].Coordinate, "Qazzurro1rosa");
    strcpy(Casella[3804].Coordinate, "Razzurro1rosa");
    strcpy(Casella[3805].Coordinate, "Sazzurro1rosa");
    strcpy(Casella[3806].Coordinate, "Tazzurro1rosa");
    strcpy(Casella[3807].Coordinate, "Uazzurro1rosa");
    strcpy(Casella[3808].Coordinate, "Vazzurro1rosa");
    strcpy(Casella[3809].Coordinate, "Wazzurro1rosa");
    strcpy(Casella[3810].Coordinate, "Xazzurro1rosa");
    strcpy(Casella[3811].Coordinate, "Yazzurro1rosa");
    strcpy(Casella[3812].Coordinate, "Zazzurro1rosa");
    strcpy(Casella[3813].Coordinate, "Agiallo1rosa");
    strcpy(Casella[3814].Coordinate, "Bgiallo1rosa");
    strcpy(Casella[3815].Coordinate, "Cgiallo1rosa");
    strcpy(Casella[3816].Coordinate, "Dgiallo1rosa");
    strcpy(Casella[3817].Coordinate, "Egiallo1rosa");
    strcpy(Casella[3818].Coordinate, "Abianco2rosa");
    strcpy(Casella[3819].Coordinate, "Bbianco2rosa");
    strcpy(Casella[3820].Coordinate, "Cbianco2rosa");
    strcpy(Casella[3821].Coordinate, "Dbianco2rosa");
    strcpy(Casella[3822].Coordinate, "Ebianco2rosa");
    strcpy(Casella[3823].Coordinate, "Fbianco2rosa");
    strcpy(Casella[3824].Coordinate, "Gbianco2rosa");
    strcpy(Casella[3825].Coordinate, "Hbianco2rosa");
    strcpy(Casella[3826].Coordinate, "Ibianco2rosa");
    strcpy(Casella[3827].Coordinate, "Jbianco2rosa");
    strcpy(Casella[3828].Coordinate, "Kbianco2rosa");
    strcpy(Casella[3829].Coordinate, "Lbianco2rosa");
    strcpy(Casella[3830].Coordinate, "Mbianco2rosa");
    strcpy(Casella[3831].Coordinate, "Nbianco2rosa");
    strcpy(Casella[3832].Coordinate, "Obianco2rosa");
    strcpy(Casella[3833].Coordinate, "Pbianco2rosa");
    strcpy(Casella[3834].Coordinate, "Qbianco2rosa");
    strcpy(Casella[3835].Coordinate, "Rbianco2rosa");
    strcpy(Casella[3836].Coordinate, "Sbianco2rosa");
    strcpy(Casella[3837].Coordinate, "Tbianco2rosa");
    strcpy(Casella[3838].Coordinate, "Ubianco2rosa");
    strcpy(Casella[3839].Coordinate, "Vbianco2rosa");
    strcpy(Casella[3840].Coordinate, "Wbianco2rosa");
    strcpy(Casella[3841].Coordinate, "Xbianco2rosa");
    strcpy(Casella[3842].Coordinate, "Ybianco2rosa");
    strcpy(Casella[3843].Coordinate, "Zbianco2rosa");
    strcpy(Casella[3844].Coordinate, "Arosso2rosa");
    strcpy(Casella[3845].Coordinate, "Brosso2rosa");
    strcpy(Casella[3846].Coordinate, "Crosso2rosa");
    strcpy(Casella[3847].Coordinate, "Drosso2rosa");
    strcpy(Casella[3848].Coordinate, "Erosso2rosa");
    strcpy(Casella[3849].Coordinate, "Frosso2rosa");
    strcpy(Casella[3850].Coordinate, "Grosso2rosa");
    strcpy(Casella[3851].Coordinate, "Hrosso2rosa");
    strcpy(Casella[3852].Coordinate, "Irosso2rosa");
    strcpy(Casella[3853].Coordinate, "Jrosso2rosa");
    strcpy(Casella[3854].Coordinate, "Krosso2rosa");
    strcpy(Casella[3855].Coordinate, "Lrosso2rosa");
    strcpy(Casella[3856].Coordinate, "Mrosso2rosa");
    strcpy(Casella[3857].Coordinate, "Nrosso2rosa");
    strcpy(Casella[3858].Coordinate, "Orosso2rosa");
    strcpy(Casella[3859].Coordinate, "Prosso2rosa");
    strcpy(Casella[3860].Coordinate, "Qrosso2rosa");
    strcpy(Casella[3861].Coordinate, "Rrosso2rosa");
    strcpy(Casella[3862].Coordinate, "Srosso2rosa");
    strcpy(Casella[3863].Coordinate, "Trosso2rosa");
    strcpy(Casella[3864].Coordinate, "Urosso2rosa");
    strcpy(Casella[3865].Coordinate, "Vrosso2rosa");
    strcpy(Casella[3866].Coordinate, "Wrosso2rosa");
    strcpy(Casella[3867].Coordinate, "Xrosso2rosa");
    strcpy(Casella[3868].Coordinate, "Yrosso2rosa");
    strcpy(Casella[3869].Coordinate, "Zrosso2rosa");
    strcpy(Casella[3870].Coordinate, "Aazzurro2rosa");
    strcpy(Casella[3871].Coordinate, "Bazzurro2rosa");
    strcpy(Casella[3872].Coordinate, "Cazzurro2rosa");
    strcpy(Casella[3873].Coordinate, "Dazzurro2rosa");
    strcpy(Casella[3874].Coordinate, "Eazzurro2rosa");
    strcpy(Casella[3875].Coordinate, "Fazzurro2rosa");
    strcpy(Casella[3876].Coordinate, "Gazzurro2rosa");
    strcpy(Casella[3877].Coordinate, "Hazzurro2rosa");
    strcpy(Casella[3878].Coordinate, "Iazzurro2rosa");
    strcpy(Casella[3879].Coordinate, "Jazzurro2rosa");
    strcpy(Casella[3880].Coordinate, "Kazzurro2rosa");
    strcpy(Casella[3881].Coordinate, "Lazzurro2rosa");
    strcpy(Casella[3882].Coordinate, "Mazzurro2rosa");
    strcpy(Casella[3883].Coordinate, "Nazzurro2rosa");
    strcpy(Casella[3884].Coordinate, "Oazzurro2rosa");
    strcpy(Casella[3885].Coordinate, "Pazzurro2rosa");
    strcpy(Casella[3886].Coordinate, "Qazzurro2rosa");
    strcpy(Casella[3887].Coordinate, "Razzurro2rosa");
    strcpy(Casella[3888].Coordinate, "Sazzurro2rosa");
    strcpy(Casella[3889].Coordinate, "Tazzurro2rosa");
    strcpy(Casella[3890].Coordinate, "Uazzurro2rosa");
    strcpy(Casella[3891].Coordinate, "Vazzurro2rosa");
    strcpy(Casella[3892].Coordinate, "Wazzurro2rosa");
    strcpy(Casella[3893].Coordinate, "Xazzurro2rosa");
    strcpy(Casella[3894].Coordinate, "Yazzurro2rosa");
    strcpy(Casella[3895].Coordinate, "Zazzurro2rosa");
    strcpy(Casella[3896].Coordinate, "Agiallo2rosa");
    strcpy(Casella[3897].Coordinate, "Bgiallo2rosa");
    strcpy(Casella[3898].Coordinate, "Cgiallo2rosa");
    strcpy(Casella[3899].Coordinate, "Dgiallo2rosa");
    strcpy(Casella[3900].Coordinate, "Egiallo2rosa");
    strcpy(Casella[3901].Coordinate, "Abianco3rosa");
    strcpy(Casella[3902].Coordinate, "Bbianco3rosa");
    strcpy(Casella[3903].Coordinate, "Cbianco3rosa");
    strcpy(Casella[3904].Coordinate, "Dbianco3rosa");
    strcpy(Casella[3905].Coordinate, "Ebianco3rosa");
    strcpy(Casella[3906].Coordinate, "Fbianco3rosa");
    strcpy(Casella[3907].Coordinate, "Gbianco3rosa");
    strcpy(Casella[3908].Coordinate, "Hbianco3rosa");
    strcpy(Casella[3909].Coordinate, "Ibianco3rosa");
    strcpy(Casella[3910].Coordinate, "Jbianco3rosa");
    strcpy(Casella[3911].Coordinate, "Kbianco3rosa");
    strcpy(Casella[3912].Coordinate, "Lbianco3rosa");
    strcpy(Casella[3913].Coordinate, "Mbianco3rosa");
    strcpy(Casella[3914].Coordinate, "Nbianco3rosa");
    strcpy(Casella[3915].Coordinate, "Obianco3rosa");
    strcpy(Casella[3916].Coordinate, "Pbianco3rosa");
    strcpy(Casella[3917].Coordinate, "Qbianco3rosa");
    strcpy(Casella[3918].Coordinate, "Rbianco3rosa");
    strcpy(Casella[3919].Coordinate, "Sbianco3rosa");
    strcpy(Casella[3920].Coordinate, "Tbianco3rosa");
    strcpy(Casella[3921].Coordinate, "Ubianco3rosa");
    strcpy(Casella[3922].Coordinate, "Vbianco3rosa");
    strcpy(Casella[3923].Coordinate, "Wbianco3rosa");
    strcpy(Casella[3924].Coordinate, "Xbianco3rosa");
    strcpy(Casella[3925].Coordinate, "Ybianco3rosa");
    strcpy(Casella[3926].Coordinate, "Zbianco3rosa");
    strcpy(Casella[3927].Coordinate, "Arosso3rosa");
    strcpy(Casella[3928].Coordinate, "Brosso3rosa");
    strcpy(Casella[3929].Coordinate, "Crosso3rosa");
    strcpy(Casella[3930].Coordinate, "Drosso3rosa");
    strcpy(Casella[3931].Coordinate, "Erosso3rosa");
    strcpy(Casella[3932].Coordinate, "Frosso3rosa");
    strcpy(Casella[3933].Coordinate, "Grosso3rosa");
    strcpy(Casella[3934].Coordinate, "Hrosso3rosa");
    strcpy(Casella[3935].Coordinate, "Irosso3rosa");
    strcpy(Casella[3936].Coordinate, "Jrosso3rosa");
    strcpy(Casella[3937].Coordinate, "Krosso3rosa");
    strcpy(Casella[3938].Coordinate, "Lrosso3rosa");
    strcpy(Casella[3939].Coordinate, "Mrosso3rosa");
    strcpy(Casella[3940].Coordinate, "Nrosso3rosa");
    strcpy(Casella[3941].Coordinate, "Orosso3rosa");
    strcpy(Casella[3942].Coordinate, "Prosso3rosa");
    strcpy(Casella[3943].Coordinate, "Qrosso3rosa");
    strcpy(Casella[3944].Coordinate, "Rrosso3rosa");
    strcpy(Casella[3945].Coordinate, "Srosso3rosa");
    strcpy(Casella[3946].Coordinate, "Trosso3rosa");
    strcpy(Casella[3947].Coordinate, "Urosso3rosa");
    strcpy(Casella[3948].Coordinate, "Vrosso3rosa");
    strcpy(Casella[3949].Coordinate, "Wrosso3rosa");
    strcpy(Casella[3950].Coordinate, "Xrosso3rosa");
    strcpy(Casella[3951].Coordinate, "Yrosso3rosa");
    strcpy(Casella[3952].Coordinate, "Zrosso3rosa");
    strcpy(Casella[3953].Coordinate, "Aazzurro3rosa");
    strcpy(Casella[3954].Coordinate, "Bazzurro3rosa");
    strcpy(Casella[3955].Coordinate, "Cazzurro3rosa");
    strcpy(Casella[3956].Coordinate, "Dazzurro3rosa");
    strcpy(Casella[3957].Coordinate, "Eazzurro3rosa");
    strcpy(Casella[3958].Coordinate, "Fazzurro3rosa");
    strcpy(Casella[3959].Coordinate, "Gazzurro3rosa");
    strcpy(Casella[3960].Coordinate, "Hazzurro3rosa");
    strcpy(Casella[3961].Coordinate, "Iazzurro3rosa");
    strcpy(Casella[3962].Coordinate, "Jazzurro3rosa");
    strcpy(Casella[3963].Coordinate, "Kazzurro3rosa");
    strcpy(Casella[3964].Coordinate, "Lazzurro3rosa");
    strcpy(Casella[3965].Coordinate, "Mazzurro3rosa");
    strcpy(Casella[3966].Coordinate, "Nazzurro3rosa");
    strcpy(Casella[3967].Coordinate, "Oazzurro3rosa");
    strcpy(Casella[3968].Coordinate, "Pazzurro3rosa");
    strcpy(Casella[3969].Coordinate, "Qazzurro3rosa");
    strcpy(Casella[3970].Coordinate, "Razzurro3rosa");
    strcpy(Casella[3971].Coordinate, "Sazzurro3rosa");
    strcpy(Casella[3972].Coordinate, "Tazzurro3rosa");
    strcpy(Casella[3973].Coordinate, "Uazzurro3rosa");
    strcpy(Casella[3974].Coordinate, "Vazzurro3rosa");
    strcpy(Casella[3975].Coordinate, "Wazzurro3rosa");
    strcpy(Casella[3976].Coordinate, "Xazzurro3rosa");
    strcpy(Casella[3977].Coordinate, "Yazzurro3rosa");
    strcpy(Casella[3978].Coordinate, "Zazzurro3rosa");
    strcpy(Casella[3979].Coordinate, "Agiallo3rosa");
    strcpy(Casella[3980].Coordinate, "Bgiallo3rosa");
    strcpy(Casella[3981].Coordinate, "Cgiallo3rosa");
    strcpy(Casella[3982].Coordinate, "Dgiallo3rosa");
    strcpy(Casella[3983].Coordinate, "Egiallo3rosa");
    strcpy(Casella[3984].Coordinate, "Abianco4rosa");
    strcpy(Casella[3985].Coordinate, "Bbianco4rosa");
    strcpy(Casella[3986].Coordinate, "Cbianco4rosa");
    strcpy(Casella[3987].Coordinate, "Dbianco4rosa");
    strcpy(Casella[3988].Coordinate, "Ebianco4rosa");
    strcpy(Casella[3989].Coordinate, "Fbianco4rosa");
    strcpy(Casella[3990].Coordinate, "Gbianco4rosa");
    strcpy(Casella[3991].Coordinate, "Hbianco4rosa");
    strcpy(Casella[3992].Coordinate, "Ibianco4rosa");
    strcpy(Casella[3993].Coordinate, "Jbianco4rosa");
    strcpy(Casella[3994].Coordinate, "Kbianco4rosa");
    strcpy(Casella[3995].Coordinate, "Lbianco4rosa");
    strcpy(Casella[3996].Coordinate, "Mbianco4rosa");
    strcpy(Casella[3997].Coordinate, "Nbianco4rosa");
    strcpy(Casella[3998].Coordinate, "Obianco4rosa");
    strcpy(Casella[3999].Coordinate, "Pbianco4rosa");
    strcpy(Casella[4000].Coordinate, "Qbianco4rosa");
    strcpy(Casella[4001].Coordinate, "Rbianco4rosa");
    strcpy(Casella[4002].Coordinate, "Sbianco4rosa");
    strcpy(Casella[4003].Coordinate, "Tbianco4rosa");
    strcpy(Casella[4004].Coordinate, "Ubianco4rosa");
    strcpy(Casella[4005].Coordinate, "Vbianco4rosa");
    strcpy(Casella[4006].Coordinate, "Wbianco4rosa");
    strcpy(Casella[4007].Coordinate, "Xbianco4rosa");
    strcpy(Casella[4008].Coordinate, "Ybianco4rosa");
    strcpy(Casella[4009].Coordinate, "Zbianco4rosa");
    strcpy(Casella[4010].Coordinate, "Arosso4rosa");
    strcpy(Casella[4011].Coordinate, "Brosso4rosa");
    strcpy(Casella[4012].Coordinate, "Crosso4rosa");
    strcpy(Casella[4013].Coordinate, "Drosso4rosa");
    strcpy(Casella[4014].Coordinate, "Erosso4rosa");
    strcpy(Casella[4015].Coordinate, "Frosso4rosa");
    strcpy(Casella[4016].Coordinate, "Grosso4rosa");
    strcpy(Casella[4017].Coordinate, "Hrosso4rosa");
    strcpy(Casella[4018].Coordinate, "Irosso4rosa");
    strcpy(Casella[4019].Coordinate, "Jrosso4rosa");
    strcpy(Casella[4020].Coordinate, "Krosso4rosa");
    strcpy(Casella[4021].Coordinate, "Lrosso4rosa");
    strcpy(Casella[4022].Coordinate, "Mrosso4rosa");
    strcpy(Casella[4023].Coordinate, "Nrosso4rosa");
    strcpy(Casella[4024].Coordinate, "Orosso4rosa");
    strcpy(Casella[4025].Coordinate, "Prosso4rosa");
    strcpy(Casella[4026].Coordinate, "Qrosso4rosa");
    strcpy(Casella[4027].Coordinate, "Rrosso4rosa");
    strcpy(Casella[4028].Coordinate, "Srosso4rosa");
    strcpy(Casella[4029].Coordinate, "Trosso4rosa");
    strcpy(Casella[4030].Coordinate, "Urosso4rosa");
    strcpy(Casella[4031].Coordinate, "Vrosso4rosa");
    strcpy(Casella[4032].Coordinate, "Wrosso4rosa");
    strcpy(Casella[4033].Coordinate, "Xrosso4rosa");
    strcpy(Casella[4034].Coordinate, "Yrosso4rosa");
    strcpy(Casella[4035].Coordinate, "Zrosso4rosa");
    strcpy(Casella[4036].Coordinate, "Aazzurro4rosa");
    strcpy(Casella[4037].Coordinate, "Bazzurro4rosa");
    strcpy(Casella[4038].Coordinate, "Cazzurro4rosa");
    strcpy(Casella[4039].Coordinate, "Dazzurro4rosa");
    strcpy(Casella[4040].Coordinate, "Eazzurro4rosa");
    strcpy(Casella[4041].Coordinate, "Fazzurro4rosa");
    strcpy(Casella[4042].Coordinate, "Gazzurro4rosa");
    strcpy(Casella[4043].Coordinate, "Hazzurro4rosa");
    strcpy(Casella[4044].Coordinate, "Iazzurro4rosa");
    strcpy(Casella[4045].Coordinate, "Jazzurro4rosa");
    strcpy(Casella[4046].Coordinate, "Kazzurro4rosa");
    strcpy(Casella[4047].Coordinate, "Lazzurro4rosa");
    strcpy(Casella[4048].Coordinate, "Mazzurro4rosa");
    strcpy(Casella[4049].Coordinate, "Nazzurro4rosa");
    strcpy(Casella[4050].Coordinate, "Oazzurro4rosa");
    strcpy(Casella[4051].Coordinate, "Pazzurro4rosa");
    strcpy(Casella[4052].Coordinate, "Qazzurro4rosa");
    strcpy(Casella[4053].Coordinate, "Razzurro4rosa");
    strcpy(Casella[4054].Coordinate, "Sazzurro4rosa");
    strcpy(Casella[4055].Coordinate, "Tazzurro4rosa");
    strcpy(Casella[4056].Coordinate, "Uazzurro4rosa");
    strcpy(Casella[4057].Coordinate, "Vazzurro4rosa");
    strcpy(Casella[4058].Coordinate, "Wazzurro4rosa");
    strcpy(Casella[4059].Coordinate, "Xazzurro4rosa");
    strcpy(Casella[4060].Coordinate, "Yazzurro4rosa");
    strcpy(Casella[4061].Coordinate, "Zazzurro4rosa");
    strcpy(Casella[4062].Coordinate, "Agiallo4rosa");
    strcpy(Casella[4063].Coordinate, "Bgiallo4rosa");
    strcpy(Casella[4064].Coordinate, "Cgiallo4rosa");
    strcpy(Casella[4065].Coordinate, "Dgiallo4rosa");
    strcpy(Casella[4066].Coordinate, "Egiallo4rosa");
    strcpy(Casella[4067].Coordinate, "Abianco5rosa");
    strcpy(Casella[4068].Coordinate, "Bbianco5rosa");
    strcpy(Casella[4069].Coordinate, "Cbianco5rosa");
    strcpy(Casella[4070].Coordinate, "Dbianco5rosa");
    strcpy(Casella[4071].Coordinate, "Ebianco5rosa");
    strcpy(Casella[4072].Coordinate, "Fbianco5rosa");
    strcpy(Casella[4073].Coordinate, "Gbianco5rosa");
    strcpy(Casella[4074].Coordinate, "Hbianco5rosa");
    strcpy(Casella[4075].Coordinate, "Ibianco5rosa");
    strcpy(Casella[4076].Coordinate, "Jbianco5rosa");
    strcpy(Casella[4077].Coordinate, "Kbianco5rosa");
    strcpy(Casella[4078].Coordinate, "Lbianco5rosa");
    strcpy(Casella[4079].Coordinate, "Mbianco5rosa");
    strcpy(Casella[4080].Coordinate, "Nbianco5rosa");
    strcpy(Casella[4081].Coordinate, "Obianco5rosa");
    strcpy(Casella[4082].Coordinate, "Pbianco5rosa");
    strcpy(Casella[4083].Coordinate, "Qbianco5rosa");
    strcpy(Casella[4084].Coordinate, "Rbianco5rosa");
    strcpy(Casella[4085].Coordinate, "Sbianco5rosa");
    strcpy(Casella[4086].Coordinate, "Tbianco5rosa");
    strcpy(Casella[4087].Coordinate, "Ubianco5rosa");
    strcpy(Casella[4088].Coordinate, "Vbianco5rosa");
    strcpy(Casella[4089].Coordinate, "Wbianco5rosa");
    strcpy(Casella[4090].Coordinate, "Xbianco5rosa");
    strcpy(Casella[4091].Coordinate, "Ybianco5rosa");
    strcpy(Casella[4092].Coordinate, "Zbianco5rosa");
    strcpy(Casella[4093].Coordinate, "Arosso5rosa");
    strcpy(Casella[4094].Coordinate, "Brosso5rosa");
    strcpy(Casella[4095].Coordinate, "Crosso5rosa");
    strcpy(Casella[4096].Coordinate, "Drosso5rosa");
    strcpy(Casella[4097].Coordinate, "Erosso5rosa");
    strcpy(Casella[4098].Coordinate, "Frosso5rosa");
    strcpy(Casella[4099].Coordinate, "Grosso5rosa");
    strcpy(Casella[4100].Coordinate, "Hrosso5rosa");
    strcpy(Casella[4101].Coordinate, "Irosso5rosa");
    strcpy(Casella[4102].Coordinate, "Jrosso5rosa");
    strcpy(Casella[4103].Coordinate, "Krosso5rosa");
    strcpy(Casella[4104].Coordinate, "Lrosso5rosa");
    strcpy(Casella[4105].Coordinate, "Mrosso5rosa");
    strcpy(Casella[4106].Coordinate, "Nrosso5rosa");
    strcpy(Casella[4107].Coordinate, "Orosso5rosa");
    strcpy(Casella[4108].Coordinate, "Prosso5rosa");
    strcpy(Casella[4109].Coordinate, "Qrosso5rosa");
    strcpy(Casella[4110].Coordinate, "Rrosso5rosa");
    strcpy(Casella[4111].Coordinate, "Srosso5rosa");
    strcpy(Casella[4112].Coordinate, "Trosso5rosa");
    strcpy(Casella[4113].Coordinate, "Urosso5rosa");
    strcpy(Casella[4114].Coordinate, "Vrosso5rosa");
    strcpy(Casella[4115].Coordinate, "Wrosso5rosa");
    strcpy(Casella[4116].Coordinate, "Xrosso5rosa");
    strcpy(Casella[4117].Coordinate, "Yrosso5rosa");
    strcpy(Casella[4118].Coordinate, "Zrosso5rosa");
    strcpy(Casella[4119].Coordinate, "Aazzurro5rosa");
    strcpy(Casella[4120].Coordinate, "Bazzurro5rosa");
    strcpy(Casella[4121].Coordinate, "Cazzurro5rosa");
    strcpy(Casella[4122].Coordinate, "Dazzurro5rosa");
    strcpy(Casella[4123].Coordinate, "Eazzurro5rosa");
    strcpy(Casella[4124].Coordinate, "Fazzurro5rosa");
    strcpy(Casella[4125].Coordinate, "Gazzurro5rosa");
    strcpy(Casella[4126].Coordinate, "Hazzurro5rosa");
    strcpy(Casella[4127].Coordinate, "Iazzurro5rosa");
    strcpy(Casella[4128].Coordinate, "Jazzurro5rosa");
    strcpy(Casella[4129].Coordinate, "Kazzurro5rosa");
    strcpy(Casella[4130].Coordinate, "Lazzurro5rosa");
    strcpy(Casella[4131].Coordinate, "Mazzurro5rosa");
    strcpy(Casella[4132].Coordinate, "Nazzurro5rosa");
    strcpy(Casella[4133].Coordinate, "Oazzurro5rosa");
    strcpy(Casella[4134].Coordinate, "Pazzurro5rosa");
    strcpy(Casella[4135].Coordinate, "Qazzurro5rosa");
    strcpy(Casella[4136].Coordinate, "Razzurro5rosa");
    strcpy(Casella[4137].Coordinate, "Sazzurro5rosa");
    strcpy(Casella[4138].Coordinate, "Tazzurro5rosa");
    strcpy(Casella[4139].Coordinate, "Uazzurro5rosa");
    strcpy(Casella[4140].Coordinate, "Vazzurro5rosa");
    strcpy(Casella[4141].Coordinate, "Wazzurro5rosa");
    strcpy(Casella[4142].Coordinate, "Xazzurro5rosa");
    strcpy(Casella[4143].Coordinate, "Yazzurro5rosa");
    strcpy(Casella[4144].Coordinate, "Zazzurro5rosa");
    strcpy(Casella[4145].Coordinate, "Agiallo5rosa");
    strcpy(Casella[4146].Coordinate, "Bgiallo5rosa");
    strcpy(Casella[4147].Coordinate, "Cgiallo5rosa");
    strcpy(Casella[4148].Coordinate, "Dgiallo5rosa");
    strcpy(Casella[4149].Coordinate, "Egiallo5rosa");
    strcpy(Casella[4150].Coordinate, "Abianco6rosa");
    strcpy(Casella[4151].Coordinate, "Bbianco6rosa");
    strcpy(Casella[4152].Coordinate, "Cbianco6rosa");
    strcpy(Casella[4153].Coordinate, "Dbianco6rosa");
    strcpy(Casella[4154].Coordinate, "Ebianco6rosa");
    strcpy(Casella[4155].Coordinate, "Fbianco6rosa");
    strcpy(Casella[4156].Coordinate, "Gbianco6rosa");
    strcpy(Casella[4157].Coordinate, "Hbianco6rosa");
    strcpy(Casella[4158].Coordinate, "Ibianco6rosa");
    strcpy(Casella[4159].Coordinate, "Jbianco6rosa");
    strcpy(Casella[4160].Coordinate, "Kbianco6rosa");
    strcpy(Casella[4161].Coordinate, "Lbianco6rosa");
    strcpy(Casella[4162].Coordinate, "Mbianco6rosa");
    strcpy(Casella[4163].Coordinate, "Nbianco6rosa");
    strcpy(Casella[4164].Coordinate, "Obianco6rosa");
    strcpy(Casella[4165].Coordinate, "Pbianco6rosa");
    strcpy(Casella[4166].Coordinate, "Qbianco6rosa");
    strcpy(Casella[4167].Coordinate, "Rbianco6rosa");
    strcpy(Casella[4168].Coordinate, "Sbianco6rosa");
    strcpy(Casella[4169].Coordinate, "Tbianco6rosa");
    strcpy(Casella[4170].Coordinate, "Ubianco6rosa");
    strcpy(Casella[4171].Coordinate, "Vbianco6rosa");
    strcpy(Casella[4172].Coordinate, "Wbianco6rosa");
    strcpy(Casella[4173].Coordinate, "Xbianco6rosa");
    strcpy(Casella[4174].Coordinate, "Ybianco6rosa");
    strcpy(Casella[4175].Coordinate, "Zbianco6rosa");
    strcpy(Casella[4176].Coordinate, "Arosso6rosa");
    strcpy(Casella[4177].Coordinate, "Brosso6rosa");
    strcpy(Casella[4178].Coordinate, "Crosso6rosa");
    strcpy(Casella[4179].Coordinate, "Drosso6rosa");
    strcpy(Casella[4180].Coordinate, "Erosso6rosa");
    strcpy(Casella[4181].Coordinate, "Frosso6rosa");
    strcpy(Casella[4182].Coordinate, "Grosso6rosa");
    strcpy(Casella[4183].Coordinate, "Hrosso6rosa");
    strcpy(Casella[4184].Coordinate, "Irosso6rosa");
    strcpy(Casella[4185].Coordinate, "Jrosso6rosa");
    strcpy(Casella[4186].Coordinate, "Krosso6rosa");
    strcpy(Casella[4187].Coordinate, "Lrosso6rosa");
    strcpy(Casella[4188].Coordinate, "Mrosso6rosa");
    strcpy(Casella[4189].Coordinate, "Nrosso6rosa");
    strcpy(Casella[4190].Coordinate, "Orosso6rosa");
    strcpy(Casella[4191].Coordinate, "Prosso6rosa");
    strcpy(Casella[4192].Coordinate, "Qrosso6rosa");
    strcpy(Casella[4193].Coordinate, "Rrosso6rosa");
    strcpy(Casella[4194].Coordinate, "Srosso6rosa");
    strcpy(Casella[4195].Coordinate, "Trosso6rosa");
    strcpy(Casella[4196].Coordinate, "Urosso6rosa");
    strcpy(Casella[4197].Coordinate, "Vrosso6rosa");
    strcpy(Casella[4198].Coordinate, "Wrosso6rosa");
    strcpy(Casella[4199].Coordinate, "Xrosso6rosa");
    strcpy(Casella[4200].Coordinate, "Yrosso6rosa");
    strcpy(Casella[4201].Coordinate, "Zrosso6rosa");
    strcpy(Casella[4202].Coordinate, "Aazzurro6rosa");
    strcpy(Casella[4203].Coordinate, "Bazzurro6rosa");
    strcpy(Casella[4204].Coordinate, "Cazzurro6rosa");
    strcpy(Casella[4205].Coordinate, "Dazzurro6rosa");
    strcpy(Casella[4206].Coordinate, "Eazzurro6rosa");
    strcpy(Casella[4207].Coordinate, "Fazzurro6rosa");
    strcpy(Casella[4208].Coordinate, "Gazzurro6rosa");
    strcpy(Casella[4209].Coordinate, "Hazzurro6rosa");
    strcpy(Casella[4210].Coordinate, "Iazzurro6rosa");
    strcpy(Casella[4211].Coordinate, "Jazzurro6rosa");
    strcpy(Casella[4212].Coordinate, "Kazzurro6rosa");
    strcpy(Casella[4213].Coordinate, "Lazzurro6rosa");
    strcpy(Casella[4214].Coordinate, "Mazzurro6rosa");
    strcpy(Casella[4215].Coordinate, "Nazzurro6rosa");
    strcpy(Casella[4216].Coordinate, "Oazzurro6rosa");
    strcpy(Casella[4217].Coordinate, "Pazzurro6rosa");
    strcpy(Casella[4218].Coordinate, "Qazzurro6rosa");
    strcpy(Casella[4219].Coordinate, "Razzurro6rosa");
    strcpy(Casella[4220].Coordinate, "Sazzurro6rosa");
    strcpy(Casella[4221].Coordinate, "Tazzurro6rosa");
    strcpy(Casella[4222].Coordinate, "Uazzurro6rosa");
    strcpy(Casella[4223].Coordinate, "Vazzurro6rosa");
    strcpy(Casella[4224].Coordinate, "Wazzurro6rosa");
    strcpy(Casella[4225].Coordinate, "Xazzurro6rosa");
    strcpy(Casella[4226].Coordinate, "Yazzurro6rosa");
    strcpy(Casella[4227].Coordinate, "Zazzurro6rosa");
    strcpy(Casella[4228].Coordinate, "Agiallo6rosa");
    strcpy(Casella[4229].Coordinate, "Bgiallo6rosa");
    strcpy(Casella[4230].Coordinate, "Cgiallo6rosa");
    strcpy(Casella[4231].Coordinate, "Dgiallo6rosa");
    strcpy(Casella[4232].Coordinate, "Egiallo6rosa");
    strcpy(Casella[4233].Coordinate, "Abianco7rosa");
    strcpy(Casella[4234].Coordinate, "Bbianco7rosa");
    strcpy(Casella[4235].Coordinate, "Cbianco7rosa");
    strcpy(Casella[4236].Coordinate, "Dbianco7rosa");
    strcpy(Casella[4237].Coordinate, "Ebianco7rosa");
    strcpy(Casella[4238].Coordinate, "Fbianco7rosa");
    strcpy(Casella[4239].Coordinate, "Gbianco7rosa");
    strcpy(Casella[4240].Coordinate, "Hbianco7rosa");
    strcpy(Casella[4241].Coordinate, "Ibianco7rosa");
    strcpy(Casella[4242].Coordinate, "Jbianco7rosa");
    strcpy(Casella[4243].Coordinate, "Kbianco7rosa");
    strcpy(Casella[4244].Coordinate, "Lbianco7rosa");
    strcpy(Casella[4245].Coordinate, "Mbianco7rosa");
    strcpy(Casella[4246].Coordinate, "Nbianco7rosa");
    strcpy(Casella[4247].Coordinate, "Obianco7rosa");
    strcpy(Casella[4248].Coordinate, "Pbianco7rosa");
    strcpy(Casella[4249].Coordinate, "Qbianco7rosa");
    strcpy(Casella[4250].Coordinate, "Rbianco7rosa");
    strcpy(Casella[4251].Coordinate, "Sbianco7rosa");
    strcpy(Casella[4252].Coordinate, "Tbianco7rosa");
    strcpy(Casella[4253].Coordinate, "Ubianco7rosa");
    strcpy(Casella[4254].Coordinate, "Vbianco7rosa");
    strcpy(Casella[4255].Coordinate, "Wbianco7rosa");
    strcpy(Casella[4256].Coordinate, "Xbianco7rosa");
    strcpy(Casella[4257].Coordinate, "Ybianco7rosa");
    strcpy(Casella[4258].Coordinate, "Zbianco7rosa");
    strcpy(Casella[4259].Coordinate, "Arosso7rosa");
    strcpy(Casella[4260].Coordinate, "Brosso7rosa");
    strcpy(Casella[4261].Coordinate, "Crosso7rosa");
    strcpy(Casella[4262].Coordinate, "Drosso7rosa");
    strcpy(Casella[4263].Coordinate, "Erosso7rosa");
    strcpy(Casella[4264].Coordinate, "Frosso7rosa");
    strcpy(Casella[4265].Coordinate, "Grosso7rosa");
    strcpy(Casella[4266].Coordinate, "Hrosso7rosa");
    strcpy(Casella[4267].Coordinate, "Irosso7rosa");
    strcpy(Casella[4268].Coordinate, "Jrosso7rosa");
    strcpy(Casella[4269].Coordinate, "Krosso7rosa");
    strcpy(Casella[4270].Coordinate, "Lrosso7rosa");
    strcpy(Casella[4271].Coordinate, "Mrosso7rosa");
    strcpy(Casella[4272].Coordinate, "Nrosso7rosa");
    strcpy(Casella[4273].Coordinate, "Orosso7rosa");
    strcpy(Casella[4274].Coordinate, "Prosso7rosa");
    strcpy(Casella[4275].Coordinate, "Qrosso7rosa");
    strcpy(Casella[4276].Coordinate, "Rrosso7rosa");
    strcpy(Casella[4277].Coordinate, "Srosso7rosa");
    strcpy(Casella[4278].Coordinate, "Trosso7rosa");
    strcpy(Casella[4279].Coordinate, "Urosso7rosa");
    strcpy(Casella[4280].Coordinate, "Vrosso7rosa");
    strcpy(Casella[4281].Coordinate, "Wrosso7rosa");
    strcpy(Casella[4282].Coordinate, "Xrosso7rosa");
    strcpy(Casella[4283].Coordinate, "Yrosso7rosa");
    strcpy(Casella[4284].Coordinate, "Zrosso7rosa");
    strcpy(Casella[4285].Coordinate, "Aazzurro7rosa");
    strcpy(Casella[4286].Coordinate, "Bazzurro7rosa");
    strcpy(Casella[4287].Coordinate, "Cazzurro7rosa");
    strcpy(Casella[4288].Coordinate, "Dazzurro7rosa");
    strcpy(Casella[4289].Coordinate, "Eazzurro7rosa");
    strcpy(Casella[4290].Coordinate, "Fazzurro7rosa");
    strcpy(Casella[4291].Coordinate, "Gazzurro7rosa");
    strcpy(Casella[4292].Coordinate, "Hazzurro7rosa");
    strcpy(Casella[4293].Coordinate, "Iazzurro7rosa");
    strcpy(Casella[4294].Coordinate, "Jazzurro7rosa");
    strcpy(Casella[4295].Coordinate, "Kazzurro7rosa");
    strcpy(Casella[4296].Coordinate, "Lazzurro7rosa");
    strcpy(Casella[4297].Coordinate, "Mazzurro7rosa");
    strcpy(Casella[4298].Coordinate, "Nazzurro7rosa");
    strcpy(Casella[4299].Coordinate, "Oazzurro7rosa");
    strcpy(Casella[4300].Coordinate, "Pazzurro7rosa");
    strcpy(Casella[4301].Coordinate, "Qazzurro7rosa");
    strcpy(Casella[4302].Coordinate, "Razzurro7rosa");
    strcpy(Casella[4303].Coordinate, "Sazzurro7rosa");
    strcpy(Casella[4304].Coordinate, "Tazzurro7rosa");
    strcpy(Casella[4305].Coordinate, "Uazzurro7rosa");
    strcpy(Casella[4306].Coordinate, "Vazzurro7rosa");
    strcpy(Casella[4307].Coordinate, "Wazzurro7rosa");
    strcpy(Casella[4308].Coordinate, "Xazzurro7rosa");
    strcpy(Casella[4309].Coordinate, "Yazzurro7rosa");
    strcpy(Casella[4310].Coordinate, "Zazzurro7rosa");
    strcpy(Casella[4311].Coordinate, "Agiallo7rosa");
    strcpy(Casella[4312].Coordinate, "Bgiallo7rosa");
    strcpy(Casella[4313].Coordinate, "Cgiallo7rosa");
    strcpy(Casella[4314].Coordinate, "Dgiallo7rosa");
    strcpy(Casella[4315].Coordinate, "Egiallo7rosa");
    strcpy(Casella[4316].Coordinate, "Abianco8rosa");
    strcpy(Casella[4317].Coordinate, "Bbianco8rosa");
    strcpy(Casella[4318].Coordinate, "Cbianco8rosa");
    strcpy(Casella[4319].Coordinate, "Dbianco8rosa");
    strcpy(Casella[4320].Coordinate, "Ebianco8rosa");
    strcpy(Casella[4321].Coordinate, "Fbianco8rosa");
    strcpy(Casella[4322].Coordinate, "Gbianco8rosa");
    strcpy(Casella[4323].Coordinate, "Hbianco8rosa");
    strcpy(Casella[4324].Coordinate, "Ibianco8rosa");
    strcpy(Casella[4325].Coordinate, "Jbianco8rosa");
    strcpy(Casella[4326].Coordinate, "Kbianco8rosa");
    strcpy(Casella[4327].Coordinate, "Lbianco8rosa");
    strcpy(Casella[4328].Coordinate, "Mbianco8rosa");
    strcpy(Casella[4329].Coordinate, "Nbianco8rosa");
    strcpy(Casella[4330].Coordinate, "Obianco8rosa");
    strcpy(Casella[4331].Coordinate, "Pbianco8rosa");
    strcpy(Casella[4332].Coordinate, "Qbianco8rosa");
    strcpy(Casella[4333].Coordinate, "Rbianco8rosa");
    strcpy(Casella[4334].Coordinate, "Sbianco8rosa");
    strcpy(Casella[4335].Coordinate, "Tbianco8rosa");
    strcpy(Casella[4336].Coordinate, "Ubianco8rosa");
    strcpy(Casella[4337].Coordinate, "Vbianco8rosa");
    strcpy(Casella[4338].Coordinate, "Wbianco8rosa");
    strcpy(Casella[4339].Coordinate, "Xbianco8rosa");
    strcpy(Casella[4340].Coordinate, "Ybianco8rosa");
    strcpy(Casella[4341].Coordinate, "Zbianco8rosa");
    strcpy(Casella[4342].Coordinate, "Arosso8rosa");
    strcpy(Casella[4343].Coordinate, "Brosso8rosa");
    strcpy(Casella[4344].Coordinate, "Crosso8rosa");
    strcpy(Casella[4345].Coordinate, "Drosso8rosa");
    strcpy(Casella[4346].Coordinate, "Erosso8rosa");
    strcpy(Casella[4347].Coordinate, "Frosso8rosa");
    strcpy(Casella[4348].Coordinate, "Grosso8rosa");
    strcpy(Casella[4349].Coordinate, "Hrosso8rosa");
    strcpy(Casella[4350].Coordinate, "Irosso8rosa");
    strcpy(Casella[4351].Coordinate, "Jrosso8rosa");
    strcpy(Casella[4352].Coordinate, "Krosso8rosa");
    strcpy(Casella[4353].Coordinate, "Lrosso8rosa");
    strcpy(Casella[4354].Coordinate, "Mrosso8rosa");
    strcpy(Casella[4355].Coordinate, "Nrosso8rosa");
    strcpy(Casella[4356].Coordinate, "Orosso8rosa");
    strcpy(Casella[4357].Coordinate, "Prosso8rosa");
    strcpy(Casella[4358].Coordinate, "Qrosso8rosa");
    strcpy(Casella[4359].Coordinate, "Rrosso8rosa");
    strcpy(Casella[4360].Coordinate, "Srosso8rosa");
    strcpy(Casella[4361].Coordinate, "Trosso8rosa");
    strcpy(Casella[4362].Coordinate, "Urosso8rosa");
    strcpy(Casella[4363].Coordinate, "Vrosso8rosa");
    strcpy(Casella[4364].Coordinate, "Wrosso8rosa");
    strcpy(Casella[4365].Coordinate, "Xrosso8rosa");
    strcpy(Casella[4366].Coordinate, "Yrosso8rosa");
    strcpy(Casella[4367].Coordinate, "Zrosso8rosa");
    strcpy(Casella[4368].Coordinate, "Aazzurro8rosa");
    strcpy(Casella[4369].Coordinate, "Bazzurro8rosa");
    strcpy(Casella[4370].Coordinate, "Cazzurro8rosa");
    strcpy(Casella[4371].Coordinate, "Dazzurro8rosa");
    strcpy(Casella[4372].Coordinate, "Eazzurro8rosa");
    strcpy(Casella[4373].Coordinate, "Fazzurro8rosa");
    strcpy(Casella[4374].Coordinate, "Gazzurro8rosa");
    strcpy(Casella[4375].Coordinate, "Hazzurro8rosa");
    strcpy(Casella[4376].Coordinate, "Iazzurro8rosa");
    strcpy(Casella[4377].Coordinate, "Jazzurro8rosa");
    strcpy(Casella[4378].Coordinate, "Kazzurro8rosa");
    strcpy(Casella[4379].Coordinate, "Lazzurro8rosa");
    strcpy(Casella[4380].Coordinate, "Mazzurro8rosa");
    strcpy(Casella[4381].Coordinate, "Nazzurro8rosa");
    strcpy(Casella[4382].Coordinate, "Oazzurro8rosa");
    strcpy(Casella[4383].Coordinate, "Pazzurro8rosa");
    strcpy(Casella[4384].Coordinate, "Qazzurro8rosa");
    strcpy(Casella[4385].Coordinate, "Razzurro8rosa");
    strcpy(Casella[4386].Coordinate, "Sazzurro8rosa");
    strcpy(Casella[4387].Coordinate, "Tazzurro8rosa");
    strcpy(Casella[4388].Coordinate, "Uazzurro8rosa");
    strcpy(Casella[4389].Coordinate, "Vazzurro8rosa");
    strcpy(Casella[4390].Coordinate, "Wazzurro8rosa");
    strcpy(Casella[4391].Coordinate, "Xazzurro8rosa");
    strcpy(Casella[4392].Coordinate, "Yazzurro8rosa");
    strcpy(Casella[4393].Coordinate, "Zazzurro8rosa");
    strcpy(Casella[4394].Coordinate, "Agiallo8rosa");
    strcpy(Casella[4395].Coordinate, "Bgiallo8rosa");
    strcpy(Casella[4396].Coordinate, "Cgiallo8rosa");
    strcpy(Casella[4397].Coordinate, "Dgiallo8rosa");
    strcpy(Casella[4398].Coordinate, "Egiallo8rosa");
    strcpy(Casella[4399].Coordinate, "Abianco9rosa");
    strcpy(Casella[4400].Coordinate, "Bbianco9rosa");
    strcpy(Casella[4401].Coordinate, "Cbianco9rosa");
    strcpy(Casella[4402].Coordinate, "Dbianco9rosa");
    strcpy(Casella[4403].Coordinate, "Ebianco9rosa");
    strcpy(Casella[4404].Coordinate, "Fbianco9rosa");
    strcpy(Casella[4405].Coordinate, "Gbianco9rosa");
    strcpy(Casella[4406].Coordinate, "Hbianco9rosa");
    strcpy(Casella[4407].Coordinate, "Ibianco9rosa");
    strcpy(Casella[4408].Coordinate, "Jbianco9rosa");
    strcpy(Casella[4409].Coordinate, "Kbianco9rosa");
    strcpy(Casella[4410].Coordinate, "Lbianco9rosa");
    strcpy(Casella[4411].Coordinate, "Mbianco9rosa");
    strcpy(Casella[4412].Coordinate, "Nbianco9rosa");
    strcpy(Casella[4413].Coordinate, "Obianco9rosa");
    strcpy(Casella[4414].Coordinate, "Pbianco9rosa");
    strcpy(Casella[4415].Coordinate, "Qbianco9rosa");
    strcpy(Casella[4416].Coordinate, "Rbianco9rosa");
    strcpy(Casella[4417].Coordinate, "Sbianco9rosa");
    strcpy(Casella[4418].Coordinate, "Tbianco9rosa");
    strcpy(Casella[4419].Coordinate, "Ubianco9rosa");
    strcpy(Casella[4420].Coordinate, "Vbianco9rosa");
    strcpy(Casella[4421].Coordinate, "Wbianco9rosa");
    strcpy(Casella[4422].Coordinate, "Xbianco9rosa");
    strcpy(Casella[4423].Coordinate, "Ybianco9rosa");
    strcpy(Casella[4424].Coordinate, "Zbianco9rosa");
    strcpy(Casella[4425].Coordinate, "Arosso9rosa");
    strcpy(Casella[4426].Coordinate, "Brosso9rosa");
    strcpy(Casella[4427].Coordinate, "Crosso9rosa");
    strcpy(Casella[4428].Coordinate, "Drosso9rosa");
    strcpy(Casella[4429].Coordinate, "Erosso9rosa");
    strcpy(Casella[4430].Coordinate, "Frosso9rosa");
    strcpy(Casella[4431].Coordinate, "Grosso9rosa");
    strcpy(Casella[4432].Coordinate, "Hrosso9rosa");
    strcpy(Casella[4433].Coordinate, "Irosso9rosa");
    strcpy(Casella[4434].Coordinate, "Jrosso9rosa");
    strcpy(Casella[4435].Coordinate, "Krosso9rosa");
    strcpy(Casella[4436].Coordinate, "Lrosso9rosa");
    strcpy(Casella[4437].Coordinate, "Mrosso9rosa");
    strcpy(Casella[4438].Coordinate, "Nrosso9rosa");
    strcpy(Casella[4439].Coordinate, "Orosso9rosa");
    strcpy(Casella[4440].Coordinate, "Prosso9rosa");
    strcpy(Casella[4441].Coordinate, "Qrosso9rosa");
    strcpy(Casella[4442].Coordinate, "Rrosso9rosa");
    strcpy(Casella[4443].Coordinate, "Srosso9rosa");
    strcpy(Casella[4444].Coordinate, "Trosso9rosa");
    strcpy(Casella[4445].Coordinate, "Urosso9rosa");
    strcpy(Casella[4446].Coordinate, "Vrosso9rosa");
    strcpy(Casella[4447].Coordinate, "Wrosso9rosa");
    strcpy(Casella[4448].Coordinate, "Xrosso9rosa");
    strcpy(Casella[4449].Coordinate, "Yrosso9rosa");
    strcpy(Casella[4450].Coordinate, "Zrosso9rosa");
    strcpy(Casella[4451].Coordinate, "Aazzurro9rosa");
    strcpy(Casella[4452].Coordinate, "Bazzurro9rosa");
    strcpy(Casella[4453].Coordinate, "Cazzurro9rosa");
    strcpy(Casella[4454].Coordinate, "Dazzurro9rosa");
    strcpy(Casella[4455].Coordinate, "Eazzurro9rosa");
    strcpy(Casella[4456].Coordinate, "Fazzurro9rosa");
    strcpy(Casella[4457].Coordinate, "Gazzurro9rosa");
    strcpy(Casella[4458].Coordinate, "Hazzurro9rosa");
    strcpy(Casella[4459].Coordinate, "Iazzurro9rosa");
    strcpy(Casella[4460].Coordinate, "Jazzurro9rosa");
    strcpy(Casella[4461].Coordinate, "Kazzurro9rosa");
    strcpy(Casella[4462].Coordinate, "Lazzurro9rosa");
    strcpy(Casella[4463].Coordinate, "Mazzurro9rosa");
    strcpy(Casella[4464].Coordinate, "Nazzurro9rosa");
    strcpy(Casella[4465].Coordinate, "Oazzurro9rosa");
    strcpy(Casella[4466].Coordinate, "Pazzurro9rosa");
    strcpy(Casella[4467].Coordinate, "Qazzurro9rosa");
    strcpy(Casella[4468].Coordinate, "Razzurro9rosa");
    strcpy(Casella[4469].Coordinate, "Sazzurro9rosa");
    strcpy(Casella[4470].Coordinate, "Tazzurro9rosa");
    strcpy(Casella[4471].Coordinate, "Uazzurro9rosa");
    strcpy(Casella[4472].Coordinate, "Vazzurro9rosa");
    strcpy(Casella[4473].Coordinate, "Wazzurro9rosa");
    strcpy(Casella[4474].Coordinate, "Xazzurro9rosa");
    strcpy(Casella[4475].Coordinate, "Yazzurro9rosa");
    strcpy(Casella[4476].Coordinate, "Zazzurro9rosa");
    strcpy(Casella[4477].Coordinate, "Agiallo9rosa");
    strcpy(Casella[4478].Coordinate, "Bgiallo9rosa");
    strcpy(Casella[4479].Coordinate, "Cgiallo9rosa");
    strcpy(Casella[4480].Coordinate, "Dgiallo9rosa");
    strcpy(Casella[4481].Coordinate, "Egiallo9rosa");
    strcpy(Casella[4482].Coordinate, "Abianco1blu");
    strcpy(Casella[4483].Coordinate, "Bbianco1blu");
    strcpy(Casella[4484].Coordinate, "Cbianco1blu");
    strcpy(Casella[4485].Coordinate, "Dbianco1blu");
    strcpy(Casella[4486].Coordinate, "Ebianco1blu");
    strcpy(Casella[4487].Coordinate, "Fbianco1blu");
    strcpy(Casella[4488].Coordinate, "Gbianco1blu");
    strcpy(Casella[4489].Coordinate, "Hbianco1blu");
    strcpy(Casella[4490].Coordinate, "Ibianco1blu");
    strcpy(Casella[4491].Coordinate, "Jbianco1blu");
    strcpy(Casella[4492].Coordinate, "Kbianco1blu");
    strcpy(Casella[4493].Coordinate, "Lbianco1blu");
    strcpy(Casella[4494].Coordinate, "Mbianco1blu");
    strcpy(Casella[4495].Coordinate, "Nbianco1blu");
    strcpy(Casella[4496].Coordinate, "Obianco1blu");
    strcpy(Casella[4497].Coordinate, "Pbianco1blu");
    strcpy(Casella[4498].Coordinate, "Qbianco1blu");
    strcpy(Casella[4499].Coordinate, "Rbianco1blu");
    strcpy(Casella[4500].Coordinate, "Sbianco1blu");
    strcpy(Casella[4501].Coordinate, "Tbianco1blu");
    strcpy(Casella[4502].Coordinate, "Ubianco1blu");
    strcpy(Casella[4503].Coordinate, "Vbianco1blu");
    strcpy(Casella[4504].Coordinate, "Wbianco1blu");
    strcpy(Casella[4505].Coordinate, "Xbianco1blu");
    strcpy(Casella[4506].Coordinate, "Ybianco1blu");
    strcpy(Casella[4507].Coordinate, "Zbianco1blu");
    strcpy(Casella[4508].Coordinate, "Arosso1blu");
    strcpy(Casella[4509].Coordinate, "Brosso1blu");
    strcpy(Casella[4510].Coordinate, "Crosso1blu");
    strcpy(Casella[4511].Coordinate, "Drosso1blu");
    strcpy(Casella[4512].Coordinate, "Erosso1blu");
    strcpy(Casella[4513].Coordinate, "Frosso1blu");
    strcpy(Casella[4514].Coordinate, "Grosso1blu");
    strcpy(Casella[4515].Coordinate, "Hrosso1blu");
    strcpy(Casella[4516].Coordinate, "Irosso1blu");
    strcpy(Casella[4517].Coordinate, "Jrosso1blu");
    strcpy(Casella[4518].Coordinate, "Krosso1blu");
    strcpy(Casella[4519].Coordinate, "Lrosso1blu");
    strcpy(Casella[4520].Coordinate, "Mrosso1blu");
    strcpy(Casella[4521].Coordinate, "Nrosso1blu");
    strcpy(Casella[4522].Coordinate, "Orosso1blu");
    strcpy(Casella[4523].Coordinate, "Prosso1blu");
    strcpy(Casella[4524].Coordinate, "Qrosso1blu");
    strcpy(Casella[4525].Coordinate, "Rrosso1blu");
    strcpy(Casella[4526].Coordinate, "Srosso1blu");
    strcpy(Casella[4527].Coordinate, "Trosso1blu");
    strcpy(Casella[4528].Coordinate, "Urosso1blu");
    strcpy(Casella[4529].Coordinate, "Vrosso1blu");
    strcpy(Casella[4530].Coordinate, "Wrosso1blu");
    strcpy(Casella[4531].Coordinate, "Xrosso1blu");
    strcpy(Casella[4532].Coordinate, "Yrosso1blu");
    strcpy(Casella[4533].Coordinate, "Zrosso1blu");
    strcpy(Casella[4534].Coordinate, "Aazzurro1blu");
    strcpy(Casella[4535].Coordinate, "Bazzurro1blu");
    strcpy(Casella[4536].Coordinate, "Cazzurro1blu");
    strcpy(Casella[4537].Coordinate, "Dazzurro1blu");
    strcpy(Casella[4538].Coordinate, "Eazzurro1blu");
    strcpy(Casella[4539].Coordinate, "Fazzurro1blu");
    strcpy(Casella[4540].Coordinate, "Gazzurro1blu");
    strcpy(Casella[4541].Coordinate, "Hazzurro1blu");
    strcpy(Casella[4542].Coordinate, "Iazzurro1blu");
    strcpy(Casella[4543].Coordinate, "Jazzurro1blu");
    strcpy(Casella[4544].Coordinate, "Kazzurro1blu");
    strcpy(Casella[4545].Coordinate, "Lazzurro1blu");
    strcpy(Casella[4546].Coordinate, "Mazzurro1blu");
    strcpy(Casella[4547].Coordinate, "Nazzurro1blu");
    strcpy(Casella[4548].Coordinate, "Oazzurro1blu");
    strcpy(Casella[4549].Coordinate, "Pazzurro1blu");
    strcpy(Casella[4550].Coordinate, "Qazzurro1blu");
    strcpy(Casella[4551].Coordinate, "Razzurro1blu");
    strcpy(Casella[4552].Coordinate, "Sazzurro1blu");
    strcpy(Casella[4553].Coordinate, "Tazzurro1blu");
    strcpy(Casella[4554].Coordinate, "Uazzurro1blu");
    strcpy(Casella[4555].Coordinate, "Vazzurro1blu");
    strcpy(Casella[4556].Coordinate, "Wazzurro1blu");
    strcpy(Casella[4557].Coordinate, "Xazzurro1blu");
    strcpy(Casella[4558].Coordinate, "Yazzurro1blu");
    strcpy(Casella[4559].Coordinate, "Zazzurro1blu");
    strcpy(Casella[4560].Coordinate, "Agiallo1blu");
    strcpy(Casella[4561].Coordinate, "Bgiallo1blu");
    strcpy(Casella[4562].Coordinate, "Cgiallo1blu");
    strcpy(Casella[4563].Coordinate, "Dgiallo1blu");
    strcpy(Casella[4564].Coordinate, "Egiallo1blu");
    strcpy(Casella[4565].Coordinate, "Abianco2blu");
    strcpy(Casella[4566].Coordinate, "Bbianco2blu");
    strcpy(Casella[4567].Coordinate, "Cbianco2blu");
    strcpy(Casella[4568].Coordinate, "Dbianco2blu");
    strcpy(Casella[4569].Coordinate, "Ebianco2blu");
    strcpy(Casella[4570].Coordinate, "Fbianco2blu");
    strcpy(Casella[4571].Coordinate, "Gbianco2blu");
    strcpy(Casella[4572].Coordinate, "Hbianco2blu");
    strcpy(Casella[4573].Coordinate, "Ibianco2blu");
    strcpy(Casella[4574].Coordinate, "Jbianco2blu");
    strcpy(Casella[4575].Coordinate, "Kbianco2blu");
    strcpy(Casella[4576].Coordinate, "Lbianco2blu");
    strcpy(Casella[4577].Coordinate, "Mbianco2blu");
    strcpy(Casella[4578].Coordinate, "Nbianco2blu");
    strcpy(Casella[4579].Coordinate, "Obianco2blu");
    strcpy(Casella[4580].Coordinate, "Pbianco2blu");
    strcpy(Casella[4581].Coordinate, "Qbianco2blu");
    strcpy(Casella[4582].Coordinate, "Rbianco2blu");
    strcpy(Casella[4583].Coordinate, "Sbianco2blu");
    strcpy(Casella[4584].Coordinate, "Tbianco2blu");
    strcpy(Casella[4585].Coordinate, "Ubianco2blu");
    strcpy(Casella[4586].Coordinate, "Vbianco2blu");
    strcpy(Casella[4587].Coordinate, "Wbianco2blu");
    strcpy(Casella[4588].Coordinate, "Xbianco2blu");
    strcpy(Casella[4589].Coordinate, "Ybianco2blu");
    strcpy(Casella[4590].Coordinate, "Zbianco2blu");
    strcpy(Casella[4591].Coordinate, "Arosso2blu");
    strcpy(Casella[4592].Coordinate, "Brosso2blu");
    strcpy(Casella[4593].Coordinate, "Crosso2blu");
    strcpy(Casella[4594].Coordinate, "Drosso2blu");
    strcpy(Casella[4595].Coordinate, "Erosso2blu");
    strcpy(Casella[4596].Coordinate, "Frosso2blu");
    strcpy(Casella[4597].Coordinate, "Grosso2blu");
    strcpy(Casella[4598].Coordinate, "Hrosso2blu");
    strcpy(Casella[4599].Coordinate, "Irosso2blu");
    strcpy(Casella[4600].Coordinate, "Jrosso2blu");
    strcpy(Casella[4601].Coordinate, "Krosso2blu");
    strcpy(Casella[4602].Coordinate, "Lrosso2blu");
    strcpy(Casella[4603].Coordinate, "Mrosso2blu");
    strcpy(Casella[4604].Coordinate, "Nrosso2blu");
    strcpy(Casella[4605].Coordinate, "Orosso2blu");
    strcpy(Casella[4606].Coordinate, "Prosso2blu");
    strcpy(Casella[4607].Coordinate, "Qrosso2blu");
    strcpy(Casella[4608].Coordinate, "Rrosso2blu");
    strcpy(Casella[4609].Coordinate, "Srosso2blu");
    strcpy(Casella[4610].Coordinate, "Trosso2blu");
    strcpy(Casella[4611].Coordinate, "Urosso2blu");
    strcpy(Casella[4612].Coordinate, "Vrosso2blu");
    strcpy(Casella[4613].Coordinate, "Wrosso2blu");
    strcpy(Casella[4614].Coordinate, "Xrosso2blu");
    strcpy(Casella[4615].Coordinate, "Yrosso2blu");
    strcpy(Casella[4616].Coordinate, "Zrosso2blu");
    strcpy(Casella[4617].Coordinate, "Aazzurro2blu");
    strcpy(Casella[4618].Coordinate, "Bazzurro2blu");
    strcpy(Casella[4619].Coordinate, "Cazzurro2blu");
    strcpy(Casella[4620].Coordinate, "Dazzurro2blu");
    strcpy(Casella[4621].Coordinate, "Eazzurro2blu");
    strcpy(Casella[4622].Coordinate, "Fazzurro2blu");
    strcpy(Casella[4623].Coordinate, "Gazzurro2blu");
    strcpy(Casella[4624].Coordinate, "Hazzurro2blu");
    strcpy(Casella[4625].Coordinate, "Iazzurro2blu");
    strcpy(Casella[4626].Coordinate, "Jazzurro2blu");
    strcpy(Casella[4627].Coordinate, "Kazzurro2blu");
    strcpy(Casella[4628].Coordinate, "Lazzurro2blu");
    strcpy(Casella[4629].Coordinate, "Mazzurro2blu");
    strcpy(Casella[4630].Coordinate, "Nazzurro2blu");
    strcpy(Casella[4631].Coordinate, "Oazzurro2blu");
    strcpy(Casella[4632].Coordinate, "Pazzurro2blu");
    strcpy(Casella[4633].Coordinate, "Qazzurro2blu");
    strcpy(Casella[4634].Coordinate, "Razzurro2blu");
    strcpy(Casella[4635].Coordinate, "Sazzurro2blu");
    strcpy(Casella[4636].Coordinate, "Tazzurro2blu");
    strcpy(Casella[4637].Coordinate, "Uazzurro2blu");
    strcpy(Casella[4638].Coordinate, "Vazzurro2blu");
    strcpy(Casella[4639].Coordinate, "Wazzurro2blu");
    strcpy(Casella[4640].Coordinate, "Xazzurro2blu");
    strcpy(Casella[4641].Coordinate, "Yazzurro2blu");
    strcpy(Casella[4642].Coordinate, "Zazzurro2blu");
    strcpy(Casella[4643].Coordinate, "Agiallo2blu");
    strcpy(Casella[4644].Coordinate, "Bgiallo2blu");
    strcpy(Casella[4645].Coordinate, "Cgiallo2blu");
    strcpy(Casella[4646].Coordinate, "Dgiallo2blu");
    strcpy(Casella[4647].Coordinate, "Egiallo2blu");
    strcpy(Casella[4648].Coordinate, "Abianco3blu");
    strcpy(Casella[4649].Coordinate, "Bbianco3blu");
    strcpy(Casella[4650].Coordinate, "Cbianco3blu");
    strcpy(Casella[4651].Coordinate, "Dbianco3blu");
    strcpy(Casella[4652].Coordinate, "Ebianco3blu");
    strcpy(Casella[4653].Coordinate, "Fbianco3blu");
    strcpy(Casella[4654].Coordinate, "Gbianco3blu");
    strcpy(Casella[4655].Coordinate, "Hbianco3blu");
    strcpy(Casella[4656].Coordinate, "Ibianco3blu");
    strcpy(Casella[4657].Coordinate, "Jbianco3blu");
    strcpy(Casella[4658].Coordinate, "Kbianco3blu");
    strcpy(Casella[4659].Coordinate, "Lbianco3blu");
    strcpy(Casella[4660].Coordinate, "Mbianco3blu");
    strcpy(Casella[4661].Coordinate, "Nbianco3blu");
    strcpy(Casella[4662].Coordinate, "Obianco3blu");
    strcpy(Casella[4663].Coordinate, "Pbianco3blu");
    strcpy(Casella[4664].Coordinate, "Qbianco3blu");
    strcpy(Casella[4665].Coordinate, "Rbianco3blu");
    strcpy(Casella[4666].Coordinate, "Sbianco3blu");
    strcpy(Casella[4667].Coordinate, "Tbianco3blu");
    strcpy(Casella[4668].Coordinate, "Ubianco3blu");
    strcpy(Casella[4669].Coordinate, "Vbianco3blu");
    strcpy(Casella[4670].Coordinate, "Wbianco3blu");
    strcpy(Casella[4671].Coordinate, "Xbianco3blu");
    strcpy(Casella[4672].Coordinate, "Ybianco3blu");
    strcpy(Casella[4673].Coordinate, "Zbianco3blu");
    strcpy(Casella[4674].Coordinate, "Arosso3blu");
    strcpy(Casella[4675].Coordinate, "Brosso3blu");
    strcpy(Casella[4676].Coordinate, "Crosso3blu");
    strcpy(Casella[4677].Coordinate, "Drosso3blu");
    strcpy(Casella[4678].Coordinate, "Erosso3blu");
    strcpy(Casella[4679].Coordinate, "Frosso3blu");
    strcpy(Casella[4680].Coordinate, "Grosso3blu");
    strcpy(Casella[4681].Coordinate, "Hrosso3blu");
    strcpy(Casella[4682].Coordinate, "Irosso3blu");
    strcpy(Casella[4683].Coordinate, "Jrosso3blu");
    strcpy(Casella[4684].Coordinate, "Krosso3blu");
    strcpy(Casella[4685].Coordinate, "Lrosso3blu");
    strcpy(Casella[4686].Coordinate, "Mrosso3blu");
    strcpy(Casella[4687].Coordinate, "Nrosso3blu");
    strcpy(Casella[4688].Coordinate, "Orosso3blu");
    strcpy(Casella[4689].Coordinate, "Prosso3blu");
    strcpy(Casella[4690].Coordinate, "Qrosso3blu");
    strcpy(Casella[4691].Coordinate, "Rrosso3blu");
    strcpy(Casella[4692].Coordinate, "Srosso3blu");
    strcpy(Casella[4693].Coordinate, "Trosso3blu");
    strcpy(Casella[4694].Coordinate, "Urosso3blu");
    strcpy(Casella[4695].Coordinate, "Vrosso3blu");
    strcpy(Casella[4696].Coordinate, "Wrosso3blu");
    strcpy(Casella[4697].Coordinate, "Xrosso3blu");
    strcpy(Casella[4698].Coordinate, "Yrosso3blu");
    strcpy(Casella[4699].Coordinate, "Zrosso3blu");
    strcpy(Casella[4700].Coordinate, "Aazzurro3blu");
    strcpy(Casella[4701].Coordinate, "Bazzurro3blu");
    strcpy(Casella[4702].Coordinate, "Cazzurro3blu");
    strcpy(Casella[4703].Coordinate, "Dazzurro3blu");
    strcpy(Casella[4704].Coordinate, "Eazzurro3blu");
    strcpy(Casella[4705].Coordinate, "Fazzurro3blu");
    strcpy(Casella[4706].Coordinate, "Gazzurro3blu");
    strcpy(Casella[4707].Coordinate, "Hazzurro3blu");
    strcpy(Casella[4708].Coordinate, "Iazzurro3blu");
    strcpy(Casella[4709].Coordinate, "Jazzurro3blu");
    strcpy(Casella[4710].Coordinate, "Kazzurro3blu");
    strcpy(Casella[4711].Coordinate, "Lazzurro3blu");
    strcpy(Casella[4712].Coordinate, "Mazzurro3blu");
    strcpy(Casella[4713].Coordinate, "Nazzurro3blu");
    strcpy(Casella[4714].Coordinate, "Oazzurro3blu");
    strcpy(Casella[4715].Coordinate, "Pazzurro3blu");
    strcpy(Casella[4716].Coordinate, "Qazzurro3blu");
    strcpy(Casella[4717].Coordinate, "Razzurro3blu");
    strcpy(Casella[4718].Coordinate, "Sazzurro3blu");
    strcpy(Casella[4719].Coordinate, "Tazzurro3blu");
    strcpy(Casella[4720].Coordinate, "Uazzurro3blu");
    strcpy(Casella[4721].Coordinate, "Vazzurro3blu");
    strcpy(Casella[4722].Coordinate, "Wazzurro3blu");
    strcpy(Casella[4723].Coordinate, "Xazzurro3blu");
    strcpy(Casella[4724].Coordinate, "Yazzurro3blu");
    strcpy(Casella[4725].Coordinate, "Zazzurro3blu");
    strcpy(Casella[4726].Coordinate, "Agiallo3blu");
    strcpy(Casella[4727].Coordinate, "Bgiallo3blu");
    strcpy(Casella[4728].Coordinate, "Cgiallo3blu");
    strcpy(Casella[4729].Coordinate, "Dgiallo3blu");
    strcpy(Casella[4730].Coordinate, "Egiallo3blu");
    strcpy(Casella[4731].Coordinate, "Abianco4blu");
    strcpy(Casella[4732].Coordinate, "Bbianco4blu");
    strcpy(Casella[4733].Coordinate, "Cbianco4blu");
    strcpy(Casella[4734].Coordinate, "Dbianco4blu");
    strcpy(Casella[4735].Coordinate, "Ebianco4blu");
    strcpy(Casella[4736].Coordinate, "Fbianco4blu");
    strcpy(Casella[4737].Coordinate, "Gbianco4blu");
    strcpy(Casella[4738].Coordinate, "Hbianco4blu");
    strcpy(Casella[4739].Coordinate, "Ibianco4blu");
    strcpy(Casella[4740].Coordinate, "Jbianco4blu");
    strcpy(Casella[4741].Coordinate, "Kbianco4blu");
    strcpy(Casella[4742].Coordinate, "Lbianco4blu");
    strcpy(Casella[4743].Coordinate, "Mbianco4blu");
    strcpy(Casella[4744].Coordinate, "Nbianco4blu");
    strcpy(Casella[4745].Coordinate, "Obianco4blu");
    strcpy(Casella[4746].Coordinate, "Pbianco4blu");
    strcpy(Casella[4747].Coordinate, "Qbianco4blu");
    strcpy(Casella[4748].Coordinate, "Rbianco4blu");
    strcpy(Casella[4749].Coordinate, "Sbianco4blu");
    strcpy(Casella[4750].Coordinate, "Tbianco4blu");
    strcpy(Casella[4751].Coordinate, "Ubianco4blu");
    strcpy(Casella[4752].Coordinate, "Vbianco4blu");
    strcpy(Casella[4753].Coordinate, "Wbianco4blu");
    strcpy(Casella[4754].Coordinate, "Xbianco4blu");
    strcpy(Casella[4755].Coordinate, "Ybianco4blu");
    strcpy(Casella[4756].Coordinate, "Zbianco4blu");
    strcpy(Casella[4757].Coordinate, "Arosso4blu");
    strcpy(Casella[4758].Coordinate, "Brosso4blu");
    strcpy(Casella[4759].Coordinate, "Crosso4blu");
    strcpy(Casella[4760].Coordinate, "Drosso4blu");
    strcpy(Casella[4761].Coordinate, "Erosso4blu");
    strcpy(Casella[4762].Coordinate, "Frosso4blu");
    strcpy(Casella[4763].Coordinate, "Grosso4blu");
    strcpy(Casella[4764].Coordinate, "Hrosso4blu");
    strcpy(Casella[4765].Coordinate, "Irosso4blu");
    strcpy(Casella[4766].Coordinate, "Jrosso4blu");
    strcpy(Casella[4767].Coordinate, "Krosso4blu");
    strcpy(Casella[4768].Coordinate, "Lrosso4blu");
    strcpy(Casella[4769].Coordinate, "Mrosso4blu");
    strcpy(Casella[4770].Coordinate, "Nrosso4blu");
    strcpy(Casella[4771].Coordinate, "Orosso4blu");
    strcpy(Casella[4772].Coordinate, "Prosso4blu");
    strcpy(Casella[4773].Coordinate, "Qrosso4blu");
    strcpy(Casella[4774].Coordinate, "Rrosso4blu");
    strcpy(Casella[4775].Coordinate, "Srosso4blu");
    strcpy(Casella[4776].Coordinate, "Trosso4blu");
    strcpy(Casella[4777].Coordinate, "Urosso4blu");
    strcpy(Casella[4778].Coordinate, "Vrosso4blu");
    strcpy(Casella[4779].Coordinate, "Wrosso4blu");
    strcpy(Casella[4780].Coordinate, "Xrosso4blu");
    strcpy(Casella[4781].Coordinate, "Yrosso4blu");
    strcpy(Casella[4782].Coordinate, "Zrosso4blu");
    strcpy(Casella[4783].Coordinate, "Aazzurro4blu");
    strcpy(Casella[4784].Coordinate, "Bazzurro4blu");
    strcpy(Casella[4785].Coordinate, "Cazzurro4blu");
    strcpy(Casella[4786].Coordinate, "Dazzurro4blu");
    strcpy(Casella[4787].Coordinate, "Eazzurro4blu");
    strcpy(Casella[4788].Coordinate, "Fazzurro4blu");
    strcpy(Casella[4789].Coordinate, "Gazzurro4blu");
    strcpy(Casella[4790].Coordinate, "Hazzurro4blu");
    strcpy(Casella[4791].Coordinate, "Iazzurro4blu");
    strcpy(Casella[4792].Coordinate, "Jazzurro4blu");
    strcpy(Casella[4793].Coordinate, "Kazzurro4blu");
    strcpy(Casella[4794].Coordinate, "Lazzurro4blu");
    strcpy(Casella[4795].Coordinate, "Mazzurro4blu");
    strcpy(Casella[4796].Coordinate, "Nazzurro4blu");
    strcpy(Casella[4797].Coordinate, "Oazzurro4blu");
    strcpy(Casella[4798].Coordinate, "Pazzurro4blu");
    strcpy(Casella[4799].Coordinate, "Qazzurro4blu");
    strcpy(Casella[4800].Coordinate, "Razzurro4blu");
    strcpy(Casella[4801].Coordinate, "Sazzurro4blu");
    strcpy(Casella[4802].Coordinate, "Tazzurro4blu");
    strcpy(Casella[4803].Coordinate, "Uazzurro4blu");
    strcpy(Casella[4804].Coordinate, "Vazzurro4blu");
    strcpy(Casella[4805].Coordinate, "Wazzurro4blu");
    strcpy(Casella[4806].Coordinate, "Xazzurro4blu");
    strcpy(Casella[4807].Coordinate, "Yazzurro4blu");
    strcpy(Casella[4808].Coordinate, "Zazzurro4blu");
    strcpy(Casella[4809].Coordinate, "Agiallo4blu");
    strcpy(Casella[4810].Coordinate, "Bgiallo4blu");
    strcpy(Casella[4811].Coordinate, "Cgiallo4blu");
    strcpy(Casella[4812].Coordinate, "Dgiallo4blu");
    strcpy(Casella[4813].Coordinate, "Egiallo4blu");
    strcpy(Casella[4814].Coordinate, "Abianco5blu");
    strcpy(Casella[4815].Coordinate, "Bbianco5blu");
    strcpy(Casella[4816].Coordinate, "Cbianco5blu");
    strcpy(Casella[4817].Coordinate, "Dbianco5blu");
    strcpy(Casella[4818].Coordinate, "Ebianco5blu");
    strcpy(Casella[4819].Coordinate, "Fbianco5blu");
    strcpy(Casella[4820].Coordinate, "Gbianco5blu");
    strcpy(Casella[4821].Coordinate, "Hbianco5blu");
    strcpy(Casella[4822].Coordinate, "Ibianco5blu");
    strcpy(Casella[4823].Coordinate, "Jbianco5blu");
    strcpy(Casella[4824].Coordinate, "Kbianco5blu");
    strcpy(Casella[4825].Coordinate, "Lbianco5blu");
    strcpy(Casella[4826].Coordinate, "Mbianco5blu");
    strcpy(Casella[4827].Coordinate, "Nbianco5blu");
    strcpy(Casella[4828].Coordinate, "Obianco5blu");
    strcpy(Casella[4829].Coordinate, "Pbianco5blu");
    strcpy(Casella[4830].Coordinate, "Qbianco5blu");
    strcpy(Casella[4831].Coordinate, "Rbianco5blu");
    strcpy(Casella[4832].Coordinate, "Sbianco5blu");
    strcpy(Casella[4833].Coordinate, "Tbianco5blu");
    strcpy(Casella[4834].Coordinate, "Ubianco5blu");
    strcpy(Casella[4835].Coordinate, "Vbianco5blu");
    strcpy(Casella[4836].Coordinate, "Wbianco5blu");
    strcpy(Casella[4837].Coordinate, "Xbianco5blu");
    strcpy(Casella[4838].Coordinate, "Ybianco5blu");
    strcpy(Casella[4839].Coordinate, "Zbianco5blu");
    strcpy(Casella[4840].Coordinate, "Arosso5blu");
    strcpy(Casella[4841].Coordinate, "Brosso5blu");
    strcpy(Casella[4842].Coordinate, "Crosso5blu");
    strcpy(Casella[4843].Coordinate, "Drosso5blu");
    strcpy(Casella[4844].Coordinate, "Erosso5blu");
    strcpy(Casella[4845].Coordinate, "Frosso5blu");
    strcpy(Casella[4846].Coordinate, "Grosso5blu");
    strcpy(Casella[4847].Coordinate, "Hrosso5blu");
    strcpy(Casella[4848].Coordinate, "Irosso5blu");
    strcpy(Casella[4849].Coordinate, "Jrosso5blu");
    strcpy(Casella[4850].Coordinate, "Krosso5blu");
    strcpy(Casella[4851].Coordinate, "Lrosso5blu");
    strcpy(Casella[4852].Coordinate, "Mrosso5blu");
    strcpy(Casella[4853].Coordinate, "Nrosso5blu");
    strcpy(Casella[4854].Coordinate, "Orosso5blu");
    strcpy(Casella[4855].Coordinate, "Prosso5blu");
    strcpy(Casella[4856].Coordinate, "Qrosso5blu");
    strcpy(Casella[4857].Coordinate, "Rrosso5blu");
    strcpy(Casella[4858].Coordinate, "Srosso5blu");
    strcpy(Casella[4859].Coordinate, "Trosso5blu");
    strcpy(Casella[4860].Coordinate, "Urosso5blu");
    strcpy(Casella[4861].Coordinate, "Vrosso5blu");
    strcpy(Casella[4862].Coordinate, "Wrosso5blu");
    strcpy(Casella[4863].Coordinate, "Xrosso5blu");
    strcpy(Casella[4864].Coordinate, "Yrosso5blu");
    strcpy(Casella[4865].Coordinate, "Zrosso5blu");
    strcpy(Casella[4866].Coordinate, "Aazzurro5blu");
    strcpy(Casella[4867].Coordinate, "Bazzurro5blu");
    strcpy(Casella[4868].Coordinate, "Cazzurro5blu");
    strcpy(Casella[4869].Coordinate, "Dazzurro5blu");
    strcpy(Casella[4870].Coordinate, "Eazzurro5blu");
    strcpy(Casella[4871].Coordinate, "Fazzurro5blu");
    strcpy(Casella[4872].Coordinate, "Gazzurro5blu");
    strcpy(Casella[4873].Coordinate, "Hazzurro5blu");
    strcpy(Casella[4874].Coordinate, "Iazzurro5blu");
    strcpy(Casella[4875].Coordinate, "Jazzurro5blu");
    strcpy(Casella[4876].Coordinate, "Kazzurro5blu");
    strcpy(Casella[4877].Coordinate, "Lazzurro5blu");
    strcpy(Casella[4878].Coordinate, "Mazzurro5blu");
    strcpy(Casella[4879].Coordinate, "Nazzurro5blu");
    strcpy(Casella[4880].Coordinate, "Oazzurro5blu");
    strcpy(Casella[4881].Coordinate, "Pazzurro5blu");
    strcpy(Casella[4882].Coordinate, "Qazzurro5blu");
    strcpy(Casella[4883].Coordinate, "Razzurro5blu");
    strcpy(Casella[4884].Coordinate, "Sazzurro5blu");
    strcpy(Casella[4885].Coordinate, "Tazzurro5blu");
    strcpy(Casella[4886].Coordinate, "Uazzurro5blu");
    strcpy(Casella[4887].Coordinate, "Vazzurro5blu");
    strcpy(Casella[4888].Coordinate, "Wazzurro5blu");
    strcpy(Casella[4889].Coordinate, "Xazzurro5blu");
    strcpy(Casella[4890].Coordinate, "Yazzurro5blu");
    strcpy(Casella[4891].Coordinate, "Zazzurro5blu");
    strcpy(Casella[4892].Coordinate, "Agiallo5blu");
    strcpy(Casella[4893].Coordinate, "Bgiallo5blu");
    strcpy(Casella[4894].Coordinate, "Cgiallo5blu");
    strcpy(Casella[4895].Coordinate, "Dgiallo5blu");
    strcpy(Casella[4896].Coordinate, "Egiallo5blu");
    strcpy(Casella[4897].Coordinate, "Abianco6blu");
    strcpy(Casella[4898].Coordinate, "Bbianco6blu");
    strcpy(Casella[4899].Coordinate, "Cbianco6blu");
    strcpy(Casella[4900].Coordinate, "Dbianco6blu");
    strcpy(Casella[4901].Coordinate, "Ebianco6blu");
    strcpy(Casella[4902].Coordinate, "Fbianco6blu");
    strcpy(Casella[4903].Coordinate, "Gbianco6blu");
    strcpy(Casella[4904].Coordinate, "Hbianco6blu");
    strcpy(Casella[4905].Coordinate, "Ibianco6blu");
    strcpy(Casella[4906].Coordinate, "Jbianco6blu");
    strcpy(Casella[4907].Coordinate, "Kbianco6blu");
    strcpy(Casella[4908].Coordinate, "Lbianco6blu");
    strcpy(Casella[4909].Coordinate, "Mbianco6blu");
    strcpy(Casella[4910].Coordinate, "Nbianco6blu");
    strcpy(Casella[4911].Coordinate, "Obianco6blu");
    strcpy(Casella[4912].Coordinate, "Pbianco6blu");
    strcpy(Casella[4913].Coordinate, "Qbianco6blu");
    strcpy(Casella[4914].Coordinate, "Rbianco6blu");
    strcpy(Casella[4915].Coordinate, "Sbianco6blu");
    strcpy(Casella[4916].Coordinate, "Tbianco6blu");
    strcpy(Casella[4917].Coordinate, "Ubianco6blu");
    strcpy(Casella[4918].Coordinate, "Vbianco6blu");
    strcpy(Casella[4919].Coordinate, "Wbianco6blu");
    strcpy(Casella[4920].Coordinate, "Xbianco6blu");
    strcpy(Casella[4921].Coordinate, "Ybianco6blu");
    strcpy(Casella[4922].Coordinate, "Zbianco6blu");
    strcpy(Casella[4923].Coordinate, "Arosso6blu");
    strcpy(Casella[4924].Coordinate, "Brosso6blu");
    strcpy(Casella[4925].Coordinate, "Crosso6blu");
    strcpy(Casella[4926].Coordinate, "Drosso6blu");
    strcpy(Casella[4927].Coordinate, "Erosso6blu");
    strcpy(Casella[4928].Coordinate, "Frosso6blu");
    strcpy(Casella[4929].Coordinate, "Grosso6blu");
    strcpy(Casella[4930].Coordinate, "Hrosso6blu");
    strcpy(Casella[4931].Coordinate, "Irosso6blu");
    strcpy(Casella[4932].Coordinate, "Jrosso6blu");
    strcpy(Casella[4933].Coordinate, "Krosso6blu");
    strcpy(Casella[4934].Coordinate, "Lrosso6blu");
    strcpy(Casella[4935].Coordinate, "Mrosso6blu");
    strcpy(Casella[4936].Coordinate, "Nrosso6blu");
    strcpy(Casella[4937].Coordinate, "Orosso6blu");
    strcpy(Casella[4938].Coordinate, "Prosso6blu");
    strcpy(Casella[4939].Coordinate, "Qrosso6blu");
    strcpy(Casella[4940].Coordinate, "Rrosso6blu");
    strcpy(Casella[4941].Coordinate, "Srosso6blu");
    strcpy(Casella[4942].Coordinate, "Trosso6blu");
    strcpy(Casella[4943].Coordinate, "Urosso6blu");
    strcpy(Casella[4944].Coordinate, "Vrosso6blu");
    strcpy(Casella[4945].Coordinate, "Wrosso6blu");
    strcpy(Casella[4946].Coordinate, "Xrosso6blu");
    strcpy(Casella[4947].Coordinate, "Yrosso6blu");
    strcpy(Casella[4948].Coordinate, "Zrosso6blu");
    strcpy(Casella[4949].Coordinate, "Aazzurro6blu");
    strcpy(Casella[4950].Coordinate, "Bazzurro6blu");
    strcpy(Casella[4951].Coordinate, "Cazzurro6blu");
    strcpy(Casella[4952].Coordinate, "Dazzurro6blu");
    strcpy(Casella[4953].Coordinate, "Eazzurro6blu");
    strcpy(Casella[4954].Coordinate, "Fazzurro6blu");
    strcpy(Casella[4955].Coordinate, "Gazzurro6blu");
    strcpy(Casella[4956].Coordinate, "Hazzurro6blu");
    strcpy(Casella[4957].Coordinate, "Iazzurro6blu");
    strcpy(Casella[4958].Coordinate, "Jazzurro6blu");
    strcpy(Casella[4959].Coordinate, "Kazzurro6blu");
    strcpy(Casella[4960].Coordinate, "Lazzurro6blu");
    strcpy(Casella[4961].Coordinate, "Mazzurro6blu");
    strcpy(Casella[4962].Coordinate, "Nazzurro6blu");
    strcpy(Casella[4963].Coordinate, "Oazzurro6blu");
    strcpy(Casella[4964].Coordinate, "Pazzurro6blu");
    strcpy(Casella[4965].Coordinate, "Qazzurro6blu");
    strcpy(Casella[4966].Coordinate, "Razzurro6blu");
    strcpy(Casella[4967].Coordinate, "Sazzurro6blu");
    strcpy(Casella[4968].Coordinate, "Tazzurro6blu");
    strcpy(Casella[4969].Coordinate, "Uazzurro6blu");
    strcpy(Casella[4970].Coordinate, "Vazzurro6blu");
    strcpy(Casella[4971].Coordinate, "Wazzurro6blu");
    strcpy(Casella[4972].Coordinate, "Xazzurro6blu");
    strcpy(Casella[4973].Coordinate, "Yazzurro6blu");
    strcpy(Casella[4974].Coordinate, "Zazzurro6blu");
    strcpy(Casella[4975].Coordinate, "Agiallo6blu");
    strcpy(Casella[4976].Coordinate, "Bgiallo6blu");
    strcpy(Casella[4977].Coordinate, "Cgiallo6blu");
    strcpy(Casella[4978].Coordinate, "Dgiallo6blu");
    strcpy(Casella[4979].Coordinate, "Egiallo6blu");
    strcpy(Casella[4980].Coordinate, "Abianco7blu");
    strcpy(Casella[4981].Coordinate, "Bbianco7blu");
    strcpy(Casella[4982].Coordinate, "Cbianco7blu");
    strcpy(Casella[4983].Coordinate, "Dbianco7blu");
    strcpy(Casella[4984].Coordinate, "Ebianco7blu");
    strcpy(Casella[4985].Coordinate, "Fbianco7blu");
    strcpy(Casella[4986].Coordinate, "Gbianco7blu");
    strcpy(Casella[4987].Coordinate, "Hbianco7blu");
    strcpy(Casella[4988].Coordinate, "Ibianco7blu");
    strcpy(Casella[4989].Coordinate, "Jbianco7blu");
    strcpy(Casella[4990].Coordinate, "Kbianco7blu");
    strcpy(Casella[4991].Coordinate, "Lbianco7blu");
    strcpy(Casella[4992].Coordinate, "Mbianco7blu");
    strcpy(Casella[4993].Coordinate, "Nbianco7blu");
    strcpy(Casella[4994].Coordinate, "Obianco7blu");
    strcpy(Casella[4995].Coordinate, "Pbianco7blu");
    strcpy(Casella[4996].Coordinate, "Qbianco7blu");
    strcpy(Casella[4997].Coordinate, "Rbianco7blu");
    strcpy(Casella[4998].Coordinate, "Sbianco7blu");
    strcpy(Casella[4999].Coordinate, "Tbianco7blu");
    strcpy(Casella[5000].Coordinate, "Ubianco7blu");
    strcpy(Casella[5001].Coordinate, "Vbianco7blu");
    strcpy(Casella[5002].Coordinate, "Wbianco7blu");
    strcpy(Casella[5003].Coordinate, "Xbianco7blu");
    strcpy(Casella[5004].Coordinate, "Ybianco7blu");
    strcpy(Casella[5005].Coordinate, "Zbianco7blu");
    strcpy(Casella[5006].Coordinate, "Arosso7blu");
    strcpy(Casella[5007].Coordinate, "Brosso7blu");
    strcpy(Casella[5008].Coordinate, "Crosso7blu");
    strcpy(Casella[5009].Coordinate, "Drosso7blu");
    strcpy(Casella[5010].Coordinate, "Erosso7blu");
    strcpy(Casella[5011].Coordinate, "Frosso7blu");
    strcpy(Casella[5012].Coordinate, "Grosso7blu");
    strcpy(Casella[5013].Coordinate, "Hrosso7blu");
    strcpy(Casella[5014].Coordinate, "Irosso7blu");
    strcpy(Casella[5015].Coordinate, "Jrosso7blu");
    strcpy(Casella[5016].Coordinate, "Krosso7blu");
    strcpy(Casella[5017].Coordinate, "Lrosso7blu");
    strcpy(Casella[5018].Coordinate, "Mrosso7blu");
    strcpy(Casella[5019].Coordinate, "Nrosso7blu");
    strcpy(Casella[5020].Coordinate, "Orosso7blu");
    strcpy(Casella[5021].Coordinate, "Prosso7blu");
    strcpy(Casella[5022].Coordinate, "Qrosso7blu");
    strcpy(Casella[5023].Coordinate, "Rrosso7blu");
    strcpy(Casella[5024].Coordinate, "Srosso7blu");
    strcpy(Casella[5025].Coordinate, "Trosso7blu");
    strcpy(Casella[5026].Coordinate, "Urosso7blu");
    strcpy(Casella[5027].Coordinate, "Vrosso7blu");
    strcpy(Casella[5028].Coordinate, "Wrosso7blu");
    strcpy(Casella[5029].Coordinate, "Xrosso7blu");
    strcpy(Casella[5030].Coordinate, "Yrosso7blu");
    strcpy(Casella[5031].Coordinate, "Zrosso7blu");
    strcpy(Casella[5032].Coordinate, "Aazzurro7blu");
    strcpy(Casella[5033].Coordinate, "Bazzurro7blu");
    strcpy(Casella[5034].Coordinate, "Cazzurro7blu");
    strcpy(Casella[5035].Coordinate, "Dazzurro7blu");
    strcpy(Casella[5036].Coordinate, "Eazzurro7blu");
    strcpy(Casella[5037].Coordinate, "Fazzurro7blu");
    strcpy(Casella[5038].Coordinate, "Gazzurro7blu");
    strcpy(Casella[5039].Coordinate, "Hazzurro7blu");
    strcpy(Casella[5040].Coordinate, "Iazzurro7blu");
    strcpy(Casella[5041].Coordinate, "Jazzurro7blu");
    strcpy(Casella[5042].Coordinate, "Kazzurro7blu");
    strcpy(Casella[5043].Coordinate, "Lazzurro7blu");
    strcpy(Casella[5044].Coordinate, "Mazzurro7blu");
    strcpy(Casella[5045].Coordinate, "Nazzurro7blu");
    strcpy(Casella[5046].Coordinate, "Oazzurro7blu");
    strcpy(Casella[5047].Coordinate, "Pazzurro7blu");
    strcpy(Casella[5048].Coordinate, "Qazzurro7blu");
    strcpy(Casella[5049].Coordinate, "Razzurro7blu");
    strcpy(Casella[5050].Coordinate, "Sazzurro7blu");
    strcpy(Casella[5051].Coordinate, "Tazzurro7blu");
    strcpy(Casella[5052].Coordinate, "Uazzurro7blu");
    strcpy(Casella[5053].Coordinate, "Vazzurro7blu");
    strcpy(Casella[5054].Coordinate, "Wazzurro7blu");
    strcpy(Casella[5055].Coordinate, "Xazzurro7blu");
    strcpy(Casella[5056].Coordinate, "Yazzurro7blu");
    strcpy(Casella[5057].Coordinate, "Zazzurro7blu");
    strcpy(Casella[5058].Coordinate, "Agiallo7blu");
    strcpy(Casella[5059].Coordinate, "Bgiallo7blu");
    strcpy(Casella[5060].Coordinate, "Cgiallo7blu");
    strcpy(Casella[5061].Coordinate, "Dgiallo7blu");
    strcpy(Casella[5062].Coordinate, "Egiallo7blu");
    strcpy(Casella[5063].Coordinate, "Abianco8blu");
    strcpy(Casella[5064].Coordinate, "Bbianco8blu");
    strcpy(Casella[5065].Coordinate, "Cbianco8blu");
    strcpy(Casella[5066].Coordinate, "Dbianco8blu");
    strcpy(Casella[5067].Coordinate, "Ebianco8blu");
    strcpy(Casella[5068].Coordinate, "Fbianco8blu");
    strcpy(Casella[5069].Coordinate, "Gbianco8blu");
    strcpy(Casella[5070].Coordinate, "Hbianco8blu");
    strcpy(Casella[5071].Coordinate, "Ibianco8blu");
    strcpy(Casella[5072].Coordinate, "Jbianco8blu");
    strcpy(Casella[5073].Coordinate, "Kbianco8blu");
    strcpy(Casella[5074].Coordinate, "Lbianco8blu");
    strcpy(Casella[5075].Coordinate, "Mbianco8blu");
    strcpy(Casella[5076].Coordinate, "Nbianco8blu");
    strcpy(Casella[5077].Coordinate, "Obianco8blu");
    strcpy(Casella[5078].Coordinate, "Pbianco8blu");
    strcpy(Casella[5079].Coordinate, "Qbianco8blu");
    strcpy(Casella[5080].Coordinate, "Rbianco8blu");
    strcpy(Casella[5081].Coordinate, "Sbianco8blu");
    strcpy(Casella[5082].Coordinate, "Tbianco8blu");
    strcpy(Casella[5083].Coordinate, "Ubianco8blu");
    strcpy(Casella[5084].Coordinate, "Vbianco8blu");
    strcpy(Casella[5085].Coordinate, "Wbianco8blu");
    strcpy(Casella[5086].Coordinate, "Xbianco8blu");
    strcpy(Casella[5087].Coordinate, "Ybianco8blu");
    strcpy(Casella[5088].Coordinate, "Zbianco8blu");
    strcpy(Casella[5089].Coordinate, "Arosso8blu");
    strcpy(Casella[5090].Coordinate, "Brosso8blu");
    strcpy(Casella[5091].Coordinate, "Crosso8blu");
    strcpy(Casella[5092].Coordinate, "Drosso8blu");
    strcpy(Casella[5093].Coordinate, "Erosso8blu");
    strcpy(Casella[5094].Coordinate, "Frosso8blu");
    strcpy(Casella[5095].Coordinate, "Grosso8blu");
    strcpy(Casella[5096].Coordinate, "Hrosso8blu");
    strcpy(Casella[5097].Coordinate, "Irosso8blu");
    strcpy(Casella[5098].Coordinate, "Jrosso8blu");
    strcpy(Casella[5099].Coordinate, "Krosso8blu");
    strcpy(Casella[5100].Coordinate, "Lrosso8blu");
    strcpy(Casella[5101].Coordinate, "Mrosso8blu");
    strcpy(Casella[5102].Coordinate, "Nrosso8blu");
    strcpy(Casella[5103].Coordinate, "Orosso8blu");
    strcpy(Casella[5104].Coordinate, "Prosso8blu");
    strcpy(Casella[5105].Coordinate, "Qrosso8blu");
    strcpy(Casella[5106].Coordinate, "Rrosso8blu");
    strcpy(Casella[5107].Coordinate, "Srosso8blu");
    strcpy(Casella[5108].Coordinate, "Trosso8blu");
    strcpy(Casella[5109].Coordinate, "Urosso8blu");
    strcpy(Casella[5110].Coordinate, "Vrosso8blu");
    strcpy(Casella[5111].Coordinate, "Wrosso8blu");
    strcpy(Casella[5112].Coordinate, "Xrosso8blu");
    strcpy(Casella[5113].Coordinate, "Yrosso8blu");
    strcpy(Casella[5114].Coordinate, "Zrosso8blu");
    strcpy(Casella[5115].Coordinate, "Aazzurro8blu");
    strcpy(Casella[5116].Coordinate, "Bazzurro8blu");
    strcpy(Casella[5117].Coordinate, "Cazzurro8blu");
    strcpy(Casella[5118].Coordinate, "Dazzurro8blu");
    strcpy(Casella[5119].Coordinate, "Eazzurro8blu");
    strcpy(Casella[5120].Coordinate, "Fazzurro8blu");
    strcpy(Casella[5121].Coordinate, "Gazzurro8blu");
    strcpy(Casella[5122].Coordinate, "Hazzurro8blu");
    strcpy(Casella[5123].Coordinate, "Iazzurro8blu");
    strcpy(Casella[5124].Coordinate, "Jazzurro8blu");
    strcpy(Casella[5125].Coordinate, "Kazzurro8blu");
    strcpy(Casella[5126].Coordinate, "Lazzurro8blu");
    strcpy(Casella[5127].Coordinate, "Mazzurro8blu");
    strcpy(Casella[5128].Coordinate, "Nazzurro8blu");
    strcpy(Casella[5129].Coordinate, "Oazzurro8blu");
    strcpy(Casella[5130].Coordinate, "Pazzurro8blu");
    strcpy(Casella[5131].Coordinate, "Qazzurro8blu");
    strcpy(Casella[5132].Coordinate, "Razzurro8blu");
    strcpy(Casella[5133].Coordinate, "Sazzurro8blu");
    strcpy(Casella[5134].Coordinate, "Tazzurro8blu");
    strcpy(Casella[5135].Coordinate, "Uazzurro8blu");
    strcpy(Casella[5136].Coordinate, "Vazzurro8blu");
    strcpy(Casella[5137].Coordinate, "Wazzurro8blu");
    strcpy(Casella[5138].Coordinate, "Xazzurro8blu");
    strcpy(Casella[5139].Coordinate, "Yazzurro8blu");
    strcpy(Casella[5140].Coordinate, "Zazzurro8blu");
    strcpy(Casella[5141].Coordinate, "Agiallo8blu");
    strcpy(Casella[5142].Coordinate, "Bgiallo8blu");
    strcpy(Casella[5143].Coordinate, "Cgiallo8blu");
    strcpy(Casella[5144].Coordinate, "Dgiallo8blu");
    strcpy(Casella[5145].Coordinate, "Egiallo8blu");
    strcpy(Casella[5146].Coordinate, "Abianco9blu");
    strcpy(Casella[5147].Coordinate, "Bbianco9blu");
    strcpy(Casella[5148].Coordinate, "Cbianco9blu");
    strcpy(Casella[5149].Coordinate, "Dbianco9blu");
    strcpy(Casella[5150].Coordinate, "Ebianco9blu");
    strcpy(Casella[5151].Coordinate, "Fbianco9blu");
    strcpy(Casella[5152].Coordinate, "Gbianco9blu");
    strcpy(Casella[5153].Coordinate, "Hbianco9blu");
    strcpy(Casella[5154].Coordinate, "Ibianco9blu");
    strcpy(Casella[5155].Coordinate, "Jbianco9blu");
    strcpy(Casella[5156].Coordinate, "Kbianco9blu");
    strcpy(Casella[5157].Coordinate, "Lbianco9blu");
    strcpy(Casella[5158].Coordinate, "Mbianco9blu");
    strcpy(Casella[5159].Coordinate, "Nbianco9blu");
    strcpy(Casella[5160].Coordinate, "Obianco9blu");
    strcpy(Casella[5161].Coordinate, "Pbianco9blu");
    strcpy(Casella[5162].Coordinate, "Qbianco9blu");
    strcpy(Casella[5163].Coordinate, "Rbianco9blu");
    strcpy(Casella[5164].Coordinate, "Sbianco9blu");
    strcpy(Casella[5165].Coordinate, "Tbianco9blu");
    strcpy(Casella[5166].Coordinate, "Ubianco9blu");
    strcpy(Casella[5167].Coordinate, "Vbianco9blu");
    strcpy(Casella[5168].Coordinate, "Wbianco9blu");
    strcpy(Casella[5169].Coordinate, "Xbianco9blu");
    strcpy(Casella[5170].Coordinate, "Ybianco9blu");
    strcpy(Casella[5171].Coordinate, "Zbianco9blu");
    strcpy(Casella[5172].Coordinate, "Arosso9blu");
    strcpy(Casella[5173].Coordinate, "Brosso9blu");
    strcpy(Casella[5174].Coordinate, "Crosso9blu");
    strcpy(Casella[5175].Coordinate, "Drosso9blu");
    strcpy(Casella[5176].Coordinate, "Erosso9blu");
    strcpy(Casella[5177].Coordinate, "Frosso9blu");
    strcpy(Casella[5178].Coordinate, "Grosso9blu");
    strcpy(Casella[5179].Coordinate, "Hrosso9blu");
    strcpy(Casella[5180].Coordinate, "Irosso9blu");
    strcpy(Casella[5181].Coordinate, "Jrosso9blu");
    strcpy(Casella[5182].Coordinate, "Krosso9blu");
    strcpy(Casella[5183].Coordinate, "Lrosso9blu");
    strcpy(Casella[5184].Coordinate, "Mrosso9blu");
    strcpy(Casella[5185].Coordinate, "Nrosso9blu");
    strcpy(Casella[5186].Coordinate, "Orosso9blu");
    strcpy(Casella[5187].Coordinate, "Prosso9blu");
    strcpy(Casella[5188].Coordinate, "Qrosso9blu");
    strcpy(Casella[5189].Coordinate, "Rrosso9blu");
    strcpy(Casella[5190].Coordinate, "Srosso9blu");
    strcpy(Casella[5191].Coordinate, "Trosso9blu");
    strcpy(Casella[5192].Coordinate, "Urosso9blu");
    strcpy(Casella[5193].Coordinate, "Vrosso9blu");
    strcpy(Casella[5194].Coordinate, "Wrosso9blu");
    strcpy(Casella[5195].Coordinate, "Xrosso9blu");
    strcpy(Casella[5196].Coordinate, "Yrosso9blu");
    strcpy(Casella[5197].Coordinate, "Zrosso9blu");
    strcpy(Casella[5198].Coordinate, "Aazzurro9blu");
    strcpy(Casella[5199].Coordinate, "Bazzurro9blu");
    strcpy(Casella[5200].Coordinate, "Cazzurro9blu");
    strcpy(Casella[5201].Coordinate, "Dazzurro9blu");
    strcpy(Casella[5202].Coordinate, "Eazzurro9blu");
    strcpy(Casella[5203].Coordinate, "Fazzurro9blu");
    strcpy(Casella[5204].Coordinate, "Gazzurro9blu");
    strcpy(Casella[5205].Coordinate, "Hazzurro9blu");
    strcpy(Casella[5206].Coordinate, "Iazzurro9blu");
    strcpy(Casella[5207].Coordinate, "Jazzurro9blu");
    strcpy(Casella[5208].Coordinate, "Kazzurro9blu");
    strcpy(Casella[5209].Coordinate, "Lazzurro9blu");
    strcpy(Casella[5210].Coordinate, "Mazzurro9blu");
    strcpy(Casella[5211].Coordinate, "Nazzurro9blu");
    strcpy(Casella[5212].Coordinate, "Oazzurro9blu");
    strcpy(Casella[5213].Coordinate, "Pazzurro9blu");
    strcpy(Casella[5214].Coordinate, "Qazzurro9blu");
    strcpy(Casella[5215].Coordinate, "Razzurro9blu");
    strcpy(Casella[5216].Coordinate, "Sazzurro9blu");
    strcpy(Casella[5217].Coordinate, "Tazzurro9blu");
    strcpy(Casella[5218].Coordinate, "Uazzurro9blu");
    strcpy(Casella[5219].Coordinate, "Vazzurro9blu");
    strcpy(Casella[5220].Coordinate, "Wazzurro9blu");
    strcpy(Casella[5221].Coordinate, "Xazzurro9blu");
    strcpy(Casella[5222].Coordinate, "Yazzurro9blu");
    strcpy(Casella[5223].Coordinate, "Zazzurro9blu");
    strcpy(Casella[5224].Coordinate, "Agiallo9blu");
    strcpy(Casella[5225].Coordinate, "Bgiallo9blu");
    strcpy(Casella[5226].Coordinate, "Cgiallo9blu");
    strcpy(Casella[5227].Coordinate, "Dgiallo9blu");
    strcpy(Casella[5228].Coordinate, "Egiallo9blu");
    strcpy(Casella[5229].Coordinate, "Abianco1arancio");
    strcpy(Casella[5230].Coordinate, "Bbianco1arancio");
    strcpy(Casella[5231].Coordinate, "Cbianco1arancio");
    strcpy(Casella[5232].Coordinate, "Dbianco1arancio");
    strcpy(Casella[5233].Coordinate, "Ebianco1arancio");
    strcpy(Casella[5234].Coordinate, "Fbianco1arancio");
    strcpy(Casella[5235].Coordinate, "Gbianco1arancio");
    strcpy(Casella[5236].Coordinate, "Hbianco1arancio");
    strcpy(Casella[5237].Coordinate, "Ibianco1arancio");
    strcpy(Casella[5238].Coordinate, "Jbianco1arancio");
    strcpy(Casella[5239].Coordinate, "Kbianco1arancio");
    strcpy(Casella[5240].Coordinate, "Lbianco1arancio");
    strcpy(Casella[5241].Coordinate, "Mbianco1arancio");
    strcpy(Casella[5242].Coordinate, "Nbianco1arancio");
    strcpy(Casella[5243].Coordinate, "Obianco1arancio");
    strcpy(Casella[5244].Coordinate, "Pbianco1arancio");
    strcpy(Casella[5245].Coordinate, "Qbianco1arancio");
    strcpy(Casella[5246].Coordinate, "Rbianco1arancio");
    strcpy(Casella[5247].Coordinate, "Sbianco1arancio");
    strcpy(Casella[5248].Coordinate, "Tbianco1arancio");
    strcpy(Casella[5249].Coordinate, "Ubianco1arancio");
    strcpy(Casella[5250].Coordinate, "Vbianco1arancio");
    strcpy(Casella[5251].Coordinate, "Wbianco1arancio");
    strcpy(Casella[5252].Coordinate, "Xbianco1arancio");
    strcpy(Casella[5253].Coordinate, "Ybianco1arancio");
    strcpy(Casella[5254].Coordinate, "Zbianco1arancio");
    strcpy(Casella[5255].Coordinate, "Arosso1arancio");
    strcpy(Casella[5256].Coordinate, "Brosso1arancio");
    strcpy(Casella[5257].Coordinate, "Crosso1arancio");
    strcpy(Casella[5258].Coordinate, "Drosso1arancio");
    strcpy(Casella[5259].Coordinate, "Erosso1arancio");
    strcpy(Casella[5260].Coordinate, "Frosso1arancio");
    strcpy(Casella[5261].Coordinate, "Grosso1arancio");
    strcpy(Casella[5262].Coordinate, "Hrosso1arancio");
    strcpy(Casella[5263].Coordinate, "Irosso1arancio");
    strcpy(Casella[5264].Coordinate, "Jrosso1arancio");
    strcpy(Casella[5265].Coordinate, "Krosso1arancio");
    strcpy(Casella[5266].Coordinate, "Lrosso1arancio");
    strcpy(Casella[5267].Coordinate, "Mrosso1arancio");
    strcpy(Casella[5268].Coordinate, "Nrosso1arancio");
    strcpy(Casella[5269].Coordinate, "Orosso1arancio");
    strcpy(Casella[5270].Coordinate, "Prosso1arancio");
    strcpy(Casella[5271].Coordinate, "Qrosso1arancio");
    strcpy(Casella[5272].Coordinate, "Rrosso1arancio");
    strcpy(Casella[5273].Coordinate, "Srosso1arancio");
    strcpy(Casella[5274].Coordinate, "Trosso1arancio");
    strcpy(Casella[5275].Coordinate, "Urosso1arancio");
    strcpy(Casella[5276].Coordinate, "Vrosso1arancio");
    strcpy(Casella[5277].Coordinate, "Wrosso1arancio");
    strcpy(Casella[5278].Coordinate, "Xrosso1arancio");
    strcpy(Casella[5279].Coordinate, "Yrosso1arancio");
    strcpy(Casella[5280].Coordinate, "Zrosso1arancio");
    strcpy(Casella[5281].Coordinate, "Aazzurro1arancio");
    strcpy(Casella[5282].Coordinate, "Bazzurro1arancio");
    strcpy(Casella[5283].Coordinate, "Cazzurro1arancio");
    strcpy(Casella[5284].Coordinate, "Dazzurro1arancio");
    strcpy(Casella[5285].Coordinate, "Eazzurro1arancio");
    strcpy(Casella[5286].Coordinate, "Fazzurro1arancio");
    strcpy(Casella[5287].Coordinate, "Gazzurro1arancio");
    strcpy(Casella[5288].Coordinate, "Hazzurro1arancio");
    strcpy(Casella[5289].Coordinate, "Iazzurro1arancio");
    strcpy(Casella[5290].Coordinate, "Jazzurro1arancio");
    strcpy(Casella[5291].Coordinate, "Kazzurro1arancio");
    strcpy(Casella[5292].Coordinate, "Lazzurro1arancio");
    strcpy(Casella[5293].Coordinate, "Mazzurro1arancio");
    strcpy(Casella[5294].Coordinate, "Nazzurro1arancio");
    strcpy(Casella[5295].Coordinate, "Oazzurro1arancio");
    strcpy(Casella[5296].Coordinate, "Pazzurro1arancio");
    strcpy(Casella[5297].Coordinate, "Qazzurro1arancio");
    strcpy(Casella[5298].Coordinate, "Razzurro1arancio");
    strcpy(Casella[5299].Coordinate, "Sazzurro1arancio");
    strcpy(Casella[5300].Coordinate, "Tazzurro1arancio");
    strcpy(Casella[5301].Coordinate, "Uazzurro1arancio");
    strcpy(Casella[5302].Coordinate, "Vazzurro1arancio");
    strcpy(Casella[5303].Coordinate, "Wazzurro1arancio");
    strcpy(Casella[5304].Coordinate, "Xazzurro1arancio");
    strcpy(Casella[5305].Coordinate, "Yazzurro1arancio");
    strcpy(Casella[5306].Coordinate, "Zazzurro1arancio");
    strcpy(Casella[5307].Coordinate, "Agiallo1arancio");
    strcpy(Casella[5308].Coordinate, "Bgiallo1arancio");
    strcpy(Casella[5309].Coordinate, "Cgiallo1arancio");
    strcpy(Casella[5310].Coordinate, "Dgiallo1arancio");
    strcpy(Casella[5311].Coordinate, "Egiallo1arancio");
    strcpy(Casella[5312].Coordinate, "Abianco2arancio");
    strcpy(Casella[5313].Coordinate, "Bbianco2arancio");
    strcpy(Casella[5314].Coordinate, "Cbianco2arancio");
    strcpy(Casella[5315].Coordinate, "Dbianco2arancio");
    strcpy(Casella[5316].Coordinate, "Ebianco2arancio");
    strcpy(Casella[5317].Coordinate, "Fbianco2arancio");
    strcpy(Casella[5318].Coordinate, "Gbianco2arancio");
    strcpy(Casella[5319].Coordinate, "Hbianco2arancio");
    strcpy(Casella[5320].Coordinate, "Ibianco2arancio");
    strcpy(Casella[5321].Coordinate, "Jbianco2arancio");
    strcpy(Casella[5322].Coordinate, "Kbianco2arancio");
    strcpy(Casella[5323].Coordinate, "Lbianco2arancio");
    strcpy(Casella[5324].Coordinate, "Mbianco2arancio");
    strcpy(Casella[5325].Coordinate, "Nbianco2arancio");
    strcpy(Casella[5326].Coordinate, "Obianco2arancio");
    strcpy(Casella[5327].Coordinate, "Pbianco2arancio");
    strcpy(Casella[5328].Coordinate, "Qbianco2arancio");
    strcpy(Casella[5329].Coordinate, "Rbianco2arancio");
    strcpy(Casella[5330].Coordinate, "Sbianco2arancio");
    strcpy(Casella[5331].Coordinate, "Tbianco2arancio");
    strcpy(Casella[5332].Coordinate, "Ubianco2arancio");
    strcpy(Casella[5333].Coordinate, "Vbianco2arancio");
    strcpy(Casella[5334].Coordinate, "Wbianco2arancio");
    strcpy(Casella[5335].Coordinate, "Xbianco2arancio");
    strcpy(Casella[5336].Coordinate, "Ybianco2arancio");
    strcpy(Casella[5337].Coordinate, "Zbianco2arancio");
    strcpy(Casella[5338].Coordinate, "Arosso2arancio");
    strcpy(Casella[5339].Coordinate, "Brosso2arancio");
    strcpy(Casella[5340].Coordinate, "Crosso2arancio");
    strcpy(Casella[5341].Coordinate, "Drosso2arancio");
    strcpy(Casella[5342].Coordinate, "Erosso2arancio");
    strcpy(Casella[5343].Coordinate, "Frosso2arancio");
    strcpy(Casella[5344].Coordinate, "Grosso2arancio");
    strcpy(Casella[5345].Coordinate, "Hrosso2arancio");
    strcpy(Casella[5346].Coordinate, "Irosso2arancio");
    strcpy(Casella[5347].Coordinate, "Jrosso2arancio");
    strcpy(Casella[5348].Coordinate, "Krosso2arancio");
    strcpy(Casella[5349].Coordinate, "Lrosso2arancio");
    strcpy(Casella[5350].Coordinate, "Mrosso2arancio");
    strcpy(Casella[5351].Coordinate, "Nrosso2arancio");
    strcpy(Casella[5352].Coordinate, "Orosso2arancio");
    strcpy(Casella[5353].Coordinate, "Prosso2arancio");
    strcpy(Casella[5354].Coordinate, "Qrosso2arancio");
    strcpy(Casella[5355].Coordinate, "Rrosso2arancio");
    strcpy(Casella[5356].Coordinate, "Srosso2arancio");
    strcpy(Casella[5357].Coordinate, "Trosso2arancio");
    strcpy(Casella[5358].Coordinate, "Urosso2arancio");
    strcpy(Casella[5359].Coordinate, "Vrosso2arancio");
    strcpy(Casella[5360].Coordinate, "Wrosso2arancio");
    strcpy(Casella[5361].Coordinate, "Xrosso2arancio");
    strcpy(Casella[5362].Coordinate, "Yrosso2arancio");
    strcpy(Casella[5363].Coordinate, "Zrosso2arancio");
    strcpy(Casella[5364].Coordinate, "Aazzurro2arancio");
    strcpy(Casella[5365].Coordinate, "Bazzurro2arancio");
    strcpy(Casella[5366].Coordinate, "Cazzurro2arancio");
    strcpy(Casella[5367].Coordinate, "Dazzurro2arancio");
    strcpy(Casella[5368].Coordinate, "Eazzurro2arancio");
    strcpy(Casella[5369].Coordinate, "Fazzurro2arancio");
    strcpy(Casella[5370].Coordinate, "Gazzurro2arancio");
    strcpy(Casella[5371].Coordinate, "Hazzurro2arancio");
    strcpy(Casella[5372].Coordinate, "Iazzurro2arancio");
    strcpy(Casella[5373].Coordinate, "Jazzurro2arancio");
    strcpy(Casella[5374].Coordinate, "Kazzurro2arancio");
    strcpy(Casella[5375].Coordinate, "Lazzurro2arancio");
    strcpy(Casella[5376].Coordinate, "Mazzurro2arancio");
    strcpy(Casella[5377].Coordinate, "Nazzurro2arancio");
    strcpy(Casella[5378].Coordinate, "Oazzurro2arancio");
    strcpy(Casella[5379].Coordinate, "Pazzurro2arancio");
    strcpy(Casella[5380].Coordinate, "Qazzurro2arancio");
    strcpy(Casella[5381].Coordinate, "Razzurro2arancio");
    strcpy(Casella[5382].Coordinate, "Sazzurro2arancio");
    strcpy(Casella[5383].Coordinate, "Tazzurro2arancio");
    strcpy(Casella[5384].Coordinate, "Uazzurro2arancio");
    strcpy(Casella[5385].Coordinate, "Vazzurro2arancio");
    strcpy(Casella[5386].Coordinate, "Wazzurro2arancio");
    strcpy(Casella[5387].Coordinate, "Xazzurro2arancio");
    strcpy(Casella[5388].Coordinate, "Yazzurro2arancio");
    strcpy(Casella[5389].Coordinate, "Zazzurro2arancio");
    strcpy(Casella[5390].Coordinate, "Agiallo2arancio");
    strcpy(Casella[5391].Coordinate, "Bgiallo2arancio");
    strcpy(Casella[5392].Coordinate, "Cgiallo2arancio");
    strcpy(Casella[5393].Coordinate, "Dgiallo2arancio");
    strcpy(Casella[5394].Coordinate, "Egiallo2arancio");
    strcpy(Casella[5395].Coordinate, "Abianco3arancio");
    strcpy(Casella[5396].Coordinate, "Bbianco3arancio");
    strcpy(Casella[5397].Coordinate, "Cbianco3arancio");
    strcpy(Casella[5398].Coordinate, "Dbianco3arancio");
    strcpy(Casella[5399].Coordinate, "Ebianco3arancio");
    strcpy(Casella[5400].Coordinate, "Fbianco3arancio");
    strcpy(Casella[5401].Coordinate, "Gbianco3arancio");
    strcpy(Casella[5402].Coordinate, "Hbianco3arancio");
    strcpy(Casella[5403].Coordinate, "Ibianco3arancio");
    strcpy(Casella[5404].Coordinate, "Jbianco3arancio");
    strcpy(Casella[5405].Coordinate, "Kbianco3arancio");
    strcpy(Casella[5406].Coordinate, "Lbianco3arancio");
    strcpy(Casella[5407].Coordinate, "Mbianco3arancio");
    strcpy(Casella[5408].Coordinate, "Nbianco3arancio");
    strcpy(Casella[5409].Coordinate, "Obianco3arancio");
    strcpy(Casella[5410].Coordinate, "Pbianco3arancio");
    strcpy(Casella[5411].Coordinate, "Qbianco3arancio");
    strcpy(Casella[5412].Coordinate, "Rbianco3arancio");
    strcpy(Casella[5413].Coordinate, "Sbianco3arancio");
    strcpy(Casella[5414].Coordinate, "Tbianco3arancio");
    strcpy(Casella[5415].Coordinate, "Ubianco3arancio");
    strcpy(Casella[5416].Coordinate, "Vbianco3arancio");
    strcpy(Casella[5417].Coordinate, "Wbianco3arancio");
    strcpy(Casella[5418].Coordinate, "Xbianco3arancio");
    strcpy(Casella[5419].Coordinate, "Ybianco3arancio");
    strcpy(Casella[5420].Coordinate, "Zbianco3arancio");
    strcpy(Casella[5421].Coordinate, "Arosso3arancio");
    strcpy(Casella[5422].Coordinate, "Brosso3arancio");
    strcpy(Casella[5423].Coordinate, "Crosso3arancio");
    strcpy(Casella[5424].Coordinate, "Drosso3arancio");
    strcpy(Casella[5425].Coordinate, "Erosso3arancio");
    strcpy(Casella[5426].Coordinate, "Frosso3arancio");
    strcpy(Casella[5427].Coordinate, "Grosso3arancio");
    strcpy(Casella[5428].Coordinate, "Hrosso3arancio");
    strcpy(Casella[5429].Coordinate, "Irosso3arancio");
    strcpy(Casella[5430].Coordinate, "Jrosso3arancio");
    strcpy(Casella[5431].Coordinate, "Krosso3arancio");
    strcpy(Casella[5432].Coordinate, "Lrosso3arancio");
    strcpy(Casella[5433].Coordinate, "Mrosso3arancio");
    strcpy(Casella[5434].Coordinate, "Nrosso3arancio");
    strcpy(Casella[5435].Coordinate, "Orosso3arancio");
    strcpy(Casella[5436].Coordinate, "Prosso3arancio");
    strcpy(Casella[5437].Coordinate, "Qrosso3arancio");
    strcpy(Casella[5438].Coordinate, "Rrosso3arancio");
    strcpy(Casella[5439].Coordinate, "Srosso3arancio");
    strcpy(Casella[5440].Coordinate, "Trosso3arancio");
    strcpy(Casella[5441].Coordinate, "Urosso3arancio");
    strcpy(Casella[5442].Coordinate, "Vrosso3arancio");
    strcpy(Casella[5443].Coordinate, "Wrosso3arancio");
    strcpy(Casella[5444].Coordinate, "Xrosso3arancio");
    strcpy(Casella[5445].Coordinate, "Yrosso3arancio");
    strcpy(Casella[5446].Coordinate, "Zrosso3arancio");
    strcpy(Casella[5447].Coordinate, "Aazzurro3arancio");
    strcpy(Casella[5448].Coordinate, "Bazzurro3arancio");
    strcpy(Casella[5449].Coordinate, "Cazzurro3arancio");
    strcpy(Casella[5450].Coordinate, "Dazzurro3arancio");
    strcpy(Casella[5451].Coordinate, "Eazzurro3arancio");
    strcpy(Casella[5452].Coordinate, "Fazzurro3arancio");
    strcpy(Casella[5453].Coordinate, "Gazzurro3arancio");
    strcpy(Casella[5454].Coordinate, "Hazzurro3arancio");
    strcpy(Casella[5455].Coordinate, "Iazzurro3arancio");
    strcpy(Casella[5456].Coordinate, "Jazzurro3arancio");
    strcpy(Casella[5457].Coordinate, "Kazzurro3arancio");
    strcpy(Casella[5458].Coordinate, "Lazzurro3arancio");
    strcpy(Casella[5459].Coordinate, "Mazzurro3arancio");
    strcpy(Casella[5460].Coordinate, "Nazzurro3arancio");
    strcpy(Casella[5461].Coordinate, "Oazzurro3arancio");
    strcpy(Casella[5462].Coordinate, "Pazzurro3arancio");
    strcpy(Casella[5463].Coordinate, "Qazzurro3arancio");
    strcpy(Casella[5464].Coordinate, "Razzurro3arancio");
    strcpy(Casella[5465].Coordinate, "Sazzurro3arancio");
    strcpy(Casella[5466].Coordinate, "Tazzurro3arancio");
    strcpy(Casella[5467].Coordinate, "Uazzurro3arancio");
    strcpy(Casella[5468].Coordinate, "Vazzurro3arancio");
    strcpy(Casella[5469].Coordinate, "Wazzurro3arancio");
    strcpy(Casella[5470].Coordinate, "Xazzurro3arancio");
    strcpy(Casella[5471].Coordinate, "Yazzurro3arancio");
    strcpy(Casella[5472].Coordinate, "Zazzurro3arancio");
    strcpy(Casella[5473].Coordinate, "Agiallo3arancio");
    strcpy(Casella[5474].Coordinate, "Bgiallo3arancio");
    strcpy(Casella[5475].Coordinate, "Cgiallo3arancio");
    strcpy(Casella[5476].Coordinate, "Dgiallo3arancio");
    strcpy(Casella[5477].Coordinate, "Egiallo3arancio");
    strcpy(Casella[5478].Coordinate, "Abianco4arancio");
    strcpy(Casella[5479].Coordinate, "Bbianco4arancio");
    strcpy(Casella[5480].Coordinate, "Cbianco4arancio");
    strcpy(Casella[5481].Coordinate, "Dbianco4arancio");
    strcpy(Casella[5482].Coordinate, "Ebianco4arancio");
    strcpy(Casella[5483].Coordinate, "Fbianco4arancio");
    strcpy(Casella[5484].Coordinate, "Gbianco4arancio");
    strcpy(Casella[5485].Coordinate, "Hbianco4arancio");
    strcpy(Casella[5486].Coordinate, "Ibianco4arancio");
    strcpy(Casella[5487].Coordinate, "Jbianco4arancio");
    strcpy(Casella[5488].Coordinate, "Kbianco4arancio");
    strcpy(Casella[5489].Coordinate, "Lbianco4arancio");
    strcpy(Casella[5490].Coordinate, "Mbianco4arancio");
    strcpy(Casella[5491].Coordinate, "Nbianco4arancio");
    strcpy(Casella[5492].Coordinate, "Obianco4arancio");
    strcpy(Casella[5493].Coordinate, "Pbianco4arancio");
    strcpy(Casella[5494].Coordinate, "Qbianco4arancio");
    strcpy(Casella[5495].Coordinate, "Rbianco4arancio");
    strcpy(Casella[5496].Coordinate, "Sbianco4arancio");
    strcpy(Casella[5497].Coordinate, "Tbianco4arancio");
    strcpy(Casella[5498].Coordinate, "Ubianco4arancio");
    strcpy(Casella[5499].Coordinate, "Vbianco4arancio");
    strcpy(Casella[5500].Coordinate, "Wbianco4arancio");
    strcpy(Casella[5501].Coordinate, "Xbianco4arancio");
    strcpy(Casella[5502].Coordinate, "Ybianco4arancio");
    strcpy(Casella[5503].Coordinate, "Zbianco4arancio");
    strcpy(Casella[5504].Coordinate, "Arosso4arancio");
    strcpy(Casella[5505].Coordinate, "Brosso4arancio");
    strcpy(Casella[5506].Coordinate, "Crosso4arancio");
    strcpy(Casella[5507].Coordinate, "Drosso4arancio");
    strcpy(Casella[5508].Coordinate, "Erosso4arancio");
    strcpy(Casella[5509].Coordinate, "Frosso4arancio");
    strcpy(Casella[5510].Coordinate, "Grosso4arancio");
    strcpy(Casella[5511].Coordinate, "Hrosso4arancio");
    strcpy(Casella[5512].Coordinate, "Irosso4arancio");
    strcpy(Casella[5513].Coordinate, "Jrosso4arancio");
    strcpy(Casella[5514].Coordinate, "Krosso4arancio");
    strcpy(Casella[5515].Coordinate, "Lrosso4arancio");
    strcpy(Casella[5516].Coordinate, "Mrosso4arancio");
    strcpy(Casella[5517].Coordinate, "Nrosso4arancio");
    strcpy(Casella[5518].Coordinate, "Orosso4arancio");
    strcpy(Casella[5519].Coordinate, "Prosso4arancio");
    strcpy(Casella[5520].Coordinate, "Qrosso4arancio");
    strcpy(Casella[5521].Coordinate, "Rrosso4arancio");
    strcpy(Casella[5522].Coordinate, "Srosso4arancio");
    strcpy(Casella[5523].Coordinate, "Trosso4arancio");
    strcpy(Casella[5524].Coordinate, "Urosso4arancio");
    strcpy(Casella[5525].Coordinate, "Vrosso4arancio");
    strcpy(Casella[5526].Coordinate, "Wrosso4arancio");
    strcpy(Casella[5527].Coordinate, "Xrosso4arancio");
    strcpy(Casella[5528].Coordinate, "Yrosso4arancio");
    strcpy(Casella[5529].Coordinate, "Zrosso4arancio");
    strcpy(Casella[5530].Coordinate, "Aazzurro4arancio");
    strcpy(Casella[5531].Coordinate, "Bazzurro4arancio");
    strcpy(Casella[5532].Coordinate, "Cazzurro4arancio");
    strcpy(Casella[5533].Coordinate, "Dazzurro4arancio");
    strcpy(Casella[5534].Coordinate, "Eazzurro4arancio");
    strcpy(Casella[5535].Coordinate, "Fazzurro4arancio");
    strcpy(Casella[5536].Coordinate, "Gazzurro4arancio");
    strcpy(Casella[5537].Coordinate, "Hazzurro4arancio");
    strcpy(Casella[5538].Coordinate, "Iazzurro4arancio");
    strcpy(Casella[5539].Coordinate, "Jazzurro4arancio");
    strcpy(Casella[5540].Coordinate, "Kazzurro4arancio");
    strcpy(Casella[5541].Coordinate, "Lazzurro4arancio");
    strcpy(Casella[5542].Coordinate, "Mazzurro4arancio");
    strcpy(Casella[5543].Coordinate, "Nazzurro4arancio");
    strcpy(Casella[5544].Coordinate, "Oazzurro4arancio");
    strcpy(Casella[5545].Coordinate, "Pazzurro4arancio");
    strcpy(Casella[5546].Coordinate, "Qazzurro4arancio");
    strcpy(Casella[5547].Coordinate, "Razzurro4arancio");
    strcpy(Casella[5548].Coordinate, "Sazzurro4arancio");
    strcpy(Casella[5549].Coordinate, "Tazzurro4arancio");
    strcpy(Casella[5550].Coordinate, "Uazzurro4arancio");
    strcpy(Casella[5551].Coordinate, "Vazzurro4arancio");
    strcpy(Casella[5552].Coordinate, "Wazzurro4arancio");
    strcpy(Casella[5553].Coordinate, "Xazzurro4arancio");
    strcpy(Casella[5554].Coordinate, "Yazzurro4arancio");
    strcpy(Casella[5555].Coordinate, "Zazzurro4arancio");
    strcpy(Casella[5556].Coordinate, "Agiallo4arancio");
    strcpy(Casella[5557].Coordinate, "Bgiallo4arancio");
    strcpy(Casella[5558].Coordinate, "Cgiallo4arancio");
    strcpy(Casella[5559].Coordinate, "Dgiallo4arancio");
    strcpy(Casella[5560].Coordinate, "Egiallo4arancio");

    char Mappa[]={" ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmcttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccttttccctttcmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttcmmmccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccctttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmtcmcmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmmmmcctcmcccmctcmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmccctccmmmmmmmmmmmccccttttcmctctttccmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmctcmcmctcmmmmmmmctttttttttttttcttctttcccmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmcttcmcttcmcccmmmcttttttttttttcmccmctttttccccmcmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmccmmctttcmctttctttccmmcttttttttttttcmmctttttttttcmccmmmmmmmmmmmm6mmmmmmmmmccccccccmccmmcttccmcttttttttttcmmcttttttttttcmmctttttttttcmccmmmmmmmmmmmmm7mmmmmmmmcttttttcmccmmcttcmmcttccttttttttcmmctttttttttcmctttttttttcmmmmmmmmmmmmmmmmm8mmmmmmmcttttcttcmcccmcccccmctcmmcttttttttccmccctttttcmmcttttttttttcccccmmmmmmmmmmmm9mmmmmmmmcttcmctcmmmmmmmmmmmcttcmctttttctctcmcmmcctttcmcttttttttttttttttcmmmmmmmmmmm1mmmmmmmcttcmmmcmmmmmmmmmmcctttcmcccttcmcmccmccmmmcttcmctttttttttttttttccmmmmmmmmmmm2mmmmmmmcttcmmmmmmmmmmmmmctttcccmmmmctcmmctcmctcmcmccmctttttttttttttttcmmmmmmmmmmmmm3mmmmmmmccccmccmmmmmmmmcctttcmmmmmmmcttcmctcmcccmmmmmmmctttttttttttttttcccmmmmmmmmmm4mmmmmmmmmmmcccmmmmmmmcttttcmcmmmccmmctcmctcmmmmmmmmmmmcccttttttttttccctttcmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmctttcmcmmmmmccmmcmctttcccmmmmmmmccmmcctttttttcmmmcccmccmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmcttccmmmmmmmmmmmmctttcccmccmmmctcmmmmctttttttcccmmmcttcmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmccccmmmcttccctcmmmmmcccccttttccccccttcmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmmmcccttttttcmmmmmmmmmmmcttcmmmmmmctcmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttcmmmccccccccmcctcmmmmmmctcmmmmmm1mmmmmmccmmmmmmmmmmmmmmmmmmmmmmcmcmmmmcccctttttttttttccctttttttcmmmcmmmmmmmctcmmmmmm2mmmcccttccmmmmmmmmmmmmmmmmmmmmmmmcmmmcttttttttcccctttttttttttttccmmmmmmmmmctcmmmmmm3mmctttttcccccmmmmmmmmmmmmmmmmcmmmmmmmmcttttttcmmmmcttttttttttttttccmmmmcmmctcmmmmmm4mmcttttcmmcctcmmmmmmmmmmmmmmmcmmmmmmmmcttttccmccccttttttttttttttcmmmmmmmcmcttcmmmmm5mctttttcmmmmccccmcmmmmmmmmmmcmmmmmmmmmctttcmmmctttttttttttttttttcmmmmmmmmmmcttcmmmm6mctttttcmmmmmmmccmmmmmmcmmccmmmmmmmmmmmccccmcccttttttttttttttttcmmmmmmmmmmmmccmmmmm7mmcttctcmmmmmmmmmccmmcctcmccmmmmmmmmmmmmmmmccmmcttttttttttttttttcmmmmmmmmmmmccmmmmm8mcctcmccmmmmccmmcttcmcttccmmmmmmmmmmmmmmmmmcmccttttttttttttttttttcmccmmmmmmmcmmmmmm9mmmctcmcccccttccttcmmcccmmmmmmmmmmmmmmmmmmmmctttttttttttttttttttttcttccmmmmccmmmmmm1mmmcccmcccttctttcccmmmmmmmmmmmmmmmmmmmmmmmmmcctttttttttttttttttttttttcmmmmmmmmmmmmm2mmmmmmmmmmccmcccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccctttttttttttttttcccccccmmmmcmmmmmmm3mmmmmmmmmmctcmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttttttttcmmmmmmmmmmmcmmmmmmm4mmmmmmmmmmmccmcccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttttttttcmmmmmmmmmmctccmmmmm5mmmmmmmmmmmmcmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmcmcttttttttttttttcmmmmmmmmmmctttcmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmccttttttccttttttttcmmmmmmmmmcttttcmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctcccccccccmmctttttcccmmmmmmmmcttttccmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmcccttcccmmmmmmccccmcttccmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmccmmmmmmmmcccctcmccmmmmmmmmmctttcmccmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmcccmmmmmmmmmcctttcmcmmmmmmmmmcttccmctcmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmmmmmmmmmmmmctcmmmmccmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmccmmmmmcmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmmmccmmmccmmmmmmmmmmmmmmmmccccccmmccccmmmcccmmmmmmm5mmmmmmmmmmmmmmmmmmmmmcmcccmmmmctcmmmmmcctccccmmmmmmmmmmcccttcmmmccccmmmmccmmmmmmmmm6mmmmmmmmmmmmmmmmmmmcccmmmmmccctttcmcccttcmmmmmmmmmmmmmccccccmmccmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmccmmmccmmmcttcmccccccmmmcmmmmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmcccmmmmmmctcmmmmmmmmmccmmmmccmctcmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmccccccmcmmccmmmmmmmmmccccmcmccmmmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmcccmmmmcccmmmmmmmmmmmmccmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccccccmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttcmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmcmcttttttcmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttctctttttttcmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttttttttttcccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttcccctttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmctttttccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"};

    char Strada[]={" ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmcttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccttttccctttcmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttcmmmccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccctttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmtcmcmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmmmmcctcmcccmctcmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmccctccmmmmmmmmmmmccccttttcmctctttccmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmctcmcmctcmmmmmmmctttttttttttttcttctttcccmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmcttcmcttcmcccmmmcttttttttttttcmccmctttttccccmcmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmccmmctttcmctttctttccmmcttttttttttttcmmctttttttttcmccmmmmmmmmmmmm6mmmmmmmmmccccccccmccmmcttccmcttttttttttcmmcttttttttttcmmctttttttttcmccmmmmmmmmmmmmm7mmmmmmmmcttttttcmccmmcttcmmcttccttttttttcmmctttttttttcmctttttttttcmmmmmmmmmmmmmmmmm8mmmmmmmcttttcttcmcccmcccccmctcmmcttttttttccmccctttttcmmcttttttttttcccccmmmmmmmmmmmm9mmmmmmmmcttcmctcmmmmmmmmmmmcttcmctttttctctcmcmmcctttcmcttttttttttttttttcmmmmmmmmmmm1mmmmmmmcttcmmmcmmmmmmmmmmcctttcmcccttcmcmccmccmmmcttcmctttttttttttttttccmmmmmmmmmmm2mmmmmmmcttcmmmmmmmmmmmmmctttcccmmmmctcmmctcmctcmcmccmctttttttttttttttcmmmmmmmmmmmmm3mmmmmmmccccmccmmmmmmmmcctttcmmmmmmmcttcmctcmcccmmmmmmmctttttttttttttttcccmmmmmmmmmm4mmmmmmmmmmmcccmmmmmmmcttttcmcmmmccmmctcmctcmmmmmmmmmmmcccttttttttttccctttcmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmctttcmcmmmmmccmmcmctttcccmmmmmmmccmmcctttttttcmmmcccmccmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmcttccmmmmmmmmmmmmctttcccmccmmmctcmmmmctttttttcccmmmcttcmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmccccmmmcttccctcmmmmmcccccttttccccccttcmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmmmcccttttttcmmmmmmmmmmmcttcmmmmmmctcmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttcmmmccccccccmcctcmmmmmmctcmmmmmm1mmmmmmccmmmmmmmmmmmmmmmmmmmmmmcmcmmmmcccctttttttttttccctttttttcmmmcmmmmmmmctcmmmmmm2mmmcccttccmmmmmmmmmmmmmmmmmmmmmmmcmmmcttttttttcccctttttttttttttccmmmmmmmmmctcmmmmmm3mmctttttcccccmmmmmmmmmmmmmmmmcmmmmmmmmcttttttcmmmmcttttttttttttttccmmmmcmmctcmmmmmm4mmcttttcmmcctcmmmmmmmmmmmmmmmcmmmmmmmmcttttccmccccttttttttttttttcmmmmmmmcmcttcmmmmm5mctttttcmmmmccccmcmmmmmmmmmmcmmmmmmmmmctttcmmmctttttttttttttttttcmmmmmmmmmmcttcmmmm6mctttttcmmmmmmmccmmmmmmcmmccmmmmmmmmmmmccccmcccttttttttttttttttcmmmmmmmmmmmmccmmmmm7mmcttctcmmmmmmmmmccmmcctcmccmmmmmmmmmmmmmmmccmmcttttttttttttttttcmmmmmmmmmmmccmmmmm8mcctcmccmmmmccmmcttcmcttccmmmmmmmmmmmmmmmmmcmccttttttttttttttttttcmccmmmmmmmcmmmmmm9mmmctcmcccccttccttcmmcccmmmmmmmmmmmmmmmmmmmmctttttttttttttttttttttcttccmmmmccmmmmmm1mmmcccmcccttctttcccmmmmmmmmmmmmmmmmmmmmmmmmmcctttttttttttttttttttttttcmmmmmmmmmmmmm2mmmmmmmmmmccmcccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccctttttttttttttttcccccccmmmmcmmmmmmm3mmmmmmmmmmctcmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttttttttcmmmmmmmmmmmcmmmmmmm4mmmmmmmmmmmccmcccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttttttttttttttcmmmmmmmmmmctccmmmmm5mmmmmmmmmmmmcmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmcmcttttttttttttttcmmmmmmmmmmctttcmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmccttttttccttttttttcmmmmmmmmmcttttcmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctcccccccccmmctttttcccmmmmmmmmcttttccmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmcccttcccmmmmmmccccmcttccmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmccmmmmmmmmcccctcmccmmmmmmmmmctttcmccmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmcccmmmmmmmmmcctttcmcmmmmmmmmmcttccmctcmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmmmmmmmmmmmmctcmmmmccmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmccmmmmmcmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcmmmccmmmccmmmmmmmmmmmmmmmmccccccmmccccmmmcccmmmmmmm5mmmmmmmmmmmmmmmmmmmmmcmcccmmmmctcmmmmmcctccccmmmmmmmmmmcccttcmmmccccmmmmccmmmmmmmmm6mmmmmmmmmmmmmmmmmmmcccmmmmmccctttcmcccttcmmmmmmmmmmmmmccccccmmccmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmccmmmccmmmcttcmccccccmmmcmmmmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmcccmmmmmmctcmmmmmmmmmccmmmmccmctcmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmccccccmcmmccmmmmmmmmmccccmcmccmmmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmcccmmmmcccmmmmmmmmmmmmccmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm5mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccccccccmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm6mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttttcmmmmmcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm7mmmmmmmmmmmmmmmmmmmmmmmmmmmmmcccmcmcttttttcmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm8mmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttctctttttttcmmmmccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm9mmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttttttttttttcccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm1mmmmmmmmmmmmmmmmmmmmmmmmmmmmmccttcccctttttttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm2mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmccmmmmctttttccccmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm3mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmctttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm4mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmcttttcmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"};

    char risp, LaTuaPartenza[] = {"\n\nLa tua Partenza"}, IlTuoArrivo[] = {"\nIl tuo Arrivo"}, CharID[] = {"Sulla Mappa il suo Carattere Identificativo è"};

    int Passi[3], Coordinate[2], CoordinateDellaPartenza[2], CoordinateDellArrivo[2], riga, colonna, i, k, NumeroCasellaPartenza = 0, NumeroCasellaArrivo = 0;

    Passi[0] = Passi[1] = Passi[2] = 0; /*PASSI NEL MARE (0), SULLA COSTA (1), VIA TERRA (2)*/

    CasellaViaggio Pressi[31];

    for (i = 0; i < 33; i = i + 1) {Pressi[riga].n = 0;}

    strcpy(Pressi[0].Nome, "- Tribù di ShaoQuing");
    strcpy(Pressi[1].Nome, "- Tribù dell'Acqua del Nord");
    strcpy(Pressi[2].Nome, "- Tempio dell'Aria del Nord");
    strcpy(Pressi[3].Nome, "- Baia del Camaleonte");
    strcpy(Pressi[4].Nome, "- Tempio dell’Aria dell'Ovest");
    strcpy(Pressi[5].Nome, "- Ba Sing Se");
    strcpy(Pressi[6].Nome, "- Passo del Serpente");
    strcpy(Pressi[8].Nome, "- Baia della Luna Piena");
    strcpy(Pressi[9].Nome, "- Gaipan");
    strcpy(Pressi[10].Nome, "- Grande Spaccatura");
    strcpy(Pressi[11].Nome, "- La Roccia Bollente");
    strcpy(Pressi[12].Nome, "- Isola di Ember");
    strcpy(Pressi[13].Nome, "- Isola di Roku");
    strcpy(Pressi[14].Nome, "- Isola Mezzaluna");
    strcpy(Pressi[15].Nome, "- Foresta di Wulong");
    strcpy(Pressi[16].Nome, "- Capitale della Nazione del Fuoco");
    strcpy(Pressi[17].Nome, "- Gaoling");
    strcpy(Pressi[18].Nome, "- Deserto di Si Wong");
    strcpy(Pressi[19].Nome, "- Fire Fountain City");
    strcpy(Pressi[20].Nome, "- Cancelli di Azulon");
    strcpy(Pressi[21].Nome, "- Jang Hui");
    strcpy(Pressi[22].Nome, "- Shu Jing");
    strcpy(Pressi[23].Nome, "- Omashu");
    strcpy(Pressi[24].Nome, "- Tempio dell’Aria dell'Est");
    strcpy(Pressi[25].Nome, "- Isola Codadibalena");
    strcpy(Pressi[26].Nome, "- Tribù della Palude");
    strcpy(Pressi[27].Nome, "- Tempio dell’Aria del Sud");
    strcpy(Pressi[28].Nome, "- Isola di Kyoshi");
    strcpy(Pressi[29].Nome, "- Tribù di HaiQuing");
    strcpy(Pressi[30].Nome, "- Tribù dell'Acqua del Sud");
    strcpy(Pressi[7].Nome, "- Senlin");

    Pressi[0].Posizione[0] = 83*4;       Pressi[0].Posizione[1] = 48;
    Pressi[1].Posizione[0] = 83*5;       Pressi[1].Posizione[1] = 38;
    Pressi[2].Posizione[0] = 83*8;       Pressi[2].Posizione[1] = 48;
    Pressi[3].Posizione[0] = 83*16;      Pressi[3].Posizione[1] = 68;
    Pressi[4].Posizione[0] = 83*18;      Pressi[4].Posizione[1] = 9;
    Pressi[5].Posizione[0] = 83*17;      Pressi[5].Posizione[1] = 62;
    Pressi[6].Posizione[0] = 83*23;      Pressi[6].Posizione[1] = 53;
    Pressi[7].Posizione[0] = 83*24;      Pressi[7].Posizione[1] = 40;
    Pressi[8].Posizione[0] = 83*24;      Pressi[8].Posizione[1] = 51;
    Pressi[9].Posizione[0] = 83*26;      Pressi[9].Posizione[1] = 47;
    Pressi[10].Posizione[0] = 83*26;     Pressi[10].Posizione[1] = 51;
    Pressi[11].Posizione[0] = 83*27;     Pressi[11].Posizione[1] = 7;
    Pressi[12].Posizione[0] = 83*27;     Pressi[12].Posizione[1] = 30;
    Pressi[13].Posizione[0] = 83*27;     Pressi[13].Posizione[1] = 32;
    Pressi[14].Posizione[0] = 83*28;     Pressi[14].Posizione[1] = 33;
    Pressi[15].Posizione[0] = 83*28;     Pressi[15].Posizione[1] = 38;
    Pressi[16].Posizione[0] = 83*29;     Pressi[16].Posizione[1] = 6;
    Pressi[17].Posizione[0] = 83*29;     Pressi[17].Posizione[1] = 42;
    Pressi[18].Posizione[0] = 83*30;     Pressi[18].Posizione[1] = 55;
    Pressi[19].Posizione[0] = 83*31;     Pressi[19].Posizione[1] = 14;
    Pressi[20].Posizione[0] = 83*32;     Pressi[20].Posizione[1] = 16;
    Pressi[21].Posizione[0] = 83*32;     Pressi[21].Posizione[1] = 27;
    Pressi[22].Posizione[0] = 83*35;     Pressi[22].Posizione[1] = 17;
    Pressi[23].Posizione[0] = 83*35;     Pressi[23].Posizione[1] = 45;
    Pressi[24].Posizione[0] = 83*37;     Pressi[24].Posizione[1] = 75;
    Pressi[25].Posizione[0] = 83*45;     Pressi[25].Posizione[1] = 39;
    Pressi[26].Posizione[0] = 83*45;     Pressi[26].Posizione[1] = 54;
    Pressi[27].Posizione[0] = 83*48;     Pressi[27].Posizione[1] = 31;
    Pressi[28].Posizione[0] = 83*53;     Pressi[28].Posizione[1] = 46;
    Pressi[29].Posizione[0] = 83*57;     Pressi[29].Posizione[1] = 45;
    Pressi[30].Posizione[0] = 83*60;     Pressi[30].Posizione[1] = 31;

    Cancella(); StampaMappa(&Mappa[0]);

    printf("\n---V---");

    scanSenzaInvio();

    printf("\n\nSi ricorda l'ordine dei colori delle lettere e dei numeri delle coordinate della Mappa:\n\n          bianco - rosso - azzurro - giallo\nbianco\nrosso\nazzurro\ngiallo\nverde\nrosa\nblu\narancio");

    printf("\n\n---V---");

    scanSenzaInvio();

    printf("\n\nCon quale metodo vuoi indicare la tua posizione di partenza? (Digita il numero corrispondente)\n\n1) Inserimento delle Coordinate Precise       2) Inserimento del Nome della Città/Località        3) Posizionamento con i Tasti Direzionali (A,W,S,D)\n\n");

    risp = '0';

    while (risp != '1' && risp != '2' && risp != '3')

    {
        risp = scanSenzaInvio();

        if (risp != '1' && risp != '2' && risp != '3') printf("\nIl numero digitato non indica nessun metodo.\nInseriscine uno adeguato:\n\n");
    }

    /*SCELTA DEL PUNTO DI PARTENZA*/

rinserisci:

    if (risp == '1') /*Sottoprogramma per la Partenza RISP1 : Inserimento Coordinate Precise*/

    {
        risp = Risp1(&Casella[0], 'P', &Strada[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Coordinate[0]);

        goto rinserisci;

    }

    if (risp == '2') /*Sottoprogramma per la Partenza RISP2 : Inserimento Carattere Identificativo*/

    {
        risp = Risp2('P', &Strada[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Coordinate[0]);

        goto rinserisci;
    }

    if (risp == '3') /*Sottoprogramma per la Partenza RISP3 : Metodo Interattivo*/

    {
        risp = Risp3(&Pressi[0], 'P', &Strada[0], &Mappa[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Passi[0], &Coordinate[0]);
    }

    /*INDIVIDUAZIONE E CALCOLO DEI DATI RELATIVI AL PUNTO DI PARTENZA*/

    i = 0;

    for (riga = 0; riga < 67 && i == 0; riga = riga + 1){
        for (colonna = 0; colonna < 83 && i == 0; colonna = colonna + 1){

            if (riga == CoordinateDellaPartenza[0] && colonna == CoordinateDellaPartenza[1]) i = 1;
            else  NumeroCasellaPartenza = NumeroCasellaPartenza + 1;
        }
    }

    printf("\n\n\nTi trovi presso ");

    if (StampaPosti (&CoordinateDellaPartenza[0]) == 0) { printf("la zona di coordinate "); StampaCoordinate(&Casella[NumeroCasellaPartenza].Coordinate[0]); printf("\n\n\n"); }

    else { printf(", le cui coordinate sono "); StampaCoordinate(&Casella[NumeroCasellaPartenza].Coordinate[0]); printf("\n\n\n"); }

    printf("---V---");

    scanSenzaInvio();

    /*SCELTA DI COME CALCOLARE IL PERCORSO FINO AL PUNTO DI ARRIVO*/

    printf("\n\nIn che modo vuoi calcolare la distanza tra il tuo punto di partenza ed il punto d'arrivo? (Digita il numero corrispondente)\n\n1) Calcolo Automatico                                        2) Calcolo Interattivo \n(minima distanza in linea d'aria)                            (spostati con A,W,S,D attraverso la mappa fino all'arrivo, il programma conterà i passi!)\n\n");

    while (risp != '1' && risp != '2') {

        risp = scanSenzaInvio();

        if (risp != '1' && risp != '2') printf("\nIl numero digitato non indica nessun metodo.\nInseriscine uno adeguato:\n\n");
    }

    if (risp == '1') { /*METODO AUTOMATICO PER CALCOLARE IL PERCORSO FINO AL PUNTO DI ARRIVO*/

        printf("\n\n---V---");

        scanSenzaInvio();

        printf("\n\nCon quale metodo vuoi indicare la tua posizione di arrivo? (Digita il numero corrispondente)\n\n1) Inserimento delle Coordinate Precise       2) Inserimento del Nome della Città/Località        3) Posizionamento con i Tasti Direzionali (A,W,S,D)\n\n");

        risp = '0';

        while (risp != '1' && risp != '2' && risp != '3') /*SCELTA DI COME CALCOLARE IL PERCORSO FINO AL PUNTO DI ARRIVO*/

        {
            risp = scanSenzaInvio();

            if (risp != '1' && risp != '2' && risp != '3') printf("\nIl numero digitato non indica nessun metodo.\nInseriscine uno adeguato:\n\n");
        }

    rinserisci2:

        if (risp == '1') /*Sottoprogramma per l'Arrivo RISP1 : Inserimento Coordinate Precise*/

        {
            risp = Risp1(&Casella[0], 'A', &Strada[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Coordinate[0]);

            goto rinserisci2;

        }

        if (risp == '2') /*Sottoprogramma per la Partenza RISP2 : Inserimento Carattere Identificativo*/

        {
            risp = Risp2('A', &Strada[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Coordinate[0]);

            goto rinserisci2;
        }

        if (risp == '3') /*Sottoprogramma per la Partenza RISP3 : Metodo Interattivo*/

        {
            risp = Risp3(&Pressi[0], 'A', &Strada[0], &Mappa[0], &CoordinateDellaPartenza[0], &CoordinateDellArrivo[0], &Passi[0], &Coordinate[0]);
        }

        /*4 CICLI PER CALCOLARE IL PERCORSO IN MODO AUTOMATICO SEGUITI DA 4 CICLI PER DISEGNARLO SULLA MAPPA*/

        Coordinate[0] = CoordinateDellaPartenza[0];
        Coordinate[1] = CoordinateDellaPartenza[1];

        if (CoordinateDellArrivo[0] < CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] <= CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'w', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);
            while (Coordinate[1] != CoordinateDellArrivo[1]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'a', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);

        }

        if (CoordinateDellArrivo[0] <= CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] > CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'w', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);
            while (Coordinate[1] != CoordinateDellArrivo[1]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'd', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);

        }

        if (CoordinateDellArrivo[0] > CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] >= CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 's', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);
            while (Coordinate[1] != CoordinateDellArrivo[1]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'd', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);

        }

        if (CoordinateDellArrivo[0] >= CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] < CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 's', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);
            while (Coordinate[1] != CoordinateDellArrivo[1]) SpostamentInterattivi(&Pressi[0], 'A', 'A', 'a', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 1);

        }

        if (Mappa[85 + CoordinateDellaPartenza[1] + (CoordinateDellaPartenza[0]*84)] == 'm') Passi[0] = Passi[0] - 1;
        if (Mappa[85 + CoordinateDellaPartenza[1] + (CoordinateDellaPartenza[0]*84)] == 'c') Passi[1] = Passi[1] - 1;
        if (Mappa[85 + CoordinateDellaPartenza[1] + (CoordinateDellaPartenza[0]*84)] == 't') Passi[2] = Passi[2] - 1;

        Coordinate[0] = CoordinateDellaPartenza[0];
        Coordinate[1] = CoordinateDellaPartenza[1];

        if (CoordinateDellArrivo[0] < CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] <= CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '|';} Coordinate[0] = Coordinate[0] - 1; }
            while (Coordinate[1] != CoordinateDellArrivo[1])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '-';} Coordinate[1] = Coordinate[1] - 1;; }

        }

        if (CoordinateDellArrivo[0] <= CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] > CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '|';} Coordinate[0] = Coordinate[0] - 1; }
            while (Coordinate[1] != CoordinateDellArrivo[1])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '-';} Coordinate[1] = Coordinate[1] + 1; }
        }

        if (CoordinateDellArrivo[0] > CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] >= CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '|';} Coordinate[0] = Coordinate[0] + 1; }
            while (Coordinate[1] != CoordinateDellArrivo[1])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '-';} Coordinate[1] = Coordinate[1] + 1; }

        }

        if (CoordinateDellArrivo[0] >= CoordinateDellaPartenza[0] && CoordinateDellArrivo[1] < CoordinateDellaPartenza[1]) {

            while (Coordinate[0] != CoordinateDellArrivo[0])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '|';} Coordinate[0] = Coordinate[0] + 1; }
            while (Coordinate[1] != CoordinateDellArrivo[1])
            { if (!(Coordinate[0] == CoordinateDellaPartenza[0] && Coordinate[1] == CoordinateDellaPartenza[1])) {Mappa[85 + Coordinate[1] + (Coordinate[0]*84)] = '-';} Coordinate[1] = Coordinate[1] - 1; }

        }

         Mappa[85 + CoordinateDellArrivo[1] + (CoordinateDellArrivo[0]*84)] = '+';

         Cancella(); StampaMappa(&Mappa[0]);

    }

    if (risp == '2') { /*METODO INTERATTIVO PER CALCOLARE IL PERCORSO FINO AL PUNTO DI ARRIVO*/

        Cancella(); StampaMappa(&Strada[0]);

        SpostamentInterattivi(&Pressi[0], 'A', 'I', 'm', &Passi[0], &Coordinate[0], &CoordinateDellaPartenza[0], &Strada[0], &Mappa[0], 0);

        CoordinateDellArrivo[0] = Coordinate[0];

        CoordinateDellArrivo[1] = Coordinate[1];

        Viaggio(&Passi[0], &Mappa[0], Coordinate[0], Coordinate[1]);

        strcpy(Mappa, Strada);
    }

    /*INDIVIDUAZIONE E CALCOLO DEI DATI RELATIVI AL PUNTO DI ARRIVO*/

    i = 0;

    for (riga = 0; riga < 67 && i == 0; riga = riga + 1){
        for (colonna = 0; colonna < 83 && i == 0; colonna = colonna + 1){

            if (!(riga == CoordinateDellArrivo[0] && colonna == CoordinateDellArrivo[1])) NumeroCasellaArrivo = NumeroCasellaArrivo + 1;
            else i = 1;
        }
    }

    /*STAMPA DEI DATI RELATIVI AL PERCORSO*/

    printf("\n\nIl percorso che ti attende è lungo %d quadretti di cui %d sono di terra, %d sono di mare e %d sono di costa.\n\nDopo questo viaggio avrai raggiunto ", (Passi[0]+Passi[1]+Passi[2]), Passi[2], Passi[0], Passi[1]);

    if (StampaPosti(&CoordinateDellArrivo[0]) == 0) printf("la tua meta");

    printf("\n\nVuoi altre informazioni? (s/n)\n\n");

    risp = scanSenzaInvio();

    if (risp == 's' || risp == 'S')

    {
        if (StamPartenzArrivo(&CoordinateDellaPartenza[0], &LaTuaPartenza[0], &CharID[0]) == 0) printf("\n\nLa tua partenza ha coordinate ");

        StampaCoordinate(&Casella[NumeroCasellaPartenza].Coordinate[0]);

        printf("\n");

        k = 0;

        for (i = 0; i < 31; i = i + 1) {if (Pressi[i].n > 1) k = k + 1;}

        if (k > 1) {

        printf("\n---V---");

        scanSenzaInvio();

        printf("\n\n\nPassi nei pressi di: \n\n");

        for (i = 0; i < 31; i = i + 1)
        {
        for (k = 0; k < 31; k = k + 1){
            if (Pressi[k].n != 0) {
                if (Pressi[k].n == 1)
                {
                    if ((Pressi[k].Posizione[1] + Pressi[k].Posizione[0]) != NumeroCasellaArrivo && (Pressi[k].Posizione[1] + Pressi[k].Posizione[0]) != NumeroCasellaPartenza) {printf("%s\n", Pressi[k].Nome);

                        if (k == 0) {printf("  Il cui Carattere Identificativo è la A\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 1) {printf("  Il cui Carattere Identificativo è il 3\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 2) {printf("  Il cui Carattere Identificativo è il 4\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 3) {printf("  Il cui Carattere Identificativo è la B\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 4) {printf("  Il cui Carattere Identificativo è il 2\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 5) {printf("  Il cui Carattere Identificativo è il 5\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 6) {printf("  Il cui Carattere Identificativo è la C\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 7) {printf("  Il cui Carattere Identificativo è la D\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 8) {printf("  Il cui Carattere Identificativo è la E\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 9) {printf("  Il cui Carattere Identificativo è la F\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 10) {printf("  Il cui Carattere Identificativo è la G\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 11) {printf("  Il cui Carattere Identificativo è l'H\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 12) {printf("  Il cui Carattere Identificativo è la I\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 13) {printf("  Il cui Carattere Identificativo è la J\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 14) {printf("  Il cui Carattere Identificativo è la K\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 15) {printf("  Il cui Carattere Identificativo è la L\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 16) {printf("  Il cui Carattere Identificativo è l'1\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 17) {printf("  Il cui Carattere Identificativo è la M\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 18) {printf("  Il cui Carattere Identificativo è la N\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 19) {printf("  Il cui Carattere Identificativo è la O\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 20) {printf("  Il cui Carattere Identificativo è la P\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 21) {printf("  Il cui Carattere Identificativo è la Q\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 22) {printf("  Il cui Carattere Identificativo è la R\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 23) {printf("  Il cui Carattere Identificativo è la S\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 24) {printf("  Il cui Carattere Identificativo è il 6\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 25) {printf("  Il cui Carattere Identificativo è la T\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 26) {printf("  Il cui Carattere Identificativo è la U\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 27) {printf("  Il cui Carattere Identificativo è l'8\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 28) {printf("  Il cui Carattere Identificativo è la V\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 29) {printf("  Il cui Carattere Identificativo è la W\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                        if (k == 30) {printf("  Il cui Carattere Identificativo è il 7\n  In Coordinate: "); StampaCoordinate(&Casella[Pressi[k].Posizione[1] + Pressi[k].Posizione[0]].Coordinate[0]); printf("\n\n");}
                    }

                    riga = riga + 1;

                }

                Pressi[k].n = Pressi[k].n - 1;}
            }

        }

        }

        printf("\n---V---\n");

        scanSenzaInvio();

        if (StamPartenzArrivo(&CoordinateDellArrivo[0], &IlTuoArrivo[0], &CharID[0]) == 0) printf("\n\nIl tuo arrivo ha coordinate ");

        StampaCoordinate(&Casella[NumeroCasellaArrivo].Coordinate[0]);

     }

    /*printf("mare:%d costa:%d terra:%d\n\nPartenza: %s\n\nArrivo: %s", Passi[0], Passi[1], Passi[2], Casella[CoordiPartenza].Coordinate, Casella[CoordiArrivo].Coordinate);*/

    printf("\n\n");


    return 0;
}
