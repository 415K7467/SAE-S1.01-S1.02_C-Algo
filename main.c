#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

typedef struct abonne ABONNE;
#define chemin "C:/Users/Utilisateur/Desktop/SAE-S1.01-S1.02_C-Algo-main/9 janvier/SAE-S1.01-S1.02_C-Algo/test.csv"
//#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"



/*ABONNE structure(){
    FILE *fic = fopen(chemin, "r");
    ABONNE *tableaudepointeur; //tableaudepointeur[i]->prenom structure


        tableaudepointeur= (ABONNE *)malloc(sizeof (ABONNE)*NBPERS);

    rewind(fic);
    char* tmp[7];
    int j=0;
    while (fgets(tab, NBPERS, fic) != NULL) {
        int a=0;
        char *token = strtok(tab, ",");
        while (token != NULL) {
            tmp[a]=*token;
            token = strtok(NULL, ",");
            a++;
        }
        ABONNE x ={tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6]};
        tableaudepointeur[j]= &x;

        j++;
    }
    ABONNE *tableau_pointeur= &tableaudepointeur;
    printf("%s",*tableau_pointeur->nom);
    return *tableau_pointeur;
}*/

void menu(FILE *fic) {
    char ch='\0';
    while (ch != 'q') {
        fflush(stdin);
        printf("\nQue voulez vous faire");
        printf("\n\t1-Faire une recherche");
        printf("\n\t2-Trier");
        printf("\n\t3-Supprimer une ligne");
        printf("\n\t4-Modifier une valeur");
        printf("\n\t5-Ajouter une valeur");
        printf("\n\t6-Tout afficher");
        printf("\n\t7-Tout compter");
        printf("\n\tQ-Quitter\n\n");
        scanf("%c", &ch);
        switch (ch) {
            case '1' :
                menu_recherche(fic, 0);
                break;
            case '2' :
                menu_tri(0);

                break;
            case '3' :
                Supprimer();
                break;
            case '4' :
                modifier();

                break;
            case '5' :
                ajouter(fic);
                break;
            case '6':
                afficher_tout(fic);
                break;
            case '7':
                printf("il y a %d personnes", NBPERS);
                break;
            case'q':
                printf("Quitter");
                break;
            default :
                printf("Erreur de saisie");
                break;
            }
        }
    }

int main(){
    FILE *fic;
    fic = fopen(chemin, "r");
    if (fic == NULL) {
        puts("Pb d'ouverture du fichier annuaire !");
        exit(0);
    }
    compter(fic);
    menu(fic);
    return 0;
}