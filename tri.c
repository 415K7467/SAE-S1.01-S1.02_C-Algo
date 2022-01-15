#include <stdio.h>
#include <time.h>
#include "fonctions.h"

typedef struct abonne ABONNE;

//----------------------------------------------Trie----------------------------------------------//
//void triFusion(int i, int j, char *tab[], char tmp[]);

typedef struct liaison {
    ABONNE ad;
    char truc[41];     //peut correspondre au prénom; nom; adresse; numéro ...
} LIASON;

void menu_tri(ABONNE* tab_point) {
    int x;
    printf("choisir par quoi l'on trie:");
    printf("\n\t1-tri par prenom");
    printf("\n\t2-tri par nom");
    printf("\n\t3-tri par ville");
    printf("\n\t4-tri par code postal");
    printf("\n\t5-tri par numero de telephone");
    printf("\n\t6-tri par mail");
    printf("\n\t7-tri par metier\n");
    scanf("%d", &x);
    if (x > 7) {
        printf("erreur de saisie");
    }
    verif_tri(x, tab_point);
}

void verif_tri(int x, ABONNE* tab_point) { // vérifie si c'est déjà trié en fonction du critère choisi, la fonction est appellé par menu tri ou menu recherche car nous voulons faire la recherche par interpolation qui utilise un tableau déjà trié
    if (TRIE != x) {
        clock_t startTime, endTime;
        startTime = clock();
        trier(x, tab_point);
        endTime = clock();
        printf("\nTemps d'execution : %ld s.\n", (endTime - startTime) / CLOCKS_PER_SEC);
        TRIE = x;
    }
}

void trier(int x, ABONNE* tab_abo) {//x correspond à la position du champs/critère de tri
    // fait la tab de trie//
    //ABONNE *tab_abo;
    //tab_abo= (ABONNE *)malloc(sizeof(ABONNE) * NBPERS);
    //tab_abo[NBPERS] = &tab_point;
    LIASON tab[NBPERS];
   /* for (int i = 0; i < NBPERS; i++) {
        tab[i] = malloc(sizeof(LIASON));
        printf("trie 6:%d\n",x);
    }*/

    for (int i = 0; i < NBPERS; i++) {
        tab[i].ad = (ABONNE) tab_abo[i];         //mettre l'addresse de la struct      ;       //tableaudepointeur[i]; ?????
        switch (x) {
            case 1:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].nom[j];
                }
                break;
            case 2:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].prenom[j];
                }
                break;
            case 3:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].adresse[j];
                }
                break;
            case 4:
                for (int j = 0; j < 5; j++) {
                    tab[i].truc[j] = tab_abo[i].codepost[j];
                }
                break;
            case 5:
                for (int j = 0; j < 20; j++) {
                    tab[i].truc[j] = tab_abo[i].numTel[j];
                }
                break;
            case 6:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].adresseMail[j];
                }
                break;
            case 7:
                for (int j = 0; j < 40; j++) {
                    tab[i].truc[j] = tab_abo[i].profession[j];
                }
                break;
            default:
                printf("erreur %d\n",x);
        }
    }
    //La partie si dessous est la fin de la partie du tri, le tri n'a pas été fait la structure liaison ne fonctionne pas
    printf("debut\n");
    for (int j = 0; j < NBPERS; j++) {
        printf("addresse:\t%p| truc:\t%s\n", tab[j].ad, tab[j].truc); // Cette partie montre que y a pas les bons trucs dans liaison dsfgshdgreqsgcwvxciutjgkl,h,jigncrjdngfdjb
    }
    printf("fin");
    //char *tmp[NBPERS];
    //triFusion(ig=0, id=NBPERS-1,tab[NBPERS], tmp[NBPERS];)
}

/*
void triFusion(int i, int j, char *tab[], char tmp[]) {

    if(j <= i){ return;}

    int m = (i + j) / 2;
    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;
    int pd = m + 1;
    int c;
//boucle pour remplir le tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) {               //tout ce qui est en dessous ne va pas, il ne faut pas échanger les valeurs mais échanger les addresses et comparer le contenu des addresses
            tmp[c] = tab[pd][1];
            pd++;
        }
        else if (pd== j + 1) {
            tmp[c] = tab[pg][1];
            pg++;
        }
        else if (tab[pg][1] < tab[pd][1]) {
            tmp[c] = tab[pg][1];
            pg++;
        }
        else {
            tmp[c] = tab[pd][1];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {
        //tab[c][1] = tmp[c];//copier les éléments de tmp[] à tab[] On cherche pas à faire ça vu qu'on veut passer par adresse
    }
}*/
