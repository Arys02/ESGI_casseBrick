//
// Created by Arys on 17/10/2022.
//
#include <stdio.h>
#include "../header/player.h"

int main() {
    Player *p = build_player("toto", 'a');
    printf("%s \n", p->name);
    printf("Hello, World!\n");
    free_player(p);
    return 0;
}
