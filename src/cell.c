//
// Created by Arys on 17/10/2022.
//

#include "../header/cell.h"


/**
 * It builds a cell
 *
 * @param kc the kind of cell you want to build
 *
 * @return A pointer to a cell
 */
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
            new_cell->is_empty = 1;
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
            break;
        case UNBREAK:
            new_cell->c = 'x';
            new_cell->is_empty = 0;
            new_cell->is_destructible = 0;
            break;
        default:
            break;
    }

    new_cell->clock = -1;
    new_cell->tmp_content = NULL;
    new_cell->content=NULL;


    return new_cell;
}

/**
 * It frees the memory allocated to a cell
 *
 * @param cell The cell to free.
 */
void free_cell(Cell *cell){
    free(cell);
}

/**
 * It updates the cell's content, and changes the cell's properties according to the kind of cell
 *
 * @param cell the cell to update
 * @param new_content the new content of the cell
 * @param kc Kind of cell, which is an enum.
 *
 * @return an integer.
 */
int update_cell(Cell *cell, void *new_content, enum kind_cell kc){
     switch(kc) {
         case PLAYER:
             cell->c = 'p';
             cell->is_empty = 0;
             cell->is_destructible = 1;
             break;
         case BOMB:
             cell->c = 'b';
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

/**
 * Get_char_cell returns the char value of a cell.
 *
 * @param cell The cell to get the character from.
 *
 * @return A character.
 */
char get_char_cell(Cell *cell){
    return cell->c;
}