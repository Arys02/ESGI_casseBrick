//
// Created by Arys on 17/10/2022.
//

#include "../header/player.h"
//#include "../header/filereader.h"




/**
 * It builds a player
 *
 * @param name The name of the player
 * @param symbol The character that will be used to represent the player on the map.
 *
 * @return A pointer to a Player struct
 */
Player *build_player(char *name, char symbol, int bomb_quantity){
    Player *new_player = malloc(sizeof(Player));
    new_player->Inventory = malloc((sizeof(Bomb*) * MAX_BOMB));
    for(int i = 0; i < MAX_BOMB; i++){
        new_player->Inventory[i] = build_bomb();
    }

    new_player->name = name;
    new_player->symbol = symbol;
    new_player->life = 1;
    new_player->bomb_range = DEFAULT_BOMB_RANGE;
    new_player->bomb_quantity = bomb_quantity;
    new_player->pos_y = -1;
    new_player->pos_x = -1;

    new_player->has_heart = 0;
    new_player->immunity_clock = 0;
    new_player->bc = NONE;
    return new_player;
}

/**
 * It frees the memory allocated for the player's inventory and then frees the memory allocated for the player
 *
 * @param p The player to be freed
 */
void free_player(Player *p){
    for(int i = 0; i < p->bomb_quantity; i++){
        free(p->Inventory[i]);
    }
    free(p);
}

/**
 * It updates the player's position
 *
 * @param p The player object
 * @param x The x position of the player
 * @param y The y coordinate of the player
 */
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
