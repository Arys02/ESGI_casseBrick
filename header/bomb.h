//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_BOMB_H
#define ESGI_CASSEBRICK_BOMB_H
#include <stdlib.h>

#define TIMER 10

enum clock_timer_STATUS {
    BOOM,
    TIC_TAC,
    INVENTORY,
};

typedef struct {
    int pos_x; //-1 (dans l'inventaire)
    int pos_y; //-1 (dans l'inventaire)
    int clock; //-1 (dans l'inventaire)
} Bomb;

Bomb *build_bomb();
void drop_bomb_init(Bomb *b, int x, int y);
void free_bomb(Bomb *b);
enum clock_timer_STATUS update_bomb_clock(Bomb *b);



#endif //ESGI_CASSEBRICK_BOMB_H
