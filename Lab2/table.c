# include <stdio.h>

int main() {

    // Declare variables
    int x;
    int y;

    // Collect user responses
    printf("Enter the 'x' number: ");
    scanf("%d", &x);
    printf("Enter the 'y' number: ");
    scanf("%d", &y);

    // Create row with '*' and each x number on top
    printf("*  ");

    for (int i=1; i <= x; i = i + 1) { 
        printf("%4d", i);
    }
    
    // Create row of -'s below the above row
    printf("\n   ");
    
    for (int i=1; i <= x; i = i + 1) {
        printf("----");
    }
    // Create table of multiplied values
    for (int i=1; i <= y; i = i + 1) {
        printf("\n%2d |", i);
        for (int j=1; j <= x; j = j + 1) { 
            printf("%4d", (i * j));
        }
    }

    printf("\n");

    return 0;
}