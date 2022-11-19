//
// Created by Arys on 19/11/2022.
//

#include "../header/player_action.h"


void drop_bomb_player(Player *p, Board *b){
    //TODO
}

void player_move(Player *p, Board *b, enum direction dir){
    int dst_x = p->pos_x;
    int dst_y = p->pos_y;
    int src_x = p->pos_x;
    int src_y = p->pos_y;
    int moved = 0;
    switch (dir) {
        case UP:
            dst_x -= 1;
            break;
        case DOWN:
            dst_x += 1;
            break;
        case LEFT:
            dst_y -= 1;
            break;
        case RIGHT:
            dst_y += 1;
            break;
        default:
            break;
    }
    outside_board(&dst_x, &dst_y, b); //we get destination coordinats
    //if next cell is empty no pb, just switch
    if (b->board[dst_x][dst_y]->kind_cell == VOID) {
        moved = 1;
        switch_cell(b, p->pos_x, p->pos_y, dst_x, dst_y);
        update_player_pos(p, dst_x, dst_y);
    }


    //if next case is a bomb
    if (b->board[dst_x][dst_y]->kind_cell == BOMB){
        if (p->bc == PASS) {
            moved = 1;
            //TODO
            //se superpose
        }
        if (p->bc == KICK){
            moved = 1;
            //TODO
            //kick la bombe
        }
    }

    if (b->board[dst_x][dst_y]->kind_cell == OBJECT){
        moved = 1;
       //TODO
    }
    //if player was on bomb after moving
    if (moved){
        if(b->board[src_x][src_y]->tmp_content != NULL){
            update_cell(b->board[src_x][src_y],b->board[src_x][src_y]->tmp_content, BOMB);
            b->board[src_x][src_y]->tmp_content = NULL;
        }
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
