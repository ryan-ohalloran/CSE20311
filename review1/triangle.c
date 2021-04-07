#include <stdio.h>

void array_changer(int [], int);

int main() {
    // declaration
    int array[] = {3, 5, 6, 12, 3, 99};
    int size = sizeof(array) / sizeof(array[0]);
    int i;
    for (i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    array_changer(array, size);
    for (i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}

void array_changer(int array[], int size) {
    int i;
    for (i = 1; i < size + 1; i++) {
        array[i-1] += i*i;
    }
}