#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"
extern int NBPERS;
//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"


int ajouter(FILE *fic){
    char chaine[100];
    fclose(fic);
    fic = fopen(chemin, "a") ;
    if (fic==NULL){
        puts("Pb d'ouverture du fichier annuaire !");
        exit(1);
    }
    fflush(stdin);
    printf("\nEntrer son Prenom : ");
    gets(&chaine);
    fprintf(fic,"%s",chaine);
    printf("\nEntrer son Nom : ");
    gets(&chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer sa Ville : ");
    gets(&chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Code postal : ");
    gets(&chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Num\202ro de t\202l\202phone : ");
    gets(&chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Adresse Mail : ");
    gets(&chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son M\202tier : ");
    gets(&chaine);
    fprintf(fic,"%s\n",chaine);
    NBPERS++;
    fclose(fic);
    printf("Ajout reussi");

    return 0;
}
