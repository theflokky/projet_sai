//INCLUDE
#include "objects.h"

extern int teleporteur_ouvert;
extern int victoire;
extern int affiche_hitbox;

//FONCTIONS
//Fonction qui dessine un immeuble de taille 10 * 10 * hauteur a la coordonne x, y
void building1(float x, float y, float z, float heigth){
    if(affiche_hitbox){
        glBegin(GL_LINE_STRIP);
            glColor3f(0, 0, 1);
            glVertex3f(x-1, y, z-1);
            glVertex3f(x-1, y + heigth, z-1);

            glVertex3f(x+11, y + heigth, z-1);
            glVertex3f(x+11, y, z-1);
            glVertex3f(x+11, y + heigth, z-1);

            glVertex3f(x+11, y + heigth, z+11);
            glVertex3f(x+11, y, z+11);
            glVertex3f(x+11, y + heigth, z+11);

            glVertex3f(x-1, y + heigth, z+11);
            glVertex3f(x-1, y, z+11);
            glVertex3f(x-1, y + heigth, z+11);

            glVertex3f(x-1, y + heigth, z-1);
            

        glEnd();    
    }

    glBegin(GL_QUADS);
        glColor3f(0.50, 0.50, 0.46);
        //Generation de la face du dessus
        glVertex3f(x, y+ heigth, z);
        glVertex3f(x+10, y+heigth, z);
        glVertex3f(x+10, y+heigth, z+10);
        glVertex3f(x, y+heigth, z+10);

        //Faces cotes
        glColor3f(0.50, 0.50, 0.46);
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
    float heigth = 10;
        if(affiche_hitbox){
        glBegin(GL_LINE_STRIP);
            glColor3f(0, 0, 1);
            glVertex3f(x-1, y, z-1);
            glVertex3f(x-1, y + heigth, z-1);

            glVertex3f(x+11, y + heigth, z-1);
            glVertex3f(x+11, y, z-1);
            glVertex3f(x+11, y + heigth, z-1);

            glVertex3f(x+11, y + heigth, z+11);
            glVertex3f(x+11, y, z+11);
            glVertex3f(x+11, y + heigth, z+11);

            glVertex3f(x-1, y + heigth, z+11);
            glVertex3f(x-1, y, z+11);
            glVertex3f(x-1, y + heigth, z+11);

            glVertex3f(x-1, y + heigth, z-1);
            

        glEnd();    
    }
    glBegin(GL_QUADS);
            
        if(teleporteur_ouvert){
            glColor3f(0, 1, 0.1);
        }
        else{
            glColor3f(1, 0.2, 0.1);
        }
        if(victoire){
            glColor3f(0.99, 0.93,0);
        }

        glVertex3f(x +4, y+ 10, z+4);
        glVertex3f(x+ 6, y+10, z+4);
        glVertex3f(x +6, y+1, z+4);
        glVertex3f(x +4 , y+1, z+4);

        glVertex3f(x +4, y+ 10, z+6);
        glVertex3f(x+ 6, y+10, z+6);
        glVertex3f(x +6, y+1, z+6);
        glVertex3f(x +4 , y+1, z+6);


        if(teleporteur_ouvert){
            glColor3f(0, 0.7, 0);
        }
        else{
            glColor3f(0.7, 0, 0);
        }
        if(victoire){
            glColor3f(1, 1,0);
        }

        glVertex3f(x +6, y+ 10, z+4);
        glVertex3f(x+ 6, y+10, z+6);
        glVertex3f(x +6, y+1, z+6);
        glVertex3f(x +6 , y+1, z+4);

        glVertex3f(x +4, y+ 10, z+4);
        glVertex3f(x+ 4, y+10, z+6);
        glVertex3f(x +4, y+1, z+6);
        glVertex3f(x +4 , y+1, z+4);

        glColor3f(0, 0, 0);
        //Generation de la face du dessus
        glVertex3f(x, y+ 10, z);
        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x, y+10, z+10);

        glVertex3f(x, y+ 8, z);
        glVertex3f(x+10, y+8, z);
        glVertex3f(x+10, y+8, z+10);
        glVertex3f(x, y+8, z+10);

        //Faces cotes
        glVertex3f(x, y+10, z);
        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y+8, z);
        glVertex3f(x, y+8, z);

        glVertex3f(x, y+10, z);
        glVertex3f(x, y+10, z+10);
        glVertex3f(x, y+8, z+10);
        glVertex3f(x, y+8, z);

        glVertex3f(x, y+10, z+10);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x+10, y+8, z+10);
        glVertex3f(x, y+8, z+10);

        glVertex3f(x+10, y+10, z);
        glVertex3f(x+10, y+10, z+10);
        glVertex3f(x+10, y+8, z+10);
        glVertex3f(x+10, y+8, z);

        //Face du dessous
        glVertex3f(x, y+1, z);
        glVertex3f(x+10, y+1, z);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x, y, z+10);

        //Faces cotes
        glVertex3f(x, y+1, z);
        glVertex3f(x+10, y+1, z);
        glVertex3f(x+10, y, z);
        glVertex3f(x, y, z);

        glVertex3f(x, y+1, z);
        glVertex3f(x, y+1, z+10);
        glVertex3f(x, y, z+10);
        glVertex3f(x, y, z);

        glVertex3f(x, y+1, z+10);
        glVertex3f(x+10, y+1, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x, y, z+10);

        glVertex3f(x+10, y+1, z);
        glVertex3f(x+10, y+1, z+10);
        glVertex3f(x+10, y, z+10);
        glVertex3f(x+10, y, z);
    glEnd();
}

