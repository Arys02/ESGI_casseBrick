//
// Created by Arys on 19/11/2022.
//

#include <stdio.h>
#include <conio.h>
#include <pthread_time.h>
#include <unistd.h>
//#include <windows.h>
#include "../header/player_action.h"

int main() {
    Board *b = build_board(1, NULL, "../map/map_3_collision");

    while(1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_board_cell(b->board, b->width, b->height);
        int frappe = 'e';
        if(kbhit())
        {
            frappe=getch();
            if (frappe == 'b'){
                break;
            }
             if (frappe == 'p'){
                 printf("\n UP \n");
                 player_move(b->players[0], b, UP);
            }
              if (frappe == 'e'){
                 printf("\n RIGHT \n");
                 player_move(b->players[0], b, RIGHT);
                // player_move_right(b->players[0], b);
            }
              if (frappe == 'u'){
                 printf("\n LEFT \n");
                  player_move(b->players[0], b, LEFT);
                 //player_move_left(b->players[0], b);
            }
              if (frappe == 'i'){
                 printf("\n DOWN \n");
                  player_move(b->players[0], b, DOWN);
                 //player_move_down(b->players[0], b);
            }
        }
        //Sleep(500);
        usleep(500 * 1000);

        printf("\n\n");


    }

    free_board(b);
    return 0;
}
