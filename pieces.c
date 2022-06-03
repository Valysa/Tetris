#include "fonctions.h"

Piece placement(Piece piece){ //On attribue l'abscisse et l'ordonnée de chacune des 4 tuiles pour chaque pièce
    int abs = piece.tuile1.abs, ord = piece.tuile1.ord ;
    switch (piece.type){
        case 1 : // la barre
            switch (piece.rotation){
                case 0 : //cas 1.1
                    //puts("1.1");
                    piece.tuile1.ord = ord -1;
                    piece.tuile2.abs = abs +1 ;
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.abs = abs +2 ;
                    piece.tuile3.ord = ord -1;
                    piece.tuile4.abs = abs +3 ;
                    piece.tuile4.ord = ord -1; break ;
                case 1 : //cas 1.2
                    //puts("1.2");
                    piece.tuile1.ord = ord +2;
                    piece.tuile2.ord = ord +1 ;
                    piece.tuile3.ord = ord ;
                    piece.tuile4.ord = ord -1 ; break ;
            }break ;
        case 2 : // le cube
                    //puts("2");
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile4.abs = abs +1;break ;
        case 3 : //le T
            switch (piece.rotation){
                case 0 : // cas 3.1
                    //puts("3.1");
                    piece.tuile1.abs = abs +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile4.abs = abs +2; break ;
                case 1 : // cas 3.2
                    //puts("3.2");
                    piece.tuile2.ord = ord -1;
                    piece.tuile4.abs = abs +1;
                    piece.tuile3.ord = ord +1; break ;
                case 2 : //cas 3.3
                    //puts("3.3");
                    piece.tuile1.ord = ord -1;
                    piece.tuile1.abs = abs +1;
                    piece.tuile2.abs = abs +2;
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.ord = ord -1; break ;
                case 3 : //cas 3.4
                    //puts("3.4");
                    piece.tuile1.abs = abs +1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile2.ord = ord +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile4.abs = abs ; break ;
            } break ;
        case 4 : // le L
            switch (piece.rotation){
                case 0 : // cas 4.1
                    //puts("4.1");
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.ord = ord -1;
                    piece.tuile4.abs = abs +2; break ;
                case 1 : //cas 4.2
                    //puts("4.2");
                    piece.tuile1.ord = ord -1;
                    piece.tuile2.ord = ord -1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.abs = abs +1;
                    piece.tuile4.ord = ord +1; break ;
                case 2 : //cas 4.3
                    //puts("4.3");
                    piece.tuile2.abs = abs +1;
                    piece.tuile3.abs = abs +2;
                    piece.tuile4.ord = ord -1;
                    piece.tuile4.abs = abs +2; break ;
                case 3 : //cas 4.4
                    //puts("4.4");
                    piece.tuile1.ord = ord +1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile2.ord = ord +1;
                    piece.tuile4.ord = ord -1; break ;
            } break ;
        case 5 : // le J
            switch (piece.rotation){
                case 0 : // cas 5.1
                    //puts("5.1");
                    piece.tuile1.ord = ord -1;
                    piece.tuile2.ord = ord -1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile3.abs = abs +2;
                    piece.tuile4.abs = abs +2; break ;
                case 1 : //cas 5.2
                    //puts("5.2");
                    piece.tuile1.ord = ord +1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile2.ord = ord +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.ord = ord -1;
                    piece.tuile4.abs = abs +1; break ;
                case 2 : //cas 5.3
                    //puts("5.3");
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.abs = abs +2; break ;
                case 3 : //cas 5.4
                    //puts("5.4");
                    piece.tuile1.ord = ord +1;
                    piece.tuile3.ord = ord -1;
                    piece.tuile4.abs = abs +1;
                    piece.tuile4.ord = ord -1; break ;
            } break ;
        case 6 : // le z
            switch (piece.rotation){
                case 0 : //cas 6.1
                    //puts("6.1");
                    piece.tuile1.ord = ord -1;
                    piece.tuile2.ord = ord -1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.abs = abs +2;
                    piece.tuile4.ord = ord; break ;
                case 1 : //cas 6.2
                    //puts("6.2");
                    piece.tuile1.ord = ord +1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile4.abs = abs +1;
                    piece.tuile4.ord = ord -1; break ;
            } break ;
        case 7 : // le s
            switch (piece.rotation){
                case 0 : //cas 7.1
                    //puts("7.1");
                    piece.tuile1.abs = abs +1;
                    piece.tuile2.abs = abs +1;
                    piece.tuile2.ord = ord -1;
                    piece.tuile4.abs = abs +2;
                    piece.tuile4.ord = ord -1; break ;
                case 1 : //cas 7.2
                    //puts("7.2");
                    piece.tuile2.ord = ord -1;
                    piece.tuile3.abs = abs +1;
                    piece.tuile3.ord = ord +1;
                    piece.tuile4.abs = abs +1; break ;
            } break ;
    }
    return(piece);
}