void objet_a_trouver(float x, float y, float z){
    float heigth =1;
    if(affiche_hitbox){
        glBegin(GL_LINE_STRIP);
            glColor3f(0, 0, 1);
            glVertex3f(x-1, y, z-1);
            glVertex3f(x-1, y + heigth, z-1);

            glVertex3f(x+2, y + heigth, z-1);
            glVertex3f(x+2, y, z-1);
            glVertex3f(x+2, y + heigth, z-1);

            glVertex3f(x+2, y + heigth, z+2);
            glVertex3f(x+2, y, z+2);
            glVertex3f(x+2, y + heigth, z+2);

            glVertex3f(x-1, y + heigth, z+2);
            glVertex3f(x-1, y, z+2);
            glVertex3f(x-1, y + heigth, z+2);

            glVertex3f(x-1, y + heigth, z-1);
            

        glEnd();    
    }
    glBegin(GL_QUADS);
        glColor3f(0.4, 0.5, 0.1);
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
void arbre(float x, float y, float z, float heigth){
    if(affiche_hitbox){
        glBegin(GL_LINE_STRIP);
            glColor3f(0, 0, 1);
            glVertex3f(x-1, y, z-1);
            glVertex3f(x-1, y + heigth, z-1);

            glVertex3f(x+6, y + heigth, z-1);
            glVertex3f(x+6, y, z-1);
            glVertex3f(x+6, y + heigth, z-1);

            glVertex3f(x+6, y + heigth, z+6);
            glVertex3f(x+6, y, z+6);
            glVertex3f(x+6, y + heigth, z+6);

            glVertex3f(x-1, y + heigth, z+6);
            glVertex3f(x-1, y, z+6);
            glVertex3f(x-1, y + heigth, z+6);

            glVertex3f(x-1, y + heigth, z-1);
            

        glEnd();    
    }

    glBegin(GL_QUADS);
        glColor3f(0.34, 0.16, 0);
        glVertex3f(x +2, y+ 2, z+2);
        glVertex3f(x+ 3, y+2, z+2);
        glVertex3f(x +3, y, z+2);
        glVertex3f(x +2 , y, z+2);

        glVertex3f(x +2, y+ 2, z+3);
        glVertex3f(x+ 3, y+2, z+3);
        glVertex3f(x +3, y, z+3);
        glVertex3f(x +2 , y, z+3);

        glColor3f(0.27, 0.12, 0);
        glVertex3f(x +3, y+ 2, z+2);
        glVertex3f(x+ 3, y+2, z+3);
        glVertex3f(x +3, y, z+3);
        glVertex3f(x +3 , y, z+2);

        glVertex3f(x +2, y+ 2, z+2);
        glVertex3f(x+ 2, y+2, z+3);
        glVertex3f(x +2, y, z+3);
        glVertex3f(x +2 , y, z+2);

        glColor3f(0.3, 0.32, 0.15);
        //Generation de la face du dessus
        glVertex3f(x, y+ 4, z);
        glVertex3f(x+5, y+4, z);
        glVertex3f(x+5, y+4, z+5);
        glVertex3f(x, y+4, z+5);

        glVertex3f(x, y+ 2, z);
        glVertex3f(x+5, y+2, z);
        glVertex3f(x+5, y+2, z+5);
        glVertex3f(x, y+2, z+5);

        //Faces cotes
        glVertex3f(x, y+4, z);
        glVertex3f(x+5, y+4, z);
        glVertex3f(x+5, y+2, z);
        glVertex3f(x, y+2, z);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x, y+4, z);
        glVertex3f(x, y+4, z+5);
        glVertex3f(x, y+2, z+5);
        glVertex3f(x, y+2, z);

        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x, y+4, z+5);
        glVertex3f(x+5, y+4, z+5);
        glVertex3f(x+5, y+2, z+5);
        glVertex3f(x, y+2, z+5);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+5, y+4, z);
        glVertex3f(x+5, y+4, z+5);
        glVertex3f(x+5, y+2, z+5);
        glVertex3f(x+5, y+2, z);

        //Generation de la face du dessus
        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+0.5, y+6, z+0.5);
        glVertex3f(x+4.5, y+6, z+0.5);
        glVertex3f(x+4.5, y+6, z+4.5);
        glVertex3f(x+0.5, y+6, z+4.5);

        glVertex3f(x+0.5, y+4, z+0.5);
        glVertex3f(x+4.5, y+4, z+0.5);
        glVertex3f(x+4.5, y+4, z+4.5);
        glVertex3f(x+0.5, y+4, z+4.5);

        //Faces cotes
        glVertex3f(x+0.5, y+6, z+0.5);
        glVertex3f(x+4.5, y+6, z+0.5);
        glVertex3f(x+4.5, y+4, z+0.5);
        glVertex3f(x+0.5, y+4, z+0.5);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+0.5, y+6, z+0.5);
        glVertex3f(x+0.5, y+6, z+4.5);
        glVertex3f(x+0.5, y+4, z+4.5);
        glVertex3f(x+0.5, y+4, z+0.5);

        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+0.5, y+6, z+4.5);
        glVertex3f(x+4.5, y+6, z+4.5);
        glVertex3f(x+4.5, y+4, z+4.5);
        glVertex3f(x+0.5, y+4, z+4.5);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+4.5, y+6, z+0.5);
        glVertex3f(x+4.5, y+6, z+4.5);
        glVertex3f(x+4.5, y+4, z+4.5);
        glVertex3f(x+4.5, y+4, z+0.5);




                //Generation de la face du dessus
        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+1, y+8, z+1);
        glVertex3f(x+4, y+8, z+1);
        glVertex3f(x+4, y+8, z+4);
        glVertex3f(x+1, y+8, z+4);

        glVertex3f(x+1, y+6, z+1);
        glVertex3f(x+4, y+6, z+1);
        glVertex3f(x+4, y+6, z+4);
        glVertex3f(x+1, y+6, z+4);

        //Faces cotes
        glVertex3f(x+1, y+8, z+1);
        glVertex3f(x+4, y+8, z+1);
        glVertex3f(x+4, y+6, z+1);
        glVertex3f(x+1, y+6, z+1);

         glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+1, y+8, z+1);
        glVertex3f(x+1, y+8, z+4);
        glVertex3f(x+1, y+6, z+4);
        glVertex3f(x+1, y+6, z+1);

        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+1, y+8, z+4);
        glVertex3f(x+4, y+8, z+4);
        glVertex3f(x+4, y+6, z+4);
        glVertex3f(x+1, y+6, z+4);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+4, y+8, z+1);
        glVertex3f(x+4, y+8, z+4);
        glVertex3f(x+4, y+6, z+4);
        glVertex3f(x+4, y+6, z+1);
        

        //Generation de la face du dessus
        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+1.5, y+10, z+1.5);
        glVertex3f(x+3.5, y+10, z+1.5);
        glVertex3f(x+3.5, y+10, z+3.5);
        glVertex3f(x+1.5, y+10, z+3.5);

        glVertex3f(x+1.5, y+8, z+1.5);
        glVertex3f(x+3.5, y+8, z+1.5);
        glVertex3f(x+3.5, y+8, z+3.5);
        glVertex3f(x+1.5, y+8, z+3.5);

        //Faces cotes
        glVertex3f(x+1.5, y+10, z+1.5);
        glVertex3f(x+3.5, y+10, z+1.5);
        glVertex3f(x+3.5, y+8, z+1.5);
        glVertex3f(x+1.5, y+8, z+1.5);

         glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+1.5, y+10, z+1.5);
        glVertex3f(x+1.5, y+10, z+3.5);
        glVertex3f(x+1.5, y+8, z+3.5);
        glVertex3f(x+1.5, y+8, z+1.5);

        glColor3f(0.3, 0.32, 0.15);
        glVertex3f(x+1.5, y+10, z+3.5);
        glVertex3f(x+3.5, y+10, z+3.5);
        glVertex3f(x+3.5, y+8, z+3.5);
        glVertex3f(x+1.5, y+8, z+3.5);

        glColor3f(0.25, 0.27, 0.15);
        glVertex3f(x+3.5, y+10, z+1.5);
        glVertex3f(x+3.5, y+10, z+3.5);
        glVertex3f(x+3.5, y+8, z+3.5);
        glVertex3f(x+3.5, y+8, z+1.5);



    glEnd();
}
