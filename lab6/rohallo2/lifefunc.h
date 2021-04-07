// Ryan O'Halloran
// CSE 20311 - Lab 6
// Conway's Game of Life
// March 29th, 2021
// header file

#define boardSize 40
void print_board(char[boardSize][boardSize]);
void print_options(void);
char determine_cell(char[boardSize][boardSize], int, int);
void next_iteration(char[boardSize][boardSize], char[boardSize][boardSize]);
void make_alive_cell(char[boardSize][boardSize], int, int);
void make_dead_cell(char[boardSize][boardSize], int, int);