#pragma once
#include <stdint-gcc.h>
#include <stdbool.h>
#include "cell.h"

typedef struct board
{
    int64_t x_axis;
    int64_t y_axis;
    cell *** data;
} Board;

//All functions that return a board ptr
Board * new_board(int64_t, int64_t);

//All functions that receive a board pointer
//void _render_board(Board * this_board);
void update_board_state(Board * this_board, cellState* living_cells);

//Cell state aux vector
cellState * new_cell_state_vec(int64_t size);

typedef struct thread_arg {
    Board* t_board;
    cellState* t_cell_state_vec;
    int offset;
    int num_threads;
} Thread_arg;