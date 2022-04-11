#include "display.h"

//VARIABLES
extern float camera_x;
extern float camera_y;
extern float camera_z;
extern float pt_regarde[];

extern ile tab_ile[];
extern int nb_iles_generes;

//FONCTIONS


//Fonction qui affiche une ile complete PROVISOIRE
void affichage_ile(int num_ile){
    float x = tab_ile[num_ile].objets[0].x;
    float y = tab_ile[num_ile].objets[0].y;
    float z =tab_ile[num_ile].objets[0].z;
    float longueur =tab_ile[num_ile].objets[0].longueur;
    float largeur =tab_ile[num_ile].objets[0].largeur;
    float hauteur =tab_ile[num_ile].objets[0].hauteur;

    glBegin(GL_QUADS);
        //Generation d'un sol de test
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(x , y, z);
        glVertex3f(x+longueur, y, z);
        glVertex3f(x+longueur, y, z+largeur);
        glVertex3f(x, y, z+largeur);
    glEnd();
}

//Fonction d'affichage de OpenGL
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camera_x, camera_y, camera_z,
             camera_x + pt_regarde[0], camera_y + pt_regarde[1], camera_z + pt_regarde[2],
              0, 1, 0);

    camera();

    affichage_ile(0);
    affichage_ile(1);

    glutSwapBuffers();
}