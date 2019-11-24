#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "display.h"
#include "board.h"

//altura e largura da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//taxa em que o board é desenhado na tela (frames por segundo)
#define FPS 5

//declaração global do board pois a função de display não aceita parâmetros
Board* glob_board;
cellState* glob_cell_state_vec;
int cellSize;

void displayInit(Board * aux_board, cellState * aux_cell_state_vec) {
    glob_board = aux_board;
    glob_cell_state_vec = aux_cell_state_vec;
    cellSize = WINDOW_HEIGHT/glob_board->y_axis;

    //preenche estado inicial do board aleatoriamente
    fillBoard();

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Jogo da Vida de Conway");
    glutDisplayFunc(drawBoard);
    glutTimerFunc(1000, refresh, 0);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT);

    //cor do board (rgb)
    glColor3f(0.2, 0.8, 0.8);
    glPointSize(1.0);

    //desenha o board
    //actually pode até ser paralelisado
    for (int i = 0; i < glob_board->y_axis; i++) {
        for (int j = 0; j < glob_board->x_axis; j++) {
            drawCell((WINDOW_WIDTH - WINDOW_HEIGHT)/2 + WINDOW_HEIGHT%glob_board->y_axis/2 + j*cellSize,
                     WINDOW_HEIGHT - (WINDOW_HEIGHT%glob_board->y_axis/2 + (i+1)*cellSize),
                     get_cell_state(glob_board->data[i][j]) ? true : false);
        }
    }

    glutSwapBuffers();
}

void drawCell(int x, int y, bool active) {
    if(active){
        glBegin(GL_POLYGON);
    } else {
        glBegin(GL_LINE_LOOP);
    }
    glVertex2i(x, y);
    glVertex2i(x, y + cellSize);
    glVertex2i(x + cellSize, y + cellSize);
    glVertex2i(x + cellSize, y);
    glEnd();
}

void refresh(){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, refresh, 0);

    update_board_state(glob_board, glob_cell_state_vec);
}

void fillBoard(){
    srand(time(NULL));
    for (int i = 0; i < glob_board->y_axis; i++) {
        for (int j = 0; j < glob_board->x_axis; j++) {
            int r = rand() % 100;
            if(r < 40){
                set_cell_state(glob_board->data[i][j], ALIVE);
            } else {
                set_cell_state(glob_board->data[i][j], DEAD);
            }
        }
    }
}