//LIBRAIRIES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include "constants.h"

//TYPES
//Definition d'un type objet qui comprends la taille et la position d'un objets de la carte
typedef struct Objet{
    /*TYPES D'OBJETS
        1 : ILES
        2 : BUILDING 
        3 : */
    int type; 
    float x;
    float y;
    float z;
    float largeur;
    float longueur;
    float hauteur;
}objet;

//Definition du type ile qui comprends tous les objets de l'ile (ile comprise)
typedef struct Ile{
    int nb_objets;
    objet objets[NB_OBJETS_MAX];
}ile;

//FONCTIONS
void building1(float x, float y, float z, float heigth);