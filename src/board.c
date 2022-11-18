//
// Created by Arys on 17/10/2022.
//

#include "../header/board.h"

Board *build_board(int inb_player, Player **p, char *file){
    //making new board
    Board *new_board = malloc(sizeof (Board));
    int nb_bomb = 1;

    //reading nb bomb & height/width
    FILE *fp;
    fp = fopen(file, "r");
    if (!fp)
        return NULL;

    //getting our reading buffer ready
    char chunk[255];

    //getting first line
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }

    nb_bomb = atoi(chunk);

    //getting second line size & length
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }

    char *first;
    char *second = strtok_r(chunk, " ", &first);

    new_board->height = atoi(first);
    new_board->width = atoi(second);
    //get Cell*** board
    new_board->board = board_from_file(file, new_board->width, new_board->height);

    int nb_player = count_nb_player(new_board->board, new_board->width, new_board->height);
    new_board->nb_player = nb_player;
    new_board->players = malloc(sizeof(Player*) * nb_player);

    fill_player_table(new_board->board, new_board->width, new_board->height, new_board->players, nb_bomb);




    fclose(fp);
    return new_board;
}
void free_board(Board *b){
    //TODO
}

//switch two cell
int switch_cell(Board *b, int src_x, int src_y, int dst_x, int dst_y){
    //TODO
    return 0;
}

//get cell from the board *b
Cell *get_cell(Board *b, int x, int y){
    //TODO
    return NULL;
}

int count_nb_player(Cell ***board, int width, int height){
     int count = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if (board[i][j]->kind_cell == PLAYER)
                count++;
        }
    }
    return count;
}

void fill_player_table(Cell ***board, int width, int height, Player **nb_player, int nb_bomb){
    int x = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j <width; j++){
            if (board[i][j]->kind_cell == PLAYER){
                char pname[256];
                itoa(x, pname, 10);
                nb_player[x] = build_player(pname, pname[0], nb_bomb);
                update_player_pos(nb_player[x], i, j);
                x++;
            }
        }
    }

}

void print_board_cell(Cell ***board, int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Cell *c = board[i][j];
            printf("%c", board[i][j]->c);
        }
        printf("\n");
    }
}
