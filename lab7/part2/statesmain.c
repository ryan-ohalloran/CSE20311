// Ryan O'Halloran
// CSE 20311
// Lab 7 - statesmain.c - main file for reading in a CSV file of US state information and providing options to a user
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "statesfunc.h"

int main(int argc, char *argv[]) { 
    const int maxNameLen = 64, numStates = 50, maxLineLen = 256;
    char csvLine[maxLineLen];
    State states[numStates];
    switch (argc) {
        case 1 : {
            char fName[maxNameLen];
            printf("enter filename --> ");
            scanf("%s", fName);
            FILE *fPointer = fopen(fName, "r");
            if (fPointer == NULL) {
                printf("Improper file entry. Exiting program.\n");
                return 1;
            }
            // read file, assign struct values, and count number of states in file 
            int count = read_file(states, fPointer, csvLine, maxNameLen);
            // declare variables
            bool isRunning = true;
            int uChoice, uYear;
            char uName[maxNameLen], uAbbr[maxNameLen], uLetter;
            while (isRunning) { // main logic
                print_options();
                scanf("%d", &uChoice);
                switch (uChoice) {
                    case 1 :
                        printf("Enter state name ---> ");
                        fgetc(stdin);
                        fgets(uName, maxNameLen, stdin);
                        state_name_info(states, count, uName);
                        break;
                    case 2 :
                        printf("Enter state abbreviation ---> ");
                        fgetc(stdin);
                        fgets(uAbbr, maxNameLen, stdin);
                        state_abbr_info(states, count, uAbbr);                        
                        break;
                    case 3 :
                        // print all years founded on or before specified year
                        printf("Enter year: ");
                        scanf("%d", &uYear);
                        print_before_year(states, count, uYear);
                        break;
                    case 4 : 
                        // print states founded after specified year
                        printf("Enter year: ");
                        scanf("%d", &uYear);
                        print_after_year(states, count, uYear);
                        break;
                    case 5 : 
                        // print states in order of joining union
                        print_in_order(states, count);
                        break;
                    case 6 :
                        // print state capitals starting with specified letter
                        printf("Enter letter: ");
                        fgetc(stdin);
                        scanf("%c", &uLetter);
                        states_starting_letter(states, count, uLetter);
                        break;
                    case 7 :
                        // print in order of joining union
                        printf("Bye bye!\n");
                        isRunning = false;
                        break;
                    default :
                        printf("Error. Improper entry. Try again.\n");
                }
            }
            break;
        }
        case 2 : {
            FILE *fPointer = fopen(argv[1], "r");
            if (fPointer == NULL) {
                printf("Improper file entry. Exiting program.\n");
                return 1;
            }
            // read file, assign struct values, and count number of states in file 
            int count = read_file(states, fPointer, csvLine, maxNameLen);
            // declare variables
            bool isRunning = true;
            int uChoice, uYear;
            char uName[maxNameLen], uAbbr[maxNameLen], uLetter;
            while (isRunning) { // main logic
                print_options();
                scanf("%d", &uChoice);
                switch (uChoice) {
                    case 1 : 
                        printf("Enter state name ---> ");
                        fgetc(stdin);
                        fgets(uName, maxNameLen, stdin);
                        state_name_info(states, count, uName);
                        break;
                    case 2 :
                        printf("Enter state abbreviation ---> ");
                        fgetc(stdin);
                        fgets(uAbbr, maxNameLen, stdin);
                        state_abbr_info(states, count, uAbbr);                        
                        break;
                    case 3 :
                        // print all years founded on or before specified year
                        printf("Enter year: ");
                        scanf("%d", &uYear);
                        print_before_year(states, count, uYear);
                        break;
                    case 4 : 
                        // print states founded after specified year
                        printf("Enter year: ");
                        scanf("%d", &uYear);
                        print_after_year(states, count, uYear);
                        break;
                    case 5 : 
                        // print states in order of joining union
                        print_in_order(states, count);
                        break;
                    case 6 :
                        // print state capitals starting with specified letter
                        printf("Enter letter: ");
                        fgetc(stdin);
                        scanf("%c", &uLetter);
                        states_starting_letter(states, count, uLetter);
                        break;
                    case 7 :
                        // print in order of joining union
                        printf("Bye bye!\n");
                        isRunning = false;
                        break;
                    default :
                        printf("Error. Improper entry. Try again.\n");
                }
            }
            break; 
        }           
        default : {
            printf("Error. Improper number of command line arguments.\n");
            break;
        }
    }
    return 0;
}