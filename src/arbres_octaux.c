#include "arbres_octaux.h"

//Fonction qui initialise un arbre octal
arbre_octal init_arbre_octal(){
    arbre_octal A;

    A->profondeur = 0;
    A->fils1 = NULL;
    A->fils2 = NULL;
    A->fils3 = NULL;
    A->fils4 = NULL;
    A->fils5 = NULL;
    A->fils6 = NULL;
    A->fils7 = NULL;
    A->fils8 = NULL;

    return A;
}

//Fonction qui ajoute un fils B a la postion i a un arbre octal A 
void ajouter_arbre_octal(arbre_octal A, int i, arbre_octal B){
    switch(i){
        case 1 :
            A->fils1 = B;
            break;
        case 2 :
            A->fils2 = B;
            break;
        case 3 :
            A->fils3 = B;
            break;
        case 4 :
            A->fils4 = B;
            break;
        case 5 :
            A->fils5 = B;
            break;
        case 6 :
            A->fils6 = B;
            break;
        case 7 :
            A->fils7 = B;
            break;
        case 8 :
            A->fils8 = B;
            break;
        default :
            fprintf(stdout, "ERREUR :  Indice Faux Arbre\n");
            break;
    }
}

//Fonction qui affiche un arbre octal dans les terminal
void afficher_arbre_octal(arbre_octal A){
    fprintf(stdout, "Profondeur %d : \n", A->profondeur);
}