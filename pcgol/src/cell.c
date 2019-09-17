#include <stdlib.h>
#include <stdbool.h>
#include <stdint-gcc.h>
#include "cell.h"

cell * new_cell(int64_t pos_x, int64_t pos_y) {
    cell * this_cell = (cell *)calloc(1, sizeof(cell));
    this_cell -> pos_x = pos_x;
    this_cell -> pos_y = pos_y;
    this_cell -> state  = DEAD;
    return this_cell;
}

void set_cell_state(cell * this_cell, cellState state) {
    this_cell -> state = state; 
}

cellState get_cell_state(cell * this_cell) {
    return this_cell -> state;
}

cell * get_cell_hood(cell * this_cell, int_fast8_t hood_pos) {
    return this_cell->hood[hood_pos];
}

void set_cell_hood(cell * this_cell, cell * hood_cell, int_fast8_t hood_pos) {
    this_cell->hood[hood_pos] = hood_cell;
}
