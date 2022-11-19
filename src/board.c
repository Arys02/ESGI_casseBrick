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
    for (int i = 0; i < height; i++){
        for (int j = 0; j <width; j++){
            if (board[i][j]->kind_cell == PLAYER){
                char pname[256];
                itoa(x, pname, 10);
                nb_player[x] = build_player(pname, pname[0], nb_bomb);
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



void explosions_timer_all(int x, int y, Board *board, int exp_size){
    explosions_timer_left(x, y - 1, board, exp_size);
    explosions_timer_right(x, y + 1, board, exp_size);
    explosions_timer_up(x - 1, y , board, exp_size);
    explosions_timer_down(x + 1, y, board, exp_size);

}

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

void explosions_timer_up(int x, int y, Board *board, int exp_size){
    //explode left
    int count = 0;
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
    if(board->board[x][y]->kind_cell == WALL){
        board->board[x][y]->clock = TIMER;
    }
}

void update_all_clock(Board *b){
    for(int i = 0; i < b->height; i++){
        for(int j = 0; j < b->width; j++){
            if (b->board[i][j]->clock > -1){
                b->board[i][j]->clock--;
                if(b->board[i][j]->clock == 0){
                    printf("EXPLOSION");

                    if(b->board[i][j]->kind_cell == WALL){
                        update_cell(b->board[i][j], NULL, VOID);
                    }
                    if(b->board[i][j]->kind_cell == PLAYER){
                        //if(b->board)
                        //TODO check for defeat for player

                        update_cell(b->board[i][j], NULL, VOID);
                    }
                }

            }
        }
    }
   printf("\n") ;
}
