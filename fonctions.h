#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <curses.h>

#if defined LINUX
#define system("cls") system("clear")
#define sleep(SPEED) usleep(SPEED*1000)
#endif
#define NBRECORDS 10
#define TAILLEPSEUDO 20
#define LONGUEUR 10
#define LARGEUR 10

typedef struct{ //structure d'une case en (x;y)
    int abs;
    int ord;
} Tuile ;

typedef struct{
    int score;
    char pseudo[TAILLEPSEUDO];
    int classement;
} Record;

typedef struct{ //structure d'une piece
    Tuile tuile1;
    Tuile tuile2;
    Tuile tuile3;
    Tuile tuile4;
    int type;
    int rotation;
} Piece ;

typedef struct{
    int nbLignes;
    int ord;
} Ligne ;

typedef struct{
    int plateau[LONGUEUR][LARGEUR];
    Piece piece;
    int score;
    int testDefaite;
    Record records[NBRECORDS];
    int choix;
    int speed;
    int difficulty;
} Game ;

void clean(void);
void printDecal(int decal);
void printPiece(Game game, int decal);
void printScore(int score);
void printPlate(int plateau[LONGUEUR][LARGEUR]);
Ligne compteur_ligne(Game game);
int ligne_complete(Game game, int ligne);
void copieTableau(int tableau[][LARGEUR], int copie[][LARGEUR]);
Game effacement(Game game, Ligne n);
Piece placement(Piece piece);
void clearPlate(int tableau[LONGUEUR][LARGEUR]);
int generatePieceType();
int testColision(Piece piece, int tableau[LONGUEUR][LARGEUR]);
int testColonne(Piece piece, int tableau[LONGUEUR][LARGEUR]);
int ColonneDroite(Piece piece, int tableau[LONGUEUR][LARGEUR]);
int ColonneGauche(Piece piece, int tableau[LONGUEUR][LARGEUR]);
int decalDroite(Piece piece, int decal);
Piece rotationDroite(Piece piece, int plateau[][LARGEUR]);
void affichagetotal(Game game, int decal);
Piece choixPlacement(Game game);
Game tour(Game game);
int incrementationScore(int score, int lignesfull);
void choixPseudo(char pseudo[TAILLEPSEUDO]);
int testScore(Game game);
void clearScore();
void recupRecord(Record records[NBRECORDS]);
int testTaille(int nb);
void sauvegarde (Record records[NBRECORDS]);
Game ajoutScore(Game game, int position);
Game game(Game game);
void hallOfFame(Record records[NBRECORDS]);
void controls();
int affichemenu(Game game);
void recupPseudo(Record record, FILE* fichier);
Game menu(Game jeu);

