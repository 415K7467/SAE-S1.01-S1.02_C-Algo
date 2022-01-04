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

    fclose(fic);
    printf("Ajout reussi");

    return 0;
}

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

int trier(FILE *fic,int trie){

    trie=1;
}

switch_tri(FILE *fic,int trie, int x){
    switch(x){
        case 1 :
            if (trie!=1){
                trier(fic,1);
            }
            break;
        case 2 :
            if (trie!=2){
                trier(fic,2);
            }
            break;
        case 3 :
            if (trie!=3){
                trier(fic,3);
            }
            break;
        case 4 :
            if (trie!=4){
                trier(fic,4);
            }
            break;
        case 5 :
            if (trie!=5){
                trier(fic,5);
            }
            break;
        case 6 :
            if (trie!=6){
                trier(fic,6);
            }
        case 7 :
            if (trie!=7){
                trier(fic,7);
            }
            break;
}

int menu_tri(FILE *fic,int trie, char tuple[]){
    int nb_personnes=0,x;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-tri par prénom\n");
    printf("\n\t2-tri par nom\n");
    printf("\n\t3-tri par ville\n");
    printf("\n\t4-tri par code postal\n");
    printf("\n\t5-tri par numéro de téléphone\n");
    printf("\n\t6-tri par mail\n");
    printf("\n\t7-tri par métier\n");
    scanf("%d", &x);
    if (x<=7){
        switch_tri(*fic,tri,x);
    }
}

int menu_recherche(FILE *fic,int trie, char tuple[]){
    int nb_personnes=0,x;
    printf("choisir ce que l'on recherche:");
    printf("\n\t1-recherche d'un prénom\n");
    printf("\n\t2-recherche d'un nom\n");
    printf("\n\t3-recherche d'une ville\n");
    printf("\n\t4-recherche d'un code postal\n");
    printf("\n\t5-recherche d'un numéro de téléphone\n");
    printf("\n\t6-recherche d'un mail\n");
    printf("\n\t7-recherche d'un métier\n");
    scanf("%d",&x);
    if (x<=7){
        switch_tri(*fic,tri,x);
    }
    int ig=0, id=compter(fic, nb_personnes, tuple)-1;   //ig= indice gauche; id=indice droit//
    rewind(fic);
}

int menu(FILE *fic, char tuple[]){
    int ch =0, nb_personnes = 0,trie=0;
    printf("\nQue voulez vous faire");
    printf("\n\t1-Faire une recherche");
    printf("\n\t2-Modifier une valeur");
    printf("\n\t3-Supprimer une ligne");
    printf("\n\t4-Ajouter une valeur");
    printf("\n\t5-Tout afficher");
    printf("\n\t6-Tout compter\n\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
            menu_recherche(fic,trie, tuple);
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
            afficher_tout(fic, tuple);
            break;
        case 6 :
            nb_personnes = compter(fic, nb_personnes, tuple);
            printf("il y a %d personnes",nb_personnes);
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
    fic = fopen(chemin, "r");
    if (fic == NULL) {
        puts("Pb d'ouverture du fichier annuaire !");
        exit(0);
    }
    menu(fic, tuple);
    return 0;
}