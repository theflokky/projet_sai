//INCLUDE
#include "generation.h"

//Tableau contenant toutes les iles
ile tab_ile[NB_ILES_MAX];
int nb_iles_generes = 0;

//FONCTIONS
//Fonction qui genere renvoie un immeuble de position et hauteur aleatoire
objet generer_immeuble(float position_y_ile){
    objet immeuble;

    immeuble.type = 2;
    immeuble.x = rand()%100 + 1;
    immeuble.y = position_y_ile;
    immeuble.z = rand()%100 + 1;
    immeuble.hauteur = 50;
    immeuble.largeur = 10;
    immeuble.longueur = 10;

    return immeuble;
}


//Fonction qui genere une ville sur l'ile
void generer_ville(int num_ile){
    //Variables
    int nb_immeubles;
    int i;
    objet immeuble_courant;

    //On tire aléatoirement le nombre de building (Bornes a confirmer) POUR LE MOMENT FIXE
    nb_immeubles = 5;

    //Boucle for pour la generation des immeubles
    for(i = 1; i < nb_immeubles; i++){
        //VERIFICATION DES COLLISION A FAIRE PLUS TARD
        immeuble_courant = generer_immeuble(tab_ile[num_ile].objets[0].y);
        tab_ile[num_ile].objets[i] = immeuble_courant;
        tab_ile[num_ile].nb_objets++;
    }
}

//Fonction qui genere une ile complete avec objets
void generer_ile(float x, float y, float z, float largeur, float longueur, float hauteur){
    //Variables
    objet objet_ile;
    ile i;

    //Verification de non conflit A FAIRE

    //On paramètre l'objet ile
    objet_ile.type = 1;
    objet_ile.x = x;
    objet_ile.y = y;
    objet_ile.z = z;
    objet_ile.largeur = largeur;
    objet_ile.longueur = longueur;
    objet_ile.hauteur = hauteur;

    //On initialise le tableau ile
    i.nb_objets = 1;
    i.objets[0] = objet_ile;

    tab_ile[nb_iles_generes]=i;

    //On genere la ville dessus
    generer_ville(nb_iles_generes);

    nb_iles_generes++;    
}


//Fonction qui genere les building sur un ile
void generer_building(int num_ile, int nb_building){

}
