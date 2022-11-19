//
// Created by Arys on 19/10/2022.
//

#include <stdlib.h>
#include <time.h>
#include "../header/object.h"

enum object_type *get_rand_ot(){
    int rnd = rand() % 101;
    enum object_type *ot = malloc(sizeof(enum object_type));

    if (rnd < 10){
        *ot = B_UP;
        return ot;
    }
    if (rnd < 20){
        *ot = B_DOWN;
        return ot;
    }
    if (rnd < 30){
        *ot = F_YELLOW;
        return ot;
    }
    if (rnd < 40){
        *ot = F_BLUE;
        return ot;
    }
    if (rnd < 50){
        *ot = F_RED;
        return ot;
    }
    if (rnd < 60){
        *ot = PASS_BOMB;
        return ot;
    }
    if (rnd < 70){
        *ot = KICK_BOMB;
        return ot;
    }
    if (rnd < 80){
        *ot = INV;
        return ot;
    }
    if (rnd < 90){
        *ot = HEART;
        return ot;
    }
    if (rnd < 100){
        *ot = HP_UP;
        return ot;
    }
    return NULL;
}
