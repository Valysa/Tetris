#include "fonctions.h"

Ligne compteur_ligne(Game game) { //On compte le nombre de lignes complètes
    int i=LONGUEUR-1, j=0, compteur=0;
    Ligne n;
    n.nbLignes = 0;
    n.ord = 0;
    for(i=LONGUEUR-1; i>-1; i--) {
        for(j=0; j<LARGEUR; j++) {
            if(game.plateau[i][j] != 0)
                compteur++;
        }
        if(compteur == LARGEUR) {
            n.nbLignes++;
            if(n.nbLignes == 1) {
                n.ord = i;
            }
        }
        compteur=0;
    }
    return (n);
}

int ligne_complete(Game game, int ligne) { //On compte le nombre de lignes complètes
    int i=ligne, j=0, compteur=0;
    for(j=0; j<LARGEUR; j++) {
        if(game.plateau[i][j] != 0) {
            compteur++;
        }
    }
    return (compteur);
}

void copieTableau(int tableau[][LARGEUR], int copie[][LARGEUR]){
    int i, j;
    for(i=0; i<LONGUEUR ;i++){
        for(j=0 ; j<LARGEUR ; j++){
            copie[i][j] = tableau[i][j] ;
        }
    }
}

Game effacement(Game game, Ligne n) { //On efface les lignes complètes et on descend ensuite
    int i=n.ord, j=0, lignesEffacees=n.nbLignes, temp=0; //les pièces restantes selon le nombre de lignes effacées
    int copie[LONGUEUR][LARGEUR];
    copieTableau(game.plateau, copie);
    if(n.nbLignes>0) {                                      
        do{
            if(ligne_complete(game, i) == LARGEUR) { //On efface les lignes complètes
                for(j=0; j<LARGEUR; j++) {
                    game.plateau[i][j]=0;
                }
                lignesEffacees--;
                }
                i--;
        }while(lignesEffacees>0 && i>0);
        for(int u=0; u<3 ; u++){ //boucle pour "faire clignoter" les lignes
                system("clear");
                printf("\n\n\n\n");
                printPlate(game.plateau);
                usleep(1500*100);
                system("clear");
                printf("\n\n\n\n");
                printPlate(copie);
                usleep(1500*100);
            }
        do{ //On décale les pièces en fonction du nombre de lignes effacées
            for(i=n.ord-n.nbLignes; i>-1; i--) {
                for(j=0; j<LARGEUR; j++) {
                    if(game.plateau[i][j] != 0) {
                        temp = game.plateau[i][j];
                        game.plateau[i+1][j] = temp;
                        game.plateau[i][j]=0;
                    }
                }
            }
            n.nbLignes--;
        }while(n.nbLignes>0); //On répète l'opération jusqu'à ce qu'il n'y ait plus de ligne complète
    }
    return (game);
}


void clearPlate(int tableau[LONGUEUR][LARGEUR]){  //une fonction qui clear le plateau de jeu
    int i,j;
    for(i=0; i<LONGUEUR; i++){
        for(j=0 ; j<LARGEUR; j++){
            tableau[i][j] = 0 ;
        }
    }
}
