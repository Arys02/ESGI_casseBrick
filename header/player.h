//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_PLAYER_H
#define ESGI_CASSEBRICK_PLAYER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "bomb.h"

#define MAX_BOMB 10
#define DEFAULT_BOMB_RANGE 2
#define DEFAULT_BOMB_QUANTITY 1

enum bomb_collision {
    NONE,
    PASS,
    KICK
};

typedef struct {
    char *name;
    char symbol;
    int life;
    int bomb_range;
    int bomb_quantity;
    int pos_x;
    int pos_y;
    Bomb **Inventory;

    //objects
    int has_heart;
    int immunity_clock;
    enum bomb_collision bc;
}
Player;


Player *build_player(char *name, char symbol);

void free_player(Player *p);
//update all clocks from the players (bomb and immunity if it has one)
void update_clocks_player(Player *p);

void update_bomb_range_player(Player *p, int new_value);
void update_bomb_quantity_player(Player *p, int new_value);
void update_bomb_collision(Player *p, enum bomb_collision);

void get_object_player(Player *p, enum object_type);
void update_player_pos(Player *p, int x, int y);
void drop_bomb_player(Player *p);



#endif //ESGI_CASSEBRICK_PLAYER_H
