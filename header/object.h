//
// Created by Arys on 19/10/2022.
//

#ifndef ESGI_CASSEBRICK_OBJECT_H
#define ESGI_CASSEBRICK_OBJECT_H

enum object_type{
    B_UP,
    B_DOWN,
    F_YELLOW,
    F_BLUE,
    F_RED,
    PASS_BOMB,
    KICK_BOMB,
    INV,
    HEART,
    HP_UP
};

enum object_type *get_rand_ot();

#endif //ESGI_CASSEBRICK_OBJECT_H
