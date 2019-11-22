#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint-gcc.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "cell.h"
#include "board.h"
#include "display.h"
//#include "rules.h"

/*
    Dependencias:
    1. OpenGL libraries:
    $ sudo apt-get install mesa-utils
    2. freeGlut:
    $ sudo apt-get install freeglut3-dev
*/

int main(int argc, char *argv[]) {
    int64_t auz = (int64_t) atoi(argv[1]);
    printf("Yo, here a board...\n");
    Board * aBoard = new_board(auz, auz);
    cellState* cell_state_vec = new_cell_state_vec(auz*auz);
    //render_board(aBoard);

    glutInit(&argc, argv);
    displayInit(aBoard);
    glutMainLoop();

    return 0;
}
