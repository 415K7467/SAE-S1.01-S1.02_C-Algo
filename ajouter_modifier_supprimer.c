#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define chemin "C:/Users/Utilisateur/Desktop/SAE-S1.01-S1.02_C-Algo-main/9 janvier/SAE-S1.01-S1.02_C-Algo/test.csv"
#define chemin2 "C:/Users/Utilisateur/Desktop/SAE-S1.01-S1.02_C-Algo-main/9 janvier/SAE-S1.01-S1.02_C-Algo/tmp.csv"
//#define chemin "C:/Users/Administrateur/OneDrive - etu.univ-lyon1.fr/Documents/S1/SAE/SAE1.2_C-algo/SAE-S1.01-S1.02_C-Algo/test.csv"

typedef struct abonne ABONNE;
extern int NBPERS;

int ajouter(FILE *fic){ //Ajoute un Abonnée avec son prenom,nom,...
    char chaine[100];
    fclose(fic);
    fic = fopen(chemin, "a") ;
    if (fic==NULL){
        puts("Pb d'ouverture du fichier annuaire !");
        exit(1);
    }
    fflush(stdin);
    printf("\nEntrer son Prenom : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Nom : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer sa Ville : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Code postal : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Num\202ro de t\202l\202phone : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son Adresse Mail : ");
    gets(chaine);
    fprintf(fic,"%s,",chaine);
    printf("\nEntrer son M\202tier : ");
    gets(chaine);
    fprintf(fic,"%s\n",chaine);
    NBPERS++;
    fclose(fic);
    printf("Ajout reussi");
    return 0;
}

void Supprimer(){ //supprime une ligne du fichier en sachant la ligne
    int del_ligne,temp=1;
    FILE *fic = fopen(chemin, "r");
    FILE *fichiertmp = fopen(chemin2, "w");
    printf("Il y a %d ligne\n",NBPERS);
    printf("Quel ligne voulez vous supprimer :\n");
    scanf("%d",&del_ligne);
    char ligne[200];
    while(fgets(ligne,200,fic)!=NULL) {
        if(temp != del_ligne ){
            fputs(ligne, fichiertmp);
            printf("ligne %d copier\n",temp);
        }
        temp++;
    }
    NBPERS--;
    printf("les clients ont bien été copiés");
    fclose(fichiertmp);
    fclose(fic);
    remove(chemin);
    rename(chemin2, chemin);

}

 void modifier(){ //modifie soit le prenom,nom,... selon une ligne
     char modif[40];
     char tab[8][40];
     int mod_ligne,temp=1,choixmodif,i,j=0,k=0;
     FILE *fic = fopen(chemin, "r");
     FILE *fichiertmp = fopen(chemin2, "w");
     printf("Il y a %d ligne\n",NBPERS);
     printf("Quel ligne voulez vous modifier :\n");
     scanf("%d",&mod_ligne);
     char ligne[200];
     while(fgets(ligne,200,fic)!=NULL) {
         if(temp != mod_ligne ){
             fputs(ligne, fichiertmp);
         }
         if(temp == mod_ligne ) {
             for (int i=0; i < strlen(ligne); i++) {
                 if (ligne[i] == ',') {
                     k = 0;
                     j++;
                 } else {
                     tab[j][k] = ligne[i];
                     k++;
                 }
             }
             printf("Quel donn\202 voulez vous modifier\n");
             printf("\t1-Modifier le prenom\n");
             printf("\t2-Modifier le nom\n");
             printf("\t3-Modifier la ville\n");
             printf("\t4-Modifier le code postal\n");
             printf("\t5-Modifier le num\202ro de t\202l\202phone\n");
             printf("\t6-Modifier l adresse mail\n");
             printf("\t7-Modifier le m\202tier\n");
             scanf("%d", &choixmodif);
             i=0;
             switch (choixmodif) {
                 case 1:
                     printf("\nEntrer son Prenom : ");
                     break;
                 case 2:
                     printf("\nEntrer son Nom : ");
                     break;
                 case 3:
                     printf("\nEntrer sa Ville : ");
                     break;
                 case 4:
                     printf("\nEntrer son Code postal : ");
                     break;
                 case 5:
                     printf("\nEntrer son Num\202ro de t\202l\202phone : ");
                     break;
                 case 6:
                     printf("\nEntrer son Adresse Mail : ");
                     break;
                 case 7:
                     printf("\nEntrer son M\202tier : ");
                     break;
                 default:
                     break;
             }
             fflush(stdin);
             gets(&modif);
             while (i<40) {
                 tab[choixmodif - 1][i] = modif[i];
                 i++;
             }
             printf("\n");
             i=0,k=0;
             while (i < 7) {
                 k = 0;
                 //printf("test");
                 while (tab[i][k] != NULL) {
                     printf("%c", tab[i][k]);
                     fprintf(fichiertmp,"%c",tab[i][k]);
                     k++;
                 }
                 printf("\n");
                 fprintf(fichiertmp,",");
                 i++;
             }
         }
         temp++;
     }
     NBPERS--;
     printf("\ntest");
     printf("Le client a \202t\202 modifier");
     printf("\ntest");
     fclose(fichiertmp);
     printf("\ntest");
     fclose(fic);
     printf("\ntest");
     int test = remove(chemin);
     printf("\n\ttest%d",test);
     test = rename(chemin2, chemin);
     printf("\n\ttest%d",test);
 }