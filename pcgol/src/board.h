#pragma once
#include <stdint-gcc.h>
#include <stdbool.h>
#include "cell.h"

typedef struct board
{
    int64_t x_axis;
    int64_t y_axis;
    cell *** data;

}board;

//All functions that return a board ptr
board * new_board(int64_t, int64_t);


//All functions that receive a board pointer
void render_board(board * this_board);
void update_board(board * this_board, cell ** living_cells);