//
// Created by Arys on 17/10/2022.
//

#ifndef ESGI_CASSEBRICK_FILEREADER_H
#define ESGI_CASSEBRICK_FILEREADER_H

#include "cell.h"

extern int DEFAULT_BOMB_QUANTITY;

//should be called before building player to overwrite DEFAULT_BOMB_QUANITY
Cell ***board_from_file(char *file, int width, int height);

#endif //ESGI_CASSEBRICK_FILEREADER_H
