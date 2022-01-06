#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"
extern int NBPERS;
//#define chemin "test.csv"
#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

int modifier(int ligne,char choix,FILE *fic);

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

int menu_modifier(FILE *fic){
    int ligne,choixmodif;
    char chaine[100];
    fclose(fic);
    fic = fopen(chemin, "a") ;
    if (fic==NULL){
        puts("Pb d'ouverture du fichier annuaire !");
        exit(1);
    }
    scanf("%d",&choixmodif);
    printf("Quel donné voulez vous modier\n");
    printf("\t1-Modifier le nom\n");
    printf("\t2-Modifier le prenom\n");
    printf("\t3-Modifier la ville\n");
    printf("\t4-Modifier le code postal\n");
    printf("\t5-Modifier le numéro de téléphone\n");
    printf("\t6-Modifier l adresse mail\n");
    printf("\t7-Modifier le métier\n");
    scanf("%d",&choixmodif);
    printf("Quel ligne voulez vous modifier\n");
    scanf("%d",&ligne);
    switch (choixmodif) {
        case 1:
            modifier(ligne,"nom",fic);
            break;
        case 2:
            modifier(ligne,"prenom",fic);
            break;
        case 3:
            modifier(ligne,"adresse",fic);
            break;
        case 4:
            modifier(ligne,"codepost",fic);
            break;
        case 5:
            modifier(ligne,"numTel",fic);
            break;
        case 6:
            modifier(ligne,"adresseMail",fic);
            break;
        case 7:
            modifier(ligne,"profession",fic);
            break;
        default:
            break;
    }
}
int modifier(int ligne,char choix,FILE *fic){

    fseek(fic,sizeof(ABONNE)*ligne,SEEK_SET);

}
