//
// Created by Arys on 17/10/2022.
//

#include "../header/player.h"

Player *build_player(char *name, char symbol){
    Player *new_player = malloc(sizeof(Player));
    new_player->Inventory = malloc((sizeof(Bomb*) * MAX_BOMB));
    for(int i = 0; i < MAX_BOMB; i++){
        new_player->Inventory[i] = build_bomb();
    }

    new_player->name = name;
    new_player->symbol = symbol;
    new_player->life = 1;
    new_player->bomb_range = DEFAULT_BOMB_RANGE;
    new_player->bomb_quantity = DEFAULT_BOMB_QUANTITY;
    new_player->pos_y = -1;
    new_player->pos_x = -1;

    new_player->has_heart = 0;
    new_player->immunity_clock = 0;
    new_player->bc = NONE;
    return new_player;
}

void free_player(Player *p){
    for(int i = 0; i < p->bomb_quantity; i++){
        free(p->Inventory[i]);
    }
    free(p);
}

void update_player_pos(Player *p, int x, int y){
    p->pos_x = x;
    p->pos_y = y;
}
//update all clocks from the players (bomb and immunity if it has one)
void update_clocks_player(Player *p){
    //TODO
}

void update_bomb_range_player(Player *p, int new_value){
    //TODO
}
void update_bomb_quantity_player(Player *p, int new_value){
    //TODO
}
void update_bomb_collision(Player *p, enum bomb_collision bc){
    //TODO
}

//call the function corresponding of the right object
void get_object_player(Player *p, enum object_type ot){
    //TODO
}

void drop_bomb_player(Player *p){
    //TODO
}
