//
// Created by Arys on 19/11/2022.
//

#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "../header/player_action.h"

int main() {
    Board *b = build_board(1, NULL, "../map/map_3_collision");

    while(1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_board_cell(b->board, b->width, b->height);
        int frappe;
        if(kbhit()){
            frappe=getch();
            if (frappe == 'b'){
                break;
            }
             if (frappe == 'p'){
                 printf("\n p pressed \n");
            }
        }
        sleep(1);

        printf("\n\n");


    }

    free_board(b);
    return 0;
}
