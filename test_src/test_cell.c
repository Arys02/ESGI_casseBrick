//
// Created by Arys on 17/10/2022.
//
#include <stdio.h>
#include "../header/cell.h"

int main() {
    Cell *c = build_cell(PLAYER);

    printf("la cell : %c\n", c->c);
    free(c);
    return 0;
}
