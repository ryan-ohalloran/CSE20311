#include <stdio.h>

int main() {
    // initialize array
    int array[5];
    // take input
    int i;
    for (i = 0; i < sizeof(array) / sizeof(int); i++) {
        printf("enter positive interger: ");
        scanf("%d", &array[i]);
    }

    // print off
    for (i = (sizeof(array) / sizeof(int)) - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}