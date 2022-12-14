//
// Created by Arys on 17/10/2022.
//

#include "../header/board.h"

/**
 * It reads the file, creates a board, fills the board with the cells from the file, and then fills the player table with
 * the players from the file
 *
 * @param inb_player the number of players in the game
 * @param p the array of players
 * @param file the file to read from
 *
 * @return A pointer to a Board struct
 */
Board *build_board(int inb_player, Player **p, char *file){
    //making new board
    Board *new_board = malloc(sizeof (Board));
    int nb_bomb = 1;

    //reading nb bomb & height/width
    FILE *fp;
    fp = fopen(file, "r");
    if (!fp)
        return NULL;

    //getting our reading buffer ready
    char chunk[255];

    //getting first line
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }

    nb_bomb = atoi(chunk);

    //getting second line size & length
    if(fgets(chunk, sizeof(chunk), fp) == NULL){
        fclose(fp);
        return NULL;
    }

    char *first;
    char *second = strtok_r(chunk, " ", &first);

    new_board->height = atoi(first);
    new_board->width = atoi(second);
    //get Cell*** board
    new_board->board = board_from_file(file, new_board->width, new_board->height);

    int nb_player = count_nb_player(new_board->board, new_board->width, new_board->height);
    new_board->nb_player = nb_player;
    new_board->players = malloc(sizeof(Player*) * nb_player);

    fill_player_table(new_board->board, new_board->width, new_board->height, new_board->players, nb_bomb);

    fclose(fp);
    return new_board;
}


/**
 * It frees the memory allocated for the board
 *
 * @param b the board
 */
void free_board(Board *b){
    for(int i = 0; i < b->nb_player; i++){
        free(b->players[i]);
    }
    free(b->players);

    for(int i = 0; i < b->height; i++){
        for(int j = 0; j < b->width; j++){
            free(b->board[i][j]);
        }
        free(b->board[i]);
    }
    free(b->board);
    free(b);
}


//switch two cell
/**
 * It switches the contents of two cells
 *
 * @param b The board
 * @param src_x The x coordinate of the source cell
 * @param src_y The y coordinate of the source cell
 * @param dst_x The x coordinate of the destination cell
 * @param dst_y The y coordinate of the destination cell
 *
 * @return A pointer to a cell
 */
int switch_cell(Board *b, int src_x, int src_y, int dst_x, int dst_y){

    outside_board(&dst_x, &dst_y, b);

    Cell *tmp1 = get_cell(b, src_x, src_y);
    if (tmp1 && get_cell(b, dst_x, dst_y)){
        b->board[src_x][src_y] = b->board[dst_x][dst_y];
        b->board[dst_x][dst_y] = tmp1;
        return 1;
    }
    return 0;
}


/**
 * It returns a pointer to the cell at the given coordinates, or NULL if the coordinates are out of bounds
 *
 * @param b The board
 * @param x The x coordinate of the cell you want to get.
 * @param y the y coordinate of the cell
 *
 * @return A pointer to a Cell
 */
Cell *get_cell(Board *b, int x, int y){
    if (x < 0 || x >=  b->height || y < 0 || y >= b->width){
        return NULL;
    }

    return b->board[x][y];
}


/**
 * It counts the number of players on the board
 *
 * @param board the board
 * @param width the width of the board
 * @param height the height of the board
 *
 * @return The number of players on the board.
 */
int count_nb_player(Cell ***board, int width, int height){
     int count = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if (board[i][j]->kind_cell == PLAYER)
                count++;
        }
    }
    return count;
}


/**
 * It fills the player table with the players found on the board
 *
 * @param board the board
 * @param width the width of the board
 * @param height the height of the board
 * @param nb_player the array of players
 * @param nb_bomb the number of bombs the player can place
 */
void fill_player_table(Cell ***board, int width, int height, Player **nb_player, int nb_bomb){
    int x = 0;
    int first = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j <width; j++){
            if (board[i][j]->kind_cell == PLAYER){
                char pname[256];
                itoa(x, pname, 10);
                nb_player[x] = build_player(pname, pname[0], nb_bomb);
                if (first == 0){
                    nb_player[x]->kp = GAMER;
                    first = 1;
                }else{
                    nb_player[x]->kp = IA;
                }
                update_player_pos(nb_player[x], i, j);
                x++;
            }
        }
    }

}


/**
 * It prints the board
 *
 * @param board the board
 * @param width the width of the board
 * @param height the height of the board
 */
void print_board_cell(Cell ***board, int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Cell *c = board[i][j];
            if (c->kind_cell == PLAYER){
                //SDL.PRINT[RED SQUARE]
            }
            printf("%c", board[i][j]->c);
        }
        printf("\n");
    }
}


/**
 * If the destination is outside the board, then set the destination to the opposite side of the board
 *
 * @param dst_x the x coordinate of the destination
 * @param dst_y the y coordinate of the destination
 * @param b the board
 */
void outside_board(int *dst_x, int *dst_y, Board *b){
    if (*dst_x < 0 || *dst_x >=  b->height || *dst_y < 0 || *dst_y >= b->width){
        if (*dst_x < 0)
            *dst_x = b->height - 1;
        if (*dst_x >= b->height)
            *dst_x = 0;
        if (*dst_y < 0)
            *dst_y = b->width - 1;
        if (*dst_y >= b->width)
            *dst_y = 0;
    }

}



