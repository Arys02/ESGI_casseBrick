//
// Created by Arys on 20/11/2022.
//

#ifndef ESGI_CASSEBRICK_IA_H
#define ESGI_CASSEBRICK_IA_H

#include "player_action.h"



Path init_path();

int has_safe_spot(Player *p, Board *b, int *x, int *y);
Path get_move_queue(Player *p, Board *b);
enum direction get_next_move(Player *p);
void ia_move(Player *p, Board *b);

Path get_path_rec(int x, int y, Board *b, Path path, int distance, enum direction dir);

enum direction get_random_valid_move(Player *p, Board *b);

int is_valid_move(Player *p, Board *b, enum direction dir);

#endif //ESGI_CASSEBRICK_IA_H
