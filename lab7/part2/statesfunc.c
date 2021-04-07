// Ryan O'Halloran
// CSE 20311
// Lab 7 - statesfunc.c - function file for reading in a CSV file of US state information and providing options to a user
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "statesfunc.h"
// function to read file and assign struct array values
int read_file(State states[], FILE *fPointer, char csvLine[], int maxNameLen) {
    int count = 0;
    // read file's values
    while (1) {
        fgets(csvLine, maxNameLen, fPointer);
        if (feof(fPointer)) break;
        strcpy(states[count].abbr, strtok(csvLine, ","));
        strcpy(states[count].name, strtok(NULL, ","));
        strcpy(states[count].capt, strtok(NULL, ","));
        states[count].year = atoi(strtok(NULL, "/n"));
        // increment count
        count++;
    }
    return count;
}
// function to print available options to user
void print_options(void) {
    printf("------------------------------------------------------------------------------------\n");
    printf("Enter your choice below:\n");
    printf(" - 1. Display capital, abbreviation, and year founded for specified state name\n");
    printf(" - 2. Display state name, capital, and year founded for specified state abbreviation\n");
    printf(" - 3. Display all states founded on or before a specified year\n");
    printf(" - 4. Display all states founded after a specified year\n");
    printf(" - 5. List state names in order of joining the union\n");
    printf(" - 6. List state capitals starting with specified letter\n");
    printf(" - 7. QUIT PROGRAM.\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("Enter choice: ");
}
// function to display information for given state name
void state_name_info(State states[], int count, char uName[]) {
    // convert user-entered state name to proper format
    for (int i = 0; i <= strlen(uName); i++) {
        uName[i] = tolower(uName[i]);
    }
    uName[0] = toupper(uName[0]);       // make first letter capital
    uName[strcspn(uName, "\0")] = 0;    // remove null character
    uName[strcspn(uName, "\n")] = 0;    // remove newline
    // capitalize second name in two word states
    for (int i = 0; i <= strlen(uName); i++) {
        if (uName[i] == ' ') {
            uName[i + 1] = toupper(uName[i + 1]);
        }
    }
    // loop through states struct array and find specified state
    char *isIn;
    int isFound = -1;
    for (int i = 0; i < count; i++) {
        isIn = strstr(states[i].name, uName);
        if (isIn != NULL) {
            isFound = i;
            break;
        }
    }
    if (isFound > -1) {
        printf("\n%s:\n", uName);
        printf("Abbreviation: %s | Capital: %s | Year Founded: %d\n", states[isFound].abbr, states[isFound].capt, states[isFound].year);
    } 
    else {
        printf("State not found - check for improper entry.\n");
    }
}
// function to display information for given state abbreviation
void state_abbr_info(State states[], int count, char uAbbr[]) {
    // convert user-entered state abbreviation to proper format
    for (int i = 0; i <= strlen(uAbbr); i++) {
        uAbbr[i] = toupper(uAbbr[i]);
    }
    uAbbr[strcspn(uAbbr, "\0")] = 0;    // remove null character
    uAbbr[strcspn(uAbbr, "\n")] = 0;    // remove newline
    // loop through states struct array and find specified abbreviation
    char *isIn;
    int isFound = -1;
    for (int i = 0; i < count; i++) {
        isIn = strstr(states[i].abbr, uAbbr);
        if (isIn != NULL) {
            isFound = i;
            break;
        }
    }
    if (isFound > -1) {
        printf("\n%s:\n", uAbbr);
        printf("Name: %s | Capital %s | Year Founded: %d\n", states[isFound].name, states[isFound].capt, states[isFound].year);
    }
    else {
        printf("Abbreviation not found - check for improper entry.\n");
    }
}
// function to print all states who joined before or on a certain year
void print_before_year(State states[], int count, int uYear) {
    // create temp state array
    State tempStates[count];
    // declare variables to assing temp variables values
    int numCount = 0, startYear = 1785;
    // create tempStates array of structs arranged in order of year joining union
    while (numCount < 50) { 
        for (int i = 0; i < count; i++) {
            if (states[i].year == startYear) {
                tempStates[numCount].year = states[i].year;
                strcpy(tempStates[numCount].name, states[i].name);
                numCount++;
            }
        }
        startYear++;
    }
    // print only years after uYear
    printf("States that joined before %d:\n", uYear);
    for (int i = 0; i < count; i++) {
        if (tempStates[i].year <= uYear) {
            printf("- %s | %d\n", tempStates[i].name, tempStates[i].year);
        }
    }
}
// function to print all states who joined after a certain year
void print_after_year(State states[], int count, int uYear) {
    // create temp state array
    State tempStates[count];
    // declare variables to assing temp variables values
    int numCount = 0, startYear = 1785;
    // create tempStates array of structs arranged in order of year joining union
    while (numCount < 50) { 
        for (int i = 0; i < count; i++) {
            if (states[i].year == startYear) {
                tempStates[numCount].year = states[i].year;
                strcpy(tempStates[numCount].name, states[i].name);
                numCount++;
            }
        }
        startYear++;
    }
    // print only years after uYear
    printf("States that joined after %d:\n", uYear);
    for (int i = 0; i < count; i++) {
        if (tempStates[i].year > uYear) {
            printf("- %s | %d\n", tempStates[i].name, tempStates[i].year);
        }
    }
}
// funciton to display states in order of joining union
void print_in_order(State states[], int count) {
    // create temp state array
    State tempStates[count];
    // declare variables to assing temp variables values
    int numCount = 0, startYear = 1785;
    // create tempStates array of structs arranged in order of year joining union
    while (numCount < 50) { 
        for (int i = 0; i < count; i++) {
            if (states[i].year == startYear) {
                tempStates[numCount].year = states[i].year;
                strcpy(tempStates[numCount].name, states[i].name);
                numCount++;
            }
        }
        startYear++;
    }
    // print state name and year joined in order
    printf("\nStates in order of year joined:\n\n");
    for (int i = 0; i < count; i++) {
        printf(" - %s | %d\n", tempStates[i].name, tempStates[i].year);
    }
}
// function to display state capitals that start with a specified letter
void states_starting_letter(State states[], int count, char uLetter) {
    // capitalize uLetter
    uLetter = toupper(uLetter);
    // loop through all state capitals
    printf("States whose capital starts with %c:\n", uLetter);
    for (int i = 0; i < count; i++) {
        if (states[i].capt[0] == uLetter) {
            printf(" - %s: %s\n", states[i].name, states[i].capt);
        }
    }
}