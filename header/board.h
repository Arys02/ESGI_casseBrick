//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_BOARD_H
#define ESGI_CASSEBRICK_BOARD_H

#include "object.h"
#include "player.h"
#include "bomb.h"
#include "cell.h"
#include "filereader.h"

typedef struct {
    int width;
    int height;
    Cell ***board;

    //let include the players in board for now
    int nb_player;
    Player **players;
}
Board;

//read src_files to build a new board
Board *build_board(int inb_player, Player **p, char *src_file);
void free_board(Board *b);

//switch two cell
int switch_cell(Board *b, int src_x, int src_y, int dst_x, int dst_y);

//get cell from the board *b
Cell *get_cell(Board *b, int x, int y);
void print_board_cell(Cell ***board, int width, int height);

int count_nb_player(Cell ***board, int width, int height);

void fill_player_table(Cell ***board, int width, int height, Player **nb_player, int nb_bomb);


void outside_board(int *dst_x, int *dst_y, Board *b);



#endif //ESGI_CASSEBRICK_BOARD_H
