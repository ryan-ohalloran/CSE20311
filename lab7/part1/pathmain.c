#include <stdio.h>
#include <math.h>
#include "pathfunc.h"

int main(int argc, char *argv[]) {
    // declare file pointer
    FILE *fPointer;
    // run program depending on number of command line arguments
    switch (argc) {
        case 1 : { /***file entered by user in program***/
            // declare filename
            char fName[maxPoints];  // use maxPoints var value because 30 chars is appropriate filename length
            // assign string to filename pointer
            prompt_name(fName);
            // open file
            fPointer = fopen(fName, "r");
            if (!fPointer) {
                printf("File not found. Exiting program.\n");
                return 1;
            }
            // declare variables for reading file
            int numPoints = 0;
            Point point[maxPoints];
            // read file and get new value of numPoints
            numPoints = read_file(point, fPointer, numPoints);
            // print out results
            print_num_points(numPoints);
            print_table(point, numPoints);
            print_dist(point, numPoints);
            break;
        }
        case 2 : /***file entered in command line***/
            // open file
            fPointer = fopen(argv[1], "r");
            if (!fPointer) {
                printf("File not found. Exiting program.\n");
                return 1;
            }
            // declare variables for reading file
            int numPoints = 0;
            Point point[maxPoints];
            // read file and get new value of numPoints
            numPoints = read_file(point, fPointer, numPoints);
            // print out results
            print_num_points(numPoints);
            print_table(point, numPoints);
            print_dist(point, numPoints);
            break;
        default :
            // error - too many arguments
            printf("Error. Too many command line arguments.\n");
            return 1;
    }
    return 0;
}