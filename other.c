#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
typedef struct abonne ABONNE;
int NBPERS;

void afficher_tout(FILE *fic) {// affiche tous les abonnés dans le fichier
    clock_t startTime, endTime;
    startTime = clock();

    rewind(fic);
    char tab[220];
    while (fgets(tab, NBPERS, fic) != NULL) {
        // Returns first token
        char *token = strtok(tab, ",");
        // Keep printing tokens while one of the delimiters present in tuple.

        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    endTime = clock();
    printf("\nTemps d'execution : %ld s.\n", (endTime - startTime) / CLOCKS_PER_SEC);
}

void compter(FILE *fic) {//Compte le nombre de client
    NBPERS=0;
    char tab[50000];
    rewind(fic);
    while (fgets(tab, 50000, fic) != NULL) {
        NBPERS++;
    }
}

