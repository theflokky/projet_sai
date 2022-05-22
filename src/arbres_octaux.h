#include "objects.h"


//Structure d'arbre octal
typedef struct ArbreOctal{
    int profondeur;
    float angle_hg[3];
    float angle_bd[3];
    objet liste_objets[NB_OBJETS_MAX];
    struct ArbreOctal *fils1;
    struct ArbreOctal *fils2;
    struct ArbreOctal *fils3;
    struct ArbreOctal *fils4;
    struct ArbreOctal *fils5;
    struct ArbreOctal *fils6;
    struct ArbreOctal *fils7;
    struct ArbreOctal *fils8;
}* arbre_octal;

arbre_octal creer_noeud(int valeur);
void ajouter_arbre_octal(arbre_octal A, int i, arbre_octal B);
arbre_octal init_arbre_octal();