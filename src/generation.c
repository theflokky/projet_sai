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

//Fonction qui genere renvoie un immeuble de position et hauteur aleatoire
objet generer_arbre(int num_ile){
    objet immeuble;

    immeuble.type = 5;
    immeuble.x = tab_ile[num_ile].objets[0].x + rand()%90;
    immeuble.y = tab_ile[num_ile].objets[0].y;
    immeuble.z = tab_ile[num_ile].objets[0].z + rand()%90;
    immeuble.hauteur = 10;
    immeuble.largeur = 5;
    immeuble.longueur = 5; 

    
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

    //fprintf(stdout, "POSITION OBJET : %f, %f\n", o.x, o.z);
    return o;
}

//Fonction qui verifie si il y a collision du batiment courant avec les autres batiments de l'ile renvoie true pas co
int conflit_generation_ville(objet o, int num_ile){
    int i;
    float x = o.x;
    float y =o.y;
    float z = o.z;

    if((x <= (tab_ile[num_ile].objets[0].x + 6)) && (z <= (tab_ile[num_ile].objets[0].z + 6))){
        return 0;
    }
    //fprintf(stderr, "POSITION TESTE %f %f\n", x, z);

    for(i=1; i < tab_ile[num_ile].nb_objets; i++){
        float x1 = tab_ile[num_ile].objets[i].x;
        float y1 = tab_ile[num_ile].objets[i].y;
        float z1 = tab_ile[num_ile].objets[i].z;
        float largeur = tab_ile[num_ile].objets[i].largeur +5;
        float longueur = tab_ile[num_ile].objets[i].longueur +5;
        float hauteur = tab_ile[num_ile].objets[i].hauteur;

        if(x >= x1 && y >= y1 && z >= z1 && x <= x1 + largeur && y <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x +largeur >= x1 && y + hauteur >= y1 && z + longueur >= z1 && x + largeur <= x1 + largeur && y + hauteur <= y1 + hauteur && z + longueur <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y >= y1 && z >= z1 && x + largeur <= x1 + largeur && y <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y + hauteur>= y1 && z >= z1 && x + largeur <= x1 + largeur && y + hauteur <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y >= y1 && z + longueur >= z1 && x <= x1 + largeur && y <= y1 + hauteur && z + longueur<= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y + hauteur>= y1 && z + longueur >= z1 && x <= x1 + largeur && y + hauteur<= y1 + hauteur && z + longueur<= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y + hauteur>= y1 && z >= z1 && x <= x1 + largeur && y + hauteur<= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y >= y1 && z + longueur>= z1 && x + largeur <= x1 + largeur && y <= y1 + hauteur && z + longueur <= z1 + longueur){
            return 0;
        }
    }
    return 1;
}

//Fonction qui verifie si il y a collision du batiment courant avec les autres batiments de l'ile renvoie true pas co
int conflit_generation_ile(int x, int y, int z){
    int i;

    if(x >= LARGEUR_MONDE - 100 || y >= HAUTEUR_MONDE - 50 || z >= LONGUEUR_MONDE -100){
        return 0;
    }

    for(i=0; i<NB_ILES_MAX; i++){
        float x1 = tab_ile[i].objets[0].x;
        float y1 = tab_ile[i].objets[0].y;
        float z1 = tab_ile[i].objets[0].z;
        float largeur = tab_ile[i].objets[0].largeur + 5;
        float longueur = tab_ile[i].objets[0].longueur +5 ;
        float hauteur = tab_ile[i].objets[0].hauteur + 15;

        //ANGLE 1
        if(x >= x1 && y >= y1 && z >= z1 && x <= x1 + largeur && y <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x +largeur >= x1 && y + hauteur >= y1 && z + longueur >= z1 && x + largeur <= x1 + largeur && y + hauteur <= y1 + hauteur && z + longueur <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y >= y1 && z >= z1 && x + largeur <= x1 + largeur && y <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y + hauteur>= y1 && z >= z1 && x + largeur <= x1 + largeur && y + hauteur <= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y >= y1 && z + longueur >= z1 && x <= x1 + largeur && y <= y1 + hauteur && z + longueur<= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y + hauteur>= y1 && z + longueur >= z1 && x <= x1 + largeur && y + hauteur<= y1 + hauteur && z + longueur<= z1 + longueur){
            return 0;
        }
        if(x >= x1 && y + hauteur>= y1 && z >= z1 && x <= x1 + largeur && y + hauteur<= y1 + hauteur && z <= z1 + longueur){
            return 0;
        }
        if(x + largeur >= x1 && y >= y1 && z + longueur>= z1 && x + largeur <= x1 + largeur && y <= y1 + hauteur && z + longueur <= z1 + longueur){
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

    tab_ile[num_ile].objets[2] = immeuble_courant;
    tab_ile[num_ile].nb_objets++;
    
    immeuble_courant = generer_immeuble(num_ile);
    //Boucle for pour la generation des immeubles
    for(i = 3; i < nb_immeubles ; i++){
        //Verif Generation Collision
        while(conflit_generation_ville(immeuble_courant, num_ile) != 1){
            if(i%2 == 0){
                immeuble_courant = generer_immeuble(num_ile);
                //printf("IMMEUBLE AVANT TAB: %f, %f\n", immeuble_courant.x, immeuble_courant.z);
            }
            else{
                immeuble_courant = generer_arbre(num_ile);
            }
        }
        
        //printf("IMMEUBLE Généré: %f, %f\n", immeuble_courant.x, immeuble_courant.z);
        tab_ile[num_ile].objets[i] = immeuble_courant;
        tab_ile[num_ile].nb_objets++;
        //printf("IMMEUBLE APRES TAB: %f, %f\n" ,tab_ile[num_ile].objets[i].x, tab_ile[num_ile].objets[i].z);
    }
    immeuble_courant = generer_objet_a_trouver(num_ile);
    while(conflit_generation_ville(immeuble_courant, num_ile) != 1){
        immeuble_courant = generer_objet_a_trouver(num_ile);
    }
    tab_ile[num_ile].objets[2] = immeuble_courant;
    tab_ile[num_ile].nb_objets++;
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
        while(conflit_generation_ile(x,y, z) != 1);

        generer_ile(x, y, z);
    }
}


//Fonction qui genere les building sur un ile
void generer_building(int num_ile, int nb_building){

}
