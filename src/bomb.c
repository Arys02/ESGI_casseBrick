//
// Created by Arys on 17/10/2022.
//

#include "../header/bomb.h"

/**
 * It creates a new bomb and returns a pointer to it
 *
 * @return A pointer to a Bomb struct.
 */
Bomb *build_bomb(){
    Bomb *b = malloc(sizeof(Bomb));
    b->pos_x = -1;
    b->pos_y = -1;
    b->clock = -1;
    return b;
}
void free_bomb(Bomb *b){
    free(b);
}
/**
 * It updates the clock of a bomb and returns a status
 *
 * @param b the bomb to update
 *
 * @return The status of the bomb.
 */
enum clock_timer_STATUS update_bomb_clock(Bomb *b){
    //la clock est déjà à -1, la bombe est dans l'inventaire
    if (b->clock == -1)
        return INVENTORY;
    //la bombe n'est pas dans l'inventaire la clock descend

    b->clock--;
    switch(b->clock){
        case -1:
            return INVENTORY;
        case 0:
            return BOOM;
        default:
            return TIC_TAC;
    }
}

void drop_bomb_init(Bomb *b, int x, int y){
    b->clock = TIMER;
    b->pos_y = y;
    b->pos_x = x;
}

