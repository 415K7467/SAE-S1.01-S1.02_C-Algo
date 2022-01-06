#ifndef SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
#define SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H


extern int NBPERS;
//main//
void structure();
void menu(FILE *fic);
int main();

//ajouter-modifier-supprimmer//
int ajouter(FILE *fic);

//trie//
void trier(FILE *fic, int trie);
void switch_tri(FILE *fic, int trie,int x);
int menu_tri(FILE *fic, int trie);

//recherche//
int menu_recherche(FILE *fic, int trie);

//other//
char afficher_tout(FILE *fic);
int compter(FILE *fic);


#endif //SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
