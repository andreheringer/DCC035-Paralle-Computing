#include <mpi.h>
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
    Dependencias interface gráfica (openGL):
    1. OpenGL libraries:
    $ sudo apt-get install mesa-utils
    2. freeGlut:
    $ sudo apt-get install freeglut3-dev
*/

int main(int argc, char *argv[]) {
    int64_t auz = (int64_t) atoi(argv[1]);
    
    Board * aBoard = new_board(auz, auz);
    cellState* cell_state_vec = new_cell_state_vec(auz*auz);
    
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size > 2) {
        printf("Nope, cant build a board this big :P");
        return 1;
    }
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    
    //render_board(aBoard);

    // glutInit(&argc, argv);
    // displayInit(aBoard, cell_state_vec);
    // glutMainLoop();
    MPI_Finalize();
    return 0;
}
