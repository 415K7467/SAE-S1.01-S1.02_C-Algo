#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

//----------------------------------------------Recherche----------------------------------------------//
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
