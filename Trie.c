#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct abonne;
#include "fonctions.h"
extern int NBPERS;
//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

//----------------------------------------------Trie----------------------------------------------//
void switch_tri(FILE *fic, int trie,int x);

typedef struct liaison{
    * addresse
    char truc[30]       //peut correspondre au prénom; nom; adresse; numéro ...
} LIASON;

int menu_tri(FILE *fic, int trie){
    int x;
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
        printf("erreur de saisie");
    }
    switch_tri(fic,trie,x);
}

void switch_tri(FILE *fic, int trie,int x){
    switch(x) {
        case 1 :
            if (trie != 1) {
                trier(fic, 1);
                trie=1;
            }
            break;
        case 2 :
            if (trie != 2) {
                trier(fic, 2);
                trie=2;
            }
            break;
        case 3 :
            if (trie != 3) {
                trier(fic, 3);
                trie=3;
            }
            break;
        case 4 :
            if (trie != 4) {
                trier(fic, 4);
                trie=4;
            }
            break;
        case 5 :
            if (trie != 5) {
                trier(fic, 5);
                trie=5;
            }
            break;
        case 6 :
            if (trie != 6) {
                trier(fic, 6);
                trie=6;
            }
            break;
        case 7 :
            if (trie != 7) {
                trier(fic, 7);
                trie=7;
            }
            break;
    }
}

void trier(FILE *fic, int trie){
    // fait la tab de trie//
    LIASON tab[NBPERS];
    int i=0;
    rewind(fic);
    while (fgets(tab, NBPERS, fic) != NULL) {
        tab[i][0]= &tableaudepointeur[i]; //mettre l'addresse de la struct      ;       //tableaudepointeur[i]; ?????
        char *token = strtok(tab, ",");
        int a=-1;
        while (token != NULL) {
            a++;
            if (a==trie){
                tab[i][1]=token;
            }
            token = strtok(NULL, ",");
        }
        printf("%s",tab[i]);
        i++;
    }
    //utiliser la fonction structure
}

















