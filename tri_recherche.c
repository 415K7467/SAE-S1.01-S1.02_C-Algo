#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

//----------------------------------------------Trie----------------------------------------------//
int trier(FILE *fic, int trie){
    trie=1;
}

void switch_tri(FILE *fic, int trie,int x){
    switch(x) {
        case 1 :
            if (trie != 1) {
                trier(fic, 1);
            }
            break;
        case 2 :
            if (trie != 2) {
                trier(fic, 2);
            }
            break;
        case 3 :
            if (trie != 3) {
                trier(fic, 3);
            }
            break;
        case 4 :
            if (trie != 4) {
                trier(fic, 4);
            }
            break;
        case 5 :
            if (trie != 5) {
                trier(fic, 5);
            }
            break;
        case 6 :
            if (trie != 6) {
                trier(fic, 6);
            }
            break;
        case 7 :
            if (trie != 7) {
                trier(fic, 7);
            }
            break;
    }
}

//----------------------------------------------Recherche----------------------------------------------//


//----------------------------------------------Menu----------------------------------------------//

int menu_tri(FILE *fic, int trie, char tuple[]){
    int nb_personnes=0,x;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-tri par prénom");
    printf("\n\t2-tri par nom");
    printf("\n\t3-tri par ville");
    printf("\n\t4-tri par code postal");
    printf("\n\t5-tri par numéro de téléphone");
    printf("\n\t6-tri par mail");
    printf("\n\t7-tri par métier\n");
    scanf("%d", &x);
    if (x<=7){
        switch_tri(fic,trie,x);
    }
}

int menu_recherche(FILE *fic, int trie, char tuple[]){
    int nb_personnes=0,x;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-recherche d'un prénom");
    printf("\n\t2-recherche d'un nom");
    printf("\n\t3-recherche d'une ville");
    printf("\n\t4-recherche d'un code postal");
    printf("\n\t5-recherche d'un numéro de téléphone");
    printf("\n\t6-recherche d'un mail");
    printf("\n\t7-recherche d'un métier\n");
    scanf("%d",&x);
    if (x<=7){
        switch_tri(fic,trie,x);
    }
    int ig=0, id=compter(fic, nb_personnes, tuple)-1;   //ig= indice gauche; id=indice droit//
    rewind(fic);
}
