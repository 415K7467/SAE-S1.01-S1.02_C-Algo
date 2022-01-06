#ifndef SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
#define SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
typedef struct abonne;

//main//
void structure();
int menu(FILE *fic, char tuple[]);
int main();

//ajouter-modifier-supprimmer//
int ajouter(FILE *fic);

//trie//
int trier(FILE *fic, int trie);
void switch_tri(FILE *fic, int trie,int x);
int menu_tri(FILE *fic, int trie, char tuple[]);

//recherche//
int menu_recherche(FILE *fic, int trie, char tuple[]);

//other//
char afficher_tout(FILE *fic, char tuple[]);
int compter(FILE *fic, int nb_personne, char tuple[]);


#endif //SAE_S1_01_S1_02_C_ALGO_FONCTIONS_H
