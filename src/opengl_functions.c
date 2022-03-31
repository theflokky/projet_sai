//Fonctions a implementer pour OpenGL

//INCLUSION
#include "opengl_functions.h"

//VARIABLES GLOBALE
//Coordonnées de la camera
float camera_x = 0;
float camera_y = 2;
float camera_z = 0;

//Vercteur directo
float direction_x = 0;
float direction_y = 0;
float direction_z = 0;

//Vecteur qui represente la gauche du point regarde (orthogonal a pt_regarde)
float gauche_pt_regarde[3] = {-4, 0, 4};

//Vecteur du point regarde
float pt_regarde[3] = {4, 0, 4};

//Angles
float angle_horizontal = 0;
float angle_vertical = 0;

//Booleen qui represente les directions
int direction_bool[4] = {0, 0, 0, 0};

//FONCTIONS
//Fonction d'affichage de OpenGL
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camera_x, camera_y, camera_z, camera_x + pt_regarde[0], camera_y + pt_regarde[1], camera_z + pt_regarde[2], 0, 1, 0);

    camera();

    glBegin(GL_QUADS);
        //Generation d'un sol de test
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(-10, 0, -10);
        glVertex3f(-10, 0, 10);
        glVertex3f(10, 0, 10);
        glVertex3f(10, 0, -10);
    glEnd();
    glutSwapBuffers();
}

//Fonction pour la camera premiere personne
void camera(){
    //Gestion des mouvemetns de clavier
    if(direction_bool[0]){
        camera_x += pt_regarde[0]/20;
        camera_z += pt_regarde[2]/20;
    }
    if(direction_bool[1]){
        camera_x -= pt_regarde[0]/20;
        camera_z -= pt_regarde[2]/20;
    }
    if(direction_bool[3]){
        camera_x -= gauche_pt_regarde[0]/20;
        camera_z -= gauche_pt_regarde[2]/20;
    }
    if(direction_bool[2]){
        camera_x += gauche_pt_regarde[0]/20;
        camera_z += gauche_pt_regarde[2]/20;
    }

    if(angle_horizontal >= 70){
        angle_horizontal = 70;
    }
    if(angle_horizontal <= -60){
        angle_horizontal = -60;
    }

    glRotatef(-angle_vertical, 0, 1, 0);
    glRotatef(-angle_horizontal, 1, 0, 0);
    glTranslatef(-camera_x, 0, -camera_z);
    
    //On redefinit le vecteur pt_regarde
    pt_regarde[1] = angle_horizontal;
    pt_regarde[0] = cos(angle_vertical) + sin(angle_vertical);
    pt_regarde[2] = cos(angle_vertical) -sin(angle_vertical);

    //On redefniti la gauche du vecteur point_regarde
    gauche_pt_regarde[0]= -pt_regarde[2];
    gauche_pt_regarde[1] = angle_horizontal;
    gauche_pt_regarde[2]= pt_regarde[0];


}


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