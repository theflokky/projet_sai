#include "display.h"

//VARIABLES
extern float camera_x;
extern float camera_y;
extern float camera_z;
extern float pt_regarde[];
extern int affiche_hitbox;

extern ile tab_ile[];
extern int nb_iles_generes;

extern arbre_octal A;

//FONCTIONS
//Affichage building

//Fonction qui affiche une ile complete PROVISOIRE
void affichage_ile(int num_ile){
    float heigth =100;

    int i;
    float x = tab_ile[num_ile].objets[0].x;
    float y = tab_ile[num_ile].objets[0].y;
    float z =tab_ile[num_ile].objets[0].z;
    float longueur =tab_ile[num_ile].objets[0].longueur;
    float largeur =tab_ile[num_ile].objets[0].largeur;
    float hauteur =tab_ile[num_ile].objets[0].hauteur;

        if(affiche_hitbox){
        glBegin(GL_LINE_STRIP);
            glColor3f(0, 0, 1);
            glVertex3f(x+1, y, z+1);
            glVertex3f(x+1, y + heigth, z+1);

            glVertex3f(x+largeur-1, y + heigth, z+1);
            glVertex3f(x+largeur-1, y, z+1);
            glVertex3f(x+largeur-1, y + heigth, z+1);

            glVertex3f(x+largeur-1, y + heigth, z+longueur-1);
            glVertex3f(x+largeur-1, y, z+longueur-1);
            glVertex3f(x+largeur-1, y + heigth, z+longueur-1);

            glVertex3f(x+1, y + heigth, z+longueur-1);
            glVertex3f(x+1, y, z+longueur-1);
            glVertex3f(x+1, y + heigth, z+longueur-1);

            glVertex3f(x+1, y + heigth, z+1);
            

        glEnd();    
    }

    //printf("ILE AFFICHAGE X: %f, %f\n", x, longueur);
    //printf("ILE AFFICHAGE Z: %f, %f\n", z, largeur);
    //printf("ILE AFFICHAGE Y: %f, %f\n", y, hauteur);

    glBegin(GL_QUADS);
        //Generation d'un sol de test
        glColor3f(0.3137, 0.349, 0.3333);
        glVertex3f(x , y, z);
        glVertex3f(x+longueur, y, z);
        glVertex3f(x+longueur, y, z+largeur);
        glVertex3f(x, y, z+largeur);

        glColor3f(0.26, 0.08, 0);
        glVertex3f(x , y-10, z);
        glVertex3f(x+longueur, y-10, z);
        glVertex3f(x+longueur, y-10, z+largeur);
        glVertex3f(x, y-10, z+largeur);

        glColor3f(0.30, 0.12, 0);
        glVertex3f(x , y, z);
        glVertex3f(x , y-10, z);
        glVertex3f(x + longueur , y-10, z);
        glVertex3f(x + longueur, y, z);

        glColor3f(0.3451, 0.1608, 0);
        glVertex3f(x , y, z);
        glVertex3f(x , y-10, z);
        glVertex3f(x  , y-10, z + largeur);
        glVertex3f(x , y, z +largeur);

        glColor3f(0.30, 0.12, 0);
        glVertex3f(x +longueur, y, z);
        glVertex3f(x +longueur, y-10, z);
        glVertex3f(x + longueur , y-10, z+largeur);
        glVertex3f(x + longueur, y, z+largeur);

        glColor3f(0.3451, 0.1608, 0);
        glVertex3f(x , y, z+largeur);
        glVertex3f(x , y-10, z+largeur);
        glVertex3f(x + longueur , y-10, z+largeur);
        glVertex3f(x + longueur, y, z+largeur);
    glEnd();

    objet_a_trouver(tab_ile[num_ile].objets[2].x, tab_ile[num_ile].objets[2].y, tab_ile[num_ile].objets[2].z);
    teleporteur(tab_ile[num_ile].objets[1].x, tab_ile[num_ile].objets[1].y, tab_ile[num_ile].objets[1].z);

    for(i=3; i < tab_ile[num_ile].nb_objets -1 ; i++){
        float x = tab_ile[num_ile].objets[i].x;
        float y = tab_ile[num_ile].objets[i].y;
        float z =tab_ile[num_ile].objets[i].z;
        //fprintf(stdout, "BATIMENT_AFFICHAGE : %f, %f\n", x, z);
        if(tab_ile[num_ile].objets[i].type == 5){
            arbre(x, y, z, 10);
        }
        else{
            building1(x, y, z, 50);
        }
    }


}

//Fonction d'affichage de OpenGL
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 700);
    //glFrustum(0, 0,  0 , 0, 1, 400);
        gluLookAt(camera_x, camera_y, camera_z,
             camera_x + pt_regarde[0], camera_y + pt_regarde[1], camera_z + pt_regarde[2],
              0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /*gluLookAt(camera_x, camera_y, camera_z,
             camera_x + pt_regarde[0], camera_y + pt_regarde[1], camera_z + pt_regarde[2],
              0, 1, 0);*/

    //affiche_arbre_octal(A);

    for(int i = 0; i< NB_ILES_MAX; i++){
        affichage_ile(i);
    }
    camera();

    glutSwapBuffers();
}