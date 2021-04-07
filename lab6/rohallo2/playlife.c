// Ryan O'Halloran
// CSE 20311 - Lab 6
// Conway's Game of Life
// March 29th, 2021
// main file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lifefunc.h"

int main(int argc, char *argv[]) {
    char realBoard[boardSize][boardSize], tempBoard[boardSize][boardSize];

    // initialize both boards to all spaces
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            realBoard[i][j] = ' ';
            tempBoard[i][j] = ' ';
        }
    }
    // main logic dependent upon number of command line arguments
    switch (argc) {
    case 1 : {
        // interactive mode
        printf("Interactive mode:\n");
        int tempX = -1, tempY = -1;
        char inputStr[2], uChoice = '\0';
        while (uChoice != 'q' && uChoice != 'p') {
            // tell user their options
            print_options();
            // take user input
            printf("Enter Command ---> ");
            scanf("%s", inputStr);
            // exit if more than one letter entered
            if (strlen(inputStr) >= 2) { puts("Invalid command! Re-start program."); return 1; }
            uChoice = inputStr[0];

            switch (uChoice) {
                case 'a' : 
                    // add specified cell
                    scanf("%d %d", &tempX, &tempY);
                    if (tempX < 0 || tempX >= boardSize || tempY < 0 || tempY >= boardSize) {
                        printf("Entry out of bounds. Try again.\n");
                        break;
                    }
                    make_alive_cell(realBoard, tempX, tempY);
                    print_board(realBoard);
                    break; 
                
                case 'r' :
                    // remove a specified cell
                    scanf("%d %d", &tempX, &tempY);
                    if (tempX < 0 || tempX >= boardSize || tempY < 0 || tempY >= boardSize) {
                        printf("Entry out of bounds. Try again.\n");
                        break;
                    }
                    make_dead_cell(realBoard, tempX, tempY);
                    print_board(realBoard);
                    break;
                
                case 'n' :
                    // run one iteration
                    next_iteration(realBoard, tempBoard);
                    print_board(realBoard);
                    break;

                case 'p' :
                    // run continuously until user uses control-c
                    while (1) {
                        next_iteration(realBoard, tempBoard);
                        print_board(realBoard);
                        usleep(300000);
                        system("clear");
                    }
                case 'q' : 
                    printf("Bye Bye!\n");
                    return 0;

                default : 
                    printf("Improper letter choice. Try again!\n");
                    break;
            } 
        }
        return 0;
    }
    case 2 : 
        // batch mode
        printf("Batch mode:\n");
        FILE *fPointer = fopen(argv[1], "r");   // open file
        // account for non-existent files
        if (!fPointer) {
            printf("File not found. Exiting program.");
            return 1;
        }
        // declare variables for reading scenes
        char uChoice;
        int row, column;
        while (1) {
            if (feof(fPointer)) break;
            // read values within scene
            fscanf(fPointer, "%c %d %d", &uChoice, &row, &column);
            // if adding new cell
            if (uChoice == 'a') {
                make_alive_cell(realBoard, row, column);
            }
            // if removing cell
            if (uChoice == 'r') {
                make_dead_cell(realBoard, row, column);
            }
            // if playing constantly
            if (uChoice == 'p') break;
        }
        // play game forever
        while (1) {
            print_board(realBoard);
            next_iteration(realBoard, tempBoard);
            usleep(300000);
            system("clear");
        }
        break;
    default : 
        printf("Error. Too many arguments!\n");
        break;
    }
    return 0;
}