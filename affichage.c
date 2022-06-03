#include "fonctions.h"

void printDecal(int decal){
    int i;
    printf(" ");
    for (i=0 ; i<decal ; i++){
        printf("    ");
    }
}

void printPlate(int plateau[LONGUEUR][LARGEUR]){  //une fonction qui affiche le plateau de jeu (avec des "   " si la valeur dans le tableau est 0
    int i=0,j=0;                                       // et des " X " si la valeur dans le tableau est 1)
    for(i=0; i<LONGUEUR ;i++){
        printf("|") ;
        for(j=0 ; j<LARGEUR ; j++){
            switch(plateau[i][j]){
                case 0 : printf("   ") ; break ;
                case 1 : printf("\033[38;5;14m"); printf(" @ ") ; break ;
                case 2 : printf("\033[38;5;11m"); printf(" @ ") ; break ;
                case 3 : printf("\033[38;5;93m"); printf(" @ ") ; break ;
                case 4 : printf("\033[38;5;214m"); printf(" @ ") ; break ;
                case 5 : printf("\033[38;5;171m"); printf(" @ ") ; break ;
                case 6 : printf("\033[38;5;9m"); printf(" @ ") ; break ;
                case 7 : printf("\033[38;5;34m"); printf(" @ ") ; break ;
            }
        printf("\033[0m");
        printf("|") ;
        }
    puts("\r");
    }
}


void printPiece(Game game, int decal){ //On affiche chaque pièce selon son type et sa rotation
    system("clear");
    switch (game.piece.type){
        case 1 : printf("\033[38;5;14m"); //La barre
            switch(game.piece.rotation){
                case 0 : puts("\r");puts("\r"); puts("\r");  printDecal(decal) ; puts(" @   @   @   @\r"); break ;
                case 1 : printDecal(decal) ; puts(" @           \r");
                         printDecal(decal) ; puts(" @           \r");
                         printDecal(decal) ; puts(" @           \r");
                         printDecal(decal) ; puts(" @           \r"); break ;
            } break ;
        case 2 : printf("\033[38;5;11m"); //le cube
                puts("\r"); puts("\r");
                printDecal(decal) ; puts(" @   @\r");
                printDecal(decal) ; puts(" @   @\r"); break ;
        case 3 : printf("\033[38;5;93m"); //Le T
            switch(game.piece.rotation){
                case 0 : puts("\r"); puts("\r"); printDecal(decal) ; puts("     @    \r");
                         printDecal(decal) ; puts(" @   @   @\r");
                        break;
                case 1 : puts("\r"); printDecal(decal) ; puts(" @    \r");
                         printDecal(decal) ; puts(" @   @\r");
                         printDecal(decal) ; puts(" @    \r");
                        break;
                case 2 :puts("\r"); puts("\r");  printDecal(decal) ; puts(" @   @   @\r");
                         printDecal(decal) ; puts("     @    \r");
                        break;
                case 3 :puts("\r");  printDecal(decal) ; puts("     @    \r");
                         printDecal(decal) ; puts(" @   @    \r");
                         printDecal(decal) ; puts("     @    \r");
                        break;
            } break ;
        case 4 : printf("\033[38;5;214m"); //Le L
            switch(game.piece.rotation){
                case 0 : puts("\r"); puts("\r"); printDecal(decal) ; puts(" @   @   @\r");
                         printDecal(decal) ; puts(" @        \r");
                        break;
                case 1 : puts("\r"); printDecal(decal) ; puts(" @   @    \r");
                         printDecal(decal) ; puts("     @    \r");
                         printDecal(decal) ; puts("     @    \r");
                        break;
                case 2 : puts("\r"); puts("\r"); printDecal(decal) ; puts("         @\r");
                         printDecal(decal) ; puts(" @   @   @\r");
                        break;
                case 3 : puts("\r"); printDecal(decal) ; puts(" @        \r");
                         printDecal(decal) ; puts(" @        \r");
                         printDecal(decal) ; puts(" @   @    \r");
            } break ;
        case 5 : printf("\033[38;5;171m"); //Le J
            switch(game.piece.rotation){
                case 0 : puts("\r"); puts("\r"); printDecal(decal) ; puts(" @   @   @\r");
                         printDecal(decal) ; puts("         @\r");
                        break ;
                case 1 : puts("\r"); printDecal(decal) ; puts("     @    \r");
                         printDecal(decal) ; puts("     @    \r");
                         printDecal(decal) ; puts(" @   @    \r");
                        break ;
                case 2 : puts("\r"); puts("\r"); printDecal(decal) ; puts(" @        \r");
                         printDecal(decal) ; puts(" @   @   @\r");
                        break ;
                case 3 :puts("\r");  printDecal(decal) ; puts(" @   @    \r");
                         printDecal(decal) ; puts(" @        \r");
                         printDecal(decal) ; puts(" @        \r");
                        break;
            } break ;
        case 6 : printf("\033[38;5;9m"); //Le S
            switch(game.piece.rotation){
                case 0 : puts("\r"); puts("\r"); printDecal(decal) ; puts(" @   @    \r");
                         printDecal(decal) ; puts("     @   @\r");
                        break;
                case 1 : puts("\r"); printDecal(decal) ; puts("     @\r");
                         printDecal(decal) ; puts(" @   @\r");
                         printDecal(decal) ; puts(" @    \r");
                        break;
            } break ;
        case 7 : printf("\033[38;5;34m"); //Le Z
            switch(game.piece.rotation){
                case 0 : puts("\r"); puts("\r"); printDecal(decal) ; puts("     @   @\r");
                         printDecal(decal) ; puts(" @   @    \r");
                        break;
                case 1 : puts("\r"); printDecal(decal) ; puts(" @        \r");
                         printDecal(decal) ; puts(" @   @    \r");
                         printDecal(decal) ; puts("     @    \r");
                        break;
            } break ;
    }
    printf("\033[0m");
}

