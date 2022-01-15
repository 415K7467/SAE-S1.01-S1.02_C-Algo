#include <stdio.h>
typedef struct abonne ABONNE;
#include <time.h>
#include "fonctions.h"

//----------------------------------------------Recherche----------------------------------------------//
void recherche_interpolation(char tab[], char x);
void menu_recherche(FILE *fic,ABONNE tab_point){
    char a,recherche;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-recherche d'un pr\202nom");
    printf("\n\t2-recherche d'un nom");
    printf("\n\t3-recherche d'une ville");
    printf("\n\t4-recherche d'un code postal");
    printf("\n\t5-recherche d'un num\202ro de t\202l\202phone");
    printf("\n\t6-recherche d'un mail");
    printf("\n\t7-recherche d'un m\202tier\n");
    scanf("%s",&a);
    int x=(int)a;
    if (x<=7){
        printf("erreur de saisie");
    }
    clock_t startTime, endTime;
    startTime = clock();
    verif_tri(fic,x);
    //int ig=0, id=NBPERS-1;   //ig= indice gauche; id=indice droit//
    //rewind(fic);
    printf("entrez se que vous recherchez :\n");
    scanf("%s",&recherche)
    //recherche_interpolation(tab_point,recherche);

    endTime = clock();
    printf("\nTemps d'execution : %ld s.\n", (endTime - startTime) / CLOCKS_PER_SEC);
}
/*
void recherche_interpolation(char tab[], char x) {
    int gauche = 0, droite = NBPERS - 1;
    while (gauche < droite) {
        int a = (tab[droite] - tab[gauche]) / (droite - gauche), b = tab[gauche] - agauche;
        int milieu = (gauche + droite) / 2, k = (tab[milieu] - b) / (a);
        if (x == *tab[k]) {
            trouve =[-1
            for
            i
            in
            range(len(tab) - 1)]
            i = 0
        }
        while (tab[k + i] == x) {
            trouve[i] = k + i
            i += 1
            j = 1
        }
        while (tab[k - j] == x) {
            trouve[i + j - 1] = k - j;
            j++;
            printf("%s", trouve);
        }
        if (x > tab[k]) {
            gauche = k + 1
        }
        if (x < tab[k]) {
            droite = k - 1;
        }
    }
}*/