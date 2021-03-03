// Ryan O'Halloran - CSE 20311
// Lab 3

#include <stdio.h>

// Function prototype
int getgcd(int, int);

int main() {
    // Declare user input variables
    int interger1;
    int interger2;

    // Take user input
    printf("Enter an interger: ");
    scanf("%d", &interger1);
    printf("Enter another interger: ");
    scanf("%d", &interger2);

    // Call getgcd function
    getgcd(interger1, interger2);

    return 0;
}

int getgcd(int interger1, int interger2) {
    // Swap intergers one and two and doesn't create a new variable
    // if interger one is smaller than interger two
    if (interger1 < interger2) {
        interger1 += interger2;
        interger2 = interger1 - interger2;
        interger1 -= interger2;
    }
    
    // We assume the user will only enter positive intergers, so no need to check for zero

    // Implement Euclid's algorithm for finding the GCD 
    //     --- Continues looping until there is no longer a remainder
    while (interger1 % interger2 != 0) {
        // Swap integers one and two without using additional memory
        interger1 += interger2;
        interger2 = interger1 - interger2;
        interger1 -= interger2;
        // Turn interger two into the remainder between itself and interger one
        interger2 %= interger1;
    }
    // Print results
    printf("The GCD is %d.\n", interger2);
    return 0;
}