#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"
int NBPERS;

char afficher_tout(FILE *fic) {
    rewind(fic);
    char tab[130];
    while (fgets(tab, 130, fic) != NULL) {
        // Returns first token
        char *token = strtok(tab, ",");
        // Keep printing tokens while one of the delimiters present in tuple.

        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }
}

int compter(FILE *fic) {
    NBPERS=0;
    char tab[50000];
    rewind(fic);
    while (fgets(tab, 50000, fic) != NULL) {
        NBPERS++;
    }
}

