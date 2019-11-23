#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint-gcc.h>
#include <pthread.h>
#include "utils.h"
#include "cell.h"
#include "board.h"

void _link_board(Board * this_board) {

    for (int64_t i = 0; i < this_board->y_axis; i++) {

        for (int64_t j = 0; j < this_board->x_axis; j++) {
            set_cell_hood(this_board->data[i][j], i-1 > 0 ? this_board->data[i-1][j] : NULL, 0);

            set_cell_hood(this_board->data[i][j], (i-1 > 0 && 
                                                  j+1 < this_board->x_axis) ? this_board->data[i-1][j+1] : NULL, 1);

            set_cell_hood(this_board->data[i][j], j+1 < this_board->x_axis ? this_board->data[i][j+1] : NULL, 2);

            set_cell_hood(this_board->data[i][j], (i+1 < this_board->y_axis &&
                                                   j+1 < this_board->x_axis) ? this_board->data[i+1][j+1] : NULL, 3);

            set_cell_hood(this_board->data[i][j], i+1 < this_board->y_axis ? this_board->data[i+1][j] : NULL, 4);

            set_cell_hood(this_board->data[i][j], (i+1 < this_board->y_axis && 
                                                   j-1 > 0) ? this_board->data[i+1][j-1] : NULL, 5);

            set_cell_hood(this_board->data[i][j], j-1 > 0 ? this_board->data[i][j-1] : NULL, 6);

            set_cell_hood(this_board->data[i][j], j-1 > 0 && i-1 > 0 ? this_board->data[i-1][j-1] : NULL, 7);
        }

    }

}

cellState * new_cell_state_vec(int64_t size) {
    cellState* alive_cells = (cellState *)malloc(size * sizeof(cellState));
    return alive_cells;
}


Board * new_board(int64_t x_axis, int64_t y_axis) {

    Board * this_board = (Board *) calloc(1, sizeof(Board));

    this_board->x_axis = x_axis;
    this_board->y_axis = y_axis;
    this_board->data = (cell ***)calloc(this_board->y_axis, sizeof(cell**));

    for (int i = 0; i < this_board->y_axis ; i++) {
        this_board->data[i] = (cell **)calloc(this_board->x_axis, sizeof(cell*));
    }

    for (int64_t i = 0; i < this_board->y_axis; i++) {
        
        for (int64_t j = 0; j < this_board->x_axis; j++) {
            this_board->data[i][j] = new_cell(j, i);
        }

    }

    _link_board(this_board);

    return this_board;
}

void _render_board(Board * this_board) {

    for (int64_t i = 0; i < this_board->y_axis; i++) {
        
        for (int64_t j = 0; j < this_board->x_axis; j++) {
            printf("%s", get_cell_state(this_board->data[i][j]) ? "[x]" : "[ ]");
        }
        
        printf("\n");
    }

}

void _kill_all(cellState* cells, int size) {
    for (int i = 0; i < size; i++) {
        cells[i] = DEAD;
    }
}

void _compute_next_board_state(Board * this_board, cellState* alive_cells) {

    _kill_all(alive_cells, this_board->x_axis*this_board->x_axis);

    //paralelismo
    int num_threads = 2;
    pthread_t t[num_threads];

    for (int64_t i = 0; i < this_board->y_axis; i++) {
        for (int64_t j = 0; j < this_board->x_axis; j++) {
            Thread_arg* t_arg = (Thread_arg *)malloc(sizeof(Thread_arg));
            t_arg->this_board = this_board;
            t_arg->alive_cell = alive_cells[i*this_board->x_axis + j];
            t_arg->i = i;
            t_arg->j = j;

            printf("cell value: %d, thread: %ld\n", alive_cells[i*this_board->x_axis + j],
                                                    (i*this_board->x_axis + j)%num_threads);
            pthread_create(&t[(i*this_board->x_axis + j)%num_threads],
                            NULL,
                            parallel_rules,
                            (void*) t_arg);
        }
    }

    for (int64_t i = 0; i < this_board->y_axis; i++) {
        for (int64_t j = 0; j < this_board->x_axis; j++) {
            void* return_aux;
            pthread_join(t[(i*this_board->x_axis + j)%num_threads], &return_aux);
            alive_cells[i*this_board->x_axis + j] = (cellState)return_aux;
        }
    }

    return;
}

void update_board_state(Board * this_board, cellState* living_cells) {
    _compute_next_board_state(this_board, living_cells);
    for (int64_t i = 0; i < this_board->x_axis*this_board->x_axis; i++) {
        int64_t cur_cell_y = i / this_board->y_axis;
        int64_t cur_cell_x = i % this_board->x_axis;
        set_cell_state(this_board->data[cur_cell_y][cur_cell_x], living_cells[i]);
    }
}

void* parallel_rules(void* arg){
    Thread_arg * t_arg = (Thread_arg *)arg;
    free(arg);

    int8_t living_hood = num_cell_hood(t_arg->this_board->data[t_arg->i][t_arg->j]);

    if (get_cell_state(t_arg->this_board->data[t_arg->i][t_arg->j]) == ALIVE) {
        if (living_hood == 2 || living_hood == 3) {
            t_arg->alive_cell = ALIVE;
        }
    }
    else {
        if (living_hood == 3) {
            t_arg->alive_cell = ALIVE;
        }
    }

    return (void *)t_arg->alive_cell;
}