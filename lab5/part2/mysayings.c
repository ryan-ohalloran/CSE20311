// Ryan O'Halloran - CSE 20311
// Lab 5
// mysayings.c - program to read in a startup file and present user with several options to interact with the file

// *Note* - I set up my program so that option 2 automatically saves each new saying to the database and subsequently to startup.dat,
// and option 4 creates an entirely new .txt file that the user can name themselves, with all sayings currently in database 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// these values are defined here so that the array's bounds are more easily adjusted later on, if necessary
#define maxSayings 50   // max number of sayings in file
#define maxChars 256    // max number of characters per saying - including additonal character (null/newline) at end
#define fNameSize 30    // max length of file name - including additional character (null/newline) at end

// function prototypes
void file_prompt(char[]);
void read_file(FILE *, char[maxSayings][maxChars]);
int get_num_sayings(FILE *);
int display_options(void);
void display_sayings(char[maxSayings][maxChars], int);
void enter_new_saying(char[maxSayings][maxChars], int);
void saying_to_file(FILE *, char[maxSayings][maxChars], char[], int);
void get_comparison_word(char[]);
void print_sayings_with_word(char[maxSayings][maxChars], char[], int);
void prompt_new_file(char[]);
void save_all_sayings(FILE *, char[maxSayings][maxChars], int);

int main() {
    // declare startup filename and potentially used newFileName arrays
    char fileName[fNameSize], newFileName[fNameSize];
    // prompt user for filename
    file_prompt(fileName);
    // creare file pointer and open file
    FILE *fPointer = fopen(fileName, "r");
    // account for nonexistent filename
    if (fPointer == NULL) {
        printf("File '%s' is not found.\n", fileName);
        return 1;
    }
    // declare 2D array of chars for all sayings
    char sayingsArr[maxSayings][maxChars];
    // declare word to be compared if user chooses option 4
    char word[maxChars];
    // get number of sayings in startup file
    int numSayings = get_num_sayings(fPointer);
    freopen(fileName, "r", fPointer);
    // main loop
    bool isRunning = true;
    while (isRunning) {
        // read file on each pass
        read_file(fPointer, sayingsArr);
        // take user choice and assign sayingsArr value
        int uChoice = display_options();
        // main program logic
        switch (uChoice) {
            case 1 : 
                // display all sayings currently in database
                display_sayings(sayingsArr, numSayings);
                break;
            case 2 : 
                // enter new saying in database
                enter_new_saying(sayingsArr, numSayings);
                // save new saying to startup file
                saying_to_file(fPointer, sayingsArr, fileName, numSayings);
                numSayings++;
                break;
            case 3 : 
                // prompt user for word to find in string
                get_comparison_word(word);
                // print all sayings containing given word
                print_sayings_with_word(sayingsArr, word, numSayings);
                break;
            case 4 : 
                // get name of new file from user
                prompt_new_file(newFileName);
                // create pointer and new file
                FILE *newStrPointer = fopen(newFileName, "w");
                // save all sayings to the new file
                save_all_sayings(newStrPointer, sayingsArr, numSayings);
                break;
            case 5 : 
                // quit program
                isRunning = false;
                printf("Bye-bye!\n");
                break;
            default : 
                // account for improper entry
                printf("*** INVALID ENTRY ***\nTry again.\n");
        }
    }
    fclose(fPointer); //  close startup file pointer
    return 0;
}
// function to prompt user for file name and take in response
void file_prompt(char fileName[]) {
    // Prompt user for name of file
    printf("Enter startup filename: ");
    scanf("%s", fileName);
}
// function to read file and assign sayings to sayings array
void read_file(FILE *fPointer, char sayingsArr[maxSayings][maxChars]) {
    // declare and initialize variables
    char ch;
    int rowCount = 0, colCount = 0;
    while ((ch = fgetc(fPointer)) != EOF) {
        if (ch != '\n') {
            sayingsArr[rowCount][colCount] = ch;
            colCount++;
        }
        else {
            sayingsArr[rowCount][colCount] = '\0';  // append null character in place of newline to filter out garbage
            rowCount++;
            colCount = 0;
        }
        sayingsArr[rowCount][colCount] = '\0';  // add null character to end of last saying
    }
}
// retrieve number of sayings in sayingsARR
int get_num_sayings(FILE *fPointer) {
    char ch;
    int numSayings = 0;
    while ((ch = fgetc(fPointer)) != EOF) {
        if (ch == '\n') {
            numSayings += 1;
        }
    }
    return numSayings + 1;
}
// function to display all options for main while loop and return user's choice
int display_options(void) {
    // decalare user's choice variable
    int uChoice;
    // display all options and scan value of uChoice
    printf("------------------------------------------------------------------------------\n");
    printf("1. Display all sayings currently in database\n");
    printf("2. Add new saying to database\n");
    printf("3. List sayings that contain a given word or part of a word specified by user\n");
    printf("4. Save all sayings in a new text file\n");
    printf("5. Quit the program\n");
    printf("------------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &uChoice);
    // return user's choice
    return uChoice;
}
// function to display all sayings
void display_sayings(char sayingsArr[maxSayings][maxChars], int numSayings) {
    // print out message and loop through and print out each row of array
    printf("\nAll stored sayings:\n");
    for (int i = 0; i < numSayings; i++) { 
        printf(" - ");
        puts(sayingsArr[i]);
    }
}
// function to enter new saying into database
void enter_new_saying(char sayingsArr[maxSayings][maxChars], int numSayings) {
    // declare saying
    char newSaying[maxChars];
    // retrieve saying from user
    printf("Enter new saying:\n - ");
    fgetc(stdin);
    fgets(newSaying, maxChars, stdin);
    // remove newline from newSaying
    newSaying[strcspn(newSaying, "\n")] = 0;
    // insert new saying into sayingsArr database
    strncpy(sayingsArr[numSayings], newSaying, maxChars);
}
// function to add new saying into startup file
void saying_to_file(FILE *fPointer, char sayingsArr[maxSayings][maxChars], char fileName[], int numSayings) {
    // reopen file in append mode
    freopen(fileName, "a", fPointer);
    // print newSaying to startup file
    fprintf(fPointer, "\n%s", sayingsArr[numSayings]);
    // reopen file in read mode
    freopen(fileName, "r", fPointer);
}
// function to get string name of word
void get_comparison_word(char word[]) {
    printf("Enter desired word (or letter) to check for: ");
    // retrieve word
    scanf("%s", word);
}
// function to print all sayings containing specified word
void print_sayings_with_word(char sayingsArr[maxSayings][maxChars], char word[maxChars], int numSayings) {
    printf("Sayings containing '%s':", word);
    for (int i = 0; i < numSayings; i++) {
        if (strstr(sayingsArr[i], word) != NULL) {
            printf("\n - %s", sayingsArr[i]);
        }
    }
    printf("\n");
}
// function to prompt user for new .txt filename
void prompt_new_file(char newFileName[]) { 
    // prompt user to enter new file name and scan filename
    printf("Enter name for new text file - don't add '.txt', just type filename:\n");
    scanf("%s", newFileName);
    // append .txt to new file name
    strcat(newFileName, ".txt");
}
// function to save all sayings to a new file
void save_all_sayings(FILE *newStrPointer, char sayingsArr[maxSayings][maxChars], int numSayings) {
    // loop through database and print to new file
    for (int i = 0; i < numSayings - 1; i++) {
        fprintf(newStrPointer, "%s\n", sayingsArr[i]);
    }
    fprintf(newStrPointer, "%s", sayingsArr[numSayings - 1]);
}