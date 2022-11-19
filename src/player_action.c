//
// Created by Arys on 19/11/2022.
//

#include "../header/player_action.h"


void drop_bomb_player(Player *p, Board *b){
    //TODO
}

void player_move(Player *p, Board *b, enum direction dir){
    int newp_x = p->pos_x;
    int newp_y = p->pos_y;
    if (dir == UP){

    }
}


void player_move_up(Player *p, Board *b){
    int dst_x = p->pos_x - 1;
    int dst_y = p->pos_y;

    outside_board(&dst_x, &dst_y, b);

    switch_cell(b, p->pos_x, p->pos_y, dst_x, dst_y);
    update_player_pos(p, dst_x, dst_y);
}
void player_move_down(Player *p, Board *b){
    int dst_x = p->pos_x + 1;
    int dst_y = p->pos_y;

    outside_board(&dst_x, &dst_y, b);

    switch_cell(b, p->pos_x, p->pos_y, dst_x, dst_y);
    update_player_pos(p, dst_x, dst_y);

}
void player_move_right(Player *p, Board *b){
    int dst_x = p->pos_x;
    int dst_y = p->pos_y + 1;

    outside_board(&dst_x, &dst_y, b);

    switch_cell(b, p->pos_x, p->pos_y, dst_x, dst_y);
    update_player_pos(p, dst_x, dst_y);
}

void player_move_left(Player *p, Board *b){
    int dst_x = p->pos_x;
    int dst_y = p->pos_y - 1;

    outside_board(&dst_x, &dst_y, b);

    switch_cell(b, p->pos_x, p->pos_y, dst_x, dst_y);
    update_player_pos(p, dst_x, dst_y);
}
