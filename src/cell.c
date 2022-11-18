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
            break;
        case BOMB:
            new_cell->c = '*';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            break;
        case OBJECT:
            new_cell->c = 'o';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            break;
        case WALL:
            new_cell->c = 'w';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 1;
            break;
        case VOID:
            new_cell->c = ' ';
            new_cell->is_empty = 1;
            new_cell->is_destructible = 1;
            new_cell->content = NULL;
        case UNBREAK:
            new_cell->c = 'x';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 0;
            break;
        default:
            break;
    }

    new_cell->tmp_content = NULL;
    new_cell->content=NULL;


    return new_cell;
}
void free_cell(Cell *cell){
    free(cell);
}

int update_cell(Cell *cell, void *new_content, enum kind_cell kc){
     switch(kc) {
         case PLAYER:
             cell->c = 'p';
             cell->is_empty = 0;
             cell->is_destructible = 1;
             break;
         case BOMB:
             cell->c = '*';
             cell->is_empty = 0;
             cell->is_destructible = 1;
             cell->tmp_content = cell->content;
             break;
         case OBJECT:
             cell->c = 'o';
             cell->is_empty = 0;
             cell->is_destructible = 1;
             break;
         case WALL:
             cell->c = 'w';
             cell->is_empty = 0;
             cell->is_destructible = 1;
             break;
         case VOID:
             cell->c = ' ';
             cell->is_empty = 1;
             cell->is_destructible = 1;
         case UNBREAK:
             cell->c = 'x';
             cell->is_empty = 0;
             cell->is_destructible = 0;
             break;
         default:
             return 0;
             break;
     }
     cell->content = new_content;
     return 1;
}
char get_char_cell(Cell *cell){
    return cell->c;
}