#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "display.h"
#include "board.h"

#define BOARD_SIZE 400
#define SHIFT_X 130
#define SHIFT_Y 50
#define FPS 2

board* this_board;
int cellSize;

void displayInit(board * aux_board){
    this_board = aux_board;
    cellSize = BOARD_SIZE/this_board->x_axis;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jogo da Vida de Conway");
    glutDisplayFunc(drawBoard);
    glutTimerFunc(1000, update, 0);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawBoard(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2, 0.8, 0.8);
    glPointSize(1.0);

    //desenha o board
    for (int i = 0; i < this_board->y_axis; i++) {
        for (int j = 0; j < this_board->x_axis; j++) {
            //constrói o board de baixo pra cima.
            //mudar caso necessário
            drawCell(SHIFT_X + j*cellSize, SHIFT_Y + i*cellSize, get_cell_state(this_board->data[i][j]) ? true : false);
        }
    }

    glutSwapBuffers();
}

void drawCell(int x, int y, bool active){
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

void update(){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, update, 0);
}