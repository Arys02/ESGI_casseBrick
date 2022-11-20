//
// Created by Arys on 19/11/2022.
//

#ifndef ESGI_CASSEBRICK_PLAYER_ACTION_H
#define ESGI_CASSEBRICK_PLAYER_ACTION_H
#include "player.h"
#include "board.h"
#include "object.h"


void drop_bomb_player(Player *p, Board *b);
void player_move(Player *p, Board *b, enum direction dir);




#endif //ESGI_CASSEBRICK_PLAYER_ACTION_H
