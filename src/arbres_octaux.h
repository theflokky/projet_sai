#include "objects.h"



//Structure d'arbre octal
typedef struct ArbreOctal{
    int profondeur;
    float angle_hg[3];
    float angle_bd[3];
    int nombre_objets;
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
void affiche_arbre_octal(arbre_octal A);
arbre_octal genere_arbre_octal(int profondeur_arbre, float x1, float y1, float z1, float x2, float y2, float z2);
void dessine_cube(float x1, float y1, float z1, float x2, float y2, float z2);