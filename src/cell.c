//
// Created by Arys on 17/10/2022.
//

#include "../header/cell.h"

/**
 *
 *
enum kind_cell {
    PLAYER,
    BOMB,
    OBJECT,
    WALL,
    VOID
};

typedef struct {
    char c;
    int is_empty; // 1 if empty, 0 if not
    int is_destructible; // 1 if destructible (wall)
    enum kind_cell kind_cell;
    void *content; // can be a Player*, a Bomb* or an Object*
} Cell;
 * */

Cell *build_cell(enum kind_cell kc){
    Cell *new_cell = malloc(sizeof(Cell));
    new_cell->kind_cell = kc;
    switch(kc){
        case PLAYER:
            new_cell->c = 'p';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
            break;
        case BOMB:
            new_cell->c = 'b';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
            break;
        case OBJECT:
            new_cell->c = 'o';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
            break;
        case WALL:
            new_cell->c = 'w';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
            break;
        case VOID:
            new_cell->c = ' ';
            new_cell->is_empty = 1;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
        case UNBREAK:
            new_cell->c = 'u';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 0;
            new_cell->content = NULL;
            break;
    }


    return new_cell;
}
void free_cell(Cell *cell){
    free(cell);
}
int update_cell(void *new_content, enum kind_cell){
    //TODO
    return 0;
}
char get_char_cell(Cell *cell){
    //TODO
    return '0';
}
