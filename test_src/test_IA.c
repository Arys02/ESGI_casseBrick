//
// Created by Arys on 17/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/ia.h"



int main() {
    Board *b = build_board(1, NULL, "../map/map_3_collision");
    //Path p = init_path();

    //drop_bomb_player(b->players[0], b);
    //Path p = get_move_queue(b->players[0], b);
    while(1){
        print_board_cell(b->board, b->width, b->height);
        ia_move(b->players[0], b);
        update_all_clock(b);
        //sleep(1);
    }


    return 0;
}
