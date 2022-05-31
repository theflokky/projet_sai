#include "arbres_octaux.h"

//Fonction qui initialise un arbre octal
arbre_octal init_arbre_octal(){
    arbre_octal A = (arbre_octal) malloc(sizeof(struct ArbreOctal));

    A->profondeur = 0;
    A->nombre_objets = 0;
    A->angle_hg[0] = 0;
    A->angle_hg[1] = 0;
    A->angle_hg[2] = 0;
    A->angle_bd[0] = 0;
    A->angle_bd[1] = 0;
    A->angle_bd[2] = 0;
    A->fils1 = NULL;
    A->fils2 = NULL;
    A->fils3 = NULL;
    A->fils4 = NULL;
    A->fils5 = NULL;
    A->fils6 = NULL;
    A->fils7 = NULL;
    A->fils8 = NULL;
    
    return A;
}



//Fonction qui ajoute un fils B a la postion i a un arbre octal 
void ajouter_arbre_octal(arbre_octal A, int i, arbre_octal B){
    switch(i){
        case 1 :
            A->fils1 = B;
            break;
        case 2 :
            A->fils2 = B;
            break;
        case 3 :
            A->fils3 = B;
            break;
        case 4 :
            A->fils4 = B;
            break;
        case 5 :
            A->fils5 = B;
            break;
        case 6 :
            A->fils6 = B;
            break;
        case 7 :
            A->fils7 = B;
            break;
        case 8 :
            A->fils8 = B;
            break;
        default :
            fprintf(stdout, "ERREUR :  Indice Faux Arbre\n");
            break;
    }
}

arbre_octal genere_arbre_octal_bis(int profondeur_arbre, float x1, float y1, float z1, float x2, float y2, float z2){
    if(profondeur_arbre == 0){
        return NULL;
    }
    arbre_octal A = init_arbre_octal();

    A->angle_hg[0] = x1;
    A->angle_hg[1] = y1;
    A->angle_hg[2] = z1;
    //fprintf(stderr, "Profondeur %d : HG = %f, %f, %f\n  ", profondeur_arbre, x1, y1, z1);

    A->angle_bd[0] = x2;
    A->angle_bd[1] = y2;
    A->angle_bd[2] = z2;

    //fprintf(stderr, "Profondeur %d : BD = %f, %f, %f\n  ", profondeur_arbre, x2, y2, z2);

    //fprintf(stderr, "%f\n" , y1/2);
    A->fils1 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1, z1, x2/2, y2/2, z2/2);

    A->fils2 = genere_arbre_octal_bis(profondeur_arbre - 1, x1/2, y1, z1, x2, y2/2, z2/2);

    A->fils3 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1, z1/2, x2/2, y2/2, z2);

    A->fils4 = genere_arbre_octal_bis(profondeur_arbre - 1, x1/2, y1, z1/2, x2, y2/2, z2);


    A->fils5 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1/2, z1, x2/2, y2, z2/2);

    A->fils6 = genere_arbre_octal_bis(profondeur_arbre - 1, x1/2, y1/2, z1, x2, y2, z2/2);

    A->fils7 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1/2, z1/2, x2/2, y2, z2);

    A->fils8 = genere_arbre_octal_bis(profondeur_arbre - 1, x1/2, y1/2, z1/2, x2, y2, z2);

    return A;
}

//Fonction qui genere l'arbre octal au debut de la partie
arbre_octal genere_arbre_octal(int profondeur_arbre, float x1, float y1, float z1, float x2, float y2, float z2){
    if(profondeur_arbre == 0){
        return NULL;
    }
    arbre_octal A = init_arbre_octal();

    A->angle_hg[0] = x1;
    A->angle_hg[1] = y1;
    A->angle_hg[2] = z1;
    //fprintf(stderr, "Profondeur %d : HG = %f, %f, %f\n  ", profondeur_arbre, x1, y1, z1);

    A->angle_bd[0] = x2;
    A->angle_bd[1] = y2;
    A->angle_bd[2] = z2;

    //fprintf(stderr, "Profondeur %d : BD = %f, %f, %f\n  ", profondeur_arbre, x2, y2, z2);
    //fprintf(stderr, "%f\n" , y1/2);
    A->fils1 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1, z1, x2/2, y1/2, z2/2);

    A->fils2 = genere_arbre_octal_bis(profondeur_arbre - 1, x2/2, y1, z1, x2, y1/2, z2/2);

    A->fils3 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1, z2/2, x2/2, y1/2, z2);

    A->fils4 = genere_arbre_octal_bis(profondeur_arbre - 1, x2/2, y1, z2/2, x2, y1/2, z2);


    A->fils5 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1/2, z1, x2/2, y2, z2/2);

    A->fils6 = genere_arbre_octal_bis(profondeur_arbre - 1, x2/2, y1/2, z1, x2, y2, z2/2);

    A->fils7 = genere_arbre_octal_bis(profondeur_arbre - 1, x1, y1/2, z2/2, x2/2, y2, z2);

    A->fils8 = genere_arbre_octal_bis(profondeur_arbre - 1, x2/2, y1/2, z2/2, x2, y2, z2);



    //fprintf(stderr, "Arbre Octal Généré\n");

    return A;
}

void dessine_cube(float x1, float y1, float z1, float x2, float y2, float z2){
    glBegin(GL_LINE_LOOP);
        glColor3f(1,0,0);

        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y2, z1);
        glVertex3f(x1, y1, z1);

        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x1, y1, z2);

        glVertex3f(x2, y1, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y1, z2);

        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x2, y1, z1);

        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y2, z1);

        glVertex3f(x1, y2, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y2, z1);
        glVertex3f(x1, y2, z1);





    glEnd();
}

void affiche_arbre_octal(arbre_octal A){
    if(A != NULL){
        dessine_cube(A->angle_hg[0] , A->angle_hg[1], A->angle_hg[2], 
                    A->angle_bd[0] , A->angle_bd[1], A->angle_bd[2]);
        //fprintf(stderr, "Arbre Octal Affiche\n");

        affiche_arbre_octal(A->fils1);
        affiche_arbre_octal(A->fils2);
        affiche_arbre_octal(A->fils3);
        affiche_arbre_octal(A->fils4);
        affiche_arbre_octal(A->fils5);
        affiche_arbre_octal(A->fils6);
        affiche_arbre_octal(A->fils7);
        affiche_arbre_octal(A->fils8);
    }

}