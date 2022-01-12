#ifndef SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
#define SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
typedef struct abonne {
    char nom[40];
    char prenom[40];
    char adresse[40];
    char codepost[5];
    char numTel[20];
    char adresseMail[40];
    char profession[40];
} ABONNE;

extern int TRIE;
extern int NBPERS;

//main//
void structure(ABONNE *);
void menu(FILE *fic,ABONNE* tab_point);
int main();

//ajouter-modifier-supprimmer//
int ajouter(FILE *fic);

//trie//
void trier(int x, ABONNE* tab_point);
void verif_tri(int x, ABONNE* tab_point);
void menu_tri(ABONNE* tab_point);

//recherche//
int menu_recherche(FILE *fic,ABONNE tab_point);

//other//
void afficher_tout(FILE *fic);
void compter(FILE *fic);


#endif //SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H