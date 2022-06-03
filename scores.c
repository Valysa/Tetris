#include "fonctions.h"

void choixPseudo(char pseudo[TAILLEPSEUDO]){
    puts("Veuillez saisir un pseudo pour entrer dans la légende\r");
    int i=0;
    char c;
    int choix = 0;
    do{
        choix = 0;
        choix = getchar();
        if(choix != ERR && choix != 127){
            if (choix == ' '){
                printf("_");
                c = '_' ;
            }
            else{
                printf("%c",choix);
                c = choix ;
            }
            if(choix != 13){
				pseudo[i] = c;
			}
            i++;
        }
    }while(i != TAILLEPSEUDO-1 && choix != 13);
}

Game ajoutScore(Game game, int position){
    for(int i=NBRECORDS-1; i>0; i--){
        if(i >= position){
            game.records[i].score = game.records[i-1].score;
            game.records[i] = game.records[i-1];
        }
    }
    game.records[position].classement = position ;
    game.records[position].score = game.score;
    for(int j=0; j<TAILLEPSEUDO+1; j++){
		game.records[position].pseudo[j] = 32;
	}
    puts("");
    choixPseudo(game.records[position].pseudo);
    clearScore();
    sauvegarde(game.records);
    return (game);
}

void recupRecord(Record records[NBRECORDS]){//10 car on ne garde que les 10 meilleurs en mémoire
    FILE *fichier = NULL;
    fichier = fopen("scores.txt", "r");
    if(fichier == NULL){
        puts("Erreur : le fichier n'est pas accessible");
        exit(1);
    }
    fseek(fichier, 0, SEEK_SET);
    for (int i=0 ; i<NBRECORDS; i++){
        fseek(fichier, (TAILLEPSEUDO+8)*i, SEEK_SET);
        fscanf(fichier, "%s", &records[i].pseudo);
    }
    fseek(fichier, 0, SEEK_SET);
    for (int j=0 ; j<NBRECORDS; j++){
        fseek(fichier, TAILLEPSEUDO+1, SEEK_CUR);
        fscanf(fichier, "%d", &records[j].score);
    }
    for (int i=0 ; i<NBRECORDS; i++){
        records[i].classement = i;
    }
    fclose(fichier);
}

int testTaille(int nb){
    if(nb <= 9){
        return 5;
    }
    if(nb <= 99){
        return 4;
    }
    if(nb <= 999){
        return 3;
    }
    if(nb <= 9999){
        return 2;
    }
    if(nb <= 99999){
        return 1;
    }
    return 0;
}

void sauvegarde (Record records[NBRECORDS]){
    FILE *fichier = NULL;
    fichier = fopen("scores.txt", "r+");
    fseek(fichier, 0, SEEK_SET);
    for (int i=0 ; i<NBRECORDS; i++){
        fseek(fichier, (TAILLEPSEUDO+8)*i, SEEK_SET);
        fprintf(fichier, "%s", records[i].pseudo);
    }
    fseek(fichier, 0, SEEK_SET);
    for (int j=0 ; j<NBRECORDS; j++){
        fseek(fichier, TAILLEPSEUDO+1, SEEK_CUR);
        for(int u=0; u<testTaille(records[j].score); u++){
            fprintf(fichier, "0");          //autofill avec des 0
        }
        fprintf(fichier, "%d\n", records[j].score);
    }
    fclose(fichier);
}

void recupPseudo(Record record, FILE* fichier){
    fscanf(fichier, "%s", &record.pseudo);
}


int testScore(Game game){
    printf("Le score est %d\r",game.score);
    for(int i=0; i<NBRECORDS; i++){
        if(game.score > game.records[i].score){
            return i;
        }
    }
    return -1;
}

void clearScore(){
    FILE *fichier = NULL;
    fichier = fopen("scores.txt", "w");
    for(int i=0; i<NBRECORDS ; i++){
        for(int j=0; j<TAILLEPSEUDO+8; j++){
            fprintf(fichier, " ");
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}


int incrementationScore(int score, int lignesfull) {
    switch (lignesfull) {
        case 1: score = score + 40; break;
        case 2: score = score + 100; break;
        case 3: score = score + 250; break;
        case 4: score = score + 500; break;
    }
    return score;
}
