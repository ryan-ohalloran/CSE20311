// Ryan O'Halloran
// CSE 20311 - Lab 6
// Conway's Game of Life
// March 29th, 2021
// function file

#include <stdio.h>
#include <stdbool.h>
#include "lifefunc.h"

// interactive mode function to print out blank board and assign space values to the board
void print_board(char realBoard[boardSize][boardSize]) {
    printf("\n\n*");
    for (int i = 0; i < boardSize; i++) {
        printf("--");
    }
    printf("*\n");
    for (int i = 0; i < boardSize; i++) {
        printf("|");
        for (int j = 0; j < boardSize; j++) {
            printf("%c ", realBoard[i][j]);
        }
        printf("|\n");
    }
    printf("*");
    for (int i = 0; i < boardSize; i++) {
        printf("--");
    }
    printf("*\n");
}
// display all options to the user
void print_options(void) {
    printf("a (int) (int) to add a cell to the specified coordinate (between 0 and 39 for x and y)\n");
    printf("r (int) (int) to delete a cell from the specified coordinate (between 0 and 39 for x and y)\n");
    printf("n to move to the next iteration of the game\n");
    printf("q to quit\n");
    printf("p to play continuously\n");
}
// function to determine next iteration of game
char determine_cell(char temp[boardSize][boardSize], int row, int column) {
    int aliveNeighbors = 0, deadNeighbors = 0;
    // look around the temp board and determine number of live and/or dead neighbors
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // check to see where on the board the cell is and make sure it's not on an edge
            if (!((i == 0 && j == 0) || column + i >= boardSize || row + i >= boardSize || row + i < 0 || column + i < 0)) {
                if (temp[row + i][column + j] == ' ') { 
                    deadNeighbors++;    // increment number of deadNeighbors by 1 
                }
                if (temp[row + i][column + j] == 'X') {
                    aliveNeighbors++;   // incremement number of aliveNeighbors by 1
                }
            }
        }
    }
    // make a new cell if the cell is blank and has 3 neighbors
    if (temp[row][column] == ' ' && aliveNeighbors == 3) {
        return 'X';
    }
    // cell remains alive if it is alive and has 2 or 3 neighbors
    if (temp[row][column] == 'X' && (aliveNeighbors == 2 || aliveNeighbors == 3)) {
        return 'X';
    }
    // if cell doesn't have enough neghbors, it becomes or remains dead
    else {
        return ' ';
    }
}
// function to deploy next iteration of game
void next_iteration(char realBoard[boardSize][boardSize], char tempBoard[boardSize][boardSize]) {
    // loop through tempBoard and assign new values using determine_cell function
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            tempBoard[i][j] = determine_cell(realBoard, i, j);
        }
    }
    // loop through and assign all values of tempBoard to realBoard
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            realBoard[i][j] = tempBoard[i][j];
        }
    }
}
// function to create new live cell at specified location
void make_alive_cell(char realBoard[boardSize][boardSize], int tempX, int tempY) {
    realBoard[tempX][tempY] = 'X';
}
// function to create new dead cell at specified location
void make_dead_cell(char realBoard[boardSize][boardSize], int tempX, int tempY) {
    realBoard[tempX][tempY] = ' ';
}