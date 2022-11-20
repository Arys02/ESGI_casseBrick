//
// Created by Arys on 20/11/2022.
//

#include "../header/ia.h"


int has_safe_spot(Player *p, Board *b, int *x, int *y){

}


/**
 * It returns the shortest path to the nearest safe cell
 *
 * @param p the player
 * @param b the board
 *
 * @return The path with the least number of moves that is safe.
 */
Path get_move_queue(Player *p, Board *b){
    Path path = init_path();
    Path p1 = get_path_rec(p->pos_x, p->pos_y, b, path, 1, UP);
    Path p2 = get_path_rec(p->pos_x, p->pos_y, b, path, 1, DOWN);
    Path p3 = get_path_rec(p->pos_x ,p->pos_y, b, path, 1, LEFT);
    Path p4 = get_path_rec(p->pos_x, p->pos_y, b, path, 1, RIGHT);

    Path arr_p[4] = {p1, p2, p3, p4};
    int min = arr_p[0].nb_move;
    int min_i = 0;
    for(int i = 1; i < 4; i++){
        if (arr_p[i].is_safe == 1){
            if (arr_p[min_i].nb_move <= arr_p[i].nb_move && arr_p[min_i].is_safe){
                //min_i = i;
                //min = arr_p[i].nb_move;
            }
            else {
                min_i = i;
                min = arr_p[i].nb_move;
            }
        }

    }
    return arr_p[min_i];
}


/**
 * It returns the shortest path to a safe cell
 *
 * @param x the x coordinate of the current cell
 * @param y the y coordinate of the player
 * @param b the board
 * @param path the path we're currently exploring
 * @param distance the distance from the starting point
 * @param dir the direction we're coming from
 *
 * @return A path
 */
Path get_path_rec(int x, int y, Board *b, Path path, int distance, enum direction dir){
    switch(dir){
        case UP:
            x -= 1;
            break;
        case DOWN:
            x += 1;
            break;
        case LEFT:
            y -= 1;
            break;
        case RIGHT:
            y += 1;
            break;
        default:
            break;
    }
    outside_board(&x, &y, b); //we get destination coordinats
    Cell *c = b->board[x][y];
    if(c->kind_cell == WALL || c->kind_cell == UNBREAK || distance >= DIST_MAX || c->kind_cell == BOMB){
        return path;
    }
    if (c->clock == distance){
        return path;
    }
    path.nb_move = distance;
    path.dir[distance - 1] = dir;
    path.x = x;
    path.y = y;

    //on a trouvé un chemin safe, on s'arrête.
    if (c->clock == -1){
        path.is_safe = 1;
        return path;
    }
    Path p1 = get_path_rec(x, y, b, path, distance + 1, UP);
    Path p2 = get_path_rec(x, y, b, path, distance + 1, DOWN);
    Path p3 = get_path_rec(x ,y, b, path, distance + 1, LEFT);
    Path p4 = get_path_rec(x, y, b, path, distance + 1, RIGHT);

    Path arr_p[4] = {p1, p2, p3, p4};
    int min = arr_p[0].nb_move;
    int min_i = 0;
    for(int i = 1; i < 4; i++){
        if (arr_p[i].is_safe == 1){
            if (arr_p[min_i].nb_move <= arr_p[i].nb_move && arr_p[min_i].is_safe){
                //min_i = i;
                //min = arr_p[i].nb_move;
            }
            else {
                min_i = i;
                min = arr_p[i].nb_move;
            }
        }

    }
    return arr_p[min_i];
}


/**
 * It returns the next direction in the path, and removes it from the path
 *
 * @param p The player
 *
 * @return The next direction to move in.
 */
enum direction get_next_move(Player *p){
    for (int i = 0; i < DIST_MAX; i++){
       if (p->path.dir[i] != NONE_D){
           enum direction d = p->path.dir[i];
           p->path.dir[i] = NONE_D;
           return d;
       }
    }
    return NONE_D;
}


/**
 * It moves the player in the direction of the next move in the player's move list
 *
 * @param p the player
 * @param b the board
 *
 * @return 1 if the player has a move to do, 0 otherwise.
 */
int move_next_move(Player *p, Board *b){
    enum direction dir = get_next_move(p);
    if (dir != NONE_D){ //still has move to do
        player_move(p, b, dir);
        return 1;
    }
    return 0;
}


/**
 * move the IA player
 *
 * @param p the player
 * @param b the board
 *
 * @return a pointer to a queue.
 */
void ia_move(Player *p, Board *b){
    enum direction dir = get_next_move(p);
    if (dir != NONE_D){ //still has move to do
        printf("already a road to follow %d\n", dir);
        player_move(p, b, dir);
        return;
    }
    //current cell
    Cell *current_cell = b->board[p->pos_x][p->pos_y];
    if (current_cell->clock > 0 && current_cell->clock < 6){
        p->path = get_move_queue(p, b);
        move_next_move(p, b);
        printf("danger let's find le next move\n");
        return;
        //danger
        //defensive move
        //find safe place
    }
    else {

        int rng = rand() % 7;

        printf("sleep\n");
        if (rng == 1){
            drop_bomb_player(p, b);
        }
        else {
            enum direction rand_dir = get_random_valid_move(p, b);
            player_move(p, b, rand_dir);
        }

        //safe let's get agressive
        //if player or wall on explosion sight ->drop bomb
        //randomly move ? find the player ?
    }
}


/**
 * It checks if the player can move in the given direction
 *
 * @param p pointer to the player
 * @param b the board
 * @param dir the direction the player wants to move in
 *
 * @return 1 if the move is valid, 0 otherwise.
 */
int is_valid_move(Player *p, Board *b, enum direction dir){
    int dst_x = p->pos_x;
    int dst_y = p->pos_y;
    switch (dir) {
        case UP:
            dst_x -= 1;
            break;
        case DOWN:
            dst_x += 1;
            break;
        case LEFT:
            dst_y -= 1;
            break;
        case RIGHT:
            dst_y += 1;
            break;
        default:
            break;
    }
    outside_board(&dst_x, &dst_y, b); //we get destination coordinats
    if (b->board[dst_x][dst_y]->is_empty == 1){
        return 1;
    }


    return 0;
}


/**
 * It returns a random direction that is valid for the player to move in
 *
 * @param p The player
 * @param b The board
 *
 * @return The direction of the move.
 */
enum direction get_random_valid_move(Player *p, Board *b){
    int rng = rand() % 4;
    enum direction dir[4] = {UP, DOWN, RIGHT, LEFT};

    for(int i = 0; i < 4; i++){
        if (is_valid_move(p, b, dir[rng])){
           return dir[rng];
        }
        rng = (rng + 1) % 4;
    }
}
