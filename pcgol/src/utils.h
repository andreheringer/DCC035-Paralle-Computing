#pragma once
#include "board.h"
#include "cell.h"
#define len(x) (sizeof (x) / sizeof (*x))

typedef struct thread_arg {
    Board * t_board;
    cellState * t_cell_state_vec;
    int offset;
    int num_threads;
}Thread_arg;