//
// Created by Arys on 19/11/2022.
//

#include "../header/player_action.h"


void drop_bomb_player(Player *p, Board *b){
    //TODO
}



void player_move_up(Player *p, Board *b){
    switch_cell(b, p->pos_x, p->pos_y, p->pos_x - 1, p->pos_y);
    update_player_pos(p, p->pos_x - 1, p->pos_y);
}
void player_move_down(Player *p, Board *b){
    switch_cell(b, p->pos_x, p->pos_y, p->pos_x + 1, p->pos_y);
    update_player_pos(p, p->pos_x + 1, p->pos_y);
}
void player_move_right(Player *p, Board *b){
    switch_cell(b, p->pos_x, p->pos_y, p->pos_x, p->pos_y + 1);
    update_player_pos(p, p->pos_x, p->pos_y + 1);
}
void player_move_left(Player *p, Board *b){
    switch_cell(b, p->pos_x, p->pos_y, p->pos_x, p->pos_y - 1);
    update_player_pos(p, p->pos_x, p->pos_y - 1);
}
