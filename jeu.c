#include "fonctions.h"

Game tour(Game game){ // fonction du tour d'un joueur
    game.piece.type = generatePieceType();
    game.piece.rotation = 1 ;
    printf("piece type est %d\n",game.piece.type);
    puts("choisissez la colone puis la rotation") ;
    game.piece = choixPlacement(game);
    game.piece.tuile2.abs = game.piece.tuile1.abs ;
    game.piece.tuile2.ord = game.piece.tuile1.ord ;
    game.piece.tuile3.abs = game.piece.tuile1.abs ;
    game.piece.tuile3.ord = game.piece.tuile1.ord ;
    game.piece.tuile4.abs = game.piece.tuile1.abs ;
    game.piece.tuile4.ord = game.piece.tuile1.ord ; // set abs et ord de chaque tuile sur celles de la tuile1
    game.piece = placement(game.piece) ;
    do{ //On fait descendre la pièce tant qu'elle n'entre pas en colision avec une autre pièce ou tant qu'elle n'atteind la limite verticale du plateau
        game.piece.tuile1.ord ++;
        game.piece.tuile2.ord ++;
        game.piece.tuile3.ord ++;
        game.piece.tuile4.ord ++;
    }while (testColision(game.piece, game.plateau) == 0) ;
    if(testColonne(game.piece, game.plateau) == 1) {
        game.testDefaite = 1;
    }
    game.plateau[game.piece.tuile1.ord][game.piece.tuile1.abs] = game.piece.type ;
    game.plateau[game.piece.tuile2.ord][game.piece.tuile2.abs] = game.piece.type ;
    game.plateau[game.piece.tuile3.ord][game.piece.tuile3.abs] = game.piece.type ;
    game.plateau[game.piece.tuile4.ord][game.piece.tuile4.abs] = game.piece.type ;
    system("clear");
    return(game);
}

Game game(Game game){  // fonction gérant une partie complète (avec tout les tour du joueur et jusqu'a défaite)
    int testscore, nbTour=0;
    game.testDefaite = 0;
    game.score = 0;
    game.speed=18;
    Ligne lignesfull;
    lignesfull.nbLignes = 0;
    lignesfull.ord = 0;
    clearPlate(game.plateau);
    do{
        game = tour(game);
        nbTour++;
        lignesfull = compteur_ligne(game);
        game.score = incrementationScore(game.score, lignesfull.nbLignes);
        game = effacement(game, lignesfull);
			if(game.speed > 3) {
				if(nbTour%10 == 0) {
					game.speed--;
				}
			}
    } while (game.testDefaite ==0) ;
    testscore = testScore(game);
    if(testscore != -1){
        game = ajoutScore(game, testscore);
        clearScore();
        sauvegarde(game.records);
    }
    puts("Game Over");
    return game;
}

Game menu(Game jeu){
    int choix = 0;
    choix = affichemenu(jeu) ;
    switch(choix){
        case 1 : jeu = game(jeu); break;
        case 2 : controls(); break ;
        case 3 : puts("succes exit") ; break ;
    }
    jeu.choix = choix;
    return(jeu);
}

