#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "display.h"
#include "board.h"

board* this_board;
int cellSize;

void displayInit(board * aux_board){
    this_board = aux_board;
    cellSize = 400/this_board->x_axis; //trocar 400 por tamanho da tela (?)

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jogo da Vida de Conway");
    glutDisplayFunc(drawBoard);
    glutTimerFunc(1000, timer, 0);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawBoard(){
    glClear(GL_COLOR_BUFFER_BIT);

    srand(time(NULL));
    float r = (float)(rand() % 100) / 100;

    glColor3f(0.2, 0.8, r);
    glPointSize(1.0);

    for (int i = 0; i < this_board->y_axis; i++) {
        for (int j = 0; j < this_board->x_axis; j++) {
            int r = rand() % 100;
            if(r % 2 == 0){
                set_cell_state(this_board->data[j][i], ALIVE);
            } else {
                set_cell_state(this_board->data[j][i], DEAD);
            }
        }
    }

    for (int i = 0; i < this_board->y_axis; i++) {
        for (int j = 0; j < this_board->x_axis; j++) {
            drawCell(130 + j*cellSize, 50 + i*cellSize, get_cell_state(this_board->data[i][j]) ? true : false);
        }
    }

    //glFlush();
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

void timer(){
    glutPostRedisplay();
    //printf("called\n");
    glutTimerFunc(1000/60, timer, 0);
}