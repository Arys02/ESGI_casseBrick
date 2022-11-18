//
// Created by Arys on 17/10/2022.
//
#include <stdio.h>
#include "../header/board.h"

int main() {
    Board *b = build_board(1, NULL, "../map/map_1");
    print_board_cell(b->board, b->width, b->height);
    free_board(b);
    printf("Hello, World!\n");
    //free(b);
    printf("%d\n",b->height);
    return 0;
}
