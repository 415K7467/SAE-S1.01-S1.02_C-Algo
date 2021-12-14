#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int menu(){
    int ch =0;
    printf("\nQue voulez vous faire");
    printf("\n\t1-Faire une recherche");
    printf("\n\t2-Modifier une valeur");
    printf("\n\t3-Supprimer une ligne");
    printf("\n\t4-Ajouter une valeur");
    printf("\n\t5-Tout afficher");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
            printf("recherche();");
            break;
        case 2 :
            printf("modifier();");
            break;
        case 3 :
            printf("Supprimer();");
            break;
        case 4 :
            printf("Ajouter();");
            break;
        case 5 :
            printf("afficher();");
            break;
        default :
            printf("Erreur de saisie");
            break;
    }
}

int main() {
    char c = '\0'; // or c=0; //code ASCII
    FILE *fic;
    char tuple[130];
    ABONNE personne;
    int nb_personnes = 0;
    fic = fopen(chemin, "r");
    if (fic == NULL) {
        puts("Pb d'ouverture du fichier annuaire !");
        exit(0);
    }
    afficher_tout(fic, tuple);
    nb_personnes = compter(fic, nb_personnes, tuple);
    printf("il y a %d personnes",nb_personnes);
    return 0;
}
