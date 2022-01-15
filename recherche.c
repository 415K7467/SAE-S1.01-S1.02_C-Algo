#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct abonne;
#include "fonctions.h"
extern int NBPERS;
extern int TRIE;
//----------------------------------------------Recherche----------------------------------------------//
int menu_recherche(FILE *fic,ABONNE tab_point){
    int x;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-recherche d'un pr\202nom");
    printf("\n\t2-recherche d'un nom");
    printf("\n\t3-recherche d'une ville");
    printf("\n\t4-recherche d'un code postal");
    printf("\n\t5-recherche d'un num\202ro de t\202l\202phone");
    printf("\n\t6-recherche d'un mail");
    printf("\n\t7-recherche d'un m\202tier\n");
    scanf("%d",&x);
    if (x<=7){
        printf("erreur de saisie");
    }
    verif_tri(fic,x);
    int ig=0, id=NBPERS-1;   //ig= indice gauche; id=indice droit//
    rewind(fic);
}