Piece choixPlacement(Game game){ //On choisit le placement et l'orientation de la pièce affichée dans le terminal
    int decal = 0, nbRotation = 4;
    time_t debut;
    time_t fin;
    switch(game.piece.type){
        case 1 : case 6 : case 7 : nbRotation = 2 ; break ;
        case 2 : nbRotation = 1 ; break;
    }
    decal = LARGEUR/2 ;
    affichagetotal(game, decal);
    int choix = 0;
    debut=time(NULL);
    do{
        game.piece.tuile1.abs = decal;
        game.piece.tuile2.abs = game.piece.tuile1.abs ; //On initialise l'abscisse et l'ordonnée de chacune des tuiles 2,3 et 4 sur la tuile 1
        game.piece.tuile2.ord = game.piece.tuile1.ord ;
        game.piece.tuile3.abs = game.piece.tuile1.abs ;
        game.piece.tuile3.ord = game.piece.tuile1.ord ;
        game.piece.tuile4.abs = game.piece.tuile1.abs ;
        game.piece.tuile4.ord = game.piece.tuile1.ord ;
        game.piece = placement(game.piece);
        choix = getchar();
        fin=time(NULL);
        if(difftime(fin, debut)>game.speed) {
			choix=118;
		}
        if(choix != 0){
			if(choix == 100){
				if (ColonneDroite(game.piece, game.plateau) == 1) { //On vérifie que la pièce ne peut pas sortir du côté droit plateau.
					affichagetotal(game, decal) ; //Si la pièce est censée "sortir" du plateau, alors on ne modifie pas la pièce.
		}
			else {
				decal ++;
				affichagetotal(game, decal);
			}
		}
		if(choix == 113){
			if (ColonneGauche(game.piece, game.plateau) == 1) { //On vérifie que la pièce ne peut pas sortir du côté gauche plateau.
				affichagetotal(game, decal) ; //Si la pièce est censée "sortir" du plateau, alors on ne modifie pas la pièce.
		}
			else {
				decal --;
				affichagetotal(game, decal);
			}
		}
		if(choix == 122){
			if ((ColonneDroite(game.piece, game.plateau) == 1)) { //On vérifie que la pièce ne peut pas sortir ni du coté ni du coté gauche du plateau.
				game.piece.rotation --;
				if(game.piece.rotation == -1){
					game.piece.rotation = game.piece.rotation + nbRotation;
				}
				game.piece.rotation = game.piece.rotation % nbRotation ;
				game.piece = placement(game.piece);
				game.piece = rotationDroite(game.piece, game.plateau);
				decal = decalDroite(game.piece, decal);
				affichagetotal(game, decal); //Si la pièce est censée "sortir" du plateau, alors on ne modifie pas la pièce.
			}
			else {
				game.piece.rotation --;
				if(game.piece.rotation == -1){
					game.piece.rotation = game.piece.rotation + nbRotation;
				}
				game.piece.rotation = game.piece.rotation % nbRotation ;
				game.piece = placement(game.piece);
				if(game.piece.type == 1) {
					if(game.piece.rotation == 0) {
						switch(decal) {
							case LONGUEUR - 3: case LONGUEUR - 2: decal = LONGUEUR - 4;
						}
					}
				}
				affichagetotal(game, decal);
			}
		}
		if(choix == 115) {
			if ((ColonneDroite(game.piece, game.plateau) == 1)) { //On vérifie que la pièce ne peut pas sortir ni du coté ni du coté gauche du plateau.
				game.piece.rotation ++;
				game.piece.rotation = game.piece.rotation % nbRotation ;
				game.piece = placement(game.piece);
				game.piece = rotationDroite(game.piece, game.plateau);
				decal = decalDroite(game.piece, decal);
				affichagetotal(game, decal); //Si la pièce est censée "sortir" du plateau, alors on ne modifie pas la pièce.
			}
		else {
			game.piece.rotation ++;
			game.piece.rotation = game.piece.rotation % nbRotation ;
			game.piece = placement(game.piece);
			if(game.piece.type == 1) {
				if(game.piece.rotation == 0) {
					switch(decal) {
						case LONGUEUR - 3: case LONGUEUR - 2: decal = LONGUEUR - 4;
					}
				}
			}
			affichagetotal(game, decal);
			}
		}
		game.piece.tuile1.abs = decal ;
		}
    }while(choix != 118);
    game.piece.tuile1.ord = 0 ; //On réinitialise l'ordonnée de la tuile 1 à 0.
    return (game.piece);
}

int generatePieceType(){ // fonction qui genere une piece
    int rdm;
    rdm = rand() % 7 +1;
    return(rdm);
}