// partie colisions 


int testColision(Piece piece, int tableau[LONGUEUR][LARGEUR]){ //On vérifie que les pièces n'entrent pas en colision entre elles ou bien sortent du plateau
    if(tableau[piece.tuile1.ord+1][piece.tuile1.abs] != 0 || piece.tuile1.ord+1 == LONGUEUR){
        puts("ça pete1");
        return(1) ;
    }
    if(tableau[piece.tuile2.ord+1][piece.tuile2.abs] != 0 || piece.tuile2.ord+1 == LONGUEUR){
        puts("ça pete2");
        return(1) ;
    }
    if(tableau[piece.tuile3.ord+1][piece.tuile3.abs] != 0 || piece.tuile3.ord+1 == LONGUEUR){
        puts("ça pete3");
        return(1) ;
    }
    if(tableau[piece.tuile4.ord+1][piece.tuile4.abs] != 0 || piece.tuile4.ord+1 == LONGUEUR){
        puts("ça pete4");
        return(1) ;
    }
    return 0;
}

int testColonne(Piece piece, int tableau[LONGUEUR][LARGEUR]) {
    if(tableau[piece.tuile1.ord][piece.tuile1.abs] != 0 || piece.tuile1.ord<0) {
        puts("Fin du jeu");
        return 1;
    }
    if(tableau[piece.tuile2.ord][piece.tuile2.abs] != 0 || piece.tuile2.ord<0) {
        puts("Fin du jeu");
        return 1;
    }
    if(tableau[piece.tuile3.ord][piece.tuile3.abs] != 0 || piece.tuile3.ord<0) {
        puts("Fin du jeu");
        return 1;
    }
    if(tableau[piece.tuile4.ord][piece.tuile4.abs] != 0 || piece.tuile4.ord<0) {
        puts("Fin du jeu");
        return 1;
    }
    return 0;
}

int ColonneDroite(Piece piece, int tableau[LONGUEUR][LARGEUR]) { //On vérifie que la pièce ne peut pas dépasser le côté droit du plateau
    printf("1 %d / %d\n",piece.tuile1.abs, piece.tuile1.ord);
    printf("2 %d / %d\n",piece.tuile2.abs, piece.tuile2.ord);
    printf("3 %d / %d\n",piece.tuile3.abs, piece.tuile3.ord);
    printf("4 %d / %d\n",piece.tuile4.abs, piece.tuile4.ord);
    if(piece.tuile1.abs+1 >= LARGEUR) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile2.abs+1 >= LARGEUR) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile3.abs+1 >= LARGEUR) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile4.abs+1 >= LARGEUR) {
        puts("On sort du tableau");
        return 1;
    }
    return 0;
}

int ColonneGauche(Piece piece, int tableau[LONGUEUR][LARGEUR]) { //On vérifie que la pièce ne peut pas dépasser le coté gauche du plateau
    printf("1 %d / %d\n",piece.tuile1.abs, piece.tuile1.ord);
    printf("2 %d / %d\n",piece.tuile2.abs, piece.tuile2.ord);
    printf("3 %d / %d\n",piece.tuile3.abs, piece.tuile3.ord);
    printf("4 %d / %d\n",piece.tuile4.abs, piece.tuile4.ord);
    if(piece.tuile1.abs-1 == -1) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile2.abs-1 == -1) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile3.abs-1 == -1) {
        puts("On sort du tableau");
        return 1;
    }
    if(piece.tuile4.abs-1 == -1) {
        puts("On sort du tableau");
        return 1;
    }
    return 0;
}

int decalDroite(Piece piece, int decal) { //On met à jour le décalage de la pièce pour que la pièce ne sorte pas du côté droit du plateau
    switch (piece.type) {
        case 1: case 6: //la barre et le Z
            switch(piece.rotation) {
                case 0: decal = piece.tuile1.abs;
            } break;
        case 3: //le T
            switch(piece.rotation) {
                case 0: case 2: decal = piece.tuile1.abs-1;
            } break;
        case 4: case 5: //le L et le J
            switch(piece.rotation) {
                case 0: case 2: decal = piece.tuile1.abs;
            } break;
        case 7: //Le S
            switch(piece.rotation) {
                case 0: decal = piece.tuile1.abs-1;
            } break;
    }
    return decal;
}

Piece rotationDroite(Piece piece, int plateau[][LARGEUR]) { //On vérifie que la rotation ne sort pas du côté droit plateau
    switch (piece.type) {
        case 1: case 3: case 4: case 5: case 6: case 7:
            while(ColonneDroite(piece, plateau) == 1) {
                piece.tuile1.abs--;
                piece.tuile2.abs--;
                piece.tuile3.abs--;
                piece.tuile4.abs--;
            } break;
    }
    piece.tuile1.abs++;
    piece.tuile2.abs++;
    piece.tuile3.abs++;
    piece.tuile4.abs++;
    return piece;
}
