// Ryan O'Halloran - CSE 20311
// Lab 5
// letterfreq.c - program to read in text file and display frequency of each letter of the alphabet, as well as totals of characters and letters
#include <stdio.h>
#include <math.h>
#include <string.h>

// define ASCII boundaries for upper and lower case letters
// defining like this makes it easier to transition ASCII values to a different language, if needed
#define uppCaseLower 65  // - upper case lower bound ('A')
#define uppCaseUpper 90  // - upper case upper bound ('Z')
#define lowCaseLower 97  // - lower case lower bound ('a')
#define lowCaseUpper 122 // - lower case upper bound ('z')
#define numLettersAlphabet 128 // - set number of letters in alphabet to number that can accommodate any language
                               // - 128 is chosen so as to accommodate all 128 possible characters on the ASCII table
// function prototypes
void file_prompt(char[]);
void zero_freq(int[]);
void count_all(FILE *, int[], int[]);
void print_totals(char[], int[]);
int num_NonZero(int[]);
void print_letter_freq(int[], int);
void letter_percentage(int[], int, int[]);

int main() {
    // declare filename array and size
    const int fNameSize = 30;
    char fileName[fNameSize];
    // prompt user for filename
    file_prompt(fileName);
    // create file pointer and open file
    FILE *fPointer;
    fPointer = fopen(fileName, "r");
    // account for improper filename input
    if (fPointer == NULL) {
        printf("File '%s' is not found.\n", fileName);
        return 1;
    }
    // declare int freq array
    int freq[numLettersAlphabet];
    // set all elements of freq to 0
    zero_freq(freq);
    // create int array to count number of characters and letters
    int arrCharsLetters[2] = {0, 0};    // 0th index is numChars, 1st index is numLetters
    // count number of times each character appears and store in freq
    count_all(fPointer, freq, arrCharsLetters);
    // print total number of characters and letters
    print_totals(fileName, arrCharsLetters);
    // get number of nonzero elements in freq
    int numNonZero = num_NonZero(freq);
    // print frequency of each letter
    print_letter_freq(freq, numNonZero);
    // print letter percentages
    letter_percentage(freq, numNonZero, arrCharsLetters);
    // close file
    fclose(fPointer);

    return 0;
}
// function to prompt user for file name and take in response
void file_prompt(char fileName[]) {
    // Prompt user for name of file
    printf("Enter filename: ");
    scanf("%s", fileName);
}
// function to set all freq values to 0
void zero_freq(int freq[]) {
    for (int i = 0; i < numLettersAlphabet; i++) {
        freq[i] = 0;
    }
}
// function to count number of times each character appears as well as total chars and letters
void count_all(FILE *fPointer, int freq[], int arrCharsLetters[]) {
    char ch;
    while ((ch = fgetc(fPointer)) != EOF) {
        if (ch >= uppCaseLower && ch <= uppCaseUpper) {
            freq[ch - uppCaseLower] += 1;
            arrCharsLetters[1] += 1;
        }
        else if (ch >= lowCaseLower && ch <= lowCaseUpper) {
            freq[ch - lowCaseLower] += 1;
            arrCharsLetters[1] += 1;
        }
        arrCharsLetters[0] += 1;
    }
}
// function to print total number of characters and letters
void print_totals(char fileName[], int arrCharsLetters[]) {
    printf("\nGeneral summary for %s:\n", fileName);
    printf("Number of total characters: %d\n", arrCharsLetters[0]);
    printf("Number of letters: %d\n\n", arrCharsLetters[1]);
} 
// function to find number of nonzero elements in freq
int num_NonZero(int freq[]) {
    int count = 0;
    for (int i = 0; i < numLettersAlphabet; i++) {
        if (freq[i] > 0) {
            count++;
        }
    }
    return count;
}
// function to print out letter frequencies
void print_letter_freq(int freq[], int numNonZero) {
    int numCols = 6;    // printing 6 columns to best fit output
    int numRows = floor(numNonZero / numCols);
    int count = 0;
    printf("Letter counts:\n");
    for (int i = 0; i <= numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (freq[count] > 0) {
                printf("%c:%6d ", count + lowCaseLower, freq[count]);
                count++;
            }
        }
        printf("\n");
    }
    printf("\n");
}
// function to print percentage of all letters for each letter
void letter_percentage(int freq[], int numNonZero, int arrCharsLetters[]) {
    int numCols = 6;    // printing 6 columns to best fit output
    int numRows = floor(numNonZero / numCols);
    int count = 0;
    printf("Letter percentages:\n");
    for (int i = 0; i <= numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (freq[count] > 0) {
                float percentage = ((float) freq[count] / (float) arrCharsLetters[1]) * 100;
                printf("%c:%5.1f%% ", count + lowCaseLower, percentage);
                count++;
            }
        }
        printf("\n");
    } 
}