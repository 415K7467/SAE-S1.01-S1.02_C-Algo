#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

typedef struct abonne ABONNE;

extern int NBPERS;
extern int TRIE;
//----------------------------------------------Trie----------------------------------------------//
void verif_tri(int x, ABONNE* tab_point);

void trier(int x, ABONNE* tab_point);

typedef struct liaison {
    ABONNE ad;
    char truc[41];     //peut correspondre au prénom; nom; adresse; numéro ...
} LIASON;

void menu_tri(ABONNE* tab_point) {
    int x;
    printf("choisir par quoi l'on trie:");
    printf("\n\t1-tri par prenom");
    printf("\n\t2-tri par nom");
    printf("\n\t3-tri par ville");
    printf("\n\t4-tri par code postal");
    printf("\n\t5-tri par numero de telephone");
    printf("\n\t6-tri par mail");
    printf("\n\t7-tri par metier\n");
    scanf("%d", &x);
    if (x > 7) {
        printf("erreur de saisie");
    }
    verif_tri(x, tab_point);
}

void verif_tri(int x, ABONNE* tab_point) { // vérifie si c'est déjà trié en fonction du critère choisi, la fonction est appellé par menu tri ou menu recherche car nous voulons faire la recherche par interpolation qui utilise un tableau déjà trié
    if (TRIE != x) {
        printf("test,%d\n",x);
        trier(x, tab_point);
        TRIE = x;
    }
}

void trier(int x, ABONNE* tab_abo) {//x correspond à la position du champs/critère de tri
    LIASON *tab,*tmp[2];
    tab=(LIASON *) malloc(sizeof (LIASON)*NBPERS);
    for (int i = 0; i < NBPERS; i++) {
        tmp[0] =  &tab_abo[i];         //mettre l'addresse de la struct      ;       //tableaudepointeur[i]; ?????
        switch (x) {
            case 1:
                for (int j = 0; j < 40; j++) {
                    tmp[1] = tab_abo[i].nom[j];
                }
                break;
            case 2:
                for (int j = 0; j < 40; j++) {
                    tmp[1] = tab_abo[i].prenom[j];
                }
                break;
            case 3:
                for (int j = 0; j < 40; j++) {
                    tmp[1]  = tab_abo[i].adresse[j];
                }
                break;
            case 4:
                for (int j = 0; j < 5; j++) {
                    tmp[1]  = tab_abo[i].codepost[j];
                }
                break;
            case 5:
                for (int j = 0; j < 20; j++) {
                    tmp[1]  = tab_abo[i].numTel[j];
                }
                break;
            case 6:
                for (int j = 0; j < 40; j++) {
                    tmp[1] = tab_abo[i].adresseMail[j];
                }
                break;
            case 7:
                printf("test");
                for (int j = 0; j < 40; j++) {
                    tmp[1]  = tab_abo[i].profession[j];
                    printf("test metier:\t %s\n", tab_abo[i].profession[j]);
                }
                break;
            default:
                printf("erreur %d\n",x);
        }
        printf("%s",tmp[1]);
        LIASON x={tmp[0],tmp[1]};
        *(tab+i)=x;
    }
    printf("debut\n");
    for (int j = 0; j < NBPERS; j++) {
        printf("addresse:\t%p| truc:\t%s\n", tab[j].ad, tab[j].truc);
    }
    printf("fin");
}