//Fonctions a implementer pour OpenGL

//LIBRAIRIES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"

//CONSTANTES
#define HEIGTH 800
#define WIDTH 800
#define TO_RADIAN 3.14/180.0



//FONCTIONS
void display();
void animate();
void keyboard(unsigned char key, int x, int y);
void keyboard_release(unsigned char key, int x, int y);
void timer(int x);
void passive_motion(int x, int y);
void camera();