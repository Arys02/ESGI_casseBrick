//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_CELL_H
#define ESGI_CASSEBRICK_CELL_H

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "bomb.h"
#include "object.h"


/* An enumeration of the different types of cells. */
enum kind_cell {
    PLAYER,
    BOMB,
    OBJECT,
    WALL,
    UNBREAK,
    VOID
};


/**
 * A Cell is a structure that contains a char, an int, an int, an enum, a void pointer and a void pointer.
 * @property {char} c - the character that will be displayed on the screen
 * @property {int} is_empty - 1 if the cell is empty, 0 if not
 * @property {int} is_destructible - 1 if the cell is destructible (wall), 0 if not
 * @property kind_cell - the kind of the cell (player, bomb, object, wall, empty)
 * @property {void} content - the content of the cell, can be a Player*, a Bomb* or an Object*
 * @property {void} tmp_content - used when a player drop a bomb, it's a pointer to the player who dropped the bomb.
 */
typedef struct {
    char c;
    int is_empty; // 1 if empty, 0 if not
    int is_destructible; // 1 if destructible (wall)
    enum kind_cell kind_cell;
    void *content; // can be a Player*, a Bomb* or an Object*
    void *tmp_content; //only used when a player drop a bomb
} Cell;

Cell *build_cell(enum kind_cell kc);
void free_cell(Cell *cell);
int update_cell(Cell *cell, void *new_content, enum kind_cell kc);
char get_char_cell(Cell *cell);

#endif //ESGI_CASSEBRICK_CELL_H
