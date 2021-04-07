// Ryan O'Halloran - CSE 20311
// Lab 4
// ndfootball.c

#include <stdio.h>
#include <stdbool.h>

// win and loss arrays
int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 10 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5, 3, 8, 3, 1, 2, 2 };

// prototypes
void display_options(void);
int array_size(void);
void win_percent(int, float);
void x_wins(int, int);
void x_losses(int, int);
void season_record(int, int);

int main() {
    // initialize isChoosing boolean 
    bool isChoosing = true;
    // declare variables for different menu options
    int uChoice;
    float winPercent;
    int numWins, numLosses, seasonChoice;
    // declare and determine arrayLen variable
    int arrayLen = array_size();

    // main logic for choices
    while (isChoosing) {
        // print options and prompt user
        display_options();
        scanf("%d", &uChoice);
        switch (uChoice) {
            case 1: // if user enters 1
                printf("Enter desired win percentage as a decimal (ex. 0.652): ");
                scanf("%f", &winPercent);
                win_percent(arrayLen, winPercent);
                break;
            case 2: // if user enters 2
                printf("Enter number of wins: ");
                scanf("%d", &numWins);
                x_wins(arrayLen, numWins);
                break;
            case 3: // if user enters 3
                printf("Enter number of losses: ");
                scanf("%d", &numLosses);
                x_losses(arrayLen, numLosses);
                break;
            case 4: // if user enters 4
                printf("Enter desired season: ");
                scanf("%d", &seasonChoice);
                season_record(arrayLen, seasonChoice);
                break;
            case 5: // if user chooses to exit
                isChoosing = false;
                break;
            default:    // account for invalid entries
                printf("***Invalid entry. Retry choice.***\n\n");
                break;
        }
    }
    printf("Bye-bye.\n");
}

// funtion to determine and output size of arrays
int array_size(void) {
    // declare array length int
    int arrayLen;
    // calculate size of win and loss arrays assuming wins and loss arrays are of same size
    arrayLen = (sizeof(wins) / sizeof(wins[0]));
    // return arrayLen
    return arrayLen;
}

// function to display user input options
void display_options(void) {
    // display options and prompt for choice
    printf("1: Display seasons with a win percentage at or above specified value.\n");
    printf("2: Display seasons with at least 'x' wins.\n");
    printf("3: Display seasons with at least 'x' losses.\n");
    printf("4: Display record for specified season.\n");
    printf("5: Exit.\n");
    printf("\nEnter your choice: ");
}

// function for win percentage above specified value
void win_percent(int arrayLen, float winPercent) {
    // declare wins and losses for given season as floats and declare win percentage as a float
    float seasonWins, seasonLosses;
    float seasonPercent;
    // determine and print seasons with win percentages at or above winPercent and account for bad input
    if (winPercent > 1.00 || winPercent < 0.0) {
        printf("Invalid win percentage.\n");
    }
    else {
        printf("Seasons with a win percentage at or above %.3f:\n", winPercent);
        for (int i = 0; i < arrayLen; i++) {
            seasonWins = wins[i] / 1.0;
            seasonLosses = losses[i] / 1.0;
            seasonPercent = seasonWins / (seasonWins + seasonLosses);
            if (seasonPercent >= winPercent) {
                printf("%d ", 1900 + i);
            }
        }
    }
    printf("\n\n");
}

// function for seasons with at least x wins
void x_wins(int arrayLen, int numWins) {
    // loop to find seasons with more than or equal to numWins and account for invalid entries
    if (numWins < 0) {
        printf("Invalid. Number of wins cannot be negative!\n");
    }
    else {
        printf("Seasons with at least %d wins:\n", numWins);
        for (int i = 0; i < arrayLen; i++) {
            if (wins[i] >= numWins) {
                printf("%d ", 1900 + i);
            }
        }
    }
    printf("\n\n");
}

// function for seasons with at least x losses
void x_losses(int arrayLen, int numLosses) {
    // loop to find seasons with more than or equal to numLosses and account for invalid entries
    if (numLosses < 0) {
        printf("Invalid. Number of losses cannot be negative!\n");
    }
    else {
        printf("Seasons with at least %d losses:\n", numLosses);
        for (int i = 0; i < arrayLen; i++) {
            if (losses[i] >= numLosses) {
                printf("%d ", 1900 + i);
            }
        }
    }
    printf("\n\n");
}

// function for specified season's record
void season_record(int arrayLen, int seasonChoice) {
    // find target season and display record while accounting for invalid entries
    if (seasonChoice > 1900 + arrayLen - 1 || seasonChoice < 1900) {
        printf("Invalid season entry.\n");
    }
    else {
        printf("Record for %d season:\n", seasonChoice);
        printf("%d Wins - %d Losses\n", wins[seasonChoice - 1900], losses[seasonChoice - 1900]);
    }
}