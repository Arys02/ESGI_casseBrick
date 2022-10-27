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

enum kind_cell {
    PLAYER,
    BOMB,
    OBJECT,
    WALL,
    UNBREAK,
    VOID
};

typedef struct {
    char c;
    int is_empty; // 1 if empty, 0 if not
    int is_destructible; // 1 if destructible (wall)
    enum kind_cell kind_cell;
    void *content; // can be a Player*, a Bomb* or an Object*
} Cell;

Cell *build_cell(enum kind_cell kc);
void free_cell(Cell *cell);
int update_cell(Cell *c, void *new_content, enum kind_cell kc);
char get_char_cell(Cell *cell);

#endif //ESGI_CASSEBRICK_CELL_H
