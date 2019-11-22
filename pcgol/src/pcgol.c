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

int main(int argc, char *argv[]) {
    int_fast64_t auz = (int_fast64_t) atoi(argv[1]);
    printf("Yo, here a board...\n");
    board * aBoard = new_board(auz, auz);
    //render_board(aBoard);

    glutInit(&argc, argv);
    displayInit(aBoard);
    glutMainLoop();

    return 0;
}
