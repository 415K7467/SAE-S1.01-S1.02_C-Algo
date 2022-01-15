#include <stdio.h>

#include "fonctions.h"

typedef struct abonne ABONNE;

//----------------------------------------------Trie----------------------------------------------//

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
    printf("trie debut:%d\n",x);
    // fait la tab de trie//
    //ABONNE *tab_abo;
    printf("trie 3:%d\n",x);
    //tab_abo= (ABONNE *)malloc(sizeof(ABONNE) * NBPERS);
    //tab_abo[NBPERS] = &tab_point;
    printf("trie 4:%d\n",x);
    LIASON tab[NBPERS];
    printf("trie 5:%d\n",x);
   /* for (int i = 0; i < NBPERS; i++) {
        tab[i] = malloc(sizeof(LIASON));
        printf("trie 6:%d\n",x);
    }*/

    for (int i = 0; i < NBPERS; i++) {
        printf("trie:%d\n",x);
        tab[i].ad = (ABONNE) tab_abo[i];         //mettre l'addresse de la struct      ;       //tableaudepointeur[i]; ?????
        switch (x) {
            case 1:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].nom[j];
                }
                break;
            case 2:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].prenom[j];
                }
                break;
            case 3:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].adresse[j];
                }
                break;
            case 4:
                for (int j = 0; j < 5; j++) {
                    tab[i].truc[j] = tab_abo[i].codepost[j];
                }
                break;
            case 5:
                for (int j = 0; j < 20; j++) {
                    tab[i].truc[j] = tab_abo[i].numTel[j];
                }
                break;
            case 6:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].adresseMail[j];
                }
                break;
            case 7:
                printf("test");
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].profession[j];
                }
                break;
            default:
                printf("erreur %d\n",x);
        }
    }
    printf("debut\n");
    for (int j = 0; j < NBPERS; j++) {
        printf("addresse:\t%p| truc:\t%s\n", tab[j].ad, tab[j].truc);
    }
    printf("fin");
}