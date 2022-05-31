#include "mouse.h"

extern float angle_horizontal;
extern float angle_vertical;

//Fonction qui gere un timer
void timer(int x){
    glutPostRedisplay();
    //on remet le pointeur au milieu de l'ecran
    glutWarpPointer(WIDTH/2, HEIGTH/2);
    glutTimerFunc(1000/60, timer, 0);
}

//Fonction qui gere les mouvements de souris
void passive_motion(int x, int y){
    float dx = WIDTH/2-x;
    float dy = HEIGTH/2-y;

    angle_horizontal += (float) dy / 100.0;
    angle_vertical += (float) dx / 100.0;
}