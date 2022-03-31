#include "camera.h"

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