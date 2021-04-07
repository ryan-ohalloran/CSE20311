#include <stdio.h>
#include <math.h>
#include "pathfunc.h"

// function to print number of points in file
void print_num_points(int numPoints) {
    printf("\nNumber of points in the file: %d\n\n", numPoints);
}
// function to print table of points
void print_table(Point point[], int numPoints) {
    printf("    x   |   y   \n");   // set up table
    printf("--------+--------\n");  
    for (int i = 0; i < numPoints; i++) {   // print table values
        printf("%5.1f   |  %5.1f\n", point[i].x, point[i].y);
    }
}
// function to find and print total distance through points
void print_dist(Point point[], int numPoints) {
    float distSum = 0;
    // calculate total distance
    for (int i = 0; i < numPoints - 1; i++) {
        distSum += sqrt( pow(point[i+1].x - point[i].x, 2) + pow(point[i+1].y - point[i].y, 2) );
    }
    // print total distance
    printf("\nThe path distance through the points is %4.2f\n", distSum);
}
// function to read file's values and return number of points in the file
int read_file(Point point[], FILE *fPointer, int numPoints) {
    while (1) {
        if (feof(fPointer)) break;
        // read file's values
        fscanf(fPointer, "%f %f", &point[numPoints].x, &point[numPoints].y);
        // increment number of points
        numPoints += 1;
    }
    return numPoints;
}
// function to prompt user for file name
void prompt_name(char namePtr[]) {
    printf("Enter filename ---> ");
    scanf("%s", namePtr);
}