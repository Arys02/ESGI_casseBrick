//
// Created by Arys on 17/10/2022.
//

#include "../header/filereader.h"
#include <stdio.h>
#include <string.h>
#include "../header/cell.h"


int DEFAULT_BOMB_QUANTITY = 1;



/**
 * It reads a file and returns a Cell *** (a 2D array of Cell*)
 *
 * @param file the file to read from
 * @param width the width of the board
 * @param height the height of the board
 *
 * @return A pointer to a pointer to a pointer to a Cell.
 */
Cell ***board_from_file(char *file, int width, int height){
    //opening the file
    FILE *fp;
    fp = fopen(file, "r");
    if (!fp)
        return NULL;

    //getting our reading buffer ready
    char chunk[255];

    //skipping first and second line
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }

    //BUILDING OUR CELLARRAY
    Cell ***new_array_cell = malloc(sizeof(Cell **) * height);
    for(int x = 0; x < width; x++){
        new_array_cell[x] = malloc(sizeof(Cell*) * width);
    }

    int i = 0;
    while (fgets(chunk, sizeof(chunk), fp) != NULL){
        for(int j = 0; j < width; j++){
           switch(chunk[j]){
               case 'x':
                   new_array_cell[i][j] = build_cell(UNBREAK);
                   break;
               case 'm':
                   new_array_cell[i][j] = build_cell(WALL);
                   break;
               case 'p':
                   new_array_cell[i][j] = build_cell(PLAYER);
                   break;
               case ' ':
                   new_array_cell[i][j] = build_cell(VOID);
                   break;
               default:
                   new_array_cell[i][j] = build_cell(UNBREAK);
           }
        }
        i++;
    }
    fclose(fp);
    return new_array_cell;
}
