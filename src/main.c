//INCLUSIONS
#include "display.h"
#include "mouse.h"
#include "keyboard.h"
#include "camera.h"

//MAIN DU PROJET DE SAI
int main(int argc, char const *argv[]){
    //Initialisation de Glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);

    //Creation de la fenetre du jeu
    glutCreateWindow("Projet SAI");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutSetCursor(GLUT_CURSOR_NONE);
    

    //Postionne le pointeur de souris au milieu de la fenetre
    glutWarpPointer(800/2, 800/2);
    glClearColor(0.4667, 0.7098, 0.9961, 1);

    //Definition des fonctions pour OpenGL
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_release);
    glutTimerFunc(0,timer,0);
    glutPassiveMotionFunc(passive_motion);

    glutMainLoop();


    return 0;
}