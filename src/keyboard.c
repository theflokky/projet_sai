#include "keyboard.h"

extern int direction_bool[];
int affiche_hitbox = 0;

//Fonction qui gere quand on appuie sur une touche
void keyboard(unsigned char key, int x, int y){
    //Switch pour les commandes claviers
    switch (key){
        //On avance
        case 'z':
            direction_bool[0] = 1; 
        break;

        //On recule
        case 's':
            direction_bool[1] = 1; 
        break;

        //On va a droite
        case 'd':
            direction_bool[2] = 1; 
        break;

        //On va a gauche
        case 'q':
            direction_bool[3] = 1; 
        break;

        //On quitte le jeu
        case 'e':
            exit(0);
        break;

        case 'c':
            affiche_hitbox = 1;
        break;

        
        case 'v':
            affiche_hitbox = 0;
        break;

        

        default:
        break;
    }
}

//Fonction qui gere quand on relache une touche (pour s'arreter)
void keyboard_release(unsigned char key, int x, int y){
        //Switch pour les commandes claviers
    switch (key){
        //On avance
        case 'z':
            direction_bool[0] = 0; 
        break;

        //On recule
        case 's':
            direction_bool[1] = 0; 
        break;

        //On va a droite
        case 'd':
            direction_bool[2] = 0; 
        break;

        //On va a gauche
        case 'q':
            direction_bool[3] = 0; 
        break;

        default:
        break;
    }
}