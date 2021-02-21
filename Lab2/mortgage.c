#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    // Declare variables needed for input and input check
    float principal;
    float monthlyPayment;
    float interestRate;
    bool principalBool = true;
    bool interestBool = true;
    bool paymentBool = true;

    // Get user input and check to ensure proper entry
    printf("Enter loan principal: ");
    scanf("%f", &principal);
    while (principalBool) {
        if (principal > 0) {
            principalBool = false;
        }
        else {
            printf("Invalid entry. Enter principal again: ");
            scanf("%f", &principal);
        }
    }
    printf("Enter interest rate (as a percentage): ");
    scanf("%f", &interestRate);
    while (interestBool) {
        if (interestRate >= 0) {
            interestBool = false;
        }
        else {
            printf("Invalid entry. Enter interest rate again: ");
            scanf("%f", &interestRate);
        }
    }    
    printf("Enter desired monthly payment: ");
    scanf("%f", &monthlyPayment);
    while (paymentBool) {
        if (monthlyPayment > 0) {
            paymentBool = false;
        }
        else {
            printf("Invalid entry. Enter monthly payment again: ");
            scanf("%f", &monthlyPayment);
        }
    }
    
    // Declare variables needed to execute conditional and calculate values
    int numYears = 0;
    int numMonths = 0;
    float monthInterest;
    float balance;
    float monthPaid;
    float totalInterest = 0;
    float lastPayment;

    // Initialize balance
    balance = principal;
    //Calculate first month's interest
    monthInterest = (interestRate / 100) * (balance) * (1.0 / 12.0);

    // Run main loop and account for monthly payments that are too low
    if (monthlyPayment < monthInterest) {
        printf("Monthly payment too low!\n");
    }
    else {
        // Print header for table
        printf("\nMonth%*sPayment%*sInterest%*sBalance\n",
                             6, "", 8, "", 9, "");
        // Calculate each month's stats
        while (balance >= monthlyPayment) {
            monthInterest = (interestRate / 100) * (balance) * (1.0 / 12.0);
            monthPaid = monthlyPayment - monthInterest;
            balance -= monthPaid;
            totalInterest += monthInterest;
            numMonths += 1;
            
            // Print table values as a formatted string
            printf("%-4d", numMonths);          // display month number
            printf("%*s", 6, "");               // spacing
            printf("$%8.2f", monthlyPayment);   // display monthly payment
            printf("%*s", 6, "");               // spacing
            printf("$%8.2f", monthInterest);    // display month's interest
            printf("%*s", 6, "");               // spacing
            printf("$%10.2f\n", balance);       // display new balance
        }
        // Calculate and display information on last payment
        monthInterest = (interestRate / 100) * (balance) * (1.0 / 12.0);
        lastPayment = balance + monthInterest;
        balance -= balance;
        totalInterest += monthInterest;
        totalInterest += principal;
        numMonths += 1;

        // Print last payment value as a formatted string
        printf("%-4d", numMonths);          // display month number
        printf("%*s", 6, "");               // spacing
        printf("$%8.2f", lastPayment);      // display last payment
        printf("%*s", 6, "");               // spacing
        printf("$%8.2f", monthInterest);    // display month's interest
        printf("%*s", 6, "");               // spacing
        printf("$%10.2f\n", balance);       // display new balance

        // Calculate number of months and years
        numYears = floor(numMonths / 12);
        numMonths %= 12;
        
        // Print total interest and time of mortgage
        printf("\nYou paid a total of $%.2f over %d years and %d months.\n\n", 
                        totalInterest, numYears, numMonths);
    }
    return 0;
}