#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define chemin "test.csv"


typedef struct abonne{
    char nom[20];
    char prenom[20];
    char adresse[30];
    char numTel[20];
    char adresseMail[20];
    char profession[20];
} ABONNE;


int function(){
  static int count = 0;
  count++;
  return count;
}

char afficher_tout(fic, tuple){
    while (fgets(tuple, 130, fic) != NULL){
        printf("test1");
        // Returns first token
        char* token = strtok(tuple, ",");
        // Keep printing tokens while one of the delimiters present in tuple.

        while (token != NULL){
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }
}

int compter(fic,nb_personne,tuple){
    printf("test2");
    while (fgets(tuple, 130, fic) != NULL){
        char* token = strtok(tuple, ",");
        while (token != NULL){
            nb_personne ++;
        }
    }
    return nb_personne;
}

int main(){
    FILE * fic ;
    fic = fopen(chemin, "r") ;
    if (fic==NULL){
        puts("Pb d'ouverture du fichier annuaire !");
        exit(0);
    }

    //char c='\0'; // or c=0; //code ASCII
    char tuple[130];
    int nb_personnes=0;
    ABONNE personne;

    afficher_tout(fic, tuple);
    nb_personnes= compter(fic,nb_personnes,tuple);
    return 0;
}
