#include "camera.h"

//VARIABLES GLOBALE
extern ile tab_ile[];
//Coordonnées de la camera
float camera_x = 2;
float camera_y = 2;
float camera_z = 2;

int teleporteur_ouvert = 0;
int victoire = 0;


//Vercteur directo
float direction_x = 0;
float direction_y = 0;
float direction_z = 0;

int ile_courante =0;

//Vecteur qui represente la gauche du point regarde (orthogonal a pt_regarde)
float gauche_pt_regarde[3] = {-4, 0, 4};

//Vecteur du point regarde
float pt_regarde[3] = {4, 0, 4};

//Angles
float angle_horizontal = 0;
float angle_vertical = 0;

//Booleen qui represente les directions
int direction_bool[4] = {0, 0, 0, 0};

int colision_ile(int x, int z){
    float longueur = tab_ile[ile_courante].objets[0].x + LONGUEUR_ILE;
    float largeur = tab_ile[ile_courante].objets[0].z + LARGEUR_ILE;
    if(x -1< tab_ile[ile_courante].objets[0].x){
        return 1;
    }
    if(z -1< tab_ile[ile_courante].objets[0].z){
            return 1;
    }
    if(x +1> longueur){
        return 1;
    }
    if(z +1> largeur){
        return 1;
    }



    return 0;
}

int colision_objet(int x, int z){
    float bat_x;
    float bat_z;

    for(int i = 3; i<tab_ile[ile_courante].nb_objets -1; i++){
        bat_x = tab_ile[ile_courante].objets[i].x;
        bat_z = tab_ile[ile_courante].objets[i].z;

        //fprintf(stdout, "BAT_COLISION %f, %f\n", bat_x, bat_z);
        if(tab_ile[ile_courante].objets[i].type == 5){
            if(x +2 > bat_x && z +2 > bat_z && x < bat_x + 7 && z < bat_z +7){
                return 1;
            }
        }
        else{
            if(x +2 > bat_x && z +2 > bat_z && x < bat_x + 12 && z < bat_z +12){
                return 1;
            }
        }
    }
    return 0;
}

int colision_teleporteur(int x, int z){
    if(x +2 > tab_ile[ile_courante].objets[1].x
         && z +2 > tab_ile[ile_courante].objets[1].z
         && x < tab_ile[ile_courante].objets[1].x + 12 
         && z < tab_ile[ile_courante].objets[1].z +12){
        
        return 1;
    }
    return 0;
}

int colision_cible(int x, int z){
    if(x +2 > tab_ile[ile_courante].objets[2].x
         && z  +2> tab_ile[ile_courante].objets[2].z
         && x < tab_ile[ile_courante].objets[2].x + 2 
         && z < tab_ile[ile_courante].objets[2].z + 2){
        //fprintf(stdout, "\nCible Trouvé\n");
        return 1;
    }
    return 0;
}

void teleportation(){
    if(ile_courante == NB_ILES_MAX -1){
        fprintf(stdout, "\n VICTOIRE GROS BG\n");
        teleporteur_ouvert = 0;
        victoire =1;
    }
    else{
        //fprintf(stderr, "Ile Courante : %d", ile_courante);
        ile_courante++;
        camera_x = tab_ile[ile_courante].objets[0].x + 4;
        camera_y = tab_ile[ile_courante].objets[0].y +2;
        camera_z = tab_ile[ile_courante].objets[0].z +4;
    }

}

//Fonction pour la camera premiere personne
void camera(){
    //Gestion des mouvemetns de clavier
    //fprintf(stdout, "POSITION CAMERA : %f, %f, %f\n", camera_x, camera_y, camera_z);
    if(direction_bool[0]){
        if(colision_ile(camera_x + pt_regarde[0]/10, camera_z + pt_regarde[2]/10) == 0){
            if(colision_objet(camera_x + pt_regarde[0]/10, camera_z + pt_regarde[2]/10) == 0){
                camera_x += pt_regarde[0]/10;
                camera_z += pt_regarde[2]/10;
                //fprintf(stdout, "POSITION CAMERA : %f, %f, %f\n", camera_x, camera_y, camera_z);
            }
        }
        if(colision_cible(camera_x + pt_regarde[0]/10, camera_z + pt_regarde[2]/10) == 1){
            teleporteur_ouvert = 1;
        }
        if(colision_teleporteur(camera_x + pt_regarde[0]/10, camera_z + pt_regarde[2]/10) == 1){
            //exit(0);
            if(teleporteur_ouvert){
                teleportation();
                teleporteur_ouvert = 0;
            }
        }
    }
    if(direction_bool[1]){
        if(colision_ile(camera_x - pt_regarde[0]/10, camera_z - pt_regarde[2]/10) == 0){
            if(colision_objet(camera_x - pt_regarde[0]/10, camera_z - pt_regarde[2]/10) == 0){
                camera_x -= pt_regarde[0]/10;
                camera_z -= pt_regarde[2]/10;
                //fprintf(stdout, "POSITION CAMERA : %f, %f, %f\n", camera_x, camera_y, camera_z);
            }
        }
        if(colision_cible(camera_x - pt_regarde[0]/10, camera_z - pt_regarde[2]/10) == 1){
            teleporteur_ouvert = 1;
        }
        if(colision_teleporteur(camera_x - pt_regarde[0]/10, camera_z - pt_regarde[2]/10) == 1){
            //exit(0);
            if(teleporteur_ouvert){
                teleportation();
                teleporteur_ouvert = 0;
            }
        }
    }
    if(direction_bool[3]){
        if(colision_ile(camera_x - gauche_pt_regarde[0]/10, camera_z - gauche_pt_regarde[2]/10) == 0){
            if(colision_objet(camera_x - gauche_pt_regarde[0]/10, camera_z - gauche_pt_regarde[2]/10) == 0){
                camera_x -= gauche_pt_regarde[0]/10;
                camera_z -= gauche_pt_regarde[2]/10;
                //fprintf(stdout, "POSITION CAMERA : %f, %f, %f\n", camera_x, camera_y, camera_z);
            }
        }
        if(colision_cible(camera_x - gauche_pt_regarde[0]/10, camera_z - gauche_pt_regarde[2]/10) == 1){
            teleporteur_ouvert = 1;
        }
        if(colision_teleporteur(camera_x - gauche_pt_regarde[0]/10, camera_z - gauche_pt_regarde[2]/10) == 1){
            //exit(0);
            if(teleporteur_ouvert){
                teleportation();
                teleporteur_ouvert = 0;
            }
        }
        
    }
    if(direction_bool[2]){
        if(colision_ile(camera_x + gauche_pt_regarde[0]/10, camera_z + gauche_pt_regarde[2]/10) == 0){
            if(colision_objet(camera_x + gauche_pt_regarde[0]/10, camera_z + gauche_pt_regarde[2]/10) == 0){
                camera_x += gauche_pt_regarde[0]/10;
                camera_z += gauche_pt_regarde[2]/10;
                //fprintf(stdout, "POSITION CAMERA : %f, %f, %f\n", camera_x, camera_y, camera_z);
            }
        }
        if(colision_cible(camera_x + gauche_pt_regarde[0]/10, camera_z + gauche_pt_regarde[2]/10) == 1){
            teleporteur_ouvert =1;
        }
        if(colision_teleporteur(camera_x + gauche_pt_regarde[0]/10, camera_z + gauche_pt_regarde[2]/10) == 1){
            //exit(0);
            if(teleporteur_ouvert){
                teleportation();
                teleporteur_ouvert = 0;
            }
        }
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