#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"


char afficher_tout(FILE *fic, char tuple[]) {
    rewind(fic);
    while (fgets(tuple, 130, fic) != NULL) {
        // Returns first token
        char *token = strtok(tuple, ",");
        // Keep printing tokens while one of the delimiters present in tuple.

        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }
}

int compter(FILE *fic, int nb_personne, char tuple[]) {
    rewind(fic);
    while (fgets(tuple, 130, fic) != NULL) {
        nb_personne++;
    }
    return nb_personne;
}

