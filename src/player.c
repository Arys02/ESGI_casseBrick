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
    new_player->is_dead = 0;
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
void update_clock_player(Player *p){
    if (p->immunity_clock > 0)
        p->immunity_clock--;
}


void update_clocks_players(Player **players, int nb_players){
    for(int i = 0; i < nb_players; i++){
        update_clock_player(players[i]);
    }
}


void update_bomb_quantity_player(Player *p, int new_value){
    if (new_value < 10 && new_value > 0){
        p->bomb_quantity = new_value;
    }
}


//call the function corresponding of the right object
void get_object_player(Player *p, enum object_type ot){
    switch(ot){
        case B_UP:
            update_bomb_quantity_player(p, p->bomb_quantity + 1);
            break;
        case B_DOWN:
            update_bomb_quantity_player(p, p->bomb_quantity - 1);
            break;
        case F_YELLOW:
            p->bomb_range++;
            break;
        case F_BLUE:
            p->bomb_range = p->bomb_range - 1 > 1 ? p->bomb_range - 1 : p->bomb_range;
            break;
        case F_RED:
            p->bomb_range = BOMB_MAX_RANGE;
            break;
        case PASS_BOMB:
            p->bc = PASS;
            break;
        case KICK_BOMB:
            p->bc = KICK;
            break;
        case INV:
            p->immunity_clock = IMMUNITY_TIME;
            break;
        case HEART:
            p->has_heart = p->has_heart != -1 ? 1 : -1;
            break;
        case HP_UP:
            break;
    }
}

void display_player_inf(Player *p){
    printf("\n");
    printf("name    : %s \n", p->name);
    printf("symbol  : %c \n", p->symbol);
    printf("life    : %d\n", p->life);
    printf("range   : %d, nb_bomb : %d\n", p->bomb_range, p->bomb_quantity);
    printf("pos   : %d,%d\n", p->pos_x, p->pos_y);
    printf("- Object -\n");
    printf("has heart : %d\n", p->has_heart);
    printf("immunity clock : %d\n", p->immunity_clock);
    printf("collision : %d\n", p->bc);
}