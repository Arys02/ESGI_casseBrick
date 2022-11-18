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


/* An enumeration of the possible collision types that a player can have with a bomb. */
enum bomb_collision {
    NONE,
    PASS,
    KICK
};


/**
 * A player has a name, a symbol, life, bomb range, bomb quantity, position, inventory, heart, immunity clock, and bomb
 * collision.
 * @property {char} name - The name of the player
 * @property {char} symbol - The character that will be displayed on the map.
 * @property {int} life - the number of lives the player has
 * @property {int} bomb_range - the range of the bomb
 * @property {int} bomb_quantity - the number of bombs the player can place at a time
 * @property {int} pos_x - the x coordinate of the player
 * @property {int} pos_y - the y coordinate of the player
 * @property {Bomb} Inventory - An array of pointers to bombs.
 * @property {int} has_heart - if the player has a heart, he can't be killed by a bomb
 * @property {int} immunity_clock - This is a clock that counts down to 0. When it reaches 0, the player is no longer
 * immune to bombs.
 * @property bc - This is a variable that is used to determine if the player has a collision object with a bomb.
 */
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
