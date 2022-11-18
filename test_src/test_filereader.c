//
// Created by Arys on 17/10/2022.
//
#include <stdio.h>
#include "../header/filereader.h"

void print_board_cell(Cell ***board, int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Cell *c = board[i][j];
            printf("%c", board[i][j]->c);
        }
        printf("\n");
    }
}
int main() {
    printf("Hello, World!\n");

    board_from_file("../map/map_1", 9, 5);

    printf("%d\n", DEFAULT_BOMB_QUANTITY);

    return 0;
}
