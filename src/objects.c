//INCLUDE
#include "objects.h"

//FONCTIONS
//Fonction qui dessine un immeuble de taille 10 * 10 * hauteur a la coordonne x, y
void building1(float x, float y, float z, float heigth){


    glBegin(GL_QUADS);
        glColor3f(0.50, 0.50, 0.46);
        //Generation de la face du dessus
        glVertex3f(x, y+ heigth, z);
        glVertex3f(x+10, y+heigth, z);
        glVertex3f(x+10, y+heigth, z+10);
        glVertex3f(x, y+heigth, z+10);

        //Faces cotes
        glVertex3f(x, y+heigth, z);
        glVertex3f(x+10, y+heigth, z);
        glVertex3f(x+10, y, z);
        glVertex3f(x, y, z);

        glColor3f(0.40, 0.40, 0.40);
        glVertex3f(x, y+heigth, z);
        glVertex3f(x, y+heigth, z+10);
        glVertex3f(x, y, z+10);
        glVertex3f(x, y, z);

        glColor3f(0.50, 0.50, 0.46);
        glVertex3f(x, y+heigth, z+10);
        glVertex3f(x+10, y+heigth, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x, y, z+10);

        glColor3f(0.40, 0.40, 0.40);
        glVertex3f(x+10, y+heigth, z);
        glVertex3f(x+10, y+heigth, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x+10, y, z);
    glEnd();
}

void teleporteur(float x, float y, float z){
    glBegin(GL_QUADS);
        glColor3f(1, 0.2, 0.1);
        //Generation de la face du dessus
        glVertex3f(x, y+ 10, z);
        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x, y+10, z+10);

        //Faces cotes
        glVertex3f(x, y+10, z);
        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y, z);
        glVertex3f(x, y, z);

        glVertex3f(x, y+10, z);
        glVertex3f(x, y+10, z+10);
        glVertex3f(x, y, z+10);
        glVertex3f(x, y, z);

        glVertex3f(x, y+10, z+10);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x, y, z+10);

        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x+10, y, z);
    glEnd();
}

void objet_a_trouver(float x, float y, float z){
        glBegin(GL_QUADS);
        glColor3f(0, 1, 0.1);
        //Generation de la face du dessus
        glVertex3f(x, y+ 1, z);
        glVertex3f(x+1, y+1, z);
        glVertex3f(x+1, y+1, z+1);
        glVertex3f(x, y+1, z+1);

        //Faces cotes
        glVertex3f(x, y+1, z);
        glVertex3f(x+1, y+1, z);
        glVertex3f(x+1, y, z);
        glVertex3f(x, y, z);

        glVertex3f(x, y+1, z);
        glVertex3f(x, y+1, z+1);
        glVertex3f(x, y, z+1);
        glVertex3f(x, y, z);

        glVertex3f(x, y+1, z+1);
        glVertex3f(x+1, y+1, z+1);
        glVertex3f(x+1, y, z+1);
        glVertex3f(x, y, z+1);

        glVertex3f(x+1, y+1, z);
        glVertex3f(x+1, y+1, z+1);
        glVertex3f(x+1, y, z+1);
        glVertex3f(x+1, y, z);
    glEnd();
}

//Fonction qui dessine un arbre 
void tree(float x, float y){

}
