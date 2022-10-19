//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_BOARD_H
#define ESGI_CASSEBRICK_BOARD_H

#include "object.h"
#include "player.h"
#include "bomb.h"
#include "cell.h"

typedef struct {
    int width;
    int length;
    Cell **board;

    //let include the players in board for now
    int nb_player;
    Player **players;
}
Board;

#endif //ESGI_CASSEBRICK_BOARD_H