/**
 * It takes in a position, a board, and an explosion size, and then calls the other explosion timer functions on the four
 * directions
 *
 * @param x x coordinate of the explosion
 * @param y the y coordinate of the explosion
 * @param board the board that the explosion is on
 * @param exp_size the size of the explosion
 */
void explosions_timer_all(int x, int y, Board *board, int exp_size){
    explosions_timer_left(x, y - 1, board, exp_size);
    explosions_timer_right(x, y + 1, board, exp_size);
    explosions_timer_up(x - 1, y , board, exp_size);
    explosions_timer_down(x + 1, y, board, exp_size);
    board->board[x][y]->clock = TIMER;
}


/**
 * It set the timer for explosion in every direction
 *
 * @param x x coordinate of the bomb
 * @param y the y coordinate of the bomb
 * @param board the board
 * @param exp_size the size of the explosion
 */
void explosions_timer_left(int x, int y, Board *board, int exp_size){
   //explode left
   int count = 0;
   while(board->board[x][y]->kind_cell != WALL && board->board[x][y]->kind_cell != UNBREAK){
       outside_board(&x, &y, board);

       board->board[x][y]->clock = TIMER;
       y--;
        count++;
        if(count >= exp_size)
            break;
   };
   if(board->board[x][y]->kind_cell == WALL){
       board->board[x][y]->clock = TIMER;
   }
}


/**
 * It explodes the bomb in the right direction
 *
 * @param x x coordinate of the bomb
 * @param y the y coordinate of the bomb
 * @param board the board
 * @param exp_size the size of the explosion
 */
void explosions_timer_right(int x, int y, Board *board, int exp_size){
    //explode left
    int count = 0;
    while(board->board[x][y]->kind_cell != WALL && board->board[x][y]->kind_cell != UNBREAK){
        outside_board(&x, &y, board);

        board->board[x][y]->clock = TIMER;
        y++;
        count++;
        if(count >= exp_size)
            break;
    };
    if(board->board[x][y]->kind_cell == WALL){
        board->board[x][y]->clock = TIMER;
    }
}

/**
 * It checks if the cell is a wall or unbreakable block, if it is, it sets the timer to the value of the constant TIMER
 *
 * @param x the x coordinate of the bomb
 * @param y the y coordinate of the bomb
 * @param board the board
 * @param exp_size the size of the explosion
 */
void explosions_timer_up(int x, int y, Board *board, int exp_size){
    //explode left
    int count = 0;
    outside_board(&x, &y, board);
    while(board->board[x][y]->kind_cell != WALL && board->board[x][y]->kind_cell != UNBREAK){
        outside_board(&x, &y, board);

        board->board[x][y]->clock = TIMER;
        x--;
        count++;
        if(count >= exp_size)
            break;
    };
    if(board->board[x][y]->kind_cell == WALL){
        board->board[x][y]->clock = TIMER;
    }
}


/**
 * It takes in the x and y coordinates of the bomb, the board, and the explosion size, and then it explodes the bomb to the
 * left
 *
 * @param x x coordinate of the bomb
 * @param y the y coordinate of the bomb
 * @param board the board
 * @param exp_size the size of the explosion
 */
void explosions_timer_down(int x, int y, Board *board, int exp_size){
    //explode left
    int count = 0;
    while(board->board[x][y]->kind_cell != WALL && board->board[x][y]->kind_cell != UNBREAK){
        outside_board(&x, &y, board);

        board->board[x][y]->clock = TIMER;
        x++;
        count++;
        if(count >= exp_size)
            break;
    };
    outside_board(&x, &y, board);
    if(board->board[x][y]->kind_cell == WALL){
        board->board[x][y]->clock = TIMER;
    }
}

/**
 * It updates the clock of all the cells of the board
 * and manage explosion, kills player and break walls
 * @param b the board
 */
void update_all_clock(Board *b){
    update_clock_players_board(b);
    for(int i = 0; i < b->height; i++){
        for(int j = 0; j < b->width; j++){
            if (b->board[i][j]->clock > -1){
                b->board[i][j]->clock--;
                if(b->board[i][j]->clock == 0){
                    printf("EXPLOSION");

                    //BREAK THE WALL
                    if(b->board[i][j]->kind_cell == WALL){
                        int a = rand() % 10;
                        if (a < 2){
                            enum object_type *ot = get_rand_ot();
                            update_cell(b->board[i][j], ot, OBJECT);
                        }
                    }
                    //KILL THE PLAYER
                    if(b->board[i][j]->kind_cell == PLAYER){

                        //TODO check object for protection or life
                        Player *p = (Player *)b->board[i][j]->content;
                        if (p->immunity_clock <= 0 && p->has_heart == 0 && p->life == 1){
                            if(p->kp ==GAMER){
                                printf("PERDU\n");
                                exit(1);
                            }
                            else{
                                p->is_dead = 1;
                            }
                            update_cell(b->board[i][j], NULL, VOID);
                        }
                        else {
                            if (p->immunity_clock > 0){}
                            else if (p->has_heart){
                                p->has_heart = -1;
                            }
                            else {
                                p->life--;
                            }
                        }

                    }
                    //THE BOMB DISAPEAR
                    if (b->board[i][j]->kind_cell == BOMB){
                        ((Bomb*)b->board[i][j]->content)->clock = -1; // the bomb return in the inventory
                        update_cell(b->board[i][j], NULL, VOID);
                    }
                }

            }
        }
    }
   printf("\n") ;
}

/**
 * It updates the clock of the players
 *
 * @param b the board
 */
void update_clock_players_board(Board *b){
    update_clocks_players(b->players, b->nb_player);
}