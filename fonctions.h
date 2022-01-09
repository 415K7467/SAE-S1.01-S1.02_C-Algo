#ifndef SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
#define SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
typedef struct abonne {
    char nom[20];
    char prenom[20];
    char adresse[30];
    char codepost[5];
    char numTel[20];
    char adresseMail[20];
    char profession[20];
} ABONNE;


extern int NBPERS;
//main//
ABONNE structure();
void menu(FILE *fic);
int main();

//ajouter-modifier-supprimmer//
int ajouter(FILE *fic);

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