// Ryan O'Halloran - CSE 20311
// Lab 4

#include <stdio.h>
#include <math.h>

int array_ones(int, int array[]);
int array_primer(int, int array[]);
void array_printer(int, int, int array[]);

int main() {
    // declare number of elements in array, number of columns in array, and array itself
    int numElements = 1000, numCols = 10;
    int array[numElements];

    // set all values of array to 1
    array[numElements] = array_ones(numElements, array);

    // remove all composite numbers from array
    array[numElements] = array_primer(numElements, array);

    // print new prime array
    array_printer(numElements, numCols, array);

    return 0;
}

// assign the value of 1 to all elements in an array
int array_ones(int numElements, int array[numElements]) {
    // loop through array and set all values to 1
    for (int i = 0; i < numElements; i++) {
        array[i] = 1;
    }
    // return array
    return array[numElements];
}

// function to remove composites
int array_primer(int numElements, int array[numElements]) {
    // initialize counter
    //counter = 2;
    
    // main loop cycles through all non-zero elements and zeros any of those element's multiples
    for (int i = 2; i <= sqrt(numElements); i++) {
        if (array[i]) {
            for (int j = 2; j <= numElements / i; j++) {
                array[j * i] = 0;
            }
        }
    }
    // return new array
    return array[numElements];
}

// function to print out primes array
void array_printer(int numElements, int numCols, int array[numElements]) {
    // initialize prime counter and count number of prime numbers
    int primeCount = 0, primeArray[numElements];
    for (int i = 2; i <= numElements; i++) {
        if (array[i]) {
            primeArray[primeCount] = i;
            primeCount++;
        }
    }
    // calculate number of rows to print and initialize variables for printing loops
    int counter = 0;
    int numRows = floor(primeCount / numCols);

    // print prime numbers in columns of numCols and rows of numRows
    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            printf("%5d", primeArray[counter]);
            counter++;
        }
        printf("\n");
    }
    // print last row of values
    for (int j = 1; j <= primeCount - (numRows * numCols); j++) {
        printf("%5d", primeArray[counter]);
        counter++;
    }
    printf("\n");
}