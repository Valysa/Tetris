#include "fonctions.h"

int main(){
    Game game;
    recupRecord(game.records);
    srand(time(NULL));
    initscr();
    noecho();
    do {
        game = menu(game);
    }while (game.choix !=4);
    return (0);
}
