#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define chemin "test.csv"

typedef struct abonne {
    char nom[20];
    char prenom[20];
    char adresse[30];
    char codepost[5];
    char numTel[20];
    char adresseMail[20];
    char profession[20];
} ABONNE;

void structure(){
    FILE *fic = fopen(chemin, "r");
    char tabl[500];
    //int nb=compter(fic, 0, tabl);
    ABONNE *tableaudepointeur[nb]; //tableaudepointeur->prenom structure
    for(int i=0; i<nb ;i++){
        tableaudepointeur[i] = malloc(sizeof (ABONNE));
    }
}

int modifier(FILE *fic){



}




