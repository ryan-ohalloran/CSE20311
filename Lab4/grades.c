// Ryan O'Halloran - CSE 20311
// Lab 4
// grades.c

#include <stdio.h>
#include <math.h>

// function prototypes ...
int num_grades(int grades[]);
float compute_average(int, int grades[]);
float compute_stdev(float, int, int grades[]);

int main()
{
    // declare array
    int grades[50] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79,-1 };

    // declare variables
    int numGrades = 0;
    float average;
    float stdev;

    // calculate and print number of grades
    while (grades[numGrades] >= 0) {
        numGrades += 1;
    }
    printf("There are %d grades in the set.\n", numGrades);

    // calculate average number of grades
    average = compute_average(numGrades, grades);

    // print grade average
    printf("Average: %f\n", average);

    // calculate standard deviation of grades
    stdev = compute_stdev(average, numGrades, grades);

    // print standard deviation
    printf("Standard Deviation: %f\n", stdev);

    return 0;
}

float compute_average(int numGrades, int grades[numGrades]) {
    // declare sum and average variables
    float sum = 0;
    float average;

    // calculate sum of grades
    for (int i = 0; i < numGrades; i++) {
        sum += grades[i];
    }
    
    // calculate average of array
    average = sum / numGrades;

    // return average
    return average;
}

float compute_stdev(float average, int numGrades, int grades[numGrades]) {
    // declare variables
    float squareDiff;
    float sum = 0;
    float stdev;
    
    // calculate sum of square differences
    for (int i = 0; i < numGrades; i++) {
        squareDiff = pow((grades[i] - average), 2);
        sum += squareDiff;
    }
    // compute average of all square differences
    stdev = sum / numGrades;
    
    // calculate stdev
    stdev = sqrt(stdev);
    
    // return stdev
    return stdev;
}