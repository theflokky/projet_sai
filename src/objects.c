//INCLUDE
#include "objects.h"

//FONCTIONS
//Fonction qui dessine un immeuble de taille 10 * 10 * hauteur a la coordonne x, y
void building1(float x, float z, float heigth){
    glBegin(GL_QUADS);
        glColor3f(0.3, 0.2, 0.1);
        //Generation de la face du dessus
        glVertex3f(x, heigth, z);
        glVertex3f(x+10, heigth, z);
        glVertex3f(x+10, heigth, z+10);
        glVertex3f(x, heigth, z+10);

        //Faces cotes
        glVertex3f(x, heigth, z);
        glVertex3f(x+10, heigth, z);
        glVertex3f(x+10, 0, z);
        glVertex3f(x, 0, z);

        glVertex3f(x, heigth, z);
        glVertex3f(x, heigth, z+10);
        glVertex3f(x, 0, z+10);
        glVertex3f(x, 0, z);

        glVertex3f(x, heigth, z+10);
        glVertex3f(x+10, heigth, z+10);
        glVertex3f(x+10, 0, z+10);
        glVertex3f(x, 0, z+10);

        glVertex3f(x+10, heigth, z);
        glVertex3f(x+10, heigth, z+10);
        glVertex3f(x+10, 0, z+10);
        glVertex3f(x+10, 0, z);
    glEnd();
}