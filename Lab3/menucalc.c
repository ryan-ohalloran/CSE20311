// Ryan O'Halloran - CSE 20311
// Lab 3

#include <stdio.h>
#include <stdbool.h>

void print_options(void);
int get_choice(void);
void displayInputs(double, double);
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double perform_operation(int, double, double);

int main() {
    // Declare variables
    bool isRunning;
    int operationChoice;
    double numOne, numTwo;
    double output;

    // set isRunning to true
    isRunning = true;

    while (isRunning) {
        // display operation options
        print_options();

        // get choice
        operationChoice = get_choice();
        
        if (operationChoice == 5) {
            isRunning = false;
        }
        else {

            // Prompt user for numbers
            printf("Enter number: ");
            scanf("%lf", &numOne);
            printf("Enter second number: ");
            scanf("%lf", &numTwo);

            // display inputs
            displayInputs(numOne, numTwo);

            // Perform calculations based on operation choice
            output = perform_operation(operationChoice, numOne, numTwo);

            // display results
            printf("%.3lf\n\n", output);
        }
    }
    // print goodbye
    printf("Bye-bye!\n");

    return 0;
}

void print_options(void) {
    // print options
    printf("What would you like to do?\n");
    printf("Enter 1 for addition.\n");
    printf("Enter 2 for subtraction.\n");
    printf("Enter 3 for multiplication.\n");    
    printf("Enter 4 for division.\n");
    printf("Enter 5 to quit.\n");
}

int get_choice(void) {
    // declare choice variable
    int choice;
    // ask user for their choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // return choice
    return choice;
}

double addition(double numOne, double numTwo) {
    // Declare variable
    double output;

    // Multiply values
    output = numOne + numTwo;

    // return output
    return output;
}

double subtraction(double numOne, double numTwo) {
    // Declare variable
    double output;

    // Multiply values
    output = numOne - numTwo;

    // return output
    return output;
}

double multiplication(double numOne, double numTwo) {
    // Declare variable
    double output;

    // Multiply values
    output = numOne * numTwo;

    // return output
    return output;
}

double division(double numOne, double numTwo) {
    // Declare variable
    double output;

    // Multiply values
    output = numOne / numTwo;

    // return output
    return output;
}

double perform_operation(int operationChoice, double numOne, double numTwo) {
    // Declare output value
    double output;
    // Run main switch statement
    switch (operationChoice) {
        case 1 :
            output = addition(numOne, numTwo);
            printf("(%.2lf) + (%.2lf) = ", numOne, numTwo);
            break;
        case 2 :
            output = subtraction(numOne, numTwo);
            printf("(%.2lf) - (%.2lf) = ", numOne, numTwo);
            break;
        case 3 :
            output = multiplication(numOne, numTwo);
            printf("(%.2lf) * (%.2lf) = ", numOne, numTwo);
            break;
        case 4 :
            output = division(numOne, numTwo);
            printf("(%.2lf) / (%.2lf) = ", numOne, numTwo);
            break;
        
    }
    // return output
    return output;
}

void displayInputs(double numOne, double numTwo) {
    // Display operation choice
    printf("Inputs: %.2lf, %.2lf\n", numOne, numTwo);
    printf("Result of operation:\n");
}