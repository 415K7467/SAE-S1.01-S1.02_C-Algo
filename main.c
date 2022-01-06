#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fonctions.h"

//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

typedef struct abonne {
    char nom[20];
    char prenom[20];
    char adresse[30];
    char numTel[20];
    char adresseMail[20];
    char profession[20];
} ABONNE;

void structure(){
    FILE *fic = fopen(chemin, "r");
    int nb=compter(fic, 0);
    ABONNE *tableaudepointeur[nb]; //tableaudepointeur[i]->prenom structure
    for(int i=0; i<nb ;i++){
        tableaudepointeur[i] = malloc(sizeof (ABONNE));
    }
}

int menu(FILE *fic){
    int ch =0, nb_personnes = 0;
    printf("\nQue voulez vous faire");
    printf("\n\t1-Faire une recherche");
    printf("\n\t2-Modifier une valeur");
    printf("\n\t3-Supprimer une ligne");
    printf("\n\t4-Ajouter une valeur");
    printf("\n\t5-Tout afficher");
    printf("\n\t6-Trier");
    printf("\n\t7-Tout compter\n\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
            menu_recherche(fic,0);
            break;
        case 2 :
            printf("modifier();");
            break;
        case 3 :
            printf("Supprimer();");
            break;
        case 4 :
            ajouter(fic);
            break;
        case 5 :
            afficher_tout(fic);
            break;
        case 6:
            menu_tri(fic,0);
            break;
        case 7 :
            nb_personnes = compter(fic, nb_personnes);
            printf("il y a %d personnes",nb_personnes);
            break;
        default :
            printf("Erreur de saisie");
            break;
    }
}

int main(){
    char c = '\0'; // or c=0; //code ASCII
    FILE *fic;
    ABONNE personne;
    fic = fopen(chemin, "r");
    if (fic == NULL) {
        puts("Pb d'ouverture du fichier annuaire !");
        exit(0);
    }
    menu(fic);
    return 0;
}