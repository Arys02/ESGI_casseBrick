#include <stdio.h>
#include <conio.h>
#include "header/ia.h"
#include "header/board.h"

int main() {
    printf("Hello, World!\n");

    Board *b = build_board(1, NULL, "../map/map_2");



    int frappe;
    while(1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        display_player_inf(b->players[0]);
        print_board_cell(b->board, b->width, b->height);
        frappe = getch();
        if (frappe == 'b') {
            break;
        }
        if (frappe == 'z') {
            printf("\n UP \n");
            player_move(b->players[0], b, UP);
        }
        if (frappe == 'd') {
            printf("\n RIGHT \n");
            player_move(b->players[0], b, RIGHT);
        }
        if (frappe == 'q') {
            printf("\n LEFT \n");
            player_move(b->players[0], b, LEFT);
        }
        if (frappe == 's') {
            printf("\n DOWN \n");
            player_move(b->players[0], b, DOWN);
        }
        if (frappe == ' ') {
            printf("\n BOMB \n");
            drop_bomb_player(b->players[0], b);
        }


        for (int i = 1; i < b->nb_player; i++)
            ia_move(b->players[i], b);
        update_all_clock(b);
        printf("\n\n");
    }




    free_board(b);
    return 0;
}
