//INCLUDE
#include "generation.h"

//Tableau contenant toutes les iles
ile tab_ile[NB_ILES_MAX];
int nb_iles_generes = 0;

//FONCTIONS
//Fonction qui genere renvoie un immeuble de position et hauteur aleatoire
objet generer_immeuble(int num_ile){
    objet immeuble;

    immeuble.type = 2;
    immeuble.x = tab_ile[num_ile].objets[0].x + rand()%90;
    immeuble.y = tab_ile[num_ile].objets[0].y;
    immeuble.z = tab_ile[num_ile].objets[0].z + rand()%90;
    immeuble.hauteur = 50;
    immeuble.largeur = 10;
    immeuble.longueur = 10; 

    
    return immeuble;
}

objet generer_teleporteur(int num_ile){
    objet teleporteur;

    teleporteur.type = 3;
    teleporteur.x = tab_ile[num_ile].objets[0].x + tab_ile[num_ile].objets[0].largeur /2;
    teleporteur.y = tab_ile[num_ile].objets[0].y;
    teleporteur.z = tab_ile[num_ile].objets[0].z + tab_ile[num_ile].objets[0].longueur /2;
    teleporteur.hauteur = 10;
    teleporteur.largeur = 10;
    teleporteur.longueur = 10; 
    
    return teleporteur;
}

objet generer_objet_a_trouver(int num_ile){
    objet o;

    o.type = 4;
    o.x = tab_ile[num_ile].objets[0].x +rand()%80;
    o.y = tab_ile[num_ile].objets[0].y;
    o.z = tab_ile[num_ile].objets[0].z + rand()%80;
    o.hauteur = 1;
    o.largeur = 1;
    o.longueur = 1; 
    return o;
}

//Fonction qui verifie si il y a collision du batiment courant avec les autres batiments de l'ile renvoie true pas co
int conflit_generation_ville(objet o, int num_ile){
    int i;

    for(i=1; i<tab_ile[num_ile].nb_objets; i++)
        //Angle 1
        //verification du x
        if((o.x >= tab_ile[num_ile].objets[i].x && 
            o.x <= tab_ile[num_ile].objets[i].x + tab_ile[num_ile].objets[i].longueur )
            || (o.x <= tab_ile[num_ile].objets[i].x + 5 && o.z <= tab_ile[num_ile].objets[i].z + 5)){
            //Verification du z
            if(o.z >= tab_ile[num_ile].objets[i].z && 
            o.z <= tab_ile[num_ile].objets[i].z + tab_ile[num_ile].objets[i].largeur){
                return 0;
            } 
        //Angle 2
        //verification du x
        if(o.x + o.longueur >= tab_ile[num_ile].objets[i].x && 
            o.x + o.longueur <= tab_ile[num_ile].objets[i].x + tab_ile[num_ile].objets[i].longueur){
            //Verification du z
            if(o.z >= tab_ile[num_ile].objets[i].z && 
            o.z <= tab_ile[num_ile].objets[i].z + tab_ile[num_ile].objets[i].largeur){
                return 0;
            }        
        }
        //Angle 3
        //verification du x
       if(o.x + o.longueur >= tab_ile[num_ile].objets[i].x && 
            o.x + o.longueur <= tab_ile[num_ile].objets[i].x + tab_ile[num_ile].objets[i].longueur){
            //Verification du z
            if(o.z +o.largeur>= tab_ile[num_ile].objets[i].z && 
            o.z + o.largeur<= tab_ile[num_ile].objets[i].z + tab_ile[num_ile].objets[i].largeur){
                return 0;
            }        
        }     
        //Angle 4
        //verification du x
        if(o.x >= tab_ile[num_ile].objets[i].x && 
            o.x  <= tab_ile[num_ile].objets[i].x + tab_ile[num_ile].objets[i].longueur){
            //Verification du z
            if(o.z +o.largeur>= tab_ile[num_ile].objets[i].z && 
            o.z + o.largeur<= tab_ile[num_ile].objets[i].z + tab_ile[num_ile].objets[i].largeur){
                return 0;
            }        
        }
    }
    return 1;
}

