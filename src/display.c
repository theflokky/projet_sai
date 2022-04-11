#include "display.h"

//VARIABLES
extern float camera_x;
extern float camera_y;
extern float camera_z;
extern float pt_regarde[];

//FONCTIONS
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

    glBegin(GL_QUADS);
        //Generation d'un sol de test
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-100, 0, -100);
        glVertex3f(-100, 0, 100);
        glVertex3f(100, 0, 100);
        glVertex3f(100, 0, -100);
    glEnd();

    building1(0, 0, 30);
    building1(15, 15, 60);
    building1(60, 60, 40);

    glutSwapBuffers();
}