void printScore(int score){
    printf("\33[%d;%dH",LONGUEUR+5,LARGEUR*4);
    printf("%d\n\r", score);
}

void affichagetotal(Game game, int decal){
printPiece(game, decal);
    printPlate(game.plateau);
    printScore(game.score);
}

void hallOfFame(Record records[NBRECORDS]){
    //system("cls");
    for (int i=0; i<NBRECORDS ; i++){
        printf("%s : %d\n\r", records[i].pseudo, records[i].score);
    }
}

int affichemenu(Game game){
    int c=0, choix=0;
	system("clear");
	puts("  _______ ______ _______ _____  _____  _____ \r");
	puts(" |__   __|  ____|__   __|  __ \x5C|_   _|/ ____|\r");
	puts("    | |  | |__     | |  | |__) | | | | (___  \r");
	puts("    | |  |  __|    | |  |  _  /  | |  \x5C___ \x5C \r");
	puts("    | |  | |____   | |  | | \x5C \x5C _| |_ ____) |\r");
	puts("    |_|  |______|  |_|  |_|  \x5C_\x5C_____|_____/ \r");
	puts("-------------------\r");
	puts("|Start Game    - 1|\r");
    puts("|Controls      - 2|\r");
    puts("|Quit          - 3|\r");
    puts("-------------------\r");
    hallOfFame(game.records);
    puts("\r");
    do {
		choix=getchar();
		if(choix != ERR) {
			switch(choix) {
				case 49: c=1; break;
				case 50: c=2; break;
				case 51: c=3; break;
			}
		}
	}while (c == 0);
	return c;
}


void controls(){
    char c='a';
    system("clear");
    puts("Pour bouger les pieces en haut de l'écran appuyez sur :\r");
    puts("'q' pour aller a gauche\r");
    puts("'d' pour aller a droite\r");
    puts("'z' pour tourner la piece dans le sens horaire \r");
    puts("'s' pour la tourner dans le sens antihoraire\r");
    puts("Une fois voitre choix effectué, saisissez 'v' pour que la piece tombe (attention le temps est compté, si vous mettez trop de temps, votre dernier coup ne sera pas compté\r");
    puts("Appuyez sur Entrée pour sortir de ce menu\r");
    do {
		c=getchar();
	}while(c!=13);
}

