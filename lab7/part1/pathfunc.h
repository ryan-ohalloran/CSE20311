#include <stdio.h>
#define maxPoints 30
#define fNameSize 25

typedef struct {
    float x;
    float y;
} Point;

void print_num_points(int);
void print_table(Point[], int);
void print_dist(Point[], int);
int read_file(Point[], FILE *, int);
void prompt_name(char[]);