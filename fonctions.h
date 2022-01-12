#ifndef SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
#define SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
typedef struct abonne {
    char nom[40];
    char prenom[40];
    char adresse[40];
    char codepost[8];
    char numTel[15];
    char adresseMail[50];
    char profession[40];
} ABONNE;


extern int NBPERS;
//main//
ABONNE structure();
void menu(FILE *fic);
int main();

//ajouter-modifier-supprimmer//
int ajouter(FILE *fic);
void modifier();
void Supprimer();

//trie//
void trier(int trie);
void switch_tri(int trie,int x);
void menu_tri(int trie);

//recherche//
int menu_recherche(FILE *fic, int trie);

//other//
void afficher_tout(FILE *fic);
void compter(FILE *fic);


#endif //SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H