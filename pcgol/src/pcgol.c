#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint-gcc.h>
#include "cell.h"
#include "board.h"
//#include "rules.h"

int main(int argc, char const *argv[]) {
    int_fast64_t auz = (int_fast64_t) atoi(argv[1]);
    printf("Yo, here a board...\n");
    board * aBoard = new_board(auz, auz);
    render_board(aBoard);
    return 0;
}
