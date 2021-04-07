#include <stdio.h>

void flip(int [], int);

int main() {

    int arr[] = {4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    for (i=0; i<size; i++) printf("%d ", arr[i]);
    flip(arr, size);
    printf("\n");
    for (i=0; i<size; i++) printf("%d ", arr[i]);
    printf("\n");
}

void flip(int arr[], int size) {
    int temp[size];
    int i;
    
    for (i=0; i<size; i++) {
        temp[size - i - 1] = arr[i];
    }
    for (i=0; i<size; i++) {
        arr[i] = temp[i];
    }
}