//Fonction qui verifie si il y a collision du batiment courant avec les autres batiments de l'ile renvoie true pas co
int conflit_generation_ile(int x, int z){
    int i;

    for(i=0; i<NB_ILES_MAX; i++){
        //ANGLE 1
        if(x >= tab_ile[i].objets[0].x && x <= tab_ile[i].objets[0].x + tab_ile[i].objets[0].largeur && z >= tab_ile[i].objets[0].z 
            && z <= tab_ile[i].objets[0].z + tab_ile[i].objets[0].longueur){
                return 0;
        }
        //ANGLE 2
        if(x + LARGEUR_ILE >= tab_ile[i].objets[0].x && x + LARGEUR_ILE <= tab_ile[i].objets[0].x + tab_ile[i].objets[0].largeur &&
            z + LONGUEUR_ILE >= tab_ile[i].objets[0].z && z + LONGUEUR_ILE <= tab_ile[i].objets[0].z + tab_ile[i].objets[0].longueur){
                return 0;
        }
        //ANGLE 3
        if(x >= tab_ile[i].objets[0].x && x  <= tab_ile[i].objets[0].x + tab_ile[i].objets[0].largeur && 
            z + LONGUEUR_ILE >= tab_ile[i].objets[0].z && z + LONGUEUR_ILE <= tab_ile[i].objets[0].z + tab_ile[i].objets[0].longueur){
                return 0;
        }
        //ANGLE 4
        if(x + LARGEUR_ILE >= tab_ile[i].objets[0].x && x + LARGEUR_ILE <= tab_ile[i].objets[0].x + tab_ile[i].objets[0].largeur 
        && z  >= tab_ile[i].objets[0].z && z  <= tab_ile[i].objets[0].z + tab_ile[i].objets[0].longueur){
                return 0;
        }
    }
    return 1;
}


//Fonction qui genere une ville sur l'ile
void generer_ville(int num_ile){
    //Variables
    int nb_immeubles;
    int i;
    objet immeuble_courant;

    //On tire aléatoirement le nombre de building (Bornes a confirmer) POUR LE MOMENT FIXE
    nb_immeubles = NB_IMMEUBLE;

    immeuble_courant = generer_teleporteur(num_ile);
    tab_ile[num_ile].objets[1] = immeuble_courant;
    tab_ile[num_ile].nb_objets++;

    immeuble_courant = generer_objet_a_trouver(num_ile);
    tab_ile[num_ile].objets[2] = immeuble_courant;
    tab_ile[num_ile].nb_objets++;
    

    //Boucle for pour la generation des immeubles
    for(i = 3; i < nb_immeubles; i++){
        //Verif Generation Collision
        
        while(conflit_generation_ville(immeuble_courant, num_ile) != 1){
            immeuble_courant = generer_immeuble(num_ile);
            //printf("IMMEUBLE AVANT TAB: %f, %f\n", immeuble_courant.x, immeuble_courant.z);
        }
        
        
        tab_ile[num_ile].objets[i] = immeuble_courant;
        tab_ile[num_ile].nb_objets++;
        //printf("IMMEUBLE APRES TAB: %f, %f\n" ,tab_ile[num_ile].objets[i].x, tab_ile[num_ile].objets[i].z);
    }
}

//Fonction qui genere une ile complete avec objets
void generer_ile(float x, float y, float z){
    //Variables
    objet objet_ile;
    ile i;

    //On paramètre l'objet ile
    objet_ile.type = 1;
    objet_ile.x = x;
    objet_ile.y = y;
    objet_ile.z = z;
    objet_ile.largeur = LARGEUR_ILE;
    objet_ile.longueur = LONGUEUR_ILE;
    objet_ile.hauteur = HAUTEUR_ILE;

    //On initialise le tableau ile
    i.nb_objets = 1;
    i.objets[0] = objet_ile;

    tab_ile[nb_iles_generes]=i;

    //On genere la ville dessus
    generer_ville(nb_iles_generes);

    nb_iles_generes++;    
}

void generer_monde(){
    //VARIABLES
    float x, y, z;
    int i;


    generer_ile(0,0 ,0);
    //Boucle de génération
    for(i = 1; i < NB_ILES_MAX; i++){
        //Verification Conflit
        do{
            //Tirage aléatoire des tailles et position de l'ile
            x =  rand()%LARGEUR_MONDE; 
            y =  rand()%HAUTEUR_MONDE;
            z =  rand()%LONGUEUR_MONDE;
        }
        while(conflit_generation_ile(x, z) != 1);

        generer_ile(x, y, z);
    }
    
}


//Fonction qui genere les building sur un ile
void generer_building(int num_ile, int nb_building){

}
