#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"
typedef struct abonne ABONNE;

extern int NBPERS;

//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

//----------------------------------------------Trie----------------------------------------------//
void switch_tri(int trie,int x);

typedef struct liaison{
    ABONNE *ad;
    char truc;     //peut correspondre au prénom; nom; adresse; numéro ...
} LIASON;

void menu_tri(int trie){
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
    if (x>7){
        printf("erreur de saisie");
    }
    switch_tri(trie,x);
}

void switch_tri(int trie,int x){
    switch(x) {
        case 1 :
            if (trie != 1) {
                trier(1);
                trie=1;
            }
            break;
        case 2 :
            if (trie != 2) {
                trier(2);
                trie=2;
            }
            break;
        case 3 :
            if (trie != 3) {
                trier(3);
                trie=3;
            }
            break;
        case 4 :
            if (trie != 4) {
                trier(4);
                trie=4;
            }
            break;
        case 5 :
            if (trie != 5) {
                trier(5);
                trie=5;
            }
            break;
        case 6 :
            if (trie != 6) {
                trier(6);
                trie=6;
            }
            break;
        case 7 :
            if (trie != 7) {
                trier(7);
                trie=7;
            }
            break;
    }
}

void trier(int trie){
    // fait la tab de trie//
                                        //je sais pas ou le free(void *TABPOINT)
    ABONNE tab_abo[NBPERS];
    tab_abo[NBPERS]= structure();

    LIASON *tab[NBPERS];
    for(int i=0; i<NBPERS ;i++){
        tab[i]=malloc(sizeof (LIASON));
    }


   for(int i=0;i<NBPERS;i++) {
        tab[i]->ad=&tab_abo[i];         //mettre l'addresse de la struct      ;       //tableaudepointeur[i]; ?????
        switch (trie) {
            case 1:
                tab[i]->truc= *tab_abo[i].nom;
                break;
            case 2:
                tab[i]->truc= *tab_abo[i].prenom;
                break;
            case 3:
                tab[i]->truc= *tab_abo[i].adresse;
                break;
            case 4:
                tab[i]->truc= *tab_abo[i].codepost;
                break;
            case 5:
                tab[i]->truc= *tab_abo[i].numTel;
                break;
            case 6:
                tab[i]->truc= *tab_abo[i].adresseMail;
                break;
            case 7:
                tab[i]->truc= *tab_abo[i].profession;
                break;
        }
        char *token = strtok(tab, ",");
    }
    // à partir de là ça marche plus
    printf("debut\n");
   for(int j=0;j<NBPERS;j++){
        printf("addresse:\t%A| truc:\t%c\n", tab[j]->ad, tab[j]->truc);
    }
    printf("fin");
}