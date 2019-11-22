#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint-gcc.h>
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

cellState* compute_next_board_state(Board * this_board) {
    cellState* alive_cells;
    alive_cells = (cell *)calloc(this_board->x_axis*this_board->x_axis, sizeof(cellState));
    

    for (int64_t i = 0; i < this_board->y_axis; i++) {
        for (int64_t j = 0; j < this_board->x_axis; j++) {
            
            int8_t living_hood = num_cell_hood(this_board->data[i][j]);
            
            if (get_cell_state(this_board->data[i][j]) == ALIVE) {
                if (living_hood == 2 || living_hood == 3) {
                    alive_cells[i*this_board->x_axis + j] = ALIVE;
                }
            }
            else {
                if (living_hood == 2 || living_hood == 3) {
                    alive_cells[i*this_board->x_axis + j] =ALIVE;
                }
            }
        }
    }

    return alive_cells;
}

void update_board_state(Board * this_board) {

    cellState* living_cells = compute_next_board_state(this_board);
    
    for (int64_t i = 0; i < len(living_cells); i++) {
        
        int64_t cur_cell_y = i / this_board->y_axis;
        int64_t cur_cell_x = i % this_board->x_axis;
        
        if (living_cells[i] != NULL) {
            set_cell_state(this_board->data[cur_cell_y][cur_cell_x], living_cells[i]);
        }
    }
    
}
